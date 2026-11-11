# -*- coding: utf-8 -*-
"""重建 b094_system.tsv（单行、正确转义）。"""
import csv
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
p = ROOT / "localization/text/work/b094_system.tsv"

line = "表演之夜的全部节目到此结束。"
NL = chr(92) + "n"  # 字面 反斜杠+n 两个字符
tr = line + NL + line + NL + line
src = ("パフォー<ruby>(0,あいう)マンスパーティーのプログラムはすべて終了した。" + NL
       + "パフォー<ruby>(0,あいう)マンスパーティーのプログラムはすべて終了した。" + NL
       + "パフォー<ruby>(0,あいう)マンスパーティーのプログラムはすべて終了した。")

with open(p, "w", encoding="utf-8", newline="") as f:
    f.write("id\trow\toffset\tscen\tbudget\tsource\ttranslation\tnote\n")
    f.write(f"b094_system_0001\t108471\t0x0035400C\tsystem\t182\t{src}\t{tr}\t删ruby；三行重复节目播报统一\n")

r = list(csv.DictReader(open(p, encoding="utf-8"), delimiter="\t"))[0]
n = sum(1 if ord(c) < 128 else 2 for c in r["translation"])
print("rows:", 1, "cols:", len(r), "translation bytes:", n, "budget:", r["budget"])
assert "\\n" in r["translation"], "escape lost"
print("escape ok")
