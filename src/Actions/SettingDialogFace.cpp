// SettingDialogFace.cpp — SettingDialog(批 437)
#include "SettingDialogFace.h"

// FUN_006ea66e(318B,0022:14440)ctor 真身
SettingDialogFace::SettingDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006ea66e
{
	setWindowTitle(QStringLiteral("Settings")); // tr(0xc9f084)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006dd310
	build2(); // @FUN_006ea37a
}

// FUN_006dd310 建造 — 结构段(cited)
void SettingDialogFace::build() {}

// FUN_006ea37a 建造 — 结构段(cited)
void SettingDialogFace::build2() {}
