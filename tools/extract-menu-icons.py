#!/usr/bin/env python3
#
# 从 WindTerm 2.7.0 原版菜单截图裁剪动作图标。
# 素材来源：运行 WindTerm 2.7.0（KingToolbox 版权所有）得到的菜单渲染图
#           docs/imgs/original/orig_menu_N.png + terminal/configs/menu.config。
# 仅用于本地界面还原研究；图标版权归 KingToolbox，不随仓库分发。
#
# 用法：python3 tools/extract-menu-icons.py
# 输出：assets/icons/<ActionId>.png（纯黑剪影 + alpha 掩码，运行时按 icon.theme 着色）
#       与 assets/icons/manifest.json（可重复运行，覆盖）。

import json
import os
import re
import statistics
import sys

from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MENU_CONFIG = "/opt/WindTerm_2.7.0/terminal/configs/menu.config"
IMAGE_DIR = os.path.join(ROOT, "docs/imgs/original")
OUT_DIR = os.path.join(ROOT, "assets/icons")


def strip_line_comments(text):
    out = []
    in_string = False
    escaped = False
    i = 0
    while i < len(text):
        ch = text[i]
        if in_string:
            out.append(ch)
            if escaped:
                escaped = False
            elif ch == "\\":
                escaped = True
            elif ch == '"':
                in_string = False
            i += 1
            continue
        if ch == '"':
            in_string = True
            out.append(ch)
            i += 1
            continue
        if ch == "/" and i + 1 < len(text) and text[i + 1] == "/":
            while i < len(text) and text[i] not in "\r\n":
                i += 1
            continue
        out.append(ch)
        i += 1
    return "".join(out)


def load_menu_config(path):
    with open(path, "rb") as f:
        data = f.read().decode("utf-8-sig")
    return json.loads(strip_line_comments(data))


def slug(title):
    text = title.replace("&", "").strip().lower()
    text = re.sub(r"[^a-z0-9]+", "-", text).strip("-")
    return text or "submenu"


def rows_to_bands(rows):
    bands = []
    for y in rows:
        if bands and y - bands[-1][1] <= 2:
            bands[-1] = (bands[-1][0], y)
        else:
            bands.append((y, y))
    return bands


def detect_item_bands(image):
    width, height = image.size
    pixels = image.load()
    corners = [pixels[1, 1], pixels[width - 2, 1], pixels[1, height - 2], pixels[width - 2, height - 2]]
    bg = tuple(statistics.median(pixel[channel] for pixel in corners) for channel in range(3))

    hits = []
    x0, x1 = 4, max(4, width - 8)
    for y in range(height):
        total = 0
        foreground = 0
        for x in range(x0, x1):
            p = pixels[x, y]
            total += 1
            if max(abs(p[c] - bg[c]) for c in range(3)) > 10:
                foreground += 1
        if total and foreground / total > 0.08:
            hits.append(y)

    return [band for band in rows_to_bands(hits) if band[1] - band[0] + 1 >= 6]


def main():
    if not os.path.isfile(MENU_CONFIG):
        print(f"menu.config not found: {MENU_CONFIG}", file=sys.stderr)
        return 1

    config = load_menu_config(MENU_CONFIG)
    menu_names = [entry["Menu"] for entry in config["Kit"]]
    os.makedirs(OUT_DIR, exist_ok=True)
    manifest = {}

    print(f"{'menu':<12} {'entries':>7} {'bands':>5} {'cropped':>7}  note")
    for index, name in enumerate(menu_names):
        image_path = os.path.join(IMAGE_DIR, f"orig_menu_{index}.png")
        image = Image.open(image_path).convert("RGB")

        entries = [entry for entry in config[name] if "Separator" not in entry]
        bands = detect_item_bands(image)

        if len(entries) != len(bands):
            print(f"{name:<12} {len(entries):>7} {len(bands):>5} {0:>7}  WARN count mismatch, skipped")
            continue

        cropped = 0
        for entry, (top, bottom) in zip(entries, bands):
            if "Action" in entry:
                key = entry["Action"]
            else:
                key = slug(entry["Menu"])

            y0 = max(0, top - 2)
            y1 = min(image.height, bottom + 3)
            icon = image.crop((6, y0, 38, y1))

            # 白底按亮度转 alpha，RGB 固定纯黑：运行时由 icon.theme 着色
            alpha = icon.convert("L").point(lambda value: 255 - value)
            file_name = key + ".png"

            mask = Image.new("RGBA", icon.size, (0, 0, 0, 0))
            mask.putalpha(alpha)
            mask.save(os.path.join(OUT_DIR, file_name))

            manifest[key] = {"file": file_name, "menu": name, "y": top}
            cropped += 1

        print(f"{name:<12} {len(entries):>7} {len(bands):>5} {cropped:>7}")

    manifest_path = os.path.join(OUT_DIR, "manifest.json")
    with open(manifest_path, "w", encoding="utf-8") as f:
        json.dump(manifest, f, indent=2, ensure_ascii=False)
        f.write("\n")

    print(f"\nmanifest: {manifest_path} ({len(manifest)} icons)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
