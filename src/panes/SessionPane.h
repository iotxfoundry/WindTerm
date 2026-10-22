#pragma once

#include <QTreeWidget>

class SessionPane : public QTreeWidget
{
    Q_OBJECT

public:
    explicit SessionPane(QWidget *parent = nullptr);
};
