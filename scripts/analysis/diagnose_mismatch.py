# -*- coding: utf-8 -*-
"""抽样诊断批次文件与 CSV 的错位形态。"""
import csv
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
csv.field_size_limit(10**9)

truth = {}
with open(ROOT / "extracted/script/script_strings.csv", encoding="utf-8-sig", newline="") as f:
    for i, row in enumerate(csv.DictReader(f), start=2):
        if row["category"] == "jp":
            truth[i] = (row["offset"], row["text"], len(bytes.fromhex(row["raw_hex"])))

CASES = [
    ("b002_ev0040.tsv", "b002_ev0040_0090"),
    ("b004_ev0125.tsv", "b004_ev0125_0042"),
    ("b006_ev0210.tsv", "b006_ev0210_0086"),
    ("b007_ev0260.tsv", "b007_ev0260_0254"),
    ("b003_ev0095.tsv", "b003_ev0095_0089"),
    ("b003_ev0095.tsv", "b003_ev0095_0138"),
]
for fname, rid in CASES:
    rows = {r["id"]: r for r in csv.DictReader(open(ROOT / f"localization/text/work/{fname}", encoding="utf-8"), delimiter="\t")}
    r = rows[rid]
    rown = int(r["row"])
    print("=" * 70)
    print(f"{fname}  {rid}  row={rown}  file_budget={r['budget']}  file_offset={r['offset']}")
    t = truth.get(rown, ("?", "?", "?"))
    print("file src  :", r["source"][:70])
    print(f"csv[{rown}] : ({t[0]}) {t[1][:70]}  bytes={t[2]}")
    for d in (-1, 1):
        t2 = truth.get(rown + d)
        if t2:
            print(f"csv[{rown+d}]: ({t2[0]}) {t2[1][:70]}  bytes={t2[2]}")
