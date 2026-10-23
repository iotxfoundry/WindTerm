#include "OutlinePane.h"

#include "core/LocaleManager.h"

OutlinePane::OutlinePane(QWidget *parent)
    : QListWidget(parent)
{
    // KitPane 三连 0x008c3bbe：objectName → setWindowIcon（挂账）→ setWindowTitle(King_title 0x008a1106)
    setObjectName(QStringLiteral("OutlinePane"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Outline")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    addItem(QStringLiteral("ls -la"));
    addItem(QStringLiteral("cd /var/log"));
    addItem(QStringLiteral("tail -f syslog"));
    addItem(QStringLiteral("git status"));
    addItem(QStringLiteral("make -j8"));
}
