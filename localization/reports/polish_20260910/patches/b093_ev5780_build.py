# -*- coding: utf-8 -*-
"""b093_ev5780 润色补丁构建脚本（宽度自检与 validate_translations.py 一致：ASCII=1，其余=2）"""
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b093_ev5780.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b093_ev5780.json")

patches = [
    {"id": "b093_ev5780_0008", "translation": "理事长在信里得出的结论是：她身手高超足以获得免许皆传、不输男子这一点，或许在流传中被歪曲了。"},
    {"id": "b093_ev5780_0022", "translation": "「……对、对不起。还有点乱……」"},
    {"id": "b093_ev5780_0025", "translation": "「这个嘛」"},
    {"id": "b093_ev5780_0041", "translation": "「拜托过理事长一件事……」"},
    {"id": "b093_ev5780_0082", "translation": "我把带有大猫耳的发箍戴在真央酱头上。"},
    {"id": "b093_ev5780_0087", "translation": "其实我本想去真央酱家接她，结果被以既绕路又浪费电车费为由否决了。"},
    {"id": "b093_ev5780_0088", "translation": "「！？怎么样？合适吗？」"},
    {"id": "b093_ev5780_0092", "translation": "「怎么办？」"},
    {"id": "b093_ev5780_0106", "translation": "「可不说的话条件照旧，相当严峻吧？」"},
    {"id": "b093_ev5780_0110", "translation": "「想来多少次都行。因为我们正在交往嘛」"},
    {"id": "b093_ev5780_0112", "translation": "「现在好幸福……」"},
    {"id": "b093_ev5780_0114", "translation": "「我想让老爷子100%认可我的剑，获得免许皆传」"},
    {"id": "b093_ev5780_0122", "translation": "「藤乃大人以女性之身获得了免许皆传，我只要全力以赴也绝对能做到……我坚信如此」"},
    {"id": "b093_ev5780_0134", "translation": "「不用，我自己买」"},
    {"id": "b093_ev5780_0163", "translation": "「当然，得补回被破门期间的份」"},
]


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


# 控制字符检查
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：与批次 TSV 的 budget 列核对
budget = {}
for line in BATCH.read_text(encoding="utf-8").splitlines()[1:]:
    cols = line.split("\t")
    if len(cols) >= 6:
        budget[cols[0]] = int(cols[4])

errs = []
for p in patches:
    b = budget.get(p["id"])
    if b is None:
        errs.append("%s: id not found in batch" % p["id"])
        continue
    w = enc_len(p["translation"])
    if w > b:
        errs.append("%s: width %d > budget %d (%s)" % (p["id"], w, b, p["translation"]))

if errs:
    raise SystemExit("WIDTH/ID FAIL:\n" + "\n".join(errs))

OUT.write_text(
    json.dumps({"patches": patches}, ensure_ascii=False, indent=1),
    encoding="utf-8",
)
print("patches:", len(patches), "all width checks passed")
