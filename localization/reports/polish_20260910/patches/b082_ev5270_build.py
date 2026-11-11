# -*- coding: utf-8 -*-
import json

patches = [
    # 0014: 补回「す、少し」的结巴语气，顺一下语序
    {"id": "b082_ev5270_0014", "translation": "「……是，是贴太近了吧？」"},
    # 0035: 「没时间没坐上」双「没」读着像笔误，理顺
    {"id": "b082_ev5270_0035", "translation": "「初中毕业远足时没时间坐上，这次绝对要坐那个！」"},
    # 0039: 原译 48>46 超宽，压缩到预算内
    {"id": "b082_ev5270_0039", "translation": "「害怕的话看前面，那样和普通摩天轮差不多」", "note": "原译超宽，压缩措辞"},
    # 0087: 预算允许，补全「吸——呼——」四次呼吸
    {"id": "b082_ev5270_0087", "translation": "「是、是……吸——呼——吸——呼——……」"},
    # 0093: budget=5，「咿」带引号宽 6 超限，仿 0070 省略「」
    {"id": "b082_ev5270_0093", "translation": "咿", "note": "预算≤5，省略「」"},
    # 0136: 「对……很高兴」不通顺，理顺
    {"id": "b082_ev5270_0136", "translation": "「好像特别喜欢步梦小姐的便当呢」"},
    # 0146: ev5275 是回程电车，降りる=下车，补明确
    {"id": "b082_ev5270_0146", "translation": "「这次轮到我们下车了呢」"},
    # 0155: 误译，ev5275 回程电车语境下降りる指下车而非轿厢下降
    {"id": "b082_ev5270_0155", "translation": "然后，下车时——"},
    # 0176: 聞けない=问不出口（对应 0160「问陆斗能明白吗」）
    {"id": "b082_ev5270_0176", "translation": "（不……问不出口）"},
    # 0178: 「X，真的感激」倒装生硬，改为独白语序
    {"id": "b082_ev5270_0178", "translation": "（真的很感谢让我意识到这点的陆斗）"},
    # 0191: 「怎么」→「怎么了」，语气自然
    {"id": "b082_ev5270_0191", "translation": "「……怎么了，真央酱」"},
    # 0192: 补回原文句末「?」
    {"id": "b082_ev5270_0192", "translation": "「女仆咖啡店……行吗？」"},
    # 0197: 原译 30>28 超宽，压缩到预算内
    {"id": "b082_ev5270_0197", "translation": "「夺冠的话樱花祭就单独第一」", "note": "原译超宽，压缩措辞"},
    # 0235: 原译丢了「わからないの?」的反问调侃语气，预算内补回
    {"id": "b082_ev5270_0235", "translation": "「真央酱是为陆斗才肯做的，没发现？」"},
    # 0251: 该行预算极紧，原文「?」压宽维持省略，维持初翻
    {"id": "b082_ev5270_0251", "translation": "「说错什么了」"},
    # 0261: 「就当结果还好吧」生硬，理顺；源行为独白，不加「」
    {"id": "b082_ev5270_0261", "translation": "不过结果好，就这样吧。"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b082_ev5270.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
