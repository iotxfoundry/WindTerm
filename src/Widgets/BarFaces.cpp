// BarFaces.cpp — QuickBar / TransferBar(批 446/447)
#include "BarFaces.h"

// FUN_0056e26e(402B)QuickBar ctor 真身
QuickBarFace::QuickBarFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @0056e26e
	, m_host30(parent)                    // +0x30 = 父
{
	setObjectName(QStringLiteral("QuickBar"));  // @0056e2d0(strlen 8)
	// King__registerBarsAndPanes("QuickBar")(注册 + setWindowTitle) — cited
}

// FUN_005858fe(449B)TransferBar ctor 真身
TransferBarFace::TransferBarFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @005858fe
{
	setObjectName(QStringLiteral("TransferBar")); // @00585969(strlen 0xb)
	// King__registerBarsAndPanes("TransferBar")(注册 + setWindowTitle) — cited
}
