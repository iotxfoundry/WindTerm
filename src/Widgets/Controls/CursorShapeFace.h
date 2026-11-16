#pragma once

#include <QWidget>

// s_CursorShape_7cf5d0(619B):光标形状选择,字段 **+0x80**。
class CursorShapeFace : public QWidget {
	Q_OBJECT
public:
	explicit CursorShapeFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f80 = nullptr; // +0x80
};
