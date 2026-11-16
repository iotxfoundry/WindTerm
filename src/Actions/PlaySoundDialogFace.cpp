// PlaySoundDialogFace.cpp — PlaySoundDialog(批 434)
#include "PlaySoundDialogFace.h"

// FUN_006cc63e(175B,0021:59501)ctor 真身
PlaySoundDialogFace::PlaySoundDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006cc63e
{
	setWindowTitle(QStringLiteral("Play Sound")); // tr(0xc9fb4c)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006cbbbe
	build2(); // @FUN_006cc276
}

// FUN_006cbbbe 建造 — 结构段(cited)
void PlaySoundDialogFace::build() {}

// FUN_006cc276 建造 — 结构段(cited)
void PlaySoundDialogFace::build2() {}
