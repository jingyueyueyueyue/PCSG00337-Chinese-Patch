# -*- coding: utf-8 -*-
"""b006_ev0210 润色补丁构建脚本（含显示宽度自检）"""
import json


def w(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)


patches = [
    # --- 译文修改 ---
    {"id": "b006_ev0210_0006", "budget": 20,
     "translation": "「……怎么不说话？」"},
    {"id": "b006_ev0210_0008", "budget": 39,
     "translation": "「你觉得那家伙跟我告白，才会尴尬？」"},
    {"id": "b006_ev0210_0017", "budget": 32,
     "translation": "「首先，这种展开怎么可能交往」"},
    {"id": "b006_ev0210_0018", "budget": 68,
     "translation": "「对吧。考虑到他想在初中最后做个了断的心情，我可不能随便敷衍了事」"},
    {"id": "b006_ev0210_0024", "budget": 47,
     "translation": "「不止我一个人。坐这趟缆车的所有人都这么想」"},
    {"id": "b006_ev0210_0026", "budget": 59,
     "translation": "「要说见过……我正要坐摩天轮时，正好看见她下来了」"},
    {"id": "b006_ev0210_0029", "budget": 16,
     "translation": "「我才不可怜呢」"},
    {"id": "b006_ev0210_0060", "budget": 16,
     "translation": "「话是没错……」"},
    {"id": "b006_ev0210_0087", "budget": 55,
     "translation": "「那，听陆斗劝的话……步梦肯定会趁你睡着下手吧？」"},
    {"id": "b006_ev0210_0105", "budget": 20,
     "translation": "「陆斗君？我是良子」"},
    {"id": "b006_ev0210_0106", "budget": 22,
     "translation": "「良子小姐，早上好」"},
    {"id": "b006_ev0210_0125", "budget": 25,
     "translation": "「对。去偷袭睡着的步梦」"},
    {"id": "b006_ev0210_0142", "budget": 79,
     "translation": "「不过入学式肯定能见到，就把这当成多了想象步梦是什么人的时间，不也挺好吗？」"},
    {"id": "b006_ev0210_0218", "budget": 14,
     "translation": "「当然了！！」"},
    {"id": "b006_ev0210_0246", "budget": 18,
     "translation": "「来，淑女，走吧」"},
    {"id": "b006_ev0210_0256", "budget": 23,
     "translation": "「那位绅士，帮个忙？」"},
    {"id": "b006_ev0210_0264", "budget": 20,
     "translation": "「是、是……明白了」"},
    {"id": "b006_ev0210_0306", "budget": 12,
     "translation": "视线汇聚——"},
    {"id": "b006_ev0210_0311", "budget": 38,
     "translation": "目光长远……从老师嘴里说出来好吗？"},
    {"id": "b006_ev0210_0344", "budget": 34,
     "translation": "「森、森老师！您在学生席干嘛？」"},
    {"id": "b006_ev0210_0359", "budget": 40,
     "translation": "自顾自定好规则后，奉莉开始了自我介绍。"},
    {"id": "b006_ev0210_0382", "budget": 50,
     "translation": "没什么好犹豫的，就按横山君说的排进中间——"},
    {"id": "b006_ev0210_0393", "budget": 23,
     "translation": "旁边一列传来惊讶声。"},
    {"id": "b006_ev0210_0400", "budget": 28,
     "translation": "「Mi、ta、ni……真是啊」"},
    {"id": "b006_ev0210_0421", "budget": 18,
     "translation": "「横山章介，绅士」"},
    {"id": "b006_ev0210_0440", "budget": 35,
     "translation": "「非常感谢您，三谷君……诶！？」"},
    {"id": "b006_ev0210_0529", "budget": 63,
     "translation": "「嘛，绅士不会为这点小事生气……三谷君的女友说话可真直率」"},
    # --- 仅补 note（译文原样保留，说明预算过紧放弃润色） ---
    {"id": "b006_ev0210_0001", "budget": 23,
     "translation": "和奉莉两人的归途——", "note": "预算过紧"},
    {"id": "b006_ev0210_0043", "budget": 16,
     "translation": "「呃……奉莉？」", "note": "预算过紧"},
    {"id": "b006_ev0210_0133", "budget": 25,
     "translation": "「等!? 那、那也太……」", "note": "预算过紧"},
    {"id": "b006_ev0210_0184", "budget": 12,
     "translation": "「……咋办」", "note": "预算过紧"},
    {"id": "b006_ev0210_0249", "budget": 16,
     "translation": "「去保健室……」", "note": "预算过紧"},
    {"id": "b006_ev0210_0436", "budget": 8,
     "translation": "「累了」", "note": "预算过紧"},
    {"id": "b006_ev0210_0534", "budget": 19,
     "translation": "「哟，好久不见」", "note": "预算过紧"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

over = [(p["id"], w(p["translation"]), p["budget"]) for p in patches if w(p["translation"]) > p["budget"]]
if over:
    for pid, width, budget in over:
        print("TOO LONG: %s width=%d budget=%d" % (pid, width, budget))
    raise SystemExit("width over budget")

out = {"patches": [{k: v for k, v in p.items() if k != "budget"} for p in patches]}
json.dump(out, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b006_ev0210.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), " all within budget")
