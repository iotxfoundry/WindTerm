#ifndef TCPCOMMANDER_H
#define TCPCOMMANDER_H

#pragma once

#include "SuperCommander.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperCommander.
class TcpCommander : public SuperCommander
{
	Q_OBJECT

public:
	TcpCommander(QObject *parent = nullptr);
	virtual ~TcpCommander(void) = default;

private:
	Q_DISABLE_COPY(TcpCommander)
};

#endif // TCPCOMMANDER_H
