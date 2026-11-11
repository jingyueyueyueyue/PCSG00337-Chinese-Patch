# -*- coding: utf-8 -*-
"""b023_ev1200 润色补丁构建脚本（自带控制字符与显示宽度自检）"""
import io
import json

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b023_ev1200.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b023_ev1200.json"


def width(s):
    return sum(1 if ord(c) < 0x80 else 2 for c in s)


budgets = {}
with io.open(BATCH, encoding="utf-8") as f:
    next(f)
    for line in f:
        parts = line.rstrip("\n").split("\t")
        if len(parts) >= 7 and parts[0]:
            budgets[parts[0]] = int(parts[4])

patches = [
    {"id": "b023_ev1200_0003", "translation": "章介早就说过想由自己主导洗场任务，想必他对此有自己的执念吧。"},
    {"id": "b023_ev1200_0011", "translation": "奉莉元气满满地走进了教室。"},
    {"id": "b023_ev1200_0021", "translation": "「主线任务是连续型谜语任务。要读懂谜面、辗转前往各个目的地，以抵达终点为目标」"},
    {"id": "b023_ev1200_0027", "translation": "「任务里有乍看难懂的谜面，也有『什么什么怎么做』这种直截了当的题目」"},
    {"id": "b023_ev1200_0038", "translation": "「洗场任务可是能让我尽情发挥实力的活动，要我别这么起劲是不可能的」"},
    {"id": "b023_ev1200_0042", "translation": "「我必定带领全班夺冠！就包在我横山章介身上！」"},
    {"id": "b023_ev1200_0058", "translation": "「没错，要来了，我的时刻！！」"},
    {"id": "b023_ev1200_0060", "translation": "「而且，在那些任务之外，还存在一个『主线任务』」"},
    {"id": "b023_ev1200_0087", "translation": "感觉自己在想什么都被看穿了。"},
    {"id": "b023_ev1200_0152", "translation": "章介一边复述，一边输入谜面。"},
    {"id": "b023_ev1200_0168", "translation": "「那就是『瀑布广场』吗？和谜面完全不吻合哦？」"},
    {"id": "b023_ev1200_0186", "translation": "「光与暗两股力量均衡之时……明与暗两股力量均衡之时……唔，没感觉……」"},
    {"id": "b023_ev1200_0195", "translation": "「久等了，那么读一下任务内容……嗯……从大地……解脱……」"},
    {"id": "b023_ev1200_0198", "translation": "「有对得上谜面的吗？」"},
    {"id": "b023_ev1200_0215", "translation": "「这是主线任务的下一句谜面吧？」"},
    {"id": "b023_ev1200_0222", "translation": "「也就是说谜面设计成让人一下子答不出来？」"},
    {"id": "b023_ev1200_0247", "translation": "其他时候就预定和章介一起解读谜面。"},
    {"id": "b023_ev1200_0265", "translation": "「谜面怎么解？」"},
    {"id": "b023_ev1200_0266", "translation": "「可是把人手分过去，谜面解读就吃紧了吧……？」"},
    {"id": "b023_ev1200_0278", "translation": "「三谷君、步梦小姐，加油」"},
    {"id": "b023_ev1200_0285", "translation": "「拜田的知识是解读谜面必需的……好，赶海任务交给陆斗和步梦两人」"},
    {"id": "b023_ev1200_0298", "translation": "「那个……任务18，从现在起1小时内在洗场海滨公园挖出10个蛤蜊……」"},
    {"id": "b023_ev1200_0303", "translation": "「这个关键词很好懂，很快就能解读。更重要的是这边的任务」"},
    {"id": "b023_ev1200_0316", "translation": "再减少教室的人数，可能就会妨碍谜面的解读……"},
    {"id": "b023_ev1200_0329", "translation": "所以事到如今，就算步梦说漏嘴几句怪话，我也绝不会觉得她怪。"},
    {"id": "b023_ev1200_0381", "translation": "朝步梦亮出手表。"},
    {"id": "b023_ev1200_0440", "translation": "「小心点，脚还麻着吧？」"},
    {"id": "b023_ev1200_0547", "translation": "步梦用力点头，再次拿起耙子挖起沙来。"},
    {"id": "b023_ev1200_0555", "translation": "反反复复的单调作业。"},
]

problems = []
for p in patches:
    t = p["translation"]
    if "\t" in t or "\n" in t:
        problems.append((p["id"], "control chars"))
        continue
    if p["id"] not in budgets:
        problems.append((p["id"], "id not found in batch"))
        continue
    w = width(t)
    if w > budgets[p["id"]]:
        problems.append((p["id"], "too long: %d > %d" % (w, budgets[p["id"]])))

if problems:
    raise SystemExit("patch problems: %r" % problems)

json.dump({"patches": patches}, io.open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
print("all width checks passed")
