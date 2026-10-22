#include "FilerPane.h"

#include <QHeaderView>

FilerPane::FilerPane(QWidget *parent)
    : QTreeWidget(parent)
{
    setColumnCount(2);
    setHeaderLabels({tr("Name"), tr("Date mod")});
    setRootIsDecorated(false);
    header()->setStretchLastSection(false);
    header()->setSectionResizeMode(0, QHeaderView::Stretch);

    addTopLevelItem(new QTreeWidgetItem(this, QStringList{QStringLiteral(".."), QStringLiteral("2026-10-22 09:12")}));
    addTopLevelItem(new QTreeWidgetItem(this, QStringList{QStringLiteral("bin"), QStringLiteral("2026-09-01 11:40")}));
    addTopLevelItem(new QTreeWidgetItem(this, QStringList{QStringLiteral("etc"), QStringLiteral("2026-08-15 18:03")}));
    addTopLevelItem(new QTreeWidgetItem(this, QStringList{QStringLiteral("home"), QStringLiteral("2026-10-20 07:55")}));
    addTopLevelItem(new QTreeWidgetItem(this, QStringList{QStringLiteral("var"), QStringLiteral("2026-10-21 22:31")}));
}
