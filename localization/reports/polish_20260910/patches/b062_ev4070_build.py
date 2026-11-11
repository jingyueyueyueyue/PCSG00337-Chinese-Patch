# -*- coding: utf-8 -*-
"""b062_ev4070 润色补丁构建（自带显示宽度自检）"""
import json

BUDGETS = {
    "b062_ev4070_0027": 53,
    "b062_ev4070_0030": 97,
    "b062_ev4070_0037": 46,
    "b062_ev4070_0046": 73,
    "b062_ev4070_0064": 47,
    "b062_ev4070_0085": 46,
    "b062_ev4070_0094": 22,
    "b062_ev4070_0095": 21,
    "b062_ev4070_0097": 28,
    "b062_ev4070_0099": 29,
    "b062_ev4070_0104": 35,
    "b062_ev4070_0113": 76,
    "b062_ev4070_0122": 32,
    "b062_ev4070_0123": 28,
    "b062_ev4070_0126": 50,
    "b062_ev4070_0149": 26,
}

patches = [
    {"id": "b062_ev4070_0027", "translation": "由于是『难解类型』，任务全是一看就莫名其妙的谜面。"},
    {"id": "b062_ev4070_0030", "translation": "「任务02……从假设出发、以演绎法探求事实的广场，古今贤者聚集之地……？」"},
    {"id": "b062_ev4070_0037", "translation": "教室里待命的只剩我和拜田同学、真央酱、章介。"},
    {"id": "b062_ev4070_0046", "translation": "网页上写着，船的博物馆旁的潮骚公园里有模仿船形、同名的游乐设施。"},
    {"id": "b062_ev4070_0064", "translation": "「『迸溅水柱。上岸的她。没有孩子讨厌她』」"},
    {"id": "b062_ev4070_0085", "translation": "「就不能中止现在的任务，让他们前往潮骚丸吗？」"},
    {"id": "b062_ev4070_0094", "translation": "「原来英语确实是这样」"},
    {"id": "b062_ev4070_0095", "translation": "「放弃这个挺伤的啊」"},
    {"id": "b062_ev4070_0097", "translation": "「那个，万一2对2了怎么办？」"},
    {"id": "b062_ev4070_0099", "translation": "「……果然不是船的博物馆？」"},
    {"id": "b062_ev4070_0104", "translation": "「这样就百分之百符合谜面条件了呢」"},
    {"id": "b062_ev4070_0113", "translation": "「但之前的谜面几乎没有无意义的部分。唯独这条后半全无意义，很难想象」"},
    {"id": "b062_ev4070_0122", "translation": "「原来如此，又是谜面呢，说吧」"},
    {"id": "b062_ev4070_0123", "translation": "「总感觉会联想到美人鱼……」"},
    {"id": "b062_ev4070_0126", "translation": "「嘛，谜面太过简单，那里本身应该不是目的地」"},
    {"id": "b062_ev4070_0149", "translation": "拜田同学垂着头，很低落……"},
]

bad = []
for p in patches:
    tr = p["translation"]
    if "\t" in tr or "\n" in tr or "\r" in tr:
        bad.append("control char: " + p["id"])
    n = sum(1 if ord(c) < 128 else 2 for c in tr)
    b = BUDGETS.get(p["id"])
    if b is not None and n > b:
        bad.append("too_long: %s %d>%d" % (p["id"], n, b))
    if b is None:
        bad.append("no budget recorded: " + p["id"])
if bad:
    raise SystemExit("; ".join(bad))

json.dump({"patches": patches}, open(
    r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b062_ev4070.json",
    "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width checks passed")
