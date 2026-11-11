# -*- coding: utf-8 -*-
"""b058_ev3680 润色补丁构建（带控制符与显示宽度自检）"""
import json
import sys
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b058_ev3680.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b058_ev3680.json")

patches = [
    {"id": "b058_ev3680_0017", "translation": "「因为我——」"},
    {"id": "b058_ev3680_0031", "translation": "……说到底，奉莉为什么要说那种话？"},
    {"id": "b058_ev3680_0043", "translation": "要是想牵制我，用『身高不到180cm就不行』之类的就足够了。"},
    {"id": "b058_ev3680_0080", "translation": "然后那晚——"},
    {"id": "b058_ev3680_0086", "translation": "而且话题很敏感，我一个男的不好随便开口……"},
    {"id": "b058_ev3680_0087", "translation": "可这样一来…", "note": "预算紧，省略号减半"},
    {"id": "b058_ev3680_0117", "translation": "「……哎呀，到时间了。来，大家集合～」"},
    {"id": "b058_ev3680_0158", "translation": "这么说……"},
    {"id": "b058_ev3680_0163", "translation": "东云小姐今天头一次笑了。"},
    {"id": "b058_ev3680_0164", "translation": "东云小姐敛容，低头行礼。"},
    {"id": "b058_ev3680_0171", "translation": "「……为何变成这样？」"},
    {"id": "b058_ev3680_0183", "translation": "「今后两人关系能否改善，我不得而知」"},
    {"id": "b058_ev3680_0188", "translation": "「能拯救奉莉酱的只有三谷学长。真心拜托您了」"},
    {"id": "b058_ev3680_0209", "translation": "对，现在立刻——"},
    {"id": "b058_ev3680_0213", "translation": "说完之后——"},
    {"id": "b058_ev3680_0214", "translation": "——来了!"},
    {"id": "b058_ev3680_0240", "translation": "等了近一个小时——"},
    {"id": "b058_ev3680_0248", "translation": "「——我喜欢奉莉!」"},
    {"id": "b058_ev3680_0263", "translation": "「……陆斗!!」", "note": ""},
    {"id": "b058_ev3680_0277", "translation": "「可、可是……奉莉怎么看都是女孩……」"},
    {"id": "b058_ev3680_0287", "translation": "「猜错了真的抱歉。但我——」"},
    {"id": "b058_ev3680_0300", "translation": "「到此为止!而且，说好不再提那件事的——」"},
    {"id": "b058_ev3680_0318", "translation": "「因为我……」"},
    {"id": "b058_ev3680_0322", "translation": "「不……听到了……但没太懂……」"},
    {"id": "b058_ev3680_0329", "translation": "「是吗……到四十岁」"},
    {"id": "b058_ev3680_0363", "translation": "然后，在奉莉逃进儿童公园的那一刻——"},
    {"id": "b058_ev3680_0365", "translation": "后来成了互称盟友的关系，如今这样接吻着——"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：非 ASCII 计 2，半角计 1，对照批次 budget 列
def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

budgets = {}
for line in BATCH.read_text(encoding="utf-8").splitlines()[1:]:
    f = line.split("\t")
    if len(f) >= 6:
        budgets[f[0]] = int(f[4])

over = [(p["id"], enc_len(p["translation"]), budgets.get(p["id"])) for p in patches
        if p["id"] in budgets and enc_len(p["translation"]) > budgets[p["id"]]]
if over:
    for pid, n, b in over:
        print("TOO LONG: %s %d>%d" % (pid, n, b))
    raise SystemExit("width check failed")

missing = [p["id"] for p in patches if p["id"] not in budgets]
if missing:
    raise SystemExit("unknown ids: %r" % missing)

OUT.write_text(json.dumps({"patches": patches}, ensure_ascii=False, indent=1), encoding="utf-8")
print("patches:", len(patches))
