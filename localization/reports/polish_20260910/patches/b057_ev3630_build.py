# -*- coding: utf-8 -*-
"""b057_ev3630 润色补丁构建（带显示宽度自检：全角=2 半角=1，须 <= budget）"""
import csv
import json

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b057_ev3630.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b057_ev3630.json"


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


# translation 必填；note 仅在需要时给出（省略则保持原 note）
patches = [
    # ---- 译文修改 ----
    {"id": "b057_ev3630_0010",
     "translation": "「You alright! 这么说，你也听说夏奏酱的后辈要来指导我们了吗？」"},
    {"id": "b057_ev3630_0012",
     "translation": "「所以昨天你休息时我还担心，看来没事呢」"},
    {"id": "b057_ev3630_0074",
     "translation": "「啊，说是表演组的」"},
    {"id": "b057_ev3630_0077",
     "translation": "「那个，奉莉同学进哪个组分好了吗？」", "note": "奉莉さん按词表规则改奉莉同学"},
    {"id": "b057_ev3630_0089",
     "translation": "「我明白。但我想在那段期间内能练成的动作里，挑战最难的那个！」"},
    {"id": "b057_ev3630_0105",
     "translation": "发现东云小姐在雕塑旁，跑了过去。"},
    {"id": "b057_ev3630_0133",
     "translation": "「所以关于奉莉酱的事，若有让您在意的，我必定联系您」"},
    {"id": "b057_ev3630_0140",
     "translation": "「想为喜欢的女孩做点什么……这是我真实的心声」"},
    {"id": "b057_ev3630_0151",
     "translation": "「啊……失礼了」"},
    {"id": "b057_ev3630_0202",
     "translation": "「……哭的时候什么样？」"},
    {"id": "b057_ev3630_0212",
     "translation": "「前天那会儿，我还以为她喜欢上了哥哥，却因为说不出口而烦恼着」"},
    {"id": "b057_ev3630_0292",
     "translation": "「不不，还早着呢」"},
    {"id": "b057_ev3630_0300",
     "translation": "「厉害，不愧是奉莉酱」"},
    # ---- 仅补 note：曾尝试润色但超出预算，保留初翻并标记 ----
    {"id": "b057_ev3630_0155", "translation": "「不是来喝茶的……」", "note": "预算过紧"},
    {"id": "b057_ev3630_0219", "translation": "「哭了？」", "note": "预算过紧"},
    {"id": "b057_ev3630_0258", "translation": "「难以置信」", "note": "预算过紧"},
    {"id": "b057_ev3630_0272", "translation": "「好久不见了」", "note": "预算过紧"},
    {"id": "b057_ev3630_0273", "translation": "「有种逼人的气势呢」", "note": "预算过紧"},
    {"id": "b057_ev3630_0280", "translation": "「奈奈濑同学怎么也吓到？」", "note": "预算过紧"},
    {"id": "b057_ev3630_0295", "translation": "「是吗？」", "note": "预算过紧"},
    {"id": "b057_ev3630_0297", "translation": "「是男友来电，我先走了」", "note": "预算过紧"},
    {"id": "b057_ev3630_0299", "translation": "「谁？」", "note": "预算过紧"},
    {"id": "b057_ev3630_0313", "translation": "「久违了！」", "note": "预算过紧"},
    {"id": "b057_ev3630_0314", "translation": "「劈腿……」", "note": "预算过紧"},
    {"id": "b057_ev3630_0321", "translation": "到底在想什么……", "note": "预算过紧"},
]

# ---- 自检 1：控制字符 ----
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"] or "\r" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# ---- 自检 2：id 存在 + 显示宽度不超预算 + 仅补注组译文须与现文一致 ----
NOTE_ONLY = {p["id"] for p in patches if p.get("note") == "预算过紧"}
rows = {r["id"]: r for r in csv.DictReader(open(BATCH, encoding="utf-8"), delimiter="\t")}
errs = []
for p in patches:
    tid = p["id"]
    if tid not in rows:
        errs.append("unknown id: " + tid)
        continue
    n = enc_len(p["translation"])
    b = int(rows[tid]["budget"])
    if n > b:
        errs.append("%s too long: %d>%d" % (tid, n, b))
    if tid in NOTE_ONLY and p["translation"] != rows[tid]["translation"]:
        errs.append("%s claims note-only but translation differs" % tid)
if errs:
    raise SystemExit("\n".join(errs))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
