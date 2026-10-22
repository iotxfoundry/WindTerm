#pragma once

#include <QJsonArray>
#include <QWidget>

class AppletBar : public QWidget
{
    Q_OBJECT

public:
    explicit AppletBar(const QJsonArray &actions = QJsonArray(), QWidget *parent = nullptr);

private slots:
    void onActionPressed();
};
