#ifndef SESSIONS_TRANSFERS_MODEMPROCESS_H
#define SESSIONS_TRANSFERS_MODEMPROCESS_H

#pragma once

// ModemProcess — 外部传输程序(lrzsz 的 rz/sz 或 zsz/sz)的进程封装。
// RTTI 类名 "ModemProcess"(vtable 0x11a6fa8);ctor = termproc_init(0x007a230e,
// 869B),dtor = 0x007a200e(249B)。基类 = QProcess(ctor 首句实读)。
// metaobject 自有方法:`readyRead`(1 参)。
//
// 字段:
//   +0x10 QMutex         *(8B,operator_new(8))
//   +0x18 QWaitCondition *(8B)
//   +0x20 bool           启动完成旗标(0x007a26be 置 1 + wakeOne)
//   +0x24 int            mode(由 ctor 第 1 实参写入;== 1 时才做 matcher 匹配)
//   +0x28 bool           matcher 命中旗标(0x007a26d8 置 1)
//   +0x30 QByteArray     stdout 累积
//   +0x38 QByteArray     stderr 累积
//   +0x40 QByteArrayMatcher *(0x410B)

#include <QByteArray>
#include <QMutex>
#include <QProcess>
#include <QWaitCondition>

class QByteArrayMatcher;

class ModemProcess : public QProcess {
	Q_OBJECT

public:
	explicit ModemProcess(int mode, QObject *parent = nullptr); // termproc_init
	~ModemProcess() override;                                  // 007a200e

	QByteArray takeStdout(); // 007a217c
	QByteArray takeStderr(); // 007a2120

	void signalFinished();                  // 007a26be
	void startProcess();                    // 007a26ce
	void writeData(const QByteArray &data); // 007a26d8
	void clearFlag();                       // 007a2720

private:
	void wire(); // 007a2214

	QMutex *m_mutex10 = nullptr;            // +0x10
	QWaitCondition *m_cond18 = nullptr;     // +0x18
	bool m_f20 = false;                     // +0x20
	int m_mode24 = 0;                       // +0x24
	bool m_matched28 = false;               // +0x28
	QByteArray m_out30;                     // +0x30
	QByteArray m_err38;                     // +0x38
	QByteArrayMatcher *m_matcher40 = nullptr; // +0x40
};

#endif // SESSIONS_TRANSFERS_MODEMPROCESS_H
