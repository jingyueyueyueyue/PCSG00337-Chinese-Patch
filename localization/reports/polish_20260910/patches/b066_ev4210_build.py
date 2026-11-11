# -*- coding: utf-8 -*-
import io
import json

PATCHES_TSV = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b066_ev4210.tsv"
OUT_JSON = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b066_ev4210.json"

patches = [
    {"id": "b066_ev4210_0071", "translation": "「取消女仆装的事，三谷君的妈妈没有生气吗？」"},
    {"id": "b066_ev4210_0093", "translation": "「所以是被原谅了吗？」"},
    {"id": "b066_ev4210_0112", "translation": "「……最后那句让人很在意，现在先别吐槽了」"},
    {"id": "b066_ev4210_0116", "translation": "「那要不要提提『高藤咖啡』『高藤松饼』之类的？」"},
    {"id": "b066_ev4210_0124", "translation": r"早上我已经确认过班上大家各能带来什么制服了——"},
    {"id": "b066_ev4210_0141", "translation": "「——之后，果酱装罐完毕。」"},
    {"id": "b066_ev4210_0160", "translation": "「细砂糖渐渐溶化了呢」"},
    {"id": "b066_ev4210_0183", "translation": "「那个……三谷君果然在和奉莉小姐交往吗……？」"},
    {"id": "b066_ev4210_0184", "translation": "「回见啦」"},
    {"id": "b066_ev4210_0197", "translation": "而老爸他——"},
    {"id": "b066_ev4210_0243", "translation": "「嗯，很有祭日将近氛围」"},
    {"id": "b066_ev4210_0264", "translation": "「听说用店里的烤箱，2个小时左右就能烤100个，准备工作应该能从容完成」"},
    {"id": "b066_ev4210_0274", "translation": "「那个……托、托大家的福，各项准备都顺利完成，今天就先到这里」"},
    {"id": "b066_ev4210_0278", "translation": "「是嘛？我们正好做完准备，正在回来的路上」"},
    {"id": "b066_ev4210_0279", "translation": "「步梦小姐她们也刚好做完准备」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)


def width(s):
    return sum(1 if ord(ch) < 0x80 else 2 for ch in s)


budgets = {}
ids_in_file = set()
for ln in io.open(PATCHES_TSV, encoding="utf-8").read().splitlines()[1:]:
    c = ln.split("\t")
    if len(c) >= 8:
        ids_in_file.add(c[0])
        budgets[c[0]] = int(c[4])

errors = []
for p in patches:
    pid = p["id"]
    if pid not in ids_in_file:
        errors.append("%s: id not in batch" % pid)
        continue
    w = width(p["translation"])
    if w > budgets[pid]:
        errors.append("%s: width %d > budget %d" % (pid, w, budgets[pid]))
if errors:
    raise SystemExit("\n".join(errors))

json.dump({"patches": patches}, io.open(OUT_JSON, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
