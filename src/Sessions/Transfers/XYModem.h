#ifndef SESSIONS_TRANSFERS_XYMODEM_H
#define SESSIONS_TRANSFERS_XYMODEM_H

#pragma once

// XYModem — XMODEM/YMODEM 协议实现(含收发重试与落盘)。
// RTTI 类名 "XYModem"(vtable 0x118e700 / 0x118f2a0 / 0x118f2b8);XModem / YModem
// 是它的协议变体(0x118f2f8 / 0x118f390,见 XModem.cpp / YModem.cpp)。
//
// 字段(整体接在 Modem 之后,起始 +0x50;来自 ctor 0x0079c8a0 与 0x0079c6de):
//   +0x50 bool     dirOnly        (真 → 目标是目录,名字由报文头给)
//   +0x51 bool     trimSub        (落盘前裁尾部 SUB)
//   +0x52 char     subChar = 0x1a (ctor 实读 0x1a)
//   +0x53 quint8   crcMode        (0 = CRC16,1 = 8bit 和)
//   +0x54 bool     receiving      (!dirOnly)
//   +0x56 quint16  = 0x80         (块/窗口参数)
//   +0x58 quint8   state          (6 = 空闲/结束,见 vt13)
//   +0x60 QByteArray              (报文暂存)
//   +0x68 QByteArray  chunk
//   +0x70 QByteArray  buffer      (累计到 0x20000 才落盘,见 saveChunk)
//   +0x78 QSaveFile *saveFile
//   +0x80 QObject   *f80          (dtor 以虚析构删除)
//   +0x88 quint8   mode           (3 → 重名时 "%1(%2)%3" 找空闲名)
//   +0x8c int
//   +0x90 int      expectedSize = -1
//   +0xa0 qint64   written
//   +0xa8 int      retries        (≥5 → "… failed, retry limit reached.")
//   +0xb0 QObject  *fB0           (deleteLater)
//   +0xb8 int      retryCount     (≥10 → stop + reset;3/10 两档回 C/NAK)
//   +0xc0 QObject  *fC0           (deleteLater)

#include "Sessions/Transfers/Modem.h"

class QSaveFile;

class XYModem : public Modem {
	Q_OBJECT

public:
	// FUN_0079c8a0(126B)ctor:Modem 基 → vptr → +0x50 = 0 / +0x52 = 0x1a /
	//   +0x56 = 0x80 / +0x60..+0x70 空 / +0x78·+0x80 = 0 / +0x88 = 0 /
	//   +0xb0·+0xc0 = 0 → 0x0079c6de(状态复位)。
	explicit XYModem(QObject *session, QObject *writer); // 0079c8a0
	~XYModem() override;                                 // 0079c926

	void reset() override;                // vt13 0079ba70
	bool isRunning() const override;      // vt14 0079ba76
	void feed(QByteArray &data) override; // vt15 0079f16e
	void sendInit() override;             // vt16 0079f1ac

protected:
	// ---- 输入/输出 ------------------------------------------------------
	void translateInput(QByteArray &data);  // 0079b610
	void appendLf(QByteArray &data);        // 0079b774
	void writeData(const QByteArray &data); // 0079b858
	void writeByte(char ch);                // 0079b8d8
	void addSendFiles(const QStringList &files); // 0079b942

	// ---- 校验 ------------------------------------------------------------
	quint16 checksum(const char *data, int len) const;    // 0079bc6a
	bool verifyChecksum(const char *data, int len) const; // 0079bcd2

	// ---- 落盘 ------------------------------------------------------------
	bool openReceiveFile();                       // 0079bd1a
	bool saveChunk(const char *data, int len);    // 0079c43e
	bool sendWithRetry(const QByteArray &data);   // 0079c1da
	void sendSub();                               // 0079c3ab(发 0x15 = NAK)
	void retryTimeout();                          // 0079bb76
	void setSubChar(bool on);                     // 0079c88c

	// ---- 协议核(体量 1–4KB,入口已锚定,正文 cited) --------------------
	void recvPkt(const QByteArray &data);      // xymodem_recvPkt 0079cde6(2094B)
	void processInput(const QByteArray &data); // xymodem_processInput 0079ed2e(1030B)
	void resetState();                         // 0079c6de

	QByteArray m_buf60;      // +0x60
	QByteArray m_chunk68;    // +0x68
	QByteArray m_buffer70;   // +0x70
	QSaveFile *m_saveFile78 = nullptr; // +0x78
	QObject *m_f80 = nullptr;          // +0x80
	QObject *m_fB0 = nullptr;          // +0xb0
	QObject *m_fC0 = nullptr;          // +0xc0
	bool m_dirOnly50 = false;   // +0x50
	bool m_trimSub51 = false;   // +0x51
	char m_subChar52 = 0x1a;    // +0x52
	quint8 m_crcMode53 = 0;     // +0x53
	bool m_receiving54 = false; // +0x54
	quint16 m_flag56 = 0x80;    // +0x56
	quint8 m_state58 = 0;       // +0x58
	quint8 m_mode88 = 0;        // +0x88
	int m_f8c = 0;              // +0x8c
	int m_expectedSize90 = -1;  // +0x90
	qint64 m_writtenA0 = 0;     // +0xa0
	int m_retriesA8 = 0;        // +0xa8
	int m_retryCountB8 = 0;     // +0xb8
};

#endif // SESSIONS_TRANSFERS_XYMODEM_H
