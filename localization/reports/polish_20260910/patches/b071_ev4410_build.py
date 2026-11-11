# -*- coding: utf-8 -*-
"""b071_ev4410 润色补丁构建（自带宽度自检）。

校验：id 存在、译文无制表符/真实换行、显示宽度(非ASCII=2)不超 budget。
通过后写出 b071_ev4410.json 供 apply_polish_patch.py 使用。
"""
import csv
import json
import os

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b071_ev4410.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b071_ev4410.json"

patches = [
    {"id": "b071_ev4410_0016",
     "translation": "「……不用猜，剧本八成出事了？」"},
    {"id": "b071_ev4410_0021",
     "translation": "「问她有没有打印稿，有的话给我们看看」"},
    {"id": "b071_ev4410_0040",
     "translation": "「呐，知道拜田酱怎么了？」"},
    {"id": "b071_ev4410_0063",
     "translation": "今天周三，要是大家知道『剧本得从头重写了』会怎么想。",
     "note": "叙述句，去误加的外层引号"},
    {"id": "b071_ev4410_0078",
     "translation": "看来拜田同学的拼劲传达到了，骚动渐渐变小。"},
    {"id": "b071_ev4410_0170",
     "translation": "「那之后我想了很多……只能判断，按现在的剧本很难拿总冠军……」"},
    {"id": "b071_ev4410_0192",
     "translation": "「就是说那网络小说。难怪『天使之泪』成那样」"},
    {"id": "b071_ev4410_0312",
     "translation": "我们班没有进过戏剧部的人确实有点麻烦，但说这些也无济于事。"},
    {"id": "b071_ev4410_0354",
     "translation": "「首、首先，是我构想的女主角，还有演对手戏的男主角……」"},
]


def width(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


rows = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        rows[r["id"]] = r

errors = []
for p in patches:
    pid = p["id"]
    if pid not in rows:
        errors.append("unknown id: " + pid)
        continue
    tr = p["translation"]
    if "\t" in tr or "\n" in tr or "\r" in tr:
        errors.append("control char in: " + pid)
        continue
    n, b = width(tr), int(rows[pid]["budget"])
    if n > b:
        errors.append("%s too_long %d>%d: %s" % (pid, n, b, tr))

if errors:
    raise SystemExit("\n".join(errors))

os.makedirs(os.path.dirname(OUT), exist_ok=True)
json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
