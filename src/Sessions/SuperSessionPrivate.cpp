#include "SuperSessionPrivate.h"
#include "SuperCommander.h"
#include "SuperSession.h"

#include <QMap>
#include <QVariantList>
#include <new>
#include "../Editor/CTerminalConfig.h"

// 混合实现:逆向信号/方法名(moc 权威)× 真 libssh API。
// libssh 0.9.6+ 补丁精确源码见 src/libssh。

SuperSessionPrivate::SuperSessionPrivate(SuperSession *owner)
	: q(owner)
{
}

SuperSessionPrivate::~SuperSessionPrivate()
{
	closeSession();
}

// --- 注册表:四个 UUID→对象表(kind: 0=Commander 1=Term 2=Transfer 3=Logger)---
// 逆向锚(权威):SuperSession+0x18 Commander(007da09a:自旋锁 +0x61,
// 删同 uuid 全部节点,逐个释放 +0x18/+0x20,尾 vtable+0x20 拆除)/
// +0x20 Term(007dac60)/ +0x28 Transfer(007dad94)/ +0x40 Logger
// (007db8ee:keepFlag bit2@+0x19 免拆,发 loggerRemoved=0091228e)
// 插入侧消解(批 48c):FUN_007d6cee(119B)实证查表 = FUN_007ddad0
// (99B,QMap 节点行走,operator< 键比较)→ 容器 = QMap;插入 =
// QMap 定址写(查得即用/未查得建节点),无独立插入函数 —— 行为
// 由 QMap 语义覆盖。挂入/移除面 = FUN_007da178(linkCommanderSession
// 批 43 转写)与 FUN_007da09a(removeRegistry 转写);调用者
// 007da1ee/007da219/007dc314/00912927。会话 start 写表经
// linkCommanderSession 落位。
void SuperSessionPrivate::removeRegistry(int kind, const QUuid &id)
{
	if (kind < 0 || kind > 3)
		return;
	m_registry[kind].remove(id);
	if (kind == 3 && q)
		emit q->loggerRemoved(id);
}

void SuperSessionPrivate::loggerOp(const QUuid &id, int op)
{
	// moc 权威:case 33 flushLogger(007d4d7c,31B)/ 46 pauseLogger
	// (007db8a6,64B)/ 52 resumeLogger(007dc11e,39B):
	//   flush  = FUN_007c1b92(logger)(sink 冲刷 — cited)
	//   pause  = flush + 绑定 term +0x1c8 = 1
	//   resume = 绑定 term +0x1c8 = 0
	// term 查找语料经 FUN_007db6ce(logger);重建以同 uuid 跨表近似。
	void *logger = m_registry[3].value(id, nullptr);
	if (!logger)
		return;
	if (op == 1 || op == 0) {
		// FUN_007c1b92(logger) sink 冲刷 — cited(spdlog 面 Phase-4)
	}
	if (op == 1) {
		if (void *term = m_registry[1].value(id, nullptr))
			*(unsigned char *)((char *)term + 0x1c8) = 1;
	} else if (op == 2) {
		if (void *term = m_registry[1].value(id, nullptr))
			*(unsigned char *)((char *)term + 0x1c8) = 0;
	}
}

// --- 选项:CTerminalConfig 单例为下层(SESSION-CONFIG-LAYER.md ①)---
QVariant SuperSessionPrivate::option(const QString &name,
                                     const QVariant &defaultValue) const
{
	// 逆向:option(const&)/session_optGet → CTerminalConfig 单例
	// (FUN_00809d78)的会话/终端配置;键串 "terminal.*"/"editor.*" 等
	return CTerminalConfig::instance()->value(name, defaultValue);
}

void SuperSessionPrivate::setOption(const QString &name, const QVariant &value)
{
	// 逆向:setOption(name, value) → 写入配置覆盖
	CTerminalConfig::instance()->setValue(name, value);
}

bool SuperSessionPrivate::openSession(const QString &host, int port,
                                      const QString &user)
{
	closeSession();
	m_session = ssh_new();
	if (!m_session)
		return false;
	ssh_options_set(m_session, SSH_OPTIONS_HOST, host.toUtf8().constData());
	ssh_options_set(m_session, SSH_OPTIONS_PORT, &port);
	ssh_options_set(m_session, SSH_OPTIONS_USER, user.toUtf8().constData());
	// 逆向:connectImpl(0x7a5588)的会话建立路径
	if (ssh_connect(m_session) != SSH_OK)
		return false;
	return true;
}

void SuperSessionPrivate::closeSession()
{
	if (m_session) {
		ssh_disconnect(m_session);
		ssh_free(m_session);
		m_session = nullptr;
	}
}

// --- 主机校验:libssh 的已知主机状态与 King::ServerKnownState 对齐 ---
int SuperSessionPrivate::verifyKnownHost()
{
	if (!m_session)
		return -1;   // King::ServerUnknown
	return ssh_session_is_known_server(m_session);
	// SSH_KNOWN_SERVERS_OK..NOT_FOUND ↔ ServerKnown..ServerMismatched
}

void SuperSessionPrivate::writeKnownHost(int knownState)
{
	if (!m_session || knownState < 0)
		return;
	ssh_session_update_known_hosts(m_session);
}

// --- 认证族:每法返回 libssh 状态,信号由 SuperSession 侧发射 ---
int SuperSessionPrivate::authAgent(const QString &service)
{
	(void)service;
	return m_session ? ssh_userauth_agent(m_session, nullptr)
	                 : SSH_AUTH_ERROR;
}

int SuperSessionPrivate::authNone(const QString &service)
{
	return m_session
	    ? ssh_userauth_none(m_session, service.toUtf8().constData())
	    : SSH_AUTH_ERROR;
}

int SuperSessionPrivate::authGssapiWithMic(const QString &service)
{
	(void)service;
	return m_session ? ssh_userauth_gssapi(m_session)
	                 : SSH_AUTH_ERROR;
}

int SuperSessionPrivate::authPassword(const QString &service,
                                      const QString &password)
{
	return m_session
	    ? ssh_userauth_password(m_session, service.toUtf8().constData(),
	                            password.toUtf8().constData())
	    : SSH_AUTH_ERROR;
}

int SuperSessionPrivate::authPublicKey(const QString &identityFile,
                                       const QString &passphrase)
{
	if (!m_session)
		return SSH_AUTH_ERROR;
	ssh_key key;
	const int rc = ssh_pki_import_privkey_file(
	    identityFile.toUtf8().constData(),
	    passphrase.isEmpty() ? nullptr : passphrase.toUtf8().constData(),
	    nullptr, nullptr, &key);
	if (rc != SSH_OK)
		return rc;
	const int auth = ssh_userauth_publickey(m_session, nullptr, key);
	ssh_key_free(key);
	return auth;
}

int SuperSessionPrivate::authInteractive(const QString &service)
{
	// 键盘交互第一步:发起后由 authInteractiveUser/Prompts 回答
	// (moc 三方法 authInteractive×2/User/Prompts/Instruction 对应
	// libssh 的 challenge/response 状态机)
	return m_session
	    ? ssh_userauth_kbdint(m_session, service.toUtf8().constData(), nullptr)
	    : SSH_AUTH_ERROR;
}

int SuperSessionPrivate::authKeyboardInteractive(const QString &service,
                                                 const QString &password)
{
	if (!m_session)
		return SSH_AUTH_ERROR;
	const int rc = ssh_userauth_kbdint(
	    m_session, service.toUtf8().constData(), nullptr);
	if (rc != SSH_AUTH_INFO)
		return rc;
	const int n = ssh_userauth_kbdint_getnprompts(m_session);
	for (int i = 0; i < n; ++i) {
		ssh_userauth_kbdint_setanswer(
		    m_session, i, password.toUtf8().constData());
	}
	return ssh_userauth_kbdint(m_session, nullptr, nullptr);
}

QStringList SuperSessionPrivate::authMethods() const
{
	if (!m_session || m_authMethods.isEmpty()) {
		int methods = ssh_userauth_list(m_session, nullptr);
		QStringList out;
		if (methods & SSH_AUTH_METHOD_NONE)     out << "none";
		if (methods & SSH_AUTH_METHOD_PASSWORD) out << "password";
		if (methods & SSH_AUTH_METHOD_PUBLICKEY) out << "publickey";
		if (methods & SSH_AUTH_METHOD_HOSTBASED) out << "hostbased";
		if (methods & SSH_AUTH_METHOD_INTERACTIVE) out << "keyboard-interactive";
		if (methods & SSH_AUTH_METHOD_GSSAPI_MIC) out << "gssapi-with-mic";
		m_authMethods = out;
	}
	return m_authMethods;
}

// FUN_007da178(168B,批 43 语料转写):commander→session 链。
// 语料体:FUN_007d6cee(&node, this, commander)查注册表节点 →
//   node 非空 && node+4 非零 && session 非空 → dynamic_cast 校验
//   (PTR_011a7310/011a9050)→ session 非空写 commander+0x48,
//   空 → FUN_007da09a(this, commander)移除。
// 本树等价面:Commander UUID 表(kind 0)置/清 commander→session
// 链接;FUN_007d6cee/007da09a 对应本类注册表查/删(cited —
// wave-2:节点结构逐字段转写待注册表批)。
void SuperSessionPrivate::linkCommanderSession(SuperCommander *commander,
                                               SuperSession *session)
{
	// FUN_007da178(168B)语料转写:FUN_007d6cee(119B)查节点
	// (spinlock@+0x61 + FUN_007ddad0 map@+0x18;单线程重建免锁,
	// 注记)→ node+0x20 = commander → dynamic_cast 校验 →
	// commander+0x48 = session;session 空 → FUN_007da09a(208B)
	// qmap_detach2 移除
	if (commander == nullptr)
		return;
	if (session == nullptr) {
		m_commanderLinks.remove(commander);        // FUN_007da09a detach
		commander->m_session = nullptr;            // 语料 +0x48 清
		return;
	}
	m_commanderLinks.insert(commander, commander); // 语料 node+0x20
	commander->m_session = session;                // 语料 value+0x48 = session
}

// FUN_007da228(475B,0025.c:7540)转写:Logger 表插入。
// 入参核对(语料 @007da25a-2f1):param_3 = QVariantList(判空差
// ==5)+ 五 QVariant —— toInt×3(cVar2/cVar3/uVar4)+ toString×2。
// ctor FUN_007c1b38(90B,0024.c:30589)= SessionLogger 字段初始化面
// (批 144 转写,见 SuperSessionPrivate.h);腿体 FUN_007c24c8
// (5980B,0024.c:31047)= spdlog logger/sink 建腿(spdlog 下行层
// 外库边界,EXT-BOUNDARY)→ cited 引地址,不发明(铁律 3)。
// 失败腿 vtable+0x20 拆除 @007da3d7 保留;成功腿 spinlock@+0x61 →
// FUN_007e159e(this+0x40)插入 → FUN_00912264 = loggerCreated
// (idx5;IMPL-ADDRESSES #5,0030.c:1683)。单线程重建免锁,注记
// 照 007da178 判例。
void SuperSessionPrivate::insertLoggerSession(const QUuid &id,
                                              const QVariantList &settings)
{
	if (settings.size() != 5)  // 语料:*(int*)(l+0xc)-*(int*)(l+8)!=5 → return
		return;
	const int a0 = settings[0].toInt();   // @007da25a(cVar2,→腿体 param_4)
	const int a1 = settings[1].toInt();   // @007da262(cVar3,→param_5)
	const int a2 = settings[2].toInt();   // @007da26a(uVar4,→param_6)
	const QString s3 = settings[3].toString();  // @007da2dd(→param_7)
	const QString s4 = settings[4].toString();  // @007da2ed(→param_8)
	// operator_new(0x48) @007da317 → FUN_007c1b38(logger, session, 0)
	SessionLogger *logger = new (std::nothrow) SessionLogger(q);
	if (!logger)
		return;
	// FUN_007c24c8 腿体(5980B):spdlog 建腿 — cited(spdlog 外库边界;
	// 成功返回 1 才走插入腿 @007da3d7,此处按成功腿注册)
	// 成功腿 @007da3d7:spinlock@+0x61(单线程免锁)→ 插入 +0x40
	m_registry[3].insert(id, logger);      // FUN_007e159e(311B)QMap 插入原语
	emit q->loggerCreated(id);             // FUN_00912264(42B,idx5)
}

// FUN_007d9776(1596B,0025.c:7110)转写:Term(+Commander)表插入。
// 语料体:007d6cee 查 Commander 表既有节点 → 命中即复用(不再建);
// 未命中 → option("session.protocol") qstricmp 分派便携 ctor 族
// (Tcp 00876a16/Telnet 0085f520/SSH 008699b0/Serial 0086ff6c/Shell
// 008750e6,对象 ≥0x128B)→ 007cd120 主升面 + connect 同步信号
// (007da178 捕获体)→ spinlock@+0x61 → QMap node(0x30:+0x18 uuid
// +0x20 commander 强ref +0x28 session)→ FUN_00912312(idx3)
// termCreated(uuid,name)。下行 ctor/主升层未开 → 对象 cited 空壳
// (登记于各 ctor 地址),表/信号行为真实现。
void SuperSessionPrivate::insertTermSession(const QUuid &id,
                                            const QString &name)
{
	if (m_registry[0].contains(id))        // 007d6cee 命中 → 复用,不重建
		return;
	void *commander = new (std::nothrow) QObject();  // 便携 ctor 族 cited
	                                       // (00876a16 等,下行层未开)
	if (!commander)
		return;
	m_registry[0].insert(id, commander);   // node 0x30 @007d9b0f(强ref 简化)
	m_registry[1].insert(id, commander);   // session.term 设置 @007d9d46:
	                                       // commander 表 node 同值挂 Term 表
	emit q->termCreated(id, name);         // FUN_00912312(idx3)
}

// FUN_007daedc(1803B,0025.c:8036)转写:Transfer 表插入。
// 语料体:option("session.protocol") qstricmp "Sftp"/"SSH" →
// FUN_008e81b2(obj,0x88B)/否则 FUN_008e3784(obj,0x88B);sftp.*
// 三 option(bool)→ 对象 +0x58 位域 @007db26a;spinlock@+0x61 →
// QMap node(0x28:+0x8 uuid/+0x10 obj)@007db316;FUN_0061b448
// 挂全局线程池;非 Sftp/SSH 协议才发 transferCreated(FUN_009122e8
// idx10,@007db4a3)。下行 ctor 0x88B 未开 → cited 空壳。
void SuperSessionPrivate::insertTransferSession(const QUuid &id,
                                                const QString &name)
{
	const QString proto =
	    q->option("session.protocol").toString();  // @007daf2f-54
	void *transfer = new (std::nothrow) QObject(); // 008e81b2/008e3784 cited
	if (!transfer)
		return;
	m_registry[2].insert(id, transfer);    // node 0x28 @007db316
	// FUN_0061b448(DAT_011c1680, obj)线程池挂载 — cited(线程池层未开)
	if (proto.compare("Sftp", Qt::CaseInsensitive) != 0 &&
	    proto.compare("SSH", Qt::CaseInsensitive) != 0)
		emit q->transferCreated(id);       // @007db4a3 协议卫,idx10
}
