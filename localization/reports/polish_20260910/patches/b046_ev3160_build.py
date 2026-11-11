# -*- coding: utf-8 -*-
"""b046_ev3160 润色补丁构建（含显示宽度自检，全角=2 半角=1）"""
import json

BUDGET = {
    "b046_ev3160_0022": 54,
    "b046_ev3160_0031": 23,
    "b046_ev3160_0039": 10,
    "b046_ev3160_0040": 50,
    "b046_ev3160_0041": 25,
    "b046_ev3160_0062": 19,
    "b046_ev3160_0079": 74,
    "b046_ev3160_0093": 17,
    "b046_ev3160_0094": 16,
    "b046_ev3160_0102": 28,
    "b046_ev3160_0106": 49,
    "b046_ev3160_0136": 31,
    "b046_ev3160_0206": 15,
    "b046_ev3160_0214": 18,
    "b046_ev3160_0227": 22,
    "b046_ev3160_0241": 12,
}

patches = [
    {"id": "b046_ev3160_0022",
     "translation": "速度和早上在公园健走的人差不多，就这么一直走。"},
    {"id": "b046_ev3160_0031",
     "translation": "「——就是这样！！」",
     "note": ""},
    {"id": "b046_ev3160_0039",
     "translation": "「呵呵呵」"},
    {"id": "b046_ev3160_0040",
     "translation": "「……该不会在想『奉莉的裸体被步梦看到了』吧？」"},
    {"id": "b046_ev3160_0041",
     "translation": "「……该不会觉得不行？」"},
    {"id": "b046_ev3160_0062",
     "translation": "「真的真的，快点」"},
    {"id": "b046_ev3160_0079",
     "translation": "「这是男女组队的任务吧？章介要坐镇指挥，必须留在这里，能去的只有陆斗了」"},
    {"id": "b046_ev3160_0093",
     "translation": "「不、不是……」"},
    {"id": "b046_ev3160_0094",
     "translation": "「不、不是……」"},
    {"id": "b046_ev3160_0102",
     "translation": "「那个……新任务有2个呢」"},
    {"id": "b046_ev3160_0106",
     "translation": "「是、是吗……岛、岛浦那边的出入口看得见了」"},
    {"id": "b046_ev3160_0136",
     "translation": "然后，朝岛浦侧出入口的大楼——"},
    {"id": "b046_ev3160_0206",
     "translation": "「啊、嗯……」"},
    {"id": "b046_ev3160_0214",
     "translation": "「嗯、算是吧……」"},
    {"id": "b046_ev3160_0227",
     "translation": "「这样……那就好……」"},
    {"id": "b046_ev3160_0241",
     "translation": "「呐，奉莉」"},
]

bad = [p["id"] for p in patches
       if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

over = []
for p in patches:
    n = sum(1 if ord(c) < 128 else 2 for c in p["translation"])
    if n > BUDGET[p["id"]]:
        over.append((p["id"], n, BUDGET[p["id"]]))
if over:
    raise SystemExit("too_long: %r" % over)

json.dump({"patches": patches},
          open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b046_ev3160.json",
               "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("patches:", len(patches))
