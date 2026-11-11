# -*- coding: utf-8 -*-
"""按 block_map 顺序把 script_strings.csv 的 jp 行切成翻译批次 TSV。

同批次内重复原文只发一次；跨批重复由 validate_translations.py --finalize 回填。
用法: python scripts/convert/make_translation_batches.py [--batch-lines 400]
"""
import argparse
import csv
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CSV_PATH = ROOT / "extracted/script/script_strings.csv"
BLOCK_MAP = ROOT / "extracted/script/block_map.json"
WORK = ROOT / "localization/text/work"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--batch-lines", type=int, default=400)
    ap.add_argument("--force", action="store_true", help="清空 work/ 后重建（会丢未合并的译文）")
    args = ap.parse_args()

    blocks = json.loads(BLOCK_MAP.read_text(encoding="utf-8"))
    blocks.sort(key=lambda b: int(b["offset"], 16))
    scen_of = {b["offset"]: (b["scen"][0][:-2] if b["scen"] else "system") for b in blocks}

    by_off = defaultdict(list)
    with open(CSV_PATH, encoding="utf-8-sig", newline="") as f:
        for i, row in enumerate(csv.DictReader(f), start=2):
            if row["category"] == "jp":
                by_off[row["offset"]].append(
                    {
                        "row": i,
                        "offset": row["offset"],
                        "budget": len(bytes.fromhex(row["raw_hex"])),
                        "source": row["text"],
                    }
                )

    if args.force:
        for p in WORK.glob("b*.tsv"):
            p.unlink()
    WORK.mkdir(parents=True, exist_ok=True)

    batches, cur = [], []
    for b in blocks:
        cur.extend(by_off.get(b["offset"], []))
        if len(cur) >= args.batch_lines:
            batches.append(cur)
            cur = []
    if cur:
        batches.append(cur)

    seen = {}
    manifest = []
    for bi, batch in enumerate(batches, 1):
        name = f"b{bi:03d}_{scen_of[batch[0]['offset']]}"
        out = WORK / f"{name}.tsv"
        lines = [r for r in batch if r["source"] not in seen]
        for r in batch:
            seen.setdefault(r["source"], name)
        with open(out, "w", encoding="utf-8", newline="") as f:
            f.write("id\trow\toffset\tscen\tbudget\tsource\ttranslation\tnote\n")
            for j, r in enumerate(lines, 1):
                src = r["source"].replace("\\", "\\\\").replace("\n", "\\n").replace("\t", "\\t")
                f.write(
                    f"{name}_{j:04d}\t{r['row']}\t{r['offset']}\t{scen_of[r['offset']]}\t"
                    f"{r['budget']}\t{src}\t\t\n"
                )
        manifest.append(
            {
                "batch": name,
                "file": str(out.relative_to(ROOT)),
                "lines": len(lines),
                "rows_covered": len(batch),
            }
        )

    (WORK / "manifest.json").write_text(
        json.dumps(manifest, ensure_ascii=False, indent=1), encoding="utf-8"
    )
    print(f"batches: {len(batches)}  unique lines: {sum(m['lines'] for m in manifest)}  "
          f"rows covered: {sum(m['rows_covered'] for m in manifest)}")


if __name__ == "__main__":
    main()
