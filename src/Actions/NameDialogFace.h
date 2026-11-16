#pragma once

#include <QDialog>

class QFormLayout;

// NameDialogFace — 语料 NameDialog(通用"Create <名>"输入框,批 347)。
//
// ctor FUN_006bd7f6(319B,0021.c:50242) asm 实测(0x6bd7f6..0x6bd8xx):
//   QDialog(parent, 0) → vptr = 0x11a13b8(asm: mov $0x11a13a8 + lea 0x10)/
//   副 vptr = 0x11a1590(+0x1e8)→ +0x30 = byte 0(bool)→ +0x38 = 名字 QString
//   (引用计数拷贝)→ windowTitle = tr("Create")(0xc9da96) + " "(0xd992f9) +
//   名字(+0x38)(即 "Create <名>")→ setAttribute(0x37, true)→
//   buildInputs()(FUN_006bd34a,449B)+ buildButtons()(FUN_006bd50c,670B)。
class NameDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit NameDialogFace(const QString &name, QWidget *parent = nullptr); // FUN_006bd7f6

	const QString &name38() const { return m_name38; } // +0x38

protected:
	bool m_f30 = false;   // +0x30
	QString m_name38;     // +0x38
};

// FUN_006bd250(242B,0021.c:50039)通用"表单加一行 + 重排 Tab 序"真身:
//   form = dlg->findChild<QFormLayout*>();空 → 返;
//   form->addRow(field);
//   prev = form->itemAt(0, FieldRole)->widget();
//   for (i = 1; i < form->rowCount(); ++i)
//     cur = form->itemAt(i, FieldRole)->widget();setTabOrder(prev, cur);prev = cur;
void nameDialogAddFormRow(QWidget *dlg, QWidget *field);
