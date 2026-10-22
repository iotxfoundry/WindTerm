#include "OutlinePane.h"

OutlinePane::OutlinePane(QWidget *parent)
    : QListWidget(parent)
{
    addItem(QStringLiteral("ls -la"));
    addItem(QStringLiteral("cd /var/log"));
    addItem(QStringLiteral("tail -f syslog"));
    addItem(QStringLiteral("git status"));
    addItem(QStringLiteral("make -j8"));
}
