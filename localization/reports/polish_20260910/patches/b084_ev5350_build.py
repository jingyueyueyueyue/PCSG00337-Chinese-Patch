# -*- coding: utf-8 -*-
"""b084_ev5350 润色补丁构建（自带控制符与显示宽度自检）"""
import json

BUDGETS = {
    "b084_ev5350_0019": 17,
    "b084_ev5350_0042": 35,
    "b084_ev5350_0049": 30,
    "b084_ev5350_0098": 48,
    "b084_ev5350_0169": 13,
    "b084_ev5350_0250": 18,
    "b084_ev5350_0259": 54,
}

patches = [
    {"id": "b084_ev5350_0019", "translation": r"「奉莉酱明天见」"},
    {"id": "b084_ev5350_0042", "translation": r"我真的满脑子都是真央酱吗……？"},
    {"id": "b084_ev5350_0049", "translation": r"「那……超、超可爱哦，真央酱」"},
    {"id": "b084_ev5350_0098", "translation": r"「我也不太懂，说是自己要做的只有收拾贵重物品」"},
    {"id": "b084_ev5350_0169", "translation": r"「换我来？」"},
    {"id": "b084_ev5350_0250", "translation": r"「加油哦，真央酱」"},
    {"id": "b084_ev5350_0259", "translation": r"「没什么，在这节车厢碰过几次，想着你们说不定会坐……」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

too_long = [
    (p["id"], enc_len(p["translation"]), BUDGETS[p["id"]])
    for p in patches
    if p["id"] not in BUDGETS or enc_len(p["translation"]) > BUDGETS[p["id"]]
]
if too_long:
    raise SystemExit("too_long: %r" % too_long)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b084_ev5350.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
