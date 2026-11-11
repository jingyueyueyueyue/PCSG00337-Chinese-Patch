# -*- coding: utf-8 -*-
"""b070_ev4390 润色补丁构建脚本（含显示宽度自检）。"""
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b070_ev4390.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b070_ev4390.json")

patches = [
    {"id": "b070_ev4390_0016", "translation": "正要和身旁走来的人在同一个检票口刷IC卡，想让对方先过……"},
    {"id": "b070_ev4390_0022", "translation": "我用粉笔在黑板上写下『PP』。"},
    {"id": "b070_ev4390_0062", "translation": "观察了一下反应，同学们并没有发出反对的声音。"},
    {"id": "b070_ev4390_0077", "translation": "……那本书，能留在三谷君这里吗？"},
    {"id": "b070_ev4390_0138", "translation": "坐同一班电车不算稀奇，但竟会想在同一时机和陆斗过同一个检票口"},
    {"id": "b070_ev4390_0152", "translation": "啊，不过太长、内容又差的话，评价会下降，要注意哦"},
    {"id": "b070_ev4390_0179", "translation": "嗯，最根本的企划也是拜田酱提出的"},
    {"id": "b070_ev4390_0184", "translation": "是、是的……是呢……"},
    {"id": "b070_ev4390_0186", "translation": "诶、那个……让我来写剧本，真的可以吗……？"},
    {"id": "b070_ev4390_0190", "translation": "是的……出于提案者的责任，我本想剧本无论如何要自己想办法……"},
    {"id": "b070_ev4390_0239", "translation": "是指？"},
    {"id": "b070_ev4390_0311", "translation": "不过，总觉得拜田同学工作时的表情有些僵硬。"},
    {"id": "b070_ev4390_0333", "translation": "怎、怎、怎、怎、怎么了？"},
    {"id": "b070_ev4390_0354", "translation": "但不能就这样让今天结束……"},
    {"id": "b070_ev4390_0365", "translation": "说不定也因为写剧本而睡眠不足……"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：从批次文件取 budget 与 id 校验
budgets = {}
with open(BATCH, encoding="utf-8") as f:
    for line in f.read().split("\n")[1:]:
        if not line:
            continue
        cols = line.split("\t")
        budgets[cols[0]] = int(cols[4])

def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

over = []
for p in patches:
    pid = p["id"]
    if pid not in budgets:
        over.append(f"{pid}: id not found in batch")
        continue
    n = enc_len(p["translation"])
    if n > budgets[pid]:
        over.append(f"{pid}: {n}>{budgets[pid]} {p['translation']}")
if over:
    raise SystemExit("width check failed:\n" + "\n".join(over))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
