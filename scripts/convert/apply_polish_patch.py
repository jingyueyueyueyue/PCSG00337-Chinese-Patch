# -*- coding: utf-8 -*-
"""按 id 将润色补丁安全写入批次 TSV 的 translation/note 列。

用法：
    python -X utf8 -B scripts/convert/apply_polish_patch.py <batch.tsv> <patch.json> [--dry-run]

patch.json 格式：
    {"batch": "b002_ev0040", "patches": [{"id": "b002_ev0040_0001", "translation": "...", "note": "..."}]}
note 可省略（保持原 note 不变）；translation 必填且不得为空字符串。

安全规则：
- 原始文本按物理行 + 制表符切分（本库批次均无带引号跨行字段），逐字段原样保留，
  只替换 translation 列；note 仅在补丁显式给出时替换（7 列行补 note 时补成 8 列）。
- 补丁中任何 id 不存在于目标文件、或新译文含制表符/换行/反斜杠n 以外的控制符时，
  整体拒绝写入（fail-fast），避免半套修改落盘。
"""
import csv
import json
import sys
from pathlib import Path


def split_fields(line):
    return line.split("\t")


def main():
    if len(sys.argv) < 3:
        print("usage: apply_polish_patch.py <batch.tsv> <patch.json> [--dry-run]")
        return 2
    batch_path = Path(sys.argv[1])
    patch_path = Path(sys.argv[2])
    dry = "--dry-run" in sys.argv[3:]

    data = batch_path.read_bytes()
    if data[:3] == b"\xef\xbb\xbf":
        print(f"FAIL: {batch_path} has BOM")
        return 1
    text = data.decode("utf-8")
    if "\r" in text:
        print(f"FAIL: {batch_path} contains CR")
        return 1
    lines = text.split("\n")
    if lines and lines[-1] == "":
        trailing_nl = True
        lines = lines[:-1]
    else:
        trailing_nl = False

    header = split_fields(lines[0])
    if header[0] != "id" or len(header) < 7:
        print(f"FAIL: unexpected header: {header}")
        return 1

    rows = [split_fields(l) for l in lines[1:]]
    id_to_idx = {}
    for i, r in enumerate(rows):
        if not r or not r[0]:
            print(f"FAIL: line {i + 2} has empty id")
            return 1
        if r[0] in id_to_idx:
            print(f"FAIL: duplicate id {r[0]}")
            return 1
        if len(r) not in (7, 8):
            print(f"FAIL: id {r[0]} has {len(r)} columns, expect 7 or 8")
            return 1
        id_to_idx[r[0]] = i

    patch = json.loads(patch_path.read_text(encoding="utf-8"))
    patches = patch["patches"] if isinstance(patch, dict) else patch

    errors = []
    for p in patches:
        pid = p.get("id", "")
        if pid not in id_to_idx:
            errors.append(f"unknown id: {pid}")
            continue
        new = p.get("translation")
        if not isinstance(new, str) or new == "":
            errors.append(f"empty translation for {pid}")
            continue
        if "\t" in new or "\n" in new or "\r" in new:
            errors.append(f"control char in translation for {pid}")
            continue
        if "note" in p and p["note"] is not None and ("\t" in p["note"] or "\n" in p["note"]):
            errors.append(f"control char in note for {pid}")
    if errors:
        print("PATCH REJECTED — nothing written:")
        for e in errors:
            print("  " + e)
        return 1

    changed = 0
    for p in patches:
        i = id_to_idx[p["id"]]
        row = rows[i]
        old = row[6]
        new = p["translation"]
        note_changed = False
        if "note" in p and p["note"] is not None:
            current_note = row[7] if len(row) == 8 else ""
            if current_note != p["note"]:
                note_changed = True
        if old == new and not note_changed:
            continue
        if dry:
            print(f"DRY {p['id']}\n  - {old}\n  + {new}")
        else:
            row[6] = new
            if "note" in p and p["note"] is not None:
                if len(row) == 7:
                    row.append(p["note"])
                else:
                    row[7] = p["note"]
        changed += 1

    print(f"patch items: {len(patches)}  rows actually changed: {changed}")
    if dry:
        return 0
    if changed == 0:
        print("no changes, file untouched")
        return 0

    out = lines[0] + "\n" + "\n".join("\t".join(r) for r in rows)
    if trailing_nl:
        out += "\n"
    batch_path.write_bytes(out.encode("utf-8"))
    print(f"written: {batch_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
