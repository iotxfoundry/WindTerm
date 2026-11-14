// 冒烟断言(ctest 门;铁律 5:断言语料行为,非教科书行为)——
// onFocusChanged 槽体真身(批 92,FUN_008e0bb2):验证 S4-S6 tab bar
// state 翻转腿(008e0da5:祖先→"Active";S2 锚 = win.focusWidget(),
// 窗口失活保持 — 008e0c9e 反汇编)、S8-S9 焦点链回溯不崩、S0/S10
// 更新禁更撤防(FUN_008dfd89→008dfd7c);批 106:b1 SplitterGroup
// isZoomed(FUN_005a23c6)初值 / b2 onTabBlankRequested(FUN_008df5f8)
// 无 win 上溯早返 / b3 renamePane(008df0a4)无 pane 早返。
#include <QApplication>
#include <QMenu>
#include <QTabBar>
#include <QTimer>
#include <cstdio>
#include "Actions/KitWindowFace.h"
#include "Actions/MuxWindow.h"
#include "Actions/MuxPaneGroup.h"
#include "Actions/TabGroup.h"

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
		void *menu() override { // 槽 62 对位(0x5e97d2/0x858fce 同型)
			++menuCalls;
			if (g_menu == nullptr)
				g_menu = new QMenu;
			return g_menu;
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

	printf("mwc_smoke: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
