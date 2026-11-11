# -*- coding: utf-8 -*-
"""b039_ev1940 润色补丁构建（2026-09-10 校对批次）"""
import json

P = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b039_ev1940.json"

patches = [
    # 0001 词表统一：夢のおにいちゃん→梦中哥哥
    {"id": "b039_ev1940_0001", "translation": "……说起来，梦中哥哥最近怎么样了？"},
    # 0004 补回 でも（转折）
    {"id": "b039_ev1940_0004", "translation": "但对方不知为何中途换成了步梦……"},
    # 0045 指代明确：喊"哥哥"的梦话（梦中哥哥伏笔）
    {"id": "b039_ev1940_0045", "translation": "喊着哥哥的梦话，好久没听到……"},
    # 0050 去翻译腔（"而且"起句生硬）
    {"id": "b039_ev1940_0050", "translation": "而无法释怀的感情又涌上心头……"},
    # 0064 一瞬→一度，搭配"很悬"更通顺
    {"id": "b039_ev1940_0064", "translation": "一度很悬，但步梦选择了和大家一起努力。"},
    # 0121 称呼规则 Xくん→X君（章介くーん）
    {"id": "b039_ev1940_0121", "translation": "「章介君！」"},
    # 0143 溶ける→烫化（熨斗烫尼龙的明确表达）
    {"id": "b039_ev1940_0143", "translation": "「这部分是尼龙面料，用熨斗粘的话可能会烫化……」"},
    # 0160 补全 やらないで後悔（不做才后悔）的逻辑
    {"id": "b039_ev1940_0160", "translation": "「不做会后悔嘛！」"},
    # 0163 补问号（原文 ?）
    {"id": "b039_ev1940_0163", "translation": "到底聊什么……？"},
    # 0178 补 ずいぶん（频繁）
    {"id": "b039_ev1940_0178", "translation": "今天回家之后，她好像一直在频繁地收发邮件……"},
    # 0192 恢复そ、その的结巴感
    {"id": "b039_ev1940_0192", "translation": "「那、那个……不是那个意思……」"},
    # 0194 补 ああ 的迟疑起句
    {"id": "b039_ev1940_0194", "translation": "「啊，哥哥的梦……咦？」"},
    # 0216 补"的"，定语更顺
    {"id": "b039_ev1940_0216", "translation": "邻座的拜田同学也搭话。"},
    # 0224 补"变"，句子完整
    {"id": "b039_ev1940_0224", "translation": "「教室会变成工作间，恐怕待不下去」"},
    # 0252 加逗号，呼名更自然
    {"id": "b039_ev1940_0252", "translation": "「怎么了，步梦」"},
    # 0276 "有这一面"更通顺
    {"id": "b039_ev1940_0276", "translation": "「当然。良子也商量过，实际相处我也确实感到他有这一面」"},
    # 0279 じきに=很快（原译"慢慢"方向偏了）
    {"id": "b039_ev1940_0279", "translation": "妈妈遗物的事虽然还堵在心头，但疙瘩很快就会变小，终会消失的吧……"},
    # 0305 ただいま→我回来了，更自然
    {"id": "b039_ev1940_0305", "translation": "「我回来了」"},
    # 0333 词表：歩夢さん（希実花对步梦的称呼）→步梦小姐
    {"id": "b039_ev1940_0333", "translation": "「是、是的。所以决定明天让步梦小姐去取」"},
]

# 控制字符自检
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 显示宽度自检（全角=2 半角=1），budget 对照批次文件手工核定
budgets = {
    "b039_ev1940_0001": 37, "b039_ev1940_0004": 34, "b039_ev1940_0045": 31,
    "b039_ev1940_0050": 36, "b039_ev1940_0064": 39, "b039_ev1940_0121": 13,
    "b039_ev1940_0143": 53, "b039_ev1940_0160": 19, "b039_ev1940_0163": 16,
    "b039_ev1940_0178": 52, "b039_ev1940_0192": 32, "b039_ev1940_0194": 26,
    "b039_ev1940_0216": 23, "b039_ev1940_0224": 34, "b039_ev1940_0252": 16,
    "b039_ev1940_0276": 54, "b039_ev1940_0279": 70, "b039_ev1940_0305": 12,
    "b039_ev1940_0333": 44,
}
over = []
for p in patches:
    w = sum(1 if ord(c) < 128 else 2 for c in p["translation"])
    b = budgets[p["id"]]
    if w > b:
        over.append(f"{p['id']}: {w}>{b}")
if over:
    raise SystemExit("over budget: " + "; ".join(over))

json.dump({"patches": patches}, open(P, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width OK")
