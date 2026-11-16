#pragma once

#include <QLineEdit>

class QTimer;

// CrumbEditFace — 语料地址栏编辑件(0xd8 字节,FUN_0054e188 ctor 未转写)
// 的行为面(批 275)。字段证据:
//   +0x74 byte 激活位 / +0xb8 QTimer*(FUN_0054d22a 两处消费)。
class CrumbEditFace : public QLineEdit {
	Q_OBJECT
public:
	// FUN_0054d22a(197B,0017.c:19741)激活切换:
	//   +0x74 = active;!active → +0xb8 timer->start();active →
	//   setSelection(0);cursor = QCursor(active ? IBeam(4) : Arrow(0));
	//   setAttribute(2, !active);update()。
	void setActive(bool active);

private:
	quint8 m_flags74 = 0;        // +0x74
	QTimer *m_timerB8 = nullptr; // +0xb8
};
