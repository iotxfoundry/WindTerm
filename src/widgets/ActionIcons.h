// 图标解析——忠实原版（docs/phase10-findings.md）：
// FUN_007572ac：名字 → 主题 images/<name>.svg 候选路径 → QSvgRenderer 有效则渲染；
// 文件缺失 → 空 QIcon → QToolButton/QAction 自动回退显示文字（Qt 默认行为）。
// 原版无 QPainter 生成器（phase5 推断已推翻）；king::colorXXX 色板见 SwatchIcons.h（已复现的模板）。
#pragma once
#include <QColor>
#include <QDir>
#include <QFile>
#include <QIcon>
#include <QPixmap>

namespace ActionIcons {

// 主题目录：exe 同级 ../assets 优先，CWD 回退（与 Assets::dir 语义一致，避免循环依赖）
inline QString themeImagesDir(const QString &theme) {
    const QString base = QStringLiteral("assets/themes/%1/images").arg(theme);
    if (QDir(base).exists())
        return base;
    return QStringLiteral("assets/themes/default/images");
}

// 命中主题同名 SVG → 图标；否则返回空 QIcon（按钮自动回退显示文字，忠实原版）
inline QIcon iconFor(const QString &semanticName, const QString &theme) {
    const QString bare = semanticName;
    QString name = bare;
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

} // namespace ActionIcons
