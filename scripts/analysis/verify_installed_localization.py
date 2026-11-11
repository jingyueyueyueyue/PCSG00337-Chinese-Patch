#!/usr/bin/env python3
"""Independently verify an installed or staged PCSG00337 localization.

Read manifest fingerprints, inspect the actual ROM/MAP bytes, resolve every
CSV identity against the pristine STR records, compare all translated and
untouched strings, and follow each font lookup through its bitmap offset.
This never builds or installs a package. A passing result is a file/format
audit; runtime acceptance still requires playing the game.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import io
import json
import struct
import sys
import zlib
from collections import Counter, defaultdict
from datetime import datetime
from functools import lru_cache
from pathlib import Path

import numpy as np
from fontTools.ttLib import TTFont
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts" / "build"))

SCRIPT_BASE = "archive/2026-09/20260907_script.rom"
SCRIPT_MAP_BASE = "archive/2026-09/20260908_script_map_pristine.map"
FONT_BASE = "archive/2026-09/20260908_rodata_pristine.rom"
FONT_MAP_BASE = "archive/2026-09/20260908_rodata_map_pristine.map"
EBOOT_BASE = "archive/2026-09/20260908_eboot_pristine.bin"
EXTRACTED = "extracted/script/script_strings.csv"
EBOOT_EXTRACTION = "extracted/eboot/eboot_strings.csv"
ORIGINAL_CODES = "extracted/script/custom_code_table.tsv"
TRANSLATION = "localization/text/translation_source.csv"
EBOOT_TRANSLATION = "localization/text/eboot_translations.csv"
CODE_TABLE = "localization/font/generated/font_code_table_reset.tsv"
PRISTINE_SHA256 = "75a23c47863cf77a9d0451df34f84e323d1478a50309fd0bb6001a1fbf7d7dfd"
REQUIRED_FILES = ("rom/script.rom", "map/script.map", "rom/rodata.rom",
                  "map/rodata.map", TRANSLATION, CODE_TABLE)
REQUIRED_SOURCES = (SCRIPT_BASE, SCRIPT_MAP_BASE, FONT_BASE, FONT_MAP_BASE, EXTRACTED, ORIGINAL_CODES)
MAX_RESOURCE_SIZE = 64 * 1024 * 1024
UNIFIED_FONT_PROFILES = {
    1: {"width": 48, "height": 48, "advance": 41, "size": 44, "baseline": 37},
    2: {"width": 48, "height": 48, "advance": 43, "size": 44, "baseline": 36},
    3: {"width": 48, "height": 48, "advance": 40, "size": 44, "baseline": 36},
    4: {"width": 48, "height": 48, "advance": 34, "size": 40, "baseline": 32},
    5: {"width": 16, "height": 16, "advance": 14, "size": 14, "baseline": 12},
    6: {"width": 48, "height": 48, "advance": 26, "size": 30, "baseline": 24},
}
DISPLAY_FORMS = {"\u3099": "\u309b", "\u309a": "\u309c"}
TEXT_FONT_NAME = "GlowSansSC-Normal-Medium.otf"
EXPLICIT_SYMBOL_FALLBACKS = {"\u266a": "msgothic.ttc", "\u2606": "msgothic.ttc"}


def u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def fingerprint(data: bytes) -> dict:
    return {"bytes": len(data), "sha256": hashlib.sha256(data).hexdigest()}


def relative_name(value: str) -> str:
    path = Path(value)
    if path.is_absolute() or path.drive or ".." in path.parts:
        raise ValueError(f"manifest path must stay relative to its workspace: {value}")
    return path.as_posix()


def parse_sections(data: bytes, start: int) -> list[tuple[bytes, bytes]]:
    """Independent strict TLV parser; sizes include the eight-byte header."""
    result, seen = [], set()
    offset = start
    while offset < len(data):
        if offset + 8 > len(data):
            raise ValueError(f"truncated section header at {offset:#x}")
        tag, size = data[offset:offset + 4], u32(data, offset + 4)
        if size < 8 or size % 4 or offset + size > len(data):
            raise ValueError(f"invalid section extent at {offset:#x}")
        if tag in seen:
            raise ValueError(f"duplicate section {tag!r}")
        seen.add(tag)
        result.append((tag, data[offset + 8:offset + size]))
        offset += size
    return result


def inspect_map(rom: bytes, data: bytes) -> dict:
    """Read actual FILE fields and recalculate their capacities independently."""
    if len(data) < 28 or data[:4] != b"DCFS" or u32(data, 4) != len(data):
        raise ValueError("invalid DCFS magic or total length")
    if u32(data, 8) != 1 or u32(data, 0x14) != len(rom):
        raise ValueError("DCFS version or recorded ROM length does not match")
    if len(rom) < 4 or u32(data, 12) != u32(rom, 0):
        raise ValueError("DCFS ROM identity differs from the actual ROM")
    unit = (data[0x18] + 1) * 128
    sections = dict(parse_sections(data, 0x1C))
    file_table = sections.get(b"FILE", b"")
    if len(file_table) < 4:
        raise ValueError("missing FILE table")
    count = u32(file_table, 0)
    if len(file_table) < 4 + count * 12 or any(file_table[4 + count * 12:]):
        raise ValueError("FILE count differs from its payload")
    records, offsets = [], set()
    for index in range(count):
        name, block, meta = struct.unpack_from("<III", file_table, 4 + index * 12)
        position = block * unit
        if position in offsets or position < unit or position + 12 > len(rom):
            raise ValueError(f"FILE[{index}] has a duplicate/out-of-range block")
        offsets.add(position)
        size_unit = 1 if meta & (1 << 29) else unit
        compressed = bool(meta & (1 << 30))
        if compressed:
            magic, flag, cs, osz = struct.unpack_from("<HHII", rom, position)
            if magic != 0x19A6 or flag != 1 or not (
                    0 < cs <= MAX_RESOURCE_SIZE and 0 < osz <= MAX_RESOURCE_SIZE):
                raise ValueError(f"FILE[{index}] compressed header is invalid")
            end = position + 12 + cs
            read_field = (12 + cs - 1) // size_unit
            output_field = (osz - 1) // size_unit
            if read_field > 0x3FFF or output_field > 0x3FFF:
                raise ValueError(f"FILE[{index}] capacities exceed encoded field limits")
            expected_meta = (meta & 0xF0000000) | read_field | (output_field << 14)
            if meta != expected_meta:
                raise ValueError(f"FILE[{index}] capacities {meta:#x} != {expected_meta:#x}")
            packed = rom[position + 12:end]
            dec = zlib.decompressobj()
            payload = dec.decompress(packed, osz + 1)
            if not dec.eof or dec.unconsumed_tail or len(payload) != osz:
                raise ValueError(f"FILE[{index}] zlib EOF/output size mismatch")
            if any(dec.unused_data):
                raise ValueError(f"FILE[{index}] nonzero bytes follow the zlib stream")
            trailing = len(dec.unused_data)
        else:
            if rom[position:position + 4] != b"DCVM":
                raise ValueError(f"FILE[{index}] unsupported uncompressed resource")
            osz = u32(rom, position + 4)
            if not 24 <= osz <= MAX_RESOURCE_SIZE:
                raise ValueError(f"FILE[{index}] raw DCVM size is invalid")
            cs, end, trailing = osz, position + osz, 0
            if osz > ((meta & 0x0FFFFFFF) + 1) * size_unit:
                raise ValueError(f"FILE[{index}] raw read capacity is too small")
            payload, packed = rom[position:end], b""
        read_cap = ((meta & (0x3FFF if compressed else 0x0FFFFFFF)) + 1) * size_unit
        if end > len(rom) or position + read_cap > len(rom):
            raise ValueError(f"FILE[{index}] read extent exceeds the ROM")
        records.append({"index": index, "name": name, "meta": meta, "offset": position,
                        "compressed": compressed, "size": cs, "end": end,
                        "payload": payload, "packed": packed, "trailing": trailing})
    ordered = sorted(records, key=lambda row: row["offset"])
    for index, record in enumerate(ordered):
        following = ordered[index + 1]["offset"] if index + 1 < len(ordered) else len(rom)
        if record["end"] > following:
            raise ValueError(f"FILE[{record['index']}] overlaps the next resource")
        if any(rom[record["end"]:following]):
            raise ValueError(f"FILE[{record['index']}] nonzero bytes outside indexed payload")
        aligned = (record["end"] + unit - 1) // unit * unit
        if aligned != following:
            raise ValueError(f"FILE[{record['index']}] indexed entry chain contains a gap")
    if not ordered or ordered[0]["offset"] != unit:
        raise ValueError("first indexed resource is not the first archive block")
    directory = sections.get(b"DIR ", b"")
    if len(directory) < 4 or len(directory) < 4 + u32(directory, 0) * 16:
        raise ValueError("invalid DIR record count")
    coverage = Counter()
    for index in range(u32(directory, 0)):
        interval = u32(directory, 4 + index * 16 + 12)
        first, length = interval & 0xFFFF, interval >> 16
        if first + length > count:
            raise ValueError("DIR interval exceeds FILE table")
        coverage.update(range(first, first + length))
    if any(coverage[index] != 1 for index in range(count)):
        raise ValueError("DIR intervals must cover every FILE record once")
    return {"records": records, "sections": sections, "unit": unit}


def inspect_dcvm(data: bytes) -> dict:
    """Verify checksum inputs and STR references without the builder's parser."""
    if len(data) < 24 or data[:4] != b"DCVM" or u32(data, 4) != len(data):
        raise ValueError("DCVM magic or total size mismatch")
    if data[12:16] != b"\x00\x10\x00\x00":
        raise ValueError("DCVM version/flags mismatch")
    sections = parse_sections(data, 16)
    if not sections or sections[-1] != (b"\0" * 4, b""):
        raise ValueError("DCVM is missing its final eight-byte zero section")
    by_tag = dict(sections)
    if not {b"CODE", b"STR ", b"STBL"}.issubset(by_tag):
        raise ValueError("DCVM required sections missing")
    code, strings, table = (by_tag[tag] for tag in (b"CODE", b"STR ", b"STBL"))
    if len(code) < 20 or len(strings) < 8 or len(table) < 4:
        raise ValueError("DCVM required subheader truncated")
    if u32(code, 16) or u32(strings, 4):
        raise ValueError("unexpected CODE/STR XOR obfuscation")
    code_size = u32(code, 8)
    if code_size > len(code) - 20 or len(code) - 20 - code_size > 3 or any(code[20 + code_size:]):
        raise ValueError("CODE byte count or alignment is invalid")
    code_sum = 0
    for index, value in enumerate(code[20:20 + code_size]):
        code_sum = (code_sum + value + index) & 0xFFFFFFFF
        if index & 1:
            code_sum ^= 0xFFFFFFFF
    if code_sum != u32(code, 12):
        raise ValueError("CODE checksum mismatch")
    region = strings[8:]
    records, offsets, position = [], {}, 0
    while position < len(region):
        end = region.find(b"\0", position)
        if end == -1:
            raise ValueError("unterminated STR record")
        offsets[position] = len(records)
        records.append((position, region[position:end]))
        position = end + 1
    count = u32(table, 0)
    if len(table) != 4 + count * 4:
        raise ValueError("STBL count/size mismatch")
    references = list(struct.unpack_from(f"<{count}I", table, 4))
    if any(value not in offsets for value in references):
        raise ValueError("STBL points outside STR record starts")
    record_hashes = {offset: sum(v if v < 128 else v - 256 for v in raw)
                     for offset, raw in records}
    text_sum = sum(record_hashes[offset] for offset in references) & 0xFFFFFFFF
    if text_sum != u32(strings, 0) or (code_sum + text_sum) & 0xFFFFFFFF != u32(data, 8):
        raise ValueError("STR/DCVM checksum mismatch")
    ptbl = by_tag.get(b"PTBL")
    if ptbl and len(ptbl) >= 4 and u32(ptbl, 0) and b"PSTR" not in by_tag:
        raise ValueError("nonempty PTBL requires PSTR")
    return {"header": data[:16], "sections": sections, "by_tag": by_tag,
            "records": records, "record_indices": offsets, "references": references}


def read_table(data: bytes) -> dict[str, bytes]:
    result, reverse = {}, {}
    for row in csv.DictReader(io.StringIO(data.decode("utf-8-sig")), delimiter="\t"):
        char, raw = row.get("char", ""), bytes.fromhex(row.get("code_hex", ""))
        if len(char) != 1 or len(raw) not in (1, 2):
            raise ValueError("code table row must have one character and one/two bytes")
        if len(raw) == 1:
            legal = 0x20 <= raw[0] <= 0x7E or 0xA1 <= raw[0] <= 0xDF
        else:
            legal = ((0x81 <= raw[0] <= 0x9F or 0xE0 <= raw[0] <= 0xFC)
                     and (0x40 <= raw[1] <= 0x7E or 0x80 <= raw[1] <= 0xFC))
        if not legal:
            raise ValueError(f"illegal engine character code: {char!r}={raw.hex()}")
        if char in result and result[char] != raw:
            raise ValueError(f"character has multiple codes: {char!r}")
        if raw in reverse and reverse[raw] != char:
            raise ValueError(f"code has multiple characters: {raw.hex()}")
        result[char], reverse[raw] = raw, char
    if not result:
        raise ValueError("empty font code table")
    return result


def encode_translation(value: str, table: dict[str, bytes]) -> bytes:
    pieces = []
    for char in value:
        if char in "\r\n\t":
            pieces.append(bytes([ord(char)]))
        elif char in table:
            pieces.append(table[char])
        else:
            raise ValueError(f"translation character absent from code table: {char!r}")
    return b"".join(pieces)


def character_codes(raw: bytes) -> set[int]:
    """Tokenize bytes using the engine's actual one/two-byte predicate."""
    result, offset = set(), 0
    while offset < len(raw):
        lead = raw[offset]
        if lead in (9, 10, 13):
            offset += 1
            continue
        if 0x81 <= lead <= 0x9F or 0xE0 <= lead <= 0xFC:
            if offset + 1 >= len(raw) or not (0x40 <= raw[offset + 1] <= 0x7E
                                             or 0x80 <= raw[offset + 1] <= 0xFC):
                raise ValueError(f"invalid double-byte sequence at {offset}: {raw.hex()}")
            result.add(lead * 256 + raw[offset + 1])
            offset += 2
        elif 0x20 <= lead <= 0x7E or 0xA1 <= lead <= 0xDF:
            result.add(lead)
            offset += 1
        else:
            raise ValueError(f"invalid text byte {lead:02x} at {offset}")
    return result


def assert_same_resource_identity(old: dict, new: dict) -> None:
    if old["unit"] != new["unit"] or len(old["records"]) != len(new["records"]):
        raise ValueError("resource count or block units changed")
    for tag, payload in old["sections"].items():
        if tag != b"FILE" and new["sections"].get(tag) != payload:
            raise ValueError(f"non-FILE map section changed: {tag!r}")
    if set(old["sections"]) != set(new["sections"]):
        raise ValueError("map section set changed")
    for before, after in zip(old["records"], new["records"]):
        if before["name"] != after["name"] or before["meta"] & 0xF0000000 != after["meta"] & 0xF0000000:
            raise ValueError(f"FILE[{before['index']}] identity/flags changed")


def inspect_script(old: dict, new: dict, csv_data: bytes,
                   table: dict[str, bytes]) -> tuple[dict, set[int]]:
    assert_same_resource_identity(old, new)
    originals = {row["offset"]: inspect_dcvm(row["payload"]) for row in old["records"]}
    # Resolve source CSV rows as an ordered subsequence of pristine STR records.
    # This keeps duplicate strings tied to their own occurrence.
    row_index, cursors, expected_ids = {}, defaultdict(int), set()
    with (ROOT / EXTRACTED).open(encoding="utf-8-sig", newline="") as handle:
        for line, row in enumerate(csv.DictReader(handle), 2):
            offset = int(row["offset"], 16) - 12
            if offset not in originals:
                raise ValueError(f"extraction row {line}: no original compressed entry")
            records = originals[offset]["records"]
            raw = bytes.fromhex(row["raw_hex"])
            cursor = cursors[offset]
            while cursor < len(records) and records[cursor][1] != raw:
                cursor += 1
            if cursor == len(records):
                raise ValueError(f"extraction row {line}: raw bytes absent/out of sequence")
            cursors[offset] = cursor + 1
            row_index[f"jp{line:06d}"] = (row, offset, records[cursor][0])
            if row["category"] == "jp":
                expected_ids.add(f"jp{line:06d}")
    translations = list(csv.DictReader(io.StringIO(csv_data.decode("utf-8-sig"))))
    seen_ids, replacements, translated_chars = set(), {}, set()
    counts = Counter(rows=len(translations))
    required_codes = {int.from_bytes(raw, "big") for raw in table.values()}
    for row in translations:
        identity = row.get("id", "")
        if identity in seen_ids or identity not in expected_ids:
            raise ValueError(f"translation identity duplicate/unknown: {identity}")
        seen_ids.add(identity)
        source, entry_offset, record_offset = row_index[identity]
        if row.get("offset") != source["offset"] or row.get("source") != source["text"]:
            raise ValueError(f"{identity}: source or container offset differs from original")
        translated = row.get("translation", "").strip()
        if translated:
            encoded = encode_translation(translated, table)
            replacements[(entry_offset, record_offset)] = encoded
            counts["nonempty_rows"] += 1
            translated_chars.update(translated)
            required_codes.update(character_codes(encoded))
        else:
            counts["empty_rows"] += 1
            required_codes.update(character_codes(bytes.fromhex(source["raw_hex"])))
    if seen_ids != expected_ids:
        raise ValueError(f"formal CSV omitted {len(expected_ids - seen_ids)} original Japanese rows")
    counts["distinct_translated_chars"] = len(translated_chars)
    counts["entries"] = len(old["records"])
    counts["raw_entries"] = sum(not item["compressed"] for item in old["records"])
    counts["compressed_entries"] = counts["entries"] - counts["raw_entries"]
    for before, after in zip(old["records"], new["records"]):
        entry_offset = before["offset"]
        original = originals[entry_offset]
        installed = inspect_dcvm(after["payload"])
        old_tags = [tag for tag, _ in original["sections"]]
        if old_tags != [tag for tag, _ in installed["sections"]]:
            raise ValueError(f"entry {entry_offset:#x}: DCVM sections reordered")
        if original["header"][:4] + original["header"][12:] != installed["header"][:4] + installed["header"][12:]:
            raise ValueError(f"entry {entry_offset:#x}: non-size/hash DCVM header bytes changed")
        for tag, payload in original["sections"]:
            if tag not in (b"STR ", b"STBL") and installed["by_tag"][tag] != payload:
                raise ValueError(f"entry {entry_offset:#x}: non-text section {tag!r} changed")
        old_records, new_records = original["records"], installed["records"]
        if len(new_records) < len(old_records) or len(new_records) > len(old_records) + 3:
            raise ValueError(f"entry {entry_offset:#x}: STR record count changed beyond alignment")
        if any(raw for _, raw in new_records[len(old_records):]):
            raise ValueError(f"entry {entry_offset:#x}: nonempty records appended")
        positions = {}
        for index, (old_offset, raw) in enumerate(old_records):
            key = (entry_offset, old_offset)
            expected = replacements.get(key, raw)
            if new_records[index][1] != expected:
                label = "translated" if key in replacements else "untouched"
                raise ValueError(f"entry {entry_offset:#x} STR+{old_offset:#x}: {label} record mismatch")
            positions[old_offset] = new_records[index][0]
            counts["translated_records" if key in replacements else "untouched_records"] += 1
        expected_refs = [positions[value] for value in original["references"]]
        if installed["references"] != expected_refs:
            raise ValueError(f"entry {entry_offset:#x}: STBL semantic target changed")
        counts["stbl_references"] += len(expected_refs)
        if before["payload"] != after["payload"]:
            counts["changed_entries"] += 1
            if after["compressed"] and after["packed"] != zlib.compress(after["payload"], 9):
                raise ValueError(f"entry {entry_offset:#x}: changed script is not the zlib-9 stream")
        elif before["packed"] != after["packed"] and after["compressed"]:
            raise ValueError(f"entry {entry_offset:#x}: untouched compressed bytes changed")
    return dict(counts), required_codes


class UniformRasterAudit:
    """Reproduce the documented profile from TTF files, without the builder."""

    def __init__(self):
        self.fonts = []
        self.used_fonts = set()
        self.cache = {}
        for path in (ROOT / "localization/font/sources/GlowSansSC-Normal-Medium.otf",
                     *(Path("C:/Windows/Fonts") / name
                       for name in ("msgothic.ttc", "simsun.ttc", "seguisym.ttf"))):
            if path.exists():
                with TTFont(str(path), fontNumber=0, lazy=True) as font:
                    self.fonts.append((path, frozenset(font.getBestCmap())))
        if not self.fonts or self.fonts[0][0].name != TEXT_FONT_NAME:
            raise ValueError("uniform font verification requires Glow Sans SC Medium")

    @lru_cache(maxsize=100)
    def face(self, path: str, size: int):
        return ImageFont.truetype(path, size, index=0)

    def render(self, char: str, profile: dict, advance: int) -> tuple[np.ndarray, dict]:
        display = DISPLAY_FORMS.get(char, char)
        key = (display, tuple(sorted(profile.items())), advance)
        if key in self.cache:
            return self.cache[key]
        source = next((path for path, cmap in self.fonts if ord(display) in cmap), None)
        if source is None:
            raise ValueError(f"no source font contains U+{ord(display):04X}")
        allowed = EXPLICIT_SYMBOL_FALLBACKS.get(display, TEXT_FONT_NAME)
        if source.name != allowed:
            raise ValueError(f"unapproved font fallback for U+{ord(display):04X}: {source.name}")
        self.used_fonts.add(source)
        width, height = profile["width"], profile["height"]
        size, baseline = profile["size"], profile["baseline"]
        info = {"font": source.name, "display": display, "pixel_size": size}
        pixels = np.zeros((height, width), dtype=np.uint8)
        if not char.isspace():
            for actual_size in range(size, max(5, size * 2 // 3) - 1, -1):
                canvas = Image.new("L", (width * 4, height * 3), 0)
                ImageDraw.Draw(canvas).text((width, height + baseline), display,
                                            font=self.face(str(source), actual_size),
                                            anchor="ls", fill=255)
                bounds = canvas.getbbox()
                if bounds is None:
                    raise ValueError(f"source font has an empty U+{ord(display):04X}")
                if bounds[1] >= height and bounds[3] <= height * 2:
                    break
            else:
                raise ValueError(f"source glyph U+{ord(display):04X} does not fit its profile")
            ink = canvas.crop((bounds[0], height, bounds[2], height * 2))
            available = max(1, min(width, advance) - 1)
            if ink.width > available:
                ink = ink.resize((available, height), Image.Resampling.LANCZOS)
            pixels[:, :ink.width] = ((np.asarray(ink).astype(np.uint16) * 15 + 127) // 255).astype(np.uint8)
            if not pixels.any():
                raise ValueError(f"source glyph U+{ord(display):04X} vanished after P4 conversion")
            info["pixel_size"] = actual_size
        pixels.setflags(write=False)
        self.cache[key] = (pixels, info)
        return pixels, info

    def render_fonts(self) -> dict:
        return {path.name: {"path": path.as_posix(), **fingerprint(path.read_bytes())}
                for path in sorted(self.used_fonts)}


def indexed_font_records(report: dict, field: str, key: str) -> dict:
    rows = report.get(field)
    if not isinstance(rows, list):
        raise ValueError(f"font report missing {field}")
    result = {}
    for row in rows:
        identity = int(row[key], 16) if key == "code" else row[key]
        if not isinstance(identity, int) or identity in result:
            raise ValueError(f"font report has duplicate/invalid {field} {key}")
        result[identity] = row
    return result


def require_font_record(actual: dict, expected: dict, description: str) -> None:
    for key, value in expected.items():
        if actual.get(key) != value:
            raise ValueError(f"{description}: declared {key} differs from independently verified value")


def inspect_font_glyphs(baseline, font, report: dict, labels: dict[int, str],
                        profile: dict, renderer: UniformRasterAudit) -> dict:
    """Check native repaint, icon preservation and all new mappings/pixels."""
    import dcft
    if report.get("uniform_text_style") is not True or report.get("native_code_gid_and_advances_preserved") is not True:
        raise ValueError("font report does not declare uniform text and preserved native metrics")
    if report.get("profile") != profile:
        raise ValueError("font report profile differs from the accepted physical font slot")
    if (baseline.glyph_w, baseline.glyph_h, baseline.offset_unit) != (
            font.glyph_w, font.glyph_h, font.offset_unit):
        raise ValueError("font raster geometry or bitmap offset unit changed")
    if (font.glyph_w, font.glyph_h) != (profile["width"], profile["height"]):
        raise ValueError("font raster geometry differs from the accepted profile")
    if font.code_limit < baseline.code_limit or font.sections[b"CLUT"][2] != baseline.sections[b"CLUT"][2]:
        raise ValueError("font native bounds/palette changed")
    native = baseline.entries()
    installed = font.entries()
    if len(set(native.values())) != len(native):
        raise ValueError("ambiguous native glyph aliases require explicit review")
    if len(set(installed.values())) != len(installed):
        raise ValueError("installed font maps several codes to the same glyph id")
    if set(installed) != set(native) | set(labels):
        raise ValueError("font contains missing or unexpected character-code mappings")
    repaints = indexed_font_records(report, "repainted_native_glyph_details", "gid")
    preserved = indexed_font_records(report, "preserved_native_glyphs", "gid")
    additions = indexed_font_records(report, "new_glyph_details", "code")
    by_display, expected_text, expected_nontext = {}, set(), set()
    fallback_counts = Counter()
    for code, gid in native.items():
        if installed.get(code) != gid:
            raise ValueError(f"native {code:04X}: glyph id changed")
        if baseline.ls[gid] != font.ls[gid]:
            raise ValueError(f"native {code:04X}: advance changed")
        if int(baseline.image_info[gid]) != int(font.image_info[gid]):
            raise ValueError(f"native {code:04X}: IMGI entry changed")
        try:
            char = code.to_bytes(1 if code <= 0xFF else 2, "big").decode("cp932")
        except UnicodeDecodeError:
            char = ""
        if len(char) != 1 or ord(char) < 0x20 or 0xE000 <= ord(char) <= 0xF8FF:
            expected_nontext.add(gid)
            if gid not in preserved:
                raise ValueError(f"native {code:04X}: missing preserved non-text report")
            require_font_record(preserved[gid], {"code": f"{code:04X}", "gid": gid, "char": "",
                                "reason": "control_private_or_unrecognized_glyph"}, "preserved native glyph")
            if not np.array_equal(baseline.glyph(gid), font.glyph(gid)):
                raise ValueError(f"native {code:04X}: preserved non-text pixels changed")
            continue
        expected_text.add(gid)
        if gid not in repaints:
            raise ValueError(f"native {code:04X}: missing repaint report")
        advance = baseline.ls[gid]
        if advance <= 0:
            raise ValueError(f"native {code:04X}: nonpositive text advance")
        pixels, info = renderer.render(char, profile, advance)
        if not np.array_equal(font.glyph(gid), pixels):
            raise ValueError(f"native {code:04X}: uniform source font pixels do not match")
        require_font_record(repaints[gid], {"code": f"{code:04X}", "gid": gid, "char": char,
                            "advance": advance, **info,
                            "pixels_sha256": fingerprint(dcft.pack_glyph(pixels))["sha256"]}, "native repaint")
        display = info["display"]
        previous = by_display.get(display)
        if previous is not None and (previous["advance"] != advance or
                                     not np.array_equal(previous["pixels"], pixels)):
            raise ValueError(f"native display aliases disagree: U+{ord(display):04X}")
        if previous is None:
            by_display[display] = {"gid": gid, "pixels": pixels, "advance": advance, "info": info}
        if info["font"] != TEXT_FONT_NAME:
            fallback_counts[info["font"]] += 1
    if set(repaints) != expected_text or set(preserved) != expected_nontext:
        raise ValueError("font repaint/preservation report coverage does not match native glyphs")
    if report.get("repainted_native_glyphs") != len(expected_text):
        raise ValueError("font repaint report count differs from native text glyphs")
    expected_added = set(labels) - set(native)
    if set(additions) != expected_added or report.get("new_glyphs") != len(expected_added):
        raise ValueError("font new glyph report coverage/count does not match required codes")
    for code in sorted(expected_added):
        char, record = labels[code], additions[code]
        gid = installed[code]
        alias = by_display.get(DISPLAY_FORMS.get(char, char))
        if alias is None:
            advance = profile["advance"]
            pixels, info = renderer.render(char, profile, advance)
            if "copied_native_gid" in record:
                raise ValueError(f"new {code:04X}: falsely declared native alias")
        else:
            advance, pixels = alias["advance"], alias["pixels"]
            info = {**alias["info"], "copied_native_gid": alias["gid"]}
        require_font_record(record, {"code": f"{code:04X}", "gid": gid, "char": char,
                            "advance": advance, **info}, "new glyph")
        if font.ls[gid] != advance or not np.array_equal(font.glyph(gid), pixels):
            raise ValueError(f"new {code:04X}: unified pixels/advance differ from source font")
        if info["font"] != TEXT_FONT_NAME:
            fallback_counts[info["font"]] += 1
    for code, char in labels.items():
        gid = installed[code]
        if font.ls[gid] <= 0 or (not char.isspace() and not font.glyph(gid).any()):
            raise ValueError(f"required {code:04X}: blank glyph or nonpositive advance")
    if report.get("coverage_checked") != len(labels):
        raise ValueError("font declared coverage differs from required text codes")
    return {"native_code_gid_advance_imgi_preserved": len(native),
            "native_text_glyphs_repainted": len(expected_text),
            "native_nontext_glyphs_preserved": len(expected_nontext),
            "new_text_glyphs_verified": len(expected_added),
            "source_pixels_checked": len(expected_text) + len(expected_added),
            "symbol_fallback_glyphs": dict(fallback_counts)}


def inspect_fonts(old: dict, new: dict, table: dict[str, bytes],
                  required_codes: set[int], report: dict) -> dict:
    import dcft  # Shares the eboot-verified lookup/bitmap model, never the builder.
    assert_same_resource_identity(old, new)
    # Original Japanese has both singleton and fullwidth encodings for 52
    # characters. Keep every raw code; the release encoder has one per char.
    labels = {}
    with (ROOT / ORIGINAL_CODES).open(encoding="utf-8-sig", newline="") as handle:
        for row in csv.DictReader(handle, delimiter="\t"):
            raw, char = bytes.fromhex(row["code_hex"]), row["char"]
            codes = character_codes(raw)
            if len(char) != 1 or len(codes) != 1 or len(raw) not in (1, 2):
                raise ValueError("invalid original character-code row")
            code = next(iter(codes))
            if code in labels and labels[code] != char:
                raise ValueError("original byte code has conflicting characters")
            labels[code] = char
    required_codes = set(required_codes) | set(labels)
    for char, raw in table.items():
        code = int.from_bytes(raw, "big")
        if code in labels and labels[code] != char:
            raise ValueError("release table overrides an original character binding")
        labels[code] = char
    for code, char in list(labels.items()):
        if 0xA1 <= code <= 0xDF:
            display = DISPLAY_FORMS.get(char, char)
            normalized = display.encode("cp932")
            if len(normalized) == 2:
                target = int.from_bytes(normalized, "big")
                if target in labels and labels[target] != display:
                    raise ValueError("Buriko display normalization conflicts with the code table")
                required_codes.add(target)
                labels[target] = display
    if required_codes != set(labels):
        raise ValueError("font coverage contains unlabeled codes or omits required labels")
    if report.get("uniform_text_style") is not True or report.get("font_count") != 6:
        raise ValueError("font manifest does not declare all six unified font slots")
    font_reports = indexed_font_records(report, "fonts", "original_offset")
    expected_offsets = {row["offset"] for row in old["records"] if row["payload"][:4] == b"DCFT"}
    if set(font_reports) != expected_offsets:
        raise ValueError("font manifest slot offsets do not match pristine font resources")
    physical_slots = {row["offset"]: ordinal for ordinal, row in
                      enumerate(sorted(old["records"], key=lambda row: row["offset"]))}
    renderer = UniformRasterAudit()
    slots, totals = [], Counter()
    for before, after in zip(old["records"], new["records"]):
        if before["payload"][:4] != b"DCFT":
            if before["payload"] != after["payload"]:
                raise ValueError(f"rodata FILE[{before['index']}]: non-font resource changed")
            continue
        baseline = dcft.parse_dcft(before["payload"])
        font = dcft.parse_dcft(after["payload"], strict=True)
        ordinal = physical_slots[before["offset"]]
        if ordinal not in UNIFIED_FONT_PROFILES:
            raise ValueError(f"unexpected physical font slot {ordinal}")
        slot_report = font_reports[before["offset"]]
        require_font_record(slot_report, {"entry_index": ordinal, "rebuilt_bytes": len(after["payload"]),
                            "rebuilt_glyphs": font.n_glyph}, "font slot")
        problems = dcft.verify_dcft(after["payload"], strict=True)
        if problems:
            raise ValueError(f"font FILE[{before['index']}]: {'; '.join(problems)}")
        stats = inspect_font_glyphs(baseline, font, slot_report, labels,
                                   UNIFIED_FONT_PROFILES[ordinal], renderer)
        totals.update({key: value for key, value in stats.items() if isinstance(value, int)})
        if before["payload"] != after["payload"] and after["packed"] != zlib.compress(after["payload"], 9):
            raise ValueError(f"font FILE[{before['index']}]: changed font is not the zlib-9 stream")
        slots.append({"file_index": before["index"], "physical_font_slot": ordinal, "old_offset": before["offset"],
                      "offset": after["offset"], "width": font.glyph_w, "height": font.glyph_h,
                      "glyphs": font.n_glyph, "required_codes_checked": len(required_codes), **stats})
    if len(slots) != 6:
        raise ValueError(f"expected six original DCFT fonts, found {len(slots)}")
    source_fonts = renderer.render_fonts()
    if report.get("render_fonts") != source_fonts:
        raise ValueError("font source paths/fingerprints differ from the files used to reproduce pixels")
    return {"slots": slots, "required_codes": len(required_codes), **dict(totals),
            "uniform_text_style": True, "render_fonts": source_fonts}


def read_csv_bytes(data: bytes, fields: list[str]) -> list[dict]:
    reader = csv.DictReader(io.StringIO(data.decode("utf-8-sig"), newline=""))
    if reader.fieldnames != fields:
        raise ValueError(f"csv columns {reader.fieldnames} != {fields}")
    return list(reader)


def inspect_installed_eboot(eboot_bytes: bytes, translation_csv: bytes, manifest_eboot: dict) -> dict:
    """eboot 深检：假 SELF 结构、基线↔导入源↔安装字节三方一致。

    提取基线来自工作区固定文件（只读）；导入源按清单 sources 指纹先行核对。
    """
    import eboot_text

    inspected = eboot_text.inspect_fake_self(eboot_bytes)
    rows = read_csv_bytes(translation_csv, list(eboot_text.TRANSLATION_FIELDS))
    baseline = read_csv_bytes((ROOT / EBOOT_EXTRACTION).read_bytes(),
                              list(eboot_text.EXTRACTION_FIELDS))
    if len(rows) != len(baseline):
        raise ValueError(f"eboot import source has {len(rows)} rows, baseline has {len(baseline)}")
    installed = {row["offset"] - eboot_text.HEADER_SIZE: row["source"] for row in inspected["strings"]}
    if len(inspected["strings"]) != len(rows):
        raise ValueError(f"installed eboot exposes {len(inspected['strings'])} strings, expected {len(rows)}")
    translated = 0
    for row, want in zip(rows, baseline):
        if row["id"] != want["id"] or int(row["offset"], 16) != int(want["offset"], 16) \
                or row["source"] != want["source"]:
            raise ValueError(f"eboot import source drift at row {row['id']}")
        expected = row["translation"] or row["source"]
        actual = installed.get(int(row["offset"], 16))
        if actual != expected:
            raise ValueError(f"installed eboot mismatch at {row['id']} ({row['offset']})")
        translated += 1 if row["translation"] else 0
    if manifest_eboot.get("installed_sha256") != fingerprint(eboot_bytes)["sha256"]:
        raise ValueError("manifest eboot report does not match the installed executable")
    return {"strings": len(inspected["strings"]), "translated": translated,
            "sha256": inspected["sha256"]}


def verify_release(release_dir: Path = ROOT) -> dict:
    release_dir = Path(release_dir).resolve()
    result = {"ok": False, "game_id": "PCSG00337", "release_dir": str(release_dir),
              "checked_at": datetime.now().isoformat(timespec="seconds"), "errors": []}
    try:
        manifest_path = release_dir / "localization/build_manifest.json"
        manifest = json.loads(manifest_path.read_text(encoding="utf-8-sig"))
        if manifest.get("game_id", manifest.get("title_id")) != "PCSG00337":
            raise ValueError("manifest game_id is not PCSG00337")
        files = manifest.get("files")
        if not isinstance(files, dict):
            raise ValueError("manifest has no files fingerprint map")
        file_data = {}
        for raw_name, expected in files.items():
            name = relative_name(raw_name)
            data = (release_dir / name).read_bytes()
            actual = fingerprint(data)
            if actual["bytes"] != expected.get("bytes") or actual["sha256"] != expected.get("sha256"):
                raise ValueError(f"release fingerprint mismatch: {name}")
            file_data[name] = data
        if set(REQUIRED_FILES) - file_data.keys():
            raise ValueError("manifest omitted required resource/CSV/code-table files")
        result["file_fingerprints_checked"] = len(file_data)
        provenance = {}
        for section in ("sources", "baseline", "baselines", "source_hashes"):
            entries = manifest.get(section, {})
            if not isinstance(entries, dict):
                continue
            for key, expected in entries.items():
                if not isinstance(expected, dict) or "sha256" not in expected:
                    continue
                name = relative_name(expected.get("path", key))
                provenance[name] = expected
        if set(REQUIRED_SOURCES) - provenance.keys():
            missing = sorted(set(REQUIRED_SOURCES) - provenance.keys())
            raise ValueError(f"manifest omitted baseline/extraction fingerprints: {missing}")
        for name, expected in provenance.items():
            data = file_data[name] if name in file_data else (ROOT / name).read_bytes()
            actual = fingerprint(data)
            if actual["sha256"] != expected["sha256"] or (
                    "bytes" in expected and actual["bytes"] != expected["bytes"]):
                raise ValueError(f"source fingerprint mismatch: {name}")
        result["source_fingerprints_checked"] = len(provenance)
        required_sources = set(REQUIRED_SOURCES)
        if "eboot.bin" in files:
            required_sources.update((EBOOT_BASE, EBOOT_EXTRACTION))
        if required_sources - provenance.keys():
            missing = sorted(required_sources - provenance.keys())
            raise ValueError(f"manifest omitted baseline/extraction fingerprints: {missing}")
        if fingerprint((ROOT / SCRIPT_BASE).read_bytes())["sha256"] != PRISTINE_SHA256:
            raise ValueError("pristine script ROM is not the confirmed original")
        if "eboot.bin" in file_data:
            csv_path = release_dir / EBOOT_TRANSLATION
            translation_csv = (csv_path if csv_path.exists() else ROOT / EBOOT_TRANSLATION).read_bytes()
            result["eboot"] = inspect_installed_eboot(file_data["eboot.bin"], translation_csv,
                                                      manifest.get("eboot", {}))
        table = read_table(file_data[CODE_TABLE])
        result["code_table_characters"] = len(table)
        translation_sha = fingerprint(file_data[TRANSLATION])["sha256"]
        if manifest.get("translation_sync", {}).get("sha256") != translation_sha:
            raise ValueError("translation-sync report does not match packaged CSV")
        if manifest.get("code_table", {}).get("translation_sha256") != translation_sha:
            raise ValueError("code table was built from a different translation snapshot")
        if manifest.get("script", {}).get("translation", {}).get("sha256") != translation_sha:
            raise ValueError("script report references a different translation snapshot")
        script_table = json.dumps({char: raw.hex() for char, raw in sorted(table.items())},
                                  ensure_ascii=True, separators=(",", ":")).encode("ascii")
        font_table = json.dumps({char: raw.hex().upper() for char, raw in sorted(table.items())},
                                ensure_ascii=False, sort_keys=True).encode("utf-8")
        if manifest["script"].get("code_table_sha256") != fingerprint(script_table)["sha256"]:
            raise ValueError("script report references a different character-code mapping")
        if manifest.get("font", {}).get("code_table_sha256") != fingerprint(font_table)["sha256"]:
            raise ValueError("font report references a different character-code mapping")
        script_old_rom, script_new_rom = (ROOT / SCRIPT_BASE).read_bytes(), file_data["rom/script.rom"]
        font_old_rom, font_new_rom = (ROOT / FONT_BASE).read_bytes(), file_data["rom/rodata.rom"]
        if script_old_rom[:0x400] != script_new_rom[:0x400] or font_old_rom[:0x400] != font_new_rom[:0x400]:
            raise ValueError("opaque ROM header bytes changed")
        script_old = inspect_map(script_old_rom, (ROOT / SCRIPT_MAP_BASE).read_bytes())
        script_new = inspect_map(script_new_rom, file_data["map/script.map"])
        font_old = inspect_map(font_old_rom, (ROOT / FONT_MAP_BASE).read_bytes())
        font_new = inspect_map(font_new_rom, file_data["map/rodata.map"])
        result["script"], required_codes = inspect_script(
            script_old, script_new, file_data[TRANSLATION], table)
        result["font"] = inspect_fonts(font_old, font_new, table, required_codes, manifest["font"])
        result["ok"] = True
        result["runtime_verified"] = False
        result["scope"] = ("On-disk integrity, exact text, pointers and code coverage; independently reproduced "
                           "unified font pixels with preserved native code/glyph ids, advances, IMGI entries and non-text icons; "
                           "plaintext fake-SELF eboot checked against the import source and extraction baseline.")
    except (OSError, ValueError, KeyError, IndexError, TypeError, struct.error, zlib.error) as error:
        result["errors"].append(f"{type(error).__name__}: {error}")
    return result


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--release-dir", type=Path, default=ROOT,
                        help="Candidate root containing rom/map/localization, or installed game root.")
    parser.add_argument("--output", type=Path, help="Optional diagnostic JSON; use archive/YYYY-MM/.")
    args = parser.parse_args()
    result = verify_release(args.release_dir)
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n",
                               encoding="utf-8")
    print(json.dumps(result, ensure_ascii=False, indent=2))
    return 0 if result["ok"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
