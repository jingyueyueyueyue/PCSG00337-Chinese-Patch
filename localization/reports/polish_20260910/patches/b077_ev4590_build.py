# -*- coding: utf-8 -*-
"""b077_ev4590 润色补丁构建脚本（含显示宽度自检）"""
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b077_ev4590.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b077_ev4590.json")

patches = [
    # くすっと微笑んだ是抿嘴轻笑，"噗嗤"过于外放
    {"id": "b077_ev4590_0014", "translation": "希实花吸了口气，轻轻一笑。"},
    # その後指代明确化
    {"id": "b077_ev4590_0029", "translation": "「……换个话题。那之后如何？」"},
    # 正解=正确答案/真相，补出"何があった"的求证语气
    {"id": "b077_ev4590_0035", "translation": "「抱歉。靠自己只能想到这了。当时的真相，能告诉我吗？」"},
    # 消除"朴实花哭了"的歧义断句
    {"id": "b077_ev4590_0053", "translation": "「放学后，被笑话是朴实花，我哭了，陆斗君牵起我的手，带我去了某个地方」"},
    # あれから=那之后
    {"id": "b077_ev4590_0059", "translation": "「那之后，有想起往事吗？」"},
    # がっかりさせたくない=不想让你失望；补"还"
    {"id": "b077_ev4590_0060", "translation": "「不想让你失望就直说，我还没全部想起来」"},
    # 原句逻辑：为了脱裤子而先裹上毛巾
    {"id": "b077_ev4590_0144", "translation": "为了脱裤子而往身上裹毛巾时，我猛然一惊。"},
    # トス=托球，"托传"生造
    {"id": "b077_ev4590_0205", "translation": "我垫起的球，被真央酱托球送上半空。"},
    # "ほっとしちゃった"=松了口气；预算不足去引号
    {"id": "b077_ev4590_0224", "translation": "我也放心了", "note": "预算紧，省略引号"},
    # しよう+な是意志鼓励，非既成事实
    {"id": "b077_ev4590_0226", "translation": "「胜点虽少，也要稳稳为班级出力！」"},
    # 体勢を崩す=失去平衡，"姿势尽失"易误解
    {"id": "b077_ev4590_0264", "translation": "真央酱虽然失去平衡仍追上球，救了起来。"},
]

# 控制字符检查
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 显示宽度自检：全角=2，半角=1
def width(s):
    return sum(2 if ord(c) > 0x7F else 1 for c in s)

budget = {}
for line in BATCH.read_text(encoding="utf-8").split("\n")[1:]:
    if not line:
        continue
    f = line.split("\t")
    budget[f[0]] = int(f[4])

over = []
for p in patches:
    w, b = width(p["translation"]), budget[p["id"]]
    if w > b:
        over.append(f"{p['id']}: width {w} > budget {b} :: {p['translation']}")
if over:
    raise SystemExit("too_long:\n" + "\n".join(over))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width checks passed")
