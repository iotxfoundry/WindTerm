#!/usr/bin/env bash
# 从本机 WindTerm 发行包复制骨架所需资产子集（不把 103MB 全量入库）
# 用法: ./tools/fetch-assets.sh /path/to/WindTerm_2.7.0 [repo根=脚本上级]
set -euo pipefail

SRC="${1:?用法: fetch-assets.sh <发行包目录> [仓库根]}"
SRC="${SRC%/}"
REPO="${2:-$(cd "$(dirname "$0")/.." && pwd)}"
ASSETS="$REPO/assets"

[ -f "$SRC/WindTerm" ] || { echo "错误: $SRC 下没有 WindTerm 主程序，请确认发行包目录"; exit 1; }

mkdir -p "$ASSETS/locales"
# 主题子集：仅 SVG 图标 + 字体（跳过 audios，约省 90MB）
for t in default dige-white dige-black dige-black-and-white; do
  if [ -d "$SRC/global/themes/$t" ]; then
    mkdir -p "$ASSETS/themes/$t"
    cp -r "$SRC/global/themes/$t/images"   "$ASSETS/themes/$t/" 2>/dev/null || true
    cp "$SRC/global/themes/$t/"*.theme     "$ASSETS/themes/$t/" 2>/dev/null || true
    cp -r "$SRC/global/themes/$t/fonts"    "$ASSETS/themes/$t/" 2>/dev/null || true
  fi
done
# 全部语言包（<2MB）
cp "$SRC"/global/locales/*.locale "$ASSETS/locales/"
# 数据驱动的动作/配置文件（Phase 3/6）
mkdir -p "$ASSETS/config"
cp "$SRC"/global/wind.config "$SRC"/global/wind.actions "$ASSETS/config/" 2>/dev/null || true
mkdir -p "$ASSETS/config/uiconfigs"
cp "$SRC"/terminal/configs/*.config "$ASSETS/config/uiconfigs/" 2>/dev/null || true

echo "已写入 $ASSETS:"
du -sh "$ASSETS/themes/"* "$ASSETS/locales" 2>/dev/null
