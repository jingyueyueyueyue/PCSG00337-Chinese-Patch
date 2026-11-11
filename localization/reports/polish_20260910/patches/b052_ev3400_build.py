# -*- coding: utf-8 -*-
"""b052_ev3400 润色补丁构建脚本（自带显示宽度自检）。
宽度规则：全角字符=2、半角字符=1，译文宽度不得超过该行 budget。
"""
import json

# (id, budget, translation, note or None)
patches_raw = [
    ("b052_ev3400_0005", 13, r"服务生A", "与服务生组统一"),
    ("b052_ev3400_0006", 13, r"服务生B", "与服务生组统一"),
    ("b052_ev3400_0007", 13, r"服务生C", "与服务生组统一"),
    ("b052_ev3400_0013", 17, r"正迎来紧要关头。", "佳境=紧要关头，原译尾声有误"),
    ("b052_ev3400_0017", 42, r"按章介的指示，浴衣咖啡店的装饰进展顺利。", "浴衣咖啡店与制服咖啡店等译名统一"),
    ("b052_ev3400_0031", 90, r"「是金枪鱼美乃滋。另外，本套餐提供服务生当面捏饭团的服务，请问您意下如何？」", "服务生与服务生组统一"),
    ("b052_ev3400_0054", 29, r"「久等了，这是凉水和湿毛巾」", "おしぼり统一译湿毛巾"),
    ("b052_ev3400_0104", 26, r"「……今天能留下来住吗？」", "留宿措辞与0113等统一为留下来住"),
    ("b052_ev3400_0114", 25, r"「……怎么了？奉莉酱」", "按原文语序并补问号"),
    ("b052_ev3400_0148", 21, r"「啊，欢迎，奉莉酱」", None),
    ("b052_ev3400_0213", 27, r"「……奉莉真会住下来吗？」", "预算内改住下来更顺"),
    ("b052_ev3400_0249", 15, r"下意识别开脸。", "避免反射性别连读歧义"),
    ("b052_ev3400_0268", 20, r"「我在的话不行吧！」", "补出でしょ的反问语气"),
    ("b052_ev3400_0317", 13, r"「尴尬……」", "预算压缩省略结巴，原文:き、気まずい"),
    ("b052_ev3400_0321", 39, r"强行迈开快要停下的脚步，走出了房间。", "理顺原译强令将停的脚步"),
]


def width(s):
    return sum(2 if ord(ch) > 0x7F else 1 for ch in s)


patches = []
for pid, budget, tr, note in patches_raw:
    w = width(tr)
    if w > budget:
        raise SystemExit(f"too_long: {pid} width {w} > budget {budget}: {tr}")
    if "\t" in tr or "\n" in tr:
        raise SystemExit(f"control chars in: {pid}")
    p = {"id": pid, "translation": tr}
    if note is not None:
        p["note"] = note
    patches.append(p)

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b052_ev3400.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
print("all width checks passed")
