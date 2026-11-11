#!/usr/bin/env python3
"""Validate script import length and control-token constraints."""

from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from collections import defaultdict
from datetime import datetime
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
SCRIPT_STRINGS = ROOT / "extracted" / "script" / "script_strings.csv"
DEFAULT_TRANSLATION = ROOT / "localization" / "text" / "translation_source.csv"
DEFAULT_CODE_TABLE = ROOT / "localization" / "font" / "generated" / "font_code_table_reset.tsv"
REPORT_DIR = ROOT / "localization" / "reports"

ANGLE_TAG_RE = re.compile(r"<[^>\r\n]+>(?:\([^)\r\n]*\))?")
ESCAPED_CONTROL_RE = re.compile(r"\\[nrt]")
BRACKET_CONTROL_RE = re.compile(r"\[[A-Za-z_][A-Za-z0-9_:=,;+\-./# ]{0,120}\]")
# 翻译方案允许删除 ruby 注音标记（中文无注音），校验时两侧同步豁免。
RUBY_TAG_RE = re.compile(r"<ruby2?>\([^)\r\n]*\)")


def read_script_rows(path: Path) -> list[dict[str, str]]:
    with path.open("r", encoding="utf-8-sig", newline="") as handle:
        return list(csv.DictReader(handle))


def read_code_table(path: Path) -> dict[str, bytes]:
    table: dict[str, bytes] = {}
    if not path.exists():
        return table
    with path.open("r", encoding="utf-8-sig", newline="") as handle:
        reader = csv.DictReader(handle, delimiter="\t")
        for row in reader:
            char = row.get("char") or ""
            code_hex = row.get("code_hex") or ""
            if len(char) != 1 or not code_hex:
                continue
            try:
                table[char] = bytes.fromhex(code_hex)
            except ValueError:
                continue
    return table


def candidate_field(row: dict[str, str], names: tuple[str, ...]) -> str:
    lowered = {key.lower(): key for key in row}
    for name in names:
        key = lowered.get(name.lower())
        if key is not None:
            return row.get(key, "")
    return ""


def read_translation_rows(path: Path) -> list[dict[str, str]]:
    with path.open("r", encoding="utf-8-sig", newline="") as handle:
        return list(csv.DictReader(handle))


def raw_len_from_hex(raw_hex: str) -> int | None:
    try:
        return len(bytes.fromhex(raw_hex))
    except ValueError:
        return None


def control_signature(text: str) -> list[str]:
    text = RUBY_TAG_RE.sub("", text)
    tokens: list[tuple[int, str]] = []
    for index, char in enumerate(text):
        if char in "\r\n\t":
            tokens.append((index, repr(char)))
    for regex in (ANGLE_TAG_RE, ESCAPED_CONTROL_RE, BRACKET_CONTROL_RE):
        for match in regex.finditer(text):
            tokens.append((match.start(), match.group(0)))
    return [token for _index, token in sorted(tokens, key=lambda item: item[0])]


def encoded_length(text: str, code_table: dict[str, bytes]) -> tuple[int, list[str]]:
    total = 0
    missing: list[str] = []
    for char in text:
        if char in "\r\n\t":
            total += 1
            continue
        mapped = code_table.get(char)
        if mapped is not None:
            total += len(mapped)
            continue
        try:
            total += len(char.encode("cp932"))
        except UnicodeEncodeError:
            missing.append(char)
    return total, sorted(set(missing), key=lambda ch: (ord(ch), ch))


def build_original_indexes(rows: list[dict[str, str]]):
    by_raw: dict[str, dict[str, str]] = {}
    by_offset_source: dict[tuple[str, str], list[dict[str, str]]] = defaultdict(list)
    for row in rows:
        if row.get("category") != "jp":
            continue
        raw_hex = row.get("raw_hex", "")
        if raw_hex:
            by_raw.setdefault(raw_hex, row)
        by_offset_source[(row.get("offset", ""), row.get("text", ""))].append(row)
    return by_raw, by_offset_source


def resolve_original(
    row: dict[str, str],
    by_raw: dict[str, dict[str, str]],
    by_offset_source: dict[tuple[str, str], list[dict[str, str]]],
) -> list[dict[str, str]]:
    """返回所有候选原文行。

    同一 (offset, source) 可能对应多行（如全角/半角假名两种存储的重复句）。
    导入器会替换所有出现位置，因此校验按所有候选中最小的 raw_len 执行。
    """
    raw_hex = candidate_field(row, ("raw_hex", "original_raw_hex"))
    if raw_hex and raw_hex in by_raw:
        return [by_raw[raw_hex]]

    offset = candidate_field(row, ("offset", "script_offset"))
    source = candidate_field(row, ("source", "original", "jp", "text", "原文"))
    return by_offset_source.get((offset, source), [])


def validate(args: argparse.Namespace) -> int:
    if not SCRIPT_STRINGS.exists():
        print(f"missing script extraction: {SCRIPT_STRINGS}", file=sys.stderr)
        return 2
    if not args.translation.exists():
        print(f"translation file not found, nothing to validate: {args.translation}")
        return 0

    script_rows = read_script_rows(SCRIPT_STRINGS)
    by_raw, by_offset_source = build_original_indexes(script_rows)
    code_table = read_code_table(args.code_table)
    translation_rows = read_translation_rows(args.translation)

    REPORT_DIR.mkdir(parents=True, exist_ok=True)
    report_rows = []
    status_counts = defaultdict(int)

    for index, trans_row in enumerate(translation_rows, start=2):
        translation = candidate_field(
            trans_row,
            ("translation", "translated", "zh", "chs", "cn", "text_cn", "译文", "中文"),
        )
        if not translation:
            continue

        originals = resolve_original(trans_row, by_raw, by_offset_source)
        if not originals:
            status = "missing_original"
            report_rows.append(
                {
                    "csv_line": index,
                    "status": status,
                    "offset": candidate_field(trans_row, ("offset", "script_offset")),
                    "source": candidate_field(trans_row, ("source", "original", "jp", "text", "原文")),
                    "translation": translation,
                    "raw_len": "",
                    "encoded_len": "",
                    "remaining": "",
                    "missing_chars": "",
                    "source_controls": "",
                    "translation_controls": "",
                    "note": "Cannot resolve original row; include raw_hex or exact offset+source.",
                }
            )
            status_counts[status] += 1
            continue

        raw_len = min(
            (raw_len_from_hex(o.get("raw_hex", "")) for o in originals),
            key=lambda v: (v is None, v if v is not None else 0),
        )
        control_source_text = originals[0].get("text", "")
        encoded_len, missing_chars = encoded_length(translation, code_table)
        source_controls = control_signature(control_source_text)
        translation_controls = control_signature(translation)

        problems = []
        if raw_len is None:
            problems.append("bad_raw_hex")
        elif encoded_len > raw_len and getattr(args, "in_place", False):
            problems.append("too_long")
        if missing_chars:
            problems.append("missing_code")
        if source_controls != translation_controls:
            problems.append("control_mismatch")

        status = "ok" if not problems else "+".join(problems)
        status_counts[status] += 1
        report_rows.append(
            {
                "csv_line": index,
                "status": status,
                "offset": originals[0].get("offset", ""),
                "source": control_source_text,
                "translation": translation,
                "raw_len": raw_len if raw_len is not None else "",
                "encoded_len": encoded_len,
                "remaining": raw_len - encoded_len if raw_len is not None else "",
                "missing_chars": "".join(missing_chars),
                "source_controls": json.dumps(source_controls, ensure_ascii=False),
                "translation_controls": json.dumps(translation_controls, ensure_ascii=False),
                "note": "; ".join(problems) or (
                    "STR/STBL rebuild required; supported by build_localization.py"
                    if raw_len is not None and encoded_len > raw_len else ""),
            }
        )

    report_path = REPORT_DIR / "import_constraints_report.tsv"
    with report_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "csv_line",
                "status",
                "offset",
                "source",
                "translation",
                "raw_len",
                "encoded_len",
                "remaining",
                "missing_chars",
                "source_controls",
                "translation_controls",
                "note",
            ],
            delimiter="\t",
        )
        writer.writeheader()
        writer.writerows(report_rows)

    summary = {
        "generated_at": datetime.now().isoformat(timespec="seconds"),
        "translation": str(args.translation.relative_to(ROOT) if args.translation.is_relative_to(ROOT) else args.translation),
        "code_table": str(args.code_table.relative_to(ROOT) if args.code_table.is_relative_to(ROOT) else args.code_table),
        "rows_checked": len(report_rows),
        "status_counts": dict(status_counts),
        "report": str(report_path.relative_to(ROOT)),
    }
    summary_path = REPORT_DIR / "import_constraints_summary.json"
    summary_path.write_text(json.dumps(summary, ensure_ascii=False, indent=2), encoding="utf-8")

    bad = sum(count for status, count in status_counts.items() if status != "ok")
    print(f"checked: {len(report_rows)}")
    print(f"bad: {bad}")
    print(f"report: {report_path}")
    return 1 if bad else 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--translation", type=Path, default=DEFAULT_TRANSLATION)
    parser.add_argument("--code-table", type=Path, default=DEFAULT_CODE_TABLE)
    parser.add_argument("--in-place", action="store_true", help="Legacy length-limit check; the full builder supports growth")
    args = parser.parse_args()
    args.translation = args.translation.resolve()
    args.code_table = args.code_table.resolve()
    return validate(args)


if __name__ == "__main__":
    raise SystemExit(main())
