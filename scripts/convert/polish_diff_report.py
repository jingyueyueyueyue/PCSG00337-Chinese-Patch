# -*- coding: utf-8 -*-
"""生成润色修改前后对照文档（单个 Markdown）。

用法：
    python -X utf8 -B scripts/convert/polish_diff_report.py \
        --before archive/2026-09/20260910_polish_before --out 润色对照_20260910.md

对比 localization/text/work/b*.tsv 与 <before>/work/b*.tsv（按 id 对齐，只看 translation 列），
以及 eboot_translations.csv。输出每个被修改行的原文、修改前、修改后，附各批统计。
"""
import argparse
import csv
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def load_tsv(path):
    rows = {}
    text = path.read_bytes().decode("utf-8")
    for line in text.split("\n")[1:]:
        if not line:
            continue
        f = line.split("\t")
        if len(f) >= 7:
            rows[f[0]] = f
    return rows


def load_eboot(path):
    rows = {}
    with open(path, encoding="utf-8-sig", newline="") as f:
        for r in csv.DictReader(f):
            rows[r["id"]] = r
    return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--before", default="archive/2026-09/20260910_polish_before")
    ap.add_argument("--out", default="润色对照_20260910.md")
    ap.add_argument("--work", default="localization/text/work")
    ap.add_argument("--eboot", default="localization/text/eboot_translations.csv")
    args = ap.parse_args()

    before_work = (ROOT / args.before).resolve() / "work"
    work = ROOT / args.work
    sections = []
    stats = []
    total_changed = 0
    total_rows = 0

    for cur_path in sorted(work.glob("b*.tsv")):
        old_path = before_work / cur_path.name
        if not old_path.exists():
            continue
        old = load_tsv(old_path)
        new = load_tsv(cur_path)
        changed = [
            (rid, of, nf)
            for rid, nf in new.items()
            if (of := old.get(rid)) is not None and nf[6] != of[6]
        ]
        total_rows += len(new)
        total_changed += len(changed)
        stats.append((cur_path.stem, len(new), len(changed)))
        if not changed:
            continue
        sec = [f"## {cur_path.stem}", ""]
        for rid, of, nf in changed:
            sec += [f"### {rid}", f"- 原文：{of[5]}", f"- 修改前：{of[6]}", f"- 修改后：{nf[6]}", ""]
        sections.append("\n".join(sec))

    eboot_old_path = ROOT / args.before / "eboot_translations.csv"
    if eboot_old_path.exists():
        old_e = load_eboot(eboot_old_path)
        new_e = load_eboot(ROOT / args.eboot)
        changed_e = [
            (rid, old_e[rid], r)
            for rid, r in new_e.items()
            if rid in old_e and old_e[rid]["translation"] != r["translation"]
        ]
        stats.append(("eboot_translations", len(new_e), len(changed_e)))
        total_changed += len(changed_e)
        total_rows += len(new_e)
        if changed_e:
            sec = ["## eboot_translations（系统文本）", ""]
            for rid, of, nf in changed_e:
                sec += [
                    f"### {rid}",
                    f"- 原文：{of['source']}",
                    f"- 修改前：{of['translation']}",
                    f"- 修改后：{nf['translation']}",
                    "",
                ]
            sections.append("\n".join(sec))

    out_lines = [
        "# 润色校对修改对照",
        "",
        "逐行对照日文原文对全部译文完成润色校对后的修改记录，仅列出 translation 列实际发生变化的行。",
        "「原文」为日文源文（含控制标记，字面 \\n 为换行标记），修改前后均为中文译文。",
        "",
        "| 批次 | 总行数 | 修改行数 |",
        "|---|---:|---:|",
    ]
    out_lines += [f"| {name} | {n} | {c} |" for name, n, c in stats]
    out_lines += [f"| **合计** | **{total_rows}** | **{total_changed}** |", ""]

    out = ROOT / args.out
    out.write_text("\n".join(out_lines + sections), encoding="utf-8")
    print(f"batches compared: {len(stats)}  rows: {total_rows}  changed: {total_changed}")
    print(f"written: {out}")


if __name__ == "__main__":
    main()
