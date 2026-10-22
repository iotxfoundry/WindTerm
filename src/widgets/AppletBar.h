#pragma once

#include <QJsonArray>
#include <QStyle>
#include <QWidget>

class AppletBar : public QWidget
{
    Q_OBJECT

public:
    explicit AppletBar(const QJsonArray &actions = QJsonArray(), QWidget *parent = nullptr);

private:
    static QStyle::StandardPixmap standardIconFor(const QString &actionIdOrName);

private slots:
    void onActionPressed();
};
