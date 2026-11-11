# -*- coding: utf-8 -*-
"""b079_ev5110 润色补丁构建（含宽度自检：ASCII=1，其余=2，与校验器 enc_len 一致）"""
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b079_ev5110.tsv")

patches = [
    {"id": "b079_ev5110_0011", "translation": "这里一出事就能马上冲出房间。",
     "note": "补出「場所」：描述的是守夜位置"},
    {"id": "b079_ev5110_0019", "translation": "也算以防万一……"},
    {"id": "b079_ev5110_0029", "translation": "而且我也拜托了睡在真央酱另一侧、我右手边的章介帮忙……",
     "note": "反対側＝和真央相反的一侧，不是对面"},
    {"id": "b079_ev5110_0035", "translation": "不过，或许多亏这鼾声，我才一直没睡。",
     "note": "补出 よって…のかもしれない 的推测语气"},
    {"id": "b079_ev5110_0044", "translation": "从真央酱的样子来看，我睡着后似乎没出什么事。",
     "note": "顔を見る限り＝看样子，避免「看脸色」歧义"},
    {"id": "b079_ev5110_0045", "translation": "总觉得真央酱隐约察觉到我睡眠不足的原因了。",
     "note": "删多余一层的「好像」，与なんとなく…気がする双层对应"},
    {"id": "b079_ev5110_0049", "translation": "「……没怎么睡好？」",
     "note": "补 あまり＝没怎么"},
    {"id": "b079_ev5110_0050", "translation": "「……不，没事」",
     "note": "补 いや 的否认"},
    {"id": "b079_ev5110_0065", "translation": "「才、才没有……章介鼾声太吵了」",
     "note": "补 そ、的结巴"},
    {"id": "b079_ev5110_0080", "translation": "也有谜面从简单到莫名其妙的任务。",
     "note": "谜かけ文按词表作谜面；补 も＝也"},
    {"id": "b079_ev5110_0097", "translation": "在两人用力挥手的目送下，我们跑过沙滩。"},
    {"id": "b079_ev5110_0108", "translation": "「不过，这任务也真够简单的」",
     "note": "ずいぶん＝真够，原「太过」语气过重"},
    {"id": "b079_ev5110_0119", "translation": "「走吧」",
     "note": "行ってみよう＝（我们）走吧，原「去吧」像下指令"},
    {"id": "b079_ev5110_0120", "translation": "「这次是在大摩天轮入口拍照。当然必须把真央酱拍进去，否则无效哦」"},
    {"id": "b079_ev5110_0130", "translation": "「真央酱，咱们快去大摩天轮！」",
     "note": "行くよ＝一起去，用「咱们」"},
    {"id": "b079_ev5110_0136", "translation": "「两位是什么任务呀——！？」",
     "note": "のぉ――っ 拖长语气"},
    {"id": "b079_ev5110_0151", "translation": "「谢啦，喂？」",
     "note": "预算紧，暂略步梦"},
    {"id": "b079_ev5110_0161", "translation": "「是奈奈濑和三谷妹」",
     "note": "奈々瀬に三谷妹＝奈奈濑和三谷妹两个人"},
    {"id": "b079_ev5110_0178", "translation": "「看，水上巴士好帅」",
     "note": "补 かっこいい"},
    {"id": "b079_ev5110_0180", "translation": "「好、好，赶上了。呼……」",
     "note": "补 よ、よし 的喘息结巴"},
    {"id": "b079_ev5110_0182", "translation": "「懂、懂了」",
     "note": "补 わ、わかった 的结巴"},
]

def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)

budgets = {}
for line in BATCH.read_text(encoding="utf-8").split("\n"):
    p = line.split("\t")
    if len(p) >= 8 and p[0] != "id":
        budgets[p[0]] = int(p[4])

bad = []
for p in patches:
    pid = p["id"]
    if "\t" in p["translation"] or "\n" in p["translation"] or "\r" in p["translation"]:
        bad.append(f"{pid}: control char")
    w = enc_len(p["translation"])
    if pid in budgets and w > budgets[pid]:
        bad.append(f"{pid}: width {w} > budget {budgets[pid]} :: {p['translation']}")
if bad:
    raise SystemExit("WIDTH/CHAR FAIL:\n" + "\n".join(bad))

json.dump({"patches": patches},
          open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b079_ev5110.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("patches:", len(patches))
