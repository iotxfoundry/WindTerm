#!/usr/bin/env python3
# 从原版菜单截图（docs/imgs/original/orig_menu_*.png）裁剪图标 → assets/icons/<ActionId>.png
# 仅覆盖 wind.actions 无 icon 字段的动作（king 矢量优先，见 ActionIcons.h）
# 素材：运行 WindTerm 2.7.0（KingToolbox 版权）离屏采集（docs/phase11）
import json, os, re, sys
from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(ROOT, "docs", "imgs", "original")
OUT_DIR = os.path.join(ROOT, "assets", "icons")
MENU_CONFIG = "/opt/WindTerm_2.7.0/terminal/configs/menu.config"
WIND_ACTIONS = "/opt/WindTerm_2.7.0/global/wind.actions"

def bands(img, x0, x1, thresh=18, gap=2, minh=6):
    im = img.convert("RGB"); w, h = im.size
    rows = []
    for y in range(h):
        hit = any(abs(im.getpixel((x, y))[0]-245) > thresh or abs(im.getpixel((x, y))[1]-245) > thresh
                  or abs(im.getpixel((x, y))[2]-245) > thresh for x in range(x0, min(x1, w)))
        rows.append(hit)
    out = []; s = None; prev = -10
    for y, hit in enumerate(rows):
        if hit:
            if s is None: s = y
            prev = y
        else:
            if s is not None and y - prev > gap:
                if prev - s + 1 >= minh: out.append((s, prev))
                s = None
    if s is not None and prev - s + 1 >= minh: out.append((s, prev))
    return out

raw_actions = open(WIND_ACTIONS, encoding="utf-8-sig").read()
kpos = [(m.group(1), m.start()) for m in re.finditer(r'^\s{2}"([A-Za-z0-9_.]+)"\s*:\s*\{', raw_actions, re.M)]
kpos.append(("__END__", len(raw_actions)))
def has_icon(aid):
    for i, (k, s) in enumerate(kpos[:-1]):
        if k == aid:
            return re.search(r'"icon"\s*:', raw_actions[s:kpos[i+1][1]]) is not None
    return False

cfg = json.loads(re.sub(r'^\s*//.*$', '', open(MENU_CONFIG, encoding="utf-8-sig").read(), flags=re.M))
menus = [m["Menu"] for m in cfg["Kit"]]

os.makedirs(OUT_DIR, exist_ok=True)
cropped = 0
for i, mn in enumerate(menus):
    entries = [e for e in cfg.get(mn, []) if "Separator" not in e]
    try:
        image = Image.open(os.path.join(SRC_DIR, f"orig_menu_{i}.png"))
    except FileNotFoundError:
        print(f"{mn}: 截图缺失，跳过"); continue
    bs = bands(image, 44, 200)
    if len(bs) != len(entries):
        print(f"{mn}: 带 {len(bs)} != 条目 {len(entries)}，跳过（对齐失败保护）"); continue
    for e, (top, bottom) in zip(entries, bs):
        key = e.get("Action") or ("slug-" + re.sub(r"[^a-z0-9]+", "-", e.get("Menu", "").replace("&", "").lower()))
        if e.get("Action") and has_icon(e["Action"]):
            continue  # 有 icon 字段：king 矢量优先，无需裁剪
        icon = image.crop((10, max(0, top - 2), 38, min(image.height, bottom + 3)))
        alpha = icon.convert("L").point(lambda v: min(255, (255 - v) * 255 // 200))
        mask = Image.new("RGBA", icon.size, (0, 0, 0, 0))
        mask.putalpha(alpha)
        bbox = mask.getchannel("A").getbbox()
        if bbox:
            mask = mask.crop(bbox)  # 原生尺寸，不缩放
        mask.save(os.path.join(OUT_DIR, f"{key}.png"))
        cropped += 1
    print(f"{mn}: 裁剪完成")

print(f"manifest 未生成；共裁剪 {cropped} 个（仅无 icon 字段动作）")
