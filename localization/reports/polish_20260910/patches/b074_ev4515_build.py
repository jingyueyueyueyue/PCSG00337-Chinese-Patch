# -*- coding: utf-8 -*-
import json

patches = [
    {"id": "b074_ev4515_0033", "translation": "「魅、魅力……？」"},
    {"id": "b074_ev4515_0041", "translation": "「那我也直接叫希实花」"},
    {"id": "b074_ev4515_0071", "translation": "「三谷君对奉莉同学和步梦小姐不都直呼名字吗。所以……」", "note": "歩夢さん按词表译步梦小姐"},
    {"id": "b074_ev4515_0078", "translation": "「考私立初中，去了所没人认识小学时代的我的学校，这点三谷君也知道……」"},
    {"id": "b074_ev4515_0110", "translation": "「结、结果和三谷君重逢了，完全没人认识从前的我这一目标，还是没能达成……」"},
    {"id": "b074_ev4515_0112", "translation": "「虽然只能做这些，但别忘记。希实花不是一个人」"},
    {"id": "b074_ev4515_0121", "translation": "「那个……想、想起朴实花的事，果然，很讨厌……」"},
    {"id": "b074_ev4515_0142", "translation": "「简直像量身定做般的外号呢。我叫希实花，却被叫朴实花」"},
    {"id": "b074_ev4515_0185", "translation": "被奉莉一捅，踉跄了。"},
    {"id": "b074_ev4515_0194", "translation": "我拿不定主意，看向步梦他们。"},
    {"id": "b074_ev4515_0198", "translation": "希实花的过呼吸也没发作……"},
    {"id": "b074_ev4515_0205", "translation": "实际上，时间只够进行一次带细节调整的排练，就会用得一干二净。"},
    {"id": "b074_ev4515_0213", "translation": "和大道具组谈完，朝这边走来。"},
    {"id": "b074_ev4515_0214", "translation": "「我真的能满足于只是好朋友的关系吗？」"},
    {"id": "b074_ev4515_0215", "translation": "一看到她，除了她之外的一切都仿佛褪色消失。"},
    {"id": "b074_ev4515_0225", "translation": "「――已毫无疑问，我喜欢上老爷了……」", "note": "旦那様按词表译老爷"},
    {"id": "b074_ev4515_0227", "translation": "「……！那孩子和老爷……！」", "note": "旦那様按词表译老爷"},
    {"id": "b074_ev4515_0236", "translation": "「……不久，老爷和那孩子将结为夫妻……」", "note": "旦那様按词表译老爷"},
    {"id": "b074_ev4515_0246", "translation": "「目前勉强刚好压在60分钟以内。就算现在大刀阔斧地删减，说不定也行」"},
    {"id": "b074_ev4515_0260", "translation": "「正式演出当天的观众是二、三年级，必须赢到现在16倍以上的掌声，不能松懈」"},
    {"id": "b074_ev4515_0302", "translation": "「总之明天总排练能以万全状态迎接，太好了」"},
    {"id": "b074_ev4515_0324", "translation": "这里是主人公暗中目击背叛自己的上流阶级大小姐和自己主人约会的段落。"},
    {"id": "b074_ev4515_0335", "translation": "看上去四十来岁的女占卜师接过表格看了一遍，将手悬在水晶上。"},
    {"id": "b074_ev4515_0346", "translation": "希实花忽然压低声音。"},
    {"id": "b074_ev4515_0349", "translation": "能被希实花这么想，我很开心。"},
    {"id": "b074_ev4515_0353", "translation": "希实花一定会是可爱的妻子吧……"},
    {"id": "b074_ev4515_0366", "translation": "身旁希实花轻轻倒吸一口气。"},
    {"id": "b074_ev4515_0367", "translation": "希实花从旁边投来恳求般的目光。"},
    {"id": "b074_ev4515_0381", "translation": "「那……和步梦小姐呢？」", "note": "歩夢さん按词表译步梦小姐"},
    {"id": "b074_ev4515_0417", "translation": "「彼此相恋的两个人……吗」"},
    {"id": "b074_ev4515_0418", "translation": "「啊，三谷君一脸遗憾了吗？」"},
    {"id": "b074_ev4515_0437", "translation": "「和爸爸或亲戚以外的男性这样单独走路，还是第一次……」"},
]

budgets = {
    "b074_ev4515_0033": 18,
    "b074_ev4515_0041": 24,
    "b074_ev4515_0071": 55,
    "b074_ev4515_0078": 79,
    "b074_ev4515_0110": 81,
    "b074_ev4515_0112": 46,
    "b074_ev4515_0121": 52,
    "b074_ev4515_0142": 60,
    "b074_ev4515_0185": 21,
    "b074_ev4515_0194": 29,
    "b074_ev4515_0198": 26,
    "b074_ev4515_0205": 75,
    "b074_ev4515_0213": 30,
    "b074_ev4515_0214": 38,
    "b074_ev4515_0215": 53,
    "b074_ev4515_0225": 42,
    "b074_ev4515_0227": 29,
    "b074_ev4515_0236": 40,
    "b074_ev4515_0246": 67,
    "b074_ev4515_0260": 75,
    "b074_ev4515_0302": 45,
    "b074_ev4515_0324": 80,
    "b074_ev4515_0335": 68,
    "b074_ev4515_0346": 20,
    "b074_ev4515_0349": 28,
    "b074_ev4515_0353": 30,
    "b074_ev4515_0366": 27,
    "b074_ev4515_0367": 34,
    "b074_ev4515_0381": 26,
    "b074_ev4515_0417": 31,
    "b074_ev4515_0418": 28,
    "b074_ev4515_0437": 58,
}

def width(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

missing = [p["id"] for p in patches if p["id"] not in budgets]
if missing:
    raise SystemExit("no budget for: %r" % missing)

over = [(p["id"], width(p["translation"]), budgets[p["id"]]) for p in patches if width(p["translation"]) > budgets[p["id"]]]
if over:
    raise SystemExit("too long: %r" % over)

json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b074_ev4515.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
