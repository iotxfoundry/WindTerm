#pragma once

#include <QDialog>

// SettingDialogFace — 语料 SettingDialog(批 437)。
//
// ctor FUN_006ea66e(318B,0022:14440) asm 实测:
//   QDialog(parent, 0) → vtable SettingDialog_vtable + 副 011a4230 →
//   setWindowTitle(tr("Settings")(0xc9f084)) →
//   setAttribute(0x37, true) →
//   字段 +0x30 = param_2 →
//   字段 +0x38 = 0 →
//   字段 +0x60 = 0 →
//   字段 +0x68 = 0 →
//   build()(FUN_006dd310) + build2()(FUN_006ea37a)。
//   另有两串:tr(\"Terminal Settings\")(0xc9f07b) / tr(\"Editor Settings\")(0xc9f06b)
class SettingDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SettingDialogFace(QWidget *parent = nullptr);
	// 两腿分工(批 471):
	//   FUN_006dd310(**56B**)=短腿:仅动 **+0x50**(单字段,疑为页签/栈切换)。
	//   FUN_006ea37a(683B)=**装配**:QVBoxLayout + QHBoxLayout + QLabel +
	//     **QStackedWidget** + QDialogButtonBox;文案实读 **"Close"** 与
	//     **"Requires a restart to take affect"**(原版拼写 affect,非 effect)。
	void build();    // FUN_006ea37a(683B)
	void shortLeg(); // FUN_006dd310(56B)

protected:
	QWidget *m_f48 = nullptr; QWidget *m_f50 = nullptr;
	QWidget *m_f58 = nullptr; QWidget *m_f60 = nullptr;
};

