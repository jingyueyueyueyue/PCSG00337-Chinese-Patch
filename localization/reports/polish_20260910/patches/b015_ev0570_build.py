# -*- coding: utf-8 -*-
# b015_ev0570 润色补丁构建脚本（2026-09-10）
import json

patches = [
    {"id": "b015_ev0570_0005", "translation": "（泡芙吗……）"},
    {"id": "b015_ev0570_0007", "translation": "（真的……太好了呢……）"},
    {"id": "b015_ev0570_0009", "translation": "（三谷君……没想起来啊……）"},
    {"id": "b015_ev0570_0020", "translation": "（奇怪……眼泪又渗出来了……）"},
    {"id": "b015_ev0570_0021", "translation": "（还有能遇见出色的人的学校……）"},
    {"id": "b015_ev0570_0027", "translation": "虽然很感兴趣，但问了不说，只好放弃。"},
    {"id": "b015_ev0570_0067", "translation": "「嗯。作为联谊会来说算是大成功」"},
    {"id": "b015_ev0570_0069", "translation": "「嗯，那软乎乎的手感真棒……对了，能再摸吗？」"},
    {"id": "b015_ev0570_0088", "translation": "「嘛，步梦虽然瞒着大家身份。朝冈在这种方面是不是管得挺松？」"},
    {"id": "b015_ev0570_0091", "translation": "所以才时不时想把那种长篇大论讲到最后吧。"},
    {"id": "b015_ev0570_0136", "translation": "摸摸强忍着的小男孩的头。"},
    {"id": "b015_ev0570_0137", "translation": "略显扫兴的奉莉迈步走了。"},
    {"id": "b015_ev0570_0198", "translation": "「嗯……就算真是那样也不用担心吧」"},
    {"id": "b015_ev0570_0204", "translation": "话虽如此，其实我想的和步梦一样。"},
    {"id": "b015_ev0570_0233", "translation": "说不定在真央酱眼里，这不算内衣姿态。"},
    {"id": "b015_ev0570_0236", "translation": "抱着体操服的步梦发现我，回过头来。"},
    {"id": "b015_ev0570_0241", "translation": "「……章介！」"},
    {"id": "b015_ev0570_0254", "translation": "「遗憾得很，我的内衣就是这样。不嫌弃的话，随意看吧」"},
    {"id": "b015_ev0570_0283", "translation": "「换衣服……怎么办？」"},
    {"id": "b015_ev0570_0288", "translation": "「我懂，但不妥吧？」"},
    {"id": "b015_ev0570_0292", "translation": "「等等……」"},
    {"id": "b015_ev0570_0295", "translation": "「是说我？」"},
    {"id": "b015_ev0570_0301", "translation": "慌忙别开视线，背对真央酱。"},
    {"id": "b015_ev0570_0303", "translation": "到底怎么了……"},
    {"id": "b015_ev0570_0306", "translation": "这是……束胸和四角裤……", "note": "新词:サラシ=束胸、トランクス=四角裤"},
    {"id": "b015_ev0570_0320", "translation": "总算注意到了……但现在可不能松懈。"},
    {"id": "b015_ev0570_0330", "translation": "明明是男的却比女生还迟钝，算怎么回事……"},
    {"id": "b015_ev0570_0334", "translation": "我是C组，先从握力测试开始吗……"},
    {"id": "b015_ev0570_0363", "translation": "更衣风波后，我们来到体育馆。"},
    {"id": "b015_ev0570_0366", "translation": "想着她们算正常代表，我望向反复横跳的拜田同学和步梦。"},
    {"id": "b015_ev0570_0396", "translation": "「顺序定好后，受测者躺在垫子上摆好规定姿势，辅助者要牢牢支撑住对方的脚」"},
    {"id": "b015_ev0570_0429", "translation": "「嗯，倒不是讨厌茂森同学……只是会被大家说闲话……」"},
    {"id": "b015_ev0570_0431", "translation": "「好，我来换」"},
]

# 控制字符自检
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 显示宽度自检（全角=2，半角=1），budget 取自批次文件对应行
budgets = {
    "b015_ev0570_0005": 22, "b015_ev0570_0007": 24, "b015_ev0570_0009": 29,
    "b015_ev0570_0020": 33, "b015_ev0570_0021": 33, "b015_ev0570_0027": 37,
    "b015_ev0570_0067": 34, "b015_ev0570_0069": 48,
    "b015_ev0570_0088": 61, "b015_ev0570_0091": 40, "b015_ev0570_0136": 25,
    "b015_ev0570_0137": 26, "b015_ev0570_0198": 34, "b015_ev0570_0204": 33,
    "b015_ev0570_0233": 39, "b015_ev0570_0236": 34, "b015_ev0570_0241": 15,
    "b015_ev0570_0254": 54, "b015_ev0570_0283": 22, "b015_ev0570_0288": 21,
    "b015_ev0570_0292": 13, "b015_ev0570_0295": 13, "b015_ev0570_0301": 32,
    "b015_ev0570_0303": 15, "b015_ev0570_0306": 29, "b015_ev0570_0320": 35,
    "b015_ev0570_0330": 41, "b015_ev0570_0334": 36, "b015_ev0570_0363": 30,
    "b015_ev0570_0366": 55, "b015_ev0570_0396": 79, "b015_ev0570_0429": 61,
    "b015_ev0570_0431": 16,
}

def width(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)

over = [(p["id"], width(p["translation"]), budgets[p["id"]])
        for p in patches if width(p["translation"]) > budgets[p["id"]]]
if over:
    raise SystemExit("too long: %r" % over)

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b015_ev0570.json", "w", encoding="utf-8"),
    ensure_ascii=False, indent=1,
)
print("patches:", len(patches))
