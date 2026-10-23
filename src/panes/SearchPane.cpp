#include "SearchPane.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>
#include <QVBoxLayout>

#include "core/LocaleManager.h"

SearchPane::SearchPane(QWidget *parent)
    : QWidget(parent)
    , m_searchEdit(new QLineEdit(this))
    , m_searchButton(new QPushButton(tr("Search"), this))
    , m_results(new QTreeWidget(this))
{
    // KitPane 三连 0x008c3bbe：objectName → setWindowIcon（挂账）→ setWindowTitle(King_title 0x008a1106)
    setObjectName(QStringLiteral("SearchPane"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Search")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    m_results->setColumnCount(3);
    m_results->setHeaderLabels({tr("File"), tr("Line"), tr("Match")});
    m_results->addTopLevelItem(new QTreeWidgetItem(m_results, QStringList{QStringLiteral("MainWindow.cpp"), QStringLiteral("42"), QStringLiteral("MainWindow")}));
    m_results->addTopLevelItem(new QTreeWidgetItem(m_results, QStringList{QStringLiteral("README.md"), QStringLiteral("7"), QStringLiteral("WindTerm")}));

    auto *searchRow = new QHBoxLayout;
    searchRow->addWidget(m_searchEdit);
    searchRow->addWidget(m_searchButton);

    auto *layout = new QVBoxLayout(this);
    layout->addLayout(searchRow);
    layout->addWidget(m_results);
}
