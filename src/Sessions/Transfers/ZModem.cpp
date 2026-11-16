#include "Sessions/Transfers/ZModem.h"

#include "Sessions/Transfers/ModemProcess.h"

#include <QCoreApplication>
#include <QDir>
#include <QThread>

// ─────────────────────────────────────────────────────────────────────────────
// 出处:tools/re/decomp/decomp-part-0024.c(0x0079fc66..0x007a1f07)。
// 读循环 FUN_007a0f86(0x007a0f86,3062B)与状态槽 FUN_0079fb5c(245B)按 AGENTS §5
// 引用档只锚入口。
// ─────────────────────────────────────────────────────────────────────────────

// FUN_007a0160(286B)ctor 真身:
//   FUN_0079a842(基类)→ vptr = ZModem vtable
//   → +0x50 = 0、+0x58/+0x60 QString 空、+0x68..+0x78 = 0、+0x80 = 0
//   → +0x88 QString 空、+0x90 QStringMatcher(默认)→ +0x4a8/+0x4b0/+0x4b8 = 0
//   → m_matcher90 = QStringMatcher("transfer"@0xca3c26)
ZModem::ZModem(QObject *session, QObject *writer)
    : Modem(session, writer) // FUN_0079a842
    , m_matcher90(QStringLiteral("transfer"))
{
	m_f50 = 0; // +0x50
	m_state80 = 0; // +0x80
}

// ZModem_dtor(0x007a029e,523B)真身:vptr → vt13(reset)
//   → 删 +0x4b8/+0x4b0/+0x4a8 → 析构 +0x90/+0x88/+0x70(QSharedPointer)。
ZModem::~ZModem()
{
	reset(); // 首句调 ZModem_vt13
	delete m_reB8;
	delete m_reB0;
	delete m_reA8;
}

// ZModem_vt13(0x0079fc66,216B)停止真身:
//   +0x68 空 → 返回;
//   +0x70 内部块非空(引用计数 +0x04 != 0)且 +0x78 非空 →
//     FUN_007a26be(+0x78)(= ModemProcess::signalFinished)+ deleteLater(+0x78)
//     + +0x70 / +0x78 清空(减引用)+ +0x80 = 0;
//   QThread::quit() + wait(+0x68, 无限)+ deleteLater(+0x68)+ +0x68 = 0。
void ZModem::reset()
{
	if (m_thread68 == nullptr)
		return;
	if (!m_process70.isNull()) {
		m_process70->signalFinished(); // 007a26be:+0x20 = 1 + wakeOne
		m_process70->deleteLater();
		m_process70.clear();
		m_state80 = 0;
	}
	m_thread68->quit();
	m_thread68->wait(); // 语料:超时 0x7fffffffffffffff = 无限
	m_thread68->deleteLater();
	m_thread68 = nullptr;
}

// ZModem_vt14(0x0079fd3e,64B)真身:
//   +0x80 != 2 → false;进程为空 → true;否则返回 !process->+0x28(命中旗标)。
bool ZModem::isRunning() const
{
	if (m_state80 != 2)
		return false;
	if (m_process70.isNull())
		return true;
	return !m_process70->isMatched(); // +0x28 取反
}

// ZModem_vt15(0x007a0134,44B)真身:
//   +0x80 != 2(未运行)→ 直接返回;否则 FUN_0090ea58(this, data)
//   = emit modemRead(data) —— 由 zmodem_init 的接线送到进程 stdin。
void ZModem::feed(QByteArray &data)
{
	if (m_state80 != 2)
		return;
	translateInput(data); // 0079b610(与 XYModem 共用,已落 Modem)
	emit modemRead(data);
}

// zmodem_init(0x007a04c2,2636B)启动腿真身。逐句:
//   args += "-b"; args += "-e"; args += "-v"
//   direction == 1 → 待发文件列表(+0x48)非空则整表追加;
//                    reset();+0x30 = 1(上传);程序 "/vendors/lrzsz/sz"@0xca3c2f
//   否则          → 接收文件名(+0x38)非空则追加;
//                    reset();+0x30 = direction;程序 "/vendors/lrzsz/rz"@0xca3c41
//   +0x60 = 程序名;+0x58 = toNativeSeparators(applicationDirPath() + 程序名)
//   三段正则 → new ModemProcess(direction, nullptr) → new QThread(this)
//   → setProgram / setWorkingDirectory / setArguments / moveToThread
//   → 五条 connect → QThread::start(TimeCriticalPriority = 7)
void ZModem::startTransfer(int direction, QStringList &args)
{
	args << QStringLiteral("-b") << QStringLiteral("-e") << QStringLiteral("-v"); // "-b"/"-e"/"-v"

	// 语料 param_1[0x30] = param_2(原值);本处按 bool 语义等价书写。
	if (direction == 1) { // 发送
		if (!m_sendFiles.isEmpty())
			for (const QVariant &v : m_sendFiles)
				args << v.toString(); // FUN_0057d198(args, this + 0x48) 整表追加
		reset();
		m_uploading = true; // +0x30 = 1
		m_name60 = QString::fromUtf8("/vendors/lrzsz/sz"); // 0xca3c2f
	} else { // 接收
		if (!m_receiveFileName.isEmpty())
			args << m_receiveFileName; // +0x38
		reset();
		m_uploading = direction != 0; // 语料:param_1[0x30] = param_2
		m_name60 = QString::fromUtf8("/vendors/lrzsz/rz"); // 0xca3c41
	}

	m_path58 = QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + m_name60);
	setupPatterns(); // 0x007a06xx-0x007a08xx 三段正则

	m_process70.reset(new ModemProcess(direction, nullptr)); // termproc_init(p, direction, 0)
	m_thread68 = new QThread(this); // operator_new(0x10)
	m_process70->setProgram(m_path58);
	m_process70->setWorkingDirectory(m_path58); // 语料:同传 setProgram 的指针
	m_process70->setArguments(args);
	m_process70->moveToThread(m_thread68);

	// 五条 connect(0x007a08xx-0x007a0xxx 实读):
	// 1) thread.started          → process.startProcess()         (007a26ce)
	// 2) this.modemRead          → process.writeData(QByteArray)  (007a26d8)
	// 3) process.stateChanged    → FUN_0079fb5c                    (245B,cited)
	// 4) process.readyRead(int)  → onProcessReadyRead(channel)    (007a0f86)
	// 5) process.errorOccurred   → stateText(int)                  (007a0105)
	connect(m_thread68, &QThread::started, m_process70.data(),
	        &ModemProcess::startProcess);
	connect(this, &ZModem::modemRead, m_process70.data(),
	        &ModemProcess::writeData);
	connect(m_process70.data(), &QProcess::stateChanged, this, [this](QProcess::ProcessState) {
		// FUN_0079fb5c(245B)状态槽:按 state 切换 +0x80 与提示文案 —— cited。
	});
	connect(m_process70.data(), &ModemProcess::readyRead, this,
	        &ZModem::onProcessReadyRead);
	connect(m_process70.data(), &QProcess::errorOccurred, this, [this](QProcess::ProcessError e) {
		stateText(int(e));
	});

	m_thread68->start(QThread::TimeCriticalPriority); // 语料实参 7
}

// zmodem_init 中段三段正则(串实读):
//   +0x4a8 "(?:Sending|Receiving): *(?<transferFile>[^\r]+)"        (0x2f 字符)
//   +0x4b0 escape(<程序路径>) + ":?[^\\.]++\\."                      (0xb 字符)
//   +0x4b8 "(?:Sent|received): *(?<transferedSize>\\d+)(/ *(?<totalSize>\\d+))?"
void ZModem::setupPatterns()
{
	m_reA8 = new QRegularExpression( // operator_new(8)
	    QString::fromUtf8("(?:Sending|Receiving): *(?<transferFile>[^\\r]+)"));
	// escape 的实参在语料里被 sret 折叠(local_60 复用);按用途取程序路径。
	m_reB0 = new QRegularExpression(
	    QRegularExpression::escape(m_path58) + QStringLiteral(":?[^\\.]++\\."));
	m_reB8 = new QRegularExpression(
	    QString::fromUtf8("(?:Sent|received): *(?<transferedSize>\\d+)(/ *(?<totalSize>\\d+))?"));
}

// FUN_0079fd7e(882B)状态文案真身(tr 索引实读):0 启动失败 / 1 崩溃 / 2 超时 /
// 3 读错误 / 4 写错误 / 5 未知错误;末尾 arg(+0x60 程序名)后 showError(text, true)。
void ZModem::stateText(int code)
{
	QString text;
	switch (code) {
	case 0:
		text = tr("Process %1 failed to start.");
		break;
	case 1:
		text = tr("Process %1 crashed.");
		break;
	case 2:
		text = tr("Process %1 timeout.");
		break;
	case 3:
		text = tr("An error occurred when attempting to read from the %1 process.");
		break;
	case 4:
		text = tr("An error occurred when attempting to write to the %1 process.");
		break;
	case 5:
		text = tr("An unknown error occurred in %1 process.");
		break;
	default:
		break;
	}
	showError(text.arg(m_name60), true);
}

// FUN_007a0f86(3062B)读槽真身(可复原段)。逐句:
//   channel == 0 → FUN_007a217c(取 stdout)→ FUN_0079b858(this, 该块)
//                   = writeData(...) 原样上行给会话(协议流回终端)
//   channel != 1 → 返回
//   channel == 1 → FUN_007a2120(取 stderr)→ 非 null 则 fromUtf8 追加到 +0x88
//                  → QString::replace(+0x88, m_reB0)(抹掉程序路径)
//                  → 按换行切行;末行不以 \r 或 \n 结尾则留回 +0x88
//                  → 逐行 trimmed;空行跳过
//                     · 行含 "transfer"(m_matcher90)→ 不解析,只显示
//                     · 否则 match(m_reB8) 命中 → captured("transferedSize")
//                       / captured("totalSize")→ transferProgress(done, total)
//                     · 否则 match(m_reA8) 命中 → +0x38 = captured("transferFile"),
//                       行尾补 CRLF,m_progress.reset()(FUN_0079a598)
//                     · 每行最后 path_normalizeSep(行) 显示
void ZModem::onProcessReadyRead(int channel)
{
	if (m_process70.isNull())
		return;

	if (channel == 0) {
		writeData(m_process70->takeStdout()); // 007a217c → 0079b858
		return;
	}
	if (channel != 1)
		return;

	const QByteArray err = m_process70->takeStderr(); // 007a2120
	if (!err.isNull())
		m_f88 += QString::fromUtf8(err);
	// 抹掉程序路径(替换串被 sret 折叠 —— cited)
	m_f88.replace(*m_reB0, QString());

	static const QRegularExpression kSep(QStringLiteral("[\r\n]"));
	QStringList lines = m_f88.split(kSep, Qt::KeepEmptyParts);
	if (!m_f88.endsWith(QLatin1Char('\n')) && !m_f88.endsWith(QLatin1Char('\r')))
		m_f88 = lines.takeLast(); // 残段留待下次
	else
		m_f88.clear();

	for (const QString &raw : lines) {
		QString line = raw.trimmed();
		if (line.isEmpty())
			continue;
		if (m_matcher90.indexIn(line) == -1) { // 不含 "transfer" 才解析
			const QRegularExpressionMatch prog = m_reB8->match(line);
			if (prog.hasMatch()) {
				const qlonglong done = prog.captured(QStringLiteral("transferedSize")).toLongLong();
				const qlonglong total = prog.captured(QStringLiteral("totalSize")).toLongLong();
				transferProgress(done, total);
			} else {
				const QRegularExpressionMatch file = m_reA8->match(line);
				if (file.hasMatch()) {
					m_receiveFileName = file.captured(QStringLiteral("transferFile")); // +0x38
					if (!line.endsWith(QLatin1Char('\n')))
						line += QStringLiteral("\r\n");
					m_progress.reset(); // FUN_0079a598(this + 0x10)
				}
			}
		}
		appendText(line);
	}
}
