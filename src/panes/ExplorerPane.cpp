#include "ExplorerPane.h"

ExplorerPane::ExplorerPane(QWidget *parent)
    : QTreeWidget(parent)
{
    // 原版 KitPane 派生类以类名挂 objectName（0x008c3bbe+0x0072fbee）；gui.theme:544
    setObjectName(QStringLiteral("ExplorerPane"));
    setHeaderHidden(true);

    auto *workspace = new QTreeWidgetItem(this, QStringList{QStringLiteral("workspace")});
    auto *project = new QTreeWidgetItem(workspace, QStringList{QStringLiteral("WindTerm")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("src")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("docs")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("tools")});

    expandAll();
}
