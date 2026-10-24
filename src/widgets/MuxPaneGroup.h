#pragma once

#include <QWidget>

#include <functional>

class QColor;
class Session;
class QStackedWidget;
class QTabBar;
class QToolButton;
class TerminalView;

class MuxPaneGroup : public QWidget
{
    Q_OBJECT

public:
    explicit MuxPaneGroup(QWidget *parent = nullptr);

    // 多组分屏工厂：MainWindow::createKitGroup 装配点注入（widgets 层不依赖宿主，
    // 返回新 KitGroup——内含新 MuxPaneGroup/muxRow/标签行/ToolBar，0x89f516 新建组）
    static std::function<QWidget *()> s_createGroup;

    // 分屏/窗格生命周期引擎（批 2）：
    // splitView 0x8d4166：父 splitter（MuxRow）里再插新 KitGroup+新 MuxPaneGroup；
    // dir 0=Left/1=Right/2=Top/3=Bottom
    void splitView(int dir);
    // splitGroup 0x8d42e8：insertPaneSplitter 引擎（0x5a277a 同款）组内再插一窗格，
    // 旧组焦点 view 迁移过去并激活
    void splitGroup(int dir);
    // closeGroup 0x8cc99c / canCloseGroup 0x8cc916
    bool canCloseGroup() const;
    void closeGroup();
    // activateNextView 链 0x8ce784：全 splitter 树 view 循环激活
    void activateNextView(bool next);

    // 0x0089e9e0：按旧 view 的会话参数在新组重建标签（splitView 用）
    void openRebuiltSession(TerminalView *old);

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
