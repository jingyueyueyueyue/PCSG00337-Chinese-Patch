#!/usr/bin/env python3
"""Regression checks for PCSG00337's six-slot font and import contract."""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
import unittest
from datetime import datetime
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts/build"))
import build_font
import dcfs
import dcft


class FontPipelineTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rom = build_font.ORIG_ROM.read_bytes()
        if hashlib.sha256(cls.rom).hexdigest() != build_font.ORIG_ROM_SHA256:
            raise ValueError("pristine font regression fixture SHA256 mismatch")
        cls.fonts = {index: dcft.parse_dcft(dcft.find_font_entry(cls.rom, index)[3])
                     for index in range(1, 7)}
        # The first glyph is a Unicode alias of an existing native CP932
        # character; the last needs a new raster and the final private group.
        cls.table = {" ": b"\x20", "\u91cc": b"\xf0\x40", "\u7ad9": b"\xf9\xfc"}
        cls.bundle = build_font.build_font_bundle(cls.table)
        cls.renderer = build_font.GlyphRenderer()
        cls.rebuilt = {index: dcft.parse_dcft(dcft.find_font_entry(cls.bundle["rom"], index)[3], strict=True)
                       for index in range(1, 7)}

    def test_native_glyph_anchor_is_not_shifted_by_94(self):
        font = self.fonts[1]
        anchors = {
            0x41: (33, 36, "ef43f8323272880b22ff162d76d5f5144dbfa965b73a23ce6e7c5d99f7e28da2"),
            0x82A0: (177, 37, "66ea87e5f0529993b38ddcecfb13dff03fc1296daa0b28d7c84b0ee48a445fdf"),
            0x97A2: (2000, 41, "51e1c4cb873bb2eac257e747ead1f03d489194d641b5cc18329c37f79de05d8b"),
        }
        for code, (gid, advance, digest) in anchors.items():
            self.assertEqual(font.lookup(code), gid)
            self.assertEqual(font.block_of(gid), gid)
            self.assertEqual(font.ls[gid], advance)
            self.assertEqual(hashlib.sha256(dcft.pack_glyph(font.glyph(gid))).hexdigest(), digest)
        self.assertEqual(font.lookup(0x20), 0)
        self.assertEqual(font.lookup(0x8140), 94)

    def test_all_six_slots_unify_text_and_preserve_native_codes_metrics_and_icons(self):
        self.assertTrue(self.bundle["report"]["uniform_text_style"])
        reports = {item["entry_index"]: item for item in self.bundle["report"]["fonts"]}
        repainted_count = 0
        preserved_count = 0
        for index, font in self.fonts.items():
            with self.subTest(font=index):
                rebuilt = self.rebuilt[index]
                self.assertEqual(rebuilt.ls[:font.n_blocks], font.ls[:font.n_blocks])
                self.assertTrue(np.array_equal(rebuilt.image_info[:font.n_blocks],
                                               font.image_info[:font.n_blocks]))
                details = {item["gid"]: item for item in reports[index]["repainted_native_glyph_details"]}
                preserved = {item["gid"] for item in reports[index]["preserved_native_glyphs"]}
                self.assertTrue(reports[index]["uniform_text_style"])
                self.assertEqual(len(details), reports[index]["repainted_native_glyphs"])
                characters = build_font.native_glyph_characters(font)
                for code, gid in font.entries().items():
                    self.assertEqual(rebuilt.lookup(code), gid)
                    char = characters[gid][1]
                    if char:
                        parameters = {**build_font.FONT_PROFILES[index], "advance": font.ls[gid]}
                        expected, rendering = self.renderer.render_with_info(char, **parameters)
                        self.assertTrue(np.array_equal(rebuilt.glyph(gid), expected))
                        self.assertEqual(details[gid]["font"], rendering["font"])
                        self.assertEqual(details[gid]["pixel_size"], rendering["pixel_size"])
                        self.assertEqual(details[gid]["pixels_sha256"], hashlib.sha256(dcft.pack_glyph(expected)).hexdigest())
                        self.assertNotIn(gid, preserved)
                        repainted_count += 1
                    else:
                        self.assertIn(gid, preserved)
                        self.assertTrue(np.array_equal(rebuilt.glyph(gid), font.glyph(gid)))
                        preserved_count += 1
        self.assertEqual((repainted_count, preserved_count), (7121, 1))

    def test_all_original_alias_and_assigned_codes_exist_in_every_slot(self):
        required = build_font.required_code_characters(self.table)
        self.assertIn(0xA1, required)
        self.assertIn(0x8142, required)
        for index, font in self.rebuilt.items():
            self.assertEqual(dcft.verify_dcft(font.data, strict=True), [])
            self.assertEqual(len(font.entries()), len(set(font.entries().values())))
            for code, char in required.items():
                gid = font.lookup(code)
                self.assertIsNotNone(gid, (index, code, char))
                self.assertGreater(font.ls[gid], 0)
                if not char.isspace():
                    self.assertTrue(np.any(font.glyph(gid)), (index, code, char))

    def test_private_code_limit_and_group_directory_expand_together(self):
        self.assertEqual(dcft.code_index(0xF040), 0x7000)
        self.assertEqual(dcft.code_index(0xF9FC), 0x79BC)
        for index, font in self.rebuilt.items():
            self.assertGreaterEqual(font.code_limit, 0x79C0, index)
            self.assertGreaterEqual(len(font.g), 0x79C, index)
            self.assertIsNotNone(font.lookup(0xF9FC), index)
            damaged = bytearray(font.data)
            struct.pack_into("<H", damaged, 8, 0x100)
            limited = dcft.parse_dcft(bytes(damaged))
            self.assertIsNone(limited.lookup(0xF040))
            self.assertIsNone(limited.lookup(0x8140))

    def test_private_unicode_alias_uses_the_same_unified_pixels_and_advance(self):
        for index in range(1, 7):
            original = self.fonts[index]
            rebuilt = self.rebuilt[index]
            native_gid = original.lookup(0x97A2)
            custom_gid = rebuilt.lookup(0xF040)
            self.assertTrue(np.array_equal(rebuilt.glyph(rebuilt.lookup(0x97A2)), rebuilt.glyph(custom_gid)))
            parameters = dict(build_font.FONT_PROFILES[index])
            if native_gid is not None:
                parameters["advance"] = original.ls[native_gid]
                self.assertEqual(original.ls[native_gid], rebuilt.ls[custom_gid])
            expected = self.renderer.render("\u91cc", **parameters)
            self.assertTrue(np.array_equal(rebuilt.glyph(custom_gid), expected))
        native = self.fonts[1]
        new = self.rebuilt[1]
        self.assertFalse(np.array_equal(native.glyph(native.lookup(0x97A2)), new.glyph(new.lookup(0x97A2))))
        # A1 is Buriko's single-byte full stop, not a CP932 halfwidth image.
        font = self.rebuilt[1]
        self.assertTrue(np.array_equal(font.glyph(font.lookup(0xA1)), font.glyph(font.lookup(0x8142))))

    def test_16_pixel_slot_and_padding_use_their_own_geometry(self):
        font = self.rebuilt[5]
        self.assertEqual((font.glyph_w, font.glyph_h, font.block_bytes), (16, 16, 128))
        self.assertEqual(font.glyph(font.lookup(0xF9FC)).shape, (16, 16))
        for index, original in self.fonts.items():
            rebuilt = self.rebuilt[index]
            first_new = min(set(rebuilt.entries().values()) - set(original.entries().values()))
            self.assertEqual(first_new, original.n_blocks)
            self.assertEqual(rebuilt.bitmap_offset(first_new), len(original.bm))
            self.assertEqual(len(rebuilt.ls), len(rebuilt.image_info))
            self.assertEqual(rebuilt.n_blocks, len(rebuilt.ls))

    def test_p4_nibble_order_and_imgi_offset_unit(self):
        self.assertEqual(dcft.pack_glyph(np.array([[1, 10], [15, 0]], dtype=np.uint8)), b"\xa1\x0f")
        font = self.fonts[1]
        changed = bytearray(font.data)
        offset = font.sections[b"IMGI"][0] + 8 + 33 * 4
        struct.pack_into("<I", changed, offset, 0x82400090)
        # Palette bits are not part of the 22-bit offset. Unit is 8, not 16.
        remapped = dcft.parse_dcft(bytes(changed))
        self.assertEqual(remapped.bitmap_offset(33), 0x90 * 8)
        self.assertTrue(np.array_equal(remapped.glyph(33), font.glyph(1)))
        struct.pack_into("<I", changed, offset, 0x8FFFFFFF)
        self.assertTrue(dcft.verify_dcft(bytes(changed)))

    def test_duplicate_unicode_codes_and_illegal_trails_are_rejected(self):
        for table in ({"\u301c": b"\x81\x60", "\uff5e": b"\x81\x60"},
                      {"\u4e00": b"\xf1\x3f"}, {"\u4e00": b"\xf0\x7f"},
                      {"\u4e00": b"\xf0\xfd"}):
            with self.assertRaises(ValueError):
                build_font.validate_code_table(table)
        build_font.validate_code_table({"\u301c": b"\x81\x60", "\uff5e": b"\xf0\x40"})

    def test_duplicate_glyph_directory_is_rejected(self):
        font = self.fonts[1]
        changed = bytearray(font.data)
        code = 0x41
        index = dcft.code_index(code)
        run = int(font.g[index >> 4])
        offset = font.sections[b"@FNT"][0] + 8 + (run + (index & 15)) * 2
        struct.pack_into("<H", changed, offset, font.lookup(0x42))
        self.assertTrue(any("share a glyph" in problem for problem in dcft.verify_dcft(bytes(changed))))

    def test_candidate_map_locations_read_and_output_capacities_match(self):
        rom, map_data = self.bundle["rom"], self.bundle["map"]
        self.assertEqual(dcft.verify_rodata_map(rom, map_data), [])
        index = dcfs.parse_map(map_data)
        self.assertEqual(index.rom_size, len(rom))
        original = dcfs.parse_map(build_font.ORIG_MAP.read_bytes())
        self.assertEqual([record.name for record in original.records], [record.name for record in index.records])
        for record in index.records:
            position = record.block * index.block_size
            compressed, expanded = struct.unpack_from("<II", rom, position + 4)
            self.assertGreaterEqual(record.read_capacity(index.block_size), compressed + 12)
            self.assertGreaterEqual(record.output_capacity(index.block_size), expanded)

    def test_pristine_special_codes_are_protected_from_future_allocation(self):
        protected = build_font.native_codepoints()
        self.assertEqual(len(protected), 2129)
        for font in self.fonts.values():
            self.assertTrue(set(font.entries()) <= protected)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--report", type=Path)
    args = parser.parse_args()
    suite = unittest.defaultTestLoader.loadTestsFromTestCase(FontPipelineTests)
    result = unittest.TextTestRunner(verbosity=2).run(suite)
    if args.report:
        report = {"timestamp": datetime.now().isoformat(timespec="seconds"),
                  "tests": result.testsRun, "failures": len(result.failures),
                  "errors": len(result.errors), "passed": result.wasSuccessful(),
                  "baseline_rom_sha256": build_font.ORIG_ROM_SHA256,
                  "checks": [name for name in dir(FontPipelineTests) if name.startswith("test_")]}
        args.report.parent.mkdir(parents=True, exist_ok=True)
        args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
    return 0 if result.wasSuccessful() else 1


if __name__ == "__main__":
    raise SystemExit(main())
