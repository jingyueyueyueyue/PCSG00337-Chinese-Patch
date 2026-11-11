# -*- coding: utf-8 -*-
"""b048_ev3240（奉莉线 ev3240-3260）润色补丁构建，含宽度自检。"""
import csv
import json

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b048_ev3240.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b048_ev3240.json"

patches = [
    {"id": "b048_ev3240_0002", "translation": "三天两夜的住宿研修结束了，果然有点累。"},
    {"id": "b048_ev3240_0003", "translation": "三天两夜的住宿研修结束，久违回家的那晚——"},
    {"id": "b048_ev3240_0010", "translation": "现在，刚好轮到步梦洗澡，房间里只有我一个。"},
    {"id": "b048_ev3240_0012", "translation": "「好像不是大事，放心了」"},
    {"id": "b048_ev3240_0020", "translation": "「……难道说超开心？」"},
    {"id": "b048_ev3240_0025", "translation": "「然后，是问步梦要不要一起去」"},
    {"id": "b048_ev3240_0068", "translation": "被请吃了太多，总觉得有点过意不去。"},
    {"id": "b048_ev3240_0087", "translation": "奉莉的叔叔笑盈盈地捏起了寿司。"},
    {"id": "b048_ev3240_0091", "translation": "「那个，奉莉酱？」"},
    {"id": "b048_ev3240_0094", "translation": "「……话说今天吃的，真要算的话得多少钱啊？」"},
    {"id": "b048_ev3240_0125", "translation": "「中途……啊对了」"},
    {"id": "b048_ev3240_0127", "translation": "「你们俩吃得都那么香，我捏着也值了」"},
    {"id": "b048_ev3240_0142", "translation": "「啊哈哈。那还死不了呢！好料还多着呢」"},
    {"id": "b048_ev3240_0146", "translation": "「没关系。我也受了不少步梦的照顾呢」"},
    {"id": "b048_ev3240_0147", "translation": "「今天的中脂格外好吃！」"},
    {"id": "b048_ev3240_0157", "translation": "「嗯……总觉得，两人眼里都完全没有对方……」"},
    {"id": "b048_ev3240_0164", "translation": "「那、那个……能吃吗？」"},
    {"id": "b048_ev3240_0194", "translation": "「听他们这么说，请他们来就值了，爸爸」"},
    {"id": "b048_ev3240_0218", "translation": "「好嘞，那看在你们照顾奉莉的份上，都使劲吃吧」"},
    {"id": "b048_ev3240_0224", "translation": "「嗯……这就去爸爸那边？」"},
    {"id": "b048_ev3240_0234", "translation": "原本热闹的店里一下子安静下来。"},
    {"id": "b048_ev3240_0248", "translation": "门口铃声和店员的问候传来，我朝柜台望去——"},
    {"id": "b048_ev3240_0251", "translation": "奉莉似乎被我说服了，把刚才递到我面前的巧克力蛋糕一口吃掉。"},
    {"id": "b048_ev3240_0253", "translation": "把布丁和饮料放到夏奏酱面前……"},
    {"id": "b048_ev3240_0256", "translation": "久到不在意间接接吻了……"},
    {"id": "b048_ev3240_0259", "translation": "穿私服的夏奏酱在那里。"},
    {"id": "b048_ev3240_0260", "translation": "笑着应答之后，夏奏酱开始打量柜台的展示柜。"},
    {"id": "b048_ev3240_0261", "translation": "夏奏酱发出心底呐喊。"},
    {"id": "b048_ev3240_0264", "translation": "用力挥手，目送夏奏酱消失在车站里。"},
    {"id": "b048_ev3240_0268", "translation": "奉莉在步梦招呼下坐到旁边。"},
    {"id": "b048_ev3240_0274", "translation": "「……你们俩尝一口？」"},
    {"id": "b048_ev3240_0277", "translation": "「……难道是入学说明会上认错的那位……？」"},
    {"id": "b048_ev3240_0294", "translation": "「不过继陆斗之后连叔叔也认错了……夏奏酱是真年轻啊」"},
    {"id": "b048_ev3240_0303", "translation": "「公寓相关文件明天必须寄达对方，刚才才发现少了一页」"},
    {"id": "b048_ev3240_0304", "translation": "「不好意思，有件急事想拜托你」"},
    {"id": "b048_ev3240_0351", "translation": "「我才是被请的呢。谢谢你，步梦」"},
    {"id": "b048_ev3240_0352", "translation": "「也尝尝我的巧克力蛋糕嘛」"},
    {"id": "b048_ev3240_0370", "translation": "「开动啦……嗯嗯」"},
    {"id": "b048_ev3240_0371", "translation": "「谢谢平时对他们俩这么好」"},
    {"id": "b048_ev3240_0399", "translation": "「对了……能帮我跑一趟吗」"},
    {"id": "b048_ev3240_0400", "translation": "「是啊……巧克力蛋糕怎么样？」"},
    {"id": "b048_ev3240_0401", "translation": "「嗯，有什么好吃的吗」"},
    {"id": "b048_ev3240_0410", "translation": "「那，点完单后请到这边来」"},
    {"id": "b048_ev3240_0448", "translation": "步梦……可是男的……"},
    {"id": "b048_ev3240_0453", "translation": "看到那身打扮，还是只像和我们同龄。"},
    {"id": "b048_ev3240_0457", "translation": "不知为何，比夏奏酱那时寂寞得多。"},
    {"id": "b048_ev3240_0462", "translation": "众人起身朝柜台走去。"},
    # 仅改 note：想改但预算压不下的行，保留初翻
    {"id": "b048_ev3240_0013", "translation": "「昨天简直莫名其妙……」", "note": "预算过紧（欲补“说实话”）"},
    {"id": "b048_ev3240_0037", "translation": "「明天一整天有空」", "note": "预算过紧（欲加“都”）"},
    {"id": "b048_ev3240_0078", "translation": "合掌拜托的步梦。", "note": "预算过紧（欲用“双手合十”）"},
    {"id": "b048_ev3240_0306", "translation": "「是吗」", "note": "预算压缩（違うのか？）；预算过紧，欲改“这样啊”放不下"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)


def enc_len(s: str) -> int:
    return sum(1 if ord(c) < 128 else 2 for c in s)


budget = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        budget[r["id"]] = int(r["budget"])

missing = [p["id"] for p in patches if p["id"] not in budget]
if missing:
    raise SystemExit("unknown ids: %r" % missing)

over = [(p["id"], enc_len(p["translation"]), budget[p["id"]])
        for p in patches if enc_len(p["translation"]) > budget[p["id"]]]
if over:
    raise SystemExit("too_long: %r" % over)

with open(OUT, "w", encoding="utf-8") as f:
    json.dump({"patches": patches}, f, ensure_ascii=False, indent=1)
print("patches:", len(patches))
