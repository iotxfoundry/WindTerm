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
	// findSession FUN_005b3e46: dynamic_cast(QObject) walking UP the
	// parent chain (+8/+0x10) to the nearest owner of the find-engine
	// class (typeinfo 0x11ab390)
	// runFind FUN_0091b198: it is a SIGNAL EMITTER - QMetaObject::activate
	// (engine, staticMetaObject, signal index 0, {forward, text}):
	// the actual search runs in whichever slot is connected.
	// searchText FUN_005c6448: EXT command 0x4efe ("get selection text"),
	// registers its result metatype on first use.

	// --- dialog -------------------------------------------------------------------
	void showFindReplaceDialog();                   // FUN_005c3320 (QDialog::finished
	                                                //  wired to FUN_005c3409)

	// --- command forwards (generated from TEXTVIEW-COMMANDS.md) ---

	void activateNextSelection()
	{
		// EXT CMD_20173
		sendEditor(m_result, 0x4ecd, QVariant(), QVariant());
	}

	void activatePreviousSelection()
	{
		// EXT CMD_20174
		sendEditor(m_result, 0x4ece, QVariant(), QVariant());
	}

	void addScrollBarMark(const QVariant & arg0, const QVariant & arg1, const QVariant & arg2)
	{
		// WT CMD_30021
		sendEditor(m_result, 0x7545, QVariant(), arg0, arg1, arg2, QVariant());
	}

	void appendText(const QVariant & arg0, const QVariant & arg1, const QVariant & arg2)
	{
		// WT CMD_30033
		sendEditor(m_result, 0x7551, QVariant(), arg0, arg1, arg2, QVariant());
	}

	void appendText(const QVariant & arg0, const QVariant & arg1)
	{
		// WT CMD_30033
		sendEditor(m_result, 0x7551, QVariant(), arg0, arg1, QVariant());
	}

	void cancelAutoComplete()
	{
		// SCI SCI_AUTOCCANCEL
		sendEditor(m_result, 0x835, QVariant(), QVariant());
	}

	void cancelMultipleSelections()
	{
		// EXT CMD_20228
		sendEditor(m_result, 0x4f04, QVariant(), QVariant());
	}

	void cancelSelection()
	{
		// EXT CMD_20177
		sendEditor(m_result, 0x4ed1, QVariant(), QVariant());
	}

	void cancelSnippetMode()
	{
		// WT CMD_30138
		sendEditor(m_result, 0x75ba, QVariant(), QVariant());
	}

	void commitAutoComplete()
	{
		// SCI SCI_AUTOCPOSSTART
		sendEditor(m_result, 0x837, QVariant(), QVariant());
	}

	void copy()
	{
		// SCI SCI_COPY
		sendEditor(m_result, 0x882, QVariant(), QVariant());
	}

	void discardAutoComplete()
	{
		// WT CMD_30001
		sendEditor(m_result, 0x7531, QVariant(), QVariant());
	}

	void dropSelection(const QVariant & arg0)
	{
		// EXT CMD_20176
		sendEditor(m_result, 0x4ed0, QVariant(), arg0, QVariant());
	}

	void dropSelection()
	{
		// EXT CMD_20176
		sendEditor(m_result, 0x4ed0, QVariant(), QVariant());
	}

	void eolString(const QVariant & arg0)
	{
		// WT CMD_30071
		sendEditor(m_result, 0x7577, QVariant(), arg0, QVariant());
	}

	void eolString()
	{
		// WT CMD_30071
		sendEditor(m_result, 0x7577, QVariant(), QVariant());
	}

	void exchangeCaretAnchor()
	{
		// EXT CMD_20181
		sendEditor(m_result, 0x4ed5, QVariant(), QVariant());
	}

	void fold(const QVariant & arg0, const QVariant & arg1)
	{
		// WT CMD_30065
		sendEditor(m_result, 0x7571, QVariant(), arg0, arg1, QVariant());
	}

	void fold(const QVariant & arg0)
	{
		// WT CMD_30065
		sendEditor(m_result, 0x7571, QVariant(), arg0, QVariant());
	}

	void fold(const QVariant & arg0, const QVariant & arg1)
	{
		// WT CMD_30063
		sendEditor(m_result, 0x756f, QVariant(), arg0, arg1, QVariant());
	}

	void fold(const QVariant & arg0)
	{
		// WT CMD_30064
		sendEditor(m_result, 0x7570, QVariant(), arg0, QVariant());
	}

	void gotoLine(const QVariant & arg0, const QVariant & arg1)
	{
		// WT CMD_30123
		sendEditor(m_result, 0x75ab, QVariant(), arg0, arg1, QVariant());
	}

	void gotoLine(const QVariant & arg0)
	{
		// WT CMD_30123
		sendEditor(m_result, 0x75ab, QVariant(), arg0, QVariant());
	}

	void gotoPosition(const QVariant & arg0)
	{
		// WT CMD_30124
		sendEditor(m_result, 0x75ac, QVariant(), arg0, QVariant());
	}

	void indexOf(const QVariant & arg0, const QVariant & arg1, const QVariant & arg2, const QVariant & arg3, const QVariant & arg4)
	{
		// WT CMD_30078
		sendEditor(m_result, 0x757e, QVariant(), arg0, arg1, arg2, arg3, arg4, QVariant());
	}

	void indexOf(const QVariant & arg0, const QVariant & arg1, const QVariant & arg2, const QVariant & arg3)
	{
		// WT CMD_30078
		sendEditor(m_result, 0x757e, QVariant(), arg0, arg1, arg2, arg3, QVariant());
	}

	void invertSelection()
	{
		// EXT CMD_20179
		sendEditor(m_result, 0x4ed3, QVariant(), QVariant());
	}

	void jumpToNextSnippetStop()
	{
		// WT CMD_30144
		sendEditor(m_result, 0x75c0, QVariant(), QVariant());
	}

	void jumpToPreviousSnippetStop()
	{
		// WT CMD_30144
		sendEditor(m_result, 0x75c0, QVariant(), QVariant());
	}

	void lockSelection()
	{
		// EXT CMD_20175
		sendEditor(m_result, 0x4ecf, QVariant(), QVariant());
	}

	void margin(const QVariant & arg0)
	{
		// WT CMD_30096
		sendEditor(m_result, 0x7590, QVariant(), arg0, QVariant());
	}

	void margins()
	{
		// WT CMD_30097
		sendEditor(m_result, 0x7591, QVariant(), QVariant());
	}

	void moveTo(const QVariant & arg0, const QVariant & arg1)
	{
		// EXT CMD_20226
		sendEditor(m_result, 0x4f02, QVariant(), arg0, arg1, QVariant());
	}

	void moveTo(const QVariant & arg0)
	{
		// EXT CMD_20226
		sendEditor(m_result, 0x4f02, QVariant(), arg0, QVariant());
	}

	void paste()
	{
		// SCI SCI_PASTE
		sendEditor(m_result, 0x883, QVariant(), QVariant());
	}

	void removeMargin(const QVariant & arg0)
	{
		// WT CMD_30100
		sendEditor(m_result, 0x7594, QVariant(), arg0, QVariant());
	}

	void removeScrollBarMark(const QVariant & arg0)
	{
		// WT CMD_30025
		sendEditor(m_result, 0x7549, QVariant(), arg0, QVariant());
	}

	void scrollLineDown()
	{
		// SCI SCI_LINESCROLLDOWN
		sendEditor(m_result, 0x926, QVariant(), QVariant());
	}

	void scrollLineUp()
	{
		// SCI SCI_LINESCROLLUP
		sendEditor(m_result, 0x927, QVariant(), QVariant());
	}

	void selectColumnTo(const QVariant & arg0, const QVariant & arg1)
	{
		// EXT CMD_20226
		sendEditor(m_result, 0x4f02, QVariant(), arg0, arg1, QVariant());
	}

	void selectColumnTo(const QVariant & arg0)
	{
		// EXT CMD_20226
		sendEditor(m_result, 0x4f02, QVariant(), arg0, QVariant());
	}

	void selectionText(const QVariant & arg0, const QVariant & arg1)
	{
		// WT CMD_30136
		sendEditor(m_result, 0x75b8, QVariant(), arg0, arg1, QVariant());
	}

	void selectionText(const QVariant & arg0)
	{
		// WT CMD_30136
		sendEditor(m_result, 0x75b8, QVariant(), arg0, QVariant());
	}

	void selectAll()
	{
		// SCI SCI_SELECTALL
		sendEditor(m_result, 0x7dd, QVariant(), QVariant());
	}

	void selectCommand()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void selectFold()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void selectIndentation()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void selectLine()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void selectPair()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void selectParagraph()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void selectScope()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void selectTo(const QVariant & arg0, const QVariant & arg1)
	{
		// EXT CMD_20226
		sendEditor(m_result, 0x4f02, QVariant(), arg0, arg1, QVariant());
	}

	void selectTo(const QVariant & arg0)
	{
		// EXT CMD_20226
		sendEditor(m_result, 0x4f02, QVariant(), arg0, QVariant());
	}

	void selectWord()
	{
		// EXT CMD_20191
		sendEditor(m_result, 0x4edf, QVariant(), QVariant());
	}

	void setEol(const QVariant & arg0)
	{
		// WT CMD_30073
		sendEditor(m_result, 0x7579, QVariant(), arg0, QVariant());
	}

	void setEolVisible(const QVariant & arg0)
	{
		// SCI SCI_SETVIEWEOL
		sendEditor(m_result, 0x934, QVariant(), arg0, QVariant());
	}

	void setHexBase(const QVariant & arg0)
	{
		// WT CMD_30106
		sendEditor(m_result, 0x759a, QVariant(), arg0, QVariant());
	}

	void setHexMode(const QVariant & arg0)
	{
		// WT CMD_30110
		sendEditor(m_result, 0x759e, QVariant(), arg0, QVariant());
	}

	void setIndentSize(const QVariant & arg0)
	{
		// WT CMD_30085
		sendEditor(m_result, 0x7585, QVariant(), arg0, QVariant());
	}

	void setMargin(const QVariant & arg0)
	{
		// WT CMD_30102
		sendEditor(m_result, 0x7596, QVariant(), arg0, QVariant());
	}

	void setMarginTrackChange(const QVariant & arg0)
	{
		// WT CMD_30103
		sendEditor(m_result, 0x7597, QVariant(), arg0, QVariant());
	}

	void setOvertypeEnabled(const QVariant & arg0)
	{
		// WT CMD_30117
		sendEditor(m_result, 0x75a5, QVariant(), arg0, QVariant());
	}

	void setSelection(const QVariant & arg0)
	{
		// SCI SCI_SETSELECTION
		sendEditor(m_result, 0xa0c, QVariant(), arg0, QVariant());
	}

	void setSelection(const QVariant & arg0, const QVariant & arg1)
	{
		// SCI SCI_SETSELECTION
		sendEditor(m_result, 0xa0c, QVariant(), arg0, arg1, QVariant());
	}

	void setSelectionType(const QVariant & arg0, const QVariant & arg1)
	{
		// SCI SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE
		sendEditor(m_result, 0xa20, QVariant(), arg0, arg1, QVariant());
	}

	void setSelectionType(const QVariant & arg0)
	{
		// SCI SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE
		sendEditor(m_result, 0xa20, QVariant(), arg0, QVariant());
	}

	void setTabSize(const QVariant & arg0)
	{
		// WT CMD_30148
		sendEditor(m_result, 0x75c4, QVariant(), arg0, QVariant());
	}

	void setUseTabPosition(const QVariant & arg0)
	{
		// WT CMD_30149
		sendEditor(m_result, 0x75c5, QVariant(), arg0, QVariant());
	}

	void setUseTabStop(const QVariant & arg0)
	{
		// WT CMD_30150
		sendEditor(m_result, 0x75c6, QVariant(), arg0, QVariant());
	}

	void setWordSeparators(const QVariant & arg0, const QVariant & arg1)
	{
		// WT CMD_30166
		sendEditor(m_result, 0x75d6, QVariant(), arg0, arg1, QVariant());
	}

	void setWordSeparators(const QVariant & arg0)
	{
		// WT CMD_30166
		sendEditor(m_result, 0x75d6, QVariant(), arg0, QVariant());
	}

	void setZoomFactor(const QVariant & arg0)
	{
		// SCI SCI_SETZOOM
		sendEditor(m_result, 0x945, QVariant(), arg0, QVariant());
	}

	void splitSelection()
	{
		// EXT CMD_20178
		sendEditor(m_result, 0x4ed2, QVariant(), QVariant());
	}

	void subString(const QVariant & arg0, const QVariant & arg1)
	{
		// WT CMD_30036
		sendEditor(m_result, 0x7554, QVariant(), arg0, arg1, QVariant());
	}

	void subString(const QVariant & arg0)
	{
		// WT CMD_30036
		sendEditor(m_result, 0x7554, QVariant(), arg0, QVariant());
	}



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
