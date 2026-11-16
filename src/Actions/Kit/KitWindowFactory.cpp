#include "Actions/Kit/KitWindowFactory.h"

#include <QApplication>
#include <QMenuBar>
#include <QStackedWidget>
#include <QVariant>

#include "Actions/Kit/KitBar.h"
#include "Actions/Mux/MuxPane.h"
#include "Editor/CGlobalConfigFace.h"
#include "Editor/CTerminalConfig.h"

// Terminal 腿面转接:语料 CTerminalConfig 单例对象(DAT_011c2220)即
// menu() 返回容器(IS-A CGlobalConfig 基,CGlobalConfigFace.h 头注)。
// 批 142 双 Meyers 合一:CTerminalConfig 私有继承 CTerminalConfigFace,
// face() = 同一单例的 face 基面(值面 + 容器面共一对象,不再双静态)。
CGlobalConfigFace *terminalConfigAsFace()
{
	return CTerminalConfig::face(); // DAT_011c2220 face 视图(= 单例本体)
}

// === 批 189(M24-②):菜单族消费真身(KitWindowFactory 承载 = menu()
// 容器消费邻接面;语料落点 0021.c:18732/18914/18969 全读)===

// kitFindOrCreateGroupMenu — FUN_00692ef0(310B,0021.c:18914)逐句:
//   S1 名空(id==0)→ nullptr @00692ef7;S2 容器 +0x28 组节点 FUN_006926c2
//   键查 → 命中 → FUN_00692a70(组节点,pane)取缓存 QMenu 返回
//   (@00692efc-27;命中腔 lVar1=节点);S3 未命中 → QMetaObject::tr(name)
//   → operator_new(0x30)+QMenu(标题,pane)@00692f68-030(新建不入组表 —
//   语料同相:散建菜单不写回 +0x28)。容器面 = CGlobalConfigFace(批 140
//   定案;组遍历 = SharedConfigHandlerFace children 键比对,FUN_006926c2
//   memcmp 语义同相)。
QMenu *kitFindOrCreateGroupMenu(CGlobalConfigFace *container,
                                const QByteArray &name, QWidget *pane)
{
	if (name.isEmpty())                       // S1 @00692ef7
		return nullptr;
	SharedConfigHandlerFace &groups = container->m_groups; // 容器 +0x28
	for (SharedConfigHandlerFace **it = groups.m_begin;
	     it != groups.m_end; ++it) {          // FUN_006926c2 键查 @00692efc
		if ((*it)->m_value.toByteArray() == name)
			return (*it)->findOrBuildMenu(pane);  // FUN_00692a70 @00692f4c
	}
	return new QMenu(QObject::tr(name.constData()), pane); // S3 @00692fbf-030
}

// kitMenuBarBuild — King::MenuBar::MenuBar(575B,0021.c:18969)装配腿:
//   operator_new(0x30)+QMenuBar(hostPane)@00693060 → objectName
//   "MenuBar"(@0069309a-9e)→ windowTitle(King::registerBarsAndPanes
//   标题合成面 cited — KitBar.cpp:176 同判,不发明)→ 容器组腿
//   buildMenuBarGroupMenus("Kit",host)(@00693130-6;组名 "Kit" =
//   FUN_008c9ee4 实参 QByteArray("Kit")@008c9f1a 二进制面)→ vt+0x218
//   cornerWidget 腿归 008c9ee4 域(批 192:kitMenubarAssemble 真身,
//   KitWindowFace::kitCornerWidget)→ setMenuBar 归 008c9ee4 宿主腿。
QMenuBar *kitMenuBarBuild(CGlobalConfigFace *container, QWidget *hostPane)
{
	QMenuBar *bar = new QMenuBar(hostPane);            // @00693060-64
	bar->setObjectName(QStringLiteral("MenuBar"));     // @0069309a-9e
	// windowTitle ← King::registerBarsAndPanes(&out,"MenuBar") — cited
	// (@006930e5-f4;合成面未落库,同 KitBar 判)。
	container->m_groups.buildMenuBarGroupMenus(
	    bar, QByteArrayLiteral("Kit"), hostPane);      // @00693130-6(008c9ee4 实参 "Kit")
	return bar;                                        // @0069307c
}

// EditorWindowFace::menu — FUN_005e97d2(39B,0019.c:22781):
//   DAT_011c12e0 懒缓存 → FUN_005df8d6(CEditorConfig Meyers 单例,face
//   批 140 落库)→ FUN_008aa896 校验尾(批 142:两 yaml 装载腿真身化
//   入 ensureLoaded)。单例身份恒同一对象 → 一次缓存后恒返(DAT 懒缓存同相)。
CGlobalConfigFace *EditorWindowFace::menu()
{
	static CGlobalConfigFace *s_editorConfigSingleton = nullptr; // DAT_011c12e0
	if (s_editorConfigSingleton == nullptr) {
		s_editorConfigSingleton = CEditorConfigFace::instance(); // FUN_005df8d6 @005e97da
		s_editorConfigSingleton->ensureLoaded();                 // FUN_008aa896 @005e97e2
	}
	return s_editorConfigSingleton;                 // @005e97d6 非空直返
}

// TerminalWindowFace::menu — FUN_00858fce(39B,0026.c:50296):
//   DAT_011c2200 懒缓存 → FUN_00809d78(= CTerminalConfig::instance(),
//   src/Editor/CTerminalConfig.cpp 已落库)→ FUN_008aa896 校验尾(cited;
//   批 142 两 yaml 装载腿真身化入 ensureLoaded)。语料单例 IS-A
//   CGlobalConfig 基(两 ctor 首句同 FUN_008a71e4)→ CTerminalConfig
//   经 face 转接面回 CGlobalConfigFace(批 142 双 Meyers 合一:同一对象)。
CGlobalConfigFace *TerminalWindowFace::menu()
{
	static CGlobalConfigFace *s_terminalConfigSingleton = nullptr; // DAT_011c2200
	if (s_terminalConfigSingleton == nullptr) {
		s_terminalConfigSingleton = terminalConfigAsFace(); // FUN_00809d78 @00858fd6(合一:face=单例本体)
		s_terminalConfigSingleton->ensureLoaded();          // FUN_008aa896 @00858fde(装载校验尾)
	}
	return s_terminalConfigSingleton;               // @00858fd0 非空直返
}

// === kitWindowFactory — FUN_0089d752(246B,0027.c:55302)===
// 语料三分支(compare_helper cs=1 = 大小写敏感 Qt::CaseInsensitive 值 0?
// 否 — cs=1):"Editor" @0089d75a → operator_new(0xd0)+s_EditorWindow_
// 5e96ac;@0089d7a3 "Terminal" → operator_new(0x110)+s_TerminalWindow_
// 859902;@0089d7ed "Buy"(DAT_00d0eaa4 二进制实读="Buy")→ EditorWindow
// 腿复用;@0089d846 尾 return 0(未知类型 null,调用点 null 卫 0x7664cf)。
KitWindowFace *kitWindowFactory(const QString &type, QWidget *parent)
{
	if (type == QStringLiteral("Editor"))
		return new EditorWindowFace(parent);   // @0089d795-9d(0xd0)
	if (type == QStringLiteral("Terminal"))
		return new TerminalWindowFace(parent); // @0089d7df-e7(0x110)
	if (type == QStringLiteral("Buy"))         // DAT_00d0eaa4
		return new EditorWindowFace(parent);   // @0089d839-41(0xd0,Editor 同型)
	return nullptr;                            // @0089d846
}

// === kitWindowAttachPage — s_HistoryHints_7664a2(244B,0023.c:33200)===
// 唯一调用点 0x7664c7 转写(汇编全读 0x7664a2-0x766596):工厂 null →
// 直返 @0x7664cf;hints 非空(*(*(p4+0)+4)!=0 → QByteArray size)!=0 @
// 0x7664e8 → setProperty 双腿;addWidget @0x766543;param_3!=0 →
// setCurrentIndex @0x766548→587;KitBar addKit @0x766565(title=param_2,
// iconName=QArrayData::shared_null 空 QString,汇编 rdx=shared_null 实证)。
void kitWindowAttachPage(MainWindowFace::Slots host, QMainWindow *mainWindow,
                         const QString &type, bool select,
                         const QByteArray &hints, int hintValue)
{
	Q_UNUSED(mainWindow); // 语料 param_1 其余用途仅工厂 parent(见头注)
	KitWindowFace *page = kitWindowFactory(type, mainWindow); // @0x7664c7
	if (page == nullptr)
		return; // @0x7664cf(null 卫,工厂未知类型腿)
	if (!hints.isEmpty()) { // *(int*)(*(long*)param_4+4)!=0 @0x7664e5-e8
		page->setProperty("History", QVariant(hints));        // @0x766507(0xc9e544="History")
		page->setProperty("HistoryHints", QVariant(hintValue)); // @0x76652f(0x11820e8→"HistoryHints";QVariant(int) @0x76651a)
	}
	int index = host.f58->addWidget(page); // QStackedWidget::addWidget @0x766543
	if (select)
		host.f58->setCurrentIndex(index); // param_3!=0 @0x766548→58b
	host.f50->addKit(index, type, QString()); // FUN_008b346e @0x766565(icon=shared_null 空 QString)
}

// === kitWindowRestoreFirstPage — FUN_0075e3fe(332B,0023.c:27332)对位
// 恢复路径(批 142 宿主接线;kitwindow-recon Q4 接线结论兑现):
//   语料 window_activeMainPane(105B,0023.c:25789)==0 腿 @0075e3fe-4a:
//   无活动 pane → FUN_007665ae(122B,0023.c:33235)= s_HistoryHints
//   ("Terminal",select=0,hints=shared_null,hintValue=1)—— "Terminal"
//   首页建立;有活动 pane → saveGeometry/FUN_007669b2/FUN_00766c26 几何
//   恢复腿(本接线域外,cited)。activeMainPane 门 = QApplication::
//   activeWindow() 祖先链 dynamic_cast(MuxPane 面,011a69d0)@0075c0be。
// 本接线 = 无 pane 腿挂 MainWindowFace::Slots(装配面判例 mwctest d1/d2);
// 产品启动链(mainWindow_connectSignals 0076b9ec 第 3 步 FUN_0076663e →
// FUN_007662e6 装配)无我方可运行消费点 → mwctest 级接线 + 报告,不发明
// 启动路径(kitwindow-recon Q4 同判)。
void kitWindowRestoreFirstPage(MainWindowFace::Slots host, QMainWindow *mainWindow)
{
	QWidget *aw = QApplication::activeWindow(); // @0075c0be 首句
	bool hasMainPane = false;
	for (QWidget *w = aw; w != nullptr; w = w->parentWidget())
		if (dynamic_cast<MuxPane *>(w) != nullptr) { // __dynamic_cast 011a69d0
			hasMainPane = true;
			break;
		}
	if (hasMainPane)
		return; // activeMainPane!=0 → 几何恢复腿,页插不在本接线域
	kitWindowAttachPage(host, mainWindow, QStringLiteral("Terminal"), false,
	                    QByteArray(), 1); // FUN_007665ae:select=0/hints 空/hintValue=1
}
