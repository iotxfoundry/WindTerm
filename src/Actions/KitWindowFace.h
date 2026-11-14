#pragma once

#include <QMainWindow>

#include "Editor/CGlobalConfigFace.h"

// KitWindowFace —— 语料 KitWindow(typeinfo 011ab390,名 "9KitWindow" ELF
// 实读)承载面壳(MainWindowFace 判例批 100;铁律 6:抽象身份 + 纯虚 menu()。
// showConfigMenu 消费清单 = 零实例字段 + 一记虚调用 —— KITWINDOW-RECON.md
// Q2 实证"KitWindow 实例字段被读数 = 0",故本壳不落数据成员。
// ctor 字段初始化面证据在案(FUN_008cc692,214B,decomp-part-0028.c:13331
// 全读):+0x30 WORD=0x0101(+0x30/+0x31 双 BYTE)/+0x38..+0x68 七 qw 槽位族 /
// +0x70 BYTE=1 / +0x78..+0x90 四 qw / +0x98 QList shared_null / +0xa0..+0xb0
// 三 qw;sizeof(KitWindow)=0xb8(deleting dtor FUN_008cc7d2 尾 delete 0xb8,
// 0028.c:13392)。抽象类:vtable 槽 62(+0x1f0)= __cxa_pure_virtual(0xbec350
// 实证),零直接构造点;槽 53-74 对位声明不在本壳做(22 虚零消费,声明即自造
// ABI 面;menu() 槽位由 C++ 自洽,见方案书 §3 要点)。
// 接线:工厂 FUN_0089d752(0027.c:55302)页插属 MainWindow 宿主批 —— 本壳
// 不造实例(批 133 任务书§4)。
class KitWindowFace : public QMainWindow {
public:
	// FUN_008cc692(214B,0028.c:13331):QMainWindow(parent,flags0)
	//   @0x8cc69a + 尾 setAcceptDrops(true)(try 段 @0x8cc75c)。字段面
	//   见类注(壳不落 → 无清零体)。
	explicit KitWindowFace(QWidget *parent = nullptr)
		: QMainWindow(parent, Qt::WindowFlags(0)) // @0x8cc69a
	{
		setAcceptDrops(true); // @0x8cc75c
	}
	// FUN_008cc770(92B,0028.c:13364)cited:壳无字段 → 清偿面即
	//   QMainWindow 析构(语料 +0xa0 FUN_00674550+delete(0x20)/+0x98
	//   FUN_008d60a0 detach 消解腿属字段族,未落不发明)。
	virtual ~KitWindowFace() = default;
	// vtable 槽 62(+0x1f0)纯虚;子类实现:EditorWindow 0x5e97d2 /
	//   TerminalWindow 0x858fce(懒单例容器 + FUN_008aa896 校验尾)。
	//   返回 = Config 系单例(批 140 定案:Editor 腿 CEditorConfig 单例
	//   FUN_005df8d6 / Terminal 腿 CTerminalConfig 单例 FUN_00809d78,两
	//   单例 IS-A CGlobalConfig 基,src/Editor/CGlobalConfigFace.h 头注);
	//   K 效消费面 FUN_00692ef0 只触 +0x28/+0x38 → face 即 CGlobalConfigFace
	//   字段面(批 133 头注风险条款兑现)。
	virtual CGlobalConfigFace *menu() = 0;
};
