#include "Sessions/Transfers/XYModem.h"

#include <QDir>
#include <QFileInfo>
#include <QSaveFile>

// ─────────────────────────────────────────────────────────────────────────────
// 出处:tools/re/decomp/decomp-part-0024.c(0x0079b610..0x0079f9ae 连续段)。
// 协议核(xymodem_recvPkt / xymodem_processInput / xymodem_sendInit)体量
// 2094B / 1030B / 1954B,按 AGENTS §5「引用档」只锚定入口 + 语义摘要,
// 正文待收尾期逐句转写。
// ─────────────────────────────────────────────────────────────────────────────

// FUN_0079c8a0(126B)ctor 真身:
//   FUN_0079a842(基类 ctor)→ vptr = XYModem vtable
//   → +0x50 ushort = 0、+0x52 = 0x1a、+0x56 = 0x80
//   → +0x60/+0x68/+0x70 = QByteArray 空、+0x78/+0x80 = 0、+0x88 = 0
//   → +0xb0/+0xc0 = 0 → FUN_0079c6de(状态复位)
XYModem::XYModem(QObject *session, QObject *writer)
    : Modem(session, writer) // FUN_0079a842
{
	m_dirOnly50 = false; // +0x50 ushort 低字节
	m_subChar52 = '\x1a'; // +0x52
	m_flag56 = 0x80; // +0x56
	m_saveFile78 = nullptr; // +0x78
	m_f80 = nullptr; // +0x80
	m_mode88 = 0; // +0x88
	m_fB0 = nullptr; // +0xb0
	m_fC0 = nullptr; // +0xc0
	resetState(); // 0079c6de
}

// FUN_0079c6de(429B)状态复位真身:
//   +0x58 = 0;+0x54 = (+0x50 == 0);+0xa8 = +0xb8 = +0x8c = 0;
//   +0xa0 = 0;+0x90 = -1;+0x50 != 0 时另清 +0x38(QString)与 +0x70(QByteArray)
//   (尾部 0x0079c75b- 段:QByteArray::clear ×3 + +0x70 预留 0x20000)。
void XYModem::resetState()
{
	m_state58 = 0;
	m_receiving54 = !m_dirOnly50;
	m_retriesA8 = 0;
	m_retryCountB8 = 0;
	m_f8c = 0;
	m_writtenA0 = 0;
	m_expectedSize90 = -1;
	if (m_dirOnly50) {
		m_receiveFileName.clear();
		// 尾部:三个 QByteArray::clear()(即 +0x60/+0x68/+0x70)+ +0x70 预留
		// 0x20000 字节容量(cited,只登记)。
		m_buf60.clear();
		m_chunk68.clear();
		m_buffer70.clear();
	}
}

// XYModem_dtor(0x0079c926,373B)真身:
//   vptr → 虚面 vt13(reset)→ 逐项删除 +0x80/+0x78(虚析构)、
//   +0x70/+0x68/+0x60(QByteArray)、+0xb0/+0xc0(deleteLater)。
XYModem::~XYModem()
{
	reset(); // 0079c926 首句调 XYModem_vt13
	delete m_f80; // +0x80
	delete m_saveFile78; // +0x78
	m_fB0 = nullptr; // +0xb0(deleteLater,会话层持有)
	m_fC0 = nullptr; // +0xc0
}

// XYModem_vt13(5B):+0x58 = 6(空闲/结束)。
void XYModem::reset()
{
	m_state58 = 6;
}

// XYModem_vt14(8B):+0x58 != 6。
bool XYModem::isRunning() const
{
	return m_state58 != 6;
}

// FUN_0079c88c(19B):+0x56 = (-(ushort)(on == 0) & 0xfc80) + 0x400
//   → on = false 时 0x10080 截 16 位 = 0x0080;on = true 时 0x0400。
void XYModem::setSubChar(bool on)
{
	m_flag56 = on ? 0x400 : 0x80;
}

// XYModem_vt15(62B)收包入口真身:
//   data 为空 → 直接返回
//   translateInput(data) → +0x30 == 0(下载)→ recvPkt;否则 processInput
void XYModem::feed(QByteArray &data)
{
	if (data.isEmpty())
		return;
	translateInput(data);
	if (!m_uploading)
		recvPkt(data);
	else
		processInput(data);
}

// xymodem_recvPkt(0x0079cde6,2094B)— cited:
//   收包主循环:按 +0x56 的块参取报文头(0x01 SOH / 0x02 STX / 0x18 CAN),
//   校验 checksum()/verifyChecksum(),写 ACK(0x06)/NAK(0x15)/CAN(0x18),
//   成功后 saveChunk() 落盘并 transferProgress()。逐句未转写。
void XYModem::recvPkt(const QByteArray &data)
{
	Q_UNUSED(data);
}

// xymodem_processInput(0x0079ed2e,1030B)— cited:
//   发包侧的应答处理(ACK/NAK/CAN),驱动下一块发送与重试计数。
void XYModem::processInput(const QByteArray &data)
{
	Q_UNUSED(data);
}

// xymodem_sendInit(0x0079f1ac,1954B)— cited:
//   发包初始化:组首块(文件名/大小/时间戳),进 +0x58 状态机,
//   起重试定时器(+0xb8 计数)。
void XYModem::sendInit()
{
}

// FUN_0079bc6a(103B)+0x53 == 0 → CRC16(语料逐位形态原样转写);
// +0x53 == 1 → 8bit 累加和;其它 → 0。
quint16 XYModem::checksum(const char *data, int len) const
{
	if (m_crcMode53 == 0) {
		quint32 crc = 0;
		for (int i = 0; i < len; ++i) {
			quint32 t = (crc & 0xffff0000u)
			            | quint32(quint16((crc << 8) | (crc >> 8)));
			t ^= quint32(quint8(data[i]));
			t ^= quint32((t & 0xff) >> 4);
			t = (t << 12) ^ t;
			crc = ((t & 0x07fff8ffu) << 5) ^ t;
		}
		return quint16(crc);
	}
	if (m_crcMode53 == 1) {
		quint8 sum = 0;
		for (int i = 0; i < len; ++i)
			sum = quint8(sum + quint8(data[i]));
		return sum;
	}
	return 0;
}

// FUN_0079bcd2(71B):尾部 2 字节(CRC 模式)或 1 字节(和模式)与重算值比较。
bool XYModem::verifyChecksum(const char *data, int len) const
{
	const quint16 sum = checksum(data, len);
	const quint8 *tail = reinterpret_cast<const quint8 *>(data + len);
	if (m_crcMode53 == 0)
		return quint16((tail[0] << 8) | tail[1]) == sum;
	return tail[0] == sum;
}

// FUN_0079bd1a(1120B)收文件打开腿:
//   +0x78 为空 → new QSaveFile(nullptr);
//     +0x50 == 0 → setFileName(receiveFileName)
//     否则 → 目标 = receiveDir;+0x88 == 3 且目标已存在 → 用 "%1(%2)%3"
//            (baseName/序号/'.'+suffix)自增找空闲名(QDir::exists 判定)
//   setDirectWriteFallback(false) → open(QIODevice::WriteOnly);
//   失败 → showError(errorString(), true)
//   返回 saveFile != nullptr && saveFile->isOpen()
bool XYModem::openReceiveFile()
{
	if (m_saveFile78 == nullptr) {
		m_saveFile78 = new QSaveFile(nullptr); // operator_new(0x10)
		if (!m_dirOnly50) {
			m_saveFile78->setFileName(m_receiveFileName);
		} else {
			QString path = m_receiveDir; // +0x40
			if (m_mode88 == 3) {
				QFileInfo info(path);
				if (info.exists()) {
					// 重名腿:base + "(n)" + "." + suffix,自 n = 1 递增到
					// QDir 下不再存在为止(QString::arg 三参形态) —— cited。
					const QString base = info.baseName();
					const QString suffix = info.completeSuffix().isEmpty()
					                           ? QString()
					                           : QLatin1Char('.') + info.completeSuffix();
					for (int n = 1; n != 0x7fffffff; ++n) {
						m_receiveFileName = QStringLiteral("%1(%2)%3")
						                        .arg(base)
						                        .arg(n)
						                        .arg(suffix);
						// QDir(<dir>/<name>).exists() —— cited
						if (!QFileInfo(QDir(info.absolutePath()).filePath(m_receiveFileName)).exists())
							break;
					}
				}
			}
			m_saveFile78->setFileName(path);
		}
	}
	m_saveFile78->setDirectWriteFallback(false);
	if (!m_saveFile78->open(QIODevice::WriteOnly)) {
		showError(m_saveFile78->errorString(), true);
	}
	return m_saveFile78 != nullptr && m_saveFile78->isOpen();
}

// FUN_0079c43e(663B)落盘腿。可复原部分:
//   data == nullptr(收尾调用)→ +0x90 == -1 时按 +0x51 裁尾部连续 SUB(+0x52);
//   否则把 chunk 截到 +0x90;
//   再 openReceiveFile() → write(+0x70) → transferProgress(已写量, 总长) → 清 +0x68。
//   非空 data → 先把旧 chunk 追加进 +0x70、累加 +0xa0,再令 +0x68 = QByteArray(data,len);
//   +0x70 未满 0x20000 即返回(不落盘)。
//   追加源与截断长度因 QString/QByteArray 引用计数噪声被反编译折叠 —— cited。
bool XYModem::saveChunk(const char *data, int len)
{
	if (data == nullptr) {
		if (m_expectedSize90 == -1) {
			if (m_trimSub51) {
				// 裁掉 +0x70 尾部连续 m_subChar52
				while (!m_buffer70.isEmpty()
				       && m_buffer70.at(m_buffer70.size() - 1) == m_subChar52)
					m_buffer70.chop(1);
			}
		} else {
			m_buffer70 = m_buffer70.left(m_expectedSize90);
		}
	} else {
		m_buffer70.append(m_chunk68); // 追加源:语料折叠,cited
		m_writtenA0 += m_chunk68.size(); // +0xa0 += +0x68.size
		m_chunk68 = QByteArray(data, len);
		if (m_buffer70.size() != 0x20000)
			return true;
	}

	if (!openReceiveFile())
		return true;
	const qint64 written = m_saveFile78->write(m_buffer70);
	if (written != -1) {
		transferProgress(qint64(m_saveFile78->size()), m_uploading ? m_expectedSize90 : -1);
	} else {
		showError(m_saveFile78->errorString(), true);
		if (data != nullptr) {
			cancel();
			reset();
		}
		return false;
	}
	m_chunk68.clear();
	return true;
}

// FUN_0079c1da(428B)带重试的发送:+0xa8 < 5 才发,否则报
//   "%1 failed, retry limit reached."(%1 = "Receive" / "Send")并 showError(…, true)。
bool XYModem::sendWithRetry(const QByteArray &data)
{
	if (m_retriesA8 < 5) {
		writeData(data); // 0079b858
		++m_retriesA8;
		return true;
	}
	const QString what = m_uploading ? QStringLiteral("Send") : QStringLiteral("Receive");
	showError(QStringLiteral("%1 failed, retry limit reached.") // 0x1f 字符
	              .arg(what),
	          true);
	return false;
}

// FUN_0079c3ab(138B)槽腿:状态未结束(+0x58 != 6)时发 0x15(NAK)。
void XYModem::sendSub()
{
	if (m_state58 == 6)
		return;
	sendWithRetry(QByteArray(1, '\x15'));
}

// FUN_0079bb76(244B)重试定时器回调真身:
//   取 +0xb8 计数:< 3 → +0x53 = 0 并发 0x43('C');3..9 → +0x53 = 1 并发 0x15(NAK);
//   ≥ 10 → stop() + 虚面 +0x60(cancel) + reset();计数 +1。
void XYModem::retryTimeout()
{
	if (m_retryCountB8 < 3) {
		m_crcMode53 = 0;
		writeByte('\x43');
	} else if (m_retryCountB8 < 10) {
		m_crcMode53 = 1;
		writeByte('\x15');
	} else {
		cancel();
		reset();
	}
	++m_retryCountB8;
}
