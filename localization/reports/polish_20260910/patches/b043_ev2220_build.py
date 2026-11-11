# -*- coding: utf-8 -*-
"""b043_ev2220 润色补丁构建脚本（含宽度自检）"""
import json

# {id: (budget, new_translation, note)}  note 为 None 时保持原 note 不变
patches_map = {
    "b043_ev2220_0002": (18, "……完全不差嘛。", "全然ダメじゃない为双重否定，译作不差"),
    "b043_ev2220_0009": (36, "不过，我俩的关系已正式告诉奉莉了。", None),
    "b043_ev2220_0015": (12, "确实如此……", None),
    "b043_ev2220_0080": (37, "「因为……梦中哥哥，是我的初恋嘛」", None),
    "b043_ev2220_0088": (41, "「可是，才住了一个月左右……好神奇……」", None),
    "b043_ev2220_0105": (23, "「有点怪，但确实好吃」", None),
    "b043_ev2220_0110": (69, "「延误大概两周，我们也考虑过住周租公寓……」", None),
    "b043_ev2220_0156": (56, "「嗯。希望陆斗君和步梦尽量变得要好，才安排两人同住一间」", None),
    "b043_ev2220_0180": (48, "「是啊。活蹦乱跳的步梦就这样回家了嘛……」", None),
    "b043_ev2220_0187": (39, "「这不就是说，这1个月让人特别难忘吗？」", None),
    "b043_ev2220_0188": (27, "「所以让我们住一起……？」", None),
    "b043_ev2220_0194": (22, "「我回来了，爸爸妈妈」", None),
    "b043_ev2220_0195": (42, "「总之，近期要好好向琉伍学长道谢和道歉」", None),
    "b043_ev2220_0196": (27, "「其中最难忘的是……？」", None),
    "b043_ev2220_0227": (34, "良子小姐温柔地搂住轻轻挨近的步梦。", None),
    "b043_ev2220_0239": (38, "不过现在，我们可比兄妹还要亲近了……", "おにいちゃん以上に=超出兄妹关系"),
    "b043_ev2220_0248": (33, "『不过，只能在梦里约会……。』", None),
    "b043_ev2220_0268": (33, "「嗯。别看我这样，排球还不错哦」", None),
    "b043_ev2220_0273": (52, "「嘛，我知道陆斗什么项目都能应付……真的没问题吗？」", None),
    "b043_ev2220_0275": (14, "「我也会应援」", None),
}

def width(s):
    # 全角=2、半角=1（本批新译文中非 ASCII 字符均按全角计）
    return sum(2 if ord(c) > 0x7F else 1 for c in s)

patches = []
bad = []
for pid, (budget, tr, note) in patches_map.items():
    if "\t" in tr or "\n" in tr or "\r" in tr:
        bad.append(f"control char in {pid}")
        continue
    w = width(tr)
    if w > budget:
        bad.append(f"{pid} too_long: {w} > {budget}")
        continue
    item = {"id": pid, "translation": tr}
    if note is not None:
        item["note"] = note
    patches.append(item)

if bad:
    raise SystemExit("BUILD FAILED:\n" + "\n".join(bad))

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b043_ev2220.json", "w", encoding="utf-8"),
    ensure_ascii=False,
    indent=1,
)
print("patches:", len(patches))
