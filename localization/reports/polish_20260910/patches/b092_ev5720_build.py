# -*- coding: utf-8 -*-
"""b092_ev5720 润色补丁构建脚本（自带显示宽度自检）。"""
import json

# (id, budget, translation)
patches_raw = [
    ("b092_ev5720_0004", 35, "……把真央酱一个人丢下，真的好吗？"),
    ("b092_ev5720_0006", 51, "但要是那之后还和真央酱在一起，我没自信坚持到底。"),
    ("b092_ev5720_0015", 24, "其实，很想抱住真央酱。"),
    ("b092_ev5720_0025", 30, "我正端坐在真央酱家的道场里。"),
    ("b092_ev5720_0043", 43, "……愚蠢老人可怜的愿望，能否请你答应？"),
    ("b092_ev5720_0055", 39, "……说出来，你会接受真央的心意吗？"),
    ("b092_ev5720_0088", 62, "必须尽早让她从剑中解放。哪怕早一秒，也要让她变回普通女孩"),
    ("b092_ev5720_0139", 45, "以后不是练习对象……想作为真正的恋人交往"),
    ("b092_ev5720_0147", 35, "那……昨天约会到底发生了什么？"),
    ("b092_ev5720_0151", 43, "为剑奉献一切的真央，谁能叫她到此为止？"),
    ("b092_ev5720_0162", 62, "那我要以女性的身心生活，同时以首位获免许皆传的女性为目标"),
    ("b092_ev5720_0227", 56, "要是能让免许皆传的可能性再高一点，对真央酱也是鼓励……"),
    ("b092_ev5720_0244", 38, "那为什么还牵着三谷君的手……？"),
    ("b092_ev5720_0280", 20, "从上周延续的细活。"),
    ("b092_ev5720_0281", 47, "这速度还不至于挨骂，但不想被念叨，还是减了速。"),
    ("b092_ev5720_0288", 26, "……你就是三谷君吧？"),
    ("b092_ev5720_0314", 36, "从第三名开始依次公布，只剩一个——"),
    ("b092_ev5720_0325", 22, "找到了，三谷君"),
    ("b092_ev5720_0328", 39, "是的。说交给三谷君就明白了……"),
]

def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

bad = []
patches = []
for pid, budget, tr in patches_raw:
    if "\t" in tr or "\n" in tr or "\r" in tr:
        bad.append(f"{pid}: control char")
        continue
    n = enc_len(tr)
    if n > budget:
        bad.append(f"{pid}: width {n}>{budget}: {tr}")
        continue
    patches.append({"id": pid, "translation": tr})

if bad:
    raise SystemExit("WIDTH/CHAR FAIL:\n" + "\n".join(bad))

out = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b092_ev5720.json"
json.dump({"patches": patches}, open(out, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
