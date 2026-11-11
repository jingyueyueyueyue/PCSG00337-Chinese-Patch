# -*- coding: utf-8 -*-
"""b019_ev0999 润色补丁构建：生成 JSON，带宽度自检（全角=2/半角=1，与校验器一致）。"""
import csv
import json
import sys
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b019_ev0999.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b019_ev0999.json")

patches = [
    {"id": "b019_ev0999_0091", "translation": "「那么，首先想问一下报了超额项目的同学，有没有人愿意改报别的项目？」"},
    {"id": "b019_ev0999_0130", "translation": "「为什么？一旦留下作弊委员的印象可是致命伤哦？」"},
    {"id": "b019_ev0999_0140", "translation": "「你没有女式泳衣吗？」"},
    {"id": "b019_ev0999_0142", "translation": "「既然要以男学生身份打沙滩排球，就不能穿女式泳衣」"},
    {"id": "b019_ev0999_0156", "translation": "「嗯，我也不太明白。只是觉得自己一个人躲在安全的地方……所以……」"},
    {"id": "b019_ev0999_0171", "translation": "「没、没什么，没事的」"},
    {"id": "b019_ev0999_0187", "translation": "实在忍不住，我也脱了鞋，接着开始脱袜子。"},
    {"id": "b019_ev0999_0212", "translation": "……！！"},
    {"id": "b019_ev0999_0219", "translation": "「早就看穿了。章介边玩手机边在想多幺色的事，我也全都看在眼里」"},
    {"id": "b019_ev0999_0258", "translation": "「嗯……哥哥……」"},
    {"id": "b019_ev0999_0290", "translation": "与平时稍有不同。"},
    {"id": "b019_ev0999_0362", "translation": "「嗯……哥哥……」"},
]

enc_len = lambda s: sum(1 if ord(c) < 128 else 2 for c in s)

rows = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        rows[r["id"]] = r

bad = []
for p in patches:
    t = p["translation"]
    if "\t" in t or "\n" in t or "\r" in t:
        bad.append(f"{p['id']}: control char")
        continue
    if t.strip() == "":
        bad.append(f"{p['id']}: empty translation")
        continue
    if p["id"] not in rows:
        bad.append(f"{p['id']}: unknown id")
        continue
    w, b = enc_len(t), int(rows[p["id"]]["budget"])
    if w > b:
        bad.append(f"{p['id']}: width {w} > budget {b}: {t}")
if bad:
    for x in bad:
        print("BAD", x)
    sys.exit("patch self-check failed, JSON not written")

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "-> all width checks passed")
