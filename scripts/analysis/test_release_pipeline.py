#!/usr/bin/env python3
"""Regressions for atomic publication, source sync, code allocation and glyphs.

All mutation fixtures begin inside archive/YYYY-MM/YYYYMMDD_release_tests_*.
No game resource or formal translation is modified. Successful fixtures are
removed after a JSON summary is archived; failing fixtures remain for review.
"""
from __future__ import annotations

import copy
import csv
from dataclasses import replace
from datetime import datetime
import hashlib
import io
import json
import os
from pathlib import Path
import shutil
import struct
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts/build"))
sys.path.insert(0, str(ROOT / "scripts/convert"))
import build_font
import build_localization as release
import dcft
import eboot_text
import numpy as np
import reset_font_code_table as codes
import sync_translation_source as sync
import verify_installed_localization as verify

TEST_ROOT: Path | None = None


def csv_bytes(rows: list[dict], fields: list[str], delimiter=",") -> bytes:
    stream = io.StringIO(newline="")
    writer = csv.DictWriter(stream, fieldnames=fields, delimiter=delimiter)
    writer.writeheader()
    writer.writerows(rows)
    return stream.getvalue().encode("utf-8-sig")


def write_csv(path: Path, rows: list[dict], fields: list[str], delimiter=",") -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(csv_bytes(rows, fields, delimiter))


def unencodable_cjk(count: int) -> list[str]:
    result = []
    for point in range(0x4E00, 0xA000):
        char = chr(point)
        try:
            char.encode("cp932")
        except UnicodeEncodeError:
            result.append(char)
            if len(result) == count:
                return result
    raise AssertionError("not enough CJK test characters")


def translation_data(chars: str) -> bytes:
    return csv_bytes([{"translation": chars}], ["translation"])


class FixtureTest(unittest.TestCase):
    def setUp(self):
        self.workspace = TEST_ROOT / self.__class__.__name__ / self._testMethodName
        self.workspace.mkdir(parents=True)

    def assert_no_staging(self):
        self.assertFalse((self.workspace / release.LOCK).exists())
        self.assertEqual(list(self.workspace.rglob("*.stage")), [])


class PublicationTests(FixtureTest):
    def seed(self):
        originals = {"rom/script.rom": b"old script", "map/script.map": b"old map"}
        targets = {"rom/script.rom": b"new script",
                   "localization/font/generated/table.tsv": b"new table",
                   "map/script.map": b"new map"}
        for name, data in originals.items():
            path = self.workspace / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(data)
        return originals, targets

    def assert_originals(self, originals, targets):
        for name in targets:
            path = self.workspace / name
            if name in originals:
                self.assertEqual(path.read_bytes(), originals[name])
            else:
                self.assertFalse(path.exists())
        self.assert_no_staging()

    def test_partial_commit_restores_old_and_removes_new_files(self):
        originals, targets = self.seed()
        calls = 0

        def fail_on_third(source, target):
            nonlocal calls
            calls += 1
            if calls == 3:
                raise PermissionError("injected failure during final file replacement")
            os.replace(source, target)

        with self.assertRaises(PermissionError):
            release.install_outputs(targets, root=self.workspace,
                                    running_check=lambda: [], replace=fail_on_third)
        self.assertEqual(calls, 3)
        self.assert_originals(originals, targets)
        backups = list((self.workspace / "archive").glob("*/*_before_release_*"))
        self.assertEqual(len(backups), 1)
        for name, value in originals.items():
            self.assertEqual((backups[0] / name).read_bytes(), value)

    def test_staging_write_failure_never_commits(self):
        originals, targets = self.seed()
        real_fsync = os.fsync
        calls = 0

        def fail_on_stage(fd):
            nonlocal calls
            calls += 1
            if calls == 2:
                raise OSError("injected staging flush failure")
            return real_fsync(fd)

        with mock.patch.object(release.os, "fsync", side_effect=fail_on_stage):
            with self.assertRaises(OSError):
                release.install_outputs(targets, root=self.workspace, running_check=lambda: [])
        self.assert_originals(originals, targets)

    def test_failed_independent_verification_rolls_back_complete_set(self):
        originals, targets = self.seed()
        verified = []

        def reject_committed_files():
            self.assertTrue((self.workspace / release.LOCK).exists())
            for name, value in targets.items():
                self.assertEqual((self.workspace / name).read_bytes(), value)
            verified.append(True)
            return {"ok": False, "errors": ["injected independent semantic mismatch"]}

        with self.assertRaisesRegex(ValueError, "independent installed verification failed"):
            release.install_outputs(targets, root=self.workspace, running_check=lambda: [],
                                    installed_check=reject_committed_files)
        self.assertEqual(verified, [True])
        self.assert_originals(originals, targets)

    def test_exception_in_independent_verifier_rolls_back_complete_set(self):
        originals, targets = self.seed()

        def unreadable_verification_input():
            raise OSError("injected verification read failure")

        with self.assertRaisesRegex(OSError, "verification read failure"):
            release.install_outputs(targets, root=self.workspace, running_check=lambda: [],
                                    installed_check=unreadable_verification_input)
        self.assert_originals(originals, targets)

    def test_running_game_rejected_without_writes(self):
        originals, targets = self.seed()
        with self.assertRaisesRegex(RuntimeError, "running"):
            release.install_outputs(targets, root=self.workspace, running_check=lambda: [123])
        self.assert_originals(originals, targets)
        self.assertFalse((self.workspace / "archive").exists())

    def test_game_started_during_staging_cancels_commit(self):
        originals, targets = self.seed()
        checks = iter(([], [456]))
        with self.assertRaisesRegex(RuntimeError, "started"):
            release.install_outputs(targets, root=self.workspace, running_check=lambda: next(checks))
        self.assert_originals(originals, targets)

    def test_existing_lock_refuses_concurrent_install(self):
        originals, targets = self.seed()
        lock = self.workspace / release.LOCK
        lock.parent.mkdir(parents=True)
        lock.write_bytes(b"another active importer")
        with self.assertRaises(FileExistsError):
            release.install_outputs(targets, root=self.workspace, running_check=lambda: [])
        self.assertEqual(lock.read_bytes(), b"another active importer")
        for name, data in originals.items():
            self.assertEqual((self.workspace / name).read_bytes(), data)
        self.assertFalse((self.workspace / "localization/font/generated/table.tsv").exists())
        self.assertEqual(list(self.workspace.rglob("*.stage")), [])

    def test_reentrant_competing_commit_refused_while_first_succeeds(self):
        _, targets = self.seed()
        attempts = 0

        def compete_then_replace(source, target):
            nonlocal attempts
            attempts += 1
            if attempts == 1:
                with self.assertRaises(FileExistsError):
                    release.install_outputs({"rom/script.rom": b"competing build"},
                                            root=self.workspace, running_check=lambda: [])
            os.replace(source, target)

        backup = release.install_outputs(targets, root=self.workspace,
                                         running_check=lambda: [], replace=compete_then_replace)
        self.assertIsNotNone(backup)
        for name, data in targets.items():
            self.assertEqual((self.workspace / name).read_bytes(), data)
        self.assert_no_staging()
        self.assertIsNone(release.install_outputs(targets, root=self.workspace, running_check=lambda: []))

    def test_install_rejects_relative_and_absolute_path_escape(self):
        for name in ("../escaped.bin", str(self.workspace.parent / "escaped-absolute.bin")):
            with self.subTest(name=name), self.assertRaises(ValueError):
                release.install_outputs({name: b"must not write"}, root=self.workspace,
                                        running_check=lambda: [])
        self.assertFalse((self.workspace.parent / "escaped.bin").exists())
        self.assertFalse((self.workspace.parent / "escaped-absolute.bin").exists())

    def test_candidate_rejects_path_escape(self):
        candidate = self.workspace / "candidate"
        with self.assertRaises(ValueError):
            release.stage_outputs({"../escaped.bin": b"must not write"}, candidate)
        self.assertFalse((self.workspace / "escaped.bin").exists())

    def test_candidate_conflict_preserves_all_existing_files(self):
        candidate = self.workspace / "candidate"
        release.stage_outputs({"rom/script.rom": b"old"}, candidate)
        with self.assertRaises(FileExistsError):
            release.stage_outputs({"map/script.map": b"new map", "rom/script.rom": b"new"}, candidate)
        self.assertEqual((candidate / "rom/script.rom").read_bytes(), b"old")
        self.assertFalse((candidate / "map/script.map").exists())


class TranslationSyncTests(FixtureTest):
    ORIGINAL_FIELDS = ["offset", "category", "raw_hex", "text"]
    FORMAL_FIELDS = ["id", "offset", "source", "translation", "note"]
    WORK_FIELDS = ["id", "row", "offset", "scen", "budget", "source", "translation", "note"]

    def setUp(self):
        super().setUp()
        self.original = self.workspace / "extracted/script/script_strings.csv"
        self.formal = self.workspace / "localization/text/translation_source.csv"
        self.work = self.workspace / "localization/text/work"
        self.original_rows = [
            {"offset": "0x0000080C", "category": "jp", "text": "\u6700\u521d\u306e\u6587\u3002"},
            {"offset": "0x0000080C", "category": "symbol", "text": "_main"},
            {"offset": "0x00002C0C", "category": "jp", "text": "\u5171\u6709\u3059\u308b\u6587\u3002"},
            {"offset": "0x0000300C", "category": "jp", "text": "\u5171\u6709\u3059\u308b\u6587\u3002"},
            {"offset": "0x0000300C", "category": "jp", "text": "\u307e\u3060\u672a\u8a33\u3002"},
        ]
        for row in self.original_rows:
            row["raw_hex"] = row["text"].encode("cp932").hex()
        write_csv(self.original, self.original_rows, self.ORIGINAL_FIELDS)
        formal = []
        for line, row in enumerate(self.original_rows, 2):
            if row["category"] == "jp":
                formal.append({"id": f"jp{line:06d}", "offset": row["offset"], "source": row["text"],
                               "translation": "\u65e7\u8bd1" if line == 2 else "", "note": ""})
        write_csv(self.formal, formal, self.FORMAL_FIELDS)
        self.work.mkdir(parents=True)
        manifests, self.batch_rows = [], {}
        for batch, line_ids, covered in (
                ("b001_system", [2, 4], 2), ("b002_next", [6], 2)):
            path = self.work / f"{batch}.tsv"
            rows = []
            for sequence, line in enumerate(line_ids, 1):
                source = self.original_rows[line - 2]
                rows.append({"id": f"{batch}_{sequence:04d}", "row": str(line),
                             "offset": source["offset"], "scen": "test",
                             "budget": str(len(bytes.fromhex(source["raw_hex"]))),
                             "source": source["text"],
                             "translation": {2: "\u7b2c\u4e00\u53e5", 4: "\u5171\u4eab\u53e5"}.get(line, ""),
                             "note": ""})
            self.batch_rows[path] = rows
            write_csv(path, rows, self.WORK_FIELDS, "\t")
            manifests.append({"batch": batch, "file": path.relative_to(self.workspace).as_posix(),
                              "rows_covered": covered, "lines": len(rows)})
        (self.work / "manifest.json").write_text(json.dumps(manifests), encoding="utf-8")
        blocks = [{"offset": value} for value in ("0x0000080C", "0x00002C0C", "0x0000300C")]
        (self.original.parent / "block_map.json").write_text(json.dumps(blocks), encoding="utf-8")
        self.patches = mock.patch.multiple(sync, ROOT=self.workspace, ORIGINAL=self.original,
                                           WORK=self.work, FORMAL=self.formal)
        self.patches.start()
        self.addCleanup(self.patches.stop)

    def test_merge_is_in_memory_and_preserves_all_source_identities(self):
        before = {path: path.read_bytes() for path in (self.original, self.formal, *self.batch_rows)}
        bundle = sync.build_translation_bundle()
        rows = list(csv.DictReader(io.StringIO(bundle["data"].decode("utf-8-sig"))))
        self.assertEqual(len(rows), 4)
        self.assertEqual([row["id"] for row in rows], ["jp000002", "jp000004", "jp000005", "jp000006"])
        self.assertEqual([row["translation"] for row in rows],
                         ["\u7b2c\u4e00\u53e5", "\u5171\u4eab\u53e5", "\u5171\u4eab\u53e5", ""])
        for row in rows:
            original = self.original_rows[int(row["id"][2:]) - 2]
            self.assertEqual((row["source"], row["offset"]), (original["text"], original["offset"]))
        self.assertEqual(bundle["report"]["translated_rows"], 3)
        self.assertEqual(bundle["report"]["untranslated_rows"], 1)
        self.assertEqual(bundle["report"]["exact_row_translations"], 2)
        for path, value in before.items():
            self.assertEqual(path.read_bytes(), value)

    def test_changed_immutable_batch_fields_rejected(self):
        path = next(iter(self.batch_rows))
        for field, value in (("source", "\u88ab\u4fee\u6539"),
                             ("budget", "999"), ("row", "999"),
                             ("offset", "0x0000300C"), ("id", "b001_wrong_0001")):
            rows = [dict(row) for row in self.batch_rows[path]]
            rows[0][field] = value
            write_csv(path, rows, self.WORK_FIELDS, "\t")
            with self.subTest(field=field), self.assertRaises(ValueError):
                sync.build_translation_bundle()
        write_csv(path, self.batch_rows[path], self.WORK_FIELDS, "\t")

    def test_missing_batch_row_is_rejected(self):
        path = next(iter(self.batch_rows))
        write_csv(path, self.batch_rows[path][1:], self.WORK_FIELDS, "\t")
        with self.assertRaisesRegex(ValueError, "rows"):
            sync.build_translation_bundle()

    def test_formal_source_drift_is_rejected(self):
        rows = list(csv.DictReader(io.StringIO(self.formal.read_text(encoding="utf-8-sig"))))
        rows[0]["source"] = "\u7be1\u6539\u539f\u6587"
        write_csv(self.formal, rows, self.FORMAL_FIELDS)
        with self.assertRaisesRegex(ValueError, "source drift"):
            sync.build_translation_bundle(formal_only=True)

    def test_formal_only_preserves_every_row_without_batch_overrides(self):
        before = self.formal.read_bytes()
        output = sync.build_translation_bundle(formal_only=True)["data"]
        original_rows = list(csv.DictReader(io.StringIO(before.decode("utf-8-sig"))))
        output_rows = list(csv.DictReader(io.StringIO(output.decode("utf-8-sig"))))
        self.assertEqual(output_rows, original_rows)
        self.assertEqual(self.formal.read_bytes(), before)

    def test_added_control_token_is_rejected(self):
        path = next(iter(self.batch_rows))
        rows = [dict(row) for row in self.batch_rows[path]]
        rows[0]["translation"] = "\u9519\u8bef<wait>"
        write_csv(path, rows, self.WORK_FIELDS, "\t")
        with self.assertRaisesRegex(ValueError, "control"):
            sync.build_translation_bundle()


class UnifiedFontTests(unittest.TestCase):
    """Small real DCFT fixture: original text, a control icon and new codes."""

    @classmethod
    def setUpClass(cls):
        cls.profile = dict(verify.UNIFIED_FONT_PROFILES[4])
        width = height = 48
        native_text = np.zeros((height, width), dtype=np.uint8)
        native_text[4:35, 3:19] = 8
        icon = np.zeros_like(native_text)
        icon[10:20, 10:20] = 15
        groups = [0, 0xFFFF, 0xFFFF, 0xFFFF, 16, 0xFFFF, 0xFFFF, 0xFFFF]
        lookup = [0xFFFF] * 32
        lookup[9], lookup[17] = 0, 1
        header = bytearray(0x40)
        header[:4] = b"DCFT"
        struct.pack_into("<HHHH", header, 8, 0x80, width, height, 4)
        header[0x14:0x18] = b"\xef\xbe\xad\xde"
        struct.pack_into("<I", header, 0x18, 0x2C)
        sections = {
            b"@#LS": b"\x00\x17\x00\x00",
            b"@GRP": struct.pack("<8H", *groups),
            b"@FNT": struct.pack("<32H", *lookup),
            b"IMGD": struct.pack("<I", 12) + dcft.pack_glyph(icon) + dcft.pack_glyph(native_text),
            b"CLUT": bytes(range(64)),
            b"IMGI": struct.pack("<4I", 0x80000000, 0x80000120, 0, 0),
        }
        for tag, payload in sections.items():
            header += tag + struct.pack("<I", len(payload) + 8) + payload
        struct.pack_into("<I", header, 4, len(header))
        cls.original_data = bytes(header)
        cls.baseline = dcft.parse_dcft(cls.original_data)
        if dcft.verify_dcft(cls.original_data):
            raise AssertionError("invalid synthetic font fixture")
        source = build_font.GlyphRenderer()
        unified, aliases, repaint_report = build_font.repaint_native_font(
            cls.original_data, cls.profile, source)
        cls.labels = {0x41: "A", 0xF040: "A", 0xF041: "\u7ec8", 0xF042: "\u266a"}
        additions, details = {}, []
        for code, char in cls.labels.items():
            if cls.baseline.lookup(code) is not None:
                continue
            alias = aliases.get(char)
            if alias is None:
                pixels, info = source.render_with_info(char, **cls.profile)
                advance = cls.profile["advance"]
            else:
                pixels, advance = alias["pixels"], alias["advance"]
                info = {**alias["info"], "copied_native_gid": alias["gid"]}
            additions[code] = (pixels, advance)
            details.append({"code": f"{code:04X}", "char": char, "advance": advance, **info})
        cls.unified_data, extension = dcft.extend_font(unified, additions)
        cls.unified_font = dcft.parse_dcft(cls.unified_data, strict=True)
        for row in details:
            row["gid"] = extension["new_gids"][int(row["code"], 16)]
        cls.report = {**repaint_report, "profile": cls.profile, "new_glyphs": len(additions),
                      "new_glyph_details": details, "coverage_checked": len(cls.labels)}
        cls.renderer = verify.UniformRasterAudit()

    def audit(self, font=None, report=None):
        return verify.inspect_font_glyphs(self.baseline, font or self.unified_font,
                                         self.report if report is None else report,
                                         self.labels, self.profile, self.renderer)

    def repaint(self, gid, pixels):
        return dcft.parse_dcft(dcft.repaint_font(self.unified_data, {gid: pixels}), strict=True)

    def test_uniform_native_new_chinese_and_native_alias_are_verified(self):
        stats = self.audit()
        self.assertEqual(stats["native_text_glyphs_repainted"], 1)
        self.assertEqual(stats["native_nontext_glyphs_preserved"], 1)
        self.assertEqual(stats["new_text_glyphs_verified"], 3)
        self.assertEqual(stats["source_pixels_checked"], 4)
        self.assertFalse(np.array_equal(self.baseline.glyph(1), self.unified_font.glyph(1)))

    def test_original_native_pixels_cannot_be_claimed_as_uniform(self):
        font = self.repaint(1, self.baseline.glyph(1))
        report = copy.deepcopy(self.report)
        report["repainted_native_glyph_details"][0]["pixels_sha256"] = verify.fingerprint(
            dcft.pack_glyph(self.baseline.glyph(1)))["sha256"]
        with self.assertRaisesRegex(ValueError, "uniform source font pixels"):
            self.audit(font, report)

    def test_alias_cannot_copy_the_old_japanese_raster(self):
        font = self.repaint(self.unified_font.lookup(0xF040), self.baseline.glyph(1))
        with self.assertRaisesRegex(ValueError, "unified pixels/advance"):
            self.audit(font)

    def test_missing_duplicate_or_extra_native_repaint_evidence_is_rejected(self):
        row = self.report["repainted_native_glyph_details"][0]
        for rows in ([], [row, row], [row, {**row, "gid": 999}]):
            with self.subTest(records=len(rows)):
                report = copy.deepcopy(self.report)
                report["repainted_native_glyph_details"] = rows
                with self.assertRaises(ValueError):
                    self.audit(report=report)

    def test_native_advance_change_is_rejected(self):
        metrics = bytearray(self.unified_font.ls)
        metrics[1] += 1
        with self.assertRaisesRegex(ValueError, "advance changed"):
            self.audit(replace(self.unified_font, ls=bytes(metrics)))

    def test_native_imgi_flags_change_is_rejected_even_with_identical_pixels(self):
        entries = self.unified_font.image_info.copy()
        entries[1] ^= 0x40000000
        font = replace(self.unified_font, image_info=entries)
        self.assertTrue(np.array_equal(font.glyph(1), self.unified_font.glyph(1)))
        with self.assertRaisesRegex(ValueError, "IMGI entry changed"):
            self.audit(font)

    def test_native_glyph_id_reassignment_is_rejected(self):
        lookup = self.unified_font.f.copy()
        zero, one = lookup == 0, lookup == 1
        lookup[zero], lookup[one] = 1, 0
        with self.assertRaisesRegex(ValueError, "glyph id changed"):
            self.audit(replace(self.unified_font, f=lookup))

    def test_preserved_control_icon_pixels_cannot_change(self):
        pixels = self.unified_font.glyph(0).copy()
        pixels[0, 0] ^= 15
        with self.assertRaisesRegex(ValueError, "preserved non-text pixels changed"):
            self.audit(self.repaint(0, pixels))

    def test_new_chinese_pixels_must_match_the_source_font(self):
        gid = self.unified_font.lookup(0xF041)
        pixels = self.unified_font.glyph(gid).copy()
        pixels[0, 0] ^= 15
        with self.assertRaisesRegex(ValueError, "unified pixels/advance"):
            self.audit(self.repaint(gid, pixels))

    def test_undeclared_or_wrong_native_alias_is_rejected(self):
        for gid in (None, 0):
            with self.subTest(copied_native_gid=gid):
                report = copy.deepcopy(self.report)
                record = next(row for row in report["new_glyph_details"] if row["code"] == "F040")
                if gid is None:
                    record.pop("copied_native_gid")
                else:
                    record["copied_native_gid"] = gid
                with self.assertRaisesRegex(ValueError, "copied_native_gid"):
                    self.audit(report=report)

    def test_native_font_name_or_profile_cannot_misreport_style(self):
        report = copy.deepcopy(self.report)
        report["repainted_native_glyph_details"][0]["font"] = "simsun.ttc"
        with self.assertRaisesRegex(ValueError, "declared font"):
            self.audit(report=report)
        report = copy.deepcopy(self.report)
        report["profile"]["size"] -= 1
        with self.assertRaisesRegex(ValueError, "profile differs"):
            self.audit(report=report)


class CodeAllocationTests(FixtureTest):
    @classmethod
    def setUpClass(cls):
        cls.native_codes = build_font.native_codepoints()
        cls.non_cp932 = unencodable_cjk(1920)
        cls.original, cls.original_occupied = codes.read_original_codes()

    def assert_valid(self, bundle):
        table = bundle["table"]
        self.assertEqual(len(set(table.values())), len(table))
        for value in table.values():
            codes.validate_code_bytes(value)
        for char, raw in self.original.items():
            if char in table:
                self.assertEqual(table[char], raw)

    def test_current_translation_pool_is_legal_unique_and_read_only(self):
        protected = [codes.TRANSLATION, codes.GENERATED_DIR / "font_code_table_reset.tsv"]
        before = {path: path.read_bytes() for path in protected}
        bundle = codes.build_code_table_bundle(before[codes.TRANSLATION], native_codes=self.native_codes)
        self.assert_valid(bundle)
        self.assertEqual(bundle["report"]["illegal_code_count"], 0)
        for path, value in before.items():
            self.assertEqual(path.read_bytes(), value)

    def test_more_than_1880_custom_characters_overflow_without_native_collision(self):
        with mock.patch.object(codes, "GENERATED_DIR", self.workspace / "empty_generated"):
            bundle = codes.build_code_table_bundle(translation_data("".join(self.non_cp932)),
                                                   native_codes=self.native_codes)
        self.assert_valid(bundle)
        values = [bundle["table"][char] for char in self.non_cp932]
        self.assertEqual(len(values), 1920)
        self.assertGreater(sum(value[0] not in codes.PRIVATE_LEADS for value in values), 0)
        for value in values:
            self.assertNotIn(int.from_bytes(value, "big"), self.native_codes)
            self.assertNotIn(value, self.original_occupied)
            if value[0] not in codes.PRIVATE_LEADS:
                with self.assertRaises(UnicodeDecodeError):
                    value.decode("cp932")
        self.assertFalse((self.workspace / "empty_generated").exists())

    def test_invalid_duplicate_and_native_overriding_legacy_codes_migrate(self):
        chars = self.non_cp932[:5]
        generated = self.workspace / "generated"
        history = generated / "font_code_table_reset.tsv"
        native = next(value for value in sorted(self.native_codes) if value > 0xFF)
        rows = [{"char": char, "code_hex": raw} for char, raw in zip(chars, [
            "F0 00", "F0 41", "F0 41", native.to_bytes(2, "big").hex(), "F0 50"])]
        write_csv(history, rows, ["char", "code_hex"], "\t")
        original_bytes = history.read_bytes()
        with mock.patch.object(codes, "GENERATED_DIR", generated):
            bundle = codes.build_code_table_bundle(translation_data("".join(chars)),
                                                   native_codes=self.native_codes)
        self.assert_valid(bundle)
        allocated = bundle["table"]
        self.assertNotEqual(allocated[chars[0]], b"\xF0\x00")
        self.assertEqual(allocated[chars[1]], b"\xF0\x41")
        self.assertNotEqual(allocated[chars[2]], b"\xF0\x41")
        self.assertNotEqual(int.from_bytes(allocated[chars[3]], "big"), native)
        self.assertEqual(allocated[chars[4]], b"\xF0\x50")
        self.assertGreaterEqual(bundle["report"]["migrated_assignments"], 3)
        self.assertEqual(history.read_bytes(), original_bytes)

    def test_cp932_halfwidth_katakana_does_not_reuse_buriko_hiragana(self):
        with mock.patch.object(codes, "GENERATED_DIR", self.workspace / "empty_generated"):
            bundle = codes.build_code_table_bundle(translation_data("\uFF76"),
                                                   native_codes=self.native_codes)
        self.assert_valid(bundle)
        self.assertEqual(bundle["table"]["\u304B"], b"\xB6")
        self.assertNotEqual(bundle["table"]["\uFF76"], b"\xB6")
        self.assertEqual(len(bundle["table"]["\uFF76"]), 2)

    def test_exhausted_legal_pool_fails_without_files(self):
        reserved = self.native_codes | {int.from_bytes(value, "big") for value in codes.iter_custom_codes()}
        generated = self.workspace / "empty_generated"
        with mock.patch.object(codes, "GENERATED_DIR", generated):
            with self.assertRaisesRegex(ValueError, "exhausted"):
                codes.build_code_table_bundle(translation_data(self.non_cp932[0]), native_codes=reserved)
        self.assertFalse(generated.exists())


class EbootPipelineTests(FixtureTest):
    """eboot 解密、回写与假 SELF 重建回归；真实基线只读，产物只落在隔离区。"""

    @classmethod
    def setUpClass(cls):
        super().setUpClass()
        cls.bundle = eboot_text.build_eboot_bundle()
        cls.elf = eboot_text.decrypt_baseline_eboot()
        cls.translations = eboot_text.load_translations()

    def test_bundle_report_and_installed_self(self):
        report = self.bundle["report"]
        self.assertEqual(report["patch"]["records"], report["extraction"]["records"])
        self.assertEqual(report["patch"]["translated"], report["extraction"]["records"])
        self.assertEqual(report["patch"]["kept_japanese"], 0)
        installed = eboot_text.inspect_fake_self(self.bundle["files"]["eboot.bin"])
        self.assertEqual(len(installed["strings"]), report["extraction"]["records"])
        self.assertEqual(installed["sha256"], report["installed_sha256"])

    def test_extraction_baseline_is_deterministic(self):
        first = eboot_text.extraction_rows(self.elf)
        second = eboot_text.extraction_rows(eboot_text.decrypt_baseline_eboot())
        self.assertEqual(first, second)
        eboot_text.check_extraction_baseline(self.elf)

    def test_verify_installed_eboot_accepts_bundle(self):
        report = self.bundle["report"]
        translation_csv = eboot_text.TRANSLATIONS.read_bytes()
        summary = verify.inspect_installed_eboot(self.bundle["files"]["eboot.bin"],
                                                 translation_csv,
                                                 {"installed_sha256": report["installed_sha256"]})
        self.assertEqual(summary["translated"], report["patch"]["translated"])

    def test_tampered_installed_eboot_is_rejected(self):
        tampered = bytearray(self.bundle["files"]["eboot.bin"])
        tampered[0x1000 + 0x135048] ^= 0x01
        with self.assertRaisesRegex(ValueError, "mismatch|structure|strings"):
            verify.inspect_installed_eboot(bytes(tampered),
                                           eboot_text.TRANSLATIONS.read_bytes(),
                                           {"installed_sha256": "x"})

    def test_over_budget_translation_is_rejected(self):
        rows = [dict(row) for row in self.translations]
        lengths = {row["offset"]: row["length"] for row in eboot_text.extraction_rows(self.elf)}
        rows[0]["translation"] = "超" * (lengths[rows[0]["offset"]] // 3 + 2)
        with self.assertRaisesRegex(ValueError, "budget"):
            eboot_text.apply_translations(self.elf, rows)

    def test_source_mismatch_is_rejected(self):
        rows = [dict(row) for row in self.translations]
        rows[3]["source"] = "改动过的原文"
        with self.assertRaisesRegex(ValueError, "source mismatch"):
            eboot_text.apply_translations(self.elf, rows)

    def test_missing_import_row_is_rejected(self):
        rows = [dict(row) for row in self.translations][:-1]
        with self.assertRaisesRegex(ValueError, "missing from import source"):
            eboot_text.apply_translations(self.elf, rows)

    def test_extraction_baseline_drift_is_detected(self):
        stale = self.workspace / "stale_baseline.csv"
        rows = eboot_text.extraction_rows(self.elf)
        rows[10]["source"] = "漂移的原文"
        stale.write_bytes(eboot_text.csv_bytes(
            [{key: row[key] for key in eboot_text.EXTRACTION_FIELDS} for row in rows],
            eboot_text.EXTRACTION_FIELDS))
        original = eboot_text.EXTRACTION_BASELINE
        try:
            eboot_text.EXTRACTION_BASELINE = stale
            with self.assertRaisesRegex(ValueError, "drift"):
                eboot_text.check_extraction_baseline(self.elf)
        finally:
            eboot_text.EXTRACTION_BASELINE = original

    def test_install_outputs_publishes_eboot(self):
        targets = {"eboot.bin": self.bundle["files"]["eboot.bin"]}
        release.install_outputs(targets, root=self.workspace, running_check=lambda: [])
        self.assertEqual((self.workspace / "eboot.bin").read_bytes(),
                         self.bundle["files"]["eboot.bin"])
        self.assert_no_staging()


def main() -> int:
    global TEST_ROOT
    archive = ROOT / "archive" / datetime.now().strftime("%Y-%m")
    archive.mkdir(parents=True, exist_ok=True)
    prefix = datetime.now().strftime("%Y%m%d_release_tests_")
    TEST_ROOT = Path(tempfile.mkdtemp(prefix=prefix, dir=archive)).resolve()
    suite = unittest.defaultTestLoader.loadTestsFromModule(sys.modules[__name__])
    result = unittest.TextTestRunner(stream=sys.stdout, verbosity=2).run(suite)
    summary = {"checked_at": datetime.now().isoformat(timespec="seconds"),
               "tests": result.testsRun, "failures": len(result.failures), "errors": len(result.errors),
               "successful": result.wasSuccessful(), "fixture_directory": str(TEST_ROOT),
               "failures_detail": [{"test": str(case), "traceback": text} for case, text in result.failures],
               "errors_detail": [{"test": str(case), "traceback": text} for case, text in result.errors],
               "scope": ("Isolated publication fault injection, immutable translation sync, legal code allocation, "
                         "independent unified-font pixel reproduction, native mappings/metrics/IMGI and icon preservation.")}
    if result.wasSuccessful():
        allowed = archive.resolve()
        if allowed not in TEST_ROOT.parents or not TEST_ROOT.name.startswith(prefix):
            raise ValueError(f"refusing to remove unverified fixture path: {TEST_ROOT}")
        shutil.rmtree(TEST_ROOT)
        summary["fixtures_removed"] = True
    else:
        summary["fixtures_removed"] = False
    output = archive / datetime.now().strftime("%Y%m%d_release_pipeline_tests.json")
    output.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(f"Report: {output}")
    return 0 if result.wasSuccessful() else 1


if __name__ == "__main__":
    raise SystemExit(main())
