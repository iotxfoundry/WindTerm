#ifndef SSHCOMMANDER_H
#define SSHCOMMANDER_H

#pragma once

#include "SuperCommander.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperCommander.
class SshCommander : public SuperCommander
{
	Q_OBJECT

public:
	SshCommander(QObject *parent = nullptr);
	virtual ~SshCommander(void) = default;

private:
	Q_DISABLE_COPY(SshCommander)
};

#endif // SSHCOMMANDER_H
