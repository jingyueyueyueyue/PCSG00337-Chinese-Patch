#!/usr/bin/env python3
"""Regression checks against the pinned Japanese baseline; no files are written.

Exercise growing STR records, raw and compressed ROM relocation, stale MAP
capacities, checksums, malformed pointers, source-ID drift and repeatable
partial translation builds. Run from any directory with Python -X utf8 -B.
"""
from __future__ import annotations

import csv
import io
import random
from pathlib import Path
import struct
import sys
import unittest
import zlib

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts/build"))

import dcfs
import dcvm
import import_script_text as importer


def translation_csv(records: list[tuple[importer.OriginalString, str]], *, bad_source=False) -> bytes:
    stream = io.StringIO(newline="")
    writer = csv.DictWriter(stream, fieldnames=["id", "offset", "source", "translation", "note"])
    writer.writeheader()
    for record, text in records:
        writer.writerow({"id": f"jp{record.line:06d}", "offset": f"0x{record.stream_offset:08X}",
                         "source": "wrong source" if bad_source else record.source,
                         "translation": text, "note": ""})
    return stream.getvalue().encode("utf-8")


def sections(data: bytes) -> dict[bytes, bytes]:
    return {section[0]: section[1] for section in dcvm.parse_dcvm(data)[1]}


class ScriptPipelineTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rom = importer.ORIGINAL_ROM.read_bytes()
        cls.map_data = importer.ORIGINAL_MAP.read_bytes()
        if importer.sha256(cls.rom) != importer.ORIGINAL_ROM_SHA256:
            raise AssertionError("test baseline ROM SHA256 mismatch")
        if importer.sha256(cls.map_data) != importer.ORIGINAL_MAP_SHA256:
            raise AssertionError("test baseline MAP SHA256 mismatch")
        cls.items = list(dcvm.iter_items(cls.rom))
        cls.raw_item = next(item for item in cls.items if item[0] == "raw")
        cls.compressed_item = next(item for item in cls.items if item[0] == "z")
        cls.raw_payload = dcvm.inflate_entry(cls.rom, cls.raw_item)
        cls.compressed_payload = dcvm.inflate_entry(cls.rom, cls.compressed_item)
        cls.original = importer.load_baseline_strings(cls.rom)
        cls.sample = next(record for record in cls.original
                          if record.category == "jp" and not importer.control_signature(record.source))

    def test_original_complete_and_noop_byte_exact(self):
        self.assertEqual((len(self.items), sum(item[0] == "raw" for item in self.items)), (491, 9))
        self.assertEqual(dcvm.verify_rom(self.rom, map_data=self.map_data, exact_stream=True), [])
        rom, map_data, offsets = dcvm.repack_rom(self.rom, self.map_data, {})
        self.assertEqual((rom, map_data), (self.rom, self.map_data))
        self.assertTrue(all(old == new for old, new in offsets.items()))

    def test_growth_remaps_stbl_and_preserves_non_text(self):
        old = sections(self.compressed_payload)
        entries = dcvm.stbl_entries(old[b"STBL"])
        offset = entries[0]
        replacement = b"Translation that exceeds the original slot. " * 30
        rebuilt, mapping = dcvm.rebuild_container(self.compressed_payload, {offset: replacement})
        new = sections(rebuilt)
        self.assertEqual(dcvm.verify_dcvm(rebuilt), [])
        self.assertGreater(len(rebuilt), len(self.compressed_payload))
        self.assertTrue(any(old_offset != new_offset for old_offset, new_offset in mapping.items()))
        records = dict(dcvm.region_records(new[b"STR "][8:]))
        old_records = dict(dcvm.region_records(old[b"STR "][8:]))
        for before, after in zip(entries, dcvm.stbl_entries(new[b"STBL"])):
            self.assertEqual(after, mapping[before])
            self.assertEqual(records[after], replacement if before == offset else old_records[before])
        for tag in old:
            if tag not in (b"STR ", b"STBL"):
                self.assertEqual(new[tag], old[tag])
        self.assertTrue(all(length % 4 == 0 and position % 4 == 0
                            for _tag, _payload, position, length in dcvm.parse_dcvm(rebuilt)[1]))

    def test_raw_growth_relocates_first_compressed_resource(self):
        offset = dcvm.stbl_entries(sections(self.raw_payload)[b"STBL"])[0]
        rebuilt, _ = dcvm.rebuild_container(self.raw_payload, {offset: b"RAW TEXT " * 800})
        rom, map_data, mapping = dcvm.repack_rom(self.rom, self.map_data, {self.raw_item[1]: rebuilt})
        self.assertGreater(len(rom), len(self.rom))
        self.assertEqual(rom[0x400:0x404], b"DCVM")
        self.assertGreater(mapping[self.compressed_item[1]], self.compressed_item[1])
        self.assertEqual(dcvm.verify_rom(rom, map_data=map_data, exact_stream=True), [])
        records = dcfs.parse_map(map_data).records
        raw_record = next(record for record in records
                          if record.block * 0x400 == mapping[self.raw_item[1]])
        self.assertEqual(raw_record.read_capacity(0x400), dcvm.align(len(rebuilt)))

    def test_compressed_growth_updates_exact_sizes_and_full_map(self):
        source = sections(self.compressed_payload)
        offset = dcvm.stbl_entries(source[b"STBL"])[0]
        rng = random.Random(20260908)
        replacement = bytes(rng.randrange(0x21, 0x7F) for _ in range(40000))
        rebuilt, _ = dcvm.rebuild_container(self.compressed_payload, {offset: replacement})
        rom, map_data, mapping = dcvm.repack_rom(self.rom, self.map_data,
                                               {self.compressed_item[1]: rebuilt})
        new_offset = mapping[self.compressed_item[1]]
        item = next(item for item in dcvm.iter_items(rom) if item[1] == new_offset)
        self.assertGreater(item[2], self.compressed_item[2])
        self.assertEqual(item[3], len(rebuilt))
        self.assertEqual(rom[new_offset + 12:new_offset + 12 + item[2]], zlib.compress(rebuilt, 9))
        self.assertEqual(dcvm.inflate_entry(rom, item, exact_stream=True), rebuilt)
        self.assertEqual(dcvm.verify_rom(rom, map_data=map_data, exact_stream=True), [])
        self.assertTrue(dcfs.verify_rom_map(rom, self.map_data))

    def test_wrong_map_capacity_is_rejected_and_repairable(self):
        record = next(record for record in dcfs.parse_map(self.map_data).records
                      if record.compressed and record.output_capacity(0x400) > 0x400)
        broken = bytearray(self.map_data)
        struct.pack_into("<I", broken, record.offset + 8, record.metadata & dcfs.FLAG_MASK)
        self.assertTrue(dcfs.verify_rom_map(self.rom, bytes(broken)))
        self.assertEqual(dcfs.sync_map(self.rom, bytes(broken)), self.map_data)

    def test_corrupt_stbl_and_code_are_rejected(self):
        parsed = dcvm.parse_dcvm(self.compressed_payload)[1]
        table = next(section for section in parsed if section[0] == b"STBL")
        broken = bytearray(self.compressed_payload)
        struct.pack_into("<I", broken, table[2] + 12, 0xFFFFFFFF)
        self.assertTrue(dcvm.verify_dcvm(bytes(broken)))
        broken = bytearray(self.compressed_payload)
        struct.pack_into("<I", broken, table[2] + 8, 0xFFFFFFFF)
        self.assertTrue(dcvm.verify_dcvm(bytes(broken)))
        code = next(section for section in parsed if section[0] == b"CODE")
        broken = bytearray(self.compressed_payload)
        broken[code[2] + 28] ^= 1
        self.assertTrue(any("CODE checksum" in issue for issue in dcvm.verify_dcvm(bytes(broken))))

    def test_nul_unknown_offset_and_illegal_encodings_fail(self):
        record = dcvm.string_records(self.compressed_payload)[0][0]
        with self.assertRaises(ValueError):
            dcvm.rebuild_container(self.compressed_payload, {record: b"bad\0value"})
        with self.assertRaises(ValueError):
            dcvm.rebuild_container(self.compressed_payload, {0xFFFFFFFF: b"bad"})
        for invalid in (b"\0", b"\xA0\x40", b"\x81\x7F", b"A"):
            with self.subTest(code=invalid.hex()), self.assertRaises(ValueError):
                importer.validate_code_table({"\u4e00": invalid})
        with self.assertRaises(ValueError):
            importer.validate_code_table({"\u4e00": b"\x81\xAD", "\u4e01": b"\x81\xAD"})
        with self.assertRaises(ValueError):
            importer.encode_text("\u4e00", {})

    def test_precise_source_ids_and_conflicts(self):
        data = translation_csv([(self.sample, "first"), (self.sample, "second")])
        with self.assertRaisesRegex(ValueError, "conflicting translation"):
            importer._translation_plan(data, self.original, {})
        data = translation_csv([(self.sample, "text")], bad_source=True)
        with self.assertRaisesRegex(ValueError, "does not identify"):
            importer._translation_plan(data, self.original, {})
        sources = {}
        pair = None
        for record in self.original:
            if record.category == "jp" and not importer.control_signature(record.source):
                if record.source in sources:
                    pair = sources[record.source], record
                    break
                sources[record.source] = record
        self.assertIsNotNone(pair)
        data = translation_csv([(pair[0], " left "), (pair[1], " right ")])
        plan, counts, _ = importer._translation_plan(data, self.original, {})
        self.assertEqual(plan[pair[0].entry_offset][pair[0].string_offset], b" left ")
        self.assertEqual(plan[pair[1].entry_offset][pair[1].string_offset], b" right ")
        self.assertEqual(counts["nonempty_rows"], 2)

    def test_partial_build_repeats_and_blank_restores_original(self):
        data = translation_csv([(self.sample, "Repeatable translation test")])
        first = importer.build_script_bundle({}, translation_data=data)
        second = importer.build_script_bundle({}, translation_data=data)
        self.assertEqual((first["rom"], first["map"]), (second["rom"], second["map"]))
        self.assertEqual(first["report"], second["report"])
        self.assertEqual(first["report"]["strings"]["translated_records"], 1)
        restored = importer.build_script_bundle({}, translation_data=translation_csv([(self.sample, "")]))
        self.assertEqual((restored["rom"], restored["map"]), (self.rom, self.map_data))
        self.assertEqual(restored["report"]["translation"]["empty_rows"], 1)


if __name__ == "__main__":
    unittest.main(verbosity=2)
