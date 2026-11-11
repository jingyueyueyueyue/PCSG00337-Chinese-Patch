# -*- coding: utf-8 -*-
"""b045_ev3090 润色补丁构建：生成 JSON，并自带预算与控制符自检。"""
import json
import sys
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b045_ev3090.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b045_ev3090.json")

patches = [
    {"id": "b045_ev3090_0004",
     "translation": "「三四名决赛好像结束了」"},
    {"id": "b045_ev3090_0013",
     "translation": "「啊，不过拜田同学乒乓球进半决赛！」"},
    {"id": "b045_ev3090_0034",
     "translation": "我把真央酱接起的球高高托起。"},
    {"id": "b045_ev3090_0036",
     "translation": "真央酱的鱼跃救球够到了球，球砰地弹上空中。"},
    {"id": "b045_ev3090_0094",
     "translation": "「……也看看奈奈濑的表现吧」"},
    {"id": "b045_ev3090_0102",
     "translation": "「完美嘛！」", "note": ""},
    {"id": "b045_ev3090_0126",
     "translation": "「接下来干嘛？」"},
    {"id": "b045_ev3090_0209",
     "translation": "「不是温泉……是洗澡……」"},
    {"id": "b045_ev3090_0256",
     "translation": "「原来是这种构造啊」"},
    {"id": "b045_ev3090_0304",
     "translation": "但从昨晚起心里的郁结一直消不散……"},
    {"id": "b045_ev3090_0333",
     "translation": "「真无聊呢」"},
    {"id": "b045_ev3090_0345",
     "translation": "「话说女生那边怎样？」"},
    {"id": "b045_ev3090_0346",
     "translation": "「哈啊……好困……」", "note": ""},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 预算自检：全角=2、半角=1，新译文显示宽度必须 <= budget
def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

budgets = {}
for line in BATCH.read_text(encoding="utf-8").splitlines()[1:]:
    cols = line.split("\t")
    if len(cols) >= 5:
        budgets[cols[0]] = int(cols[4])

over = [(p["id"], enc_len(p["translation"]), budgets.get(p["id"]))
        for p in patches if p["id"] not in budgets or enc_len(p["translation"]) > budgets[p["id"]]]
if over:
    for pid, n, b in over:
        print(f"OVER BUDGET {pid}: {n}>{b}")
    raise SystemExit("budget check failed")

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
