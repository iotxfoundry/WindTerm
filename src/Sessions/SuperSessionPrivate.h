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

// SessionLogger(语料 SessionLogger_vtable 类,0024.c 区):+0x40 表值。
// ctor FUN_007c1b38(90B,0024.c:30589)字段初始化面转写 —— QObject 基
// (param_3=parent)+ vtable 置换 + +0x10 session + +0x18 清零 +
// +0x20/+0x28 QString shared_null + +0x30..+0x40 shared_ptr 清。
// 拆除面 SessionLogger_dtor(007c1bba,205B,0024.c:30620):+0x40
// shared_ptr _M_release(spdlog sink 面,cited)+ +0x30 state(0x48B)
// delete + 双 QString 释放 —— 成员析构自动承接,不另写。
class SessionLogger : public QObject
{
public:
	// FUN_007c1b38 @007da317(operator_new(0x48)后):param_2=session,
	// param_3=0(无父)
	explicit SessionLogger(SuperSession *session)
		: QObject(nullptr), m_session(session) {}

	SuperSession *m_session = nullptr;   // +0x10(007c1b52:*(param_1+0x10)=param_2)
	unsigned char m_flags18 = 0;         // +0x18(007c1b5b 二字节清零;腿体
	                                     // @007c35e2 位域写 +0x18/+0x19)
	QString m_s20;                       // +0x20(shared_null 初始化)
	QString m_s28;                       // +0x28(腿体 @007c2528 operator= ← 文件名参;
	                                     // 参源 list[3]/list[4] 折叠未定,不猜,保默认)
	void *m_state30 = nullptr;           // +0x30(session_state,007c350a 换新)
	void *m_sink38 = nullptr;            // +0x38(spdlog logger,007c334a 存)
	void *m_sink40 = nullptr;            // +0x40(spdlog sink,007c3356 存)
};

class SuperSessionPrivate
{
public:
	explicit SuperSessionPrivate(SuperSession *q);
	~SuperSessionPrivate();

	// --- 注册表(逆向:Commander/Term/Transfer/Logger 四个 UUID→对象表)---
	void removeRegistry(int kind, const QUuid &id);
	void loggerOp(const QUuid &id, int op);

	// FUN_007da228(475B,0025.c:7540)= +0x40 Logger 表插入侧
	// (session_applySetting 007dc146 case 0xd @007dc4d8 调用)。
	// 语料三源定 kind:ctor 007c1b38 置 SessionLogger_vtable;配对
	// 移除 007db8ee@+0x40 发 loggerRemoved;信号 00912264 =
	// activate(idx5)= loggerCreated(IMPL-ADDRESSES #5;qmo idx 序:
	// 0 asyncMessage/1 autoLoginFailed/2 commanderCreated/3
	// commandOutput/4 errorOccurred/5 loggerCreated/6 loggerRemoved
	// /7 stateChanged/8 syncMessage/9 termCreated/10 transferCreated)。
	// 任务书原记"Term 表"系判读偏差;+0x20 Term 插入侧已定位:
	// FUN_007d9776(见 insertTermSession)。
	// 五 QVariant 参(int×3 + QString×2,@007da25a-2f1 解引用面)
	void insertLoggerSession(const QUuid &id, const QVariantList &settings);

	// +0x20 Term 表插入侧 = FUN_007d9776(1596B,0025.c:7110):查
	// Commander 表(007d6cee)既有节点则复用;否则按 option
	// "session.protocol" 分派 Tcp/Telnet/SSH/Serial/Shell 便携 ctor
	// (FUN_00876a16/0085f520/008699b0/0086ff6c/008750e6)→ connect
	// 同步信号(FUN_007da178 为其 lambda 捕获体)→ spinlock@+0x61 →
	// QMap 插入 node(0x30,+0x18 uuid/+0x20 commander 强ref/+0x28
	// session)→ termCreated = FUN_00912312(idx3,2 参:uuid+name)。
	// 下行层(protocol ctor 族 ≥0x88B/FUN_007cd120 主升面)未开 →
	// 对象 cited 空壳注册,表/信号行为真实现。
	void insertTermSession(const QUuid &id, const QString &name);

	// +0x28 Transfer 表插入侧 = FUN_007daedc(1803B,0025.c:8036):
	// option "session.protocol" qstricmp Sftp/SSH → FUN_008e81b2
	// (0x88B)/else FUN_008e3784(0x88B)+ sftp.* 三 option 位写入
	// (对象 +0x58 bit0/1/2 @007db26a)+ spinlock@+0x61 → QMap 插入
	// node(0x28,+0x8 uuid/+0x10 对象)+ FUN_0061b448 挂线程池 →
	// transferCreated = FUN_009122e8(idx10,1 参;仅非 Sftp/SSH 协议
	// 发,@007db4a3)。下行 ctor 0x88B 未开 → cited 空壳。
	void insertTransferSession(const QUuid &id, const QString &name);

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

	// 测试行为门访问(仅 reginserttest;表内容非行为面)
	const QMap<QUuid, void *> *registry() const { return m_registry; }

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
