#pragma once

#include <QApplication>
#include <QFile>
#include <QIcon>
#include <QStyle>
#include <QStringList>

#include "core/ThemeManager.h"

namespace ActionIcons {

inline QStyle::StandardPixmap standardPixmapFor(const QString &actionIdOrName)
{
    const QString name = actionIdOrName.toLower();

    if (name.contains(QStringLiteral("remove")) || name.contains(QStringLiteral("delete"))
        || name.contains(QStringLiteral("close")) || name.contains(QStringLiteral("trash")))
        return QStyle::SP_TrashIcon;
    if (name.contains(QStringLiteral("add")) || name.contains(QStringLiteral("new"))
        || name.contains(QStringLiteral("create")))
        return QStyle::SP_FileIcon;
    if (name.contains(QStringLiteral("search")) || name.contains(QStringLiteral("find")))
        return QStyle::SP_FileDialogContentsView;
    if (name.contains(QStringLiteral("ping")) || name.contains(QStringLiteral("network"))
        || name.contains(QStringLiteral("traceroute")))
        return QStyle::SP_ComputerIcon;
    if (name.contains(QStringLiteral("reboot")) || name.contains(QStringLiteral("restart"))
        || name.contains(QStringLiteral("system")))
        return QStyle::SP_BrowserReload;
    if (name.contains(QStringLiteral("copy")))
        return QStyle::SP_DialogApplyButton;
    if (name.contains(QStringLiteral("move")))
        return QStyle::SP_ArrowRight;
    if (name.contains(QStringLiteral("open")))
        return QStyle::SP_DialogOpenButton;
    if (name.contains(QStringLiteral("save")))
        return QStyle::SP_DialogSaveButton;
    if (name.contains(QStringLiteral("folder")) || name.contains(QStringLiteral("dir")))
        return QStyle::SP_DirIcon;
    if (name.contains(QStringLiteral("help")))
        return QStyle::SP_DialogHelpButton;
    if (name.contains(QStringLiteral("about")) || name.contains(QStringLiteral("info")))
        return QStyle::SP_MessageBoxInformation;
    if (name.contains(QStringLiteral("refresh")) || name.contains(QStringLiteral("reload")))
        return QStyle::SP_BrowserReload;
    if (name.contains(QStringLiteral("back")))
        return QStyle::SP_ArrowBack;
    if (name.contains(QStringLiteral("forward")))
        return QStyle::SP_ArrowForward;
    if (name.contains(QStringLiteral("up")))
        return QStyle::SP_ArrowUp;
    if (name.contains(QStringLiteral("down")))
        return QStyle::SP_ArrowDown;
    if (name.contains(QStringLiteral("settings")) || name.contains(QStringLiteral("config")))
        return QStyle::SP_FileDialogDetailedView;

    return QStyle::SP_FileIcon;
}

// 主题同名 SVG 优先，否则标准图标占位（king:: 图标为程序化绘制，未还原）
inline QIcon iconFor(const QString &actionIdOrName)
{
    const QString fileName = actionIdOrName.toLower() + QStringLiteral(".svg");
    const QStringList dirs{
        QStringLiteral("assets/themes/%1/images").arg(ThemeManager::instance().currentTheme()),
        QStringLiteral("assets/themes/default/images")
    };
    for (const QString &dir : dirs) {
        const QString path = dir + QLatin1Char('/') + fileName;
        if (QFile::exists(path))
            return QIcon(path);
    }
    return QApplication::style()->standardIcon(standardPixmapFor(actionIdOrName));
}

} // namespace ActionIcons
