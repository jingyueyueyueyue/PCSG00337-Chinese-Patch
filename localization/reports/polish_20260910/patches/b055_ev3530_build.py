# -*- coding: utf-8 -*-
"""b055_ev3530 润色补丁构建脚本（含显示宽度自检：全角=2 半角=1）"""
import json
import unicodedata

def width(s):
    w = 0
    for ch in s:
        w += 2 if unicodedata.east_asian_width(ch) in ("F", "W") else 1
    return w

# id -> (translation, note 或 None=保持原note, budget)
patches_def = [
    ("b055_ev3530_0029", "「我要换衣服，你去客厅好吗？」", None, 31),
    ("b055_ev3530_0030", "「快起床！！是未玖，未玖！」", None, 29),
    ("b055_ev3530_0035", "「哥哥坐这边，这边」", None, 21),
    ("b055_ev3530_0082", "「我想是专业表演者征得许可才演的吧」", None, 41),
    ("b055_ev3530_0088", "「去了就知道！」", None, 16),
    ("b055_ev3530_0095", "「未玖酱，谢谢你邀请我们看电影」", None, 33),
    ("b055_ev3530_0115", "「要这么说的话，我们不来的那天才稀奇呢」", None, 42),
    ("b055_ev3530_0122", "「细节还得再打磨，不过做也不是不行吧？」", None, 46),
    ("b055_ev3530_0124", "「哇，倒立着跳耶！」", None, 20),
    ("b055_ev3530_0188", "「嗯。你们俩回来前，我陪未玖酱在这等」", None, 40),
    ("b055_ev3530_0258", "「……我也能去趟厕所吗？」", None, 27),
    ("b055_ev3530_0273", "「没事吧，奉莉？」", None, 19),
    ("b055_ev3530_0277", "「奉莉酱说啥」", "", 14),
    ("b055_ev3530_0287", "「不，怎么会……」", None, 19),
]

patches = []
bad = []
for pid, tr, note, budget in patches_def:
    if "\t" in tr or "\n" in tr or "\r" in tr:
        bad.append((pid, "control char"))
        continue
    w = width(tr)
    if w > budget:
        bad.append((pid, f"width {w} > budget {budget}"))
        continue
    item = {"id": pid, "translation": tr}
    if note is not None:
        item["note"] = note
    patches.append(item)

if bad:
    for pid, why in bad:
        print("BAD:", pid, why)
    raise SystemExit("width/control-char check failed")

out = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b055_ev3530.json"
json.dump({"patches": patches}, open(out, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
