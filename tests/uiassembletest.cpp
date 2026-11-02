// 五级装配链组装冒烟(批 77-92 已落类;本测只断言装配面,不引新行为)。
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 链:MuxWindow(FUN_008dffa0 装配 +0x70 SplitterGroup)→
//    SplitterGroup(FUN_005a2314;QSplitter Vertical 不可折叠)→
//    MuxPaneGroup(s_MuxPaneGroup_8dece0;+0x38 TabGroup "PaneGroup")→
//    TabGroup(s_TabGroup_5af896;TabBar/QStackedWidget 装配)→
//    MuxPaneView(s_MuxPane_8de0c0;"MuxPane")。
// 无头惯例:QApplication + offscreen(tests/rendermathtest.cpp 同面)。
#include <QApplication>
#include <QFrame>
#include <QSplitter>
#include <QStackedWidget>
#include <QTabBar>
#include <cstdio>
#include "Actions/MuxWindow.h"
#include "Actions/MuxPaneGroup.h"
#include "Actions/MuxPaneView.h"
#include "Actions/SplitterGroup.h"
#include "Actions/TabGroup.h"

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	// ======== a. MuxPaneView ctor(s_MuxPane_8de0c0,0028:25440)========
	MuxPaneView pane(nullptr, TypeTerminal);
	expect(pane.objectName() == QStringLiteral("MuxPane"),
	       "a: objectName==\"MuxPane\"(@008de12c)");
	expect(pane.layout() != nullptr,
	       "a: 布局装配非 null(FUN_008de052 QVBoxLayout;setLayout @008de086)");

	// ======== b. TabGroup ctor(s_TabGroup_5af896,0018:28725)========
	TabGroup tab(nullptr);
	expect(dynamic_cast<QFrame *>(&tab) != nullptr,
	       "b: QFrame 型(QFrame 基,s_TabGroup_5af896 面)");
	expect(tab.findChild<QTabBar *>() != nullptr,
	       "b: TabBar 子件非 null(fullAssemble new TabBar(this) @005aef45;"
	       "s_TabScrollRightButton_5aec28 0018:28375)");

	// ======== c/f 共用:堆分配(栈对象会被 win 子件析构二次释放;
	//         mwctest.cpp:22 同因 heap)========
	// c. MuxPaneGroup ctor(s_MuxPaneGroup_8dece0,0028:25950)
	MuxPaneGroup *group = new MuxPaneGroup(true, nullptr);
	expect(group->findChild<TabGroup *>(QStringLiteral("PaneGroup")) !=
	           nullptr,
	       "c: findChild<TabGroup*>(\"PaneGroup\") 非 null(008de936 装配;"
	       "TabGroup objectName @008dea33/ctor @008de96f)");

	// ======== d. SplitterGroup ctor(FUN_005a2314,0018:18539)========
	SplitterGroup sg(nullptr);
	QSplitter *dsp = sg.splitter(); // +0x30(SplitterGroup.h 内联取面)
	expect(dsp != nullptr && dsp->orientation() == Qt::Vertical,
	       "d: splitter 非 null 且 Vertical(setOrientation(2) @005a22b8)");
	expect(!dsp->childrenCollapsible(),
	       "d: 不可折叠(setChildrenCollapsible(false) @005a22c2)");

	// ======== e. MuxWindow ctor(s_MuxWindow_8e0938;装配 FUN_008dffa0)========
	MuxWindow win(QStringLiteral("asmoke"), nullptr);
	expect(win.splitter() != nullptr,
	       "e: splitter() 非 null(FUN_008e01ac = +0x70→+0x30)");
	SplitterGroup *wsg = win.findChild<SplitterGroup *>();
	expect(wsg != nullptr && wsg->parentWidget() == &win &&
	           win.splitter() == wsg->splitter(),
	       "e: +0x70 = SplitterGroup(this) 且 splitter 同源"
	       "(new SplitterGroup(this) @008dfff9,存 +0x70 @FUN_008dffa0)");

	// ======== f. 五级组装(addWidget 面 = restorePaneSplitter @0083bd4c;
	//             addTab = FUN_008de3e8,0028:25642)========
	MuxPaneView *pane2 = new MuxPaneView(nullptr, TypeTerminal);
	QSplitter *sp = win.splitter();
	sp->addWidget(group);
	group->addTab(pane2, /*normal=*/false); // false → "Pinned"(008de4bc)
	TabGroup *tg = group->findChild<TabGroup *>(QStringLiteral("PaneGroup"));
	expect(group->parentWidget() == sp,
	       "f1: group 挂 splitter(QSplitter::addWidget 收养;0083bd4c 面)");
	expect(pane2->parentWidget() == tg->stack(),
	       "f2: pane 挂 TabGroup stack(insertWidget @TabGroup.cpp:316/"
	       "FUN_005abe1c 面)");
	expect(tg->stack()->parentWidget() == group,
	       "f3: stack 挂 group(attachChildWidgets @008debaa)");
	expect(tg->parentWidget() == group,
	       "f4: TabGroup 挂 group(new TabGroup(this) @008de96f)");
	expect(tg->tabBar()->parentWidget() == tg,
	       "f5: TabBar 挂 TabGroup(new TabBar(this) @005aef45)");
	expect(win.isAncestorOf(pane2),
	       "f6: 五级贯通 win→splitter→group→tg→stack→pane(isAncestorOf)");
	expect(group->tabCount() == 1,
	       "f7: tabCount==1(FUN_008de59c→QTabBar::count @005a79c4)");
	expect(group->currentPane() == pane2,
	       "f8: currentPane==pane(dynamic_cast 面 @008de3c5;"
	       "stack 首插即 current = Qt QStackedLayout 行为面)");

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
