#pragma once

#include <QDialog>

class QDialogButtonBox;
class QFormLayout;
class QLabel;

// NameDialogFace — 语料 NameDialog(通用"Create <名>"输入框,批 347)。
//
// ctor FUN_006bd7f6(319B,0021.c:50242) asm 实测(0x6bd7f6..0x6bd8xx):
//   QDialog(parent, 0) → vptr = 0x11a13b8(asm: mov $0x11a13a8 + lea 0x10)/
//   副 vptr = 0x11a1590(+0x1e8)→ +0x30 = byte 0(bool)→ +0x38 = 名字 QString
//   (引用计数拷贝)→ windowTitle = tr("Create")(0xc9da96) + " "(0xd992f9) +
//   名字(+0x38)(即 "Create <名>")→ setAttribute(0x37, true)→
//   build()(FUN_006bd50c,670B)+ wire()(FUN_006bd34a,449B)。
class NameDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit NameDialogFace(const QString &name, QWidget *parent = nullptr); // FUN_006bd7f6

	const QString &name38() const { return m_name38; } // +0x38

	// FUN_006bd50c(670B,0021.c:50140)装配(逐句实读):
	//   vbox = QVBoxLayout(0x20);form = QFormLayout(0x20, 父 0);
	//   **+0x48 = QLabel(tr("Enter a name for the new %1.")(0xc9da79)
	//     .arg(+0x38 名))**;
	//   **+0x50 = new 0x70 + searchEdit_init(w, 0)**(名字输入);
	//   **+0x40 = QDialogButtonBox(0x30, 0x400400 /*Ok|Cancel*/)**;
	//   Ok 按钮 setText(tr("Create")(0xc9da96));
	//   form->addRow(tr("&Name:")(0xc9da9d), +0x50);
	//   setLayout(vbox);FUN_0075c132(0.35 /*0x3fd6666666666666*/, 0, qApp, this)。
	// FUN_006bdced(65B,0021.c:50472)文本变化闭包:
	//   **+0x30 != 0 → 直返**(+0x30 = "允许空名"旗标);
	//   否则 FUN_006bdbc6(this, text 长度 != 0)(Ok 按钮 setEnabled)。
	//   ⇒ 名字为空时 Ok 灰显。
	void onTextChanged(const QString &text);

	// FUN_006bdbc6(29B,0021.c:50407)Ok 按钮启停真身:
	//   setEnabled(button(+0x40, 0x400 /*Ok*/) != 0)。
	void setAcceptEnabled(bool on);

	// FUN_006bdbe4(249B,0021.c:504xx)"允许空名"置位:
	//   与 +0x30 同值 → 直返;否则 +0x30 = 入参;
	//   入参为 0 → 以编辑框当前文本重算 Ok 启停(setAcceptEnabled(文本非空));
	//   入参非 0 → tr("Optional")(0xc9dabf 实读) → 写入编辑框占位(放开校验提示)。
	void build();   // FUN_006bd50c
	void wire();    // FUN_006bd34a(449B)

protected:
	bool m_f30 = false;              // +0x30
	QString m_name38;                // +0x38
	QDialogButtonBox *m_buttons40 = nullptr; // +0x40(0x30,0x400400)
	QLabel *m_label48 = nullptr;     // +0x48(0x30,提示行)
	QWidget *m_edit50 = nullptr;     // +0x50(0x70 searchEdit)
};

// FUN_006bd250(242B,0021.c:50039)通用"表单加一行 + 重排 Tab 序"真身。
// 实参三路 asm 实测(0x6bd25c mov %rsi→rbp / 0x6bd25f mov %rdx→r12):
//   (dlg, 标签 QString, 字段 QWidget*) → addRow(标签, 字段)。
//   form = dlg->findChild<QFormLayout*>()(空名递归);空 → 返;
//   form->addRow(label, field);
//   prev = form->itemAt(0, FieldRole)->widget();
//   for (i = 1; i < rowCount(); ++i)(itemAt(i, FieldRole)→widget())setTabOrder。
void nameDialogAddFormRow(QWidget *dlg, const QString &label, QWidget *field);
