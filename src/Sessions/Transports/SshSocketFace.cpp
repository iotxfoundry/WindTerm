// SshSocketFace.cpp — SSH 套接字包装。

#include "Sessions/Transports/SshSocketFace.h"

#include <QAbstractSocket>

static void detachSocketPre(void *sock);        // 0x0065cf9c
static void releaseQueueElem(void *ctx, void *elem); // 0x0063a5f2
static void connectViaProxy(SshSocketFace *self, const QString &host, ...); // 0x0086c7b2

SshSocketFace::SshSocketFace(QObject *parent)
    : QObject(parent)
{
}

// 0x0086ebee(320B)dtor 真身 —— **全程持锁**:
//   vptr = &SshSocket_vtable;
//   m_mutex30.lock();
//   ① +0x20:先 FUN_0065cf9c,再 flush(),再走 vtable+0x20 释放,置 0
//   ② +0x18:flush(),再走 vtable+0x20 释放,置 0
//   ③ +0x48 队列:detach 后逐元素 FUN_0063a5f2(+0x50, elem),
//      再把队列换回 shared_null
//   m_mutex30.unlock();   ← 注意:unlock 之后才真正释放队列本体
//   ~QWaitCondition(+0x38) → ~QMutex(+0x30) → QObject 析构
// deleting 0x0086ed2e(23B):同上 + operator_delete(this, 0x60)。
SshSocketFace::~SshSocketFace()
{
	QMutexLocker lk(&m_mutex30);
	delete m_sock20;
	m_sock20 = nullptr;
	delete m_sock18;
	m_sock18 = nullptr;
	m_queue48.clear();
}

// 0x00918540(502B)桥真身:
//   op=0:index 0..3 依次 emit;index 4 → caseD_4(connectHost)
//   op=10:反查发射器,写回 0..3
//   op=0xc:**元类型注册面** —— args[1] 为 0 时才做,index 1 有效;
//          QMetaType::normalizedType → registerNormalizedType(…,
//          &QAbstractSocket::staticMetaObject),结果缓存进 DAT_011c2498,
//          并写回 *args。这就是 Qt 侧"自定义信号形参必须先注册元类型"的标准腿。
void SshSocketFace::connectHost(const QString &host)
{
	// caseD_4:先注册元类型(见上),再 0x0086c7b2 走代理建连
	Q_UNUSED(host);
}
