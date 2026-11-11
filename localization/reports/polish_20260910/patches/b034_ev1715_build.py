# -*- coding: utf-8 -*-
"""b034_ev1715 润色补丁构建：生成 JSON 并做宽度/控制符自检。"""
import csv
import json
import sys
from pathlib import Path

ROOT = Path(r"D:\VITA3K\ux0\app\PCSG00337")
BATCH = ROOT / "localization/text/work/b034_ev1715.tsv"
OUT = ROOT / "localization/reports/polish_20260910/patches/b034_ev1715.json"

patches = [
    {"id": "b034_ev1715_0009", "translation": "兄妹……不想让妹妹哭……"},
    {"id": "b034_ev1715_0012", "translation": "让我叫妈妈这种话……良子绝不会说。"},
    {"id": "b034_ev1715_0022", "translation": "而且，总有一天我会打心底把良子小姐当成家人。"},
    {"id": "b034_ev1715_0047", "translation": "「对不起，哥哥」"},
    {"id": "b034_ev1715_0058", "translation": "「怪吗？」"},
    {"id": "b034_ev1715_0064", "translation": "「呀？」"},
    {"id": "b034_ev1715_0070", "translation": "呜哇啊啊……关于步梦的胸，我说了好多过分的话。"},
    {"id": "b034_ev1715_0090", "translation": "舞蹈组的大家在更衣室换上体操服，前往露台。"},
    {"id": "b034_ev1715_0094", "translation": "委员里被分到幕后组的就这两个人，有点担心……"},
    {"id": "b034_ev1715_0097", "translation": "在教室门口的奉莉叫住了我。"},
    {"id": "b034_ev1715_0104", "translation": "同时也冒火。"},
    {"id": "b034_ev1715_0118", "translation": "「不是和慈善义卖会那次一样吗……？」"},
    {"id": "b034_ev1715_0125", "translation": "「请加油，三谷君」"},
    {"id": "b034_ev1715_0133", "translation": "「女生不是跳不了高难度舞吗？」"},
    {"id": "b034_ev1715_0164", "translation": "「那么，宣布选拔队的成员」"},
    {"id": "b034_ev1715_0172", "translation": "好的。要记的舞很简单，但没有肌力是很吃力的位置。"},
    {"id": "b034_ev1715_0192", "translation": "于是，虽然我被选进了选拔队……"},
    {"id": "b034_ev1715_0233", "translation": "「为什么？那次被拦了……」"},
    {"id": "b034_ev1715_0242", "translation": "今天这样的谎……我最喜欢了……"},
    {"id": "b034_ev1715_0297", "translation": "「呐，找啥呢？」"},
    {"id": "b034_ev1715_0312", "translation": "而且还在拼命扫视着地面寻找。"},
    {"id": "b034_ev1715_0323", "translation": "不是大事的话，告诉我不就好了。"},
    {"id": "b034_ev1715_0339", "translation": "打心底这么想。"},
    {"id": "b034_ev1715_0368", "translation": "确实，每完成一次樱花祭活动，就觉得班级凝聚力更强了。"},
    {"id": "b034_ev1715_0372", "translation": "领队还夸我们不愧是选拔队，大家都进步很快"},
    {"id": "b034_ev1715_0376", "translation": "「奉莉的直觉吗」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)


def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)


rows = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        rows[r["id"]] = r

errs = []
for p in patches:
    rid = p["id"]
    if rid not in rows:
        errs.append(f"unknown id: {rid}")
        continue
    budget = int(rows[rid]["budget"])
    n = enc_len(p["translation"])
    if n > budget:
        errs.append(f"{rid}: width {n} > budget {budget}: {p['translation']}")
if errs:
    print("SELF-CHECK FAILED:")
    for e in errs:
        print("  " + e)
    sys.exit(1)

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "-> all width checks passed")
