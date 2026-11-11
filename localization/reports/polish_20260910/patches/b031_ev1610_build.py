# -*- coding: utf-8 -*-
"""b031_ev1610 润色补丁构建脚本（2026-09-10）"""
import json

patches = [
    # 误译：頑<ruby>な</ruby>（かたく）＝固执，原译"这么拼"偏离词义
    {"id": "b031_ev1610_0004", "translation": "为什么这么固执呢？",
     "note": "頑な（かたく）＝固执，修正误译；删ruby"},
    # 恢复源文句首省略号（预算内放得下）
    {"id": "b031_ev1610_0035", "translation": "「……那、那我就稍微休息一下啦」"},
    # 补"もしかして"（难道）语义
    {"id": "b031_ev1610_0041", "translation": "「因、因为……难道露馅——」"},
    # 消除"顶替去休息"的主语歧义（休息的是陆斗）
    {"id": "b031_ev1610_0060", "translation": "「我接下来要跟拜田同学换班去休息。所以步梦你也马上休息」"},
    # 遠慮＝不好意思开口，原译"没敢开口"语气偏差
    {"id": "b031_ev1610_0073", "translation": "「因为步梦忙，千里酱才不好意思开口」"},
    # 词表规则：Xくん→X君
    {"id": "b031_ev1610_0082", "translation": "「三谷君的熟人？」", "note": "词表：Xくん→X君"},
    # 校验器实际限宽 20，恢复省略号会超宽，维持初翻
    {"id": "b031_ev1610_0092", "translation": "「啊……嘛，还行吧」", "note": "预算过紧"},
    # 校验器实际限宽 14，补逗号会超宽，维持初翻
    {"id": "b031_ev1610_0132", "translation": "「这样啊谢啦」", "note": "预算过紧"},
    # 语句更通顺
    {"id": "b031_ev1610_0133", "translation": "「是嘛……那我告诉你件看到小步想起的事」"},
    # 词表：歩夢さん→步梦小姐（希实花对步梦的称呼）
    {"id": "b031_ev1610_0138", "translation": "「这样啊……那接待就和步梦小姐换班吧」",
     "note": "词表：歩夢さん→步梦小姐"},
    # 词表规则：Xくん→X君
    {"id": "b031_ev1610_0159", "translation": "「三谷君」", "note": "词表：Xくん→X君"},
    # かな？疑问语气补回
    {"id": "b031_ev1610_0178", "translation": "「差不多吧？」"},
    # 叙述句，去掉误加的「」
    {"id": "b031_ev1610_0200", "translation": "章介的话有些地方让人摸不着头脑，但就不深究了。"},
    # 词表规则：Xくん→X君
    {"id": "b031_ev1610_0266", "translation": "「辛苦了三谷君」", "note": "词表：Xくん→X君"},
    # 内心独白（叙述），去引号并补句号
    {"id": "b031_ev1610_0298", "translation": "……不，还是别想这些了。",
     "note": "叙述句去引号并补句号"},
    # 补"是"，语句更自然
    {"id": "b031_ev1610_0318", "translation": "「……不愧是小直，超好吃的～」"},
    # 补そ、的结巴语气（预算内放得下）
    {"id": "b031_ev1610_0406", "translation": "那、那不妙吧……？"},
    # 作っている＝正在做，原译"会做晚饭"语义偏差
    {"id": "b031_ev1610_0413", "translation": "没想到爸爸居然在做晚饭。"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)
json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b031_ev1610.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
