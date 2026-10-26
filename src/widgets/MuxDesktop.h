#pragma once

#include <QMap>
#include <QSet>
#include <QSplitter>
#include <QStackedWidget>
#include <QStringList>
#include <QVariant>
#include <QVector>
#include <QWidget>
#include "TabGroupBar.h" // 标签条族面（R45/R46/R47）：成员直接持 TabGroupBar*
class QTimer;
class TerminalView;
class Tmux;
class MuxWindow;
class MuxPaneGroup;
struct LayoutNode;

// 布局语法树节点（0x84b483 splitter_restoreState 输入）：cell=WxH,X,Y[,id]；
// '{'=左右分（Horizontal）、'['=上下分（Vertical）递归包子树；
// 实例 "80x24,0,0{40x24,0,0,1,39x24,41,0,2}"。解析器在 MuxDesktop.cpp。
struct LayoutNode
{
    int w = 0, h = 0, x = 0, y = 0, id = -1;
    bool vertical = false;
    QVector<LayoutNode> kids;
};

// P7b MuxDesktop（0x8d9be0/0x8da51c/0x8d98d0 照搬）：
// QWidget objectName "MuxDesktop"；vbox(0,0)[TabGroup.centralStack, hbox[TabGroup,stretch]]；
// 此 TabGroup：tabsClosable=true、TabAddButton/TabListButton 显示、ConfigButton 隐藏、
// movable；页=Tmux 窗口（MuxWindow）。
// 挂载面：MainWindow::attachMuxDesktop（I 节，activeMuxGroup 当前页 stack 插页替换）。
class MuxDesktop : public QWidget
{
    Q_OBJECT

public:
    explicit MuxDesktop(TerminalView *host, QWidget *parent = nullptr);

    TerminalView *hostView() const { return m_host; }
    Tmux *tmux() const { return m_tmux; }

    // 测试断言面
    int pageCount() const { return m_stack->count(); }
    MuxWindow *windowPage(int windowId) const { return m_pages.value(windowId); }
    // 0x8de3e8 attach 首窗注册：MainWindow 手建的 MuxWindow 挂 desktop 栈+页表；
    // windowId 已知则同步，后续 reconcile/ensureWindowPage 以存在性守卫接管
    void adoptInitialWindow(MuxWindow *win, int windowId);
    TerminalView *viewForPane(int paneId) const;
    // 页签位映射：QTabBar 无 indexOf(QWidget)——mw->tabIndex()（插入/移动/移除时同步）
    int tabIndexOf(MuxWindow *mw) const;

    // ═══ wind.actions Tmux.* script 面（desktop 命令桥，J 节）═══
    QStringList tmuxSessionNames() const { return m_sessionNames; }
    QString currentTmuxSessionName() const;
    void attachTmuxSession(const QString &name);
    void detachTmuxClient();
    void killTmuxSession(const QString &name);
    void executeTmuxCommand(); // QInputDialog 直发
    void renameTmuxSession();  // QInputDialog
    void selectTmuxLayout(const QString &name);
    void synchronizeTmuxPanes(bool on);

signals:
    // %exit 完成帧：desktop 已隐藏（宿主 MainWindow 恢复 TerminalView 显示并弃件）
    void finished();

private:
    void buildUi();
    // E：0x84dd5a onTmuxWindowsChanged 全流程（windowsChanged/windowsRemoved 共路径）
    void reconcile();
    MuxWindow *ensureWindowPage(int windowId, int idx, const QString &name);
    void closePage(int windowId);
    // 0x84b483 splitter_restoreState：布局串→树→组归位（paneId 匹配/摘出 hide）
    void restoreSplitterTree(MuxWindow *mw, const QString &layout);
    void buildLayoutNode(MuxWindow *mw, const LayoutNode &node, QSplitter *parent);
    // 0x8e12c0：root 下全部 QSplitter splitterMoved 防抖→resize-pane 下发
    void hookSplitter(QSplitter *sp);
    void sendPendingResizes();
    // G（0x8e0bb2）：focusChanged→TabBar Active 刷新+pane select-pane
    void onFocusChanged();
    // F（0x877610 链）：capture-pane 补屏/尺寸修正/输出回灌
    void onScreenCaptured(int paneId, bool altScreen, int historySize, const QByteArray &data);
    void onScreenResized(int paneId);
    void onTermsRemoved(const QList<int> &paneIds);
    void feedPaneView(int paneId, const QByteArray &data);
    // H（0x8dd1b8）：attach 三态/单确认
    void onTabCloseRequested(int index);

    MuxPaneGroup *groupUnder(QWidget *w) const;

    TerminalView *m_host = nullptr;
    Tmux *m_tmux = nullptr;
    QStackedWidget *m_stack = nullptr; // TabGroup.centralStack
    TabGroupBar *m_tabBar = nullptr;
    QMap<int, MuxWindow *> m_pages; // windowId→页（desktop 比对 +0x44）
    QHash<MuxWindow *, QString> m_pageStates; // 页 state 面（"Normal"/"Pinned"/"Active"，0x8e0bb2）
    QStringList m_sessionNames;
    QString m_currentSessionName;
    int m_focusedPaneId = -1; // 输出路由显示 pane（vtOutput 回灌目标）

    // 0x8e12c0 resize-pane 防抖状态
    QTimer *m_resizeDebounce = nullptr;
    QSet<QSplitter *> m_movedSplitters;
    struct HandleMove
    {
        int pos = -1;
        int index = -1;
    };
    QMap<QSplitter *, HandleMove> m_handleMove;
    QMap<QSplitter *, int> m_handlePrev;
};

// 布局语法树节点（0x84b483 splitter_restoreState 输入；定义前置声明见匿名 namespace 前）
struct LayoutNode;
