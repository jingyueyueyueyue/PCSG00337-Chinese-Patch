# -*- coding: utf-8 -*-
"""b007_ev0260 润色补丁构建脚本（自带宽度自检）。"""
import json
import unicodedata
import sys

TSV = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b007_ev0260.tsv"

patches = [
    # 恢复被预算压缩掉的「静かに」，现宽度 20/23
    {"id": "b007_ev0260_0007", "translation": r"闻言，大家静静点头。", "note": ""},
    # 词表：サードステージ=第三环节
    {"id": "b007_ev0260_0012", "translation": r"「樱花祭第三环节、『慈善义卖会』呢」"},
    # ２泊３日=三天两夜（原译两天三夜有误）
    {"id": "b007_ev0260_0037", "translation": r"「而这两项活动，将在入学后第一个周末进行的三天两夜住宿研修中实施」"},
    # 词表：ファーストステージ=第一环节
    {"id": "b007_ev0260_0046", "translation": r"「第一环节是『球技大会』」"},
    # 词表：ファイナルステージ=最终环节
    {"id": "b007_ev0260_0057", "translation": r"「接下来就是最后一项。在4月最后一天举行的、樱花祭最终环节『表演之夜』」"},
    # 词表：セカンドステージ=第二环节
    {"id": "b007_ev0260_0066", "translation": r"「接下来，第二环节『洗场任务』」"},
    # 雰囲気作り=气氛营造，补足「作り」
    {"id": "b007_ev0260_0074", "translation": r"「模拟店气氛营造不也很重要吗？」"},
    # 「打乱前辈说明的变成了我」语序生硬
    {"id": "b007_ev0260_0142", "translation": r"不知不觉，打断前辈说明的人变成了我。"},
    # 「打开爬完楼梯尽头」动宾堆叠，理顺
    {"id": "b007_ev0260_0147", "translation": r"而前辈爬完楼梯，打开尽头那扇门后——"},
    # 认错方向修正：是陆斗他们把森先生错认成学生
    {"id": "b007_ev0260_0197", "translation": r"「哎呀，我有点懂陆斗他们认错我的心情了」", "note": "指陆斗他们错认森先生为学生"},
    # 错字：内进→内在
    {"id": "b007_ev0260_0167", "translation": r"「请别看外表，看内在来判断！」"},
    # 「互相架势」生硬，改为双方对峙
    {"id": "b007_ev0260_0185", "translation": r"「各流派有不同的解释，无法一概而论……剑术修习的是从双方对峙的架势击败对手的技与型」"},
    # 词表：グッデーイ=古德拜
    {"id": "b007_ev0260_0253", "translation": r"「那么，淑女们……古德拜！」", "note": "按词表:グッデーイ=古德拜"},
    # 归属关系：丰川（站）在深城区内
    {"id": "b007_ev0260_0259", "translation": r"「横山同学也是深城区的丰川，大家真的都偏在这一侧啊」"},
    # 実家=老家
    {"id": "b007_ev0260_0316", "translation": r"「嗯？奈奈濑老家是寿司店？」"},
    # note 中的旧译名露克树改为词表统一的卢克树（译文本就正确）
    {"id": "b007_ev0260_0288", "translation": r"「不，没有……呃……是卢克树方向……」", "note": "新词:ルークツリー=卢克树（按词表统一）"},
    # 「还手帕」有歧义，改为归还
    {"id": "b007_ev0260_0331", "translation": r"（可是归还手帕的时候，不小心喊出了三谷同学）"},
    # それは……いや……为慌乱自我否定，原「那可不行」欠妥
    {"id": "b007_ev0260_0343", "translation": r"（不行不行……）"},
    # 「零星能看到」语序不顺
    {"id": "b007_ev0260_0357", "translation": r"如奉莉所说，甚至能零星看到空座。"},
    # 友達か 的感叹语气补足
    {"id": "b007_ev0260_0358", "translation": r"……朋友啊"},
    # 番線=站台（站台号，非线路号）
    {"id": "b007_ev0260_0362", "translation": r"「1号站台开往龙国、经秋日至厅舍前……列车即将发车，请注意关门」"},
    # 千尋の谷为习语（千丈深谷），原译「千寻谷」易误读为地名
    {"id": "b007_ev0260_0393", "translation": r"「当然，也有推下千丈深谷之类的做法，但我想尽力支持已经成了朋友的人」"},
]

# 自检 1：控制字符
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"] or "\r" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 自检 2：id 存在性 + 显示宽度 <= budget（全角=2 半角=1）
def width(s):
    return sum(2 if unicodedata.east_asian_width(ch) in ("W", "F", "A") else 1 for ch in s)

budgets = {}
for line in open(TSV, encoding="utf-8"):
    c = line.rstrip("\n").split("\t")
    if c[0] != "id":
        budgets[c[0]] = int(c[4])

errs = []
for p in patches:
    pid = p["id"]
    if pid not in budgets:
        errs.append("unknown id: %s" % pid)
        continue
    w = width(p["translation"])
    if w > budgets[pid]:
        errs.append("%s width %d > budget %d: %s" % (pid, w, budgets[pid], p["translation"]))
if errs:
    raise SystemExit("WIDTH/ID FAIL:\n" + "\n".join(errs))

out = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b007_ev0260.json"
json.dump({"batch": "b007_ev0260", "patches": patches}, open(out, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "-> all width/id checks passed")
