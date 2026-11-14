#include "KitWindowFactory.h"

#include <QStackedWidget>
#include <QVariant>

#include "KitBar.h"
#include "Editor/CTerminalConfig.h"

// EditorWindowFace::menu — FUN_005e97d2(39B,0019.c:22781):
//   DAT_011c12e0 懒单例 → FUN_005df8d6(CEditorConfig Meyers 构造,
//   ctor 005df8ae = FUN_008a71e4 + CEditorConfig_vtable)→ FUN_008aa896
//   校验尾。CEditorConfig 类未建模(cited — KITWINDOW-RECON 未解 1:
//   容器类名/008a99de·8aa39e 四腿未转写)→ 静态 nullptr 承接懒单例
//   槽位,不发明构造面。
void *EditorWindowFace::menu()
{
	static void *s_editorConfigSingleton = nullptr; // DAT_011c12e0(cited)
	return s_editorConfigSingleton;                 // @005e97d6 非空直返
}

// TerminalWindowFace::menu — FUN_00858fce(39B,0026.c:50296):
//   DAT_011c2200 懒单例 → FUN_00809d78(= CTerminalConfig::instance(),
//   src/Editor/CTerminalConfig.cpp 已落库)→ FUN_008aa896 校验尾
//   (cited,未解 1;型差:void* 不透明面对位批 133 头注)。
void *TerminalWindowFace::menu()
{
	static void *s_terminalConfigSingleton = nullptr; // DAT_011c2200
	if (s_terminalConfigSingleton == nullptr)
		s_terminalConfigSingleton = CTerminalConfig::instance(); // FUN_00809d78 @00858fd6
	return s_terminalConfigSingleton;                 // @00858fd0 非空直返
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
