// SessionDialogFace.cpp — 会话编辑对话框(批 420)
#include "SessionDialogFace.h"

#include <QDialogButtonBox>
#include <QIntValidator>

// FUN_0072223c(364B)ctor 真身
SessionDialogFace::SessionDialogFace(const QString &name, const QVariant &config,
                                     QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @0072223c
	, m_name30(name)                      // +0x30
	, m_config40(config)                  // +0x40(json_value_copy_ctor)
{
	// vtable SessionDialog_vtable / 副 011a21f0(C++ 自洽)
	m_portValidator70 = new QIntValidator(0, 99999999, this); // @007222ac(0x18)
	setWindowTitle(name);                 // @00722376
	buildCommon();                        // @FUN_007101a0(1166B)
	wire();                               // @FUN_0070c918(343B)
	// proto = s_session_protocol_70ed6a(this)@0072xx → applyProtocol(proto)
	//   — cited(协议取面 1215B 同族)
}

// FUN_007101a0(1166B)主装配 — 结构段(cited)
void SessionDialogFace::buildCommon()
{
	// 语料在本腿建会话页的通用字段组(+0x78..+0xe8 各控件) — cited
}

// FUN_0070c918(343B)接线真身
void SessionDialogFace::wire()
{
	// ① +0x90 QTabBar currentChanged → 闭包 FUN_007223c8 — cited(槽体未转写)
	// ② 本类信号 FUN_00904d62 → 闭包 s_ColorButton_71850e,smeta 011a2240 — cited
	if (auto *box = qobject_cast<QDialogButtonBox *>(m_buttons68)) { // +0x68
		connect(box, &QDialogButtonBox::accepted, this, &QDialog::accept); // ③
		connect(box, &QDialogButtonBox::rejected, this, &QDialog::reject); // ④
	}
}

// FUN_00721412(3333B)按协议切页 — 结构段(cited)
void SessionDialogFace::applyProtocol(int proto)
{
	Q_UNUSED(proto);
	// 语料:按协议 id 显示/隐藏字段组并改页签(3333B,未逐句转写)
}
