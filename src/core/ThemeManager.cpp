#include "ThemeManager.h"

#include <QApplication>
#include <QFile>
#include <QFont>
#include <QPalette>

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
    // Qt QSS 类型选择器只匹配 C++ 类名（Qt5/6 实测），原版自定义类是 objectName：
    // 把原版类名改写成 #objectName 才能命中 gui.theme 的 TextView/TabGroup/KitBar 等规则
    QString qss = m_qss;
    for (const char *name : {"TextView", "TabGroup", "KitBar", "AppletBar", "TerminalWindow"}) {
        const QLatin1String token(name);
        qss.replace(token, QStringLiteral("#") + token);
    }
    qApp->setStyleSheet(qss);

    // 原版 GUI 为白底窗体（docs/imgs/WindTerm2.7.0.png）；QSS 未覆盖的窗体角色补白
    QPalette palette = qApp->palette();
    palette.setColor(QPalette::Window, Qt::white);
    palette.setColor(QPalette::Base, Qt::white);
    qApp->setPalette(palette);
}
