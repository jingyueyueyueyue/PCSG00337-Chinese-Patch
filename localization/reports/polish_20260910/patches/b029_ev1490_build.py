# -*- coding: utf-8 -*-
import json
import unicodedata

def disp_width(s):
    w = 0
    for c in s:
        w += 2 if unicodedata.east_asian_width(c) in ("W", "F", "A") else 1
    return w

patches = [
    {"id": "b029_ev1490_0008", "translation": "对女孩步梦来说，身边最近的憧憬异性……"},
    {"id": "b029_ev1490_0025", "translation": "「总觉得你从刚才就在笑……」"},
    {"id": "b029_ev1490_0046", "translation": "听说因为要去办公寓的签约手续，今天店里交给了主厨。"},
    {"id": "b029_ev1490_0085", "translation": "「良子。玩笑开得太过分了吧? 步梦君很困扰」"},
    {"id": "b029_ev1490_0161", "translation": "「这就去!」"},
    {"id": "b029_ev1490_0178", "translation": "「嗯，谢谢。那我回料理室去啦」"},
    {"id": "b029_ev1490_0236", "translation": "「三谷妹，我来拿」"},
    {"id": "b029_ev1490_0240", "translation": "「声音太小啦! 再来一遍!」"},
    {"id": "b029_ev1490_0271", "translation": "「好的，哥哥」"},
    {"id": "b029_ev1490_0285", "translation": "「但是陆斗，你其实没觉得多困扰吧?」"},
    {"id": "b029_ev1490_0293", "translation": "「哪有什么遗憾……」"},
    {"id": "b029_ev1490_0305", "translation": "「嗯，真是这么想」"},
    {"id": "b029_ev1490_0313", "translation": "「陆斗的『妹妹』真勤快呢」"},
    {"id": "b029_ev1490_0327", "translation": "难道说奉莉一开始就知道步梦是女孩……?"},
    {"id": "b029_ev1490_0360", "translation": "「良子……这种事别跟孩子说」"},
    {"id": "b029_ev1490_0366", "translation": "「拜托冷静点陆斗君」"},
    {"id": "b029_ev1490_0374", "translation": "「不，不是的——」", "note": "预算所限：保留否认与截断语气，省称呼"},
    {"id": "b029_ev1490_0380", "translation": "「我明白。但我觉得该对陆斗君和盘托出……特别是钱的事……」"},
    {"id": "b029_ev1490_0383", "translation": "在这里生活下去……也就是要和步梦继续同屋……?", "note": "原译超宽，压缩措辞并补出「在这里」"},
]

budgets = {
    "b029_ev1490_0008": 38,
    "b029_ev1490_0025": 28,
    "b029_ev1490_0046": 53,
    "b029_ev1490_0085": 45,
    "b029_ev1490_0161": 11,
    "b029_ev1490_0178": 31,
    "b029_ev1490_0236": 19,
    "b029_ev1490_0240": 25,
    "b029_ev1490_0271": 14,
    "b029_ev1490_0285": 38,
    "b029_ev1490_0293": 20,
    "b029_ev1490_0305": 18,
    "b029_ev1490_0313": 27,
    "b029_ev1490_0327": 40,
    "b029_ev1490_0360": 30,
    "b029_ev1490_0366": 20,
    "b029_ev1490_0374": 18,
    "b029_ev1490_0380": 62,
    "b029_ev1490_0383": 53,
}

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

for p in patches:
    b = budgets.get(p["id"])
    if b is None:
        raise SystemExit("no budget for %s" % p["id"])
    w = disp_width(p["translation"])
    if w > b:
        raise SystemExit("too long: %s width=%d budget=%d" % (p["id"], w, b))

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b029_ev1490.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
