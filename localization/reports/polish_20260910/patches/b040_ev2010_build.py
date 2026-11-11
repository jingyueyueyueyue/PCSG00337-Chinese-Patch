# -*- coding: utf-8 -*-
"""b040_ev2010 润色补丁构建（自带预算宽度/控制符/重复自检，超限整体拒绝）"""
import csv
import json
from pathlib import Path

ROOT = Path(r"D:\VITA3K\ux0\app\PCSG00337")
TSV = ROOT / r"localization\text\work\b040_ev2010.tsv"
OUT = ROOT / r"localization\reports\polish_20260910\patches\b040_ev2010.json"

patches = [
    {"id": "b040_ev2010_0006", "translation": "「良子小姐今天好像也很晚，只剩我和爸……」"},
    {"id": "b040_ev2010_0008", "translation": "「……但做千里酱自己不也挺好？」"},
    {"id": "b040_ev2010_0019", "translation": "「然后大家都意识到她年长，现在都像对待易碎品似的……」"},
    {"id": "b040_ev2010_0020", "translation": "「不过那样正好吧？被人毫无顾忌地直说，说不定会火大哦？」"},
    {"id": "b040_ev2010_0025", "translation": "好久不见！"},
    {"id": "b040_ev2010_0039", "translation": "「被青梅竹马嫌弃，啊哈……」"},
    {"id": "b040_ev2010_0047", "translation": "「嗯……不过我这也是头一回遇到年长的同学，有点不知所措……」"},
    {"id": "b040_ev2010_0060", "translation": "「那孩子最初也说别在意年龄，最近却只会强颜欢笑……还常常不上学……」"},
    {"id": "b040_ev2010_0071", "translation": "「不过还不太自然」"},
    {"id": "b040_ev2010_0082", "translation": "『郁美寄』"},
    {"id": "b040_ev2010_0091", "translation": "信封上这么写着。"},
    {"id": "b040_ev2010_0120", "translation": "「良子面前……不好开口……」"},
    {"id": "b040_ev2010_0131", "translation": "喏，陆斗"},
    {"id": "b040_ev2010_0148", "translation": "怎么回事，没反应……？"},
    {"id": "b040_ev2010_0177", "translation": "「不，那晚安」"},
    {"id": "b040_ev2010_0233", "translation": "『想必对方要是刻薄，陆斗就不会烦恼了吧。』"},
    {"id": "b040_ev2010_0234", "translation": "『让你孤单，真的很对不起。』"},
    {"id": "b040_ev2010_0241", "translation": "还是先去应个门……"},
    {"id": "b040_ev2010_0250", "translation": "休息日明明一个人是常态……不知怎的……"},
    {"id": "b040_ev2010_0270", "translation": "「……那么我先挂了」"},
    {"id": "b040_ev2010_0274", "translation": "「……良子小姐也请读一读」"},
    {"id": "b040_ev2010_0279", "translation": "「收到的那一刻，我和丈夫都喜极而泣……感觉就像女儿回来了……」"},
    {"id": "b040_ev2010_0292", "translation": "「你珍视的妈妈的遗物……谢谢……」"},
    {"id": "b040_ev2010_0302", "translation": "「还有……陆斗君」"},
    {"id": "b040_ev2010_0317", "translation": "『不知几点回来，不用给我留饭，转告步梦哦！』"},
    {"id": "b040_ev2010_0327", "translation": "下定决心般点点头，和奉莉她们去找队长。"},
    {"id": "b040_ev2010_0334", "translation": "虽然不安，但队长发话了，没办法。"},
    {"id": "b040_ev2010_0357", "translation": "「重要？什么样的？」"},
    {"id": "b040_ev2010_0369", "translation": "「哎呀，还谈不上完美……」"},
    {"id": "b040_ev2010_0380", "translation": "「喂，要继续啦！」"},
    {"id": "b040_ev2010_0387", "translation": "那要听步梦本人说了"},
    {"id": "b040_ev2010_0388", "translation": "「话虽如此，电话打不通啊……」"},
    {"id": "b040_ev2010_0391", "translation": "「你笑什么呢？奉莉不担心步梦吗？」"},
    {"id": "b040_ev2010_0398", "translation": "之后换乘电车，回到了伊奈濑站前。"},
]

# 想润色但预算压不进、维持初翻的行，仅加备注
for _pid in ("b040_ev2010_0067", "b040_ev2010_0208", "b040_ev2010_0296", "b040_ev2010_0305"):
    patches.append({"id": _pid, "translation": None, "note": "预算过紧"})

with open(TSV, encoding="utf-8", newline="") as f:
    rows = {r["id"]: r for r in csv.DictReader(f, delimiter="\t")}

# 幂等：已应用到 TSV 的译文补丁不再重复输出
patches = [p for p in patches if p["translation"] is None or p["translation"] != rows[p["id"]]["translation"]]


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


errors = []
for p in patches:
    pid = p["id"]
    if pid not in rows:
        errors.append(f"unknown id: {pid}")
        continue
    if p["translation"] is None:
        p["translation"] = rows[pid]["translation"]
    tr = p["translation"]
    if "\t" in tr or "\n" in tr or "\r" in tr:
        errors.append(f"control char in: {pid}")
        continue
    budget = int(rows[pid]["budget"])
    n = enc_len(tr)
    if n > budget:
        errors.append(f"too long: {pid} {n}>{budget}: {tr}")
    cur_note = rows[pid].get("note") or ""
    if tr == rows[pid]["translation"] and p.get("note", cur_note) == cur_note:
        errors.append(f"no-op: {pid}")

if errors:
    print("REJECT, nothing written:")
    for e in errors:
        print("  " + e)
    raise SystemExit(1)

OUT.parent.mkdir(parents=True, exist_ok=True)
with open(OUT, "w", encoding="utf-8") as f:
    json.dump({"patches": patches}, f, ensure_ascii=False, indent=1)
print("patches:", len(patches))
