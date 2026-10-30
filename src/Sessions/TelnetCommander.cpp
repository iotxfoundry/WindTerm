#include "TelnetCommander.h"

TelnetCommander::TelnetCommander(QObject *parent)
	: SuperCommander(parent)
{
}

void TelnetCommander::negotiateOption(const QString &command)
{
	// cited — wave-2(moc 槽,QMetaObject 权威;槽体未转写)
	Q_UNUSED(command);
}

void TelnetCommander::negotiateSubOption(const QString &option)
{
	// cited — wave-2(moc 槽,QMetaObject 权威;槽体未转写)
	Q_UNUSED(option);
}
