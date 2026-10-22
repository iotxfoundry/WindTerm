#pragma once

#include <QTabWidget>

class QColor;

class MuxPaneGroup : public QTabWidget
{
    Q_OBJECT

public:
    explicit MuxPaneGroup(QWidget *parent = nullptr);

private:
    void addPane(const QString &title, const QColor &color);
};
