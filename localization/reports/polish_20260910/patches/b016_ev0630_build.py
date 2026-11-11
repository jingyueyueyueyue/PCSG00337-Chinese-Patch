# -*- coding: utf-8 -*-
"""b016_ev0630 润色补丁构建脚本（自带显示宽度自检）。
宽度规则：半角=1，全角=2；新译文宽度必须 <= 批次 budget。
"""
import csv
import json
import sys

BATCH = r"D:\VITA3K\ux0\app\PCSG00337\localization\text\work\b016_ev0630.tsv"
OUT = r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b016_ev0630.json"

patches = [
    {"id": "b016_ev0630_0009", "translation": "确实学长超帅，步梦有这反应也难怪……等等，步梦是男的啊。"},
    {"id": "b016_ev0630_0034", "translation": "「那，食堂组回来前就坐着等吧」"},
    {"id": "b016_ev0630_0036", "translation": "「那是啥样？超想看看呀～」"},
    {"id": "b016_ev0630_0043", "translation": "「所以，那只是学长想多了……」"},
    {"id": "b016_ev0630_0062", "translation": "「我是小林琉伍。刚才的话你们大概明白了，我是足球部的二年级。往后多指教」"},
    {"id": "b016_ev0630_0078", "translation": "「学长，介绍下。弟……不，我妹步梦」"},
    {"id": "b016_ev0630_0095", "translation": "「琉伍学长!!」", "note": "预算紧用半角!!"},
    {"id": "b016_ev0630_0110", "translation": "「不、不是……没好到能给人看……」"},
    {"id": "b016_ev0630_0169", "translation": "「毕竟实际入部等到『樱花祭』结束后也没问题，好好考虑吧」"},
    {"id": "b016_ev0630_0199", "translation": "但拜田同学不在乎笑点质量。"},
    {"id": "b016_ev0630_0202", "translation": "递过粉笔，代替拜田同学站上讲台。"},
    {"id": "b016_ev0630_0203", "translation": "看着慌了神的拜田同学……"},
    {"id": "b016_ev0630_0215", "translation": "被大家一笑，转眼就陷入慌乱的拜田同学。"},
    {"id": "b016_ev0630_0216", "translation": "被老师点名，和拜田同学走到前面。"},
    {"id": "b016_ev0630_0223", "translation": "「……以上匆匆说明完毕，有——什么问题的人——！」"},
    {"id": "b016_ev0630_0241", "translation": "「三谷君」", "note": "预算紧省略……"},
    {"id": "b016_ev0630_0242", "translation": "「住宿研修首日晚上，全班受邀出席学园合作温泉设施的晚餐！哇——啪啪——咻咻！」"},
    {"id": "b016_ev0630_0291", "translation": "随后拜田同学站上讲台——"},
    {"id": "b016_ev0630_0294", "translation": "不过，昨天章介说的要是真的，应该没到那么夸张……"},
    {"id": "b016_ev0630_0295", "translation": "不过并非嘲笑拜田同学，只是单纯觉得好笑的笑声。"},
    {"id": "b016_ev0630_0303", "translation": "确认同学基本都回去后，我招呼委员们过来。"},
    {"id": "b016_ev0630_0313", "translation": "正副委员长拜田同学和我站在黑板前，其他人坐在最前排。"},
    {"id": "b016_ev0630_0315", "translation": "莫非对特效化妆有兴趣？", "note": ""},
    {"id": "b016_ev0630_0317", "translation": "是拜田同学"},
    {"id": "b016_ev0630_0318", "translation": "是拜田同学的女仆装。"},
    {"id": "b016_ev0630_0321", "translation": "是步梦", "note": ""},
    {"id": "b016_ev0630_0324", "translation": "是奉莉", "note": ""},
    {"id": "b016_ev0630_0330", "translation": "「……抱歉……真不像我，忘乎所以了」"},
    {"id": "b016_ev0630_0333", "translation": "「……只有横山君一人呢？」"},
    {"id": "b016_ev0630_0342", "translation": "「没、没关系，别在意」"},
    {"id": "b016_ev0630_0364", "translation": "「中餐、意大利菜、法国菜……」"},
    {"id": "b016_ev0630_0367", "translation": "「当然，女仆咖啡店是绅士的梦想」"},
    {"id": "b016_ev0630_0381", "translation": "「可以可以。这阵子我来主持，拜田同学担任书记」"},
    {"id": "b016_ev0630_0385", "translation": "「嗯，就是说先定好店的定位，再研究符合它的菜单比较好」"},
    {"id": "b016_ev0630_0391", "translation": "「鲷鱼烧、章鱼烧、咖喱拉面……」", "note": "预算紧省略ええと"},
    {"id": "b016_ev0630_0399", "translation": "「抱歉，我孤陋寡闻，听到特效化妆也没啥概念……」"},
    {"id": "b016_ev0630_0407", "translation": "「赞成女仆咖啡店的人呢」"},
    {"id": "b016_ev0630_0411", "translation": "「不过章介君的梦先不论，长班会上也作为意见提出来了，我觉得不能无视」"},
    {"id": "b016_ev0630_0412", "translation": "「不过用水设施没法解决，据说正经做菜推荐在烹饪室进行哦——」"},
    {"id": "b016_ev0630_0417", "translation": "「就是这样，实在遗憾……」"},
    {"id": "b016_ev0630_0425", "translation": "正合我意", "note": "预算紧省略引号"},
    {"id": "b016_ev0630_0427", "translation": "「可以。相对地IH电磁炉、铁板烧之类的电热厨具就ＯＫ没问题。啊，吹风机算不算来着？」"},
    {"id": "b016_ev0630_0428", "translation": "「好——来啦。不飞奔，就地说明哦」"},
    {"id": "b016_ev0630_0442", "translation": "不过我们委员要继续商量，便留在了教室。"},
    {"id": "b016_ev0630_0443", "translation": "说着，章介要和奉莉握手。"},
    {"id": "b016_ev0630_0450", "translation": "拜田同学少见地主动搭话过来。"},
]


def enc_len(s):
    return sum(1 if ord(c) < 128 else 2 for c in s)


budgets = {}
with open(BATCH, encoding="utf-8", newline="") as f:
    for row in csv.DictReader(f, delimiter="\t"):
        budgets[row["id"]] = int(row["budget"])

bad = []
for p in patches:
    tr = p["translation"]
    if "\t" in tr or "\n" in tr or "\r" in tr:
        bad.append((p["id"], "control chars"))
        continue
    if p["id"] not in budgets:
        bad.append((p["id"], "unknown id"))
        continue
    n = enc_len(tr)
    if n > budgets[p["id"]]:
        bad.append((p["id"], f"{n}>{budgets[p['id']]}"))

if bad:
    for pid, why in bad:
        print("BAD %s: %s" % (pid, why))
    sys.exit(1)

json.dump({"patches": patches}, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches), "all width checks passed")
