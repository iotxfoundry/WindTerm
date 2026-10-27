#ifndef TELNETCOMMANDER_H
#define TELNETCOMMANDER_H

#pragma once

#include "SuperCommander.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperCommander.
class TelnetCommander : public SuperCommander
{
	Q_OBJECT

public:
	TelnetCommander(QObject *parent = nullptr);
	virtual ~TelnetCommander(void) = default;
public slots:
	void negotiateOption(const QString &command);
	void negotiateSubOption(const QString &option);

private:
	Q_DISABLE_COPY(TelnetCommander)
};

#endif // TELNETCOMMANDER_H
