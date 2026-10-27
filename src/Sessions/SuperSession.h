#ifndef SUPERSESSION_H
#define SUPERSESSION_H

#pragma once

#include <QObject>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// Base class of Ssh/Shell/Telnet/Tcp/Serial sessions. Method surface as
// exported by moc; parameter names are approximate (recovered from the
// meta string table, some are neighboring-string artifacts).
class SuperSession : public QObject
{
	Q_OBJECT

public:
	SuperSession(QObject *parent = nullptr);
	virtual ~SuperSession(void) = default;

public slots:
	void open();
	void drop();
	void autoLogin();

	bool isConnected() const;
	bool isUnconnected() const;
	bool isDuplicable() const;
	bool needVerifyServerFingerprint() const;

	QString name() const;
	QString protocolName() const;
	QString hostName() const;
	QString hostAddress() const;
	QString serverBanner() const;
	QString opensshVersion() const;
	QString lastError() const;
	QString lastErrorString() const;

	QString fingerprint(const QString &hash = QString()) const;

	void option(const QString &name);
	void setOption(const QString &name, const QVariant &value);

	void verifyKnownHost();
	void writeKnownHost(const QString &hostsFile);

	void authAgent(const QString &service = QString());
	void authNone(const QString &service = QString());
	void authGssapiWithMic(const QString &service = QString());
	void authPassword(const QString &service, const QString &password);
	void authPublicKey(const QString &identityFilePath, const QString &passphrase = QString());
	void authInteractive(const QString &service = QString());
	void authInteractiveUser(const QString &username);
	void authInteractiveInstruction();
	void authInteractivePrompts();
	void authInteractive(const QString &service, const QString &password);
	void authOneKey(const QUuid &oneKeyUuid);

	QStringList authMethods() const;

	void removeCommander(const QUuid &commanderUuid);
	void removeTerm(const QUuid &commanderUuid);
	void removeTransfer(const QUuid &transferUuid);
	void removeLogger(const QUuid &loggerUuid);
	void flushLogger(const QUuid &loggerUuid);
	void pauseLogger(const QUuid &loggerUuid);
	void resumeLogger(const QUuid &loggerUuid);

signals:
	void stateChanged(int oldState, King::SessionState state);
	void errorOccurred(const QString &context, int code);
	void commanderCreated(const QUuid &commanderUuid);
	void termCreated(const QUuid &commanderUuid);
	void transferCreated(const QUuid &transferUuid);
	void loggerCreated(const QUuid &loggerUuid);
	void loggerRemoved(const QUuid &loggerUuid);
	void commandOutput(const QString &context, const QString &output);
	void autoLoginFailed();
	void syncMessage(int type, int sessionMessage, int wParam, int lParam);
	void asyncMessage(int type, int wParam, int lParam);

private:
	Q_DISABLE_COPY(SuperSession)
};

#endif // SUPERSESSION_H
