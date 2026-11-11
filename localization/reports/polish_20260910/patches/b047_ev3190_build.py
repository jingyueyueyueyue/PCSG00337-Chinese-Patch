# -*- coding: utf-8 -*-
"""b047_ev3190 润色补丁构建脚本（含显示宽度自检）。"""
import json
import sys
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b047_ev3190.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b047_ev3190.json")

patches = [
    {"id": "b047_ev3190_0014", "translation": "「1年8班，获得210分，是第3名！」"},
    {"id": "b047_ev3190_0015", "translation": "「这可不是随便能做到的，三谷兄真的很重视伙伴」"},
    {"id": "b047_ev3190_0018", "translation": "「我扭到脚的话也拜托你」"},
    {"id": "b047_ev3190_0042", "translation": "「只是可惜，冠军没戏了吧」"},
    {"id": "b047_ev3190_0059", "translation": "「可是，为什么敢断言那么遥远的未来……？」"},
    {"id": "b047_ev3190_0060", "translation": "「不过，看起来那样，是因为篝火的火光吧……？」"},
    {"id": "b047_ev3190_0073", "translation": "「……可奉莉到时还没结婚……？」"},
    {"id": "b047_ev3190_0086", "translation": "「再说，聊孩子还早，连有没有人愿意跟我结婚都不知道……」"},
    {"id": "b047_ev3190_0087", "translation": "「所以……到现在想法没变吗？」"},
    {"id": "b047_ev3190_0099", "translation": "「魔芋丝反正不会有吧……」"},
    {"id": "b047_ev3190_0103", "translation": "「在吃呢」"},
    {"id": "b047_ev3190_0106", "translation": "「不是火锅大王是烧烤奉行吗……」"},
    {"id": "b047_ev3190_0108", "translation": "「都说要保证了，没办法，我负责哦」"},
    {"id": "b047_ev3190_0187", "translation": "住宿研修第二天的晚上，和昨天一样，在被查寝老师提醒几次后大家也自然入睡了。"},
    {"id": "b047_ev3190_0198", "translation": "而且我知道，这话还有后续……"},
    {"id": "b047_ev3190_0199", "translation": "是因为今天的事？"},
    {"id": "b047_ev3190_0200", "translation": "大概是因为从没想过和奉莉交往吧……"},
    {"id": "b047_ev3190_0202", "translation": "也就是说，到那岁数前两人不可能交往。"},
    {"id": "b047_ev3190_0203", "translation": "难道说，现在的我其实有想和奉莉交往的心情？"},
    {"id": "b047_ev3190_0209", "translation": "住宿研修最终日——"},
    {"id": "b047_ev3190_0220", "translation": "「怎么了？眼睛有点红吧？没睡好？」"},
    {"id": "b047_ev3190_0233", "translation": "「是没错啦……！」"},
    {"id": "b047_ev3190_0256", "translation": "步梦小姐也辛苦了", "note": "预算紧省略「」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：对照批次 TSV 的 budget 列（全角=2、半角=1）
def width(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)

budgets = {}
for line in BATCH.read_text(encoding="utf-8").splitlines()[1:]:
    f = line.split("\t")
    if len(f) >= 5:
        budgets[f[0]] = int(f[4])

over = []
for p in patches:
    b = budgets.get(p["id"])
    if b is None:
        over.append("%s: id not in batch" % p["id"])
        continue
    w = width(p["translation"])
    if w > b:
        over.append("%s: width %d > budget %d" % (p["id"], w, b))
if over:
    raise SystemExit("width check failed:\n" + "\n".join(over))

OUT.write_text(json.dumps({"patches": patches}, ensure_ascii=False, indent=1), encoding="utf-8")
print("patches:", len(patches))
