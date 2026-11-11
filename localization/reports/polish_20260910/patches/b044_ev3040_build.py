# -*- coding: utf-8 -*-
"""b044_ev3040 润色补丁构建（自带宽度自检，预算=全角2/半角1，含引号）。"""
import csv
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b044_ev3040.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b044_ev3040.json")


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


patches = [
    # 「ま、奉莉ちゃんっ!」: ま是「待って」的截断，初翻误作名字结巴
    {"id": "b044_ev3040_0016",
     "translation": "「等、奉莉酱！呀！」"},
    # 「晴了真好呢」生硬，改顺口（预算内舍弃语尾ね）
    {"id": "b044_ev3040_0100",
     "translation": "「天晴了真好」"},
    # 说话人条目「対戦相手A/B」去冗余
    {"id": "b044_ev3040_0128",
     "translation": "对手A"},
    {"id": "b044_ev3040_0129",
     "translation": "对手B"},
    # 「自分も気になるし」补出“好奇”语气
    {"id": "b044_ev3040_0137",
     "translation": "「嗯。想请陆斗去看看其他项目，我自己也挺好奇」"},
    # 「真央酱棒！」生硬；预算 14 压不下「」，省略引号
    {"id": "b044_ev3040_0151",
     "translation": "太棒了真央酱！", "note": "预算紧省略「」"},
    # 「あと半分だ」＝还剩一半，初翻“才刚过一半”焦点反了
    {"id": "b044_ev3040_0170",
     "translation": "按球技大会的特别规则，比赛只打到第二节，还剩一半——"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

with open(BATCH, encoding="utf-8", newline="") as f:
    rows = {r["id"]: r for r in csv.DictReader(f, delimiter="\t")}

errors = []
for p in patches:
    r = rows.get(p["id"])
    if r is None:
        errors.append(f"{p['id']}: id not in batch")
        continue
    n = enc_len(p["translation"])
    b = int(r["budget"])
    if n > b:
        errors.append(f"{p['id']}: width {n}>{b}")
if errors:
    raise SystemExit("\n".join(errors))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
