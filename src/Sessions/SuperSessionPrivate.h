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

// SessionTransfer(语料 LocalTransfer/SftpTransfer 公共基 =
// s_filer_hiddenItemsVisible_8ec79a,502B,0028.c:38135):+0x28 表值
// (QMap node 0x28:+0x8 uuid/+0x10 obj)。批 145 ctor 字段面真身化
// —— 基体 008ec79a(Sftp/Local Transfer 共同基 ctor)+ 下行
// FUN_008e81b2(Sftp,60B)/FUN_008e3784(Local,106B)::
//   +0x00 vtable 置换(+0x10 session 覆写 @8ec7*由下行)/
//   +0x10 session(param_2)/+0x18/+0x20 清/+0x28..+0x48 容器清/
//   +0x40 filer.hiddenItemsVisible(global_setting_get @8ec875)/
//   +0x50/+0x54 = 0x1a4/0x1ed(@8ec9* 常量对;FUN_008eb532/540 卫同值)
//   +0x58 bit0..2 = 1(默认 sftp 位 @8ec8*)/+0x59 清/+0x5c..+0x6c 清/
//   +0x78 容器清。
// 下行依赖 cited:Sftp=FUN_008e8150(98B:session==+0x80 短路;
//   SftpTransfer_h8e72d6→FUN_008ecc38 清单)+ FUN_008eadd6(637B
//   connectImpl 信号族)→ 网络/fsModel 面,未开;cited 逐地址登记。
//   Local:FUN_008e533d(130B QTimer lambda;FUN_008e4fea 下行未开)。
class SessionTransfer : public QObject
{
public:
	// FUN_008e81b2(param_2=session,param_3=0)/FUN_008e3784(…,1):
	// 二者公共基 = 008ec79a 字段面;下行差异仅 vtable + 条件 lambda
	// (008e3784 param_3!=0 → QTimer::singleShotImpl 0x18 lambda)
	// —— 本树对象共用字段面,vtable 差异以 m_isSftp 记录(下行层
	// 未开,注记照 insertTermSession 便携 ctor 族判例)。
	explicit SessionTransfer(bool sftp, QObject *session)
		: QObject(nullptr), m_session(session), m_isSftp(sftp) {}

	QObject *m_session = nullptr;        // +0x10(008ec79a @base: param_2)
	bool m_isSftp = false;               // vtable 分派面(Sftp/Local,008e81b2/3784)
	void *m_model18 = nullptr;           // +0x18(008ec8e2 sink 挂点,清零)
	void *m_model20 = nullptr;           // +0x20(shared_ptr,清零)
	int m_hiddenItems40 = 0;             // +0x40(global_setting_get "filer.hiddenItemsVisible" @008ec875)
	int m_perm50 = 0x1a4;                // +0x50 文件创建权限 0o644(@8ec9*)
	int m_perm54 = 0x1ed;                // +0x54 目录创建权限 0o755(@8ec9*)
	unsigned char m_bits58 = 7;          // +0x58 bit0..2 默认全 1(@8ec8* |7)

	// 007daedc @007db26a-2a9:sftp.* 三 option 位写入(bit0 直接,
	// bit1/bit2 移位合写)+ FUN_008eb532/540(13B×2:0 → 0x1a4/0x1ed)
	void applySftpOptions(unsigned fixInvalid, unsigned preserveFile,
	                      unsigned preserveFolder)
	{
		m_bits58 = (unsigned char)((m_bits58 & 0xf8) | (fixInvalid & 1) |
		                           ((preserveFile & 1) << 1) |
		                           ((preserveFolder & 1) << 2));   // @007db26a
	}
	void setFilePerm(int v)  { m_perm50 = v ? v : 0x1a4; }  // FUN_008eb532(13B)
	void setFolderPerm(int v) { m_perm54 = v ? v : 0x1ed; } // FUN_008eb540(13B)
};

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
	unsigned char m_flags19 = 0;         // +0x19:bit0=启用(腿尾 @007c35e8=param_4);
	                                     // bit2=keepFlag(removeRegistry 007db8ee 免拆位)

	// 建腿调面 = FUN_007c24c8(5980B,0024.c:31047)分面转写(批 145):
	// 真实现 = 启用卫/+0x28 label/标志尾;cited 三段见 SuperSessionPrivate.cpp
	// (pattern/路径装配、spdlog sink/logger 构造、formatter/state 尾段)。
	// 参形照语料:param_2=target 串(007d5b1a)/param_3=label(007d4d9c)/
	// param_4=启用/param_5=标志字节(bit0=append)/param_6=轮转字节/
	// param_7=文件名 pattern/param_8=行 pattern。
	bool buildLeg(const QString &target, const QString &label, bool enable,
	              unsigned char flags, int rotateBytes,
	              const QString &fileNamePattern, const QString &linePattern);
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
	// /else FUN_008e3784(批 145:对象真身 SessionTransfer,基体
	// 008ec79a 字段面)+ sftp.* option 读 → 位/权限写(真实现,
	// FUN_008eb532/540)+ spinlock@+0x61 → QMap 插入 node(0x28,
	// +0x8 uuid/+0x10 对象)+ FUN_0061b448 挂线程池(cited)→
	// transferCreated = FUN_009122e8(idx10,1 参;仅非 Sftp/SSH 协议
	// 发,@007db4a3)。下行网络/fsModel 面 → cited(见 SessionTransfer 注)。
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
