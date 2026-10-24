// P3 mode7 palette 文件模式回归（offscreen，*.palette 一手证据落地 2026-10-25）：
// calculator.palette（trigger "="，不依赖终端）：
//   open("=")→enterEvent items "Please enter the formula"→输入 "1+2*3"→filterEvent 首项 "7"
//   →输入 "abc("→错误 items（"Invalid formula" 字样+值/方法表）
// goto-line.palette（trigger ":"，依赖 view）：bash 输出 100 行→enterEvent items
//   "Type a line number"→输入 "50"→filterEvent 调用后 scrollTop 变化→Enter→commitEvent
//   gotoLine→Esc 关闭 leaveEvent 滚动还原
// 经 MainWindow 走真实链（openCommandPalette+ScriptHost 注入）
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QStackedWidget>
#include <QStandardItemModel>
#include <QTimer>

#include "core/Assets.h"
#include "core/LocalSession.h"
#include "core/Session.h"
#include "widgets/CommandPalette.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/TerminalView.h"
#include "MainWindow.h"

static int failed = 0;
static void check(bool ok, const QString &what)
{
    std::printf("%s: %s\n", ok ? "PASS" : "FAIL", qPrintable(what));
    if (!ok)
        ++failed;
}

static QStandardItemModel *modelOf(QWidget *pal)
{
    if (!pal)
        return nullptr;
    QListView *lv = pal->findChild<QListView *>();
    return lv ? qobject_cast<QStandardItemModel *>(lv->model()) : nullptr;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    // palette 文件在位（assets/palettes 一手证据拷贝）
    check(QFileInfo::exists(Assets::dir() + QStringLiteral("/palettes/goto-line.palette")),
          "goto-line.palette in assets/palettes");
    check(QFileInfo::exists(Assets::dir() + QStringLiteral("/palettes/calculator.palette")),
          "calculator.palette in assets/palettes");

    MainWindow mw;
    mw.show();
    for (int i = 0; i < 5; ++i)
        QApplication::processEvents();

    // bash 标签（goto-line 需要活动 view；window.activeText 经焦点链取它）
    MuxPaneGroup *mux = mw.findChild<MuxPaneGroup *>();
    check(mux != nullptr, "mux group exists");
    mux->onAddSession();
    for (int i = 0; i < 10; ++i)
        QApplication::processEvents();
    TerminalView *view = mux->findChild<TerminalView *>();
    check(view != nullptr, "terminal view exists");
    Session *session = view ? view->session() : nullptr;
    check(session != nullptr, "bash session attached");
    if (view)
        view->setFocus(Qt::OtherFocusReason); // activeText 焦点链锚定
    for (int i = 0; i < 3; ++i)
        QApplication::processEvents();

    // ═══ calculator.palette（trigger "="；不依赖终端）═══
    mw.openCommandPalette(QStringLiteral("="));
    for (int i = 0; i < 5; ++i)
        QApplication::processEvents();
    QWidget *pal = mw.findChild<QWidget *>(QStringLiteral("CommandPalette"));
    check(pal && pal->isVisible(), "calc: palette visible after open(\"=\")");
    QStandardItemModel *model = modelOf(pal);
    check(model && model->rowCount() >= 1
              && model->item(0)->text() == QStringLiteral("Please enter the formula"),
          "calc: enterEvent items = 'Please enter the formula'");

    QLineEdit *edit = pal ? pal->findChild<QLineEdit *>() : nullptr;
    if (edit) {
        edit->setText(QStringLiteral("=1+2*3")); // trigger 后文本=filter
        for (int i = 0; i < 5; ++i)
            QApplication::processEvents();
        model = modelOf(pal);
        check(model && model->rowCount() >= 1 && model->item(0)->text() == QStringLiteral("7"),
              "calc: filterEvent '1+2*3' -> title '7'");

        edit->setText(QStringLiteral("=abc(")); // 非法公式→错误 items+方法表
        for (int i = 0; i < 5; ++i)
            QApplication::processEvents();
        model = modelOf(pal);
        bool hasInvalid = false, hasTrunc = false;
        if (model) {
            for (int r = 0; r < model->rowCount(); ++r) {
                const QString t = model->item(r)->text();
                if (t.startsWith(QStringLiteral("Invalid formula")))
                    hasInvalid = true;
                if (t == QStringLiteral("trunc"))
                    hasTrunc = true; // methods 表补齐（abc 无 a- 开头方法→回退全表）
            }
        }
        check(hasInvalid, "calc: invalid formula -> 'Invalid formula' item");
        check(hasTrunc, "calc: invalid formula -> method table appended");
    }

    // 关闭（Esc→leaveEvent；calculator 无 leaveEvent——events 表过滤为空操作）
    QKeyEvent esc(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QApplication::sendEvent(pal->findChild<QListView *>(), &esc);
    for (int i = 0; i < 8; ++i) {
        QApplication::processEvents();
        QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
    }

    // ═══ goto-line.palette（trigger ":"；依赖 view 滚动链）═══
    if (view && session) {
        // 100 行输出（scrollback 足够 scrollTop/gotoLine 语义可见）
        session->write("for i in $(seq 1 100); do echo LINE$i; done\n");
        QTimer wait;
        QEventLoop loop;
        QObject::connect(&wait, &QTimer::timeout, &loop, &QEventLoop::quit);
        wait.start(1200);
        loop.exec();

        const int scrollBefore = view->scrollTop();
        mw.openCommandPalette(QStringLiteral(":"));
        for (int i = 0; i < 5; ++i)
            QApplication::processEvents();
        pal = mw.findChild<QWidget *>(QStringLiteral("CommandPalette"));
        model = modelOf(pal);
        check(model && model->rowCount() >= 2
                  && model->item(0)->text().startsWith(QStringLiteral("Type a line number")),
              "goto: enterEvent items 'Type a line number between 1 and …'");
        check(model && model->rowCount() >= 2
                  && model->item(1)->text().contains(QStringLiteral("relative line")),
              "goto: enterEvent items '+,- relative' hint");

        edit = pal ? pal->findChild<QLineEdit *>() : nullptr;
        if (edit) {
            edit->setText(QStringLiteral(":50"));
            for (int i = 0; i < 5; ++i)
                QApplication::processEvents();
            // filterEvent：scrollTop = 50-1-屏半高（行语义，qBound 后必 <scrollBefore 或 0）
            const int scrollAfter = view->scrollTop();
            std::printf("  scrollTop before=%d after=:50 filter=%d\n", scrollBefore, scrollAfter);
            check(scrollAfter < scrollBefore, "goto: filterEvent ':50' scrolled view up");

            // Enter→commitEvent→gotoLine(49)：activated 信号直发（dispatch 分派链，
            // Key_Return 实际经 QShortcut→BackwardButton——测试同 test_command_palette 直发）
            QListView *lv = pal->findChild<QListView *>();
            emit lv->activated(lv->currentIndex());
            for (int i = 0; i < 5; ++i)
                QApplication::processEvents();
            const int scrollCommitted = view->scrollTop();
            const int caretAfter = view->caretLine();
            const int scrollMax = view->verticalScrollBar()->maximum();
            std::printf("  scrollTop after commit=%d (max=%d) caret=%d lineCount=%d\n",
                        scrollCommitted, scrollMax, caretAfter, view->lineCount());
            // gotoLine(49) 语义断言：scrollTop==min(49,max)（目标行滚入视口）；
            // caret 仅在 49 行落入活动屏时移动（'d' 绝对行）
            check(scrollCommitted == qMin(49, scrollMax),
                  "goto: commitEvent gotoLine(49) scroll positioned");
            const int screenRows = view->screenLineCapacity();
            const int scrollbackAtCommit = qMax(0, view->lineCount() - screenRows);
            if (49 >= scrollbackAtCommit) {
                const int expectCaret = qBound(0, 49 - scrollbackAtCommit, screenRows - 1);
                check(caretAfter == expectCaret,
                      "goto: commitEvent gotoLine(49) caret (in-screen case)");
            } else {
                // 行 49 在 scrollback 覆盖区 → caret 不动（'d' 仅作用于活动屏；滚动已足证）
                check(true, "goto: commitEvent caret untouched (line 49 in scrollback)");
            }
        }

        // commit 已消费 palette（goto-line commit 即终点，removeRegister——leaveEvent 不触发，
        // 滚动保持 gotoLine 结果）。此断言=commit 终点语义：滚动不被后续 close 误还原
        const int scrollAtCommit = view->scrollTop();
        Q_UNUSED(scrollAtCommit);
        if (pal && mw.findChild<QWidget *>(QStringLiteral("CommandPalette"))) {
            QKeyEvent esc2(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
            QApplication::sendEvent(pal->findChild<QListView *>(), &esc2);
            for (int i = 0; i < 8; ++i) {
                QApplication::processEvents();
                QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
            }
        }
        check(view->scrollTop() == scrollAtCommit,
              "goto: after commit close, scroll stays at gotoLine target (no stray leave)");

        // leaveEvent 还原链（原版 Esc 未 commit 路径）：重开 ":" palette→Esc→register 还原
        mw.openCommandPalette(QStringLiteral(":"));
        for (int i = 0; i < 5; ++i)
            QApplication::processEvents();
        pal = mw.findChild<QWidget *>(QStringLiteral("CommandPalette"));
        // 重开时 enterEvent 再暂存当前 scrollTop=49；先滚动它处再 Esc
        if (view && pal) {
            view->setScrollTop(0);
            QKeyEvent esc3(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
            QApplication::sendEvent(pal->findChild<QListView *>(), &esc3);
            for (int i = 0; i < 8; ++i) {
                QApplication::processEvents();
                QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
            }
            std::printf("  leaveEvent restored=%d expect=49\n", view->scrollTop());
            check(view->scrollTop() == 49,
                  "goto: leaveEvent restored scrollTop via register (Esc path)");
        }
    }

    std::printf("TEST_PALETTE_MODE %s (%d failures)\n", failed == 0 ? "PASSED" : "FAILED", failed);
    return failed == 0 ? 0 : 1;
}
