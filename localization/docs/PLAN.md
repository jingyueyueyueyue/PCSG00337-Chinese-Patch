# 《いますぐお兄ちゃんに妹だっていいたい！》PSV 汉化翻译方案

- 游戏：いますぐお兄ちゃんに妹だっていいたい！（PCSG00337，fairys，2014）
- 标准中文译名：**现在就想告诉哥哥，我是妹妹！**（简称"我妹"）
- 引擎：Buriko/DCVM，文本在 `rom/script.rom`（zlib 块），码表为 Buriko 单字节假名 + CP932 双字节。
- 文本量：43,753 条 `category=jp` 字符串，约 87 万日文字符；按块去重后约 3.46 万句待译。

## 1. 路线与批次划分

按 `extracted/script/block_map.json`（块偏移→场景文件）划分，顺序即游戏顺序：

| 区段 | 场景 | 约行数 | 说明 |
|---|---|---|---|
| 系统 | 无场景块 | ~354 | 标题/存读档/系统菜单 |
| 共通线 | ev0000–ev0999 | ~9,700 | 四线分支前 |
| 歩夢线 | ev1000–ev2999 | ~12,500 | ED=01ayumued；ev2xxx 为后半段 |
| 奉莉线 | ev3000–ev3999 | ~8,800 | ED=03matsuried |
| 希実花线 | ev4000–ev4999 | ~8,240 | ED=04kimikaed |
| 真央线 | ev5000–ev5999 | ~8,460 | ED=05maoed |
| 路线判定 | evchk* | ~300 | |

批次规则：按块偏移顺序切分，每批约 400 个去重句；文件名 `localization/text/work/bNNN_起点场景.tsv`。全量约 90–110 批。

## 2. 工作文件格式

批次文件为 **TSV**（译文含逗号/引号，CSV 易碎），8 列：

```text
id  row  offset  scen  budget  source  translation  note
```

- `row`：`script_strings.csv` 的 CSV 记录号（从 2 起计数，是回写定位键，禁止改动；含内嵌换行时不等于物理行号）。
- `budget`：原始字节数，保持原值，作为保守排版参考。当前导入器支持 STR/STBL 与资源包扩容，不再要求译文小于等于旧预算。
- `translation`：正式译文；`note`：可选（说话人、删 ruby、限长说明）。
- 同一原文通常只翻译一次，合并时先按精确原行定位，再回填重复句；已有不同位置译法保留各自的原行对应关系。

## 3. 翻译规则

1. **语义与排版**：语义、标点和对白引号完整优先。`budget` 是旧格式的参考值，超出时由构建器重排 STR/STBL 和 ROM/map，不需要强行缩写。名字框、菜单、长句仍需游戏内检查；不得脚本截断，不因极小旧预算删引号。
2. **控制 token**：除以下两条外，原文中一切标记原样保留：
   - `<ruby>(...)`、`<ruby2>(n,读音)` 为汉字注音标记，中文无意义，**允许整体删除**（含括号内容），note 标注"删ruby"。
   - BGM 条目 `!曲名／Elements Garden　(m:ss)/`：只译曲名段，`!`、`／`、艺人名、时长、结尾 `/` 原样保留。
3. **标点**：用全角标点 。，！？……「」『』（）、：～；省略号用"……"两个字符；破折号"——"。数字保留半角。
4. **人名/名词**：一律以 `localization/text/glossary.tsv` 为准，不得自创译名；发现新专名先按规则拟定并写入 note，批次结束后汇报，由主控统一入表。
5. **语气**：简体中文口语化。歩夢毒舌傲娇、真央认真直率、希実花生硬礼貌（渐软化）、奉莉开朗元气、章介轻浮吐槽。称呼保持日式（～君、～同学按语境）。
6. 不合并、不拆分、不调序；一行对一行。

## 4. 子代理并发纪律

- **同时最多 2 个翻译子代理**，每个负责一个批次文件。
- 子代理必须先读 `glossary.tsv` 再动笔；产出直接写回批次 TSV。
- 每批完成后主控：跑 `validate_translations.py` → 汇总新专名 → 更新 glossary → 记 CHANGELOG → 再派下两批。

## 5. 质检、同步与完整导入

- `python -X utf8 -B scripts/analysis/audit_batch_integrity.py`：核对批次行数、原行号、源文与预算元数据，发现漂移先恢复源字段。
- `python -X utf8 -B scripts/analysis/validate_translations.py`：检查控制 token、残留假名、术语与旧预算，输出 `localization/reports/translation_qc.tsv`。普通模式的预算超限只提示；控制符及术语等 QC 错误返回失败。主动加 `--strict-budget` 时才执行旧预算硬限制。
- `python -X utf8 -B scripts/analysis/validate_translations.py --finalize`：QC 通过后委派安全同步，生成正式 CSV（43,753 条原行，含重复句回填）；此命令不修改游戏资源。

日常更新直接使用 `python -X utf8 -B scripts/build/build_localization.py --dry-run`。它会在内存中核对并合并批次、生成同一份码表，重建脚本和统一字体，更新两份 map。退出本游戏后运行同一入口的 `--apply`，整套安装并同步正式 CSV；最后执行 `python -X utf8 -B scripts/analysis/verify_installed_localization.py` 回读检查。

直接编辑正式 CSV 时用 `--formal-only`，避免批次覆盖；部分未译记录继续显示日文。固定日文基线不重新导出、不覆盖。操作与回滚细节见 [WORKFLOW.md](WORKFLOW.md)。

## 6. 当前进度

见 `localization/reports/translation_qc.tsv` 汇总与 `localization/CHANGELOG.md`。
