# -*- coding: utf-8 -*-
"""b067_ev4280 润色补丁构建：生成 JSON 并按批次 budget 自检显示宽度。"""
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b067_ev4280.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b067_ev4280.json")

patches = [
    {"id": "b067_ev4280_0011", "translation": "给我冷静。"},
    {"id": "b067_ev4280_0023", "translation": "「希望你们俩能冷静听我说……」"},
    {"id": "b067_ev4280_0033", "translation": "「连何时能签约也不知道？」"},
    {"id": "b067_ev4280_0038", "translation": "「钱不一定就拿不回来，只是有这种可能。」"},
    {"id": "b067_ev4280_0041", "translation": "――就这样，我和拜田同学各自联系家里后，便埋头做起了少量多次烤泡芙的工作。"},
    {"id": "b067_ev4280_0094", "translation": "「……？有、有那么吃惊？」"},
    {"id": "b067_ev4280_0109", "translation": "「可、可是那有点……那个」"},
    {"id": "b067_ev4280_0112", "translation": "「但就算有新消息也是下周以后了。现在什么都做不了，只能等。」"},
    {"id": "b067_ev4280_0114", "translation": "「我觉得这比一个人闷头苦想好多了。」"},
    {"id": "b067_ev4280_0118", "translation": "「开心？开心什么？」"},
    {"id": "b067_ev4280_0152", "translation": "「呃……是三谷君新家的……？」"},
    {"id": "b067_ev4280_0163", "translation": "「原来如此，是这样啊……可为什么不直说——」"},
    {"id": "b067_ev4280_0174", "translation": "「没……没什么，没事。不、不如赶紧开工吧！」"},
    {"id": "b067_ev4280_0228", "translation": "拜田同学犹豫着点了点头。"},
    {"id": "b067_ev4280_0230", "translation": "毛毯滑落，仅着内衣的拜田同学发出尖叫。"},
    {"id": "b067_ev4280_0246", "translation": "「不、不……好像一时半会找不到……」"},
    {"id": "b067_ev4280_0253", "translation": "「那个……奶油是油性的吧。不赶紧处理就洗不掉了哦。」"},
    {"id": "b067_ev4280_0254", "translation": "「拜托了……」", "note": "预算内恢复「」"},
    {"id": "b067_ev4280_0262", "translation": "「那、那个……脱下来倒洗涤剂拍拍，不然……」"},
    {"id": "b067_ev4280_0276", "translation": "「知道了，这就过去。」"},
    {"id": "b067_ev4280_0278", "translation": "「知道了……只是……怎么说呢……」"},
]

# 控制字符检查
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 与 validate_translations.py 相同的宽度口径：ord(c) < 128 记 1，否则记 2
def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

budgets = {}
for line in BATCH.read_text(encoding="utf-8").splitlines()[1:]:
    cols = line.split("\t")
    if len(cols) >= 5 and cols[0]:
        budgets[cols[0]] = int(cols[4])

over = []
for p in patches:
    b = budgets.get(p["id"])
    n = enc_len(p["translation"])
    if b is None:
        over.append("%s: id not in batch" % p["id"])
    elif n > b:
        over.append("%s: %d>%d %s" % (p["id"], n, b, p["translation"]))

if over:
    raise SystemExit("width overflow:\n" + "\n".join(over))

OUT.write_text(json.dumps({"patches": patches}, ensure_ascii=False, indent=1), encoding="utf-8")
print("patches:", len(patches))
