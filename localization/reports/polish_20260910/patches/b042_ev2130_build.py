# -*- coding: utf-8 -*-
"""b042_ev2130 润色补丁构建（自带宽度自检，预算=全角2/半角1，含引号）。"""
import csv
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b042_ev2130.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b042_ev2130.json")


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


patches = [
    {"id": "b042_ev2130_0017",
     "translation": "「车上一定配有信号火棒。为了告知出事点燃信号火棒，很有可能……」"},
    {"id": "b042_ev2130_0040",
     "translation": "「是啊……对了」"},
    {"id": "b042_ev2130_0050",
     "translation": "「原来如此。定位发光点……」"},
    {"id": "b042_ev2130_0095",
     "translation": "「要去！？」"},
    {"id": "b042_ev2130_0116",
     "translation": "「这里……有东西掉落的痕迹……」"},
    {"id": "b042_ev2130_0131",
     "translation": "（真话……明明只要想说就能说的……）"},
    {"id": "b042_ev2130_0132",
     "translation": "（明明是妹妹，是女孩……）"},
    {"id": "b042_ev2130_0223",
     "translation": "急忙找好新落脚点，一只手松开抓手绕到步梦背后，撑住步梦。"},
    {"id": "b042_ev2130_0237",
     "translation": "得快点带她去暖和地方……"},
    {"id": "b042_ev2130_0287",
     "translation": "「因为最爱……绝对守护！」"},
    {"id": "b042_ev2130_0313",
     "translation": "「诶？暖？」"},
    {"id": "b042_ev2130_0314",
     "translation": "「这里吗？」", "note": ""},
    {"id": "b042_ev2130_0319",
     "translation": "「哥哥……让你担心了，对不起」"},
    {"id": "b042_ev2130_0334",
     "translation": "「作为一个女孩……步梦……我真心喜欢……」"},
    {"id": "b042_ev2130_0335",
     "translation": "「已经藏不住心意了……」"},
    {"id": "b042_ev2130_0344",
     "translation": "「我不是弟弟，是妹妹……」"},
    {"id": "b042_ev2130_0347",
     "translation": "「嗯……哥哥！」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

with open(BATCH, encoding="utf-8", newline="") as f:
    rows = {r["id"]: r for r in csv.DictReader(f, delimiter="\t")}

errors = []
for p in patches:
    r = rows.get(p["id"])
    if r is None:
        errors.append(f"{p['id']}: id not in batch")
        continue
    n = enc_len(p["translation"])
    b = int(r["budget"])
    if n > b:
        errors.append(f"{p['id']}: width {n}>{b}")
if errors:
    raise SystemExit("\n".join(errors))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
