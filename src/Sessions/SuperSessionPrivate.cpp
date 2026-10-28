#include "SuperSessionPrivate.h"
#include "SuperSession.h"

#include <QMap>
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
	// 0=flush 1=pause 2=resume:对象从注册表取;spdlog sink 级操作
	// 需 Phase-4 sink 面(spdlog 静态打包实证,96 处特征串)
	if (m_registry[3].contains(id))
		; // cited — logger 对象面未开
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
