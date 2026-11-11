# -*- coding: utf-8 -*-
"""b076_ev4580 润色补丁构建（自带显示宽度自检，宽度口径与 validate_translations.py 一致）"""
import json

BUDGETS = {
    "b076_ev4580_0016": 39,
    "b076_ev4580_0030": 47,
    "b076_ev4580_0057": 19,
    "b076_ev4580_0092": 22,
    "b076_ev4580_0099": 96,
    "b076_ev4580_0126": 67,
    "b076_ev4580_0195": 29,
    "b076_ev4580_0196": 41,
    "b076_ev4580_0204": 43,
    "b076_ev4580_0212": 44,
    "b076_ev4580_0230": 24,
    "b076_ev4580_0246": 52,
    "b076_ev4580_0248": 50,
    "b076_ev4580_0250": 48,
    "b076_ev4580_0253": 15,
    "b076_ev4580_0274": 11,
    "b076_ev4580_0336": 27,
    "b076_ev4580_0338": 12,
    "b076_ev4580_0367": 33,
    "b076_ev4580_0373": 8,
    "b076_ev4580_0388": 26,
}

patches = [
    {"id": "b076_ev4580_0016", "translation": "黑暗中，可见希实花轻轻点了点头。"},
    {"id": "b076_ev4580_0030", "translation": "希实花应该是为跳过了一幕而混乱吧……"},
    {"id": "b076_ev4580_0057", "translation": "慌乱逐渐平复下来。"},
    {"id": "b076_ev4580_0092", "translation": "我会成为你的碎片……", "note": "预算紧，省略引号"},
    {"id": "b076_ev4580_0099", "translation": "「先打扫还是先收拾，对女仆来说是永恒的命题，我把先有蛋还是先有鸡的问题混为一谈，才说了奇怪的话」"},
    {"id": "b076_ev4580_0126", "translation": "「没关系的……失去那个人，你深受重创，这些我想我是明白的……」"},
    {"id": "b076_ev4580_0195", "translation": "全班一起沸腾了起来。"},
    {"id": "b076_ev4580_0196", "translation": "一瞬间她又变回了入学之初的拘谨委员长。"},
    {"id": "b076_ev4580_0204", "translation": "我只是怔怔望着教室门口，伫立在原地。"},
    {"id": "b076_ev4580_0212", "translation": "希实花的笑颜、她羞涩的笑脸、她哭泣的脸……"},
    {"id": "b076_ev4580_0230", "translation": "取而代之，莫名苦闷袭来。"},
    {"id": "b076_ev4580_0246", "translation": "「毕竟是自己班的事，说恭喜有点怪。再说一次，恭喜。」"},
    {"id": "b076_ev4580_0248", "translation": "「重力无法抗拒。恋爱即陷阱。甜～到不行的人生陷阱」"},
    {"id": "b076_ev4580_0250", "translation": "「身为绅士，可得更善于体察淑女的心情才行哦？」"},
    {"id": "b076_ev4580_0253", "translation": "火热拥抱……？", "note": "预算紧，省略引号"},
    {"id": "b076_ev4580_0274", "translation": "嗯，是啊。"},
    {"id": "b076_ev4580_0336", "translation": "不知不觉就喜欢上了啊。"},
    {"id": "b076_ev4580_0338", "translation": "心跳加速。"},
    {"id": "b076_ev4580_0367", "translation": "「无论何时都想在陆斗君身边……」"},
    {"id": "b076_ev4580_0373", "translation": "希实花", "note": "预算紧，省略引号"},
    {"id": "b076_ev4580_0388", "translation": "「嗯，我也想在希实花身边」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

over = []
for p in patches:
    n = sum(1 if ord(c) < 128 else 2 for c in p["translation"])
    if n > BUDGETS[p["id"]]:
        over.append("%s %d>%d" % (p["id"], n, BUDGETS[p["id"]]))
if over:
    raise SystemExit("too_long: %r" % over)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b076_ev4580.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
