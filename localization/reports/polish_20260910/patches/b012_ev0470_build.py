# -*- coding: utf-8 -*-
"""b012_ev0470 润色补丁构建脚本（2026-09-10）。
修改类型：词表称谓统一（Xくん→X君、東雲さん→东云小姐、良子さん→良子小姐、
拝田さん/茂森さん→同学）、误译修正、语气词/结巴补足、语句通顺度。
"""
import csv
import json

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b012_ev0470.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b012_ev0470.json"

patches = [
    {"id": "b012_ev0470_0005", "translation": "虽然觉得不值得道谢，可一说出口，拜田同学怕要一直惶恐下去，还是算了。"},
    {"id": "b012_ev0470_0009", "translation": "「那横山君就在这分别了」"},
    {"id": "b012_ev0470_0016", "translation": "「可茂森君是男生啊……」"},
    {"id": "b012_ev0470_0049", "translation": "「真希望那阵竞选热潮时，除横山君外还能有一个人一拍脑门举手就好了……」"},
    {"id": "b012_ev0470_0066", "translation": "「这样叫，就像我们认识的茂森同学了」", "note": "存疑：さん付け意译为称呼"},
    {"id": "b012_ev0470_0083", "translation": "「那拜田同学也要绕一大圈咯？」"},
    {"id": "b012_ev0470_0088", "translation": "「没什么啊」"},
    {"id": "b012_ev0470_0097", "translation": "「先不管了，有人见过我们认识的茂森同学吗？」"},
    {"id": "b012_ev0470_0104", "translation": "「拜田同学，怎么了？」"},
    {"id": "b012_ev0470_0111", "translation": "于是，横山君也要跟我们坐同一方向的车了。"},
    {"id": "b012_ev0470_0136", "translation": "「好——偷笑到此为止，步梦君」"},
    {"id": "b012_ev0470_0151", "translation": "「诶？那个，不是妹妹……」"},
    {"id": "b012_ev0470_0154", "translation": "「被、被说可爱……很难为情……」"},
    {"id": "b012_ev0470_0156", "translation": "「『步梦君』这个称呼，别在别人面前用比较好吧？」"},
    {"id": "b012_ev0470_0157", "translation": "「可爱到跟妹妹差不多啦」"},
    {"id": "b012_ev0470_0187", "translation": "「横山君要能变成美少女，那真了不起……」"},
    {"id": "b012_ev0470_0191", "translation": "可惜，横山君变成美少女的样子实在想象不出。"},
    {"id": "b012_ev0470_0202", "translation": "东云小姐……好大……"},
    {"id": "b012_ev0470_0206", "translation": "爸爸和良子小姐参加完入学式就去上班了，人不在很正常，可步梦也不在。"},
    {"id": "b012_ev0470_0208", "translation": "步梦君进爸爸他们的房间十几分钟后。"},
    {"id": "b012_ev0470_0234", "translation": "「刚才提到的东云小姐，比我们低一届，是奉莉的青梅竹马」"},
    {"id": "b012_ev0470_0235", "translation": "「在校生代表……就是东云小姐吧？」"},
    {"id": "b012_ev0470_0244", "translation": "「怎么可能不行！中一的未玖可是有未来的！」"},
    {"id": "b012_ev0470_0245", "translation": "「良子的道具？化妆品？」", "note": "预算过紧（良子小姐放不下）"},
    {"id": "b012_ev0470_0253", "translation": "「啊……原来如此。步梦的女装靠的是良子小姐这技术」"},
    {"id": "b012_ev0470_0260", "translation": "「唔，想象不出东云小姐会做有趣的致辞……」"},
    {"id": "b012_ev0470_0262", "translation": "「不，别在意」"},
    {"id": "b012_ev0470_0266", "translation": "「那个，那我去那边换咯」"},
    {"id": "b012_ev0470_0269", "translation": "「这下未玖也是真正的女初中生」"},
    {"id": "b012_ev0470_0276", "translation": "「对。东云小姐很可爱，不如说非常漂亮……」"},
    {"id": "b012_ev0470_0281", "translation": "「然后然后，朝冈学园入学式怎么样？」"},
    {"id": "b012_ev0470_0294", "translation": "「差两岁，未玖再过2年也能到那程度」"},
    {"id": "b012_ev0470_0312", "translation": "然后手绕到腰后，摘下皮带上的手表。"},
    {"id": "b012_ev0470_0319", "translation": "看着一身女孩打扮扭扭捏捏，搞得我像干了坏事一样。"},
    {"id": "b012_ev0470_0337", "translation": "「陆斗君」"},
    {"id": "b012_ev0470_0341", "translation": "「陆斗君？」"},
    {"id": "b012_ev0470_0362", "translation": "「哎？陆斗君认识？」"},
    {"id": "b012_ev0470_0383", "translation": "「呵呵，太好了」", "note": "预算过紧（歩夢放不下）"},
]

bad = [p["id"] for p in patches
       if "\t" in p["translation"] or "\n" in p["translation"] or "\r" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 宽度自检：新译文显示宽度必须 <= budget
def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

budget = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for row in csv.DictReader(f, delimiter="\t"):
        budget[row["id"]] = int(row["budget"])

over = [(p["id"], enc_len(p["translation"]), budget.get(p["id"]))
        for p in patches
        if p["id"] not in budget or enc_len(p["translation"]) > budget[p["id"]]]
if over:
    for pid, n, b in over:
        print("OVER %s: %d>%s" % (pid, n, b))
    raise SystemExit("budget overflow: %d patches" % len(over))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width checks passed")
