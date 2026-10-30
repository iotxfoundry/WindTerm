#ifndef SUPERSESSIONPRIVATE_H
#define SUPERSESSIONPRIVATE_H

#pragma once

#include <QMetaType>
#include <QString>
#include <QVariant>
#include <QUuid>
#include <libssh/libssh.h>

// SuperSession 的 SSH 认证/主机校验实现(混合架构:真 libssh)。
// 逆向语义锚:SSH-INTERNALS.md;信号族(moc 真名)见 SuperSession.h。
// 0x40xxxx 区 auth* 实现 → libssh API 直映射,session 句柄经
// SuperSession::m_d 携带。

class SuperSession;

class SuperSessionPrivate
{
public:
	explicit SuperSessionPrivate(SuperSession *q);
	~SuperSessionPrivate();

	// --- 注册表(逆向:Commander/Term/Transfer/Logger 四个 UUID→对象表)---
	void removeRegistry(int kind, const QUuid &id);
	void loggerOp(const QUuid &id, int op);

	// FUN_007da178(168B,批 43/47 转写):commander→session 链 ——
	// FUN_007d6cee(119B)查注册表节点(spinlock@+0x61 + FUN_007ddad0
	// map@+0x18 查)→ dynamic_cast 校验 → session 非空写
	// commander+0x48,空 → FUN_007da09a(208B)qmap_detach2 移除
	// 语料成员:QMap @+0x18(spinlock@+0x61;单线程重建免锁,注记)
	QMap<class SuperCommander *, class SuperCommander *> m_commanderLinks;   // +0x18
	void linkCommanderSession(class SuperCommander *commander,
	                          class SuperSession *session);

	// --- 选项(逆向:option(const&)→读;setOption→写;CTerminalConfig
	//     单例为真下层,键串如 "terminal.startupSessions")---
	QVariant option(const QString &name, const QVariant &defaultValue) const;
	void setOption(const QString &name, const QVariant &value);

	// --- 连接与状态(逆向:状态机见 STATE-MACHINE.md)---
	bool openSession(const QString &host, int port, const QString &user);
	void closeSession();

	// --- 主机校验(0x4xxxxx:verifyKnownHost/writeKnownHost)---
	// libssh ssh_session_is_known_server: ServerKnown 状态族与
	// King::ServerKnownState 逐值对齐(SSH-INTERNALS.md)
	int verifyKnownHost();
	void writeKnownHost(int knownState);

	// --- 认证族(moc 真名,14 个;信号 auth* 见 SuperSession.h)---
	int authAgent(const QString &service);
	int authNone(const QString &service);
	int authGssapiWithMic(const QString &service);
	int authPassword(const QString &service, const QString &password);
	int authPublicKey(const QString &identityFile, const QString &passphrase);
	int authInteractive(const QString &service);
	int authKeyboardInteractive(const QString &service, const QString &password);
	QStringList authMethods() const;

	ssh_session session() const { return m_session; }

private:
	SuperSession *q;
	ssh_session m_session = nullptr;
	mutable QStringList m_authMethods;
	// 四注册表(kind 0=Commander 1=Term 2=Transfer 3=Logger);
	// SuperSession_h7d7096(dtor 走查)实证注册表为 QMap<QUuid,obj>,
	// 逐对象 vtable+0x20 拆除
	QMap<QUuid, void *> m_registry[4];
};

#endif // SUPERSESSIONPRIVATE_H
