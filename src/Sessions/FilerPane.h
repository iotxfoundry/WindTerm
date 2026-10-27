#ifndef FILERPANE_H
#define FILERPANE_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// FilerPane: a guard-forward shell over the file-manager backend held
// at +0x68 (the 0x576-0x57a operation cluster). Every moc slot checks
// the backend pointer then delegates; a few build CoW shared buffers
// (FUN_00731634/0x731550) or open dialogs (QDialog::finished wiring).
// metacall: 0x90aba2 (property shim) -> dispatcher 0x90a86a;
// 35 cases -> 0x730-0x732 cluster (see classes_sweep.json).

class FilerPane
{
public:
	void *m_fileView;   // +0x68: file-manager backend (0x576-0x57a cluster)

	// --- guard-forward slots (all: if (m_fileView) backend->op()) ------
	void *currentPath() const;        // FUN_00730cfc -> FUN_00578d88
	void *currentDir() const;         // FUN_00730d0e -> FUN_00578e18
	void setPath(const QString &p, bool flag);  // FUN_00730d20 -> FUN_0057664e
	void refresh();                   // FUN_00730d32 -> FUN_00576732
	void *selection() const;          // FUN_00731da6 -> 0x5787aa + FUN_00730d42
	void navUp();                     // FUN_00731186 -> FUN_00578e9c
	void navBack();                   // FUN_00731196 -> FUN_00578f44
	void focusView();                 // FUN_007311a6 -> QWidget::setFocus(3)
	                                   //   (view via FUN_008c3968)
	void *bookmarkDir() const;        // FUN_007311ca -> FUN_00577396
	void opNewFolder();               // FUN_00731442 -> FUN_005785d6
	void opDelete();                  // FUN_00731452 -> FUN_0057870e
	void opRename();                  // FUN_00731462 -> FUN_0057884e
	void opCopyPath();                // FUN_00731472 -> FUN_0057a928
	void opOpenTerminal();            // FUN_00731482 -> FUN_0057a73a

	// --- CoW shared-buffer slots ---------------------------------------
	// FUN_007324ca/0x7325c4: scheme/list getters building atomically
	//   refcounted shared buffers via FUN_00731634/0x731550
	// FUN_00732d0e/0x732dfa: matching setters (copy + write)
	// FUN_007326be/0x732b4a: uint-list walks (selection ids, CoW detach
	//   via FUN_00525800/0x5e9480)

	// --- dialog ---------------------------------------------------------
	void openTransferDialog();        // FUN_0073138e: FUN_007311ee(this,1)
	                                   //  + QDialog::finished -> FUN_00730...cb
};

#endif // FILERPANE_H
