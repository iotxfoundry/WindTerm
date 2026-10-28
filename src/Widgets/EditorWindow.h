#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// EditorWindow: metacall 0x8fc36e, 8 slots. One signal emitter, one
// Qt QList-copy infra stub (0x533df0, already identified), four real
// bodies at 0x5e9-0x5eb.

#include <QVariant>

class EditorWindow
{
public:
	void openSessionQuery()       // FUN_005eb4fc (1.4K)
	{
		// session query via FUN_008cabee + list handling (cited)
	}

	void tripleOp(const QVariant &a, const QVariant &b, const QVariant &c)
	                              // FUN_005ea368 (1.8K, shared by 3 slots)
	{
		// three-arg list operation (CoW detach + walk) — cited
	}

	void nodeCallbackWalk()       // FUN_005eb64e (4.8K)
	{
		// Node-tree callback iteration (function-pointer table walk)
		// — cited
	}

	void globalRegister()         // FUN_005e97ba
	{
		// one-liner: FUN_005df958(this, DAT_011c12e0)
	}
};

#endif // EDITORWINDOW_H
