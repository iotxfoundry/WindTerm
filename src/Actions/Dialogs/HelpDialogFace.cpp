// HelpDialogFace.cpp — VcXsrv 帮助对话框(批 478)
#include "Actions/Dialogs/HelpDialogFace.h"

#include <QCoreApplication>
#include <QDialogButtonBox>
#include <QTextEdit>
#include <QVBoxLayout>

// FUN_006ebd28(794B)工厂型构建真身
HelpDialogFace::HelpDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006ebd51(new 0x30)
{
	build(); // @006ebd28
}

// 路径:applicationDirPath() + "/vendors/vcxsrv/help.md"(实读)
QString HelpDialogFace::helpFilePath()
{
	return QCoreApplication::applicationDirPath()
		+ QStringLiteral("/vendors/vcxsrv/help.md");
}

// FUN_006ebd28(794B)装配真身(结构段)
void HelpDialogFace::build()
{
	m_text30 = new QTextEdit(this);                     // @006ebd68(0x30)
	auto *box = new QDialogButtonBox(QDialogButtonBox::Close, this); // @006ebd86(0x200000)
	auto *vbox = new QVBoxLayout;                       // @006ebd9b(0x20)
	vbox->addWidget(m_text30);
	vbox->addWidget(box);
	setLayout(vbox);
	// QFile 读 help.md → 填入正文(余段 cited)
}
