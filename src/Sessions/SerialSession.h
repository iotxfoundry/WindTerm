#ifndef SERIALSESSION_H
#define SERIALSESSION_H

#pragma once

#include "SuperSession.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperSession.
class SerialSession : public SuperSession
{
	Q_OBJECT

public:
	SerialSession(QObject *parent = nullptr);
	virtual ~SerialSession(void) = default;

private:
	Q_DISABLE_COPY(SerialSession)
};

#endif // SERIALSESSION_H
