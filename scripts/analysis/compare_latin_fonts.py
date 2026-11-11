#!/usr/bin/env python3
"""Render candidate Latin font treatments with the slot-1 dialogue profile.

Reproduces build_font.GlyphRenderer.render_with_info's fit/squeeze logic and
the native per-glyph advances, so each candidate strip shows exactly what the
game would produce.  Output: localization/reports/font/latin_font_compare.png
"""
from __future__ import annotations

import sys
import zlib
from functools import lru_cache
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts/build"))
import dcft  # noqa: E402

ORIG_ROM = ROOT / "archive/2026-09/20260908_rodata_pristine.rom"
OUT_PNG = ROOT / "localization/reports/font/latin_font_compare.png"

PROFILE = {"width": 48, "height": 48, "advance": 41, "size": 44, "baseline": 37}
LINES = ["（手帕上，绣着花……）", "「M、ta、ni……」", "（果然是三谷同学，没错……）"]

FONTS = {
    "msyh": "C:/Windows/Fonts/msyh.ttc",
    "msyhbd": "C:/Windows/Fonts/msyhbd.ttc",
    "noto": "C:/Windows/Fonts/NotoSansSC-VF.ttf",
}

# (label, latin spec, cjk spec); spec = (font key, wght or None, stroke, size scale)
CONFIGS = [
    ("当前: 全部雅黑Regular", ("msyh", None, 0, 1.0), ("msyh", None, 0, 1.0)),
    ("拉丁用雅黑Bold", ("msyhbd", None, 0, 1.0), ("msyh", None, 0, 1.0)),
    ("拉丁雅黑Bold+放大1.2", ("msyhbd", None, 0, 1.2), ("msyh", None, 0, 1.0)),
    ("拉丁雅黑+描边1px", ("msyh", None, 1, 1.0), ("msyh", None, 0, 1.0)),
    ("全部雅黑Bold", ("msyhbd", None, 0, 1.0), ("msyhbd", None, 0, 1.0)),
    ("思源黑体 Regular", ("noto", 400, 0, 1.0), ("noto", 400, 0, 1.0)),
    ("思源黑体 Bold", ("noto", 700, 0, 1.0), ("noto", 700, 0, 1.0)),
    ("拉丁思源Bold+中文雅黑", ("noto", 700, 0, 1.0), ("msyh", None, 0, 1.0)),
]


def native_advances() -> dict[str, int]:
    rom = ORIG_ROM.read_bytes()
    for pos, comp, _exp in dcft.iter_rodata_items(rom):
        payload = zlib.decompress(rom[pos + 12:pos + 12 + comp])
        if payload[:4] != b"DCFT":
            continue
        font = dcft.parse_dcft(payload)
        entries = font.entries()
        result = {}
        for code in range(0x20, 0x7F):
            code |= 0  # single byte
            gid = entries.get(code)
            if gid is not None:
                result[chr(code)] = int(font.ls[gid])
        for ch in "、。「」（）……":
            try:
                code = int.from_bytes(ch.encode("cp932"), "big")
            except UnicodeEncodeError:
                continue
            gid = entries.get(code)
            if gid is not None:
                result[ch] = int(font.ls[gid])
        return result
    raise ValueError("no DCFT found in pristine rodata")


ADVANCES = native_advances()
CJK_ADVANCE = PROFILE["advance"]


def advance_of(char: str) -> int:
    return ADVANCES.get(char, CJK_ADVANCE)


@lru_cache(maxsize=200)
def get_font(path: str, size: int, wght: int | None):
    font = ImageFont.truetype(path, size, index=0)
    if wght is not None:
        font.set_variation_by_axes([wght])
    return font


def render_cell(char: str, spec, advance: int) -> np.ndarray:
    key, wght, stroke, scale = spec
    width, height = PROFILE["width"], PROFILE["height"]
    size, baseline = PROFILE["size"], PROFILE["baseline"]
    start = max(6, min(255, round(size * scale)))
    path = FONTS[key]
    for pixel_size in range(start, max(5, size * 2 // 3) - 1, -1):
        font = get_font(path, pixel_size, wght)
        canvas = Image.new("L", (width * 4, height * 3), 0)
        ImageDraw.Draw(canvas).text((width, height + baseline), char, font=font,
                                    fill=255, anchor="ls",
                                    stroke_width=stroke, stroke_fill=255)
        raster = np.asarray(canvas)
        ys, xs = np.nonzero(raster)
        if not len(xs):
            raise ValueError(f"empty glyph {char!r}")
        if int(ys.min()) >= height and int(ys.max()) < height * 2:
            break
    else:
        raise ValueError(f"{char!r} cannot fit cell with {path}")
    ink = raster[height:height * 2, int(xs.min()):int(xs.max()) + 1]
    max_width = max(1, min(width, advance) - 1)
    if ink.shape[1] > max_width:
        ink = np.asarray(Image.fromarray(ink).resize((max_width, height),
                                                     Image.Resampling.LANCZOS))
    cell = np.zeros((height, width), dtype=np.uint8)
    cell[:, :ink.shape[1]] = ink
    return cell


def render_line(text: str, latin_spec, cjk_spec) -> np.ndarray:
    cells = []
    for char in text:
        spec = latin_spec if ord(char) < 0x80 else cjk_spec
        cells.append((render_cell(char, spec, advance_of(char)), advance_of(char)))
    total = sum(adv for _cell, adv in cells) + 8
    line = np.zeros((PROFILE["height"], total), dtype=np.uint8)
    x = 4
    for cell, adv in cells:
        span = min(PROFILE["width"], total - x)
        region = line[:, x:x + span]
        np.maximum(region, cell[:, :span], out=region)
        x += adv
    return line


def main() -> None:
    pad, line_gap, block_gap, label_w = 12, 6, 14, 300
    strips = []
    for label, latin_spec, cjk_spec in CONFIGS:
        lines = [render_line(text, latin_spec, cjk_spec) for text in LINES]
        width = max(line.shape[1] for line in lines) + pad
        height = len(lines) * PROFILE["height"] + (len(lines) - 1) * line_gap
        block = np.zeros((height, label_w + width), dtype=np.uint8)
        y = 0
        for line in lines:
            block[y:y + PROFILE["height"], label_w:label_w + line.shape[1]] = line
            y += PROFILE["height"] + line_gap
        strips.append((label, block))
    out_w = max(b.shape[1] for _l, b in strips) + pad
    out_h = sum(b.shape[0] for _l, b in strips) + block_gap * (len(strips) - 1) + pad * 2
    pil = Image.new("RGB", (out_w, out_h), (250, 246, 236))
    draw = ImageDraw.Draw(pil)
    label_font = ImageFont.truetype(FONTS["msyh"], 18)
    y = pad
    for label, block in strips:
        mask = Image.fromarray(block, "L")
        dark = Image.new("RGB", mask.size, (64, 50, 42))
        pil.paste(dark, (pad, y), mask)
        draw.text((pad + 6, y + 4), label, font=label_font, fill=(120, 90, 60))
        y += block.shape[0] + block_gap
    OUT_PNG.parent.mkdir(parents=True, exist_ok=True)
    pil.save(OUT_PNG)
    print(f"wrote {OUT_PNG} ({out_w}x{out_h})")
    print("ASCII advances:", {c: ADVANCES[c] for c in "Mtani"})


if __name__ == "__main__":
    main()
