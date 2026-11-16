#include "SuperSessionPrivate.h"
#include "Sessions/Commanders/SuperCommander.h"
#include "SuperSession.h"

#include <QMap>
#include <QVariantList>
#include <new>
#include "Editor/Config/CTerminalConfig.h"

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
		// FUN_007c1b92(logger,31B,0024.c:30539)转写(批 151):
		// logger+0x38 非空 → vtable+0x20 = spdlog logger::flush
		// (真库委托,LoggerOp::flushSessionLogger;null sink 不打盘)
		LoggerOp::flushSessionLogger(
		    ((SessionLogger *)logger)->m_sink38);
	}
	if (op == 1) {
		if (void *term = m_registry[1].value(id, nullptr))
			*(unsigned char *)((char *)term + 0x1c8) = 1;
	} else if (op == 2) {
		if (void *term = m_registry[1].value(id, nullptr))
			*(unsigned char *)((char *)term + 0x1c8) = 0;
	}
}

// --- 选项:CTerminalConfig 单例为下层(session-config-layer.md ①)---
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
// 外库边界,ext-boundary)→ cited 引地址,不发明(铁律 3)。
// 失败腿 vtable+0x20 拆除 @007da3d7 保留;成功腿 spinlock@+0x61 →
// FUN_007e159e(this+0x40)插入 → FUN_00912264 = loggerCreated
// (idx5;impl-addresses #5,0030.c:1683)。单线程重建免锁,注记
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
	// 参源 @007da2fd-31b:param_2=target = s_session_target_7d5b1a
	// (228B,0025.c:4577:option("session.label") 空 → option("session.target"));
	// param_3=label = FUN_007d4d9c(39B,批 151:virtualLabel() 真身,
	// q+0x10 协议槽非空 → option 近面;空 → shared_null);
	// operator_new(0x48) → FUN_007c1b38(logger, session, 0)。
	// 腿体 FUN_007c24c8 调面真实现 = SessionLogger::buildLeg(启
	// 用卫/+0x28 label/标志尾 + spdlog 委托面);cited ①③(pattern
	// 装配/formatter·state)逐地址登记于其体。失败腿
	// @007da3d7 前卫:vtable+0x20 拆除 → delete。
	QString target = q->option("session.label").toString();   // @007d5b56
	if (target.isEmpty())
		target = q->option("session.target").toString();      // @007d5ba6
	SessionLogger *logger = new (std::nothrow) SessionLogger(q);
	if (!logger)
		return;
	// @007da36a:cVar2 = FUN_007c24c8(logger,target,label,a0,a1,a2,s3,s4)
	if (!logger->buildLeg(target, logger->virtualLabel(), a0 != 0,
	                      (unsigned char)a1, a2, s3, s4)) {
		delete logger;                     // 语料 vtable+0x20 拆除腿
		return;
	}
	// 批 161:'h'(host)/'n'(name)自有 token 腿升真 —— 语料
	// @007c27d5-295c:h ← +0x28 label(virtualLabel 空 → "UnknownIP" 卫),
	// n ← target 名参,对 state 行缓冲字面替换(007c5882 簿记)。
	// (语料此处 state 已 init @007c350a,'h'/'n' 先于 %Y..%v 渲染)
	logger->m_state.applyHost(logger->m_s28);          // @007c2864
	logger->m_state.applyName(target);                 // @007c2931
	// 成功腿 @007da3d7:spinlock@+0x61(单线程免锁)→ 插入 +0x40
	m_registry[3].insert(id, logger);      // FUN_007e159e(311B)QMap 插入原语
	emit q->loggerCreated(id);             // FUN_00912264(42B,idx5)
}

// FUN_007c24c8(5980B,0024.c:31047)腿体调面(批 145)。分面:
// 【真实现】@007c24e0 param_4==0 → return 0(启用卫);@007c2528
// +0x28 = param_3(label);@007c35e2-ee 尾:+0x19 = param_4(启用
// 字节;bit2 = 007db8ee keepFlag 读面)、+0x18 bit0 = param_5>>2&1。
// 【cited ① pattern 装配段 @007c259c-2f9a】%token 替换引擎
// (FUN_007c4440/007c4980/007c5780/007c5970/007c6570/007c5882 族 +
// session_state_init 007c4a30,下行 token 层未开)+ Windows 保留名
// 卫(CON/PRN/COM1-9/LPT1-9 @007c2b36-2e4a)+ 路径归一
// (FUN_008063d6 "/logs/" + cfg_ensureProfileDir 005d7dae
// "%1/profiles/%2/%3" mkpath)+ 保留名前缀插入 → +0x20 完整路径。
// 【cited ② spdlog sink/logger 构造段 @007c3751-3388】批 151 →
// 真库委托面落地(Sessions/Core/SessionLoggerOp.h):param_6<1:基础 file sink
// (operator_new 0x48/0xb0,FUN_005fe1d4,logfile_open)
// ;否则轮转 sink(0x68,maxsize=min(param_6,0x3fffff)<<10,fstat);
// → operator_new(200) spdlog logger(PTR_FUN_011868c8)+ FUN_007c44a4
// sink 绑定 + FUN_007c4cf0 registry + logger_register_unique
// (00612a90)→ +0x38 logger/+0x40 持有块。真盘写截停(null_sink,
// ext-boundary 规则 3):文件/轮转形态实参面登记于 SpdlogLeg,
// sink_it_ 行为面 cited。
// 【cited ③ formatter/state 尾段 @007c3388-3588】"%v"+"\n"
// pattern_formatter(operator_new 0xb0,FUN_005fd340)+ set_formatter
// (FUN_005f5bc0);m_sink38 非 0 时:行 pattern(param_8,空 →
// "[%Y-%m-%d %H:%M:%S] %v")→ session_state_init(0x48B)→ +0x30,
// FUN_007c6570(state,label)/FUN_007c5882(state,'n',…) token 引擎
// 同族 cited。param_5 bit0 = append(local_2d8 @007c2500 → logfile_open)。
// 批 155:q+0x10 协议槽测试门(体置 cpp:moc/前置声明卫)
void *SuperSessionPrivate::protocolSlot() const { return q->m_protocol; }
void SuperSessionPrivate::setProtocolSlot(void *p) { q->m_protocol = p; }

bool SessionLogger::buildLeg(const QString &target, const QString &label,
                             bool enable, unsigned char flags, int rotateBytes,
                             const QString &fileNamePattern,
                             const QString &linePattern)
{
	(void)target;            // cited ①(%h/UnknownIP 装配腿)
	(void)fileNamePattern;   // cited ①(+0x20 装配路径;现保原样不装配)
	if (!enable)             // @007c24e0
		return false;
	m_s28 = label;           // @007c2528 QString::operator=(+0x28, param_3)
	// 批 151:cited ② spdlog sink/logger 构造段 @007c3751-3388 →
	// 真库委托面(EXT/SpdlogFace.h;null sink 截停真盘写,实参登记)
	LoggerOp::SpdlogLeg leg = LoggerOp::buildSessionLogger(rotateBytes >= 1, m_s28,
	                                             rotateBytes);
	m_sink38 = leg.loggerRaw;      // @007c39ac *(param_1+0x38) = p_Var18+0x10
	m_sink40 = leg.loggerOwn.get(); // @007c39b7 *(param_1+0x40) = p_Var18
	if (m_sink38) {  // cited ③ 行 pattern 腿(@007c34c8:m_sink38 非 0)
		LoggerOp::applyLinePattern(m_sink38, linePattern);
		// 批 161:session_state 0x48B 下行窄面真身(@007c350a
		// operator_new(0x48) → 007c4a30 init):行 pattern(空 →
		// "[%Y-%m-%d %H:%M:%S] %v" @007c3500)→ state.init;+0x30
		// 指针面对位(语料 operator_new 块 ↔ m_state 值成员)。
		m_state.init(linePattern.isEmpty()
		                 ? QByteArrayLiteral("[%Y-%m-%d %H:%M:%S] %v")
		                 : linePattern.toUtf8());   // @007c4a30 体
		m_state30 = &m_state;          // @007c3518 *(param_1+0x30) = 新块
	}
	// (m_state30 旧指针语义:语料换新时旧块 QDateTime/QString 析构 +
	// operator_delete @007c3524 —— 值成员析构自动对称,无泄漏面)
	m_flags19 = enable ? 1 : 0;                   // @007c35e8
	m_flags18 = (unsigned char)((flags >> 2) & 1); // @007c35ee &1
	return true;             // 语料成功尾 return 1 @007c3600
}

// FUN_007d4d9c(39B,0025.c:4080)转写(批 151;批 155 升真):param_2
// +0x10 非空 → 虚表 +0x68 label 调面(真虚调);空 → shared_null。
// 本树 q+0x10 = m_protocol(SuperSession.h 注:moc getter 全从此转发)
// → 非 0 卫 + SessionProtocolFace::label() 真虚调。
QString SessionLogger::virtualLabel() const
{
	if (m_session && m_session->m_protocol != nullptr)
		return static_cast<const SessionProtocolFace *>(
		           m_session->m_protocol)->label(); // @007d4da2 +0x68 虚调
	return QString();        // shared_null 臂(全同 @007d4da7)
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
// FUN_008e81b2(obj,0x88B)/否则 FUN_008e3784(obj,0x88B)。
// 批 145:对象 ctor 真身化 —— SessionTransfer(008ec79a 基体字段面,
// 见头文件);下行依赖(Sftp 008e8150/008e8add6 connect 族/Local
// 008e533d QTimer lambda)网络/fsModel 面 → cited 逐地址登记于头。
// sftp.* option 读 @007db0dc-232(fileCreationPermissions/
// folderCreationPermissions toUInt + fixInvalidPathCharacters/
// preserveOriginalFileModifyTime/preserveOriginalFolderModifyTime
// toBool)→ +0x58 位写 + FUN_008eb532/540 权限写(真实现)。
// spinlock@+0x61 → QMap node(0x28:+0x8 uuid/+0x10 obj)@007db316;
// FUN_0061b448 挂全局线程池(DAT_011c1680)→ cited(线程池层未开);
// 非 Sftp/SSH 协议才发 transferCreated(FUN_009122e8 idx10,@007db4a3)。
void SuperSessionPrivate::insertTransferSession(const QUuid &id,
                                                const QString &name)
{
	(void)name;                            // 语料参数仅透传 signal 面
	const QString proto =
	    q->option("session.protocol").toString();  // @007daf2f-54
	const bool sftp = proto.compare("Sftp", Qt::CaseInsensitive) == 0 ||
	                  proto.compare("SSH", Qt::CaseInsensitive) == 0;
	// @007dafa9/007db3d6:operator_new(0x88) → FUN_008e81b2/008e3784
	// 批 151:Local 腿 param_3=1(007daedc 实读)→ m_localLambda 置位
	SessionTransfer *transfer = new (std::nothrow) SessionTransfer(sftp, q, !sftp);
	if (!transfer)
		return;
	// sftp.* options(007daedc 下行;default 对 0x1a4/0x1ed = @8ec9*)
	transfer->setFilePerm(q->option("sftp.fileCreationPermissions")
	                          .toByteArray().toUInt(nullptr));        // @007db0dc
	transfer->setFolderPerm(q->option("sftp.folderCreationPermissions")
	                            .toByteArray().toUInt(nullptr));      // @007db138
	transfer->applySftpOptions(
	    q->option("sftp.fixInvalidPathCharacters").toBool() ? 1u : 0u,   // @007db19a
	    q->option("sftp.preserveOriginalFileModifyTime").toBool() ? 1u : 0u, // @007db1db
	    q->option("sftp.preserveOriginalFolderModifyTime").toBool() ? 1u : 0u); // @007db21c
	m_registry[2].insert(id, transfer);    // node 0x28 @007db316
	// FUN_0061b448(DAT_011c1680, obj)线程池挂载 — cited(线程池层未开)
	if (!sftp)
		emit q->transferCreated(id);       // @007db4a3 卫,idx10
}
