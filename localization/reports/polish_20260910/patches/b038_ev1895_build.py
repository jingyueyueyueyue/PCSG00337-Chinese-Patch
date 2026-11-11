# -*- coding: utf-8 -*-
"""b038_ev1895 润色补丁构建（含宽度自检：全角=2 半角=1，超限即拒绝生成）。"""
import json

BUDGET = {
    "b038_ev1895_0010": 25,
    "b038_ev1895_0046": 35,
    "b038_ev1895_0049": 52,
    "b038_ev1895_0053": 23,
    "b038_ev1895_0055": 60,
    "b038_ev1895_0068": 30,
    "b038_ev1895_0074": 17,
    "b038_ev1895_0079": 71,
    "b038_ev1895_0083": 37,
    "b038_ev1895_0092": 12,
    "b038_ev1895_0108": 7,
    "b038_ev1895_0113": 25,
    "b038_ev1895_0128": 57,
    "b038_ev1895_0134": 30,
    "b038_ev1895_0137": 26,
    "b038_ev1895_0138": 37,
    "b038_ev1895_0142": 23,
    "b038_ev1895_0145": 14,
    "b038_ev1895_0160": 39,
    "b038_ev1895_0173": 24,
    "b038_ev1895_0199": 13,
    "b038_ev1895_0200": 40,
    "b038_ev1895_0209": 21,
    "b038_ev1895_0241": 36,
    "b038_ev1895_0266": 28,
    "b038_ev1895_0271": 29,
    "b038_ev1895_0291": 19,
    "b038_ev1895_0298": 20,
}

patches = [
    {"id": "b038_ev1895_0010", "translation": "回过神来，步梦也在哭……"},
    {"id": "b038_ev1895_0046", "translation": "「……正在一点点换成新的回忆」"},
    {"id": "b038_ev1895_0049", "translation": "「对、对不起……我一直在哭……好难看啊……呜呜……」"},
    {"id": "b038_ev1895_0053", "translation": "「没、没事吧？红灯？」"},
    {"id": "b038_ev1895_0055", "translation": "「换成我遇到同样情况，说不定还要闹别扭……可是哥哥却……」"},
    {"id": "b038_ev1895_0068", "translation": "「为什么……不肯放过我呢……」"},
    {"id": "b038_ev1895_0074", "translation": "「在施工……」"},
    {"id": "b038_ev1895_0079", "translation": "「生气啊。遗物那件事，我暂时没法原谅爸爸……也还有想不通的地方……」"},
    {"id": "b038_ev1895_0083", "translation": "「爸爸也……夺走我和妈妈的回忆……」"},
    {"id": "b038_ev1895_0092", "translation": "「可以吗？」"},
    {"id": "b038_ev1895_0108", "translation": "厉害？", "note": "预算紧省略「」"},
    {"id": "b038_ev1895_0113", "translation": "「那里，妈妈不在了……」"},
    {"id": "b038_ev1895_0128", "translation": "明明哭过、烦恼过、也选择了接受现实，心本该支离破碎……"},
    {"id": "b038_ev1895_0134", "translation": "这或许就是喜欢上一个人吧……"},
    {"id": "b038_ev1895_0137", "translation": "那时我和步梦都已经不哭了。"},
    {"id": "b038_ev1895_0138", "translation": "这时，对面贴着的广告无意间映入眼帘。"},
    {"id": "b038_ev1895_0142", "translation": "我觉得心情高涨了一些。"},
    {"id": "b038_ev1895_0145", "translation": "「…郁美的？」"},
    {"id": "b038_ev1895_0160", "translation": "「我也是父亲……对方心情我太懂了……」"},
    {"id": "b038_ev1895_0173", "translation": "「啊，现在说他可能动摇」"},
    {"id": "b038_ev1895_0199", "translation": "深深低下头。"},
    {"id": "b038_ev1895_0200", "translation": "一看到两人的脸，平静的心再度躁动。"},
    {"id": "b038_ev1895_0209", "translation": "「……今天，对不住」"},
    {"id": "b038_ev1895_0241", "translation": "「所以，我们吃饭吧。我肚子饿啦」"},
    {"id": "b038_ev1895_0266", "translation": "『他内心的伤还很深……。』"},
    {"id": "b038_ev1895_0271", "translation": "『告诉他我喜欢哥哥……。』"},
    {"id": "b038_ev1895_0291", "translation": "「…妈妈怎么了？」"},
    {"id": "b038_ev1895_0298", "translation": "「……嗯，就这么办」"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

over = [(p["id"], enc_len(p["translation"]), BUDGET[p["id"]])
        for p in patches if enc_len(p["translation"]) > BUDGET[p["id"]]]
if over:
    for pid, n, b in over:
        print(f"TOO_LONG {pid}: {n}>{b}")
    raise SystemExit("width over budget")

json.dump(
    {"patches": patches},
    open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b038_ev1895.json", "w", encoding="utf-8"),
    ensure_ascii=False, indent=1,
)
print("patches:", len(patches), "all within budget")
