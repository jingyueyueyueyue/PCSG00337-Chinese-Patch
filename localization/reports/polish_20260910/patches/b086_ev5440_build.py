# -*- coding: utf-8 -*-
"""b086_ev5440 润色补丁构建：生成 JSON 并按批次真实 budget 做显示宽度自检。"""
import csv
import json
import sys

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b086_ev5440.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b086_ev5440.json"

patches = [
    {"id": "b086_ev5440_0001", "translation": "但光是看着，我们也能感觉到真央酱在勉强自己……"},
    {"id": "b086_ev5440_0003", "translation": "班里的大家高兴极了，互相拥抱、互相击掌。"},
    {"id": "b086_ev5440_0011", "translation": "「……啊，抱歉。别在意我！」"},
    {"id": "b086_ev5440_0019", "translation": "「不……没找到老爷子……」"},
    {"id": "b086_ev5440_0020", "translation": "「嗯！没有茂森同学，留不下这么好的成绩！」"},
    {"id": "b086_ev5440_0034", "translation": "果然还是不安……"},
    {"id": "b086_ev5440_0035", "translation": "像被温柔的话语触动了，真央酱有点哽咽。"},
    {"id": "b086_ev5440_0036", "translation": "苦恼了好一阵之后——"},
    {"id": "b086_ev5440_0056", "translation": "「我也是……而且大概也猜得到奉莉同学想说什么……」", "note": ""},
    {"id": "b086_ev5440_0059", "translation": "「真央酱被判破门都怪我们。必须设法请老爷子撤回」"},
    {"id": "b086_ev5440_0117", "translation": "所以一刻也不能分心！"},
    {"id": "b086_ev5440_0123", "translation": "真央酱一惊，看向我。"},
    {"id": "b086_ev5440_0136", "translation": "古朴威严的门楼把大家都震住了。"},
    {"id": "b086_ev5440_0147", "translation": "面向前方，老爷子直直地盯着我。"},
    {"id": "b086_ev5440_0149", "translation": "把剑高高举起，朝老爷子冲去。"},
    {"id": "b086_ev5440_0170", "translation": "「……名字是陆斗吧」"},
    {"id": "b086_ev5440_0173", "translation": "「……话说完了？」", "note": ""},
    {"id": "b086_ev5440_0175", "translation": "「……打、打扰了」"},
    {"id": "b086_ev5440_0179", "translation": "「……也要上」", "note": ""},
    {"id": "b086_ev5440_0181", "translation": "「……嗯，准了」", "note": ""},
    {"id": "b086_ev5440_0198", "translation": "「怎么办」", "note": "预算紧省略问号"},
    {"id": "b086_ev5440_0202", "translation": "「老夫并非责怪她当女仆。老夫命真央全力投入樱花祭的活动」"},
    {"id": "b086_ev5440_0205", "translation": "「茂森同学绝不是自己说要做的。责任始终在拜托她的我们身上」"},
    {"id": "b086_ev5440_0224", "translation": "「嗯，是的……」", "note": ""},
    {"id": "b086_ev5440_0227", "translation": "「欢、欢迎…」"},
    {"id": "b086_ev5440_0239", "translation": "「以、以女人身份…不行…」"},
    {"id": "b086_ev5440_0241", "translation": "「你若获胜，便解除真央的破门」"},
    {"id": "b086_ev5440_0242", "translation": "「你有想变回女人的渴望……也就是执念」"},
    {"id": "b086_ev5440_0250", "translation": "「可当初决定当男人的究竟是谁？」"},
    {"id": "b086_ev5440_0254", "translation": "「那、那样的话我…」"},
    {"id": "b086_ev5440_0257", "translation": "「看在友情份上，最后再给真央一次解除破门的机会」"},
    {"id": "b086_ev5440_0269", "translation": "「是……是的……真的是让我受之有愧的朋友……陆斗、大家……」", "note": ""},
    {"id": "b086_ev5440_0271", "translation": "「是……当女仆时我享受着身为女人……这便是被破门的原因」"},
    {"id": "b086_ev5440_0281", "translation": "「大、大家，别为我到这份上……」", "note": ""},
    {"id": "b086_ev5440_0288", "translation": "「知道了……我做。今后当女人」", "note": "预算紧压缩"},
    {"id": "b086_ev5440_0304", "translation": "「正说着……」", "note": ""},
    {"id": "b086_ev5440_0321", "translation": "「那明天见」", "note": ""},
    {"id": "b086_ev5440_0340", "translation": "「要和章介君道别呢」"},
    {"id": "b086_ev5440_0341", "translation": "「总在想这样真的好吗……」"},
    {"id": "b086_ev5440_0343", "translation": "「不过陆斗明知勉强也上了……嗯，是友情的力量啊」"},
    {"id": "b086_ev5440_0344", "translation": "这样啊，一辈子的决定可就太重了……"},
    {"id": "b086_ev5440_0347", "translation": "「陆斗，干得好」"},
    {"id": "b086_ev5440_0349", "translation": "「唔……不是没有……」", "note": ""},
]

bad = [p["id"] for p in patches if "\t" in p["translation"] or "\n" in p["translation"]]
if bad:
    raise SystemExit("control chars in: %r" % bad)

# 显示宽度自检：全角=2、半角=1，与校验器 enc_len 同规则，超宽即拒绝生成
def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)

rows = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for r in csv.DictReader(f, delimiter="\t"):
        rows[r["id"]] = r

errors = []
for p in patches:
    rid = p["id"]
    if rid not in rows:
        errors.append("unknown id: " + rid)
        continue
    w = enc_len(p["translation"])
    b = int(rows[rid]["budget"])
    if w > b:
        errors.append(f"{rid} too_long: width {w} > budget {b}")
if errors:
    print("WIDTH/ID CHECK FAILED:")
    for e in errors:
        print("  " + e)
    sys.exit(1)

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width checks passed")
