# -*- coding: utf-8 -*-
"""b088_ev5530 润色补丁构建：自带 id 存在性 / 显示宽度 / 控制符自检。

translation 为 None 的补丁行表示仅改 note（自动沿用当前译文，保证不误改译文）。
"""
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b088_ev5530.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b088_ev5530.json")

rows = {}
for line in BATCH.read_text(encoding="utf-8").split("\n")[1:]:
    if not line.strip():
        continue
    f = line.split("\t")
    rows[f[0]] = {"budget": int(f[4]), "translation": f[6]}


def width(s):
    return sum(1 if ord(c) < 0x80 else 2 for c in s)


# (id, 新译文 or None=仅改note, note or None)
patches_spec = [
    ("b088_ev5530_0001", "父亲似乎满意我的回答，笑得眯起眼。", None),
    ("b088_ev5530_0015", "「还有，说不是真恋爱就不被认可，也只是我的猜测，别在意」", None),
    ("b088_ev5530_0096", None, "预算过紧"),
    ("b088_ev5530_0099", "「可你忽然不说话了……」", None),
    ("b088_ev5530_0101", None, "预算过紧"),
    ("b088_ev5530_0106", None, "预算过紧"),
    ("b088_ev5530_0117", "「不，看着超好吃！」", None),
    ("b088_ev5530_0127", "「好吃？」", None),
    ("b088_ev5530_0137", "「这样可以吗？」", None),
    ("b088_ev5530_0145", "「嗯，煎蛋卷也超好吃」", None),
    ("b088_ev5530_0180", "「缝上去？」", None),
    ("b088_ev5530_0221", "逛了快十家店，才终于找到。", None),
    ("b088_ev5530_0226", None, "预算过紧"),
    ("b088_ev5530_0247", "「嗯……这个超可爱……」", None),
    ("b088_ev5530_0250", "「诶？啊，说起来……」", None),
    ("b088_ev5530_0252", None, "预算过紧"),
    ("b088_ev5530_0254", "「可爱吧？」", None),
    ("b088_ev5530_0258", "「看啥？」", None),
    ("b088_ev5530_0259", None, "预算过紧"),
    ("b088_ev5530_0263", "「真是的，坦率表露心情不也挺好？」", None),
    # b088_ev5530_0269 预算 25，理顺措辞压不进（26+），放弃修改
    ("b088_ev5530_0270", "到那时，吊坠什么的确实……", None),
]

patches = []
errors = []
for pid, tr, note in patches_spec:
    if pid not in rows:
        errors.append("unknown id: " + pid)
        continue
    cur = rows[pid]
    new_tr = cur["translation"] if tr is None else tr
    if tr is not None:
        if "\t" in new_tr or "\n" in new_tr or "\r" in new_tr:
            errors.append("control char: " + pid)
            continue
        w = width(new_tr)
        if w > cur["budget"]:
            errors.append("too long %s: %d > %d" % (pid, w, cur["budget"]))
            continue
    p = {"id": pid, "translation": new_tr}
    if note is not None:
        p["note"] = note
    patches.append(p)

if errors:
    raise SystemExit("BUILD FAILED:\n" + "\n".join(errors))

OUT.write_text(json.dumps({"patches": patches}, ensure_ascii=False, indent=1), encoding="utf-8")
print("patches:", len(patches))
