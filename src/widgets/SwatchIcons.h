// 原版色板图标生成模板（反编译提取自 WindTerm 2.7.0 二进制，docs/phase10-findings.md）
// king::colorXXX 系列 = 以下三个 SVG 模板 + 颜色/半径/透明度参数替换后经 QSvgRenderer 渲染
#pragma once
#include <QColor>
#include <QIcon>
#include <QPixmap>
#include <QPainter>

namespace SwatchIcons {

// 圆环色板（king::colorXXX 默认形态：描边圆）
inline QIcon ring(const QColor &color, int size = 16, int radius = 12, int strokeWidth = 36) {
    // 模板: <svg><rect fill='none' width='418' height='418'/><circle stroke='%1' stroke-width='36'
    //        cx='209' cy='209' r='%2'/>%3</svg>   (418 逻辑坐标)
    QPixmap pm(size, size);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing);
    const qreal scale = qreal(size) / 418.0;
    p.setPen(QPen(color, strokeWidth * scale));
    p.setBrush(Qt::NoBrush);
    p.drawEllipse(QPointF(209 * scale, 209 * scale), radius * scale, radius * scale);
    return QIcon(pm);
}

// 实心圆色板（fill-opacity 0.8 + 描边）
inline QIcon filledCircle(const QColor &color, int size = 16, int radius = 12) {
    QPixmap pm(size, size);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing);
    const qreal scale = qreal(size) / 418.0;
    QColor fill = color;
    fill.setAlphaF(0.8);
    p.setPen(QPen(color, 18 * scale));
    p.setBrush(fill);
    p.drawEllipse(QPointF(209 * scale, 209 * scale), radius * scale, radius * scale);
    return QIcon(pm);
}

// 方块色板
inline QIcon square(const QColor &color, int size = 16, int opacity = 255) {
    QPixmap pm(size, size);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing);
    const qreal scale = qreal(size) / 418.0;
    QColor fill = color;
    fill.setAlpha(opacity);
    p.setPen(Qt::NoPen);
    p.setBrush(fill);
    p.drawRect(QRectF(103 * scale, 103 * scale, 212 * scale, 212 * scale));
    return QIcon(pm);
}

} // namespace SwatchIcons
