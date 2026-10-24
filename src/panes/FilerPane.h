#pragma once

#include "KitPane.h"

class PaneHeader;
class QTreeWidget;

class FilerPane : public KitPane
{
    Q_OBJECT

public:
    explicit FilerPane(QWidget *parent = nullptr);

signals:
    void closeRequested();

private:
    PaneHeader *m_header;
    QTreeWidget *m_tree;
};
