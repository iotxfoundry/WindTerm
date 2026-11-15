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
#include "Actions/TabGroup.h"
#include "Editor/CGlobalConfigFace.h"
#include "Editor/CTerminalConfig.h"
#include "Actions/StartupChain.h"
#include "Sessions/WorkspaceLoader.h"

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

	delete edW;
	delete buyW;

	printf("mwc_smoke: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
