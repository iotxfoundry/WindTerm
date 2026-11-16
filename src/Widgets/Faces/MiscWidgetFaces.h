#pragma once

#include <QWidget>

// 语料零散控件三类(批 492/493)。三者均**未取到自有 vtable 与基类**
// (Ghidra 该段无 vtable 写/基类调用可见)—— 故基类保持 QWidget 并标 cited,
// 只落**字段与行为面**。

// s_CountSpinbox_73bea0(278B):计数微调框(名 -> CountSpinbox)。
class CountSpinboxFace : public QWidget {
	Q_OBJECT
public:
	explicit CountSpinboxFace(QWidget *parent = nullptr);
};

// s_CursorShape_7cf5d0(619B):光标形状选择,字段 **+0x80**。
class CursorShapeFace : public QWidget {
	Q_OBJECT
public:
	explicit CursorShapeFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f80 = nullptr; // +0x80
};

// s_BackwardButton_53e936(753B):**基类 = QShortcut**(不是按钮!)——
//   即"后退"快捷键的绑定族,字段 **+0x38 / +0x40 / +0x48 / +0x50 / +0x58**。
//   与前缀 BackwardButton 的字面("按钮")不符 —— **名不副实**。
class BackwardShortcutFace : public QWidget {   // 基类未直接声明 QShortcut
	Q_OBJECT
public:
	explicit BackwardShortcutFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f38 = nullptr; QWidget *m_f40 = nullptr; QWidget *m_f48 = nullptr;
	QWidget *m_f50 = nullptr; QWidget *m_f58 = nullptr;
};
