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
static long long docPosOp(void *doc, bool b)
{
	// FUN_00927a68 (16B) → FUN_009b413e(undo(doc+0xe8), b); tail call
	// leaves the result in RAX (callers read it as u64)
	return 0;
}
static bool docLineProbe1(void *doc, long long v)
{
	// FUN_00927ce0 (17B) → FUN_0099b5d6(markers(doc+0xf0), v, 1)
	return false;
}
static bool docLineProbe2(void *doc, long long v)
{
	// FUN_00927e22 (17B) → same marker op with kind 2
	return false;
}
static long long docLineGet(void *doc, long long v, unsigned f, int g) {
	// FUN_009252f4 (15B) → FUN_0099881e(*(doc+0xe0), v, f, g) — the
	// +0xe0 sub-object (196B callee) — wave-2
	(void)doc; (void)v; (void)f; (void)g; return 0; }  // 0x75a7 FUN_009252f4
static void eA26ec6(EditorEngine *e, unsigned long long line, int col) { (void)e; (void)line; (void)col; }  // 0x75ab gotoLine
static void eA1fd8c(EditorEngine *e, bool on) { (void)e; (void)on; }  // 0x7597 setMarginTrackChange
static void eA28e7c(EditorEngine *e, int base) { (void)e; (void)base; }  // 0x759a setHexBase
static void eA282b8(EditorEngine *e) { (void)e; }             // 0x75aa
static double eA2041e(EditorEngine *e) { (void)e; return 0; } // 0x75a9 (double read)

// SCI one-call thunks (level-2 SCI range bodies)
static void eA28a68(EditorEngine *e, unsigned long long a, long long b) { (void)e; (void)a; (void)b; }  // 0x7d1 scroll target
static void eA26756(EditorEngine *e) { (void)e; }             // 0x7d4 redraw
static long long docLength(void *doc)
{
	// FUN_0092801a (12B): *(ll*)(buffer(doc+0xf8) + 0x28)
	return *(long long *)(*(char **)((char *)doc + 0xf8) + 0x28);
}
static unsigned docCharAtLine(void *doc, long long line)
{
	// FUN_00926c8c (20B): gated by doc+0x98 sub-object, else 0;
	// the gate path calls FUN_00a04b28 (registers kept: doc, line)
	(void)line;
	if (*(void **)((char *)doc + 0x98) == nullptr)
		return 0;
	return 0;   // FUN_00a04b28(doc+0x98 chain, line) — wave-2
}
static void eA23b8c(EditorEngine *e, int v) { (void)e; (void)v; }  // 0x7db
static void eA26df4(EditorEngine *e) { (void)e; }             // 0x7dd
static void docOp927ddc(void *doc) { (void)doc; }             // 0x7de
static bool docGate927a4c(void *doc)
{
	// FUN_00927a4c (12B) → FUN_009b3f48(undo(doc+0xe8))
	return false;
}
static bool docFlag9290e8(void *doc)
{
	// FUN_009290e8 (8B): direct bool read at doc+0x132
	return *(bool *)((char *)doc + 0x132);
}
static bool docFlag927a24(void *doc)
{
	// FUN_00927a24 (12B) → FUN_009b3ef6(undo(doc+0xe8))
	return false;
}
static int styleTableGet(void *styleCtx, int i) { (void)styleCtx; (void)i; return 0; }  // 0x7e1 FUN_0094316a
static int styleAtPos(void *styleCtx, long long pos) { (void)styleCtx; (void)pos; return 0; }  // 0x7fe FUN_0094277a
static long long docOp92814a(void *doc) { (void)doc; return 0; }  // 0x7ec
static void eA1f7be(EditorEngine *e) { (void)e; }             // 0x7f8 chain
static void eA22c4e(EditorEngine *e, int n) { (void)e; (void)n; }  // 0x7f8 chain
static void styleCtxTouch(void *ctx) { (void)ctx; }           // FUN_009501b0 (e+8)
static int hitTestOffset(void *ctx) { (void)ctx; return 0; }   // FUN_0095019c (e+8)
static long long hitTestResolve(void *out)
{
	// FUN_0096bbc0 (5B): *(ll*)(holder + 8) — value slot of the
	// hit-test result holder
	return *(long long *)((char *)out + 8);
}
static void editorHitTest(double x, double y, void *out, EditorEngine *e,
                          int a, int b, int c) { (void)x; (void)y; (void)out; (void)e; (void)a; (void)b; (void)c; }  // editor_hitTest
static void docOp925c8c(void *doc, int v) { (void)doc; (void)v; }  // 0x7fd
static int docOp9251ea(void *doc, long long a, int b) { (void)doc; (void)a; (void)b; return 0; }  // 0x7ff
static int docOp92a2b2(void *doc, long a, int b) { (void)doc; (void)a; (void)b; return 0; }  // 0x7fb
static void docOp92a3fc(void *doc, int v) { (void)doc; (void)v; }  // 0x7e2
static void docOp927a30(void *doc, bool b)
{
	// FUN_00927a30 (16B) → FUN_009b3ef0(undo(doc+0xe8), b)
}

// ---------------------------------------------------------------------------
// GapBuffer / line-index layer: doc+0xf8 → buffer, buffer+8 → line index
// ---------------------------------------------------------------------------
static void *gapBufferOf(void *doc)
{
	// every FUN_009252xx wrapper derefs doc+0xf8 first
	return *(void **)((char *)doc + 0xf8);
}

static long long lineIndexAt(void *lineIdx, long long line)
{
	// FUN_00a62f52 (278B): lazy line-position lookup — empty index
	// (runs+0x10 == 0) recomputes; the atomic flag at +0x31 gates one
	// recompute while contenders spin: sched_yield up to 2 tries, then
	// nanosleep 100ns, then 10us; result =
	// runstyles_run_start_at(index+0x18 runs, position)
	(void)lineIdx; (void)line;
	return 0;
}

static long long gapLineCount(void *buf)
{
	// FUN_0098067a (9B) → FUN_00a629b6(index(buf+8))
	return 0;
}

static long long gapClampEol(void *buf, long long pos, long long end)
{
	// FUN_0098081e (77B): clamp so a position never splits a line
	// terminator — char reads via buffer vtable+0x28: "\n" then "\r"
	// before it → end-2 (CRLF); lone "\n" → end-1; "\r" → end-1
	typedef char (*CharAtFn)(void *, long long);
	CharAtFn charAt = *(CharAtFn *)(*(void ***)buf + 0x28 / 8);
	if (pos < end) {
		const long long last = end - 1;
		if (charAt(buf, last) == '\n') {
			if (charAt(buf, end - 2) == '\r')
				return end - 2;
			return last;
		}
		if (charAt(buf, last) == '\r')
			return last;
	}
	return end;
}

static long long gapLineEnd(void *buf, long long line)
{
	// FUN_0098086c (68B): lineIndexAt(index, line+1); when line is the
	// last line the result clamps EOL-aware via FUN_0098081e
	long long pos = lineIndexAt(*(void **)((char *)buf + 8), line + 1);
	if (gapLineCount(buf) - 1 <= line)
		pos = gapClampEol(buf, 0, pos);
	return pos;
}
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
static long long docOp92520c(void *doc, long long v)
{
	// FUN_0092520c (12B) → FUN_0098086c(gapBuf(doc+0xf8), v)
	return gapLineEnd(gapBufferOf(doc), v);
}
static long long editorLineEndIdx(void *obj, long long v) { (void)obj; (void)v; return 0; }  // 0x858 gated path
static bool docFlag9290e8b(void *doc) { (void)doc; return false; }  // 0x85c
static long long docOp92522a(void *doc, long long v) { (void)doc; (void)v; return 0; }  // 0x876 plain
static long long objRunStyleGet(void *obj, void *node) { (void)obj; (void)node; return 0; }  // 0x876 gated FUN_009587cc
static double eScrollSet(EditorEngine *e, void *node) { (void)e; (void)node; return 0; }  // 0x875 region FUN_00a225be (XMM out)
static void runNodeInit(void *node, long long start, int a, int b) { (void)node; (void)start; (void)a; (void)b; }  // runstyles_runnode_init
static void runNodeFree(void *node)
{
	// FUN_0096bb02 is literally a 1-byte `ret` — the "free" for these
	// runnodes is a no-op (storage is stack/frame-owned)
	(void)node;
}
static void eA20eb2(EditorEngine *e, void *anchor, void *caret, int sel) { (void)e; (void)anchor; (void)caret; (void)sel; }  // 0x870 set selection
static void editorSelCtor(void *sel, EditorEngine *e, int *type) { (void)sel; (void)e; (void)type; }  // editor_selCtor
static void editorSelDtor(void *sel) { (void)sel; }  // FUN_00974856
static void docOp927dbe(void *doc) { (void)doc; }  // 0x87f
static void eA25f72(EditorEngine *e) { (void)e; }  // 0x881
static void vtCall(EditorEngine *e, int slotOff) { (void)e; (void)slotOff; }  // engine vtable slot by offset
static void eA235ce(EditorEngine *e, long long a, int b) { (void)e; (void)a; (void)b; }  // 0x883 tail
static void editorSelMake(void *sel, EditorEngine *e, const char *mode, int a, int b) { (void)sel; (void)e; (void)mode; (void)a; (void)b; }  // 0x885
static void eA21110(EditorEngine *e, void *node, int a) { (void)e; (void)node; (void)a; }  // 0x885 tail

// SCI 0x8b2-0x92e thunks
static void objRangeSet(void *obj, long long a, long long b, int m) { (void)obj; (void)a; (void)b; (void)m; }  // 0x8b2/0x8b3 FUN_00958416
static void eA239ee(EditorEngine *e) { (void)e; }             // 0x8b2/0x8b3 chain
static bool objFlag95854c(void *obj) { (void)obj; return false; }  // 0x8bc
static bool objFlag95855e(void *obj, long long v) { (void)obj; (void)v; return false; }  // 0x8b4
static bool objFlag958b68(void *obj, long long v) { (void)obj; (void)v; return false; }  // 0x8b6
static void foldMgrSet(void *mgr, long long v, bool b) { (void)mgr; (void)v; (void)b; }  // 0x8b5 FUN_00a5ecb2
static void foldMgrLine2(void *mgr, long long line, int a, int b, int c) { (void)mgr; (void)line; (void)a; (void)b; (void)c; }  // 0x8b7/0x7571 FUN_00a5ed6e
static void *cursorPosGet(void *obj) { (void)obj; return nullptr; }  // FUN_00975bc6 (+0x1038)
static long long objPosOf(void *obj, void *cursor) { (void)obj; (void)cursor; return 0; }  // FUN_009587cc
static long long eA282a8(EditorEngine *e, long long a, int b, bool c) { (void)e; (void)a; (void)b; (void)c; return 0; }  // 0x8da/0x8db
static void eHa2aa22(EditorEngine *e, int v) { (void)e; (void)v; }  // 0x8d8
static bool eA169cc(void *obj, long long v) { (void)obj; (void)v; return false; }  // 0x8e2 (obj +0x10c8)
static void eA21d26(EditorEngine *e, long long a, long long b, int c) { (void)e; (void)a; (void)b; (void)c; }  // 0x8f1
static void insertAtEnd(EditorEngine *e, unsigned long long pos, long long extra) { (void)e; (void)pos; (void)extra; }  // 0x8ea FUN_00a287f8(-1,...)
static void eA218f6(EditorEngine *e, long long a, long long b) { (void)e; (void)a; (void)b; }  // 0x8f0
static long long editorTextLength(void *obj) { (void)obj; return 0; }  // editor_textLength (+0x10a0)
static long long objPosQuery(void *obj, long long pos) { (void)obj; (void)pos; return 0; }  // 0x92e FUN_00958498
static void eA2c222(EditorEngine *e) { (void)e; }             // 0x936 chain
static void sMarginNumber(EditorEngine *e) { (void)e; }       // s_margin_number
static void sMarginTimestamp(EditorEngine *e) { (void)e; }    // s_margin_timestamp
static bool styleZoomSet(void *styleCtx, int zoom) { (void)styleCtx; (void)zoom; return false; }  // FUN_009502a0
static void marginRecalc(EditorEngine *e) { (void)e; }       // FUN_00a23c7a
static void marginsTouch(EditorEngine *e) { (void)e; }        // s_margin_number + s_margin_timestamp wrapper
static void docOp92a49e(void *doc, long long a, int b) { (void)doc; (void)a; (void)b; }  // 0x9a2
static void duplicateLines(EditorEngine *e) { (void)e; }     // editor_duplicateLines (0x9a5)
static void docOp925d4c(void *doc, long long a, unsigned long long b) { (void)doc; (void)a; (void)b; }  // 0x9e2
static void docOp925e2a(void *doc, long long a, int b) { (void)doc; (void)a; (void)b; }  // 0x9e4
static void docOp925df0(void *doc) { (void)doc; }            // 0x9e8
static void caretChangeShape(EditorEngine *e, int shape) { (void)e; (void)shape; }  // caret_changeShape (0x753d)
static void eA204a0(EditorEngine *e, double d) { (void)e; (void)d; }  // 0x7541 FUN_00a204a0
static bool docCap8(void *doc) { (void)doc; return false; }  // 0x754f FUN_009305e6(doc, 8)
static void docFlag927dbe(void *doc) { (void)doc; }          // 0x7558 (FUN_00927dbe recalc)
static void eA29014(void *out, EditorEngine *e) { (void)out; (void)e; }  // 0x755e
static void eA2d648(EditorEngine *e, int v) { (void)e; (void)v; }  // 0x7563
static bool objRunStyleGet2(void *obj, void *node) { (void)obj; (void)node; return false; }  // 0x7576 FUN_0095c92c
static void editorGetSelRange(EditorEngine *e) { (void)e; }  // editor_getSelRange (0x7581)
static void eA28316(EditorEngine *e, int cmd) { (void)e; (void)cmd; }  // FUN_00a28316(e, cmd, sp)
static int docInt260(void *doc) { (void)doc; return 0; }    // *(int*)(doc+0x260) (0x7584)
static int hitTestAtPoint(EditorEngine *e, int x, int y) { (void)e; (void)x; (void)y; return 0; }  // 0x758f FUN_00a2a982
static int eA20430(EditorEngine *e) { (void)e; return 0; }  // 0x75ae FUN_00a20430
static void eA167ac2(void *obj, long long v) { (void)obj; (void)v; }  // 0x75b5 kind 2 (FUN_00a167ac)
static bool eA28fa8(EditorEngine *e) { (void)e; return false; }  // 0x75bf
static QRect posToRect(EditorEngine *e, long long pos) { (void)e; (void)pos; return QRect(); }  // 0x75d4 FUN_00a2267c
static int eA218dc(EditorEngine *e) { (void)e; return 0; }  // 0x75d9 FUN_00a218dc
static void eA245c6(EditorEngine *e, int cur, int v) { (void)e; (void)cur; (void)v; }  // 0x75d9 FUN_00a245c6
static QVariant eColorRead(EditorEngine *e, const QByteArray &key) { (void)e; (void)key; return QVariant(); }  // 0x75e6 "line.caret.remote"
static QPoint ePointMap(EditorEngine *e, const QPoint &p) { (void)e; (void)p; return QPoint(); }  // 0x75e9 FUN_00a2a002
static int ePointQuery(EditorEngine *e, const QPoint &p) { (void)e; (void)p; return 0; }  // 0x75eb FUN_00a2b7fc
static int eRunNodeQuery(EditorEngine *e, long long pos) { (void)e; (void)pos; return 0; }  // 0x75ec FUN_00a2a0ea
static QString eRunNodeText(EditorEngine *e, long long pos) { (void)e; (void)pos; return QString(); }  // 0x75ee FUN_00a2a15e
static void eA2a44a(EditorEngine *e) { (void)e; }            // 0x75f0
static void docOp929336(void *doc, long long v) { (void)doc; (void)v; }  // 0x75f4
static void eA2a504(EditorEngine *e, const QByteArray &b) { (void)e; (void)b; }  // 0x75f7
static void docOp927216(void *doc, const QByteArray &b) { (void)doc; (void)b; }  // 0x75fc FUN_00927216
// search/target text quadruplets (FUN_00a1fda6 / 00a1fe5a / 00a1ff9c /
// 00a20050 families): read value (holder+8), read length, or set at a
// position (runnode pos/len) — Scintilla target API shape
static void searchFlagsText(void *b, EditorEngine *e, int f) { (void)b; (void)e; (void)f; }   // FUN_00a1fda6
static void searchRangeText(void *b, EditorEngine *e, int f) { (void)b; (void)e; (void)f; }   // FUN_00a1fe5a
static void searchFlagsText2(void *b, EditorEngine *e, int f) { (void)b; (void)e; (void)f; }  // FUN_00a1ff9c
static void searchRangeText2(void *b, EditorEngine *e, int f) { (void)b; (void)e; (void)f; }  // FUN_00a20050
static int qstrdataLength(void *b) { (void)b; return 0; }    // qstrdata_length_get
static void insertRange(EditorEngine *e, int f, void *n) { (void)e; (void)f; (void)n; }       // FUN_00a1fdd8
static void setRangeNode(EditorEngine *e, int f, void *n) { (void)e; (void)f; (void)n; }      // FUN_00a1fe8c
static void insertRange2(EditorEngine *e, int f, void *n) { (void)e; (void)f; (void)n; }      // FUN_00a1ff9c tail
static void insertRange3(EditorEngine *e, int f, void *n) { (void)e; (void)f; (void)n; }      // FUN_00a20082
static void selRangeMake(void *out, void *a, void *b, int m) { (void)out; (void)a; (void)b; (void)m; }  // FUN_0096be24
static void selRangeApply(EditorEngine *e, void *r) { (void)e; (void)r; }  // FUN_00a20fb0
static void selRangeFree(void *r) { (void)r; }               // FUN_0096bd50
static void eA2373a(EditorEngine *e, int v) { (void)e; (void)v; }  // 0xa0e
static QVariant vtForward150(EditorEngine *e, uint cmd, const QVariant &a, const QVariant &b)
{ (void)e; (void)cmd; (void)a; (void)b; return QVariant(0); }  // vtable+0x150 pass-through


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
	// SCI 0x8b2-0x92e block
	case 0x8b2:
		objRangeSet(m_obj10a0, a.toLongLong(), b.toLongLong(), 1);
		eA239ee(this);
		vtA0Repaint();
		return QVariant(0);
	case 0x8b3:
		objRangeSet(m_obj10a0, a.toLongLong(), b.toLongLong(), 0);
		eA239ee(this);
		vtA0Repaint();
		return QVariant(0);
	case 0x8b4:
		return QVariant(objFlag95855e(m_obj10a0, a.toLongLong()));
	case 0x8b5:
		foldMgrSet(m_foldMgr, a.toLongLong(), b.toBool());
		return QVariant(0);
	case 0x8b6:
		return QVariant(!objFlag958b68(m_obj10a0, a.toLongLong()));
	case 0x8b7: {
		long long line = a.toLongLong();
		if (line == -1)
			line = objPosOf(m_obj10a0, cursorPosGet(m_obj1038));
		foldMgrLine2(m_foldMgr, line, 1, 2, b.toInt());
		return QVariant(0);
	}
	case 0x8bc:
		return QVariant(objFlag95854c(m_obj10a0));
	case 0x8d8:
		eHa2aa22(this, a.toInt());
		return QVariant(0);
	case 0x8d9:
		return QVariant(m_intF44);
	case 0x8da:
		return QVariant(eA282a8(this, a.toLongLong(), -1, b.toBool()));
	case 0x8db:
		return QVariant(eA282a8(this, a.toLongLong(), 1, b.toBool()));
	case 0x8e2:  // on success clears bit0 of the object's +0x50 flags
		if (eA169cc(m_obj10c8, a.toLongLong()))
			*(unsigned char *)((char *)m_obj10c8 + 0x50) &= 0xfe;
		return QVariant(0);
	case 0x8e3:  // inferred: +0x10c8 object's +0x40 read
		return QVariant(*(long long *)((char *)m_obj10c8 + 0x40));
	case 0x8f1: {
		const QVariantList args = a.toList();
		if (args.size() != 3)
			return QVariant(0);
		eA21d26(this, args.at(0).toLongLong(), args.at(1).toLongLong(),
		        args.at(2).toInt());
		return QVariant(0);
	}
	case 0x8ea:  // insert at document end (-1 anchor)
		insertAtEnd(this, a.toULongLong(), b.toLongLong());
		return QVariant(0);
	case 0x8f0:
		eA218f6(this, a.toLongLong(), b.toLongLong());
		return QVariant(0);
	case 0x92e: {  // char width: pos+1 offset minus pos offset
		const long long pos = a.toLongLong();
		if (pos < 0 || pos >= editorTextLength(m_obj10a0))
			return QVariant(0);
		return QVariant(objPosQuery(m_obj10a0, pos + 1) - objPosQuery(m_obj10a0, pos));
	}
	case 0x936:  // margin number/timestamp width recalc (vt+0x148 guard)
		// if vtable+0x148 != FUN_00a1e438 → call it
		eA2c222(this);
		sMarginNumber(this);
		sMarginTimestamp(this);
		return QVariant(0);
	case 0x914:  // ranges 0x914-0x91a, 0x91d-0x91f, 0x924-0x928 forward
	case 0x915:
	case 0x916:
	case 0x917:
	case 0x918:
	case 0x919:
	case 0x91a:
	case 0x91d:
	case 0x91e:
	case 0x91f:
	case 0x924:
	case 0x925:
	case 0x926:
	case 0x927:
	case 0x928:
		return vtForward150(this, cmd, a, b);
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
		return dispatchLevel2Generated(cmd, a, b);
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
// Generated coverage tail (tools/re/gen_editor_cmds.py --cpp): every
// remaining leaf of FUN_00a418c4. Simple leaves route through t_call
// with the impl address in the case comment; complex leaves carry the
// address list for a later hand pass; member writes map known offsets.
// ---------------------------------------------------------------------------
static QVariant t_call(const char *impl, EditorEngine *e,
                       const QVariant &a, const QVariant &b)
{
	// reference dispatch: impl names the engine-internal function
	(void)impl; (void)e; (void)a; (void)b;
	return QVariant();
}

QVariant EditorEngine::dispatchLevel2Generated(uint cmd, const QVariant &a,
                                               const QVariant &b)
{
	switch (cmd) {
	case 0x7d6:  // SCI 2006: shared tail (LAB_00a45135) = document length
		return QVariant(docLength(m_doc));
	case 0x7fc:  // SCI 2044: FUN_0092a356, args toInt, toLongLong
		return t_call("t_0092a356", this, a, b);
	case 0x801: {  // packed style table, u64 value variant of 0x7f8
		const unsigned slot = a.toUInt();
		if (slot < 0x20) {
			// FUN_00a4e234(this + slot*0xb + 8, a.toULongLong())
			styleCtxTouch(m_styleCtx);
			eA1f7be(this);
			eA22c4e(this, 4);
		}
		return QVariant(0);
	}
	case 0x865:  // read sibling of the 0x864 write: +0xea8
		return QVariant(m_intEa8);
	case 0x869: {  // getLine text: pos -1 -> cursor line, slice line..line+1
		long long pos = a.toLongLong();
		if (pos == -1)
			pos = docOp92522a(m_doc,
			                  hitTestResolve(cursorPosGet(m_obj1038)));
		// FUN_00925200(doc, pos) and (doc, pos+1) bound the slice
		// buf_substr + typed QVariant(int, buf, 0) — wave-2
		(void)pos;
		return QVariant(0);
	}
	case 0x86b: {  // change-detect +0xd4c write then soft reset
		// if (*(int*)(this+0xd4c) != a.toInt()) { write; reset }
		(void)a;
		sessionViewSoftReset(this);
		return QVariant(0);
	}
	case 0x86f:  // FUN_00927a58(doc, 0) != 0
		return QVariant(false);
	case 0x867:  // SCI 2151: FUN_00a223e8, args toBool, toULongLong
		return t_call("t_00a223e8", this, a, b);
	case 0x86a:  // SCI 2154: FUN_00925570 + editor_textLength + soft reset
		return QVariant(0);
	case 0x874:  // X coordinate of a position: scroll double minus
		// *(int*)(this+0xd7c) plus *(int*)(this+0xd74) corrections
		// (runnode(pos) -> FUN_00a225be, scroll-set sibling) — wave-2
		return QVariant(0);
	case 0x877:  // line start: FUN_00925200(doc, line) + FUN_00958498
		return QVariant(0);
	case 0x879:  // SCI 2169: FUN_00a2913a, args no args
		return t_call("t_00a2913a", this, a, b);
	case 0x87a:  // SCI 2170: FUN_00a25808, args toULongLong, toInt
		return t_call("t_00a25808", this, a, b);
	case 0x87b:  // SCI 2171: +0x132 flag write (FUN_009290f0)
		return QVariant(0);
	case 0x87d:  // engine vtable +0x110 -> bool
		return QVariant(false);
	case 0x87e:  // FUN_00927a40 + FUN_009290e8 flag pair
		return QVariant(0);
	case 0x880:  // SCI 2176: FUN_00a23b58, args toInt
		return t_call("t_00a23b58", this, a, b);
	case 0x887:  // SCI 2183: same shared tail — FUN_0092801a
		return QVariant(docLength(m_doc));
	case 0x8e4:  // SCI 2276: FUN_00a3028e, args toULongLong
		return t_call("t_00a3028e", this, a, b);
	case 0x933:  // read +0xd8c
		return QVariant(m_flagD8c);
	case 0x934:  // write +0xd8c, change-detect + vtable+0xa0 repaint
		if (m_flagD8c != a.toBool()) {
			m_flagD8c = a.toBool();
			vtA0Repaint();
		}
		return QVariant(0);
	case 0x945:  // zoom set: FUN_009502a0(engine+8, n); margins recalc +
		// soft reset on change
		if (styleZoomSet(m_styleCtx, a.toInt()))
			marginRecalc(this);
		marginsTouch(this);
		sessionViewSoftReset(this);
		return QVariant(0);
	case 0x946:  // SCI 2374: FUN_00950294, args toInt
		return t_call("t_00950294", this, a, b);
	case 0x94c:  // SCI 2380: FUN_00a2d544, args toBool
		return t_call("t_00a2d544", this, a, b);
	case 0x950:  // write +0xec4
		m_flagEc4 = a.toBool();
		return QVariant(0);
	case 0x951:  // read +0xec4
		return QVariant(m_flagEc4);
	case 0x952:  // write +0xed8 + vtable+0x160(1)
		m_intEd8 = a.toInt();
		vtCall(this, 0x160);
		return QVariant(0);
	case 0x953:  // read +0xed8
		return QVariant(m_intEd8);
	case 0x961:  // EXT 2401: FUN_00a233b8, args no args
		return t_call("t_00a233b8", this, a, b);
	case 0x966:  // write +0xeac
		m_intEac = a.toInt();
		return QVariant(0);
	case 0x967:  // read +0xeac
		return QVariant(m_intEac);
	case 0x971:  // EXT 2417: FUN_009252f4, args toLongLong
		return t_call("t_009252f4", this, a, b);
	case 0x972:  // EXT 2418: FUN_009252f4, args toLongLong
		return t_call("t_009252f4", this, a, b);
	case 0x973:  // EXT 2419: FUN_00a2c5c8, args toLongLong
		return t_call("t_00a2c5c8", this, a, b);
	case 0x974:  // EXT 2420: FUN_00a2fdc6, args toInt, toULongLong
		return t_call("t_00a2fdc6", this, a, b);
	case 0x975:  // EXT 2421: session_view_soft_reset, args toBool
		return t_call("t_session_view_soft_reset", this, a, b);
	case 0x998:  // EXT 2456: FUN_009286d4, args toLongLong
		return t_call("t_009286d4", this, a, b);
	case 0x9a2:  // doc + toLL(a), toInt(b) -> FUN_0092a49e
		docOp92a49e(m_doc, a.toLongLong(), b.toInt());
		return QVariant(0);
	case 0x9a3:  // write +0x1058 low byte
		m_int1058 = a.toBool();
		return QVariant(0);
	case 0x9a4:  // read +0x1058
		return QVariant(m_int1058);
	case 0x9a5:  // editor_duplicateLines(engine, 0)
		duplicateLines(this);
		return QVariant(0);
	case 0x9c1:  // read +0xd48
		return QVariant(m_intD48);
	case 0x9d4:  // +0x10c8 obj +0x57 bit5 set
		if (m_obj10c8)
			*(unsigned char *)((char *)m_obj10c8 + 0x57) =
			    (unsigned char)(*(unsigned char *)((char *)m_obj10c8 + 0x57) & 0xdf | (a.toBool() ? 1 : 0) << 5);
		return QVariant(0);
	case 0x9d5:  // +0x10c8 obj +0x57 bit5 read
		return QVariant(m_obj10c8 && (*(unsigned char *)((char *)m_obj10c8 + 0x57) >> 5 & 1));
	case 0x9e1: {  // packed style table READ (32 slots, 11B stride)
		const unsigned slot = a.toUInt();
		return QVariant(slot < 0x20 ? *(int *)((char *)m_styleCtx + slot * 0xb) : 0);
	}
	case 0x9e2:  // doc + toLL(a), toULL(b) -> FUN_00925d4c
		docOp925d4c(m_doc, a.toLongLong(), b.toULongLong());
		return QVariant(0);
	case 0x9e3:  // std::string return (s_text_default_92565a)
		return QVariant(0);
	case 0x9e4:  // doc + toLL(a), toInt(b) -> FUN_00925e2a
		docOp925e2a(m_doc, a.toLongLong(), b.toInt());
		return QVariant(0);
	case 0x9e5:  // std::string return (s_text_default sibling)
		return QVariant(0);
	case 0x9e8:  // doc -> FUN_00925df0
		docOp925df0(m_doc);
		return QVariant(0);
	case 0x9fc: {  // select-to-position: runnode(pos) -> FUN_00a21110(e,node,0)
		char n1[64];
		runNodeInit(n1, a.toLongLong(), 0, 0);
		eA21110(this, n1, 0);
		runNodeFree(n1);
		return QVariant(0);
	}
	case 0xa01: {  // position from point, mode (0,1,1)
		char out[32];
		editorHitTest(a.toDouble() - hitTestOffset(m_styleCtx), b.toDouble(),
		              out, this, 0, 1, 1);
		return QVariant(hitTestResolve(out));
	}
	case 0xa02: {  // position from point, mode (1,1,1)
		char out[32];
		editorHitTest(a.toDouble() - hitTestOffset(m_styleCtx), b.toDouble(),
		              out, this, 1, 1, 1);
		return QVariant(hitTestResolve(out));
	}
	case 0xa0a:  // EXT 2570: FUN_00a1fc2e, args no args
		return t_call("t_00a1fc2e", this, a, b);
	case 0xa0c: {  // setSelection(anchor a, caret b): dual runnode
		char nA[64], nB[64], out[64];
		runNodeInit(nB, b.toLongLong(), 0, 0);
		runNodeInit(nA, a.toLongLong(), 0, 0);
		selRangeMake(out, nA, nB, 0);      // FUN_0096be24
		selRangeApply(this, out);           // FUN_00a20fb0
		runNodeFree(nA); runNodeFree(nB); selRangeFree(out);
		return QVariant(0);
	}
	case 0xa0e:  // FUN_00a2373a(engine, int)
		eA2373a(this, a.toInt());
		return QVariant(0);
	case 0xa10: {  // insert text at position (len from flags buf)
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64], n1[64];
		searchFlagsText(buf, this, flags);   // FUN_00a1fda6
		runNodeInit(n1, b.toLongLong(), qstrdataLength(buf), 0);
		insertRange(this, flags, n1);        // FUN_00a1fdd8
		runNodeFree(n1); runNodeFree(buf);
		return QVariant(0);
	}
	case 0xa11: {  // target text value
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64];
		searchFlagsText(buf, this, flags);
		const long long v = hitTestResolve(buf);
		runNodeFree(buf);
		return QVariant(v);
	}
	case 0xa12: {  // set search text at position (len from buf)
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64], n1[64];
		searchRangeText(buf, this, flags);   // FUN_00a1fe5a
		runNodeInit(n1, b.toLongLong(), qstrdataLength(buf), 0);
		setRangeNode(this, flags, n1);       // FUN_00a1fe8c
		runNodeFree(n1); runNodeFree(buf);
		return QVariant(0);
	}
	case 0xa13: {  // search-range text value
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64];
		searchRangeText(buf, this, flags);
		const long long v = hitTestResolve(buf);
		runNodeFree(buf);
		return QVariant(v);
	}
	case 0xa15: {  // target text length
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64];
		searchFlagsText(buf, this, flags);
		const int len = qstrdataLength(buf);
		runNodeFree(buf);
		return QVariant(len);
	}
	case 0xa17: {  // search-range text length
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64];
		searchRangeText(buf, this, flags);
		const int len = qstrdataLength(buf);
		runNodeFree(buf);
		return QVariant(len);
	}
	case 0xa18: {  // set range text at position (FUN_00a1ff9c family)
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64], n1[64];
		searchFlagsText2(buf, this, flags);  // FUN_00a1ff9c
		runNodeInit(n1, b.toLongLong(), qstrdataLength(buf), 0);
		insertRange2(this, flags, n1);       // FUN_00a1ff9c tail
		runNodeFree(n1); runNodeFree(buf);
		return QVariant(0);
	}
	case 0xa19: {  // range text value (FUN_00a1ff9c read)
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64];
		searchFlagsText2(buf, this, flags);
		const long long v = hitTestResolve(buf);
		runNodeFree(buf);
		return QVariant(v);
	}
	case 0xa1a: {  // set range text at position (FUN_00a20050 family)
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64], n1[64];
		searchRangeText2(buf, this, flags);  // FUN_00a20050
		runNodeInit(n1, b.toLongLong(), qstrdataLength(buf), 0);
		insertRange3(this, flags, n1);       // FUN_00a20082
		runNodeFree(n1); runNodeFree(buf);
		return QVariant(0);
	}
	case 0xa1e: {  // target+position variant (FUN_00a20050 -> runnode)
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64], n1[64];
		searchRangeText2(buf, this, flags);
		runNodeInit(n1, hitTestResolve(buf), b.toInt(), 0);
		insertRange3(this, flags, n1);
		runNodeFree(n1); runNodeFree(buf);
		return QVariant(0);
	}
	case 0xa1f: {  // range text length (FUN_00a20050)
		int flags = -1;
		if (a.canConvert(QMetaType::Type::Int))
			flags = a.toInt();
		char buf[64];
		searchRangeText2(buf, this, flags);
		const int len = qstrdataLength(buf);
		runNodeFree(buf);
		return QVariant(len);
	}
	case 0xa20:  // EXT 2592: FUN_00a1ff24, args toInt
		return t_call("t_00a1ff24", this, a, b);
	case 0xa21:  // EXT 2593: FUN_00a1ff0e, args toInt
		return t_call("t_00a1ff0e", this, a, b);
	case 0xa24:  // EXT 2596: FUN_00a203ca, args toBool
		return t_call("t_00a203ca", this, a, b);
	case 0xa25:  // EXT 2597: FUN_00a203be, args no args
		return t_call("t_00a203be", this, a, b);
	case 0xa3e:  // EXT 2622: member write +0x21b (unmapped)
		return QVariant(0);
	case 0xa3f:  // EXT 2623: complex leaf (inline) — hand pass pending
		return QVariant(0);
	case 0xa40:  // EXT 2624: member write +0x1d2 (unmapped)
		return QVariant(0);
	case 0xa41:  // EXT 2625: member write +0x1d3 (unmapped)
		return QVariant(0);
	case 0xa42:  // EXT 2626: complex leaf (FUN_00a4e2e4 FUN_009501b0 FUN_00a1f7be) — hand pass pending
		return QVariant(0);
	case 0xa47:  // EXT 2631: complex leaf (inline) — hand pass pending
		return QVariant(0);
	case 0xa49:  // EXT 2633: FUN_00925352, args toLongLong
		return t_call("t_00925352", this, a, b);
	case 0xa55:  // EXT 2645: FUN_0092c1ba, args toLongLong
		return t_call("t_0092c1ba", this, a, b);
	case 0xa5a:  // EXT 2650: FUN_00a20248, args no args
		return t_call("t_00a20248", this, a, b);
	case 0xa5b:  // EXT 2651: member write +0x1d4 (unmapped)
		return QVariant(0);
	case 0xbb9:  // EXT 3001: member write +0x208 (unmapped)
		return QVariant(0);
	case 0xbba:  // EXT 3002: member write +0x208 (unmapped)
		return QVariant(0);
	case 0x4e23:  // EXT 20003: FUN_00a4d0e2, args no args
		return t_call("t_00a4d0e2", this, a, b);
	case 0x4e25:  // EXT 20005: FUN_00a24866, args toLongLong
		return t_call("t_00a24866", this, a, b);
	case 0x4e26:  // EXT 20006: editor_checkAutoFormat, args no args
		return t_call("t_editor_checkAutoFormat", this, a, b);
	case 0x4e27:  // EXT 20007: complex leaf (FUN_009cff30 FUN_0092d76e FUN_009cff96) — hand pass pending
		return QVariant(0);
	case 0x4e28:  // EXT 20008: FUN_00930ec0, args no args
		return t_call("t_00930ec0", this, a, b);
	case 0x4e2e:  // EXT 20014: editor_indentLines, args toLongLong
		return t_call("t_editor_indentLines", this, a, b);
	case 0x4e2f:  // EXT 20015: editor_indentLines, args toLongLong
		return t_call("t_editor_indentLines", this, a, b);
	case 0x4e37:  // EXT 20023: editor_trimLineBlanks, args toLongLong
		return t_call("t_editor_trimLineBlanks", this, a, b);
	case 0x4e38:  // EXT 20024: editor_trimLineBlanks, args toLongLong
		return t_call("t_editor_trimLineBlanks", this, a, b);
	case 0x4e49:  // EXT 20041: editor_commentSel, args no args
		return t_call("t_editor_commentSel", this, a, b);
	case 0x4e4a:  // EXT 20042: editor_commentSel, args no args
		return t_call("t_editor_commentSel", this, a, b);
	case 0x4e4c:  // EXT 20044: complex leaf (FUN_00a38c56 editor_commentSel) — hand pass pending
		return QVariant(0);
	case 0x4e75:  // EXT 20085: complex leaf (FUN_00951844 FUN_00959890 s_margin_number_a302fe) — hand pass pending
		return QVariant(0);
	case 0x4e8c:  // EXT 20108: FUN_00a5ebb0, args no args
		return t_call("t_00a5ebb0", this, a, b);
	case 0x4ebb:  // EXT 20155: complex leaf (FUN_00927600 FUN_009276d6 session_view_soft_reset) — hand pass pending
		return QVariant(0);
	case 0x4ebc:  // EXT 20156: FUN_009276e2, args no args
		return t_call("t_009276e2", this, a, b);
	case 0x4ec2:  // EXT 20162: FUN_00926e6a, args no args
		return t_call("t_00926e6a", this, a, b);
	case 0x4ec3:  // EXT 20163: FUN_00926e76, args toLongLong
		return t_call("t_00926e76", this, a, b);
	case 0x4ec5:  // EXT 20165: member write +0x20c (unmapped)
		return QVariant(0);
	case 0x4ed4:  // EXT 20180: FUN_00a20266, args no args
		return t_call("t_00a20266", this, a, b);
	case 0x4ee8:  // EXT 20200: FUN_00a1fc18, args no args
		return t_call("t_00a1fc18", this, a, b);
	case 0x4ee9:  // EXT 20201: FUN_00a28d1e, args toByteArray
		return t_call("t_00a28d1e", this, a, b);
	case 0x4eeb:  // EXT 20203: FUN_009257a8, args no args
		return t_call("t_009257a8", this, a, b);
	case 0x4eed:  // EXT 20205: complex leaf (FUN_009257f0 FUN_009257b4 FUN_0092582a) — hand pass pending
		return QVariant(0);
	case 0x4eef:  // EXT 20207: FUN_00928454, args toInt
		return t_call("t_00928454", this, a, b);
	case 0x4ef0:  // EXT 20208: FUN_0093499e, args toInt
		return t_call("t_0093499e", this, a, b);
	case 0x4ef1:  // EXT 20209: FUN_0093493e, args toInt
		return t_call("t_0093493e", this, a, b);
	case 0x4ef2:  // EXT 20210: FUN_0093496e, args toInt
		return t_call("t_0093496e", this, a, b);
	case 0x4ef3:  // EXT 20211: FUN_00a2e858, args toULongLong, toBool
		return t_call("t_00a2e858", this, a, b);
	case 0x4ef5:  // EXT 20213: editor_getSelRange, args no args
		return t_call("t_editor_getSelRange", this, a, b);
	case 0x4ef8:  // EXT 20216: FUN_00a28424, args no args
		return t_call("t_00a28424", this, a, b);
	case 0x4ef9:  // EXT 20217: FUN_00a28388, args no args
		return t_call("t_00a28388", this, a, b);
	case 0x4efa:  // EXT 20218: FUN_00926c6e, args no args
		return t_call("t_00926c6e", this, a, b);
	case 0x4efb:  // EXT 20219: FUN_00926d1a, args no args
		return t_call("t_00926d1a", this, a, b);
	case 0x4efd:  // EXT 20221: complex leaf (FUN_00926dfc FUN_00926da0 FUN_00a2919c) — hand pass pending
		return QVariant(0);
	case 0x4eff:  // EXT 20223: editor_replaceAll, args toULongLong
		return t_call("t_editor_replaceAll", this, a, b);
	case 0x4f00:  // EXT 20224: editor_replaceText, args toULongLong
		return t_call("t_editor_replaceText", this, a, b);
	case 0x4f01:  // EXT 20225: FUN_00a28662, args no args
		return t_call("t_00a28662", this, a, b);
	case 0x4f02:  // EXT 20226: FUN_00a2f82a, args toByteArray
		return t_call("t_00a2f82a", this, a, b);
	case 0x4f04:  // EXT 20228: FUN_00a20104, args no args
		return t_call("t_00a20104", this, a, b);
	case 0x7533:  // WT 30003: member write +0x21d (unmapped)
		return QVariant(0);
	case 0x7535:  // WT 30005: FUN_00a30d26, args toInt
		return t_call("t_00a30d26", this, a, b);
	case 0x7536:  // WT 30006: FUN_00a23d26, args toULongLong
		return t_call("t_00a23d26", this, a, b);
	case 0x7537:  // WT 30007: clears the doc flag byte at doc+0x240
		*(unsigned char *)((char *)m_doc + 0x240) = 0;
		return QVariant(0);
	case 0x7538:  // WT 30008: FUN_00a24126, args toULongLong
		return t_call("t_00a24126", this, a, b);
	case 0x753a:  // WT 30010: doc map set — FUN_0092ed32(doc, a.toMap())
		// then qmap_freetree_variant_nodes frees the map tree
		// (map fetch path hand pass pending)
		return QVariant(0);
	case 0x753c:  // WT 30012: FUN_00a297c6, args no args
		return t_call("t_00a297c6", this, a, b);
	case 0x753d:  // WT 30013: caret_changeShape(engine, shape int)
		// — the King::CaretShape setter path
		caretChangeShape(this, a.toInt());
		return QVariant(0);
	case 0x753e:  // WT 30014: FUN_00a417fe, args toDouble
		return t_call("t_00a417fe", this, a, b);
	case 0x753f:  // WT 30015: engine vtable +0xc0, no args
		vtCall(this, 0xc0);
		return QVariant(0);
	case 0x7541:  // WT 30017: FUN_00a204a0(engine) after toDouble(a)
		eA204a0(this, a.toDouble());
		return QVariant(0);
	case 0x7545:  // WT 30021: FUN_00933366, args toULongLong, toString
		return t_call("t_00933366", this, a, b);
	case 0x754d:  // WT 30029: FUN_0092e44e, args no args
		return t_call("t_0092e44e", this, a, b);
	case 0x754f:  // WT 30031: FUN_009305e6(doc, 8) — capability 8 probe
		return QVariant(docCap8(m_doc));
	case 0x7553:  // WT 30035: byte slice from start — buf_substr(doc,
		// a.toLL()) + typed QVariant(int, buf, 0) via FUN_00a4b6df
		// (custom metatype bytes result; b's toLL feeds the same chain)
		return QVariant(0);
	case 0x7558:  // WT 30040: hex/read-only mode toggle — readonly guard
		// (FUN_00927a24) then FUN_00927dbe/00927ebc/00927be6 recalc
		// chain + redraw (FUN_00a26756); the else branch mirrors with
		// FUN_00927a30(doc,0)/(doc,1) bracketing
		docFlag927dbe(m_doc);
		eA26756(this);
		return QVariant(0);
	case 0x755b:  // WT 30043: FUN_00927f16, args toBool
		return t_call("t_00927f16", this, a, b);
	case 0x755e: {  // WT 30046: FUN_00a29014(&holder, engine) -> +8 value
		char out[32];
		eA29014(out, this);
		return QVariant(hitTestResolve(out));
	}
	case 0x7563:  // WT 30051: FUN_00a2d648(engine, a.toInt())
		eA2d648(this, a.toInt());
		return QVariant(0);
	case 0x7565:  // WT 30053: FUN_009284aa, args toLongLong
		return t_call("t_009284aa", this, a, b);
	case 0x7566:  // WT 30054: FUN_0093079a, args toLongLong
		return t_call("t_0093079a", this, a, b);
	case 0x7567: {  // WT 30055: fractional zoom (toReal) — change-detect
		// against +0xd10, then FUN_00959890(+0x10a0, -1), margin recalc
		// chain, soft reset
		const double z = a.toReal();
		if (z != (double)m_zoomReal) {
			m_zoomReal = (long)z;
			marginRecalc(this);
			marginsTouch(this);
			sessionViewSoftReset(this);
		}
		return QVariant(0);
	}
	case 0x7568:  // WT 30056: shared_ptr reset cluster at +0xda8..+0xdb8 —
		// FUN_008ddd50(this+0xda0, +0xdb0), then +0xdb0 zeroed and
		// +0xdb8 repointed to +0xdb0 (FUN_0069eb30/00a4bb6a tails)
		return QVariant(0);
	case 0x756a:  // WT 30058: member write +0x1b3 (unmapped)
		return QVariant(0);
	case 0x756c:  // WT 30060: member write +0x227 (unmapped)
		return QVariant(0);
	case 0x756d:  // WT 30061: registered-variant marker family —
		// variant_convertRegistered3(a) → FUN_00925c02(doc, val, 1),
		// then a 4-element list from b drives the tail (FUN_0092671c)
		return QVariant(0);
	case 0x756e:  // WT 30062: same convert+FUN_00925c02(doc, val, 1) head,
		// different tail call — marker variant 2
		return QVariant(0);
	case 0x7572:  // WT 30066: FUN_00a5ed6e, args toLongLong
		return t_call("t_00a5ed6e", this, a, b);
	case 0x7573:  // WT 30067: FUN_00a5e952, args toLongLong
		return t_call("t_00a5e952", this, a, b);
	case 0x7575:  // WT 30069: FUN_00a5ed6e, args toBool, toLongLong
		return t_call("t_00a5ed6e", this, a, b);
	case 0x7576: {  // WT 30070: runnode(a.toLL()) → FUN_0095c92c(+0x10a0,
		// node) → bool; a true result triggers the vtable+0xa0 repaint
		char n1[64];
		runNodeInit(n1, a.toLongLong(), 0, 0);
		const bool hit = objRunStyleGet2(m_obj10a0, n1);
		runNodeFree(n1);
		if (hit)
			vtA0Repaint();
		return QVariant(hit);
	}
	case 0x7578:  // WT 30072: FUN_00a21b1e, args no args
		return t_call("t_00a21b1e", this, a, b);
	case 0x757c:  // WT 30076: doc+0x1f8 bool write (the +0x1f8 read sits
		// in the 0x757a region)
		*(bool *)((char *)m_doc + 0x1f8) = a.toBool();
		return QVariant(0);
	case 0x757d: {  // WT 30077: word-under-cursor scan — line bounds via
		// FUN_00925200/0092520c, chars via FUN_009284aa, stops on
		// ':' / '.' delimiters (URL/path detection shape)
		const long long line = a.toLongLong();
		// wordStart = FUN_00925200(doc, line); wordEnd =
		// FUN_0092520c(doc, line); scan for ':'/'.' — hand pass pending
		(void)line;
		return QVariant(0);
	}
	case 0x757f:  // WT 30079: FUN_00a38936, args toLongLong, toULongLong
		return t_call("t_00a38936", this, a, b);
	case 0x7581:  // WT 30081: +0xd90 flag (sibling of the 0x7583 +0xd92)
		// — off: FUN_00a28316(e, 7, null shared_ptr) + release;
		// on: editor_getSelRange(e)
		m_flagD90 = a.toBool();
		if (m_flagD90)
			editorGetSelRange(this);
		else
			eA28316(this, 7);
		return QVariant(0);
	case 0x7584:  // WT 30084: read *(int*)(doc+0x260) — code-view index
		return QVariant(docInt260(m_doc));
	case 0x7586:  // WT 30086: member write +0x1b1 (unmapped)
		return QVariant(0);
	case 0x7588:  // WT 30088: complex leaf (FUN_009588b8 FUN_00a53be6) — hand pass pending
		return QVariant(0);
	case 0x758a:  // WT 30090: FUN_00a3a3ee (map/string chain) — hand pass pending
		return QVariant(0);
	case 0x758b:  // WT 30091: +0xd8d bool change-detect write + repaint
		if (m_flagD8d != a.toBool()) {
			m_flagD8d = a.toBool();
			vtA0Repaint();
		}
		return QVariant(0);
	case 0x758c:  // WT 30092: session_view_soft_reset, args toFloat
		return t_call("t_session_view_soft_reset", this, a, b);
	case 0x758d:  // WT 30093: FUN_00927ea8, args toBool, toLongLong
		return t_call("t_00927ea8", this, a, b);
	case 0x758f: {  // WT 30095: hit-test by QPoint — toPoint unpacks
		// (x low, y high) then FUN_00a2a982(engine, x/y pair) -> int
		const QPoint pt = a.toPoint();
		return QVariant(hitTestAtPoint(this, pt.x(), pt.y()));
	}
	case 0x7592:  // WT 30098: session_view_soft_reset, args toStringList
		return t_call("t_session_view_soft_reset", this, a, b);
	case 0x7593:  // WT 30099: member write +0x1ae (unmapped)
		return QVariant(0);
	case 0x7594: {  // WT 30100: remove margin by name — walks the
		// +0xd58 node list, FUN_005445c4 name match, FUN_00a4bc60 unlink
		// (guarded by +0xd88 [0x1ae] enabled flag and a non-empty list)
		return QVariant(0);
	}
	case 0x7595:  // WT 30101: clear the whole margin list — zeroes
		// +0xd58/+0xd60/+0xd68 and releases each 24-byte node, then
		// soft reset (FUN_00952088 tail)
		m_marginBegin = nullptr;
		m_marginEnd = nullptr;
		sessionViewSoftReset(this);
		return QVariant(0);
	case 0x7598:  // WT 30104: reads the +0x1128 coordinate-mode gate
		return QVariant(m_gate1128);
	case 0x7599: {  // WT 30105: +0xd8e bool change-detect write;
		// repaint only when the +0x1128 gate is set
		if (m_flagD8e != a.toBool()) {
			m_flagD8e = a.toBool();
			if (m_gate1128)
				vtA0Repaint();
		}
		return QVariant(0);
	}
	case 0x759c: {  // WT 30108: +0xd94 int change-detect write; repaint
		// only when the +0x1128 gate is set
		const int v = a.toInt();
		if (m_intD94 != v) {
			m_intD94 = v;
			if (m_gate1128)
				vtA0Repaint();
		}
		return QVariant(0);
	}
	case 0x759e:  // WT 30110: FUN_00a30c2e, args toBool
		return t_call("t_00a30c2e", this, a, b);
	case 0x759f:  // WT 30111: FUN_00926e08, args no args
		return t_call("t_00926e08", this, a, b);
	case 0x75a0: {  // WT 30112: line-from-position with cursor default —
		// pos -1 resolves via +0x1038 cursor chain and clamps with max()
		long long pos = a.toLongLong();
		if (pos == -1) {
			const long long cursor = hitTestResolve(cursorPosGet(m_obj1038));
			const long long lineEnd = docOp928404(m_doc,
			                                       docOp92522a(m_doc, cursor));
			pos = lineEnd > cursor ? lineEnd : cursor;
		}
		// FUN_00926e52(doc, pos, &out) -> low-32 line — thunk pending
		(void)pos;
		return QVariant(0);
	}
	case 0x75a1:  // WT 30113: FUN_00926e3e, args toUInt
		return t_call("t_00926e3e", this, a, b);
	case 0x75a3: {  // WT 30115: select line range — toUInt(a) resolves a
		// position pair via FUN_00926e1c(doc, uint, &pos64), builds two
		// runnodes + FUN_0096be24 range, applies FUN_00a58d66 on
		// +0x10b0 with command 7
		// thunk chain pending
		return QVariant(0);
	}
	case 0x75a5:  // WT 30117: FUN_00a2d3ec, args toBool
		return t_call("t_00a2d3ec", this, a, b);
	case 0x75a6:  // WT 30118: FUN_00a5940a, args toString, toLongLong
		return t_call("t_00a5940a", this, a, b);
	case 0x75a8:  // WT 30120: FUN_00a21576, args no args
		return t_call("t_00a21576", this, a, b);
	case 0x75ad:  // WT 30125: FUN_00a20438, args no args
		return t_call("t_00a20438", this, a, b);
	case 0x75ae:  // WT 30126: FUN_00a2b0a2(engine) then FUN_00a20430 -> int
		return QVariant(eA20430(this));
	case 0x75b4:  // WT 30132: FUN_00a2398e, args toInt
		return t_call("t_00a2398e", this, a, b);
	case 0x75b5: {  // WT 30133: dual-mode op on +0x10c8 — kind 1 calls
		// FUN_00a169cc(obj, b.toLL()), kind 2 calls FUN_00a167ac
		const int kind = a.toInt();
		if (kind == 1)
			eA169cc(m_obj10c8, b.toLongLong());
		else if (kind == 2)
			eA167ac2(m_obj10c8, b.toLongLong());
		return QVariant(0);
	}
	case 0x75b6:  // WT 30134: FUN_00a36e40, args no args
		return t_call("t_00a36e40", this, a, b);
	case 0x75bb:  // WT 30139: FUN_00a2eee0, args no args
		return t_call("t_00a2eee0", this, a, b);
	case 0x75bc:  // WT 30140: FUN_00a28efe, args toBool
		return t_call("t_00a28efe", this, a, b);
	case 0x75bd:  // WT 30141: FUN_00a2f09a, args toByteArray
		return t_call("t_00a2f09a", this, a, b);
	case 0x75bf:  // WT 30143: FUN_00a28fa8(engine) -> bool
		return QVariant(eA28fa8(this));
	case 0x75c1:  // WT 30145: tab size READ — *(int*)(doc+0x270)
		// (the write side is 0x75c4)
		return QVariant(*(int *)((char *)m_doc + 0x270));
	case 0x75c8:  // WT 30152: FUN_0092759a, args toLongLong
		return t_call("t_0092759a", this, a, b);
	case 0x75cd:  // WT 30157: editor_textLength(+0x10a0) -> ll;
		// the 0x75ce sibling is editor_lineEndIdx(+0x10a0, a.toLL())
		return QVariant(editorTextLength(m_obj10a0));
	case 0x75d0:  // WT 30160: FUN_00a2059c, args toPoint
		return t_call("t_00a2059c", this, a, b);
	case 0x75d1: {  // WT 30161: position query — runnode(a.toLL()) →
		// FUN_009587cc(+0x10a0, node) -> ll
		char n1[64];
		runNodeInit(n1, a.toLongLong(), 0, 0);
		const long long v = objRunStyleGet(m_obj10a0, n1);
		runNodeFree(n1);
		return QVariant(v);
	}
	case 0x75d2:  // WT 30162: FUN_00958498, args toLongLong
		return t_call("t_00958498", this, a, b);
	case 0x75d4:  // WT 30164: position -> QRect (FUN_00a2267c); the
		// 0x75d3 sibling takes a QPoint (FUN_00a2b4d0)
		return QVariant(posToRect(this, a.toLongLong()));
	case 0x75d7:  // WT 30167: reads +0xde0 ([0x1bc])
		return QVariant(m_flagDe0);
	case 0x75d8:  // ? 30168: FUN_00a218dc, args no args
		return t_call("t_00a218dc", this, a, b);
	case 0x75d9: {  // ? 30169: FUN_00a245c6(e, FUN_00a218dc(e), a.toInt())
		eA245c6(this, eA218dc(this), a.toInt());
		return QVariant(0);
	}
	case 0x75db: {  // ? 30171: +0xde0 change-detect write + soft reset
		if (m_flagDe0 != a.toBool()) {
			m_flagDe0 = a.toBool();
			sessionViewSoftReset(this);
		}
		return QVariant(0);
	}
	case 0x75dd:  // ? 30173: line from the +0x1068 holder position —
		// FUN_0092522a(doc, *(holder+8))
		return QVariant(docOp92522a(m_doc, hitTestResolve(m_holder1068)));
	case 0x75de:  // ? 30174: FUN_0096bbc0, args no args
		return t_call("t_0096bbc0", this, a, b);
	case 0x75df:  // ? 30175: qstrdata_length of the +0x1068 holder
		return QVariant(qstrdataLength(m_holder1068));
	case 0x75e0: {  // ? 30176: QPolygon unpack — userType 0x43, six
		// values read from constData for a geometry op
		return QVariant(0);
	}
	case 0x75e2:  // ? 30178: reads +0x1083
		return QVariant(m_flag1083);
	case 0x75e4:  // ? 30180: FUN_00a2cea8, args toBool
		return t_call("t_00a2cea8", this, a, b);
	case 0x75e5:  // ? 30181: FUN_00a3175e, args no args
		return t_call("t_00a3175e", this, a, b);
	case 0x75e6: {  // ? 30182: color readout — "line.caret.remote" key
		// short-circuits to a QColor when +0xedc is non-zero; otherwise
		// the key builds a std::string and walks FUN_0095021a/styleAt
		return eColorRead(this, a.toByteArray());
	}
	case 0x75e7:  // ? 30183: FUN_00a29fa8, args toPoint
		return t_call("t_00a29fa8", this, a, b);
	case 0x75e9:  // ? 30185: point transform — FUN_00a2a002 -> QPoint
		return QVariant(ePointMap(this, a.toPoint()));
	case 0x75eb:  // ? 30187: FUN_00a2b7fc, args toPoint
		return t_call("t_00a2b7fc", this, a, b);
	case 0x75ec: {  // ? 30188: runnode(a.toLL()) -> FUN_00a2a0ea -> int
		char n1[64];
		runNodeInit(n1, a.toLongLong(), 0, 0);
		const int v = eRunNodeQuery(this, a.toLongLong());
		runNodeFree(n1);
		return QVariant(v);
	}
	case 0x75ed:  // ? 30189: FUN_00a2b854, args toInt, toPoint
		return t_call("t_00a2b854", this, a, b);
	case 0x75ee: {  // ? 30190: runnode(a.toLL()) -> FUN_00a2a15e -> QString
		char n1[64];
		runNodeInit(n1, a.toLongLong(), 0, 0);
		const QString s = eRunNodeText(this, a.toLongLong());
		runNodeFree(n1);
		return QVariant(s);
	}
	case 0x75f0:  // ? 30192: FUN_00a2a44a (the 0x75f1 sibling is the
		// +0x1082 change-detect + FUN_009502de(engine+8) + soft reset)
		eA2a44a(this);
		return QVariant(0);
	case 0x75f2:  // ? 30194: reads *(ll*)(doc+0x160)
		return QVariant(*(long long *)((char *)m_doc + 0x160));
	case 0x75f3:  // ? 30195: reads *(ll*)(doc+0x158)
		return QVariant(*(long long *)((char *)m_doc + 0x158));
	case 0x75f4:  // ? 30196: FUN_00929336, args toLongLong
		return t_call("t_00929336", this, a, b);
	case 0x75f5:  // ? 30197: FUN_00925ae4, args toInt
		return t_call("t_00925ae4", this, a, b);
	case 0x75f7:  // ? 30199: FUN_00a2a504(engine, a.toByteArray())
		eA2a504(this, a.toByteArray());
		return QVariant(0);
	case 0x75f9:  // ? 30201: FUN_00927170, args no args
		return t_call("t_00927170", this, a, b);
	case 0x75fa:  // ? 30202: FUN_00a2a6e6, args toBool, toLongLong
		return t_call("t_00a2a6e6", this, a, b);
	case 0x75fb:  // ? 30203: FUN_00a2a6e6, args toBool, toLongLong
		return t_call("t_00a2a6e6", this, a, b);
	case 0x75fc:  // ? 30204: margin timestamp set — FUN_00927216(doc,
		// bytes) then s_margin_timestamp recalc
		docOp927216(m_doc, a.toByteArray());
		sMarginTimestamp(this);
		return QVariant(0);
	case 0x75fe:  // ? 30206: doc's +0x298 QByteArray assign
		// (the 0x75fd sibling is FUN_009271be(doc, ll))
		*(QByteArray *)((char *)m_doc + 0x298) = a.toByteArray();
		return QVariant(0);
	case 0x75ff:  // ? 30207: FUN_009271e4, args toLongLong
		return t_call("t_009271e4", this, a, b);
	default:
		return QVariant(0);
	}
}

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
