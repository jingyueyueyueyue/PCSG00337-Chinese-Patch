# -*- coding: utf-8 -*-
# b018_ev0710 润色补丁构建脚本（2026-09-10）
import json

def w(s):
    return sum(2 if ord(c) > 0x7F else 1 for c in s)

patches = [
    # --- 语句润色 / 语序 ---
    {"id": "b018_ev0710_0001", "translation": "真央酱向前迈出一步。"},
    {"id": "b018_ev0710_0186", "translation": "横山，咋了？", "note": "省略「」"},
    {"id": "b018_ev0710_0189", "translation": "「章介本来就赞成……那松饼就定下来了」"},
    {"id": "b018_ev0710_0225", "translation": "要舍弃这个动作、全程保持平底锅水平做蛋包饭，确实有点难……"},
    {"id": "b018_ev0710_0306", "translation": "嗯，不事先知道的话绝对认不出是未玖。"},
    {"id": "b018_ev0710_0392", "translation": "要是连这点事都犹豫，在这个家就再也提不了妈妈了。"},
    # --- 误译 / 漏译 ---
    {"id": "b018_ev0710_0099", "translation": "不是姑且做做，是必须做"},
    {"id": "b018_ev0710_0102", "translation": "「我也不太懂，但老老实实瘦下来好处更多吧，对健康也好」"},
    {"id": "b018_ev0710_0106", "translation": "「三谷妹擅长乒乓球？」"},
    {"id": "b018_ev0710_0130", "translation": "「呃……是想让人觉得『明明瘦了会更帅』，才故意不瘦？」"},
    {"id": "b018_ev0710_0197", "translation": "「作为真正的主人拥有女仆的妙趣！不是绅士之梦又是什么？」"},
    {"id": "b018_ev0710_0313", "translation": "看着良子小姐，步梦无奈地耸了耸肩。"},
    # --- 词表称谓 / 名词统一 ---
    {"id": "b018_ev0710_0024", "translation": "「确实叫『茂森同学』挺别扭的」"},
    {"id": "b018_ev0710_0035", "translation": "「拜田酱也不想被章介君说吧？」"},
    {"id": "b018_ev0710_0042", "translation": "「啊，茂森君？」"},
    {"id": "b018_ev0710_0104", "translation": "加油哦，章介君", "note": "省略「」"},
    {"id": "b018_ev0710_0212", "translation": "「没错，没有爱恋冲击哪来女仆咖啡店！」"},
    {"id": "b018_ev0710_0221", "translation": "好，步梦小姐请说"},
    {"id": "b018_ev0710_0237", "translation": "笑着走出爸爸房间的良子小姐。"},
    {"id": "b018_ev0710_0248", "translation": "「但我没忘记哦，和陆斗君的约定」"},
    {"id": "b018_ev0710_0265", "translation": "陆斗君……好想你……"},
    {"id": "b018_ev0710_0266", "translation": "「陆斗君，请和我结婚……」"},
    {"id": "b018_ev0710_0270", "translation": "啊，陆斗君！"},
    {"id": "b018_ev0710_0294", "translation": "「那个直接问良子小姐不就行了？她今天补休，应该一直在家」"},
    {"id": "b018_ev0710_0312", "translation": "也就是说，良子小姐拥有那么高的水准……"},
    # --- 恢复对白引号（源文有「」且预算允许）---
    {"id": "b018_ev0710_0011", "translation": "「活了15年，还是头一次被人说自己的姓氏很奇怪……」"},
    {"id": "b018_ev0710_0015", "translation": "「那你今天打算吃什么？」"},
    {"id": "b018_ev0710_0017", "translation": "「那这样看来，果然还是不该叫『真央酱』吗？」"},
    {"id": "b018_ev0710_0020", "translation": "「可我又觉得除了『真央酱』以外都不太对劲……」"},
    {"id": "b018_ev0710_0021", "translation": "「您怎么会来这种地方？」"},
    {"id": "b018_ev0710_0022", "translation": "「不对，陆斗。你误会了。」"},
    {"id": "b018_ev0710_0023", "translation": "「不对！是钢真斋大人」"},
]

# 控制字符自检
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 显示宽度自检（需与批次 budget 对照，这里手工核对过的上限表）
budget = {
    "b018_ev0710_0001": 20, "b018_ev0710_0011": 59, "b018_ev0710_0015": 26,
    "b018_ev0710_0017": 46, "b018_ev0710_0020": 48, "b018_ev0710_0021": 24,
    "b018_ev0710_0022": 26,
    "b018_ev0710_0023": 35, "b018_ev0710_0024": 30, "b018_ev0710_0035": 35,
    "b018_ev0710_0042": 19, "b018_ev0710_0099": 23, "b018_ev0710_0102": 61,
    "b018_ev0710_0104": 16, "b018_ev0710_0106": 23, "b018_ev0710_0130": 59,
    "b018_ev0710_0186": 13, "b018_ev0710_0189": 41, "b018_ev0710_0197": 68,
    "b018_ev0710_0212": 43, "b018_ev0710_0221": 18, "b018_ev0710_0225": 67,
    "b018_ev0710_0237": 31, "b018_ev0710_0248": 37, "b018_ev0710_0265": 23,
    "b018_ev0710_0266": 28, "b018_ev0710_0270": 13, "b018_ev0710_0294": 60,
    "b018_ev0710_0306": 36, "b018_ev0710_0312": 38, "b018_ev0710_0313": 34,
    "b018_ev0710_0392": 50,
}
over = [(p["id"], w(p["translation"]), budget[p["id"]])
        for p in patches if w(p["translation"]) > budget[p["id"]]]
if over:
    raise SystemExit("over budget: %r" % over)

json.dump({"patches": patches},
          open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b018_ev0710.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("patches:", len(patches))
