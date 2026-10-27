#ifndef TCPBRIDGE_H
#define TCPBRIDGE_H

#pragma once

#include "SuperBridge.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperBridge.
class TcpBridge : public SuperBridge
{
	Q_OBJECT

public:
	TcpBridge(QObject *parent = nullptr);
	virtual ~TcpBridge(void) = default;

private:
	Q_DISABLE_COPY(TcpBridge)
};

#endif // TCPBRIDGE_H
