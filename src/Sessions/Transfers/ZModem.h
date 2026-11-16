#ifndef SESSIONS_TRANSFERS_ZMODEM_H
#define SESSIONS_TRANSFERS_ZMODEM_H

#pragma once

// ZModem — ZMODEM 协议驱动:起外部 lrzsz 进程(rz/sz)在独立线程里收发。
// RTTI 类名 "ZModem"(vtable 0x11a6ec8)。ctor 0x007a0160 / dtor 0x007a029e /
// 启动腿 zmodem_init 0x007a04c2(2636B)。
// metaobject:super = Modem(0x011a6e80),自有方法 `modemRead`(1 参)。
//
// 字段(接在 Modem 之后 0x50 起;由 ctor 0x007a0160 + zmodem_init + vt13 读回):
//   +0x50 int        = 0
//   +0x58 QString    程序**全路径**(applicationDirPath() + "/vendors/lrzsz/xx",
//                    再 QDir::toNativeSeparators)
//   +0x60 QString    程序**名**(错误文案 "%1" 用)
//   +0x68 QThread *  工作线程(vt13:quit + wait + deleteLater)
//   +0x70 QSharedPointer<ModemProcess> 内部块 d
//   +0x78 …                            内部块 value(裸指针)
//   +0x80 int        state(2 = 运行中)
//   +0x88 QString
//   +0x90 QStringMatcher(ctor 实读:由 "transfer"@0xca3c26 构造)
//   +0x4a8 QRegularExpression *   文件名抓取
//   +0x4b0 QRegularExpression *   程序名抓取
//   +0x4b8 QRegularExpression *   进度抓取
//
// 虚拟面(vt13/vt14/vt15 有实体,vt16 = zmodem_init):
//   vt16 的签名与 XYModem 的 xymodem_sendInit 不同(这里带 direction + 参数表),
//   故**不上升为 Modem 的纯虚**,各带各的。

#include "Sessions/Transfers/Modem.h"

#include <QRegularExpression>
#include <QSharedPointer>
#include <QStringList>
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

	// zmodem_init(0x007a04c2)启动腿:
	//   direction == 1 → 发送(`/vendors/lrzsz/sz`),参数表追加待发文件列表
	//   direction != 1 → 接收(`/vendors/lrzsz/rz`),参数表追加接收文件名
	//   两向都先追加 "-b" "-e" "-v",再 reset(),最后起线程执行。
	void startTransfer(int direction, QStringList &args);

	// 进程侧状态文案(0..5),末尾统一 showError(…, true)。
	void stateText(int code); // 0079fd7e

	// QProcess::stateChanged 槽(FUN_0079fb5c,245B):
	//   +0x50 记「已进入 Running」;从 Running(2) 掉到 NotRunning(0) 且已
	//   Running 过 → "Process %1 crashed before the transfer is completed."
	//   + finish(false)。末尾无条件 +0x80 = state。
	void setProcessState(int state);

	// 进程输出读槽(FUN_007a0f86,3062B):
	//   channel 0(stdout)→ 原样上行给会话(writeData)
	//   channel 1(stderr)→ 累积到 +0x88,抹掉程序路径,按 [\r\n] 切行,
	//                       每行做进度/文件名匹配后显示
	void onProcessReadyRead(int channel);

signals:
	void modemRead(const QByteArray &data); // metaobject 自有方法(→ 进程 stdin)

private:
	void setupPatterns(); // zmodem_init 内三段 QRegularExpression

	int m_f50 = 0;                        // +0x50
	QString m_path58;                     // +0x58 程序全路径
	QString m_name60;                     // +0x60 程序名
	QThread *m_thread68 = nullptr;        // +0x68
	QSharedPointer<ModemProcess> m_process70; // +0x70/+0x78
	int m_state80 = 0;                    // +0x80
	QString m_f88;                        // +0x88
	QStringMatcher m_matcher90;           // +0x90
	QRegularExpression *m_reA8 = nullptr; // +0x4a8
	QRegularExpression *m_reB0 = nullptr; // +0x4b0
	QRegularExpression *m_reB8 = nullptr; // +0x4b8
};

#endif // SESSIONS_TRANSFERS_ZMODEM_H
