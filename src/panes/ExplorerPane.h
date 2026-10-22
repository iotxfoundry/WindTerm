#pragma once

#include <QTreeWidget>

class ExplorerPane : public QTreeWidget
{
    Q_OBJECT

public:
    explicit ExplorerPane(QWidget *parent = nullptr);
};
