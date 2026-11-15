// menutest — 批 189(M24-②)菜单装载腿行为门(手工验证;CMakeLists
// 主控合流时注册)。铁律 5:断言语料行为,每条断言带语料锚。
// 面:menu.config 根 map 装载批 189 勘正腿(getMemberNames 键集遍历
// @00af3a20 对账)+ 菜单树消费真身(FUN_00692a70/00692ef0/King::MenuBar
// 00693036,/opt 实证对表)。
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QMenuBar>
#include <cstdio>
#include "Actions/KitWindowFactory.h"
#include "Editor/CGlobalConfigFace.h"
#include "Editor/CTerminalConfig.h"

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

// 树结构计数器(组→项 两级 + Menu 三级)
static int groupCount(const SharedConfigHandlerFace &root)
{
	return int(root.m_end - root.m_begin);
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	// ======== a. /opt 原版 menu.config 装载对表(终端腿)========
	// 路径面 = FUN_008a58f0:appdir/Terminal(toLower)/configs/menu.config
	//   — 测试树无该文件 → 复制 /opt 原版到 applicationDirPath()/
	//   terminal/configs/ 实测装载产出(键集/树形)。
	const QString cfgDir = QCoreApplication::applicationDirPath()
	                       + QStringLiteral("/terminal/configs");
	QDir().mkpath(cfgDir);
	const QString srcMenu = QStringLiteral(
	    "/opt/WindTerm_2.7.0/terminal/configs/menu.config");
	QFile::copy(srcMenu, cfgDir + QStringLiteral("/menu.config"));

	CTerminalConfig *cfg = CTerminalConfig::instance();
	CGlobalConfigFace *face = cfg->face();
	const bool loaded = face->loadGroups();
	expect(loaded, "a: loadGroups true(/opt 原版,@008a9a5d yaml_loadFile)");
	if (!loaded) {
		printf("menutest: abort(loadGroups false)\n");
		return 1;
	}

	// 键集对账:原版顶层 33 组(/opt 文件实读:Kit/Kit More/Dock/Layout/
	//   MuxPaneGroup/Open Recent/Navigation List/Filer History/Filer More/
	//   Explorer Popup/Filer Popup/Outline More/Outline Popup/Session Popup/
	//   TabGroup Popup/Transfer Popup/View Popup/View Margin Popup/
	//   View Shift Popup/View Ctrl Popup/View Alt Popup/View Meta Popup/
	//   ViewTab Popup/Session/Edit/Search/Selection/Goto/View/Mode/Tool/
	//   Window/Help)。
	const SharedConfigHandlerFace &groups = face->m_groups;
	const int nGroups = groupCount(groups);
	expect(nGroups == 33, "a: 顶层 33 组(getMemberNames 键集 @00af3a20)");

	// 树形对账(抽样 — 数据逐项来自 menu.config,禁发明):
	if (nGroups == 33) {
		SharedConfigHandlerFace **g = groups.m_begin;
		// 首组 "Kit":10 项全 Menu kind=2(原版 "Kit" 数组实读)。
		if (g[0]->m_value.toString() != QStringLiteral("Kit"))
			++g_fail, printf("FAIL: 首组名 ≠ Kit\n");
		else if (g[0]->m_end - g[0]->m_begin != 10)
			++g_fail, printf("FAIL: Kit 组 ≠ 10 菜单项\n");
		else {
			expect(g[0]->m_begin[0]->m_value.toString()
			           == QStringLiteral("Session")
			       && g[0]->m_begin[0]->kind() == 2,
			       "a: Kit[0] = Menu \"Session\" kind=2(@008a991c)");
			expect(g[0]->m_begin[9]->m_value.toString()
			           == QStringLiteral("Help"),
			       "a: Kit[9] = Menu \"Help\"(原版序末位)");
			expect(g[0]->m_begin[0]->m_end - g[0]->m_begin[0]->m_begin == 0,
			       "a: Menu 无 Actions 键 → 三级空(@008a9990 递归缺键腿)");
		}
		// "Session" 组(主菜单真树):21 项(原版逐项实读)/含 &Log 子菜单。
		for (int i = 0; i < nGroups; ++i) {
			if (g[i]->m_value.toString() != QStringLiteral("Session"))
				continue;
			expect(g[i]->m_end - g[i]->m_begin == 21,
			       "a: Session 组 21 项(原版逐项实读)");
			// 首项 Action Terminal.NewSession(kind=3,名 = 键值 @008a9836)。
			expect(g[i]->m_begin[0]->kind() == 3
			       && g[i]->m_begin[0]->m_value.toString()
			              == QStringLiteral("Terminal.NewSession"),
			       "a: Session[0] = Action Terminal.NewSession");
			// "Open Rece&nt" Menu 无 Actions(挂点由消费腿动态装 — 原版
			//   同形:无 "Actions" 键)。
			expect(g[i]->m_begin[7]->kind() == 2
			       && g[i]->m_begin[7]->m_value.toString()
			              == QStringLiteral("Open Rece&nt"),
			       "a: Session[7] = Menu \"Open Rece&nt\"(原版字面)");
			break;
		}
		// "Explorer Popup" 组:Set Tab &Color 子菜单 16 项(Actions 递归
		//   @008a9990;原版逐项实读)。
		for (int i = 0; i < nGroups; ++i) {
			if (g[i]->m_value.toString() != QStringLiteral("Explorer Popup"))
				continue;
			SharedConfigHandlerFace *m0 = g[i]->m_begin[0];
			expect(m0->kind() == 2
			       && m0->m_value.toString() == QStringLiteral("Set Tab &Color")
			       && m0->m_end - m0->m_begin == 16,
			       "a: Explorer Popup[0] 子菜单 16 项(@008a971e 三级递归)");
			expect(m0->m_begin[1]->kind() == 0
			       && m0->m_begin[1]->m_value.toString().isEmpty(),
			       "a: 子菜单 [1] Separator 名空(@008a9943 clear)");
			break;
		}
		// 空数组组("View Shift Popup" 等 4 组 = 原版 [ ] 空 — 组节点
		//   0 子,FUN_008a971e size 门直返 @008a976a)。
		for (int i = 0; i < nGroups; ++i) {
			if (g[i]->m_value.toString() != QStringLiteral("View Shift Popup"))
				continue;
			expect(g[i]->m_end - g[i]->m_begin == 0,
			       "a: View Shift Popup 空数组组(size 门 @008a976a)");
			break;
		}
	}

	// ======== b. 菜单消费真身(FUN_00692a70/00692ef0/King::MenuBar)========
	// b1. kitFindOrCreateGroupMenu:命中组 → 树构建 QMenu(项数同构)。
	QWidget pane;                                   // 宿主 param_3
	QMenu *muxMenu = kitFindOrCreateGroupMenu(
	    face, QByteArrayLiteral("MuxPaneGroup"), &pane);
	expect(muxMenu != nullptr, "b1: 组命中 → QMenu(FUN_00692ef0 S2)");
	if (muxMenu != nullptr) {
		// MuxPaneGroup 组原版 11 项:9 Action + 2 Separator。
		expect(muxMenu->actions().size() == 11,
		       "b1: MuxPaneGroup 菜单 11 项(2 Sep+9 Act,原版逐项)");
		// kind=0 → addSeparator(isSeparator 门);kind=3 → 工厂 QAction
		//   setText 面(名 = "Mux.TogglePaneZoom" 原版首项)。
		expect(muxMenu->actions()[0]->text()
		           == QStringLiteral("Mux.TogglePaneZoom"),
		       "b1: 首 action text = 工厂 setText(名)(@00665f98 区)");
		expect(muxMenu->actions()[2]->isSeparator(),
		       "b1: kind=0 → addSeparator(@00692d7e)");
	}
	// 缓存面:二调同指针(FUN_006926c2 命中 → m_menu)。
	QMenu *again = kitFindOrCreateGroupMenu(
	    face, QByteArrayLiteral("MuxPaneGroup"), &pane);
	expect(again == muxMenu, "b1: 二调缓存同址(FUN_006926c2 命中读)");
	// 未命中组 → 散建不入表(语料 S3 不写回 +0x28)。
	QMenu *loose = kitFindOrCreateGroupMenu(
	    face, QByteArrayLiteral("NoSuchGroup"), &pane);
	expect(loose != nullptr && loose != muxMenu,
	       "b1: 未命中 → 散建新菜单(@00692f68-030)");
	expect(kitFindOrCreateGroupMenu(face, QByteArray(), &pane) == nullptr,
	       "b1: 空名 → nullptr(@00692ef7)");

	// b2. 子菜单递归(k=2 → addMenu)。"Session" 组含 &Log/&Preferences
	//     子菜单(原版 Session[12] Menu &Log Actions 10 项、[14] &Preferences
	//     5 项、[7] Open Rece&nt 无 Actions)。
	for (int i = 0; i < groupCount(groups); ++i) {
		SharedConfigHandlerFace *grp = groups.m_begin[i];
		if (grp->m_value.toString() != QStringLiteral("Session"))
			continue;
		QMenu *sm = kitFindOrCreateGroupMenu(
		    face, QByteArrayLiteral("Session"), &pane);
		expect(sm != nullptr && sm->actions().size() == 21,
		       "b2: Session 菜单 21 项(项=action/sep/menu 全落)");
		int menus = 0;
		for (const QAction *a : sm->actions())
			if (a->menu() != nullptr)
				++menus;                    // k==2 → addMenu 项
		expect(menus == 3,
		       "b2: 子菜单 3 记(&Log/&Preferences/Open Rece&nt — 原版实读)");
		break;
	}

	// b3. King::MenuBar::MenuBar 装配腿(@00693036):
	//     "Kit" 组 10 Menu → QMenuBar 10 addMenu(@00693052-6 门 @006931b0)。
	QMenuBar *bar = kitMenuBarBuild(face, &pane);
	expect(bar != nullptr
	           && bar->objectName() == QStringLiteral("MenuBar"),
	       "b3: objectName==\"MenuBar\"(@0069309a-9e)");
	if (bar != nullptr) {
		expect(bar->actions().size() == 10,
		       "b3: Kit 组 10 Menu → addMenu ×10(@00693052-6)");
		if (bar->actions().size() == 10) {
			// 首菜单标题 = tr("Session")(QMetaObject::tr @00692b0e;离屏
			//   无翻译 → 原文)。
			expect(bar->actions()[0]->text() == QStringLiteral("Session"),
			       "b3: 首菜单 text = tr(\"Session\")(@00692b0e)");
			// MenuBar 腿只消费 kind==2(Kit 组无 Separator/Action — 门
			//   @006931b0);顺序 = 原版 Kit 序。
			expect(bar->actions()[9]->text() == QStringLiteral("Help"),
			       "b3: 末菜单 = Help(原版序)");
		}
	}

	// ======== c. 装载腿复跑清树(FUN_008aaae2)+ 缓存换血 ========
	// 二次 loadGroups → clearChildren 后重建(项数同);旧 QMenu 缓存随
	//   节点消偿(SharedConfigHandlerFace dtor — 壳判例 QMenu* 裸槽非
	//   所属,Qt parent 链 pane 清偿)。
	expect(face->loadGroups() && groupCount(face->m_groups) == 33,
	       "c: 复跑装载 33 组重建(@008a9add 清树腿)");

	QFile::remove(cfgDir + QStringLiteral("/menu.config"));

	printf("menutest: %s (%d fails)\n", g_fail ? "FAIL" : "PASS", g_fail);
	return g_fail ? 1 : 0;
}
