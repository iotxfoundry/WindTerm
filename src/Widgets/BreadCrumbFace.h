#pragma once

#include <QLineEdit>
#include <QWidget>

class QTimer;

// CrumbEditFace — 语料地址栏编辑件(0xd8 字节,FUN_0054e188 ctor 未转写)
// 的行为面(批 275)。字段证据:
//   +0x74 byte 激活位 / +0xb8 QTimer*(FUN_0054d22a 两处消费)。
class CrumbEditFace : public QLineEdit {
	Q_OBJECT
public:
	// FUN_0054d22a(197B,0017.c:19741)激活切换:
	//   +0x74 = active;!active → +0xb8 timer->start();active →
	//   setSelection(0);cursor = QCursor(active ? IBeam(4) : Arrow(0));
	//   setAttribute(2, !active);update()。
	void setActive(bool active);

private:
	quint8 m_flags74 = 0;        // +0x74
	QTimer *m_timerB8 = nullptr; // +0xb8
};

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

// AddressBarFace — 语料 AddressBar(BreadCrumb 子类,toolbar kind 5)基面。
// ctor FUN_005211fe(162B,0016.c:15189):
//   BreadCrumb ctor(FUN_00548546)@005211fe → vtable AddressBar →
//   objectName "AddressBar"@00521242-57 → FUN_00521178(134B)接线:
//   connect(edit, 信号 FUN_008f826e(smeta 0119a540 = edit 类)→ this,
//   FUN_005247c5)@00521178。
class AddressBarFace : public BreadCrumbFace {
	Q_OBJECT
public:
	explicit AddressBarFace(QWidget *parent = nullptr); // FUN_005211fe
};
