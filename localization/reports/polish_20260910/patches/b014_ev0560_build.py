# -*- coding: utf-8 -*-
# b014_ev0560 润色补丁：词表统一（Xくん→X君、歩夢さん→步梦小姐、八幡様去"大人"）、
# 误译/漏译修正、语气与通顺度打磨。全部逐行核对宽度（全角=2 半角=1）。
import io

def w(s):
    return sum(2 if ord(c) > 0x7F else 1 for c in s)

patches = [
    {"id": "b014_ev0560_0006", "translation": r"确实，拜托说明的部分都讲过了……"},
    {"id": "b014_ev0560_0014", "translation": r"「……果然还是不行？有老师在就太拘束了」"},
    {"id": "b014_ev0560_0017", "translation": r"「那么，『洗场任务』就交给横山君负责……下一个！」"},
    {"id": "b014_ev0560_0019", "translation": r"「茂森君就先这样，进入正题吧！」"},
    {"id": "b014_ev0560_0022", "translation": r"「那么，顺便当作复习，能请大家说明一下樱花祭各项活动分别该开怎样的筹备会吗？」"},
    {"id": "b014_ev0560_0030", "translation": r"「怎、怎么突然这么大声……？」"},
    {"id": "b014_ev0560_0040", "translation": r"「横山君，不多想会更幸福哦」"},
    {"id": "b014_ev0560_0046", "translation": r"「确实，到第三环节为止是不是第一，在搏一把还是求稳的判断上也会不一样……」"},
    {"id": "b014_ev0560_0048", "translation": r"「完全……不对，能早回去的话更该排练吧？」"},
    {"id": "b014_ev0560_0055", "translation": r"「光听刚才那些，确实不会太想做呢」"},
    {"id": "b014_ev0560_0068", "translation": r"「听说这是进朝冈后头一个惩罚游戏」"},
    {"id": "b014_ev0560_0083", "translation": r"「哎呀，很懂嘛横山君」"},
    {"id": "b014_ev0560_0095", "translation": r"「那个……茂森君愿意接下活动执行委员一职，这样理解没问题吧？」"},
    {"id": "b014_ev0560_0096", "translation": r"「那个，要去三谷君爸爸店里吗？」"},
    {"id": "b014_ev0560_0109", "translation": r"「是呢，能在器材租借开始受理的住宿研修最后一天定下，行动方便些」"},
    {"id": "b014_ev0560_0127", "translation": r"「哇，横山君真博学呢」"},
    {"id": "b014_ev0560_0138", "translation": r"「说着，横山君已经操作起了手机。」"},
    {"id": "b014_ev0560_0165", "translation": r"得知哭因，稍放心了。"},
    {"id": "b014_ev0560_0169", "translation": r"「虽被『算了』带过……但被叫了章介，也算值了」"},
    {"id": "b014_ev0560_0173", "translation": r"「那……比如横山君想被怎么称呼？」"},
    {"id": "b014_ev0560_0191", "translation": r"「怎、怎么哭了？」"},
    {"id": "b014_ev0560_0205", "translation": r"「三谷君他爸爸……」"},
    {"id": "b014_ev0560_0206", "translation": r"「我……用『三谷君』和『步梦小姐』？」"},
    {"id": "b014_ev0560_0240", "translation": r"「直接叫我『奉莉』就好。后面加不加『同学』『酱』都随意」"},
    {"id": "b014_ev0560_0255", "translation": r"「不，身为武道中人，可不能从武神八幡面前过而不入」"},
    {"id": "b014_ev0560_0258", "translation": r"「欢迎光临！陆斗君你好」"},
    {"id": "b014_ev0560_0266", "translation": r"「呃、呃……今天是良辰吉日……那个……呃……那个……」"},
    {"id": "b014_ev0560_0269", "translation": r"诶？哪里哪里", "note": "预算13容不下「」，省略引号"},
    {"id": "b014_ev0560_0283", "translation": r"好、好可爱……", "note": "预算15容不下「」，省略引号"},
    {"id": "b014_ev0560_0328", "translation": r"「呼呼……不行，嘴角要压不住了……」"},
    {"id": "b014_ev0560_0329", "translation": r"「呵呵，绝对没有，哥哥你也一样」"},
    {"id": "b014_ev0560_0331", "translation": r"「难得你会坚持……也就是说，你不想被用名字来称呼啊……」"},
    {"id": "b014_ev0560_0340", "translation": r"「哇，好多人呀。请稍等……老板，陆斗君来啦！」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：读批次文件取 budget 对照
budgets = {}
with io.open(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b014_ev0560.tsv", encoding="utf-8") as f:
    next(f)
    for line in f:
        cols = line.rstrip("\n").split("\t")
        budgets[cols[0]] = int(cols[4])

over = []
for p in patches:
    limit = budgets[p["id"]]
    width = w(p["translation"])
    if width > limit:
        over.append((p["id"], width, limit))
if over:
    raise SystemExit("too_long: %r" % over)

import json
json.dump({"patches": patches},
          open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b014_ev0560.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("patches:", len(patches), "| all within budget")
