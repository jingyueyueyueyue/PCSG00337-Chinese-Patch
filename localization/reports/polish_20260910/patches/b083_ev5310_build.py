# -*- coding: utf-8 -*-
"""Polish patch builder for b083_ev5310 (2026-09-11)."""
import csv
import json
import os

ROOT = r"D:\VITA3K\ux0\app\PCSG00337"
TSV = os.path.join(ROOT, "localization", "text", "work", "b083_ev5310.tsv")
OUT = os.path.join(ROOT, "localization", "reports", "polish_20260910", "patches", "b083_ev5310.json")

patches = [
    {"id": "b083_ev5310_0009", "translation": "「不行不行！那句至少得改成『那个……就算突然被说禁止，我也一直是这种措辞嘛……』才行」", "note": "いきなり禁止=突然被说禁止，原译语序不通；与0014对应"},
    {"id": "b083_ev5310_0014", "translation": "「不、不对……就算突然被说禁止，我一直都是这种措辞……」", "note": "同0009，修正被说禁止突然来"},
    {"id": "b083_ev5310_0015", "translation": "「嗯，完全是女孩」", "note": "补そのもの=完全"},
    {"id": "b083_ev5310_0027", "translation": "「既然决定了，就要当完美的女仆吧？」", "note": "做到完美女仆搭配不当"},
    {"id": "b083_ev5310_0036", "translation": "……看来，代价很大。", "note": "叙述行去引号，与0037一致"},
    {"id": "b083_ev5310_0047", "translation": "「可是束胸和四角裤，你觉得那样算完美女仆吗？」", "note": "トランクス按词表=四角裤"},
    {"id": "b083_ev5310_0048", "translation": "「为、为什么！？」", "note": "预算内恢复全角！?"},
    {"id": "b083_ev5310_0056", "translation": "「那当然。踏进那种地方，失去的比得到的多……」", "note": "多得多为多译"},
    {"id": "b083_ev5310_0059", "translation": "「正常就行……吗……」", "note": "与0084正常点呼应"},
    {"id": "b083_ev5310_0064", "translation": "「要我说啊，束胸和四角裤可不行呢」", "note": "トランクス按词表=四角裤"},
    {"id": "b083_ev5310_0072", "translation": "「是、是吗？」", "note": "预算内恢复全角？"},
    {"id": "b083_ev5310_0079", "translation": "「诶？真央酱」", "note": "恢复「」与问号"},
    {"id": "b083_ev5310_0083", "translation": "「完、完全搞不懂啊！」", "note": "恢复ま、まったく口吃"},
    {"id": "b083_ev5310_0086", "translation": "嘛，步梦确实可能……", "note": "补そうかも=确实可能"},
    {"id": "b083_ev5310_0088", "translation": "……真心觉得扭扭捏捏的真央酱好可爱。", "note": "原译主语错认"},
    {"id": "b083_ev5310_0094", "translation": "「……穿了？」", "note": "つけてきた=穿戴而来，非带了"},
    {"id": "b083_ev5310_0096", "translation": "「1站台，车门要关了」", "note": "番线=站台"},
    {"id": "b083_ev5310_0105", "translation": "「啊，好好穿着呢？」", "note": "つけてきたのね=好好穿着呢"},
    {"id": "b083_ev5310_0151", "translation": "「现在行吗？」", "note": "今、いいかな=现在行吗"},
    {"id": "b083_ev5310_0157", "translation": "「……嗯。我不会再迷茫。最迟后天一定变成完美女仆给你看」", "note": "明後日までに=最迟后天"},
    {"id": "b083_ev5310_0162", "translation": "「……就是说，女款的会害羞？」", "note": "与0061女款统一"},
    {"id": "b083_ev5310_0166", "translation": "「拍咯？」", "note": "恢复じゃ、撮るよ?的确认语气"},
    {"id": "b083_ev5310_0189", "translation": "「从陆斗？」", "note": "陸斗に=もらった来源，原译方向反"},
    {"id": "b083_ev5310_0192", "translation": "「那，真央酱」", "note": "预算过紧，あのさ未能译出"},
    {"id": "b083_ev5310_0200", "translation": "「刚……说什么……？」", "note": "预算内恢复全角？"},
    {"id": "b083_ev5310_0216", "translation": "「哦哦哦！？」", "note": "预算内恢复！?"},
    {"id": "b083_ev5310_0220", "translation": "「抱……抱歉哦」", "note": "对齐す……ご的起口失误"},
    {"id": "b083_ev5310_0223", "translation": "「那、那是因为束胸和四角裤……被看到也没事……」", "note": "トランクス按词表=四角裤"},
    {"id": "b083_ev5310_0230", "translation": "「求你了……不对，拜托了……」", "note": "頼む改口お願いします的粗口转敬语"},
    {"id": "b083_ev5310_0234", "translation": "「平时跟男生混……可惜了……」", "note": "原译明明是男生与设定矛盾（真央是女生）"},
    {"id": "b083_ev5310_0238", "translation": "「果然很怪……？」", "note": "预算内恢复全角？"},
    {"id": "b083_ev5310_0240", "translation": "啊，对了，本校理事长。", "note": "补そうか=对了"},
    {"id": "b083_ev5310_0243", "translation": "嗯……超可爱。", "note": "恢复うん……停顿"},
    {"id": "b083_ev5310_0255", "translation": "那身影比刚才更……更加……可爱……", "note": "要更不顺，改更加"},
]


def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)


bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

with open(TSV, encoding="utf-8", newline="") as f:
    rows = {r["id"]: r for r in csv.DictReader(f, delimiter="\t")}

missing = [p["id"] for p in patches if p["id"] not in rows]
if missing:
    raise SystemExit("unknown ids: %r" % missing)

too_long = []
for p in patches:
    tr = p["translation"].strip()
    n = enc_len(tr)
    budget = int(rows[p["id"]]["budget"])
    if n > budget:
        too_long.append((p["id"], n, budget))
if too_long:
    raise SystemExit("too_long: %r" % too_long)

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
