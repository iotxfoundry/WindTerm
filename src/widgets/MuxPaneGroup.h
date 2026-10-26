#pragma once

#include <QWidget>

#include <functional>

class QColor;
class MuxPane;
class Session;
class QStackedWidget;
class QMenu;
class QToolButton;
class TabGroupBar;
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

    // ── P7b：tmux pane 组模式（MuxWindow 承载，0x8de936/0x8dece0 结构差异点）──
    // TabGroup objectName "PaneGroup"、documentMode(false)、focusPolicy NoFocus、
    // tabsClosable(false)、scrollButtons(false)、doubleClickAction 属性="RenameTab"；
    // attached 组按钮 [ConfigButton]、非 attached [TabAddButton,TabListButton,ConfigButton]，
    // CloseButton visible=false
    void initTmuxMode(bool attached);
    // 组内挂 tmux pane（tab+stack；0x8de1a8 addChildWidget 语义由 MuxPane::setView 承担）
    void attachTmuxPane(MuxPane *pane, const QString &title);
    // 组标题（"%1:%2" paneId:name，0x84b483 链）
    void setPaneTitle(const QString &title);

    // R50 ConfigButton 菜单动作落点（tests 驱动面）：动作按 actionId 分派，
    // 未接线项空槽挂账
    void dispatchConfigAction(const QString &actionId);

    // 测试驱动面：校验 menu.config "MuxPaneGroup" 键动作集（showConfigMenu 同源构建，
    // exec 阻塞不入测试）
    bool configMenuActionsForTest(const QStringList &expectedActionIds) const;

private slots:
    // R50（0x008de2d4）：ConfigButton→menu.config "MuxPaneGroup" 键弹菜单
    void showConfigMenu();

private:
    void addPane(Session *session, const QString &title, const QColor &color);

    QWidget *m_tabBarRow;
    TabGroupBar *m_tabBar;
    QStackedWidget *m_stack;
    QToolButton *m_scrollLeftButton;
    QToolButton *m_scrollRightButton;
    QToolButton *m_addButton;
    QToolButton *m_listButton;
    QToolButton *m_configButton = nullptr; // P7b tmux 模式（initTmuxMode 建）
    QMenu *m_configMenu = nullptr;         // R50：menu.config "MuxPaneGroup" 弹出面（懒建）
    bool m_confirmClose = true;
};
