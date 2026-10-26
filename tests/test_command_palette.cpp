// P3 CommandPalette 命令面板回归（offscreen QApplication+MainWindow，深逆批 2026-10-24）：
// 1) open(">") 面板可见(objectName CommandPalette)  2) 初始列表=全部动作(>10)取前行上限 9
// 3) 输入过滤词收缩+首项含词  4) Enter→Window.ToggleQuickBar 可见性翻转
// 5) Esc 关闭+焦点还原  6) "m" 模式 mux/tmux 词过滤  7) "" 默认模式非空
#include <QApplication>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QStackedWidget>
#include <QStandardItemModel>

#include "core/ActionRegistry.h"
#include "widgets/CommandPalette.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/QuickBar.h"

#include "MainWindow.h"

static int failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++failed;
}

static QListView *listOf(QWidget *pal)
{
    return pal ? pal->findChild<QListView *>() : nullptr;
}
static QStandardItemModel *modelOf(QWidget *pal)
{
    QListView *lv = listOf(pal);
    return lv ? qobject_cast<QStandardItemModel *>(lv->model()) : nullptr;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    MainWindow mw;
    mw.show();
    for (int i = 0; i < 5; ++i)
        QApplication::processEvents();

    // 焦点锚点（还原断言用）：无会话时 openCommandPalette 宿主回退组容器
    auto *mux = mw.findChild<MuxPaneGroup *>();
    check(mux != nullptr, "mux group exists");
    QWidget *before = QApplication::focusWidget();
    if (!before) {
        if (auto *addr = mw.findChild<QLineEdit *>(QStringLiteral("AddressBarEdit")))
            addr->setFocus(Qt::OtherFocusReason);
        for (int i = 0; i < 3; ++i)
            QApplication::processEvents();
        before = QApplication::focusWidget();
    }
    check(before != nullptr, "focus anchor before open");

    // ── 1) open(">")：面板懒建+可见 ──
    mw.openCommandPalette(QStringLiteral(">"));
    for (int i = 0; i < 5; ++i)
        QApplication::processEvents();
    QWidget *pal = mw.findChild<QWidget *>(QStringLiteral("CommandPalette"));
    check(pal && pal->isVisible(), "1) palette visible after openCommandPalette(\">\")");

    // ── 2) 初始列表=全部动作（>10）取前行上限 9 ──
    const int regCount = ActionRegistry::instance().actionIds().size();
    check(regCount > 10, "2) registry actions > 10");
    QStandardItemModel *model = modelOf(pal);
    check(model && model->rowCount() == 9, "2) initial rows = 行上限 9 (0x583b8a clamp)");

    // ── 3) 过滤词收缩+首项含词 ──
    QLineEdit *edit = pal ? pal->findChild<QLineEdit *>() : nullptr;
    check(edit != nullptr, "3) searchEdit exists");
    if (edit) {
        edit->setText(QStringLiteral(">quickbar")); // ">" 前缀保留，过滤词 quickbar
        for (int i = 0; i < 3; ++i)
            QApplication::processEvents();
        model = modelOf(pal);
        const int rows = model ? model->rowCount() : 0;
        const QString first = (model && rows > 0)
            ? model->item(0)->text() : QString();
        qInfo() << "  filtered rows:" << rows << "first:" << first;
        check(rows > 0 && rows < 9, "3) rows shrink after filter");
        check(first.contains(QStringLiteral("quick"), Qt::CaseInsensitive),
              "3) first item contains filter word");
    }

    // ── 4) Enter→Window.ToggleQuickBar 可见性翻转（activated 同链 0x583bac）──
    {
        QListView *lv = listOf(pal);
        for (int flip = 0; flip < 2; ++flip) {
            emit lv->activated(lv->currentIndex()); // 分派 kind1→QAction::activate(Trigger)
            for (int i = 0; i < 3; ++i)
                QApplication::processEvents();
            QuickBar *qb = mw.findChild<QuickBar *>();
            if (flip == 0)
                check(qb && qb->isVisible(), "4) activate #1 -> QuickBar visible");
            else
                check(qb && qb->isHidden(), "4) activate #2 -> QuickBar hidden (flip)");
        }
    }

    // ── 5) Esc→close+焦点还原（0x5436ce/0x53e3e4）──
    {
        QKeyEvent esc(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
        QApplication::sendEvent(listOf(pal), &esc);
        for (int i = 0; i < 8; ++i) { // WA_DeleteOnClose deleteLater 落地
            QApplication::processEvents();
            QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
        }
        check(mw.findChild<QWidget *>(QStringLiteral("CommandPalette")) == nullptr,
              "5) palette deleted after Esc (WA_DeleteOnClose)");
        check(QApplication::focusWidget() == before, "5) focus restored to pre-open widget");
    }

    // ── 6) "m" 模式词过滤（mux/tmux）──
    mw.openCommandPalette(QStringLiteral("m"));
    for (int i = 0; i < 5; ++i)
        QApplication::processEvents();
    pal = mw.findChild<QWidget *>(QStringLiteral("CommandPalette"));
    model = modelOf(pal);
    {
        const int rows = model ? model->rowCount() : 0;
        check(rows > 0, "6) m-mode rows > 0");
        bool allMux = rows > 0;
        for (int r = 0; r < rows; ++r) {
            const QString id = model->item(r)->data(Qt::UserRole).toString();
            if (!id.startsWith(QStringLiteral("Mux.")) && !id.startsWith(QStringLiteral("Tmux.")))
                allMux = false;
        }
        check(allMux, "6) all ids in Mux./Tmux. groups (0x542f1b word filter)");
    }

    // ── 7) "" 默认模式（mode3 Anything）非空 ──
    mw.openCommandPalette(QString());
    for (int i = 0; i < 5; ++i)
        QApplication::processEvents();
    pal = mw.findChild<QWidget *>(QStringLiteral("CommandPalette"));
    model = modelOf(pal);
    check(model && model->rowCount() > 0, "7) default mode rows > 0");

    std::printf("TEST_COMMAND_PALETTE %s (%d failures)\n", failed == 0 ? "PASSED" : "FAILED",
                failed);
    return failed == 0 ? 0 : 1;
}
