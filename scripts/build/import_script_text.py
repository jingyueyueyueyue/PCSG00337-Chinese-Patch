#!/usr/bin/env python3
"""Build a reproducible PCSG00337 script ROM/map candidate from Japanese originals.

Default/--dry-run validates in memory. --output DIR writes a candidate
rom/script.rom, map/script.map and manifest, never the running game's files.
The complete localization entry point must install text and matching fonts
together. String and compression growth is handled by STR/STBL and DCFS
repacking; translations are never truncated or skipped to fit old slots.
"""
from __future__ import annotations

import argparse
import csv
from dataclasses import dataclass
import hashlib
import io
import json
from pathlib import Path
import re
import sys
import zlib
from collections import defaultdict

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))

import dcfs
import dcvm
from scripts.analysis.extract_text_assets import classify_string, decode_buriko, looks_like_text
from scripts.analysis.validate_import_constraints import control_signature

SCRIPT_STRINGS = ROOT / "extracted/script/script_strings.csv"
DEFAULT_TRANSLATION = ROOT / "localization/text/translation_source.csv"
DEFAULT_CODE_TABLE = ROOT / "localization/font/generated/font_code_table_reset.tsv"
ORIGINAL_ROM = ROOT / "archive/2026-09/20260907_script.rom"
ORIGINAL_MAP = ROOT / "archive/2026-09/20260908_script_map_pristine.map"
ORIGINAL_ROM_SHA256 = "75a23c47863cf77a9d0451df34f84e323d1478a50309fd0bb6001a1fbf7d7dfd"
ORIGINAL_MAP_SHA256 = "4ef71dc0a7ec6c93114922aa9786f87a21ebcf25da040db49f970f42f90306d3"
SJIS_LEADS = set(range(0x81, 0xA0)) | set(range(0xE0, 0xFD))
SJIS_TRAILS = set(range(0x40, 0x7F)) | set(range(0x80, 0xFD))


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def _csv_rows(data: bytes) -> list[dict[str, str]]:
    return list(csv.DictReader(io.StringIO(data.decode("utf-8-sig"), newline="")))


def validate_code_table(table: dict[str, bytes]) -> None:
    """Reject collisions and byte sequences the game's SJIS tokenizer cannot read."""
    reverse = {}
    for char, code in table.items():
        if not isinstance(char, str) or len(char) != 1 or not isinstance(code, bytes):
            raise ValueError("code table must map one Unicode character to bytes")
        if len(code) == 1:
            valid = code[0] in (9, 10, 13) or 0x20 <= code[0] <= 0x7E or 0xA1 <= code[0] <= 0xDF
        elif len(code) == 2:
            valid = code[0] in SJIS_LEADS and code[1] in SJIS_TRAILS
        else:
            valid = False
        if not valid:
            raise ValueError(f"illegal game code for U+{ord(char):04X}: {code.hex()}")
        if len(code) == 1 and code[0] < 0x80 and char != chr(code[0]):
            raise ValueError(f"character U+{ord(char):04X} cannot take a reserved ASCII/control byte")
        if char in "\r\n\t" or 0x20 <= ord(char) <= 0x7E:
            if code != bytes([ord(char)]):
                raise ValueError(f"ASCII/control character U+{ord(char):04X} must retain its byte")
        if len(code) == 1 and (code[0] in (9, 10, 13) or 0x20 <= code[0] <= 0x7E):
            if ord(char) != code[0]:
                raise ValueError("a native ASCII/control code cannot be reassigned to another character")
        if code in reverse and reverse[code] != char:
            raise ValueError(f"ambiguous code {code.hex()} assigned to two characters")
        reverse[code] = char


def read_code_table(path: Path) -> dict[str, bytes]:
    table = {}
    with Path(path).open(encoding="utf-8-sig", newline="") as handle:
        for line, row in enumerate(csv.DictReader(handle, delimiter="\t"), 2):
            char = row.get("char")
            code_text = row.get("code_hex")
            if char is None or code_text is None:
                raise ValueError("code table requires char and code_hex columns")
            try:
                code = bytes.fromhex(code_text)
            except ValueError as error:
                raise ValueError(f"code table row {line}: invalid hex") from error
            if char in table and table[char] != code:
                raise ValueError(f"code table row {line}: conflicting character assignment")
            table[char] = code
    validate_code_table(table)
    return table


def encode_text(text: str, code_table: dict[str, bytes]) -> bytes:
    """Encode exactly; unsupported characters and embedded NUL always fail."""
    result = bytearray()
    for char in text:
        if char in "\r\n\t" or 0x20 <= ord(char) <= 0x7E:
            result.append(ord(char))
        elif char in code_table:
            result += code_table[char]
        else:
            raise ValueError(f"no assigned code for U+{ord(char):04X}")
    if b"\0" in result:
        raise ValueError("encoded translation contains NUL")
    return bytes(result)


@dataclass(frozen=True)
class OriginalString:
    line: int
    entry_offset: int
    stream_offset: int
    string_offset: int
    raw: bytes
    source: str
    category: str


def load_baseline_strings(rom: bytes, script_strings: Path = SCRIPT_STRINGS,
                          *, script_strings_data: bytes | None = None
                          ) -> list[OriginalString]:
    """Regenerate extraction records in memory and verify the saved Japanese CSV.

    jpNNNNNN IDs refer to DictReader record numbers starting at 2, not to
    physical lines when a CSV field contains newlines. Exact original bytes,
    offset, text and ordering are required so a stale extraction cannot be
    silently used to patch the wrong occurrence of a repeated sentence.
    """
    saved = Path(script_strings).read_bytes() if script_strings_data is None else script_strings_data
    rows = _csv_rows(saved)
    expected = []
    for _index, position, size, output_size, data in dcvm.find_containers(rom):
        for offset, raw in dcvm.string_records(data):
            if len(raw) < 2:
                continue
            source = decode_buriko(raw)
            if not looks_like_text(source):
                continue
            expected.append((position, size, output_size, offset, raw, source, classify_string(source)))
    if len(rows) != len(expected):
        raise ValueError(f"Japanese extraction has {len(rows)} records; original requires {len(expected)}")
    result = []
    for line, (row, record) in enumerate(zip(rows, expected), 2):
        position, size, output_size, offset, raw, source, category = record
        try:
            matches = (
                int(row["offset"], 0) == position + 12
                and bytes.fromhex(row["raw_hex"]) == raw
                and row["text"] == source and row["category"] == category
                and int(row["compressed_size"]) == size
                and int(row["decompressed_size"]) == output_size
            )
        except (KeyError, TypeError, ValueError) as error:
            raise ValueError(f"invalid Japanese extraction record {line}") from error
        if not matches:
            raise ValueError(f"Japanese extraction record {line} differs from the verified original")
        result.append(OriginalString(line, position, position + 12, offset, raw, source, category))
    return result


def _translation_plan(data: bytes, original: list[OriginalString], code_table: dict[str, bytes]):
    by_line = {record.line: record for record in original}
    by_source = defaultdict(list)
    for record in original:
        if record.category == "jp":
            by_source[record.stream_offset, record.source].append(record)
    rows = _csv_rows(data)
    replacements = defaultdict(dict)
    assignments = {}
    origins = {}
    characters = set()
    counts = {"rows": len(rows), "nonempty_rows": 0, "empty_rows": 0,
              "resolved_rows": 0, "identical_duplicate_records": 0,
              "control_signatures_checked": 0, "translated_characters": 0}
    for line, row in enumerate(rows, 2):
        label = f"translation record {line}"
        source, translation = row.get("source"), row.get("translation")
        if source is None or translation is None:
            raise ValueError(f"{label}: source and translation columns are required")
        try:
            stream_offset = int(row.get("offset") or "", 0)
        except ValueError as error:
            raise ValueError(f"{label}: invalid original stream offset") from error
        stable_id = row.get("id") or ""
        source_line = row.get("row") or ""
        if stable_id:
            match = re.fullmatch(r"jp(\d+)", stable_id)
            if not match:
                raise ValueError(f"{label}: expected an original jpNNNNNN row ID")
            number = int(match.group(1))
            if source_line and int(source_line) != number:
                raise ValueError(f"{label}: ID and source row disagree")
            candidates = [by_line[number]] if number in by_line else []
        elif source_line:
            number = int(source_line)
            candidates = [by_line[number]] if number in by_line else []
        else:
            candidates = by_source.get((stream_offset, source), [])
        if not candidates or any(
            record.stream_offset != stream_offset or record.source != source or record.category != "jp"
            for record in candidates
        ):
            raise ValueError(f"{label}: ID/offset/source does not identify the original Japanese text")
        counts["resolved_rows"] += 1
        if not translation.strip():
            counts["empty_rows"] += 1
            continue
        counts["nonempty_rows"] += 1
        if control_signature(source) != control_signature(translation):
            raise ValueError(f"{label}: control tokens differ (ruby deletion is allowed)")
        counts["control_signatures_checked"] += 1
        try:
            encoded = encode_text(translation, code_table)
        except ValueError as error:
            raise ValueError(f"{label}: {error}") from error
        characters.update(translation)
        counts["translated_characters"] += len(translation)
        for record in candidates:
            key = record.entry_offset, record.string_offset
            if key in assignments:
                if assignments[key] != translation:
                    raise ValueError(f"{label}: conflicting translation; first defined at {origins[key]}")
                counts["identical_duplicate_records"] += 1
            assignments[key] = translation
            origins.setdefault(key, label)
            replacements[record.entry_offset][record.string_offset] = encoded
    return dict(replacements), counts, characters


def build_script_bundle(code_table: dict[str, bytes],
                        translation_path: Path = DEFAULT_TRANSLATION,
                        baseline_rom: Path = ORIGINAL_ROM,
                        baseline_map: Path = ORIGINAL_MAP,
                        script_strings: Path = SCRIPT_STRINGS,
                        *, translation_data: bytes | None = None) -> dict:
    """Return {rom: bytes, map: bytes, report: dict}; never write any file.

    Font and full-release builders pass their one shared code table and
    optional translation snapshot. Repeated builds always start from the
    pinned Japanese original, so edits/deletions and new code assignments
    cannot leave text encoded with an older release's mapping.
    """
    validate_code_table(code_table)
    original_rom, original_map = Path(baseline_rom).read_bytes(), Path(baseline_map).read_bytes()
    if sha256(original_rom) != ORIGINAL_ROM_SHA256:
        raise ValueError("script source is not the verified Japanese original (SHA256 mismatch)")
    if sha256(original_map) != ORIGINAL_MAP_SHA256:
        raise ValueError("script map is not the original paired DCFS index (SHA256 mismatch)")
    problems = dcvm.verify_rom(original_rom, map_data=original_map, exact_stream=True)
    if problems:
        raise ValueError("original script validation failed: " + "; ".join(problems[:10]))
    source_csv = Path(script_strings).read_bytes()
    original_strings = load_baseline_strings(original_rom, script_strings, script_strings_data=source_csv)
    translations = Path(translation_path).read_bytes() if translation_data is None else bytes(translation_data)
    plan, translation_report, chars = _translation_plan(translations, original_strings, code_table)
    old_items = list(dcvm.iter_items(original_rom))
    payload_changes = {}
    expected_payloads = {}
    per_entry = []
    changed_records = 0
    for item in old_items:
        kind, position, size, output_size = item
        payload = dcvm.inflate_entry(original_rom, item)
        replacements = plan.get(position, {})
        if replacements:
            records = dict(dcvm.string_records(payload))
            changed = sum(records[offset] != value for offset, value in replacements.items())
            rebuilt, _mapping = dcvm.rebuild_container(payload, replacements)
            changed_records += changed
            if rebuilt != payload:
                payload_changes[position] = rebuilt
        else:
            rebuilt, changed = payload, 0
        expected_payloads[position] = rebuilt
        per_entry.append({"old_entry_offset": position, "kind": kind,
                          "old_stored_size": size, "old_payload_size": output_size,
                          "translated_records": len(replacements), "changed_records": changed})
    rom, map_data, offsets = dcvm.repack_rom(original_rom, original_map, payload_changes)
    rebuilt_items = {item[1]: item for item in dcvm.iter_items(rom)}
    for record in per_entry:
        old = record["old_entry_offset"]
        new = offsets[old]
        item = rebuilt_items[new]
        actual = dcvm.inflate_entry(rom, item, exact_stream=True)
        if actual != expected_payloads[old]:
            raise ValueError(f"final ROM payload read-back mismatch at {new:#x}")
        record.update({"new_entry_offset": new, "new_stored_size": item[2], "new_payload_size": item[3]})
    translated_count = sum(len(values) for values in plan.values())
    code_table_data = json.dumps({char: code.hex() for char, code in sorted(code_table.items())},
                                 ensure_ascii=True, separators=(",", ":")).encode("ascii")
    report = {
        "format_version": 2, "game_id": "PCSG00337", "compression": "zlib level 9",
        "zlib_version": zlib.ZLIB_RUNTIME_VERSION,
        "baseline_rom": {"path": str(Path(baseline_rom).resolve()), "bytes": len(original_rom),
                         "sha256": sha256(original_rom)},
        "baseline_map": {"path": str(Path(baseline_map).resolve()), "bytes": len(original_map),
                         "sha256": sha256(original_map)},
        "script_strings": {"path": str(Path(script_strings).resolve()), "bytes": len(source_csv),
                           "sha256": sha256(source_csv), "rows": len(original_strings)},
        "translation": {"path": str(Path(translation_path).resolve()), "sha256": sha256(translations),
                        **translation_report},
        "code_table_sha256": sha256(code_table_data), "distinct_translated_characters": len(chars),
        "entries": {"total": len(old_items), "compressed": sum(item[0] == "z" for item in old_items),
                    "raw": sum(item[0] == "raw" for item in old_items), "rebuilt": len(payload_changes),
                    "relocated": sum(old != new for old, new in offsets.items())},
        "strings": {"extracted": len(original_strings),
                    "japanese_original": sum(record.category == "jp" for record in original_strings),
                    "translated_records": translated_count, "changed_records": changed_records,
                    "unchanged_records": len(original_strings) - changed_records},
        "per_entry": per_entry,
        "outputs": {"rom/script.rom": {"bytes": len(rom), "sha256": sha256(rom)},
                    "map/script.map": {"bytes": len(map_data), "sha256": sha256(map_data)}},
        "checks": {"original_source_rows": "passed", "all_nonempty_translations_resolved": True,
                   "raw_and_compressed_dcvm": "passed", "code_and_string_checksums": "passed",
                   "str_and_stbl_relocation": "passed", "non_text_sections_preserved": True,
                   "complete_rom_map_index": "passed", "final_payload_readback": "passed"},
        "runtime_validation": "A fresh game launch with the matching font bundle is required.",
    }
    return {"rom": rom, "map": map_data, "report": report}


def write_candidate(output: Path, bundle: dict) -> None:
    output = Path(output).resolve()
    if output == ROOT.resolve():
        raise ValueError("candidate output must not be the live game root")
    artifacts = {"rom/script.rom": bundle["rom"], "map/script.map": bundle["map"],
                 "script_build_manifest.json": (json.dumps(bundle["report"], ensure_ascii=False, indent=2)
                                                 + "\n").encode("utf-8")}
    for relative, data in artifacts.items():
        path = output / relative
        if path.resolve() in {(ROOT / "rom/script.rom").resolve(), (ROOT / "map/script.map").resolve()}:
            raise ValueError("candidate output cannot overwrite a live game resource")
        if path.exists() and path.read_bytes() != data:
            raise ValueError(f"different candidate already exists: {path}; choose a new output directory")
    for relative, data in artifacts.items():
        path = output / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        if not path.exists():
            path.write_bytes(data)
        if path.read_bytes() != data:
            raise ValueError(f"candidate read-back failed: {path}")


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--dry-run", action="store_true", help="validate without writing")
    parser.add_argument("--output", type=Path, help="stage a script ROM/map candidate under this directory")
    parser.add_argument("--translation", type=Path, default=DEFAULT_TRANSLATION)
    parser.add_argument("--code-table", type=Path, default=DEFAULT_CODE_TABLE)
    parser.add_argument("--baseline-rom", type=Path, default=ORIGINAL_ROM)
    parser.add_argument("--baseline-map", type=Path, default=ORIGINAL_MAP)
    parser.add_argument("--script-strings", type=Path, default=SCRIPT_STRINGS)
    args = parser.parse_args(argv)
    if args.output and args.dry_run:
        parser.error("choose --dry-run or --output")
    try:
        bundle = build_script_bundle(read_code_table(args.code_table), args.translation,
                                     args.baseline_rom, args.baseline_map, args.script_strings)
        report = bundle["report"]
        print(f"Original source verified; {report['translation']['nonempty_rows']} translated CSV rows; "
              f"{report['strings']['translated_records']} exact STR records")
        print(f"Rebuilt {report['entries']['rebuilt']}/{report['entries']['total']} DCVM entries; "
              f"ROM {len(bundle['rom'])} bytes; all checks passed")
        if args.output:
            write_candidate(args.output, bundle)
            print(f"Script ROM/map candidate: {args.output.resolve()}")
        else:
            print("Dry run: no files changed")
        return 0
    except (OSError, UnicodeError, ValueError, KeyError) as error:
        print(f"Build failed: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
