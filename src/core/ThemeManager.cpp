#include "ThemeManager.h"

#include <QApplication>
#include <QFile>
#include <QFont>

#include "Assets.h"

ThemeManager &ThemeManager::instance()
{
    static ThemeManager manager;
    return manager;
}

bool ThemeManager::loadTheme(const QString &name)
{
    QFile file(Assets::dir() + QStringLiteral("/themes/%1/gui.theme").arg(name));
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);

    QString text = QString::fromUtf8(data);
    text.replace(QStringLiteral("\r\n"), QStringLiteral("\n"));

    const QString assetsDir = Assets::dir();
    text.replace(QStringLiteral("${AppDir}/global/themes"), assetsDir + QStringLiteral("/themes"));

    text.replace(QStringLiteral("${AppDir}"), assetsDir);

    QString fontFamily = QApplication::font().family();
    if (fontFamily.isEmpty())
        fontFamily = QStringLiteral("monospace");
    text.replace(QStringLiteral("${SystemFonts}"), fontFamily);

    m_currentTheme = name;
    m_qss = text;
    return true;
}

void ThemeManager::apply() const
{
    qApp->setStyleSheet(m_qss);
}
