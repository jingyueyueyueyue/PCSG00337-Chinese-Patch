# -*- coding: utf-8 -*-
"""打印错位区段的邻域形态。"""
import csv
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

rows = list(csv.DictReader(open(ROOT / "localization/text/work/b023_ev1200.tsv", encoding="utf-8"), delimiter="\t"))
# 找出前 12 个 shift 位置并打印邻域
hits = []
for idx, r in enumerate(rows):
    rown = int(r["row"]); src = unesc(r["source"]); t = truth.get(rown)
    if t != src and (truth.get(rown - 1) == src or truth.get(rown + 1) == src):
        hits.append(idx)
print("shift hits:", len(hits))
for idx in hits[:3]:
    print("=" * 60)
    for j in range(max(0, idx - 1), min(len(rows), idx + 3)):
        r = rows[j]; rown = int(r["row"]); src = unesc(r["source"])
        mark = ">>" if j == idx else "  "
        match = "OK " if truth.get(rown) == src else "BAD"
        print(f"{mark}{match} {r['id']} row={rown} src={src[:42]!r}")
        if truth.get(rown) != src:
            print(f"        truth[{rown}]={str(truth.get(rown))[:42]!r}")
            print(f"        truth[{rown-1}]={str(truth.get(rown-1))[:42]!r}")
            print(f"        truth[{rown+1}]={str(truth.get(rown+1))[:42]!r}")
