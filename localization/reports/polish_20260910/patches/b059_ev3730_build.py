# -*- coding: utf-8 -*-
"""b059_ev3730 润色补丁构建脚本（自带显示宽度自检）"""
import json

def width(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

patches = [
    {"id": "b059_ev3730_0005",
     "translation": r"奉莉温柔摸着怀里喜极而泣的步梦的头。",
     "note": "补出「自分の胸で」细节：步梦伏在奉莉怀里"},
    {"id": "b059_ev3730_0016",
     "translation": r"「……总感觉像真的在交往一样呢」"},
    {"id": "b059_ev3730_0017",
     "translation": r"「可是……可是……呜……太好了……」",
     "note": "补出呜咽声ううぅ"},
    {"id": "b059_ev3730_0054",
     "translation": r"「那么……我和奉莉，从昨天开始交往了」"},
    {"id": "b059_ev3730_0122",
     "translation": r"「对了，有件事我从昨天就在想」"},
    {"id": "b059_ev3730_0167",
     "translation": r"「所以三谷君今天就到此为止，为明天养精蓄锐吧」",
     "note": "三谷くん按称呼规则改三谷君"},
    {"id": "b059_ev3730_0174",
     "translation": r"赢得大家的掌声喝彩。"},
    {"id": "b059_ev3730_0181",
     "translation": r"为什么会变，我当然清楚。"},
    {"id": "b059_ev3730_0191",
     "translation": r"被伙伴们推了一把，我和奉莉离校约会去了。"},
    {"id": "b059_ev3730_0249",
     "translation": r"「我也懂奉莉的心情」"},
    {"id": "b059_ev3730_0250",
     "translation": r"「这里可以举办各种活动，不过这次是婚礼」"},
    {"id": "b059_ev3730_0268",
     "translation": r"「顺便问下，包场的人都会做些什么？」"},
    {"id": "b059_ev3730_0290",
     "translation": r"所谓带孩子的婚礼……"},
    {"id": "b059_ev3730_0292",
     "translation": r"不过这样也许更好，不会被人看出表情。"},
    {"id": "b059_ev3730_0293",
     "translation": r"刚才还羡慕望着新娘的奉莉，神色忽然变了。"},
    {"id": "b059_ev3730_0296",
     "translation": r"说着，这次把自己的鲷鱼烧递了过来。"},
]

budgets = {
    "b059_ev3730_0005": 39,
    "b059_ev3730_0016": 33,
    "b059_ev3730_0017": 36,
    "b059_ev3730_0054": 40,
    "b059_ev3730_0122": 30,
    "b059_ev3730_0167": 49,
    "b059_ev3730_0174": 20,
    "b059_ev3730_0181": 24,
    "b059_ev3730_0191": 44,
    "b059_ev3730_0249": 20,
    "b059_ev3730_0250": 43,
    "b059_ev3730_0268": 36,
    "b059_ev3730_0290": 21,
    "b059_ev3730_0292": 37,
    "b059_ev3730_0293": 42,
    "b059_ev3730_0296": 34,
}

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

over = [(p["id"], width(p["translation"]), budgets[p["id"]])
        for p in patches if width(p["translation"]) > budgets[p["id"]]]
if over:
    for pid, w, b in over:
        print("TOO LONG: %s width=%d budget=%d" % (pid, w, b))
    raise SystemExit("width overflow")

missing = [p["id"] for p in patches if p["id"] not in budgets]
if missing:
    raise SystemExit("no budget for: %r" % missing)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b059_ev3730.json", "w", encoding="utf-8"),
    ensure_ascii=False, indent=1,
)
print("patches:", len(patches))
print("width check: all OK")
