#ifndef OUTPUTPANE_H
#define OUTPUTPANE_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// OutputPane: metacall 0x909e08, 9 slots, real bodies at 0x749-0x74a.

#include <QVariant>

class OutputPane
{
public:
	void dispatch(int type)          // FUN_00749422 (2.0K)
	{
		// type dispatch over the output channels (cited branches)
	}

	void writeMark(void *pos)        // FUN_00749878
	{
		// *(param+0x40) -> FUN_005ab5ca classify -> FUN_005ab180 mark
	}

	void appendPipeline(int kind)    // FUN_0074a1ea (4.7K)
	{
		// the output append pipeline: channel setup + text append
		// (bulk: string/attr handling) — cited
	}

	int resolvePath(const QString &p)  // FUN_0074a728 (2.0K)
	{
		// reuses the Filer path normalization FUN_0057d555
		return 0;
	}

	void openResolved(const QVariant &target)  // FUN_0074a8f6
	{
		// collect list (FUN_00749b3e) -> normalize (0x57d555) -> open
	}

	QVariant property(const QVariant &key)     // FUN_0074a946 (1.8K)
	{
		// QVariant attribute lookup (cited map walk)
		return QVariant();
	}

	// helper: list collector FUN_00749b3e (shared-null QList walk)
};

#endif // OUTPUTPANE_H
