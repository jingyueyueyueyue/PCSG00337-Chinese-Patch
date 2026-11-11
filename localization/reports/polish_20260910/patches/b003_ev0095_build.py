import json
patches = [
    {"id": "b003_ev0095_0146", "translation": "「好，马上拆」"},
    {"id": "b003_ev0095_0405", "translation": "小直？", "note": "预算过紧，省略引号"},
]
json.dump({"patches": patches}, open(r"D:\VITA3K\ux0\app\PCSG00337\localization\reports\polish_20260910\patches\b003_ev0095.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("patches:", len(patches))
