#ifndef FILEOPS_H
#define FILEOPS_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// FilerPane's backend: a Qt view-model wrapper (QItemSelectionModel
// based). Holds its own refcounted pair (+0x88 count / +0x90 raw).
// All op methods run the same three-check guard, then either run the
// selection query (FUN_005784ee current index + FUN_005776e2 selection
// list + FUN_0057d555 path resolve) or open a dialog whose completion
// is wired via a shared_ptr callback (_Sp_counted_base<_Lock_policy 2>).

class FileOps
{
public:
	void *m_modelRef;     // +0x88: refcounted model
	void *m_modelRaw;     // +0x90: raw model pointer

	bool hasSelection();                       // FUN_00577396
	void *selectedIndexes();                   // FUN_0057a73a -> open first
	void *currentPath();                       // FUN_00578d88 (0x5784ee/0x5776e2/0x57d555)
	void *currentDir();                        // FUN_00578e18
	void navigateUp();                         // FUN_00578e9c
	void navigateBack();                       // FUN_00578f44
	void setPath(const QString &p, bool flag); // FUN_0057664e
	void refresh();                            // FUN_00576732
	void newFolder();                          // FUN_005785d6 (dialog + callback)
	void remove();                             // FUN_0057870e (same 1323B shape)
	void rename();                             // FUN_0057884e (same 1323B shape)
	void copyPath();                           // FUN_0057a928 (clipboard flow)
};

// 0x8b9 model cluster (ViewBase backend): two-hop id dispatch
//   FUN_008b99f6(args) -> numeric model id
//   FUN_008b9b8e/0x8b9bbc/0x8b9c06/0x8b9c46(view, id, payload)
// 0x8bbe50: 4.2K QMap property walk (model query)
#endif // FILEOPS_H
