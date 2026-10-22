#pragma once

#include <QWidget>

class QColor;
class Session;
class QStackedWidget;
class QTabBar;
class QToolButton;

class MuxPaneGroup : public QWidget
{
    Q_OBJECT

public:
    explicit MuxPaneGroup(QWidget *parent = nullptr);

    // 复用与 + 钮相同的建标签路径；会话由调用方 start()
    void openSession(Session *session, const QString &title, const QColor &color);

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
