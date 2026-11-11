# -*- coding: utf-8 -*-
"""b089_ev5590 润色补丁构建脚本（含显示宽度自检：全角=2 半角=1）。"""
import json

BUDGET = {
    "b089_ev5590_0035": 23,
    "b089_ev5590_0041": 16,
    "b089_ev5590_0089": 27,
    "b089_ev5590_0122": 33,
    "b089_ev5590_0133": 27,
    "b089_ev5590_0164": 33,
    "b089_ev5590_0176": 31,
    "b089_ev5590_0197": 34,
    "b089_ev5590_0254": 30,
    "b089_ev5590_0255": 16,
    "b089_ev5590_0257": 27,
    "b089_ev5590_0259": 51,
    "b089_ev5590_0260": 28,
    "b089_ev5590_0270": 23,
    "b089_ev5590_0285": 35,
    "b089_ev5590_0295": 39,
    "b089_ev5590_0319": 26,
    "b089_ev5590_0323": 26,
}

patches = [
    {"id": "b089_ev5590_0035", "translation": "然后，我像昨天一样——"},
    {"id": "b089_ev5590_0041", "translation": "先不说这个……"},
    {"id": "b089_ev5590_0089", "translation": "『喜欢』明明不是那意思……"},
    {"id": "b089_ev5590_0122", "translation": "「……膝枕也算恋人会做的事吗？」"},
    {"id": "b089_ev5590_0133", "translation": "「现在想和真央酱这样……」"},
    {"id": "b089_ev5590_0164", "translation": "难得牵上了手，想再多牵一会儿。"},
    {"id": "b089_ev5590_0176", "translation": "（可如果真是……恋爱的话……）"},
    {"id": "b089_ev5590_0197", "translation": "到检票口前，牵着手变成一前一后——"},
    {"id": "b089_ev5590_0254", "translation": "温柔而惬意的时光悄然流逝——"},
    {"id": "b089_ev5590_0255", "translation": "……这手怎么办？", "note": ""},
    {"id": "b089_ev5590_0257", "translation": "我向理事长大致说明了情况。"},
    {"id": "b089_ev5590_0259", "translation": "现在才放手有点别扭，但牵着手跟理事长说话太失礼了。"},
    {"id": "b089_ev5590_0260", "translation": "今天也是真央酱亲手做的便当。"},
    {"id": "b089_ev5590_0270", "translation": "「……理事长懂得真多」"},
    {"id": "b089_ev5590_0285", "translation": "「二代是说理事长的孩子也在学？」"},
    {"id": "b089_ev5590_0295", "translation": "「啊……理事长家两代都在道场学」"},
    {"id": "b089_ev5590_0319", "translation": "另外『好吃的——』也挺……"},
    {"id": "b089_ev5590_0323", "translation": "而现在正好刚吃完。"},
]

bad = []
for p in patches:
    tr = p["translation"]
    if "\t" in tr or "\n" in tr or "\r" in tr:
        bad.append((p["id"], "control char"))
        continue
    if p["id"] not in BUDGET:
        bad.append((p["id"], "no budget entry"))
        continue
    n = sum(1 if ord(c) < 128 else 2 for c in tr)
    if n > BUDGET[p["id"]]:
        bad.append((p["id"], "too_long %d>%d" % (n, BUDGET[p["id"]])))
if bad:
    raise SystemExit("width/control check failed: %r" % bad)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b089_ev5590.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
