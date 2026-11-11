# -*- coding: utf-8 -*-
import json

patches = [
    {"id": "b078_ev5070_0003", "translation": "第一局被跳发球折腾得输掉了，第二局总算扳了回来。"},
    {"id": "b078_ev5070_0005", "translation": "不过，真的感觉好悬……不对，不能看。"},
    {"id": "b078_ev5070_0016", "translation": "没能赶上，球滚落在我们的场地里，对方得分。"},
    {"id": "b078_ev5070_0018", "translation": "真央酱发力时漏出的声音，怎么说呢……"},
    {"id": "b078_ev5070_0019", "translation": "刚在规定位置站好，那个发跳发球的对手就走进了发球区。"},
    {"id": "b078_ev5070_0080", "translation": "「刚才不是故意的！！」"},
    {"id": "b078_ev5070_0081", "translation": "「冲啊啊！」"},
    {"id": "b078_ev5070_0120", "translation": "「明、明白……比起这个，能快点缠吗？对手也在等」"},
    {"id": "b078_ev5070_0142", "translation": "怎么说呢，事到如今……"},
    {"id": "b078_ev5070_0187", "translation": "「男生被看到裸体也会害羞」"},
    {"id": "b078_ev5070_0200", "translation": "「不，一个人不行的。多亏三谷兄给了契机才振作起来」"},
    {"id": "b078_ev5070_0239", "translation": "「好厉害，拜田同学」"},
    {"id": "b078_ev5070_0276", "translation": "不过仔细想想，这种事一开始就该由校方考虑吧……？"},
    {"id": "b078_ev5070_0298", "translation": "「还是说错了？」"},
    {"id": "b078_ev5070_0349", "translation": "「当然，不管怎样我都是女人，逃不掉。也有些事像泡澡一样没办法」"},
    {"id": "b078_ev5070_0362", "translation": "那果然还是女孩的微笑。"},
]

budgets = {
    "b078_ev5070_0003": 68,
    "b078_ev5070_0005": 42,
    "b078_ev5070_0016": 51,
    "b078_ev5070_0018": 37,
    "b078_ev5070_0019": 65,
    "b078_ev5070_0080": 24,
    "b078_ev5070_0081": 12,
    "b078_ev5070_0120": 50,
    "b078_ev5070_0142": 22,
    "b078_ev5070_0187": 27,
    "b078_ev5070_0200": 53,
    "b078_ev5070_0239": 23,
    "b078_ev5070_0276": 51,
    "b078_ev5070_0298": 18,
    "b078_ev5070_0349": 63,
    "b078_ev5070_0362": 25,
}

def width(s):
    return sum(2 if ord(c) > 0x7F else 1 for c in s)

bad = []
for p in patches:
    t = p["translation"]
    if "\t" in t or "\n" in t:
        bad.append((p["id"], "control chars"))
    b = budgets.get(p["id"])
    if b is not None and width(t) > b:
        bad.append((p["id"], "too long %d > %d" % (width(t), b)))
if bad:
    raise SystemExit("problems: %r" % bad)

json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b078_ev5070.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
