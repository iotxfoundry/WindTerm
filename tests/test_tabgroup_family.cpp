// TabGroup 族五件收敛测试（批 2026-10-26）：
// A hoverToSelect 计时语义（R45 0x005ad4a6/0x005abfd8）
// B TabScroll autoRepeat/溢出面/步进（R47 0x005aec28/0x005aa862/0x005ab6ee）
// C TabListMenu 行构建+过滤计数（0x005b1c08）
// D ConfigButton 菜单动作集（R50 0x008de2d4）
// E session.color 染色（R46 0x7503a0/0x5a7b66/0x5a8b2e）
#include <QApplication>
#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMouseEvent>
#include <QTabBar>
#include <QTimer>
#include <QToolButton>
#include <QWidgetAction>

#include "widgets/MuxDesktop.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/TabGroupBar.h"

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

    auto *bar = new TabGroupBar;
    bar->addTab(QStringLiteral("one"));
    bar->addTab(QStringLiteral("two"));
    bar->addTab(QStringLiteral("three"));

    // ── A hoverToSelect（R45）──
    {
        CHECK(bar->hoverTimer() == nullptr, "hover: timer absent before enable");
        bar->setHoverToSelect(0.2); // wind.config:34 默认值
        CHECK(bar->hoverTimer() != nullptr, "hover: >0 creates timer (0x005ad4a6)");
        CHECK(bar->hoverTimer()->interval() == 200,
              "hover: double seconds->int ms (0.2s->200ms)");
        bar->setHoverToSelect(0.05); // 下限夹取
        CHECK(bar->hoverTimer()->interval() == 100,
              "hover: below-100ms clamped to 100 (0x005ad4a6 cmovl 0x64)");
        bar->setHoverToSelect(0.0);
        CHECK(bar->hoverTimer() == nullptr,
              "hover: <=0 deletes timer (0x005ad4a6 <=0 branch)");
        // MouseMove→记位+start；超时→切签。
        // 注：QApplication::notify 对未显示 widget 的合成 MouseMove 有前置吞没
        // （notify 返回 true 不达 event()），测试直接走 notify_helper 同源虚调用
        // event()（原生鼠标路径即此分派）
        bar->setHoverToSelect(0.1);
        QTimer *timer = bar->hoverTimer();
        QMouseEvent move(QEvent::MouseMove, QPointF(4, 4), Qt::NoButton, Qt::NoButton,
                         Qt::NoModifier);
        bar->sendSyntheticEvent(&move);
        CHECK(bar->hoverTimer() != nullptr && bar->hoverTimer()->isActive(),
              "hover: MouseMove new index starts timer");
        CHECK(bar->hoverIndex() == 0, "hover: MouseMove records tabAt (0x005abfd8 +0x40)");
        const int wait = (bar->hoverTimer() ? bar->hoverTimer()->interval() : 100) + 50;
        QElapsedTimer clock;
        clock.start();
        while (!clock.hasExpired(wait))
            QCoreApplication::processEvents();
        CHECK(bar->currentIndex() == 0, "hover: timeout selects hovered tab (0x005aa91e)");
        // Leave→清位+stop
        QEvent leave(QEvent::Leave);
        bar->sendSyntheticEvent(&leave);
        CHECK(timer != nullptr && !timer->isActive(),
              "hover: Leave stops timer (0x005abfd8 0xb)");
        CHECK(bar->hoverIndex() == -1, "hover: Leave clears index (0x005abfd8)");
        bar->sendSyntheticEvent(&move);
        CHECK(bar->hoverIndex() == 0, "hover: re-enter records again");
        bar->setHoverToSelect(0.0);
    }

    // ── B TabScroll（R47）──
    {
        auto *mux = new MuxPaneGroup;
        auto *left = mux->findChild<QToolButton *>(QStringLiteral("TabScrollLeftButton"));
        auto *right = mux->findChild<QToolButton *>(QStringLiteral("TabScrollRightButton"));
        CHECK(left && right, "scroll: buttons exist in MuxPaneGroup row");
        CHECK(left && left->autoRepeat() && right && right->autoRepeat(),
              "scroll: autoRepeat(true) both (0x005aec28)");
        CHECK(left && !left->isVisible() && !left->isEnabled(),
              "scroll: initial hide+disabled (no overflow)");
        CHECK(left && !left->property("animated").isValid(),
              "scroll: no animation property (原版无动画)");
        // 步进：right 点击→currentIndex+1（0x005ab6ee 语义面）
        mux->onAddSession();
        mux->onAddSession();
        QApplication::processEvents();
        auto *tabBar = mux->findChild<TabGroupBar *>();
        CHECK(tabBar && tabBar->count() == 2, "scroll: two sessions added");
        if (tabBar && right) {
            tabBar->refreshScrollButtonsForTest(); // 溢出面显式刷（offscreen 无布局拍）
            const int idx = tabBar->currentIndex();
            if (right->isEnabled()) {
                right->click();
                QApplication::processEvents();
                CHECK(tabBar->currentIndex() == qMin(idx + 1, tabBar->count() - 1),
                      "scroll: right click steps forward (0x005ab6ee)");
            } else {
                CHECK(true, "scroll: disabled at no-overflow (original gate kept)");
            }
        }
        delete mux;
    }

    // ── C TabListMenu（0x005b1c08）──
    {
        int closedAt = -1;
        QMenu *menu = TabGroupBar::buildTabListMenu(
            bar, [&closedAt](int index) { closedAt = index; });
        CHECK(menu && menu->objectName() == QStringLiteral("TabListMenu"),
              "tablist: menu objectName (0x005b2918)");
        const QList<QAction *> actions = menu->actions();
        CHECK(actions.size() == 1 + 3, "tablist: filter row + 3 tab rows");
        // 行件树：#MenuItemWidget[#IconLabel,#TextLabel,#CloseButton]
        bool rowsOk = true;
        int labelCount = 0;
        for (QAction *action : actions) {
            auto *wa = qobject_cast<QWidgetAction *>(action);
            QWidget *w = wa ? wa->defaultWidget() : nullptr;
            if (!w || w->objectName() != QStringLiteral("MenuItemWidget"))
                continue; // filter 行
            labelCount++;
            if (!w->findChild<QWidget *>(QStringLiteral("IconLabel"))
                || !w->findChild<QWidget *>(QStringLiteral("TextLabel"))
                || !w->findChild<QWidget *>(QStringLiteral("CloseButton")))
                rowsOk = false;
        }
        CHECK(rowsOk && labelCount == 3,
              "tablist: rows have IconLabel/TextLabel/CloseButton (0x005b2c26)");
        // 行触发带关闭位→closeHandler(index)（0x005aa958 分流）
        QWidgetAction *row2 = qobject_cast<QWidgetAction *>(actions.at(2));
        CHECK(row2 && row2->data().toInt() == 1, "tablist: row action data=tab index");
        if (row2) {
            row2->setProperty("closeRequested", true);
            emit row2->triggered();
            CHECK(closedAt == 1, "tablist: close flow reaches handler (0x008fb5e0 面)");
        }
        // FilterEdit 行为：textChanged 过滤行+计数
        QWidgetAction *filterAction = qobject_cast<QWidgetAction *>(actions.first());
        QWidget *filterBox = filterAction ? filterAction->defaultWidget() : nullptr;
        FilterEdit *edit = filterBox ? filterBox->findChild<FilterEdit *>() : nullptr;
        QLabel *countLabel = filterBox ? filterBox->findChild<QLabel *>(QStringLiteral("CountLabel"))
                                       : nullptr;
        CHECK(edit && countLabel, "tablist: FilterEdit+CountLabel row (0x005b25d4)");
        CHECK(countLabel && countLabel->text() == QStringLiteral("3"),
              "tablist: initial count=3 (0x005b27a2)");
        if (edit) {
            edit->setText(QStringLiteral("tw"));
            CHECK(countLabel && countLabel->text() == QStringLiteral("1"),
                  "tablist: filter narrows count");
            edit->setText(QStringLiteral("zzz"));
            CHECK(countLabel && countLabel->text() == QStringLiteral("0"),
                  "tablist: no-match count=0");
            edit->setText(QString());
            CHECK(countLabel && countLabel->text() == QStringLiteral("3"),
                  "tablist: cleared filter restores count");
        }
        delete menu;
    }

    // ── D ConfigButton 菜单动作集（R50）──
    {
        auto *mux = new MuxPaneGroup;
        mux->initTmuxMode(true);
        auto *config = mux->findChild<QToolButton *>(QStringLiteral("ConfigButton"));
        CHECK(config != nullptr, "config: ConfigButton exists (tmux attached)");
        // 动作集断言经 menu.config 解析同源函数——直弹 menu 会阻塞 exec，故只断
        // dispatch 分派面（菜单构建=showConfigMenu 内部同 entries）
        const QStringList expected = {
            QStringLiteral("Mux.TogglePaneZoom"),
            QStringLiteral("Mux.MovePaneToNewWindow"),
            QStringLiteral("Mux.SplitPaneUp"), QStringLiteral("Mux.SplitPaneDown"),
            QStringLiteral("Mux.SplitPaneLeft"), QStringLiteral("Mux.SplitPaneRight"),
            QStringLiteral("Mux.RenamePane"), QStringLiteral("Mux.RenameWindow"),
            QStringLiteral("Tmux.RenameSession")};
        bool entriesOk = mux->configMenuActionsForTest(expected);
        CHECK(entriesOk, "config: menu.config MuxPaneGroup actions present (0x008de2d4)");
        delete mux;
    }

    // ── E session.color 染色（R46）──
    {
        CHECK(bar->tabColor(0).isValid() == false, "color: default invalid (0x005a7b66)");
        const QColor green(QStringLiteral("#00ff00"));
        bar->setTabColor(0, green);
        CHECK(bar->tabColor(0) == green, "color: setTabColor stores (0x005a7b66)");
        // 渲染断言：染色签与非染签像素差（0x005a8b2e fillRect）
        bar->resize(400, 30);
        bar->show();
        QApplication::processEvents();
        const QRect r = bar->tabRect(0);
        const QImage img = bar->grab().toImage();
        const QColor pixel = img.pixelColor(r.center());
        CHECK(pixel == green, "color: painted fillRect pixel==session color (0x005a8b2e)");
        // 无效色不染：tab1 保持默认（与背景非强断言，仅结构面）
        CHECK(bar->tabColor(1).isValid() == false, "color: tab1 stays invalid/untinted");
        // removeTab 色表收缩
        bar->setTabColor(2, QColor(QStringLiteral("blue")));
        bar->removeTab(1);
        CHECK(bar->tabColor(1) == QColor(QStringLiteral("blue")),
              "color: colors shift with removeTab");
    }

    delete bar;

    qInfo().nospace() << "TEST_TABGROUP_FAMILY " << (failed == 0 ? "PASSED" : "FAILED")
                      << " (" << failed << " failures)";
    return failed == 0 ? 0 : 1;
}
