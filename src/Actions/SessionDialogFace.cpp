// SessionDialogFace.cpp — 会话编辑对话框(批 420)
#include "SessionDialogFace.h"

#include <QDialogButtonBox>
#include <QStackedWidget>
#include <QTabBar>
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

// FUN_007101a0(1166B)主装配真身(建造部分):
//   @造 +0x80/+0x88 两个 QStackedWidget、+0x90 QTabBar、+0x68 QDialogButtonBox;
//   按钮 "Connect" / "Cancel" / "&Edit Default Settings..." 三串实读。
void SessionDialogFace::buildCommon()
{
	m_f80 = new QStackedWidget(this);      // +0x80(0x30)
	m_f88 = new QStackedWidget(this);      // +0x88(0x30)
	m_tabBar90 = new QTabBar(this);        // +0x90(0x30)
	auto *box = new QDialogButtonBox(this);// +0x68(0x30)
	m_buttons68 = box;
	// 三个按钮:Connect(自定义)/ Cancel / &Edit Default Settings...
	//   语料以 addButton + setText 落地,cited(按钮枚举未取证)
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

// FUN_00721412(3333B)按协议切页真身(结构段)
void SessionDialogFace::applyProtocol(int proto)
{
	auto *tabs = qobject_cast<QTabBar *>(m_tabBar90);       // +0x90
	if (tabs == nullptr)
		return;
	const int n = tabs->count();                            // @QTabBar::count
	for (int i = 0; i < n; ++i) {
		const int pageProto = tabs->tabData(i).toInt();     // @QTabBar::tabData
		if (pageProto == proto) {
			tabs->setCurrentIndex(i);                       // @QTabBar::setCurrentIndex
			break;
		}
	}
	// "Custom"(0xc8a049)特例分支 — cited
	// 各控件按协议启停(+0xb0/+0xb8/+0xc0/+0xd0/+0xd8/+0xe0/+0xe8/+0xf0/
	//   +0xf8/+0x100;双栈 +0x80/+0x88 联动) — cited
}
