#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// TerminalWidget: the Qt widget hosting a terminal session. Holds the
// session (+0x118), the screen smart-pointer pair (+0x1f0/+0x1f8, the
// raw pointer feeds the 0x7e33xx Screen cluster), a modem object
// (+0x120), the log-file path (+0x148) and the editor backend (via the
// TextView-style sendEditor command space, WT ids >= 30173).
// metacall: 0x910a98; 18 signals (0x9107-0x910a emit stubs) + 58 slots
// (0x83c-0x849 real bodies). Case table:
// tools/re/data/terminalwidget_cases.json

#include <QFileInfo>

class TerminalWidget
{
public:
	// --- object layout (offsets proven in the 0x83c cluster) -----------
	void *m_session;        // +0x118 (session API: 0x7d36a0/0x7d5d2a/0x7d6722/0x7d6736)
	void *m_modem;          // +0x120 (0x38-byte object, released on cancel)
	QString m_logFilePath;  // +0x148 (QFileInfo::exists -> isLogFileExists)
	int m_state;            // +0x150 (session state)
	unsigned char m_flags;  // +0x160 (protocol mode flag byte)
	void *m_timer;          // +0x1a8 (QTimer, reconnect/auto flow)
	QString m_widgetId;     // +0x1b0 (registered with the global manager)
	void *m_ptr1b8;         // +0x1b8 (smart pair with +0x1c0)
	void *m_ptr1c0;         // +0x1c0
	void *m_sessionRef;     // +0x1e0 (refcounted session ptr)
	void *m_sessionRaw;     // +0x1e8 (raw session, 0x7cabf8 protocol query)
	void *m_screenRef;      // +0x1f0 (refcounted screen ptr)
	Screen *m_screen;       // +0x1f8 -> 0x7e33xx Screen cluster calls

	// --- screen cluster forwards (guards: +0x1f0 valid && +0x1f8) -------
	// The clear family routes: slot -> Screen::sendScreenCommand(n)
	// -> Screen signal 2 (commandRequested) -> connected slot executes.
	// FUN_0083cbc8 clearScreen          -> command 6 (FUN_007e3326)
	// FUN_0083cc00 clearScrollback      -> FUN_007e3388(screen)
	// FUN_0083c6a8 clearScreenAndScrollback -> FUN_007e31ec(screen)
	// FUN_0083cf68 resetHard -> FUN_0083cee2(this, 0)
	// FUN_0083c4c8 isAltScreen -> FUN_007e4028(screen) (screenback mode query)
	// FUN_0083c696 isMainScreen = !isAltScreen

	// --- WT command getters (sendEditor space, TerminalWidget ids) ------
	// FUN_0083c9e2 promptPosition  CMD 0x75dd (int)
	// FUN_0083ca74 promptLine      CMD 0x75de (int)
	// FUN_0083c710 scrollbackLines CMD 0x75df (int)
	// FUN_0083c538 isUnconnected   CMD 0x75e2 (bool)
	// FUN_0083c822 caretVirtualSpace CMD 0x75f9

	bool isConnected() const
	{
		// FUN_0083c5e6: session stack (+0x1e0/+0x1e8) valid then +0x150
		return m_sessionRef && m_state != 0 && m_sessionRaw != nullptr;
	}

	bool isLogFileExists() const
	{
		// FUN_0083c5c8: refcount guard then QFileInfo::exists(+0x148)
		return QFileInfo::exists(m_logFilePath);
	}

	void openLogFolder()
	{
		// FUN_0083c8b4: no log -> open the default (global 0x11c2200);
		// else open QFileInfo(+0x148).absolutePath()
	}

	QString protocolName() const
	{
		// FUN_0083cb0c: +0x118 guard then session protocol query 0x7d5d2a
		return QString();
	}

	bool isModemSupported(int direction, int type)
	{
		// FUN_0083cb36: without the +0x160 flag only "Telnet" supports it
		// (QString::compare against "Telnet"); with the flag the type
		// range decides
		return true;
	}

	bool isModemTransmitting()
	{
		// FUN_0083c6a8: modem object at +0x120 non-null -> true, else
		// query the screen cluster (FUN_007e31ec)
		return m_modem != nullptr;
	}

	void cancelModemTransmitting()
	{
		// FUN_00842172: screen stack guard, screen call FUN_007e318a,
		// then delete the 0x38-byte modem object at +0x120
	}

	void openSessionTriggersDialog()   // FUN_0083c970: isModemTransmitting
	{                                  // guard -> FUN_0083c616 -> dialog
	}                                  // via global 0x11c1680 (+0x148 args)

	void executeCommand(const QString &text);  // FUN_00843050: full
	                                           // editor-text command path
	void showError(const char *category);      // FUN_0083d97a:
	                                           // "SessionErrorMessage" scheme
};

#endif // TERMINALWIDGET_H
