#ifndef WIDGETS_VIEWS_LOCKSCREENFACE_H
#define WIDGETS_VIEWS_LOCKSCREENFACE_H

#pragma once

// LockScreen — 全屏锁屏遮罩页(取消 / 改主密码 / 锁屏 三钮 + 密码框)。
// RTTI 类名 "LockScreen"(vtable 由 ctor 写入;&LockScreen vtable → 见 .cpp)。
// ctor s_LockScreen_560888(0x00560888,243B);布局 s_TitleLabel_560414
// (0x00560414,1004B);接线 lockscreen_connectSignals(0x005600a0,883B)。
// 键事件转发 FUN_0056098e(0x0056098e,381B)。
//
// 字段(全部由 ctor 与布局函数实读):
//   +0x00 vptr(主)          +0x10 vptr(第二多态基,PTR_FUN_01199dc8)
//   +0x30 QLabel             (布局首件)
//   +0x38 (未在本次取证中使用)
//   +0x40 QLabel *title      objectName "TitleLabel",alignment 0x84
//   +0x48 QPushButton *cancel      tr("&Cancel")@0xc8a1b4
//   +0x50 QPushButton *change      tr("&Change Master Password")@0xc8a1bc
//   +0x58 QPushButton *lock        tr("&Lock Screen")@0xc8a1d4
//   +0x60/+0x68/+0x70  0x90B 自定义件 ×3(FUN_005646ae(this, 3))
//   +0x78 0x30B 自定义件(FUN_00561d28(this))
//   +0x80 QStackedWidget
//   +0x88 quint8 mode(键事件转发用)
//   +0x8c int  = style()->pixelMetric(0x53) * 2
//   +0x90 int  = 0

#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>

class LockScreenFace : public QWidget {
	Q_OBJECT

public:
	explicit LockScreenFace(QWidget *parent = nullptr); // 00560888

protected:
	void keyPressEvent(QKeyEvent *event) override; // 0056098e

private:
	void buildUi();        // 00560414
	void connectSignals(); // 005600a0

	// ---- 槽体(逐条见 .cpp;体量大的标 cited)----------------------------
	void onLockClicked();        // 00561492(46B)
	void onChangeClicked();      // 005614c0(858B)
	void onCancelClicked();      // 0055fa50(5B)
	void onPasswordReturned();   // 0055fb0b(192B)
	void onPasswordEdited();     // 00561c9e
	void onSignalA();            // 0055ff05(387B)
	void onSignalB();            // 0055fbd3(753B)

	QLabel *m_f30 = nullptr;        // +0x30
	QLabel *m_title40 = nullptr;    // +0x40
	QPushButton *m_cancel48 = nullptr; // +0x48
	QPushButton *m_change50 = nullptr; // +0x50
	QPushButton *m_lock58 = nullptr;   // +0x58
	QWidget *m_f60 = nullptr;       // +0x60(0x90B 自定义件)
	QWidget *m_f68 = nullptr;       // +0x68
	QWidget *m_f70 = nullptr;       // +0x70
	QWidget *m_f78 = nullptr;       // +0x78(0x30B 自定义件)
	QStackedWidget *m_stack80 = nullptr; // +0x80
	quint8 m_mode88 = 0;            // +0x88
	int m_f8c = 0;                  // +0x8c
	int m_f90 = 0;                  // +0x90
};

#endif // WIDGETS_VIEWS_LOCKSCREENFACE_H
