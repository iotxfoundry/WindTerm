#ifndef TELNETSESSION_H
#define TELNETSESSION_H

#pragma once

#include "SuperSession.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperSession.
class TelnetSession : public SuperSession
{
	Q_OBJECT

public:
	TelnetSession(QObject *parent = nullptr);
	virtual ~TelnetSession(void) = default;

private:
	Q_DISABLE_COPY(TelnetSession)
};

#endif // TELNETSESSION_H
