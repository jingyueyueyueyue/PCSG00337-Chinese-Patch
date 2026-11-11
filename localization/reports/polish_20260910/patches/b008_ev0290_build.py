# -*- coding: utf-8 -*-
"""b008_ev0290 润色补丁构建：生成 JSON，并做控制符 + 显示宽度自检。"""
import csv
import json
import sys

TSV = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b008_ev0290.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b008_ev0290.json"

patches = [
    {"id": "b008_ev0290_0001", "translation": "（……不，三谷君不会的）"},
    {"id": "b008_ev0290_0011", "translation": "（不知不觉，就只剩三谷君了……）"},
    {"id": "b008_ev0290_0012", "translation": "（三谷君一定……）"},
    {"id": "b008_ev0290_0017", "translation": "（而且不只奈奈濑同学……拜田同学、横山君……）"},
    {"id": "b008_ev0290_0021", "translation": "「1号站台，经龙国、秋日开往厅舍前……电车即将发车，请注意关门」"},
    {"id": "b008_ev0290_0026", "translation": "完全忘了去找她!!"},
    {"id": "b008_ev0290_0038", "translation": "「哪位?」"},
    {"id": "b008_ev0290_0043", "translation": "「嗯，诶?」"},
    {"id": "b008_ev0290_0050", "translation": "「而且能见到步梦君吧？」"},
    {"id": "b008_ev0290_0067", "translation": "那根递到一半给东云小姐的巧克力香蕉……"},
    {"id": "b008_ev0290_0075", "translation": "最后，东云小姐深深一礼，送走了奉莉的阿姨。"},
    {"id": "b008_ev0290_0084", "translation": "东云小姐的视线尽头——"},
    {"id": "b008_ev0290_0102", "translation": "「嗯，好吃」"},
    {"id": "b008_ev0290_0120", "translation": "「你也太散漫了？步梦君他们马上搬来，准备好了吗？」"},
    {"id": "b008_ev0290_0124", "translation": "「我想着今天是庙会，奉莉酱说不定会来，就稍微过来看看……」"},
    {"id": "b008_ev0290_0152", "translation": "「谢谢奉莉酱，那么……」"},
    {"id": "b008_ev0290_0161", "translation": "「嗯。说是看到东云小姐吃东西，就来干劲和勇气」"},
    {"id": "b008_ev0290_0179", "translation": "「小皋能把东西吃得特别香，真羡慕」"},
    {"id": "b008_ev0290_0209", "translation": "这种分寸，开和果子店的东云小姐自然也懂。"},
    {"id": "b008_ev0290_0211", "translation": "然后再次把巧克力香蕉递给东云小姐。"},
    {"id": "b008_ev0290_0218", "translation": "『陆斗君会原谅爱撒谎的我吗？』"},
    {"id": "b008_ev0290_0220", "translation": "『朝冈的入学准备说明会那次，我是真的感冒了，但要是没感冒，我就会撒谎缺席了。』"},
    {"id": "b008_ev0290_0223", "translation": "『不得不对陆斗君说谎这件事。』"},
    {"id": "b008_ev0290_0224", "translation": "『不想被陆斗君讨厌……。』"},
    {"id": "b008_ev0290_0227", "translation": "『妈妈和直真。我有……陆斗君。』", "note": "预算过紧：直真さん暂压缩为直真"},
    {"id": "b008_ev0290_0230", "translation": "『因为这个谎，毕业远足那天我只能躲着陆斗君了。』"},
    {"id": "b008_ev0290_0236", "translation": "一看到纤瘦的步梦君，就觉得重体力活还是该我来干。"},
    {"id": "b008_ev0290_0242", "translation": "「三年……都一起那么久了，和陆斗君关系不是很好吗？」"},
    {"id": "b008_ev0290_0248", "translation": "「不挤吗?」"},
    {"id": "b008_ev0290_0264", "translation": "「嗯。我留了这块空间和架子给步梦君用，够吗？」"},
    {"id": "b008_ev0290_0298", "translation": "「奉莉吗?」"},
    {"id": "b008_ev0290_0304", "translation": "良子小姐和步梦君今天终于要搬来了。"},
    {"id": "b008_ev0290_0306", "translation": "对，步梦君也是男的嘛。"},
    {"id": "b008_ev0290_0312", "translation": "就这样，我想到什么就和步梦君聊了各种话题。"},
    {"id": "b008_ev0290_0315", "translation": "……介绍『兄弟』时，我犹豫了。", "note": "存疑:原文字面『兄弟』（日语可泛指兄弟姐妹），改按字面直译"},
    {"id": "b008_ev0290_0317", "translation": "我向一直盯着这边的步梦君使了个眼色：没事的。"},
    {"id": "b008_ev0290_0319", "translation": "但步梦君的表情依旧微妙。"},
    {"id": "b008_ev0290_0321", "translation": "但这样一来，说话对象又只剩步梦君了。"},
    {"id": "b008_ev0290_0327", "translation": "一进客厅，未玖就超欢快地打了个招呼。"},
    {"id": "b008_ev0290_0331", "translation": "终究是步梦君自我介绍了。"},
    {"id": "b008_ev0290_0332", "translation": "结果步梦君的衣服没拿完，只能连纸箱一起放着……"},
    {"id": "b008_ev0290_0333", "translation": "现身的未玖穿着崭新的初中制服。"},
    {"id": "b008_ev0290_0334", "translation": "客厅再次只剩下我和步梦君两人。"},
    {"id": "b008_ev0290_0335", "translation": "未玖动作飞快地摸上了步梦君的胸。"},
    {"id": "b008_ev0290_0338", "translation": "老爸一走，良子小姐就打了个大哈欠。"},
    {"id": "b008_ev0290_0339", "translation": "房间又小又挤，既不是我的错也不是步梦君的错。"},
    {"id": "b008_ev0290_0340", "translation": "经步梦君同意，我让未玖进了门。"},
    {"id": "b008_ev0290_0341", "translation": "和满面笑容点头的步梦君一起走向客厅。"},
    {"id": "b008_ev0290_0343", "translation": "未玖好像也觉得有点不对劲……"},
    {"id": "b008_ev0290_0344", "translation": "「……抱歉啊，太闹了」"},
    {"id": "b008_ev0290_0347", "translation": "「……真是男的?」"},
    {"id": "b008_ev0290_0349", "translation": "「良子小姐没事吧？」"},
    {"id": "b008_ev0290_0350", "translation": "「……良子小姐，没睡够?」"},
    {"id": "b008_ev0290_0355", "translation": "「没有」"},
    {"id": "b008_ev0290_0359", "translation": "「明白了」"},
    {"id": "b008_ev0290_0388", "translation": "「火灾？……是家务啊」"},
    {"id": "b008_ev0290_0408", "translation": "「步梦君，一直处得很好的邻居家的孩子说想来，让她进门可以吗？」"},
    {"id": "b008_ev0290_0411", "translation": "「陆斗君?」"},
    {"id": "b008_ev0290_0412", "translation": "「陆斗君也这么说，我觉得你还是睡吧……？」"},
    {"id": "b008_ev0290_0413", "translation": "「喜欢做菜的话，做饭交给步梦君，其他还是分担比较好……」"},
    {"id": "b008_ev0290_0415", "translation": "「良子小姐困了?」"},
    {"id": "b008_ev0290_0422", "translation": "「谢谢陆斗君真温柔」"},
    {"id": "b008_ev0290_0430", "translation": "「给你看好东西?」"},
    {"id": "b008_ev0290_0433", "translation": "「不……要是让人从卢克树上跳下来，那可有点……」", "note": "新词:ルークツリー=卢克树（按词表统一卢克树）"},
    {"id": "b008_ev0290_0436", "translation": "「不不不，是步梦君和我」"},
    {"id": "b008_ev0290_0439", "translation": "「没事，加油小直」"},
    {"id": "b008_ev0290_0440", "translation": "「嗯，未玖酱和陆斗君关系真好呢」"},
    {"id": "b008_ev0290_0448", "translation": "「呃，我是要当陆斗君弟弟的步梦」"},
    {"id": "b008_ev0290_0463", "translation": "「再对步梦君乱来我绝不原谅。再犯就绝交」"},
    {"id": "b008_ev0290_0466", "translation": "「是嘛，谢谢。未玖绝不是坏孩子……我想步梦君早晚也能处熟」"},
    {"id": "b008_ev0290_0480", "translation": "「不能把负担都压给步梦君……」"},
    {"id": "b008_ev0290_0484", "translation": "「总之步梦君是男孩子」"},
    {"id": "b008_ev0290_0485", "translation": "「总之步梦君是男孩子，懂了吗？」"},
    {"id": "b008_ev0290_0490", "translation": "「呐呐，刚搬来吧？介绍下嘛」"},
    {"id": "b008_ev0290_0498", "translation": "「嗯，没事。陆斗君和未玖酱感情好，我很清楚了……」"},
    {"id": "b008_ev0290_0512", "translation": "良子小姐轻轻挥手，进了老爸的房间。"},
    {"id": "b008_ev0290_0513", "translation": "接住未玖时，我和步梦君对上了眼。"},
    {"id": "b008_ev0290_0514", "translation": "我轻声问，步梦君重重地点头。"},
    {"id": "b008_ev0290_0516", "translation": "说着，未玖向步梦君要求握手。"},
    {"id": "b008_ev0290_0518", "translation": "低语的步梦君，眼神显得有些寂寞。"},
    {"id": "b008_ev0290_0524", "translation": "未玖边低语，边紧盯步梦君的脸。"},
    {"id": "b008_ev0290_0526", "translation": "步梦君悲鸣刺耳。"},
    {"id": "b008_ev0290_0531", "translation": "步梦君终于又有笑容了。"},
]

bad = [p["id"] for p in patches
       if "\t" in p["translation"] or "\n" in p["translation"] or "\r" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

enc_len = lambda s: sum(1 if ord(c) < 128 else 2 for c in s)

budget = {}
with open(TSV, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        budget[r["id"]] = int(r["budget"])

over = [(p["id"], enc_len(p["translation"]), budget.get(p["id"], -1))
        for p in patches if enc_len(p["translation"]) > budget.get(p["id"], -1)]
if over:
    for pid, n, b in over:
        print("TOO LONG: %s %d>%d" % (pid, n, b))
    raise SystemExit("width check failed: %d rows" % len(over))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width checks passed")
