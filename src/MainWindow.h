#pragma once

#include <QHash>
#include <QMainWindow>
#include <QPointer>
#include <QPoint>
#include <QStringList>

#include "core/LocaleManager.h"
#include "core/MenuConfig.h"
#include "core/ScriptHost.h"

struct ToolbarEntry;

class QCloseEvent;
class QAction;
class QColor;
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

    // ── 测试驱动面（test_menu_actions）──
    // R52 View Popup 条目取节（0x00834f2c→0x008c5f16 门卫+修饰键节名）
    QVector<MenuEntry> viewPopupEntriesForTest(Qt::KeyboardModifiers mods)
    {
        return viewPopupEntriesForTestImpl(mods);
    }
    // 0x76cb16 逐 action update 体直调（aboutToShow 同源）
    void refreshMenuActionsForTest(QMenu *menu) { refreshMenuActionsForTestImpl(menu); }
    // Layout 节菜单构建（MenuBarCorner ManageLayoutButton 同节同管线——widgets 层不在
    // 本批改动面，行为面经此驱动）
    void buildLayoutMenuForTest(QMenu *menu);
    // 动作工厂（makeAction 私有，rename 类不在 Kit 菜单的动作经此驱动）
    QAction *makeActionForTest(const QString &actionId) { return makeAction(actionId); }
    // 0x76cb16/0x76c3ee 双挂接面（buildMenu 同源；测试直驱 aboutToShow/aboutToHide 链）
    void hookMenuUpdateForTest(QMenu *menu) { hookMenuUpdate(menu); }

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
    // hookMenuUpdate aboutToShow 体公开面（测试直调；0x76cb16 逐 action update 骨架面）
    void refreshMenuActions(QMenu *menu);
    QVector<MenuEntry> viewPopupEntriesForTestImpl(Qt::KeyboardModifiers mods) { return viewPopupEntries(mods); }
    void refreshMenuActionsForTestImpl(QMenu *menu) { refreshMenuActions(menu); }
    void showPopupMenu(QWidget *paneLike, Qt::KeyboardModifiers mods);
    // R52 终端区右键条目（0x00834f2c→0x008c5f16）：rightClickAction 门卫+修饰键节名取条目
    QVector<MenuEntry> viewPopupEntries(Qt::KeyboardModifiers mods);
    // TerminalView::contextMenuRequested 落点：sender() 即 view（UniqueConnection 去重连）
    void onTerminalContextMenu(const QPoint &globalPos, Qt::KeyboardModifiers mods);
    // 动作执行分派（wind.actions script 面已接线子集）；未接线返回 false（调用方禁用+挂账）
    bool runActionScript(const QString &actionId);
    // R53 moveGroupToGroup 最小实现（原生未逆明挂账）：活动组标签组文本迁到目标名同组
    void moveActiveGroupTo(const QString &targetName);
    // allGroupNames JS 面（0x8cc994 text/state 求值用）：主窗全部组名集合（MuxPaneGroup 标签组）
    Q_INVOKABLE QStringList allGroupNames() const;
    QAction *makeAction(const QString &actionId);
    static QString displayActionText(const QString &en, const QString &translated);
    void createCentral();
    // KitGroup 装配（setupBars 0x008bade2 同款，自 createCentral 抽出供分屏复用——落点 1）
    QWidget *createKitGroup();
    QToolBar *buildGroupToolBar();
    // 焦点 view 沿父链找 MuxPaneGroup（0x8ca6ca 焦点链骨架等价）；无焦点回退主组
    MuxPaneGroup *activeMuxGroup() const;
    // ── P7b：tmux 会话 GUI（I 节挂载+J 节 Tmux.* 动作桥）──
    // attach/detach 深逆 0x00842414/0x00842778 照搬：layout->replaceWidget 原位换入/
    // 换回（第三参 1），desktop 每终端一份（TerminalView::muxDesktop 字段承载守卫）
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
};
