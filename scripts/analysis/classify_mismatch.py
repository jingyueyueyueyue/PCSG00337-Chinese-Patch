# -*- coding: utf-8 -*-
"""分类源文偏差：shift-prev / shift-next / edited / other；并找出缺失与多余行。"""
import csv
import glob
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
csv.field_size_limit(10**9)

truth = {}
with open(ROOT / "extracted/script/script_strings.csv", encoding="utf-8-sig", newline="") as f:
    for i, row in enumerate(csv.DictReader(f), start=2):
        if row["category"] == "jp":
            truth[i] = row["text"]

def unesc(s):
    out, i = [], 0
    while i < len(s):
        c = s[i]
        if c == "\\" and i + 1 < len(s) and s[i+1] in "nt\\":
            out.append({"n": "\n", "t": "\t", "\\": "\\"}[s[i+1]]); i += 2
        else:
            out.append(c); i += 1
    return "".join(out)

# 生成器算法重放：期望的 (batch -> [row])
blocks = json.loads((ROOT / "extracted/script/block_map.json").read_text(encoding="utf-8"))
blocks.sort(key=lambda b: int(b["offset"], 16))
scen_of = {b["offset"]: (b["scen"][0][:-2] if b["scen"] else "system") for b in blocks}
by_off = {}
for i in sorted(truth):
    by_off.setdefault(rows_off, []).append(i) if False else None
# 重新按 CSV 顺序取 offset
offs = {}
with open(ROOT / "extracted/script/script_strings.csv", encoding="utf-8-sig", newline="") as f:
    for i, row in enumerate(csv.DictReader(f), start=2):
        if row["category"] == "jp":
            offs[i] = row["offset"]
batches, cur = [], []
for b in blocks:
    cur.extend(sorted(offs_row for offs_row in [i for i in by_off_list.get(b["offset"], [])])) if False else None

# 简化：直接用 row 顺序 + offset 分组重放
from collections import defaultdict
rows_by_off = defaultdict(list)
for i, off in offs.items():
    rows_by_off[off].append(i)
batches, cur = [], []
for b in blocks:
    cur.extend(rows_by_off.get(b["offset"], []))
    if len(cur) >= 400:
        batches.append(cur); cur = []
if cur:
    batches.append(cur)

allseen = set()
expect = {}
for k, b2 in enumerate(batches):
    name = f"b{k+1:03d}_{scen_of[offs[b2[0]]]}"
    ids = []
    for j, rown in enumerate([r for r in b2 if truth[r] not in allseen], 1):
        ids.append((f"{name}_{j:04d}", rown))
    for r in b2:
        allseen.add(truth[r])
    expect[name] = ids

report = {}
for p in sorted(glob.glob(str(ROOT / "localization/text/work/b*.tsv"))):
    name = Path(p).stem
    file_rows = list(csv.DictReader(open(p, encoding="utf-8"), delimiter="\t"))
    exp = dict(expect.get(name, []))
    file_ids = {r["id"] for r in file_rows}
    missing = [eid for eid in exp if eid not in file_ids]
    extra = [r["id"] for r in file_rows if r["id"] not in exp]
    shifts = edits = other = 0
    for r in file_rows:
        rown = int(r["row"])
        src = unesc(r["source"])
        t = truth.get(rown)
        if t == src:
            continue
        if truth.get(rown - 1) == src:
            shifts += 1
        elif truth.get(rown + 1) == src:
            shifts += 1
        elif t and abs(len(t) - len(src)) <= max(6, len(t) // 4) and sum(a != b for a, b in zip(t, src)) <= 8:
            edits += 1
        else:
            other += 1
    if missing or extra or shifts or edits or other:
        report[name] = {"missing": len(missing), "extra": len(extra),
                        "shift": shifts, "edit": edits, "other": other}
for k, v in sorted(report.items()):
    print(k, v)
print("files affected:", len(report))
