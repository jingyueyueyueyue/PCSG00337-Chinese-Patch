# -*- coding: utf-8 -*-
"""全批次完整性审计：对照 script_strings.csv 校验每行 source 与 budget。"""
import csv
import glob
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
csv.field_size_limit(10**9)

truth = {}
with open(ROOT / "extracted/script/script_strings.csv", encoding="utf-8-sig", newline="") as f:
    for i, row in enumerate(csv.DictReader(f), start=2):
        if row["category"] == "jp":
            truth[i] = (row["text"], len(bytes.fromhex(row["raw_hex"])))

def unesc(s: str) -> str:
    out, i = [], 0
    while i < len(s):
        c = s[i]
        if c == "\\" and i + 1 < len(s):
            nxt = s[i + 1]
            if nxt == "n":
                out.append("\n"); i += 2; continue
            if nxt == "t":
                out.append("\t"); i += 2; continue
            if nxt == "\\":
                out.append("\\"); i += 2; continue
        out.append(c); i += 1
    return "".join(out)

bad_src = bad_budget = 0
for p in sorted(glob.glob(str(ROOT / "localization/text/work/b*.tsv"))):
    rows = list(csv.DictReader(open(p, encoding="utf-8"), delimiter="\t"))
    for r in rows:
        if r.get("row") is None or r.get("source") is None:
            bad_src += 1
            print("STRUCT-BAD", Path(p).name, r.get("id"))
            continue
        rown = int(r["row"])
        src = unesc(r["source"])
        t, b = truth.get(rown, (None, None))
        if t is None or src != t:
            bad_src += 1
            if bad_src <= 5:
                print("SRC-MISMATCH", Path(p).name, r["id"])
        if b is not None and int(r["budget"]) != b:
            bad_budget += 1
            if bad_budget <= 8:
                print("BUDGET-MISMATCH", Path(p).name, r["id"], r["budget"], "truth", b)
print("total src mismatches:", bad_src, " budget mismatches:", bad_budget)
sys.exit(1 if bad_src or bad_budget else 0)
