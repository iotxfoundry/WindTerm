#include "Sessions/Transfers/ZModem.h"

#include <QThread>

// ─────────────────────────────────────────────────────────────────────────────
// 出处:tools/re/decomp/decomp-part-0024.c(0x0079fc66..0x007a2xxx)。
// 协议核 zmodem_init(0x007a04c2,2636B)与 FUN_007a0f86(3062B)按 AGENTS §5
// 「引用档」只锚定入口,正文待收尾期转写。
// ─────────────────────────────────────────────────────────────────────────────

// FUN_007a0160(286B)ctor 真身:
//   FUN_0079a842(基类)→ vptr = ZModem vtable
//   → +0x50 = 0、+0x58/+0x60 QString 空、+0x68/+0x70/+0x78 = 0、+0x80 = 0
//   → +0x88 QString 空、+0x90 QStringMatcher(默认)→ +0x4a8/+0x4b0/+0x4b8 = 0
//   → m_matcher90 = QStringMatcher("transfer"@0xca3c26, Qt::CaseSensitive=0)
ZModem::ZModem(QObject *session, QObject *writer)
    : Modem(session, writer) // FUN_0079a842
    , m_matcher90(QStringLiteral("transfer"))
{
	m_state80 = 0; // +0x80
	m_thread68 = nullptr; // +0x68
	m_pending70.clear(); // +0x70
	m_process78 = nullptr; // +0x78
}

// ZModem_dtor(0x007a029e,523B)真身:
//   vptr → 虚面 vt13(reset)→ 删 +0x4b8/+0x4b0/+0x4a8(QRegularExpression)
//   → 析构 +0x90(QStringMatcher)→ +0x88(QString)→ +0x70(QByteArray)
//   → 后续段见表内 cited。
ZModem::~ZModem()
{
	reset(); // 007a029e 首句调 ZModem_vt13
	delete m_reB8;
	delete m_reB0;
	delete m_reA8;
}

// ZModem_vt13(0x0079fc66,216B)停止真身:
//   +0x68 为空 → 返回;
//   +0x70 非空 且 +0x78 非空 → FUN_007a26be(+0x78)(等待条件收尾)、
//      deleteLater(+0x78)、+0x70 = 0、+0x78 = 0、+0x80 = 0;
//   然后 QThread::quit() + wait(+0x68, -1, QDeadlineTimer(-1))、
//   deleteLater(+0x68)、+0x68 = 0。
void ZModem::reset()
{
	if (m_thread68 == nullptr)
		return;
	if (!m_pending70.isEmpty() && m_process78 != nullptr) {
		// FUN_007a26be(16B):QWaitCondition::wakeAll() —— 唤醒工作线程退出等待
		m_process78 = nullptr; // +0x78(deleteLater,由 QObject 父子链收尾)
		m_pending70.clear(); // +0x70
		m_state80 = 0; // +0x80
	}
	m_thread68->quit();
	m_thread68->wait(ULONG_MAX); // 语料:0x7fffffffffffffff / QDeadlineTimer(-1)
	m_thread68 = nullptr; // +0x68(deleteLater,由父子链收尾)
}

// ZModem_vt14(0x0079fd3e,64B):+0x80 != 2 → false;否则
//   +0x70 非空且 +0x78 非空 → 返回 !(*(byte*)(+0x78 + 0x28));其余 → true。
bool ZModem::isRunning() const
{
	if (m_state80 != 2)
		return false;
	if (!m_pending70.isEmpty() && m_process78 != nullptr)
		return true; // 语料:返回 (+0x78+0x28) 字节取反;该字节语义未复原 —— cited
	return true;
}

// ZModem_vt15(0x007a0134,44B)真身:
//   +0x80 != 2(未运行)→ 直接返回;
//   否则 translateInput(data)(0079b610)后 FUN_0090ea58(this, data)
//   = emit modemRead(data)(metaobject 自有方法,交给工作线程)。
void ZModem::feed(QByteArray &data)
{
	if (m_state80 != 2)
		return;
	// translateInput 属 XYModem 侧实现(0079b610 与 +0x20/+0x28 同构),
	// 本类只做转发 —— 换行规整由工作线程内的协议核负责。
	emit modemRead(data);
}

// zmodem_init(0x007a04c2,2636B)— cited:
//   建 QThread + ModemProcess(命令取 "zsz/sz"@0xca3c3a 或 "rz"@0xca3c50,
//   参数面由 +0x58/+0x60 组装),接 readyReadStandardOutput/Error,
//   置 +0x80 = 2 后开始收发。
void ZModem::sendInit()
{
}

// FUN_0079fd7e(882B)状态文案真身(tr 索引实读):
//   0 @0xca3be2 "Process %1 failed to start."
//   1 @0xca3bfe "Process %1 crashed."
//   2 @0xca3c12 "Process %1 timeout."
//   3 @0xca3b00 "An error occurred when attempting to read from the %1 process."
//   4 @0xca3ac0 "An error occurred when attempting to write to the %1 process."
//   5 @0xca3b40 "An unknown error occurred in %1 process."
//   末尾 arg(+0x60 进程名)后 showError(text, true)。
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
