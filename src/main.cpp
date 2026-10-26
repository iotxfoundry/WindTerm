#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QPixmap>
#include <QPointer>
#include <QTabBar>
#include <QTimer>

#include "MainWindow.h"
#include "core/ActionRegistry.h"
#include "core/LocalSession.h"
#include "core/Session.h"
#include "core/SessionStore.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/QuickBar.h"
#include "widgets/TerminalView.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    MainWindow *window = new MainWindow;
    window->show();

    if (argc > 1 && QString::fromLocal8Bit(argv[1]) == QStringLiteral("--screenshot")) {
        const QString path = argc > 2 ? QString::fromLocal8Bit(argv[2])
                                      : QStringLiteral("/tmp/opencode/skeleton.png");
        QTimer::singleShot(400, &app, [window, path]() {
            window->grab().save(path, "PNG");
            QCoreApplication::quit();
        });
    }

    // --selfcheck：QuickBar 骨架断言（动作注册/惰性创建/toggle 可见性/objectName）
    if (argc > 1 && QString::fromLocal8Bit(argv[1]) == QStringLiteral("--selfcheck")) {
        QTimer::singleShot(200, &app, [window, &app]() {
            int failed = 0;
            auto check = [&failed](bool ok, const char *what) {
                if (!ok) {
                    qWarning() << "SELFCHECK FAIL:" << what;
                    ++failed;
                }
            };
            check(ActionRegistry::instance().actionIds().contains(QStringLiteral("Window.ToggleQuickBar")),
                  "Window.ToggleQuickBar registered in wind.actions");
            QuickBar *bar = window->findChild<QuickBar *>();
            check(!bar, "QuickBar not created until first toggle (lazy)");
            check(window->objectName() == QStringLiteral("TerminalWindow"), "sanity: main window alive");
            QMetaObject::invokeMethod(window, [window, &failed, &app]() {
                int inner = 0;
                auto check2 = [&inner](bool ok, const char *what) {
                    if (!ok) {
                        qWarning() << "SELFCHECK FAIL:" << what;
                        ++inner;
                    }
                };
                // 通过 QAction data 定位 Window.ToggleQuickBar 并触发（与菜单点击同路径）
                QAction *quickToggle = nullptr;
                for (QAction *a : window->findChildren<QAction *>())
                    if (a->data() == QStringLiteral("Window.ToggleQuickBar"))
                        quickToggle = a;
                check2(quickToggle, "action Window.ToggleQuickBar exists");
                check2(quickToggle && quickToggle->isCheckable(), "action is checkable");
                if (quickToggle)
                    quickToggle->trigger();
                QuickBar *bar2 = window->findChild<QuickBar *>();
                check2(bar2, "QuickBar created after first toggle");
                check2(bar2 && bar2->objectName() == QStringLiteral("QuickBar"), "objectName == QuickBar");
                check2(bar2 && bar2->isVisible(), "QuickBar visible after first toggle");
                check2(quickToggle && quickToggle->isChecked(), "action checked while visible");
                if (quickToggle)
                    quickToggle->trigger();
                check2(bar2 && !bar2->isVisible(), "QuickBar hidden after second toggle");
                check2(quickToggle && !quickToggle->isChecked(), "action unchecked while hidden");

                // F4：标签关闭销毁会话（close→deleteLater→removeWidget 顺序，0x008df6c0 链）
                MuxPaneGroup *mux = window->findChild<MuxPaneGroup *>();
                check2(mux, "MuxPaneGroup exists");
                if (mux) {
                    auto *local = new LocalSession(24, 80, mux);
                    check2(local->start(), "local session started");
                    QPointer<Session> guard = local;
                    mux->setConfirmClose(false); // selfcheck 跳过 QMessageBox
                    mux->openSession(local, QStringLiteral("selfcheck"), Qt::gray);
                    auto *tabBar = mux->tabBarRow()->findChild<QTabBar *>();
                    check2(tabBar && tabBar->count() >= 1, "tab added");
                    mux->onTabCloseRequested(0);
                    check2(tabBar && tabBar->count() == 0, "tab removed after close");
                    QApplication::processEvents();
                    // deleteLater 的 DeferredDelete 不被 processEvents 派发（loopLevel 相同），显式派发
                    QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
                    check2(!guard, "session destroyed after close (QPointer null)");
                }

                // F4：user.sessions 只读接入——本机有真数据，条目数>0 且首条字段完整
                const QVector<SessionEntry> entries = SessionStore::load();
                check2(!entries.isEmpty(), "user.sessions loaded entries > 0");
                if (!entries.isEmpty()) {
                    const SessionEntry &e = entries.first();
                    check2(!e.uuid.isEmpty() && !e.group.isEmpty() && !e.label.isEmpty()
                               && !e.protocol.isEmpty() && !e.target.isEmpty() && e.port > 0,
                           "first entry fields complete");
                }

                failed += inner;
                qInfo() << "SELFCHECK" << (failed == 0 ? "PASSED" : "FAILED") << "(" << failed << "failures)";
                app.exit(failed == 0 ? 0 : 1);
            });
        });
        return app.exec();
    }

    return app.exec();
}
