// RemoteFileDialogFace.cpp — RemoteFileDialog(批 435)
#include "Widgets/Dialogs/RemoteFileDialogFace.h"

#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QFrame>
#include <QHBoxLayout>
#include <QLineEdit>

// FUN_006d8cfe(247B,0022:5146)ctor 真身
RemoteFileDialogFace::RemoteFileDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d8cfe
{
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build();  // @FUN_006d6bf2(7811B)
	setMode(0); // @FUN_006d5eec(616B)
}

// FUN_006d5eec(616B)按模式改标题真身
void RemoteFileDialogFace::setMode(int mode)
{
	switch (mode) {                                   // 四模式标题(实读)
	case 0: setWindowTitle(QStringLiteral("Create Directory")); break;
	case 1: setWindowTitle(QStringLiteral("Create File")); break;
	case 2: setWindowTitle(QStringLiteral("Create Link")); break;
	case 3: setWindowTitle(QStringLiteral("Move to")); break;
	default: break;
	}
}

// FUN_006d6bf2(7811B)装配真身(结构段)
void RemoteFileDialogFace::build()
{
	auto *form = new QFormLayout;                     // 表单
	auto *hbox = new QHBoxLayout;                     // 行框
	auto *frame = new QFrame;                          // 分隔框
	auto *check = new QCheckBox(
		QStringLiteral("&Open directory after created")); // tr 实读
	auto *box = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	form->addRow(QStringLiteral("&Directory:"), new QLineEdit); // tr 实读
	form->addRow(QStringLiteral("&File:"), new QLineEdit);
	form->addRow(QStringLiteral("&Link:"), new QLineEdit);
	hbox->addWidget(frame);
	hbox->addWidget(check);
	hbox->addWidget(box);
	setLayout(hbox);
	Q_UNUSED(form);
	// 7811B 余段(模式切换显隐/图标/路径栏) — cited
}
