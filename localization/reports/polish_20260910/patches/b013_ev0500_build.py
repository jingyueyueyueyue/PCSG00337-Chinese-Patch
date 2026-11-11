# -*- coding: utf-8 -*-
"""b013_ev0500 润色补丁构建（带显示宽度自检）"""
import csv
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b013_ev0500.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b013_ev0500.json")

patches = [
    {"id": "b013_ev0500_0009", "translation": "（刚听说时有点不敢相信，不过陆斗好像真的相信步梦是他弟弟）"},
    {"id": "b013_ev0500_0011", "translation": "（入学说明会上认识的拜田同学和横山君）"},
    {"id": "b013_ev0500_0012", "translation": "（茂森同学虽然很遗憾，但同班的变成了陆斗的弟弟『步梦君』）"},
    {"id": "b013_ev0500_0013", "translation": "（陆斗也和我同班了呢……）"},
    {"id": "b013_ev0500_0015", "translation": "（我盟友陆斗的话……）"},
    {"id": "b013_ev0500_0020", "translation": "「……才怪，其实是妹妹」"},
    {"id": "b013_ev0500_0053", "translation": "「好——慢走」"},
    {"id": "b013_ev0500_0081", "translation": "也在给人添麻烦，想把手放下来，可能不太行……"},
    {"id": "b013_ev0500_0082", "translation": "阴差阳错，我和步梦摆出了紧紧相拥的姿势……"},
    {"id": "b013_ev0500_0083", "translation": "既然坐电车上学，满员电车早有心理准备……可这才第二天啊……"},
    {"id": "b013_ev0500_0094", "translation": "「2号站台开往左之丘，经柴门、八本木……电车即将发车，请小心车门」"},
    {"id": "b013_ev0500_0095", "translation": "「那，下定决心上车吧」"},
    {"id": "b013_ev0500_0098", "translation": "「真的啦。再说了，这种话题本身，在步梦面前说就很失礼吧」"},
    {"id": "b013_ev0500_0170", "translation": "茂森同学与我对视，轻轻一笑。"},
    {"id": "b013_ev0500_0175", "translation": "绝对算不上大，但也不是错觉能解释的量……"},
    {"id": "b013_ev0500_0177", "translation": "一头雾水的森老师直盯着茂森同学的胸。"},
    {"id": "b013_ev0500_0180", "translation": "女生B"},
    {"id": "b013_ev0500_0181", "translation": "回头一看，横山君摆出绅士（？）姿势。"},
    {"id": "b013_ev0500_0185", "translation": "其他同学也纷纷落座，我看向昨天缺席的茂森君的座位……"},
    {"id": "b013_ev0500_0191", "translation": "「……莫非茂森君是女孩？」"},
    {"id": "b013_ev0500_0194", "translation": "「可她是女孩子吧……却是男学生……」"},
    {"id": "b013_ev0500_0202", "translation": "「介绍一下昨天缺席的同学。我是茂森正博哟！」"},
    {"id": "b013_ev0500_0204", "translation": "「三谷君？」", "note": "预算所限省「……」"},
    {"id": "b013_ev0500_0230", "translation": "「横山君早」", "note": ""},
    {"id": "b013_ev0500_0235", "translation": "「总之，人好像不在教室里……」"},
    {"id": "b013_ev0500_0240", "translation": "「好啦，都当上委员了，就好好相处嘛」"},
    {"id": "b013_ev0500_0257", "translation": "女生C"},
    {"id": "b013_ev0500_0258", "translation": "女生D"},
    {"id": "b013_ev0500_0260", "translation": "男生D"},
    {"id": "b013_ev0500_0304", "translation": "从大家的对话中，大致听出了茂森同学男装的理由……"},
    {"id": "b013_ev0500_0311", "translation": "横山君一边纳闷地歪着头，一边猛吃了起来。"},
    {"id": "b013_ev0500_0320", "translation": "奉莉轻挥了挥手，带着横山君和拜田同学去食堂买餐券。"},
    {"id": "b013_ev0500_0335", "translation": "「明白了，不嫌弃我这种人，就让我同行」", "note": "预算所限省「……」"},
    {"id": "b013_ev0500_0382", "translation": "「利润可一分都没算进去哦。真开店这价格撑不住」"},
    {"id": "b013_ev0500_0403", "translation": "「不奇怪啦……啊——朝冈午餐真好吃」"},
    {"id": "b013_ev0500_0435", "translation": "「是、对不起……」"},
    {"id": "b013_ev0500_0439", "translation": "「好，我会加油！」"},
    {"id": "b013_ev0500_0458", "translation": "和不知何时凑来的横山君简短聊完，视线转向真正最后一件之人的座位——"},
]


def width(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)


budgets = {}
with open(BATCH, encoding="utf-8") as f:
    for row in csv.reader(f, delimiter="\t", quoting=csv.QUOTE_NONE):
        if row and row[0].startswith("b013_ev0500_"):
            budgets[row[0]] = int(row[4])

bad = []
for p in patches:
    t = p["translation"]
    pid = p["id"]
    if "\t" in t or "\n" in t or "\r" in t:
        bad.append((pid, "control char"))
        continue
    if pid not in budgets:
        bad.append((pid, "unknown id"))
        continue
    w = width(t)
    if w > budgets[pid]:
        bad.append((pid, "too long: %d > %d" % (w, budgets[pid])))

if bad:
    for b in bad:
        print("BAD:", b)
    raise SystemExit("width/control check failed")

OUT.parent.mkdir(parents=True, exist_ok=True)
with open(OUT, "w", encoding="utf-8") as f:
    json.dump({"patches": patches}, f, ensure_ascii=False, indent=1)
print("patches:", len(patches))
