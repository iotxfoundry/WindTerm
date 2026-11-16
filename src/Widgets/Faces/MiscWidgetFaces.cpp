// MiscWidgetFaces.cpp — 计数框 / 光标形状 / 后退快捷键(批 492/493)
#include "MiscWidgetFaces.h"

// s_CountSpinbox_73bea0(278B)ctor
CountSpinboxFace::CountSpinboxFace(QWidget *parent)
	: QWidget(parent)
{
	// 基类与字段未取证 — cited
}

// s_CursorShape_7cf5d0(619B)ctor
CursorShapeFace::CursorShapeFace(QWidget *parent)
	: QWidget(parent)
{
	// +0x80 字段 + 619B 体 — cited
}

// s_BackwardButton_53e936(753B)**QShortcut** 族 ctor
BackwardShortcutFace::BackwardShortcutFace(QWidget *parent)
	: QWidget(parent)
{
	// 语料基类为 QShortcut(非 QWidget):以承接面保留,字段 +0x38..+0x58 — cited
}
