// TextMarkDialogFace.cpp — TextMarkDialog(批 438)
#include "TextMarkDialogFace.h"

// FUN_006f1036(175B,0022:18703)ctor 真身
TextMarkDialogFace::TextMarkDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006f1036
{
	setWindowTitle(QStringLiteral("Text Mark")); // tr(0xc9faaa)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
}
