# 《现在就想告诉哥哥，我是妹妹！》汉化工程

PS Vita 游戏《现在就想告诉哥哥，我是妹妹！》（いま妹なの！？～おにいちゃん、聞かないでよ絶対！！～，日版编号 PCSG00337）的中文汉化工程，包含全部译文、字库、构建工具链与发布补丁。

- **正文台词**：43,753 行全部译出
- **系统文本**：eboot 内 284 条全部译出
- **正文字体**：统一替换为未来荧黑（Glow Sans SC Medium，OFL 许可）
- **适用环境**：日版原版 PCSG00337（PS Vita 实机 3.60/3.65 enso / Vita3K 模拟器）

## 下载补丁

成品补丁在本仓库 [`archive/2026-11/PCSG00337_汉化补丁_20261004.zip`](archive/2026-11/PCSG00337_汉化补丁_20261004.zip)（约 9.7 MB），包内附完整的《安装说明.txt》与 SHA256 校验文件。

补丁为增量覆盖式，只含被修改的 5 个文件，其余资源沿用你自己的原版：

| 文件 | 内容 |
| --- | --- |
| `eboot.bin` | 系统文本汉化（284 条） |
| `rom/script.rom` | 正文脚本（43,753 行） |
| `rom/rodata.rom` | 六套字库（未来荧黑 Medium） |
| `map/script.map`、`map/rodata.map` | 配套 DCFS 索引（必须与对应 `.rom` 一起替换） |

### Vita3K 安装

把包内文件按原有目录结构覆盖到 `ux0/app/PCSG00337/`，完全退出 Vita3K 再重启以刷新字体缓存。

### PS Vita 实机安装

3.60/3.65 enso + VitaShell：连接后进入 `ux0:app/PCSG00337/`，先备份上述 5 个原文件，再用包内同名文件覆盖，重启游戏。

## 从源码构建

本仓库不含任何游戏本体资源（`rom/`、`movie/`、`sce_sys/`、`eboot.bin`、日文提取基线 `extracted/` 等均未上传），你需要**自己拥有一份完整可运行的日版原版**。译文行号与提取基线对齐，因此先从自己的游戏副本生成基线：

```powershell
# 1. 从自己的游戏副本提取日文基线到 extracted/
python -X utf8 -B scripts/analysis/extract_text_assets.py

# 2. 试运行构建（校验批次源字段并合并到正式译文快照）
python -X utf8 -B scripts/build/build_localization.py --dry-run

# 3. 安装完整资源集并验证
python -X utf8 -B scripts/build/build_localization.py --apply
python -X utf8 -B scripts/analysis/verify_installed_localization.py
```

日常改译：修改 `localization/text/work/b*.tsv` 的 `translation` 列（eboot 系统文本改 `localization/text/eboot_translations.csv`），再执行上面第 2、3 步。完整工作流见 [汉化工作流](localization/docs/WORKFLOW.md)，翻译规范见 [翻译方案](localization/docs/PLAN.md)，修改历史见 [CHANGELOG](localization/CHANGELOG.md)。

## 仓库结构

```
scripts/build/       完整构建、脚本与字库重建、DCVM/DCFT/DCFS 格式实现
scripts/convert/     批次与正式译文同步、码表分配及格式转换
scripts/analysis/    检查、资源分析、独立验证与回归测试
localization/text/   正式译文、eboot 系统文本导入源、名词表与 work/ 翻译批次
localization/font/   正式码表、字体预览、生成记录和字体源（sources/，OFL）
localization/docs/   工作流、翻译方案、代理模板与工作区说明
localization/reports/ 校验和分析报告
localization/CHANGELOG.md   译文修改记录
localization/build_manifest.json  当前资源集来源、哈希与构建报告
archive/2026-11/     发布补丁包
```

## 致谢与许可

- 正文字体 [未来荧黑 Glow Sans SC](https://github.com/welai/glow-sans)（Triones/@atelierAnchor）采用 [SIL Open Font License 1.1](localization/font/sources/) 授权，随仓库完整分发。
- 汉化工程代码与译文仅供学习交流，请支持正版；因使用本工程造成的任何后果自负。

## 相关文档

- [安装说明（补丁包内原文）](archive/2026-11/PCSG00337_汉化补丁_20261004.zip)
- [汉化工作流](localization/docs/WORKFLOW.md) · [翻译方案](localization/docs/PLAN.md) · [工作区说明](localization/docs/WORKSPACE.md)
