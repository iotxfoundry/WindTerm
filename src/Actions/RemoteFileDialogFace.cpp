// RemoteFileDialogFace.cpp — RemoteFileDialog(批 435)
#include "RemoteFileDialogFace.h"

// FUN_006d8cfe(247B,0022:5146)ctor 真身
RemoteFileDialogFace::RemoteFileDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d8cfe
{
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006d5eec
	build2(); // @FUN_006d6bf2
}

// FUN_006d5eec 建造 — 结构段(cited)
void RemoteFileDialogFace::build() {}

// FUN_006d6bf2 建造 — 结构段(cited)
void RemoteFileDialogFace::build2() {}
