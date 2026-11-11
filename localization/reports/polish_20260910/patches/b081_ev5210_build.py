# -*- coding: utf-8 -*-
"""b081_ev5210 润色补丁构建（含宽度自检）。"""
import json
import sys
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b081_ev5210.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b081_ev5210.json")

patches = [
    {"id": "b081_ev5210_0016", "translation": "「不想回去？」", "note": "戻る指变回女儿身；预算紧省略……"},
    {"id": "b081_ev5210_0017", "translation": "「……唔，感觉像段位最高一级？」"},
    {"id": "b081_ev5210_0019", "translation": "「还是我多事？」"},
    {"id": "b081_ev5210_0025", "translation": "「不、不是不行啦……」"},
    {"id": "b081_ev5210_0032", "translation": "「当然」", "note": ""},
    {"id": "b081_ev5210_0044", "translation": "「始祖自传里写，那人直到得到免许皆传都一直男装，以男人身份生活」"},
    {"id": "b081_ev5210_0051", "translation": "「等、等一下……嘿咻……好，搞定」"},
    {"id": "b081_ev5210_0052", "translation": "「贴、贴太近了吧……？」"},
    {"id": "b081_ev5210_0058", "translation": "「总算进来了」", "note": "预算紧省略……"},
    {"id": "b081_ev5210_0067", "translation": "夜里学校那么可怕……"},
    {"id": "b081_ev5210_0072", "translation": "怎么说……"},
    {"id": "b081_ev5210_0074", "translation": "又拼命忍住快要打出的哈欠。"},
    {"id": "b081_ev5210_0080", "translation": "「那，这个怎么办？」"},
    {"id": "b081_ev5210_0081", "translation": "「10点左右不就行了？」"},
    {"id": "b081_ev5210_0088", "translation": "不行吗", "note": "预算紧省略「」"},
    {"id": "b081_ev5210_0090", "translation": "「后半场同样努力的话，绝对能拿总分第一」"},
    {"id": "b081_ev5210_0097", "translation": "「不，我很欢迎，但不会累吗？」"},
    {"id": "b081_ev5210_0122", "translation": "住宿研修回来，3天来头一次在家吃饭。"},
    {"id": "b081_ev5210_0127", "translation": "「别、别提我了！比起这个，是哥哥和真央酱啦！之后的洗场任务也很厉害呢！」"},
    {"id": "b081_ev5210_0128", "translation": "「累过头，发烧了？」"},
    {"id": "b081_ev5210_0136", "translation": "「啊、啊啊，那孩子……她不是女孩吗……？」"},
    {"id": "b081_ev5210_0137", "translation": "「啊，ｅｅｎ×ｖｉｊｆ我也去过一次，你不记得了？」"},
    {"id": "b081_ev5210_0139", "translation": "「嗯，没错，但不知为何在学校以男生身份上学」"},
    {"id": "b081_ev5210_0164", "translation": "「章介，抱歉」"},
    {"id": "b081_ev5210_0168", "translation": "「……真央酱怎么了？」"},
    {"id": "b081_ev5210_0176", "translation": "「室内乐园、错觉艺术美术馆、还有洗场二丁目商店街……」"},
    {"id": "b081_ev5210_0177", "translation": "「我和奉莉前阵子去过，正如步梦说的，玩几次都不腻」"},
    {"id": "b081_ev5210_0182", "translation": "「洗场怪谈学校……好像很可怕」"},
    {"id": "b081_ev5210_0183", "translation": "「没事没事，大家绝对会开心」"},
    {"id": "b081_ev5210_0186", "translation": "「洗场怪谈『学校』啊……」"},
    {"id": "b081_ev5210_0189", "translation": "「拜田酱和章介也没问题吧？」"},
    {"id": "b081_ev5210_0204", "translation": "「欸？啊抱歉，给忘了」"},
    {"id": "b081_ev5210_0210", "translation": "「早。今天天晴真好」"},
    {"id": "b081_ev5210_0211", "translation": "「早，陆斗步梦」"},
    {"id": "b081_ev5210_0230", "translation": "「奉、奉莉酱……这比玩笑还扎心」"},
    {"id": "b081_ev5210_0262", "translation": "「……是啊」"},
    {"id": "b081_ev5210_0275", "translation": "「老爷子没有阻止，只让真央酱遵守约定」"},
    {"id": "b081_ev5210_0294", "translation": "「来帮忙」", "note": "预算紧省略称呼陆斗"},
    {"id": "b081_ev5210_0297", "translation": "「没事，女孩手作便当，就算是杯面也高兴」"},
    {"id": "b081_ev5210_0328", "translation": "「是啊……那……传说就此开幕……」"},
    {"id": "b081_ev5210_0334", "translation": "「这我也不清楚……但如果今天的事对真央酱没好处，作为师父他绝对会阻止」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]
       or "\t" in p.get("note", "") or "\n" in p.get("note", "")]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：对照批次 TSV 的 budget（全角=2、半角=1）
budgets = {}
with open(BATCH, encoding="utf-8") as f:
    header = f.readline().rstrip("\n").split("\t")
    for line in f:
        cols = line.rstrip("\n").split("\t")
        if len(cols) >= 5:
            budgets[cols[0]] = int(cols[4])

over = []
for p in patches:
    n = sum(1 if ord(c) < 128 else 2 for c in p["translation"])
    b = budgets.get(p["id"])
    if b is None:
        raise SystemExit("unknown id in batch: %s" % p["id"])
    if n > b:
        over.append("%s %d>%d %s" % (p["id"], n, b, p["translation"]))
if over:
    print("WIDTH OVERFLOW:")
    for o in over:
        print("  " + o)
    sys.exit(1)

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "->", OUT)
