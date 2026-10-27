#ifndef TCPSESSION_H
#define TCPSESSION_H

#pragma once

#include "SuperSession.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperSession.
class TcpSession : public SuperSession
{
	Q_OBJECT

public:
	TcpSession(QObject *parent = nullptr);
	virtual ~TcpSession(void) = default;

private:
	Q_DISABLE_COPY(TcpSession)
};

#endif // TCPSESSION_H
