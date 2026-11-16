#include "Sessions/Transfers/ModemProcess.h"

#include <QByteArrayMatcher>

// ─────────────────────────────────────────────────────────────────────────────
// 出处:tools/re/decomp/decomp-part-0024.c(0x007a200e..0x007a2720)。
// 「外部程序」取证见 docs/ext-boundary.md 附录:vendors/lrzsz/{rz,sz} 为原版随包
// 的 stripped 可执行文件,优先 applicationDirPath()/vendors/lrzsz,缺失回退系统。
// ─────────────────────────────────────────────────────────────────────────────

// termproc_init(0x007a230e,869B)ctor 真身:
//   QProcess::QProcess(this, parent) → vptr = ModemProcess vtable
//   → +0x10 = new QMutex(8B)、+0x18 = new QWaitCondition(8B)
//   → +0x20 = 0、+0x24 = mode、+0x28 = 0
//   → +0x30/+0x38 = QByteArray 空、+0x40 = 0
//   → 两个函数级 static 的 QMetaType::registerNormalizedType(输出负载类型)
//   → +0x40 = new QByteArrayMatcher(QByteArray("**\x18B0800000000022d\r"@0xca3cb8))
//   → FUN_007a2214(接线)
ModemProcess::ModemProcess(int mode, QObject *parent)
    : QProcess(parent) // QProcess::QProcess(this, parent)
    , m_mode24(mode) // +0x24
{
	m_mutex10 = new QMutex; // operator_new(8)
	m_cond18 = new QWaitCondition; // operator_new(8)
	m_f20 = false; // +0x20
	m_matched28 = false; // +0x28
	// 两个 QMetaType::registerNormalizedType(…, QProcess::staticMetaObject)
	// —— 函数级 static 一次性注册,cited。
	// 0xca3cb8 实读 19 字节:"**" 0x18 "B08" "0000000022d" "\r"
	static const char kPattern[] = {'*', '*', '\x18', 'B', '0', '8', '0', '0',
	                                '0',  '0', '0',  '0', '0', '0', '2', '2',
	                                'd',  '\r'};
	m_matcher40 = new QByteArrayMatcher(QByteArray(kPattern, sizeof(kPattern)));
	wire(); // 007a2214
}

// ModemProcess_dtor(0x007a200e,249B)真身(顺序实读):
//   vptr → 删 +0x10(QMutex,8B)→ +0x18(QWaitCondition,8B)
//   → +0x40(QByteArrayMatcher,0x410B)→ +0x38 / +0x30(QByteArray)
//   → QProcess::~QProcess
ModemProcess::~ModemProcess()
{
	delete m_mutex10;
	m_mutex10 = nullptr;
	delete m_cond18;
	m_cond18 = nullptr;
	delete m_matcher40;
	m_matcher40 = nullptr;
}

// FUN_007a2214(249B)接线真身:
//   connect(this, QProcess::readyReadStandardOutput, this, functor 007a1d70)
//   connect(this, QProcess::readyReadStandardError,  this, functor 007a1f07)
void ModemProcess::wire()
{
	connect(this, &QProcess::readyReadStandardOutput, this,
	        &ModemProcess::onReadyReadStandardOutput);
	connect(this, &QProcess::readyReadStandardError, this,
	        &ModemProcess::onReadyReadStandardError);
}

// FUN_007a1d70(399B)stdout 槽真身。逐句:
//   有 +0x10 → 加锁;+0x20(结束旗标)已置 → 解锁返回
//   +0x30 非空 → QWaitCondition::wait(+0x18, +0x10, 无限)(等消费方取走)
//   +0x20 仍为 0 → +0x30 = readAllStandardOutput()
//     mode(+0x24) == 0(接收):
//        未命中(+0x28 == 0)→ emit readyRead(0)
//        matcher(+0x40) 在 +0x30 里命中 → +0x28 = 1 且 closeWriteChannel()
//     否则 → emit readyRead(0)
void ModemProcess::onReadyReadStandardOutput()
{
	const bool locked = (m_mutex10 != nullptr);
	if (locked)
		m_mutex10->lock();

	if (m_f20) { // 已结束
		if (locked)
			m_mutex10->unlock();
		return;
	}
	if (!m_out30.isEmpty())
		m_cond18->wait(m_mutex10); // 等消费方取走,无限等待

	if (!m_f20) {
		m_out30 = readAllStandardOutput(); // +0x30
		if (m_mode24 == 0) {
			if (!m_matched28)
				emit readyRead(0);
			if (m_matcher40->indexIn(m_out30) != -1) {
				m_matched28 = true; // +0x28
				closeWriteChannel();
			}
		} else {
			emit readyRead(0);
		}
	}
	if (locked)
		m_mutex10->unlock();
}

// FUN_007a1f07(247B)stderr 槽真身:加锁 → readAllStandardError → 未结束则
// 追加到 +0x38 并 emit readyRead(1) → 解锁。
void ModemProcess::onReadyReadStandardError()
{
	const bool locked = (m_mutex10 != nullptr);
	if (locked)
		m_mutex10->lock();

	const QByteArray err = readAllStandardError();
	if (!m_f20) {
		m_err38 += err; // +0x38
		emit readyRead(1);
	}
	if (locked)
		m_mutex10->unlock();
}

// FUN_007a217c(135B):取走 +0x30 并 wakeOne(+0x10 存在时持锁)。
QByteArray ModemProcess::takeStdout()
{
	if (m_mutex10 != nullptr) {
		m_mutex10->lock();
		QByteArray out = m_out30;
		m_out30.clear();
		m_cond18->wakeOne();
		m_mutex10->unlock();
		return out;
	}
	QByteArray out = m_out30;
	m_out30.clear();
	m_cond18->wakeOne();
	return out;
}

// FUN_007a2120(92B):取走 +0x38(不唤醒)。
QByteArray ModemProcess::takeStderr()
{
	if (m_mutex10 != nullptr) {
		m_mutex10->lock();
		QByteArray out = m_err38;
		m_err38.clear();
		m_mutex10->unlock();
		return out;
	}
	QByteArray out = m_err38;
	m_err38.clear();
	return out;
}

// FUN_007a26be(16B):+0x20 = 1;wakeOne。
void ModemProcess::signalFinished()
{
	m_f20 = true;
	m_cond18->wakeOne();
}

// FUN_007a26ce(10B):QProcess::start(QIODevice::ReadWrite) —— 语料实参 3。
void ModemProcess::startProcess()
{
	start(QIODevice::ReadWrite);
}

// FUN_007a26d8(66B)下行写:
//   +0x24 == 1 时用 matcher 在待写数据里找 "**\x18B08…" 特征 → 命中则 +0x28 = 1
//   然后 QIODevice::write(data)。
void ModemProcess::writeData(const QByteArray &data)
{
	if (m_mode24 == 1 && m_matcher40->indexIn(data) != -1)
		m_matched28 = true;
	write(data); // QIODevice::write
}

// FUN_007a2720(18B):memset(*(void **)(this + 0x20), 1, *(int *)(this + 0x1c))
// —— 反编译在此处把 +0x20(bool)当指针解引(与 0x007a26be 的字节写冲突),
// 原意疑为「按长度填充缓冲区」;语义未复原,cited。
void ModemProcess::clearFlag()
{
}
