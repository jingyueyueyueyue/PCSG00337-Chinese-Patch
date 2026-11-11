# -*- coding: utf-8 -*-
"""b064_ev4150 润色补丁构建脚本（含控制符与显示宽度自检）"""
import json

BUDGET = {
    "b064_ev4150_0010": 49,
    "b064_ev4150_0011": 34,
    "b064_ev4150_0022": 64,
    "b064_ev4150_0068": 36,
    "b064_ev4150_0071": 84,
    "b064_ev4150_0073": 11,
    "b064_ev4150_0088": 23,
    "b064_ev4150_0113": 17,
    "b064_ev4150_0118": 47,
    "b064_ev4150_0121": 34,
    "b064_ev4150_0122": 40,
    "b064_ev4150_0137": 53,
    "b064_ev4150_0143": 47,
    "b064_ev4150_0207": 46,
    "b064_ev4150_0227": 31,
    "b064_ev4150_0231": 26,
    "b064_ev4150_0235": 27,
}

patches = [
    {"id": "b064_ev4150_0010", "translation": "「嗯……终于懂了。果然还是希望三谷君想起我……」"},
    {"id": "b064_ev4150_0011", "translation": "「再见，真央同学。明天也请多关照」"},
    {"id": "b064_ev4150_0022", "translation": "颜色倒是烤成了泡芙该有的金黄色，面皮却依然扁扁的，活像块煎饼。"},
    {"id": "b064_ev4150_0068", "translation": "「可结果我们几乎光顾着看了对吧？」"},
    {"id": "b064_ev4150_0071", "translation": "「看来ｅｅｎ×ｖｉｊｆ流派的泡芙这就完成了呢，拜田同学」"},
    {"id": "b064_ev4150_0073", "translation": "「古德拜」", "note": "按词表音译统一"},
    {"id": "b064_ev4150_0088", "translation": "「刚才看哪里判断的？」"},
    {"id": "b064_ev4150_0113", "translation": "「先停下试试吧」"},
    {"id": "b064_ev4150_0118", "translation": "「啊，好，不好意思。那么三谷君，今天非常感谢」"},
    {"id": "b064_ev4150_0121", "translation": "「嗯。而且我也不忍心泼拜田冷水」"},
    {"id": "b064_ev4150_0122", "translation": "「哦，拜田同学喜欢的《天使之泪》啊……」"},
    {"id": "b064_ev4150_0137", "translation": "「嗯。太多太少都麻烦……那就大概做100个左右？」"},
    {"id": "b064_ev4150_0143", "translation": "「嗯，这步让步梦教你做就好。步梦也没问题吧？」"},
    {"id": "b064_ev4150_0207", "translation": "见拜田同学低头发抖，我放心不下，又唤了一声。"},
    {"id": "b064_ev4150_0227", "translation": "「拜田同学的话让大家睁大眼。」"},
    {"id": "b064_ev4150_0231", "translation": "「樱花祭后半战，加油啊」"},
    {"id": "b064_ev4150_0235", "translation": "「不过班里也许有人留着哦」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

def width(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

over = [(p["id"], width(p["translation"]), BUDGET[p["id"]])
        for p in patches if width(p["translation"]) > BUDGET[p["id"]]]
if over:
    raise SystemExit("too long: %r" % over)

json.dump({"patches": patches},
          open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b064_ev4150.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("patches:", len(patches))
