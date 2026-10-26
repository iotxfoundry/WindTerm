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
    // 把原版类名改写成 #objectName 才能命中 gui.theme 的 TextView/ViewGroup/KitBar 等规则
    // （原版 TabGroup 类的标签行实例 objectName=ViewGroup，0x008baf26）
    QString qss = m_qss;
    // TabGroup 链式规则按骨架树逐条映射（0x7ebdfc 同款：改写保持规则语义，树差入注释）：
    // - MuxDesktop > TabGroup > QTabBar（gui.theme:676）：骨架 MuxDesktop 自持 QTabBar
    //   （MuxDesktop::buildUi hbox[QTabBar,...]，无 TabGroup 容器层）→ 中段剥除
    qss.replace(QStringLiteral("MuxDesktop > TabGroup"), QStringLiteral("MuxDesktop"));
    // - MuxPaneGroup > TabGroup / ShellPane > TabGroup（gui.theme:686/724）：骨架标签行容器
    //   实挂 ViewGroup（MuxPaneGroup ctor 0x008baf26 对照；ShellPane 未来补标签行即命中）
    qss.replace(QStringLiteral("MuxPaneGroup > TabGroup"), QStringLiteral("MuxPaneGroup > #ViewGroup"));
    qss.replace(QStringLiteral("ShellPane > TabGroup"), QStringLiteral("ShellPane > #ViewGroup"));
    // "TabGroup"→"#ViewGroup"：裸后代规则（TabGroup QToolButton/#TextLabel/#CloseButton）
    // 与类名不同名实例，非 token 循环能表达的映射
    qss.replace(QLatin1String("TabGroup"), QStringLiteral("#ViewGroup"));
    // 子串安全：TabGroup/ViewGroup/KitBar… 均非其他 QSS 标识符的子串（gui.theme 全量 rg 核过）
    for (const char *name : {"TextView", "KitBar", "AppletBar", "TerminalWindow"}) {
        const QLatin1String token(name);
        qss.replace(token, QStringLiteral("#") + token);
    }
    qApp->setStyleSheet(qss);

    // 全局窗口/输入底色 = #efefef：原版 gui.theme 无全局背景规则，实机采样全域 #efefef
    // （菜单栏 #ebebed≈Fusion Button 灰）；且 gui.theme 让 QLineEdit 仅 focus 时白 → 非焦点灰底。
    // 显式固化 Fusion 默认灰（替代早期误设的白），并抵消 offscreen 平台样式差异
    QPalette palette = qApp->palette();
    palette.setColor(QPalette::Window, QColor(QStringLiteral("#efefef")));
    palette.setColor(QPalette::Base, QColor(QStringLiteral("#efefef")));
    qApp->setPalette(palette);
}
