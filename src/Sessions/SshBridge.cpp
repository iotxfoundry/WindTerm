#include "SshBridge.h"

#include <QList>
#include <QString>

#include <functional>

// Implementation notes reconstructed from the signal-routing hub
// FUN_007bc21e (see SSH-INTERNALS.md "signal routing"):
//
// commandOutput is distributed to subscribers after stripping a trailing
// "###" prompt marker (FUN_007bebdc: QString::endsWith("###") -> chop),
// which is how the commander detects command completion.

SshBridge::SshBridge(QObject *parent)
	: SuperBridge(parent)
{
}

void SshBridge::distributeCommandOutput(const QString &output)
{
	// FUN_007bebdc transcribed
	QString text = output;
	if (text.endsWith(QLatin1String("###")))
		text.chop(3);

	// FUN_007baf70: fan out to every subscribed term/commander
	for (const auto &subscriber : m_subscribers)
		subscriber(text);

	emit commandOutput(QString(), QString(), text);
}
