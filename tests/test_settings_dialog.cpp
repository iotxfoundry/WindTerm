// R51 SettingDialog 设置中心回归（offscreen + QTemporaryDir HOME，不碰真实 profile）：
// 0x006e9cd8 页树 8 顶层+子页枚举 / 0x006ebcc6 选中切页 / 四实页控件读写 WindConfig round-trip /
// 0x006ea541 底行=提示 QLabel+Close 单钮（0x006dd310 rejected→reject）
#include <QApplication>
#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QTemporaryDir>
#include <QTreeWidget>
#include <cstdio>

#include "core/Assets.h"
#include "core/WindConfig.h"
#include "dialogs/SettingDialog.h"

static int failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++failed;
}

int main(int argc, char **argv)
{
    QTemporaryDir home; // 自管 HOME：WindConfig profile 目录隔离（不污染 ~/.wind）
    qputenv("HOME", home.path().toUtf8());
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    check(WindConfig::instance().load(
              Assets::dir() + QStringLiteral("/config/wind.config")),
          "wind.config loads");

    SettingDialog dlg;
    dlg.resize(dlg.minimumSize());

    // ── 页树结构（0x006e9cd8 顶层 8 + 子页照建全）──
    auto *tree = dlg.findChild<QTreeWidget *>();
    check(tree != nullptr, "category tree exists");
    if (tree) {
        QStringList top;
        for (int i = 0; i < tree->topLevelItemCount(); ++i)
            top << tree->topLevelItem(i)->text(0);
        check(top.size() == 8, "8 top-level pages");
        check(top == (QStringList{QStringLiteral("Application"), QStringLiteral("Appearance"),
                                  QStringLiteral("Editor"), QStringLiteral("Proxy"),
                                  QStringLiteral("Search"), QStringLiteral("Security"),
                                  QStringLiteral("Tabs"), QStringLiteral("Terminal")}),
              "top-level order Application..Terminal");
        QTreeWidgetItem *editor = tree->topLevelItem(2);
        QStringList editorChildren;
        if (editor && editor->text(0) == QStringLiteral("Editor")) {
            for (int i = 0; i < editor->childCount(); ++i)
                editorChildren << editor->child(i)->text(0);
        }
        check(editorChildren == (QStringList{QStringLiteral("Text"), QStringLiteral("Widgets")}),
              "Editor subpages Text+Widgets");
        QTreeWidgetItem *text = editor ? editor->child(0) : nullptr;
        QStringList textChildren;
        if (text) {
            for (int i = 0; i < text->childCount(); ++i)
                textChildren << text->child(i)->text(0);
        }
        check(textChildren == (QStringList{QStringLiteral("Binary"), QStringLiteral("Caret"),
                                           QStringLiteral("Font"), QStringLiteral("Highlight"),
                                           QStringLiteral("Indentation"),
                                           QStringLiteral("Line Ending"), QStringLiteral("Wrap")}),
              "Text subpages 7");
        QTreeWidgetItem *terminal = tree->topLevelItem(7);
        QStringList terminalChildren;
        if (terminal) {
            for (int i = 0; i < terminal->childCount(); ++i)
                terminalChildren << terminal->child(i)->text(0);
        }
        check(terminalChildren == (QStringList{QStringLiteral("Auto Completion"),
                                               QStringLiteral("Command History"),
                                               QStringLiteral("Mouse Tracking")}),
              "Terminal subpages 3");
    }

    // ── stack 页数=树节点总数 ──
    auto *stack = dlg.findChild<QStackedWidget *>();
    check(stack != nullptr, "page stack exists");
    // 8 顶层 + Editor 2 子 + Text 7 + Widgets 2 + Terminal 3 = 22 节点=22 页
    check(stack && stack->count() == 22, "stack has 22 pages (node count)");

    // ── 选中切页（0x006ebcc6→0x006eb952）──
    if (tree && stack) {
        QTreeWidgetItem *tabs = tree->topLevelItem(6);
        tree->setCurrentItem(tabs);
        const int idx = stack->currentIndex();
        check(stack->widget(idx)->property("categoryPath").toString() ==
                  QStringLiteral("Tabs"),
              "selecting Tabs switches stack");
        QTreeWidgetItem *mouse = tree->topLevelItem(7)->child(2);
        tree->setCurrentItem(mouse);
        check(stack->widget(stack->currentIndex())->property("categoryPath").toString() ==
                  QStringLiteral("Terminal>Mouse Tracking"),
              "selecting Terminal>Mouse Tracking switches stack");
    }

    // ── Application 页：language combo 初值+写回 round-trip ──
    {
        QWidget *appPage = nullptr;
        for (int i = 0; i < stack->count(); ++i)
            if (stack->widget(i)->property("categoryPath").toString() ==
                QStringLiteral("Application"))
                appPage = stack->widget(i);
        check(appPage != nullptr, "Application page exists");
        if (appPage) {
            auto *lang = appPage->findChild<QComboBox *>();
            check(lang != nullptr, "language combo exists");
            // application.language="auto" 不在 combo 项里（0x006dcc80 combo 无 auto 项时保持 -1）：
            // 选中态只在键值命中已插入项时成立——骨架照原版语义（未命中=空选）
            check(lang && (lang->currentIndex() < 0 ||
                               lang->currentData().toString() ==
                                   WindConfig::instance().valueToString(
                                       QStringLiteral("application.language"))),
                  "language combo prefilled from wind.config");
            lang->setCurrentIndex(0);
            emit lang->activated(0); // 0x006dcc80 activated→setValue 写回链
            check(WindConfig::instance().valueToString(QStringLiteral("application.language")) ==
                      lang->itemData(0).toString(),
                  "language activated writes WindConfig");
            auto *opacity = appPage->findChild<QDoubleSpinBox *>();
            check(opacity != nullptr &&
                      qFuzzyCompare(opacity->value(),
                                    WindConfig::instance().valueToDouble(
                                        QStringLiteral("application.windowOpacity"), 1.0)),
                  "windowOpacity spin prefilled");
            opacity->setValue(0.5);
            check(qFuzzyCompare(WindConfig::instance().valueToDouble(
                                    QStringLiteral("application.windowOpacity"), 0.0),
                                0.5),
                  "windowOpacity valueChanged writes WindConfig");
        }
    }

    // ── Appearance 页：主题列表=assets/themes 目录+即时应用链 ──
    {
        QWidget *page = nullptr;
        for (int i = 0; i < stack->count(); ++i)
            if (stack->widget(i)->property("categoryPath").toString() ==
                QStringLiteral("Appearance"))
                page = stack->widget(i);
        check(page != nullptr, "Appearance page exists");
        if (page) {
            auto *combo = page->findChild<QComboBox *>();
            check(combo != nullptr && combo->count() >= 4, "theme combo lists themes dir");
            bool hasAll = combo && combo->findText(QStringLiteral("default")) >= 0 &&
                          combo->findText(QStringLiteral("dige-black")) >= 0 &&
                          combo->findText(QStringLiteral("dige-black-and-white")) >= 0 &&
                          combo->findText(QStringLiteral("dige-white")) >= 0;
            check(hasAll, "theme combo has 4 stock themes");
            if (combo) {
                const QString cur = WindConfig::instance().valueToString(
                    QStringLiteral("application.themeGui"), QStringLiteral("dige-black"));
                check(combo->currentText() == cur, "theme combo prefilled");
                const int next = (combo->currentIndex() + 1) % combo->count();
                emit combo->activated(next);
                check(WindConfig::instance().valueToString(QStringLiteral("application.themeGui")) ==
                          combo->itemData(next).toString(),
                      "theme activated writes WindConfig");
            }
        }
    }

    // ── Tabs 页：hoverToSelect/showSequenceNumbers/textElideMode round-trip ──
    {
        QWidget *page = nullptr;
        for (int i = 0; i < stack->count(); ++i)
            if (stack->widget(i)->property("categoryPath").toString() == QStringLiteral("Tabs"))
                page = stack->widget(i);
        check(page != nullptr, "Tabs page exists");
        if (page) {
            auto *spin = page->findChild<QDoubleSpinBox *>();
            check(spin != nullptr &&
                      qFuzzyCompare(spin->value(), WindConfig::instance().valueToDouble(
                                                       QStringLiteral("tabbar.hoverToSelect"), 0.0)),
                  "hoverToSelect prefilled (0.2)");
            spin->setValue(0.5);
            check(qFuzzyCompare(
                      WindConfig::instance().valueToDouble(QStringLiteral("tabbar.hoverToSelect"), 0.0),
                      0.5),
                  "hoverToSelect writes WindConfig");

            const QList<QComboBox *> combos = page->findChildren<QComboBox *>();
            check(combos.size() == 2, "Tabs page has 2 combos");
            for (QComboBox *c : combos) {
                // 值域=原版枚举键（None/FirstNine/All、Elide*）经 itemData 写回
                const QString key = c->property("windKey").toString();
                const int next = (c->currentIndex() + 1) % c->count();
                emit c->activated(next);
                check(WindConfig::instance().valueToString(key) == c->itemData(next).toString(),
                      qPrintable(QStringLiteral("combo %1 round-trip").arg(key)));
            }
        }
    }

    // ── Terminal>Mouse Tracking 页：六 checkbox 读初值+写回 ──
    {
        QWidget *page = nullptr;
        for (int i = 0; i < stack->count(); ++i)
            if (stack->widget(i)->property("categoryPath").toString() ==
                QStringLiteral("Terminal>Mouse Tracking"))
                page = stack->widget(i);
        check(page != nullptr, "Mouse Tracking page exists");
        if (page) {
            const auto boxes = page->findChildren<QCheckBox *>();
            check(boxes.size() == 6, "6 mouseTracking checkboxes");
            const QStringList keys = {
                QStringLiteral("terminal.mouseTracking.move"),
                QStringLiteral("terminal.mouseTracking.wheel"),
                QStringLiteral("terminal.mouseTracking.click"),
                QStringLiteral("terminal.mouseTracking.doubleClick"),
                QStringLiteral("terminal.mouseTracking.middleClick"),
                QStringLiteral("terminal.mouseTracking.rightClick"),
            };
            bool allMatch = boxes.size() == 6;
            for (int i = 0; i < boxes.size() && allMatch; ++i) {
                // 布局序=0x6dfa0e 装配序（move/wheel/click/doubleClick/middleClick/rightClick）
                const bool cfg = WindConfig::instance().valueToBool(
                    keys.at(i), keys.at(i) != QStringLiteral("terminal.mouseTracking.rightClick"));
                if (boxes.at(i)->isChecked() != cfg)
                    allMatch = false;
            }
            check(allMatch, "checkbox states match wind.config");
            if (boxes.size() == 6) {
                boxes[0]->setChecked(!boxes[0]->isChecked());
                check(WindConfig::instance().valueToBool(keys.at(0), false) ==
                          boxes[0]->isChecked(),
                      "mouseTracking stateChanged writes WindConfig");
            }
        }
    }

    // ── 底行按钮=Close 单钮（0x006ea541）+rejected→reject（0x006dd310）──
    {
        auto *box = dlg.findChild<QDialogButtonBox *>();
        check(box != nullptr, "button box exists");
        check(box && box->buttons().size() == 1, "single button");
        check(box && box->button(QDialogButtonBox::Close) != nullptr, "button is Close");
        if (box) {
            auto *btn = box->button(QDialogButtonBox::Close);
            check(btn->text().contains(QStringLiteral("Close")) ||
                      btn->text().contains(QStringLiteral("关闭")),
                  "Close text (en or tr)");
        }
    }

    std::printf(failed == 0 ? "ALL PASS\n" : "FAILED %d\n", failed);
    return failed == 0 ? 0 : 1;
}
