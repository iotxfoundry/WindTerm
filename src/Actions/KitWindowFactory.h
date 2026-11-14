#pragma once

#include <QAbstractNativeEventFilter>
#include <QByteArray>
#include <QString>
#include <QWidget>

#include "Editor/CGlobalConfigFace.h"
#include "KitWindowFace.h"
#include "MainWindowFace.h"

// 批 134:KitWindow 子类工厂 + 页挂接线(方案书 §4 直执;KITWINDOW-RECON
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
};

// TerminalWindowFace — s_TerminalWindow_859902(296B,0026.c:50716):
//   sizeof 0x110(operator_new(0x110) @0089d7e3);ctor = FUN_008cc692
//   @00859914 + QAbstractNativeEventFilter 副基 @0085991e(+0xb8,副
//   vptr 011a7f48)+ 字段清零族(cited,壳不落)+ objectName
//   "TerminalWindow"(@008599c4-dd)。menu() = FUN_00858fce(39B,
//   0026.c:50296):懒单例 DAT_011c2200 ← FUN_00809d78(= CTerminalConfig::
//   instance(),src/Editor 已落库)+ FUN_008aa896 校验尾(cited —
//   FUN_008a99de/008aa39e yaml 装载腿;KITWINDOW-RECON §未解 1 余项)。
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

// Terminal 腿 face 转接(批 140):语料 CTerminalConfig 单例对象 =
// menu() 容器(KitWindowFactory.cpp 注记;KITWINDOW-RECON §未解 1 余项)。
CGlobalConfigFace *terminalConfigAsFace();
