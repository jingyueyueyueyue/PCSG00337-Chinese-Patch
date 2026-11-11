# -*- coding: utf-8 -*-
# b072_ev4450 润色补丁构建脚本（自检：控制字符）
import json
patches = [
    {"id": "b072_ev4450_0004", "translation": "我在操作笔记本电脑的拜田同学身旁提出意见。"},
    {"id": "b072_ev4450_0022", "translation": "拜田同学像是松了口气。"},
    {"id": "b072_ev4450_0049", "translation": "「而我上初中时班上有奉莉在嘛。那家伙男女都喜欢她，还能维系班级和睦」"},
    {"id": "b072_ev4450_0059", "translation": "「三谷君提到ｅｅｎ×ｖｉｊｆ时，在大家面前笑着说『啊哈哈—完蛋了哟—』」"},
    {"id": "b072_ev4450_0115", "translation": "「这就说明拜田同学很受大家信赖」"},
    {"id": "b072_ev4450_0145", "translation": "连我稍有些担心会如何表现的女生三人组也……"},
    {"id": "b072_ev4450_0210", "translation": "导演拜田同学人人争抢，忙得不可开交。"},
    {"id": "b072_ev4450_0215", "translation": "以自己这个比谁都了解的人当原型来写，角色就不会走样吧。"},
    {"id": "b072_ev4450_0217", "translation": "拜田同学、我和演员们聚在一起开练习前的碰头会。"},
    {"id": "b072_ev4450_0230", "translation": "「是我。有空吗？」"},
    {"id": "b072_ev4450_0239", "translation": "「越是张大嘴发声，共鸣就越多，声音也就越大」"},
    {"id": "b072_ev4450_0315", "translation": "休息时步梦也在认真地看着台本。"},
    {"id": "b072_ev4450_0320", "translation": "戏剧练习还在继续。"},
    {"id": "b072_ev4450_0339", "translation": "「……听你这么说，真的好开心……」"},
    {"id": "b072_ev4450_0342", "translation": "「……三、三谷君都这么说，我想就是这样……」"},
    {"id": "b072_ev4450_0344", "translation": "「纯、纯粹散心？」"},
    {"id": "b072_ev4450_0386", "translation": "「呃——说起来」"},
    {"id": "b072_ev4450_0397", "translation": "「这样啊……您不把这事禀报老爷吗……？」"},
    {"id": "b072_ev4450_0408", "translation": "可你们还是努力开起了店……店里还挂着过世母亲起的名字……"},
]
bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)
json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b072_ev4450.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
