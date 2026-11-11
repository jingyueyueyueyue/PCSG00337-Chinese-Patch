# -*- coding: utf-8 -*-
"""收尾：补录词表最后一批词条 + 记录翻译完成日志。"""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

gloss = """藤乃	藤乃	-	人名	茂森家先祖，唯一以女儿身获免许皆传的女剑士
ミツバチのベアーハンティング	蜜蜂猎熊	-	术语	游乐园设施名
越前島発着場	越前岛码头	-	术语	水上巴士站名
鉢置橋	钵置桥	-	术语	桥名
ダンスチーム	舞蹈组	-	术语	与料理组/幕后组/服务生组配套
リーダーさん	队长	-	称谓	舞蹈队领队
破門	破门	-	术语	逐出师门；解除破门=变回男儿身的关键设定词
"""
with open(ROOT / "localization/text/glossary.tsv", "a", encoding="utf-8") as f:
    f.write(gloss)

entry = """### 2026-09-09 翻译全部完成

- b088-b093 完成，b094 由主控补译（换行转义修复，新增 scripts/convert/fix_b094.py）：**全部 94 批、34,724 去重句（覆盖 43,753 行原始文本）翻译完成**。最终质检 0 问题（0 超预算 / 0 漏译 / 0 控制符破坏 / 0 人名不一致），全库完整性审计 0 偏差（新增 STRUCT-BAD 结构检测）。
- 收尾修复：b084/b088/b089/b090 列漂移重建；7 行超预算压缩；更正 09-08 日志中"33,326 句 95%"的口误（当轮实际 32,812 句 94%）。
- 执行 --finalize：全量合并至 localization/text/translation_source.csv（43,753 行全填充，重复原文按首译回填），可供既有导入管线（reset → constraints → import → checksum 验证）直接消费。
- 后续待办：① 极短预算压缩行的统一润色（各批 note 有标注）；② DCFT 字库重建（09-07 结论：私码字缺字形是黑屏根因，rebuild_dcft_font.py 待实现）；③ 全量导入后实机三轮测试（WORKFLOW 第 10 节）。
"""
with open(ROOT / "localization/CHANGELOG.md", "a", encoding="utf-8") as f:
    f.write(entry)
print("glossary + changelog done")
