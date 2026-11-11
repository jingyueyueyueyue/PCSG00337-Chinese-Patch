#!/usr/bin/env python3
"""PCSG00337 DCFT parsing, lossless glyph extension and rodata packaging.

The executable uses code - 0x8040 for double-byte codes, a shared glyph-id
space for ASCII and double-byte text, and IMGI[gid] for image addressing.
P4 pixels are packed low nibble first.  Do not use the superseded +94
bitmap bias or high-nibble-first description from early research notes.
"""
from __future__ import annotations

import struct
import zlib
from dataclasses import dataclass

import numpy as np
import dcfs

ALIGN = 0x400
TYP = 0x19A6
DOUBLE_BYTE_MIN = 0x8140
DOUBLE_BYTE_BIAS = 0x8040
GROUP_SIZE = 16
SECTION_TAGS = (b"@#LS", b"@GRP", b"@FNT", b"IMGD", b"CLUT", b"IMGI")


def code_index(code: int) -> int:
    if not 0 <= code <= 0xFFFF:
        raise ValueError(f"code outside u16: {code}")
    return code - DOUBLE_BYTE_BIAS if code >= DOUBLE_BYTE_MIN else (
        code if code <= 0xFF else code + 0x7EC0)


def index_code(index: int) -> int:
    return index if index <= 0xFF else index + DOUBLE_BYTE_BIAS


def valid_text_code(raw: bytes) -> bool:
    if len(raw) == 1:
        return 0x20 <= raw[0] <= 0x7E or 0xA1 <= raw[0] <= 0xDF
    return (len(raw) == 2 and
            (0x81 <= raw[0] <= 0x9F or 0xE0 <= raw[0] <= 0xFC) and
            (0x40 <= raw[1] <= 0x7E or 0x80 <= raw[1] <= 0xFC))


@dataclass
class Dcft:
    data: bytes
    sections: dict[bytes, tuple[int, int, bytes]]
    code_limit: int
    glyph_w: int
    glyph_h: int
    offset_unit: int
    ls: bytes
    g: np.ndarray
    f: np.ndarray
    bm: bytes
    image_info: np.ndarray
    legacy_imgi_overrun: int = 0

    @property
    def n_glyph(self) -> int:
        return len(self.ls)

    @property
    def block_bytes(self) -> int:
        return self.glyph_w * self.glyph_h // 2

    @property
    def n_blocks(self) -> int:
        return len(self.bm) // self.block_bytes

    def lookup(self, code: int) -> int | None:
        index = code_index(code)
        if index >= self.code_limit:
            return None
        group = index >> 4
        if group >= len(self.g):
            raise ValueError("DCFT code limit exceeds GRP")
        run = int(self.g[group])
        if run == 0xFFFF:
            return None
        slot = run + (index & 15)
        if slot >= len(self.f):
            raise ValueError(f"code {code:04X} exceeds FNT")
        gid = int(self.f[slot])
        return None if gid == 0xFFFF else gid

    def entries(self) -> dict[int, int]:
        result = {}
        for index in range(self.code_limit):
            code = index_code(index)
            gid = self.lookup(code)
            if gid is not None:
                result[code] = gid
        return result

    def bitmap_offset(self, gid: int) -> int:
        if not 0 <= gid < len(self.ls) or gid >= len(self.image_info):
            raise ValueError(f"glyph {gid} has no LS/IMGI entry")
        units = int(self.image_info[gid]) & 0x3FFFFF
        if units == 0x3FFFFF:
            raise ValueError(f"glyph {gid} has an absent image offset")
        offset = units * self.offset_unit
        if offset + self.block_bytes > len(self.bm):
            raise ValueError(f"glyph {gid} bitmap exceeds IMGD")
        return offset

    def block_of(self, gid: int) -> int:
        offset = self.bitmap_offset(gid)
        if offset % self.block_bytes:
            raise ValueError("glyph offset is not a whole bitmap block")
        return offset // self.block_bytes

    def glyph(self, gid: int) -> np.ndarray:
        offset = self.bitmap_offset(gid)
        raw = np.frombuffer(self.bm[offset:offset + self.block_bytes], dtype=np.uint8)
        raw = raw.reshape(self.glyph_h, self.glyph_w // 2)
        pixels = np.empty((self.glyph_h, self.glyph_w), dtype=np.uint8)
        pixels[:, 0::2], pixels[:, 1::2] = raw & 15, raw >> 4
        return pixels


def pack_glyph(pixels: np.ndarray) -> bytes:
    pixels = np.asarray(pixels)
    if (pixels.ndim != 2 or pixels.shape[1] % 2 or
            np.any(pixels < 0) or np.any(pixels > 15)):
        raise ValueError("expected an even-width array of 4bpp pixels")
    pixels = pixels.astype(np.uint8)
    return (pixels[:, 0::2] | (pixels[:, 1::2] << 4)).tobytes()


def repaint_font(base: bytes, glyphs: dict[int, np.ndarray]) -> bytes:
    """Repaint explicit glyph ids without changing any code or metric table."""
    font = parse_dcft(base)
    image_position = font.sections[b"IMGD"][0]
    image_base = image_position + struct.unpack_from("<I", base, image_position + 8)[0]
    result = bytearray(base)
    for gid, pixels in glyphs.items():
        if np.asarray(pixels).shape != (font.glyph_h, font.glyph_w):
            raise ValueError(f"glyph {gid} has the wrong repaint dimensions")
        position = image_base + font.bitmap_offset(gid)
        result[position:position + font.block_bytes] = pack_glyph(pixels)
    return bytes(result)


def parse_dcft(data: bytes, *, strict: bool = False) -> Dcft:
    if len(data) < 0x40 or data[:4] != b"DCFT":
        raise ValueError("not a complete DCFT")
    if struct.unpack_from("<I", data, 4)[0] != len(data):
        raise ValueError("DCFT total length does not match the payload")
    limit, width, height, unit = struct.unpack_from("<HHHH", data, 8)
    if not limit or not width or width % 2 or not height or not unit:
        raise ValueError("invalid DCFT bounds or raster geometry")
    if data[0x14:0x18] != b"\xef\xbe\xad\xde":
        raise ValueError("DCFT header sentinel is absent")
    if struct.unpack_from("<I", data, 0x18)[0] != 0x2C:
        raise ValueError("unexpected DCFT header block length")
    sections = {}
    overrun = 0
    position = 0x40
    while position < len(data):
        if position + 8 > len(data):
            raise ValueError("truncated DCFT section header")
        tag = data[position:position + 4]
        length = struct.unpack_from("<I", data, position + 4)[0]
        if length < 8 or tag in sections:
            raise ValueError("invalid or duplicate DCFT section")
        if position + length > len(data):
            # The six original files overstate their final IMGI lengths.
            # Accept only this known input quirk; rebuilt files are strict.
            if strict or tag != b"IMGI":
                raise ValueError("DCFT section extends beyond the payload")
            overrun = position + length - len(data)
            length = len(data) - position
        sections[tag] = (position, length, data[position + 8:position + length])
        position += length
    if set(sections) != set(SECTION_TAGS):
        raise ValueError(f"unexpected DCFT sections: {list(sections)}")
    for tag, divisor in ((b"@GRP", 2), (b"@FNT", 2), (b"IMGI", 4)):
        if len(sections[tag][2]) % divisor:
            raise ValueError(f"misaligned {tag!r} array")
    image_start, image_length, _ = sections[b"IMGD"]
    bitmap_offset = struct.unpack_from("<I", data, image_start + 8)[0]
    if not 12 <= bitmap_offset <= image_length:
        raise ValueError("IMGD bitmap offset exceeds the section")
    return Dcft(data, sections, limit, width, height, unit,
                sections[b"@#LS"][2],
                np.frombuffer(sections[b"@GRP"][2], dtype="<u2"),
                np.frombuffer(sections[b"@FNT"][2], dtype="<u2"),
                data[image_start + bitmap_offset:image_start + image_length],
                np.frombuffer(sections[b"IMGI"][2], dtype="<u4"), overrun)


def verify_dcft(data: bytes, expect_glyphs=None, *, strict: bool = False) -> list[str]:
    problems = []
    try:
        font = parse_dcft(data, strict=strict)
        if font.code_limit > len(font.g) * GROUP_SIZE:
            raise ValueError("code limit exceeds GRP capacity")
        if len(font.bm) % font.block_bytes:
            raise ValueError("IMGD contains a partial glyph block")
        active = (font.code_limit + 15) // 16
        previous = -1
        for group in range(active):
            run = int(font.g[group])
            if run == 0xFFFF:
                continue
            if run % 16 or run <= previous or run + 16 > len(font.f):
                raise ValueError(f"invalid FNT run {run} at group {group}")
            previous = run
        entries = font.entries()
        if len(entries) != len(set(entries.values())):
            raise ValueError("multiple character codes share a glyph id")
        for gid in entries.values():
            font.bitmap_offset(gid)
        if strict:
            if len(font.ls) != len(font.image_info):
                raise ValueError("rebuilt LS and IMGI lengths disagree")
            for gid in range(len(font.ls)):
                font.bitmap_offset(gid)
            if any(offset % 4 for offset, _length, _payload in font.sections.values()):
                raise ValueError("rebuilt section header is not u32 aligned")
        for code, (pixels, advance) in (expect_glyphs or {}).items():
            gid = font.lookup(code)
            if gid is None:
                raise ValueError(f"required code {code:04X} is absent")
            if font.ls[gid] != advance or not np.array_equal(font.glyph(gid), pixels):
                raise ValueError(f"required code {code:04X} failed raster/advance readback")
    except (ValueError, IndexError, struct.error) as exc:
        problems.append(str(exc))
    return problems


def extend_font(base: bytes, additions: dict[int, tuple[np.ndarray, int]]) -> tuple[bytes, dict]:
    """Keep every original glyph and append missing codes at every font size."""
    problems = verify_dcft(base)
    if problems:
        raise ValueError("invalid baseline font: " + "; ".join(problems))
    original = parse_dcft(base)
    native_entries = original.entries()
    native_count = max(native_entries.values(), default=-1) + 1
    if native_count != original.n_blocks:
        raise ValueError("baseline contains unmapped bitmap blocks; manual review required")
    if any(original.ls[native_count:]):
        raise ValueError("unmapped native LS tail contains nonzero metrics")
    if set(additions) & set(native_entries):
        raise ValueError("extension would overwrite native codes")
    for code in additions:
        raw = code.to_bytes(1 if code <= 0xFF else 2, "big")
        if not valid_text_code(raw):
            raise ValueError(f"invalid text code {code:04X}")
    highest = max([original.code_limit - 1] + [code_index(c) for c in additions])
    # An even group count keeps GRP and all following sections u32 aligned.
    group_count = ((highest + 16) // 16 + 1) // 2 * 2
    limit = group_count * 16
    if limit > 0xFFFF:
        raise ValueError("DCFT code bound exceeds u16")
    groups = [None] * group_count
    for group in range((original.code_limit + 15) // 16):
        run = int(original.g[group])
        if run != 0xFFFF:
            groups[group] = original.f[run:run + 16].astype(int).tolist()

    ls = bytearray(original.ls[:native_count])
    images = bytearray(original.image_info[:native_count].astype("<u4").tobytes())
    bitmap = bytearray(original.bm)
    assigned = {}
    for code, (pixels, advance) in sorted(additions.items()):
        pixels = np.asarray(pixels)
        if pixels.shape != (original.glyph_h, original.glyph_w):
            raise ValueError(f"code {code:04X} has the wrong raster size")
        if not 0 < advance <= 255:
            raise ValueError(f"code {code:04X} has an invalid advance")
        index = code_index(code)
        group = index >> 4
        if groups[group] is None:
            groups[group] = [0xFFFF] * 16
        if groups[group][index & 15] != 0xFFFF:
            raise ValueError(f"code {code:04X} collides with an existing entry")
        gid = len(ls)
        if gid >= 0xFFFF:
            raise ValueError("DCFT glyph count exceeds u16")
        offset = len(bitmap)
        if offset % original.offset_unit or offset // original.offset_unit >= 0x3FFFFF:
            raise ValueError("new IMGI offset exceeds its 22-bit field")
        groups[group][index & 15] = gid
        ls.append(advance)
        images += struct.pack("<I", 0x80000000 | (offset // original.offset_unit))
        bitmap += pack_glyph(pixels)
        assigned[code] = gid
    padding = (-len(ls)) % 4
    for _ in range(padding):
        images += struct.pack("<I", 0x80000000 | (len(bitmap) // original.offset_unit))
        bitmap += bytes(original.block_bytes)
        ls.append(0)
    g = bytearray()
    f = bytearray()
    for group in groups:
        if group is None:
            g += b"\xff\xff"
        else:
            run = len(f) // 2
            if run >= 0xFFFF:
                raise ValueError("FNT run offset exceeds u16")
            g += struct.pack("<H", run)
            f += struct.pack("<16H", *group)

    image_position = original.sections[b"IMGD"][0]
    image_offset = struct.unpack_from("<I", base, image_position + 8)[0]
    payloads = {
        b"@#LS": bytes(ls), b"@GRP": bytes(g), b"@FNT": bytes(f),
        b"IMGD": base[image_position + 8:image_position + image_offset] + bytes(bitmap),
        b"IMGI": bytes(images), b"CLUT": original.sections[b"CLUT"][2],
    }
    out = bytearray(base[:0x40])
    struct.pack_into("<H", out, 8, limit)
    for tag in original.sections:
        payload = payloads[tag]
        out += tag + struct.pack("<I", len(payload) + 8) + payload
    struct.pack_into("<I", out, 4, len(out))
    result = bytes(out)
    problems = verify_dcft(result, additions, strict=True)
    if problems:
        raise ValueError("rebuilt font failed validation: " + "; ".join(problems))
    rebuilt = parse_dcft(result, strict=True)
    if rebuilt.bm[:len(original.bm)] != original.bm:
        raise ValueError("native image bytes changed")
    if rebuilt.ls[:native_count] != original.ls[:native_count]:
        raise ValueError("native glyph metrics changed")
    if not np.array_equal(rebuilt.image_info[:native_count], original.image_info[:native_count]):
        raise ValueError("native IMGI addressing changed")
    for code, gid in native_entries.items():
        if rebuilt.lookup(code) != gid:
            raise ValueError(f"native code {code:04X} changed glyph id")
    return result, {
        "new_gids": assigned, "new_glyphs": len(assigned),
        "native_glyph_mappings_preserved": len(native_entries),
        "removed_native_ls_padding": len(original.ls) - native_count,
        "padding_glyphs": padding, "original_code_limit": original.code_limit,
        "code_limit": limit, "input_pixels_metrics_and_lookup_unchanged": True,
    }


def iter_rodata_items(rom: bytes, start: int = ALIGN):
    position = start
    while position < len(rom):
        if position + 12 > len(rom):
            raise ValueError("truncated rodata item header")
        magic, flag, compressed, expanded = struct.unpack_from("<HHII", rom, position)
        if magic != TYP or flag not in (0, 1) or not compressed or not expanded:
            raise ValueError(f"invalid rodata item at {position:#x}")
        end = position + 12 + compressed
        if end > len(rom):
            raise ValueError("rodata compressed item exceeds the ROM")
        yield position, compressed, expanded
        position = (end + ALIGN - 1) // ALIGN * ALIGN
    if position != len(rom):
        raise ValueError("rodata item traversal does not reach the ROM end")


def find_font_entry(rom: bytes, index: int = 1):
    position, compressed, expanded = list(iter_rodata_items(rom))[index]
    data = zlib.decompress(rom[position + 12:position + 12 + compressed])
    if len(data) != expanded or data[:4] != b"DCFT":
        raise ValueError(f"rodata entry {index} is not a complete DCFT")
    return position, compressed, expanded, data


def verify_rodata_map(rom: bytes, map_data: bytes) -> list[str]:
    try:
        entries = list(iter_rodata_items(rom))
        return dcfs.verify_rom_map(rom, map_data, expected_offsets=[p for p, _c, _s in entries])
    except ValueError as exc:
        return [str(exc)]


def rebuild_rodata_and_map(rom: bytes, map_data: bytes,
                           replacements: dict[int, bytes | tuple[bytes, bytes]]) -> tuple[bytes, bytes]:
    problems = verify_rodata_map(rom, map_data)
    if problems:
        raise ValueError("invalid source rodata/map: " + "; ".join(problems))
    if dcfs.parse_map(map_data).block_size != ALIGN:
        raise ValueError("unsupported rodata block size")
    entries = list(iter_rodata_items(rom))
    if set(replacements) - {p for p, _c, _s in entries}:
        raise ValueError("replacement is not a rodata entry")
    out = bytearray(rom[:ALIGN])
    offsets = {}
    expected = {}
    for position, compressed, expanded in entries:
        offsets[position] = len(out)
        original = zlib.decompress(rom[position + 12:position + 12 + compressed])
        if len(original) != expanded:
            raise ValueError("original rodata expanded size mismatch")
        replacement = replacements.get(position)
        if replacement is None:
            payload = original
            packed = rom[position + 12:position + 12 + compressed]
        elif isinstance(replacement, tuple):
            payload, packed = replacement
            packed = packed or zlib.compress(payload, 9)
        else:
            payload = replacement
            packed = zlib.compress(payload, 9)
        if zlib.decompress(packed) != payload:
            raise ValueError("compressed rodata replacement failed readback")
        expected[len(out)] = payload
        out += rom[position:position + 4] + struct.pack("<II", len(packed), len(payload))
        out += packed
        out += bytes((-len(out)) % ALIGN)
    result = bytes(out)
    new_map = dcfs.sync_map(result, map_data, offset_map=offsets)
    problems = verify_rodata_map(result, new_map)
    if problems:
        raise ValueError("rebuilt rodata/map failed validation: " + "; ".join(problems))
    for position, compressed, expanded in iter_rodata_items(result):
        payload = zlib.decompress(result[position + 12:position + 12 + compressed])
        if len(payload) != expanded or payload != expected[position]:
            raise ValueError("rebuilt rodata item failed payload readback")
    return result, new_map
