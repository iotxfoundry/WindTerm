#ifndef SSHBRIDGE_H
#define SSHBRIDGE_H

#pragma once

#include "SuperBridge.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperBridge.
class SshBridge : public SuperBridge
{
	Q_OBJECT

public:
	SshBridge(QObject *parent = nullptr);
	virtual ~SshBridge(void) = default;
signals:
	void sftpCreated(const QUuid &transferUuid);
	void shellCreated(const QUuid &commanderUuid);

private:
	Q_DISABLE_COPY(SshBridge)
};

#endif // SSHBRIDGE_H
