// 图标解析——忠实原版（docs/phase10/11-findings.md）：
// 掩码 PNG 的着色取活动主题 icon.theme 的 .pixmap .pen stroke（fallback .brush fill，再 black）；
// 否则按名字找主题 images/<name>.svg；再空 QIcon（按钮自动回退显示文字）。
// 原版无 QPainter 生成器（phase5 推断已推翻）；king::colorXXX 色板见 SwatchIcons.h。
#pragma once
#include <QColor>

#include "KingIcons.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QHash>
#include <QIcon>
#include <QImage>
#include <QPixmap>
#include <QRegularExpression>

#include "core/Assets.h"

namespace ActionIcons {

inline QString themeImagesDir(const QString &theme) {
    const QString base = QStringLiteral("assets/themes/%1/images").arg(theme);
    if (QDir(base).exists())
        return base;
    return QStringLiteral("assets/themes/default/images");
}

// icon.theme 的图标色：.pixmap .pen { stroke } → .pixmap .brush { fill } → black
inline QColor themeIconColor(const QString &theme) {
    static QHash<QString, QColor> cache;
    if (cache.contains(theme))
        return cache.value(theme);

    QColor color(Qt::black);
    QFile file(Assets::dir() + QStringLiteral("/themes/%1/icon.theme").arg(theme));
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        if (data.startsWith("\xEF\xBB\xBF"))
            data.remove(0, 3);
        QString text = QString::fromUtf8(data);
        text.replace(QStringLiteral("\r\n"), QStringLiteral("\n"));

        bool found = false;
        const QRegularExpression penBlock(QStringLiteral("\\.pixmap\\s+\\.pen\\s*\\{([^}]*)\\}"));
        const QRegularExpression strokeValue(QStringLiteral("stroke\\s*:\\s*([^;]+)"));
        const QRegularExpressionMatch pen = penBlock.match(text);
        if (pen.hasMatch()) {
            const QRegularExpressionMatch value = strokeValue.match(pen.captured(1));
            if (value.hasMatch()) {
                const QColor candidate(value.captured(1).trimmed());
                if (candidate.isValid()) {
                    color = candidate;
                    found = true;
                }
            }
        }

        if (!found) {
            const QRegularExpression brushBlock(QStringLiteral("\\.pixmap\\s+\\.brush\\s*\\{([^}]*)\\}"));
            const QRegularExpression fillValue(QStringLiteral("fill\\s*:\\s*([^;]+)"));
            const QRegularExpressionMatch brush = brushBlock.match(text);
            if (brush.hasMatch()) {
                const QRegularExpressionMatch value = fillValue.match(brush.captured(1));
                if (value.hasMatch()) {
                    const QColor candidate(value.captured(1).trimmed());
                    if (candidate.isValid())
                        color = candidate;
                }
            }
        }
    }

    cache.insert(theme, color);
    return color;
}

// 黑色剪影 + alpha 掩码 → 按主题色着色
inline QIcon tintedMaskIcon(const QString &path, const QColor &color) {
    QImage image(path);
    if (image.isNull())
        return QIcon();
    image = image.convertToFormat(QImage::Format_ARGB32);

    for (int y = 0; y < image.height(); ++y) {
        QRgb *line = reinterpret_cast<QRgb *>(image.scanLine(y));
        for (int x = 0; x < image.width(); ++x) {
            const int alpha = qAlpha(line[x]);
            line[x] = qRgba(color.red(), color.green(), color.blue(), alpha);
        }
    }
    return QIcon(QPixmap::fromImage(image));
}

// ① 菜单截图裁剪的掩码 PNG（按 icon.theme 着色）
// ② 主题同名 SVG（iconName 由调用方传入） ③ 空 QIcon（按钮自动回退文字）
inline QIcon iconFor(const QString &actionId, const QString &iconName, const QString &theme) {
    // 原版契约：仅 wind.actions 带 icon 字段的动作有图标（king.svg 矢量），其余纯文字（docs/phase13）
    QString kingName = iconName;
    kingName.remove(QLatin1String("king::"));
    if (!kingName.isEmpty()) {
        const QIcon king = KingIcons::icon(kingName, theme, 32);
        if (!king.isNull())
            return king;
    }
    QString name = iconName;
    name.remove(QLatin1String("king::"));
    // 名字即文件名（小写），与原版 images/%1.svg 模板一致
    for (const QString &dir : { QStringLiteral("assets/themes/%1/images").arg(theme),
                                QStringLiteral("assets/themes/default/images") }) {
        const QString path = dir + QStringLiteral("/") + name.toLower() + QStringLiteral(".svg");
        if (QFile::exists(path))
            return QIcon(path);
    }
    return QIcon();
}

// 兼容旧调用：名字同时作为 actionId 与 SVG 名
inline QIcon iconFor(const QString &semanticName, const QString &theme) {
    return iconFor(semanticName, semanticName, theme);
}

} // namespace ActionIcons
