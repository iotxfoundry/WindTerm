// P7b MuxDesktop GUI 映射端到端（真 tmux -CC；系统缺 tmux 则 SKIP）。
// 断言链（attach/detach 深逆 0x00842414/0x00842778 replaceWidget 语义，MainWindow 真链）：
// MuxDesktop 原位顶替 TerminalView（terminal 入首窗 MuxPaneGroup，parent 链在 desktop 内，
// 不隐藏）→ desktop 占 terminal 原槽位（parentWidget==原 parent，无 stack 插页残留）
// → 页/分屏树/激活/补屏 → %exit 换回（parent 恢复、desktop QPointer 判空、"tmux" 属性清除）
// → 重复 attach 幂等（QPointer 不变）。
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QFile>
#include <QLayout>
#include <QPointer>
#include <QProcess>
#include <QSplitter>
#include <QStandardPaths>
#include <QStackedWidget>
#include <functional>
#include <cstdio>

#include "MainWindow.h"
#include "core/LocalSession.h"
#include "tmux/Tmux.h"
#include "widgets/MuxDesktop.h"
#include "widgets/MuxPane.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/MuxWindow.h"
#include "widgets/TerminalView.h"

static int failed = 0;
#define CHECK(ok, what)                                                        \
    do {                                                                       \
        if (ok)                                                                \
            qInfo().nospace() << "PASS: " << what;                             \
        else {                                                                 \
            qWarning().nospace() << "FAIL: " << what;                          \
            ++failed;                                                          \
        }                                                                      \
    } while (0)

static void pump(int ms)
{
    QElapsedTimer t;
    t.start();
    while (!t.hasExpired(ms))
        QCoreApplication::processEvents(QEventLoop::AllEvents, 20);
}

// 轮询等待（总时限 ms，步长 50）
template <typename F>
static bool waitFor(int timeoutMs, F cond)
{
    QElapsedTimer t;
    t.start();
    while (!t.hasExpired(timeoutMs)) {
        pump(50);
        if (cond())
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    const QString tmux = QStandardPaths::findExecutable(QStringLiteral("tmux"));
    if (tmux.isEmpty() || !QFile::exists(tmux)) {
        printf("SKIP: tmux not available\n");
        printf("TEST_TMUX_DESKTOP PASSED (0 failures)\n");
        return 0;
    }

    // ── 宿主：真实 MainWindow（attach 链在 createKitGroup 的 tmuxModeEntered 接线）──
    MainWindow mw;
    mw.show();
    pump(200);
    MuxPaneGroup *mux = mw.findChild<MuxPaneGroup *>();
    CHECK(mux != nullptr, "main mux group exists");

    // + 钮同路径开本地 bash 标签（view 在组 stack 内——replaceWidget 的 layout 前置）
    mux->onAddSession();
    pump(200);
    TerminalView *host = mux->findChild<TerminalView *>();
    CHECK(host != nullptr, "host terminal view in group stack");
    if (!host) {
        printf("TEST_TMUX_DESKTOP FAILED (%d failures)\n", failed);
        return 1;
    }

    // ── 起 tmux -CC（attachSession 对 LocalSession 自动判定 → enableTmuxMode
    // → tmuxModeEntered → MainWindow::attachMuxDesktop 真链）──
    const QString sock = QStringLiteral("wtdesk%1").arg(QCoreApplication::applicationPid());
    auto *s = new LocalSession(24, 80, mux);
    const bool started
        = s->start(tmux, QStringLiteral("-CC -L %1 new-session -x 100 -y 30").arg(sock));
    CHECK(started, "tmux -CC pty started");
    host->attachSession(s);
    CHECK(host->tmux() != nullptr, "tmux mode detected");

    // 模型就绪 + desktop 出现（tmuxModeEntered 同步触发 attach）
    MuxDesktop *desktop = nullptr;
    CHECK(waitFor(8000, [&] {
        desktop = host->muxDesktop();
        return desktop && host->tmux() && !host->tmux()->version().isEmpty()
               && host->tmux()->windows().size() >= 1 && desktop->pageCount() >= 1;
    }),
          "desktop attached in-place (muxDesktop pointer + page >= 1)");

    // ①terminal 未被隐藏：parent 链在 desktop 内的首窗 MuxPaneGroup（0x8de3e8 原终端入组）
    MuxPaneGroup *hostGroup = nullptr;
    for (QWidget *w = host->parentWidget(); w; w = w->parentWidget()) {
        if (w == desktop)
            break;
        if ((hostGroup = qobject_cast<MuxPaneGroup *>(w)))
            break;
    }
    CHECK(hostGroup != nullptr && desktop->isAncestorOf(hostGroup),
          "terminal's MuxPaneGroup inside desktop (first window)");
    CHECK(desktop->isAncestorOf(host), "terminal parent chain inside desktop");
    CHECK(host->isVisibleTo(desktop) && host->isVisible(), "terminal NOT hidden (isVisible)");
    CHECK(host->property("tmux").isValid() && host->property("tmux").toBool(),
          "terminal \"tmux\" property set");

    // ②desktop 占 terminal 原槽位：desktop->parentWidget()==terminal 原 parent；无插页残留
    CHECK(desktop->parentWidget() == mux->findChild<QStackedWidget *>(),
          "desktop occupies terminal slot (parent == group stack)");
    const int stackCount = mux->findChild<QStackedWidget *>()->count();
    CHECK(stackCount == 1,
          "no stack insertion residue (stack holds desktop only)");

    // 幂等：重复 tmuxModeEntered 不重建（QPointer 不变）——真实信号再触发已不可能
    // （enableTmuxMode 守卫），直驱 MainWindow 挂载面用 attach 幂等守卫断言：
    const QPointer<TerminalView> hostGuard(host);
    const MuxDesktop *desktopBefore = host->muxDesktop();
    CHECK(desktopBefore != nullptr, "desktop pointer set on view");
    // 重复使能（enableTmuxMode 幂等守卫：已挂 m_tmux 直接 return，不发 entered）
    host->enableTmuxMode();
    pump(100);
    CHECK(host->muxDesktop() == desktopBefore, "repeated attach idempotent (QPointer unchanged)");

    // ③④split-window → 分屏树节点+1（根 splitter 子件数 2）+新 pane 组归位。
    const int origPane = host->tmux()->panes().firstKey();
    host->tmux()->splitWindow(origPane, 3); // -v 下分
    MuxWindow *page0 = desktop->windowPage(0);
    CHECK(page0 != nullptr, "first window page (id 0) exists");
    // 断言=分屏树叶数（restore 布局树重建后 root>splitter>2 组）
    std::function<int(QWidget *)> leafCount = [&](QWidget *w) -> int {
        int n = 0;
        std::function<void(QWidget *)> walk = [&](QWidget *x) {
            if (auto *sp = qobject_cast<QSplitter *>(x)) {
                for (int i = 0; i < sp->count(); ++i)
                    walk(sp->widget(i));
            } else if (qobject_cast<MuxPaneGroup *>(x)) {
                ++n;
            }
        };
        walk(w);
        return n;
    };
    int newPaneId = -1;
    CHECK(waitFor(6000, [&] {
        if (!page0 || leafCount(page0->rootSplitter()) < 2)
            return false;
        for (auto it = host->tmux()->panes().constBegin(); it != host->tmux()->panes().constEnd();
             ++it)
            if (it.key() != origPane && page0->groupForPane(it.key())) {
                newPaneId = it.key();
                return true;
            }
        return false;
    }),
          "split-window -> splitter tree node +1 (new pane group placed)");
    MuxPaneGroup *newGroup = newPaneId >= 0 ? page0->groupForPane(newPaneId) : nullptr;
    if (newGroup) {
        TerminalView *nv = nullptr;
        for (MuxPane *p : newGroup->findChildren<MuxPane *>())
            nv = p->view();
        CHECK(nv != nullptr, "new pane view exists");
        if (nv) {
            desktop->activateWindow();
            pump(100);
            nv->setFocus(Qt::OtherFocusReason);
            pump(100);
            CHECK(QApplication::focusWidget() != nullptr
                      && newGroup->isAncestorOf(QApplication::focusWidget()),
                  "focus chain inside activated pane group");
            CHECK(page0->currentPaneId() == newPaneId,
                  "MuxWindow currentPaneId follows focus (select-pane sent)");
        }
    }

    // ⑦补屏/回灌：新 pane view 非空（send-keys 回显经 %output 直通）
    TerminalView *newView = newPaneId >= 0 ? desktop->viewForPane(newPaneId) : nullptr;
    CHECK(newView != nullptr, "new pane view routed");
    if (newView) {
        host->tmux()->setActivePane(newPaneId);
        host->tmux()->sendCommand(QStringLiteral("send-keys -t %")
                                  + QString::number(newPaneId)
                                  + QStringLiteral(" 'echo WT_SKEL_MARK' Enter"));
        CHECK(waitFor(6000, [&] {
            return newView->plainText().contains(QLatin1String("WT_SKEL_MARK"));
        }),
              "pane view output routed (capture/screenCaptured + vtOutput)");
    }

    // ⑥%exit（kill-server→会话 EOF 链）→ replaceWidget 换回：parent 恢复、desktop 销毁、
    // 属性清除（desktop 若已先销毁则断言面走 QPointer 判空——deleteLater+destroyed 清零）
    QPointer<MuxDesktop> desktopGuard(desktop);
    QPointer<QWidget> slotParentGuard(desktop->parentWidget());
    host->tmux()->sendCommand(QStringLiteral("detach-client")); // %exit 链真触发（同 test_tmux_control）
    CHECK(waitFor(8000, [&] {
        return hostGuard.isNull() // 端到端异常路径守卫（host 不应销毁——防断言自踩悬垂）
                   || (host->muxDesktop() == nullptr && host->parentWidget() == slotParentGuard
                       && !host->property("tmux").isValid());
    }),
          "%exit -> terminal back in original slot (parent restored, desktop destroyed,"
          " \"tmux\" property cleared)");
    CHECK(host->isVisible(), "terminal visible after %exit (no hide/show path)");
    QProcess::execute(tmux, {"-L", sock, "kill-server"});

    pump(300);
    CHECK(desktopGuard.isNull(), "desktop tree destroyed after %%exit (QPointer null)");
    // slot parent 即主组 stack（MainWindow 存活期内不被销毁）；hostGuard 防异常路径悬垂
    CHECK(!slotParentGuard.isNull() && slotParentGuard == mux->findChild<QStackedWidget *>()
              && hostGuard && host->parentWidget() == slotParentGuard.data(),
          "terminal slot parent survived (group stack, not hidden/show swapped)");
    printf("TEST_TMUX_DESKTOP %s (%d failures)\n", failed == 0 ? "PASSED" : "FAILED", failed);
    return failed == 0 ? 0 : 1;
}
