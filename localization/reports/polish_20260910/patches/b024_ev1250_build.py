# -*- coding: utf-8 -*-
"""b024_ev1250 润色补丁构建脚本（含显示宽度自检：全角=2、半角=1）。"""
import json

BUDGETS = {
    "b024_ev1250_0017": 14, "b024_ev1250_0022": 13, "b024_ev1250_0024": 28,
    "b024_ev1250_0027": 44, "b024_ev1250_0028": 36, "b024_ev1250_0040": 51,
    "b024_ev1250_0052": 18, "b024_ev1250_0061": 15, "b024_ev1250_0073": 84,
    "b024_ev1250_0074": 65, "b024_ev1250_0079": 27, "b024_ev1250_0094": 13,
    "b024_ev1250_0099": 13, "b024_ev1250_0121": 18, "b024_ev1250_0139": 43,
    "b024_ev1250_0162": 28, "b024_ev1250_0165": 20, "b024_ev1250_0186": 15,
    "b024_ev1250_0201": 33, "b024_ev1250_0209": 40, "b024_ev1250_0213": 28,
    "b024_ev1250_0216": 84, "b024_ev1250_0218": 49, "b024_ev1250_0240": 41,
    "b024_ev1250_0243": 35, "b024_ev1250_0250": 22, "b024_ev1250_0253": 67,
    "b024_ev1250_0254": 34, "b024_ev1250_0258": 36, "b024_ev1250_0282": 45,
    "b024_ev1250_0290": 20, "b024_ev1250_0295": 24, "b024_ev1250_0307": 44,
    "b024_ev1250_0312": 28, "b024_ev1250_0315": 55, "b024_ev1250_0333": 49,
    "b024_ev1250_0348": 38,
}


def width(s):
    return sum(1 if ord(c) < 0x80 else 2 for c in s)


patches = [
    {"id": "b024_ev1250_0017", "translation": r"「不，可是啊」"},
    {"id": "b024_ev1250_0022", "translation": r"「抱、抱歉」", "note": "省略……（预算）"},
    {"id": "b024_ev1250_0024", "translation": r"「所以我才说，我很少感冒嘛」"},
    {"id": "b024_ev1250_0027", "translation": r"「可是，横山君电话里明明交代过了……」"},
    {"id": "b024_ev1250_0028", "translation": r"「可是他那样在外待了1个多小时……」"},
    {"id": "b024_ev1250_0040", "translation": r"「不用担心，没事的。我平时很少感冒……对吧，奉莉」"},
    {"id": "b024_ev1250_0052", "translation": r"「陆斗，冷静！！」"},
    {"id": "b024_ev1250_0061", "translation": r"嗯，我也确认过"},
    {"id": "b024_ev1250_0073", "translation": r"「对了，谜面里写着暗示垃圾处理场的词，之前说过不以它为背景可能就无效来着」"},
    {"id": "b024_ev1250_0074", "translation": r"「对对，说那个任务横山君一个人就足够应付，没必要4个人都去……」"},
    {"id": "b024_ev1250_0079", "translation": r"「就因为这个……真的吗？」"},
    {"id": "b024_ev1250_0094", "translation": r"嗯？怎么了？"},
    {"id": "b024_ev1250_0099", "translation": r"笑眯眯的夏奏"},
    {"id": "b024_ev1250_0121", "translation": r"肉、蔬菜、海鲜……"},
    {"id": "b024_ev1250_0139", "translation": r"「那么，接下来30分钟左右请你们当篝火看守」", "note": "按词表:ファイヤーキーパー=篝火看守"},
    {"id": "b024_ev1250_0162", "translation": r"「下一班篝火看守是这两位？」"},
    {"id": "b024_ev1250_0165", "translation": r"「章介君合格了？」"},
    {"id": "b024_ev1250_0186", "translation": r"谢啦，三谷君"},
    {"id": "b024_ev1250_0201", "translation": r"「三谷陆斗和三谷步梦是……？」", "note": "预算过紧（称呼省略）"},
    {"id": "b024_ev1250_0209", "translation": r"「是、是啊……说谎的人，谁都讨厌……」"},
    {"id": "b024_ev1250_0213", "translation": r"「是啊，这样就不会感冒了」"},
    {"id": "b024_ev1250_0216", "translation": r"「每个班都得派2名篝火看守负责看火，但我完全忘了要定人选……啊哈哈」"},
    {"id": "b024_ev1250_0218", "translation": r"「快到篝火看守换班的时间了，能麻烦你们吗？」"},
    {"id": "b024_ev1250_0240", "translation": r"夏奏酱笑眯眯地轻轻挥了挥手，离开了这里。"},
    {"id": "b024_ev1250_0243", "translation": r"大家目送下，我和步梦跟上了负责人。"},
    {"id": "b024_ev1250_0250", "translation": r"早就完全超过半数了……"},
    {"id": "b024_ev1250_0253", "translation": r"接下来讨论菜单，委员方案也一样没遭什么反对，顺利通过。"},
    {"id": "b024_ev1250_0254", "translation": r"「31、32……三谷君，赞成32票」"},
    {"id": "b024_ev1250_0258", "translation": r"「提案确实有，但不是半开玩笑吗？」"},
    {"id": "b024_ev1250_0282", "translation": r"本想给步梦打气，反倒被她担心，感觉真是奇妙。"},
    {"id": "b024_ev1250_0290", "translation": r"「三谷君真活跃呢」"},
    {"id": "b024_ev1250_0295", "translation": r"「那个，三谷君辛苦了」"},
    {"id": "b024_ev1250_0307", "translation": r"「那个，3天2夜的住宿研修，大家真的辛苦了」"},
    {"id": "b024_ev1250_0312", "translation": r"「是啊，现在硬撑可能拖很久」"},
    {"id": "b024_ev1250_0315", "translation": r"「顺带一提，明天是周日补休放假。请大家好好休息」"},
    {"id": "b024_ev1250_0333", "translation": r"我开始脱下代替昨天那身脏透制服的体操服。"},
    {"id": "b024_ev1250_0348", "translation": r"「是、是错觉……那我也去换衣服咯？」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

over = [(p["id"], width(p["translation"]), BUDGETS.get(p["id"]))
        for p in patches
        if p["id"] in BUDGETS and width(p["translation"]) > BUDGETS[p["id"]]]
if over:
    for pid, w, b in over:
        print("too_long: %s width=%d budget=%d" % (pid, w, b))
    raise SystemExit("width check failed")

missing = [p["id"] for p in patches if p["id"] not in BUDGETS]
if missing:
    raise SystemExit("no budget recorded for: %r" % missing)

json.dump({"patches": patches}, open(
    r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b024_ev1250.json",
    "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "width check OK")
