# -*- coding: utf-8 -*-
import json

PATH_OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b041_ev2060.json"

def width(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

budgets = {
    "b041_ev2060_0033": 34,
    "b041_ev2060_0084": 33,
    "b041_ev2060_0132": 31,
    "b041_ev2060_0149": 14,
    "b041_ev2060_0174": 17,
    "b041_ev2060_0183": 17,
    "b041_ev2060_0240": 25,
    "b041_ev2060_0241": 18,
    "b041_ev2060_0296": 35,
    "b041_ev2060_0341": 25,
}

patches = [
    {"id": "b041_ev2060_0033", "translation": "多多少少都会给大家添麻烦的……"},
    {"id": "b041_ev2060_0084", "translation": "「好、好的……那就拜托您了？」"},
    {"id": "b041_ev2060_0132", "translation": "「家里有备着应急用的钱对吧？」"},
    {"id": "b041_ev2060_0149", "translation": "「步梦回了吗」", "note": "预算紧，省略问号"},
    {"id": "b041_ev2060_0174", "translation": "「诶？还有……」"},
    {"id": "b041_ev2060_0183", "translation": "「也没联系吗？」"},
    {"id": "b041_ev2060_0240", "translation": "「不行……车开过去了」", "note": "修正误译：いっちゃいました指车驶过未停，非昏倒"},
    {"id": "b041_ev2060_0241", "translation": "「……老爷爷！？」"},
    {"id": "b041_ev2060_0296", "translation": "「肋、肋骨……糟了！得赶紧处理！」"},
    {"id": "b041_ev2060_0341", "translation": "（等等，有光？是车吗？）"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

over = [(p["id"], width(p["translation"]), budgets[p["id"]])
        for p in patches if width(p["translation"]) > budgets[p["id"]]]
if over:
    raise SystemExit("too long: %r" % over)

missing = [i for i in budgets if i not in {p["id"] for p in patches}]
if missing:
    raise SystemExit("no patch for budget entry: %r" % missing)

json.dump({"patches": patches}, open(PATH_OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
