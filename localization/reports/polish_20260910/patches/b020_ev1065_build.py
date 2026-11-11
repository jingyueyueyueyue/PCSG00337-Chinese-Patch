# -*- coding: utf-8 -*-
"""b020_ev1065 润色补丁构建脚本（含显示宽度自检）。"""
import json
import unicodedata

BUDGET = {
    "b020_ev1065_0035": 20,
    "b020_ev1065_0049": 65,
    "b020_ev1065_0085": 20,
    "b020_ev1065_0099": 65,
    "b020_ev1065_0132": 37,
    "b020_ev1065_0141": 27,
    "b020_ev1065_0157": 22,
    "b020_ev1065_0166": 23,
    "b020_ev1065_0170": 46,
    "b020_ev1065_0178": 49,
    "b020_ev1065_0179": 35,
    "b020_ev1065_0184": 8,
    "b020_ev1065_0195": 18,
    "b020_ev1065_0199": 57,
    "b020_ev1065_0218": 49,
    "b020_ev1065_0242": 14,
    "b020_ev1065_0263": 16,
    "b020_ev1065_0267": 52,
    "b020_ev1065_0299": 9,
    "b020_ev1065_0307": 8,
    "b020_ev1065_0326": 39,
    "b020_ev1065_0330": 34,
    "b020_ev1065_0334": 37,
    "b020_ev1065_0348": 77,
}


def width(s):
    w = 0
    for ch in s:
        ea = unicodedata.east_asian_width(ch)
        w += 2 if ea in ("W", "F", "A") else 1
    return w


patches = [
    {"id": "b020_ev1065_0035", "translation": "「早安，拜田同学」", "note": "预算过紧"},
    {"id": "b020_ev1065_0049", "translation": r"嘛，与其说是住宿研修，不如说樱花祭终于要开始了，当然也是当然……"},
    {"id": "b020_ev1065_0085", "translation": "「早安，拜田同学」", "note": "预算过紧"},
    {"id": "b020_ev1065_0099", "translation": r"嘛，与其说是住宿研修，不如说樱花祭终于要开始了，当然也是当然……"},
    {"id": "b020_ev1065_0132", "translation": "「……咦？完全不止一句话嘛，对不起」"},
    {"id": "b020_ev1065_0141", "translation": "「怎么了三谷兄，激动啥？」"},
    {"id": "b020_ev1065_0157", "translation": "「是挂变态的绅士吧？」"},
    {"id": "b020_ev1065_0166", "translation": "「没有，只有我们而已」"},
    {"id": "b020_ev1065_0170", "translation": "「我的探求心……我的求知欲……怎么会这样……」"},
    {"id": "b020_ev1065_0178", "translation": "「这种探求心，还是努力用正攻法来满足比较好吧？」"},
    {"id": "b020_ev1065_0179", "translation": "「是啊……让章介当罪犯也太不忍心」"},
    {"id": "b020_ev1065_0184", "translation": "「啊?」", "note": "预算过紧"},
    {"id": "b020_ev1065_0195", "translation": "立刻朝他们走去。"},
    {"id": "b020_ev1065_0199", "translation": r"但要是当女孩子对待，真央酱肯定反感，分寸不好拿捏……"},
    {"id": "b020_ev1065_0218", "translation": r"我觉得只要消除紧张肯定能正常发挥……好担心啊……"},
    {"id": "b020_ev1065_0242", "translation": "「呜——喵!!」"},
    {"id": "b020_ev1065_0263", "translation": r"之后比赛继续……"},
    {"id": "b020_ev1065_0267", "translation": "正想着这些，抛硬币已结束，奉莉和步梦的比赛开始。"},
    {"id": "b020_ev1065_0299", "translation": "「喔噢!」"},
    {"id": "b020_ev1065_0307", "translation": "「啥!?」"},
    {"id": "b020_ev1065_0326", "translation": "「4班对8班，4比0，8班胜……礼」"},
    {"id": "b020_ev1065_0330", "translation": "「但像刚才最后那样踢进就绝对……」"},
    {"id": "b020_ev1065_0334", "translation": "「夏奏酱，关于真央酱的事想找您商量」"},
    {"id": "b020_ev1065_0348", "translation": "奉莉她们在走廊练习时我看了对手的比赛，好像有不少人踢过足球"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

over = []
for p in patches:
    w = width(p["translation"])
    limit = BUDGET[p["id"]]
    if w > limit:
        over.append("%s width=%d budget=%d" % (p["id"], w, limit))
if over:
    raise SystemExit("too_long:\n" + "\n".join(over))

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b020_ev1065.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
