#include "ThemeManager.h"

#include <QDir>
#include <QFileInfo>

ThemeManager &ThemeManager::instance()
{
    static ThemeManager manager;
    return manager;
}

void ThemeManager::setTheme(const QString &name)
{
    m_theme = name;
    m_images.clear();

    const QDir dir(QStringLiteral("assets/themes/%1/images").arg(name));
    if (!dir.exists())
        return; // 主题资产缺失时静默跳过

    const QFileInfoList files = dir.entryInfoList({QStringLiteral("*.svg")}, QDir::Files, QDir::Name);
    for (const QFileInfo &file : files)
        m_images.append(file.absoluteFilePath());
}
