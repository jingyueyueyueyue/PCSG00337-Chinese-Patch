#!/usr/bin/env python3
"""Build six complete font slots from the pristine PCSG00337 rodata pair.

This module never installs files or allocates character codes.  The main
localization importer supplies the exact same char -> bytes mapping to
this builder and to the script encoder, then publishes their validated
outputs together. Native code/glyph ids and metrics are retained, while all
recognizable text is redrawn with one font profile per slot. Non-text and
unrecognized glyphs keep their original image bytes.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import io
import json
import zlib
from functools import lru_cache
from pathlib import Path

import numpy as np
from fontTools.ttLib import TTFont
from PIL import Image, ImageDraw, ImageFont

import dcft

ROOT = Path(__file__).resolve().parents[2]
ORIG_ROM = ROOT / "archive/2026-09/20260908_rodata_pristine.rom"
ORIG_MAP = ROOT / "archive/2026-09/20260908_rodata_map_pristine.map"
ORIG_ROM_SHA256 = "f5d681a7b14d1d5ae642a26e17023a409141d455d33d0da4a33654f7096033b8"
ORIG_MAP_SHA256 = "00f03d815a89ab0fb6cd90927dd36c3d78d9329148ce2a6395f351e3f343e174"
CODE_TABLE = ROOT / "localization/font/generated/font_code_table_reset.tsv"
ORIGINAL_CODES = ROOT / "extracted/script/custom_code_table.tsv"

# Measured from the six original rasters, not copied from PCSG00378.
# Native CJK median (advance, top, bottom): (41,1,42), (43,1,41),
# (40,1,41), (34,1,37), no CJK in the 16px slot, and (26,1,28).
FONT_PROFILES = {
    1: {"width": 48, "height": 48, "advance": 41, "size": 44, "baseline": 37},
    2: {"width": 48, "height": 48, "advance": 43, "size": 44, "baseline": 36},
    3: {"width": 48, "height": 48, "advance": 40, "size": 44, "baseline": 36},
    4: {"width": 48, "height": 48, "advance": 34, "size": 40, "baseline": 32},
    5: {"width": 16, "height": 16, "advance": 14, "size": 14, "baseline": 12},
    6: {"width": 48, "height": 48, "advance": 26, "size": 30, "baseline": 24},
}
# 正文统一用未来荧黑（Glow Sans SC, OFL）Medium 重量；拉丁字母源自
# Fira Sans/Raleway，与汉字粗细匹配，优于此前微软雅黑的细拉丁。
# 荧黑只缺 ☆(U+2606) 与 ♪(U+266A) 两个符号，优先回退到同为黑体的
# MS Gothic；simsun/seguisym 仅作兜底。
CJK_FONTS = (str(ROOT / "localization/font/sources/GlowSansSC-Normal-Medium.otf"),
             "C:/Windows/Fonts/msgothic.ttc", "C:/Windows/Fonts/simsun.ttc",
             "C:/Windows/Fonts/seguisym.ttf")
# Buriko stores voiced marks separately.  Their standalone visible glyphs
# are spacing dakuten/handakuten; the source Unicode often uses combining
# marks.  Existing precomposed kana and their original bitmaps are untouched.
DISPLAY_FORMS = {"\u3099": "\u309b", "\u309a": "\u309c"}


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def read_code_table(path: Path = CODE_TABLE) -> dict[str, bytes]:
    result = {}
    with Path(path).open(encoding="utf-8-sig", newline="") as handle:
        for row in csv.DictReader(handle, delimiter="\t"):
            char = row["char"]
            if char in result:
                raise ValueError(f"duplicate character in code table: U+{ord(char):04X}")
            result[char] = bytes.fromhex(row["code_hex"])
    validate_code_table(result)
    return result


def validate_code_table(table: dict[str, bytes]) -> None:
    reverse = {}
    for char, raw in table.items():
        if len(char) != 1 or not isinstance(raw, bytes) or not dcft.valid_text_code(raw):
            raise ValueError(f"invalid character/code binding: {char!r} -> {raw!r}")
        if raw in reverse and reverse[raw] != char:
            raise ValueError(f"code {raw.hex().upper()} assigned to multiple characters")
        reverse[raw] = char


def required_code_characters(code_table: dict[str, bytes]) -> dict[int, str]:
    """Cover assigned codes, original byte aliases and Buriko display forms.

    Original scripts can use several encodings for the same character.
    Add all original bindings instead of assuming the chosen encoder form
    is the only one that will ever reach the font manager.
    """
    validate_code_table(code_table)
    required = {int.from_bytes(raw, "big"): char for char, raw in code_table.items()}
    if ORIGINAL_CODES.exists():
        with ORIGINAL_CODES.open(encoding="utf-8-sig", newline="") as handle:
            for row in csv.DictReader(handle, delimiter="\t"):
                char, raw = row["char"], bytes.fromhex(row["code_hex"])
                if len(char) != 1 or not dcft.valid_text_code(raw):
                    raise ValueError("invalid pristine original-code table row")
                code = int.from_bytes(raw, "big")
                if code in required and required[code] != char:
                    raise ValueError(f"assigned code {code:04X} overrides an original character")
                required[code] = char
    for code, char in list(required.items()):
        if 0xA1 <= code <= 0xDF:
            display = DISPLAY_FORMS.get(char, char)
            try:
                raw = display.encode("cp932")
            except UnicodeEncodeError:
                continue
            if len(raw) == 2:
                normalized_code = int.from_bytes(raw, "big")
                if normalized_code in required and required[normalized_code] != display:
                    raise ValueError(f"Buriko display form collides at {normalized_code:04X}")
                required[normalized_code] = display
    return dict(sorted(required.items()))


def native_codepoints(baseline_rom: Path = ORIG_ROM) -> set[int]:
    rom = Path(baseline_rom).read_bytes()
    if sha256(rom) != ORIG_ROM_SHA256:
        raise ValueError("baseline ROM SHA256 mismatch")
    result = set()
    for position, compressed, _expanded in dcft.iter_rodata_items(rom):
        payload = zlib.decompress(rom[position + 12:position + 12 + compressed])
        if payload[:4] == b"DCFT":
            result.update(dcft.parse_dcft(payload).entries())
    return result


class GlyphRenderer:
    def __init__(self):
        self.fonts = []
        for name in CJK_FONTS:
            path = Path(name)
            if path.exists():
                with TTFont(str(path), fontNumber=0, lazy=True) as font:
                    supported = frozenset(font.getBestCmap())
                self.fonts.append((path, supported))
        if not self.fonts or self.fonts[0][0].name != "GlowSansSC-Normal-Medium.otf":
            raise FileNotFoundError("Glow Sans SC Medium (未来荧黑) is required for text glyphs")

    @lru_cache(maxsize=100)
    def _font(self, path: str, size: int):
        return ImageFont.truetype(path, size, index=0)

    def render_with_info(self, char: str, *, width: int, height: int,
                         advance: int, size: int, baseline: int) -> tuple[np.ndarray, dict]:
        display = DISPLAY_FORMS.get(char, char)
        candidates = [(path, chars) for path, chars in self.fonts if ord(display) in chars]
        if not candidates:
            raise ValueError(f"no font contains U+{ord(char):04X}")
        path = candidates[0][0]
        info = {"font": path.name, "display": display, "pixel_size": size}
        if char.isspace():
            return np.zeros((height, width), dtype=np.uint8), info
        for pixel_size in range(size, max(5, size * 2 // 3) - 1, -1):
            font = self._font(str(path), pixel_size)
            canvas = Image.new("L", (width * 4, height * 3), 0)
            ImageDraw.Draw(canvas).text((width, height + baseline), display, font=font,
                                        fill=255, anchor="ls")
            raster = np.asarray(canvas)
            ys, xs = np.nonzero(raster)
            if not len(xs):
                raise ValueError(f"U+{ord(char):04X} produced an empty glyph")
            if int(ys.min()) >= height and int(ys.max()) < height * 2:
                break
        else:
            raise ValueError(f"U+{ord(char):04X} cannot fit its {width}x{height} font cell")
        ink = raster[height:height * 2, int(xs.min()):int(xs.max()) + 1]
        max_width = max(1, min(width, advance) - 1)
        if ink.shape[1] > max_width:
            ink = np.asarray(Image.fromarray(ink).resize((max_width, height), Image.Resampling.LANCZOS))
        cell = np.zeros((height, width), dtype=np.uint8)
        # Original PCSG00337 glyphs begin at x=0; keep new glyphs at that origin.
        cell[:, :ink.shape[1]] = ink
        info["pixel_size"] = pixel_size
        pixels = ((cell.astype(np.uint16) * 15 + 127) // 255).astype(np.uint8)
        if not np.any(pixels):
            raise ValueError(f"U+{ord(char):04X} vanished during P4 quantization")
        return pixels, info

    def render(self, char: str, **profile) -> np.ndarray:
        return self.render_with_info(char, **profile)[0]

    def source_fingerprints(self, used_names: set[str]) -> dict:
        result = {}
        for path, _supported in self.fonts:
            if path.name in used_names:
                data = path.read_bytes()
                result[path.name] = {"path": path.as_posix(), "bytes": len(data), "sha256": sha256(data)}
        if set(result) != used_names:
            raise ValueError("rendering used an unrecorded font source")
        return result


def native_glyph_characters(font: dcft.Dcft) -> dict[int, tuple[int, str]]:
    """Identify original text without mistaking custom icons for Unicode."""
    result = {}
    for code, gid in font.entries().items():
        try:
            char = code.to_bytes(1 if code <= 0xFF else 2, "big").decode("cp932")
        except UnicodeDecodeError:
            char = ""
        if len(char) != 1 or ord(char) < 0x20 or 0xE000 <= ord(char) <= 0xF8FF:
            char = ""
        result[gid] = (code, char)
    return result


def repaint_native_font(data: bytes, profile: dict, renderer: GlyphRenderer) -> tuple[bytes, dict, dict]:
    """Return a unified native font, per-display aliases, and repaint evidence."""
    font = dcft.parse_dcft(data)
    pixels = {}
    details = []
    preserved = []
    by_display = {}
    for gid, (code, char) in native_glyph_characters(font).items():
        if not char:
            preserved.append({"code": f"{code:04X}", "gid": gid, "char": char,
                              "reason": "control_private_or_unrecognized_glyph"})
            continue
        advance = font.ls[gid]
        if advance <= 0:
            raise ValueError(f"native text glyph {gid} has no advance")
        parameters = {**profile, "advance": advance}
        glyph, info = renderer.render_with_info(char, **parameters)
        pixels[gid] = glyph
        display = info["display"]
        if display in by_display:
            previous = by_display[display]
            if advance != previous["advance"] or not np.array_equal(glyph, previous["pixels"]):
                raise ValueError(f"native Unicode aliases disagree for U+{ord(display):04X}")
        else:
            by_display[display] = {"gid": gid, "pixels": glyph, "advance": advance, "info": info}
        details.append({"code": f"{code:04X}", "gid": gid, "char": char,
                        "advance": advance, **info,
                        "pixels_sha256": sha256(dcft.pack_glyph(glyph))})
    repainted = dcft.repaint_font(data, pixels)
    new = dcft.parse_dcft(repainted)
    for tag in dcft.SECTION_TAGS:
        if tag != b"IMGD" and font.sections[tag][2] != new.sections[tag][2]:
            raise ValueError("repainting changed native lookup or metrics")
    for gid, expected in pixels.items():
        if not np.array_equal(new.glyph(gid), expected):
            raise ValueError("native unified glyph failed P4 readback")
    for record in preserved:
        gid = record["gid"]
        if not np.array_equal(new.glyph(gid), font.glyph(gid)):
            raise ValueError("repainting changed a preserved non-text glyph")
    return repainted, by_display, {
        "repainted_native_glyphs": len(details),
        "repainted_native_glyph_details": details,
        "preserved_native_glyphs": preserved,
        "native_code_gid_and_advances_preserved": True,
        "uniform_text_style": True,
    }


def font_evidence(font: dcft.Dcft) -> dict:
    entries = font.entries()
    native_count = max(entries.values()) + 1
    boxes = []
    for code, gid in entries.items():
        try:
            char = code.to_bytes(1 if code <= 0xFF else 2, "big").decode("cp932")
        except UnicodeDecodeError:
            continue
        if len(char) != 1 or not 0x4E00 <= ord(char) <= 0x9FFF:
            continue
        y, x = np.nonzero(font.glyph(gid))
        if len(x):
            boxes.append([int(x.min()), int(y.min()), int(x.max()), int(y.max()), font.ls[gid]])
    return {
        "width": font.glyph_w, "height": font.glyph_h,
        "code_limit": font.code_limit, "offset_unit": font.offset_unit,
        "ls_length": len(font.ls), "imgi_length": len(font.image_info),
        "bitmap_blocks": font.n_blocks, "native_glyphs": native_count,
        "grp_u16_length": len(font.g), "fnt_u16_length": len(font.f),
        "legacy_imgi_overrun": font.legacy_imgi_overrun,
        "native_bitmap_sha256": sha256(font.bm),
        "cjk_median_left_top_right_bottom_advance": np.median(boxes, axis=0).tolist() if boxes else [],
        "anchors": {f"{code:04X}": font.lookup(code)
                    for code in (0x20, 0x41, 0xA1, 0x8140, 0x8141, 0x82A0, 0x889F, 0x97A2)},
    }


def preview(fonts: dict[int, dcft.Dcft], code_table: dict[str, bytes]) -> bytes:
    # Match the user's menu screenshot and the opening train announcement.
    samples = ("\u8981\u5f00\u59cb\u6e38\u620f\u5417\uff1f", "\u7ec8\u70b9\u7ad9\uff0c\u53e4\u6865 / \u5e7f\u64ad")
    lines = ["".join(char for char in sample if char in code_table) for sample in samples]
    if not any(lines):
        lines = ["".join(list(code_table)[:16])]
    width = max(880, 80 + max(map(len, lines)) * 52)
    canvas = Image.new("RGB", (width, 88 + len(fonts) * 144), "#eee8df")
    draw = ImageDraw.Draw(canvas)
    label = ImageFont.truetype("C:/Windows/Fonts/msyh.ttc", 16)
    draw.text((20, 12), "PCSG00337 - one text font profile for native and new glyphs", fill="#342f29", font=label)
    draw.text((20, 38), "Six slots / preserved native metrics / verified IMGI + P4 readback", fill="#75664e", font=label)
    for ordinal, (index, font) in enumerate(fonts.items()):
        top = 86 + ordinal * 144
        draw.text((16, top), f"Font {index} / {font.glyph_w}x{font.glyph_h}", fill="#51432f", font=label)
        for line_number, text in enumerate(lines):
            x = 20
            for char in text:
                gid = font.lookup(int.from_bytes(code_table[char], "big"))
                if gid is None:
                    raise ValueError("preview found a missing glyph")
                gray = (font.glyph(gid) * 17).astype(np.uint8)
                scale = 2 if font.glyph_h == 16 else 1
                alpha = Image.fromarray(gray).resize((font.glyph_w * scale, font.glyph_h * scale), Image.Resampling.NEAREST)
                ink = Image.new("RGB", alpha.size, "#584129")
                canvas.paste(ink, (x, top + 30 + line_number * 48), alpha)
                x += max(font.ls[gid] * scale, 8)
    buffer = io.BytesIO()
    canvas.save(buffer, format="PNG")
    return buffer.getvalue()


def build_font_bundle(code_table: dict[str, bytes] | None = None, *,
                      baseline_rom: Path = ORIG_ROM, baseline_map: Path = ORIG_MAP,
                      table_path: Path = CODE_TABLE) -> dict:
    """Return validated rom/map/preview_png/report byte strings in memory."""
    rom = Path(baseline_rom).read_bytes()
    map_data = Path(baseline_map).read_bytes()
    if sha256(rom) != ORIG_ROM_SHA256 or sha256(map_data) != ORIG_MAP_SHA256:
        raise ValueError("baseline ROM/map SHA256 mismatch; use the pristine PCSG00337 pair")
    table = read_code_table(table_path) if code_table is None else dict(code_table)
    required = required_code_characters(table)
    renderer = GlyphRenderer()
    replacements = {}
    reports = []
    rebuilt_fonts = {}
    for index, (position, compressed, expanded) in enumerate(dcft.iter_rodata_items(rom)):
        data = zlib.decompress(rom[position + 12:position + 12 + compressed])
        if len(data) != expanded:
            raise ValueError("baseline decompressed-size mismatch")
        if data[:4] != b"DCFT":
            continue
        font = dcft.parse_dcft(data)
        if index not in FONT_PROFILES:
            raise ValueError(f"unexpected font entry {index}")
        profile = FONT_PROFILES[index]
        if (font.glyph_w, font.glyph_h) != (profile["width"], profile["height"]):
            raise ValueError(f"font {index} has unexpected raster dimensions")
        repainted, native_by_display, repaint_report = repaint_native_font(data, profile, renderer)
        additions = {}
        glyph_report = []
        for code, char in required.items():
            if font.lookup(code) is not None:
                continue
            advance = profile["advance"]
            native = native_by_display.get(DISPLAY_FORMS.get(char, char))
            if native is not None:
                # Alternate encodings receive the same newly unified glyph,
                # not the old Japanese raster that caused mixed typography.
                pixels, advance = native["pixels"], native["advance"]
                rendering = {**native["info"], "copied_native_gid": native["gid"]}
            else:
                pixels, rendering = renderer.render_with_info(char, **profile)
            additions[code] = (pixels, advance)
            glyph_report.append({"code": f"{code:04X}", "char": char,
                                 "advance": advance, **rendering})
        rebuilt_data, info = dcft.extend_font(repainted, additions)
        rebuilt = dcft.parse_dcft(rebuilt_data, strict=True)
        for code, char in required.items():
            gid = rebuilt.lookup(code)
            if gid is None:
                raise ValueError(f"font {index} missing code {code:04X} after extension")
            if not char.isspace() and not np.any(rebuilt.glyph(gid)):
                raise ValueError(f"font {index} has a blank glyph for {code:04X}")
        for record in glyph_report:
            record["gid"] = info["new_gids"][int(record["code"], 16)]
        reports.append({"entry_index": index, "original_offset": position,
                        "original_evidence": font_evidence(font), "profile": profile,
                        "rebuilt_bytes": len(rebuilt_data), "rebuilt_glyphs": len(rebuilt.ls),
                        **{key: value for key, value in info.items() if key != "new_gids"},
                        **repaint_report,
                        "coverage_checked": len(required), "new_glyph_details": glyph_report})
        replacements[position] = rebuilt_data
        rebuilt_fonts[index] = rebuilt
    if set(rebuilt_fonts) != set(FONT_PROFILES):
        raise ValueError("not all six original font slots were processed")
    new_rom, new_map = dcft.rebuild_rodata_and_map(rom, map_data, replacements)
    # Parse the packaged stream again, not just the pre-compression objects.
    for index in FONT_PROFILES:
        packaged = dcft.find_font_entry(new_rom, index)[3]
        expected = rebuilt_fonts[index].data
        if packaged != expected or dcft.verify_dcft(packaged, strict=True):
            raise ValueError("font changed during rodata packaging")
    table_digest = sha256(json.dumps({char: raw.hex().upper() for char, raw in sorted(table.items())},
                                    ensure_ascii=False, sort_keys=True).encode("utf-8"))
    used_font_names = {glyph["font"] for item in reports
                       for key in ("repainted_native_glyph_details", "new_glyph_details")
                       for glyph in item[key]}
    report = {
        "game": "PCSG00337", "baseline_rom_sha256": sha256(rom),
        "baseline_map_sha256": sha256(map_data), "rom_sha256": sha256(new_rom),
        "map_sha256": sha256(new_map), "code_table_sha256": table_digest,
        "assigned_characters": len(table), "required_codes_including_original_aliases": len(required),
        "font_count": len(reports), "fonts": reports,
        "rodata_size": len(new_rom), "map_pair_validation": "passed",
        "native_glyph_policy": "preserve code/glyph ids, advances and IMGI entries; uniformly repaint recognized text; retain non-text icons",
        "uniform_text_style": True,
        "text_font": "Glow Sans SC Normal Medium (未来荧黑 v0.93); fixed per-slot size/baseline; explicit symbol fallback where absent",
        "render_fonts": renderer.source_fingerprints(used_font_names),
        "buriko_policy": "cover raw single-byte codes and their original CP932 display forms",
        "rendering": {"lookup": "gid = FNT[GRP[index >> 4] + (index & 15)]",
                      "index": "code >= 0x8140 ? code - 0x8040 : code",
                      "bitmap": "(IMGI[gid] & 0x3FFFFF) * DCFT.u16[0x0E]",
                      "p4": "left pixel in low nibble; right pixel in high nibble"},
    }
    return {"rom": new_rom, "map": new_map, "preview_png": preview(rebuilt_fonts, table),
            "report": report}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline-rom", type=Path, default=ORIG_ROM)
    parser.add_argument("--baseline-map", type=Path, default=ORIG_MAP)
    parser.add_argument("--code-table", type=Path, default=CODE_TABLE)
    parser.add_argument("--out-dir", type=Path)
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()
    if not args.dry_run and args.out_dir is None:
        parser.error("supply --out-dir for a candidate, or --dry-run; installation belongs to the main importer")
    bundle = build_font_bundle(baseline_rom=args.baseline_rom, baseline_map=args.baseline_map,
                               table_path=args.code_table)
    if args.out_dir and not args.dry_run:
        output = args.out_dir.resolve()
        if output == ROOT or ROOT / "rom" in output.parents or output == ROOT / "rom":
            raise ValueError("font builder may only write a separate candidate directory")
        for relative, data in (("rom/rodata.rom", bundle["rom"]), ("map/rodata.map", bundle["map"]),
                               ("localization/font/font_rebuild_preview.png", bundle["preview_png"])):
            target = output / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(data)
        target = output / "font_build_report.json"
        target.write_text(json.dumps(bundle["report"], ensure_ascii=False, indent=2), encoding="utf-8")
    print(json.dumps({"fonts": 6, "required_codes": bundle["report"]["required_codes_including_original_aliases"],
                      "rodata_bytes": len(bundle["rom"]), "map_bytes": len(bundle["map"]),
                      "new_glyphs_per_font": [font["new_glyphs"] for font in bundle["report"]["fonts"]]},
                     ensure_ascii=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
