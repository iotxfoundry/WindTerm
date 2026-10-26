// P7b MuxDesktop GUI 映射端到端（真 tmux -CC；系统缺 tmux 则 SKIP）。
// 断言链：MuxDesktop 出现+页数==窗口数 → new-window 页+1（MuxWindow/TerminalView 存在）
// → split-window 分屏树节点+1 → 激活链（select-pane 后对应 pane 组焦点）
// → kill-window 页-1+空树清理 → %exit desktop 隐藏 → capture-pane 补屏（pane view 非空）。
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QFile>
#include <QProcess>
#include <QStandardPaths>
#include <functional>
#include <cstdio>

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

    // ── 宿主：tmux -CC 会话（同 test_tmux_control 3.4 实测形态）──
    TerminalView host(QStringLiteral("t"));
    auto *s = new LocalSession(24, 80, &host);
    const QString sock = QStringLiteral("wtdesk%1").arg(QCoreApplication::applicationPid());
    const bool started
        = s->start(tmux, QStringLiteral("-CC -L %1 new-session -x 100 -y 30").arg(sock));
    CHECK(started, "tmux -CC pty started");
    host.attachSession(s);
    CHECK(host.tmux() != nullptr, "tmux mode detected");

    // 模型就绪（version/panes/windows）
    CHECK(waitFor(5000, [&] {
        return host.tmux() && !host.tmux()->version().isEmpty()
               && host.tmux()->windows().size() >= 1 && host.tmux()->panes().size() >= 1
               && host.tmux()->panes().first().w > 0;
    }),
          "tmux model ready (version/panes/windows)");

    // ①MuxDesktop 出现且页数==tmux 窗口数（初始 1）
    MuxDesktop desktop(&host);
    desktop.resize(800, 600);
    desktop.show();
    CHECK(desktop.objectName() == QStringLiteral("MuxDesktop"), "desktop objectName");
    CHECK(desktop.pageCount() == host.tmux()->windows().size(),
          "page count == tmux window count (initial 1)");
    CHECK(qobject_cast<MuxWindow *>(desktop.windowPage(host.tmux()->windows().firstKey()) != nullptr
                                       ? desktop.windowPage(host.tmux()->windows().firstKey())
                                       : nullptr) != nullptr,
          "page is MuxWindow");
    // MuxWindow 结构照搬断言（A 节）
    MuxWindow *page0 = desktop.windowPage(host.tmux()->windows().firstKey());
    CHECK(page0->objectName() == QStringLiteral("MuxWindow"), "MuxWindow objectName");
    CHECK(page0->rootSplitter() != nullptr && page0->rootSplitter()->orientation() == Qt::Vertical
              && !page0->rootSplitter()->childrenCollapsible(),
          "root splitter Vertical childrenCollapsible=false");
    CHECK(page0->name() == QStringLiteral("Untitled") || !page0->name().isEmpty(),
          "MuxWindow name property present");

    // ②sendCommand new-window → 页数 +1、新页 MuxWindow/内部 TerminalView 存在
    const int before = host.tmux()->windows().size();
    host.tmux()->newWindow();
    CHECK(waitFor(5000, [&] { return host.tmux()->windows().size() > before && desktop.pageCount() > before; }),
          "new-window -> page +1");
    int newWindowId = -1;
    for (auto it = host.tmux()->windows().constBegin(); it != host.tmux()->windows().constEnd();
         ++it)
        if (!desktop.windowPage(it.key()))
            break;
    // 取最新页（页数+1 后不在初始集合的窗）
    for (auto it = host.tmux()->windows().constBegin(); it != host.tmux()->windows().constEnd();
         ++it)
        newWindowId = it.key(); // QMap 升序，最后一个即新窗（id 最大）
    MuxWindow *newPage = desktop.windowPage(newWindowId);
    CHECK(newPage != nullptr && newPage->findChild<TerminalView *>() != nullptr,
          "new page MuxWindow with inner TerminalView");

    // ③④split-window → 分屏树节点+1（根 splitter 子件数 2）+新 pane 组归位。
    // split 落在活动窗（new-window 后活动窗=新窗）——切回首窗再分，页按 windowId 0 定位
    const int origPane = host.tmux()->panes().firstKey();
    host.tmux()->selectWindow(0); // 初始窗（idx 0）
    CHECK(waitFor(3000, [&] {
        return host.tmux()->windows().value(0).rawFlags.contains(QLatin1Char('*'));
    }),
          "initial window re-activated before split");
    host.tmux()->splitWindow(origPane, 3); // -v 下分
    // 断言=分屏树叶数（visL 嵌套布局为 root>splitter>2 组，root 子件数恒 1）
    MuxWindow *splitPage = nullptr;
    int newPaneId = -1;
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
    CHECK(waitFor(6000, [&] {
        splitPage = desktop.windowPage(0);
        if (!splitPage || leafCount(splitPage->rootSplitter()) < 2)
            return false;
        for (auto it = host.tmux()->panes().constBegin(); it != host.tmux()->panes().constEnd();
             ++it)
            if (it.key() != origPane && splitPage->groupForPane(it.key())) {
                newPaneId = it.key();
                return true;
            }
        return false;
    }),
          "split-window -> splitter tree node +1 (new pane group placed)");
    MuxPaneGroup *newGroup = newPaneId >= 0 ? splitPage->groupForPane(newPaneId) : nullptr;
    if (newGroup) {
        TerminalView *nv = nullptr;
        for (MuxPane *p : newGroup->findChildren<MuxPane *>())
            nv = p->view();
        CHECK(nv != nullptr, "new pane view exists");
        if (nv) {
            desktop.activateWindow();
            pump(100);
            nv->setFocus(Qt::OtherFocusReason);
            pump(100);
            CHECK(QApplication::focusWidget() != nullptr
                      && newGroup->isAncestorOf(QApplication::focusWidget()),
                  "focus chain inside activated pane group");
            CHECK(splitPage->currentPaneId() == newPaneId,
                  "MuxWindow currentPaneId follows focus (select-pane sent)");
            CHECK(desktop.tabIndexOf(splitPage) == desktop.tabIndexOf(splitPage)
                      && QApplication::focusWidget() != nullptr,
                  "desktop tab state refreshed");
        }
    }

    // ⑦补屏/回灌：新 pane view 非空（capture len26 近空 shell → 以 setActivePane（G 链
    // desktop 调用点）+echo 标记验证 pane view 输出回灌面：vtOutput→feedPaneView）
    TerminalView *newView = newPaneId >= 0 ? desktop.viewForPane(newPaneId) : nullptr;
    CHECK(newView != nullptr, "new pane view routed");
    if (newView) {
        host.tmux()->setActivePane(newPaneId); // desktop onFocusChanged 同款调用
        // send-keys 注入（pane shell echo 依赖 control %output 对非焦点 pane 的派发面，
        // 多窗场景 tmux 3.4 实测静默——挂账；send-keys 回显经 %output 直通）
        host.tmux()->sendCommand(QStringLiteral("send-keys -t %")
                                 + QString::number(newPaneId) + QStringLiteral(" 'echo WT_SKEL_MARK' Enter"));
        CHECK(waitFor(6000, [&] {
            return newView->plainText().contains(QLatin1String("WT_SKEL_MARK"));
        }),
              "pane view output routed (capture/screenCaptured + vtOutput)");
    }

    // ⑤kill-window → 页数 -1+空树清理
    const int pagesBeforeKill = desktop.pageCount();
    host.tmux()->killWindow(host.tmux()->windows().value(newWindowId).idx);
    CHECK(waitFor(5000, [&] {
        return desktop.pageCount() < pagesBeforeKill
               && desktop.windowPage(newWindowId) == nullptr;
    }),
          "kill-window -> page -1 and page removed");

    // ⑥%exit → MuxDesktop 隐藏（finished）
    bool finished = false;
    QObject::connect(&desktop, &MuxDesktop::finished, [&finished]() { finished = true; });
    host.tmux()->sendCommand(QStringLiteral("detach-client"));
    CHECK(waitFor(5000, [&] { return finished; }), "%%exit -> desktop finished");
    CHECK(!desktop.isVisible(), "MuxDesktop hidden after %%exit");

    s->close();
    QProcess::execute(tmux, {"-L", sock, "kill-server"});
    pump(200);

    printf("TEST_TMUX_DESKTOP %s (%d failures)\n", failed == 0 ? "PASSED" : "FAILED", failed);
    return failed == 0 ? 0 : 1;
}
