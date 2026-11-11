#!/usr/bin/env python3
"""Strict PCSG00337 DCVM rebuilding and DCFS script ROM packing.

All offsets passed to rebuild_container are relative to the STR string
region, after its eight-byte subheader. No index includes checksum bytes.
The complete original archive has 482 compressed and nine raw DCVMs.
Entries begin at 0x400 and are indexed by DCFS FILE records, in 0x400-byte
blocks. Repacking updates locations, read/output capacities and ROM size.

Compression deliberately uses only zlib level 9. Some valid Zopfli streams
are misdecoded by the related PCSG00378 engine; Python inflate alone does
not establish compatibility with the game's custom decoder.

Public operations are in memory. Callers own staging and installation.
"""
from __future__ import annotations

import struct
import zlib
from collections.abc import Iterator

import dcfs

ALIGN = 0x400
ROM_FIRST_ITEM = 0x400
TYP = 0x19A6
STR_SUBHEADER = 8
MAX_CONTAINER_SIZE = 64 * 1024 * 1024


def u32(data: bytes | bytearray, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def align(value: int, unit: int = ALIGN) -> int:
    return (value + unit - 1) // unit * unit


def parse_dcvm(data: bytes) -> tuple[bytes, list[list]]:
    """Return (header, [tag, payload, offset, total_size] sections), strictly."""
    if len(data) < 24 or data[:4] != b"DCVM":
        raise ValueError("not a complete DCVM container")
    if u32(data, 4) != len(data):
        raise ValueError("DCVM +4 total length differs from its payload")
    sections = []
    seen = set()
    position = 16
    while position < len(data):
        if position + 8 > len(data):
            raise ValueError(f"truncated DCVM section at {position:#x}")
        tag, length = data[position:position + 4], u32(data, position + 4)
        if length < 8 or length % 4 or position + length > len(data):
            raise ValueError(f"invalid DCVM section extent at {position:#x}")
        if tag in seen:
            raise ValueError(f"duplicate DCVM section {tag!r}")
        if tag == b"\0" * 4:
            if length != 8 or position + length != len(data):
                raise ValueError("DCVM zero end section must be last and eight bytes")
        elif not all(32 <= value <= 126 for value in tag):
            raise ValueError(f"invalid DCVM section tag {tag!r}")
        seen.add(tag)
        sections.append([tag, data[position + 8:position + length], position, length])
        position += length
    if not sections or sections[-1][0] != b"\0" * 4:
        raise ValueError("DCVM is missing its zero end section")
    return data[:16], sections


def _sections(data: bytes) -> dict[bytes, bytes]:
    return {section[0]: section[1] for section in parse_dcvm(data)[1]}


def region_records(region: bytes) -> list[tuple[int, bytes]]:
    """Enumerate every NUL-terminated record, including alignment empties."""
    result = []
    position = 0
    while position < len(region):
        end = region.find(b"\0", position)
        if end < 0:
            raise ValueError(f"STR record at {position:#x} has no terminator")
        result.append((position, region[position:end]))
        position = end + 1
    return result


def string_records(data: bytes) -> list[tuple[int, bytes]]:
    """Return STR-region relative byte offsets and original record bytes."""
    payload = _sections(data).get(b"STR ")
    if payload is None or len(payload) < STR_SUBHEADER:
        raise ValueError("DCVM has no complete STR subheader")
    return region_records(payload[STR_SUBHEADER:])


def stbl_entries(payload: bytes) -> list[int]:
    if len(payload) < 4:
        raise ValueError("STBL has no count")
    count = u32(payload, 0)
    if len(payload) != 4 + count * 4:
        raise ValueError("STBL count does not match its complete section")
    return list(struct.unpack_from(f"<{count}I", payload, 4))


def code_hash(code: bytes) -> int:
    total = 0
    for index, value in enumerate(code):
        total = (total + value + index) & 0xFFFFFFFF
        if index & 1:
            total = (~total) & 0xFFFFFFFF
    return total


def str_hash(region: bytes, entries: list[int]) -> int:
    records = dict(region_records(region))
    missing = set(entries) - records.keys()
    if missing:
        raise ValueError(f"STBL points outside STR record starts: {sorted(missing)[:5]}")
    hashes = {
        offset: sum(value if value < 0x80 else value - 0x100 for value in records[offset])
        for offset in set(entries)
    }
    return sum(hashes[offset] for offset in entries) & 0xFFFFFFFF


def verify_dcvm(data: bytes) -> list[str]:
    """Validate all extents, string pointers and actual CODE/STR checksums."""
    try:
        header, sections = parse_dcvm(data)
        if header[12:16] != b"\x00\x10\x00\x00":
            raise ValueError("unsupported DCVM format flags at +12")
        by_tag = {section[0]: section[1] for section in sections}
        if not {b"CODE", b"STR ", b"STBL"}.issubset(by_tag):
            raise ValueError("DCVM must contain CODE, STR and STBL")
        code, strings, table = (by_tag[tag] for tag in (b"CODE", b"STR ", b"STBL"))
        if len(code) < 20 or len(strings) < STR_SUBHEADER:
            raise ValueError("truncated CODE or STR subheader")
        if u32(code, 16) or u32(strings, 4):
            raise ValueError("XOR-obfuscated CODE/STR is not supported by this baseline")
        length = u32(code, 8)
        if length > len(code) - 20 or len(code) - 20 - length > 3:
            raise ValueError("CODE byte length exceeds its section or has extra data")
        if any(code[20 + length:]):
            raise ValueError("CODE alignment padding is not zero")
        actual_code = code_hash(code[20:20 + length])
        actual_str = str_hash(strings[STR_SUBHEADER:], stbl_entries(table))
        problems = []
        if actual_code != u32(code, 12):
            problems.append(f"CODE checksum {actual_code:08x} != {u32(code, 12):08x}")
        if actual_str != u32(strings, 0):
            problems.append(f"STR checksum {actual_str:08x} != {u32(strings, 0):08x}")
        expected = (actual_code + actual_str) & 0xFFFFFFFF
        if expected != u32(header, 8):
            problems.append(f"DCVM checksum {u32(header, 8):08x} != {expected:08x}")
        return problems
    except (ValueError, struct.error) as error:
        return [str(error)]


def rebuild_container(data: bytes, replacements: dict[int, bytes]
                      ) -> tuple[bytes, dict[int, int]]:
    """Replace records by OLD STR-region byte offset and remap all STBLs.

    Return (DCVM bytes, old-to-new string offset mapping). CODE and every
    section other than STR/STBL retain their exact bytes and order. String
    growth is allowed; the new STR and all following sections stay aligned.
    Unknown offsets, embedded NULs and invalid original checksums fail.
    """
    problems = verify_dcvm(data)
    if problems:
        raise ValueError("invalid source DCVM: " + "; ".join(problems))
    header, sections = parse_dcvm(data)
    by_tag = {section[0]: section[1] for section in sections}
    old_records = region_records(by_tag[b"STR "][STR_SUBHEADER:])
    known = {offset for offset, _record in old_records}
    if set(replacements) - known:
        raise ValueError("replacement offset does not refer to an original STR record")
    for offset, replacement in replacements.items():
        if not isinstance(offset, int) or not isinstance(replacement, bytes):
            raise ValueError("replacement keys must be integer offsets and values bytes")
        if b"\0" in replacement:
            raise ValueError(f"replacement at {offset:#x} contains NUL")
    mapping = {}
    region = bytearray()
    for offset, old in old_records:
        mapping[offset] = len(region)
        region += replacements.get(offset, old) + b"\0"
    region += b"\0" * (-len(region) % 4)

    table = bytearray(by_tag[b"STBL"])
    entries = stbl_entries(bytes(table))
    for index, old in enumerate(entries):
        struct.pack_into("<I", table, 4 + index * 4, mapping[old])
    new_entries = [mapping[value] for value in entries]
    text_hash = str_hash(bytes(region), new_entries)
    strings = struct.pack("<II", text_hash, 0) + region
    output = bytearray(header)
    for tag, payload, _offset, _length in sections:
        if tag == b"STR ":
            payload = bytes(strings)
        elif tag == b"STBL":
            payload = bytes(table)
        output += tag + struct.pack("<I", 8 + len(payload)) + payload
    struct.pack_into("<I", output, 4, len(output))
    code_checksum = u32(by_tag[b"CODE"], 12)
    struct.pack_into("<I", output, 8, (code_checksum + text_hash) & 0xFFFFFFFF)
    rebuilt = bytes(output)
    problems = verify_dcvm(rebuilt)
    if problems:
        raise ValueError("invalid rebuilt DCVM: " + "; ".join(problems))
    new_sections = _sections(rebuilt)
    for tag, original_payload in by_tag.items():
        if tag not in (b"STR ", b"STBL") and new_sections[tag] != original_payload:
            raise ValueError(f"non-text section changed: {tag!r}")
    new_records = dict(region_records(new_sections[b"STR "][STR_SUBHEADER:]))
    for offset, original_record in old_records:
        if new_records[mapping[offset]] != replacements.get(offset, original_record):
            raise ValueError(f"record read-back mismatch at {offset:#x}")
    return rebuilt, mapping


def iter_items(rom: bytes, start: int = ROM_FIRST_ITEM
               ) -> Iterator[tuple[str, int, int, int]]:
    """Walk every aligned script entry; malformed/truncated chains raise.

    Values are (kind, offset, stored_size, output_size); kind is z or raw.
    This is a structural check; runtime resource lookup uses the DCFS map.
    """
    if start % ALIGN or len(rom) % ALIGN or len(rom) <= start:
        raise ValueError("script archive extents must use 0x400-byte blocks")
    position = start
    while position < len(rom):
        if position + 12 > len(rom):
            raise ValueError(f"truncated ROM entry at {position:#x}")
        if rom[position:position + 4] == b"DCVM":
            size = u32(rom, position + 4)
            if not 24 <= size <= MAX_CONTAINER_SIZE or position + size > len(rom):
                raise ValueError(f"invalid raw DCVM extent at {position:#x}")
            yield "raw", position, size, size
            end = position + size
        else:
            magic, flag, size, output_size = struct.unpack_from("<HHII", rom, position)
            if magic != TYP or flag != 1:
                raise ValueError(f"invalid compressed entry identity at {position:#x}")
            if not (0 < size <= MAX_CONTAINER_SIZE and 0 < output_size <= MAX_CONTAINER_SIZE):
                raise ValueError(f"invalid compressed entry sizes at {position:#x}")
            end = position + 12 + size
            if end > len(rom):
                raise ValueError(f"compressed entry exceeds ROM at {position:#x}")
            yield "z", position, size, output_size
        next_position = align(end)
        if next_position > len(rom):
            raise ValueError(f"entry alignment exceeds ROM at {position:#x}")
        if any(rom[end:next_position]):
            raise ValueError(f"nonzero entry alignment padding at {position:#x}")
        position = next_position


def inflate_entry(rom: bytes, item: tuple[str, int, int, int],
                  exact_stream: bool = False) -> bytes:
    kind, position, size, output_size = item
    if kind == "raw":
        return rom[position:position + size]
    compressed = rom[position + 12:position + 12 + size]
    inflater = zlib.decompressobj()
    try:
        data = inflater.decompress(compressed, output_size + 1)
    except zlib.error as error:
        raise ValueError(f"zlib error at {position:#x}: {error}") from error
    if len(data) != output_size or not inflater.eof or inflater.unconsumed_tail:
        raise ValueError(f"incomplete zlib stream or output-size mismatch at {position:#x}")
    if any(inflater.unused_data) or (exact_stream and inflater.unused_data):
        raise ValueError(f"unexpected bytes after zlib stream at {position:#x}")
    return data


def find_containers(rom: bytes) -> list[tuple[int, int, int, int, bytes]]:
    """Compressed DCVMs in original extraction order, including their payload."""
    containers = []
    for item in iter_items(rom):
        kind, position, size, output_size = item
        if kind == "z":
            data = inflate_entry(rom, item)
            if data[:4] != b"DCVM":
                raise ValueError(f"non-DCVM script resource at {position:#x}")
            containers.append((len(containers), position, size, output_size, data))
    return containers


def verify_rom(rom: bytes, verbose: bool = False, map_data: bytes | None = None,
               exact_stream: bool = False) -> list[str]:
    """Validate every raw/compressed payload plus the complete FILE index."""
    try:
        items = list(iter_items(rom))
    except (ValueError, struct.error) as error:
        return [str(error)]
    problems = []
    for item in items:
        try:
            payload = inflate_entry(rom, item, exact_stream=exact_stream)
            problems.extend(f"entry {item[1]:#x}: {problem}" for problem in verify_dcvm(payload))
        except (ValueError, struct.error) as error:
            problems.append(str(error))
    if map_data is not None:
        problems.extend(dcfs.verify_rom_map(rom, map_data, expected_offsets=[item[1] for item in items]))
    if verbose:
        print(f"entries={len(items)} compressed={sum(item[0] == 'z' for item in items)} "
              f"raw={sum(item[0] == 'raw' for item in items)} problems={len(problems)}")
    return problems


def compress_best(data: bytes) -> bytes:
    """Compatibility name; only the selected zlib level-9 codec is used."""
    return zlib.compress(data, 9)


def repack_rom(rom: bytes, map_data: bytes, replacements: dict[int, bytes]
               ) -> tuple[bytes, bytes, dict[int, int]]:
    """Repack from complete DCVM replacements keyed by OLD ROM entry offset.

    Unchanged slots remain byte exact. Changed slots use exact zlib lengths
    or remain raw, and all subsequent map offsets/capacities are rebuilt.
    No replacement can be silently skipped because of its encoded size.
    """
    problems = verify_rom(rom, map_data=map_data)
    if problems:
        raise ValueError("invalid source ROM/map: " + "; ".join(problems[:10]))
    index = dcfs.parse_map(map_data)
    if index.block_size != ALIGN:
        raise ValueError("unsupported script archive block size")
    items = list(iter_items(rom))
    offsets = [item[1] for item in items]
    if set(replacements) - set(offsets):
        raise ValueError("replacement offset is absent from the source archive")
    result = bytearray(rom[:offsets[0]])
    mapping = {}
    for item, end in zip(items, offsets[1:] + [len(rom)]):
        kind, old, _size, _output_size = item
        mapping[old] = len(result)
        if old not in replacements:
            result += rom[old:end]
            continue
        payload = replacements[old]
        problems = verify_dcvm(payload)
        if problems:
            raise ValueError(f"replacement at {old:#x}: " + "; ".join(problems))
        if kind == "z":
            compressed = compress_best(payload)
            blob = struct.pack("<HHII", TYP, 1, len(compressed), len(payload)) + compressed
        else:
            blob = payload
        result += blob + b"\0" * (-len(blob) % ALIGN)
    rebuilt = bytes(result)
    rebuilt_map = dcfs.sync_map(rebuilt, map_data, offset_map=mapping)
    problems = verify_rom(rebuilt, map_data=rebuilt_map, exact_stream=True)
    if problems:
        raise ValueError("invalid rebuilt ROM/map: " + "; ".join(problems[:10]))
    return rebuilt, rebuilt_map, mapping
