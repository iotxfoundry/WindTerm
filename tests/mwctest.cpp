// 冒烟断言(ctest 门;铁律 5:断言语料行为,非教科书行为)——
// onFocusChanged 槽体真身(批 92,FUN_008e0bb2):验证 S4-S6 tab bar
// state 翻转腿(008e0da5:祖先→"Active";S2 锚 = win.focusWidget(),
// 窗口失活保持 — 008e0c9e 反汇编)、S8-S9 焦点链回溯不崩、S0/S10
// 更新禁更撤防(FUN_008dfd89→008dfd7c);批 106:b1 SplitterGroup
// isZoomed(FUN_005a23c6)初值 / b2 onTabBlankRequested(FUN_008df5f8)
// 无 win 上溯早返 / b3 renamePane(008df0a4)无 pane 早返。
#include <QApplication>
#include <QCoreApplication>
#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QMenu>
#include <QSplitter>
#include <QTabBar>
#include <QTimer>
#include <QWidget>
#include <cstdio>
#include "Actions/KitWindowFace.h"
#include "Actions/KitBar.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/MainWindowFace.h"
#include "Actions/MuxWindow.h"
#include "Actions/MuxPaneGroup.h"
#include "Actions/MuxPaneView.h"
#include "Actions/TabGroup.h"
#include "Editor/CGlobalConfigFace.h"
#include "Editor/CTerminalConfig.h"
#include "Actions/StartupChain.h"
#include "Sessions/WorkspaceLoader.h"
#include "Editor/ProfileLoader.h"

#include <json/json.h>

#include <QDateTime>
#include <memory>

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

	// ======== 批 142:yaml 装载腿 + 双 Meyers 合一 + 宿主接线 ========

	// d5. 双 Meyers 合一(KITWINDOW-RECON §未解 1 收口):CTerminalConfig
	//     单例与 face 容器 = 同一对象双面 — face() 返回值面单例本体
	//     (私有基 upcast 同址;语料 FUN_00858fce 返回 FUN_00809d78 结果)。
	if (static_cast<CGlobalConfigFace *>(CTerminalConfig::face())
	    != static_cast<CGlobalConfigFace *>(tmMenu1))
		++fails; // face 面 == menu() 返回容器面(合一判)
	if (tmMenu1 == CEditorConfigFace::instance())
		++fails; // Editor≠Terminal 恒(两 Config 异对象,语料 011c1300/011c2220)
	CTerminalConfig *tval = CTerminalConfig::instance();
	if (static_cast<CGlobalConfigFace *>(tval->face())
	    != static_cast<CGlobalConfigFace *>(terminalConfigAsFace()))
		++fails; // 值面单例的 face == terminalConfigAsFace(同址双面)

	// d6. yaml 装载腿真身(批 142;真库委托):menu() 懒缓存腿已跑
	//     ensureLoaded(FUN_008aa896 编排)。测试树 applicationDirPath
	//     无 configs/menu.config → loadGroups/loadViews false 同相
	//     (@008a9a6a 直返腿,树不触摸),不崩即机制面;groupNames()
	//     (+0xa8 读面,批 140)不受装载腿影响(FUN_008a99de 只写
	//     +0x28/+0x60,写面实读)→ 仍空表。
	if (!static_cast<CEditorConfigFace *>(edMenu1)->groupNames().isEmpty())
		++fails; // +0xa8 非装载腿目标(批 140 判保持)

	// d7. 宿主接线(FUN_0075e3fe 无 pane 腿 → FUN_007665ae):装配面
	//     (mwHost 链)无活动 MuxPane → "Terminal" 首页第三页挂入
	//     (hints 空 → 无 setProperty 双腿;select=0 → 不改 currentIndex)。
	kitWindowRestoreFirstPage(sl, &mwHost);
	if (sl.f58->count() != 3)
		++fails; // FUN_007665ae:Terminal 首页(s_HistoryHints "Terminal")
	if (sl.f58->currentIndex() != 0)
		++fails; // select=0 → setCurrentIndex 不触发(@0x766548 门)
	if (sl.f58->widget(2) == nullptr
	    || sl.f58->widget(2)->objectName() != QStringLiteral("TerminalWindow"))
		++fails; // 第三页 = TerminalWindow face(s_TerminalWindow_859902)
	if (sl.f58->widget(2) != nullptr && sl.f58->widget(2)->property("History").isValid())
		++fails; // hints=shared_null → 双 setProperty 跳过
	if (sl.f50->buttonForIndex(2) == nullptr)
		++fails; // addKit 第三记(FUN_008b346e)

	// d8. restore 无去重(语料 FUN_007665ae 无已存在检查)→ 二调再挂。
	kitWindowRestoreFirstPage(sl, &mwHost);
	if (sl.f58->count() != 4)
		++fails; // 二调再挂(语料幂等性缺省同相 — 不发明去重)

	// ======== 批 147:树深下钻真身(FUN_008a971e / s_FilterEdit_8a9d3c)========

	// d9. 夹具 yaml 真库装载 → children 树深度断言。夹具写 applicationDirPath()
	//     /editor/configs/(FUN_008a58f0 拼序实读:strace 008a58f0 →
	//     dir + "/" + selfName.toLower() + tail,tail 全段 "/configs/...")。
	{
		const QString cfgDir = QCoreApplication::applicationDirPath()
		                       + QStringLiteral("/editor/configs");
		QDir().mkpath(cfgDir);
		// 夹具 = 真配置形态(menu.config 顶层 map 序列 + Menu/Actions 三级
		// 树,与 terminal/configs/menu.config "Set Tab &Color" 同构;
		// toolbar.config Action Menu 腿同 terminal/configs/toolbar.config)。
		{
			QFile f(cfgDir + QStringLiteral("/menu.config"));
			f.open(QIODevice::WriteOnly | QIODevice::Truncate);
			f.write(
"- { \"Kit\" : [\n"
"    { \"Menu\" : \"Session\" },\n"
"    { \"Separator\" : true },\n"
"    { \"Menu\" : \"Hex &Base\", \"Actions\" : [\n"
"        { \"Action\" : \"Text.HexBaseBinary\" },\n"
"        { \"Separator\" : true } ] } ] }\n");
			f.close(); // 装载前落盘(QFile 析构在作用域尾 — 显式关)
		}
		{
			QFile f(cfgDir + QStringLiteral("/toolbar.confi")); // Views 腿 tail
			// 22 字符截断怪癖(FUN_008aa39e fromLatin1(tail,0x17-1) 原样)
			f.open(QIODevice::WriteOnly | QIODevice::Truncate);
			f.write(
"- { \"Standard\" : [\n"
"    { \"Action\" : \"Terminal.NewSession\", \"Menu\" : \"Open Recent\" },\n"
"    { \"Separator\" : true },\n"
"    { \"AddressBar\" : true } ] }\n");
			f.close();
		}
		CEditorConfigFace *cfg = CEditorConfigFace::instance();
		if (!cfg->loadGroups() || !cfg->loadViews())
			++fails; // S2 yaml_loadFile true 腿(@008a9a5d cVar5 透传)
		// d9a. Groups 树深:顶层 "Kit" → 二级 Menu(2)/Separator(0,名空)/
		//      Menu "Hex &Base" → 三级 "Actions"(Action 3/Sep 0)。
		if (cfg->m_groups.m_end - cfg->m_groups.m_begin != 1)
			++fails; // 顶层恰一组(FUN_008accc8 @008a9b2b)
		SharedConfigHandlerFace *kit = (cfg->m_groups.m_end ==
		    cfg->m_groups.m_begin) ? nullptr : cfg->m_groups.m_begin[0];
		if (kit == nullptr || kit->m_value.toString() != QStringLiteral("Kit"))
			++fails; // 组键 QVariant(FUN_006926c2 键面)
		if (kit != nullptr) {
			if (kit->m_end - kit->m_begin != 3)
				++fails; // 二级 3 元素(FUN_008a971e 序)
			SharedConfigHandlerFace **els = kit->m_begin;
			if (els[0]->m_value.toString() != QStringLiteral("Session")
			    || els[0]->kind() != 2)
				++fails; // Menu kind=2(@008a991c 低 nibble|2)
			if (!els[1]->m_value.toString().isEmpty() || els[1]->kind() != 0)
				++fails; // Separator 名空(@008a9943 clear)+ kind=0(@008a993e)
			if (els[2]->m_value.toString() != QStringLiteral("Hex &Base")
			    || els[2]->kind() != 2)
				++fails; // Menu 名 = "Menu" 键值(@008a9910-2b)
			if (els[2]->m_end - els[2]->m_begin != 2)
				++fails; // 三级 "Actions" 递归(@008a9990)
			SharedConfigHandlerFace **sub = els[2]->m_begin;
			if (els[2]->m_begin != nullptr) {
				if (sub[0]->m_value.toString()
				        != QStringLiteral("Text.HexBaseBinary")
				    || sub[0]->kind() != 3)
					++fails; // Action kind=3(@008a982c)+ 名键值
				if (!sub[1]->m_value.toString().isEmpty() || sub[1]->kind() != 0)
					++fails; // 三级 Separator 同腿
				if (sub[0]->m_parent != els[2])
					++fails; // 挂父写位(@008acc82 local_70[5]=param_2)
			}
		}
		// d9b. Views 树深:Action k=3 + popup 名/bit3 + Columns 内省;
		//      Separator k=0;AddressBar k=5 名空。
		if (cfg->m_views.m_end - cfg->m_views.m_begin != 1)
			++fails;
		SharedConfigHandlerFace *stdv = (cfg->m_views.m_end ==
		    cfg->m_views.m_begin) ? nullptr : cfg->m_views.m_begin[0];
		if (stdv == nullptr
		    || stdv->m_value.toString() != QStringLiteral("Standard"))
			++fails;
		if (stdv != nullptr) {
			if (stdv->m_end - stdv->m_begin != 3)
				++fails; // Action/Sep/AddressBar
			SharedConfigHandlerFace **els = stdv->m_begin;
			if (els[0]->m_value.toString() != QStringLiteral("Terminal.NewSession")
			    || els[0]->kind() != 3)
				++fails; // Action(@008a9dd4)
			if (els[0]->popupName() != QByteArrayLiteral("Open Recent")
			    || !els[0]->popupFlag())
				++fails; // Menu 名入值对象 +0x8 槽(@008a9e50-6c)+ bit3 置
			if (els[0]->columns() != 1)
				++fails; // 内省腿(@008a9eb8-f0):bit3 置名非空 → cVar1 =
			             //   (-((d7&8)==0)&2)+1 = (-(0)&2)+1 = 1(负零清零;
			             //   "Columns" 键缺省 0 → 内省腿替换)
			if (els[1]->m_value.toString() != QStringLiteral("true")
			    || els[1]->kind() != 0)
				++fails; // Separator kind=0;名 = 键值(s_FilterEdit @008aa218-38
			             //   asCString 腿 ≠ Groups 空名 — "true" 字面同相)
			if (els[2]->kind() != 5 || !els[2]->m_value.toString().isEmpty())
				++fails; // AddressBar k=5 名空(@008aa292)
		}
		QFile::remove(cfgDir + QStringLiteral("/menu.config"));
		QFile::remove(cfgDir + QStringLiteral("/toolbar.confi"));
	}

	// ======== 批 149:启动链 ========

	// s1. 链函数可调:FUN_007626ce 语料序(translator/配置读/恢复门/
	//     失败腿/singleShot 尾)— 恢复门 FUN_0075ffcc cited 占位返回
	//     "未恢复"同相 → 失败腿 kitWindowRestoreFirstPage 必走
	//     (无 pane → "Terminal" 首页,d5-d8 判例形态)。
	int before = sl.f58->count();
	startupChain(sl, &mwHost);
	if (sl.f58->count() != before + 1)
		++fails; // 失败腿 = 建 "Terminal" 首页(@007628a7 FUN_0075e3fe)
	if (sl.f58->widget(sl.f58->count() - 1) == nullptr
	    || sl.f58->widget(sl.f58->count() - 1)->objectName()
	       != QStringLiteral("TerminalWindow"))
		++fails; // 新页 = TerminalWindow face(s_TerminalWindow_859902)

	// s2. 恢复门失败同相:FUN_0075ffcc cited 占位恒 false → select=0
	//     (FUN_007665ae select=0)→ currentIndex 不被链改动(d7 判同)。
	if (sl.f58->currentIndex() != 0)
		++fails; // 链不改选页(@007628a5-ab 门腿同相)

	// ======== 批 150:e 组 — 恢复门真身(FUN_0075ffcc)+ 分发壳 ========

	// e1. 魔数不配 → first-page 腿:夹具文件魔数错(0xdeadbeef)→
	//     掩码门 false(@2842e else 腿)→ startupChain 走失败腿建
	//     "Terminal" 首页(s1 判同相)。
	{
		const QString hist = QCoreApplication::applicationDirPath()
		                     + QStringLiteral("/global/reopen.history"); // @005dd570 拼序
		QDir().mkpath(QFileInfo(hist).absolutePath()); // cfg_ensureProfileDir mkpath 腿
		QByteArray fakeBlob;
		{
			QDataStream w(&fakeBlob, QIODevice::WriteOnly);
			w << quint32(0xdeadbeefu);          // 魔数不配(掩码门挡)
		}
		QFile f(hist);
		f.open(QIODevice::WriteOnly | QIODevice::Truncate);
		f.write(fakeBlob);
		f.close();
		const int beforeE1 = sl.f58->count();
		if (startupRestoreGate(sl, &mwHost, hist))
			++fails; // 魔数不配 → 门 false(@2842e else 腿)
		if (sl.f58->count() != beforeE1)
			++fails; // 门 false 不挂页(直接返 false,链外走 first-page)
		// 链级同相:s2 后链已跑过一次(状态文件此时在)—— startupChain
		// 缺省 historyPath = appdir/global/reopen.history;此刻魔数不配
		// → 失败腿再挂一页(first-page 判例 d8 幂等缺省同相)。
		const int beforeChain = sl.f58->count();
		startupChain(sl, &mwHost); // 门 false → FUN_0075e3fe 再挂首页
		if (sl.f58->count() != beforeChain + 1)
			++fails; // 魔数不配 → first-page 腿(@007628a7)
	}

	// e2. 魔数配 + payload 合法 → 恢复分发可达(壳级):b9e7e600 魔数 +
	//     1 窗(geometry 空 + payload 页名 "Terminal")→ 门 true +
	//     分发壳页挂(attachPage 面,terminalConfigAsFace 已缓存)。
	{
		QByteArray payload;
		{
			QDataStream w(&payload, QIODevice::WriteOnly);
			w << quint32(1)      // 页数 local_c8
			  << quint32(0)      // currentIndex local_c4
			  << QString(QStringLiteral("Terminal")) // 页名(@008c9e64 面)
			  << QByteArray();   // 页 payload 空(local_b8)
		}
		QByteArray blob;
		{
			QDataStream w(&blob, QIODevice::WriteOnly);
			w << quint32(0xb9e7e600u) // 魔数恰等(掩码门过)
			  << quint32(1)           // 窗数 local_74
			  << QByteArray()         // geometry 空(shared_null 同相)
			  << payload;             // 窗 payload
		}
		const QString hist = QCoreApplication::applicationDirPath()
		                     + QStringLiteral("/global/reopen.history");
		QFile f(hist);
		f.open(QIODevice::WriteOnly | QIODevice::Truncate);
		f.write(blob);
		f.close();
		const int beforeE2 = sl.f58->count();
		if (!startupRestoreGate(sl, &mwHost, hist))
			++fails; // 魔数配 + count=1 → 门 true(local_91)
		if (sl.f58->count() != beforeE2 + 1)
			++fails; // 分发壳页挂 1 页(s_HistoryHints @33637)
		QWidget *restoredPage = sl.f58->widget(sl.f58->count() - 1);
		if (restoredPage == nullptr
		    || restoredPage->objectName() != QStringLiteral("TerminalWindow"))
			++fails; // 页名 "Terminal" → 工厂 Terminal 腿(@0089d7df)
	}

	// ======== 批 154:f 组 — 工作区装载器 + 启动余量 ========

	// f1. sessionByUuid(810056 对位):空 uuid → 空 map(@0081016d);
	//     命中腿/未命中腿(@00810230/LAB_0081015f)。
	{
		QVariantList lib;
		QVariantMap a; a.insert(QStringLiteral("session.uuid"),
		                        QStringLiteral("u-1"));
		QVariantMap b; b.insert(QStringLiteral("session.uuid"),
		                        QStringLiteral("u-2"));
		lib << a << b;
		if (!Workspace::sessionByUuid(lib, QString()).isEmpty())
			++fails; // 空 uuid → 空(@0081016d)
		if (Workspace::sessionByUuid(lib, QStringLiteral("u-2"))
		        .value(QStringLiteral("session.uuid")).toString()
		    != QStringLiteral("u-2"))
			++fails; // 命中返回元素(@00810230)
		if (!Workspace::sessionByUuid(lib, QStringLiteral("nope")).isEmpty())
			++fails; // 未命中 → 空(LAB_0081015f)
	}

	// f2. workspaceLoader(522056 骨架):title trimmed(@005220c0);
	//     三件套 text+data → data 键、null → uuid 键、缺一不落
	//     (@0052340a 门);kind 位 Terminal/Browser=7 else 3
	//     (@005224c5);去重(QHash 命中早退 @0052254d)。
	{
		QVariantList lib;
		QVariantMap s1; s1.insert(QStringLiteral("session.uuid"),
		                         QStringLiteral("u1"));
		s1.insert(QStringLiteral("text"), QStringLiteral("t1"));
		s1.insert(QStringLiteral("data"), QStringLiteral("d1"));
		QVariantMap s2; s2.insert(QStringLiteral("session.uuid"),
		                         QStringLiteral("u2"));
		QVariantMap s3; s3.insert(QStringLiteral("session.uuid"),
		                         QStringLiteral("u3"));
		s3.insert(QStringLiteral("text"), QStringLiteral("t3")); // 缺 data
		lib << s1 << s2 << s3;
		QString title = QStringLiteral("  pad  ");
		Workspace::LoaderResult r =
		    Workspace::workspaceLoader(nullptr, nullptr, title, lib);
		if (title != QStringLiteral("pad"))
			++fails; // trimmed 换写(@005220c0)
		if (r.keys.size() != 2 || r.kinds.size() != 2)
			++fails; // s1→data 键 / s2→uuid 键 / s3 缺 data 不落(3 项)
		if (!r.keys.contains(QStringLiteral("d1"))
		    || !r.keys.contains(QStringLiteral("u2")))
			++fails; // 键面(data 优先 / uuid 回退 @005235d1/00522620)
		if (r.kinds.contains(7))
			++fails; // pane=null → 非 Terminal/Browser 腿 kind=3(@005224c5)
	}

	// f3. kitScopedConfigValue(FUN_008cba1c + 00760b2c 键面):kit.
	//     前缀剥除(^kit(?=\.) @00760bf1);缺省透传(global_setting_get
	//     未命中 → 缺省直返同相)。
	if (kitScopedConfigValue(QStringLiteral("TerminalWindow"),
	                         QByteArrayLiteral("kit.startupSessions"),
	                         QStringLiteral("LastSessions"))
	    != QStringLiteral("LastSessions"))
		++fails; // 键剥前缀后配置未命中 → 缺省 "LastSessions"
	             //   (@008d3685 缺省腿;真配置缺 kit.* 键 — 实机对证)

	// f4. startupWindowCreate(FUN_0075e0f8 窄面):geometry 空 →
	//     居中缩放腿(resize/move 落位非零窗)+ 产物 QMainWindow 基面
	//     (语料 MainWindow 0xf0 未建模 — KitWindowFace 抽象不可实例化,
	//     铁律 6 退基面)。
	{
		QMainWindow *w = startupWindowCreate(&mwHost, QByteArray());
		if (w == nullptr)
			++fails; // 建窗产物非空(@0075e11a)
		else
			delete w;
		QMainWindow *w2 =
		    startupWindowCreate(&mwHost, QByteArrayLiteral("junk"));
		if (w2 == nullptr)
			++fails; // geometry 非空腿(restoreGeometry 失败 → 居中腿
			         //   同相产物 @0075e13a-2c0)
		else
			delete w2;
	}

	// f5. startupWindowTail(&4 尾段 @00766f22-6fb0):全屏/置顶/透明度
	//     四读面消费不崩(读游推进 = 语料同相;X11 置顶腿 cited 平台域)。
	{
		QByteArray tail;
		{
			QDataStream w(&tail, QIODevice::WriteOnly);
			w << QByteArray();   // subBlob(@00766f22)
		}
		QByteArray blob;
		{
			QDataStream w(&blob, QIODevice::WriteOnly);
			w << tail;
		}
		QDataStream in(blob);
		startupWindowTail(&mwHost, in); // 空子流:bool/QByteArray/bool/
		                                //   double 读全失败腿(atEnd →
		                                //   零值缺省,不崩同相)
	}

	// f6. 批 159 收集面:collectorPaneTypeName(8c9e64)/
	//     collectorEditorFilePaths(8d0cf2)/collectorMuxChildren
	//     (8d097c)/sessionProtocolUrl(810d6e URL 拼面)。
	{
		// 8c9e64:objectName 去 "Window"(fromAscii "Window" 实读)
		QObject named;
		named.setObjectName(QStringLiteral("TerminalWindow"));
		if (Workspace::collectorPaneTypeName(&named)
		    != QStringLiteral("Terminal"))
			++fails; // "TerminalWindow"→"Terminal" @008c9e86-a4
		if (!Workspace::collectorPaneTypeName(nullptr).isEmpty())
			++fails; // param_1!=0 门 @00522288(workspaceLoader 侧卫)
		QObject plain;
		plain.setObjectName(QStringLiteral("Browser"));
		if (Workspace::collectorPaneTypeName(&plain)
		    != QStringLiteral("Browser"))
			++fails; // 无 "Window" 尾 → 原样 @008c9e9c remove miss

		// 8d0cf2 Editor 收集器(批 162 对位修正:收集 = TabGroup stack
		//   页族,plain pane → 空表;fixture 改 stack 页承载)
		MuxPaneGroup edPane(true, nullptr);
		QWidget withPath;
		withPath.setWindowTitle(QStringLiteral("t"));
		withPath.setWindowFilePath(QStringLiteral("/tmp/wt-f6.txt"));
		if (edPane.tabGroup() == nullptr || edPane.tabGroup()->stack() == nullptr)
			++fails;
		else
			edPane.tabGroup()->stack()->addWidget(&withPath);
		QWidget noPath(&edPane); // 非 stack 页 → 不收(页族直读同相)
		const QList<QString> paths =
		    Workspace::collectorEditorFilePaths(&edPane);
		if (paths.size() != 1 || paths.first()
		    != QStringLiteral("/tmp/wt-f6.txt"))
			++fails;

		// 8d097c Terminal 收集器(批 162 对位修正:stack 页族直读,
		//   008b9b2a/008b9890;非 TabGroup pane → 空表零判同相)
		if (!Workspace::collectorMuxChildren(&edPane,
		                                     QStringLiteral("Terminal"), false)
		         .isEmpty())
			++fails; // 非 group pane → 空表(语料 +0x38 直读空同相)
		if (!Workspace::collectorMuxChildren(nullptr, QString(), false)
		         .isEmpty())
			++fails; // null pane → 空
		// 嵌套页夹具(批 162 对位实测):stack 页族直收,页内嵌套
		//   splitter 子件不收(008b9890 逐页 = stack.widget(i) 直收)
		{
			MuxPaneGroup fgrp(true, nullptr);
			QWidget *p1 = new QWidget;
			fgrp.addTab(new MuxPaneView(nullptr, MuxPaneType(1) /*TypeTerminal*/),
			            false);
			QWidget *nested = new QWidget;
			QSplitter *nsp = new QSplitter(nested);
			(void)nsp;
			// 页挂 = TabGroup stack 直插(stack() 页族同相)
			QWidget *p2 = new QWidget;
			if (fgrp.tabGroup() == nullptr || fgrp.tabGroup()->stack() == nullptr)
				++fails;
			else {
				fgrp.tabGroup()->stack()->addWidget(p1);
				fgrp.tabGroup()->stack()->addWidget(nested);
				fgrp.tabGroup()->stack()->addWidget(p2);
				const QList<QWidget *> got = Workspace::collectorMuxChildren(
				    &fgrp, QString(), false);
				if (got.size() != 4)
					++fails; // 页族 = pane 页 + 3 直挂页;嵌套 splitter
				             //   子件不收(008b9890 逐页直收)
			}
		}

		// 810d6e protocol URL 拼面:protocol://target(:port 非默认)
		//   + " / " label 腿(@008110ae)+ toLower 尾(@008112ac)。
		QVariantMap s1;
		s1.insert(QStringLiteral("session.protocol"),
		          QStringLiteral("SSH"));
		s1.insert(QStringLiteral("session.target"),
		          QStringLiteral("host.example"));
		s1.insert(QStringLiteral("session.port"), 22);
		// SSH:22 缺省腿(@0081137f)→ 无 :port
		if (Workspace::sessionProtocolUrl(s1)
		    != QStringLiteral("ssh://host.example"))
			++fails; // SSH 默认 22 省略腿 @0081137f-a8
		s1.insert(QStringLiteral("session.port"), 2222);
		if (Workspace::sessionProtocolUrl(s1)
		    != QStringLiteral("ssh://host.example:2222"))
			++fails;
		s1.insert(QStringLiteral("session.port"), 23);
		s1.insert(QStringLiteral("session.protocol"),
		          QStringLiteral("telnet"));
		if (Workspace::sessionProtocolUrl(s1)
		    != QStringLiteral("telnet://host.example"))
			++fails;
		s1.insert(QStringLiteral("session.port"), 2223);
		s1.insert(QStringLiteral("session.label"),
		          QStringLiteral("mylab"));
		const QString withLabel = Workspace::sessionProtocolUrl(s1);
		if (!withLabel.contains(QStringLiteral(" / mylab")))
			++fails;
		if (withLabel != withLabel.toLower())
			++fails; // toLower 尾 @008112ac
		// 组腿:group 非空 → group/target 拼腿(@00811168)
		QVariantMap s2;
		s2.insert(QStringLiteral("session.protocol"),
		          QStringLiteral("SSH"));
		s2.insert(QStringLiteral("session.group"),
		          QStringLiteral("Servers"));
		s2.insert(QStringLiteral("session.target"),
		          QStringLiteral("h1"));
		if (Workspace::sessionProtocolUrl(s2)
		    != QStringLiteral("ssh://servers/h1"))
			++fails;
	}

	// f7. session_defaultDir 参数卫面(521702 批 159):kind 分派
	//     标量腿(applet 尾 2.0 腿/kind<=3 separator 腿)— 批 163 起
	//     键值域真身 sessionDefaultDirTrie(返回恒 1 卫面同相:kind
	//     标量腿已并入 522056 调用侧;此处断言恒 1 + trimmed 腿)。
	{
		QString d = QStringLiteral("/opt/my.applet");
		if (!Workspace::sessionDefaultDirTrie(QStringLiteral("Terminal"),
		                                      d, QVariant(), 1))
			++fails; // 卫恒 1 同相(@00521733 guard 空表腿)
		QString d2 = QStringLiteral("  /home/u/term  ");
		if (!Workspace::sessionDefaultDirTrie(QStringLiteral("Terminal"),
		                                      d2, QVariant(), 2))
			++fails;
		if (d2 != QStringLiteral("/home/u/term"))
			++fails; // trimmed_helper 原位腿 @00521957
		QString d3;
		if (!Workspace::sessionDefaultDirTrie(QStringLiteral("Terminal"),
		                                      d3, QVariant(), 8))
			++fails; // kind=8 → CMP 7 JA 腿(@00521e92)直入 trie 腔
			         //   → 正常返 1(0xc89127 bad-instruction 段
			         //   = switch 表内不可达域,批 159 面勘正)
	}

	// f8. kitStartupSessions splitter 段消费接线(批 158):splitter 布局
	//     段读游真身(页数头 int + 尾 restoreState 段)+ states 表逐项
	//     读游(@008d3380-9d);挂页腿宿主槽 cited(同相);空 payload/
	//     非 flags&1 门面复验(批 154 已守读游推进,此处防回归)。
	{
		QByteArray s6;
		{
			QDataStream w(&s6, QIODevice::WriteOnly);
			w << quint32(0xb9e7e623u); // version(现行写侧 ≥ 门)
			w << QByteArray();         // splitter 布局段(空表,读游直过)
			w << QByteArray();         // states 表段
		}
		QWidget s6Host;
		if (!kitStartupSessions(&s6Host, s6, 1u))
			++fails; // 空 splitter 段:读游消费直过 → return 1(@008d3c17)
	}

	// f9. 批 163:trie 键值域(StrTrie/0052674a 承载面)+ 掩盖腿
	//     (8061a0/8062b6)+ 挂页宿主槽(8d2e46 面)。
	{
		// strtrie_find_qv 承载面:命中返槽值/未命中插入返零
		//   (@0052677f 线性扫 + @00526804 插入腿)。
		Workspace::StrTrie t; // cpp 侧 StrTrie(WorkspaceLoader.h 文档注记块已删)
		bool ins = false;
		if (!t.find0052674a(0x101u, QVariant(7), &ins).isNull() || !ins)
			++fails; // 首查未命中 → 零值 + inserted=1(@00526804)
		if (t.find0052674a(0x101u, QVariant(9), &ins) != QVariant(7) || ins)
			++fails; // 二查命中 → 槽值 7(@0052677f 命中面)
		// 键升序不变量(右移批插直译 — QMap 序承载同相)
		t.find0052674a(0x103u, QVariant(), &ins);
		t.find0052674a(0x0u, QVariant(), &ins);
		QList<quint32> ks = t.cells.keys();
		if (ks != (QList<quint32>() << 0u << 0x101u << 0x103u))
			++fails; // 升序(@0052645c 右移批插直译)

		// sessionDefaultDirTrie(521702 trie 腔):trimmed 腿 @00521957。
		QString dd = QStringLiteral("  /opt/x  ");
		if (!Workspace::sessionDefaultDirTrie(QStringLiteral("Terminal"),
		                                      dd, QVariant(), 1))
			++fails;
		if (dd != QStringLiteral("/opt/x"))
			++fails; // trimmed_helper 原位腿 @00521957

		// 8061a0 掩盖腿:'@' 后 → '*'(i-1 次);i<=1 → 原样。
		QVariantMap m1;
		m1.insert(QStringLiteral("session.target"),
		          QStringLiteral("user@host.example"));
		if (Workspace::sessionTargetMasked(m1, true)
		    != QStringLiteral("u***@host.example"))
			++fails; // replace(1,i-1,'*'×(i-1))@00806255-f1
		             //   (i=4 → 3 星)
		if (Workspace::sessionTargetMasked(m1, false)
		    != QStringLiteral("user@host.example"))
			++fails; // param_4=0 → 原样 @00806229
		QVariantMap m2;
		m2.insert(QStringLiteral("session.target"),
		          QStringLiteral("plainhost"));
		if (Workspace::sessionTargetMasked(m2, true)
		    != QStringLiteral("plainhost"))
			++fails; // 无 '@'(idx=-1)→ 原样腿
		QVariantMap m3;
		m3.insert(QStringLiteral("session.target"),
		          QStringLiteral("a@b"));
		if (Workspace::sessionTargetMasked(m3, true)
		    != QStringLiteral("a@b"))
			++fails; // i==1 不 >1 → 原样 @0080623a 门

		// 8062b6 label 腿:空 → target 覆盖;非空 → 原样。
		QVariantMap m4;
		m4.insert(QStringLiteral("session.target"),
		          QStringLiteral("u@h"));
		if (Workspace::sessionLabelOrTarget(m4, true)
		    != QStringLiteral("u@h"))
			++fails; // label 空 → target 覆盖 @0080634b
		m4.insert(QStringLiteral("session.label"), QStringLiteral("L"));
		if (Workspace::sessionLabelOrTarget(m4, true)
		    != QStringLiteral("L"))
			++fails; // label 非空 → 原样 @00806346

		// protocol URL 面掩盖腿同相:target 含 '@' → URL 已脱敏。
		QVariantMap m5;
		m5.insert(QStringLiteral("session.protocol"),
		          QStringLiteral("SSH"));
		m5.insert(QStringLiteral("session.target"),
		          QStringLiteral("secret@corp.io"));
		m5.insert(QStringLiteral("session.port"), 22);
		const QString u = Workspace::sessionProtocolUrl(m5);
		if (u != QStringLiteral("ssh://s*****@corp.io"))
			++fails; // 8061a0 真腿入 URL(@00810dce 消费;i=6 → 5 星)

		// tabBarSelectionBehaviorOnRemove(89f516 面):配置未命中
		//   → 2 字面(缺省键值 @0089f54x)。
		if (tabBarSelectionBehaviorOnRemove() != 2)
			++fails;

		// kitStartupOpenSession(8d2e46 宿主槽面):命中 → 页挂产物;
		//   未知名 → null(@0089e92x 尾 0)。
		MainWindowFace::Slots emptySlots{nullptr, nullptr};
		if (kitStartupOpenSession(emptySlots, &mwHost,
		                                     QStringLiteral("Nope"),
		                                     QStringLiteral("s"), false)
		    != nullptr)
			++fails; // 工厂未中腿 → null(sub_89e8de 未中同相)
		QWidget *pg = kitStartupOpenSession(
		    emptySlots, &mwHost, QStringLiteral("Editor"),
		    QStringLiteral("s"), false);
		if (pg == nullptr)
			++fails; // 命中腿产物非 null(空宿主槽 → 跳挂页同相)
		else
			delete pg; // 工厂产物自持(未入 stack — 测试消偿)
	}

	delete edW;
	delete buyW;

	// ======== 批 169:f 组尾 — kit.startupSessions 写端 + profiles.config 写侧 ========

	// f10. s_kit_startupSessions_6e6e75 三态键值映射(@006e6f81 首钮
	//      "SpecificSessions" / @006e6ee0 次钮 "NoSessions" / @006e6f29
	//      末钮 "LastSessions";三钮皆假 → LAB_006e6f8e 直过不写)+ 键
	//      归一面(8cbb2e→760b2c:toLower + 剥 "kit" 段)。键形怪癖
	//      注记:语料 regex "^kit(?=\.)" lookahead 零宽,QString::
	//      replace 语义 Qt 实测吞 "kit" 留 "."(".startupsessions"),
	//      但库内 replace(QRegularExpression)重载连 "." 同吞
	//      (Qt5.15.13 实测 "startupsessions")— 写(8cbb2e)读
	//      (8cba1c)两通路同 regex 同形键,对称闭环成立;恢复分发
	//      &4 门批 150/154 kitStartupSessions 腿消费同键。
	{
		CTerminalConfig *cfg = CTerminalConfig::instance();
		cfg->setConfigPath(QStringLiteral("/nonexistent/wind.config"));
		cfg->setValue(QStringLiteral("startupsessions"),
		              QStringLiteral("preset")); // 前置观测基线
		cfg->setValueKitScoped(QByteArrayLiteral("kit.startupSessions"),
		                       QStringLiteral("probe"));
		cfg->setStartupSessions(false, true, false);
		if (cfg->value(QStringLiteral("startupsessions"))
		    != QStringLiteral("NoSessions"))
			++fails; // 次钮腿 @006e6ee0
		// 键落位同相:kit.* 裸键不落(键面归一 @00760b86/bf1)。
		if (cfg->contains(QStringLiteral("kit.startupSessions")))
			++fails;
		cfg->setStartupSessions(true, false, false);
		if (cfg->value(QStringLiteral("startupsessions"))
		    != QStringLiteral("SpecificSessions"))
			++fails; // 首钮腿 @006e6f81
		cfg->setStartupSessions(false, false, true);
		if (cfg->value(QStringLiteral("startupsessions"))
		    != QStringLiteral("LastSessions"))
			++fails; // 末钮腿 @006e6f29
		cfg->setStartupSessions(false, false, false);
		if (cfg->value(QStringLiteral("startupsessions"))
		    != QStringLiteral("LastSessions"))
			++fails; // 三钮皆假 → 不写(LAB_006e6f8e 直过,值保持)
		// 键面归一验证:大写 "KIT.StartupSessions" 同相落位
		//   (toLower @00760b86;写 8cbb2e 面 ↔ 读 8cba1c 面同 regex
		//   闭环)。
		cfg->setValueKitScoped(QByteArrayLiteral("KIT.StartupSessions"),
		                       QStringLiteral("LastSessions"));
		if (cfg->value(QStringLiteral("startupsessions"))
		    != QStringLiteral("LastSessions"))
			++fails;
	}

	// f11. profiles.config 写侧 roundtrip(s_profiles_config_5d8c30 写 +
	//      5d8732 读对称):写目录 → "path" 回写 → 读面(StartupChain
	//      startupProfileDir 同相解析;fold:"~" ↔ homePath 双向)。测试
	//      applicationDirPath 锚定(appdir/profiles.config)→ 测试树
	//      build/tests 内写;读侧对账 = root["path"] 直读(5d8732 面
	//      解析同构;读侧真身 StartupChain::startupProfileDir 在库,
	//      appdir 锚定不可注家目录 — 机制对账已足)。
	{
		const QString home = QDir::homePath();
		// 归一腿:不存在目录 → "."(0xc9dabd)
		{
			QFile c(QCoreApplication::applicationDirPath()
			        + QStringLiteral("/profiles.config"));
			c.remove(); // 基线清(测试树共享段顺序稳态)
		}
		if (!ProfileLoader(QStringLiteral("/tmp/wt-b169-fake"))
		        .saveConfigPath(QStringLiteral("/no/such/dir"), QString()))
			++fails; // 缺目录 → 缺省 "." 回写仍成功(@005d8cf9)
		{
			QFile c(QCoreApplication::applicationDirPath()
			        + QStringLiteral("/profiles.config"));
			if (!c.open(QIODevice::ReadOnly))
				++fails; // config_saveFile 产物存在(写侧 open 失败腿外)
			else {
				const QByteArray raw = c.readAll();
				Json::Value root;
				Json::CharReaderBuilder b;
				std::unique_ptr<Json::CharReader> r(b.newCharReader());
				std::string errs;
				if (!r->parse(raw.constData(), raw.constData() + raw.size(),
				              &root, &errs)
				    || !root.isObject()
				    || root["path"].asString() != ".")
					++fails; // "path"="."(@005d8cf9 缺省腿 + @005d8e94 赋值)
			}
		}
		// homePath 折叠腿(@005d8f99 "~"):写入 → 读回替换(目录实存
		//   fixture — QDir::exists 门 @005d8cf9 真腿)
		QDir().mkpath(home + QStringLiteral("/sub"));
		if (!ProfileLoader(QStringLiteral("/tmp/wt-b169-fake"))
		        .saveConfigPath(home + QStringLiteral("/sub"), QString()))
			++fails; // saveConfigPath 成功腿
		{
			QFile c(QCoreApplication::applicationDirPath()
			        + QStringLiteral("/profiles.config"));
			if (!c.open(QIODevice::ReadOnly))
				++fails; // 回写产物可读
			else {
				const QByteArray raw = c.readAll();
				Json::Value root;
				Json::CharReaderBuilder b;
				std::unique_ptr<Json::CharReader> r(b.newCharReader());
				std::string errs;
				if (!r->parse(raw.constData(), raw.constData() + raw.size(),
				              &root, &errs)
				    || root["path"].asString() != "~/sub")
					++fails; // homePath → "~" 折叠(@005d8f99;读侧 5d8732
					         //   "~" 前缀 homePath 插入对称腿 @005d88d4)
			}
		}
		// 同值短路(@005d8ca6):oldDir == 规范化入参 → 不触摸文件。
		//   mtime 前后判不可靠(同秒粒度),改 size+content 双证:短路腿
		//   直返,文件字节不重写。
		{
			const QString cfgFile = QCoreApplication::applicationDirPath()
			                        + QStringLiteral("/profiles.config");
			QFile c(cfgFile);
			c.open(QIODevice::ReadOnly);
			const QByteArray before = c.readAll();
			c.close();
			if (!ProfileLoader(QStringLiteral("/tmp/wt-b169-fake"))
			        .saveConfigPath(home + QStringLiteral("/sub"),
			                        QStringLiteral("~/sub")))
				++fails;
			c.open(QIODevice::ReadOnly);
			if (c.readAll() != before)
				++fails; // 短路 → 文件未重写(@005d8ca6 直返)
		}
		// 读侧对称确认(5d8732 真身 = StartupChain::startupProfileDir,
		//   static 面):appdir 锚定无法注家目录 — 机制面已由 f11 直读
		//   对账,读侧解析腿("~"→homePath 插入 @005d88d4)真身在库。
	}

	// f12. 批 171:user.sessions 序列化同构 roundtrip(config_saveFile
	//      底座 00a801c6 → 00aef8c0 → 00d38620 vtable[2]=00afc1b0)。
	//      语料形态断言:缩进 4 空格(FUN_00af8810 0035.c:73112 流态
	//      0x40000004a,+0x34=4 asm 0xaef849 实读)/ 键值 " : " 分隔
	//      (json_toStream 00afb830 0035.c:75489)/ 中文原样 UTF-8
	//      (jsoncpp_writeString 00afa810 0035.c:74563 全 >0x1f raw
	//      直包,无 \uXXXX 深转义)/ 尾换行(FUN_00afc1b0 @00afc1d6
	//      append "\n")/ 顶层数组-of-对象三层嵌套(json_toStream
	//      case7 + FUN_00afc4f0 case6 实证形态)。键序差 cited 登记
	//      (jsoncpp 字典序 vs 原版 FUN_00af34a0 插入序;读回等价)。
	{
		int f12 = 0; // 本地细分(诊断后收敛)
		const QString prof = QStringLiteral("/tmp/wt-b171-fake");
		QVariantList lib;
		{
			QVariantMap s;
			s.insert(QStringLiteral("session.uuid"),
			         QStringLiteral("u-171-a"));
			s.insert(QStringLiteral("session.label"),
			         QStringLiteral("中文终端"));          // raw UTF-8 腿
			s.insert(QStringLiteral("session.host"),
			         QString());                            // 空串腿
			s.insert(QStringLiteral("session.port"), 3023);
			s.insert(QStringLiteral("session.keepAlive"), true);
			lib.append(s);
		}
		{
			QVariantMap s;
			s.insert(QStringLiteral("session.uuid"),
			         QStringLiteral("u-171-b"));
			s.insert(QStringLiteral("session.label"),
			         QStringLiteral("β-portçais"));        // 非 BMP 外多字节
			s.insert(QStringLiteral("session.port"), 22);
			lib.append(s);
		}
		if (!ProfileLoader(prof).saveSessions(lib))
			++f12; // 写腿成功(config_saveFile 同相返回 1 @00a803b4)
		QFile f(prof + QStringLiteral("/terminal/user.sessions"));
		if (!f.open(QIODevice::ReadOnly))
			++f12;
		else {
			const QByteArray raw = f.readAll();
			if (!raw.startsWith("[\n"))
				++f12; // 顶层 [ 直落(无 BOM;ofstream 直写同相)
			if (!raw.contains("\n    {"))
				++f12; // 数组元素缩进 4 空格(FUN_00af8a00 缩进串)
			if (!raw.contains("\"session.label\" : \"中文终端\""))
				++f12; // " : " 分隔 + 中文原样(00afa810 raw 直包)
			if (raw.contains("\\u"))
				++f12; // 无 \uXXXX 深转义(emitUTF8 同相)
			if (!raw.contains("\"session.host\" : \"\""))
				++f12; // 空串落 ""(jsoncpp_writeString 空引号腿)
			if (!raw.contains("\"session.port\" : 3023")
			    || !raw.contains("\"session.keepAlive\" : true"))
				++f12; // 数字/布尔字面(json_toStream case2/5)
			if (!raw.endsWith("]\n"))
				++f12; // 尾换行(FUN_00afc1b0 @00afc1d6;顶层数组 → ]\n)
			// 读回对账(loadSessions 承载替)
			const QVariantList back = ProfileLoader(prof).loadSessions();
			if (back.size() != 2)
				++f12;
			else {
				const QVariantMap a = back.at(0).toMap();
				if (a.value(QStringLiteral("session.label"))
				        != QStringLiteral("中文终端")
				    || !a.value(QStringLiteral("session.host"))
				            .toString().isEmpty()
				    || a.value(QStringLiteral("session.port")).toInt() != 3023
				    || !a.value(QStringLiteral("session.keepAlive")).toBool())
					++f12; // 中文/空串/int/bool 读回同相
				if (back.at(1).toMap()
				        .value(QStringLiteral("session.label"))
				        != QStringLiteral("β-portçais"))
					++f12; // 多字节读回
			}
		}
		// saveConfigPath 同底座同构(批 169 f11 产物形态复核):
		//   "path" : "~" 4 空格缩进 + 尾 \n(原版 profiles.config 样本)
		if (!ProfileLoader(QStringLiteral("/tmp/wt-b171-fake"))
		        .saveConfigPath(QDir::homePath() + QStringLiteral("/sub"),
		                        QString()))
			++f12;
		{
			QFile c(QCoreApplication::applicationDirPath()
			        + QStringLiteral("/profiles.config"));
			if (c.open(QIODevice::ReadOnly)) {
				const QByteArray raw = c.readAll();
				if (!raw.contains("\"path\" : \"~/sub\"") || !raw.endsWith("\n"))
					++f12; // " : " + 尾 \n(原版样本同相;homePath 折叠
					       //   腿 @005d8f99 与批 169 f11 同串)
			}
		}
		fails += f12;
	}

	// f12. 批 171:user.sessions 序列化同构 roundtrip(config_saveFile
	//      00a801c6 底座 FUN_00aef8c0→00afc1b0 序;4 空格缩进/" : "分隔
	//      /中文 raw UTF-8/尾 \n;00806958 写者面)。中文/嵌套/空串
	//      sessions → save → 格式断言 → load 对账。
	{
		QVariantList sessions;
		QVariantMap a;
		a.insert(QStringLiteral("session.label"),
		         QStringLiteral("中文会话"));          // 非 ASCII raw 腿
		a.insert(QStringLiteral("session.target"),
		         QStringLiteral("host中文"));          // 串内中文
		a.insert(QStringLiteral("session.port"), 2222);
		QVariantMap b;
		b.insert(QStringLiteral("session.label"), QString()); // 空串腿
		b.insert(QStringLiteral("nested.sub"), true); // 点号键(平铺)
		sessions << a << b;
		const QString dir = QStringLiteral("/tmp/wt-b171-fixture");
		ProfileLoader pl(dir);
		QDir().mkpath(dir + QStringLiteral("/terminal"));
		if (!pl.saveSessions(sessions))
			++fails; // 00806958 +0x1c 槽写者成功腿
		QFile f(dir + QStringLiteral("/terminal/user.sessions"));
		if (!f.open(QIODevice::ReadOnly))
			++fails;
		else {
			const QByteArray raw = f.readAll();
			// 格式断言(config_saveFile 底座序):4 空格缩进 + " : " +
			//   尾 \n + 中文 raw UTF-8(非 \uXXXX 转义)
			if (!raw.startsWith("["))
				++fails; // 数组根(json_toStream case6/7 面)
			if (!raw.contains("\n        \"session.label\" : "))
				++fails; // 缩进 4 空格/层(00af8a00;数组根 → 元素 2 层
				             //   = 8 空格。语料直接标量缩进腿同参)+
				             //   " : "(00afbc26 段)
			if (!raw.endsWith("\n"))
				++fails; // 尾 \n(00afc1b0 尾 append 0xca995c=0x0a 实读)
			if (!raw.contains("\"中文会话\""))
				++fails; // 中文 raw UTF-8(00afa810:>0x1f 逐字节 raw
			             //   直包,无 \u 转义腿)
			if (raw.contains("\\u"))
				++fails; // \uXXXX 转义缺席(raw 直包同相)
			// load 对账(loadSessions 读侧对称;空串/点号键/端口三型)
			const QVariantList back = pl.loadSessions();
			if (back.size() != 2)
				++fails;
			else {
				const QVariantMap ra = back.first().toMap();
				if (ra.value(QStringLiteral("session.label"))
				        != QStringLiteral("中文会话")
				    || ra.value(QStringLiteral("session.target"))
				        != QStringLiteral("host中文")
				    || ra.value(QStringLiteral("session.port")).toInt()
				        != 2222)
					++fails; // 中文往返 + int 型(00afa810 raw 直包 +
					         //   loadSessions asInt 腿)
				const QVariantMap rb = back.last().toMap();
				if (!rb.contains(QStringLiteral("session.label"))
				    || rb.value(QStringLiteral("session.label"))
				           .toString()
				           != QString())
					++fails; // 空串往返(00afa810 "\"\"" 腿同相)
				if (!rb.contains(QStringLiteral("nested.sub")))
					++fails; // 点号键平铺往返(jsoncpp string 键)
			}
		}
	}

	// f13. 批 174:wind.config 复合缺口承载 + user.sessions 样本对表。
	//      五复合缺口(yaml_toQVariant FUN_00a7ecde 全型面):数组→
	//      QVariantList(case6 @00a7ed2d)/对象→QVariantMap(case7
	//      @00a7edd0)/null→miss 链不落(FUN_00a7fe9a @00a7ff03 json_
	//      isNullType → 下一源/缺省)。样本对表:tools/re/phase5/5c/
	//      original/user.sessions(原版 22863B,49 条目 24 键全标量,
	//      od 实证 [\n + 4 空格逐层 + " : " + 尾 ]\n)↔ 我方 saveSessions
	//      f12 产物框架同相(缩进/分隔/UTF-8/尾 \n;键序差 cited D3)。
	{
		CTerminalConfig *cfg = CTerminalConfig::instance();
		cfg->setConfigPath(QStringLiteral("/nonexistent/b174-wind.config"));
		cfg->setOverridePath(QString());
		cfg->reload();
		// 一、复合值承载(yaml_toQVariant 消费面现无 → 承载档)
		cfg->setValue(QStringLiteral("application.searchEngines"),
		              QVariant(QVariantList{
		                  QVariantMap{{QStringLiteral("text"),
		                               QStringLiteral("Google")}}}));
		QVariant se = cfg->value(QStringLiteral("application.searchEngines"));
		if (se.type() != QVariant::List || se.toList().size() != 1
		    || se.toList().first().toMap()
		               .value(QStringLiteral("text"))
		               != QStringLiteral("Google"))
			++fails; // 数组→QVariantList 承载(case6 @00a7ed2d 递归形态)
		cfg->setValue(QStringLiteral("text.margins"),
		              QVariant(QVariantList{
		                  QVariantMap{{QStringLiteral("name"),
		                               QStringLiteral("symbol")}}}));
		if (cfg->value(QStringLiteral("text.margins"))
		        .toList()
		        .first()
		        .toMap()
		        .value(QStringLiteral("name"))
		    != QStringLiteral("symbol"))
			++fails; // 对象数组→QVariantList-of-QVariantMap(text.margins
			         //   5 元素形态承载;消费面现无 → cited 待消费批)
		// 二、parseInto 复合腿:真实 JSONC 装载(wind.config 同形态)
		const QString jf = QStringLiteral("/tmp/wt-b174-wind.config");
		{
			QFile f(jf);
			f.open(QIODevice::WriteOnly | QIODevice::Truncate);
			f.write("{\n"
			        "  \"application.searchEngines\": [\n"
			        "    { \"text\": \"Bing\", \"url\": \"https://b.com\" }\n"
			        "  ],\n"
			        "  \"text.hiddenMargins\": [\"symbol\", \"timestamp\"],\n"
			        "  \"focusMode.settings\": null,\n"
			        "  \"terminal.bellStyle\": \"Audible\"\n"
			        "}\n");
		}
		cfg->setConfigPath(jf);
		cfg->reload();
		const QVariant hm = cfg->value(QStringLiteral("text.hiddenMargins"));
		if (hm.type() != QVariant::List || hm.toList().size() != 2
		    || hm.toList().at(1).toString()
		               != QStringLiteral("timestamp"))
			++fails; // 字符串数组承载(case6;wind.config L101 原值形态)
		const QVariant se2 =
		    cfg->value(QStringLiteral("application.searchEngines"));
		if (se2.type() != QVariant::List || se2.toList().size() != 1
		    || se2.toList().first().toMap()
		               .value(QStringLiteral("url"))
		               != QStringLiteral("https://b.com"))
			++fails; // 对象数组 parseInto 腿(@00a7edd0 case7 递归 map)
		if (cfg->contains(QStringLiteral("focusMode.settings")))
			++fails; // null → miss 不落(FUN_00a7fe9a @00a7ff03 json_
			         //   isNullType → 下一源/缺省;非空 QVariant 承载)
		if (cfg->value(QStringLiteral("terminal.bellStyle"))
		    != QStringLiteral("Audible"))
			++fails; // 标量键复合腿旁路不回归
		cfg->setConfigPath(QStringLiteral("/nonexistent/b174-wind.config"));
		cfg->reload();   // 测试卫生:复合键不残留(后续批次基线态)
	}

	printf("mwc_smoke: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);

	return fails ? 1 : 0;
}
