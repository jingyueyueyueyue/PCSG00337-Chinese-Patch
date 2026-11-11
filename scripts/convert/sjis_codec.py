#!/usr/bin/env python3
"""Validate the engine's SJIS scanner, including custom Chinese glyph codes.

A0..DF are single-byte characters, never double-byte leads. A custom code
must obey the same byte boundaries as a native code; a font cannot fix an
illegal trail byte or a NUL embedded in a string.
"""
from __future__ import annotations

from collections.abc import Mapping


def is_lead(value: int) -> bool:
    return 0x81 <= value <= 0x9F or 0xE0 <= value <= 0xFC


def is_trail(value: int) -> bool:
    return 0x40 <= value <= 0xFC and value != 0x7F


def tokenize(data: bytes) -> tuple[bytes, ...]:
    parts = []
    offset = 0
    while offset < len(data):
        value = data[offset]
        if value == 0:
            raise ValueError(f"embedded NUL at byte {offset}")
        width = 2 if is_lead(value) else 1
        if width == 2:
            if offset + 1 >= len(data) or not is_trail(data[offset + 1]):
                raise ValueError(f"invalid SJIS character at byte {offset}: {data[offset:offset+2].hex()}")
        parts.append(data[offset:offset + width])
        offset += width
    return tuple(parts)


def validate_code_bytes(data: bytes) -> None:
    if tokenize(data) != (data,):
        raise ValueError(f"not one complete character: {data.hex()}")


def encode_string(text: str, code_table: Mapping[str, bytes]) -> bytes:
    parts = []
    for char in text:
        encoded = code_table.get(char)
        if encoded is None:
            encoded = char.encode("cp932")
        validate_code_bytes(encoded)
        parts.append(encoded)
    result = b"".join(parts)
    if tokenize(result) != tuple(parts):
        raise ValueError("engine scanner changed the intended character boundaries")
    return result


def decode_string(data: bytes, code_table: Mapping[str, bytes]) -> str:
    reverse = {}
    for char, encoded in code_table.items():
        if encoded in reverse and reverse[encoded] != char:
            raise ValueError(f"ambiguous code: {encoded.hex()}")
        reverse[encoded] = char
    chars = []
    for part in tokenize(data):
        char = reverse.get(part)
        if char is None:
            char = part.decode("cp932")
        chars.append(char)
    return "".join(chars)
