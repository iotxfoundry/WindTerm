#ifndef SESSIONS_TRANSFERS_MODEM_H
#define SESSIONS_TRANSFERS_MODEM_H

#pragma once

// Modem — 文件传输协议驱动基类(XMODEM/YMODEM/ZMODEM 的公共腿)。
// 类名取自 RTTI:`tools/re/vtable_scan.py WindTerm --vtable 0x118e6f0` → "Modem"
// (同族 0x11a6de8)。ctor 链:0x0079a842(基类) → 0x0079c8a0(XYModem) /
// 0x007a0160(ZModem)。
//
// 字段偏移由 ctor 0x0079a842 逐句读回(Modem 占 0x00..0x4f):
//   +0x10 { int percent; int width; QElapsedTimer *timer; }   ← 0x0079a5bc 初始化
//   +0x20 QObject *session  (同时作为 QObject parent)
//   +0x28 QObject *writer   (会话写入面;信号挂在它上面)
//   +0x30 int     uploading (0 = 下载/收包,1 = 上传/发包)
//   +0x31 bool    lineBreak (上一段文本已以换行结尾)
//   +0x38 QString receiveFileName
//   +0x40 QString receiveDir
//   +0x48 QList<QVariant> sendFiles
//
// 虚拟面按 Ghidra vtN 命名(vptr = 0x118e700):
//   vt12 @0079a5d8 cancel()    — 基类实装
//   vt13 @0079ba70 reset()     — 基类纯虚
//   vt14 @0079ba76 isRunning() — 基类纯虚
//   vt15 @0079f16e feed()      — 基类纯虚
//   vt16 @0079f1ac sendInit()  — 基类纯虚
// 依据:Modem 的 vtable 0x11a6de8 在 vt13..vt16 四槽写 __cxa_pure_virtual
// (0x00bec350),vt12 指向实体 0x0079a5d8。

#include <QByteArray>
#include <QElapsedTimer>
#include <QList>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariant>

class Modem : public QObject {
	Q_OBJECT

public:
	// 信号表(metaobject 0x011a6e80;声明序即索引 0/1/2)。
	// 发射器:0x0090e888(idx0) / 0x0090e8bc(idx1) / 0x0090e8e6(idx2)。
	Modem(QObject *session, QObject *writer); // 0079a842

	void transferProgress(qlonglong done, qlonglong total); // 0079ac26
	void cancel();                                          // 0079a5d8(vt12)

	// ---- 派生必须实现 ----------------------------------------------------
	virtual void reset() = 0;                // vt13
	virtual bool isRunning() const = 0;      // vt14
	virtual void feed(QByteArray &data) = 0; // vt15
	virtual void sendInit() = 0;             // vt16

signals:
	void finished(bool success);           // idx 0
	void showText(const QByteArray &text); // idx 1
	void started(const QString &fileName); // idx 2

protected:
	// ---- 显示腿 ----------------------------------------------------------
	void appendText(QString text);                   // 0079a8be path_normalizeSep
	void showError(QString message, bool terminate); // 0079a9de
	void finish(bool success);                       // 0079aba0
	void emitStarted();                              // 0079ac1c
	void onFinished(bool success);                   // 0079a370(槽腿)
	void onShowText(const QByteArray &text);         // 0079a3b4(槽腿)

	struct Progress {
		int percent = -1;               // +0x10
		int width = -1;                 // +0x14
		QElapsedTimer *timer = nullptr; // +0x18
		void reset();                   // 0079a5bc / 0079a598
	};

	void wireSignals(); // 0079a6aa

	Progress m_progress;          // +0x10
	QObject *m_session = nullptr; // +0x20
	QObject *m_writer = nullptr;  // +0x28
	bool m_uploading = false;     // +0x30
	bool m_lineBreak = false;     // +0x31
	QString m_receiveFileName;    // +0x38
	QString m_receiveDir;         // +0x40
	QList<QVariant> m_sendFiles;  // +0x48
};

#endif // SESSIONS_TRANSFERS_MODEM_H
