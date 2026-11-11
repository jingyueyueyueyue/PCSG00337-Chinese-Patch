# -*- coding: utf-8 -*-
import json

# budget self-check table: id -> budget (from batch TSV, col 5)
budgets = {
    "b053_ev3435_0011": 41,
    "b053_ev3435_0013": 11,
    "b053_ev3435_0021": 32,
    "b053_ev3435_0037": 20,
    "b053_ev3435_0095": 8,
    "b053_ev3435_0104": 28,
    "b053_ev3435_0118": 31,
    "b053_ev3435_0133": 18,
    "b053_ev3435_0144": 21,
    "b053_ev3435_0172": 61,
    "b053_ev3435_0176": 19,
    "b053_ev3435_0195": 26,
    "b053_ev3435_0207": 35,
    "b053_ev3435_0211": 26,
    "b053_ev3435_0242": 30,
    "b053_ev3435_0244": 25,
    "b053_ev3435_0270": 87,
    "b053_ev3435_0272": 29,
    "b053_ev3435_0278": 8,
    "b053_ev3435_0302": 29,
    "b053_ev3435_0306": 25,
}

patches = [
    {"id": "b053_ev3435_0011", "translation": r"「不用管我。好好睡觉，为明天做准备吧」"},
    {"id": "b053_ev3435_0013", "translation": r"「嗯、嗯」"},
    {"id": "b053_ev3435_0021", "translation": r"（……为什么，我会睡在这里呢？）"},
    {"id": "b053_ev3435_0037", "translation": r"（不存在的未来……）"},
    {"id": "b053_ev3435_0095", "translation": r"「哎呀」"},
    {"id": "b053_ev3435_0104", "translation": r"总之，照吩咐在餐桌前坐下。"},
    {"id": "b053_ev3435_0118", "translation": r"「……谢谢，解决了一个烦恼」"},
    {"id": "b053_ev3435_0133", "translation": r"「原来那样就行啊」"},
    {"id": "b053_ev3435_0144", "translation": r"奉莉烦恼的一角……"},
    {"id": "b053_ev3435_0172", "translation": r"步梦是男孩这话已经成了谎话，我觉得有必要告诉未玖。"},
    {"id": "b053_ev3435_0176", "translation": r"未玖自己想通了。"},
    {"id": "b053_ev3435_0195", "translation": r"「3号桌，有客人点单了」"},
    {"id": "b053_ev3435_0207", "translation": r"「又来一单——指名三谷同学」"},
    {"id": "b053_ev3435_0211", "translation": r"「爱恋扑通扑通抱抱滚！」", "note": "按词表统一咒语译名"},
    {"id": "b053_ev3435_0242", "translation": r"「这事我也会向东云小姐说明」"},
    {"id": "b053_ev3435_0244", "translation": r"「好。步梦小姐特制！」"},
    {"id": "b053_ev3435_0270", "translation": r"「好的。这粉色奶油上点缀的草莓……足以看出步梦小姐对父亲大人的深深敬意！」"},
    {"id": "b053_ev3435_0272", "translation": r"「好，既然三谷前辈这么说」"},
    {"id": "b053_ev3435_0278", "translation": r"「哎呀」"},
    {"id": "b053_ev3435_0302", "translation": r"虽然完全不懂她想通了什么……"},
    {"id": "b053_ev3435_0306", "translation": r"正是当之无愧的人气第一。", "note": "按词表泛指语境译人气第一"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

def width(s):
    return sum(2 if ord(ch) > 127 else 1 for ch in s)

over = [(p["id"], width(p["translation"]), budgets[p["id"]])
        for p in patches if width(p["translation"]) > budgets[p["id"]]]
if over:
    raise SystemExit("too_long: %r" % over)

missing = [p["id"] for p in patches if p["id"] not in budgets]
if missing:
    raise SystemExit("no budget for: %r" % missing)

json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b053_ev3435.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
