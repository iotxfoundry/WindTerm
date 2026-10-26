#pragma once

#include <QHash>
#include <QMainWindow>
#include <QPointer>
#include <QPoint>

#include "core/LocaleManager.h"
#include "core/MenuConfig.h"
#include "core/ScriptHost.h"

struct ToolbarEntry;

class QCloseEvent;
class QAction;
class CommandPalette;
class QEvent;
class FilerPane;
class QLineEdit;
class QMenu;
class MuxDesktop;
class QResizeEvent;
class QTabBar;
class QTimer;
class QToolBar;
class MuxPaneGroup;
class QuickBar;
class SearchPane;
class SessionPane;
class SshSession;
class StatusBar;
class TerminalView;
class TransferBar;
class TransferCenter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    // P3 命令面板入口（0x768dfa window_openCommandPalette）：懒建+设初值+show
    void openCommandPalette(const QString &prefix);

protected:
    void closeEvent(QCloseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onPlaceholderAction();
    void onRestoreLayout();
    void togglePane(QWidget *pane);
    void onAddressBarReturn();

private:
    void createMenus();
    void createFallbackMenus();
    void createToolBar();
    void addToolBarEntry(QToolBar *toolBar, const ToolbarEntry &entry);
    void installPaneToolBar(QWidget *pane);
    QWidget *paneHost(QWidget *pane);
    void buildMenu(QMenu *menu, const QVector<MenuEntry> &entries);
    // 0x76cb16/0x76c3ee：每 QMenu 挂 aboutToShow→动态更新 / aboutToHide→dynamic 动作清理
    void hookMenuUpdate(QMenu *menu);
    void showPopupMenu(QWidget *paneLike, Qt::KeyboardModifiers mods);
    // TerminalView::contextMenuRequested 落点：sender() 即 view（UniqueConnection 去重连）
    void onTerminalContextMenu(const QPoint &globalPos, Qt::KeyboardModifiers mods);
    QAction *makeAction(const QString &actionId);
    static QString displayActionText(const QString &en, const QString &translated);
    void createCentral();
    // KitGroup 装配（setupBars 0x008bade2 同款，自 createCentral 抽出供分屏复用——落点 1）
    QWidget *createKitGroup();
    QToolBar *buildGroupToolBar();
    // 焦点 view 沿父链找 MuxPaneGroup（0x8ca6ca 焦点链骨架等价）；无焦点回退主组
    MuxPaneGroup *activeMuxGroup() const;
    // ── P7b：tmux 会话 GUI（I 节挂载+J 节 Tmux.* 动作桥）──
    // shortcut: MuxDesktop 落位挂账(原版 TerminalWidget+0x1d0 关联),当前以 activeMuxGroup
    // 当前页 stack 插页替换待真机定——tmux 模式启用时 MuxDesktop 顶替 TerminalView 显示，
    // TerminalView 隐藏不销毁（%exit 恢复显示）
    void attachMuxDesktop(TerminalView *view);
    void detachMuxDesktop(TerminalView *view);
    MuxDesktop *activeMuxDesktop() const;
    void createStatusBar();
    QWidget *createBottomTabs();
    QString makeMenuTitle(const QString &base, int n) const;
    void initActionRegistry();
    void connectSessionPane(SessionPane *pane);
    // F3：host key 确认/警告窗（worker 等回执的落点在 SshSession::hostKeyAnswer）
    void hookSshSession(SshSession *session);
    QuickBar *ensureQuickBar();
    void toggleQuickBar();

signals:
    // view 切换转发到 ScriptWindow/ScriptTerminal::viewActivated（createCentral stack 处 emit）
    void viewSignalForScripts(QObject *view);

private:
    LocaleManager &m_locale;
    MuxPaneGroup *m_muxPaneGroup;
    QToolBar *m_toolBar = nullptr;
    QLineEdit *m_addressBar = nullptr;
    StatusBar *m_statusBar = nullptr;
    ScriptHost m_scriptHost; // 0x005a3106：原版 MainWindow+0x48 脚本宿主（沿父链取 QJSEngine）
    QTabBar *m_viewTabBar = nullptr; // MuxPaneGroup 标签条（无 objectName），"ViewTab Popup" 映射用
    QuickBar *m_quickBar = nullptr; // 懒建（0x85ad2e），toggleQuickBar 首次创建
    // P3 命令面板（0x768dfa +0xc0 QPointer 同构）：WA_DeleteOnClose，关后下次懒重建
    QPointer<CommandPalette> m_commandPalette;
    SearchPane *m_searchPane = nullptr;
    FilerPane *m_filerPane = nullptr; // P5 浏览链宿主锚（createCentral 建）
    TransferBar *m_transferBar = nullptr; // P6 懒建（0x85af56：首个 taskEvent 建）
    TransferCenter *m_transferCenter = nullptr; // 单例锚（hook 一次）
    void ensureTransferBar(); // 0x85af56：懒建+插入 centralVSplitter（SearchPane 之后）
    QHash<TerminalView *, MuxDesktop *> m_muxDesktops; // P7b：host view→MuxDesktop（tmux 会话）
};
