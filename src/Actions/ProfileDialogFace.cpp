// ProfileDialogFace.cpp — ProfileDialog(批 434 / 460)
#include "ProfileDialogFace.h"

#include <QCoreApplication>
#include <QTranslator>

// FUN_006cf13c(240B)ctor 真身
ProfileDialogFace::ProfileDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006cf13c
{
	setWindowTitle(QStringLiteral("Choose Profiles Directory")); // tr(0xc9e135)
	build();                 // @FUN_006ce668(602B)
	applyTheme();            // @FUN_006cf012(131B)
	installAutoTranslator(); // @FUN_006cf09e(137B)
}

// FUN_006ce668(602B)接线真身(结构段)
void ProfileDialogFace::build()
{
	// 三路 connect(+0x30 / +0x38 / +0x70),闭包 FUN_006b2420 /
	//   FUN_006ce130 / FUN_006cf580 — cited
}

// FUN_006cf012(131B)应用主题真身
void ProfileDialogFace::applyTheme()
{
	// FUN_00760ffe(qApp, "dige-black")(主题装载面) — cited
}

// FUN_006cf09e(137B)装翻译器真身(结构段)
void ProfileDialogFace::installAutoTranslator()
{
	m_translator90 = new QTranslator(this);      // @006cf0da(0x20 + FUN_006368e6)
	// 语料以 "auto" 初始化(FUN_006368e6(t, this, "auto")) — cited
	if (m_translator90 != nullptr)
		QCoreApplication::installTranslator(m_translator90); // @006cf0fc
}
