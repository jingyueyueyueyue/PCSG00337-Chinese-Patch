# -*- coding: utf-8 -*-
"""翻译批次质检 + 合并。

默认:  校验 work/b*.tsv（字节预算、控制 token、残留假名、人名表一致），输出
       localization/reports/translation_qc.tsv 与进度摘要。
--finalize: 通过安全同步器生成正式 CSV（先按精确行号，再回填重复句）。
超过旧字节预算只提示，完整构建支持 STR/STBL 扩容；--strict-budget 可恢复严格预算检查。
用法: python scripts/analysis/validate_translations.py [--finalize]
"""
import argparse
import csv
import glob
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
WORK = ROOT / "localization/text/work"
GLOSSARY = ROOT / "localization/text/glossary.tsv"
REPORT_DIR = ROOT / "localization/reports"

TOKEN_RE = re.compile(r"<[^>]*>|\\n|\n")
RUBY_RE = re.compile(r"<ruby2?>\([^)]*\)")
KANA_RE = re.compile(r"[ぁ-ゖァ-ヶー]")


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


def tokens(s: str):
    return TOKEN_RE.findall(s)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--finalize", action="store_true")
    ap.add_argument("--strict-budget", action="store_true")
    args = ap.parse_args()

    gloss = {}
    with open(GLOSSARY, encoding="utf-8") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            gloss[row["ja"]] = row["zh"]

    allow = set()
    allow_file = REPORT_DIR / "qc_allowlist.tsv"
    if allow_file.exists():
        with open(allow_file, encoding="utf-8") as f:
            for row in csv.DictReader(f, delimiter="\t"):
                allow.add(row["id"])

    files = sorted(glob.glob(str(WORK / "b*.tsv")))
    if not files:
        print("no batch files; run make_translation_batches.py first")
        return 1

    issues = []
    srcmap = {}
    done = total = 0
    for fp in files:
        fname = Path(fp).stem
        with open(fp, encoding="utf-8", newline="") as f:
            rows = list(csv.DictReader(f, delimiter="\t"))
        filled_here = 0
        for r in rows:
            total += 1
            tr = (r.get("translation") or "").strip()
            src = r["source"]
            budget = int(r["budget"])
            if not tr:
                if src in srcmap:
                    continue  # 跨批重复，finalize 时回填
                continue
            filled_here += 1
            done += 1
            srcmap.setdefault(src, tr)
            if r["id"] in allow:
                continue
            n = enc_len(tr)
            if n > budget:
                issues.append((fname, r["id"], "too_long", f"{n}>{budget}", tr[:40]))
            src_t = tokens(RUBY_RE.sub("", src))
            tr_t = tokens(tr)
            if tr_t != src_t:
                issues.append((fname, r["id"], "token_mismatch",
                               f"src={src_t} tr={tr_t}", tr[:40]))
            if KANA_RE.search(tr):
                issues.append((fname, r["id"], "kana_left", "", tr[:40]))
            if src in gloss and tr != gloss[src]:
                issues.append((fname, r["id"], "name_mismatch",
                               f"{src}->{tr} 期望 {gloss[src]}", tr[:40]))
        print(f"{fname}: {filled_here}/{len(rows)}")

    REPORT_DIR.mkdir(parents=True, exist_ok=True)
    with open(REPORT_DIR / "translation_qc.tsv", "w", encoding="utf-8", newline="") as f:
        f.write("batch\tid\tissue\tdetail\ttext\n")
        for it in issues:
            f.write("\t".join(it) + "\n")

    print(f"\ntranslated(unique): {done}/{total}  ({done * 100 // max(total, 1)}%)")
    print(f"issues: {len(issues)}  -> {REPORT_DIR / 'translation_qc.tsv'}")

    fatal = [issue for issue in issues if args.strict_budget or issue[2] != "too_long"]
    if fatal:
        print("Resolve translation QC errors before finalizing; formal CSV was not changed.")
        return 1
    if args.finalize:
        sys.path.insert(0, str(ROOT / "scripts/convert"))
        from sync_translation_source import main as sync_main
        return sync_main(["--apply"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
