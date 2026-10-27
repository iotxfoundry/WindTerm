#include "EditorEngine.h"

#include <new>

// Bodies transcribed from FUN_00a418c4 (level-2 dispatcher, 37951B);
// comments cite the inline region. Phase-1 restoration (reference).

// engine-internal helpers (binary addresses noted; reference thunks)
static void editCtxBegin(void *ctx, EditorEngine *e, unsigned *flags)
{ (void)ctx; (void)e; (void)flags; }          // editctx_beginIter
static void editCtxCommit(void *ctx) { (void)ctx; }   // FUN_00a161d8
static void insertBytes(EditorEngine *e, long long pos, const char *data, int len)
{ (void)e; (void)pos; (void)data; (void)len; }        // FUN_00a287f8
static void replaceBytes(EditorEngine *e, long long pos, int a, int b,
                         const char *d1, int l1, const char *d2, int l2)
{ (void)e; (void)pos; (void)a; (void)b; (void)d1; (void)l1; (void)d2; (void)l2; }  // FUN_00a2893e
static void bufSubstr(QByteArray *out, void *doc, long long start, long long end)
{ (void)doc; (void)start; (void)end; out->clear(); } // buf_substr
static void bytesToQString(QString *out, void *doc, const QByteArray *bytes)
{ (void)doc; (void)bytes; out->clear(); }            // FUN_0092777c (doc codec)
static void searchExecute(QVariantList *out, EditorEngine *e, void *params,
                          long long start, long long end, int nth)
{ (void)e; (void)params; (void)start; (void)end; (void)nth; out->clear(); }  // FUN_00a31966
static void gotoPositionImpl(EditorEngine *e, long long pos)
{ (void)e; (void)pos; }                              // FUN_00a26f32
static bool docMark(EditorEngine *e, void *doc, long long pos, bool mode2)
{ (void)e; (void)doc; (void)pos; (void)mode2; return false; }  // FUN_0092f0f6
static void objTouch(void *obj) { (void)obj; }       // FUN_0095cc7e
static void sessionViewSoftReset(EditorEngine *e) { (void)e; }  // 0x8a4/0x8a5 共用
static void notifyFlag10(EditorEngine *e) { (void)e; }  // FUN_00a243ae(e, 0x10)
static int docTabSize(EditorEngine *e) { (void)e; return 1; }  // *(doc+0x270)
static void docSetTabSize(EditorEngine *e, int n) { (void)e; (void)n; }  // FUN_00925338
// EXT one-call thunks (addresses = the leaf implementations)
static void eA237a6(EditorEngine *e) { (void)e; }             // 0x4ecd activateNextSelection
static void eA23808(EditorEngine *e) { (void)e; }             // 0x4ece activatePreviousSelection
static void eA2386a(EditorEngine *e) { (void)e; }             // 0x4ecf lockSelection
static void eA23894(EditorEngine *e, int v) { (void)e; (void)v; }  // 0x4ed0 dropSelection
static void eA20198(EditorEngine *e) { (void)e; }             // 0x4ed2 splitSelection
static void eA2014e(EditorEngine *e) { (void)e; }             // 0x4ed1 cancelSelection
static void eA201e2(EditorEngine *e) { (void)e; }             // 0x4ed3 invertSelection
static void eA20238(EditorEngine *e, bool on) { (void)e; (void)on; }  // 0x4ecb
static bool eA2022c(EditorEngine *e) { (void)e; return false; }       // 0x4ec6
static bool eA2025a(EditorEngine *e) { (void)e; return false; }       // 0x4ed1? second probe
static void eA202b0(EditorEngine *e) { (void)e; }             // 0x4ed5 exchangeCaretAnchor
static bool eA385ee(EditorEngine *e, int a) { (void)e; (void)a; return false; }  // 0x4ee4
static void eA286a2(EditorEngine *e, int a) { (void)e; (void)a; }    // 0x4ee6
static long long docPosOp(void *doc, bool b) { (void)doc; (void)b; return 0; }  // 0x4ec9 FUN_00927a68
static bool docLineProbe1(void *doc, long long v) { (void)doc; (void)v; return false; }  // 0x4ec7 FUN_00927ce0
static bool docLineProbe2(void *doc, long long v) { (void)doc; (void)v; return false; }  // 0x4ec8 FUN_00927e22
static long long docLineGet(void *doc, long long v, unsigned f, int g) { (void)doc; (void)v; (void)f; (void)g; return 0; }  // 0x75a7 FUN_009252f4
static void eA26ec6(EditorEngine *e, unsigned long long line, int col) { (void)e; (void)line; (void)col; }  // 0x75ab gotoLine
static void eA1fd8c(EditorEngine *e, bool on) { (void)e; (void)on; }  // 0x7597 setMarginTrackChange
static void eA28e7c(EditorEngine *e, int base) { (void)e; (void)base; }  // 0x759a setHexBase
static void eA282b8(EditorEngine *e) { (void)e; }             // 0x75aa
static double eA2041e(EditorEngine *e) { (void)e; return 0; } // 0x75a9 (double read)

// SCI one-call thunks (level-2 SCI range bodies)
static void eA28a68(EditorEngine *e, unsigned long long a, long long b) { (void)e; (void)a; (void)b; }  // 0x7d1 scroll target
static void eA26756(EditorEngine *e) { (void)e; }             // 0x7d4 redraw
static long long docLength(void *doc) { (void)doc; return 0; } // FUN_0092801a
static unsigned docCharAtLine(void *doc, long long line) { (void)doc; (void)line; return 0; }  // 0x7da FUN_00926c8c
static void eA23b8c(EditorEngine *e, int v) { (void)e; (void)v; }  // 0x7db
static void eA26df4(EditorEngine *e) { (void)e; }             // 0x7dd
static void docOp927ddc(void *doc) { (void)doc; }             // 0x7de
static bool docGate927a4c(void *doc) { (void)doc; return false; }  // 0x7e0 gate
static bool docFlag9290e8(void *doc) { (void)doc; return false; }  // 0x7e0 value
static bool docFlag927a24(void *doc) { (void)doc; return false; }  // 0x7e3
static int styleTableGet(void *styleCtx, int i) { (void)styleCtx; (void)i; return 0; }  // 0x7e1 FUN_0094316a
static int styleAtPos(void *styleCtx, long long pos) { (void)styleCtx; (void)pos; return 0; }  // 0x7fe FUN_0094277a
static long long docOp92814a(void *doc) { (void)doc; return 0; }  // 0x7ec
static void eA1f7be(EditorEngine *e) { (void)e; }             // 0x7f8 chain
static void eA22c4e(EditorEngine *e, int n) { (void)e; (void)n; }  // 0x7f8 chain
static void styleCtxTouch(void *ctx) { (void)ctx; }           // FUN_009501b0 (e+8)
static int hitTestOffset(void *ctx) { (void)ctx; return 0; }   // FUN_0095019c (e+8)
static long long hitTestResolve(void *out) { (void)out; return 0; }  // FUN_0096bbc0
static void editorHitTest(double x, double y, void *out, EditorEngine *e,
                          int a, int b, int c) { (void)x; (void)y; (void)out; (void)e; (void)a; (void)b; (void)c; }  // editor_hitTest
static void docOp925c8c(void *doc, int v) { (void)doc; (void)v; }  // 0x7fd
static int docOp9251ea(void *doc, long long a, int b) { (void)doc; (void)a; (void)b; return 0; }  // 0x7ff
static int docOp92a2b2(void *doc, long a, int b) { (void)doc; (void)a; (void)b; return 0; }  // 0x7fb
static void docOp92a3fc(void *doc, int v) { (void)doc; (void)v; }  // 0x7e2
static void docOp927a30(void *doc, bool b) { (void)doc; (void)b; }  // 0x7dc
static void vtA0Repaint()
{
	// engine vtable +0xa0 slot — full repaint trigger (0x7e5/0x7583)
}

// SCI 0x80x-0x88x one-call thunks
static void docOp927a08(void *doc, unsigned long long v) { (void)doc; (void)v; }  // 0x81e
static void docOp927a14(void *doc, int v) { (void)doc; (void)v; }  // 0x81f (arg 1)
static void docOp92c4ae(void *doc, long long a, int b) { (void)doc; (void)a; (void)b; }  // 0x84e
static long long docOp928404(void *doc, long long v) { (void)doc; (void)v; return 0; }  // 0x850 (gated +0x1067)
static int docOp9284c6(void *doc, long long v) { (void)doc; (void)v; return 0; }  // 0x84f sibling (gated)
static long long docOp928624(void *doc, long long v) { (void)doc; (void)v; return 0; }  // 0x851 plain path
static long long docOp92520c(void *doc, long long v) { (void)doc; (void)v; return 0; }  // 0x858 plain path
static long long editorLineEndIdx(void *obj, long long v) { (void)obj; (void)v; return 0; }  // 0x858 gated path
static bool docFlag9290e8b(void *doc) { (void)doc; return false; }  // 0x85c
static long long docOp92522a(void *doc, long long v) { (void)doc; (void)v; return 0; }  // 0x876 plain
static long long objRunStyleGet(void *obj, void *node) { (void)obj; (void)node; return 0; }  // 0x876 gated FUN_009587cc
static double eScrollSet(EditorEngine *e, void *node) { (void)e; (void)node; return 0; }  // 0x875 region FUN_00a225be (XMM out)
static void runNodeInit(void *node, long long start, int a, int b) { (void)node; (void)start; (void)a; (void)b; }  // runstyles_runnode_init
static void runNodeFree(void *node) { (void)node; }  // FUN_0096bb02
static void eA20eb2(EditorEngine *e, void *anchor, void *caret, int sel) { (void)e; (void)anchor; (void)caret; (void)sel; }  // 0x870 set selection
static void editorSelCtor(void *sel, EditorEngine *e, int *type) { (void)sel; (void)e; (void)type; }  // editor_selCtor
static void editorSelDtor(void *sel) { (void)sel; }  // FUN_00974856
static void docOp927dbe(void *doc) { (void)doc; }  // 0x87f
static void eA25f72(EditorEngine *e) { (void)e; }  // 0x881
static void vtCall(EditorEngine *e, int slotOff) { (void)e; (void)slotOff; }  // engine vtable slot by offset
static void eA235ce(EditorEngine *e, long long a, int b) { (void)e; (void)a; (void)b; }  // 0x883 tail
static void editorSelMake(void *sel, EditorEngine *e, const char *mode, int a, int b) { (void)sel; (void)e; (void)mode; (void)a; (void)b; }  // 0x885
static void eA21110(EditorEngine *e, void *node, int a) { (void)e; (void)node; (void)a; }  // 0x885 tail


void EditorEngine::cmdAppendText(const QVariantList &args)
{
	// 0x7551 (0xa48ca8 region): 3-arg form (position, bytes,
	// moveCursor). flags = moveCursor ? 0x200 : 0x2 — the edit
	// transaction context decides cursor placement; insert runs inside
	// begin/commit
	if (args.size() != 3)
		return;
	const long long pos = args.at(0).toLongLong();
	const QByteArray bytes = args.at(1).toByteArray();
	const bool moveCursor = args.at(2).toBool();
	unsigned flags = moveCursor ? 0x200 : 0x2;
	char ctx[64];
	editCtxBegin(ctx, this, &flags);
	insertBytes(this, pos, bytes.constData(), bytes.size());
	editCtxCommit(ctx);
}

void EditorEngine::cmdReplaceText(const QVariantList &args)
{
	// 0x7552 (0xa47a2a region): 5-arg form (position, from, to,
	// oldBytes, newBytes) — the two ints go through FUN_00a4e152
	// (column/line resolution) before the replace
	if (args.size() != 5)
		return;
	const long long pos = args.at(0).toLongLong();
	const int a = (int)(long long)args.at(1).toLongLong();
	const int b = (int)(long long)args.at(2).toLongLong();
	const QByteArray oldB = args.at(3).toByteArray();
	const QByteArray newB = args.at(4).toByteArray();
	replaceBytes(this, pos, a, b, oldB.constData(), oldB.size(),
	             newB.constData(), newB.size());
}

void EditorEngine::cmdSubString(long long start, long long end, QVariant *ret)
{
	// 0x7554 (0xa48d60 region): byte-range slice of the document
	// (buf_substr) decoded to QString through the document's codec
	QByteArray buf;
	bufSubstr(&buf, m_doc, start, end);
	QString out;
	bytesToQString(&out, m_doc, &buf);
	*ret = QVariant(out);
}

void EditorEngine::cmdIndexOf(const QVariantList &args, QVariant *ret)
{
	// 0x757e (0xa428c4 region): pattern search. Args (list): pattern
	// (QString), start, end (ll), matchOptions (int), nth (int).
	// MatchOption bits map to engine flags: MatchCase(1)->2,
	// MatchRegex(2)->1, MatchWord(4)->4. Searcher object 0x68 bytes,
	// ctor FUN_00899fba, pattern QString at +0x18, flags at +0xc;
	// execution FUN_00a31966 returns the match list; nth < 1 reads as 1
	if (args.size() < 6)
		return;
	const QString pattern = args.at(0).toString();
	const long long start = args.at(1).toLongLong();
	const long long end = args.at(2).toLongLong();
	const int opt = args.at(3).toInt();
	int nth = args.at(4).toInt();
	if (nth < 1)
		nth = 1;
	unsigned flags = 0;
	if (opt & 1)
		flags |= 2;
	if (opt & 2)
		flags |= 1;
	if (opt & 4)
		flags |= 4;
	char *searcher = (char *)::operator new(0x68);
	// FUN_00899fba ctor; pattern QString at +0x18, flags at +0xc
	new (searcher + 0x18) QString(pattern);
	*(unsigned *)(searcher + 0xc) = flags;
	QVariantList results;
	searchExecute(&results, this, searcher, start, end, nth);
	*ret = QVariant(results);
	::operator delete(searcher, 0x68);
}

void EditorEngine::cmdSetFlagF8(int which, bool on)
{
	// 0x754b/0x754c (0xa48b90 region): engine vtable +0xf8 slot called
	// with (which 1|2, on) — paired boolean engine modes
	typedef void (*SetFn)(EditorEngine *, int, bool);
	(*(SetFn *)(*(void ***)this + 0xf8 / 8))(this, which, on);
}

void EditorEngine::cmdGotoPosition(long long pos)
{
	// 0x75ac: FUN_00a26f32
	gotoPositionImpl(this, pos);
}

// ---------------------------------------------------------------------------
// Level-2 dispatcher (0x00a418c4, 37951B): the command bodies live as
// cmdXxx methods above; this routes. First batch wired, remainder as
// the table in EDITOR-ENGINE-COMMANDS.md grows.
// ---------------------------------------------------------------------------
QVariant EditorEngine::dispatchLevel2(uint cmd, const QVariant &a, const QVariant &b)
{
	switch (cmd) {
	case 0x754b:
	case 0x754c:
		cmdSetFlagF8(cmd == 0x754c ? 2 : 1, a.toBool());
		return QVariant(0);
	case 0x7551:
		cmdAppendText(a.toList());
		return QVariant(0);
	case 0x7552:
		cmdReplaceText(a.toList());
		return QVariant(0);
	case 0x7554: {
		QVariant ret;
		cmdSubString(a.toLongLong(), b.toLongLong(), &ret);
		return ret;
	}
	case 0x757e: {
		QVariant ret;
		cmdIndexOf(a.toList(), &ret);
		return ret;
	}
	case 0x7543:
		cmdDocMark(a.toLongLong());
		return QVariant(0);
	case 0x7544:
		return cmdRenderPixmap(a.toReal());
	case 0x7546:
		return QVariant(cmdVtE8Probe(1));
	case 0x7548:
		return QVariant(cmdVtE8Probe(2));
	case 0x754a:
		cmdVtD0();
		return QVariant(0);
	case 0x7556:
		return QVariant(cmdDocFlag());
	case 0x7559:
		return QVariant(cmdDocCollect(a.toList()));
	case 0x755a:
		cmdDocSetString(a.toString());
		return QVariant(0);
	case 0x755c:
		return QVariant(cmdFlag1dbBit1());
	case 0x755d:
		return QVariant(cmdFlag1dbHigh());
	case 0x755f:
		return QVariant(cmdIntDd0());
	case 0x7560:
		return QVariant(cmdZoomFactor());
	case 0x7561:
		cmdSetBoolD5a0(a.toBool());
		return QVariant(0);
	case 0x75af:
		return QVariant(cmdProbe28398());
	case 0x75b1:
		return QVariant(cmdProbe224e4());
	case 0x75b3:
		return QVariant(cmdVtE0Read(a.toInt()));
	case 0x75ba:
		cmdCancelSnippet();
		return QVariant(0);
	case 0x75c2:
		return QVariant(cmdIndentSize());
	case 0x75c3:
		return QVariant(cmdDocFlag279());
	case 0x75c4:
		return QVariant(cmdSetTabSize(a.toInt()));
	case 0x75c5:
		return QVariant(cmdSetIndentSize(a.toInt()));
	case 0x75c6:
		cmdSetDocFlag279(a.toBool());
		return QVariant(0);
	case 0x75c9:
		return cmdGetRegisterList();
	case 0x75ca:
		return QVariant(cmdRegisterFlag());
	case 0x75cb:
		cmdSetRegister(a.toLongLong());
		return QVariant(0);
	case 0x75cf:
		return QVariant(cmdUllFrom10a0(a.toLongLong()));
	case 0x75d6:
		cmdSetWordSeparators(a.toString(), b.toBool());
		return QVariant(0);
	// level-2 SCI range (0x7d1-0x7ff)
	case 0x7d1:
		eA28a68(this, a.toULongLong(), b.toLongLong());
		return QVariant(0);
	case 0x7d4:
		eA26756(this);
		return QVariant(0);
	case 0x7da: {
		const long long line = a.toLongLong();
		if (line < 0 || line >= docLength(m_doc))
			return QVariant(0u);
		return QVariant(docCharAtLine(m_doc, line));
	}
	case 0x7db:
		eA23b8c(this, a.toInt());
		return QVariant(0);
	case 0x7dc:  // doc bool op, returns 0
		docOp927a30(m_doc, a.toBool());
		return QVariant(0);
	case 0x7dd:
		eA26df4(this);
		return QVariant(0);
	case 0x7de:
		docOp927ddc(m_doc);
		return QVariant(0);
	case 0x7e0:
		return QVariant(docGate927a4c(m_doc) ? !docFlag9290e8(m_doc) : false);
	case 0x7e1:
		return QVariant(styleTableGet(m_doc, a.toInt()));
	case 0x7e2:
		docOp92a3fc(m_doc, a.toInt());
		return QVariant(0);
	case 0x7e3:
		return QVariant(docFlag927a24(m_doc));
	case 0x7e4:
		return QVariant(m_intD80);
	case 0x7e5:  // change-detect write + vtable+0xa0 repaint
		if (a.toInt() != m_intD80) {
			m_intD80 = a.toInt();
			vtA0Repaint();
		}
		return QVariant(0);
	case 0x7e6:  // position from point (x,y doubles), nearest mode 0
	case 0x7e7: {  // same, mode 1
		char out[32];
		editorHitTest(a.toDouble() - hitTestOffset(m_styleCtx), b.toDouble(),
		              out, this, cmd == 0x7e7 ? 1 : 0, 2, 1);
		return QVariant(hitTestResolve(out));
	}
	case 0x7ec:
		return QVariant(docOp92814a(m_doc));
	case 0x7f2:
		return QVariant(m_flagEc5);
	case 0x7f3:
		m_flagEc5 = a.toBool();
		return QVariant(0);
	case 0x7f8: {  // packed int table: 32 slots, 11-byte stride at this+8
		const unsigned slot = a.toUInt();
		if (slot < 0x20) {
			*(int *)((char *)m_styleCtx + slot * 0xb) = b.toInt();
			styleCtxTouch(m_styleCtx);
			eA1f7be(this);
			eA22c4e(this, 4);
		}
		return QVariant(0);
	}
	case 0x7fb:
		return QVariant(docOp92a2b2(m_doc, a.toInt(), b.toInt()));
	case 0x7fd:
		docOp925c8c(m_doc, a.toInt());
		return QVariant(0);
	case 0x7fe:
		return QVariant(styleAtPos(m_styleCtx, a.toLongLong()));
	case 0x7ff:
		return QVariant(docOp9251ea(m_doc, a.toLongLong(), b.toInt()));
	case 0x800: {  // backward scan: first position <= a whose style hits mask b
		unsigned long long pos = a.toULongLong();
		const int mask = b.toInt();
		while ((long)pos >= 0) {
			if (mask & styleAtPos(m_styleCtx, (long long)(uint)pos))
				return QVariant((long long)pos);
			if (pos-- == 0)
				break;
		}
		return QVariant((long long)-1);
	}
	case 0x81e:
		docOp927a08(m_doc, a.toULongLong());
		return QVariant(0);
	case 0x81f:
		docOp927a14(m_doc, 1);
		return QVariant(0);
	case 0x84e:
		docOp92c4ae(m_doc, a.toLongLong(), b.toInt());
		return QVariant(0);
	case 0x84f:  // gated by +0x1067 (byte at engine)
		if (m_docFlag1067 == 0)
			return QVariant(0);
		return QVariant(docOp9284c6(m_doc, a.toLongLong()));
	case 0x850:
		if (m_docFlag1067 == 0)
			return QVariant((long long)0);
		return QVariant(docOp928404(m_doc, a.toLongLong()));
	case 0x851:  // +0x1128 gate: plain vs column-modulo conversion
		if (m_gate1128 == 0)
			return QVariant(docOp928624(m_doc, a.toLongLong()));
		return QVariant(a.toLongLong() % m_mod1118);
	case 0x857:
		return QVariant(m_intFd4);
	case 0x858:  // line end: dual path by the same gate
		if (m_gate1128 == 0)
			return QVariant(docOp92520c(m_doc, a.toLongLong()));
		return QVariant(editorLineEndIdx(m_obj10a0, a.toLongLong()));
	case 0x85c:
		return QVariant(docFlag9290e8b(m_doc));
	case 0x862:
		m_intEa4 = a.toInt();
		return QVariant(0);
	case 0x863:  // inferred id: the <0x864 sibling read of the pair
		return QVariant(m_intEa4);
	case 0x864:
		m_intEa8 = a.toInt();
		return QVariant(0);
	case 0x870: {  // setSelection(anchor, caret): negative defaults
		int selType = 8;
		char sel[64];
		editorSelCtor(sel, this, &selType);
		long long caret = b.toLongLong();
		long long anchor = a.toLongLong();
		if (caret < 0)
			caret = docLength(m_doc);
		if (anchor < 0)
			anchor = caret;
		char n1[64], n2[64];
		runNodeInit(n1, caret, 0, 0);
		runNodeInit(n2, anchor, 0, 0);
		eA20eb2(this, n2, n1, 1);
		runNodeFree(n2);
		runNodeFree(n1);
		editorSelDtor(sel);
		return QVariant(0);
	}
	case 0x873:  // change-detect bool + repaint
		if (m_flagEc2 != a.toBool()) {
			m_flagEc2 = a.toBool();
			vtA0Repaint();
		}
		return QVariant(0);
	case 0x875: {  // scroll set (pos >= 0), XMM double return
		const long long pos = a.toLongLong();
		if (pos < 0)
			return QVariant(0);
		char n1[64];
		runNodeInit(n1, pos, 0, 0);
		const double d = eScrollSet(this, n1);
		runNodeFree(n1);
		return QVariant(d);
	}
	case 0x876:
		if (m_gate1128 != 0) {
			char n1[64];
			runNodeInit(n1, a.toLongLong(), 0, 0);
			const long long r = objRunStyleGet(m_obj10a0, n1);
			runNodeFree(n1);
			return QVariant(r);
		}
		return QVariant(docOp92522a(m_doc, a.toLongLong()));
	case 0x87f:
		docOp927dbe(m_doc);
		return QVariant(0);
	case 0x881:
		eA25f72(this);
		return QVariant(0);
	case 0x882:  // engine vtable +0x108
		vtCall(this, 0x108);
		return QVariant(0);
	case 0x883:  // SCI_COPY: vtable +0x118 then mode guard tail
		vtCall(this, 0x118);
		if (m_docFlag1067 != 2)
			eA235ce(this, -1, 1);
		return QVariant(0);
	case 0x885: {  // select-all style make (mode str @0xcb99b6)
		char sel[64], n1[64];
		editorSelMake(sel, this, "\x08", 8, 2);
		runNodeInit(n1, 0, 0, 0);
		eA21110(this, n1, 0);
		runNodeFree(n1);
		editorSelDtor(sel);
		return QVariant(0);
	}
	// EXT block (0x4e23-0x4f04) — one-call leaves, addresses in thunk names
	case 0x4ec7:
		return QVariant(docLineProbe1(m_doc, a.toLongLong()));
	case 0x4ec8:
		return QVariant(docLineProbe2(m_doc, a.toLongLong()));
	case 0x4ec9:
		return QVariant(docPosOp(m_doc, a.toBool()));
	case 0x4ec6:
		return QVariant(eA2022c(this));
	case 0x4ecb:
		eA20238(this, a.toBool());
		return QVariant(0);
	case 0x4ecd:
		eA237a6(this);
		return QVariant(0);
	case 0x4ece:
		eA23808(this);
		return QVariant(0);
	case 0x4ecf:
		eA2386a(this);
		return QVariant(0);
	case 0x4ed0:
		eA23894(this, a.toInt());
		return QVariant(0);
	case 0x4ed1:
		eA2014e(this);
		return QVariant(0);
	case 0x4ed2:
		eA20198(this);
		return QVariant(0);
	case 0x4ed3:
		eA201e2(this);
		return QVariant(0);
	case 0x4ed5:
		eA202b0(this);
		return QVariant(0);
	case 0x4ee4:
		return QVariant(eA385ee(this, 0));
	case 0x4ee6:
		eA286a2(this, 0);
		return QVariant(0);
	// tail WT leaves
	case 0x7597:
		eA1fd8c(this, a.toBool());
		return QVariant(0);
	case 0x759a:
		eA28e7c(this, a.toInt());
		return QVariant(0);
	case 0x75a7:
		return QVariant(docLineGet(m_doc, a.toLongLong(),
		                           b.toBool() ? 1u : ~1u, 1));
	case 0x75a9:
		return QVariant(eA2041e(this));
	case 0x75aa:
		eA282b8(this);
		return QVariant(0);
	case 0x75ab:  // gotoLine(line u64 in a, column int in b)
		eA26ec6(this, a.toULongLong(), b.toInt());
		return QVariant(0);
	case 0x756f:
		cmdFoldRange(a.toLongLong(), b.toLongLong());
		return QVariant(0);
	case 0x7571:
		cmdFoldLine(a.toLongLong(), b.toBool());
		return QVariant(0);
	case 0x7577:
		return QVariant(cmdEolString(a.toLongLong()));
	case 0x757a:
		cmdSetEol(a.toInt());
		return QVariant(0);
	case 0x7591:
		return QVariant(cmdMargins());
	case 0x75b7:
		return QVariant(cmdSelectionTextBytes(a.toByteArray(), b.toBool()));
	case 0x75b8:
		return QVariant(cmdSelectionText(a.toString(), b.toBool()));
	case 0x7583:
		cmdSetPairHighlight(a.toBool());
		return QVariant(0);
	case 0x75ac:
		cmdGotoPosition(a.toLongLong());
		return QVariant(0);
	default:
		return QVariant(0);   // remaining ~329 leaves per the command table
	}
}

// ---------------------------------------------------------------------------
// Second batch: fold / margin / eol / selection families (inline regions)
// ---------------------------------------------------------------------------

void EditorEngine::cmdFoldRange(long long start, long long end)
{
	// 0x756f (0xa49290 region): fold range on the fold manager
	// (+0x10b8): FUN_00a5ec00(mgr, start, end, 0, 1)
	// foldMgrFoldRange(m_foldMgr, start, end, 0, 1); — thunk
}

void EditorEngine::cmdFoldLine(long long line, bool expand)
{
	// 0x7571 (0xa4a0d0 region): FUN_00a5ed6e(mgr, line, 1, 0, expand)
	// foldMgrFoldLine(m_foldMgr, line, 1, 0, expand); — thunk
}

QByteArray EditorEngine::cmdEolString(long long eol)
{
	// 0x7577 (0xa42761 region): FUN_00a21a0e(&out, engine, eol) — the
	// per-eol-kind line terminator string
	// QByteArr return; — thunk
	return QByteArray();
}

void EditorEngine::cmdSetEol(int eol)
{
	// 0x757a: FUN_00a21b6a(engine, eol) — eol kind set; sibling 0x757b
	// (FUN_00a21b2c) is the other kind slot
	// eolSet(this, eol); — thunk
}

QStringList EditorEngine::cmdMargins()
{
	// 0x7591 (0xa47538 region): walks the inline margin node list
	// (+0xd58..+0xd60, 24-byte nodes); nodes with a non-empty +4 name
	// field convert (cstr_toQStr) into the QStringList result
	QStringList out;
	for (const char *n = (const char *)m_marginBegin; n != (const char *)m_marginEnd; n += 24)
		if (*(const int *)(n + 4) != 0)
			out << QString::fromUtf8(*(const char *const *)n);
	return out;
}

QString EditorEngine::cmdSelectionText(const QString &sep, bool useSep)
{
	// 0x75b8 (0xa49a8e region): FUN_00a36f26(&out, engine, sep, useSep)
	(void)sep; (void)useSep;
	return QString();
}

QByteArray EditorEngine::cmdSelectionTextBytes(const QByteArray &sep, bool useSep)
{
	// 0x75b7 sibling (0xa426fc region): FUN_00a36eb0 — byte form
	(void)sep; (void)useSep;
	return QByteArray();
}

void EditorEngine::cmdSetPairHighlight(bool on)
{
	// 0x7583 (0xa41ef0 region): +0xd92 flag; off → FUN_00a10c68 on the
	// pair object (+0x10e0)+8 then engine vtable+0xa0 repaint; on →
	// pairHighlightUnmatched(engine, -1) (FUN_00a29352)
	m_pairEnabled = on;
	if (on) {
		// FUN_00a10c68(*(char **)m_pairObj + 8);
		// (*(vt+0xa0))(this);
	} else {
		// pairHighlightUnmatched(this, -1);
	}
}

// ---------------------------------------------------------------------------
// Third batch: probes / document ops / pixmap render (inline regions)
// ---------------------------------------------------------------------------

QVariant EditorEngine::cmdRenderPixmap(qreal scale)
{
	// 0x7544 (0xa48ded region): toReal(a) then FUN_00a4186e renders the
	// view to a QPixmap (scale factor) — the only pixel-returning command
	(void)scale;
	return QVariant();
}

bool EditorEngine::cmdVtE8Probe(int which)
{
	// 0x7546/0x7548 (0xa48dc0/0xa48db0 region): engine vtable +0xe8
	// with (1|2) — paired mode probes (hex/read-only family)
	typedef bool (*ProbeFn)(EditorEngine *, int);
	return (*(ProbeFn *)(*(void ***)this + 0xe8 / 8))(this, which);
}

void EditorEngine::cmdVtD0()
{
	// 0x754a (0xa48d80 region): engine vtable +0xd0, no args
	typedef void (*Fn)(EditorEngine *);
	(*(Fn *)(*(void ***)this + 0xd0 / 8))(this);
}

void EditorEngine::cmdDocMark(long long pos)
{
	// 0x7543 (0xa48b00 region): FUN_0092f0f6(doc, pos, +0x1067 == 2)
	// — on success: FUN_0095cc7e(+0x10a0), session_view_soft_reset,
	// FUN_00a243ae(engine, 0x10)
	const bool ok = docMark(this, m_doc, pos, m_docFlag1067 == 2);
	if (ok) {
		objTouch(m_obj10a0);
		sessionViewSoftReset(this);
		notifyFlag10(this);
	}
}

bool EditorEngine::cmdDocFlag()
{
	// 0x7556: FUN_00927ec8(doc)
	return false;
}

QString EditorEngine::cmdDocCollect(const QVariantList &args)
{
	// 0x7559 (0xa49659 region): 5-arg form (pattern QString, bool,
	// ull, ll, ll) — FUN_00929076(&out, doc, ...) returns text
	(void)args;
	return QString();
}

void EditorEngine::cmdDocSetString(const QString &s)
{
	// 0x755a (0xa42e04 region): FUN_00927efc(doc, s)
	(void)s;
}

int EditorEngine::cmdFlag1dbBit1()
{
	// 0x755c (0xa42f00 region): (int)((flags1db << 0x1e) >> 0x1f) — bit1
	return (int)((m_flags1db << 0x1e) >> 0x1f);
}

int EditorEngine::cmdFlag1dbHigh()
{
	// 0x755d (0xa42f20 region): (int)flags >> 3 — high nibble bits
	return m_flags1db >> 3;
}

int EditorEngine::cmdIntDd0()
{
	// 0x755f: reads +0xdd0
	return m_intDd0;
}

double EditorEngine::cmdZoomFactor()
{
	// 0x7560: reads +0xdd8
	return m_zoomFactor;
}

void EditorEngine::cmdSetBoolD5a0(bool on)
{
	// 0x7561: FUN_00a2d5a0(engine, on)
	(void)on;
}

void EditorEngine::cmdCancelSnippet()
{
	// 0x75ba: FUN_00a28ee8(engine) — snippet-mode teardown
}

long long EditorEngine::cmdVtE0Read(int arg)
{
	// 0x75b3 (0xa4a1f0 region): engine vtable +0xe0 (int arg) → object
	// or 0; hit → read long long at +0x40
	(void)arg;
	return 0;
}

bool EditorEngine::cmdProbe28398()
{
	// 0x75af: FUN_00a28398(engine)
	return false;
}

int EditorEngine::cmdProbe224e4()
{
	// 0x75b1: FUN_00a224e4(engine)
	return 0;
}

// ---------------------------------------------------------------------------
// Fourth batch: tab / indent / register / word-separator families
// ---------------------------------------------------------------------------

bool EditorEngine::cmdSetTabSize(int n)
{
	// 0x75c4 (0xa49460 region): rejected when n < 1 or unchanged
	// (doc+0x270); accepted runs FUN_00925338(doc, n) + soft reset
	if (n < 1 || n == docTabSize(this))
		return false;
	docSetTabSize(this, n);
	sessionViewSoftReset(this);
	return true;
}

int EditorEngine::cmdIndentSize()
{
	// 0x75c2: doc+0x274 read
	return 0;
}

bool EditorEngine::cmdSetIndentSize(int n)
{
	// 0x75c5 (0xa494a0 region): change-detect against doc+0x274, write
	// only when different, returns changed
	(void)n;
	return false;
}

bool EditorEngine::cmdDocFlag279()
{
	// 0x75c3: doc+0x279 bool read
	return false;
}

void EditorEngine::cmdSetDocFlag279(bool on)
{
	// 0x75c6: doc+0x279 write
	(void)on;
}

void EditorEngine::cmdSetWordSeparators(const QString &s, bool keep)
{
	// 0x75d6 (0xa482fc region): FUN_009279ec(doc, separators, keep)
	(void)s; (void)keep;
}

void EditorEngine::cmdSetRegister(long long key)
{
	// 0x75cb (0xa45d6c region): builds an edit ctx (FUN_00a20680) +
	// value (FUN_0096bbc0), engine key (FUN_00a20666) then
	// FUN_009301a8(doc, key, valueA, valueB); ctx dtor FUN_0096bb02
	(void)key;
}

QVariant EditorEngine::cmdGetRegisterList()
{
	// 0x75c9: FUN_00926b28(doc) — register contents list
	return QVariant();
}

bool EditorEngine::cmdRegisterFlag()
{
	// 0x75ca: FUN_00926afe(doc)
	return false;
}

long long EditorEngine::cmdUllFrom10a0(long long v)
{
	// 0x75cf: FUN_009589f0(+0x10a0 object, v)
	(void)v;
	return 0;
}

// ---------------------------------------------------------------------------
// Fifth batch: EXT block one-call leaves (0x4e23-0x4f04) + gotoLine
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// Level-1 dispatcher (0x00a5205e, 1113B): SCI fast range + two WT ids.
// Everything else falls through to level 2 (0x00a418c4). Names follow
// TEXTVIEW-COMMANDS.md where verified; hex ids otherwise.
// ---------------------------------------------------------------------------

QVariant EditorEngine::dispatchLevel1(uint cmd, const QVariant &a, const QVariant &b)
{
	// engine-internal thunks (level-1 bodies; addresses cited)
	auto f982 = [](EditorEngine *) -> int { return 0; };      // FUN_00a4f982
	auto fae8 = [](EditorEngine *) -> int { return 0; };      // FUN_00a4fae8
	auto f9ee = []() -> QString { return QString(); };        // FUN_00a4f9ee
	auto face = [](EditorEngine *) -> long long { return 0; };// FUN_00a4face
	auto f7b4 = [](EditorEngine *) {};                        // FUN_00a4f7b4
	auto f796 = [](EditorEngine *) -> bool { return false; }; // FUN_00a4f796
	auto f0bf2 = [](EditorEngine *) {};                       // FUN_00a50bf2
	auto eb22 = [](EditorEngine *, int, int) -> bool { return false; };  // FUN_00a2eb22
	auto styleChanged = [](EditorEngine *) {};                // s_text_default (0x50b1a)

	switch (cmd) {
	case 0x833:  // SCI_AUTOCACTIVE family — bool via (engine,0,0)
		return QVariant(eb22(this, 0, 0));
	case 0x834:  // reset style +0x1238 then apply
		m_style = 0;
		(void)a.toULongLong();
		styleChanged(this);
		return QVariant(0);
	case 0x835:  // SCI_AUTOCCANCEL (repo-verified)
		f7b4(this);
		return QVariant(0);
	case 0x836:  // bool state probe
		return QVariant(f796(this));
	case 0x837:  // SCI_AUTOCPOSSTART (repo-verified)
		f0bf2(this);
		return QVariant(0);
	case 0x838:
		return QVariant(f982(this));
	case 0x839:
		return QVariant(f9ee());
	case 0x83a:
		return QVariant(face(this));
	case 0x83c:  // style pair write +0x123c
		m_stylePair = a.toInt();
		styleChanged(this);
		return QVariant(0);
	case 0x83d:
		return QVariant(m_stylePair);
	case 0x83e:  // +0x1240 target: optional object call w/ int arg
		if (m_ptr1240) {
			(void)a.toInt();
			// FUN_00955098(m_ptr1240, ...)
		}
		return QVariant(0);
	case 0x83f:
		return QVariant(m_ptr1240 ? 0 : 0);   // FUN_00955094 when set
	case 0x840:  // style write +0x1238
		m_style = a.toInt();
		styleChanged(this);
		return QVariant(0);
	case 0x898:  // run-style range (wparam=range start ll, lparam=ull)
		// runstyles_runnode_init(node, a.toLL, 0, 0); FUN_00a225be;
		// s_calltip_text (FUN_00a50850); node dtor FUN_0096bb02
		(void)b.toULongLong();
		(void)a.toLongLong();
		return QVariant(0);
	case 0x899:
		// FUN_00a74088(m_sub1148)
		return QVariant(0);
	case 0x89a:
		return QVariant(m_flag11e8);
	case 0x89b:
		return QVariant(m_pos11f0);
	case 0x89c:  // two-int op on +0x1148 (wparam from b, lparam from a)
		// FUN_00a740a0(m_sub1148, a.toInt(), b.toInt())
		(void)a.toInt(); (void)b.toInt();
		return QVariant(0);
	case 0x8a4:  // +0x1148 then soft view reset
		(void)a.toInt();
		// FUN_00a740c4(m_sub1148); session_view_soft_reset(this)
		return QVariant(0);
	case 0x8a5:  // +0x1148 then soft view reset (bool arg)
		(void)a.toBool();
		// FUN_00a740c8(m_sub1148); session_view_soft_reset(this)
		return QVariant(0);
	case 0x8a6:
		m_pos11f0 = a.toLongLong();
		return QVariant(0);
	case 0x7531:  // WT CMD_30001 discardAutoComplete
		// FUN_00a51780(this)
		return QVariant(0);
	case 0x7532:
		return QVariant(false);   // FUN_00a4f95e(this)
	default:
		return dispatchLevel2(cmd, a, b);
	}
}
