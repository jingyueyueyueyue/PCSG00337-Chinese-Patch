#!/usr/bin/env python3
"""扫描 script.rom，验证全部 DCVM 容器的加载期校验和。

算法与引擎加载期校验函数一致（已在原始 rom 482 个压缩容器 + 9 个未压缩
容器上经验确认 100% 通过）：

  DCVM 头：魔数 "DCVM"、+12 必须为 0x1000、+14 为 0
  CODE 段：对 payload 逐字节 sum += byte + i（i 为奇数时 sum = ~sum），
           与 CODE 头 +20 比对（payload 起点 = 段偏移 +28，长度 = +16）
  STR 段 ：对 STBL 引用的每条字符串按有符号 char 累加至 NUL，
           与 STR 头 +8 比对（STBL 计数 = +8，偏移表 = +12，相对 STR 记录区
           起点 = STR 段偏移 +16）
  DCVM+8 == code_hash + str_hash（内容校验和，不是 ID；改 STR 后必须重算）

任一不满足，引擎加载时即拒绝该脚本（表现为调用处返回 0）。

用法:
  python scripts/analysis/verify_dcvm_checksums.py [--rom rom/script.rom]
"""

from __future__ import annotations

import argparse
import re
import struct
import sys
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
DEFAULT_ROM = ROOT / "rom" / "script.rom"

ZLIB_RE = re.compile(rb"\x78[\x01\x5e\x9c\xda]")


def u32(data: bytes | bytearray, off: int) -> int:
    return struct.unpack_from("<I", data, off)[0]


def dcvm_sections(data: bytes) -> dict[bytes, int]:
    """tag -> 段偏移。段序列从 DCVM+16 开始，总长 = DCVM+4。"""
    total = u32(data, 4)
    out: dict[bytes, int] = {}
    off = 16
    while off + 8 <= total:
        tag = data[off : off + 4]
        size = u32(data, off + 4)
        if size < 8 or off + size > len(data):
            break
        out.setdefault(tag, off)
        off += size
        if size == 0:
            break
    return out


def code_hash(code: bytes | bytearray) -> int:
    s = 0
    for i, x in enumerate(code):
        s = (s + x + i) & 0xFFFFFFFF
        if i & 1:
            s = (~s) & 0xFFFFFFFF
    return s


def str_hash(data: bytes, str_pay: int, stbl_pay: int, count: int) -> int:
    s = 0
    for j in range(count):
        p = str_pay + u32(data, stbl_pay + 4 * j)
        while data[p] != 0:
            c = data[p]
            if c >= 0x80:
                c -= 0x100  # 有符号 char
            s = (s + c) & 0xFFFFFFFF
            p += 1
    return s


def verify_dcvm(data: bytes) -> tuple[bool, str] | None:
    """返回 (是否通过, 失败详情)；非 DCVM 或缺段返回 None。"""
    if data[:4] != b"DCVM":
        return None
    if struct.unpack_from("<H", data, 12)[0] != 0x1000 or data[14] != 0:
        return None
    secs = dcvm_sections(data)
    if b"CODE" not in secs or b"STR " not in secs or b"STBL" not in secs:
        return None
    ch, sh, th = secs[b"CODE"], secs[b"STR "], secs[b"STBL"]
    # 本作 482+9 个容器 CODE/STR 混淆计数（CODE+24 / STR+12）全为 0，
    # 无需 eboot 内的 XOR 密钥；若非零则此处按未混淆计算会自然报错提示。
    if u32(data, ch + 24) or u32(data, sh + 12):
        return False, f"xor obfuscation present (code={u32(data, ch + 24)} str={u32(data, sh + 12)})"
    hc = code_hash(data[ch + 28 : ch + 28 + u32(data, ch + 16)])
    ec = u32(data, ch + 20)
    hs = str_hash(data, sh + 16, th + 12, u32(data, th + 8))
    es = u32(data, sh + 8)
    total = (hc + hs) & 0xFFFFFFFF
    stored8 = u32(data, 8)
    if hc == ec and hs == es and total == stored8:
        return True, ""
    return False, f"code {hc:08X}/{ec:08X} str {hs:08X}/{es:08X} sum {total:08X}/dcvm+8 {stored8:08X}"


def scan_rom(rom: bytes) -> tuple[int, int, list[str]]:
    ok = 0
    fails: list[str] = []

    # 压缩容器：条目头 12 字节（魔数 a6190100 + comp_size + decomp_size）+ zlib
    for match in ZLIB_RE.finditer(rom):
        off = match.start()
        dec = zlib.decompressobj()
        try:
            payload = dec.decompress(rom[off:])
            payload += dec.flush()
        except zlib.error:
            continue
        if not payload:
            continue
        r = verify_dcvm(payload)
        if r is None:
            continue
        passed, detail = r
        if passed:
            ok += 1
        else:
            fails.append(f"zlib entry 0x{off - 12:08X}: {detail}")

    # 未压缩容器：裸 DCVM 魔数，总长 = DCVM+4
    for match in re.finditer(rb"DCVM", rom):
        off = match.start()
        total = u32(rom, off + 4)
        if not (16 < total < 0x400000) or off + total > len(rom):
            continue
        r = verify_dcvm(rom[off : off + total])
        if r is None:
            continue
        passed, detail = r
        if passed:
            ok += 1
        else:
            fails.append(f"raw dcvm 0x{off:08X}: {detail}")
    return ok, len(fails), fails


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, default=DEFAULT_ROM)
    args = parser.parse_args()

    if not args.rom.exists():
        print(f"missing rom: {args.rom}", file=sys.stderr)
        return 2
    ok, bad, fails = scan_rom(args.rom.read_bytes())
    print(f"{args.rom}: pass={ok} FAIL={bad}")
    for line in fails[:20]:
        print(" ", line)
    if len(fails) > 20:
        print(f"  ... and {len(fails) - 20} more")
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
