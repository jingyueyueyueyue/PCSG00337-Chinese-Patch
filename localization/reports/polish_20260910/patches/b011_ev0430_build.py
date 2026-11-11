# -*- coding: utf-8 -*-
"""b011_ev0430 润色补丁构建脚本（2026-09-10 校对）"""
import json

def w(s):
    # 显示宽度：全角=2，半角=1
    return sum(2 if ord(c) > 0x2E7F or c in "，。！？…「」『』（）：；～—、【】" else 1 for c in s)

patches = [
    {"id": "b011_ev0430_0001", "translation": "……比想象中可爱多了？"},
    {"id": "b011_ev0430_0018", "translation": "轮到我们办手续了。"},
    {"id": "b011_ev0430_0038", "translation": "奉莉，你对拜田做了什么？", "note": "省略号因预算省略"},
    {"id": "b011_ev0430_0051", "translation": "怎样", "note": "预算紧，压为两字"},
    {"id": "b011_ev0430_0060", "translation": "兄妹……还同年级？"},
    {"id": "b011_ev0430_0071", "translation": "奉莉那边的队伍长好多呢"},
    {"id": "b011_ev0430_0072", "translation": "蓄势待发，轮到我闪亮登场！"},
    {"id": "b011_ev0430_0083", "translation": "呃……前台是按五十音顺序排的……"},
    {"id": "b011_ev0430_0086", "translation": "久等啦！！", "note": ""},
    {"id": "b011_ev0430_0087", "translation": "请、请、请多、多指教……"},
    {"id": "b011_ev0430_0089", "translation": "这位是拜田希实花，这位是横山章介。都是我在入学准备说明会上混熟的"},
    {"id": "b011_ev0430_0094", "translation": "说是三谷，那你们俩是什么关系……？"},
    {"id": "b011_ev0430_0103", "translation": "是！！", "note": ""},
    {"id": "b011_ev0430_0111", "translation": "预备——起！"},
    {"id": "b011_ev0430_0113", "translation": "了解～", "note": ""},
    {"id": "b011_ev0430_0117", "translation": "嗯？啥？"},
    {"id": "b011_ev0430_0126", "translation": "而奉莉半拖半拽带过来的却是——"},
    {"id": "b011_ev0430_0156", "translation": "察觉？", "note": ""},
    {"id": "b011_ev0430_0172", "translation": "照上下文就剩一两句了！"},
    {"id": "b011_ev0430_0187", "translation": "今、今后的三年……还、还要承蒙大、大家很多帮助……"},
    {"id": "b011_ev0430_0190", "translation": "时、时而严厉……时、时而温柔地守护我们……"},
    {"id": "b011_ev0430_0191", "translation": "愿各位从这学园毕业之时，能说自己这三年度过得充实，谨以此权当贺词"},
    {"id": "b011_ev0430_0195", "translation": "不……试试看吧……"},
    {"id": "b011_ev0430_0250", "translation": "女生A"},
    {"id": "b011_ev0430_0254", "translation": "男生A"},
    {"id": "b011_ev0430_0255", "translation": "男生B"},
    {"id": "b011_ev0430_0256", "translation": "入学典礼前在别的房间等候时知道的，大家都没忍住笑了……"},
    {"id": "b011_ev0430_0274", "translation": "兄妹！？", "note": ""},
    {"id": "b011_ev0430_0278", "translation": "还是新生代表……"},
    {"id": "b011_ev0430_0281", "translation": "入学准备说明会上也说过，我像各位所见，冒失又慌张。没有能挺起胸膛担任班主任的资历和实力"},
    {"id": "b011_ev0430_0282", "translation": "我叫拜田、希实花……那、那个……请、请多、多指教……"},
    {"id": "b011_ev0430_0283", "translation": "痛痛痛痛……"},
    {"id": "b011_ev0430_0294", "translation": "噗！？", "note": ""},
    {"id": "b011_ev0430_0295", "translation": "哦……等等！？啊哈哈，不是干这个的时候"},
    {"id": "b011_ev0430_0296", "translation": "先从男生开始……顺序就按出席编号来……那，第一位是爱泽大辉同学"},
    {"id": "b011_ev0430_0297", "translation": "大家——早上好——！！"},
    {"id": "b011_ev0430_0298", "translation": "嘿……哈！", "note": ""},
    {"id": "b011_ev0430_0301", "translation": "嗯——！怎样？很强吧？", "note": ""},
    {"id": "b011_ev0430_0305", "translation": "肯定是不合心意的自我介绍吧。"},
    {"id": "b011_ev0430_0310", "translation": "那、那个前倾的姿势有点……乳沟……"},
    {"id": "b011_ev0430_0363", "translation": "我没有违抗老师的话，从座位上站了起来。"},
    {"id": "b011_ev0430_0365", "translation": "见没人反应，我便瞟了眼奉莉。"},
    {"id": "b011_ev0430_0366", "translation": "男生C"},
    {"id": "b011_ev0430_0371", "translation": "确认奉莉的情况"},
    {"id": "b011_ev0430_0394", "translation": "看来是定了"},
    {"id": "b011_ev0430_0423", "translation": "对吧，三谷也这么想……欸？"},
    {"id": "b011_ev0430_0432", "translation": "那么，要自荐活动执行委员的人——！"},
    {"id": "b011_ev0430_0435", "translation": "好，我来！", "note": "预算所限压平长音"},
    {"id": "b011_ev0430_0438", "translation": "咦！？", "note": ""},
    {"id": "b011_ev0430_0439", "translation": "三、三谷……"},
    {"id": "b011_ev0430_0440", "translation": "不用猜就是自荐"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 预算自检（按批次文件中的 budget 上限）
budgets = {
    "b011_ev0430_0001": 23, "b011_ev0430_0018": 18, "b011_ev0430_0038": 24,
    "b011_ev0430_0051": 6, "b011_ev0430_0060": 21, "b011_ev0430_0071": 26,
    "b011_ev0430_0072": 26, "b011_ev0430_0083": 32, "b011_ev0430_0086": 11,
    "b011_ev0430_0087": 25, "b011_ev0430_0089": 74, "b011_ev0430_0094": 39,
    "b011_ev0430_0103": 7, "b011_ev0430_0111": 13, "b011_ev0430_0113": 7,
    "b011_ev0430_0117": 8, "b011_ev0430_0126": 30, "b011_ev0430_0156": 7,
    "b011_ev0430_0172": 23, "b011_ev0430_0187": 57, "b011_ev0430_0190": 47,
    "b011_ev0430_0191": 85, "b011_ev0430_0195": 18, "b011_ev0430_0250": 5,
    "b011_ev0430_0254": 5, "b011_ev0430_0255": 5, "b011_ev0430_0256": 56,
    "b011_ev0430_0274": 9, "b011_ev0430_0278": 18, "b011_ev0430_0281": 88,
    "b011_ev0430_0282": 58, "b011_ev0430_0283": 12, "b011_ev0430_0294": 8,
    "b011_ev0430_0295": 41, "b011_ev0430_0296": 63, "b011_ev0430_0297": 23,
    "b011_ev0430_0298": 11, "b011_ev0430_0301": 22, "b011_ev0430_0305": 29,
    "b011_ev0430_0310": 36, "b011_ev0430_0363": 47, "b011_ev0430_0365": 34,
    "b011_ev0430_0366": 5, "b011_ev0430_0371": 20, "b011_ev0430_0394": 11,
    "b011_ev0430_0423": 27, "b011_ev0430_0432": 40, "b011_ev0430_0435": 11,
    "b011_ev0430_0438": 6, "b011_ev0430_0439": 14, "b011_ev0430_0440": 16,
}
over = []
for p in patches:
    b = budgets.get(p["id"])
    if b is None:
        over.append((p["id"], "no budget on record"))
        continue
    width = w(p["translation"])
    if width > b:
        over.append((p["id"], width, b))
if over:
    raise SystemExit("too_long: %r" % over)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b011_ev0430.json", "w", encoding="utf-8"),
    ensure_ascii=False, indent=1,
)
print("patches:", len(patches))
print("width self-check OK")
