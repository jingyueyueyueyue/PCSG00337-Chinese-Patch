# -*- coding: utf-8 -*-
"""b091_ev5685 润色补丁构建：生成 JSON，并自带宽度/控制符自检。"""
import csv
import json
import sys

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b091_ev5685.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b091_ev5685.json"

patches = [
    {"id": "b091_ev5685_0017", "translation": "「然后你们就约好那时候要一起争取免许皆传？」"},
    {"id": "b091_ev5685_0024", "translation": "「脚都跟着大家动了哦」"},
    {"id": "b091_ev5685_0090", "translation": "眼前出现了那家买过帽子布贴的杂货店。"},
    {"id": "b091_ev5685_0131", "translation": "红着脸羞笑的真央酱。"},
    {"id": "b091_ev5685_0134", "translation": "「但……陆斗呢？」"},
    {"id": "b091_ev5685_0136", "translation": "「……比想的远」"},
    {"id": "b091_ev5685_0167", "translation": "「那在看什么？」"},
    {"id": "b091_ev5685_0168", "translation": "「那慢慢走哦」"},
    {"id": "b091_ev5685_0196", "translation": "「啊哈哈。不过主意是弟子想的」"},
    {"id": "b091_ev5685_0212", "translation": "呀！！"},
    {"id": "b091_ev5685_0221", "translation": "「那也是原因……从这个角度看着它渐渐靠近很新鲜」"},
    {"id": "b091_ev5685_0222", "translation": "「我觉得真央酱大概比谁都可爱……」"},
    {"id": "b091_ev5685_0257", "translation": "不久，船转了个大弯，靠上了码头。"},
    {"id": "b091_ev5685_0276", "translation": "真央酱微微点头。"},
    {"id": "b091_ev5685_0280", "translation": "「……怎么样？老爷子果然不会同意？」"},
    {"id": "b091_ev5685_0285", "translation": "「……今天不开心？」"},
    {"id": "b091_ev5685_0287", "translation": "「要放弃免许皆传吗？」", "note": "预算所限合并两句"},
]

# 控制符自检
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：从批次文件读 budget，enc_len 规则与 validate_translations.py 一致
def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

budgets = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for row in csv.DictReader(f, delimiter="\t"):
        budgets[row["id"]] = int(row["budget"])

errors = []
for p in patches:
    b = budgets.get(p["id"])
    if b is None:
        errors.append("%s: id not in batch" % p["id"])
        continue
    n = enc_len(p["translation"])
    if n > b:
        errors.append("%s: too_long %d>%d %s" % (p["id"], n, b, p["translation"]))
if errors:
    raise SystemExit("WIDTH FAIL:\n" + "\n".join(errors))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width checks passed")
