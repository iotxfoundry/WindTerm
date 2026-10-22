#pragma once

#include <QColor>
#include <QFile>
#include <QFont>
#include <QIcon>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QRectF>
#include <QStringList>
#include <QtMath>

#include "core/Assets.h"
#include "core/ThemeManager.h"

class QWidget;

namespace ActionIcons {

// 原版 king::* 图标即 QPainter 程序化绘制（phase5）；这里用同架构的语义占位图形
inline QIcon paintIcon(const QString &semantic, const QColor &color, int size = 16)
{
    QPixmap pixmap(size, size);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.scale(size / 16.0, size / 16.0);

    QPen pen(color);
    pen.setWidthF(2.0);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    const QString name = semantic.toLower();

    auto line = [&painter](qreal x1, qreal y1, qreal x2, qreal y2) {
        painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
    };

    if (name.contains(QStringLiteral("remove")) || name.contains(QStringLiteral("trash"))) {
        painter.drawRect(QRect(4, 5, 8, 8));
        line(3, 4, 13, 4);
        line(8, 2, 8, 4);
    } else if (name.contains(QStringLiteral("move"))) {
        line(8, 2, 8, 14);
        line(2, 8, 14, 8);
        line(6, 4, 8, 2);
        line(10, 4, 8, 2);
        line(6, 12, 8, 14);
        line(10, 12, 8, 14);
        line(4, 6, 2, 8);
        line(4, 10, 2, 8);
        line(12, 6, 14, 8);
        line(12, 10, 14, 8);
    } else if (name.contains(QStringLiteral("menu")) || name.contains(QStringLiteral("more"))
               || name.contains(QStringLiteral("kitmore")) || name.contains(QStringLiteral("≡"))) {
        line(3, 4, 13, 4);
        line(3, 8, 13, 8);
        line(3, 12, 13, 12);
    } else if (name.contains(QStringLiteral("add")) || name.contains(QStringLiteral("new"))
               || name.contains(QStringLiteral("create")) || name.contains(QStringLiteral("+"))) {
        line(8, 3, 8, 13);
        line(3, 8, 13, 8);
    } else if (name.contains(QStringLiteral("copy"))) {
        painter.drawRect(QRect(4, 4, 7, 9));
        painter.drawRect(QRect(6, 3, 7, 9));
    } else if (name.contains(QStringLiteral("traceroute"))) {
        painter.setBrush(color);
        painter.drawEllipse(QPointF(3, 12), 1.5, 1.5);
        painter.drawEllipse(QPointF(8, 4), 1.5, 1.5);
        painter.drawEllipse(QPointF(13, 10), 1.5, 1.5);
        painter.setBrush(Qt::NoBrush);
        line(3, 12, 8, 4);
        line(8, 4, 13, 10);
    } else if (name.contains(QStringLiteral("ping")) || name.contains(QStringLiteral("network"))) {
        painter.setBrush(color);
        painter.drawEllipse(QPointF(8, 8), 1.5, 1.5);
        painter.setBrush(Qt::NoBrush);
        painter.drawArc(QRectF(4, 4, 8, 8), 45 * 16, 90 * 16);
        painter.drawArc(QRectF(2, 2, 12, 12), 45 * 16, 90 * 16);
    } else if (name.contains(QStringLiteral("shell")) || name.contains(QStringLiteral("terminal"))) {
        painter.drawRect(QRect(2, 3, 12, 10));
        line(4, 6, 6, 8);
        line(6, 8, 4, 10);
        line(7, 10, 11, 10);
    } else if (name.contains(QStringLiteral("cat")) || name.contains(QStringLiteral("edit"))) {
        painter.drawRect(QRect(4, 2, 8, 12));
        line(6, 5, 10, 5);
        line(6, 8, 10, 8);
        line(6, 11, 9, 11);
        line(10, 2, 12, 4);
    } else if (name.contains(QStringLiteral("ls")) || name.contains(QStringLiteral("list"))
               || name.contains(QStringLiteral("file"))) {
        painter.drawRect(QRect(4, 2, 8, 12));
        line(6, 5, 10, 5);
        line(6, 8, 10, 8);
        line(6, 11, 9, 11);
    } else if (name.contains(QStringLiteral("reboot")) || name.contains(QStringLiteral("power"))) {
        painter.drawArc(QRectF(3, 3, 10, 10), 30 * 16, 300 * 16);
        line(8, 2, 8, 7);
    } else if (name.contains(QStringLiteral("disconnect")) || name.contains(QStringLiteral("plug"))) {
        line(3, 5, 7, 9);
        line(9, 7, 13, 11);
        line(7, 8, 9, 6);
    } else if (name.contains(QStringLiteral("reconnect")) || name.contains(QStringLiteral("refresh"))
               || name.contains(QStringLiteral("reload"))) {
        painter.drawArc(QRectF(4, 4, 8, 8), 30 * 16, 120 * 16);
        painter.drawArc(QRectF(4, 4, 8, 8), 210 * 16, 120 * 16);
        line(11, 4, 13, 4);
        line(5, 12, 3, 12);
    } else if (name.contains(QStringLiteral("settings")) || name.contains(QStringLiteral("gear"))
               || name.contains(QStringLiteral("config"))) {
        painter.drawEllipse(QPointF(8, 8), 3, 3);
        for (int i = 0; i < 6; ++i) {
            const qreal angle = i * M_PI / 3.0;
            line(8 + 4 * qCos(angle), 8 + 4 * qSin(angle),
                 8 + 6 * qCos(angle), 8 + 6 * qSin(angle));
        }
    } else {
        painter.drawEllipse(QPointF(8, 8), 6, 6);
        QFont font = painter.font();
        font.setPixelSize(10);
        font.setBold(true);
        painter.setFont(font);
        painter.drawText(QRect(0, 0, 16, 16), Qt::AlignCenter, QStringLiteral("?"));
    }

    painter.end();
    return QIcon(pixmap);
}

inline QIcon accentIcon(const QString &semantic, int size = 16)
{
    return paintIcon(semantic, QColor(QStringLiteral("#007acc")), size);
}

// 主题同名 SVG 优先，否则 QPainter 语义图标
inline QIcon iconFor(const QString &actionIdOrName)
{
    const QString fileName = actionIdOrName.toLower() + QStringLiteral(".svg");
    const QStringList dirs{
        Assets::dir() + QStringLiteral("/themes/%1/images").arg(ThemeManager::instance().currentTheme()),
        Assets::dir() + QStringLiteral("/themes/default/images")
    };
    for (const QString &dir : dirs) {
        const QString path = dir + QLatin1Char('/') + fileName;
        if (QFile::exists(path))
            return QIcon(path);
    }
    return accentIcon(actionIdOrName);
}

inline QIcon iconFor(QWidget *context, const QString &semanticName)
{
    Q_UNUSED(context);
    return iconFor(semanticName);
}

} // namespace ActionIcons
