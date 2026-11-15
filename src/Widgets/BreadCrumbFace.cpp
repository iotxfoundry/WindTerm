// BreadCrumbFace.cpp — 语料 BreadCrumb 基面(批 252)
#include "BreadCrumbFace.h"

#include <QHBoxLayout>

// FUN_00548546(110B,0017.c:16245)ctor 真身:
//   @00548546 QWidget(parent,0);@0054856x +0x38/+0x40 = 0;
//   @0054858b setAttribute(0xe,1);@0054859x setFocusPolicy(0xb);
//   @0054859x FUN_0054842a(this)(子件装配,见下)+ FUN_0054813e(this)(cited)。
BreadCrumbFace::BreadCrumbFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @00548546
{
	setAttribute(static_cast<Qt::WidgetAttribute>(0xe), true); // @0054858b
	setFocusPolicy(Qt::StrongFocus); // 0xb @0054859x
	// FUN_0054842a(258B)子件装配:
	//   edit = operator_new(0xd8)+FUN_0054e188(edit 类未建模,cited);
	//   tr(0xc899e0)→ FUN_0058dac2(edit,文本);s_CompleterButton_58dad4(
	//   edit,1,1);setFocusProxy(edit);QHBoxLayout(+ 边距/间距 Ghidra 折叠)
	//   → addWidget(edit) → setLayout。因 edit 类未建模,本波仅落布局空壳:
	if (m_edit30 != nullptr) {
		auto *box = new QHBoxLayout(); // 语料 QHBoxLayout(0x20)
		box->addWidget(m_edit30);
		setLayout(box);
		setFocusProxy(m_edit30);
	}
	// FUN_0054813e(748B)接线腿 — cited(体未转写)。
}

// FUN_00548630(55B,0017.c:16344)真身:
//   FUN_0054d22a(*(this+0x30), flags)(编辑件启用/只读面,cited);
//   flag != 0 → QWidget::setFocus(edit, 7 = MenuBarFocusReason)。
void BreadCrumbFace::setCrumbsActive(bool active)
{
	if (m_edit30 == nullptr)
		return;
	// FUN_0054d22a(m_edit30, active)@00548630 — cited(编辑件类未建模)。
	if (active)
		m_edit30->setFocus(Qt::MenuBarFocusReason); // 7 @0054864x
}
