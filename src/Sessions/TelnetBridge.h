#ifndef TELNETBRIDGE_H
#define TELNETBRIDGE_H

#pragma once

#include "SuperBridge.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperBridge.
class TelnetBridge : public SuperBridge
{
	Q_OBJECT

public:
	TelnetBridge(QObject *parent = nullptr);
	virtual ~TelnetBridge(void) = default;

private:
	Q_DISABLE_COPY(TelnetBridge)
};

#endif // TELNETBRIDGE_H
