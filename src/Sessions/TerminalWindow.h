#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// TerminalWindow: metacall 0x911868, 18 slots at 0x858b-0x859a.
// Shapes: tab/container ops via dynamic_cast(0x11a8310), dialogs,
// global-manager calls (0x11c2200/0x11c1a60/0x11c1b00).

#include <QVariant>

class TerminalWindow
{
public:
	// --- slot bodies (from the case table, classes_sweep.json) ---------
	// FUN_00858b18/0x858be8 (twin pair, shared by cases 3-4/5-6):
	//   resolve the container (FUN_008a0ac6) -> dynamic_cast class
	//   0x11a8310 -> set a bool QVariant(false/true) — split/merge pair
	void setSplit(bool on)
	{
		void *c = container();         // FUN_008a0ac6 + cast 0x11a8310
		if (c)
			applyFlag(c, on);          // cited tail
	}

	// FUN_00858cbc (cases 7-8): builds a 0x38-byte options object
	// (FUN_00aee620) + global config (FUN_00807194, 0x11c2200) + a
	// Connection (QDialog wiring) — settings dialog flow
	void openSettingsFlow();

	// FUN_00859a42 (cases 9-10, 2.6K): multi-object int-pair walk
	// (window tile/arrange logic) — cited
	void arrangeWindows();

	// FUN_00858e86 (cases 11-13, shared): global (FUN_008cbc36) +
	// QString("t") passed to FUN_00768dfa — theme toggle
	void toggleTheme();

	// FUN_00858efa: 0x70-byte dialog (FUN_0072abce ctor) + QDialog::open
	void openDialog();

	// FUN_00858f32: global 0x11c1a60 query with a string out-param
	void queryGlobal();

	// FUN_00858f9e: global 0x11c1b00 call
	void notifyGlobal2();

	// FUN_00858fb0: global-manager op (0x11c2200) via FUN_008086d0
	void globalOp();

	// FUN_00533df0 (case 1): Qt QList copy infra (identified)
	// signals (cases 0/2, 0x9117c8/0x911802): moc emit stubs

	void *container();              // FUN_008a0ac6
	void applyFlag(void *c, bool on);
};

#endif // TERMINALWINDOW_H
