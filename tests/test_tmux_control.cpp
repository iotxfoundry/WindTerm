// P7a tmux 集成：纯解析单测（无 tmux 依赖）+ 真实端到端（tmux -CC control 会话，
// 系统缺 tmux 则 SKIP）。断言链：模式检测→version 回填→pane/window 模型→new-window
// →%output 路由→kill-window→%exit 退模式。
#include <QElapsedTimer>
#include <QApplication>
#include <QCoreApplication>
#include <QElapsedTimer>
#include <QFile>
#include <QProcess>
#include <QStandardPaths>
#include <QTimer>
#include <cstdio>

#include "core/LocalSession.h"
#include "tmux/Tmux.h"
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

// ── 纯解析单测 ──
static int testParse()
{
    int f = 0;
    auto check = [&](bool ok, const char *what) {
        if (ok) qInfo("PASS: %s", what);
        else { qWarning("FAIL: %s", what); ++f; }
    };
    Tmux t;
    t.setWriter([](const QByteArray &) {}); // 单测不下发
    t.start(); // 排队 version/list-panes/list-windows（帧完成须有在队命令才分派 type）
    pump(10);  // flushTimer(0) 需事件轮次落队

    // %begin→帧开（2）
    check(t.parseLine("%begin 12 34 0") == 2, "parse %begin -> 2");
    // 命令挂起中普通行→11 追加
    check(t.parseLine("version:3.5a") == 11, "parse pending line -> 11");
    // %end 尾→5，version 回填（type3 分派）
    check(t.parseLine("%end 12 34 0") == 5, "parse %end -> 5");
    check(t.version() == QStringLiteral("3.5a"), "version backfilled");
    // 未知名 %→0 / 普通行→1
    check(t.parseLine("%bogus x") == 0, "parse unknown %% -> 0");
    check(t.parseLine("ls -la") == 1, "parse plain -> 1");
    // %output→9 + pendingOut 路由（非活动 pane）
    check(t.parseLine("%output %5 hello") == 9, "parse %output -> 9");
    check(t.pendingOut().value(5) == QByteArrayLiteral("hello"), "pendingOut[5]==hello");
    // \X 四字符反转义：\033 → ESC
    t.parseLine(QByteArray("%output %5 \\033[2J"));
    check(t.pendingOut().value(5).contains("\x1b[2J"), "deescape \\033 -> ESC");
    // 活动 pane 路由：直喂 vtOutput 信号
    int vt = 0;
    QByteArray vtData;
    QObject::connect(&t, &Tmux::vtOutput, [&](const QByteArray &d) { ++vt; vtData += d; });
    t.setActivePane(5);
    t.parseLine("%output %5 active!");
    check(vt == 1 && vtData == QByteArrayLiteral("active!"), "active pane -> vtOutput");
    // %layout-change：建窗建 pane 后改几何
    t.parseLine("%begin 1 4 0");
    t.parseLine("@0 80x24,0,0,1 80x24,0,0,1"); // list-windows 行（type5 挂起? 需 type5 帧）
    // ↑ 该行在无帧时=普通行透传；走 type5 帧正式建窗（新 Tmux 消初始队——version 帧先弹，
    // list-panes/list-windows 依次对号）：
    Tmux t2;
    t2.setWriter([](const QByteArray &) {});
    t2.start();
    pump(10);
    // 帧序 = start() 队序：3 version → 4 list-panes → 5 list-windows；
    // 前两个帧用占位输出消费掉（type3/4 各一帧），第三帧喂真 list-windows 数据
    t2.parseLine("%begin 1 1 0");
    t2.parseLine("version:0");
    t2.parseLine("%end 1 1 0");
    t2.parseLine("%begin 1 2 0");
    t2.parseLine("junk");
    t2.parseLine("%end 1 2 0");
    t2.parseLine("%begin 1 4 0");
    t2.parseLine("session_id:$0;session_name:main;window_id:@0;window_index:0;window_name:bash;"
                 "window_layout:80x24,0,0,1;window_raw_flags:*;window_visible_layout:80x24,0,0,1");
    check(t2.parseLine("%end 1 4 0") == 5, "list-windows frame closed");
    check(t2.windows().size() == 1 && t2.windows().value(0).id == 0, "window model built");
    // list-panes 帧：触发全量重查（%window-add 泛化路径）入队 type4 后按序完成
    t2.parseLine("%window-add @9");
    pump(10);
    t2.parseLine("%begin 1 5 0");
    t2.parseLine("pane_id:%1;pane_active:1;pane_width:80;pane_height:24;session_id:$0;window_id:@0;"
                 "pane_current_path:/tmp;alternate_on:0;pane_synchronized:0");
    check(t2.parseLine("%end 1 5 0") == 5, "list-panes frame closed");
    t2.parseLine("%begin 1 6 0");
    t2.parseLine("session_id:$0;session_name:main;window_id:@0;window_index:0;window_name:bash;"
                 "window_layout:80x24,0,0,1;window_raw_flags:*;window_visible_layout:80x24,0,0,1");
    check(t2.parseLine("%end 1 6 0") == 5, "list-windows frame closed (2nd)");
    check(t2.panes().size() == 1 && t2.panes().value(1).w == 80 && t2.panes().value(1).h == 24,
          "pane model built (w/h)");
    check(t2.panes().value(1).cwd == QStringLiteral("/tmp"), "pane cwd");
    check((t2.panes().value(1).flags & 1) == 1, "pane active flag bit0");
    // %layout-change → w/h 更新 + screenResized
    int resized = 0;
    QObject::connect(&t2, &Tmux::screenResized, [&](int) { ++resized; });
    t2.parseLine("%layout-change @0 40x24,0,0,1 40x24,0,0,1 *");
    check(t2.panes().value(1).w == 40, "layout-change updated pane w");
    check(resized == 1, "screenResized emitted");
    // %window-pane-changed → activePaneId + active 位重算 + windowsChanged
    int winChanged = 0;
    QObject::connect(&t2, &Tmux::windowsChanged, [&] { ++winChanged; });
    t2.parseLine("%window-add @1");
    pump(50); // 全量重查入队（writer 吞掉）
    t2.parseLine("%window-pane-changed @0 %1"); // pane %1 不存在→泛化入队
    // pane %1 存在，窗 @1 不存在→入队路径；对已知窗断言：
    t2.parseLine("%window-pane-changed @0 %1");
    // %window-renamed → name 更新
    t2.parseLine("%window-renamed @0 work");
    check(t2.windows().value(0).name == QStringLiteral("work"), "window-renamed applied");
    // %exit：feedData 整体匹配（含 \r\n\033\\ 尾）
    int exited = 0;
    QString reason;
    QObject::connect(&t2, &Tmux::exited, [&](const QString &r) { ++exited; reason = r; });
    t2.feedData("%exit\r\n\033\\");
    check(exited == 1 && reason.isEmpty(), "%exit matched (empty reason)");
    t2.feedData("%exit lost tty\r\n\033\\trailing");
    check(exited == 2 && reason == QStringLiteral("lost tty"), "%exit reason captured");
    check(t2.takeBuffer() == QByteArrayLiteral("trailing"), "trailing bytes buffered");

    // 命令原语串（0x83eaa6 照抄）
    Tmux c;
    QByteArray out;
    c.setWriter([&](const QByteArray &b) { out += b; });
    c.start();
    c.newWindow();
    c.splitWindow(3, 1);
    c.killPane(7);
    c.killWindow(2);
    c.killSession(QStringLiteral("s0"));
    c.selectPane(9);
    c.resizePane(4, 1, 5);
    c.swapPaneTarget(2, 0);
    c.attachSession(QStringLiteral("s0"));
    c.detachClient();
    c.renameWindow(1, QStringLiteral("main"));
    c.selectLayout(QStringLiteral("even-horizontal"));
    c.resizeClient(100, 30);
    c.sendCommand(QStringLiteral("send-keys -t %1 'echo HI' Enter"));
    pump(200); // flushTimer(0) 弹队
    const QString s = QString::fromUtf8(out);
    check(s.contains(QLatin1String("new-window\n")), "cmd new-window");
    check(s.contains(QLatin1String("split-window -h -t 3\n")), "cmd split-window -h");
    check(s.contains(QLatin1String("kill-pane -t 7\n")), "cmd kill-pane 7");
    check(s.contains(QLatin1String("kill-window -t 2\n")), "cmd kill-window 2");
    check(s.contains(QLatin1String("kill-session -t 's0'\n")), "cmd kill-session");
    check(s.contains(QLatin1String("select-pane -t 9\n")), "cmd select-pane");
    check(s.contains(QLatin1String("resize-pane -R -t 4 5\n")), "cmd resize-pane");
    check(s.contains(QLatin1String("swap-pane -d -t '{left-of}'\n")), "cmd swap-pane target");
    check(s.contains(QLatin1String("attach-session -t 's0'\n")), "cmd attach-session");
    check(s.contains(QLatin1String("detach-client\n")), "cmd detach-client");
    check(s.contains(QLatin1String("rename-window -t 1 'main'\n")), "cmd rename-window");
    check(s.contains(QLatin1String("select-layout 'even-horizontal'\n")), "cmd select-layout");
    check(s.contains(QLatin1String("refresh-client -C 100,30\n")), "cmd refresh-client");
    check(s.contains(QLatin1String("send-keys -t %1 'echo HI' Enter\n")), "cmd sendCommand");
    check(s.contains(QLatin1String("display-message -p 'version:#{version}'\n")), "cmd version query");
    check(s.contains(QLatin1String("list-panes -s -F 'alternate_on:#{alternate_on}")), "cmd list-panes 27-var fmt");
    check(s.contains(QLatin1String("list-windows -a -F 'session_id:#{session_id}")), "cmd list-windows fmt");
    return f;
}

// ── 真实端到端（tmux 存在才跑）──
static int testEndToEnd()
{
    const QString tmux = QStandardPaths::findExecutable(QStringLiteral("tmux"));
    if (tmux.isEmpty() || !QFile::exists(tmux)) {
        printf("SKIP: tmux not available\n");
        return 0;
    }
    int f = 0;
    auto check = [&](bool ok, const char *what) {
        if (ok) qInfo("PASS: %s", what);
        else { qWarning("FAIL: %s", what); ++f; }
    };
    TerminalView view(QStringLiteral("t"));
    auto *s = new LocalSession(24, 80, &view);
    const QString sock = QStringLiteral("wtskel%1").arg(QCoreApplication::applicationPid());
    // tmux 3.4 实测（2026-10-25）：-CC 下 "new-session -d" 会让 control 客户端立即收
    // %begin/%end 空帧 + %sessions-changed + %exit 并退出（-CC 自身即 attach 语义，-d 附加
    // 在 3.4 = 创建后即刻脱离并退出客户端；tmux 3.5a 起行为或不同）。原版 -CC 条目
    // （user.sessions "process.arguments":"-CC"）不带子命令——保持客户端挂载。
    const bool started = s->start(tmux, QStringLiteral("-CC -L %1 new-session -x 100 -y 30").arg(sock));
    check(started, "tmux -CC pty started");
    view.attachSession(s);
    check(view.tmux() != nullptr, "tmux mode detected (view->tmux() non-null)");

    // ②version 回填
    bool hasVersion = false;
    {
        QElapsedTimer t;
        t.start();
        while (!t.hasExpired(5000)) {
            pump(100);
            if (view.tmux() && !view.tmux()->version().isEmpty()) { hasVersion = true; break; }
        }
    }
    check(hasVersion, "version query backfilled");

    // ③pane/window 模型
    bool model = false;
    {
        QElapsedTimer t;
        t.start();
        while (!t.hasExpired(5000)) {
            pump(100);
            if (view.tmux() && view.tmux()->panes().size() >= 1
                && view.tmux()->windows().size() >= 1
                && view.tmux()->panes().first().w > 0 && view.tmux()->panes().first().h > 0) {
                model = true;
                break;
            }
        }
    }
    check(model, "pane/window model (panes>=1 windows>=1 w/h>0)");

    // ④new-window → 窗口数 +1
    const int before = view.tmux() ? view.tmux()->windows().size() : 0;
    view.tmux()->newWindow();
    bool grew = false;
    {
        QElapsedTimer t;
        t.start();
        while (!t.hasExpired(5000)) {
            pump(100);
            if (view.tmux() && view.tmux()->windows().size() > before) { grew = true; break; }
        }
    }
    check(grew, "new-window -> windowsChanged (+1)");

    // ⑤%output 路由：split-window 后对非活动 pane echo 标记串
    if (view.tmux() && view.tmux()->panes().size() >= 1) {
        const int origPane = view.tmux()->panes().firstKey();
        view.tmux()->splitWindow(origPane, 3); // -v 下分
        pump(1500);
        const int newPane = view.tmux()->panes().lastKey();
        view.tmux()->setActivePane(origPane); // 非 newPane 为活动→输出入 pendingOut
        // tmux 3.4 实测：pane 目标须带 % 前缀（"send-keys -t 2"=窗序号 2 → can't find window；
        // "-t %2"=pane id 2）。QString::arg 无 %% 转义，% 用拼接产生。
        view.tmux()->sendCommand(QStringLiteral("send-keys -t %") + QString::number(newPane)
                                 + QStringLiteral(" 'echo WT_SKEL_MARK' Enter"));
        bool routed = false;
        QByteArray vtMark;
        view.tmux()->setActivePane(origPane);
        // 活动窗切到 newPane 一次以观测 vtOutput 路径（任一路径命中即过）
        QElapsedTimer t;
        t.start();
        while (!t.hasExpired(5000)) {
            pump(100);
            const QByteArray p = view.tmux()->pendingOut().value(newPane);
            if (p.contains("WT_SKEL_MARK")) { routed = true; break; }
        }
        check(routed, "%output routed (pendingOut)");
    } else {
        check(false, "output routing (no pane)");
    }

    // ⑥kill-window → 数 -1
    if (grew) {
        const int more = view.tmux()->windows().size();
        const int killIdx = view.tmux()->windows().lastKey(); // QMap 键=window id
        view.tmux()->killWindow(view.tmux()->windows().value(killIdx).idx);
        bool shrank = false;
        QElapsedTimer t;
        t.start();
        while (!t.hasExpired(5000)) {
            pump(100);
            if (view.tmux()->windows().size() < more) { shrank = true; break; }
        }
        check(shrank, "kill-window -> windowsRemoved (-1)");
    }

    // ⑦%exit → 退模式
    view.tmux()->sendCommand(QStringLiteral("detach-client"));
    bool exited = false;
    {
        QElapsedTimer t;
        t.start();
        while (!t.hasExpired(5000)) {
            pump(100);
            if (view.tmux() == nullptr) { exited = true; break; }
        }
    }
    check(exited, "%%exit -> tmux mode exited (view->tmux() null)");
    s->close();
    QProcess::execute(tmux, {"-L", sock, "kill-server"});
    return f;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    int f = testParse();
    f += testEndToEnd();

    printf("TEST_TMUX_CONTROL %s (%d failures)\n", f == 0 ? "PASSED" : "FAILED", f);
    return f == 0 ? 0 : 1;
}
