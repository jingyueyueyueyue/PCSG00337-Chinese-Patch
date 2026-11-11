# -*- coding: utf-8 -*-
"""b061_ev4020 润色补丁构建脚本（2026-09-10 校对批次），自带宽度自检"""
import csv
import json

enc = lambda s: sum(1 if ord(c) < 128 else 2 for c in s)

patches = [
    {"id": "b061_ev4020_0003", "translation": "与伙伴们击掌欢呼的对手形成鲜明对比，拜田同学却颓然垂下了肩膀。"},
    {"id": "b061_ev4020_0039", "translation": "「别在意别在意！反正还差一分就赢，这点没变！拜田同学加油——！」"},
    {"id": "b061_ev4020_0055", "translation": "「我陪你，哥哥」"},
    {"id": "b061_ev4020_0077", "translation": "「这么说，8班女生乒乓最高就是拜田同学的八强」"},
    {"id": "b061_ev4020_0137", "translation": "「这样啊，足球就差一步……乒乓球呢？」", "note": "预算紧，フットサル缩略为足球"},
    {"id": "b061_ev4020_0151", "translation": "对拜田同学这种内向怯懦的孩子来说，真央酱显得格外耀眼啊。"},
    {"id": "b061_ev4020_0180", "translation": "章介移开视线不看拜田同学，难得地语塞了。"},
    {"id": "b061_ev4020_0206", "translation": "悄悄观察邻座的拜田同学……"},
    {"id": "b061_ev4020_0216", "translation": "除冠军队外，所有班级聚在一起，热热闹闹地把自助餐填进肚子。"},
    {"id": "b061_ev4020_0222", "translation": "「可缠着束胸穿男泳衣，本来就不让进吧？」"},
    {"id": "b061_ev4020_0239", "translation": "「嗯。不用那么担心我的……」"},
    {"id": "b061_ev4020_0244", "translation": "说着，拜田同学朝着放有饭菜的桌子走去。"},
    {"id": "b061_ev4020_0274", "translation": "平静下来之前，先去外面转转……"},
    {"id": "b061_ev4020_0292", "translation": "「不过，学了才知道吧？」"},
    {"id": "b061_ev4020_0310", "translation": "「北斗七星延长线的正前方就是大角星。沿着延长线继续下去，能到达室女座的角宿一。这就是『春季大曲线』」"},
    {"id": "b061_ev4020_0311", "translation": "「枕头大战吗……」"},
    {"id": "b061_ev4020_0336", "translation": "「这样啊……矶野绫子的『天使之泪』如何？」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

budget = {}
with open(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b061_ev4020.tsv", encoding="utf-8") as f:
    for row in csv.DictReader(f, delimiter="\t"):
        budget[row["id"]] = int(row["budget"])

over = [(p["id"], enc(p["translation"]), budget.get(p["id"])) for p in patches
        if p["id"] not in budget or enc(p["translation"]) > budget[p["id"]]]
if over:
    raise SystemExit("over budget or unknown id: %r" % over)

json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b061_ev4020.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all within budget")
