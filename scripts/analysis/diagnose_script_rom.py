#!/usr/bin/env python3
"""诊断当前 rom/script.rom 相对原始基线的结构差异。

对照基线 archive/2026-09/20260907_script.rom（原始未改动版）：
  1. 文件头 / 条目头 / 流数据区 / 其它区域 分别统计差异字节
  2. 引擎视角逐条目走位：magic、compressed_size、decompressed_size 是否一致
  3. 当前 rom 全部 zlib 流可解压性、数量是否与基线一致
"""

from __future__ import annotations

import re
import struct
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ORIG = ROOT / "archive" / "2026-09" / "20260907_script.rom"
CUR = ROOT / "rom" / "script.rom"
ZLIB_RE = re.compile(rb"\x78[\x01\x5e\x9c\xda]")
ENTRY_MAGIC = b"\xa6\x19\x01\x00"


def scan(data: bytes) -> list[tuple[int, int, bytes]]:
    streams = []
    for match in ZLIB_RE.finditer(data):
        off = match.start()
        dec = zlib.decompressobj()
        try:
            payload = dec.decompress(data[off:])
            payload += dec.flush()
        except zlib.error:
            continue
        consumed = len(data) - off - len(dec.unused_data)
        if consumed <= 2 or not payload:
            continue
        streams.append((off, consumed, payload))
    return streams


def main() -> int:
    orig = ORIG.read_bytes()
    cur = CUR.read_bytes()
    print(f"orig: {ORIG.name} {len(orig)} bytes")
    print(f"cur : {CUR.name} {len(cur)} bytes")
    if len(orig) != len(cur):
        print(f"!! size differs: {len(orig)} vs {len(cur)}")

    ostreams = scan(orig)
    cstreams = scan(cur)
    print(f"zlib streams: orig {len(ostreams)}  cur {len(cstreams)}")

    o_by_off = {off: (size, payload) for off, size, payload in ostreams}
    c_by_off = {off: (size, payload) for off, size, payload in cstreams}
    missing = sorted(set(o_by_off) - set(c_by_off))
    added = sorted(set(c_by_off) - set(o_by_off))
    print(f"streams missing in cur: {len(missing)}  added in cur: {len(added)}")
    for off in missing[:10]:
        print(f"  missing 0x{off:08X}")
    for off in added[:10]:
        print(f"  added   0x{off:08X}")

    # --- 区域分类diff ---
    n = min(len(orig), len(cur))
    stream_mask = bytearray(n)
    header_mask = bytearray(n)
    for off, size, _p in ostreams:
        stream_mask[off : off + size] = b"\x01" * size
        header_mask[off - 12 : off] = b"\x01" * 12
    diff_header = diff_stream = diff_other = 0
    other_regions: list[tuple[int, int]] = []
    open_region = None
    for i in range(n):
        if orig[i] == cur[i]:
            if open_region is not None:
                other_regions.append((open_region, i))
                open_region = None
            continue
        if header_mask[i]:
            diff_header += 1
        elif stream_mask[i]:
            diff_stream += 1
        else:
            diff_other += 1
            if open_region is None:
                open_region = i
    if open_region is not None:
        other_regions.append((open_region, n))
    print(
        f"diff bytes: entry-header {diff_header}  stream-data {diff_stream}  OTHER {diff_other}"
    )
    for start, end in other_regions[:20]:
        print(f"  OTHER diff region 0x{start:08X}-0x{end:08X} ({end - start} bytes)")

    # --- 条目头逐条对比 ---
    bad_magic = bad_comp = bad_decomp = 0
    for off, size, _p in ostreams:
        start = off - 12
        oh = orig[start : start + 12]
        ch = cur[start : start + 12]
        if oh == ch:
            continue
        om, oc, od = struct.unpack("<III", oh)
        cm, cc, cd = struct.unpack("<III", ch)
        if oh[:4] != ch[:4]:
            bad_magic += 1
        if oc != cc:
            bad_comp += 1
            print(
                f"  comp_size changed at entry 0x{start:08X}: {oc} -> {cc} (zlib at 0x{off:08X})"
            )
        if od != cd:
            bad_decomp += 1
            print(f"  decomp_size changed at entry 0x{start:08X}: {od} -> {cd}")
    print(
        f"entry headers changed: magic {bad_magic}  comp_size {bad_comp}  decomp_size {bad_decomp}"
    )

    # --- 当前 rom 流解压与长度不变量 ---
    bad_inflate = 0
    size_mismatch = 0
    for off, (osize, opayload) in o_by_off.items():
        got = c_by_off.get(off)
        if got is None:
            continue
        csize, cpayload = got
        if len(cpayload) != len(opayload):
            size_mismatch += 1
            print(
                f"  decompressed length changed at 0x{off:08X}: {len(opayload)} -> {len(cpayload)}"
            )
    print(f"decompressed length mismatches: {size_mismatch}")

    # --- 2KB 文件头 ---
    head_diff = sum(1 for i in range(min(0x800, n)) if orig[i] != cur[i])
    print(f"file header (0x000-0x800) diff bytes: {head_diff}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
