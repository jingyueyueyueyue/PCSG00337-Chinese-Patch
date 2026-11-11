# -*- coding: utf-8 -*-
import json

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b073_ev4485.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b073_ev4485.json"

patches = [
    {"id": "b073_ev4485_0001", "translation": "――结果拜田同学的意见没通过，最后决定保险起见提早收工，就这样解散了。"},
    {"id": "b073_ev4485_0005", "translation": "不知三人是否多少觉得有责任，都垂头丧气……"},
    {"id": "b073_ev4485_0037", "translation": "仔细想想，知道拜田同学戴隐形眼镜的，原来只有我、奉莉、步梦、真央酱、章介这些活动执行委员。"},
    {"id": "b073_ev4485_0042", "translation": "真央酱急匆匆地冲出了教室。"},
    {"id": "b073_ev4485_0046", "translation": "既然疼痛复发了，那之后她大概没去眼科或眼镜店咨询过吧。"},
    {"id": "b073_ev4485_0052", "translation": "仔细端详拜田同学脚边那小小的反光，发现一小片镜片碎了。"},
    {"id": "b073_ev4485_0053", "translation": "拜田同学呼吸紊乱，脸色也变得煞白。"},
    {"id": "b073_ev4485_0075", "translation": "「ｂｒｉｎｇ ｂａｃｋ是表示『让人想起』的固定搭配……」"},
    {"id": "b073_ev4485_0076", "translation": "「那、那我去角落摘……三谷君，能跟我来吗？」"},
    {"id": "b073_ev4485_0080", "translation": "「对啊。那也没办法嘛？」"},
    {"id": "b073_ev4485_0093", "translation": "「横山君莫名威风的派头挺好。体格也很像样」"},
    {"id": "b073_ev4485_0096", "translation": "「过呼吸——就是过换气综合征啊」"},
    {"id": "b073_ev4485_0113", "translation": "「裸眼几乎什么也看不见……所以你在身边我会安心……」"},
    {"id": "b073_ev4485_0137", "translation": "「离最晚放学时间还有一会儿！来练习吧！」"},
    {"id": "b073_ev4485_0161", "translation": "「没、没什么。大家还等着，我去戴眼镜」"},
    {"id": "b073_ev4485_0171", "translation": "「唉，算上今天还剩四天，只能想办法了」"},
    {"id": "b073_ev4485_0174", "translation": "「要、要说解决……反而出了别的问题……」"},
    {"id": "b073_ev4485_0182", "translation": "现在我能做的，也只有留心别让今天这事留下别扭的余波了……"},
    {"id": "b073_ev4485_0189", "translation": "虽、虽然有点沉……"},
    {"id": "b073_ev4485_0193", "translation": "话说，这阴影竟然重到会当场晕倒吗……"},
    {"id": "b073_ev4485_0196", "translation": "总感觉她绷得太紧了……"},
    {"id": "b073_ev4485_0198", "translation": "突然出声的正是那伙爱捣乱三人组。"},
    {"id": "b073_ev4485_0206", "translation": "「拜田过呼吸？」", "note": "预算紧压缩称谓"},
    {"id": "b073_ev4485_0211", "translation": "「总之。既然这样就得当她的依靠，陆斗」"},
    {"id": "b073_ev4485_0212", "translation": "――我还在想心事，夏奏酱已传达了几项简单的确认事项，还发了资料。"},
    {"id": "b073_ev4485_0214", "translation": "她大概回想起了昨天的事，领会了要刻意不加明说的用意。"},
    {"id": "b073_ev4485_0215", "translation": "班会结束夏奏酱走出去后，奉莉他们围到了我的桌边。"},
    {"id": "b073_ev4485_0218", "translation": "被戳中要害，话卡在喉咙里。"},
    {"id": "b073_ev4485_0237", "translation": "拜田同学今天请假了吗……"},
    {"id": "b073_ev4485_0241", "translation": "那个女生三人组扎成一堆，好像正聊得起劲。"},
    {"id": "b073_ev4485_0252", "translation": "「录像机的硬盘不加点就来不及了嘛——」"},
    {"id": "b073_ev4485_0260", "translation": "「拜田君吗。迟到已有所闻，坐好」"},
    {"id": "b073_ev4485_0268", "translation": "「不过，喊口令的拜田同学现在不在。就由副委员长三谷君代喊吧」"},
    {"id": "b073_ev4485_0272", "translation": "「我明白了」"},
    {"id": "b073_ev4485_0298", "translation": "「三、三谷君，在上课……」"},
    {"id": "b073_ev4485_0305", "translation": "结合她之前的言行，连同从前把短发留长、改戴隐形眼镜一起来想……"},
    {"id": "b073_ev4485_0315", "translation": "果然和小学时代那个称呼脱不了干系啊。"},
    {"id": "b073_ev4485_0324", "translation": "本想劝她把导演交给我、先歇一阵——但放弃了。"},
    {"id": "b073_ev4485_0329", "translation": "看着连声音都在抖的拜田同学，担心得不行。"},
    {"id": "b073_ev4485_0330", "translation": "责任感过人的拜田同学，绝不可能听进去这种话……"},
    {"id": "b073_ev4485_0336", "translation": "拜田同学的呼吸渐渐平稳下来。"},
    {"id": "b073_ev4485_0339", "translation": "奉莉、步梦、真央酱、章介凑过来。"},
    {"id": "b073_ev4485_0343", "translation": "那个女生三人组站着。"},
    {"id": "b073_ev4485_0344", "translation": "「――你真是个怪人啊。若是你愿意在找不到自身价值的我身上发现价值……」"},
    {"id": "b073_ev4485_0347", "translation": "「……拜田同学，有话跟你说」", "note": ""},
    {"id": "b073_ev4485_0354", "translation": "「三谷君……？」", "note": "预算紧压缩结巴"},
    {"id": "b073_ev4485_0370", "translation": "「好担心」"},
    {"id": "b073_ev4485_0412", "translation": "只是一时玩过头……再也不说希实花讨厌的事了"},
    {"id": "b073_ev4485_0419", "translation": "「又是过呼吸！？」"},
    {"id": "b073_ev4485_0435", "translation": "不久拜田同学的呼吸总算平复了。"},
    {"id": "b073_ev4485_0436", "translation": "有这么讨厌自己的名字吗……"},
    {"id": "b073_ev4485_0442", "translation": "大家面色阴沉，悄悄交换视线。"},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

def width(s):
    return sum(2 if ord(c) > 127 else 1 for c in s)

budgets = {}
with open(BATCH, encoding="utf-8") as f:
    f.readline()
    for line in f:
        cols = line.rstrip("\n").split("\t")
        if len(cols) >= 6:
            budgets[cols[0]] = int(cols[4])

errors = []
for p in patches:
    b = budgets.get(p["id"])
    if b is None:
        errors.append("%s: id not found in batch" % p["id"])
        continue
    wd = width(p["translation"])
    if wd > b:
        errors.append("%s: width %d > budget %d | %s" % (p["id"], wd, b, p["translation"]))
if errors:
    raise SystemExit("\n".join(errors))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
