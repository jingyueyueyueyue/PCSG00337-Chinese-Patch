# -*- coding: utf-8 -*-
import csv
import json

TSV = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b027_ev1390.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b027_ev1390.json"

budgets = {}
with open(TSV, encoding="utf-8", newline="") as f:
    for row in csv.reader(f, delimiter="\t"):
        if row and row[0].startswith("b027_ev1390_"):
            budgets[row[0]] = int(row[4])


def width(s):
    return sum(2 if ord(c) >= 0x80 else 1 for c in s)


patches = [
    {"id": "b027_ev1390_0001", "translation": "向大家轻轻道了个歉，离开了现场。"},
    {"id": "b027_ev1390_0004", "translation": "问卷调查结果要是不好，别说夺冠，说不定连进前列都进不去。"},
    {"id": "b027_ev1390_0016", "translation": "确实如章介所说。"},
    {"id": "b027_ev1390_0029", "translation": "作为社团组进了应援组的同学过来搭话。"},
    {"id": "b027_ev1390_0032", "translation": "「横山君，怎么了？」"},
    {"id": "b027_ev1390_0068", "translation": "「前一天布置和当天一起加油」"},
    {"id": "b027_ev1390_0073", "translation": "「说好是不会吃撑的量，一份是平常的七成左右？」"},
    {"id": "b027_ev1390_0074", "translation": "「陆斗。你打算把吧台设在哪里？」"},
    {"id": "b027_ev1390_0082", "translation": "「听着陆斗，一个人进店的客人图的是什么？」"},
    {"id": "b027_ev1390_0083", "translation": "「不是，我真在反省了……慈善义卖会我会拼死干活给你看的，哈哈哈哈！」"},
    {"id": "b027_ev1390_0090", "translation": "「呃，现在稍微插句话行吗？」"},
    {"id": "b027_ev1390_0093", "translation": "「那，差不多开始吧？」"},
    {"id": "b027_ev1390_0094", "translation": "「呃，就是说会变成背对客人对吧？」"},
    {"id": "b027_ev1390_0101", "translation": "「是这样，但每份量要比平常少点对吧？」"},
    {"id": "b027_ev1390_0104", "translation": "「既然懂为什么还提议靠墙？冲女仆来的客人看墙会满意吗？」"},
    {"id": "b027_ev1390_0108", "translation": "「那个……是来看女仆吗？」"},
    {"id": "b027_ev1390_0116", "translation": "「喂喂，陆斗～！！」"},
    {"id": "b027_ev1390_0132", "translation": "只是一时鬼迷心窍……"},
    {"id": "b027_ev1390_0150", "translation": "怎么看都是女孩啊，步梦！"},
    {"id": "b027_ev1390_0163", "translation": "一只黑得发亮的大蟑螂，正一动不动地潜伏着窥探这边的动静。"},
    {"id": "b027_ev1390_0165", "translation": "慈善义卖会的讨论比预想花了更长时间。"},
    {"id": "b027_ev1390_0175", "translation": "全都换完后，才发觉口渴。"},
    {"id": "b027_ev1390_0177", "translation": "是男是女？"},
    {"id": "b027_ev1390_0188", "translation": "「怎、怎么？」"},
    {"id": "b027_ev1390_0190", "translation": "「……真的吗？」"},
    {"id": "b027_ev1390_0192", "translation": "「哥、哥哥？」"},
    {"id": "b027_ev1390_0196", "translation": "「那、那……我去那边了……」"},
    {"id": "b027_ev1390_0199", "translation": "「出了啥？」"},
    {"id": "b027_ev1390_0201", "translation": "「抱歉我是下流哥哥……嘻？」"},
    {"id": "b027_ev1390_0203", "translation": "「真……真的……？」"},
    {"id": "b027_ev1390_0208", "translation": "「让你看到奇怪打扮……抱歉」"},
    {"id": "b027_ev1390_0218", "translation": "「啊啊，它过来了啊！」"},
    {"id": "b027_ev1390_0223", "translation": "「明明是男的……穿女孩内衣……」"},
    {"id": "b027_ev1390_0230", "translation": "「呀啊啊啊啊！！」"},
    {"id": "b027_ev1390_0240", "translation": "「真是……这样又会感冒哦？」"},
    {"id": "b027_ev1390_0244", "translation": "咦？还是说瞒着其实是女孩之类的事……？"},
    {"id": "b027_ev1390_0246", "translation": "盯着看了半天，被说了句哥哥真下流……"},
    {"id": "b027_ev1390_0248", "translation": "不，不对……毕竟步梦的内衣姿态看起来就是完美女孩……"},
    {"id": "b027_ev1390_0259", "translation": "连点接缝似的都没有……"},
    {"id": "b027_ev1390_0264", "translation": "不，步梦是男的！！"},
    {"id": "b027_ev1390_0272", "translation": "嘛，多少意识到自己有那种想法……"},
    {"id": "b027_ev1390_0289", "translation": "「那，陆斗君」"},
    {"id": "b027_ev1390_0291", "translation": "「……千万、千万别对步梦君抱有奇怪的想法」"},
    {"id": "b027_ev1390_0296", "translation": "「那么陆斗君，再问一次，步梦的内衣怎么样？」"},
    {"id": "b027_ev1390_0298", "translation": "「心跳了？还是被『哇，变态！』吓到？」"},
    {"id": "b027_ev1390_0300", "translation": "「不说我也知道！」"},
    {"id": "b027_ev1390_0301", "translation": "「我在问陆斗君！」"},
    {"id": "b027_ev1390_0306", "translation": "「没被陆斗君当成变态」"},
    {"id": "b027_ev1390_0316", "translation": "「突然搞什么，一直闷着的步梦就继续安静待着」"},
    {"id": "b027_ev1390_0317", "translation": "「陆斗君，回答嘛」"},
    {"id": "b027_ev1390_0328", "translation": "果然步梦的脸眼看着阴了下去……"},
    {"id": "b027_ev1390_0334", "translation": "晚饭后我尽量不去在意，对话也能正常进行了……可被这么来个措手不及……"},
    {"id": "b027_ev1390_0346", "translation": "「换衣时偷看了你，抱歉」", "note": "依0341语义，道歉主体为陆斗"},
    {"id": "b027_ev1390_0351", "translation": "「哥哥，别道歉……啊！？」"},
]

bad_ctrl = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"] or "\r" in p["translation"]]
if bad_ctrl:
    raise SystemExit("control chars in: %r" % bad_ctrl)

unknown = [p["id"] for p in patches if p["id"] not in budgets]
if unknown:
    raise SystemExit("unknown ids: %r" % unknown)

too_long = [(p["id"], width(p["translation"]), budgets[p["id"]])
            for p in patches if width(p["translation"]) > budgets[p["id"]]]
if too_long:
    raise SystemExit("too_long: %r" % too_long)

with open(OUT, "w", encoding="utf-8") as f:
    json.dump({"patches": patches}, f, ensure_ascii=False, indent=1)
print("patches:", len(patches))
