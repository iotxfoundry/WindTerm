#ifndef TRANSFERPANE_H
#define TRANSFERPANE_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// TransferPane: metacall 0x909c8a, 6 slots, small bodies at 0x734.
// All six walk the transfer list container (FUN_00734398) with CoW
// detach (FUN_00525800) and act via the global object 0x11c1680.

#include <QVariant>

class TransferPane
{
public:
	void *transferList();          // FUN_00734398 container accessor

	void actOnSelection()          // FUN_0073452e
	{
		// non-empty selection -> global action; empty -> default branch
	}

	bool anyCheck()                // FUN_007345a4
	{
		// CoW detach then boolean scan of the transfer entries
		return false;
	}

	void actWhenEmpty()            // FUN_00734656
	{
		// empty-list branch of actOnSelection
	}

	void walkOpA() {}              // FUN_007346c4 (shared shape)
	void walkOpB() {}              // FUN_00734764 (isomorphic)
	void walkOpC() {}              // FUN_00734804 (isomorphic)
};

#endif // TRANSFERPANE_H
