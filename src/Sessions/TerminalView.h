#ifndef TERMINALVIEW_H
#define TERMINALVIEW_H

#pragma once

#include <QString>
#include <QVariant>
#include <QByteArray>
#include <QUuid>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// TerminalView's own slots (beyond the shared ViewBase methods):
// session-identity resolution via the UUID property at +0x218, the
// A/B/C/D session-slot letter mapping, and cross-widget SessionPane
// focus operations. Shares the 0x8c5 cluster with EditorView/GrepView.

class TerminalView
{
public:
	QString m_sessionUuid;   // +0x218 property (0x8c5578 reads "Url"-style props)

	QString resolveSessionUuid()
	{
		// FUN_00833ee0: reads the +0x218 property as a QUuid; on a valid
		// UUID registers with the global manager via FUN_0083c330
		// (the same registration TerminalWidget::FUN_0083c330 uses)
		QString uuid = property(m_sessionUuid);
		if (QUuid::fromString(uuid).isNull())
			return uuid;
		registerWithManager();       // FUN_0083c330 — cited
		return uuid;
	}

	bool hasValidSession()
	{
		// FUN_00833f84: !QUuid::isNull() over the +0x218 property
		return !QUuid::fromString(property(m_sessionUuid)).isNull();
	}

	int sessionSlotType(const QString &letter)
	{
		// FUN_008341c8: maps the slot letter to its id — "A"->1, "B"->2,
		// "C"->3, "D"->4 (the four anonymous session slots); anything
		// else is ignored
		static const char *letters[] = { "A", "B", "C", "D" };
		for (int i = 0; i < 4; i++)
			if (letter == letters[i])
				return i + 1;
		return 0;
	}

	void notifyGlobal()
	{
		// FUN_008342ae: global-manager call with singleton 0x11c1a00
	}

	void focusSessionPane()
	{
		// FUN_00834920 / FUN_00834a2e: with a valid session, walks up to
		// the "SessionPane" ancestor (hash lookup 0x89eed8 +
		// dynamic_cast typeinfo 0x11ab690/0x11a56f0), resolves the
		// +0x218 property and focuses it. FUN_00834a2e passes a
		// QMetaObject::tr-translated context string first.
	}

private:
	QString property(const QString &key);   // FUN_008c5578 (ViewBase)
	void registerWithManager();             // FUN_0083c330
};

#endif // TERMINALVIEW_H
