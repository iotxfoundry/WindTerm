#pragma once

#include "KitPane.h"

class QLineEdit;
class QPushButton;
class QTreeWidget;

class SearchPane : public KitPane
{
    Q_OBJECT

public:
    explicit SearchPane(QWidget *parent = nullptr);

private:
    QLineEdit *m_searchEdit;
    QPushButton *m_searchButton;
    QTreeWidget *m_results;
};
