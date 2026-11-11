#!/usr/bin/env python3
"""Extract text, zlib payloads, and font candidates from this Vita game dump."""

from __future__ import annotations

import argparse
import csv
import json
import re
import struct
import unicodedata
import zlib
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
OUT_ROOT = ROOT / "extracted"
ZLIB_RE = re.compile(rb"\x78[\x01\x5e\x9c\xda]")
PRINTABLE_ASCII_RE = re.compile(rb"[\x20-\x7e]{4,}")
SJIS_LEADS = set(range(0x81, 0xA0)) | set(range(0xE0, 0xF0))
SJIS_TRAILS = set(range(0x40, 0x7F)) | set(range(0x80, 0xFD))
HALFWIDTH_KANA = set(range(0xA1, 0xE0))


def halfwidth_to_buriko_char(text: str) -> str:
    converted = unicodedata.normalize("NFKC", text)
    out = []
    for ch in converted:
        code = ord(ch)
        if ch == "｡":
            out.append("。")
        elif ch == "､":
            out.append("、")
        elif 0x30A1 <= code <= 0x30F6:
            out.append(chr(code - 0x60))
        else:
            out.append(ch)
    return "".join(out)


SINGLE_BYTE_TABLE = {
    value: halfwidth_to_buriko_char(bytes([value]).decode("cp932"))
    for value in range(0xA1, 0xE0)
}


@dataclass
class ZlibStream:
    source: str
    offset: int
    compressed_size: int
    decompressed_size: int
    payload: bytes


def read_sections(path: Path) -> dict[str, bytes]:
    data = path.read_bytes()
    if data[:4] != b"DCFS":
        raise ValueError(f"{path} is not a DCFS map")
    sections: dict[str, bytes] = {}
    off = 28
    while off + 8 <= len(data):
        tag = data[off : off + 4].decode("ascii", errors="replace")
        size = struct.unpack_from("<I", data, off + 4)[0]
        payload = data[off + 8 : off + 8 + size]
        sections[tag] = payload
        off += 8 + size
    return sections


def parse_names(payload: bytes) -> list[str]:
    if len(payload) < 4:
        return []
    names_size = struct.unpack_from("<I", payload, 0)[0]
    raw = payload[4 : 4 + names_size]
    return [part.decode("ascii", errors="replace") for part in raw.split(b"\0") if part]


def dcfs_summary(map_dir: Path) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for path in sorted(map_dir.glob("*.map")):
        sections = read_sections(path)
        names = parse_names(sections.get("NAME", b""))
        rows.append(
            {
                "map": path.name,
                "sections": {key: len(value) for key, value in sections.items()},
                "names": names,
            }
        )
    return rows


def scan_zlib(path: Path) -> list[ZlibStream]:
    data = path.read_bytes()
    streams: list[ZlibStream] = []
    for match in ZLIB_RE.finditer(data):
        off = match.start()
        dec = zlib.decompressobj()
        try:
            payload = dec.decompress(data[off:])
            payload += dec.flush()
        except zlib.error:
            continue
        consumed = len(data[off:]) - len(dec.unused_data)
        if consumed <= 2 or not payload:
            continue
        streams.append(
            ZlibStream(
                source=path.name,
                offset=off,
                compressed_size=consumed,
                decompressed_size=len(payload),
                payload=payload,
            )
        )
    return streams


def parse_sized_sections(data: bytes, start: int) -> list[tuple[str, int, int, bytes]]:
    sections: list[tuple[str, int, int, bytes]] = []
    off = start
    while off + 8 <= len(data):
        tag_raw = data[off : off + 4]
        if not all(32 <= b <= 126 for b in tag_raw):
            break
        size = struct.unpack_from("<I", data, off + 4)[0]
        if size < 8 or off + size > len(data):
            break
        tag = tag_raw.decode("ascii", errors="replace")
        sections.append((tag, off, size, data[off + 8 : off + size]))
        off += size
    return sections


def dcvm_sections(payload: bytes) -> list[tuple[str, int, int, bytes]]:
    if not payload.startswith(b"DCVM"):
        return []
    return parse_sized_sections(payload, 0x10)


def dcft_sections(payload: bytes) -> list[tuple[str, int, int, bytes]]:
    if not payload.startswith(b"DCFT"):
        return []
    return parse_sized_sections(payload, 0x40)


def iter_str_records(payload: bytes) -> list[bytes]:
    records: list[bytes] = []
    for tag, _off, _size, section in dcvm_sections(payload):
        if tag != "STR ":
            continue
        raw = section[8:] if len(section) >= 8 else section
        for part in raw.split(b"\0"):
            if len(part) >= 2:
                records.append(part)
    return records


def decode_cp932_lossy(raw: bytes) -> str:
    return raw.decode("cp932", errors="ignore")


def decode_buriko(raw: bytes) -> str:
    out = []
    i = 0
    while i < len(raw):
        value = raw[i]
        if value in HALFWIDTH_KANA:
            out.append(SINGLE_BYTE_TABLE.get(value, ""))
            i += 1
        elif value in SJIS_LEADS and i + 1 < len(raw) and raw[i + 1] in SJIS_TRAILS:
            out.append(raw[i : i + 2].decode("cp932", errors="ignore"))
            i += 2
        elif 0x20 <= value <= 0x7E:
            out.append(chr(value))
            i += 1
        else:
            try:
                out.append(bytes([value]).decode("cp932"))
            except UnicodeDecodeError:
                pass
            i += 1
    return "".join(out)


def looks_like_text(text: str) -> bool:
    if len(text.strip()) < 2:
        return False
    useful = 0
    for ch in text:
        code = ord(ch)
        if ch in "\r\n\t":
            useful += 1
        elif 0x20 <= code <= 0x7E:
            useful += 1
        elif 0x3040 <= code <= 0x30FF:
            useful += 2
        elif 0x3400 <= code <= 0x9FFF:
            useful += 2
        elif 0xFF00 <= code <= 0xFFEF:
            useful += 1
    return useful >= max(2, len(text) // 2)


def has_japanese(text: str) -> bool:
    return any(
        0x3040 <= ord(ch) <= 0x30FF or 0x3400 <= ord(ch) <= 0x9FFF
        for ch in text
    )


def classify_string(text: str) -> str:
    if has_japanese(text):
        return "jp"
    if "/" in text or text.endswith(".s"):
        return "path"
    if re.search(r"[A-Za-z_]{3,}", text):
        return "symbol"
    return "other"


def unique_charset(strings: list[str]) -> list[str]:
    chars = set()
    for text in strings:
        for ch in text:
            if ch not in "\r\n\t" and not (0 <= ord(ch) < 0x20):
                chars.add(ch)
    return sorted(chars, key=lambda ch: (ord(ch), ch))


def cp932_table(chars: list[str]) -> list[tuple[str, str]]:
    table: list[tuple[str, str]] = []
    for ch in chars:
        try:
            code = ch.encode("cp932")
        except UnicodeEncodeError:
            continue
        table.append((code.hex(" ").upper(), ch))
    return table


def collect_code_table(raw_records: list[bytes]) -> list[dict[str, object]]:
    counts: dict[tuple[str, str, str], int] = {}
    for raw in raw_records:
        i = 0
        while i < len(raw):
            value = raw[i]
            if value in HALFWIDTH_KANA:
                code = f"{value:02X}"
                char = SINGLE_BYTE_TABLE.get(value, "")
                source = "buriko_singlebyte"
                i += 1
            elif value in SJIS_LEADS and i + 1 < len(raw) and raw[i + 1] in SJIS_TRAILS:
                chunk = raw[i : i + 2]
                code = chunk.hex(" ").upper()
                char = chunk.decode("cp932", errors="ignore")
                source = "cp932_doublebyte"
                i += 2
            elif 0x20 <= value <= 0x7E:
                code = f"{value:02X}"
                char = chr(value)
                source = "ascii"
                i += 1
            else:
                i += 1
                continue
            if char:
                counts[(code, char, source)] = counts.get((code, char, source), 0) + 1
    rows = [
        {"code_hex": code, "char": char, "source": source, "count": count}
        for (code, char, source), count in counts.items()
    ]
    rows.sort(key=lambda row: (row["source"], row["code_hex"], row["char"]))
    return rows


def write_zlib_outputs(kind: str, streams: list[ZlibStream]) -> None:
    out_dir = OUT_ROOT / kind / "zlib"
    out_dir.mkdir(parents=True, exist_ok=True)
    manifest = []
    for idx, stream in enumerate(streams):
        name = f"{idx:04d}_{stream.offset:08X}.bin"
        (out_dir / name).write_bytes(stream.payload)
        manifest.append(
            {
                "file": name,
                "source": stream.source,
                "offset": stream.offset,
                "compressed_size": stream.compressed_size,
                "decompressed_size": stream.decompressed_size,
                "magic": stream.payload[:16].hex(" "),
            }
        )
    (out_dir / "manifest.json").write_text(
        json.dumps(manifest, ensure_ascii=False, indent=2), encoding="utf-8"
    )


def write_text_outputs(streams: list[ZlibStream]) -> None:
    out_dir = OUT_ROOT / "script"
    out_dir.mkdir(parents=True, exist_ok=True)
    rows = []
    all_text: list[str] = []
    raw_records: list[bytes] = []
    for stream in streams:
        records = iter_str_records(stream.payload)
        raw_records.extend(records)
        for raw in records:
            raw_cp932 = decode_cp932_lossy(raw)
            text = decode_buriko(raw)
            if not looks_like_text(text):
                continue
            category = classify_string(text)
            rows.append(
                {
                    "offset": f"0x{stream.offset:08X}",
                    "compressed_size": stream.compressed_size,
                    "decompressed_size": stream.decompressed_size,
                    "category": category,
                    "raw_hex": raw.hex(" ").upper(),
                    "raw_cp932": raw_cp932,
                    "text": text,
                }
            )
            if category == "jp":
                all_text.append(text)
    with (out_dir / "script_strings.csv").open("w", encoding="utf-8-sig", newline="") as f:
        writer = csv.DictWriter(
            f,
            fieldnames=[
                "offset",
                "compressed_size",
                "decompressed_size",
                "category",
                "raw_hex",
                "raw_cp932",
                "text",
            ],
        )
        writer.writeheader()
        writer.writerows(rows)
    (out_dir / "script_strings.txt").write_text(
        "\n".join(dict.fromkeys(row["text"] for row in rows)), encoding="utf-8"
    )
    (out_dir / "script_text.txt").write_text(
        "\n".join(dict.fromkeys(all_text)), encoding="utf-8"
    )
    chars = unique_charset(all_text)
    (out_dir / "charset.txt").write_text("".join(chars), encoding="utf-8")
    with (out_dir / "cp932_table.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f, delimiter="\t")
        writer.writerow(["cp932_hex", "char"])
        writer.writerows(cp932_table(chars))
    with (out_dir / "custom_code_table.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=["code_hex", "char", "source", "count"], delimiter="\t")
        writer.writeheader()
        writer.writerows(collect_code_table(raw_records))
    with (out_dir / "buriko_singlebyte_kana_table.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f, delimiter="\t")
        writer.writerow(["code_hex", "cp932_halfwidth", "buriko_char"])
        for value, char in SINGLE_BYTE_TABLE.items():
            writer.writerow([f"{value:02X}", bytes([value]).decode("cp932"), char])


def classify_rodata_payloads(streams: list[ZlibStream]) -> list[dict[str, object]]:
    rows = []
    for stream in streams:
        payload = stream.payload
        magic = payload[:16]
        kind = "unknown"
        if payload.startswith(b"\x89PNG"):
            kind = "png"
        elif payload.startswith(b"GXT"):
            kind = "gxt"
        elif payload.startswith(b"DDS "):
            kind = "dds"
        elif payload.startswith((b"BM", b"\x00\x01\x00\x00", b"OTTO", b"ttcf")):
            kind = "font_or_bitmap"
        elif payload.startswith(b"DCFT"):
            kind = "dcft_font"
        elif len(payload) > 1024 and payload.count(b"\0") > len(payload) // 5:
            kind = "binary_table_or_texture"
        ascii_hits = [
            hit.decode("ascii", errors="replace")
            for hit in PRINTABLE_ASCII_RE.findall(payload[:4096])[:8]
        ]
        rows.append(
            {
                "offset": f"0x{stream.offset:08X}",
                "compressed_size": stream.compressed_size,
                "decompressed_size": stream.decompressed_size,
                "kind": kind,
                "magic": magic.hex(" "),
                "ascii_preview": " | ".join(ascii_hits),
            }
        )
    return rows


def write_rodata_report(streams: list[ZlibStream]) -> None:
    out_dir = OUT_ROOT / "rodata"
    out_dir.mkdir(parents=True, exist_ok=True)
    rows = classify_rodata_payloads(streams)
    with (out_dir / "rodata_zlib_report.csv").open("w", encoding="utf-8-sig", newline="") as f:
        writer = csv.DictWriter(
            f,
            fieldnames=[
                "offset",
                "compressed_size",
                "decompressed_size",
                "kind",
                "magic",
                "ascii_preview",
            ],
        )
        writer.writeheader()
        writer.writerows(rows)


def write_font_outputs(streams: list[ZlibStream]) -> None:
    out_dir = OUT_ROOT / "rodata" / "font_dcft"
    tables_dir = out_dir / "fnt_tables"
    out_dir.mkdir(parents=True, exist_ok=True)
    tables_dir.mkdir(parents=True, exist_ok=True)
    section_rows = []
    for idx, stream in enumerate(streams):
        if not stream.payload.startswith(b"DCFT"):
            continue
        base = f"{idx:04d}_{stream.offset:08X}"
        target = out_dir / f"{base}.dcft"
        target.write_bytes(stream.payload)
        for tag, section_offset, size, section_payload in dcft_sections(stream.payload):
            section_rows.append(
                {
                    "font": target.name,
                    "section": tag,
                    "offset": f"0x{section_offset:08X}",
                    "size": size,
                    "payload_size": len(section_payload),
                }
            )
            if tag == "@FNT":
                values = [
                    struct.unpack_from("<H", section_payload, pos)[0]
                    for pos in range(0, len(section_payload) - 1, 2)
                ]
                with (tables_dir / f"{base}_fnt.tsv").open("w", encoding="utf-8", newline="") as f:
                    writer = csv.writer(f, delimiter="\t")
                    writer.writerow(["index", "value_hex", "value_dec"])
                    for pos, value in enumerate(values):
                        writer.writerow([pos, f"0x{value:04X}", value])
    with (out_dir / "dcft_sections.csv").open("w", encoding="utf-8-sig", newline="") as f:
        writer = csv.DictWriter(
            f,
            fieldnames=["font", "section", "offset", "size", "payload_size"],
        )
        writer.writeheader()
        writer.writerows(section_rows)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=ROOT)
    args = parser.parse_args()

    root = args.root.resolve()
    out = root / "extracted"
    out.mkdir(exist_ok=True)

    summary = dcfs_summary(root / "map")
    (out / "dcfs_summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2), encoding="utf-8"
    )

    script_streams = scan_zlib(root / "rom" / "script.rom")
    rodata_streams = scan_zlib(root / "rom" / "rodata.rom")
    write_zlib_outputs("script", script_streams)
    write_zlib_outputs("rodata", rodata_streams)
    write_text_outputs(script_streams)
    write_rodata_report(rodata_streams)
    write_font_outputs(rodata_streams)

    print(f"script zlib streams: {len(script_streams)}")
    print(f"rodata zlib streams: {len(rodata_streams)}")
    print(f"output: {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
