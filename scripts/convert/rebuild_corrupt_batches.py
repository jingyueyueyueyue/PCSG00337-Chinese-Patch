# -*- coding: utf-8 -*-
"""一次性：按生成器算法确定性重建被换行损坏的批次文件。"""
import csv
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TARGET = {70, 71, 93}  # 0-based 批次号：b071, b072, b094

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
    if k not in TARGET:
        continue
    name = f"b{k+1:03d}_{scen_of[b2[0]['offset']]}"
    out = ROOT / f"localization/text/work/{name}.tsv"
    with open(out, "w", encoding="utf-8", newline="") as f:
        f.write("id\trow\toffset\tscen\tbudget\tsource\ttranslation\tnote\n")
        for j, r in enumerate(lines, 1):
            src = r["source"].replace("\\", "\\\\").replace("\n", "\\n").replace("\t", "\\t")
            f.write(f"{name}_{j:04d}\t{r['row']}\t{r['offset']}\t"
                    f"{scen_of[r['offset']]}\t{r['budget']}\t{src}\t\t\n")
    print(name, len(lines), "lines rebuilt")

bad = 0
for p in sorted(ROOT.glob("localization/text/work/b*.tsv")):
    with open(p, encoding="utf-8") as f:
        for ln, line in enumerate(f, 1):
            if len(line.rstrip("\n").split("\t")) != 8:
                bad += 1
                print("BAD", p, ln)
print("bad lines:", bad)
