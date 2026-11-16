// BackwardShortcutFace.cpp —— 从 Widgets/Faces/MiscWidgetFaces 拆出(按 UI 架构归位)
#include "Actions/BackwardShortcutFace.h"

// s_BackwardButton_53e936(753B)**QShortcut** 族 ctor
BackwardShortcutFace::BackwardShortcutFace(QWidget *parent)
	: QWidget(parent)
{
	// 语料基类为 QShortcut(非 QWidget):以承接面保留,字段 +0x38..+0x58 — cited
}
