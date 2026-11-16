#include "Sessions/Transfers/Modem.h"

#include "Utility/Format.h"

#include <QTimer>

// ─────────────────────────────────────────────────────────────────────────────
// 出处:tools/re/decomp/decomp-part-0024.c。
// Modem 本体 = 0x0079a842(ctor)/0x0079a6aa(接线)/0x0079a8be..0x0079ac26(方法)/
// 0x0079a5d8(cancel)/0x0079a598·a5bc(Progress)/0x0079a370·a3b4·a472(槽腿)。
// +0x50 之后属派生类(XYModem / ZModem),见各自文件。
// ─────────────────────────────────────────────────────────────────────────────

// FUN_0079a5bc + FUN_0079a598(13B + 35B)Progress 初始化/析构真身:
//   *(+0x10) = 0xffffffffffffffff(两个 int 同写 -1);
//   delete +0x18(operator_delete 尺寸 0x10 = QElapsedTimer);+0x18 = 0。
void Modem::Progress::reset()
{
	percent = -1;
	width = -1;
	delete timer;
	timer = nullptr;
}

// FUN_0079a842(107B)ctor 真身:
//   QObject::QObject(this, session) → vptr = Modem vtable(0x011a6df8)
//   → +0x10 Progress 初始化 → +0x20 = session → +0x28 = writer
//   → +0x31 = false → +0x38/+0x40 = QString 空 → +0x48 = QList 空
//   → FUN_0079a6aa(接线)。
// 注意:+0x30(m_uploading)本 ctor 不写,派生 ctor 亦未写 —— 原版即如此。
Modem::Modem(QObject *session, QObject *writer)
    : QObject(session) // QObject::QObject(this, session)
    , m_session(session) // +0x20
    , m_writer(writer) // +0x28
{
	m_progress.reset(); // 0079a5bc
	m_lineBreak = false; // +0x31
	wireSignals(); // 0079a6aa
}

// FUN_0079a6aa(408B)接线真身:
//   connectImpl(this, FUN_0090e888 /*finished*/, this, 0, functor 0079a370,
//               type = 2 /*Qt::QueuedConnection*/, &DAT_00c8a998, &Modem::staticMetaObject)
//   connectImpl(this, FUN_0090e8bc /*showText*/, this, 0, functor 0079a3b4, type = 0)
//   connectImpl(writer(+0x28), FUN_009132ce /*metaobject 011a82e0 idx 0x0b*/,
//               this, 0, functor 0079ba00, type = 0)
void Modem::wireSignals()
{
	connect(this, &Modem::finished, this,
	        [this](bool success) { onFinished(success); }, Qt::QueuedConnection);
	connect(this, &Modem::showText, this,
	        [this](const QByteArray &text) { onShowText(text); });
	// 第三条的发送方是 writer 的索引 0x0b 信号,信号名未从 metaobject 复原 ——
	// 接线本身 cited(不影响 Modem 侧语义)。
}

// FUN_0079a370(68B)finished(bool) 槽腿真身:
//   FUN_00913498(writer, bool) —— writer 的信号(metaobject 011a82e0 idx 10)
//   FUN_007e4482(writer)       —— deleteLater(writer+0x208 / writer+0x200)
// 两个被调均属会话/终端层且未转写,只登记不落调用。
void Modem::onFinished(bool success)
{
	Q_UNUSED(success);
}

// FUN_0079a3b4(65B)showText 槽腿真身:
//   FUN_007e7b88(writer, text) —— 终端 writeText 入口(Screen.cpp:3088 已转写)
//   FUN_007f5736(writer)       —— 行快照/刷新腿
void Modem::onShowText(const QByteArray &text)
{
	Q_UNUSED(text);
}

// FUN_0079a8be(271B)真身:
//   !(+0x31) && !startsWith('\r') && !startsWith('\n') → insert(0, "\r\n"@0xca3941)
//   → FUN_0090e8bc(this, toUtf8) = emit showText(…)
//   → +0x31 = endsWith('\n')
void Modem::appendText(QString text)
{
	if (!m_lineBreak && !text.startsWith(QLatin1Char('\r'))
	    && !text.startsWith(QLatin1Char('\n')))
		text.insert(0, QStringLiteral("\r\n"));
	emit showText(text.toUtf8());
	m_lineBreak = text.endsWith(QLatin1Char('\n'));
}

// FUN_0079a9de(417B)错误腿真身:
//   text = "Error: "@0xca3926 + message.trimmed()
//   terminate → text += "\r\nTransfer aborted.\r\n"@0xca392e 并调虚面 +0x60(=vt12
//   cancel);末尾 path_normalizeSep(text) 显示。
void Modem::showError(QString message, bool terminate)
{
	message = QStringLiteral("Error: ") + message.trimmed();
	if (terminate) {
		message += QStringLiteral("\r\nTransfer aborted.\r\n");
		cancel(); // vtable +0x60 → vt12 = 0x0079a5d8
	}
	appendText(message);
}

// FUN_0079aba0(115B)收尾真身:
//   path_normalizeSep(this, "\r\n") → FUN_0090e888(this, success) = finished(success)
void Modem::finish(bool success)
{
	appendText(QStringLiteral("\r\n"));
	emit finished(success);
}

// FUN_0079ac1c(9B):FUN_0090e8e6(this, this + 0x38) = emit started(receiveFileName)。
void Modem::emitStarted()
{
	emit started(m_receiveFileName);
}

// FUN_0079ac26(1937B)进度条真身。逐句:
//   +0x18 为空 → new QElapsedTimer + start(),再 emitStarted()
//   total == -1 → "\r %1 bytes transferred...".arg(done) 直接显示
//   total == 0  → percent = 100(上次已过 99 则跳过)
//   否则 percent = done*100/total,不比上次大就跳过(进度不回退)
//   bar = QString(percent/5, '='),pad = QString(20 - percent/5, ' ')
//   elapsed = QElapsedTimer::elapsed(),下限 1ms
//   percent == 100 → tail = 时长 + " %1 bytes" + 空格补到上次宽度
//   否则           → tail = 时长 + " %1/s",bar 末尾改 '>',pad 少一格,
//                    再按上次宽度补空格(不够就把宽度记成新长度)
//   末段:"\r %1% [%2%3] %4"(0x0f 字符)逐个 arg
void Modem::transferProgress(qlonglong done, qlonglong total)
{
	if (m_progress.timer == nullptr) {
		m_progress.timer = new QElapsedTimer; // operator_new(0x10)
		m_progress.timer->start(); // QElapsedTimer::start()
		emitStarted();
	}

	if (total == -1) {
		appendText(QStringLiteral("\r %1 bytes transferred...").arg(done));
		return;
	}

	int percent;
	if (total == 0) {
		percent = 100;
		if (m_progress.percent > 99)
			return;
	} else {
		percent = int(done * 100 / total);
		if (percent <= m_progress.percent)
			return;
	}

	QString bar(percent / 5, QChar('=')); // 0x3d
	QString pad(20 - percent / 5, QChar(' '));

	qlonglong elapsed = m_progress.timer->elapsed();
	if (elapsed <= 0)
		elapsed = 1;

	QString tail = formatDuration(elapsed, false); // FUN_006168b6(ms, showMillis = 0)
	if (percent == 100) {
		if (total == 0)
			total = done;
		tail += QStringLiteral(" %1 bytes").arg(total); // 9 字符
		int fill = m_progress.width - tail.size();
		if (fill < 0)
			fill = 0;
		tail += QString(fill, QChar(' '));
	} else {
		const QString rate = formatByteCount(done * 1000 / elapsed); // FUN_00616636
		tail += QStringLiteral(" %1/s").arg(rate);
		bar += QChar('>');
		pad.chop(1);
		const int width = tail.size();
		if (width < m_progress.width)
			tail += QString(m_progress.width - width, QChar(' '));
		else
			m_progress.width = width;
	}

	m_progress.percent = percent;
	appendText(QStringLiteral("\r %1% [%2%3] %4") // 0x0f 字符
	               .arg(QString::number(percent).rightJustified(3, QChar(' ')))
	               .arg(bar)
	               .arg(pad)
	               .arg(tail));
}

// FUN_0079a5d8(202B)cancel 真身:
//   +0x30 == 1(上传中)→ 虚面 +0x68(=vt13 reset)+ FUN_0090e888(this, 0)(finished(false))
//   → 写 0xca3915(8×0x18 CAN + 8×0x08 BS)
//   → +0x30 == 0(下载中)→ singleShot(3000ms, Qt::CoarseTimer, this, 0079a472)
void Modem::cancel()
{
	if (m_uploading) {
		reset();
		emit finished(false);
	}
	// 0xca3915 实读:8 个 0x18 + 8 个 0x08
	static const char kCancelSeq[16] = {'\x18', '\x18', '\x18', '\x18',
	                                    '\x18', '\x18', '\x18', '\x18',
	                                    '\x08', '\x08', '\x08', '\x08',
	                                    '\x08', '\x08', '\x08', '\x08'};
	// FUN_007cdff2(session, writer, seq) —— 会话上行写(SuperCommander.cpp:1810 侧,cited)
	Q_UNUSED(kCancelSeq);

	if (!m_uploading) {
		QTimer::singleShot(3000, Qt::CoarseTimer, this, [this] {
			// FUN_0079a472(278B)超时收尾:
			//   emit showText("\r\nTransfer canceled.");emit finished(false);
			//   FUN_007cdff2(session, writer, FUN_007e4998(writer))
			//   (FUN_007e4998 = 终端行复位序列,未转写 —— cited)
			appendText(QStringLiteral("\r\nTransfer canceled."));
			emit finished(false);
		});
	}
}
