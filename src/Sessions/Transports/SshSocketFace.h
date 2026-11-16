#pragma once

#include <QList>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QWaitCondition>

class QAbstractSocket;

// SshSocketFace — SSH 通道用的套接字包装(带互斥/等待条件/待写队列)。
//
// 出处:RTTI "SshSocket";QMetaObject 0x011a94c0
// (rev=8,class="SshSocket",methods=5,**signals=4**,props=0,superdata=0);
// sizeof = **0x60**(deleting 0x0086ed2e 的 operator_delete(_,0x60));
// dtor 0x0086ebee(320B);信号/槽桥 0x00918540(502B);
// metacast 0x00918746 / metacall 0x00918788(109B)。
//
// 四条信号(串表实读)+ 一条槽:
//   #0 disconnected()              0 参 → 0x00918498
//   #1 errorOccurred(...)          1 参(整槽)→ 0x009184a8
//   #2 listening(...)              1 参(**quint16**)→ 0x009184de
//   #3 writing(...)                1 参 → 0x00918516
//   #4 connectHost(...)            槽 —— case 4 是 `goto caseD_4`,
//      函数尾段先 `QMetaType::registerNormalizedType(..., QAbstractSocket::
//      staticMetaObject)` 注册元类型(缓存进 DAT_011c2498),再走
//      `s_session_proxyWorkingDirectory_86c7b2(this, &str, …)` 建连。
//
// 字段(dtor 实读,顺序即释放序):
//   +0x18 QAbstractSocket*   先 flush 再走 vtable+0x20 释放,置 0
//   +0x20 QAbstractSocket*   同上(先调 FUN_0065cf9c 再 flush)
//   +0x30 QMutex             **inline**(析构最末尾才 ~QMutex)
//   +0x38 QWaitCondition     inline
//   +0x48 QList<写队列>       元素经 FUN_0063a5f2(+0x50, elem) 释放
//   +0x50 void*              队列元素的释放上下文
class SshSocketFace : public QObject {
	Q_OBJECT

public:
	explicit SshSocketFace(QObject *parent = nullptr);
	~SshSocketFace() override; // 0x0086ebee

signals:
	void disconnected();               // #0
	void errorOccurred(int errorCode); // #1
	void listening(quint16 port);      // #2
	void writing(const QString &data); // #3

public slots:
	void connectHost(const QString &host); // #4

private:
	QAbstractSocket *m_sock18 = nullptr; // +0x18
	QAbstractSocket *m_sock20 = nullptr; // +0x20
	mutable QMutex m_mutex30;            // +0x30
	QWaitCondition m_wait38;             // +0x38
	QList<void *> m_queue48;             // +0x48
	void *m_ctx50 = nullptr;             // +0x50
};
