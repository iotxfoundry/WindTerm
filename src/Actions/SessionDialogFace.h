#pragma once

#include <QDialog>
#include <QHash>
#include <QString>
#include <QVariant>

class QIntValidator;
class QVariant;

// SessionDialogFace — 语料 **SessionDialog**(批 420 归属勘定)。
//
// ctor FUN_0072223c(364B,0022.c:...) asm 逐字段实测:
//   QDialog(parent, 0) → vtable **SessionDialog_vtable** + 副 011a21f0 →
//   **+0x30 = 名字 QString**(入参)→ +0x38 = 空 QString →
//   **+0x40 = JSON 值**(json_value_copy_ctor,会话配置本体)→
//   **+0x70 = QIntValidator 子类**(0..99999999,vtable IntValidator_vtable
//      —— 端口号校验器)→ +0x78 / +0x98 / +0xa0 / +0xa8 / +0xb0 / +0xb8 /
//   +0xc0 / +0xc8 / +0xd0 / +0xd8 / +0xe0 / +0xe8 全清 0(控件槽)→
//   **+0xf0 / +0xf8 = 两个 QHash** → +0x100 / +0x108 = 0 →
//   setWindowTitle → 装配 A(007101a0,1166B)+ 装配 B(0070c918,343B)→
//   proto = s_session_protocol_70ed6a(this) → FUN_00721412(this, proto)(3333B
//   按协议切页,cited)。
class SessionDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SessionDialogFace(const QString &name, const QVariant &config,
	                           QWidget *parent = nullptr);

	void buildCommon();   // FUN_007101a0(1166B)
	// FUN_0070c918(343B)**接线**(非装配),四路:
	//   ① +0x90 QTabBar::currentChanged → 闭包 impl FUN_007223c8;
	//   ② 本类信号 FUN_00904d62 → 闭包 impl s_ColorButton_71850e(**名不副实**),
	//      smeta **011a2240 = SessionDialog** 自身;
	//   ③ +0x68 "2accepted()" → this "1accept()";
	//   ④ +0x68 "2rejected()" → this "1reject()"。
	void wire();
	void applyProtocol(int proto); // FUN_00721412(3333B) — 结构段

protected:
	QString m_name30;                  // +0x30
	QString m_f38;                     // +0x38
	QVariant m_config40;               // +0x40(会话 JSON)
	QIntValidator *m_portValidator70 = nullptr; // +0x70(0..99999999)
	QWidget *m_buttons68 = nullptr;    // +0x68(QDialogButtonBox)
	QWidget *m_f78 = nullptr;          // +0x78
	QWidget *m_tabBar90 = nullptr;     // +0x90(QTabBar,currentChanged 宿主)
	QWidget *m_f98 = nullptr;          // +0x98
	QWidget *m_textA0 = nullptr;       // +0xa0
	QWidget *m_fA8 = nullptr;          // +0xa8
	QWidget *m_fB0 = nullptr;          // +0xb0
	QWidget *m_fB8 = nullptr;          // +0xb8
	QWidget *m_fC0 = nullptr;          // +0xc0
	QWidget *m_fC8 = nullptr;          // +0xc8
	QWidget *m_fD0 = nullptr;          // +0xd0
	QWidget *m_fD8 = nullptr;          // +0xd8
	QWidget *m_fE0 = nullptr;          // +0xe0
	QWidget *m_fE8 = nullptr;          // +0xe8
	QHash<QString, QVariant> m_hashF0; // +0xf0
	QHash<QString, QVariant> m_hashF8; // +0xf8
	QWidget *m_f100 = nullptr;         // +0x100
	QWidget *m_f108 = nullptr;         // +0x108
};
