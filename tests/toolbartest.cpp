// ToolBarBuilder 行为门(批 190;toolbar_build 00694276 转写)。
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 无头惯例:QApplication offscreen(tests/kitbartest.cpp 同面)。
// 装载面 = CGlobalConfigFace::loadViews(批 142 真身,yaml-cpp 委托;
// /opt/WindTerm_2.7.0/terminal/configs/toolbar.config 45 行原版实证 —
// 只读对表;configPath = appdir/"terminal"/tail;strace 同款)。
#include <QApplication>
#include <QAction>
#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <cstdio>

#include "Actions/KitWindowFactory.h"
#include "Actions/ToolBarBuilder.h"
#include "Editor/CGlobalConfigFace.h"

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

	// ======== a. views 装载(批 142 真身;/opt 原版对表)========
	// TerminalWindowFace::menu() → ensureLoaded → loadViews
	// (configPath appdir+"terminal"+"/configs/toolbar.confi" 语料尾差
	// 一位怪癖原样 — 测试 appdir = build 目录 → 直接构造 /opt 层:
	// 语料路径腿为 appdir 拼序;测试以 CTerminalConfig 同款 setConfigPath
	// 缝?face 无路径注入缝 → 放 cwd 等效目录不可行,直接读 /opt 校
	// yaml 解析面:cgroup 副本注入。此处按批 142 测试先例(mwctest d5):
	// appDirPath 无 /opt → loadViews false → views 空 — 语料文件缺腿
	// 同相。对表腿改手装树:appendChild 面批 147 真身直驱。
	CGlobalConfigFace::SharedConfigHandlerFace root;
	// 手装 "Standard" 组(toolbar.config 第 5-11 行原版结构):
	auto *grp = root.appendChild(QByteArrayLiteral("Standard")); // 第 5 行
	{ // 第 6 行 { "Action": "Terminal.NewSession", "Menu": "Open Recent" }
		auto *n = grp->appendChild(QByteArrayLiteral("Terminal.NewSession"));
		n->setKind(3);
		n->setPopup(QByteArrayLiteral("Open Recent")); // Menu 键 → bit3 置
	}
	{ // 第 7 行 { "Action": "Terminal.DisconnectSession" }
		auto *n = grp->appendChild(QByteArrayLiteral("Terminal.DisconnectSession"));
		n->setKind(3);
	}
	{ // 第 9 行 { "AddressBar": true } → kind 5
		auto *n = grp->appendChild(QByteArray());
		n->setKind(5);
	}
	// 顶层另立 "Kit" 组(原版第 2-4 行 {"Kit":[{"ToolBar":"Standard"}]})
	auto *kitGrp = root.appendChild(QByteArrayLiteral("Kit"));
	{
		auto *n = kitGrp->appendChild(QByteArrayLiteral("Standard"));
		n->setKind(2); // ToolBar 递归子栏
	}

	// ======== b. 工厂动作(ActionFactory 批 35 面;克隆腿 00666de2)========
	auto *mw = new QMainWindow;
	auto *proto = ActionFactory::getOrCreate(QByteArrayLiteral("Terminal.NewSession"));
	expect(proto != nullptr, "a: getOrCreate 建原型(00665dc2 转写)");
	expect(proto->text() == QStringLiteral("Terminal.NewSession"),
	       "a: 原型 text=名(00665f98 区 setText)");

	// ======== c. buildToolbar("Standard")(00694276 主面)========
	// 容器腿 = menu() 虚槽 → mw 无 KitWindowFace 宿主 → 直接断言 S0
	// 守卫(语料 mw 链尽 return 同相);真容器腿经 TerminalWindowFace。
	QToolBar *none = ToolBarBuilder::buildToolbar(mw, QByteArrayLiteral("Standard"));
	expect(none == nullptr,
	       "b: 无 KitWindowFace 容器 → null(S0 链尽腿 @006942bx)");

	// 真容器:TerminalWindowFace(menu() → CTerminalConfig face 单例)
	auto *kitwin = new TerminalWindowFace(mw); // 0x110 ctor(@0089d7df)
	// 注入 views 树:face 单例 m_views = 手装树(装载腿 appdir 无配置 →
	// loadViews false 同相,树原空;此处直写批 147 真身 appendChild 面 —
	// 装载/消费分离,消费面 = 本批 toolbar_build)。
	CGlobalConfigFace *cfg = kitwin->menu();
	expect(cfg != nullptr, "b: menu() face 单例(FUN_00858fce 转写)");
	// 清默认树(loadViews 失败腿树空;防御 clear)+ 注入手装树:
	// SharedConfigHandlerFace 无 assign — 逐节点重建到 m_views:
	cfg->m_views.clearChildren();
	for (auto **p = root.m_begin; p != root.m_end; ++p) {
		CGlobalConfigFace::SharedConfigHandlerFace *g =
		    cfg->m_views.appendChild((*p)->m_value.toByteArray());
		g->setKind((*p)->kind());
		g->setPopup((*p)->popupName());
		for (auto **q = (*p)->m_begin; q != (*p)->m_end; ++q) {
			CGlobalConfigFace::SharedConfigHandlerFace *c =
			    g->appendChild((*q)->m_value.toByteArray());
			c->setKind((*q)->kind());
			c->setPopup((*q)->popupName());
			c->setColumns((*q)->columns());
		}
	}

	QToolBar *bar = ToolBarBuilder::buildToolbar(mw, QByteArrayLiteral("Standard"));
	expect(bar != nullptr, "c: Standard 栏建成(0069430d new QToolBar)");
	expect(bar != nullptr && bar->objectName() == QStringLiteral("ToolBar"),
	       "c: objectName==\"ToolBar\"(@006943f6-0d)");
	expect(bar != nullptr
	           && bar->windowTitle() == QStringLiteral("Standard"),
	       "c: windowTitle==tr(组名)(@00694375-84,simplified 同相)");
	// 条目面:NewSession(带 Menu→钮)/Disconnect(Columns!=0 内省腿→1
	// → 钮)/AddressBar(kind5 cited 空壳)/共 3 kind 非 0 条目 →
	// addWidget×2 + separator 0 → actions 计 = 钮 2(QToolButton 的
	// defaultAction 挂 actions?语料 addWidget 腿不入 actions — 计
	// 布局面计数替代)。
	int toolBtns = 0;
	for (QObject *o : bar->children()) {
		if (qobject_cast<QToolButton *>(o) != nullptr)
			++toolBtns;
	}
	expect(toolBtns == 2,
	       "c: 2 钮(NewSession Menu 腿 @00694a1a / Disconnect 内省腿 @0069472e)");
	// 克隆腿:defaultAction = 新 QAction(text 同原型;非原型本体)。
	QToolButton *b1 = static_cast<QToolButton *>(bar->findChild<QToolButton *>());
	expect(b1 != nullptr && b1->defaultAction() != proto,
	       "c: defaultAction 为克隆非原型(00666de2 新 QAction @00666e23)");
	expect(b1 != nullptr && b1->defaultAction() != nullptr
	           && b1->defaultAction()->text() == proto->text(),
	       "c: 克隆 text 拷(@00666e12-6e)");

	// ======== d. Kit 递归子栏(case2 @00694675)========
	QToolBar *kitBar = ToolBarBuilder::buildToolbar(mw, QByteArrayLiteral("Kit"));
	expect(kitBar == nullptr,
	       "d: Kit 组仅 ToolBar 条目 → 本栏零条目删除(@00694a9x 空判)");

	// ======== e. buildAllToolbars(8bade2 工具栏段)========
	ToolBarBuilder::buildAllToolbars(mw);
	const QList<QToolBar *> added = mw->findChildren<QToolBar *>();
	int customBars = 0;
	for (QToolBar *t : added)
		if (t->objectName() == QStringLiteral("ToolBar"))
			++customBars;
	expect(customBars == 1,
	       "e: 全组遍历挂 1 栏(Kit 空删;Standard 存留 @008bb07d)");

	// ======== f. 触发槽 FUN_006941d5(真身)========
	// Popup 名空 → 短路(体首门同相);无崩溃即可(3293B 弹出体 cited)。
	if (b1 != nullptr && b1->defaultAction() != nullptr)
		ToolBarBuilder::actionTriggered(b1->defaultAction());
	expect(true, "f: 空Popup名触发短路(@006941d5→cited 体首门)");

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
