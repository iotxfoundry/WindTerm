// 图标解析契约（docs/phase13）：仅 wind.actions 带 icon 字段的动作有图标——
// king.svg 矢量（KingIcons 按 icon.theme 着色）→ 主题同名 SVG → 空 QIcon（按钮回退纯文字）。
// 截图裁剪位图管线已按契约删除（2020 截图曾两次误导，证据链禁截图素材）。
#pragma once
#include <QColor>

#include "KingIcons.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QHash>
#include <QIcon>

#include "core/Assets.h"

namespace ActionIcons {

inline QString themeImagesDir(const QString &theme) {
    const QString base = QStringLiteral("assets/themes/%1/images").arg(theme);
    if (QDir(base).exists())
        return base;
    return QStringLiteral("assets/themes/default/images");
}

inline QIcon iconFor(const QString &actionId, const QString &iconName, const QString &theme) {
    Q_UNUSED(actionId);
    // 原版契约：仅 wind.actions 带 icon 字段的动作有图标（king.svg 矢量），其余纯文字（docs/phase13）
    QString kingName = iconName;
    kingName.remove(QLatin1String("king::"));
    if (!kingName.isEmpty()) {
        const QIcon king = KingIcons::icon(kingName, theme, 16);  // Qt Fusion PM_SmallIconSize 默认 16；原版工厂 rect 动态不可达
        if (!king.isNull())
            return king;
    }
    QString name = iconName;
    name.remove(QLatin1String("king::"));
    // 名字即文件名（小写），与原版 images/%1.svg 模板一致
    const QString base = Assets::dir() + QStringLiteral("/themes");
    for (const QString &dir : { QStringLiteral("%1/%2/images").arg(base, theme),
                                QStringLiteral("%1/default/images").arg(base) }) {
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
