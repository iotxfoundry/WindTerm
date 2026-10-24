#pragma once

#include "KitPane.h"

#include <QTreeWidget>

class QLineEdit;

class ExplorerPane : public KitPane
{
    // 骨架近似：ExplorerPane 原为 QTreeWidget（0x008c3bbe 派生）；工具行=toolbar.config
    // ExplorerPane[FilterEdit] 顶部行（FilterEdit ctor 0x0057eb0c），树本体挂 objectName
    Q_OBJECT

public:
    explicit ExplorerPane(QWidget *parent = nullptr);

signals:
    void filterChanged(const QString &text);

private:
    QLineEdit *m_filter;
    QTreeWidget *m_tree;
};
