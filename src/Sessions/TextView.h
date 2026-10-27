#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// TextView is a command-forwarding shell over an embedded editor object:
// every moc slot marshals QVariant args and calls sendEditor(), which
// makes a virtual call (vtable slot 0x1c0) on the editor backend held
// at +0x58. Command ids split into three spaces:
//   SCI  - standard Scintilla messages (<= 2400)
//   EXT  - WindTerm extension block (20173-20228)
//   WT   - WindTerm custom commands (30001-30166)
// See TEXTVIEW-COMMANDS.md for the full method->command table.

class QVariant;

class TextView
{
public:
	// --- object layout (offsets proven) -----------------------------------
	void *m_editor;        // +0x58: editor backend (virtual sendEditor)
	void *m_properties;    // +0xf8: property hash map (QString->QVariant)
	void *m_codec;         // +0xe0 via the view object
	int m_page;            // (page-related members per find flow)

	// --- dispatcher ----------------------------------------------------------
	// FUN_005b5d68: (*(*editor)->vtable[0x1c0])(result, editor, cmd, args...)
	void sendEditor(QVariant &result, int command, const QVariant &wparam,
	                const QVariant &lparam);

	// --- standard SCI forwards (samples, full table in the md) -------------
	void copy() { sendEditor(m_result, 0x882, {}, {}); }            // SCI_COPY
	void paste() { sendEditor(m_result, 0x883, {}, {}); }           // SCI_PASTE
	void selectAll() { sendEditor(m_result, 0x7dd, {}, {}); }       // SCI_SELECTALL
	void cancelAutoComplete() { sendEditor(m_result, 0x835, {}, {}); }
	void lineScrollDown() { sendEditor(m_result, 0x926, {}, {}); }
	void lineScrollUp() { sendEditor(m_result, 0x927, {}, {}); }
	void setViewEol(bool e) { sendEditor(m_result, 0x934, e, {}); }
	void setZoom(int z) { sendEditor(m_result, 0x945, z, {}); }
	void setSelection(int s, int e) { sendEditor(m_result, 0xa0c, s, e); }

	// --- property store (+0xf8, copy-on-write hash) ---------------------------
	QVariant property(const QString &name) const;   // FUN_005c4c0a (+0x20 payload)
	void setProperty(const QString &name, const QVariant &value);  // FUN_005c6fae
	void detachProperties();                        // FUN_0059ecda (CoW)

	// --- scheme ----------------------------------------------------------------
	QString schemeName() const;                     // FUN_005b985e ("Plain Text" default)

	// --- find engine -------------------------------------------------------------
	void find(bool forward, bool useSelectionText); // FUN_005c6752
	void findNext(bool flag) { find(true, flag); }  // FUN_005c6834
	void findPrevious(bool flag) { find(false, flag); }  // FUN_005c6842
	void *findSession();                            // FUN_005b3e46
	static void runFind(void *engine, bool forward, const QString *text);  // FUN_0091b198
	QString searchText();                           // FUN_005c6448

	// --- dialog -------------------------------------------------------------------
	void showFindReplaceDialog();                   // FUN_005c3320 (QDialog::finished
	                                                //  wired to FUN_005c3409)

private:
	QVariant m_result;      // scratch for sendEditor returns
	void runDialog();       // FUN_005c3320 helpers: FUN_006b6bfe ctor,
	                        // FUN_005c0f4c params, virtual 0x1a0 exec
};

QVariant TextView::property(const QString &name) const
{
	// FUN_005c4c0a: hash lookup FUN_00544cec on +0xf8; found -> QVariant
	// payload at node+0x20, miss -> null QVariant
	const void *node = hashLookup(m_properties, name);   // FUN_00544cec
	if (!node)
		return QVariant();
	return *reinterpret_cast<const QVariant *>((const char *)node + 0x20);
}

void TextView::setProperty(const QString &name, const QVariant &value)
{
	// FUN_005c6fae: detach on shared (+0xf8 refcount > 1), then insert
	// or update the node payload
	if (sharedCount(m_properties) > 1)
		detachProperties();
	if (existing node)
		update node + 0x20 with value;
	else
		insertNode(name, value);   // map grow path - cited
}

QString TextView::schemeName() const
{
	// FUN_005b985e: "Plain Text" default; looks up the scheme registry
	// (FUN_005b97cc) and decodes its UTF-8 name
	QString name = QStringLiteral("Plain Text");
	const void *scheme = lookupScheme(this);   // FUN_005b97cc
	if (scheme)
		name = QString::fromUtf8(scheme->name);
	return name;
}

void TextView::find(bool forward, bool useSelectionText)
{
	// FUN_005c6752: optionally seed the search text from the current
	// selection (FUN_005c6448); empty text with seed -> no-op; runs the
	// find through the engine session (FUN_005b3e46 -> FUN_0091b198)
	QString text;
	if (useSelectionText) {
		text = searchText();
		if (text.isEmpty())
			return;
	}
	void *engine = findSession();
	if (engine)
		runFind(engine, forward, &text);
}

#endif // TEXTVIEW_H
