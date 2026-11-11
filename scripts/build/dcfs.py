#!/usr/bin/env python3
"""DCFS map parsing and ROM metadata synchronization.

FILE records are {name, block, metadata}.  The archive block size is
(map[0x18] + 1) * 0x80.  Metadata bit30 marks a compressed entry; bit29
selects byte units instead of archive blocks.  For compressed entries,
bits0..13 and bits14..27 encode read and output capacities minus one.
The read starts at the entry header, so it must include all 12 header
bytes as well as the compressed stream.  Keep the upper four flag bits.

These formulas reproduce every original compressed record in this
workspace, including entries whose 12-byte header crosses a block edge.
All public operations are in-memory; callers own validation and writes.
"""
from __future__ import annotations

import struct
from collections import Counter
from dataclasses import dataclass
from typing import Iterable

COMPRESSED = 1 << 30
BYTE_UNITS = 1 << 29
FLAG_MASK = 0xF0000000
FIELD_MASK = 0x3FFF
RAW_FIELD_MASK = 0x0FFFFFFF
ENTRY_HEADER_SIZE = 12
ENTRY_MAGIC = 0x19A6


def _u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


@dataclass(frozen=True)
class FileRecord:
    index: int
    offset: int
    name: int
    block: int
    metadata: int

    @property
    def compressed(self) -> bool:
        return bool(self.metadata & COMPRESSED)

    def unit(self, block_size: int) -> int:
        return 1 if self.metadata & BYTE_UNITS else block_size

    def read_capacity(self, block_size: int) -> int:
        mask = FIELD_MASK if self.compressed else RAW_FIELD_MASK
        return ((self.metadata & mask) + 1) * self.unit(block_size)

    def output_capacity(self, block_size: int) -> int:
        if not self.compressed:
            return 0
        return (((self.metadata >> 14) & FIELD_MASK) + 1) * self.unit(block_size)


@dataclass(frozen=True)
class DcfsIndex:
    block_size: int
    rom_size: int
    rom_id: int
    records: tuple[FileRecord, ...]


def parse_map(map_data: bytes) -> DcfsIndex:
    """Parse strictly; reject malformed headers, section chains and counts."""
    if len(map_data) < 28 or map_data[:4] != b"DCFS":
        raise ValueError("not a complete DCFS map")
    if _u32(map_data, 4) != len(map_data):
        raise ValueError("DCFS +0x04 does not match the map file size")
    if _u32(map_data, 8) != 1:
        raise ValueError("unsupported DCFS version at +0x08")
    block_size = (map_data[0x18] + 1) * 0x80
    sections: dict[bytes, tuple[int, int]] = {}
    pos = 0x1C
    while pos < len(map_data):
        if pos + 8 > len(map_data):
            raise ValueError(f"truncated DCFS section at {pos:#x}")
        tag, length = map_data[pos:pos + 4], _u32(map_data, pos + 4)
        if length < 8 or pos + length > len(map_data):
            raise ValueError(f"invalid DCFS section length at {pos:#x}")
        if tag in sections:
            raise ValueError(f"duplicate DCFS section {tag!r}")
        sections[tag] = (pos, length)
        pos += length
    if b"FILE" not in sections:
        raise ValueError("DCFS map has no FILE section")
    pos, length = sections[b"FILE"]
    if length < 12:
        raise ValueError("FILE section has no record count")
    count = _u32(map_data, pos + 8)
    end = pos + 12 + count * 12
    if end > pos + length:
        raise ValueError("FILE count exceeds its section")
    if any(map_data[end:pos + length]):
        raise ValueError("FILE section has nonzero data after its declared records")
    records = tuple(
        FileRecord(i, off, *struct.unpack_from("<III", map_data, off))
        for i in range(count)
        for off in (pos + 12 + i * 12,)
    )
    duplicates = [block for block, n in Counter(r.block for r in records).items() if n > 1]
    if duplicates:
        raise ValueError(f"FILE records duplicate ROM blocks: {duplicates[:5]}")
    # Names can repeat across directories; their global uniqueness is not required.
    if b"DIR " in sections:
        dpos, dlength = sections[b"DIR "]
        if dlength < 12:
            raise ValueError("DIR section has no record count")
        dcount = _u32(map_data, dpos + 8)
        if 12 + dcount * 16 > dlength:
            raise ValueError("DIR count exceeds its section")
        coverage = [0] * count
        for i in range(dcount):
            file_range = _u32(map_data, dpos + 12 + i * 16 + 12)
            first, n = file_range & 0xFFFF, file_range >> 16
            if first + n > count:
                raise ValueError(f"DIR[{i}] references FILE records outside its table")
            for j in range(first, first + n):
                coverage[j] += 1
        if any(n != 1 for n in coverage):
            raise ValueError("DIR ranges must reference every FILE record exactly once")
    return DcfsIndex(block_size, _u32(map_data, 0x14), _u32(map_data, 0x0C), records)


def _capacity_count(size: int, unit: int, mask: int) -> int:
    if size <= 0 or unit <= 0:
        raise ValueError("capacity sizes and units must be positive")
    value = (size - 1) // unit
    if value > mask:
        raise ValueError(f"capacity {size} exceeds a {mask.bit_length()}-bit field in unit {unit}")
    return value


def encode_compressed_metadata(old_metadata: int, cs: int, osz: int,
                               block_size: int) -> int:
    """Encode exact required capacities and preserve every upper flag bit."""
    if not old_metadata & COMPRESSED:
        raise ValueError("compressed metadata must retain bit30")
    if cs <= 0 or osz <= 0:
        raise ValueError("compressed and output sizes must be positive")
    unit = 1 if old_metadata & BYTE_UNITS else block_size
    read = _capacity_count(ENTRY_HEADER_SIZE + cs, unit, FIELD_MASK)
    output = _capacity_count(osz, unit, FIELD_MASK)
    return (old_metadata & FLAG_MASK) | (output << 14) | read


def _compressed_sizes(rom: bytes, offset: int) -> tuple[int, int]:
    if offset < 0 or offset + ENTRY_HEADER_SIZE > len(rom):
        raise ValueError(f"compressed entry header outside ROM at {offset:#x}")
    magic, flag, cs, osz = struct.unpack_from("<HHII", rom, offset)
    if magic != ENTRY_MAGIC or flag not in (0, 1):
        raise ValueError(f"invalid compressed entry header at {offset:#x}")
    if cs <= 0 or osz <= 0 or offset + ENTRY_HEADER_SIZE + cs > len(rom):
        raise ValueError(f"invalid compressed entry size at {offset:#x}")
    return cs, osz


def verify_rom_map(rom: bytes, map_data: bytes,
                   expected_offsets: Iterable[int] | None = None) -> list[str]:
    """Check one-to-one locations, header identity, ranges and exact capacities.

    Pass the known ROM entry offsets to detect missing or extra map records.
    A script ROM also has a raw DCVM at 0x400, before the old iterator's
    default 0x800 start; include it when supplying that iterator's offsets.
    """
    try:
        index = parse_map(map_data)
    except (ValueError, struct.error) as error:
        return [str(error)]
    problems: list[str] = []
    if index.rom_size != len(rom):
        problems.append(f"DCFS ROM size {index.rom_size} != actual {len(rom)}")
    if len(rom) < 4 or index.rom_id != _u32(rom, 0):
        problems.append("DCFS ROM identity at +0x0C does not match ROM header")
    offsets = [r.block * index.block_size for r in index.records]
    if expected_offsets is not None:
        expected = list(expected_offsets)
        if len(expected) != len(set(expected)):
            problems.append("expected ROM offsets contain duplicates")
        missing = set(expected) - set(offsets)
        extra = set(offsets) - set(expected)
        if missing or extra or len(expected) != len(offsets):
            problems.append(f"FILE location/count mismatch: missing={sorted(missing)[:8]}, "
                            f"extra={sorted(extra)[:8]}, records={len(offsets)}, expected={len(expected)}")
    ordered = sorted(offsets)
    next_offset = dict(zip(ordered, ordered[1:] + [len(rom)]))
    for record in index.records:
        offset = record.block * index.block_size
        prefix = f"FILE[{record.index}] @{offset:#x}"
        if offset < 0 or offset >= len(rom):
            problems.append(f"{prefix}: location outside ROM")
            continue
        read_cap = record.read_capacity(index.block_size)
        if offset + read_cap > len(rom):
            problems.append(f"{prefix}: read capacity extends beyond ROM")
        if record.compressed:
            try:
                cs, osz = _compressed_sizes(rom, offset)
                expected_meta = encode_compressed_metadata(record.metadata, cs, osz, index.block_size)
            except ValueError as error:
                problems.append(f"{prefix}: {error}")
                continue
            if offset + ENTRY_HEADER_SIZE + cs > next_offset[offset]:
                problems.append(f"{prefix}: compressed payload overlaps the following entry")
            if record.metadata != expected_meta:
                problems.append(
                    f"{prefix}: FILE.c={record.metadata:#010x}, expected {expected_meta:#010x}; "
                    f"read capacity={read_cap}, need={ENTRY_HEADER_SIZE + cs}; "
                    f"output capacity={record.output_capacity(index.block_size)}, need={osz}")
        elif rom[offset:offset + 4] == b"DCVM":
            if offset + 8 > len(rom):
                problems.append(f"{prefix}: truncated raw DCVM header")
                continue
            size = _u32(rom, offset + 4)
            if size < 16 or offset + size > next_offset[offset]:
                problems.append(f"{prefix}: invalid raw DCVM extent")
            if size > read_cap:
                problems.append(f"{prefix}: raw DCVM exceeds map read capacity")
    return problems


def sync_map(rom: bytes, map_data: bytes,
             offset_map: dict[int, int] | None = None) -> bytes:
    """Return a synchronized map; never write any file.

    offset_map maps old byte offsets to new byte offsets after a ROM
    rebuild.  Omit it when only entry contents or sizes have changed.
    Uncompressed entries retain metadata unless they are raw DCVMs.
    """
    index = parse_map(map_data)
    if len(rom) > 0xFFFFFFFF:
        raise ValueError("ROM size cannot be represented in the DCFS header")
    mapping = {} if offset_map is None else dict(offset_map)
    old_offsets = {r.block * index.block_size for r in index.records}
    unknown = set(mapping) - old_offsets
    if unknown:
        raise ValueError(f"offset map references unknown entries: {sorted(unknown)[:5]}")
    for old, new in mapping.items():
        if old % index.block_size or new < 0 or new % index.block_size:
            raise ValueError("ROM entry relocations must preserve archive block alignment")
    result = bytearray(map_data)
    struct.pack_into("<I", result, 0x14, len(rom))
    for record in index.records:
        old_offset = record.block * index.block_size
        offset = mapping.get(old_offset, old_offset)
        if offset < 0 or offset >= len(rom):
            raise ValueError(f"FILE[{record.index}] target outside ROM")
        struct.pack_into("<I", result, record.offset + 4, offset // index.block_size)
        metadata = record.metadata
        if record.compressed:
            cs, osz = _compressed_sizes(rom, offset)
            metadata = encode_compressed_metadata(metadata, cs, osz, index.block_size)
        elif rom[offset:offset + 4] == b"DCVM":
            if offset + 8 > len(rom):
                raise ValueError("truncated raw DCVM header")
            size = _u32(rom, offset + 4)
            count = _capacity_count(size, record.unit(index.block_size), RAW_FIELD_MASK)
            metadata = (metadata & FLAG_MASK) | count
        struct.pack_into("<I", result, record.offset + 8, metadata)
    new_map = bytes(result)
    problems = verify_rom_map(rom, new_map)
    if problems:
        raise ValueError("invalid synchronized map: " + "; ".join(problems[:5]))
    return new_map
