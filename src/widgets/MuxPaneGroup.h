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

    // selfcheck 用：跳过 QMessageBox::question（原版 0x008df6c0 有确认框，自动应答不可行）
    void setConfirmClose(bool confirm) { m_confirmClose = confirm; }

    // selfcheck 直接驱动关闭路径（QMessageBox 无法自动应答）
    void onTabCloseRequested(int index);
    void onAddSession();

public:
    // 标签行（tabBar+scroll/add/list 按钮容器，objectName=ViewGroup）：MainWindow 经
    // KitGroup::setMenuWidget 挂其 menuWidget 槽（0x008bade2）
    QWidget *tabBarRow() const { return m_tabBarRow; }

private:
    void addPane(Session *session, const QString &title, const QColor &color);

    QWidget *m_tabBarRow;
    QTabBar *m_tabBar;
    QStackedWidget *m_stack;
    QToolButton *m_scrollLeftButton;
    QToolButton *m_scrollRightButton;
    QToolButton *m_addButton;
    QToolButton *m_listButton;
    bool m_confirmClose = true;
};
