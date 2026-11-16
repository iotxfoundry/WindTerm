#pragma once

#include <QWidget>

// 补充(批 490):CompleterButton(s_CompleterButton_58dad4,819B)——补全下拉钮,
//   字段 **+0x40**。
class CompleterButtonFace : public QWidget {
	Q_OBJECT
public:
	explicit CompleterButtonFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f40 = nullptr; // +0x40
};
