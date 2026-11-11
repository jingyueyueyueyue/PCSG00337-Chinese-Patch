# -*- coding: utf-8 -*-
"""b060_ev3770 润色补丁构建：生成 JSON，附带控制符与显示宽度自检。"""
import json

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b060_ev3770.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b060_ev3770.json"

patches = [
    # 0084 补回「控えめながらも」（拘谨却开心）的漏译
    {"id": "b060_ev3770_0084", "translation": "奉莉也略显拘谨，开心地举了手。"},
    # 0112 补回「陸斗も」的"也"
    {"id": "b060_ev3770_0112", "translation": "「陆斗也别担心。昨天不是好好的嘛？」"},
    # 0136 衣装=演出服，更准确
    {"id": "b060_ev3770_0136", "translation": "「各位——快到出场时间了，请换上演出服前往体育馆！」"},
    # 0138 「これが最後」补"一次"，消除"这都是最后"的破碎感
    {"id": "b060_ev3770_0138", "translation": "「大家，无论哭笑这都是最后一次，全力以赴吧！」"},
    # 0148 フォークダンス=土风舞（民族舞易误解为民族舞蹈艺术）
    {"id": "b060_ev3770_0148", "translation": "就这样牵着手，像跳土风舞一样两人旋转着跳过绳去。"},
    # 0212 三谷くん按词表规则 Xくん→X君（原译"三谷同学"不符）
    {"id": "b060_ev3770_0212", "translation": "「三谷君还是快去保健室比较好」"},
    # 0226 「あれって……?」是追问含义，"哪个"易读成选择问
    {"id": "b060_ev3770_0226", "translation": "「什么？」"},
    # 0266 "宝宝能正常生下"缺宾语悬空，调整语序并补回「も」
    {"id": "b060_ev3770_0266", "translation": "既然知道宝宝也能正常生下来——"},
    # 0306 与 0312「我也只认定陆斗哦」呼应，统一「ひと筋」译法
    {"id": "b060_ev3770_0306", "translation": "「真的哦。我只认定奉莉」"},
    # 0332 「によろしくね」补"替我"更自然
    {"id": "b060_ev3770_0332", "translation": "「慢走，替我问奉莉酱好」"},
    # 0334 休日返上="放弃休息"，原"休假返工"有歧义
    {"id": "b060_ev3770_0334", "translation": "「不，听说高藤的自治学生会放弃休息是家常便饭。就当是提前演习……」"},
    # 0341 約束する是动词，"约好了"优于名词化的"约定"（恰好18宽）
    {"id": "b060_ev3770_0341", "translation": "「嗯，约好了……」"},
    # 0397 "因为……的结果"句式杂糅，理顺
    {"id": "b060_ev3770_0397", "translation": "因为在正规医院做了检查，结果确认她货真价实是个女孩子。"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：对照批次文件 budget 列，全角=2 半角=1
budgets = {}
with open(BATCH, encoding="utf-8") as f:
    next(f)
    for line in f:
        cols = line.rstrip("\n").split("\t")
        budgets[cols[0]] = int(cols[4])

def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

over = [(p["id"], enc_len(p["translation"]), budgets.get(p["id"])) for p in patches
        if p["id"] not in budgets or enc_len(p["translation"]) > budgets[p["id"]]]
if over:
    raise SystemExit("width over / unknown id: %r" % over)

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all within budget")
