#include <QVariant>
#include "SuperSession.h"
#include "SuperSessionPrivate.h"

// SuperSession 的公共方法实现:转发到 SuperSessionPrivate
// (混合架构:认证/校验→真 libssh;管家/选项→最小可用)

SuperSession::SuperSession(QObject *parent)
	: QObject(parent), m_d(nullptr)
{
}

SuperSession::~SuperSession()
{
	delete m_d;
}

void SuperSession::removeCommander(const QUuid &id) { if (m_d) m_d->removeRegistry(0, id); }
void SuperSession::removeTerm(const QUuid &id)       { if (m_d) m_d->removeRegistry(1, id); }
void SuperSession::removeTransfer(const QUuid &id)   { if (m_d) m_d->removeRegistry(2, id); }
void SuperSession::removeLogger(const QUuid &id)     { if (m_d) m_d->removeRegistry(3, id); }
void SuperSession::flushLogger(const QUuid &id)  { if (m_d) m_d->loggerOp(id, 0); }
void SuperSession::pauseLogger(const QUuid &id)  { if (m_d) m_d->loggerOp(id, 1); }
void SuperSession::resumeLogger(const QUuid &id) { if (m_d) m_d->loggerOp(id, 2); }
QVariant SuperSession::option(const QString &name) const
{
	return m_d ? m_d->option(name, QVariant()) : QVariant();
}
QVariant SuperSession::option(const QString &name, const QVariant &defaultValue) const
{
	return m_d ? m_d->option(name, defaultValue) : defaultValue;
}
void SuperSession::setOption(const QString &name, const QVariant &value)
{
	if (m_d) m_d->setOption(name, value);
}

void SuperSession::authAgent(const QString &service)        { if (m_d) m_d->authAgent(service); }
void SuperSession::authNone(const QString &service)         { if (m_d) m_d->authNone(service); }
void SuperSession::authGssapiWithMic(const QString &service){ if (m_d) m_d->authGssapiWithMic(service); }
void SuperSession::authPassword(const QString &service, const QString &password)
                                                             { if (m_d) m_d->authPassword(service, password); }
void SuperSession::authPublicKey(const QString &identity, const QString &passphrase)
                                                             { if (m_d) m_d->authPublicKey(identity, passphrase); }
void SuperSession::authInteractive(const QString &service)  { if (m_d) m_d->authInteractive(service); }
void SuperSession::authInteractive(const QString &service, const QString &password)
                                                             { if (m_d) m_d->authKeyboardInteractive(service, password); }
void SuperSession::verifyKnownHost()                        { if (m_d) m_d->verifyKnownHost(); }
void SuperSession::writeKnownHost(King::ServerKnownState s) { if (m_d) m_d->writeKnownHost(s); }
void SuperSession::authOneKey(const QUuid &id)              { (void)id; }
void SuperSession::authInteractiveUser(const QString &user) { (void)user; }
void SuperSession::authInteractiveInstruction()            {}
void SuperSession::authInteractivePrompts()                {}
QStringList SuperSession::authMethods() const               { return m_d ? m_d->authMethods() : QStringList(); }
void SuperSession::autoLogin()                             {}

// ---------------------------------------------------------------------------
// 协议对象转发族(moc 名权威:supersession_moc_methods.json)
// 共同模式(FUN_007d4d9c/7d6736/7d5da2/7d6722/7d4dc4/7d4dda/7d5422/
// 7d5e68/7d583a/7d5b1a/7d5d2a/7d5cb8):无协议对象(+0x10)→ 空值;
// 有则 dynamic_cast 校验后调协议虚查询(各槽 vtable 偏移 0x68/0x78/
// 0x80 等)。协议对象模型 Phase-4 落地后补虚调用;现按语料空分支。
// ---------------------------------------------------------------------------

bool SuperSession::isConnected() const        // case 36 → FUN_007d6736
{
	return m_protocol != nullptr && false;   // 虚查询 cited(Phase-4)
}

bool SuperSession::isUnconnected() const      // case 38 → FUN_007d6722
{
	return m_protocol == nullptr;
}

bool SuperSession::isDuplicable() const       // case 37 → FUN_007d5da2
{
	return false;   // 虚查询 cited(Phase-4)
}

bool SuperSession::needVerifyServerFingerprint() const  // case 42 → 7d5cb8
{
	return false;   // s_ssh_verifyServerFingerprint — cited(Phase-4)
}

QString SuperSession::name() const            // case 41 → s_session_target_7d5b1a
{
	return QString();
}

QString SuperSession::hostName() const        // case 35 → s_session_target_7d583a
{
	return QString();
}

QString SuperSession::hostAddress() const     // case 34 → FUN_007d4d9c(vtable+0x68)
{
	return QString();
}

QString SuperSession::protocolName() const    // case 47 → s_session_protocol_7d5d2a
{
	return QString();
}

QString SuperSession::serverBanner() const    // case 53 → FUN_007d5e68
{
	return QString();
}

QString SuperSession::opensshVersion() const  // case 44 → FUN_007d5422
{
	return QString();
}

QString SuperSession::lastError() const       // case 39 → FUN_007d4dc4(vtable+0x78)
{
	return QString();
}

QString SuperSession::lastErrorString() const // case 40 → FUN_007d4dda(vtable+0x80)
{
	return QString();
}

QString SuperSession::fingerprint(King::FingerprintType type) const  // case 31/32 → 7d4c60
{
	(void)type;
	return QString();
}

void SuperSession::open()                     // case 43:metacall 直调 vtable+0x60
{
	// (**(code **)(*this + 0x60))() —— 会话派生类(SshSession 等)
	// 实现连接;基类无默认体。Phase-4 协议类层级落地后接。
}

void SuperSession::drop()                     // case 30 → FUN_007d48cc
{
	// FUN_007d48cc:注册表 +0x28 面拆除 — cited(Phase-4)
	if (m_d)
		m_d->closeSession();
}
