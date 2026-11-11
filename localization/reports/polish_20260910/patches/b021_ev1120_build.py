# -*- coding: utf-8 -*-
"""b021_ev1120 润色补丁构建：生成 JSON，并按批次 TSV 的 budget 做显示宽度自检。"""
import csv
import json
import os

ROOT = r"D:\VITA3K\ux0\app\PCSG00337"
BATCH = os.path.join(ROOT, "localization", "text", "work", "b021_ev1120.tsv")
OUT = os.path.join(ROOT, "localization", "reports", "polish_20260910", "patches", "b021_ev1120.json")

patches = [
    {"id": "b021_ev1120_0056", "translation": "只不过是把守门员的长传一碰，碰巧滚进了球门而已。"},
    {"id": "b021_ev1120_0097", "translation": "「这个嘛……我不太起眼……」"},
    {"id": "b021_ev1120_0121", "translation": "被误判动摇的两人反而丢了第二局，第三局章介看起来是体力不支了。"},
    {"id": "b021_ev1120_0126", "translation": "对方队伍里打过篮球的好像很多，我们陷入苦战。"},
    {"id": "b021_ev1120_0136", "translation": "「……信过你」"},
    {"id": "b021_ev1120_0141", "translation": "「这么说，就看我们了，说不定还不错？」"},
    {"id": "b021_ev1120_0157", "translation": "「怪章介君？」"},
    {"id": "b021_ev1120_0172", "translation": "「总、总算是前四……」"},
    {"id": "b021_ev1120_0176", "translation": "「不用道歉啦……话说你怎么过来了？你自己的比赛呢？」"},
    {"id": "b021_ev1120_0185", "translation": "「果然好难……」"},
    {"id": "b021_ev1120_0208", "translation": "可是练了之后，比赛虽然一开始失利，表现却渐渐变好……"},
    {"id": "b021_ev1120_0220", "translation": "用我教的脚内侧踢法把球传给奉莉。"},
    {"id": "b021_ev1120_0232", "translation": "一时冲动报了五人制足球，之后又担心得不行，怕打不好……"},
    {"id": "b021_ev1120_0254", "translation": "「咋回事？」"},
    {"id": "b021_ev1120_0259", "translation": "「传球……往门里传！」"},
    {"id": "b021_ev1120_0261", "translation": "「温泉、温泉……」"},
    {"id": "b021_ev1120_0283", "translation": "「嗯！」"},
    {"id": "b021_ev1120_0301", "translation": "「知道！」"},
    {"id": "b021_ev1120_0320", "translation": "如有神助地一记挥拳，击出了瞄向右上角的近距离射门。"},
    {"id": "b021_ev1120_0324", "translation": "步梦用力地抱住了我。"},
    {"id": "b021_ev1120_0344", "translation": "「三谷君，好厉害，真的……我……呜呜……」"},
    {"id": "b021_ev1120_0358", "translation": "「拜田同学，别哭啦」"},
    {"id": "b021_ev1120_0366", "translation": "平局收场就进点球大战。"},
]

# 控制字符自检
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)


def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)


# 预算自检：对照批次 TSV 的 budget 列
with open(BATCH, encoding="utf-8", newline="") as f:
    rows = {r["id"]: r for r in csv.DictReader(f, delimiter="\t")}

errors = []
for p in patches:
    r = rows.get(p["id"])
    if r is None:
        errors.append("%s: id not in batch" % p["id"])
        continue
    n = enc_len(p["translation"])
    b = int(r["budget"])
    if n > b:
        errors.append("%s: too_long %d>%d  %s" % (p["id"], n, b, p["translation"]))
    if "note" in p and ("\t" in p["note"] or "\n" in p["note"]):
        errors.append("%s: control char in note" % p["id"])
if errors:
    raise SystemExit("BUDGET/ID CHECK FAILED:\n" + "\n".join(errors))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "-> all within budget")
