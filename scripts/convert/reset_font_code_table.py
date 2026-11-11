#!/usr/bin/env python3
"""Build a stable, collision-free code table from original text and formal CSV.

The public builder is read-only. Code assignments belong to one complete
script/font release. This CLI checks by default, or writes a candidate with
--out-dir; install through scripts/build/build_localization.py --apply.
"""
from __future__ import annotations

import argparse
from collections import Counter
import csv
import hashlib
import io
import json
from pathlib import Path
import sys

from sjis_codec import is_lead, is_trail, validate_code_bytes

ROOT = Path(__file__).resolve().parents[2]
GENERATED_DIR = ROOT / "localization/font/generated"
SCRIPT_STRINGS = ROOT / "extracted/script/script_strings.csv"
ORIGINAL_TABLE = ROOT / "extracted/script/custom_code_table.tsv"
SINGLE_BYTE_TABLE = ROOT / "extracted/script/buriko_singlebyte_kana_table.tsv"
TRANSLATION = ROOT / "localization/text/translation_source.csv"
PRIVATE_LEADS = range(0xF0, 0xFA)
PRIVATE_TRAILS = tuple(range(0x40, 0x7F)) + tuple(range(0x80, 0xFD))


def iter_private_codes():
    for lead in PRIVATE_LEADS:
        for trail in PRIVATE_TRAILS:
            yield bytes((lead, trail))


def iter_custom_codes():
    """Prefer F0..F9; overflow only into undefined legal CP932 pairs."""
    yield from iter_private_codes()
    for lead in range(256):
        if not is_lead(lead) or lead in PRIVATE_LEADS:
            continue
        for trail in PRIVATE_TRAILS:
            code = bytes((lead, trail))
            try:
                code.decode("cp932")
            except UnicodeDecodeError:
                yield code


def read_original_codes() -> tuple[dict[str, bytes], set[bytes]]:
    codes = {}
    occupied = set()
    with ORIGINAL_TABLE.open(encoding="utf-8-sig", newline="") as stream:
        for row in csv.DictReader(stream, delimiter="\t"):
            char, code = row.get("char") or "", bytes.fromhex(row.get("code_hex") or "")
            if not code:
                continue
            validate_code_bytes(code)
            occupied.add(code)
            if len(char) == 1:
                codes.setdefault(char, code)
    return codes, occupied


def read_code_table(path: Path) -> dict[str, bytes]:
    result = {}
    owners = {}
    with path.open(encoding="utf-8-sig", newline="") as stream:
        for row in csv.DictReader(stream, delimiter="\t"):
            char = row.get("char") or ""
            code = bytes.fromhex(row.get("code_hex") or "")
            if len(char) != 1:
                raise ValueError("code-table rows must contain one Unicode character")
            validate_code_bytes(code)
            if char in result or code in owners:
                raise ValueError(f"duplicate character/code in table: {char!r} / {code.hex()}")
            result[char], owners[code] = code, char
    return result


def collect_source_text(translation_data: bytes) -> Counter[str]:
    chars = Counter()
    with SCRIPT_STRINGS.open(encoding="utf-8-sig", newline="") as stream:
        for row in csv.DictReader(stream):
            if row["category"] == "jp":
                chars.update(c for c in row["text"] if ord(c) >= 32)
    for row in csv.DictReader(io.StringIO(translation_data.decode("utf-8-sig"), newline="")):
        chars.update(c for c in row.get("translation", "") if ord(c) >= 32)
    return chars


def build_code_table_bundle(translation_data: bytes | None = None, *, native_codes: set[int] | None = None) -> dict:
    if translation_data is None:
        translation_data = TRANSLATION.read_bytes()
    if native_codes is None:
        sys.path.insert(0, str(ROOT / "scripts/build"))
        from build_font import native_codepoints
        native_codes = native_codepoints()
    original, reserved = read_original_codes()
    reserved.update(code.to_bytes(1 if code <= 255 else 2, "big") for code in native_codes)
    counts = collect_source_text(translation_data)
    chars = sorted(counts, key=ord)
    table = {}
    kinds = {}
    owners = {}
    pending = []
    for char in chars:
        code = original.get(char)
        if code is not None:
            if code in owners and owners[code] != char:
                raise ValueError("original table contains conflicting Unicode meanings")
            table[char], owners[code], kinds[char] = code, char, "original_table"
    for char in chars:
        if char in table:
            continue
        try:
            code = char.encode("cp932")
            validate_code_bytes(code)
            # These native single bytes display Buriko hiragana, not CP932 halfwidth kana.
            if len(code) == 1 and 0xA1 <= code[0] <= 0xDF:
                raise ValueError("Buriko single-byte semantic conflict")
            if code in owners:
                raise ValueError("CP932 Unicode alias requires a distinct glyph code")
        except (UnicodeEncodeError, ValueError):
            pending.append(char)
            continue
        table[char], owners[code] = code, char
        kinds[char] = "cp932_singlebyte" if len(code) == 1 else "cp932_doublebyte"
    previous = {}
    previous_path = GENERATED_DIR / "font_code_table_reset.tsv"
    if previous_path.exists():
        with previous_path.open(encoding="utf-8-sig", newline="") as stream:
            for row in csv.DictReader(stream, delimiter="\t"):
                try:
                    code = bytes.fromhex(row["code_hex"])
                except ValueError:
                    continue
                previous[row["char"]] = code
    preserved = 0
    for char in pending:
        code = previous.get(char)
        if code is None or code in reserved or code in owners or len(code) != 2:
            continue
        if not is_lead(code[0]) or not is_trail(code[1]):
            continue
        table[char], owners[code], kinds[char] = code, char, "private_reset"
        preserved += 1
    pool = iter_custom_codes()
    for char in pending:
        if char in table:
            continue
        code = next((code for code in pool if code not in reserved and code not in owners), None)
        if code is None:
            raise ValueError("legal unused SJIS glyph codes exhausted; no text/font files were modified")
        table[char], owners[code], kinds[char] = code, char, "private_reset"
    for code in table.values():
        validate_code_bytes(code)
    if len(set(table.values())) != len(table):
        raise ValueError("code-table mapping is not reversible")
    stream = io.StringIO(newline="")
    writer = csv.DictWriter(stream, fieldnames=["char", "unicode", "count", "code_hex", "code_source", "note"], delimiter="\t")
    writer.writeheader()
    for char in chars:
        writer.writerow({"char": char, "unicode": f"U+{ord(char):04X}", "count": counts[char],
                         "code_hex": table[char].hex(" ").upper(), "code_source": kinds[char],
                         "note": "original native mapping" if kinds[char] == "original_table" else
                         "matching glyph required in every font; generated with the script release"})
    files = {
        "localization/font/generated/font_code_table_reset.tsv": stream.getvalue().encode("utf-8"),
        "localization/font/generated/required_charset.txt": "".join(chars).encode("utf-8"),
        "localization/font/generated/buriko_singlebyte_kana_table.tsv": SINGLE_BYTE_TABLE.read_bytes(),
    }
    report = {
        "total_chars": len(table), "private_reset_chars": len(pending),
        "preserved_private_assignments": preserved,
        "migrated_assignments": sum(char in previous and previous[char] != table[char] for char in chars),
        "private_pool_capacity": 1880, "custom_pool_capacity": sum(1 for code in iter_custom_codes() if code not in reserved),
        "overflow_custom_codes": sum(kinds[c] == "private_reset" and table[c][0] not in PRIVATE_LEADS for c in chars),
        "illegal_code_count": 0, "duplicate_code_count": 0,
        "translation_sha256": hashlib.sha256(translation_data).hexdigest(),
        "allocation": "preserve native and valid historical codes; F0-F9 then unused undefined CP932 pairs",
    }
    files["localization/font/generated/manifest.json"] = (json.dumps(report, ensure_ascii=False, indent=2) + "\n").encode("utf-8")
    return {"table": table, "files": files, "report": report}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out-dir", type=Path, help="Stage candidate code-table files in an archive directory")
    parser.add_argument("--refresh-extract", action="store_true", help=argparse.SUPPRESS)
    args = parser.parse_args()
    if args.refresh_extract:
        parser.error("live extraction may destroy the Japanese row baseline; use the complete release builder")
    bundle = build_code_table_bundle()
    print(json.dumps(bundle["report"], ensure_ascii=False, indent=2))
    if args.out_dir:
        target = args.out_dir.resolve()
        if (ROOT / "archive").resolve() not in target.parents:
            parser.error("candidate directory must be below archive/")
        for relative, data in bundle["files"].items():
            path = target / Path(relative).name
            if path.exists() and path.read_bytes() != data:
                raise FileExistsError(f"different candidate already exists: {path}")
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(data)
    else:
        print("Checked in memory. Use scripts/build/build_localization.py --apply for a complete release.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
