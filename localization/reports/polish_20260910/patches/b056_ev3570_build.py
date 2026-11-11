# -*- coding: utf-8 -*-
"""b056_ev3570 润色校对补丁构建脚本（2026-09-10）。
逐行对照日文原文修正：译文错位互换、误译/漏译、翻译腔、词表称呼规则。
自带控制符自检；宽度自检：全角=2、半角=1，须 <= budget。
"""
import json

BUDGET = {
    "b056_ev3570_0054": 25,
    "b056_ev3570_0127": 22,
    "b056_ev3570_0129": 19,
    "b056_ev3570_0141": 31,
    "b056_ev3570_0152": 43,
    "b056_ev3570_0183": 23,
    "b056_ev3570_0204": 24,
    "b056_ev3570_0205": 12,
    "b056_ev3570_0227": 25,
    "b056_ev3570_0311": 23,
    "b056_ev3570_0320": 27,
}

patches = [
    # 0054: 「〜って……」引述邮件内容，"说到家了"有歧义，改为"说是……"
    {"id": "b056_ev3570_0054", "translation": r"说是到家了，别担心……"},
    # 0127: 补回 みたい（好像）的推断语气
    {"id": "b056_ev3570_0127", "translation": r"「她现在好像烦恼不少」"},
    # 0129: 三谷くん按词表规则 Xくん→X君
    {"id": "b056_ev3570_0129", "translation": r"「三谷君，辛苦了」", "note": "三谷くん按词表译三谷君"},
    # 0141: 补回「今」（刚）这一时间信息
    {"id": "b056_ev3570_0141", "translation": r"「啊、嗯……刚见到奉莉阿姨了」"},
    # 0152: 奉莉さん按同学间称呼规则补"同学"
    {"id": "b056_ev3570_0152", "translation": r"「那个……您知道奉莉同学现在人在哪吗？」", "note": "奉莉さん按称呼规则补同学"},
    # 0183: 去除直译腔"一次"，"一度離れる"=暂时走开
    {"id": "b056_ev3570_0183", "translation": r"总之，先从家门口走开。"},
    # 0204/0205: 初翻两行译文错位互换，按各自原文校正
    {"id": "b056_ev3570_0204", "translation": r"「……这话别再说了」", "note": "初翻与_0205译文错位，已校正"},
    {"id": "b056_ev3570_0205", "translation": r"「原来如此」", "note": "预算紧，省略号省略"},
    # 0227: 补回宾语"奉莉の悩み"，避免"想知道"悬空
    {"id": "b056_ev3570_0227", "translation": r"「我还是想知道她的烦恼」"},
    # 0311: 不覚にも=不由得，"不自觉"生硬
    {"id": "b056_ev3570_0311", "translation": r"（不由得心动了一下）"},
    # 0320: "这身体"生硬，补量词"这副身体"
    {"id": "b056_ev3570_0320", "translation": r"（要是说出这副身体……）"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)


def width(s):
    return sum(2 if ord(c) > 0x2E80 else 1 for c in s)


too_long = [(p["id"], width(p["translation"]), BUDGET[p["id"]])
            for p in patches if width(p["translation"]) > BUDGET[p["id"]]]
if too_long:
    raise SystemExit("too_long: %r" % too_long)

unknown = [p["id"] for p in patches if p["id"] not in BUDGET]
if unknown:
    raise SystemExit("unknown id: %r" % unknown)

json.dump({"patches": patches},
          open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b056_ev3570.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("patches:", len(patches))
