#include "ExplorerPane.h"

ExplorerPane::ExplorerPane(QWidget *parent)
    : QTreeWidget(parent)
{
    setHeaderHidden(true);

    auto *workspace = new QTreeWidgetItem(this, QStringList{QStringLiteral("workspace")});
    auto *project = new QTreeWidgetItem(workspace, QStringList{QStringLiteral("WindTerm")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("src")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("docs")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("tools")});

    expandAll();
}
