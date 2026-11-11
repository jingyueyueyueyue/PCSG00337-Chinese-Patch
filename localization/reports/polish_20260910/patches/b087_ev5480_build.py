# -*- coding: utf-8 -*-
"""b087_ev5480 润色补丁构建脚本（自带控制符与显示宽度自检）"""
import json

# id -> (budget, new_translation, note_or_None)
patches_map = {
    # 主语误译：受けてくれた 的施动者是替真央接下老爷子比试的人（下文「尤其是对陆斗」），不是老爷子本人
    "b087_ev5480_0007": (43, "（明知没有胜算，还是接下了老爷子的比试）", None),
    # 陸斗には：补出「对」的指向
    "b087_ev5480_0009": (21, "（尤其是对陆斗……）", None),
    # 与 0022 贯口措辞统一为「变成女孩子的方法」
    "b087_ev5480_0047": (45, "「……啊，是说真央酱明显变成女孩子的方法？」", None),
    # 补「一起」，句子更顺
    "b087_ev5480_0056": (35, "「别急。午休再连同真央酱一起说明」", None),
    # 恢复い、いきなり的断续语气
    "b087_ev5480_0062": (17, "「拍、拍什么？」", ""),
    # 补やっぱり（果然）
    "b087_ev5480_0072": (37, "「诶？啊，陆斗和真央酱果然感情很好」", None),
    # 恢复す、すまん的断续语气
    "b087_ev5480_0078": (48, "「对、对不住，看到稀罕东西就会条件反射按快门」", None),
    # 补どうだい（如何）；实际预算 31，压缩为「我当练习台」
    "b087_ev5480_0123": (31, "「……女士，我当练习台如何？」", None),
    # 女の子以外→除了女孩，语法更顺
    "b087_ev5480_0141": (47, "「除了女孩也有人能行……现在说这个无关，嗯」", None),
    # いるから：真央续句「因为你在我身边」，按「有你在」处理
    "b087_ev5480_0144": (13, "「有你在呢」", "存疑：「いる」主语两可，按真央续句「有你在」处理"),
    # 恢复そ、そう言われても的断续语气
    "b087_ev5480_0156": (36, "「就、就算这么说……我……恋爱……」", None),
    # から因果语序理顺；末尾あるの……迟疑尾音按语气并入
    "b087_ev5480_0207": (74, "「其实，男装和内衣全被老爷子没收了，所以得去买女装……嗯……」",
                          "原文末「あるの……」为迟疑尾音，按语气并入"),
    # 实际预算 25，问号加不进；回退为初翻（初翻宽度 24 合规）
    "b087_ev5480_0209": (25, "「真央酱，提个要求好吗」", None),
    # 恋人らしいこと→恋人该做的事
    "b087_ev5480_0212": (42, "「两人好好想，把恋人该做的事一件件做就好」", None),
    # 恢复ど、どうかな的断续语气
    "b087_ev5480_0294": (18, "「如、如何……？」", ""),
    # 今の服=现在身上这件，非「刚才那件」
    "b087_ev5480_0300": (22, "「我更喜欢现在这件？」", None),
}

def width(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)

patches = []
bad = []
for pid, (budget, trn, note) in patches_map.items():
    if "\t" in trn or "\n" in trn or "\r" in trn:
        bad.append((pid, "control char"))
        continue
    w = width(trn)
    if w > budget:
        bad.append((pid, "width %d > %d" % (w, budget)))
        continue
    p = {"id": pid, "translation": trn}
    if note is not None:
        p["note"] = note
    patches.append(p)

if bad:
    for pid, why in bad:
        print("BAD:", pid, why)
    raise SystemExit("patch self-check failed")

out = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b087_ev5480.json"
json.dump({"batch": "b087_ev5480", "patches": patches}, open(out, "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("patches:", len(patches))
