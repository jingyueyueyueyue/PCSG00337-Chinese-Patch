# 汉化工作区说明（原 README）

> 本文件是仓库公开前项目根目录的 `README.md` 原文，面向日常工作流；
> 面向使用者的仓库说明见仓库根目录的新 [README](../../README.md)。

# PCSG00337 汉化工作区

《现在就想告诉哥哥，我是妹妹！》的译文、字库与资源构建工作区。统一入口从固定日文原版重建脚本、六套字库、码表、eboot 系统文本及配套索引，正文统一使用未来荧黑（Glow Sans SC Medium）；未译文本保留日文。

## 日常导入

修改 `localization/text/work/b*.tsv` 的 `translation` 列（eboot 系统文本改 `localization/text/eboot_translations.csv`），保存后在项目根运行：

```powershell
python -X utf8 -B scripts/build/build_localization.py --dry-run
```

检查通过并退出本游戏后，安装完整资源集：

```powershell
python -X utf8 -B scripts/build/build_localization.py --apply
python -X utf8 -B scripts/analysis/verify_installed_localization.py
```

不用分别导入脚本和字体。默认构建会校验批次源字段并合并到正式译文快照；`--apply` 同步正式 CSV。直接修改 `localization/text/translation_source.csv` 时，两次构建命令都加 `--formal-only`，避免批次覆盖直接修改。

完整命令、候选包检查、原版基线和测试方法见 [汉化工作流](WORKFLOW.md)。翻译规范见 [翻译方案](PLAN.md)，每次译文修改记录到 [CHANGELOG](../CHANGELOG.md)。

## 目录说明

- `rom/`：游戏正在使用的资源包。
- `map/`：与当前资源包配套的 DCFS 索引，须随 ROM 一起构建和安装。
- `scripts/build/`：完整构建、脚本与字库重建、DCVM/DCFT/DCFS 格式实现。
- `scripts/convert/`：批次与正式译文同步、码表分配及格式转换。
- `scripts/analysis/`：检查、资源分析、独立验证与回归测试。
- `extracted/`：固定日文提取基线（`script/` 正文、`eboot/` 系统文本）；批次和正式 CSV 的原行号依赖它。
- `localization/text/`：正式译文、eboot 系统文本导入源、名词表与 `work/` 翻译批次。
- `localization/font/`：正式码表、字体预览、生成记录和正文字体源（`sources/` 内为 OFL 许可的未来荧黑）。
- `localization/docs/`：工作流、翻译方案与代理模板。
- `localization/images/`：后续图片文字资料的约定位置，图片汉化开始时创建；贴图汉化独立处理。
- `localization/rebuild/`：构建锁及重建中间产物。
- `localization/reports/`：持续使用的校验和分析报告。
- `localization/build_manifest.json`：当前完整资源集的来源、内容哈希和构建报告。
- `archive/YYYY-MM/`：固定原版、整套回滚备份、候选包及按日期归档的实验资料。五份固定原版（含 `20260908_eboot_pristine.bin`）不可删除。
