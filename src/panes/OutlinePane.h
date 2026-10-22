#pragma once

#include <QListWidget>

class OutlinePane : public QListWidget
{
    Q_OBJECT

public:
    explicit OutlinePane(QWidget *parent = nullptr);
};
