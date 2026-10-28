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
