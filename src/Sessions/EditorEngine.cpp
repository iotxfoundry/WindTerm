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
	case 0x75ac:
		cmdGotoPosition(a.toLongLong());
		return QVariant(0);
	default:
		return QVariant(0);   // remaining ~329 leaves per the command table
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
