#pragma once

#include <QPushButton>

// ColorButtonFace — 语料 **ColorButton**(批 450)。
//
// ctor s_ColorButton_53904e(582B,0017.c:5452) asm 实测:
//   QPushButton(parent) → vtable **ColorButton_vtable** + 副 01193fe0 →
//   **objectName = "ColorButton"**(strlen 0xb)→
//   **styleSheet = 原样式 + "QPushButton { text-align: left; }"**(33 字节实读)→
//   余段(取色/绘制腿)。
//   用途:MarkStyleWidget 的 +0x38 颜色钮(FUN_00703900),以及 SessionDialog
//   的同族槽。
class ColorButtonFace : public QPushButton {
	Q_OBJECT
public:
	explicit ColorButtonFace(QWidget *parent = nullptr);
};
