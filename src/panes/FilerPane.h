#pragma once

#include <QTreeWidget>

class FilerPane : public QTreeWidget
{
    Q_OBJECT

public:
    explicit FilerPane(QWidget *parent = nullptr);
};
