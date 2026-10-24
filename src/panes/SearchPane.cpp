#include "SearchPane.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>
#include <QVBoxLayout>

SearchPane::SearchPane(QWidget *parent)
    : KitPane(parent, QStringLiteral("SearchPane"))
    , m_searchEdit(new QLineEdit(this))
    , m_searchButton(new QPushButton(tr("Search"), this))
    , m_results(new QTreeWidget(this))
{
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
