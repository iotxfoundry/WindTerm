#ifndef SSHBRIDGE_H
#define SSHBRIDGE_H

#pragma once

#include "SuperBridge.h"

#include <QSharedPointer>
#include <functional>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
//
// 出处:QMetaObject 0x011a9020(rev=8,class="SshBridge",superdata ⇒ SuperBridge);
// 信号在基类之外再加两条(串表实读,发射器 0x00918028 / 0x00918062):
//   #0 sftpCreated(const QUuid &transferUuid)     (activate idx 0)
//   #1 shellCreated(const QUuid &commanderUuid)   (activate idx 1)
// sizeof = **0x170**(deleting 0x00866e32 的 operator_delete(_,0x170))。
//
// 字段(析构 0x00866c36 与三个取用器 0x00862692/0x008626c6/0x0086270a 实读):
//   +0x30/+0x38  弱引用 + 对象一对(析构里两者皆在才走 vtable+0x20 释放)
//   +0x40/+0x48  同上,第二对
//   +0x50/+0x58  同上,第三对 —— 三个取用器都只认这一对
//   +0x70        另一件(0x0086270a 先查它 + FUN_00627600)
//   +0x150       引用计数件(析构里计数减一,归零 operator_delete)
//   +0x160/+0x168  QSharedPointer(数据指针 + 对象);0x00864630 惰建
//   +0x170 之后无字段(sizeof 0x170 收口)
class SshBridge : public SuperBridge
{
	Q_OBJECT

public:
	SshBridge(QObject *parent = nullptr);
	~SshBridge() override; // 0x00866c36(508B)

	// 0x00864630(437B)—— 惰建 +0x160/+0x168 的共享件(0x40B,
	// FUN_00869f80)并接线到 0x0091823c。语料签名 (this, a, b) 两实参。
	void ensureShared();

signals:
	void sftpCreated(const QUuid &transferUuid);
	void shellCreated(const QUuid &commanderUuid);

public slots:
	void distributeCommandOutput(const QString &output);

private:
	Q_DISABLE_COPY(SshBridge)

	// 三个取用器(虚面 vt13/vt14/vt15)—— 都只读 +0x50/+0x58 那一对
	void takeWith086c20a(void *out) const; // vt13 0x00862692(52B)
	void takeWith086c312(void *out) const; // vt14 0x008626c6(52B)
	void takeWith086bf84() const;          // vt15 0x0086270a(58B)

	QList<std::function<void(const QString &)>> m_subscribers;

	void *m_pair30 = nullptr;        // +0x30
	void *m_pair38 = nullptr;        // +0x38
	void *m_pair40 = nullptr;        // +0x40
	void *m_pair48 = nullptr;        // +0x48
	void *m_pair50 = nullptr;        // +0x50
	void *m_pair58 = nullptr;        // +0x58
	void *m_f70 = nullptr;           // +0x70
	void *m_ref150 = nullptr;        // +0x150
	QSharedPointer<void> m_shared160; // +0x160/+0x168
};

#endif // SSHBRIDGE_H
