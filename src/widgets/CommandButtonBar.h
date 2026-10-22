#pragma once

#include <QJsonArray>
#include <QWidget>

class CommandButtonBar : public QWidget
{
    Q_OBJECT

public:
    explicit CommandButtonBar(const QJsonArray &actions = QJsonArray(), QWidget *parent = nullptr);

private slots:
    void onActionPressed();
};
