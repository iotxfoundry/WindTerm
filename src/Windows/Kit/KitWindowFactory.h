#pragma once

#include <QAbstractNativeEventFilter>
#include <QByteArray>
#include <QString>
#include <QVariant>
#include <QWidget>

#include "Editor/Config/CGlobalConfigFace.h"
#include "Windows/Kit/KitWindowFace.h"
#include "Windows/Kit/MainWindowFace.h"

// 批 134:KitWindow 子类工厂 + 页挂接线(方案书 §4 直执;kitwindow-recon
// Q4:工厂唯一调用点 = s_HistoryHints_7664a2 @asm 0x7664c7,不挂
// EditorEngine)。EditorWindow/TerminalWindow 真身类未建模 → face 壳
// (批 133 判例:壳不落数据成员,字段族 cited;铁律 6)。

// EditorWindowFace — s_EditorWindow_5e96ac(187B,0019.c:22692):
//   sizeof 0xd0(operator_new(0xd0) @0089d799);ctor = FUN_008cc692
//   @005e96be + +0xb8/+0xc0/+0xc8 清零族(cited,壳不落)+ objectName
//   "EditorWindow"(fromLatin1 @005e970d-26)。menu() = FUN_005e97d2
//   (39B,0019.c:22781):懒单例 DAT_011c12e0 ← FUN_005df8d6(CEditorConfig
//   Meyers,ctor 005df8ae;批 140 face 落库 src/Editor/CGlobalConfigFace.h)。
class EditorWindowFace : public KitWindowFace {
public:
	explicit EditorWindowFace(QWidget *parent = nullptr)
		: KitWindowFace(parent)                        // FUN_008cc692 @005e96be
	{
		setObjectName(QStringLiteral("EditorWindow")); // @005e970d-26
	}
	CGlobalConfigFace *menu() override; // FUN_005e97d2(39B)— cpp 侧

	// --- 槽体半边(原 src/Widgets/EditorWindow.h,2026-11-16 并入本类)---
	// metacall 0x8fc36e,8 slots;一处信号发射体 + Qt QList 拷贝基建
	// (0x533df0)+ 下列 4 个实体(0x5e9-0x5eb)。槽体未逐句转写 → cited。
public slots:
	void openSessionQuery() { /* FUN_005eb4fc(1.4K)— cited */ }
	void tripleOp(const QVariant &a, const QVariant &b, const QVariant &c)
	{ Q_UNUSED(a); Q_UNUSED(b); Q_UNUSED(c); /* FUN_005ea368(1.8K,3 槽共用)— cited */ }
	void nodeCallbackWalk() { /* FUN_005eb64e(4.8K)— cited */ }
	void globalRegister() { /* FUN_005e97ba:FUN_005df958(this, DAT_011c12e0)— cited */ }
};

// TerminalWindowFace — s_TerminalWindow_859902(296B,0026.c:50716):
//   sizeof 0x110(operator_new(0x110) @0089d7e3);ctor = FUN_008cc692
//   @00859914 + QAbstractNativeEventFilter 副基 @0085991e(+0xb8,副
//   vptr 011a7f48)+ 字段清零族(cited,壳不落)+ objectName
//   "TerminalWindow"(@008599c4-dd)。menu() = FUN_00858fce(39B,
//   0026.c:50296):懒单例 DAT_011c2200 ← FUN_00809d78(= CTerminalConfig::
//   instance(),src/Editor 已落库)+ FUN_008aa896 校验尾(cited —
//   FUN_008a99de/008aa39e yaml 装载腿;kitwindow-recon §未解 1 余项)。
class TerminalWindowFace : public KitWindowFace, private QAbstractNativeEventFilter {
public:
	explicit TerminalWindowFace(QWidget *parent = nullptr)
		: KitWindowFace(parent)                          // FUN_008cc692 @00859914
	{
		setObjectName(QStringLiteral("TerminalWindow")); // @008599c4-dd
	}
	CGlobalConfigFace *menu() override; // FUN_00858fce(39B)— cpp 侧
	bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override
	{
		Q_UNUSED(eventType); Q_UNUSED(message); Q_UNUSED(result);
		return false; // cited — 副基槽体 011a7f48 未转写(ctor 不注册,零消费面)
	}

	// --- 槽体半边(原 src/Widgets/TerminalWindow.h,2026-11-16 并入本类)---
	// metacall 0x911868,18 slots @0x858b-0x859a;tab/容器操作用
	// dynamic_cast(0x11a8310),全局管理器 0x11c2200/0x11c1a60/0x11c1b00。
	// 槽体未逐句转写 → cited(空体,不引未定义符号)。
public slots:
	void setSplit(bool on) { Q_UNUSED(on); /* FUN_00858b18/0x858be8 分裂/合并对 — cited */ }
	void openSettingsFlow() { /* FUN_00858cbc(cases 7-8)— cited */ }
	void arrangeWindows() { /* FUN_00859a42(cases 9-10,2.6K)— cited */ }
	void toggleTheme() { /* FUN_00858e86(cases 11-13,全局 FUN_008cbc36)— cited */ }
	void openDialog() { /* FUN_00858efa(0x70 字节对话框 FUN_0072abce)— cited */ }
	void queryGlobal() { /* FUN_00858f32(global 0x11c1a60)— cited */ }
	void notifyGlobal2() { /* FUN_00858f9e(global 0x11c1b00)— cited */ }
	void globalOp() { /* FUN_00858fb0(0x11c2200 via FUN_008086d0)— cited */ }
};

// FUN_0089d752(246B,0027.c:55302)= KitWindow 子类唯一工厂
//   (compare_helper cs=1 三分支 @0089d75a/0089d7a3/0089d7ed + 语料尾
//   return 0 @0089d846)。
KitWindowFace *kitWindowFactory(const QString &type, QWidget *parent);

// s_HistoryHints_7664a2(244B,0023.c:33200;唯一调用点 0x7664c7 转写):
//   工厂产物非 null →(hints 非空 @0x7664e8)setProperty 双腿
//   ("History" ← QVariant(QByteArray) @0x766507 / "HistoryHints" ←
//   QVariant(int) @0x76652f;名串 0x11820e0/e8 → .rodata "History"/
//   "HistoryHints" 二进制实读)→ stack(+0x58)addWidget @0x766543 →
//   select 时 setCurrentIndex @0x766587 → KitBar(+0x50)addKit @0x766565
//   (title=type,iconName=shared_null 空 QString)。
//   host = MainWindowFace::Slots(+0x50/+0x58,批 100 面);mainWindow =
//   语料 param_1(工厂 parent 实参,addWidget 随即收养 — Slots 未携带
//   宿主,单列实参,对位 param_1 唯一用途)。
void kitWindowAttachPage(MainWindowFace::Slots host, QMainWindow *mainWindow,
                         const QString &type, bool select,
                         const QByteArray &hints, int hintValue);

// FUN_0075e3fe(332B,0023.c:27332)对位恢复路径(批 142 宿主接线):
// window_activeMainPane()==0 腿 → FUN_007665ae("Terminal" 首页);
// pane 活动腿(几何恢复)不在本面(cited)。
void kitWindowRestoreFirstPage(MainWindowFace::Slots host, QMainWindow *mainWindow);

// Terminal 腿 face 转接(批 140;批 142 双 Meyers 合一 — 同一单例的
// face 基面):语料 CTerminalConfig 单例对象 = menu() 容器
// (KitWindowFactory.cpp 注记;kitwindow-recon §未解 1 收口)。
CGlobalConfigFace *terminalConfigAsFace();

// 批 189(M24-②):菜单族消费三件(FUN_00692a70/00692ef0 升真承载;
// 见 CGlobalConfigFace.h 头注与 MuxPaneGroup.cpp 升级注):
//   kitMenuBarBuild — King::MenuBar::MenuBar(575B,0021.c:18969)装配
//     腿:operator_new(0x30)+QMenuBar(parent)→ objectName "MenuBar"
//     (@0069309a-9e)→ windowTitle(registerBarsAndPanes 合成面 cited,
//     KitBar.cpp:176 同判)→ 容器 buildMenuBarGroupMenus("Kit",host)
//     (@00693130-6)→ vt+0x218 cornerWidget 非空 setCornerWidget 腿
//     (cited — 宿主槽未建模)→ setMenuBar(宿主腿 008c9ee4 域,本件
//     只产 bar 归调用方)。
QMenuBar *kitMenuBarBuild(CGlobalConfigFace *container, QWidget *hostPane);

//   kitFindOrCreateGroupMenu — FUN_00692ef0(310B,0021.c:18914)升真:
//     S1 空名 nullptr(@00692ef7)→ S2 FUN_006926c2(+0x28)命中 →
//     FUN_00692a70(组节点,pane)缓存直返(@00692efc-27)→ S3 未命中
//     tr+new QMenu(@00692f68-030)。容器面 = CGlobalConfigFace::m_groups
//     (kitwindow-recon §未解 1 收口:容器类 = Config 系单例,批 140
//     定案)— MuxPaneGroup::kitFindOrCreateGroupMenu(void* 壳态)随本
//     件升级(同库真身调用)。
QMenu *kitFindOrCreateGroupMenu(CGlobalConfigFace *container,
                                const QByteArray &name, QWidget *pane);
