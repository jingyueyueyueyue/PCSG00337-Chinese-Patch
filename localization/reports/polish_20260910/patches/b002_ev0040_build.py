# -*- coding: utf-8 -*-
"""b002_ev0040 润色补丁构建脚本（含字节预算自检）。"""
import csv
import json
import sys
from pathlib import Path

ROOT = Path(r"D:\VITA3K\ux0\app\PCSG00337")
BATCH = ROOT / "localization/text/work/b002_ev0040.tsv"
OUT = ROOT / "localization/reports/polish_20260910/patches/b002_ev0040.json"

# (id, 新译文, note 或 None)
PATCHES = [
    ("b002_ev0040_0002", r"（……是那样吗？没错……）", None),
    ("b002_ev0040_0014", r"「呼」", None),
    ("b002_ev0040_0060", r"「2号站台，即将关门」", None),
    ("b002_ev0040_0064", r"「所以说，无法想象和陆斗不在一个班」", None),
    ("b002_ev0040_0071", r"「真的～?」", None),
    ("b002_ev0040_0075", r"「观光啊」", None),
    ("b002_ev0040_0088", r"「嗯……搞不懂啦」", None),
    ("b002_ev0040_0118", r"「即将到站，福留站，右侧出口……」", None),
    ("b002_ev0040_0119", r"「不嫌弃就用这个」", None),
    ("b002_ev0040_0142", r"（……当然。他哪会记得我这种人）", None),
    ("b002_ev0040_0144", r"（可是，三谷君没注意到我……）", None),
    ("b002_ev0040_0147", r"（别说哭的理由，连为手帕道谢都……）", None),
    ("b002_ev0040_0151", r"（以前虽然也很帅……）", None),
    ("b002_ev0040_0154", r"（再说，三谷君要来朝冈的话，他忘了我反而更方便……）", None),
    ("b002_ev0040_0155", r"（果然是三谷君，没错……）", None),
    ("b002_ev0040_0156", r"（这份温柔……没变啊……）", None),
    ("b002_ev0040_0164", r"朝挥着手远去的奉莉，我也用力挥手回应。", None),
    ("b002_ev0040_0180", r"「哪里？」", None),
    ("b002_ev0040_0181", r"「是不是很怪？」", None),
    ("b002_ev0040_0183", r"共鸣？", None),
    ("b002_ev0040_0186", r"不觉得", "预算过紧，省略引号"),
    ("b002_ev0040_0190", r"「电车上有个女孩哭了吧?」", None),
    ("b002_ev0040_0192", r"「奉莉你也考上了，恭喜你。今后也照旧请多关照」", None),
    ("b002_ev0040_0199", r"「有有有有，大大地有。那孩子要的是能共鸣的人」", None),
    ("b002_ev0040_0216", r"「不好意思——工程车要通过，请稍等片刻」", None),
    ("b002_ev0040_0231", r"但那笑容，从六年前起就丝毫未变……", None),
    ("b002_ev0040_0272", r"紧握住挂在腰间的表。", None),
    ("b002_ev0040_0289", r"借此契机，静下心神。", None),
    ("b002_ev0040_0292", r"「……那，是怎样的人?」", None),
    ("b002_ev0040_0293", r"「3月……」", None),
    ("b002_ev0040_0302", r"「冷笑话？」", None),
    ("b002_ev0040_0307", r"「要我接?」", None),
    ("b002_ev0040_0318", r"「啊，嗯……抱歉」", None),
    ("b002_ev0040_0319", r"「哦，回来得正好?」", None),
    ("b002_ev0040_0327", r"「为什么?」", None),
    ("b002_ev0040_0331", r"「再婚？那个再婚?」", None),
    ("b002_ev0040_0338", r"回来啦", None),
    ("b002_ev0040_0358", r"再婚呐……", None),
    ("b002_ev0040_0384", r"明明至少今天，想忘掉一切享受考上的余韵……", None),
    ("b002_ev0040_0402", r"「一见钟情」", None),
    ("b002_ev0040_0407", r"「……愿那女孩有好事发生」", None),
    ("b002_ev0040_0415", r"嗯，硬撑也要高兴起来！", None),
]


def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)


def main():
    budget = {}
    with open(BATCH, encoding="utf-8", newline="") as f:
        for r in csv.DictReader(f, delimiter="\t"):
            budget[r["id"]] = int(r["budget"])

    warns = 0
    seen = set()
    items = []
    for pid, tr, note in PATCHES:
        if pid in seen:
            sys.exit(f"duplicate patch id: {pid}")
        seen.add(pid)
        if any(c in tr for c in ("\t", "\n", "\r")):
            sys.exit(f"control char in {pid}")
        if note is not None and any(c in note for c in ("\t", "\n", "\r")):
            sys.exit(f"control char in note {pid}")
        b = budget.get(pid)
        if b is None:
            sys.exit(f"unknown id: {pid}")
        n = enc_len(tr)
        if n > b:
            print(f"WARN over budget {pid}: {n}>{b}  {tr}")
            warns += 1
        item = {"id": pid, "translation": tr}
        if note is not None:
            item["note"] = note
        items.append(item)

    OUT.parent.mkdir(parents=True, exist_ok=True)
    with open(OUT, "w", encoding="utf-8") as f:
        json.dump({"patches": items}, f, ensure_ascii=False, indent=1)
    print(f"patches: {len(items)}  over-budget warns: {warns}")
    print(f"written: {OUT}")


if __name__ == "__main__":
    main()
