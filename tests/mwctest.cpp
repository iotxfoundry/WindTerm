// 冒烟断言(ctest 门;铁律 5:断言语料行为,非教科书行为)——
// onFocusChanged 槽体真身(批 92,FUN_008e0bb2):验证 S4-S6 tab bar
// state 翻转腿(008e0da5:祖先→"Active";S2 锚 = win.focusWidget(),
// 窗口失活保持 — 008e0c9e 反汇编)、S8-S9 焦点链回溯不崩、S0/S10
// 更新禁更撤防(FUN_008dfd89→008dfd7c);批 106:b1 SplitterGroup
// isZoomed(FUN_005a23c6)初值 / b2 onTabBlankRequested(FUN_008df5f8)
// 无 win 上溯早返 / b3 renamePane(008df0a4)无 pane 早返。
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QTabBar>
#include <QTimer>
#include <cstdio>
#include "Actions/KitWindowFace.h"
#include "Actions/KitBar.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/MainWindowFace.h"
#include "Actions/MuxWindow.h"
#include "Actions/MuxPaneGroup.h"
#include "Actions/TabGroup.h"
#include "Editor/CGlobalConfigFace.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv); // focusChanged 信号源(qcoreapp)
	int fails = 0;
	QWidget *out = nullptr; // 常驻焦点外顶层

	MuxWindow win(false, nullptr); // ctor param_2 = +0x41 BYTE 旗标(008e0984;
	                               //   非 tmux 腿调用点全 0:0026:34935 等)
	win.resize(300, 200);

	MuxPaneGroup *group = new MuxPaneGroup(true, &win); // S3 findChildren 面
	group->show();
	win.show();

	// 与槽体 S4 同面取 bar(TabGroup 装配的;非另造)
	QTabBar *bar = group->findChild<QTabBar *>(QString());
	if (bar == nullptr) {
		printf("mwc_smoke: FAIL (no QTabBar under group)\n");
		return 1;
	}

	// 焦点进 win → S5 真腿:bar 是 win 焦点链祖先 → "Active"
	QApplication::setActiveWindow(&win);
	bar->setFocus(); // 焦点落在 tab bar(S4 同 face 部件)
	QApplication::processEvents();
	if (bar->property("state").toString() != QStringLiteral("Active"))
		++fails; // 语料 008e0da5-dac:祖先 → "Active"

	// 焦点移出(常驻顶层防失焦回收)—— 语料语义:槽内锚 = this->focusWidget()
	//   (008e0c9e-8e0ca6 反汇编:receiver = 0x20(%rsp) = this;窗口失活后
	//   QWidget::focusWidget 仍返回窗口内旧焦点件)→ state 保持 "Active"
	//   = 原版行为(isaprobe34 实证;不按"教科书清空"断言,铁律 5)
	out = new QWidget;
	out->show();
	QApplication::setActiveWindow(out);
	out->setFocus();
	QApplication::processEvents();
	printf("dbg2: app.fw=%p win.fw==bar? %d upd=%d state='%s'\n",
	       (void *)QApplication::focusWidget(),
	       (int)(win.focusWidget() == (QWidget *)bar),
	       (int)win.updatesEnabled(),
	       bar->property("state").toString().toUtf8().constData());
	if (bar->property("state").toString() != QStringLiteral("Active"))
		++fails; // 语料 008e0ca6 锚语义:win.fw 仍 bar → Active 保持

	// 直接喂槽复核(语料槽面 = 只读 win.focusWidget(),幂等):
	QMetaObject::invokeMethod(&win, "onFocusChanged",
	                          Q_ARG(QWidget *, nullptr),
	                          Q_ARG(QWidget *, nullptr));

	// S0/S1+S10 更新禁更腿:槽外沿(enabled 默认 true)
	if (!win.updatesEnabled())
		++fails; // FUN_008dfd7c 撤防后必须回 true

	// ======== 批 106:界面四槽落点 ========

	// b1. SplitterGroup::isZoomed(FUN_005a23c6 9B:+0x40 占位槽!=0)初值
	//     装配后 ph 空 → false;MuxWindow::isZoomed(FUN_008e01a2)同相
	if (win.isZoomed())
		++fails; // FUN_005a23c6:*(+0x40)==0 → false(未 zoom 基线)

	// b1b. MuxWindow BYTE 双旗标语料语义(批 108 勘正落码):
	//      ctor +0x40 ← 1 @008e0980 / +0x41 ← param_2 @008e0984(byte 写);
	//      setPaneZoom S7 gate 体只翻 +0x40(FUN_008dfd9b←0 @008e0764 /
	//      FUN_008dfd93←1 @008e07d4),+0x41 不触。无 pane 路径(pane==0
	//      @008e04ae 直返)不进 gate → +0x40 保持 ctor 值 1。
	if (win.isTmuxBranch() != false)
		++fails; // +0x41 == param_2(false)
	if (win.isZoomGate() != true)
		++fails; // +0x40 == ctor 1

	// b2. onTabBlankRequested(FUN_008df5f8)/confirmCloseCurrentPane
	//     (FUN_008dfa8c)/renamePane(008df0a4)均为私有槽;测试面走
	//     MuxPaneGroup 内嵌 TabGroup 的公共信号链(ctor
	//     connectGroupSignals 六条已在库 FUN_008de5a6):无 tab → pane
	//     空早返路径,直发不崩即同相。
	{
		MuxPaneGroup orphan(false, nullptr); // 无 win 父链(上溯早返同相)
		TabGroup *tg = orphan.findChild<TabGroup *>(QStringLiteral("PaneGroup"));
		if (tg == nullptr) {
			printf("mwc_smoke: FAIL (no PaneGroup TabGroup)\n");
			++fails;
		} else {
			emit tg->closeRequested();        // sig7 → FUN_008dfa8c(pane 空 → confirmPaneClose S1)
			emit tg->tabCloseRequested(-1);   // sig3 → FUN_008dfa76(index 未消费)
			emit tg->tabRenameRequested(-1);  // sig6 → FUN_008df466(-1→currentIndex;无 tab → S2 早返)
			emit tg->tabBlankRequested();     // sig2 → FUN_008df5f8(无 win 上溯早返)
		}
	}

	// ======== 批 133:showConfigMenu 三段真身(壳态早退/虚调用路径)========

	// c1. 壳态早退:orphan(块内)上溯无 KitWindowFace → 语料 008de2f1-319
	//     直返。此处置于 win 链:win 上无 KitWindow 子类(dynamic_cast
	//     失败)→ 同相直返;configRequested → showConfigMenu 直发不崩。
	TabGroup *tg = group->findChild<TabGroup *>(QStringLiteral("PaneGroup"));
	if (tg != nullptr)
		emit tg->configRequested(); // s_MuxPaneGroup_8de2d4(win 链无 KitWindowFace)

	// c2. 虚调用路径经测试子类:menu() 覆写计数(语料槽 62 +0x1f0;
	//     面见 KITWINDOW-RECON Q2/FUN_006926a0 vcall)。group 父链改为
	//     this → kit → win(对位 KitWindow ∈ MainWindow stack 页):
	//     上溯命中 kit → menu() 恰一记。尾段 kitPopupConfigButton:语料
	//     面有 "ConfigButton" 钮(expandable=true 分叉 008deb78 建)——
	//     空 QMenu::exec 在 offscreen 阻塞不可测 → 钮改名令 findChild
	//     miss → @005ac7fd 语料早返(exec 腿行为留宿主批验证)。
	static QMenu *g_menu = nullptr; // 测试空菜单容器(menu() 返回面)
	class TestKit : public KitWindowFace {
	public:
		int menuCalls = 0;
		CGlobalConfigFace *menu() override { // 槽 62 对位(0x5e97d2/0x858fce 同型)
			++menuCalls;
			if (g_menu == nullptr)
				g_menu = new QMenu;
			return reinterpret_cast<CGlobalConfigFace *>(g_menu);
		}
	} kit;
	kit.setParent(&win);
	group->setParent(&kit); // group 父链:this → kit(命中)→ win
	QToolButton *cfgBtn = tg->findChild<QToolButton *>(QStringLiteral("ConfigButton"));
	if (cfgBtn != nullptr)
		cfgBtn->setObjectName(QStringLiteral("c133bypass")); // findChild miss → 早返
	emit tg->configRequested();
	if (kit.menuCalls != 1)
		++fails; // 上溯命中 → vcall +0x1f0 恰一记(FUN_006926a0)
	// kitPopupConfigButton 可调性 + 钮缺早退面(FUN_005ac790 @005ac7fd:
	//   findChild 空 → 返回;menu 实参不触,传 null 同相)
	MuxPaneGroup::kitPopupConfigButton(&kit, QStringLiteral("Nope"), nullptr);
	delete g_menu;
	g_menu = nullptr;
	group->setParent(&win); // 恢复原链(后续不再上溯,原样)

	// c3. kitFindOrCreateGroupMenu S1/S3 面(FUN_00692ef0):name 空 →
	//     nullptr(@00692ef7);name 非空 + 容器空 → 新建腿 @00692fbf
	//     (tr + operator_new(0x30))非 null,标 (owner)。
	if (MuxPaneGroup::kitFindOrCreateGroupMenu(nullptr, QByteArray(), nullptr) != nullptr)
		++fails; // S1:*(int*)(name+4)==0 → 0 @00692ef7
	QMenu *m = MuxPaneGroup::kitFindOrCreateGroupMenu(
	    nullptr, QByteArrayLiteral("MuxPaneGroup"), nullptr);
	if (m == nullptr)
		++fails; // S3:容器空跳 S2 → tr 新建 QMenu @00692fbf-030
	delete m;

	// ======== 批 134:工厂接线(FUN_0089d752 ← s_HistoryHints_7664a2)========

	// d1. 工厂分派(FUN_0089d752 三分支 + 未知 null)—— 用 MainWindowFace
	//     装配真宿主(QMainWindow)+ Slots 面,产物挂 stack 页(不造真
	//     窗口:产物即 KitWindowFace 派生壳,ctor 只 parent+acceptDrops)。
	QMainWindow mwHost;      // 语料 param_1 = QMainWindow(MainWindowFace 面)
	mwHost.resize(200, 100);
	MainWindowFace mf(&mwHost); // FUN_007662e6 面(批 100):bar→f50/stack→f58
	MainWindowFace::Slots sl = mf.hostSlots();
	KitWindowFace *edW = kitWindowFactory(QStringLiteral("Editor"), &mwHost);
	if (edW == nullptr || edW->objectName() != QStringLiteral("EditorWindow"))
		++fails; // @0089d75a → EditorWindow(0xd0)+ objectName @005e970d
	KitWindowFace *buyW = kitWindowFactory(QStringLiteral("Buy"), &mwHost);
	if (buyW == nullptr || buyW->objectName() != QStringLiteral("EditorWindow"))
		++fails; // @0089d7ed(DAT_00d0eaa4="Buy" 二进制实读)→ EditorWindow 同型腿
	if (dynamic_cast<TerminalWindowFace *>(edW) != nullptr)
		++fails; // Editor 腿落 EditorWindow 面(非 Terminal)@0089d799
	KitWindowFace *bad = kitWindowFactory(QStringLiteral("Nope"), &mwHost);
	if (bad != nullptr)
		++fails; // @0089d846 未知类型 → null(调用点卫 0x7664cf)
	if (kitWindowFactory(QString(), &mwHost) != nullptr)
		++fails; // 空串同未知腿

	// d2. 页挂接线(s_HistoryHints_7664a2 面):hints 腿 setProperty 双
	//     记(@0x766507 "History"/@0x76652f "HistoryHints")+ stack 页数
	//     + KitBar 登记对账(@0x766543/0x766565);select 腿 setCurrentIndex
	//     (@0x766587);null 腿直返(上面 bad 未入页即间接对账)。
	kitWindowAttachPage(sl, &mwHost, QStringLiteral("Editor"), true,
	                    QByteArrayLiteral("hh"), 7); // hints 非空 → 双 setProperty
	kitWindowAttachPage(sl, &mwHost, QStringLiteral("Terminal"), false,
	                    QByteArray(), 0); // hints 空 → 跳双腿 @0x7664e8
	if (sl.f58->count() != 2)
		++fails; // 两页:Editor(select=true)+ Terminal(hints 空腿)
	if (sl.f58->currentIndex() != 0)
		++fails; // select 腿:Editor 页 index0 setCurrentIndex @0x766587
	QWidget *edPage = sl.f58->widget(0);
	if (edPage == nullptr || edPage->property("History").toByteArray() != QByteArrayLiteral("hh"))
		++fails; // @0x766507:QVariant(QByteArray) → "History"
	if (edPage == nullptr || edPage->property("HistoryHints").toInt() != 7)
		++fails; // @0x76652f:QVariant(int) → "HistoryHints"
	if (sl.f58->widget(1) == nullptr || sl.f58->widget(1)->property("History").isValid())
		++fails; // hints 空 → 双腿跳过(无属性落)
	if (sl.f50->buttonForIndex(0) == nullptr || sl.f50->buttonForIndex(1) == nullptr)
		++fails; // addKit 两记:@0x766565(FUN_008b346e index=addWidget 返回)
	if (sl.f50->buttonForIndex(2) != nullptr)
		++fails; // null 工厂腿不入页 → kit 钮恰两记(bad/空串直返)

	// ======== 批 140:menu() 两腿单例身份(CGlobalConfigFace 面)========

	// d3. Editor 腿(FUN_005e97d2):返回 CEditorConfig 单例非空;两页
	//     Editor 窗(Buy 同型腿)菜单身份恒同一对象(DAT_011c12e0 懒缓存
	//     语义 — 工厂每次新窗,菜单容器唯一)。
	CGlobalConfigFace *edMenu1 = static_cast<EditorWindowFace *>(edW)->menu();
	if (edMenu1 == nullptr)
		++fails; // FUN_005df8d6 Meyers 单例非 null @005e97da
	CGlobalConfigFace *edMenu2 = static_cast<EditorWindowFace *>(buyW)->menu();
	if (edMenu2 != edMenu1)
		++fails; // DAT_011c12e0 缓存 → 两腿同一单例(FUN_005df8d6)
	if (edMenu1 != CEditorConfigFace::instance())
		++fails; // 返回 = face 单例本体(FUN_005df8d6 → DAT_011c1300)
	if (!static_cast<CEditorConfigFace *>(edMenu1)->groupNames().isEmpty())
		++fails; // FUN_005df958 @005df96a:装载链 cited → +0xa8 空表 →
	             //   返回空 QList(机制原样,非空列表待容器真身批)

	// d4. Terminal 腿(FUN_00858fce):返回 CTerminalConfig 容器面非空;
	//     与 Editor 腿互异单例(DAT_011c12e0 ≠ DAT_011c2200);身份恒同。
	CGlobalConfigFace *tmMenu1 = static_cast<TerminalWindowFace *>(
	    sl.f58->widget(1))->menu();
	if (tmMenu1 == nullptr)
		++fails; // FUN_00809d78 单例非 null @00858fd6
	CGlobalConfigFace *tmMenu2 = static_cast<TerminalWindowFace *>(
	    sl.f58->widget(1))->menu();
	if (tmMenu2 != tmMenu1)
		++fails; // DAT_011c2200 缓存 → 同一 face 单例
	if (tmMenu1 == edMenu1)
		++fails; // 两腿异容器(语料双单例地址 011c1300/011c2220)
	if (tmMenu1 != static_cast<CGlobalConfigFace *>(terminalConfigAsFace()))
		++fails; // Terminal 腿返回 = face 转接单例(KitWindowFactory.cpp)

	delete edW;
	delete buyW;

	printf("mwc_smoke: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
