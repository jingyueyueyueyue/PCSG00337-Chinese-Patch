# -*- coding: utf-8 -*-
"""b035_ev1770 润色补丁构建脚本（2026-09-10）"""
import json

patches = [
    # 补"確実に"（确实）
    {"id": "b035_ev1770_0007", "translation": "可刚才步梦确实一脸凶相……"},
    # "激しく戸惑う"生硬直译改为通顺表达
    {"id": "b035_ev1770_0032", "translation": "就在步梦慌乱不已时，导演朝这边走来。"},
    # 补"たっての"（特意）
    {"id": "b035_ev1770_0040", "translation": "良子小姐特意拜托，实在没法拒绝。"},
    # 良子さん→良子小姐（词表统一）因 budget=11 放弃：恢复初翻（问号也放不下）
    {"id": "b035_ev1770_0092", "translation": "「良子吗」", "note": "预算紧省略问号；良子さん拟统一良子小姐，但预算放不下"},
    # 补"できるかな?"疑问语气
    {"id": "b035_ev1770_0112", "translation": "「嗯、嗯……吃醋吗？做得来吗」", "note": ""},
    # "してないよ?"否认语气更自然
    {"id": "b035_ev1770_0138", "translation": "「才没？」"},
    # "されたし"无奈语气补"都"
    {"id": "b035_ev1770_0140", "translation": "「也是……不过良子小姐都拜托了……」"},
    # 补"わ、わたしも"口吃与"ホントに、"停顿
    {"id": "b035_ev1770_0194", "translation": "「我、我也……最喜欢了……真的、最喜欢……」"},
    # "进入不高兴模式的呢"拗口，理顺
    {"id": "b035_ev1770_0204", "translation": "到底是什么契机会让步梦进入不高兴模式……？"},
    # "胜任大任"用词重复，改"挑大梁"（对应"大役"）
    {"id": "b035_ev1770_0209", "translation": "这么僵硬的两个人，真能挑起大梁吗……？"},
    # 恢复句末省略号（budget 允许）
    {"id": "b035_ev1770_0279", "translation": "「太好了……」"},
    # 原译双重否定"并不是不……就会"拗口，改写为等义通顺句
    {"id": "b035_ev1770_0303", "translation": "让我想答案，就说明事情还没到不马上处理就不行的地步吧。"},
    # 补"じ、実は"口吃
    {"id": "b035_ev1770_0313", "translation": "「其、其实，我和步梦……当了那剧的群演」"},
    # 补"役"（演），原译"就、恋人"漏译角色含义
    {"id": "b035_ev1770_0316", "translation": "「就……演恋人……」"},
    # "俺が……気づく?"补"要"，问句指向更明确
    {"id": "b035_ev1770_0327", "translation": "「要我察觉？」"},
    # 补"い、いや"否认语气
    {"id": "b035_ev1770_0338", "translation": "「不……因为……」"},
    # 补"役"（演），并还原"ええと"语气词
    {"id": "b035_ev1770_0345", "translation": "「呃……演恋人……」"},
    # 补"で"承接
    {"id": "b035_ev1770_0351", "translation": "「这样啊……那演什么角色？」"},
    # 补"は、恥ずかしいよ"口吃
    {"id": "b035_ev1770_0357", "translation": "「害、害羞死了……和哥哥演恋人……」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)
json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b035_ev1770.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
