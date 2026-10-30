#ifndef SHELLSESSION_H
#define SHELLSESSION_H

#pragma once

#include "SuperSession.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperSession.
class ShellSession : public SuperSession
{
	Q_OBJECT

public:
	ShellSession(QObject *parent = nullptr);
	virtual ~ShellSession(void) = default;

private:
	Q_DISABLE_COPY(ShellSession)
};

#endif // SHELLSESSION_H
