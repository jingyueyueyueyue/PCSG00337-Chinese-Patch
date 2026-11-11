#!/usr/bin/env python3
"""PCSG00337 eboot.bin 文本域：解密、提取、回写与明文假 SELF 重建。

零售 eboot.bin 是 SELF（key revision 5，五个段 zlib 压缩后 AES-CTR 加密），
段内容的明文形态就是标准 ELF 镜像。构建流程：

1. 从 archive 固定原版解密出 ELF，并核对固定 SHA256；
2. 按 NUL 结界提取全部 UTF-8 日文串，与 extracted/eboot 固定提取基线核对；
3. 按 localization/text/eboot_translations.csv（导入源）回写中文：UTF-8
   编码不超过原长度、NUL 填充，不移动或改写任何其他字节；
4. 重建 Vita3K 可直接加载的明文假 SELF：key revision 清零、五个段未压缩
   明文、无法重算的哈希控制记录与元数据区清零、段表指向 0x1000 起的 ELF
   镜像。该格式与多个已在 Vita3K 正常运行的解密版游戏一致。

CLI：--extract 重建提取基线；--check 只做基线与导入源核对，不产出补丁。
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import io
import json
import re
import struct
import sys
import zlib
from pathlib import Path

import Crypto.Cipher.AES

ROOT = Path(__file__).resolve().parents[2]

# 固定原版与解密产物基线；原始 eboot SHA256 与 build_localization.EBOOT_SHA256 一致。
EBOOT_BASELINE = "archive/2026-09/20260908_eboot_pristine.bin"
EBOOT_SHA256 = "f73beefee2c2644e8b2dfa95974451cda50b583e6cfe16cc24664e62a1adc913"
# rif[0x50:0x60] 的 klicensee，按固定值内嵌，构建不依赖 license 目录。
KLICENSE = bytes.fromhex("FC5A72D4A3E87AFC7BC26B123F522336")

EXTRACTION_BASELINE = ROOT / "extracted/eboot/eboot_strings.csv"
TRANSLATIONS = ROOT / "localization/text/eboot_translations.csv"

# SELF 头部布局（PCSG00337 与既有解密版一致）。
HEADER_SIZE = 0x1000
ELF_INFO_OFFSET = 0xA0
PHDR_TABLE_OFFSET = 0xE0
SEGMENT_INFO_OFFSET = 0x180
SEGMENT_INFO_SIZE = 32
# 无法补丁后重算的哈希控制记录区，以及加密元数据区，重建时清零。
DIGEST_CONTROL_RANGE = (0x2C0, 0x390)
STATIC_CONTROL_RANGE = (0x390, 0x600)

# 消息表所在区域；区域外不存在的 UTF-8 日文串不属于文本域。
MESSAGE_REGION = (0x134000, 0x145000)
# 全角空格是消息表中真实存在的独立串，不满足假名/汉字过滤，单独保留。
KEPT_TEXTS = {"\u3000"}
# 玩家可见的系统界面文本（存档对话框标题、截图说明、游戏标题、调试长度提示）。
UI_OFFSETS = {0x135048, 0x1371E4, 0x13720C, 0x139164}

METADATA_KEYS = {
    5: (
        "12D64D0172495226010A687DE245A73DE028B3561E25E69BABC325636F3CAE0A",
        "F149EED1757E5A915B24309795BFC380",
    ),
}
NPDRM_KEY = bytes.fromhex("16419DD3BFBE8BDC596929B72CE237CD")

EXTRACTION_FIELDS = ["id", "offset", "length", "category", "source"]
TRANSLATION_FIELDS = ["id", "offset", "source", "translation", "note"]

# 串字符集：可打印 ASCII、TAB/LF 与三字节 UTF-8（日文所在区段）。
TEXT_RUN = re.compile(rb"(?:[\x20-\x7e\x09\x0a]|[\xe0-\xef][\x80-\xbf][\x80-\xbf])+")


def _sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def _u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def _u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def _u64(data: bytes, offset: int) -> int:
    return struct.unpack_from("<Q", data, offset)[0]


def _set_u64(data: bytearray, offset: int, value: int) -> None:
    struct.pack_into("<Q", data, offset, value)


def _is_text(text: str) -> bool:
    """是否为文本域串：至少一个假名/汉字（全角空格白名单除外），无私有区字符。"""
    if any(0xE000 <= ord(char) <= 0xF8FF for char in text):
        return False
    if text in KEPT_TEXTS:
        return True
    return any("\u3040" <= char <= "\u9fff" for char in text)


def _category(offset: int, text: str) -> str:
    if text in KEPT_TEXTS:
        return "keep"
    if offset in UI_OFFSETS:
        return "ui"
    if MESSAGE_REGION[0] <= offset < MESSAGE_REGION[1]:
        return "msg"
    return "other"


def extract_strings(data: bytes, base_offset: int = 0, region_shift: int = 0) -> list[dict]:
    """提取全部 NUL 结界的 UTF-8 日文串。

    base_offset：数据在所属文件内的起点（记录偏移 = 镜像内偏移 + base_offset）；
    region_shift：消息表区域判断所用的移位，例如假 SELF 中镜像整体后移 0x1000。
    """
    records = []
    for match in TEXT_RUN.finditer(data):
        raw = match.group()
        absolute = base_offset + match.start()
        local = absolute - region_shift
        # NUL 结界检查始终在传入缓冲区内进行；base_offset 只平移记录偏移。
        if len(raw) < 2 or match.end() >= len(data) or data[match.end()] != 0:
            continue
        try:
            text = raw.decode("utf-8")
        except UnicodeDecodeError:
            continue
        # 只收消息表区域内的串：区域外的随机字节也可能恰好解码成 CJK，
        # 回写它们等于改写 ARM 指令，必须排除。
        if not (MESSAGE_REGION[0] <= local < MESSAGE_REGION[1]) and text not in KEPT_TEXTS:
            continue
        if not _is_text(text):
            continue
        if not all(char.isprintable() or char in "\n\t" or char in KEPT_TEXTS for char in text):
            continue
        records.append({
            "offset": absolute,
            "length": len(raw),
            "category": _category(local, text),
            "source": text,
        })
    return records


def decrypt_baseline_eboot() -> bytes:
    """解密固定原版 eboot 并核对两级 SHA256。"""
    self_bytes = (ROOT / EBOOT_BASELINE).read_bytes()
    if _sha256(self_bytes) != EBOOT_SHA256:
        raise ValueError(f"pristine eboot changed: {EBOOT_BASELINE}")
    return decrypt_self_payload(self_bytes)


def decrypt_self_payload(data: bytes) -> bytes:
    """Vita3K sce_utils APP 路径的移植：SELF -> 重定位前 ELF。"""
    if data[:4] != b"SCE\x00":
        raise ValueError("input is not an SCE SELF")
    key_revision = data[9]
    if key_revision not in METADATA_KEYS:
        raise ValueError(f"unsupported APP SELF key revision: {key_revision}")
    metadata_offset = _u32(data, 0x0C)
    header_length = _u64(data, 0x10)
    elf_offset = _u64(data, 0x40)
    phdr_offset = _u64(data, 0x48)
    segment_info_offset = _u64(data, 0x58)
    if data[elf_offset:elf_offset + 4] != b"\x7fELF":
        raise ValueError("embedded ELF header is invalid")

    encrypted = data[metadata_offset + 48:header_length]
    if len(encrypted) < 96:
        raise ValueError("encrypted metadata is too small")
    zero_iv = bytes(16)
    metadata_seed = Crypto.Cipher.AES.new(NPDRM_KEY, Crypto.Cipher.AES.MODE_CBC, zero_iv)\
        .decrypt(KLICENSE)
    metadata_info_wrapped = Crypto.Cipher.AES.new(metadata_seed, Crypto.Cipher.AES.MODE_CBC, zero_iv)\
        .decrypt(encrypted[:64])
    metadata_key_hex, metadata_iv_hex = METADATA_KEYS[key_revision]
    metadata_info = Crypto.Cipher.AES.new(bytes.fromhex(metadata_key_hex), Crypto.Cipher.AES.MODE_CBC,
                                          bytes.fromhex(metadata_iv_hex)).decrypt(metadata_info_wrapped)
    if any(metadata_info[16:32]) or any(metadata_info[48:64]):
        raise ValueError("metadata-info padding is nonzero; SELF decryption key is wrong")
    content_key, content_iv = metadata_info[:16], metadata_info[32:48]
    metadata = Crypto.Cipher.AES.new(content_key, Crypto.Cipher.AES.MODE_CBC, content_iv)\
        .decrypt(encrypted[64:])

    section_count = _u32(metadata, 12)
    key_count = _u32(metadata, 16)
    sections_offset = 32
    vault_offset = sections_offset + section_count * 48
    vault = [metadata[vault_offset + index * 16:vault_offset + (index + 1) * 16]
             for index in range(key_count)]
    sections = {}
    for index in range(section_count):
        offset = sections_offset + index * 48
        if _u32(metadata, offset + 32) != 3:
            continue
        segment_index = struct.unpack_from("<i", metadata, offset + 20)[0]
        sections[segment_index] = {
            "key": vault[struct.unpack_from("<i", metadata, offset + 36)[0]],
            "iv": vault[struct.unpack_from("<i", metadata, offset + 40)[0]],
        }

    phnum = _u16(data, elf_offset + 44)
    phoff = _u32(data, elf_offset + 28)
    if _u16(data, elf_offset + 42) != 32:
        raise ValueError("unsupported program-header size")
    elf_size = 0
    segments = []
    for index in range(phnum):
        phdr = struct.unpack_from("<IIIIIIII", data, phdr_offset + index * 32)
        seg_offset, seg_size, compressed, _encryption, encrypted_flag, _pad = struct.unpack_from(
            "<QQIIII", data, segment_info_offset + index * 32)
        payload = data[seg_offset:seg_offset + seg_size]
        if encrypted_flag == 1:
            section = sections.get(index)
            if section is None:
                raise ValueError(f"missing encrypted metadata section for segment {index}")
            payload = Crypto.Cipher.AES.new(section["key"], Crypto.Cipher.AES.MODE_CTR,
                                            nonce=b"", initial_value=int.from_bytes(section["iv"], "big"))\
                .decrypt(payload)
        if compressed == 2:
            payload = zlib.decompress(payload)
        if len(payload) != phdr[4]:
            raise ValueError(f"segment {index} size mismatch after decrypt: {len(payload)} != {phdr[4]}")
        segments.append((phdr, payload))
        elf_size = max(elf_size, phdr[1] + phdr[4])

    elf = bytearray(elf_size)
    elf[:52] = data[elf_offset:elf_offset + 52]
    elf[phoff:phoff + phnum * 32] = data[phdr_offset:phdr_offset + phnum * 32]
    for phdr, payload in segments:
        elf[phdr[1]:phdr[1] + len(payload)] = payload
    return bytes(elf)


def read_csv_rows(path: Path, fields: list[str]) -> list[dict]:
    with path.open("r", encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream)
        if reader.fieldnames != fields:
            raise ValueError(f"{path}: columns {reader.fieldnames} != {fields}")
        return list(reader)


def csv_bytes(rows: list[dict], fields: list[str]) -> bytes:
    stream = io.StringIO(newline="")
    writer = csv.DictWriter(stream, fieldnames=fields)
    writer.writeheader()
    writer.writerows(rows)
    return stream.getvalue().encode("utf-8-sig")


def extraction_rows(elf: bytes) -> list[dict]:
    """带稳定 id 的提取记录；id 按偏移顺序 ebNNNNNN。"""
    rows = []
    for index, record in enumerate(extract_strings(elf), start=1):
        rows.append({"id": f"eb{index:06d}", **record})
    return rows


def write_extraction_baseline(elf: bytes) -> bytes:
    rows = extraction_rows(elf)
    return csv_bytes([{**{key: row[key] for key in EXTRACTION_FIELDS if key not in ("offset", "length")},
                       "offset": f"0x{row['offset']:08X}", "length": row["length"]}
                      for row in rows], EXTRACTION_FIELDS)


def check_extraction_baseline(elf: bytes) -> dict:
    """新解密结果必须与固定提取基线完全一致，防止解密/算法漂移。"""
    expected = read_csv_rows(EXTRACTION_BASELINE, EXTRACTION_FIELDS)
    actual = extraction_rows(elf)
    if len(expected) != len(actual):
        raise ValueError(f"extraction baseline drift: {len(expected)} baseline != {len(actual)} fresh")
    for want, got in zip(expected, actual):
        if want["id"] != got["id"] or int(want["offset"], 16) != got["offset"] \
                or int(want["length"]) != got["length"] or want["category"] != got["category"] \
                or want["source"] != got["source"]:
            raise ValueError(f"extraction baseline drift at {want['id']}")
    categories = {category: sum(1 for row in actual if row["category"] == category)
                  for category in ("msg", "ui", "keep", "other")}
    return {"records": len(actual), "unique_texts": len({row["source"] for row in actual}),
            "categories": categories}


def load_translations() -> list[dict]:
    """读取导入源；source 必须与提取记录逐条对应。"""
    rows = read_csv_rows(TRANSLATIONS, TRANSLATION_FIELDS)
    for row in rows:
        row["offset"] = int(row["offset"], 16)
    return rows


def apply_translations(elf: bytes, translations: list[dict]) -> tuple[bytes, dict]:
    """原位回写：译文 UTF-8 不超过原长度，NUL 填充，其余字节不动。"""
    baseline = {row["offset"]: row for row in extraction_rows(elf)}
    patched = bytearray(elf)
    translated = empty = 0
    for row in translations:
        record = baseline.get(row["offset"])
        if record is None:
            raise ValueError(f"translation offset {row['offset']:#x} has no extraction record")
        if record["source"] != row["source"]:
            raise ValueError(f"source mismatch at {row['offset']:#x}: {row['source']!r}")
        if not row["translation"]:
            empty += 1
            continue
        encoded = row["translation"].encode("utf-8")
        if len(encoded) > record["length"]:
            raise ValueError(f"translation exceeds budget at {row['offset']:#x}: "
                             f"{len(encoded)} > {record['length']}")
        start = row["offset"]
        patched[start:start + len(encoded)] = encoded
        patched[start + len(encoded):start + record["length"]] = bytes(record["length"] - len(encoded))
        translated += 1
    missing = sorted(set(baseline) - {row["offset"] for row in translations})
    if missing:
        raise ValueError(f"extraction records missing from import source: "
                         f"{[f'{offset:#x}' for offset in missing[:4]]}")
    return bytes(patched), {"records": len(baseline), "translated": translated,
                            "kept_japanese": empty}


def verify_patched_elf(elf: bytes, patched: bytes, translations: list[dict]) -> None:
    """补丁复核：仅译文区间变化，且重提取结果与导入源逐条一致。"""
    if len(elf) != len(patched):
        raise ValueError("patched ELF size changed")
    baseline = {row["offset"]: row for row in extraction_rows(elf)}
    ranges = [(row["offset"], row["offset"] + baseline[row["offset"]]["length"])
              for row in translations]
    for index in range(len(elf)):
        if elf[index] != patched[index] and not any(start <= index < end for start, end in ranges):
            raise ValueError(f"byte {index:#x} changed outside translation ranges")
    extracted = {row["offset"]: row["source"] for row in extract_strings(patched)}
    for row in translations:
        expected_text = row["translation"] or row["source"]
        if extracted.get(row["offset"]) != expected_text:
            raise ValueError(f"re-extraction mismatch at {row['offset']:#x}")


def rebuild_fake_self(patched_elf: bytes, baseline_self: bytes) -> bytes:
    """基于固定原版头部重建明文假 SELF，附加补丁后的 ELF 镜像。"""
    if baseline_self[:4] != b"SCE\x00":
        raise ValueError("baseline SELF header is invalid")
    header = bytearray(baseline_self[:HEADER_SIZE])
    if header[STATIC_CONTROL_RANGE[0]:STATIC_CONTROL_RANGE[1]] != \
            baseline_self[STATIC_CONTROL_RANGE[0]:STATIC_CONTROL_RANGE[1]]:
        raise ValueError("static control records must stay untouched")

    elf_offset = _u64(baseline_self, 0x40)
    phdr_offset = _u64(baseline_self, 0x48)
    segment_info_offset = _u64(baseline_self, 0x58)
    phnum = _u16(patched_elf, 0x2C)
    phoff = _u32(patched_elf, 0x1C)
    phentsize = _u16(patched_elf, 0x2A)
    if phentsize != 32:
        raise ValueError("unsupported program-header size")

    # 头部内的 ELF 头/段表副本与镜像保持一致（补丁不改动它们）。
    header[elf_offset:elf_offset + 52] = patched_elf[:52]
    header[phdr_offset:phdr_offset + phnum * 32] = patched_elf[phoff:phoff + phnum * 32]

    header[8] = 0xC0  # 明文 SELF 标记，与既有解密版游戏一致
    header[9] = 0x00  # key revision 清零
    start, end = DIGEST_CONTROL_RANGE
    header[start:end] = bytes(end - start)
    header[0x600:HEADER_SIZE] = bytes(HEADER_SIZE - 0x600)

    extent = 0
    for index in range(phnum):
        p_offset = _u32(patched_elf, phoff + index * 32 + 4)
        p_filesz = _u32(patched_elf, phoff + index * 32 + 16)
        struct.pack_into("<QQIIII", header, segment_info_offset + index * SEGMENT_INFO_SIZE,
                         HEADER_SIZE + p_offset, p_filesz, 1, 0, 2, 0)
        extent = max(extent, p_offset + p_filesz)
    if _u64(baseline_self, 0x18) != extent:
        raise ValueError("ELF extent changed; in-place patch expected")
    _set_u64(header, 0x18, extent)
    _set_u64(header, 0x20, HEADER_SIZE + extent)
    return bytes(header) + patched_elf


def inspect_fake_self(data: bytes) -> dict:
    """解析明文假 SELF 结构并提取其中全部文本；独立验证共用。"""
    if data[:4] != b"SCE\x00":
        raise ValueError("installed eboot is not an SCE SELF")
    if data[9] != 0:
        raise ValueError("installed eboot still declares a key revision")
    header_length = _u64(data, 0x10)
    if header_length != HEADER_SIZE:
        raise ValueError(f"unexpected header length {header_length:#x}")
    segment_info_offset = _u64(data, 0x58)
    elf_offset = _u64(data, 0x40)
    if data[elf_offset:elf_offset + 4] != b"\x7fELF":
        raise ValueError("installed eboot lacks an ELF header")
    phnum = _u16(data, elf_offset + 44)
    phdr_table = _u64(data, 0x48)
    extent = 0
    segments = []
    for index in range(phnum):
        p_offset = _u32(data, phdr_table + index * 32 + 4)
        p_filesz = _u32(data, phdr_table + index * 32 + 16)
        info = struct.unpack_from("<QQIIII", data, segment_info_offset + index * SEGMENT_INFO_SIZE)
        if info[0] != HEADER_SIZE + p_offset or info[1] != p_filesz:
            raise ValueError(f"segment {index} info does not match the ELF program header")
        if info[2] != 1 or info[3] != 0 or info[4] != 2:
            raise ValueError(f"segment {index} is not plaintext/uncompressed")
        segments.append({"index": index, "offset": p_offset, "filesz": p_filesz})
        extent = max(extent, p_offset + p_filesz)
    if _u64(data, 0x20) != len(data) or _u64(data, 0x18) != extent:
        raise ValueError("installed eboot size fields do not match its layout")
    if any(data[0x600:HEADER_SIZE]):
        raise ValueError("installed eboot metadata area is not cleared")
    elf = data[HEADER_SIZE:HEADER_SIZE + extent]
    records = extract_strings(elf, base_offset=HEADER_SIZE, region_shift=HEADER_SIZE)
    return {"size": len(data), "elf_extent": extent, "segments": segments,
            "sha256": _sha256(data), "strings": records}


def build_eboot_bundle() -> dict:
    """完整 eboot 域构建：解密 -> 核对 -> 回写 -> 重建假 SELF。"""
    baseline_self = (ROOT / EBOOT_BASELINE).read_bytes()
    if _sha256(baseline_self) != EBOOT_SHA256:
        raise ValueError(f"pristine eboot changed: {EBOOT_BASELINE}")
    elf = decrypt_self_payload(baseline_self)
    extraction = check_extraction_baseline(elf)
    translations = load_translations()
    patched, patch_report = apply_translations(elf, translations)
    verify_patched_elf(elf, patched, translations)
    installed = rebuild_fake_self(patched, baseline_self)
    inspected = inspect_fake_self(installed)
    installed_strings = {row["offset"] - HEADER_SIZE: row["source"] for row in inspected["strings"]}
    if len(inspected["strings"]) != len(translations):
        raise ValueError(f"installed self has {len(inspected['strings'])} strings, expected {len(translations)}")
    for row in translations:
        found = installed_strings.get(row["offset"])
        if found is None or found != (row["translation"] or row["source"]):
            raise ValueError(f"installed self mismatch at {row['offset']:#x}")
    report = {
        "baseline": EBOOT_BASELINE,
        "baseline_sha256": EBOOT_SHA256,
        "elf_sha256": _sha256(elf),
        "extraction": extraction,
        "patch": patch_report,
        "installed_sha256": _sha256(installed),
        "installed_bytes": len(installed),
        "format": "plaintext fake SELF (key revision 0, uncompressed segments), Vita3K verified pattern",
    }
    return {"files": {"eboot.bin": installed}, "report": report}


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--extract", action="store_true", help="rebuild the extraction baseline CSV")
    mode.add_argument("--check", action="store_true", help="validate baseline and import source only")
    args = parser.parse_args(argv)
    elf = decrypt_baseline_eboot()
    if args.extract:
        EXTRACTION_BASELINE.parent.mkdir(parents=True, exist_ok=True)
        EXTRACTION_BASELINE.write_bytes(write_extraction_baseline(elf))
        summary = check_extraction_baseline(elf)
        print(json.dumps(summary, ensure_ascii=False, indent=2))
        return 0
    summary = check_extraction_baseline(elf)
    translations = load_translations()
    budget = [(row["id"], len(row["translation"].encode("utf-8")))
              for row in translations if row["translation"]]
    print(json.dumps({"extraction": summary, "translations": len(translations),
                      "translated": len(budget), "max_budget_bytes": max(b for _, b in budget)},
                     ensure_ascii=False, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
