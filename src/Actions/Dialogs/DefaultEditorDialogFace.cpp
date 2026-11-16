// DefaultEditorDialogFace.cpp — DefaultEditorDialog(批 429)
#include "Actions/Dialogs/DefaultEditorDialogFace.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QTabWidget>

// FUN_006b22e6(165B,0021:42122)ctor 真身
DefaultEditorDialogFace::DefaultEditorDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b22e6
{
	setWindowTitle(QStringLiteral("Default Editor")); // tr(0xc9d4db)

	build(); // @FUN_00962
}


