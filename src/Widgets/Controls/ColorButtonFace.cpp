// ColorButtonFace.cpp — 颜色按钮(批 450)
#include "ColorButtonFace.h"

// s_ColorButton_53904e(582B)ctor 真身
ColorButtonFace::ColorButtonFace(QWidget *parent)
	: QPushButton(parent)                     // @0053904e
{
	setObjectName(QStringLiteral("ColorButton")); // @0053909c(strlen 0xb)
	setStyleSheet(styleSheet()
		+ QStringLiteral("QPushButton { text-align: left; }")); // @005391xx(0x21 字节)
	// 取色/绘制腿 — cited
}
