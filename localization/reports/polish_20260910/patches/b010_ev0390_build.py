# -*- coding: utf-8 -*-
"""b010_ev0390 润色补丁构建（自带宽度自检）。"""
import csv
import json
from pathlib import Path

BATCH = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b010_ev0390.tsv")
OUT = Path(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b010_ev0390.json")

patches = [
    {"id": "b010_ev0390_0009", "translation": "最后，东云小姐微微低头致意——"},
    {"id": "b010_ev0390_0017", "translation": "这不是东云小姐嘛。"},
    {"id": "b010_ev0390_0021", "translation": "入学准备说明会上没能重逢……你肯定也升上朝冈了吧？"},
    {"id": "b010_ev0390_0023", "translation": "老爸也瞥了眼住吉同学，挥手回应。"},
    {"id": "b010_ev0390_0024", "translation": "步梦君他们诧异地看着挥手的我。"},
    {"id": "b010_ev0390_0027", "translation": "明天也想让步梦君认识大家。"},
    {"id": "b010_ev0390_0052", "translation": "「是啊。她老家开和果子店，但特别喜欢西点，是老爸做蛋糕的粉丝。」"},
    {"id": "b010_ev0390_0062", "translation": "正好有客人来，我以为东云小姐回来了，结果不是。"},
    {"id": "b010_ev0390_0064", "translation": "这多半是坐桌位的客人……"},
    {"id": "b010_ev0390_0065", "translation": "东云小姐已经注意到我，正轻轻挥手。"},
    {"id": "b010_ev0390_0066", "translation": "东云小姐嫣然一笑。"},
    {"id": "b010_ev0390_0067", "translation": "说着，住吉同学朝老爸低头致意。"},
    {"id": "b010_ev0390_0070", "translation": "我也挥手回应，直到东云小姐的身影消失……"},
    {"id": "b010_ev0390_0072", "translation": "要不是住吉同学和步梦君，我一个人绝对吃不到这种草莓。"},
    {"id": "b010_ev0390_0073", "translation": "我瞥了一眼步梦君的方向。"},
    {"id": "b010_ev0390_0084", "translation": "回想起来，好像从住吉同学回去那会儿起他就有点不对劲……"},
    {"id": "b010_ev0390_0085", "translation": "我下意识看了眼步梦君。"},
    {"id": "b010_ev0390_0087", "translation": "其他人也都差不多。"},
    {"id": "b010_ev0390_0091", "translation": "良子小姐的说明还没完没了。"},
    {"id": "b010_ev0390_0096", "translation": "「由、由良子小姐来说明？」"},
    {"id": "b010_ev0390_0098", "translation": "「那开始了，陆斗君」"},
    {"id": "b010_ev0390_0099", "translation": "「陆斗，明天起在学校要把步梦君当女孩子对待哦？」"},
    {"id": "b010_ev0390_0101", "translation": "「不然不就成了步梦君变成女孩子去朝冈上学了吗？」"},
    {"id": "b010_ev0390_0107", "translation": "「当然。步梦君不能以女孩身份过学园生活就没意义。」"},
    {"id": "b010_ev0390_0111", "translation": "「步梦君明天起以女孩子身份上学，记好了。」"},
    {"id": "b010_ev0390_0117", "translation": "「不、不对，这不是正论的问题……对啊，步梦君本人怎么想？老爸的话不奇怪吗？」"},
    {"id": "b010_ev0390_0120", "translation": "「不，步梦君以女孩子身份上朝冈学园这事我懂了……但为什么要这么做，我完全不明白。」"},
    {"id": "b010_ev0390_0130", "translation": "「那个……我听到步梦君要以女孩子身份上学……这没道理对吧？」"},
    {"id": "b010_ev0390_0134", "translation": "「等、等下！！这也太怪了吧！良子小姐你也觉得吧？」"},
    {"id": "b010_ev0390_0142", "translation": "他抿紧嘴唇，用视线偷偷观察我的样子。"},
    {"id": "b010_ev0390_0145", "translation": "从刚才起他话就变得特别少，眼神不安地四处游移。"},
    {"id": "b010_ev0390_0148", "translation": "而且，据说步梦君遵照那份遗嘱，至今在外面一直以女孩子的身份生活……"},
    {"id": "b010_ev0390_0150", "translation": "只是步梦君不一样。"},
    {"id": "b010_ev0390_0152", "translation": "据说良子小姐的爷爷，也就是步梦君的曾祖父，是位歌舞伎的著名女形。"},
    {"id": "b010_ev0390_0158", "translation": "可是面对明天起要女装上学的人，能说什么？"},
    {"id": "b010_ev0390_0159", "translation": "但现在还无法把步梦君和良子小姐当『家人』看待。"},
    {"id": "b010_ev0390_0160", "translation": "我刻意回避家人意识的举动，原来深深伤害了步梦君吗……"},
    {"id": "b010_ev0390_0162", "translation": "正干劲十足时，就被步梦君搭话了……"},
    {"id": "b010_ev0390_0167", "translation": "穿女生制服，很期待吧？"},
    {"id": "b010_ev0390_0170", "translation": "不过，能看到步梦君害羞脸红的样子也不坏。"},
    {"id": "b010_ev0390_0173", "translation": "步梦君究竟有多重视哥哥这个存在……我算是明白了。"},
    {"id": "b010_ev0390_0174", "translation": "步梦君似乎已经说不出话来，而说实话我也不知道该说什么好。"},
    {"id": "b010_ev0390_0175", "translation": "我叫住了抱着枕头和被子正要出房间的步梦君。"},
    {"id": "b010_ev0390_0178", "translation": "自从听了那件事，我和步梦君几乎没再正经说过话。"},
    {"id": "b010_ev0390_0189", "translation": "「那……那个，步梦君……身心性别不同的……那个？」"},
    {"id": "b010_ev0390_0196", "translation": "「所以对于步梦君女装，我完全不觉得恶心。」"},
    {"id": "b010_ev0390_0197", "translation": "「所以听说妈妈再婚、会有新的兄弟姐妹时，我特别高兴……」"},
    {"id": "b010_ev0390_0199", "translation": "「可是……陆斗君好像并不想被叫哥哥……」"},
    {"id": "b010_ev0390_0208", "translation": "「校门?」", "note": "预算所限问号半角"},
    {"id": "b010_ev0390_0209", "translation": "「虽然现在没法当你是兄弟，但被叫哥哥我完全不讨厌哦。」"},
    {"id": "b010_ev0390_0214", "translation": "「尤其对哥哥有很强的憧憬……要是有哥哥，会是什么样的、什么样的……总是忍不住空想……」"},
    {"id": "b010_ev0390_0218", "translation": "「陆斗……」", "note": "预算过紧"},
    {"id": "b010_ev0390_0222", "translation": "「啊，别误会。就算步梦君真是那样，我也不会觉得恶心哦。」"},
    {"id": "b010_ev0390_0230", "translation": "「嗯。良子小姐的话我听得不太明白，但里面似乎有很深的原因，我不能贸然深究。」"},
    {"id": "b010_ev0390_0233", "translation": "「那个……那我现在就叫，可以吗？」"},
    {"id": "b010_ev0390_0235", "translation": "「对了，步梦君明天要比大家先到学校，对吧？」"},
    {"id": "b010_ev0390_0241", "translation": "「是的呢……不对，是呀。」"},
    {"id": "b010_ev0390_0244", "translation": "「是呢。前提是步梦君的手续已经办完……」"},
    {"id": "b010_ev0390_0252", "translation": "「等下，步梦？怎么了？」", "note": "预算过紧"},
    {"id": "b010_ev0390_0256", "translation": "「怎么？步梦」", "note": "预算过紧"},
    {"id": "b010_ev0390_0258", "translation": "「嗯……陆斗君太温柔，我就……」"},
    {"id": "b010_ev0390_0260", "translation": "「嗯……心、身心性别是一致的……」"},
    {"id": "b010_ev0390_0266", "translation": "「当然，有能做和不能做的……话说，步梦君？」"},
    {"id": "b010_ev0390_0270", "translation": "「我明白，这是我的任性……陆斗君无法当我是兄妹，我也懂……」"},
    {"id": "b010_ev0390_0287", "translation": "就算只是表面功夫……只要能让步梦君的心得到救赎……"},
    {"id": "b010_ev0390_0290", "translation": "好……叫住步梦君……"},
    {"id": "b010_ev0390_0291", "translation": "踩着沙沙作响的沙子上学。"},
    {"id": "b010_ev0390_0302", "translation": "横山君走的是反方向线路没办法，但茂森同学或拜田同学总该碰得上一个吧……"},
    {"id": "b010_ev0390_0308", "translation": "往学校走的一路上，两人东张西望地找步梦。"},
    {"id": "b010_ev0390_0327", "translation": "作为听众的奉莉表情变来变去。"},
    {"id": "b010_ev0390_0338", "translation": "「咦？步梦君已经走了？」"},
    {"id": "b010_ev0390_0342", "translation": "「……哥哥！」"},
    {"id": "b010_ev0390_0343", "translation": "「这女孩？」", "note": "预算过紧"},
    {"id": "b010_ev0390_0356", "translation": "「就是说啊。简直是和制曼哈顿。」"},
    {"id": "b010_ev0390_0357", "translation": "「谁都没碰上呢。」"},
    {"id": "b010_ev0390_0361", "translation": "「不像初中时小孩子穿制服了，挺好。」"},
    {"id": "b010_ev0390_0363", "translation": "「是奉莉同学吧？」"},
    {"id": "b010_ev0390_0364", "translation": "「奈奈濑同学肯定会帮忙，爸爸说与其隐瞒不如先坦白……」"},
    {"id": "b010_ev0390_0367", "translation": "「步梦」", "note": "预算过紧"},
    {"id": "b010_ev0390_0368", "translation": "「步梦君……不是弟弟吗？」"},
    {"id": "b010_ev0390_0371", "translation": "「奈奈濑！！」", "note": "预算过紧"},
    {"id": "b010_ev0390_0372", "translation": "「那个，奈奈濑同学……女装的事说了……」"},
    {"id": "b010_ev0390_0380", "translation": "「我说，我就觉得步梦君眼熟，这不是陆斗毕业远足时偷瞄一眼就一见钟情的那个女孩吗。」"},
    {"id": "b010_ev0390_0386", "translation": "「你就是陆斗家的新家人步梦君？」"},
    {"id": "b010_ev0390_0391", "translation": "「陆斗君早」"},
    {"id": "b010_ev0390_0407", "translation": "「干嘛啦」", "note": "预算过紧"},
    {"id": "b010_ev0390_0418", "translation": "就是准考证那女孩！"},
    {"id": "b010_ev0390_0424", "translation": "不，倒也不是特别感兴趣，只是觉得肯定很适合他，多少想看一眼……"},
    {"id": "b010_ev0390_0433", "translation": "做早餐的步梦君……不，步梦他……"},
    {"id": "b010_ev0390_0440", "translation": "凉拌菠菜和盐烤鲑鱼。"},
]

# 自检：控制字符 + id 存在 + 宽度不超预算
budget = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        budget[r["id"]] = int(r["budget"])

bad = []
for p in patches:
    t = p["translation"]
    if "\t" in t or "\n" in t or "\r" in t:
        bad.append(f"{p['id']}: control char")
    if p["id"] not in budget:
        bad.append(f"{p['id']}: unknown id")
        continue
    n = sum(1 if ord(c) < 128 else 2 for c in t)
    if n > budget[p["id"]]:
        bad.append(f"{p['id']}: width {n}>{budget[p['id']]} :: {t}")
if bad:
    raise SystemExit("SELF-CHECK FAILED:\n" + "\n".join(bad))

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
