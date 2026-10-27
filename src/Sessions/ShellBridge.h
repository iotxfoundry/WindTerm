#ifndef SHELLBRIDGE_H
#define SHELLBRIDGE_H

#pragma once

#include "SuperBridge.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperBridge.
class ShellBridge : public SuperBridge
{
	Q_OBJECT

public:
	ShellBridge(QObject *parent = nullptr);
	virtual ~ShellBridge(void) = default;

private:
	Q_DISABLE_COPY(ShellBridge)
};

#endif // SHELLBRIDGE_H
