#pragma once

#include <QWidget>

#include "Widgets/Controls/CrumbEditFace.h"

// BreadCrumbFace — 语料 BreadCrumb(QWidget 子类)基面(批 252)。
// ctor FUN_00548546(110B,0017.c:16245):
//   QWidget(parent,0) → +0x38/+0x40 = 0 → setAttribute(0xe, true)
//   → setFocusPolicy(0xb = Qt::StrongFocus)@0054856x
//   → FUN_0054842a(258B 子件装配)+ FUN_0054813e(748B 接线,cited)。
// 子件装配 FUN_0054842a:
//   edit = operator_new(0xd8)+FUN_0054e188(编辑控件类,cited)+0x30 →
//   tr(0xc899e0)+FUN_0058dac2(edit,文本)(占位文案)→
//   s_CompleterButton_58dad4(edit,1,1)(补全钮)→ setFocusProxy(edit)→
//   QHBoxLayout + addWidget(edit) + setLayout(this)。
// 激活腿 FUN_00548630(55B):
//   FUN_0054d22a(+0x30, flag)(编辑件启用面,cited);flag 非 0 →
//   +0x30->setFocus(7)(MenuBarFocusReason)。
class BreadCrumbFace : public QWidget {
	Q_OBJECT
public:
	explicit BreadCrumbFace(QWidget *parent = nullptr); // FUN_00548546

	// FUN_00548630(55B,0017.c:16344)
	void setCrumbsActive(bool active);

	QWidget *edit30() const { return m_edit30; } // +0x30(编辑件)
	CrumbEditFace *crumbEdit() const { return m_crumb30; }

private:
	QWidget *m_edit30 = nullptr;          // +0x30(基类视图面)
	CrumbEditFace *m_crumb30 = nullptr;   // +0x30(编辑件本体)
	void *m_f38 = nullptr;       // +0x38(ctor 清零,语义 cited)
	void *m_f40 = nullptr;       // +0x40(ctor 清零,语义 cited)
};
