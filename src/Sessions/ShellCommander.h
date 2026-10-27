#ifndef SHELLCOMMANDER_H
#define SHELLCOMMANDER_H

#pragma once

#include "SuperCommander.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperCommander.
class ShellCommander : public SuperCommander
{
	Q_OBJECT

public:
	ShellCommander(QObject *parent = nullptr);
	virtual ~ShellCommander(void) = default;

private:
	Q_DISABLE_COPY(ShellCommander)
};

#endif // SHELLCOMMANDER_H
