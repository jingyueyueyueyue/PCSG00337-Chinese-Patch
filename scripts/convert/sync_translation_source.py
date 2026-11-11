#!/usr/bin/env python3
"""Merge verified work batches into the formal CSV without editing live files.

Exact row translations take priority over repeated-source fallback. Validate
immutable columns and the complete batch inventory before accepting any text.
The release builder consumes the returned bytes and installs this CSV together
with its code table, fonts and scripts. --apply only updates the formal CSV.
"""
from __future__ import annotations

import argparse
import csv
from datetime import datetime
import hashlib
import io
import json
import os
from pathlib import Path
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[2]
ORIGINAL = ROOT / "extracted/script/script_strings.csv"
WORK = ROOT / "localization/text/work"
FORMAL = ROOT / "localization/text/translation_source.csv"
sys.path.insert(0, str(ROOT / "scripts/analysis"))
from validate_import_constraints import control_signature


def unescape(text: str) -> str:
    result = []
    position = 0
    escapes = {"n": "\n", "t": "\t", "\\": "\\"}
    while position < len(text):
        if text[position] == "\\" and position + 1 < len(text) and text[position + 1] in escapes:
            result.append(escapes[text[position + 1]])
            position += 2
        else:
            result.append(text[position])
            position += 1
    return "".join(result)


def read_rows(path: Path, delimiter=",") -> list[dict[str, str]]:
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream, delimiter=delimiter))


def checked_batches(original: dict[int, dict[str, str]]) -> tuple[list[dict], list[Path]]:
    manifest_path = WORK / "manifest.json"
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    blocks_path = ROOT / "extracted/script/block_map.json"
    blocks = sorted(json.loads(blocks_path.read_text(encoding="utf-8")), key=lambda item: int(item["offset"], 16))
    by_offset = {}
    for line, row in original.items():
        by_offset.setdefault(row["offset"], []).append((line, row))
    ordered = [item for block in blocks for item in by_offset.get(block["offset"], [])]
    if len(ordered) != len(original):
        raise ValueError("block map does not cover every original Japanese row")
    expected_paths = {(ROOT / item["file"]).resolve() for item in manifest}
    if expected_paths != {path.resolve() for path in WORK.glob("b*.tsv")}:
        raise ValueError("batch file inventory differs from work/manifest.json")
    position = 0
    seen_sources = set()
    all_rows = []
    sources = [ORIGINAL, manifest_path, blocks_path]
    for item in manifest:
        path = (ROOT / item["file"]).resolve()
        if path.parent != WORK.resolve():
            raise ValueError("batch manifest path leaves localization/text/work")
        covered = ordered[position:position + int(item["rows_covered"])]
        position += len(covered)
        expected = [(line, row) for line, row in covered if row["text"] not in seen_sources]
        seen_sources.update(row["text"] for _, row in covered)
        rows = read_rows(path, "\t")
        if len(rows) != len(expected) or len(rows) != int(item["lines"]):
            raise ValueError(f"{path.name}: missing or additional batch rows")
        for sequence, (work, (line, source)) in enumerate(zip(rows, expected), 1):
            wanted_id = f"{item['batch']}_{sequence:04d}"
            if (work.get("id") != wanted_id or int(work.get("row", -1)) != line
                    or work.get("offset") != source["offset"]
                    or unescape(work.get("source", "")) != source["text"]
                    or int(work.get("budget", -1)) != len(bytes.fromhex(source["raw_hex"]))):
                raise ValueError(f"{path.name} / {wanted_id}: source, row, ID, offset or budget was changed")
            text = unescape(work.get("translation") or "")
            if text.strip():
                if "\0" in text:
                    raise ValueError(f"{wanted_id}: translation contains NUL")
                if control_signature(source["text"]) != control_signature(text):
                    raise ValueError(f"{wanted_id}: control tokens differ")
                all_rows.append({"row": line, "source": source["text"], "offset": source["offset"],
                                 "translation": text, "note": work.get("note") or "", "batch_id": wanted_id})
        sources.append(path)
    if position != len(ordered):
        raise ValueError("batch manifest does not cover the full original source")
    return all_rows, sources


def build_translation_bundle(*, formal_only: bool = False) -> dict:
    original = {line: row for line, row in enumerate(read_rows(ORIGINAL), 2) if row["category"] == "jp"}
    existing = {}
    if FORMAL.exists():
        for row in read_rows(FORMAL):
            line = int(row["id"][2:]) if row["id"].startswith("jp") else -1
            source = original.get(line)
            if source is None or source["offset"] != row["offset"] or source["text"] != row["source"]:
                raise ValueError(f"formal CSV source drift: {row['id']}")
            if line in existing:
                raise ValueError(f"duplicate formal ID: {row['id']}")
            existing[line] = row
    sources = [ORIGINAL, FORMAL]
    batch_rows = []
    if not formal_only:
        batch_rows, sources = checked_batches(original)
        sources.append(FORMAL)
    by_row = {row["row"]: row for row in batch_rows}
    by_context = {}
    by_source = {}
    variants = {}
    for row in batch_rows:
        by_context.setdefault((row["offset"], row["source"]), row)
        by_source.setdefault(row["source"], row)
        variants.setdefault(row["source"], set()).add(row["translation"])
    output = io.StringIO(newline="")
    writer = csv.DictWriter(output, fieldnames=["id", "offset", "source", "translation", "note"])
    writer.writeheader()
    filled = changed = expanded = exact = 0
    for line, source in original.items():
        old = existing.get(line, {})
        selected = (by_row.get(line) or by_context.get((source["offset"], source["text"]))
                    or by_source.get(source["text"]) or old)
        translation = selected.get("translation") or ""
        if translation:
            if "\0" in translation or control_signature(source["text"]) != control_signature(translation):
                raise ValueError(f"jp{line:06d}: invalid text or control tokens")
            filled += 1
            exact += line in by_row
            expanded += sum(1 if ord(c) < 128 else 2 for c in translation) > len(bytes.fromhex(source["raw_hex"]))
        changed += translation != old.get("translation", "")
        writer.writerow({"id": f"jp{line:06d}", "offset": source["offset"], "source": source["text"],
                         "translation": translation, "note": selected.get("note") or old.get("note") or ""})
    data = output.getvalue().encode("utf-8-sig")
    return {"data": data, "sources": list(dict.fromkeys(sources)), "report": {
        "mode": "formal" if formal_only else "batches", "rows": len(original), "translated_rows": filled,
        "batch_translated_rows": len(batch_rows), "exact_row_translations": exact,
        "changed_from_formal_rows": changed, "untranslated_rows": len(original) - filled,
        "contextual_source_variants": sum(len(texts) > 1 for texts in variants.values()),
        "rows_exceeding_old_budget": expanded, "source_integrity_errors": 0,
        "control_token_errors": 0, "sha256": hashlib.sha256(data).hexdigest(),
    }}


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--formal-only", action="store_true", help="Use the formal CSV without batch overrides")
    parser.add_argument("--apply", action="store_true", help="Synchronize the CSV; game resources still require a full build")
    args = parser.parse_args(argv)
    bundle = build_translation_bundle(formal_only=args.formal_only)
    print(json.dumps(bundle["report"], ensure_ascii=False, indent=2))
    if args.apply and (not FORMAL.exists() or FORMAL.read_bytes() != bundle["data"]):
        archive = ROOT / "archive" / datetime.now().strftime("%Y-%m")
        archive.mkdir(parents=True, exist_ok=True)
        if FORMAL.exists():
            (archive / f"{datetime.now():%Y%m%d_%H%M%S%f}_before_sync_translation_source.csv").write_bytes(FORMAL.read_bytes())
        with tempfile.NamedTemporaryFile(dir=FORMAL.parent, delete=False, prefix=".translation_source_", suffix=".stage") as stream:
            temporary = Path(stream.name)
            stream.write(bundle["data"])
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temporary, FORMAL)
        print("Formal CSV synchronized. Run scripts/build/build_localization.py to build matching resources.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
