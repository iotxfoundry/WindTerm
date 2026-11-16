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
//   @00591007 +0x60 QCheckBox(tr("&Auto login next time")(0xc8acf2));
//   @0059105c +0x68 QCheckBox(tr("&Remember this step")(0xc8ad08));
//   @00591096 +0x70 QLabel(空文本);@005910d0 +0x78 QLabel(tr("Login")
//     (0xd0d9ac))→ setAlignment(0x84 = AlignCenter)@005910f6 →
//   +0x60 setChecked(实参折叠)→ FUN_00590ee0(this)(cited)→
//   HBox: addWidget(+0x60)/addWidget(+0x68)/addWidget(+0x50 按钮盒)→
//   QFrame: setFrameShape(4 = HLine)/setFrameShadow(折叠)— 余段 cited。
class LoginWizardFace : public QDialog {
	Q_OBJECT
public:
	explicit LoginWizardFace(QWidget *parent = nullptr);
	void setupUi();

private:
	QDialogButtonBox *m_buttons50 = nullptr; // +0x50
	QCheckBox *m_check60 = nullptr;          // +0x60 "&Auto login next time"
	QCheckBox *m_check68 = nullptr;          // +0x68 "&Remember this step"
	QLabel *m_label70 = nullptr;            // +0x70(空文本)
	QLabel *m_label78 = nullptr;            // +0x78 "Login" 居中
	QFrame *m_frame = nullptr;              // cited 槽
	QStackedWidget *m_stack = nullptr;      // cited 槽
	QFormLayout *m_form = nullptr;          // cited 槽
	QHBoxLayout *m_hbox = nullptr;          // HBox(复选/按钮盒)
	QVBoxLayout *m_vbox = nullptr;          // cited 槽
};
