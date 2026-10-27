#ifndef SERIALBRIDGE_H
#define SERIALBRIDGE_H

#pragma once

#include "SuperBridge.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperBridge.
class SerialBridge : public SuperBridge
{
	Q_OBJECT

public:
	SerialBridge(QObject *parent = nullptr);
	virtual ~SerialBridge(void) = default;

private:
	Q_DISABLE_COPY(SerialBridge)
};

#endif // SERIALBRIDGE_H
