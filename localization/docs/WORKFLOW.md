# PCSG00337 完整汉化工作流

正式入口为 `scripts/build/build_localization.py`。每次从已核对的日文原版构建译文、码表、六套字库和两份资源索引，统一生成可安装的完整版本。部分翻译和全部翻译完成后使用同一套命令，空白译文对应的原文保留。

## 1. 翻译后怎样导入

在项目根目录的 PowerShell 中执行。平时编辑 `localization/text/work/b*.tsv` 的 `translation`、`note` 列，保留其他源字段。

先做完整构建检查：

```powershell
python -X utf8 -B scripts/build/build_localization.py --dry-run
```

不带参数也等同只检查。检查在内存中完成，不修改正式译文、码表或游戏资源；缺码、源行漂移、控制符错误、损坏的原版或资源结构都会中止构建。

退出本游戏后，安装并独立回读检查：

```powershell
python -X utf8 -B scripts/build/build_localization.py --apply
python -X utf8 -B scripts/analysis/verify_installed_localization.py
```

`--apply` 会重新构建，将同一快照的正式 CSV、码表、字体、脚本及索引一起安装。安装前后检查运行进程，使用构建锁，先暂存全部文件，再逐个替换；写入或独立实物验证失败时恢复整套旧文件。不要分别覆盖 `script.rom`、`rodata.rom` 或单独复制一份 map。

需要先查看候选包时：

```powershell
python -X utf8 -B scripts/build/build_localization.py --out-dir archive/2026-09/20260908_uniform_font_candidate
python -X utf8 -B scripts/analysis/verify_installed_localization.py --release-dir archive/2026-09/20260908_uniform_font_candidate --output archive/2026-09/20260908_uniform_font_verification.json
```

候选目录包含 `rom/`、`map/`、`localization/` 和构建清单。每次按当日日期换新名称；目标已有不同文件时拒绝覆盖。字体预览为候选内的 `localization/font/generated/font_preview.png`。

### 直接编辑正式 CSV

直接修改 `localization/text/translation_source.csv` 时，使用：

```powershell
python -X utf8 -B scripts/build/build_localization.py --formal-only --dry-run
python -X utf8 -B scripts/build/build_localization.py --formal-only --apply
python -X utf8 -B scripts/analysis/verify_installed_localization.py
```

`--formal-only` 不读取批次覆盖。需要撤回某条译文时，可在正式 CSV 清空该项后用此模式重建，原文会从日文原版恢复。默认批次模式会保留已有正式译文，并回填重复句；仅清空一个批次单元格不表示删除已合并的译文。后续恢复批次模式前，应同步处理对应批次，避免旧译文再次回填。

## 2. 源文件与翻译约定

- `extracted/script/script_strings.csv` 是固定日文基线，共 108,477 条提取记录，其中 43,753 条为 `category=jp`。不要用汉化 ROM 的提取结果覆盖它。
- 批次的 `id`、`row`、`offset`、`scen`、`budget`、`source` 都是定位元数据，禁止修改。`row` 是 CSV 记录序号，按 `DictReader` 从 2 起计数；不是含内嵌换行时的文件物理行号。
- 正式 CSV 的 `id=jpNNNNNN` 对应同一个原始记录号；构建同时核对 ID、块偏移、源文及原始字节，能区分同文不同译的具体位置。
- 默认合并先校验 `work/manifest.json` 的全部源字段和行数，再按精确原行、同脚本重复句、全局重复句的顺序回填；不存在的新译文保留已有正式内容，仍为空的记录保留日文。
- `budget` 保留原始值，作为保守排版参考。当前 STR/STBL 和 ROM/map 已支持扩容，超出旧预算不再阻止正常导入，也不能自动截断或删引号。实际显示宽度仍需游戏中检查。
- 控制 token、换行及标签保持顺序与内容；`<ruby>(...)`、`<ruby2>(...)` 注音标记允许完整删除，并在 `note` 说明。BGM 记录按 [翻译方案](PLAN.md) 保留艺人、时长和分隔符。
- 人名和术语遵循 `localization/text/glossary.tsv`。每次改译文同步正式入口并在 `localization/CHANGELOG.md` 记日期与范围。
- eboot 文本的导入源是 `localization/text/eboot_translations.csv`（列：`id,offset,source,translation,note`）。`id=ebNNNNNN` 与 `offset` 按解密镜像内偏移对应 `extracted/eboot/eboot_strings.csv` 固定提取基线；构建核对基线、导入源与安装字节三方一致。译文 UTF-8 编码不得超过原串长度（NUL 填充），`%s/%d` 等格式符与换行保持原位；清空译文即保留日文原文。

额外的翻译审校命令：

```powershell
python -X utf8 -B scripts/analysis/audit_batch_integrity.py
python -X utf8 -B scripts/analysis/validate_translations.py
```

`validate_translations.py --finalize` 已委派到安全同步流程，用于单独更新正式 CSV；它不安装游戏。普通模式把旧预算超限作为提示，控制符、名词等实际 QC 错误返回失败；只有主动加 `--strict-budget` 才将旧预算作为硬限制。

## 3. 完整构建负责什么

1. 核对四份原版资源、原始 eboot 和固定提取基线；构建过程中输入发生变化即中止。
2. 从同一份译文快照分配码位，保护原生码位，保留合法历史分配；无可用码位、重复码位或非法字节立即报错。
3. 用同一份码表重建六套 DCFT 字库。可识别的原生正文及新增文字统一用未来荧黑（Glow Sans SC Normal Medium，OFL；字体文件固定在 `localization/font/sources/`）绘制，各槽保留尺寸、原生码位、字形编号和原字符 advance。荧黑仅缺的 `☆`(U+2606) 与 `♪`(U+266A) 两个符号回退到同为黑体的 MS Gothic（`msgothic.ttc`），并沿用相同槽位的绘制参数；未识别的非文字图形保留。实际字体文件 SHA256 记入构建清单。
4. 从日文原版逐条重建 STR，更新 STBL 引用、四字节对齐和容器长度；保持 CODE 及其他非文本段不变，重算 STR 与 DCVM 内容校验和。
5. 固定使用 zlib level 9。数据增长时重排资源，同步 DCFS FILE 块位置、包含 12 字节头的压缩读取容量、解压容量及 ROM 总长度。
6. 回读全部 491 个 DCVM（482 压缩、9 未压缩）、每条译文和非文本段，检查六槽码位覆盖、统一字形像素及字体结构，生成来源和输出哈希清单。
7. 从 archive 固定原版解密 eboot（核对原版与解密 ELF 双重 SHA256），按提取基线回写 `eboot_translations.csv` 的中文（等长或更短、NUL 填充、其他字节不动），复核补丁只落在译文区间后，重建 Vita3K 可加载的明文假 SELF：key revision 清零、五段未压缩明文、哈希控制记录与元数据区清零，与多个已在 Vita3K 正常运行的解密版游戏同构。安装后 `eboot.bin` 即该假 SELF，不再是零售加密原版；原版固定在 `archive/2026-09/20260908_eboot_pristine.bin`。

完整资源集包括两份 ROM、两份 map、正式 CSV、生成码表与字符集、字体预览及 `localization/build_manifest.json`。独立验证器从实际输出文件重新检查内容，不以构建日志中的“通过”代替回读。

当前统一字体样本（2026-10-04 未来荧黑版）：3,777 个码表字符，其中 1,001 个自定义码；包含原文别名的 3,848 个所需码位在六槽全部覆盖。7,121 个原生文字字形已重绘，原生码位、字形编号、advance 与 IMGI 地址保持；另 1 个 TAB 占位保留原像素。新增字形共 16,063 个。统一版不再以“全部原生像素不变”为验证标准。旧样本：2026-09-08 微软雅黑版为 3,527 码表字符 / 869 自定义码 / 3,599 所需码位 / 14,569 新增字形。

单独的 `import_script_text.py` 或 `build_font.py` 用于开发检查、候选生成或内存 API。日常发布始终使用完整入口，不再使用 Zopfli、冻结旧压缩长度或逐包手工安装。

## 4. 环境与固定原版

首次准备环境时安装依赖；已有可用环境无需重复执行：

```powershell
python -m pip install -r scripts/build/requirements.txt
```

依赖为 NumPy、Pillow、fonttools、psutil，正文字体为项目内固定的未来荧黑 Medium（OFL），缺失符号回退 Windows MS Gothic。以下原版输入和 SHA256 固定在 `build_localization.py` 的 `BASELINES` 中：

| 文件 | SHA256 |
|---|---|
| `archive/2026-09/20260907_script.rom` | `75a23c47863cf77a9d0451df34f84e323d1478a50309fd0bb6001a1fbf7d7dfd` |
| `archive/2026-09/20260908_script_map_pristine.map` | `4ef71dc0a7ec6c93114922aa9786f87a21ebcf25da040db49f970f42f90306d3` |
| `archive/2026-09/20260908_rodata_pristine.rom` | `f5d681a7b14d1d5ae642a26e17023a409141d455d33d0da4a33654f7096033b8` |
| `archive/2026-09/20260908_rodata_map_pristine.map` | `00f03d815a89ab0fb6cd90927dd36c3d78d9329148ce2a6395f351e3f343e174` |
| `archive/2026-09/20260908_eboot_pristine.bin` | `f73beefee2c2644e8b2dfa95974451cda50b583e6cfe16cc24664e62a1adc913` |

原版 `eboot.bin` 为零售加密 SELF（key revision 5）。2026-09-08 之前的修复未修改可执行文件；自 eboot 文本并入主流程起，`--apply` 安装的 `eboot.bin` 为含中文系统文本的明文假 SELF（解密 ELF SHA256 `62f61c3991ad92bd66164e666bfb9835a84ae3e8c2ee46884726a264a6dde331`，见构建清单 `eboot` 段）。解密使用 RIF klicensee（已按固定值内嵌在 `scripts/build/eboot_text.py`），构建不依赖 license 目录。

这些文件是重建来源，不得用当前汉化资源或二分实验包替代。不要把 `extract_text_assets.py` 或 `reset_font_code_table.py --refresh-extract` 放在日常导入前运行；已有日文基线无需重复提取，完整入口会核对并使用它。

## 5. 回归测试与游戏验收

修改构建代码后运行：

```powershell
python -X utf8 -B scripts/analysis/test_script_pipeline.py
python -X utf8 -B scripts/analysis/verify_font_pipeline.py
python -X utf8 -B scripts/analysis/test_release_pipeline.py
```

脚本回归覆盖 STR 增长、STBL 重排、raw 与压缩条目扩容、旧 map 容量、坏校验和、非法码、源行冲突、重复构建和撤译还原。字体回归检查所有槽位、统一字形、别名和位图边界。完整流程回归覆盖批次同步、码位稳定、运行进程守卫、构建锁、安装失败及验证失败回滚，并含 eboot 域 9 项：解密确定性、提取基线漂移、超预算/源不符/缺行拒绝、假 SELF 结构与篡改拒绝、导入源核对及安装发布。测试只使用内存或归档区隔离目录，不安装正式游戏。

安装完成后重新启动游戏，检查标题到开头剧情、姓名框、长句、标点、换行、历史记录、选项和存读档。可先查看“要开始游戏吗？”及“终点站，古桥 / 广播”的字形是否统一。脚本结构检查通过不代表全路线已通关，开头正常也不代表所有译文已经人工审校。

用户已确认本轮修复后的完整资源集能够正常运行；后续字体或译文版本仍需按上述项目检查。以当前构建清单和对应运行记录区分测试版本，不根据日志最后一行打开了哪个 ROM 推断根因。

## 6. 错误处理与回滚

- 提示源行、ID 或 `budget` 漂移：恢复对应批次的原始元数据，不能改提取基线来让错误匹配。
- 提示 eboot 提取基线漂移、源不符或缺行：`extracted/eboot/eboot_strings.csv` 与解密结果或导入源不一致；先恢复导入源与基线一致，再用 `python -X utf8 -B scripts/build/eboot_text.py --check` 复核。仅当官方补丁更换 eboot 后，才可用 `--extract` 重建基线并补译新增串。
- 提示安装后的 eboot 校验失败：对照构建清单 `eboot` 段的 `installed_sha256`；不要手工拼接假 SELF，统一从完整入口重建。
- 提示字符缺码、字库覆盖不足或 map 不一致：修复输入或构建器后重跑完整入口，不接受问号替代或跳过失败条目。
- 提示本游戏正在运行：退出本游戏后重新执行 `--apply`。构建器不强制终止进程。
- 出现 `localization/rebuild/import.lock`：先核对其中 PID、备份位置和安装状态；它可能来自仍在执行的安装或中断的回滚，不应直接删锁后混用资源。
- 写入或独立实物验证失败：安装器恢复原整套文件；备份位于 `archive/YYYY-MM/YYYYMMDD_before_release_时间/`。回滚也失败时保留锁和备份供恢复。

验证当前文件可再运行 `verify_installed_localization.py`。恢复旧版本必须恢复整套资源及其清单，不从二分目录挑一个 ROM 覆盖当前版本。

## 7. 范围与归档

当前入口处理脚本文本、eboot 系统文本、码表和六套字库，不包含背景、按钮、菜单贴图的文字重绘。贴图上的日文不会随着脚本文本翻译自动变成中文；图片工作留在 `localization/images/` 单独推进，未实现的图片工具不属于必跑主流程。eboot 里的文本为引擎消息表（含少量玩家可见界面串），提取范围与判定规则见 `scripts/build/eboot_text.py` 与 `extracted/eboot/eboot_strings.csv`。

功能脚本按用途放 `scripts/build/`、`scripts/convert/`、`scripts/analysis/`。实验日志、候选包和一次性报告放 `archive/YYYY-MM/YYYYMMDD_名称`；正式译文与持续使用的报告留在 `localization/`。目录含义见根目录 [README](../../README.md)。

清理时保留四份固定原版、当前已验收版本及必要诊断记录。旧二分包仅是历史证据；本轮删除旧诊断 ROM 的操作被自动审批策略阻止，相关文件仍在归档区，不能作为当前正式包使用。
