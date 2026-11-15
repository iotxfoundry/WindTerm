#pragma once

#include <QDialog>

class QCheckBox;
class QDialogButtonBox;
class QFormLayout;
class QFrame;
class QHBoxLayout;
class QLabel;
class QStackedWidget;
class QVBoxLayout;

// LoginWizardFace — 语料 SSH 登录向导装配面(批 319)。
// LoginWizard_setupUi(1088B,0018.c:...):
//   @00590f20 +0x50 = QDialogButtonBox(标准按钮 0x400400 = Ok|Cancel);
//   @00590f53 Ok 按钮 setText(tr("Continue")(0xc8ace9));
//   @00590fa5 Cancel 按钮 setText(tr("&Cancel")(0xc8a1b5));
//   其余:QCheckBox/QHBoxLayout/QFrame/QFormLayout/QStackedWidget/QVBoxLayout
//   装配腿 — cited(1088B 余段未逐句核对)。
class LoginWizardFace : public QDialog {
	Q_OBJECT
public:
	explicit LoginWizardFace(QWidget *parent = nullptr);
	void setupUi();

private:
	QDialogButtonBox *m_buttons50 = nullptr; // +0x50
	QCheckBox *m_check = nullptr;            // cited 槽
	QLabel *m_label = nullptr;              // cited 槽
	QFrame *m_frame = nullptr;              // cited 槽
	QStackedWidget *m_stack = nullptr;      // cited 槽
	QFormLayout *m_form = nullptr;          // cited 槽
	QHBoxLayout *m_hbox = nullptr;          // cited 槽
	QVBoxLayout *m_vbox = nullptr;          // cited 槽
};
