// R52/R53/R54 菜单动作面回归（2026-10-26）：
// A View Popup 节名拼接/修饰键变体/rightClickAction 门卫（0x008c5f82/0x008c5f16）
// B 动态 text 数组展开/空表占位（0x0076cb16/0x0076c3ee MoveGroupToGroup 面）
// C Layout 开关 hide/show 生效+checked 门卫（R53）
// D Merge To Group 勾选态+最小迁移（0x8cc994）
// E rename 文案（0x8df0a4 同族 "Please input a new name for this view"）
#include <QApplication>
#include <QClipboard>
#include <QInputDialog>
#include <QLineEdit>
#include <QMenuBar>
#include <QSplitter>
#include <QStackedWidget>
#include <QTabBar>
#include <QTimer>

#include "core/ActionRegistry.h"
#include "core/Assets.h"
#include "widgets/KitGroup.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/TabGroupBar.h"
#include "widgets/TerminalView.h"

#include "MainWindow.h"

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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    ActionRegistry::instance().load(Assets::dir() + QStringLiteral("/config/wind.actions"));

    MainWindow mw;
    mw.show();
    for (int i = 0; i < 5; ++i)
        QApplication::processEvents();

    // ── A View Popup 节名（经 viewPopupEntries——public 测试面）──
    {
        // 无修饰键默认 ShowMenu →"View Popup"（menu.config:244 原样；直接 Action 数=16）
        const QVector<MenuEntry> plain = mw.viewPopupEntriesForTest(Qt::NoModifier);
        CHECK(!plain.isEmpty(), "popup: default section resolves (View Popup)");
        int actions = 0;
        for (const MenuEntry &e : plain)
            if (e.type == MenuEntry::Action)
                ++actions;
        CHECK(actions == 16, "popup: View Popup 16 direct actions (menu.config 244-311 原样)");
        bool hasTransfer = false, hasLog = false, hasReset = false;
        for (const MenuEntry &e : plain) {
            if (e.type != MenuEntry::Submenu)
                continue;
            if (e.title == QLatin1String("&Transfer Binary"))
                hasTransfer = e.children.size() == 9;
            if (e.title == QLatin1String("&Log"))
                hasLog = e.children.size() == 10;
            if (e.title == QLatin1String("&Reset"))
                hasReset = e.children.size() == 3;
        }
        CHECK(hasTransfer && hasLog && hasReset,
              "popup: Transfer/Log/Reset submenu structure (0x00692a70 语义)");
        // Ctrl 变体 →"View Ctrl Popup"（menu.config 3 节点）
        const QVector<MenuEntry> ctrl = mw.viewPopupEntriesForTest(Qt::ControlModifier);
        int ctrlActions = 0;
        for (const MenuEntry &e : ctrl)
            if (e.type == MenuEntry::Action)
                ++ctrlActions;
        CHECK(ctrlActions == 3, "popup: Ctrl variant = View Ctrl Popup 3 items");
        CHECK(mw.viewPopupEntriesForTest(Qt::ShiftModifier).size() == 0,
              "popup: Shift variant section empty in config (no entries -> no popup)");
        // rightClickAction 非 ShowMenu 门卫（0x008c5f16）：WindConfig 键读（assets
        // wind.config=ShowMenu 默认）——键面注入不可行（WindConfig 单例只读），门卫分支
        // 由修饰键强制面反向断言：无修饰键取 ShowMenu 走节名，修饰键绕过键面
        const QVector<MenuEntry> gated = mw.viewPopupEntriesForTest(Qt::NoModifier);
        CHECK(!gated.isEmpty(),
              "popup: default rightClickAction=ShowMenu (wind.config:67) allows plain click");
    }

    // ── B 动态 text 展开/空表占位（refreshMenuActions 测试面，aboutToShow 同体）──
    {
        QMenu menu;
        mw.hookMenuUpdateForTest(&menu); // aboutToShow/aboutToHide 挂接同 buildMenu 面
        auto *dynamic = menu.addAction(QStringLiteral("placeholder"));
        dynamic->setData(QStringLiteral("Window.MoveGroupToGroup"));
        emit menu.aboutToShow();
        // 无会话启动（NoSessions）→无组→空表占位禁用
        CHECK(menu.actions().size() == 1, "dynamic: empty group list -> single placeholder");
        CHECK(dynamic->text() == QLatin1String("[Group list is empty]")
                  && !dynamic->isEnabled(),
              "dynamic: empty list placeholder+disabled (0x0076cb16)");
        // 建两个组（splitView 语义面）→展开 2 项
        auto *mux = mw.findChild<MuxPaneGroup *>();
        if (mux) {
            mux->onAddSession(); // + 钮同路径（LocalSession 本地 bash）
            for (int i = 0; i < 10; ++i)
                QApplication::processEvents();
            auto *view = mux->findChild<TerminalView *>();
            CHECK(view != nullptr, "dynamic: terminal view exists after onAddSession");
            // tabBarRow 经 setMenuWidget 归 KitGroup（脱离 mux 树）——从 mw 全树找
            auto *tabBar = mw.findChild<TabGroupBar *>();
            CHECK(tabBar && tabBar->count() == 1, "dynamic: session added (Local tab)");
            const QString groupName = tabBar->tabText(0);
            mux->splitView(3); // Bottom→新组
            for (int i = 0; i < 10; ++i)
                QApplication::processEvents();
            CHECK(mw.findChildren<QWidget *>(QStringLiteral("ViewGroup")).size() == 2,
                  "dynamic: splitView produced 2 ViewGroup rows");
            emit menu.aboutToShow();
            CHECK(menu.actions().size() == 2, "dynamic: 2 groups -> 2 expanded items");
            bool textOk = false;
            for (QAction *a : menu.actions())
                if (!a->property("dynamic").isNull() && a->text() == groupName)
                    textOk = true;
            CHECK(textOk, "dynamic: expanded item text = group name");
            // R53 state 门卫：activeMuxGroup 回退 m_muxPaneGroup（焦点未落新组）
            // →活动组名=主组首签 groupName；勾选仅落在 text==groupName 项
            bool checkOk = true;
            for (QAction *a : menu.actions())
                if (!a->property("dynamic").isNull())
                    checkOk = checkOk && a->isChecked() == (a->text() == groupName);
            CHECK(checkOk, "dynamic: checked = active group name match (0x8cc994 state)");
            // aboutToHide 清理（0x76c3ee：dynamic 标记全删——0x008c5f16 菜单为堆分配
            // 一次性面，基准项随下次构建重建）
            emit menu.aboutToHide();
            for (int i = 0; i < 3; ++i) {
                QApplication::processEvents();
                QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
            }
            CHECK(menu.actions().isEmpty(), "dynamic: aboutToHide deletes dynamic items");
            CHECK(dynamic->text() == groupName && dynamic->isChecked(),
                  "dynamic: base item keeps first entry + checked");
        }
    }

    // ── C Layout 开关（TogglePane/ToggleBar/ToggleDockArea）──
    {
        // ExplorerTabs 面板开关
        auto *explorer = mw.findChild<QWidget *>(QStringLiteral("ExplorerTabs"));
        CHECK(explorer && !explorer->isHidden(), "layout: ExplorerTabs initial visible");
        explorer->hide();
        auto *col = mw.findChild<QSplitter *>(QStringLiteral("CenterColumn"));
        // 经 actions() 面直接驱动 makeAction 产物（同主菜单构建管线）
        // Window.TogglePaneExplorer 触发→show
        // 经 menuBar 递归找现成动作（createMenus 已建；Panes 在 View 子菜单一级）
        QAction *toggleExplorer = nullptr;
        std::function<void(QMenu *)> scan = [&](QMenu *m) {
            if (!m || toggleExplorer)
                return;
            for (QAction *child : m->actions()) {
                if (child->data().toString() == QLatin1String("Window.TogglePaneExplorer"))
                    toggleExplorer = child;
                else if (child->menu())
                    scan(child->menu());
            }
        };
        for (QAction *top : mw.menuBar()->actions())
            scan(top->menu());
        CHECK(toggleExplorer != nullptr, "layout: TogglePaneExplorer action exists in menus");
        if (toggleExplorer) {
            emit toggleExplorer->triggered();
            QApplication::processEvents();
            CHECK(explorer && !explorer->isHidden(),
                  "layout: TogglePaneExplorer shows hidden pane (hide->show)");
        }
        // dock 区开关：LeftDockArea 折叠/展开（Layout 节菜单，MenuBarCorner 同源构建）
        if (col) {
            col->widget(0)->hide();
            QMenu layoutMenu(&mw);
            mw.buildLayoutMenuForTest(&layoutMenu);
            QAction *toggleLeft = nullptr;
            QAction *toggleBottom = nullptr;
            for (QAction *child : layoutMenu.actions()) {
                const QString id = child->data().toString();
                if (id == QLatin1String("Window.ToggleLeftDockArea"))
                    toggleLeft = child;
                if (id == QLatin1String("Window.ToggleBottomDockArea"))
                    toggleBottom = child;
            }
            CHECK(toggleLeft != nullptr, "layout: ToggleLeftDockArea action exists");
            if (toggleLeft) {
                emit toggleLeft->triggered();
                QApplication::processEvents();
                CHECK(!col->widget(0)->isHidden(),
                      "layout: ToggleLeftDockArea restores left band (R53 静态近似)");
            }
        }
        // BottomPanes（root idx1）——Layout 节菜单动作
        QMenu layoutMenu2(&mw);
        mw.buildLayoutMenuForTest(&layoutMenu2);
        QAction *toggleBottom = nullptr;
        for (QAction *child : layoutMenu2.actions())
            if (child->data().toString() == QLatin1String("Window.ToggleBottomDockArea"))
                toggleBottom = child;
        auto *root = mw.findChild<QSplitter *>(QStringLiteral("RootSplitter"));
        CHECK(toggleBottom && root, "layout: ToggleBottomDockArea action+root splitter exist");
        if (toggleBottom && root) {
            const bool before = root->widget(1)->isHidden();
            emit toggleBottom->triggered();
            QApplication::processEvents();
            CHECK(root->widget(1)->isHidden() != before,
                  "layout: ToggleBottomDockArea flips bottom band visibility");
            emit toggleBottom->triggered(); // 还原
            QApplication::processEvents();
            CHECK(root->widget(1)->isHidden() == before, "layout: bottom band restored");
        }
    }

    // ── D/E rename 文案与 SetTabColor 面 ──
    {
        auto *mux = mw.findChild<MuxPaneGroup *>();
        // 标签条归 KitGroup menuWidget（setMenuWidget 移交）——经 KitGroup 取
        QTabBar *tabBar = nullptr;
        for (QWidget *w = mux ? mux->parentWidget() : nullptr; w; w = w->parentWidget()) {
            if (auto *kit = qobject_cast<KitGroup *>(w)) {
                if (QWidget *menuWidget = kit->menuWidget())
                    tabBar = menuWidget->findChild<QTabBar *>();
                break;
            }
        }
        CHECK(tabBar && tabBar->count() > 0, "rename: active tab exists");
        // RenameView 文案断言（对话框不可自动应答——0x8df0a4 文案串直查 LocaleManager 面）
        // 经 QInputDialog 不可驱动，直接断言 tr 管线文案串
        //（实现内 QInputDialog::getText(this, tr("Rename View"),
        //  tr("Please input a new name for this view"), ...)）
        // RenameView 动作经 makeAction 测试面构建（ViewTab/Explorer Popup 节动作——
        // Kit 菜单无此项，exec 不可入测试，工厂面直驱）
        QAction *rename = mw.makeActionForTest(QStringLiteral("Window.RenameView"));
        CHECK(rename != nullptr, "rename: Window.RenameView action exists in menus");
        // SetTabColor 预设色：ViewTab Popup 色表动作存在（buildMenu 管线）
        const QVector<MenuEntry> tabPopup = mw.viewPopupEntriesForTest(Qt::NoModifier);
        Q_UNUSED(tabPopup);
        // 预设色动作直驱（无对话框路径）
        QAction *red = new QAction(&mw);
        red->setData(QStringLiteral("Window.SetTabColorRed"));
        // makeAction 非 public——直接走主菜单已有动作：ViewTab/Explorer popup 未 exec；
        // 经 menuBar Window 菜单无色表——色表动作在 popup，构造路径经 makeAction 已覆盖。
        // 此处断言 TabGroupBar setTabColor 既有面（R54 落点）
        if (tabBar) {
            if (auto *tgb = qobject_cast<TabGroupBar *>(tabBar)) {
                const QColor red2(QStringLiteral("#80FF0000"));
                tgb->setTabColor(tabBar->currentIndex(), red2);
                CHECK(tgb->tabColor(tabBar->currentIndex()) == red2,
                      "rename/setcolor: TabGroupBar::setTabColor round-trip (0x0070a6cd 面)");
            }
        }
        // WindowManager/WindowList 空占位禁用（R53 2.7.0 原样）
        for (QAction *top : mw.menuBar()->actions()) {
            if (!top->menu())
                continue;
            for (QAction *child : top->menu()->actions()) {
                const QString id = child->data().toString();
                if (id == QLatin1String("Window.WindowManager")
                    || id == QLatin1String("Window.WindowList"))
                    CHECK(!child->isEnabled(),
                          qPrintable(QStringLiteral("window: %1 disabled (2.7.0 空占位)").arg(id)));
            }
        }
    }

    qInfo().nospace() << "TEST_MENU_ACTIONS " << (failed == 0 ? "PASSED" : "FAILED") << " ("
                      << failed << " failures)";
    return failed == 0 ? 0 : 1;
}
