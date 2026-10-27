#ifndef SERIALCOMMANDER_H
#define SERIALCOMMANDER_H

#pragma once

#include "SuperCommander.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperCommander.
class SerialCommander : public SuperCommander
{
	Q_OBJECT

public:
	SerialCommander(QObject *parent = nullptr);
	virtual ~SerialCommander(void) = default;

private:
	Q_DISABLE_COPY(SerialCommander)
};

#endif // SERIALCOMMANDER_H
