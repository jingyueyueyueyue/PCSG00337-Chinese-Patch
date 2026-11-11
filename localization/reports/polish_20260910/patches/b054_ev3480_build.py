# -*- coding: utf-8 -*-
"""b054_ev3480 润色补丁构建（带 id/宽度自检）"""
import csv
import json
import sys
from pathlib import Path

ROOT = Path(r"D:\VITA3K\ux0\app\PCSG00337")
TSV = ROOT / "localization/text/work/b054_ev3480.tsv"
OUT = ROOT / "localization/reports/polish_20260910/patches/b054_ev3480.json"

def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)

patches = [
    {"id": "b054_ev3480_0001", "translation": r"客人B"},  # 说话人条目按词表体例不加引号
    {"id": "b054_ev3480_0015", "translation": r"「哦，对了」"},
    {"id": "b054_ev3480_0026", "translation": r"说着，章介把视线投向客席。"},
    {"id": "b054_ev3480_0028", "translation": r"我也跟着看向客席。"},
    {"id": "b054_ev3480_0032", "translation": r"意外的结果让全班哗然。"},
    {"id": "b054_ev3480_0062", "translation": r"「喏，拜托」"},
    {"id": "b054_ev3480_0065", "translation": r"「现在最好快点转换心情，把目光转向下一步」"},
    {"id": "b054_ev3480_0081", "translation": r"「嘛，考虑销售额，我觉得是正确的判断。每次都填单子的话，翻台速度就会变慢」"},
    {"id": "b054_ev3480_0084", "translation": r"不过收拾基本已经结束，应援组正在做最后的垃圾收集。"},
    {"id": "b054_ev3480_0105", "translation": r"「……可你看起来还没想通哦？」"},
    {"id": "b054_ev3480_0114", "translation": r"「……呃，奉莉解释的？」"},
    {"id": "b054_ev3480_0117", "translation": r"「……为什么妹弟要代替哥哥来解释？」", "note": "删ruby"},
    {"id": "b054_ev3480_0138", "translation": r"「你们俩真是辛苦了——」"},
    {"id": "b054_ev3480_0148", "translation": r"「未玖从今天起跟哥哥们一起睡！」"},
    {"id": "b054_ev3480_0217", "translation": r"不过，睡我旁边当奖品真的行吗？"},  # 旁白，去误加引号
    {"id": "b054_ev3480_0261", "translation": r"「让孩子多的哥哥分你一个？」"},
    {"id": "b054_ev3480_0266", "translation": r"「继续……把未玖的棋子退回去」"},
    {"id": "b054_ev3480_0287", "translation": r"「要拿肚子药？」"},
    {"id": "b054_ev3480_0312", "translation": r"……怎么办？"},  # 旁白，去误加引号
    {"id": "b054_ev3480_0313", "translation": r"……今天也很怪。", "note": ""},  # 旁白；句号可放下，清掉旧提示
    {"id": "b054_ev3480_0316", "translation": r"……已不知该说什么才好。"},  # 旁白，去误加引号
    {"id": "b054_ev3480_0317", "translation": r"……本来打算和未玖睡的。"},  # 旁白，去误加引号
    {"id": "b054_ev3480_0359", "translation": r"「……能问一个吗？」", "note": ""},  # 问号可放下
    {"id": "b054_ev3480_0361", "translation": r"「……睡吧？」", "note": ""},  # 省略号问号可放下
    {"id": "b054_ev3480_0373", "translation": r"「谢谢你回答我……呜……谢谢……」"},
    {"id": "b054_ev3480_0408", "translation": r"而且明明没碰到，却感到奉莉的体温。"},
]

# ---- 自检：id 存在、无控制字符、宽度不超预算、只动 translation/note ----
with open(TSV, encoding="utf-8", newline="") as f:
    rows = {r["id"]: r for r in csv.DictReader(f, delimiter="\t")}

bad = []
for p in patches:
    pid = p["id"]
    if pid not in rows:
        bad.append(f"unknown id {pid}")
        continue
    tr = p["translation"]
    if "\t" in tr or "\n" in tr or "\r" in tr:
        bad.append(f"control char in {pid}")
        continue
    budget = int(rows[pid]["budget"])
    n = enc_len(tr)
    if n > budget:
        bad.append(f"too_long {pid}: {n}>{budget}")
if bad:
    raise SystemExit("SELF-CHECK FAILED:\n  " + "\n  ".join(bad))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), " self-check OK")
