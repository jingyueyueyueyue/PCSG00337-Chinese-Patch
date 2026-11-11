# -*- coding: utf-8 -*-
"""b051_ev3350 润色补丁构建脚本（自带宽度自检）。"""
import csv
import json
import sys

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b051_ev3350.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b051_ev3350.json"

patches = [
    {"id": "b051_ev3350_0030", "translation": "「……吃？还是不吃？」"},
    {"id": "b051_ev3350_0035", "translation": "「……对哥哥来说可能不止是盐味饭团」"},
    {"id": "b051_ev3350_0073", "translation": "「不是啦，有步梦的饭团，我的就不必了吧？」"},
    {"id": "b051_ev3350_0076", "translation": "「嗯，硬要你吃，之后你说腻了步梦的手艺就糟了」"},
    {"id": "b051_ev3350_0105", "translation": "「别发呆，去搬那边桌子行不？」"},
    {"id": "b051_ev3350_0142", "translation": "「那，到底啥时候去赶海？」"},
    {"id": "b051_ev3350_0160", "translation": "「不愧是章介，振作快」"},
    {"id": "b051_ev3350_0166", "translation": "「这样啊，以为是好主意……」"},
    {"id": "b051_ev3350_0265", "translation": "「……呼」"},
    {"id": "b051_ev3350_0266", "translation": "「……行家连坨掉的过程也享受」"},
    {"id": "b051_ev3350_0268", "translation": "「……怎么了？陆斗」"},
    {"id": "b051_ev3350_0273", "translation": "「分一瓶茶的兄妹……恰似浇汁荞麦面故事」"},
    {"id": "b051_ev3350_0275", "translation": "「这次1分30秒，行家爱的硬度」"},
    {"id": "b051_ev3350_0280", "translation": "「没问题。每30秒会煮到什么硬度我都清楚」"},
    {"id": "b051_ev3350_0283", "translation": "「咳咳……」"},
    {"id": "b051_ev3350_0284", "translation": "「啊抱歉，没空慢悠悠了！」"},
    {"id": "b051_ev3350_0288", "translation": "「没事没事，一瓶我也喝不完」"},
    {"id": "b051_ev3350_0300", "translation": "「糟、糟了……喏，快喝！」"},
    {"id": "b051_ev3350_0306", "translation": "「咕咕……」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)


def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)


with open(BATCH, encoding="utf-8", newline="") as f:
    rows = {r["id"]: r for r in csv.DictReader(f, delimiter="\t")}

errors = []
for p in patches:
    r = rows.get(p["id"])
    if r is None:
        errors.append("unknown id: %s" % p["id"])
        continue
    n = enc_len(p["translation"])
    b = int(r["budget"])
    if n > b:
        errors.append("too_long %s: %d>%d %s" % (p["id"], n, b, p["translation"]))
if errors:
    for e in errors:
        print(e)
    raise SystemExit("width/id check failed")

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
