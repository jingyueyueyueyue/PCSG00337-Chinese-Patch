#!/usr/bin/env python3
"""Build PCSG00337 text, code table, six fonts and both resource indexes.

Default / --dry-run validates in memory. --out-dir stages a complete release.
--apply installs only after validation, with process guards and rollback.
Use --formal-only when editing translation_source.csv directly instead of
work/b*.tsv. Original Japanese extraction and pristine resources never change.
"""
from __future__ import annotations

import argparse
from datetime import datetime
import hashlib
import json
import os
from pathlib import Path
import shutil
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts/convert"))
import reset_font_code_table
import sync_translation_source
import build_font
import eboot_text
import import_script_text

BASELINES = {
    "archive/2026-09/20260907_script.rom": "75a23c47863cf77a9d0451df34f84e323d1478a50309fd0bb6001a1fbf7d7dfd",
    "archive/2026-09/20260908_script_map_pristine.map": "4ef71dc0a7ec6c93114922aa9786f87a21ebcf25da040db49f970f42f90306d3",
    "archive/2026-09/20260908_rodata_pristine.rom": "f5d681a7b14d1d5ae642a26e17023a409141d455d33d0da4a33654f7096033b8",
    "archive/2026-09/20260908_rodata_map_pristine.map": "00f03d815a89ab0fb6cd90927dd36c3d78d9329148ce2a6395f351e3f343e174",
    "archive/2026-09/20260908_eboot_pristine.bin": eboot_text.EBOOT_SHA256,
}
EBOOT_SHA256 = eboot_text.EBOOT_SHA256
LOCK = "localization/rebuild/import.lock"


def fingerprint(data: bytes) -> dict:
    return {"bytes": len(data), "sha256": hashlib.sha256(data).hexdigest()}


def json_bytes(value) -> bytes:
    return (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8")


def active_game_pids() -> list[int]:
    """Observe this title's Windows windows; never change focus or terminate apps."""
    if os.name != "nt":
        return []
    import ctypes as C
    from ctypes import wintypes as W
    user = C.WinDLL("user32", use_last_error=True)
    callback_type = C.WINFUNCTYPE(W.BOOL, W.HWND, W.LPARAM)
    user.EnumWindows.argtypes = [callback_type, W.LPARAM]
    user.EnumWindows.restype = W.BOOL
    user.GetWindowTextW.argtypes = [W.HWND, W.LPWSTR, C.c_int]
    user.GetWindowTextW.restype = C.c_int
    user.GetWindowThreadProcessId.argtypes = [W.HWND, C.POINTER(W.DWORD)]
    user.GetWindowThreadProcessId.restype = W.DWORD
    pids = set()
    titled = set()

    @callback_type
    def visit(hwnd, _):
        title = C.create_unicode_buffer(1024)
        user.GetWindowTextW(hwnd, title, len(title))
        if "PCSG00337" in title.value or "いますぐお兄ちゃんに妹だっていいたい" in title.value:
            pid = W.DWORD()
            user.GetWindowThreadProcessId(hwnd, C.byref(pid))
            titled.add(pid.value)
        return True

    if not user.EnumWindows(visit, 0):
        raise C.WinError(C.get_last_error())
    # Only an emulator window proves the game is running: file explorers and
    # editors browsing this folder can carry the same title string.
    import psutil
    for pid in sorted(titled):
        try:
            if psutil.Process(pid).name().lower() == "vita3k.exe":
                pids.add(pid)
        except psutil.NoSuchProcess:
            continue
        except psutil.AccessDenied:
            pids.add(pid)  # fail closed when the window owner cannot be identified
    # A CLI-launched game may still be loading before its title window exists.
    for process in psutil.process_iter(["pid", "name"]):
        if (process.info["name"] or "").lower() != "vita3k.exe":
            continue
        try:
            if any("PCSG00337" in value for value in process.cmdline()):
                pids.add(process.pid)
        except psutil.NoSuchProcess:
            continue
        except psutil.AccessDenied as error:
            raise RuntimeError("cannot inspect a running Vita3K process safely") from error
    return sorted(pids)


def input_paths(formal_only: bool) -> list[Path]:
    paths = [ROOT / path for path in BASELINES]
    paths += [eboot_text.EXTRACTION_BASELINE, eboot_text.TRANSLATIONS,
              reset_font_code_table.SCRIPT_STRINGS,
              reset_font_code_table.ORIGINAL_TABLE, reset_font_code_table.SINGLE_BYTE_TABLE,
              sync_translation_source.FORMAL, reset_font_code_table.GENERATED_DIR / "font_code_table_reset.tsv"]
    if not formal_only:
        paths += [ROOT / "extracted/script/block_map.json", sync_translation_source.WORK / "manifest.json"]
        paths += sorted(sync_translation_source.WORK.glob("b*.tsv"))
    return list(dict.fromkeys(path for path in paths if path.exists()))


def build_release(*, formal_only=False) -> tuple[dict[str, bytes], dict]:
    if (ROOT / LOCK).exists():
        raise RuntimeError("an import is active or was interrupted; inspect localization/rebuild/import.lock before building")
    paths = input_paths(formal_only)
    before = {path: fingerprint(path.read_bytes()) for path in paths}
    for relative, expected in BASELINES.items():
        actual = fingerprint((ROOT / relative).read_bytes())
        if actual["sha256"] != expected:
            raise ValueError(f"pristine baseline changed: {relative}")
    text = sync_translation_source.build_translation_bundle(formal_only=formal_only)
    print(f"Text: {text['report']['translated_rows']}/{text['report']['rows']} rows translated; original row checks passed", flush=True)
    codes = reset_font_code_table.build_code_table_bundle(text["data"], native_codes=build_font.native_codepoints())
    print(f"Codes: {codes['report']['total_chars']} characters, {codes['report']['private_reset_chars']} custom glyph codes", flush=True)
    font = build_font.build_font_bundle(code_table=codes["table"])
    print("Fonts: six slots rebuilt with uniform text styling; glyph and index read-back verified", flush=True)
    script = import_script_text.build_script_bundle(codes["table"], translation_data=text["data"])
    print("Script: original-based text rebuild, checksums and both archive indexes passed", flush=True)
    eboot = eboot_text.build_eboot_bundle()
    print(f"Eboot: {eboot['report']['patch']['translated']}/{eboot['report']['extraction']['records']} strings translated; fake SELF verified", flush=True)
    files = dict(codes["files"])
    files.update({
        "rom/script.rom": script["rom"], "map/script.map": script["map"],
        "rom/rodata.rom": font["rom"], "map/rodata.map": font["map"],
        "localization/text/translation_source.csv": text["data"],
        "localization/font/generated/font_preview.png": font["preview_png"],
        "eboot.bin": eboot["files"]["eboot.bin"],
    })
    for path, expected in before.items():
        if not path.exists() or fingerprint(path.read_bytes()) != expected:
            raise RuntimeError(f"input changed during build; save translations and retry: {path}")
    sources = {path.relative_to(ROOT).as_posix(): value for path, value in before.items()
               if path.relative_to(ROOT).as_posix() not in files
               and path.relative_to(ROOT).as_posix() not in BASELINES}
    report = {
        "format_version": 1, "title_id": "PCSG00337", "compression": "zlib level 9",
        "eboot_sha256": EBOOT_SHA256, "translation_source": "formal" if formal_only else "batches",
        "baseline": {path: before[ROOT / path] for path in BASELINES}, "sources": sources,
        "translation_sync": text["report"], "code_table": codes["report"],
        "font": font["report"], "script": script["report"], "eboot": eboot["report"],
        "runtime_visual_validation": "separate game test required; see localization/reports/runtime_validation.json",
        "files": {name: fingerprint(data) for name, data in files.items()},
    }
    files["localization/build_manifest.json"] = json_bytes(report)
    return files, report


def stage_outputs(files: dict[str, bytes], directory: Path) -> None:
    directory = directory.resolve()
    if (ROOT / "archive").resolve() not in directory.parents:
        raise ValueError("use archive/YYYY-MM/YYYYMMDD_name for release candidates")
    targets = {safe_target(directory, name): data for name, data in files.items()}
    for path, data in targets.items():
        if path.exists() and path.read_bytes() != data:
            raise FileExistsError(f"candidate contains different files: {path}")
    for path, data in targets.items():
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)


def safe_target(root: Path, relative: str) -> Path:
    path = (root / relative).resolve()
    if Path(relative).is_absolute() or root.resolve() not in path.parents:
        raise ValueError(f"release path outside workspace: {relative}")
    return path


def install_outputs(files: dict[str, bytes], *, root: Path = ROOT, running_check=active_game_pids,
                    replace=os.replace, installed_check=None) -> Path | None:
    """Prepare full files, atomically replace each, and restore the set on error.

    The injectable root and replace operation exercise rollback in an isolated
    temporary workspace. They never bypass the real process guard in the CLI.
    """
    root = root.resolve()
    if running_check():
        raise RuntimeError("PCSG00337 is running; close this game before --apply. No files changed.")
    targets = {safe_target(root, name): data for name, data in files.items()}
    originals = {path: path.read_bytes() if path.exists() else None for path in targets}
    if all(originals[path] == data for path, data in targets.items()):
        return None
    archive = root / "archive" / datetime.now().strftime("%Y-%m")
    backup = archive / f"{datetime.now():%Y%m%d}_before_release_{datetime.now():%H%M%S_%f}"
    lock_path = root / LOCK
    lock_path.parent.mkdir(parents=True, exist_ok=True)
    # O_EXCL prevents two importers from preparing incompatible releases.
    descriptor = os.open(lock_path, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
    temporary = []
    replaced = []
    rollback_failed = False

    def prepare(path, data):
        path.parent.mkdir(parents=True, exist_ok=True)
        with tempfile.NamedTemporaryFile(dir=path.parent, prefix=".localization_", suffix=".stage", delete=False) as stream:
            staged = Path(stream.name)
            temporary.append(staged)
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        return staged

    try:
        with os.fdopen(descriptor, "wb") as stream:
            stream.write(json_bytes({"pid": os.getpid(), "backup": str(backup),
                                     "targets": {str(path.relative_to(root)): fingerprint(data) if data is not None else None
                                                 for path, data in originals.items()}}))
            stream.flush()
            os.fsync(stream.fileno())
        prepared = {path: prepare(path, data) for path, data in targets.items()}
        for path, data in originals.items():
            if data is not None:
                saved = backup / path.relative_to(root)
                saved.parent.mkdir(parents=True, exist_ok=True)
                saved.write_bytes(data)
        if running_check():
            raise RuntimeError("the game started during staging; installation cancelled")
        for path, data in targets.items():
            if originals[path] != data:
                replace(prepared[path], path)
                replaced.append(path)
        if any(path.read_bytes() != data for path, data in targets.items()):
            raise OSError("installed file read-back mismatch")
        if installed_check is not None:
            check = installed_check()
            if not check.get("ok"):
                raise ValueError("independent installed verification failed: " + "; ".join(check.get("errors", [])))
    except BaseException:
        try:
            for path in reversed(replaced):
                old = originals[path]
                if old is None:
                    path.unlink(missing_ok=True)
                else:
                    os.replace(prepare(path, old), path)
            if any((path.read_bytes() if path.exists() else None) != old for path, old in originals.items()):
                raise OSError("rollback verification failed")
        except BaseException:
            rollback_failed = True
            raise
        raise
    finally:
        for path in temporary:
            if path.exists():
                # Files used only for staging are disposable, scoped under root.
                safe_target(root, path.relative_to(root).as_posix()).unlink()
        if not rollback_failed:
            lock_path.unlink(missing_ok=True)
    return backup


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--dry-run", action="store_true")
    mode.add_argument("--out-dir", type=Path)
    mode.add_argument("--apply", action="store_true")
    parser.add_argument("--formal-only", action="store_true")
    args = parser.parse_args(argv)
    files, report = build_release(formal_only=args.formal_only)
    if args.out_dir:
        stage_outputs(files, args.out_dir)
        print(f"Complete candidate: {args.out_dir.resolve()}")
    elif args.apply:
        sys.path.insert(0, str(ROOT / "scripts/analysis"))
        from verify_installed_localization import verify_release
        backup = install_outputs(files, installed_check=lambda: verify_release(ROOT))
        print(f"Installed complete release; previous files: {backup}" if backup else "Complete release already installed")
    else:
        print("Dry run passed; no game or translation files changed")
    print(f"Translated rows: {report['translation_sync']['translated_rows']}; untranslated rows stay Japanese")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
