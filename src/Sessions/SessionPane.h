#ifndef SESSIONPANE_H
#define SESSIONPANE_H

#pragma once

#include <QString>
#include <QVariant>
#include <QByteArray>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// SessionPane: Qt model-view session-tree pane. metacall 0x90a0aa.
// The five slot monoliths share one framework: resolve the custom tree
// model (dynamic_cast typeinfo 0x119fa70), snapshot the selected rows
// (QItemSelectionModel::selectedRows with CoW detach), then either run
// a std::function-style closure over the rows or walk the Node tree.

#include <QVariant>

struct Node;   // tree node: +0x08 children, +0x14 child count, +0x20 flag

// The 0x18-byte closure built on the stack by the ops:
//   { model*, closure-self*, node-tree* } with two free-function
//   pointers: visitor FUN_00742de0 and finisher FUN_007424ef
struct TreeClosure {
	void *model;
	TreeClosure *self;
	Node *root;
	void (*visitor)(TreeClosure *, const void *row);  // FUN_00742de0
	void (*finisher)(TreeClosure *, TreeClosure *, int);  // FUN_007424ef
};

class SessionPane
{
public:
	void *m_view;          // QAbstractItemView side

	// --- the framework every op runs ------------------------------------
	void *treeModel();     // model() -> dynamic_cast(0x119fa70)
	void forEachSelectedRow(TreeClosure &ctx);   // selectedRows + CoW
	                                                    // detach + visitor
	                                                    // loop + finisher
	// --- slot bodies ------------------------------------------------------
	void operateOnSelection()   // FUN_0073e756 (canonical form, 5.0K)
	{
		// closure{model, self, shared-null tree} + visitor/finisher,
		// selectedRows detach (FUN_00535620), per-row visitor call,
		// finisher(ctx, ctx, 3), then the collected tree feeds the op
		TreeClosure ctx = { treeModel(), nullptr, nullptr,
		                    treeVisitor, treeFinisher };
		forEachSelectedRow(ctx);
	}

	void walkTreeWithRows()    // FUN_007415fc (8.1K, same canonical form)
	{
		operateOnSelection();   // identical closure machinery
	}

	void rebuildTree()          // FUN_00740472 (12.9K)
	{
		// selectedRows snapshot; per row the internal model index
		// pointer (row[2]) drives a QHash/QString gather pass over the
		// Node tree (bulk of the 12.9K body: tree/label collection)
		TreeClosure ctx = { treeModel(), nullptr, nullptr,
		                    treeVisitor, treeFinisher };
		forEachSelectedRow(ctx);
		collectTreeLabels();   // per-row tree gather — cited
	}

	void mutateTree()           // FUN_0073eb92 (12.6K)
	{
		// selectedRows loop with a -1 sentinel fallback when row[2] is
		// null (no internal pointer), then the Node-tree mutation pass
		TreeClosure ctx = { treeModel(), nullptr, nullptr,
		                    treeVisitor, treeFinisher };
		forEachSelectedRow(ctx);
		mutateNodes();         // cited
	}

	void moveBetweenModels(const QString &name, const QVariant &extra)
	                            // FUN_0073d836 (14.3K)
	{
		// guard FUN_008c379e; dual dynamic_cast: source model
		// (typeinfo 0x118dac8) + tree model (0x119fa70); empty name ->
		// selectedRows path calling the target model vtable slot 0x178;
		// non-empty -> the named-row move variant
		if (!moveGuard())
			return;
		void *src = sourceModel();     // dynamic_cast 0x118dac8
		void *dst = treeModel();
		if (!src || !dst)
			return;
		if (name.isEmpty()) {
			forEachSelectedRow(*makeMoveClosure(dst));
			moveRows(dst, nullptr);    // model vtable +0x178 — cited
		} else {
			moveRows(dst, &extra);     // cited
		}
	}

	void openCreateDialog()     // FUN_0073cdc4 (7.1K)
	{
		// QMetaObject::tr context + a 0x110-byte dialog object
		// (FUN_0072223c ctor with the translated title), wired
		// QDialog::finished -> FUN_00740325 callback, then exec
		void *dialog = createDialog(0x110);   // FUN_0072223c
		connectFinished(dialog, dialogFinished);  // FUN_00740325
		execDialog(dialog);
	}

	void buildPathHash(class QHash<QString, Node *> &out, bool openDialog);
	void deferNodeProcessing();
	void moveToWindow(const QString &name);

	// --- cited helpers ------------------------------------------------------
	static void treeVisitor(TreeClosure *, const void *row);   // FUN_00742de0
	static void treeFinisher(TreeClosure *, TreeClosure *, int); // FUN_007424ef
	void collectTreeLabels();      // FUN_00740472 gather pass
	void mutateNodes();            // FUN_0073eb92 mutation pass
	bool moveGuard();              // FUN_008c379e
	void *sourceModel();           // dynamic_cast(0x118dac8)
	TreeClosure *makeMoveClosure(void *model);
	void moveRows(void *model, const QVariant *extra);  // vtable +0x178
	void *createDialog(int size);  // FUN_0072223c
	void connectFinished(void *dialog, void (*cb)());    // FUN_00740325 cb
	void execDialog(void *dialog);
	static void dialogFinished();  // FUN_00740325
};

#endif // SESSIONPANE_H
#ifndef SESSIONPANE_H
#define SESSIONPANE_H

#pragma once

#include <QString>
#include <QVariant>
#include <QByteArray>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// SessionPane: Qt model-view session-tree pane. metacall 0x90a0aa.
// The five slot monoliths share one framework: resolve the custom tree
// model (dynamic_cast typeinfo 0x119fa70), snapshot the selected rows
// (QItemSelectionModel::selectedRows with CoW detach), then either run
// a std::function-style closure over the rows or walk the Node tree.

#include <QVariant>

struct Node;   // tree node: +0x08 children, +0x14 child count, +0x20 flag

// The 0x18-byte closure built on the stack by the ops:
//   { model*, closure-self*, node-tree* } with two free-function
//   pointers: visitor FUN_00742de0 and finisher FUN_007424ef
struct TreeClosure {
	void *model;
	TreeClosure *self;
	Node *root;
	void (*visitor)(TreeClosure *, const void *row);  // FUN_00742de0
	void (*finisher)(TreeClosure *, TreeClosure *, int);  // FUN_007424ef
};

class SessionPane
{
public:
	void *m_view;          // QAbstractItemView side

	// --- the framework every op runs ------------------------------------
	void *treeModel();     // model() -> dynamic_cast(0x119fa70)
	void forEachSelectedRow(TreeClosure &ctx);   // selectedRows + CoW
	                                                    // detach + visitor
	                                                    // loop + finisher
	// --- slot bodies ------------------------------------------------------
	void operateOnSelection()   // FUN_0073e756 (canonical form, 5.0K)
	{
		// closure{model, self, shared-null tree} + visitor/finisher,
		// selectedRows detach (FUN_00535620), per-row visitor call,
		// finisher(ctx, ctx, 3), then the collected tree feeds the op
		TreeClosure ctx = { treeModel(), nullptr, nullptr,
		                    treeVisitor, treeFinisher };
		forEachSelectedRow(ctx);
	}

	void walkTreeWithRows()    // FUN_007415fc (8.1K, same canonical form)
	{
		operateOnSelection();   // identical closure machinery
	}

	void rebuildTree()          // FUN_00740472 (12.9K)
	{
		// selectedRows snapshot; per row the internal model index
		// pointer (row[2]) drives a QHash/QString gather pass over the
		// Node tree (bulk of the 12.9K body: tree/label collection)
		TreeClosure ctx = { treeModel(), nullptr, nullptr,
		                    treeVisitor, treeFinisher };
		forEachSelectedRow(ctx);
		collectTreeLabels();   // per-row tree gather — cited
	}

	void mutateTree()           // FUN_0073eb92 (12.6K)
	{
		// selectedRows loop with a -1 sentinel fallback when row[2] is
		// null (no internal pointer), then the Node-tree mutation pass
		TreeClosure ctx = { treeModel(), nullptr, nullptr,
		                    treeVisitor, treeFinisher };
		forEachSelectedRow(ctx);
		mutateNodes();         // cited
	}

	void moveBetweenModels(const QString &name, const QVariant &extra)
	                            // FUN_0073d836 (14.3K)
	{
		// guard FUN_008c379e; dual dynamic_cast: source model
		// (typeinfo 0x118dac8) + tree model (0x119fa70); empty name ->
		// selectedRows path calling the target model vtable slot 0x178;
		// non-empty -> the named-row move variant
		if (!moveGuard())
			return;
		void *src = sourceModel();     // dynamic_cast 0x118dac8
		void *dst = treeModel();
		if (!src || !dst)
			return;
		if (name.isEmpty()) {
			forEachSelectedRow(*makeMoveClosure(dst));
			moveRows(dst, nullptr);    // model vtable +0x178 — cited
		} else {
			moveRows(dst, &extra);     // cited
		}
	}

	void openCreateDialog()     // FUN_0073cdc4 (7.1K)
	{
		// QMetaObject::tr context + a 0x110-byte dialog object
		// (FUN_0072223c ctor with the translated title), wired
		// QDialog::finished -> FUN_00740325 callback, then exec
		void *dialog = createDialog(0x110);   // FUN_0072223c
		connectFinished(dialog, dialogFinished);  // FUN_00740325
		execDialog(dialog);
	}

	// --- cited helpers ------------------------------------------------------
	static void treeVisitor(TreeClosure *, const void *row);   // FUN_00742de0
	static void treeFinisher(TreeClosure *, TreeClosure *, int); // FUN_007424ef
	void collectTreeLabels();      // FUN_00740472 gather pass
	void mutateNodes();            // FUN_0073eb92 mutation pass
	bool moveGuard();              // FUN_008c379e
	void *sourceModel();           // dynamic_cast(0x118dac8)
	TreeClosure *makeMoveClosure(void *model);
	void moveRows(void *model, const QVariant *extra);  // vtable +0x178
	void *createDialog(int size);  // FUN_0072223c
	void connectFinished(void *dialog, void (*cb)());    // FUN_00740325 cb
	void execDialog(void *dialog);
	static void dialogFinished();  // FUN_00740325
};

#endif // SESSIONPANE_H

// ---------------------------------------------------------------------------
// Deep-segment transcriptions (batch 2: the five monolith bodies)
// ---------------------------------------------------------------------------

// FUN_00740472 / FUN_0073cdc4 (twin): session-path builder + QHash fill.
// Per selected row: walk the parent chain reading model data (virtual
// +0x90, role 0) building the display path — each level prefixes the
// accumulated string with "%1%2" where %2 is ">" (QtPrivate::argToQString
// + QString::insert at position 0). Unresolvable levels fall back to the
// global query FUN_008109c6(0x11c2200). The finished path is inserted
// into a QHash<QString, Node*> (qHash + QHashData::allocateNode/rehash).
// FUN_0073cdc4 then opens the 0x110-byte create dialog
// (FUN_0071068e seed + QWidget::setAttribute(0x37, 1) + exec).
void SessionPane_buildPathHash();  // see deep-segment notes

// FUN_0073e756 / FUN_007415fc (canonical): after forEachSelectedRow
// fills the Node tree, iterate the QHash (QHashData::nextNode) and for
// each node defer processing with QTimer::singleShotImpl(0, this, cb)
// (cb = FUN_0073c702, carrying this + node refs) — zero-timer queued op.
void SessionPane_deferNodeProcessing();  // see deep-segment notes

// FUN_0073d836 deep: "move session to window".
//   name empty  -> run the selection snapshot, then a dialog flow:
//     FUN_00742950(snapshot owner) + 0x40-byte op object (FUN_006d9a66)
//     + QDialog::finished -> FUN_0073d50e (0x28 closure) + vtable 0x1a0 exec
//   name present -> global lookup FUN_00810056(0x11c2200, name, 0) +
//     FUN_008062b6/FUN_00805a3e + tr context + 0x110 dialog
//     (FUN_0072223c) — the named-window confirm/move path.
void SessionPane_moveToWindow();  // see deep-segment notes
