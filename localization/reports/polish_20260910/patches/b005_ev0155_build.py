# -*- coding: utf-8 -*-
"""b005_ev0155 润色补丁构建脚本（自带宽度自检）。

规则：全角字符=2、半角字符=1；译文显示宽度必须 ≤ 该行 budget。
note 仅在显式给出时替换；留空字符串 "" 表示清空原 note。
"""
import io
import json

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b005_ev0155.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b005_ev0155.json"


def w(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)


patches = [
    # ---- 称谓统一：良子さん→良子小姐、歩夢くん→步梦君 ----
    {"id": "b005_ev0155_0004",
     "translation": r"不过和良子小姐她们的话，感觉能好好磨合相处下去。"},
    {"id": "b005_ev0155_0005",
     "translation": r"不过不知是不是这个原因，面对良子小姐我反倒没什么先入之见。"},
    {"id": "b005_ev0155_0017",
     "translation": r"连良子都没当成母亲，却只把步梦君当弟弟，老实说做不到。"},
    {"id": "b005_ev0155_0018",
     "translation": r"良子小姐他们并不知道我的全部。"},
    {"id": "b005_ev0155_0019",
     "translation": r"良子小姐显然没想当我母亲的意思。"},
    {"id": "b005_ev0155_0032",
     "translation": r"加上步梦君和良子小姐，四人生活将从4月开始。"},
    {"id": "b005_ev0155_0034",
     "translation": r"不过这点上，良子小姐的印象也比想象中好得多。"},
    {"id": "b005_ev0155_0037",
     "translation": r"嘛，步梦君应该也没把我当成哥哥吧……"},
    {"id": "b005_ev0155_0054",
     "translation": r"『我想那时候，我和陆斗君一定想着同样的事。』"},
    {"id": "b005_ev0155_0096",
     "translation": r"「步梦君啊……名字挺像女孩呢」"},
    {"id": "b005_ev0155_0191",
     "translation": r"「三谷君好像到初三前都比奉莉矮来着？」"},
    # ---- 预算过紧、维持初翻，仅备注 ----
    {"id": "b005_ev0155_0021",
     "translation": r"「步梦……」",
     "note": "预算过紧：歩夢くん（步梦君）放不下"},
    {"id": "b005_ev0155_0057",
     "translation": r"『对，陆斗也……』",
     "note": "预算过紧：陸斗くん（陆斗君）放不下"},
    # ---- 误译修复 ----
    {"id": "b005_ev0155_0014",
     "translation": r"说没有不安是假的。"},
    {"id": "b005_ev0155_0080",
     "translation": r"「那……搬家的事，能问问吗？」"},
    {"id": "b005_ev0155_0082",
     "translation": r"「吓？」",
     "note": "预算8压缩（びっくり?）"},
    {"id": "b005_ev0155_0156",
     "translation": r"看完错觉艺术美术馆，我们回到了附设的购物中心。"},
    {"id": "b005_ev0155_0160",
     "translation": r"一发现我就消失不见，这点是肯定的……"},
    {"id": "b005_ev0155_0248",
     "translation": r"不过，女孩子接连离我而去确实是事实……"},
    {"id": "b005_ev0155_0316",
     "translation": r"只是有件要紧事没问成，这我知道。"},
    # ---- 润色 / 语气 / 标点 ----
    {"id": "b005_ev0155_0074",
     "translation": r"「……是啊，外表年轻得吓人」"},
    {"id": "b005_ev0155_0098",
     "translation": r"「陆斗！！早安！」"},
    {"id": "b005_ev0155_0099",
     "translation": r"「啊，但绝不是装嫩。确实比实际年龄年轻」"},
    {"id": "b005_ev0155_0193",
     "translation": r"「赞成——过了12点哪儿都该挤了」"},
    {"id": "b005_ev0155_0194",
     "translation": r"「同感……喂，陆斗眼角都笑弯了」"},
    {"id": "b005_ev0155_0266",
     "translation": "「……不是的" + "—" * 11 + "！！」"},
    {"id": "b005_ev0155_0271",
     "translation": r"「咋了？一脸呆住的表情哦？」"},
    {"id": "b005_ev0155_0299",
     "translation": r"「总之不是！」",
     "note": ""},
]

# ---- 自检 ----
budgets = {}
old_tr = {}
with io.open(BATCH, encoding="utf-8", newline="") as f:
    for ln in f.read().split("\n")[1:]:
        if not ln.strip():
            continue
        c = ln.split("\t")
        budgets[c[0]] = int(c[4])
        old_tr[c[0]] = c[6]

problems = []
for p in patches:
    pid = p["id"]
    t = p["translation"]
    if pid not in budgets:
        problems.append("%s: unknown id" % pid)
        continue
    if "\t" in t or "\n" in t or "\r" in t:
        problems.append("%s: control char" % pid)
        continue
    if t != old_tr[pid] and w(t) > budgets[pid]:
        problems.append("%s: width %d > budget %d" % (pid, w(t), budgets[pid]))
    n = p.get("note")
    if n is not None and ("\t" in n or "\n" in n):
        problems.append("%s: control char in note" % pid)

if problems:
    raise SystemExit("SELF-CHECK FAILED:\n" + "\n".join(problems))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
