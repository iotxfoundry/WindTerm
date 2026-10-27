#ifndef SSHSESSION_H
#define SSHSESSION_H

#pragma once

#include "SuperSession.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperSession.
class SshSession : public SuperSession
{
	Q_OBJECT

public:
	SshSession(QObject *parent = nullptr);
	virtual ~SshSession(void) = default;

private:
	Q_DISABLE_COPY(SshSession)
};

#endif // SSHSESSION_H
