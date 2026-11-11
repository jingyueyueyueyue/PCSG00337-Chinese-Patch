# -*- coding: utf-8 -*-
import json, unicodedata

patches = [
    {"id": "b075_ev4545_0039", "translation": "「……嗯。你想怎么叫都行」"},
    {"id": "b075_ev4545_0040", "translation": "「……那个，朴实花这个外号初中时代也有，我说过吧？」"},
    {"id": "b075_ev4545_0048", "translation": "「那个……三谷君，我可以直接叫你的名字吗……？」"},
    {"id": "b075_ev4545_0062", "translation": "「咦，下一首没放出来……三谷君怎么了？不点自己的歌吗？」"},
    {"id": "b075_ev4545_0079", "translation": "「那，那是因为放松状态下才唱得出来。换成三谷君以外的人在，我肯定会怯场」"},
    {"id": "b075_ev4545_0085", "translation": "「没错，重要的不是被人爱，而是去爱人。这点我感受得刻骨铭心」"},
    {"id": "b075_ev4545_0087", "translation": "「来到朝冈学园……遇见了奉莉同学、步梦小姐、真央同学、横山君和班上大家……」"},
    {"id": "b075_ev4545_0089", "translation": "「那个……下次想和三谷君合唱」"},
    {"id": "b075_ev4545_0097", "translation": "「是。本来想着要是三谷君来听……结果发现果然没问题」"},
    {"id": "b075_ev4545_0098", "translation": "「是。我想和三谷君一起唱」"},
    {"id": "b075_ev4545_0099", "translation": "「即，就算有别人在，我也想叫陆斗君。那，可以吗？」"},
    {"id": "b075_ev4545_0126", "translation": "（紧紧地，和三谷君……不，和陆斗君牵手……）"},
    {"id": "b075_ev4545_0130", "translation": "（等、等下，太……）"},
    {"id": "b075_ev4545_0132", "translation": "「怎么办……今晚可能睡不着……」"},
    {"id": "b075_ev4545_0137", "translation": "把舞台使用权交给别的班，回到教室后，希实花面对全班同学开口说话。"},
    {"id": "b075_ev4545_0152", "translation": "事先和希实花对过流程的音响、灯光组，也几乎一遍就入了戏。"},
    {"id": "b075_ev4545_0159", "translation": "奉莉走路时一直护着左脚……"},
    {"id": "b075_ev4545_0163", "translation": "「――嗯。刚才还有点疼，不过已经退下去了」"},
    {"id": "b075_ev4545_0166", "translation": "「抱歉。但真的没什么……」"},
    {"id": "b075_ev4545_0167", "translation": "「抱歉，没事的」"},
    {"id": "b075_ev4545_0175", "translation": "「完美……！」"},
    {"id": "b075_ev4545_0184", "translation": "「请说实话，奉莉同学……！」"},
    {"id": "b075_ev4545_0207", "translation": "「别突然站起来」"},
    {"id": "b075_ev4545_0212", "translation": "「嗯。之后过呼吸完全没再犯」"},
    {"id": "b075_ev4545_0214", "translation": "「都这步了还能NG？一瞬间还想过」"},
    {"id": "b075_ev4545_0219", "translation": "「奈奈濑！？」", "note": "预算紧"},
    {"id": "b075_ev4545_0224", "translation": "「看，完全没事吧？」"},
    {"id": "b075_ev4545_0250", "translation": "我也明白，就连我也说不出「好啊，主角就交给希实花吧」。"},
    {"id": "b075_ev4545_0256", "translation": "希实花说了什么、自己被说了什么，大家一时没能消化。"},
    {"id": "b075_ev4545_0264", "translation": "露出笑容，鼓起掌。"},
    {"id": "b075_ev4545_0277", "translation": "第一条条件，也是大前提：奉莉角色的台词和演技全都了然于心。"},
    {"id": "b075_ev4545_0282", "translation": "「――那个。有事必须告诉大家」"},
    {"id": "b075_ev4545_0291", "translation": "「毫无彩排直接上场是事实。与其他演员的配合也定有偏差」"},
    {"id": "b075_ev4545_0292", "translation": "「通过担任委员长，我感觉自己终于能够坚定地做自己了。现在的我一定没问题！」"},
    {"id": "b075_ev4545_0294", "translation": "「过呼吸一次都没复发，大家都清楚。没问题，我能演」"},
    {"id": "b075_ev4545_0311", "translation": "「没事吗？过呼吸……」"},
    {"id": "b075_ev4545_0313", "translation": "「奈奈濑怎么了？」", "note": "预算紧，省略同学"},
    {"id": "b075_ev4545_0326", "translation": "「再次一起夺总冠军吧！」"},
    {"id": "b075_ev4545_0333", "translation": "「诶？受伤是怎么回事？」"},
    {"id": "b075_ev4545_0334", "translation": "「诶……！？那种状态还能演！？」"},
    {"id": "b075_ev4545_0352", "translation": "「确实，能行的只有拜田同学……」"},
    {"id": "b075_ev4545_0355", "translation": "「好。――接力棒交给你了，希实花。拜托了」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：与官方校验器一致——非 ASCII 字符一律按宽度 2，ASCII 按 1
def disp_width(s):
    w = 0
    for ch in s:
        w += 1 if ord(ch) < 128 else 2
    return w

budgets = {}
with open(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b075_ev4545.tsv", encoding="utf-8") as f:
    header = next(f)
    for line in f:
        cols = line.rstrip("\n").split("\t")
        if len(cols) >= 6:
            budgets[cols[0]] = int(cols[4])

over = []
for p in patches:
    b = budgets.get(p["id"])
    if b is None:
        raise SystemExit("unknown id: %s" % p["id"])
    w = disp_width(p["translation"])
    if w > b:
        over.append((p["id"], w, b))
if over:
    raise SystemExit("too long: %r" % over)

json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b075_ev4545.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
