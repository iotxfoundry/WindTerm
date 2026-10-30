#pragma once

#include <QByteArray>
#include <QIcon>
#include <QMap>
#include <QString>

// 主题图标链 —— 语料转写(批 49;铁律 6)。
// 语料函数族:
//   theme_icon_load_svg 00756cd6(1272B):名空 → 默认;iconCache
//     查得 → 取条目 QIcon;否则(名含 "::" 或 .svg 后缀)→
//     SvgIconEngine(name) 包装 → iconCache_lookupEntry 入缓存 →
//     非空 && QColor::isValidColor(recolor)→ FUN_00756b68 着色
//   iconCache_lookupEntry 005df09e(1006B):sorted 名→QIcon 查/插
//     (语料自定义节点:0x20 头 + +0x100 子表;cited 深层表示;
//     行为面 = QMap 等价承载 —— 排序查得即用/未查得插默认)
//   FUN_00639200(98B):SvgIconEngine ctor —— QIconEngine 基 +
//     名字引用 @+8 + scale 1.0 @+0x10 + 三清零域(@+0x18/20/28)
//   FUN_00756b68(331B):着色循环 —— availableSizes → pixmap →
//     createMaskFromColor(color,MaskOutColor) → fill(color) →
//     setMask → addPixmap
// 主题容器:进程级单例(DAT_011c1ce0 语料;本单元静态承载)。
namespace ThemeIcons {

// 00756cd6:主题 SVG 图标装载(recolor = 有效色名时着色)
QIcon loadSvg(const QString &name, const QString &recolor);

} // namespace ThemeIcons
