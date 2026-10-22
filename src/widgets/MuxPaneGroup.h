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

public:
    // 标签行（tabBar+addBtn+menuBtn 容器）：MainWindow 将其提升到 central VBox 顶行，
    // 模拟原版 TabGroup 经 setMenuWidget 占菜单槽（全宽，位于工具栏行之上）
    QWidget *tabBarRow() const { return m_tabBarRow; }

private:
    void addPane(const QString &title, const QColor &color);

    QWidget *m_tabBarRow;
    QTabBar *m_tabBar;
    QStackedWidget *m_stack;
    QToolButton *m_addButton;
    QToolButton *m_menuButton;
};
