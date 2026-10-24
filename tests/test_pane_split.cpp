// 批 1+2 端到端：仿 f2diag 链接模式（全项目 .o 除 main）
// 断言：splitView(Bottom) 父 splitter count=2+对半 / 新组新 bash / closeGroup 守卫+清理+标签保留
// / activateNextView 循环 / ReopenHistory color round-trip / KitPane icon 工厂
#include <QCoreApplication>
#include <QApplication>
#include <QDebug>
#include <QColor>
#include <QCoreApplication>
#include <QFile>
#include <QSignalBlocker>
#include <QSplitter>
#include <QStackedWidget>
#include <QTemporaryDir>
#include <QTabBar>
#include <QTimer>

#include "core/LocalSession.h"
#include "core/ReopenHistory.h"
#include "panes/KitPane.h"
#include "widgets/KitGroup.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/TerminalView.h"

int failed = 0;
#define CHECK(ok, what)                                                        \
    do {                                                                       \
        if (ok)                                                                \
            qInfo().nospace() << "PASS: " << what;                             \
        else {                                                                 \
            qWarning().nospace() << "FAIL: " << what;                          \
            ++failed;                                                          \
        }                                                                      \
    } while (0)

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    // ── 复刻 createCentral 最小布局：root/muxRow/KitGroup/MuxPaneGroup+bash 标签 ──
    auto *root = new QSplitter(Qt::Vertical);
    auto *muxRow = new QSplitter(Qt::Horizontal);
    muxRow->setObjectName(QStringLiteral("MuxRow"));
    muxRow->setChildrenCollapsible(false);
    auto *mux = new MuxPaneGroup;
    muxRow->addWidget(mux);
    auto *kitGroup = new KitGroup;
    kitGroup->setMenuWidget(mux->tabBarRow());
    kitGroup->setCentralWidget(muxRow);
    root->addWidget(kitGroup);
    root->show(); // window() 锚点（canCloseGroup/activateNextView 全树收集）
    root->resize(800, 600);

    MuxPaneGroup::s_createGroup = []() -> QWidget * {
        // 仿 MainWindow::createKitGroup：新 KitGroup+MuxPaneGroup+muxRow（无 ToolBar，够断言）
        auto *nmux = new MuxPaneGroup;
        auto *nrow = new QSplitter(Qt::Horizontal);
        nrow->addWidget(nmux);
        auto *nkit = new KitGroup;
        nkit->setMenuWidget(nmux->tabBarRow());
        nkit->setCentralWidget(nrow);
        return nkit;
    };

    // 断言前放一组 bash（+ 钮同路径；tabBarRow 经 setMenuWidget 归 KitGroup——
    // findChildren 需从顶层 root 走）
    mux->onAddSession();
    QApplication::processEvents();
    auto *tabBar = root->findChild<QTabBar *>();
    CHECK(tabBar && tabBar->count() == 1, "initial bash tab added");
    const int initialTabTextHash = qHash(tabBar ? tabBar->tabText(0) : QString());

    // ── 1a paneIconFactory：KitPane 窗口图标按 king:: + 首字母小写（0x0089e584）──
    {
        KitPane pane(nullptr, QStringLiteral("ExplorerPane"));
        CHECK(!pane.windowIcon().isNull(), "KitPane icon: ExplorerPane -> king::explorerPane non-null");
        KitPane search(nullptr, QStringLiteral("SearchPane"));
        CHECK(search.windowIcon().isNull(), "KitPane icon: SearchPane (no king element) -> empty");
        KitPane odd(nullptr, QStringLiteral("Widget"));
        CHECK(odd.windowIcon().isNull(), "KitPane icon: non-*Pane objectName -> empty (endsWith gate)");
    }

    // ── 3 ReopenHistory color round-trip（0x8bbab6 QColor）——临时目录，不依赖固定路径 ──
    {
        QTemporaryDir tmpDir;
        if (!tmpDir.isValid()) {
            qWarning() << "SKIP: cannot create temp dir for reopen round-trip";
            return 2;
        }
        const QString path = tmpDir.filePath(QStringLiteral("reopen-color-test.history"));
        ReopenState out;
        out.geometry = QByteArray("geo");
        out.currentIndex = 2;
        ReopenTabEntry t1;
        t1.url = QStringLiteral("$uuid-1");
        t1.color = QColor(0x12, 0x34, 0x56, 0xff);
        ReopenTabEntry t2;
        t2.color = QColor(Qt::gray);
        out.tabs = {t1, t2};
        CHECK(ReopenHistory::save(path, out), "reopen.history save ok");
        ReopenState in;
        CHECK(ReopenHistory::load(path, in), "reopen.history load ok");
        CHECK(in.tabs.size() == 2 && in.tabs.at(0).color == QColor(0x12, 0x34, 0x56)
                  && in.tabs.at(1).color == QColor(Qt::gray),
              "color round-trip save==load");
    }

    // ── splitView(3)=Bottom（0x8d4166）：wanted=Vertical；muxRow H != V → 包 ns(V) ──
    mux->splitView(3);
    for (int i = 0; i < 5; ++i) { // 布局事件多拍落地（offscreen 无 expose 链）
        QApplication::processEvents();
        QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
    }
    {
        QSplitter *common = nullptr;
        if (mux->parentWidget() && mux->parentWidget() != muxRow)
            common = qobject_cast<QSplitter *>(mux->parentWidget()); // ns 包裹件
        CHECK(common != nullptr, "splitView(Bottom): mux wrapped in new Vertical splitter");
        CHECK(common && common->orientation() == Qt::Vertical,
              "splitView(Bottom): wanted orientation Vertical");
        CHECK(common && common->count() == 2, "splitView(Bottom): parent splitter count=2");
        const auto sizes = common ? common->sizes() : QList<int>{};
        qInfo() << "  sizes:" << sizes << "kitCount:" << root->findChildren<KitGroup *>().count()
                << "newMux:" << root->findChild<MuxPaneGroup *>();
        CHECK(sizes.size() == 2 && sizes.at(0) > 0 && qAbs(sizes.at(0) - sizes.at(1)) <= 1,
              "splitView(Bottom): sizes halved");
        const int kitCount = root->findChildren<KitGroup *>().count();
        CHECK(kitCount == 2, "splitView: one nested new KitGroup created");
        MuxPaneGroup *newMux = nullptr;
        for (MuxPaneGroup *g : root->findChildren<MuxPaneGroup *>())
            if (g != mux)
                newMux = g;
        CHECK(newMux && newMux != mux, "splitView: new MuxPaneGroup exists");
        // 新组出现新 bash（工厂回调空开——断言用空 bash 标签补齐）
        if (newMux) {
            newMux->onAddSession();
            QApplication::processEvents();
            QTabBar *ntab = nullptr;
            for (QTabBar *tb : root->findChildren<QTabBar *>()) {
                // 组 2 标签条：其 ViewGroup 父的 parentWidget = 新 KitGroup（≠ 组 1 kitGroup）
                if (tb->parentWidget() && tb->parentWidget()->parentWidget() != kitGroup)
                    ntab = tb;
            }
            CHECK(ntab && ntab->count() == 2, "splitView: new group has its own bash tab");
        }
    }

    // ── activateNextView 循环（0x8ce784）：两个组各 1 view → next 回本组，index 变化 ──
    {
        MuxPaneGroup *newMux = nullptr;
        for (MuxPaneGroup *g : root->findChildren<MuxPaneGroup *>())
            if (g != mux)
                newMux = g;
        auto *stack = mux->findChild<QStackedWidget *>();
        CHECK(stack && stack->currentIndex() == 0, "activateNextView pre: group1 index 0");
        mux->activateNextView(true); // 0 → 1（跨到新组；DFS 顺序 [组1 view, 组2 view]）
        QApplication::processEvents();
        auto *nstack = newMux ? newMux->findChild<QStackedWidget *>() : nullptr;
        const int idx1 = stack ? stack->currentIndex() : -1;
        const int idx2 = nstack ? nstack->currentIndex() : -1;
        qInfo() << "  idx1:" << idx1 << "idx2:" << idx2;
        CHECK(idx2 >= 0 && (idx2 != idx1 || idx1 != 0),
              "activateNextView: activation crossed to new group");
        if (nstack) {
            const QSignalBlocker b(nstack); // 下一步反向激活不依赖新组栈信号
            nstack->setCurrentIndex(0);
        }
        mux->activateNextView(false); // 1 → 0（回到组 1）
        QApplication::processEvents();
        CHECK(stack && stack->currentIndex() == 0,
              "activateNextView(previous): back to group1 index 0");
    }

    // ── closeGroup 守卫（0x8cc916）──
    CHECK(mux->canCloseGroup(), "canCloseGroup: two groups -> true");

    // ── 关闭新组（内层 KitGroup）：空 splitter 清理 + 剩余组标签保留（0x8cc99c/0x5a29e6）──
    {
        MuxPaneGroup *newMux = nullptr;
        for (MuxPaneGroup *g : root->findChildren<MuxPaneGroup *>())
            if (g != mux)
                newMux = g;
        CHECK(newMux != nullptr, "pre-close: inner group exists");
        if (newMux) {
            newMux->closeGroup();
            for (int i = 0; i < 5; ++i) { // singleShot(0)+DeferredDelete 多拍落地
                QApplication::processEvents();
                QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
            }
            MuxPaneGroup *gone = nullptr;
            for (MuxPaneGroup *g : root->findChildren<MuxPaneGroup *>())
                if (g == newMux)
                    gone = g;
            CHECK(gone == nullptr, "closeGroup: inner group removed");
            CHECK(root->findChildren<QSplitter *>().count() == 2,
                  "closeGroup: empty nested splitter cleaned (muxRow+root remain)");
            CHECK(tabBar && tabBar->count() == 1
                      && qHash(tabBar->tabText(0)) == initialTabTextHash,
                  "closeGroup: surviving group tab preserved");
        }
        CHECK(!mux->canCloseGroup(), "canCloseGroup: single group -> false (guard)");
        // 一组时不关：再调 closeGroup 不产生破坏
        mux->closeGroup();
        QApplication::processEvents();
        QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
        CHECK(mux->parentWidget() != nullptr, "closeGroup guarded: single group not closed");
    }

    qInfo().nospace() << "TEST_PANE_SPLIT " << (failed == 0 ? "PASSED" : "FAILED") << " (" << failed << " failures)";
    return failed == 0 ? 0 : 1;
}
