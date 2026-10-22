#pragma once

#include <QWidget>

class QColor;
class QStackedWidget;
class QTabBar;
class QToolButton;

class MuxPaneGroup : public QWidget
{
    Q_OBJECT

public:
    explicit MuxPaneGroup(QWidget *parent = nullptr);

private slots:
    void onTabCloseRequested();
    void onAddSession();

private:
    void addPane(const QString &title, const QColor &color);

    QTabBar *m_tabBar;
    QStackedWidget *m_stack;
    QToolButton *m_addButton;
    QToolButton *m_menuButton;
};
