# -*- coding: utf-8 -*-
"""b065_ev4180 润色补丁构建：按 id 对现译文做片段替换，附宽度自检。

- 每条编辑给出 (old 片段, new 片段, note)；old 片段必须在现译文中恰好出现一次，
  否则报错终止，避免误替换。
- 替换后按 enc_len（非 ASCII=2，ASCII=1）核算显示宽度，超过 budget 直接终止。
"""
import csv
import json
from pathlib import Path

ROOT = Path(r"D:\VITA3K\ux0\app\PCSG00337")
TSV = ROOT / "localization/text/work/b065_ev4180.tsv"

# id -> (old 片段, new 片段, note 或 None)
edits = {
    "b065_ev4180_0033": ("樱花祭的综合优胜就会远去",
                         "樱花祭的综合优胜就会越发遥远", None),
    "b065_ev4180_0098": ("不知咋反应，俩人一起僵住。",
                         "不知所措，两人一起僵住。", None),
    "b065_ev4180_0112": ("从客人立场能被接待更久，不是反而更开心吗",
                         "从客人立场能被接待更久，那样不是更开心吗", None),
    "b065_ev4180_0159": ("走向了料理组的圈子。", "走向了料理组那边。", None),
    "b065_ev4180_0160": ("难看地喊出了声。", "还失态地喊出了声。", None),
    "b065_ev4180_0161": ("一边品味着微妙的空气，", "一边感受着微妙的气氛，", None),
    "b065_ev4180_0187": ("改成制服咖啡店真是太好了", "改成制服咖啡店，真是太好了", None),
    "b065_ev4180_0201": ("「头脑上明白……", "「道理上都明白……", None),
    "b065_ev4180_0209": ("「啊，嗯，是……」", "「嗯，是没错……」", None),
    "b065_ev4180_0210": ("「抱歉。那――」", "「抱歉。呃――」", None),
    "b065_ev4180_0217": ("「不……要说的。", "「不……我要说。", None),
    "b065_ev4180_0226": ("「那个，抱歉，是不是不想说？」",
                         "「抱歉，是不是问到不该问的？」", None),
    "b065_ev4180_0228": ("「诶？拜田同学？」", "「诶？拜田说什么？」",
                         "预算紧压缩（拜田同学→拜田）"),
    "b065_ev4180_0231": ("「工作中抱歉了」", "「工作中打扰很抱歉」", None),
    "b065_ev4180_0238": ("「是吗？总之先上来歇着吧」", "「是吗？总之先进来歇着吧」", None),
    "b065_ev4180_0239": ("「对。能开张收据吗？」", "「对。能写张收据吗？」", None),
    "b065_ev4180_0243": ("「回来了！回来晚啦！！」", "「回来啦！回来晚了抱歉」", None),
    "b065_ev4180_0246": ("很快就完了", "很快就做完", None),
    "b065_ev4180_0255": ("「慈善义卖会传单……」", "「嗯？慈善义卖会的传单啊……」", None),
}


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


rows = {}
with open(TSV, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        rows[r["id"]] = r

patches = []
for pid, (old, new, note) in edits.items():
    cur = rows[pid]["translation"]
    if cur.count(old) != 1:
        raise SystemExit(f"{pid}: old snippet not found uniquely in: {cur!r}")
    tr = cur.replace(old, new)
    b = int(rows[pid]["budget"])
    n = enc_len(tr)
    if n > b:
        raise SystemExit(f"{pid}: width {n} > budget {b}; drop this edit")
    if "\t" in tr or "\n" in tr or "\r" in tr:
        raise SystemExit(f"{pid}: control char in translation")
    p = {"id": pid, "translation": tr}
    if note:
        p["note"] = note
    patches.append(p)

out = ROOT / "localization/reports/polish_20260910/patches/b065_ev4180.json"
out.parent.mkdir(parents=True, exist_ok=True)
with open(out, "w", encoding="utf-8") as f:
    json.dump({"patches": patches}, f, ensure_ascii=False, indent=1)
print("patches:", len(patches))
