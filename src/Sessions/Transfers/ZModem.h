#ifndef SESSIONS_TRANSFERS_ZMODEM_H
#define SESSIONS_TRANSFERS_ZMODEM_H

#pragma once

// ZModem — ZMODEM 协议驱动(经外部 lrzsz 进程收发,见 ModemProcess)。
// RTTI 类名 "ZModem"(vtable 0x11a6ec8)。ctor 0x007a0160 / dtor 0x007a029e。
// metaobject:super = Modem(0x011a6e80),自有方法 `modemRead`(1 参)。
//
// 字段(接在 Modem 之后):
//   +0x50 int       = 0
//   +0x58 QString   (工作目录/参数面)
//   +0x60 QString   (进程名,错误文案 "%1" 用,见 stateText)
//   +0x68 QThread   *thread        (vt13:quit + wait + deleteLater)
//   +0x70 QByteArray pending       (线程待处理的输入)
//   +0x78 ModemProcess *process    (QProcess 子类;vt13 里 deleteLater)
//   +0x80 int       state          (2 = 运行中)
//   +0x88 QString
//   +0x90 QStringMatcher           (ctor 实读:由 "transfer"@0xca3c26 构造)
//   +0x4a8/+0x4b0/+0x4b8 QRegularExpression *(dtor 逐个删)

#include "Sessions/Transfers/Modem.h"

#include <QRegularExpression>
#include <QStringMatcher>

class QThread;
class ModemProcess;

class ZModem : public Modem {
	Q_OBJECT

public:
	explicit ZModem(QObject *session, QObject *writer); // 007a0160
	~ZModem() override;                                // 007a029e

	void reset() override;                // vt13 0079fc66
	bool isRunning() const override;      // vt14 0079fd3e
	void feed(QByteArray &data) override; // vt15 007a0134
	void sendInit() override;             // vt16 = zmodem_init 007a04c2(cited)

	// 进程侧状态文案(0..5),末尾统一 showError(…, true):
	//   0 "Process %1 failed to start."   1 "Process %1 crashed."
	//   2 "Process %1 timeout."           3 "…read from the %1 process."
	//   4 "…write to the %1 process."     5 "…unknown error … in %1 process."
	void stateText(int code); // 0079fd7e

signals:
	void modemRead(const QByteArray &data); // metaobject 自有方法

private:
	int m_state80 = 0;              // +0x80
	QThread *m_thread68 = nullptr;  // +0x68
	QByteArray m_pending70;         // +0x70
	ModemProcess *m_process78 = nullptr; // +0x78
	QString m_name60;               // +0x60
	QString m_dir58;                // +0x58
	QString m_f88;                  // +0x88
	QStringMatcher m_matcher90;     // +0x90
	QRegularExpression *m_reA8 = nullptr; // +0x4a8
	QRegularExpression *m_reB0 = nullptr; // +0x4b0
	QRegularExpression *m_reB8 = nullptr; // +0x4b8
};

#endif // SESSIONS_TRANSFERS_ZMODEM_H
