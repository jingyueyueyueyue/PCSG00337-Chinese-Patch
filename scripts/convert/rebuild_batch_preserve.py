# -*- coding: utf-8 -*-
"""按生成器算法重建指定批次文件的完整行集，保留现有译文（按 id 匹配）。"""
import csv
import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TARGET = set(sys.argv[1:])  # 如 b013_ev0500

blocks = json.loads((ROOT / "extracted/script/block_map.json").read_text(encoding="utf-8"))
blocks.sort(key=lambda b: int(b["offset"], 16))
scen_of = {b["offset"]: (b["scen"][0][:-2] if b["scen"] else "system") for b in blocks}

by_off = defaultdict(list)
with open(ROOT / "extracted/script/script_strings.csv", encoding="utf-8-sig", newline="") as f:
    for i, row in enumerate(csv.DictReader(f), start=2):
        if row["category"] == "jp":
            by_off[row["offset"]].append({
                "row": i, "offset": row["offset"],
                "budget": len(bytes.fromhex(row["raw_hex"])), "source": row["text"],
            })

batches, cur = [], []
for b in blocks:
    cur.extend(by_off.get(b["offset"], []))
    if len(cur) >= 400:
        batches.append(cur)
        cur = []
if cur:
    batches.append(cur)

allseen = set()
for k, b2 in enumerate(batches):
    lines = [r for r in b2 if r["source"] not in allseen]
    for r in b2:
        allseen.add(r["source"])
    name = f"b{k+1:03d}_{scen_of[b2[0]['offset']]}"
    if name not in TARGET:
        continue
    out = ROOT / f"localization/text/work/{name}.tsv"
    # 读取现有译文
    old = {}
    if out.exists():
        with open(out, encoding="utf-8", newline="") as f:
            for r in csv.DictReader(f, delimiter="\t"):
                if (r.get("translation") or "").strip():
                    old[r["id"]] = (r["translation"].strip(), (r.get("note") or "").strip())
    with open(out, "w", encoding="utf-8", newline="") as f:
        f.write("id\trow\toffset\tscen\tbudget\tsource\ttranslation\tnote\n")
        kept = added = 0
        for j, r in enumerate(lines, 1):
            rid = f"{name}_{j:04d}"
            src = r["source"].replace("\\", "\\\\").replace("\n", "\\n").replace("\t", "\\t")
            tr, note = old.get(rid, ("", ""))
            if tr:
                kept += 1
            else:
                added += 1
            f.write(f"{rid}\t{r['row']}\t{r['offset']}\t{scen_of[r['offset']]}\t"
                    f"{r['budget']}\t{src}\t{tr}\t{note}\n")
    print(f"{name}: rebuilt {len(lines)} rows, kept {kept} translations, {added} empty")
