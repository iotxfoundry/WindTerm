#include "Sessions/Transfers/XYModem.h"

#include <QDir>
#include <QFileDevice>
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
	m_packetNo54 = m_dirOnly50 ? 0 : 1;
	m_retriesA8 = 0;
	m_retryCountB8 = 0;
	m_errorCount8c = 0;
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

// xymodem_recvPkt(0x0079cde6,2094B)下载侧收包真身。逐句:
//   ① 若 +0xc0 非空且首字节 b < 0x19 且位图 0x1000016 命中 → resetState()
//      (0x1000016 置位 = bit1/2/4/24 → 字面集合 {0x02,0x04,0x10,0x18},
//       即 STX / EOT / DLE / CAN —— 按位图原样转写,不解释语义)
//   ② +0x60 累积本次数据,循环消费:
//      c == 0x01/0x02(SOH/STX):payload = 0x80/0x400,packetLen = 0x83/0x403,
//          need = packetLen + (crcMode == 0 ? 2 : 1)
//          (asm 0x79cf09-0x79cf20:r8d = payload,esi = packetLen,
//           edx = crcMode==0 ? 0 : -1,lea 0x2(rdx,rsi) → 32 位回绕)
//          need > 剩余 → return(等下一批)
//          seq = data[1],inv = data[2];seq != (quint8)~inv → 丢 1 字节 + NAK(0x15)
//          seq == m_packetNo54:
//            校验 verifyChecksum(payload) 失败 → 丢 1 字节 + NAK
//            普通块(包号 != 0 或已有文件名):saveChunk(payload) → ++包号,state = 3
//            YMODEM 头块(包号 == 0 且无文件名):handleHeader(payload) →
//              文件名仍空 → finish(true),state = 6;否则 ++包号,state = 3
//            丢整包(need 字节)+ ACK(0x06)
//          seq == quint8(包号 - 1) → 重复块:丢整包 + ACK
//          其余 → showError("Invalid packet sequence number.", true),建重试定时器
//                 (+0xb0,QTimer 接 timeout → sendSub),m_retriesA8 = 0
//      c == 0x04(EOT):openReceiveFile() 成功后按 mode88 决定提交/取消 → resetState();
//          非 dirOnly → finish(true),state = 6;否则 state = 0;丢包 + ACK
//      c == 0x18(CAN):整块去 0x18 与 '\b'、trimmed,非空则显示;
//          再显示 "Server canceled transfer.";finish(false),state = 6
//      (0x04/0x18 的 finish 实参由 asm 回读:0x79d4fc/0x79d606 `mov $1,%esi`
//       → finish(true);0x79d25a `xor %esi,%esi` → finish(false);
//       ACK 字符 0x79d308 `mov $0x6,%esi`。)
void XYModem::recvPkt(const QByteArray &data)
{
	if (m_fC0 != nullptr && !data.isEmpty()) {
		const uchar b = uchar(data.at(0));
		if (b < 0x19 && ((0x1000016UL >> b) & 1))
			resetState(); // 0x0079c6de
	}
	m_buf60.append(data); // +0x60

	while (!m_buf60.isEmpty()) {
		const char c = m_buf60.at(0);

		if (c == 0x01 || c == 0x02) { // SOH / STX
			const int payload = (c == 0x01) ? 0x80 : 0x400;
			const int packetLen = (c == 0x01) ? 0x83 : 0x403;
			const int need = packetLen + (m_crcMode53 == 0 ? 2 : 1);
			if (m_buf60.size() < need)
				return; // 等下一批

			const quint8 seq = quint8(m_buf60.at(1));
			const quint8 inv = quint8(m_buf60.at(2));
			if (seq != quint8(~inv)) {
				m_buf60.remove(0, 1); // asm 0x79ce9d
				writeByte('\x15'); // NAK
				continue;
			}

			if (quint8(m_packetNo54) == seq) {
				const char *body = m_buf60.constData() + 3;
				if (!verifyChecksum(body, payload)) {
					m_buf60.remove(0, 1);
					writeByte('\x15');
					continue;
				}
				if (m_packetNo54 != 0 || !m_receiveFileName.isEmpty()) {
					if (!saveChunk(body, payload)) {
						m_buf60.remove(0, 1);
						writeByte('\x15');
						continue;
					}
					++m_packetNo54;
					m_state58 = 3;
				} else { // YMODEM 头块
					if (!handleHeader(body, payload)) {
						m_buf60.remove(0, 1);
						writeByte('\x15');
						continue;
					}
					if (m_receiveFileName.isEmpty()) {
						finish(true);
						m_state58 = 6;
					} else {
						++m_packetNo54;
						m_state58 = 3;
					}
				}
				m_buf60.remove(0, need); // asm 0x79d390:edx = r12d = need
				writeByte('\x06'); // ACK(asm 0x79d308)
			} else if (seq == quint8(m_packetNo54 - 1)) {
				m_buf60.remove(0, need); // 重复块
				writeByte('\x06');
			} else {
				showError(QStringLiteral("Invalid packet sequence number."), true); // 0x1f 字符
				if (m_fB0 == nullptr) {
					// 重试定时器:new QTimer(this),interval 由连接参数给,
					// timeout → sendSub();m_retriesA8 = 0 —— 间隔实参被折叠,cited。
					m_fB0 = new QObject(this);
				}
				m_retriesA8 = 0;
			}
		} else if (c == 0x04) { // EOT
			if (openReceiveFile()) { // 0x0079bd1a
				bool cancel = false;
				if (m_mode88 == 1 || m_mode88 == 2 || m_mode88 == 4) {
					QFileInfo info(m_saveFile78->fileName()); // vtable +0xe0
					if (info.exists()) {
						if (m_mode88 == 1 || m_mode88 == 2) {
							const qint64 mtime = info.lastModified().toSecsSinceEpoch();
							cancel = (mtime < m_f98)
							         || (m_mode88 == 2 && info.size() < m_expectedSize90);
						}
					}
				}
				saveChunk(nullptr, 0); // 收尾:按 +0x51/+0x90 裁剪
				if (cancel) {
					m_saveFile78->cancelWriting(); // 保留原文件
				} else if (!m_saveFile78->commit()) {
					showError(m_saveFile78->errorString(), true);
				}
				resetState();
			}
			if (!m_dirOnly50) {
				finish(true); // asm 0x79d4fc / 0x79d606
				m_state58 = 6;
			} else {
				m_state58 = 0;
			}
			m_buf60.remove(0, 1); // asm 0x79d2f8:mov $1,%edx
			writeByte('\x06');
			if (m_dirOnly50)
				continue;
		} else if (c == 0x18) { // CAN
			QString text = QString::fromLatin1(m_buf60);
			text.replace(QChar(0x18), QString()).replace(QChar('\b'), QString());
			text = text.trimmed();
			if (!text.isEmpty())
				appendText(text);
			appendText(QStringLiteral("Server canceled transfer.")); // 0x19 字符
			finish(false); // asm 0x79d25a
			m_state58 = 6;
		} else {
			break; // 其余首字节:本函数不消费(语料 LAB_0079ce93 退出循环)
		}

		// 任一支进入「完成」态即收口(否则 +0x60 不再被消费会死循环)。
		if (m_state58 == 6)
			return;
	}
}

// FUN_0079cab4(775B)YMODEM 头块解析真身。逐句:
//   block  = QByteArray::fromRawData(payload, len)
//   nul    = block.indexOf('\0');name = block.left(nul);rest = block.mid(nul + 1)
//   fields = rest.split(' ')(QList<QByteArray>)
//   setReceiveFileName(QString::fromUtf8(name))(0x0079b466)
//   fields 非空 → m_expectedSize90 = fields[0].toUInt(&ok),!ok → -1;
//                 fields 多于 1 项 → m_f98 = fields[1].toLongLong(&ok2),!ok2 → -1
//   m_writtenA0 = 0;返回 true
bool XYModem::handleHeader(const char *payload, int len)
{
	const QByteArray block = QByteArray::fromRawData(payload, len);
	const int nul = block.indexOf('\0');
	setReceiveFileName(QString::fromUtf8(block.left(nul))); // +0x38
	const QList<QByteArray> fields = block.mid(nul + 1).split(' ');

	if (!fields.isEmpty()) {
		bool ok = false;
		const uint size = fields.at(0).toUInt(&ok);
		m_expectedSize90 = ok ? int(size) : -1; // +0x90
		if (fields.size() > 1) {
			bool okTime = false;
			const qlonglong mtime = fields.at(1).toLongLong(&okTime);
			m_f98 = okTime ? mtime : -1; // +0x98
		}
	}
	m_writtenA0 = 0; // +0xa0
	return true;
}

// FUN_0079b466(396B)接收文件名真身。逐句:
//   name 为空 → 返回;+0x38 = QDir::toNativeSeparators(name)
//   slash = +0x38.lastIndexOf(QDir::separator(), -1, Qt::CaseSensitive)
//   path_normalizeSep("Receiving: %1\r\n"(0x0f 字符).arg(+0x38.mid(slash + 1)))
//   (mid 的 pos 由 asm 0x79b4f7 `lea 0x1(%r12),%edx` 实读 = lastIndexOf + 1)
void XYModem::setReceiveFileName(const QString &name)
{
	if (name.isEmpty())
		return;
	m_receiveFileName = QDir::toNativeSeparators(name); // +0x38
	const int slash = m_receiveFileName.lastIndexOf(QDir::separator());
	appendText(QStringLiteral("Receiving: %1\r\n").arg(m_receiveFileName.mid(slash + 1)));
}

// xymodem_processInput(0x0079ed2e,1030B)上传侧应答状态机(逐字节)。状态 +0x58:
//   0 = 等 NAK/'C' / 1 = YMODEM 已答头块 / 2 = 正在发 / 3 = 等下一块 ACK /
//   4 = 等 EOT 应答 / 5 = YMODEM 等结束 / 6 = 完成。
// 分发:
//   0x15 NAK → 非 dirOnly 且 state==0: crcMode=1 并 sendNext(1);
//              否则 sendWithRetry(m_chunk68)
//   0x18 CAN → state=6;把整块当 C 串去掉 0x18 与 '\b'、trimmed,
//              非空则显示并 ++m_errorCount8c
//   'C'      → state==0: crcMode=0,非 dirOnly 则 sendNext(1) 否则 sendNext(0);
//              state==2: sendNext(1)
//   0x06 ACK → 非 dirOnly: state==3 → sendNext(1);state==4 → state=6
//              dirOnly  : state==3 → sendNext(1);state==4 → resetState();
//                         state==5 → state=6 并显示 "Transfer complete." /
//                         "Transfer incomplete."(看 m_errorCount8c);
//                         state==1 → state=2
// 每个分支末尾统一:state == 6 → finish(m_errorCount8c == 0) 并返回。
// (sendNext 的实参由 asm 0x79ed8b / 0x79f0ee 回读:mov $1 / xor → 1 与 0。)
void XYModem::processInput(const QByteArray &data)
{
	for (int i = 0; i < data.size(); ++i) {
		const uchar c = uchar(data.at(i));

		if (c == 0x15) { // NAK
			if (!m_dirOnly50 && m_state58 == 0) {
				m_crcMode53 = 1;
				sendNext(1);
			} else {
				sendWithRetry(m_chunk68); // 0x0079c1da(this, &m_chunk68)
			}
		} else if (c > 0x15) {
			if (c == 0x18) { // CAN
				m_state58 = 6;
				QString text = QString::fromLatin1(data);
				text.replace(QChar(0x18), QString())
				    .replace(QChar('\b'), QString());
				text = text.trimmed();
				if (!text.isEmpty()) {
					appendText(text);
					++m_errorCount8c; // +0x8c
				}
			} else if (c == 'C') {
				if (m_state58 == 0) {
					m_crcMode53 = 0;
					if (!m_dirOnly50)
						sendNext(1);
					else
						sendNext(0);
				} else if (m_state58 == 2) {
					sendNext(1);
				}
			}
		} else if (c == 0x06) { // ACK
			if (!m_dirOnly50) {
				if (m_state58 == 3) {
					sendNext(1);
				} else if (m_state58 == 4) {
					m_state58 = 6;
				}
			} else {
				if (m_state58 == 3) {
					sendNext(1);
				} else if (m_state58 > 3) {
					if (m_state58 == 4) {
						resetState(); // 0x0079c6de
					} else if (m_state58 == 5) {
						m_state58 = 6;
						appendText(m_errorCount8c == 0
						               ? QStringLiteral("Transfer complete.")
						               : QStringLiteral("Transfer incomplete."));
					}
				} else if (m_state58 == 1) {
					m_state58 = 2;
				}
			}
		}

		if (m_state58 == 6) {
			finish(m_errorCount8c == 0); // 0x0079aba0(this, m_errorCount8c == 0)
			return;
		}
	}
}

// FUN_0079eb8c(388B)组一块并发出。逐句:
//   ok = buildPacket(crcMode)(FUN_0079dc32,3833B → cited)
//   !ok → 有接收文件且 error() != 0 → showError(errorString(), true);
//         否则 m_chunk68 = QByteArray(1, 0x04)(EOT),writeData(m_chunk68)
//   ok  → writeData(m_chunk68)
//   末尾:m_retriesA8 = 0;m_packetNo54 + 1(块号递增)
void XYModem::sendNext(int crcMode)
{
	const bool ok = buildPacket(crcMode); // 0079dc32
	if (!ok) {
		if (m_saveFile78 != nullptr && m_saveFile78->error() != QFileDevice::NoError) {
			showError(m_saveFile78->errorString(), true);
		} else {
			m_chunk68 = QByteArray(1, '\x04'); // EOT
			writeData(m_chunk68);
		}
	} else {
		writeData(m_chunk68);
	}
	m_retriesA8 = 0; // +0xa8 = 0
	++m_packetNo54; // +0x54 += 1
}

// FUN_0079dc32(0x0079dc32,3833B)— cited:按 +0x54 块号组一帧(头 0x01/0x02、
// 块号与反码、数据、校验)。返回 false 表示无数据可发(调用方改发 EOT)。
// ⚠ 本体未转写;此处恒 false 只是占位,会让 sendNext 一直发 EOT ——
//   收尾期必须先把 0079dc32 转写出来,ZMODEM 之外的内置收发才能真跑。
bool XYModem::buildPacket(int crcMode)
{
	Q_UNUSED(crcMode);
	return false;
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
