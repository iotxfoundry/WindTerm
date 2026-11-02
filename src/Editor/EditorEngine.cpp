#include <QCollator>
#include <QDataStream>
#include <QFontMetrics>
#include <QLineF>
#include <QPainter>
#include <QRegularExpression>
#include <QPixmap>
#include <QLocale>
#include <cstring>
#include "EditorEngine.h"

#include "CodecMemo.h"   // 批 91:ReplaceOp codec 缓存面(0089a0a0/0089a756/00899316)

#include "ScintillaEditBase.h"
#include "Scintilla.h"
#include "Ext/ZstdFace.h"   // EXT-BOUNDARY 声明面(zstd 委托;调用点待链接)

// HYBRID EditorEngine: standard SCI_* delegates to real Scintilla
// (src/Scintilla static libs); WindTerm EXT/WT stays in customDispatch.

struct RetEntry { unsigned cmd; char kind; };

static const RetEntry scintilla_returns[] =
{
#include "scintilla_returns.inc"

};

// DAT_011c1a60+0x20 QList 全局注册表(a66ae8 kind==8 腿消费;
//   FUN_006994e0(36B)@decomp-0021.c:23985 = QList::at 越界安全取
//   项;生产者未读 — r7 残留)→ 空表承载,at 恒越界返 0 同相
//   — cited — wave-2
static QVector<void *> s_grep_reg_1a60;   // DAT_011c1a60 占位

// 批 91:ReplaceOp codec 缓存面承载(CodecMemo;语料 op 体 +0x48/+0x58/
// +0x60 三缓存 + +0x08 自旋锁,布局对位见 CodecMemo.h。宿主桥 op 对象
// 不承载我方缓存 → 文件级 static 承载替,批 81 s_grep_reg_1a60 先例;
// 语料 op 级生命期 → 进程级,单会话单线程同相 — 登记)
static CodecMemo s_codecMemo;
static const void *s_grep_reg_at_6994e0(const QVector<void *> &list,
                                         int si)
{
	if (si < 0 || si >= list.size())     // 006994f2 门
		return nullptr;                  //   → 0(0069950a)
	return list.at(si);                  // *(+0x10+(begin+si)*8)
}

// —— 批 99 R2:word 跳步基元族(0x4f00 段 8/跳选腿真身化;语料
//   FUN_00925304 thunk@0030:20331 → 009988e2(176B@0032:28889)±1
//   走读,逐字基元即本族)——
// FUN_009284aa(13B)@0030:24371 — byteAt(doc,pos)(vt 委托:13B 全读
//   (**(doc+0xf8) vt+0x28)(pos))— docBytes 承接(越界读 = 0 同相)
static int s_byteAt_009284aa(const EditorContext &ctx, qint64 pos)
{
	return (pos < 0 || pos >= ctx.docBytes.size())
	    ? 0 : quint8(ctx.docBytes.at(int(pos)));
}

// FUN_0092801a(12B)@0030:23968 — doc 长度面(*(doc+0xf8)+0x28)
//   — docBytes 承接(本文件 2869 行既定适配)
static qint64 s_docLen_0092801a(const EditorContext &ctx)
{
	return ctx.docBytes.size();
}

// FUN_00a840fc(108B)@0035:993 — 游标单步推进:*(cnv+0x18)==1(单字节
//   codec)直返(语料 985/998 早退);else 00B434A0(vt+0x90,18B)+
//   00A840E6(21B)跨界重对齐 — cited — wave-2(多字节 codec 族)。
//   docBytes 单字节承载 → 直返同相
static qint64 s_cursorAdvance_00a840fc(const EditorContext &ctx, qint64 pos,
                                       bool fwd)
{
	Q_UNUSED(ctx); Q_UNUSED(fwd);
	return pos;                          // 语料 985/1000
}

// FUN_00a84168(79B)@0035:1015 — 游标单步回退(语料 6-17 全读:
//   ==1 → pos-1 clamp0;else advance(pos)<1 → 0,else advance(pos-1))
static qint64 s_cursorBack_00a84168(const EditorContext &ctx, qint64 pos)
{
	const qint64 p = s_cursorAdvance_00a840fc(ctx, pos, false);  // 14
	if (p < 1)                                                   // 15-16
		return 0;
	return s_cursorAdvance_00a840fc(ctx, p - 1, false);          // 17
}

// FUN_009975de(59B)@0032:27874 — \r\n 尾判定(语料 5-9 全读)
static bool s_isCrlfAt_009975de(const EditorContext &ctx, qint64 pos)
{
	if (s_byteAt_009284aa(ctx, pos) != '\r')          // 5-7
		return false;
	return s_byteAt_009284aa(ctx, pos + 1) == '\n';   // 8-9
}

// FUN_00998678(298B)@0032:28760 — 词类宽度:首字节门(28762)
//   ASCII → 0(28848 早退);≥0x80 → cnv[0] 多字节宽度表查
//   (28764-28846:QArrayData 分配/00997560 锁/0099948a 查,
//   *hit+0x10 宽度)— 表面 cited — wave-2 → 0(单字节承载同相)
static int s_wordClass_00998678(const EditorContext &ctx, qint64 pos)
{
	const int b = s_byteAt_009284aa(ctx, pos);        // 28762
	if (char(b) < '\0')                               // 28764 多字节臂
		return 0;                                     //   表查 cited → 0
	return 0;                                         // 28848 ASCII 早退
}

// FUN_0099881e(196B)@0032:28849 — 词跳步基元(语料全读;param_4 由
//   调面 FUN_009252f4/00925304 恒 1 → true)
static qint64 s_wordStep_0099881e(const EditorContext &ctx, qint64 pos,
                                  int dir)
{
	qint64 p = s_cursorAdvance_00a840fc(ctx, pos, dir > 0);  // 28858
	int w = s_wordClass_00998678(ctx, p);                    // 28859
	while (w != 0) {                                         // 28860
		while (dir > 0) {                                    // 28861 前向连跳
			p += w;                                          // 28862
			w = s_wordClass_00998678(ctx, p);                // 28863
			if (w == 0)                                      // 28864
				goto done;                                   //   → 28895
		}
		p = s_cursorBack_00a84168(ctx, p);                   // 28868
		w = s_wordClass_00998678(ctx, p);                    // 28869
	}
done:
	qint64 r = p;                                            // 28896
	if (s_isCrlfAt_009975de(ctx, p - 1)) {                   // 28897-28898
		r = p - 1;                                           // 28899
		if (dir > 0)                                         //   0<param_3
			r = p + 1;
	}
	const qint64 len = s_docLen_0092801a(ctx);               // 28903
	if (r >= len)                                            // 28904-28905
		r = len;
	if (r < 0)                                               // 28907-28908
		r = 0;
	return r;                                                // 28910
}

// FUN_00a66ae8(1031B)@decomp-0034.c:43589 — 批 81 骨架 → 批 84 升级 B
//   (r7 §3:特殊路径 4 条已解,009c8bf2 唯一余 cited;fillRect 色槽
//   按推断转写,asm spot check 未做 — 登记待测)。批 83:自 0x753e
//   drawLineBody 存照位提为文件级 static(机械搬移,地址注释原样;
//   捕获 view/m_ctx → 参数)。真调用面 = s_line_modified_a72ad6
//   @49784-49787 四连(case 0x7547 S5)。
// T 表 = a72ad6@49613-49630 栈帧五指针帧双胞胎{scale=pixH,
//   denom=textLength, x0=rowH, rect 槽(fillRect 聚合,
//   坐标序 b1b §4), W/3 列偏移} + arg[4]=int* wrap
static void s_grep_bands_a66ae8(EditorContext &ctx, QPainter &view,
                                int kind, int colKind, const char *styleKey,
                                double pixH, qint64 denom, double rowH,
                                double w3, int wrap)
{
	struct GrepFrameT {            // T0 五指针帧局部值模型
		double scale;              // T[0] *T[0] = pixH
		qint64 denom;              // T[1] *T[1] = textLength
		double rowH;               // T[2] *T[2] = x0
		double w3;                 // T[4] *T[4] = W/3
	} T{pixH, denom, rowH, w3};
	Q_UNUSED(wrap);                // arg[4]:958498 推进腿用
	// ① FUN_009258b2(*(ed+8),kind,0) margin 行对象(185B
	//   全读)— M 行对象表未建模 → 占位 nullptr → 段尾
	//   return(00a66b07;壳期同相 = 0x7547 S5 ① 登记款)
	//   — cited — wave-2
	const void *M = nullptr;
	if (M == nullptr)
		return;
	// ② 默认绿 {0,0xffff,0}(00a66b0e;u16 通道)。fillRect 色源 =
	//   本链色(local_78);arg[1] 槽解引用在语料呈指针位型(Ghidra
	//   聚合噪声;双胞胎 a72ad6 S4 fillRect 色源 = 链上色同构)→
	//   按推断转写,asm spot check 未做 — 登记待测(批 84 择推断)
	QColor color(0, 255, 0);   // 原始槽 {0,0xffff,0}(u16 通道)
	// ③ 特判门(00a66b31):kind==6 ‖ colKind==8 →
	//   selection/styleIdx 色链;否则直达 band 迭代
	if (kind == 6 || colKind == 8) {
		// ③a FUN_00a20248(17B)@decomp-0033.c:57881 =
		//   00974d18(*(ed+0x1038),1)(134B 全读 @0032:1804):
		//   extras 五控制字 chunked 走查(0x38 步进跨段步进),
		//   逐项 FUN_00974b5e 有效性门(未读),全过返 1。session
		//   级 store 未建模 → 空表承载(写侧未接线恒空 → 走查恒
		//   true,同相;QVector 等价替,r7 §1c 怪癖)
		const QVector<quint64> sessionSel;
		for (const quint64 it : sessionSel) {
			// FUN_00974b5e(store,it,1)==0 → false — cited — wave-2
			Q_UNUSED(it);
		}
		// ③b FUN_00a1fda6(49B)@decomp-0033.c:57594 = a1fc3a(ed,-1)
		//   (scintilla_get_text_range — cited)→ 0096bfd4(+8) 取
		//   现选区 pos 节点 → SelPos 24B 拷{packed,absIdx,xy};
		//   FUN_0096bbc0(=*(+8))即现选区 abs。a1fc3a 未转写 →
		//   占位 −1(无选区)— cited — wave-2
		const qint64 selAbs = -1;       // 0096bbc0(&local_58)@00a66d22
		Q_UNUSED(selAbs);
		// ③c 9275ec(19B)@0030:23018 = M→0096d5e6(53B:spinlock
		//   +0x70 + 注记 deque 查)doc-pos→区间 pos — M 注记
		//   deque 未建模 → 占位 0 — cited — wave-2;
		//   9275ae(21B)@0030:22987 = 0096d19a(21B 全读 @0031:
		//   42365)— 真身化:(flag&7)==0 → −1,否则 (flag>>3)−1
		const quint32 noteFlag = 0;     // 9275ec(*(ed+8),M,selAbs) 占位
		const int styleIdx = (noteFlag & 0xfffffff8u) != 0
		    ? int(noteFlag >> 3) - 1 : -1;    // 0096d19a
		if (styleIdx == -1)
			return;           // 00a66e17(FUN_0096bb02 1B no-op)
		// ③d def 四槽优先链(00a66e1f-00a66e8x)。kind==6:
		//   926b1c(12B)@0030:21938 → 009c8bf2 样式定义表查
		//   (r7 唯一余 cited)→ def 占位 nullptr — cited —
		//   wave-2;kind==8:6994e0 取项 e,def = *(int**)
		//   (*(e+0x18)+0x18)(00a66e3x)
		const int *def = nullptr;
		if (kind == 6) {
			// def = FUN_00926b1c(*(ed+8),styleIdx) — cited — wave-2
		} else if (colKind == 8) {
			const void *e =
			    s_grep_reg_at_6994e0(s_grep_reg_1a60, styleIdx);
			if (e != nullptr) {
				const void *slot = *reinterpret_cast<
				    void *const *>(static_cast<const char *>(e)
				                       + 0x18);
				if (slot != nullptr)
					def = *reinterpret_cast<int *const *>(
					    static_cast<const char *>(slot)
					        + 0x18);
			}
		}
		if (def != nullptr) {
			// 槽序(00a66e2x 原样):def[4]→def[0]→def[8]→全零
			//   显式 {0,0xffff,0};命中槽 k → QColor u16 通道
			//   {def[k],def[k+1],def[k+2],(u16)def[k+3]}(模型
			//   8-bit 钳位,不可达路径通道宽损失登记回填)
			const int *q = nullptr;
			if (def[4] != 0)
				q = def + 4;
			else if (def[0] != 0)
				q = def + 0;
			else if (def[8] != 0)
				q = def + 8;
			if (q != nullptr)
				color = QColor(qMin(q[0], 0xff), qMin(q[1], 0xff),
				               qMin(q[2], 0xff), qMin(q[3], 0xff));
			else
				color = QColor(0, 255, 0);   // 全零显式(原样)
		}
		// ③e band = 927472(*(ed+8),M,0,noteFlag)(29B→0096d0e2
		//   178B 已读:M 注记 deque 未建模)→ 占位 {-1,-1}
		//   — cited — wave-2;FUN_0096bb02(&local_58) 1B no-op
	} else {
		// band = 927472(*(ed+8),M,0,0)(00a66b55 路径;同上)
		//   → 占位 {-1,-1} — cited — wave-2
	}
	const qint64 bandFrom = -1;    // auVar15._0_8_ 占位
	if (bandFrom == -1)
		return;                    // 00a66b91-00a66ba5
	// ④ styleKey 门控(00a66b98):色 r==0 → styleLookup
	//   (styleKey)→ editor_styleAt(u,0) 覆盖;仍 r==0 →
	//   return(仅门控不入 fillRect,r7 §3)— styleTable
	//   QHash 占位(登记回填)
	if (color.red() == 0) {        // local_78[0]==0 字面
		const QColor sc = ctx.styleTable.value(
		    QLatin1String(styleKey));
		if (sc.isValid())
			color = sc;
		if (color.red() == 0)
			return;
	}
	// ⑤ 命中带 do-loop(00a66ba5-00a66ed3)— band 迭代 cited
	//   后不可达;T 表消费 + y 带公式按语料转写存照:
	do {
		// runnode_init(lo/hi)→9587cc(runstyles)=abs 行
		//   (159B 已读;hex 形态分支 009584d0 cited)→
		//   占位 0 — cited — wave-2
		const qint64 lnA = 0, lnB = 0;
		// y 带公式(00a66bc9-00a66bf1;双胞胎 a72ad6
		//   local_d8..c0 同构,全程可读):
		double y0 = (double(lnA) * T.scale) / double(T.denom);
		double y1 = (double(lnB) * T.scale) / double(T.denom);
		double cap = T.scale - T.rowH;         // local_50
		if (y0 <= cap)                         // y0 = min(lo·H/L,
			cap = y0;                          //   H−rowH)
		double yy = T.rowH + cap;              // rowH + y0
		if (yy <= y1)                          // y1 = max(rowH+y0,
			yy = y1;                           //   hi·H/L)
		if (yy <= T.scale)                     // min(y1, H)
			T.scale = yy;                      //   (scale 槽复用,原样)
		const double h = T.scale - cap;        // local_40−local_50
		// fillRect(T[3] rect 槽 = QRectF{0, y0, W3, h};
		//   坐标序 b1b §4 / 双胞胎 local_d8..c0 同构;色源 =
		//   ② 链色 — 按推断转写,asm check 未做 — 登记待测)
		view.fillRect(0.0, cap, T.w3, h, color);
		// 下一命中:958498(buf,(hi/wrap+1)*wrap,hi%wrap)→
		//   927472(*(ed+8),M,from,0)— cited — wave-2
		//   (占位 -1 哨兵 → 收循环)
	} while (false);
}

EditorEngine::EditorEngine()
	: m_edit(new ScintillaEditBase)
{
}

EditorEngine::~EditorEngine() { delete m_edit; }

QVariant EditorEngine::scintillaDelegate(uint cmd, const QVariant &a,
                                         const QVariant &b)
{
	// numeric-first marshalling; text params marshal through UTF-8
	// buffers kept alive for the send call
	QByteArray a8, b8;
	uptr_t w = 0;
	sptr_t l = 0;
	if (a.isValid()) {
		if (a.type() == QVariant::String) { a8 = a.toString().toUtf8(); w = (uptr_t)a8.constData(); }
		else if (a.type() == QVariant::ByteArray) { a8 = a.toByteArray(); w = (uptr_t)a8.constData(); }
		else w = static_cast<uptr_t>(a.toLongLong());
	}
	if (b.isValid()) {
		if (b.type() == QVariant::String) { b8 = b.toString().toUtf8(); l = (sptr_t)b8.data(); }
		else if (b.type() == QVariant::ByteArray) { b8 = b.toByteArray(); l = (sptr_t)b8.data(); }
		else l = static_cast<sptr_t>(b.toLongLong());
	}
	const sptr_t r = m_edit->send(cmd, w, l);
	const RetEntry *p = scintilla_returns;
	for (; p->cmd; ++p) {
		if (p->cmd != cmd)
			continue;
		switch (p->kind) {
		case 'b': return QVariant(r != 0);
		case 'p':
		case 'i': return QVariant(static_cast<int>(r));
		case 't': return QVariant(QByteArray(reinterpret_cast<const char *>(r)));
		default:  return QVariant(0);
		}
	}
	return QVariant(static_cast<long long>(r));
}

QVariant EditorEngine::dispatch(uint cmd, const QVariant &a, const QVariant &b)
{
	// standard SCI_* -> real Scintilla; WindTerm EXT/WT -> custom layer
	if (cmd >= 20163)   // EXT 20163-20228 / WT 30001-30166
		return customDispatch(cmd, a, b);
	return scintillaDelegate(cmd, a, b);
}

QVariant EditorEngine::charRectAt(long long pos)
{
	// FUN_00a2267c 适配:x=字符起始像素,y=行×行高,w=字符宽,h=行高;
	// run 宽度内部(FUN_00a225be/00a2240a)cited
	const long long line = m_edit->send(SCI_LINEFROMPOSITION, pos, 0);
	const int x = (int)m_edit->send(SCI_POINTXFROMPOSITION, 0, pos);
	const int x2 = (int)m_edit->send(SCI_POINTXFROMPOSITION, 0, pos + 1);
	const int lineH = qMax(1, (int)m_edit->send(SCI_TEXTHEIGHT, 0, 0));
	return QVariant(QRect(x, (int)(line * lineH), x2 - x, lineH));
}

QVariant EditorEngine::colAt(long long pos)
{
	// FUN_00a2a0ea:列 = 视图调整(009588b8 行内游走 cited → 列适配)+
	//  pos>textLength 补差(原样比较)- 模式选 +0x148/+0x158
	const long long line = m_edit->send(SCI_LINEFROMPOSITION, pos, 0);
	long long col = pos - m_edit->send(SCI_POSITIONFROMLINE, line, 0);
	if (col < 0)
		col = 0;
	const long long tl = m_edit->send(SCI_GETLENGTH, 0, 0);
	if (pos - tl > 0)
		col += pos - tl;
	col -= (long long)(m_ctx.hexMode ? m_ctx.bufField148 : m_ctx.bufField158);
	return QVariant((int)col);
}

QVariant EditorEngine::textUpTo(long long pos)
{
	// FUN_00a2a15e:buf_substr(缓冲起点, node.pos) → UTF-8;
	// 起点链 0092522a/00925200 cited → 行首适配
	if (pos < 0)
		return QVariant(QString());
	const long long line = m_edit->send(SCI_LINEFROMPOSITION, pos, 0);
	const long long start = m_edit->send(SCI_POSITIONFROMLINE, line, 0);
	const long long n = pos - start;
	if (n <= 0)
		return QVariant(QString());
	QByteArray buf((int)n + 1, 0);
	Sci_TextRange tr;
	tr.chrg.cpMin = (Sci_PositionCR)start;
	tr.chrg.cpMax = (Sci_PositionCR)pos;
	tr.lpstrText = buf.data();
	m_edit->send(SCI_GETTEXTRANGE, 0, (sptr_t)&tr);
	return QVariant(QString::fromUtf8(buf.constData()));
}

QVariant EditorEngine::customDispatch(uint cmd, const QVariant &a,
                                      const QVariant &b)
{
	// WindTerm 扩展命令(EXT 20163-20228 / WT 30001-30166)。
	// 逆向语义(EDITOR-ENGINE-COMMANDS.md)经真 Scintilla 公共 API 实现;
	// 无上游等价的 fork 特性按文档桩保留。
	auto send = [this](uint msg, uptr_t w = 0, sptr_t l = 0) {
		return m_edit->send(msg, w, l);
	};
	switch (cmd) {
	// --- 文本 ---
	case 0x7551: {   // appendText(0x75ab 变体;w=长度 l=文本)
		QByteArray t = a.toByteArray();
		send(SCI_ADDTEXT, t.size(), (sptr_t)t.constData());
		return QVariant(0);
	}
	case 0x7554: {   // subString(start,end) = SCI_GETTEXTRANGE
		const long long s = a.toLongLong(), e = b.toLongLong();
		Sci_TextRange tr;
		tr.chrg.cpMin = (Sci_PositionCR)s;
		tr.chrg.cpMax = (Sci_PositionCR)e;
		QByteArray out(e - s + 1, 0);
		tr.lpstrText = out.data();
		send(SCI_GETTEXTRANGE, 0, (sptr_t)&tr);
		return QVariant(QByteArray(out.constData(), e - s));
	}
	case 0x757e: {   // indexOf(5参列表: pattern/start/end/options/nth)
		const QVariantList args = a.toList();
		if (args.size() < 5)
			return QVariant(0);
		const QByteArray pat = args.at(0).toString().toUtf8();
		send(SCI_SETSEARCHFLAGS,
		     (args.at(3).toInt() & 1 ? SCFIND_MATCHCASE : 0) |
		     (args.at(3).toInt() & 2 ? SCFIND_REGEXP : 0) |
		     (args.at(3).toInt() & 4 ? SCFIND_WHOLEWORD : 0));
		send(SCI_SETTARGETRANGE, args.at(1).toLongLong(), args.at(2).toLongLong());
		int nth = qMax(1, args.at(4).toInt());
		sptr_t pos = -1;
		for (int i = 0; i < nth; ++i) {
			pos = send(SCI_SEARCHINTARGET, pat.size(), (sptr_t)pat.constData());
			if (pos < 0)
				return QVariant((long long)-1);
			send(SCI_SETTARGETRANGE, pos + 1, args.at(2).toLongLong());
		}
		// 命中:nth 项的 start/end(与二进制结果形状一致)
		QVariantMap m;
		m["start"] = (long long)pos;
		m["end"] = (long long)send(SCI_GETTARGETEND);
		return QVariant(m);
	}
	// --- 导航 ---
	case 0x75ab:     // gotoLine(line u64 in a, column int in b)
		send(SCI_GOTOLINE, a.toULongLong());
		return QVariant(0);
	case 0x75ac:     // gotoPosition
		send(SCI_GOTOPOS, a.toLongLong());
		return QVariant(0);
	// --- 选择 ---
	case 0x75b8: {   // selectionText(sep, useSep) = SCI_GETSELTEXT
		const int len = (int)send(SCI_GETSELTEXT, 0, 0);
		QByteArray buf(len + 1, 0);
		send(SCI_GETSELTEXT, 0, (sptr_t)buf.data());
		return QVariant(QString::fromUtf8(buf.constData()));
	}
	case 0x7571: {   // FUN_00a5ed6e(fold,line,1,0,flag):mode0=ec00 族
	                 // (与 0x756f 同体;flag=展开位;父行解析 param_3=1)
		const long long line = a.toLongLong();
		const long long parent = send(SCI_GETFOLDPARENT, line, 0);
		send(SCI_FOLDLINE, parent < 0 ? line : parent,
		     b.toBool() ? SC_FOLDACTION_EXPAND : SC_FOLDACTION_CONTRACT);
		return QVariant(0);
	}
	case 0x7572: {   // FUN_00a5ed6e(…,1,2,0):mode2=按状态 toggle
	                 // (disp 00a5f0a2:bVar2==8→ec00 / 0xc→e952)
		const long long line = a.toLongLong();
		const long long parent = send(SCI_GETFOLDPARENT, line, 0);
		send(SCI_TOGGLEFOLD, parent < 0 ? line : parent, 0);
		return QVariant(0);
	}
	case 0x756f:     // fold range = SCI_FOLDLINE 展开/折叠
		send(SCI_FOLDLINE, a.toLongLong(), b.toLongLong() ? SC_FOLDACTION_EXPAND : SC_FOLDACTION_CONTRACT);
		return QVariant(0);
	// --- 编辑设置(与 doc+0x270/274 对应的公共 API)---
	case 0x75c1:     // tabSize read
		return QVariant((int)send(SCI_GETTABWIDTH));
	case 0x75c4:     // setTabSize(拒 n<1,0x75c1 读对)
		send(SCI_SETTABWIDTH, a.toInt());
		return QVariant(0);
	case 0x75c2:     // indentSize read
		return QVariant((int)send(SCI_GETINDENT));
	case 0x75c5: {   // setIndent(语料 L24726:+0x274 旧值比较,变更才写,
	                 //   返变更 bool;读对 0x75c2 = SCI_GETINDENT 面)
		const int v = a.toInt();
		const int cur = (int)send(SCI_GETINDENT);
		if (cur == v)
			return QVariant(false);
		send(SCI_SETINDENT, v);
		return QVariant(true);
	}
	case 0x7577:     // eolString(kind) = 行尾串查询
		return QVariant(QByteArray(send(SCI_GETEOLMODE) == SC_EOL_CRLF ? "\r\n" : "\n"));
	// --- 探针 ---
	case 0x75af:     // canRedo 家族
		return QVariant(send(SCI_CANREDO) != 0);
	case 0x75b1:
		return QVariant(send(SCI_CANUNDO) != 0);
	case 0x754f:     // capability 8 探针(只读)
		return QVariant(send(SCI_GETREADONLY) == 0);
	// --- 编辑器上下文 setter 批(Phase-3;EditorContext 模型)---
	case 0x759a:     // setHexBase(FUN_00a28e7c)
		m_ctx.setHexBase(a.toInt());
		return QVariant(0);
	case 0x759d: {   // +0x111c = a.toInt();变更且 >0 门,hexMode
	                 // (+0x1128)开 → soft_reset(FUN_00a28abe 33B;
	                 //   0034:24966-24968 ≥0x759d else 腿;与 0x759e
	                 //   setHexMode(FUN_00a30c2e 247B)异体 — 独立转写)
		const int v = a.toInt();
		if (m_ctx.hexSub111c != v && v > 0) {
			m_ctx.hexSub111c = v;
			if (m_ctx.hexMode) {
				// session_view_soft_reset — cited(Phase-4 视图)
			}
		}
		return QVariant(0);
	}
	case 0x759e:     // setHexMode(FUN_00a30c2e)
		m_ctx.setHexMode(a.toBool());
		return QVariant(0);
	case 0x7597:     // setMarginTrackChange(FUN_00a1fd8c)
		m_ctx.setMarginTrackChange(a.toBool());
		return QVariant(0);
	case 0x759b: {   // hexBase 读(语料 0x759a 邻位;vt 读)
		return QVariant(m_ctx.hexBase);
	}
	// --- margin 链批(Phase-3 批 2)---
	case 0x7591:     // margins(FUN_00a4bc60 邻位;返回定义列)
		return QVariant(m_ctx.margins);
	// --- pair 高亮/片段批(Phase-3 批 2 续)---
	case 0x7583:     // pairHighlightUnmatched(FUN_00a10c68:置枚举 2;
	                 //  editctx 迭代腿 FUN_00a2398e — cited)
		m_ctx.pairHighlightUnmatched = 2;
		return QVariant(0);
	case 0x75ba:     // cancelSnippetMode(FUN_00a28ee8:
	                 //  FUN_00a20104 + FUN_00926ebc(+0x1098))
		m_ctx.snippetMode = false;
		return QVariant(0);
	// --- 批 3:清格式 / margin 元数据 / 视口滚动(语料 decomp-part-0034)---
	case 0x7557:   // 0034:23003 else 腿 = 与 0x7558 同体(批 77 清点)
	case 0x7558: {   // clearFormatting(FUN_00927a24 守卫 + FUN_00a26756)
		if (m_ctx.snippetMode)             // FUN_009290e8 守卫(00a26756 头)
			return QVariant(0);
		const bool flag = m_ctx.bufferStyleFlag;
		if (flag)
			m_ctx.bufferStyleFlag = false; // FUN_00927a30(buf,0)
		// FUN_00927dbe/00927ebc/00927be6 buffer 通知腿 — cited
		const sptr_t s = send(SCI_GETSELECTIONSTART, 0, 0);
		const sptr_t e = send(SCI_GETSELECTIONEND, 0, 0);
		if (e > s) {
			// run-node 空合并(00a26756)→ 选区回归默认样式的适配映射
			send(SCI_STARTSTYLING, s, 0xff);
			send(SCI_SETSTYLING, e - s, 0);
		}
		m_ctx.pairCacheFc0 = 0;            // +0xfc0/+0xfc8 清零
		m_ctx.pairCacheFc8 = 0;
		// session_view_soft_reset — cited(Phase-4 视图)
		if (flag)
			m_ctx.bufferStyleFlag = true;  // FUN_00927a30(buf,1)
		return QVariant(0);
	}
	case 0x7567: {   // setMarginWidth(real → +0x1a2;变化才动作)
		const double w = a.toReal();
		if (w != m_ctx.marginWidth) {
			m_ctx.marginWidth = w;
			// FUN_00959890(buf,-1,-1)全程样式失效(+0x14/+0x168 守卫
			// 与逐位置循环 — cited)+ number/timestamp margin 刷新
			// (s_margin_a302fe/a30e02)+ soft_reset — cited
		}
		return QVariant(0);
	}
	case 0x7568: {   // setMarginIcons(list → +0x1b4;先清空再过滤追加)
		QList<int> icons;
		const QVariantList in = a.toList();
		for (const QVariant &v : in) {
			if (!v.canConvert<int>())
				continue;
			const int n = v.toInt();
			if (n >= 0)
				icons.append(n);           // FUN_00a4bb6a(QList append)
		}
		m_ctx.marginIcons = icons;
		// vtable+0xa0 视图刷新 — cited(Phase-4)
		return QVariant(0);
	}
	case 0x75ad:     // 可见行数(FUN_00a20438:像素高/行高,≥1)
		return QVariant(qMax(1, (int)send(SCI_LINESONSCREEN, 0, 0)));
	case 0x75ae: {   // 行高(FUN_00a2b0a2 重算 388B cited → +0xd04)
		return QVariant((int)send(SCI_TEXTHEIGHT, 0, 0));
	}
	case 0x75b2: {   // 纵向滚动条 max(视口 vt+0xe0(1) → sb+0x30;
	                 //  适配映射:lineCount - linesOnScreen,≥0)
		const long long lc = send(SCI_GETLINECOUNT, 0, 0);
		const long long vis = send(SCI_LINESONSCREEN, 0, 0);
		return QVariant((long long)qMax<long long>(0, lc - vis));
	}
	case 0x75b3:     // 纵向 pageStep(sb pageStep;适配 SCI_LINESONSCREEN)
		return QVariant((int)send(SCI_LINESONSCREEN, 0, 0));
	case 0x75b4:     // 视口 +0x2c 字节(FUN_00a2398e:beginIter(2)+写+endIter)
		m_ctx.viewportFlag2c = a.toInt();
		return QVariant(0);
	case 0x75b5: {   // scrollTo(axis,pos):1=纵 00a169cc / 2=横 00a167ac
		const int axis = a.toInt();
		const long long pos = b.toLongLong();
		if (axis == 1) {
			// max < pos 时像素锚重算(FUN_00a16946)+ doc 通知
			// (FUN_00a243ae)— cited;可见行为 = 设首可见行
			send(SCI_SETFIRSTVISIBLELINE, pos, 0);
		} else if (axis == 2) {
			send(SCI_SETXOFFSET, pos, 0);  // FUN_00584bd8 夹取由内核做
		}
		return QVariant(0);
	}
	case 0x75bc:     // setSnippetMode(FUN_00a28efe:行扫描 cited →
	                 //  FUN_00926fde;失败且 on 则取消)
		m_ctx.snippetMode = a.toBool();
		return QVariant((bool)m_ctx.snippetMode);
	case 0x75bf:     // 片段会话活跃?(FUN_00926eb0:+0xd0 != 0)
		return QVariant((bool)m_ctx.snippetMode);
	// --- 批 4:buffer/状态簇(语料 disp 叶 22992-23145)---
	case 0x7555:   // 0034:22997 <0x7557 默认腿 = 与 0x7556 同体(批 77 清点)
	case 0x7556:     // buffer 动态类型(FUN_00927ec8:+0xf8 cast != 0)
		return QVariant((bool)m_ctx.isSuperBuffer);
	case 0x7559: {   // collect(严格 5 元素 [str,bool,u64,ll,ll];
	                 //  FUN_00980ffc 收集器深腿 — cited)
		if (a.toList().size() != 5)
			return QVariant(QString());
		return QVariant(QString());
	}
	case 0x755a:     // setString(buffer vt+0x58 — 跳转表未恢复,cited)
		m_ctx.bufferString = a.toString();
		return QVariant(0);
	case 0x755b:     // buffer 对象置换(FUN_00927f16:0x48B;
	                 //  false→009818aa / true→00989ef2 — cited)
		m_ctx.bufferModeB = a.toBool();
		return QVariant(0);
	case 0x755c:     // bit1 → -1/0(语料 (uint)b<<30>>31 语义)
		return QVariant((m_ctx.stateEd8 & 2) ? -1 : 0);
	case 0x755d:     // (int)+0xed8 >> 3 = ms 时长
		return QVariant((int)m_ctx.stateEd8 >> 3);
	case 0x755e:     // 当前样式 run → QVariant(FUN_00a29014 块样式/+0x1068
	                 //  三元 + 0096bbc0 — runnode 模型 cited)
		return QVariant();
	case 0x755f:     // +0x1ba 查询
		return QVariant(m_ctx.val1ba);
	case 0x7560:     // +0x1bb 查询(double)
		return QVariant(m_ctx.val1bb);
	case 0x7561: {   // FUN_00a2d5a0:bit1 布尔(守卫比较 bit1 派生;
	                 //  写 bit1|bit2;刷新 00a2cea8 cited)
		const bool v = a.toBool();
		const int cur = (m_ctx.stateEd8 & 2) ? -1 : 0;
		if (cur == (int)(uint)v)
			return QVariant(0);
		m_ctx.stateEd8 = (m_ctx.stateEd8 & ~2u) | (v ? 2u : 0u) | 4u;
		return QVariant(0);
	}
	case 0x7563: {   // FUN_00a2d648:+0xdd0 int + bit2 脏(+0xef0 镜像 cited)
		const int v = a.toInt();
		if (m_ctx.valDd0 != (quint32)v) {
			m_ctx.valDd0 = (quint32)v;
			m_ctx.stateEd8 |= 4;
		}
		return QVariant(0);
	}
	case 0x7564: {   // FUN_00a2d5d0:float 秒→ms 夹 100 → bits3+ + bit2
		int ms = (int)((double)a.toFloat() * 1000.0);
		if (ms < 100)
			ms = 100;
		if ((float)((int)m_ctx.stateEd8 >> 3) != (float)ms) {
			m_ctx.stateEd8 = (m_ctx.stateEd8 & 7u)
			    | ((quint32)(int)(float)ms << 3);
			m_ctx.stateEd8 |= 4;
		}
		return QVariant(0);
	}
	case 0x756d:     // 标记注册(FUN_00925c02:查得即返,否则插入 +
	                 //  通知 cited;flag=1;尾部接线 0092671c 当
	                 //  b!=0 — cited;756d/756e 语料同体)
	case 0x756e: {
		const long long p = a.toLongLong();
		m_ctx.markerInsert(RunNode::make(p, 0, true));
		return QVariant(0);
	}
	case 0x75a3: {   // 标记对选区(FUN_00926e1c×2 → RunPair;
	                 //  完整则选 [min,max],尾 0092777c/substring cited;
	                 //  语料:首对不完整且 a<b 时重取 b 再合成)
		const int i = a.toUInt();
		const int j = b.toUInt();
		RunPair pair;
		pair.first = m_ctx.markerAt(i);
		pair.second = m_ctx.markerAt(j);
		if (!pair.complete() && i < j)
			pair.second = m_ctx.markerAt(j);
		if (!pair.complete())
			return QVariant();
		const long long s = qMin(pair.first.pos, pair.second.pos);
		const long long e = qMax(pair.first.pos, pair.second.pos);
		send(SCI_SETSELECTIONSTART, s, 0);
		send(SCI_SETSELECTIONEND, e, 0);
		return QVariant();           // 尾部返回形状 cited
	}
	// --- 批 5:尾块 0x75d0-0x75ff(disp 24100-24518)---
	case 0x75d0: {   // y→行(FUN_00a2059c:首行+ y/行高;exact 恒 1:
	                 //  结果 >= textLength → -1,行数与字符数比较=原样)
		const int y = a.toPoint().y();
		long long line = send(SCI_GETFIRSTVISIBLELINE, 0, 0)
		    + y / qMax(1, (int)send(SCI_TEXTHEIGHT, 0, 0));
		if (send(SCI_GETLENGTH, 0, 0) <= line)
			line = -1;
		return QVariant(line);
	}
	case 0x75d1:     // pos→行(FUN_009587cc run 查找 — SCI_LINEFROMPOSITION 适配)
	case 0x75d2:     // pos→行(FUN_00958498)
		return QVariant((long long)send(SCI_LINEFROMPOSITION,
		                                a.toLongLong(), 0));
	case 0x75d3: {   // 点→字符矩形(hitTest→00a2267c;适配:点→pos→矩形)
		const QPoint p = a.toPoint();
		const long long pos = send(SCI_POSITIONFROMPOINT, p.x(), p.y());
		return charRectAt(pos);
	}
	case 0x75d4:     // pos→字符矩形(FUN_00a2267c:runX/runW 内部 cited;
	                 //  适配:x=POINTX,y=line*行高,w=字符宽,h=行高)
		return charRectAt(a.toLongLong());
	case 0x75d7:     // +0x1bc 查询
		return QVariant((bool)m_ctx.flag1bc);
	case 0x75d8:     // doc+0x14 查询(FUN_00a218dc)
		return QVariant(m_ctx.fontScale);
	case 0x75d9: {   // FUN_00a245c6:旧值经 FUN_00958426 通知,新值夹
	                 //  [0,10000] 回写 doc+0x14;伴侣值守卫(00a21610)cited;
	                 //  刷新 009753ca/0097a2a4 cited
		const int v = a.toInt();
		m_ctx.fontScale = qBound(0, v, 10000);
		return QVariant(0);
	}
	case 0x75db: {   // +0x1bc 写(+变化才 soft_reset)
		const bool v = a.toBool();
		if (m_ctx.flag1bc != v) {
			m_ctx.flag1bc = v;
			// session_view_soft_reset — cited(Phase-4 视图)
		}
		return QVariant(0);
	}
	// 0x75dc 已注销(批 80 r4 定案:5b5d68 全调用面 0x75d0-0x75df 逐号
	// 列表,0x75dc 全语料零调用点 = 不存在;批 5 早期接线撤)—— 发入
	// 落 default 返 0,与原版一致
	case 0x75dd:     // FUN_0092522a → FUN_00980684(+0xf8 buffer obj)——cited
		return QVariant();
	case 0x75de:     // +0x1068 存储节点 pos(FUN_0096bbc0 = *(x+8))
		return QVariant((long long)m_ctx.blockNode.pos);
	case 0x75df:     // 存储节点样式(qstrdata_length_get 复用:word0>>1)
		return QVariant(m_ctx.blockNode.style());
	case 0x75e1:     // +0x210 写(FUN_00a2cea8 刷新 cited)— 自 0x75e0
	                 //   归位(语料 L24250;原标签 = 区间腿误切,批 65 勘察)
		m_ctx.flag210 = a.toBool();
		return QVariant(0);
	case 0x75e0:     // QColor 写(userType 0x43 → +0xedc/+0x1dc 六字段
	                 //   + FUN_00a2cea8 刷新,L24255 区)— cited — wave-2
		return QVariant(0);
	case 0x75e2:     // +0x1083 查询
		return QVariant((bool)m_ctx.flag1083);
	case 0x75e3:     // FUN_00a2e9e2(296B QVariant 组装)——cited
		return QVariant();
	case 0x75e5:     // FUN_00a3175e 动作 —— cited
		return QVariant(0);
	case 0x75e6: {   // 配色读取:"line.caret.remote" 且 +0xedc 非空 → 远程
	                 //  光标色;否则 0095021a key 查 styleAt —— 查找腿 cited
		if (a.toString() == QLatin1String("line.caret.remote")
		    && m_ctx.remoteCaretFlag != 0)
			return QVariant(QColor());   // 色值随配色面(Phase-4)
		return QVariant(QColor());
	}
	case 0x75e7: {   // 点→列(FUN_00a29fa8:(x-原点)/字宽;适配:pos-行首)
		const QPoint p = a.toPoint();
		const long long pos = send(SCI_POSITIONFROMPOINT, p.x(), p.y());
		const long long line = send(SCI_LINEFROMPOSITION, pos, 0);
		return QVariant((int)(pos - send(SCI_POSITIONFROMLINE, line, 0)));
	}
	case 0x75e8:     // FUN_00a29ff6 → 009347b6(+0x1098)——buffer 面 cited
		return QVariant();
	case 0x75e9:     // 点→锚点(FUN_00a2a002:模式选 +0x148/+0x158)——cited
		return QVariant();
	case 0x75ea:     // 块节点文本(FUN_00a2a21c→00a2a15e:+0x1068 节点;
	                 //  buf_substr(缓冲起点, node.pos),起点链 cited)
		return textUpTo(m_ctx.blockNode.pos);
	case 0x75ee:     // runnode(pos)→文本(00a2a15e 同体)——行首适配
		return textUpTo(a.toLongLong());
	case 0x75eb: {   // 点→hitTest→节点→FUN_00a2a0ea(列,原样含
	                 //  pos>textLength 补差)
		const QPoint p = a.toPoint();
		return colAt(send(SCI_POSITIONFROMPOINT, p.x(), p.y()));
	}
	case 0x75ec:     // runnode(pos)→列(FUN_00a2a0ea)
		return colAt(a.toLongLong());
	case 0x75ed:     // hitTest(pt,exact)→文本(00a2b854→00a2a15e)
	{
		const QPoint p = a.toPoint();
		return textUpTo(send(SCI_POSITIONFROMPOINT, p.x(), p.y()));
	}
	case 0x75ef:     // FUN_00a29eb6 —— cited
		return QVariant();
	case 0x75f0:     // FUN_00a2a44a(177B 块跳转)——cited
		return QVariant(0);
	case 0x75f1: {   // +0x1082 写(009502de 传播 + soft_reset cited)
		const bool v = a.toBool();
		if (m_ctx.flag1082 != v)
			m_ctx.flag1082 = v;
		return QVariant(0);
	}
	case 0x75f2:     // buffer+0x160 查询
		return QVariant((long long)m_ctx.bufField160);
	case 0x75f3:     // buffer+0x158 查询
		return QVariant((long long)m_ctx.bufField158);
	case 0x75f4:     // buffer+0x160 写(FUN_00929336:<0 → -1)
		m_ctx.bufField160 = (quint64)(a.toLongLong() < 0 ? -1 : a.toLongLong());
		return QVariant(0);
	case 0x75f5: {   // FUN_00925ae4:+0x2c0 枚举;(v&~4)!=3 时 +0x168=-1
		m_ctx.modeEnum2c0 = (quint32)a.toUInt();
		if ((m_ctx.modeEnum2c0 & 0xfffffffbu) != 3u) {
			m_ctx.bufField160 = 0xffffffffffffffffull;  // +0x168 缓存失效
			// FUN_00925a78() — cited
		}
		return QVariant(0);
	}
	case 0x75f7:     // FUN_00a2a504(447B editctx iter 0x200)——cited
		return QVariant(0);
	case 0x75f8:     // FUN_00933830(1544B 节点树)——cited
		return QVariant(0);
	case 0x75f9:     // +0xd8 obj+0x20 查询(空对象 → -1;FUN_00927170)
		return QVariant((long long)m_ctx.bufObjField);
	case 0x75fa:     // FUN_00a2a6e6(+0x1067==2 hex 子态;行文本+标记)——cited
	case 0x75fb:     // 同上变体 —— cited
		return QVariant(QString());
	case 0x75fc: {   // 时间戳格式(FUN_00927216:indexOf('z') → +0xd8+8 布尔;
	                 //  串存 +0x290;margin 刷新 cited)
		m_ctx.timestampFormat = a.toByteArray();
		m_ctx.timestampHasZ = m_ctx.timestampFormat.indexOf('z') != -1;
		return QVariant(0);
	}
	case 0x75fe:     // 长时间戳格式存(disp 24506)
		m_ctx.timestampLongFormat = a.toByteArray();
		return QVariant(0);
	case 0x75ff:     // +0xd8 obj 写(FUN_009271e4 → 009af2d6)
		m_ctx.bufObjField = a.toLongLong();
		return QVariant(0);
	case 0x7594:     // removeMargin(FUN_00a4bc60:按名移除)
		m_ctx.removeMargin(a.toString());
		return QVariant(0);
	case 0x7595:     // clearMargins(inline:四标志清零)
		m_ctx.clearMarginFlags();
		return QVariant(0);
	case 0x75d6: {   // setWordSeparators(FUN_009279ec:flag 选 +0x288/+0x280 槽)
		const QString text = b.toString();
		if (a.toBool())
			m_separators1 = text;   // +0x288
		else
			m_separators0 = text;   // +0x280
		return QVariant(0);
	}
	case 0x7536: {   // FUN_00a23d26(19B):+0x1108 |= mask;标记通知
	                 //   FUN_00925bb4(+0x1098)— cited(Phase-4b 通知腿)
		m_ctx.mask1108 |= a.toULongLong();
		return QVariant(0);
	}
	case 0x7538: {   // FUN_00a24126(25B):+0x1108 &= ~mask;通知
	                 //   FUN_00925bc8 — cited(Phase-4b 通知腿)
		m_ctx.mask1108 &= ~a.toULongLong();
		return QVariant(0);
	}
	case 0x7533: {   // +0x21d 字节 = a.toBool()(00669xxx 区直写)
		m_ctx.flag21d = a.toBool();
		return QVariant(0);
	}
	case 0x7535: {   // FUN_00a30d26(219B):+0x1067 = int(a);变更时
	                 //   0 → FUN_00a245c6 + FUN_0095cc7e(ctx[0x214])
	                 //   + 0x213 面刷新 — cited(Phase-4b 通知腿)
		const int v = a.toInt();
		if (m_ctx.field1067 != (signed char)v) {
			m_ctx.field1067 = (signed char)v;
			if (v == 0) {
				// FUN_00a245c6(this,0,0)— cited(Phase-4b)
			}
		}
		return QVariant(0);
	}
	case 0x7575: {   // FUN_00a5ed6e(ctx[0x217],line,1,1,bool):fold 族
	                 //   (同 0x7571 映射;flag=展开位)
		const long long line = a.toLongLong();
		const long long parent = send(SCI_GETFOLDPARENT, line, 0);
		send(SCI_FOLDLINE, parent < 0 ? line : parent,
		     b.toBool() ? SC_FOLDACTION_EXPAND : SC_FOLDACTION_CONTRACT);
		return QVariant(0);
	}
	case 0x7578: {   // FUN_00a21b1e(14B):markers 对象 +0x210 int 查询
		return QVariant((int)m_ctx.hexField210);
	}
	case 0x7586: {   // +0x1b1 int = a.toInt();变更 → vtable+0xa0 刷新
	                 //   (cited — Phase-4b 视图腿)
		const int v = a.toInt();
		if (m_ctx.field1b1 != v) {
			m_ctx.field1b1 = v;
			// (**+0xa0)(ctx) 刷新 — cited(Phase-4b 视图腿)
		}
		return QVariant(0);
	}
	case 0x7588: {   // FUN_009588b8(ctx[0x214],a):行内游走查询
	                 //   (runstyles 面;cited — Phase-4b)
		return QVariant(0);   // cited — wave-2(009588b8 待转写)
	}
	case 0x758a: {   // QCollator 配置(006698xx 区):toMap →
	                 //   type/case/punctuation/numeric 四键 →
	                 //   QCollator set* → FUN_00a3a3ee 应用
		const QVariantMap cfg = a.toMap();
		QCollator collator;
		if (cfg.contains(QStringLiteral("type")))
			collator.setLocale(QLocale(
			    cfg.value(QStringLiteral("type")).toString()));
		if (cfg.contains(QStringLiteral("case")))
			collator.setCaseSensitivity(
			    cfg.value(QStringLiteral("case")).toInt()
			        ? Qt::CaseSensitive
			        : Qt::CaseInsensitive);
		if (cfg.contains(QStringLiteral("punctuation")))
			collator.setIgnorePunctuation(
			    cfg.value(QStringLiteral("punctuation")).toBool());
		if (cfg.contains(QStringLiteral("numeric")))
			collator.setNumericMode(
			    cfg.value(QStringLiteral("numeric")).toBool());
		// FUN_00a3a3ee(ctx,collator)应用 — cited — wave-2
		// (搜索/排序 collator 面,Phase-4b)
		return QVariant(0);
	}
	case 0x758b: {   // +0xd8d 字节 = a.toBool();变更 → 刷新(cited)
		const bool v = a.toBool();
		if (m_ctx.flagD8d != v) {
			m_ctx.flagD8d = v;
			// (**+0xa0)(ctx) 刷新 — cited(Phase-4b 视图腿)
		}
		return QVariant(0);
	}
	case 0x758d: {   // FUN_00927ea8(ctx[0x213],a.toLongLong,bool)
	                 //   — cited — wave-2(markers 面待转写)
		return QVariant(0);
	}
	case 0x7592: {   // margin 可见过滤:toStringList → 名单外条目
	                 //   bit7 置隐 → session_view_soft_reset
	                 //   (cited — Phase-4 视图)
		const QStringList names = a.toStringList();
		for (auto &e : m_ctx.marginList)
			e.hidden = !names.contains(e.name, Qt::CaseInsensitive);
		// session_view_soft_reset — cited(Phase-4 视图)
		return QVariant(0);
	}
	case 0x7593: {   // +0x1ae 字节 = a.toBool()
		m_ctx.flag1ae = a.toBool();
		return QVariant(0);
	}
	case 0x7596: {   // setMargin(focusOut)(CMD_30102;L25044-25409,
	                 //   >40 行样式名查找):+0x1ae 门关时执行 —
	                 //   toMap "name" → 0x1ab/0x1ac 向量(0x18 步长)
	                 //   memcmp 匹配 → 命中项承接 index/visible/type/
	                 //   border/cursor/alignment/trackChange/
	                 //   trackSelection/width/padding 等键回写 +
	                 //   类型分发重算(number/timestamp/…)+ soft_reset;
	                 //   memcmp→QString::== 语义同构(QByteArray
	                 //   等长字节比较);批 79 位级转写 00a43134-00a437e4
		if (m_ctx.flag1ae)
			return QVariant(0);      // L25044:+0x1ae != 0 → 跳过
		const QVariantMap spec = a.toMap();
		const QString name = spec.value(QStringLiteral("name")).toString();
		// 0x1ab/0x1ac 向量逐项匹配(0x18 步长 → QList 遍历语义)
		int hit = -1;
		for (int i = 0; i < m_ctx.marginList.size(); ++i) {
			if (m_ctx.marginList.at(i).name == name) {  // 00a43134 memcmp 同构
				hit = i;
				break;
			}
		}
		// index 键门(00a43256 取键/00a4327e:canConvert<int> && toInt()>=0)
		const QVariant indexV = spec.value(QStringLiteral("index"));
		int pos = -1;                    // 回写落点(语料 this 指针的 QList 位面)
		if (indexV.canConvert<int>() && indexV.toInt() >= 0) {
			const int index = indexV.toInt();
			EditorContext::MarginEntry fresh;  // FUN_0094fc8c(ba,4) 默认位面:
			                             //   0x84/0x8b/symbol=-1(头文件缺省承接)
			if (hit >= 0 && hit != m_ctx.marginList.size() - 1) {
				// 00a432a8 门(this!=end):位面拷入 fresh + 移除;
				//   末位命中跳过拷贝/移除 — 语料原样(重插时旧末位保留)
				const EditorContext::MarginEntry &src = m_ctx.marginList.at(hit);
				fresh.name = src.name;                   // QByteArray::operator=
				fresh.spare08 = src.spare08;             // +0x08 u16
				fresh.flagsA = src.flagsA;  // +0x0a:&0x7ff|&0xf800 = 全位面
				fresh.flagsB = src.flagsB;  // +0x0b:cursor 高位|&0xf8
				fresh.symbol = src.symbol;  // +0x0c u32 直拷
				fresh.flagsC = src.flagsC;  // +0x10:&0xfff|&0x3ff000 = 全位面
				fresh.flagsD = src.flagsD & 0xffc0;      // +0x12 leftPadding 面
				m_ctx.marginList.removeAt(hit);  // FUN_00a4bc60(387B) 左移补位
			}
			// FUN_00a4c3fa(394B) 插入;00a4aa83 门 index≥size → 尾插
			pos = index < m_ctx.marginList.size() ? index : m_ctx.marginList.size();
			m_ctx.marginList.insert(pos, fresh);
		} else if (hit < 0 || hit == m_ctx.marginList.size() - 1) {
			// index 门败且 this==end(未命中/命中末位)→ append 腿:
			//   FUN_00a4cdf0(753B) 容量 2x 增容 + move 追加(QList append
			//   承接);旧条目不覆写 — 语料原样
			m_ctx.marginList.append(EditorContext::MarginEntry{});
			pos = m_ctx.marginList.size() - 1;
		} else {
			pos = hit;                   // index 门败:this=命中项原位承接
		}
		EditorContext::MarginEntry &e = m_ctx.marginList[pos];
		e.name = name;                   // QByteArray::operator=(this,local_f8)
		// setter 依序(L25054-25388;每键门 = 语料 QVariant 空检查)
		QVariant v = spec.value(QStringLiteral("visible"));      // 00a432e4
		if (!v.isNull())
			e.flagsB = quint8((e.flagsB & 0x7f) | (v.toBool() << 7));
		v = spec.value(QStringLiteral("type"));                  // 00a43340
		if (!v.isNull()) {
			const QByteArray t = v.toByteArray().toLower();
			quint8 ty = 4;               // qstrcmp 链尾默认 symbol
			if (t == "blank") ty = 1;
			else if (t == "fold") ty = 2;
			else if (t == "number") ty = 3;
			else if (t == "text") ty = 5;
			else if (t == "timestamp") ty = 6;
			e.flagsA = quint8(ty | (e.flagsA & 0xf0));
		}
		v = spec.value(QStringLiteral("border"));                // 00a433e3
		if (!v.isNull()) {
			const QByteArray t = v.toByteArray().toLower();
			const quint8 bo = (t == "dots") ? 1 : ((t == "line") ? 2 : 0);
			e.flagsA = quint8((bo << 4) | (e.flagsA & 0x8f));
		}
		v = spec.value(QStringLiteral("cursor"));                // 00a43486
		if (!v.isNull()) {
			const bool arrow = v.toByteArray().toLower() == "arrow";
			const quint16 cu = arrow ? 2 : 7;    // ((-eq&0xfffb)+7)&0xf
			quint16 f = quint16(e.flagsA) | (quint16(e.flagsB) << 8);  // u16(+0x0a) 视角
			f = quint16((cu << 7) | (f & 0xf87f));
			e.flagsA = quint8(f & 0xff);
			e.flagsB = quint8(f >> 8);
		}
		v = spec.value(QStringLiteral("alignment"));             // 00a43523
		if (!v.isNull()) {
			const QByteArray t = v.toByteArray().toLower();
			const quint8 av = (t == "left") ? 0 : ((t == "right") ? 1 : 2);
			e.flagsB = quint8((av << 3) | (e.flagsB & 0xe7));
		}
		v = spec.value(QStringLiteral("trackChange"));           // 00a435c0
		if (!v.isNull())
			e.flagsB = quint8((e.flagsB & 0xdf) | ((v.toBool() & 1) << 5));
		v = spec.value(QStringLiteral("trackSelection"));        // 00a4361c
		if (!v.isNull())
			e.flagsB = quint8((e.flagsB & 0xbf) | ((v.toBool() & 1) << 6));
		v = spec.value(QStringLiteral("width"));                 // 00a4367a
		if (!v.isNull()) {
			int w = v.toInt();
			if (w < 0)
				w = 0;
			// (long)(float) 双重转换:语料字面(00a4367a;反编译伪影未核)
			e.flagsC = quint16(((quint16)(long)(float)w & 0xfff) | (e.flagsC & 0xf000));
		}
		v = spec.value(QStringLiteral("leftPadding"));           // 00a436ee
		if (!v.isNull()) {
			int lp = v.toInt();
			if (lp < 0)
				lp = 0;
			// 同上双重转换语料字面(00a436ee;反编译伪影未核)
			e.flagsD = quint16(((quint16)((int)(long)(float)lp << 6)) | (e.flagsD & 0x3f));
		}
		v = spec.value(QStringLiteral("rightPadding"));          // 00a4375f
		if (!v.isNull()) {
			int rp = v.toInt();
			if (rp < 0)
				rp = 0;
			quint32 u = quint32(e.flagsC) | (quint32(e.flagsD) << 16);  // +0x10 u32 视角
			// 同上双重转换语料字面(00a4375f;反编译伪影未核)
			u = ((((quint32)(long)(float)rp) & 0x3ff) << 0xc) | (u & 0xffc00fff);
			e.flagsC = quint16(u & 0xffff);
			e.flagsD = quint16(u >> 16);
		}
		if ((e.flagsA & 0x0f) == 4) {    // 00a437ac:type==4 才写 symbol
			v = spec.value(QStringLiteral("symbol"));    // DAT_00cf882c 键
			e.symbol = v.isNull() ? 0xffffffffu : v.toUInt();
		}
		// 尾部类型分发重算(L25382;门 = visible && width+padding 和非 0)
		if ((e.flagsB & 0x80)
		    && ((e.flagsC & 0xfff) + (e.flagsD >> 6)
		        + (((quint32(e.flagsC) | (quint32(e.flagsD) << 16)) >> 0xc) & 0x3ff)) != 0) {
			const quint8 ty = e.flagsA & 0x0f;
			if (ty == 3) {
				// s_margin_number_a302fe(ctx)— cited — wave-2
			} else if (ty == 6) {
				// s_margin_timestamp_a30e02(ctx)— cited — wave-2
			} else if (ty == 2) {
				// FUN_00a2509a(ctx,-1,0)— cited — wave-2
			}
		}
		// session_view_soft_reset(ctx)(L25405)— cited — wave-2
		return QVariant(0);
	}
	case 0x7598:     // +0x225 查询(SUB81 字节读)
		return QVariant((bool)m_ctx.flag225);
	case 0x7599: {   // +0xd8e bool;变更且 +0x225 门 → 刷新(cited)
		const bool v = a.toBool();
		if (m_ctx.flagD8e != v) {
			m_ctx.flagD8e = v;
			if (m_ctx.flag225) {
				// (**+0xa0)(ctx) 刷新 — cited(Phase-4b 视图腿)
			}
		}
		return QVariant(0);
	}
	case 0x759c: {   // +0xd94 int;变更且 +0x225 门 → 刷新(cited)
		const int v = a.toInt();
		if (m_ctx.fieldD94 != v) {
			m_ctx.fieldD94 = v;
			if (m_ctx.flag225) {
				// (**+0xa0)(ctx) 刷新 — cited(Phase-4b 视图腿)
			}
		}
		return QVariant(0);
	}
	case 0x759f: {   // FUN_00926e08(20B):M(+0xc0 门)→ FUN_0099d1f6
	                 //   发布快照 → *(M+0x50)(批 67a 真身化)
		if (m_ctx.markers.isEmpty())
			return QVariant(0);                          // 门(行为模型保留)
		return QVariant::fromValue<quint64>(
		    *m_ctx.markersStore.publishSnapshot());
	}
	case 0x75a1: {   // FUN_00926e3e(20B):同门 → FUN_009a096a(批 67a)
		if (m_ctx.markers.isEmpty())
			return QVariant(0);
		return QVariant(qlonglong(
		    m_ctx.markersStore.resolveLine(a.toUInt())));
	}
	case 0x75a0: {   // L24799:line==-1 → 当行解析四函数(cited,维持
	                 //   line=0)→ FUN_00926e52(24B):*out=0 + 
	                 //   FUN_009a07d8(批 67a 真身化 nearestIdFrom)
		long line = a.toLongLong();
		if (line == -1) {
			// FUN_00975bc6/0096bbc0/0092522a/00928404 — cited
			line = 0;
		}
		quint32 id = 0;                                      // FUN_00926e52:*param_3=0
		if (m_ctx.markersStore.arr)                          // +0xc0 门 ⇔ M 非空
			m_ctx.markersStore.nearestIdFrom(line, &id);     // FUN_009a07d8
		return QVariant(id);
	}
	case 0x75a5: {   // FUN_00a2d3ec(286B):+0xec3 = a.toBool();变更
	                 //   且 +0x1128 → 逐行 run 失效(FUN_0096bf4a/
	                 //   0096bfc8/0096bc28/0096bfce runstyles 族)+
	                 //   +0xdd0 复位 — cited — wave-2(失效腿)
		const bool v = a.toBool();
		if (m_ctx.flagEc3 != v) {
			m_ctx.flagEc3 = v;
			if (m_ctx.flag1128) {
				// 逐行 run 失效 + FUN_00a20b94 门重算
				// — cited — wave-2(runstyles 面)
			}
		}
		return QVariant(0);
	}
	case 0x75a7:     // FUN_009252f4(15B)→ FUN_0099881e(196B
	                 //   word-walk 层:FUN_00a840fc 类进/00998678
	                 //   类测/FUN_009975de CRLF)— cited — wave-2
		return QVariant(0);
	case 0x75a8:     // FUN_00a21576(153B)可见行数:dv = max(
	                 //   +0xd38,+0xd20);field1067==2 →
	                 //   (+0x10a0 对象+0x18)/dv;否则 FUN_00a1f7e2
	                 //   文档高-滚动偏移;clamp ≥1;门 FUN_00a20b94
	                 //   — cited — wave-2(分支选择待转写)
		return QVariant(0);
	case 0x75a9:     // FUN_00a2041e(17B):max(+0xd38,+0xd20) 行高
		return QVariant(m_ctx.lineHeightD38 > m_ctx.lineHeightD20
		    ? m_ctx.lineHeightD38 : m_ctx.lineHeightD20);
	case 0x75aa:     // FUN_00a282b8(86B)全文重着色:markers 对象 →
	                 //   FUN_00a20680 构建/FUN_0096bbc0 文档长/
	                 //   FUN_00a20666 起点 → FUN_00930226 应用
	                 //   — cited — wave-2(runstyles 面)
		return QVariant(0);
	// 0x75ab 归属核定案(批 66):唯一语义 = gotoLine(line,col);
	//   FUN_00a26ec6(99B)即其实现体(editctx 定位 + markers 现位 +
	//   FUN_00a21110 选中应用,L24915 唯一 dispatch 体)—— 我方
	//   SCI_GOTOLINE 丢 col/选中腿,待补批
	case 0x75a6: {   // FUN_00a5940a(4113B)搜索跳转(批 67b 分级转写):
	                 //   前奏 A-E 正则直转 + F2 轻量 switch(28 case 全读;
	                 //   runnode 腿 → FUN_00a557b0(2961B) cited;
	                 //   F/T/t/H/L/M Grep·视口腿整体 cited;
	                 //   'g'+'g'/未知码 = -1;'f' 空组3 直落)
		const QString cmd = b.toString();
		// A:静态正则 "(\\d*)(.)(.?)"(DAT_011c28c8,guard+atexit,options=0)
		static const QRegularExpression re(
		    QStringLiteral("(\\d*)(.)(.?)"));
		// B:matchType=0/NormalMatch;matchOptions=1(NoMatch)—— 语料
		//   字面矛盾点原样(铁律 2),行为测试裁决
		const QRegularExpressionMatch mt = re.match(
		    cmd, 0, QRegularExpression::NormalMatch,
		    QRegularExpression::MatchOptions(
		        QRegularExpression::NoMatch));
		if (!mt.hasMatch())                               // 34631
			return QVariant(qlonglong(-1));
		const qlonglong n = mt.captured(1).toLongLong();  // 34637 组1
		const quint64 count = n > 0 ? quint64(n) : 1;     // 34645 缺省 1
		const QString codeStr = mt.captured(2);           // 34655 首码元
		const QString text3 = mt.captured(3);             // 34676 组3
		// 状态定案(F2 §0):lVar5 = 当前行(FUN_0092522a);lVar6 =
		//   总行数(FUN_00925570)—— SCI 承接
		long long param2 = a.toLongLong();                // pos 基点
		const long long lVar5 = send(SCI_LINEFROMPOSITION, param2, 0);
		long long lVar6 = send(SCI_GETLINECOUNT, 0, 0);
		// F1 Grep 对象分支前提(34884):组3 空 或 码 ∉ {f,F,t,T}
		const ushort uVar1 =
		    codeStr.isEmpty() ? 0 : codeStr.at(0).unicode();
		auto runnodeLeg = [](int kind, int sign, quint64 cnt) {
			// 14 腿统一模式:runstyles_runnode_init(RunNode.h 真身)
			//   → FUN_00a557b0(2961B)运动执行器 — cited — wave-2
			//   (kind/sign/cnt 语料实证;执行后 param2 = 结果 pos)
			(void)kind; (void)sign; (void)cnt;
		};
		switch (uVar1) {
		case 0x24:  // '$' @34895:目标行(当前+count-1)行尾(FUN_0092520c)
			param2 = send(SCI_GETLINEENDPOSITION, lVar5 - 1 + (long long)count, 0);
			break;
		case 0x28:  // '(' @34902:kind 0xc 负向
			runnodeLeg(0xc, -1, count); break;
		case 0x29:  // ')' @34914:kind 0xc 正向
			runnodeLeg(0xc, 1, count); break;
		case 0x42:  // 'B' @:kind 6 负向
			runnodeLeg(6, -1, count); break;
		case 0x45:  // 'E' @:kind 5 正向
			runnodeLeg(5, 1, count); break;
		case 0x57:  // 'W' @:kind 6 正向
			runnodeLeg(6, 1, count); break;
		case 0x62:  // 'b' @:kind 2 负向
			runnodeLeg(2, -1, count); break;
		case 0x65:  // 'e' @:kind 3 正向
			runnodeLeg(3, 1, count); break;
		case 0x68:  // 'h' @:kind 1 负向
			runnodeLeg(1, -1, count); break;
		case 0x6a:  // 'j' @:kind 7 正向
			runnodeLeg(7, 1, count); break;
		case 0x6b:  // 'k' @:kind 7 负向
			runnodeLeg(7, -1, count); break;
		case 0x6c:  // 'l' @:kind 1 正向
			runnodeLeg(1, 1, count); break;
		case 0x77:  // 'w' @:kind 2 正向
			runnodeLeg(2, 1, count); break;
		case 0x7b:  // '{' @:kind 0xe 负向
			runnodeLeg(0xe, -1, count); break;
		case 0x7d:  // '}' @:kind 0xe 正向
			runnodeLeg(0xe, 1, count); break;
		case 0x2b:  // '+' @34924:min(当前+count,末行)首非空(FUN_00927952)
			{
				const long long last = lVar6 - 1;
				if (lVar5 < last) {
					long long tgt = lVar5 + (long long)count;
					if (tgt > last) tgt = last;
					// FUN_00927952(100B)下探首非空 — cited — wave-2
				}
			}
			break;
		case 0x2d:  // '-' @34940:上 count 行(≥0)首非空(FUN_00927952)
			if (0 < lVar5) {
				long long tgt = lVar5 - (long long)count;
				if (tgt < 0) tgt = 0;
				// FUN_00927952 — cited — wave-2
			}
			break;
		case 0x30:  // '0' @34952:当前行行首(FUN_00925200)
			param2 = send(SCI_POSITIONFROMLINE, lVar5, 0);
			break;
		case 0x5e:  // '^' @:当前行首非空(FUN_00927952)— cited
			break;
		case 0x47: {  // 'G' @34999:captured 组1 → 行钳制 → 首非空 cited
			const qlonglong gn = mt.captured(1).toLongLong();
			long long target = lVar6 - 1;
			if (gn >= 1 && gn <= lVar6)
				target = gn - 1;
			if (target < 0)
				target = 0;
			// FUN_00927952(doc,target)— cited — wave-2
			break;
		}
		case 0x67:  // 'g':组3=="e"→kind3 -n;"E"→kind5 -n;"g"→0;余不变
			if (text3 == QStringLiteral("e"))
				runnodeLeg(3, -1, count);
			else if (text3 == QStringLiteral("E"))
				runnodeLeg(5, -1, count);
			else if (text3 == QStringLiteral("g"))
				param2 = 0;
			break;
		case 0x7a:  // 'z':组3=="j"→kind 0x11 +n;"k"→kind 0x11 -n;余不变
			if (text3 == QStringLiteral("j"))
				runnodeLeg(0x11, 1, count);
			else if (text3 == QStringLiteral("k"))
				runnodeLeg(0x11, -1, count);
			break;
		case 0x46: case 0x54: case 0x74:  // F/T/t → F1 Grep 体
		case 0x66:                        // 'f' 空组3 直落尾
			// FUN_00a31966(1121B)Grep 搜索执行 — cited — wave-2
			break;
		case 0x48: case 0x4c: case 0x4d:  // H/L/M 视口腿(FUN_00a20580/
			//   00a20604 视口首末行 + FUN_00958498)— cited — wave-2
			break;
		default:    // 未知码 → -1(35230 尾)
			param2 = -1;
			break;
		}
		return QVariant(qlonglong(param2));
	}
	case 0x7537:     // *(u8*)(doc+0x240) = 0(0x7538 邻位写 1;语义未解)
		m_ctx.field240 = 0;
		return QVariant(0);
	case 0x753c: {   // FUN_00a297c6(33B)caret 宽度:+0x1067!=2 →
	                 //   +0x10ec;==2 时形态!=2→16 / ==2→8(语料原样)
		if (m_ctx.field1067 != 2)
			return QVariant(m_ctx.caretShape);
		return QVariant(m_ctx.caretShape != 2 ? 0x10 : 8);
	}
	case 0x753d: {   // caret_changeShape(00a29a48,1059B)核心腿:
	                 //   +0x1067==2 归一化(8→2/余→4)+ +0x10ec 短路/
	                 //   赋值;0x914 虚事件(vt+0x150)+ 块对象(+0x1de)
	                 //   + soft_reset — cited — Phase-4b
		int v = a.toInt();
		if (m_ctx.field1067 == 2)
			v = (v == 8) ? 2 : 4;
		if (m_ctx.caretShape == v)
			return QVariant(0);
		m_ctx.caretShape = v;
		return QVariant(0);
	}
	case 0x7531:     // FUN_00a51780(1155B)= 补全列表当前项打包
	                 //   SciCompleterEvent(0x50B,type 0x3ed)经 vt+0x140
	                 //   投递 + FUN_00955368 模型通知(批 66 全读勘正:
	                 //   非 props 导入;事件总线未建模)
	                 //   — cited — wave-2
		return QVariant(0);
	case 0x7532:     // FUN_00a4f95e(36B):视图 selectionModel→
	                 //   hasSelection;空视图 = false(语料空检路径)
	                 //   — cited(视图句柄 Phase-4b)
		return QVariant(false);
	case 0x753a: {   // FUN_0092ed32(430B)链接目标注册(状态门
	                 //   (+0x2c0&~4)==3,节点 0x48B)— cited — wave-2
		m_ctx.linkMap = a.toMap();   // 到达参数暂存,真身化时消费
		return QVariant(0);
	}
	case 0x753e: {   // FUN_00a417fe(112B)→ FUN_00a41552(649B 渲染核)
	                 //   真身化(批 70;a/b 语料未消费,原样)
		// === 包装层 FUN_00a417fe(全读 @decomp-0034.c:20708)===
		const long long textLen = send(SCI_GETLENGTH, 0, 0);
		//   editor_textLength(ed+0x10a0);0x7547 同款映射
		// FUN_00a1fa2a(34B):textLength 夹 ≤16 → 带宽 w(行数)
		const int w = (int)(textLen < 0x10 ? textLen : 0x10);
		// FUN_00a1fa4c(60B):FUN_00a1f9e8(65B)分数×textLength − w/2
		//   夹 ≥0;分数参 xmm0 源未解 — cited — wave-2
		//   (偏差登记:分数占位 0 → x0 = max(0, −w/2) = 0)
		long long x0 = 0 - (long long)w / 2;
		if (x0 < 0)
			x0 = 0;
		// FUN_00a1fa88(74B):x0+w 夹 ≤textLength
		long long x1 = textLen;
		if ((long long)w + x0 <= textLen)
			x1 = (long long)w + x0;
		// 带高 = *(int*)(ed+0xd04) × w(+0xd04=行高 px;SCI_TEXTHEIGHT
		//   承接,charRectAt 同款)
		const int lineH = qMax(1, (int)send(SCI_TEXTHEIGHT, 0, 0));
		const int lineCount = lineH * w;
		// === 渲染核 FUN_00a41552(649B 全读 @20630);dpr = 1.0 字面量
		//   (0x3ff0000000000000,00a4172c)===
		// ① 00a41587:ret 槽 QPixmap 默认构造
		QPixmap out;
		// ② FUN_00944556(37B)operator_new(0x40)+ ctor FUN_0094367a(72B,
		//   全读 @8470):SurfaceImpl 视图对象(局部模型,勿外提)
		struct SurfaceView {             // 语料 0x40B;成员名即偏移
			QPixmap *m8 = nullptr;       // +0x08 m_pixmap
			void *m10 = nullptr;         // +0x10 painter 引用
			quint8 m18 = 0;              // +0x18(intDpr 字节)
			quint8 m19 = 0;              // +0x19 m_started
			quint8 m1a = 0;              // +0x1a
			double m20 = 0.0;            // +0x20 moveTo/lineTo 端点 x(FUN_00943300
			                             //   Surface_vt15 存 double;ctor 清零)
			double m28 = 0.0;            // +0x28 端点 y(同上)
			double dpr = 1.0;            // +0x30 ctor 0x3ff0…=1.0
			quint8 m38 = 0;              // +0x38
			QPixmap *pixmap() const      // vt+0x148 = FUN_0094331e(5B)
			{
				return m8;
			}
			void setDpr(double d)        // vt+0x130 = FUN_00944f10(6B)
			{
				dpr = d;
			}
			void release()               // vt+0x28 = FUN_0094333e:
			{                            //   painter/pixmap 引用释放+四域清零
				m8 = nullptr;
				m10 = nullptr;
				m18 = 0; m19 = 0; m1a = 0;
			}
			void init(double d, int iw, int ih, bool alt)  // vt+0x20 =
			{   // FUN_009437a8(209B,全读 @8551;"dtor_deleting"Ghidra
			    //   误标,地址权威)
				release();               // (**vt+0x28)()
				m19 = 1;                 // +0x19 = 1
				if (ih < 1) ih = 1;      // 语料序:先 h(0094380e)后 w
				if (iw < 1) iw = 1;
				QPixmap *pm = new QPixmap((int)((double)iw * d),
				                          (int)((double)ih * d));  // 00943817
				pm->setDevicePixelRatio(d);          // 00943825
				m8 = pm;                             // +8 = pm
				// FUN_009436c2(133B,全读 @8488):metric(0xc)
				//   ×1.52587890625e-05 → round 差×1e12 ≤ max 判整数 dpr
				const double x =
				    (double)(int)(d * 65536.0) * 1.52587890625e-05;
				const double r = qRound(x);
				double fr = x - r;
				if (fr < 0)
					fr = -fr;
				double ar = r < 0 ? -r : r;
				double ax = x < 0 ? -x : x;
				const double mx = (ar <= ax) ? ar : ax;  // 语料 max 形
				m18 = (fr * 1000000000000.0 <= mx) ? 1 : 0;
				// 尾:vt+0x140==FUN_00943318(默认实现)→ +0x38 = alt
				//   (派生重写路径不建模,取默认表分支;3 参唯一消费点)
				m38 = (quint8)alt;
			}
			// === M3:SurfaceImpl vtable 0x11acff0 槽映射(r5 §2;批 75)===
			// 惰性 QPainter 锚:FUN_00943882(137B)@0031:8586
			QPainter *painter()
			{
				if (m10 != nullptr)
					return (QPainter *)m10;  // +0x10 缓存(QPaintEngine::painter 分支同效)
				if (m8 == nullptr)
					return nullptr;
				QPainter *p = new QPainter(m8);          // 00943900
				p->setRenderHints(QPainter::RenderHints(3 - (m18 == 0)), true);  // 0094396c
				p->scale(dpr, dpr);                      // 00943974
				m10 = p;
				return p;
			}
			bool hasPixmap() const          // vt+0x30 = FUN_0094332e0(9B):+0x8!=0
			{
				return m8 != nullptr;
			}
			void setPen(double width, const QColor &color, int style)  // vt+0x38 =
			{   // FUN_00943914(228B):QPen(QBrush(color),w,style,FlatCap(0),BevelJoin(0x40));
			    //   style/color/widthF/cap 四元缓存比对全等即返(语料原样)
				QPainter *p = painter();
				const QPen cur = p->pen();
				if (cur.style() == (Qt::PenStyle)style && cur.color() == color
				    && cur.widthF() == width && cur.capStyle() == Qt::FlatCap)
					return;
				p->setPen(QPen(QBrush(color), width, (Qt::PenStyle)style,
				               Qt::FlatCap, Qt::BevelJoin));
			}
			void setBrush(const QColor &c)  // FUN_0094415c(104B)@0031:8977
			{
				QPainter *p = painter();
				if (p->brush().color() == c)  // 缓存比对(语料原样)
					return;
				p->setBrush(QBrush(c));
			}
			void setFont(const QFont &f)    // FUN_00943a0e(64B)@0031:8632
			{
				QPainter *p = painter();
				if (p->font() != f)
					p->setFont(f);
			}
			void moveTo(double x, double y)  // vt+0x50 = FUN_00943300(11B):存 +0x20/+0x28
			{
				m20 = x;
				m28 = y;
			}
			void lineTo(double x, double y)  // vt+0x58 = FUN_00943a4e(103B)
			{
				QLineF ln(m20, m28, x, y);
				painter()->drawLines(&ln, 1);    // QPainter::drawLines(QLineF*,1)
				m20 = x;                         // 回写端点(语料原样)
				m28 = y;
			}
			void drawPolyline(const QPointF *pts, int n)  // vt+0x60 = FUN_00943ab6(191B)
			{
				painter()->drawPolyline(pts, n);
			}
			void drawPolygon(const QPointF *pts, int n, const QColor &penColor,
			                 const QColor &fillColor)     // vt+0x68 = FUN_009441cc(245B)
			{
				setPen(1.0, penColor, 1);        // SolidLine(语料 style 参 1)
				setBrush(fillColor);             // FUN_0094415c
				painter()->drawPolygon(pts, n, Qt::OddEvenFill);  // 语料 fillrule 0
			}
			void drawRect(double x, double y, double x2, double y2,
			              const QColor &penColor, const QColor &fillColor)
			{   // vt+0x70 = FUN_009442c2(177B):setPen(1.0)+setBrush→drawRects(w−1,h−1)
				setPen(1.0, penColor, 1);
				setBrush(fillColor);
				QRectF rr(x, y, (x2 - x) - 1.0, (y2 - y) - 1.0);
				painter()->drawRects(&rr, 1);
			}
			void fillRect(double x, double y, double x2, double y2, const QColor &color)
			{   // vt+0x78 = FUN_00943b76(88B):QPainter::fillRect(B 级高频消费面)
				painter()->fillRect(QRectF(x, y, x2 - x, y2 - y), color);
			}
			void drawRoundedRect(double x, double y, double x2, double y2,
			                     const QColor &penColor, const QColor &fillColor)
			{   // vt+0x88 = FUN_00944374(145B):r=25.0(0x4039…)RelativeSize
			    //   (批 71 槽 17;r3 猜"drawRect"误,勘正)
				setPen(1.0, penColor, 1);
				setBrush(fillColor);
				painter()->drawRoundedRect(QRectF(x, y, x2 - x, y2 - y),
				                           25.0, 25.0, Qt::RelativeSize);
			}
			void drawTextBg(double x, double y, const QFont &font, const QString &text,
			                const QColor &penColor, const QColor &bgColor)
			{   // vt+0xb0 = FUN_00943e94(184B):setFont→setPen(1.0)→setBackground
			    //   +Opaque(1)→drawText(QPointF)
				setFont(font);
				setPen(1.0, penColor, 1);
				QPainter *p = painter();
				p->setBackground(QBrush(bgColor));
				p->setBackgroundMode(Qt::OpaqueMode);       // 语料 1
				p->drawText(QPointF(x, y), text);
			}
			void drawTextClipped(double x, double y, const QFont &font, const QString &text,
			                     const QColor &penColor, const QColor &bgColor,
			                     double cx, double cy, double cx2, double cy2)
			{   // vt+0xb8 = FUN_00943f54(180B):setClipRect(+0x118)→透传 +0xb0
			    //   →setClipping(语料 bool(painter) 恒真 quirk)
				setClipRect(cx, cy, cx2, cy2);
				drawTextBg(x, y, font, text, penColor, bgColor);
				painter()->setClipping(painter() != nullptr);
			}
			void drawText(double x, double y, const QFont &font, const QString &text,
			              const QColor &color)
			{   // vt+0xc8 = FUN_00944008(128B):setFont→setPen(1.0)→Transparent(0)
			    //   →drawText(QPointF)
				setFont(font);
				setPen(1.0, color, 1);
				QPainter *p = painter();
				p->setBackgroundMode(Qt::TransparentMode);  // 语料 0
				p->drawText(QPointF(x, y), text);
			}
			void setClipRect(double x, double y, double x2, double y2)
			{   // vt+0x118 = FUN_00944088(85B):setClipRect(rect,ReplaceClip=1)
				painter()->setClipRect(QRectF(x, y, x2 - x, y2 - y), Qt::ReplaceClip);
			}
			double charWidth(const QFont &font, int ch) const  // vt+0xd8 = FUN_009433ce(69B)
			{
				return QFontMetricsF(font, m8).horizontalAdvance(ch);
			}
			double stringWidth(const QFont &font, ushort ch) const  // vt+0xe0 =
			{   // FUN_0094341c(65B)(margin 量宽槽)
				return QFontMetricsF(font, m8).horizontalAdvance(ch);
			}
			double ascent(const QFont &font) const  // vt+0xe8 = FUN_00943466(58B)
			{
				return QFontMetricsF(font, m8).ascent();
			}
			double descent(const QFont &font) const  // vt+0xf0 = FUN_009434a8(58B)
			{
				return QFontMetricsF(font, m8).descent();
			}
			double secondHeight(const QFont &font) const  // vt+0xf8 = FUN_0094330c(5B)
			{
				Q_UNUSED(font);
				return 0.0;  // 恒零 stub — 语料原样(a66f10 第二高度调用点;怪癖登记)
			}
			double leading(const QFont &font) const   // vt+0x100 = FUN_009434ea(58B)
			{
				return QFontMetricsF(font, m8).leading();
			}
			double height(const QFont &font) const    // vt+0x108 = FUN_0094352c(58B)
			{
				return QFontMetricsF(font, m8).height();
			}
			double averageCharWidth(const QFont &font) const  // vt+0x110 =
			{   // FUN_0094356e(58B)(0xa25fe2 用)
				return QFontMetricsF(font, m8).averageCharWidth();
			}
			double getDpr() const          // vt+0x128 = FUN_00944f0a(6B)
			{
				return dpr;
			}
			quint8 flag38() const          // vt+0x138 = FUN_00943312(5B)
			{
				return m38;
			}
			void setFlag38(quint8 v)       // vt+0x140 = FUN_00943318(5B)
			{
				m38 = v;
			}
			// setDpr/pixmap 已有(vt+0x130 = FUN_00944f10 / vt+0x148 = FUN_0094331e)
			// — cited — wave-2(体未读,宁缺不猜;槽位对照 r5 §2 全表):
			//   +0x00/0x08 dtor 族 009433a2/b6(局部模型栈对象同效)
			//   +0x10/0x18 Init 变体 00943748(52B)/0094377c(43B)
			//   +0x40 painter end 转发 009432ea(18B);+0x48 identity 009432fc(3B 透传)
			//   +0x80 drawPixmapTiled 00943bce(470B);+0x90 drawRoundedRect(abs)00944406(212B)
			//   +0x98 drawImageRGBA 00944c06(265B);+0xa0 drawEllipse 009444da(123B)
			//   +0xa8 drawPixmap 00943da4(240B);+0xc0 drawTextOnPixmap 00944d20(465B)
			//   +0xd0 串可见性扫描 009435f2(136B);+0x120 resetPenBrush 009440de(110B)
		} view;
		// ③ 视口:vt+0x88 分派(*vt+0x88==FUN_00a1e708 → FUN_009447a0
		//   直读):widget(editor+8)非空 → [widget+0x28]+{0x14/0x18/
		//   0x1c/0x20} 4 int → QRectF{0,0,rb−lb+1,bb−tb+1}
		//   (FUN_009445b4,122B 全读 @9180)— 内部偏移直读
		//   cited — wave-2(偏差登记:取语料空 widget 缺省分支值
		//   {0,0,1001.0,1001.0},0x408f4000)
		const QRectF vp(0, 0, 1001.0, 1001.0);
		// ④ 00a41664:带高 = (lineCount==−1)? vp.h−vp.y : lineCount
		const double bandH =
		    (lineCount == -1) ? (vp.height() - vp.y()) : (double)lineCount;
		// ⑤⑥ FUN_00a1e54d/558/582/58d(全读 @55865)+ FUN_00852bf2
		//   (93B):editor+0x113b 标志 1/0 双 guard + std::function
		//   (QPixmap/QRect 捕获)异步搬运壳 — 本核同步路径一次像素
		//   搬运同效(00a4168e-00a41772);+0x113b 消费面未建模,cited
		// FUN_00a2b07a(39B 全读 @7765)altBuffer:+0x1098 非空 →
		//   FUN_00927600()==&PTR_FUN_011bf0e0 动态类型判
		//   — cited — wave-2(占位 false)
		const bool altBuffer = false;
		// ⑦ Init:vt+0x78(editor)→dpr getter cited(Editor 表槽 14
		//   未解;模型无缩放字段,取 ctor 初始 1.0 代入 — 偏差登记)
		view.init(1.0, (int)(vp.width() - vp.x()), (int)bandH, altBuffer);
		// ⑧ setDpr(dpr):包装层透传值(0x753e=1.0 字面量)→ +0x30
		view.setDpr(1.0);
		// ⑨ FUN_00a728fc(474B 全读 @49502)逐行管线:
		QPixmap *pm = view.pixmap();
		// FUN_00a72686(621B 全读 @49449)17 步管线骨架,逐步 cited
		//   (被叫方 ~44KB 语料;DrawCtx=local_208 0x38B 工作区)
		auto drawLineBody = [&]() {
			// ===== selection chunked-deque store(r7 §1;ed+0xfb8 0x88B)=====
			// Span56/SelStoreX/平移原语批 85 上提 EditorContext.h
			//   (D2:SelStoreX 成员化 — store 生命周期 = 文档级非帧级,
			//   地址注释原样迁移;绘制侧消费 = m_ctx.selStore 成员,
			//   帧间持续,绘制帧零写入)
			using Span56 = EditorContext::Span56;         // 批 85 上提别名
			using SelStoreX = EditorContext::SelStoreX;   //   (机械限定)
			// FUN_0096beb4(31B)@0031:40707 两节点均有效门 — 真身化
			auto span_valid_beb4 = [](const Span56 &sp) {
				return sp.n0.isValid() && sp.n1.isValid();
			};
			// DrawCtx 局部模型(FUN_00a76608 4628B initDrawCtx — cited —
			//   wave-2;字段表 r5 §3 M4。init 未建模 → 全 0 缺省,偏差登记)
			struct DrawCtx {
				long long i20 = 0;        // +0x20(FUN_00a75976 参 4;行 idx 源)
				long long i28 = 0;        // +0x28 行首 idx(line_highlight styleAt 参)
				double d38 = 0.0;         // +0x38 矩形 x
				double d40 = 0.0;         // +0x40 矩形 y
				double d48 = 0.0;         // +0x48 矩形 x2
				double d50 = 0.0;         // +0x50 矩形 y2
				double d60 = 0.0;         // +0x60 x 偏(FUN_00a75b78 项)
				long long i68 = 0;        // +0x68 区间首(hex_division pos 修)
				bool b84 = false;         // +0x84 wrap 末行 u8
				long long i78 = 0;        // +0x78(FUN_00a76098 RunNode pos)
				quint32 u80 = 0;          // +0x80(FUN_00a76098 RunNode style)
				double r1d0[4] = {0, 0, 0, 0};  // +0x1d0 4-double(r3 #16 ctx1d0;
				                          //   columnMarker2 参 rect;init cited 缺省)
				QVector<const void *> nodes150;  // +0x150 runnode 指针数组
				                          //   (0x58B/项;init cited — wave-2)
				qint64 pairLo90 = 0;      // +0x90(parsePairDef lo = FUN_0096bbc0
				                          //   (ctx+0x88) = *(ctx+0x90);init cited 缺省 0)
				qint64 pairHiA8 = 0;      // +0xa8(parsePairDef hi = FUN_0096bbc0
				                          //   (ctx+0xa0) = *(ctx+0xa8);同上)
				QVector<Span56> selDeque108;  // +0x108 五控制字内嵌 deque
				                              //   (r7 §1a 同一五控制字,无需
				                              //   新模型;Span56 0x38B/项;
				                              //   initDrawCtx cited 缺省空)
			} ctx;
			// runnode 0x58B 对象布局(r3 §3 a75688 析构 stride 0x58;
			//   FUN_0096bbc0/0096bc14 = +0x08 pos/+0x10 width)
			struct RunNodeX {
				RunNode n;                // +0x00(24B;RunNode.h)
				QString s;                // +0x18(hex_division strlen==0 判)
				quint8 f50 = 0;           // +0x50(非零 = 跳过;语料 *(char*)=='\0' 门)
			};
			// s_line_highlight_a6734c(360B)@decomp-0034.c:43872 — 真身化(批 75)
			auto s_line_highlight = [&]() {
				if (!m_ctx.lineHighlightOn)          // doc+0xd4f 门(00a67368)
					return;
				// FUN_00a75976(101B)@51261 本行含 caret 门(00a6737e):
				//   ed+0xec2 早退 → fold/hex 锚行号 == ctx+0x28。
				if (m_ctx.flagEc2)
					return;
				// FUN_00975bc6(*(ed+0x1038))/FUN_00a2a8b0(*ed)/FUN_009587cc
				//   — cited — wave-2(占位 −1 = 不含 caret,安全缺省)
				const long long caretLine = -1;
				if (ctx.i28 != caretLine)
					return;
				// FUN_0095021a→FUN_0094a7f8(bit1)门:M2 inner-obj 未建模
				//   → styleTable QHash 占位常开承接(0x7547 S3 同款,登记回填)
				const QColor c = m_ctx.styleTable.value(
				    QLatin1String("line.highlight"));
				// editor_styleAt(rec,ctx+0x28) 环形槽 — 同占位(丢 %len 环绕)
				view.fillRect(ctx.d38 - m_ctx.highlightOffsetD0c, ctx.d40,
				              ctx.d48, ctx.d50, c);  // vt+0x78(00a67464)
			};
			// FUN_00a63fd6(638B)@42221 — 折线符号绘制(全读真身化):
			//   setPen(1.0,color)→moveTo×3/lineTo×5;flag=1 右向(sx=x0+2)、
			//   flag=0 左向(sx=x1−1);首 moveTo y=dVar2(语料 00a64127
			//   于调用前装载,推断为该参 — 记录)
			auto s_zigzag_a63fd6 = [&](int flag, const QColor &color, double x0,
			                           double y0, double x1, double y2) {
				view.setPen(1.0, color, 1);          // (**vt+0x38)(1.0,color,1)
				const double w = ((x1 - x0) - 2.0) - 2.0;   // 00a63f9c
				const double a = (y2 - y0) / 5.0;    // local_30
				const double b = (y2 - y0) * 0.5 + a;   // local_48
				const double dir = flag ? 1.0 : -1.0;   // local_40
				const double sx = flag ? x0 : x1 - 1.0;  // local_58 分支
				const double mx = sx + 2.0 * dir;    // moveTo x(dVar4+local_58)
				const double cx = sx + dir * ((w + w) / 3.0 + 2.0);  // 折点 x
				const double tx = sx + dir * (w + 2.0);  // 横线末 x
				const double mid = y0 + b;           // dVar2 = param_8+local_48
				view.moveTo(mx, mid);                // vt+0x50(00a6413x)
				view.lineTo(cx, mid - a);            // vt+0x58(00a6414x)
				view.moveTo(mx, mid);
				view.lineTo(cx, mid + a);            // local_30+local_48+param_8
				view.moveTo(mx, mid);
				view.lineTo(tx, mid);
				const double yEnd = (b - (a + a)) + y0;  // param_8 重赋(语料原样)
				view.lineTo(tx, yEnd);
				view.lineTo(sx + dir, yEnd);         // local_40+local_58
			};
			// s_line_wrapSymbol_a687d0(283B)@44549 — 真身化(批 75)
			auto s_line_wrapSymbol = [&]() {
				if (!m_ctx.wrapSymbolOn || ctx.b84)  // +0xda0 && !+0x84(00a687e8)
					return;
				// FUN_00a218e8(13B)@1138:(int)*(double*)(*(ed+0x10a0)+0x18)
				const double leftEdge = (double)(int)m_ctx.bufD18;
				double x0 = leftEdge + ctx.d60;      // 00a68812
				// FUN_00a76098(77B)@51642:RunNode(+0x78,+0x80,0)→
				//   FUN_00a75e9a(ctx,node,1) — cited — wave-2(占位 0)
				const double xr = 0.0;
				if (x0 <= xr)                        // max(语料原样)
					x0 = xr;
				const double x1 = x0 + m_ctx.indentWidthCf8;   // +0xcf8
				// FUN_0094a576(rec,0) 前景槽 — styleTable 占位(丢环形,登记回填)
				const QColor c = m_ctx.styleTable.value(
				    QLatin1String("line.wrapSymbol"));
				s_zigzag_a63fd6(1, c, x0, ctx.d40, x1, ctx.d50);   // 00a688c0
			};
			// s_pair_highlightMatched_a688f6(529B)@decomp-0034.c:44592 —
			//   真身化(批 80;hex_division/indentGuide(68b18)共用竖线
			//   底座):key 三选 — *(char*)(*ed+0x1128) hex →
			//   "hex.division",否则"line.indentGuide";matched 非 0 →
			//   "pair.highlightMatched" 覆盖(00a6891x,语料原样)
			auto s_pair_highlightMatched = [&](double x, bool matched) {
				const char *key =
				    m_ctx.hexMode ? "hex.division" : "line.indentGuide";
				if (matched)
					key = "pair.highlightMatched";
				// FUN_0095021a(doc,key)×2 → FUN_0094a576(rec,0) 前景槽 +
				//   editor_styleAt(rec,0) 基槽 — styleTable QHash 占位:
				//   双取色槽坍缩单值(环形序数丢,登记回填)
				const QColor c =
				    m_ctx.styleTable.value(QLatin1String(key));
				// vt+0x78 基色整竖线 (x, d40..d50)(00a689fx)
				view.fillRect(x, ctx.d40, x + 1.0, ctx.d50, c);
				// 虚线段覆盖:do-while y = d40+1 起步进 2.0、段高 1.0,
				//   门 y < d50+1.0(00a68a1x,语料原样)
				for (double y = ctx.d40 + 1.0; y < ctx.d50 + 1.0;
				     y += 2.0)
					view.fillRect(x, y, x + 1.0, y + 1.0, c);
			};
			// s_hex_division_a68ec6(511B)@44787 — 真身化(批 75;高亮腿 cited)
			auto s_hex_division = [&]() {
				if (m_ctx.hexGroupWidth > 0) {       // doc+0xd54(00a68edc)
					const long long n = ctx.nodes150.size();
					if (n != 0 && !static_cast<const RunNodeX *>(
					                      ctx.nodes150.at(0))->f50) {
						long long i = 0;
						const RunNodeX *node =
						    static_cast<const RunNodeX *>(ctx.nodes150.at(0));
						do {
							if (node->s.isEmpty()) {  // node+0x18 strlen==0
								const long long x =
								    node->n.pos - ctx.i68;   // 0096bbc0
								if (x % m_ctx.hexGroupWidth == 0
								    && x % (long long)m_ctx.hexByteWidth1118
								           != 0) {
									// FUN_00a28aea(162B)@5958 真身化:
									//   商=pos/0x1118;rem=pos%0x1118;
									//   rem>0 → 重赋 strlen(node+0x18)(语料
									//   原样 quirk:非零串长直接作加数);
									//   strlen==0 → (rem%0x111c==0)+
									//   ((rem&(宽>0xf?7:3))==0)
									double addend = (double)(node->n.pos
									    / m_ctx.hexByteWidth1118);
									const long long rem =
									    node->n.pos % m_ctx.hexByteWidth1118;
									if (rem > 0) {
										addend = (double)node->s.size();
										if (node->s.isEmpty()) {
											int sub =
											    (rem % m_ctx.hexSub111c == 0)
											        ? 1 : 0;
											const unsigned mask =
											    m_ctx.hexByteWidth1118 > 0xf
											        ? 7u : 3u;
											if ((rem & mask) == 0)
												++sub;
											addend = (double)sub;
										}
									}
									const double px = node->n.width
									    + addend * 0.5;
									if (px >= ctx.d38 && px <= ctx.d48)
										s_pair_highlightMatched(
										    px, false);  // a688f6(matched=0 语料原样;调用方自持 view/doc 参)
								}
							}
							++i;
							if (i == n)
								break;
							node = static_cast<const RunNodeX *>(
							    ctx.nodes150.at(i));
						} while (!node->f50);    // *(char*)(n+0x50)=='\0'
					}
				}
				// 尾:FUN_00a75b78(99B)@51402 真身化 = ctx[0xc](int 截断)
				//   + FUN_00a28b8c(219B,@5985 ed+0x1130 缓存:|v+1|≤eps 复算
				//   4.0×d38+1118×d20×1124+Σ a28aea(run) — hex 字段面 cited
				//   — wave-2,占位 0)− FUN_00a28ae0(9B)=4.0(0x4010… 恒常量,
				//   @5949)× doc+0xcf8 × 0.5
				const double ex = (double)(int)ctx.d60
				    + 0.0
				    - 4.0 * m_ctx.indentWidthCf8 * 0.5;
				if (ex >= ctx.d38 && ex <= ctx.d48) {   // 00a6902c
					view.fillRect(ex, ctx.d40, ex + 1.0, ctx.d50,
					              m_ctx.styleTable.value(
					                  QLatin1String("hex.division")));  // vt+0x78
				}
			};
			// s_line_columnMarker_a682e6(543B)@44394 — 真身化(批 75)
			auto s_line_columnMarker2 = [&]() {
				if (!m_ctx.columnMarkerOn
				    || m_ctx.columnMarkerMode != 0)  // +0xd58 && +0xd5c==0
					return;
				// FUN_0094a7f8(bit1)门 — styleTable 占位常开承接(登记回填)
				const double rx = ctx.r1d0[0], ry = ctx.r1d0[1];
				const double rx2 = ctx.r1d0[2], ry2 = ctx.r1d0[3];
				int ord = 0;                          // iVar8 style 序数
				for (int col : m_ctx.columnMarkers) {  // doc+0xd78 树 in-order
					// FUN_00a224f0(24B)@1735:ed+0x113b→0;否则
					//   FUN_00a16564(*(ed+0x10c8)) — cited — wave-2(占位 0;
					//   +0x113b 消费面未建模,同 0x753e ⑤⑥ 登记项)
					const double x = (double)col * m_ctx.indentWidthCf8
					    + (double)m_ctx.foldCountD34 - 0.0;
					if (rx <= x) {                    // 00a68458
						if (rx2 <= x && x != rx2)
							return;   // 越界整函数早退(语料原样 quirk)
						view.fillRect(x, ry, x + 1.0, ry2,   // x2 槽=x+1(原样)
						              m_ctx.styleTable.value(
						                  QLatin1String("line.columnMarker")));
						++ord;    // editor_styleAt(rec,ord++);QHash 占位丢序数
					}
				}
			};
			// ===== selection 三函数转写(r7 §1;批 81)=====
			// FUN_00a28516(323B)@decomp-0034.c:5696 — 真身化:store 懒建
			//   (ed+0xfb8==0 → operator_new(0x88)+0096bd82(anchor 两 pos
			//   {-1,-1}、0096bd68 flag=0)+ extras 清零;旧 store 释放腿
			//   00a28561 值语义重置同效)。00a28577:FUN_0096beb4(anchor)
			//   ==0 → FUN_00a1fc3a(ed,-1) 现选区 7-qword 载入 — cited —
			//   wave-2(scintilla_get_text_range 返回体未转写;占位跳过 →
			//   anchor 恒 {-1},与写侧未接线壳期同相)
			//   D2/批 85:懒建真调用面 = editor_replaceText(00a3360e,
			//   0034:13032 唯一真调用面;13057-13089 inline 懒建同构)
			//   — cited(我方无 replaceText 命令面;selStoreOn 置位腿
			//   随 replaceText 族落地,当前恒 false = store 未建同相)
			auto sel_store_a28516 = [&]() -> SelStoreX & {
				return m_ctx.selStore;    // 已建 store 即返(00a2858e;
				                          //   成员化后帧间持续)
			};
			// FUN_00a283a4(127B)@decomp-0034.c:5635 — 真身化:extras 探测
			//   (store 非空 && (+0x68‖+0x48 非零) && size!=0 → 返
			//   store+0x38;size 内联公式 magic-mul 0x6db6… ≡
			//   QVector::isEmpty() 等价替,怪癖登记)
			auto sel_extras_a283a4 = [&](SelStoreX *st) -> QVector<Span56> * {
				// 00a283b0 门:store 存在性 = selStoreOn(ed+0xfb8 非 0;
				//   成员化后显式门,a28516 置位面随 replaceText 落地)
				if (m_ctx.selStoreOn && st != nullptr
				    && !st->extras.isEmpty())   // size!=0 内联 ≡ isEmpty
					return &st->extras;         // = store+0x38
				return nullptr;                 // 00a28419
			};
			// FUN_0096bb52/bb04/bca4/c334 真身化批 85 上提 EditorContext.h
			//   (随 SelStoreX 成员化;vt8 写侧共用单一定义,地址注释原样)
			// 真调用面存照:a28516 懒建/ c334 平移在 Editor_vt8 写入侧
			//   (0033:56230-56277;anchor 路径 + extras 步进遍历)与会话
			//   选区通知 — 写侧 = EditorContext::notifyTextChanged(已转写,
			//   调用点待接线);本核仅结构存照
			(void)sel_store_a28516;
			// FUN_00a66ae8(1031B)s_grep_bands_a66ae8 — 批 83 提为文件级
			//   static(机械搬移,真调用面 = 0x7547 S5 四注册;
			//   本位原为存照定义,地址注释随迁至函数头)
			// s_text_selection_a67e62(603B)@decomp-0034.c:44485 — 真身化
			//   (批 81;选区亮带层:extras 全项线性迭代 + 逐项行绘委托)
			auto s_text_selection_a67e62 = [&]() {
				QVector<Span56> *ex = sel_extras_a283a4(&m_ctx.selStore); // 00a67ecb
				if (ex == nullptr)
					return;                // 00a67ed6 extras 空 → 整退
				// deque 五控制字遍历(r7 §1b)≡ QVector 线性迭代
				//   (承载等价替,怪癖登记);语料:无效项跳过步进
				for (const Span56 &sp : *ex) {
					if (!span_valid_beb4(sp))      // FUN_0096beb4 逐项门
						continue;
					// "text.selection" 样式 bg 槽 FUN_0094a806(00a67f4x;
					//   序 = ctx+0x28)— styleTable QHash 占位(丢环形
					//   序,0x753e ⑤ 同款登记回填)
					const QColor bg = m_ctx.styleTable.value(
					    QLatin1String("text.selection"));
					// 亮度压缩(00a67f8x 真身化):lum=(r*0x10+g*0xb+b*5)
					//   >>5;col={lum*0x101 ×3, a*0x101}(×0x101 复制不变,
					//   r6 怪癖);alpha>0xff 腿 = 全零 — QColor::alpha()
					//   ≤255 不可达,原样
					const int lum = (bg.red() * 0x10 + bg.green() * 0xb +
					                 bg.blue() * 5) >> 5;
					QColor band(qMin(lum * 0x101, 0xffff), qMin(lum * 0x101, 0xffff),
					            qMin(lum * 0x101, 0xffff),
					            bg.alpha() * 0x101);       // 00a67fa5
					band = band.lighter();         // QColor::lighter(默认
					                               //   因子,00a67fcx)
					// editor_paint_line_colors(e,view,doc,ctx,sp,flag,
					//   QColor(0x13),band)(00a6800x)— 行绘委托 — cited —
					//   wave-2(体未读;flag = 0094a6c4==0?0x10:0094a5ee
					//   样式位面占位,S6 同款)
				}
			};
			// s_text_selection_a680c6(532B)@decomp-0034.c:44706 — 真身化
			//   (批 81;选区行标层:ctx+0x108 内嵌 deque + 双槽色变换)
			auto s_text_selection_a680c6 = [&]() {
				if (m_ctx.flagEc2)         // *(ed+0xec2)(00a680d6)
					return;
				// 双槽 FUN_0094a790(v+0x48)/FUN_0094a806(v+0x58),序
				//   ctx+0x28 — styleTable QHash 占位(双槽坍缩单值,
				//   登记回填)
				QColor cA = m_ctx.styleTable.value(
				    QLatin1String("text.selection"));      // 00a6811d
				QColor cB = cA;
				// vt+0x10 bool(00a6817x)— r7 §1a 唯一残留:假 → 深槽
				//   darker + 主槽 lighter;asm spot check 未做 → 占位
				//   true(不换色,安全侧;登记待测)— cited — wave-2
				const bool vt10 = true;
				if (!vt10) {
					cA = cA.darker();      // QColor::darker(00a6818x)
					cB = cB.lighter();     // QColor::lighter(00a6819x)
				}
				// flag = 0094a6c4==0 ? 0x10 : 0094a5ee(00a681bx)样式
				//   位面占位 0x10(S6 同款)— cited — wave-2
				for (const Span56 &sp : ctx.selDeque108) { // +0x108 deque
					// editor_paint_line_colors(e,view,doc,ctx,sp,flag,
					//   cA,cB)(00a6820x)— 行绘委托 — cited — wave-2
					Q_UNUSED(sp);
				}
			};
			// FUN_00a76608(4628B)initDrawCtx — cited — wave-2
			// s_text_controlChar_a77836(&ctx)(4123B)— cited — wave-2
			// s_grep_mark_a6afa2(ed, doc, &ctx)(440B)— cited — wave-2
			if (!m_ctx.hexMode) {        // *(char*)(*ed+0x1128)==0
				// === s_PairColor_a72272(1001B)@decomp-0034.c:
				//   49296 — 真身化(批 84;括号对色带层:RunStyles
				//   u8 slice 消费 — 块状态机 + zstd 膨胀腿)===
				{
					// FUN_0096bbc0(ctx+0x88)/(ctx+0xa0)(5B ×2)
					const qint64 pcLo = ctx.pairLo90;  // 00a7227e
					const qint64 pcHi = ctx.pairHiA8;  // 00a72286
					Q_UNUSED(pcLo);                    // run 界 cited
					Q_UNUSED(pcHi);
					// --- slice 建(FUN_00935584(710B)@0030:
					//   33611,读体)--- *(ed1+0xa8)==0 → 0x20
					//   obj{vt=Uint8RunStyles,+8=piecetable(new
					//   0x60 init),+0x10=wrapper(new 0x30:
					//   FUN_0093fc60 init→gapbuffer_reallocate
					//   (w,0,0,2) 初始 2 块)};lo/hi 不见于可读体
					//   (r7 §2a:Ghidra 截断,疑入 0093fc60 —
					//   小注);else 腿 FUN_00a00b06(410B 未读)
					//   — cited。壳期 ed+0xa8 恒 0(块生产者未读
					//   — r7 §2b 残留)→ 局部空模型:runs 恒 0
					//   — cited — wave-2
					struct PcBlock {      // 块布局(r7 §2b,三源互证:
						quint8 *buf = nullptr;   // +0x08
						int cmpLen = 0;   // +0x10(0088ff00/
						int uncLen = 0;   // +0x14 a72272/0088f940)
						int rawCount = 0; // +0x18(原始段计数)
						int offBase = 0;  // +0x1c(偏移基)
						int state = 0;    // +0x2c 0=raw/1=待清/
						                  //   2=压缩待膨胀
						// +0x20 QReadWriteLock/+0x28 spinlock —
						// 单线程行为模型不承载(r7 §1c 同款)
					};
					struct PcSlice {      // 0x20 obj 局部模型
						int runs = 0;     // piecetable(+8)runs 数
						int total = 0;    // wrapper+0x10
						PcBlock *cached = nullptr; // +0x18
						QVector<PcBlock> blocks;   // gapbuffer
						                           // 初始 2 块等价替
						PcSlice()
						    : blocks(2)   // gapbuffer_reallocate
						{
						}             //   (w,0,0,2)
					} slice;
					m_ctx.resetTriggerGroups(
					    QLatin1String("PairColor"));  // 009257a8
					m_ctx.markerGroup(QLatin1String("PairColor"),
					    false);                       // 00925c02
					// --- 块描述子(FUN_0088f940(1448B)@0027:
					//   44030,全读)--- 命中窗缓存(desc+0x10
					// runIdx/+0x18 block/+0x20 baseIdx/+0x28 起
					// /+0x30 止;threadlocal QMap 按 currentThread
					// 缓存,窗内直返 0088f9d3)→ miss:fill_range(u)
					// →run→块指针数组 u8 槽(gap 检索,同构 0088fc0x)
					// → run_start_at 前/后界 → 块 state!=0 腿
					// superbuf_insertRuns(param_1,block,1)(0088fa8x)
					// → spinlock 线程缓存回写(0088fad2-0088fc19;
					// sched_yield/nanosleep 自旋阶梯)。模型承接 =
					// blocks 平铺直槽位;run→块映射/run 界/线程
					// 缓存 — cited — wave-2(runs==0 不可达;生产者
					// 落地时升级)
					auto pc_desc_88f940 =
					    [&slice](int) -> PcBlock * {
						    Q_UNUSED(slice);
						    return nullptr;   // 壳期恒空(见上)
					    };
					// 取值:buf[idx]−1;byte==0 → 0xffffffff=无值
					//   (r7 修正:存 0 为无,存 1..7 → 色 0..6);
					//   idx∈[+0x18,+0x14) 走 +0x1c 偏移;越界 →
					//   DAT_011c2510−1(全局默认字节,数据段直读
					//   未建模 — 推断 0 → −1,登记);缓存块快径
					//   (else 支)以裸 u 索引 + 无锁(语料原样
					//   quirk 00a723c8-00a7239e)
					for (int u = 0; u < slice.runs; ++u) { // 00a7237x
						PcBlock *blk = slice.cached;   // +0x18
						int idx = u;                   // iVar3
						quint32 v = 0xffffffffu;       // uVar10
						if (blk == nullptr) {          // 00a72386
							// total 门:u < wrapper+0x10
							//   (语料 *2>>1 打包噪声 = total)
							if (u < slice.total) {     // 00a7238a
								blk = pc_desc_88f940(u); // desc+0x18
								// idx = u − desc+0x20 baseIdx
								//   (块界未建模恒 0)
								// QReadWriteLock(+0x20)
								//   lockForRead(00a7240x;null 块
								//   守卫为模型侧新增,语料不可达)
								if (blk != nullptr) {
									if (blk->state == 2) { // 00a7242x
										// spinlock_lock_backoff
										//   (+0x28)→复查仍 2:
										//   malloc(uncLen)→
										//   zstd_ctxCreate(dst,
										//   uncLen,src=+0x8,
										//   cmpLen=+0x10)→
										//   free 旧→+0x08=dst/
										//   +0x10=+0x14/
										//   +0x1c=0/+0x2c=0
										//   (00a7246x-00a7251x)。
										//   zstd 委托真库
										//   (EXT-BOUNDARY;语料
										//   包装 00bb88b0 全
										//   zstd 内部态 = 真库
										//   ZSTD_decompress
										//   等价,声明面
										//   src/Ext/ZstdFace.h)。
										//   libzstd 未链接
										//   (CMake 写域外)
										//   → no-op sink
										//   — cited — wave-2
										blk->state = 0; // 膨胀完成
									} else if (blk->state == 1) {
										blk->state = 0; // 00a7263x
									}
									// unlock(00a7258x)
								}
								if (blk == nullptr)
									v = 0xffffffffu; // 默认−1
								else if (idx < blk->rawCount) {
									if (idx >= 0)
										v = quint32(blk->buf[idx]) - 1u;
								}              // 00a72544
								else if (idx < blk->cmpLen)
									v = quint32(
									    blk->buf[blk->offBase + idx])
									    - 1u;      // 00a7253x
								// 缓存回写:语料 a72272 不写
								//   wrapper+0x18(缓存由 RunStyles
								//   机制维护)— 模型同不写
							} else {
								v = 0xffffffffu; // DAT−1 00a7239a
							}
						} else {
							// 缓存块快径(无锁,裸 u 索引
							//   — 语料原样 quirk)
							if (idx < blk->rawCount)
								v = quint32(blk->buf[u]) - 1u;
							else if (idx < blk->cmpLen)
								v = quint32(
								    blk->buf[blk->offBase + u])
								    - 1u;
						}
						if (v < 7) {          // 00a7239e v<7 才画
							// s/e = run_start_at(u)/(u+1)
							//   (vt+0x38/0x40 直呼 runstyles 版
							//   — run 界未建模)— cited — wave-2
							// FUN_0094fd86(pair,doc,v)(90B 已读
							//   @0031:18835):doc+0xe30 16B/项
							//   u16 色对表,越界 {0,0xffff,0,0}
							//   — 表未建模 → cited — wave-2
							// FUN_00926856(ed,grp,lo+s,e−s,
							//   0x14,pair,"",0)(197B 已读
							//   @0030:21711)= style_getColorRgba
							//   (E+0x100) 门 → SciSchemeChange
							//   Event(0x3f0) 区间组播 — 0x3f0
							//   组播 cited — wave-2
							//   (EditorContext markerFill 注同款)
						}
					}
					// 引用减 slice vt+8(00a7259x;slice 局部,
					//   出栈同效)
				}
				// === editor_parsePairDef(871B)@decomp-0034.c:45827 — 真身化(批 79)===
				{
					// FUN_00a24e72(12B)@0034:3596 整表堆拷(3-long/项步进;
					//   语料 operator_delete → QList 值语义承接)
					const QList<EditorContext::PairDefEntry> pairs =
					    m_ctx.pairDefs;
					m_ctx.resetTriggerGroups(QLatin1String("Pair")); // 009257a8(M,"Pair")
					if (!pairs.isEmpty()) {
						// *(char**)(*ed+0xfd8) 语法名作 styleLookup key
						const char *syn = m_ctx.syntaxNameFd8;
						// FUN_0095021a(doc,key)→009ba94c strlist_bsearch,未命中
						//   →默认记录;M2 inner-obj 未建模 → styleTable QHash 占位
						//   (0x7547 S3/s_line_highlight 同款,登记回填)
						const QColor rec = m_ctx.styleTable.value(
						    QLatin1String(syn ? syn : ""));
						// FUN_0094a6a4(19B)= !0094a5ee(8B,*rec 内层+0x40 u8):==0
						//   才画;占位:命中即画(门位丢,登记回填)
						if (rec.isValid()) {
							// FUN_00925c02(ed,"Pair",0) 组注册 — 模型名柄
							m_ctx.markerGroup(QLatin1String("Pair"), false);
							// 区间:lo = FUN_0096bbc0(ctx+0x88)=*(ctx+0x90)(5B);
							//   hi = FUN_0096bbc0(ctx+0xa0)=*(ctx+0xa8)(00a6b61x)
							const qint64 lo = ctx.pairLo90;
							const qint64 hi = ctx.pairHiA8;
							for (const EditorContext::PairDefEntry &p : pairs) {
								if (lo <= p.close) {           // 00a6b62a
									if (hi < p.open)
										break;                     // 00a6b63a 有序早退(原样)
									// FUN_0092671c(ed,grp,p.open,p.close−p.open,
									//   0094a5ee(rec),2,syntaxName,0)
									m_ctx.markerFill(QLatin1String("Pair"),
									    p.open, p.close - p.open, rec.alpha(),
									    2, QByteArray(syn ? syn : ""), false);
								}
							}
						}
					}
				}
				// === s_text_hotSpot_a6aae6(436B)@decomp-0034.c:45546 — 真身化(批 79)===
				{
					m_ctx.resetTriggerGroups(QLatin1String("HotSpot")); // 009257a8(M,"HotSpot")
					// FUN_0095021a(doc,"text.hotSpot") — styleTable 占位(同上)
					const QColor rec = m_ctx.styleTable.value(
					    QLatin1String("text.hotSpot"));
					if (m_ctx.hotspotLo1048 != -1) {              // 00a6ab76
						// FUN_0094a6a4(rec)==0 才画(00a6ab81);占位:命中即画
						if (rec.isValid()) {
							// FUN_00925c02(ed,"HotSpot",0)— 模型名柄
							m_ctx.markerGroup(QLatin1String("HotSpot"), false);
							// FUN_0092671c(ed,grp,lo,hi−lo,0094a5ee(rec),2,
							//   "text.hotSpot",0)— len=hi−lo 可负,原样(r6 怪癖)
							m_ctx.markerFill(QLatin1String("HotSpot"),
							    m_ctx.hotspotLo1048,
							    m_ctx.hotspotHi1050 - m_ctx.hotspotLo1048,
							    rec.alpha(), 2, QByteArray("text.hotSpot"), false);
						}
					}
				}
			}
			// s_TriggerHighlightTextFont_a6b872(5995B)— cited — wave-2
			// FUN_00a6b17e(492B)— cited
			// s_line_background_a6e89e(6307B)— cited — wave-2
			// s_line_columnMarker_a674c4(…,0)(2390B)— cited
			if (m_ctx.hexMode) {
				// FUN_00a67e56(11B)— cited
			}
			s_line_highlight();          // s_line_highlight_a6734c(360B)真身化
			// FUN_00a6d05e(…,1)(6088B)— cited — wave-2
			s_text_selection_a67e62();   // s_text_selection_a67e62(603B)真身化
			s_text_selection_a680c6();   // s_text_selection_a680c6(532B)真身化
			if (!m_ctx.hexMode) {
				s_line_columnMarker2();  // s_line_columnMarker_a682e6(543B)真身化
				// FUN_00a68b18(941B)@decomp-0034.c:44655 — 真身化(批 80;
				//   缩进参考线,依赖 a688f6 底座)。doc 门 +0xd44;wrap 判
				//   FUN_009587b2 / 行号归一 FUN_009588b8 — buffer 直读
				//   (00925200/00958498 流)— cited — wave-2(占位常过/
				//   原值,initDrawCtx 回填);缩进列 FUN_009284c6(135B
				//   全读 @0030:24393,空格++/tab 升 tab 列)— cited 占位 0;
				//   ±窗回扫/前扫腿(00a68c1x-00a68dxx:窗 = max(0x14,
				//   FUN_00a20438(ed,0)) 可视行,回扫跳 fold、mode==1 须
				//   FUN_00a24e8a(ed,ln,0)&0xc==8、前扫遇更小缩进 break;
				//   pairDef 腿 ed+0xfd4>0 且对数>1 且末对 open≤line<
				//   末对 close → max=max(fd4);mode!=2 时 max+=unit)
				//   — fold/buffer API cited 占位 0(fd4 写侧未落,腿不
				//   触发,同相);FUN_00a75c8e ctx[0x36] 缓存(216B 全读
				//   @51474:|cache+1|≤eps 复算 fd4×cf8,门 fd4>0/+0x84/
				//   首末对夹 ctx+0x68)— cited 占位 0(同相)
				auto s_indentGuides = [&]() {
					if (!m_ctx.indentGuidesD44)   // doc+0xd44 门(00a68b34)
						return;
					const int unit = m_ctx.field213_260;  // *(int*)(ed+0x260)
					int maxInd = 0;   // FUN_009284c6 + 窗扫腿 — cited 占位 0
					// fVar11 = (float)maxInd/(float)unit 截断(语料原样);
					//   0/0 → NaN → (int)NaN = 0,循环不进(同相)
					const float guides = (float)maxInd / (float)unit;
					// dVar12 = unit × doc+0xcf8 步宽(00a68bax)
					const double step = (double)unit * m_ctx.indentWidthCf8;
					// FUN_00a224f0(ed)(24B 全读 @1735):+0x113b 非零 → 0,
					//   否则 FUN_00a16564(*(ed+0x10c8)) — cited — wave-2
					//   (columnMarker2 同款占位 0)
					const long long x0 = 0;
					for (long long i =
					         (long long)(((double)x0 + 0.0001) / step) - 1;
					     i < (int)guides; ++i) {
						const double x = (double)i * step + ctx.d60;
						if (ctx.d38 <= x && x != ctx.d38) {  // != 守卫原样
							if (ctx.d48 <= x && x != ctx.d48)
								return;              // 越右界整函数早退
							// FUN_00a75c8e 值 + ctx+0x60 与 x 差 ≤
							//   2.2e-16 → matched(00a68e6x)
							const double pairCacheX = 0.0;
							const double dx =
							    pairCacheX + ctx.d60 - x;
							s_pair_highlightMatched(
							    x, dx >= -2.220446049250313e-16
							        && dx <= 2.220446049250313e-16);  // ABS≤2.2e-16
						}
					}
				};
				s_indentGuides();        // FUN_00a68b18 真身化(批 80)
			} else {
				s_hex_division();        // s_hex_division_a68ec6(511B)真身化
			}
			// s_text_whiteSpace_a70196(…,0)(8299B)— cited — wave-2
			// 语料原样双判:(hex==0)||(FUN_00a72266(11B), hex==0)
			//   → 体仅非 hex 进;FUN_00a72266 仅 hex 进 — cited
			if (!m_ctx.hexMode) {
				// FUN_00a6710c(362B)— cited(后续批)
				s_line_wrapSymbol();     // s_line_wrapSymbol_a687d0(283B)真身化
			}
			// FUN_00a6d05e(…,0)(6088B 二过:先 1 后 0)— cited
			// FUN_00a6626a(2165B)— cited
			// FUN_00a64838(1193B)— cited
			// FUN_00a661a0(201B)— cited
			// FUN_00a6447a(ed)(14B)— cited
			// FUN_00a75688(&ctx) 析构(749B)— cited
		};
		if (pm != nullptr) {
			// FUN_009502c6(12B 透传:doc+0xe00 → FUN_009ba966;+0x1067
			//   字节转发)— fill 色 — cited — wave-2(色值未解,
			//   Invalid QColor 占位)
			const QColor bg;
			pm->fill(bg);                // 00a729a1;fillRect =
			                             //   QRectF(pm->rect()) y+=doc+0xcc4
			                             //   (0xa7296c 组合,记录未展开)
			// 逐行:param_5<param_6 才进循环,行号 ++(from==to 不画)
			for (long long line = x0; line < x1; ++line) {
				// s_margin_timestamp_a696b6(ed,view,doc,line)
				//   (3668B)— cited — wave-2
				drawLineBody();
			}
			// 尾:QPixmap(out, pm) copy-construct → out(00a729xx)
			out = QPixmap(*pm);
		}
		// pm==0 → out 保持默认空(00a7291b 前支)
		// ⑩ out←pm 共享搬运;⑤⑥ guard 回写(+0x113b=0);view 析构
		//   (vt+8 = FUN_0094377c SurfaceImpl_dtor 43B,栈对象同效)
		return QVariant(out);
	}
	case 0x753f:     // 槽 +0xc0 = FUN_00948b9b(thunk→FUN_00948b5a)
	                 //   — 槽已定位(批 66),体 cited
		return QVariant(0);
	case 0x7541:     // FUN_00a204a0(216B)scrollToFraction:
	                 //   target = f*len − lines*f 夹取 → scroll obj
	                 //   +0x10c8{+0x30/+0x38/+0x3c} — cited(滚动
	                 //   几何 Phase-4b)
		return QVariant(0);
	case 0x7544: {   // FUN_00a4186e(86B)→ FUN_00a41552(649B 渲染核)
	                 //   可视区 pixmap(pos..pos+lines,高参 −1=实际视高)
	                 //   真身化(批 70)
		// === 包装层 FUN_00a4186e(全读 @decomp-0034.c:20725)===
		// FUN_00a20580(12B):ed+0x10c8 scroll obj → FUN_00a17428(43B
		//   全读 @49580):(vt+0xe0)(scroll+0x18,2)非空 → +0x40
		//   — 滚动几何 Phase-4b cited;可视首行按混合边界承接真库
		const long long from = send(SCI_GETFIRSTVISIBLELINE, 0, 0);
		// 视口(同 0x753e ③;FUN_009445b4 内部直读 cited,取缺省分支)
		const QRectF vp(0, 0, 1001.0, 1001.0);
		// FUN_00a20438(103B 全读 @86):(vp.h−vp.y)/+0xd04 行高,ceil
		//   夹 ≥1(SCI_LINESONSCREEN 承接先例:0x7547;此处按语料
		//   算式原样转写)
		const long long textLen = send(SCI_GETLENGTH, 0, 0);
		const int lineH = qMax(1, (int)send(SCI_TEXTHEIGHT, 0, 0));
		const int vh = (int)(vp.height() - vp.y());
		int visCount = vh / lineH;
		visCount = (visCount + 1) - ((vh % lineH == 0) ? 1 : 0);  // ceil(00a204a2)
		if (visCount < 1)
			visCount = 1;
		// FUN_00a20604(97B 全读 @192):min(textLength, from+visCount)
		//   −1 夹 ≥0(语料原样;editor_textLength → SCI_GETLENGTH
		//   0x7547 同款映射)
		long long to = textLen;
		if (from + visCount <= textLen)
			to = from + visCount;
		to = to - 1;
		if (to < 0)
			to = 0;
		// === 渲染核 FUN_00a41552(与 0x753e 同体;dpr = param_1 透传:
		//   dispatch 未设(批 65 未消费/批 67 勘正:透传至 setDpr),
		//   寄存器残留值不可建模 — 偏差登记:占位 0.0)===
		QPixmap out;                                 // ① 00a41587
		struct SurfaceView {                         // ② 同 0x753e(FUN_00944556
			QPixmap *m8 = nullptr;       // +0x08      + ctor FUN_0094367a)
			void *m10 = nullptr;         // +0x10
			quint8 m18 = 0;              // +0x18
			quint8 m19 = 0;              // +0x19
			quint8 m1a = 0;              // +0x1a
			void *m20 = nullptr;         // +0x20
			void *m28 = nullptr;         // +0x28
			double dpr = 1.0;            // +0x30
			quint8 m38 = 0;              // +0x38
			QPixmap *pixmap() const { return m8; }   // vt+0x148=0094331e
			void setDpr(double d) { dpr = d; }       // vt+0x130=00944f10
			void release()                           // vt+0x28=0094333e
			{
				m8 = nullptr;
				m10 = nullptr;
				m18 = 0; m19 = 0; m1a = 0;
			}
			void init(double d, int iw, int ih, bool alt)  // vt+0x20=009437a8
			{
				release();
				m19 = 1;
				if (ih < 1) ih = 1;
				if (iw < 1) iw = 1;
				QPixmap *pm = new QPixmap((int)((double)iw * d),
				                          (int)((double)ih * d));
				pm->setDevicePixelRatio(d);
				m8 = pm;
				const double x =
				    (double)(int)(d * 65536.0) * 1.52587890625e-05;
				const double r = qRound(x);
				double fr = x - r;
				if (fr < 0)
					fr = -fr;
				double ar = r < 0 ? -r : r;
				double ax = x < 0 ? -x : x;
				const double mx = (ar <= ax) ? ar : ax;
				m18 = (fr * 1000000000000.0 <= mx) ? 1 : 0;  // FUN_009436c2
				m38 = (quint8)alt;           // vt+0x140 默认实现分支
			}
		} view;
		const double bandH =
		    /* param_6=−1(0xffffffff,00a4185a)*/ vp.height() - vp.y();
		view.init(1.0, (int)(vp.width() - vp.x()), (int)bandH, false);
		view.setDpr(0.0);
		QPixmap *pm = view.pixmap();
		auto drawLineBody = [&]() {
			// 17 步管线骨架 — 逐腿 cited,同 0x753e
			//   (FUN_00a72686 621B;initDrawCtx 00a76608 4628B;
			//   controlChar a77836/grepMark a6afa2/[非hex:PairColor
			//   a72272/parsePairDef/hotSpot a6aae6]/Trigger a6b872/
			//   a6b17e/lineBG a6e89e/columnMarker a674c4(0)/[hex:
			//   a67e56]/highlight a6734c/d05e(1)/selection a67e62+
			//   a680c6/[非hex:columnMarker2 a682e6+a68b18|hex:
			//   hex_division a68ec6]/whiteSpace a70196/[非hex:
			//   a6710c+wrapSymbol a687d0;语料双判含 a72266]/d05e(0)
			//   /a6626a/a64838/a661a0/a6447a/ctx 析构 a75688)
			//   — 全部 cited — wave-2
		};
		if (pm != nullptr) {
			const QColor bg;             // FUN_009502c6 — cited — wave-2
			pm->fill(bg);                // 00a729a1(QRectF+y+doc+0xcc4 组合未展开)
			for (long long line = from; line < to + 1; ++line) {
				// s_margin_timestamp_a696b6(3668B)— cited — wave-2
				drawLineBody();
			}
			out = QPixmap(*pm);          // 00a729xx copy-construct
		}
		return QVariant(out);
	}
	case 0x7545:     // FUN_00933366(892B)序列化导出(批 69 勘正:
	                 //   非条目建立 —— 标记行收集(0093f7aa)→
	                 //   QDataStream 序列化 → E+0x250 append →
	                 //   SciScrollBarMarkEvent(0x414) 广播)— cited
		return QVariant(0);
	case 0x7546:     // 槽 29(vt+0xe8,self,1)= 水平滚动条可见性
	                 //   (批 66 勘破:实例 vptr 0x11afd30/派生重写
	                 //   FUN_00948a48:policy 判定 + QScrollBar bit15)
	                 //   → SCI 承接(混合边界:标准行为委托真库)
		return QVariant((bool)send(SCI_GETHSCROLLBAR));
	case 0x7547: {   // s_line_modified_a72ad6(3008B)S1-S4(批 69):
	                 //   S5 grep 注册(FUN_00a66ae8)注册点真身/体内
	                 //   cited;S6 逐条目绘(49727-49875)态机真身化
		const double dh = a.toDouble();                  // 00a72ad9
		const double dw = b.toDouble();                  // 00a72aef
		QPixmap pm(qRound(dw), qRound(dh));              // S1 00a72b14
		pm.fill(QColor(0, 0, 0, 19));                    // S1 00a72b6e
		if (dh > 0.0) {
			QPainter p(&pm);                             // S1 00a72bbd
			// ===== S2 度量(00a72cb8-00a72d3d)真身化 =====
			const qint64 textLen = send(SCI_GETLENGTH, 0, 0);
			// FUN_00a20438(self,0):floor((bot-top)/行高),<1 夹 1
			//   —— SCI_LINESONSCREEN 承接成立(b1b §1)
			const int visLines = qMax(1, int(send(SCI_LINESONSCREEN, 0, 0)));
			qint64 denom = visLines;                     // 00a72cd4 max 怪癖(原样)
			if (denom < textLen)
				denom = textLen;
			double rowH = dh / double(denom);            // 00a72d0e
			double bw = dw / 3.0;                        // 00a72d1a
			int fstep = 1;                               // 00a72d1e
			if (rowH < 3.0) {
				rowH = 3.0;
				fstep = int(textLen * 3.0 / dh);         // 00a72d26
			}
			// ===== S3 样式装载(00a72d4c-)=====
			// 门 *(*(this)+0x113a)(00a72d4c)未建模,常开承接
			//   (偏差登记);样式表 +0xe00 未建模 → styleTable 占位
			QColor cSaved, cUnsaved, cModified;          // S3 装载(值取 styleColor,
			                                             //   空表缺省=white 回填)
			auto styleColor = [&](const char *key) -> QColor {
				// 0095021a(+0xe00)→ 0094a7f8(bit1 门,常开承接)→
				//   0094a5b2 环形 16B 槽 —— QHash 占位(丢 bit1 门,
				//   登记回填);空表缺省腿回填:0094a5b2 尾
				//   return &DAT_011c25e0 = _INIT_131(005204a8)
				//   QColor(&DAT_011c25e0,3) = Qt::GlobalColor(3) =
				//   white(r255g255b255a255,二进制实测;DAT 位于
				//   RW LOAD 文件映像零,值由 ctor 运行期定义)。
				//   同族 0094a576(v+0x20 表)空→DAT_011c25d0 =
				//   GlobalColor(2)=black,bit0 腿不在此路
				const auto it = m_ctx.styleTable.constFind(
				    QLatin1String(key));
				return it == m_ctx.styleTable.cend()
				    ? QColor(Qt::GlobalColor(3)) : it.value();
			};
			cSaved = styleColor("line.saved");           // 00a72d56
			cUnsaved = styleColor("line.unsaved");       // 00a72dd0
			cModified = styleColor("line.modified");     // 00a72e44
			// ===== S4 色带迭代(49632-49768)=====
			// 坐标序定案(b1b §4):QRectF(0, y0, bw, y1-y0),行向沿 y
			const qint64 lineCount = send(SCI_GETLINECOUNT, 0, 0);
			char savedF = 1, unsavedF = 0;               // 00a72d4e 预置(原样)
			auto markerBand = [&](qint64 from) -> QPair<qint64, qint64> {
				// FUN_00927a78(365B)— cited — wave-2(*(M+0xf0)
				//   flagmask 族未落地;桩 = 无带,安全缺省)
				Q_UNUSED(from);
				return {-1, -1};
			};
			QPair<qint64, qint64> band = markerBand(0);  // 00927a78
			qint64 st = band.first, en = band.second;
			if (st != -1) {
				// 逐带 fillRect(QRectF(0, y0, bw, y1-y0), 色按
				//   saved/unsaved/modified 三路选)—— 迭代体依赖
				//   markerBand 真身,fold 跳步(009589f0/009588b8)
				//   — cited — wave-2
			}
			Q_UNUSED(en); Q_UNUSED(lineCount);
			Q_UNUSED(savedF); Q_UNUSED(unsavedF);
			Q_UNUSED(cSaved); Q_UNUSED(cUnsaved); Q_UNUSED(cModified);
			// ===== S5 grep 4 注册(49720-49725)真调用接线(批 83)=====
			// FUN_00a66ae8(1031B)= 文件级 static s_grep_bands_a66ae8
			//   (0x753e 存照位机械搬移)。体内分级:① margin 行对象表
			//   FUN_009258b2 → M 未建模 → nullptr → 段尾 return
			//   (00a66b07 同相);② grep 浮点表 ③ run 范围 ④ 色腿
			//   (色槽 asm check 未做)⑤ 条带循环 — ①②③⑤ cited —
			//   wave-2。帧对应:T = {pixH=dh, denom=S2 denom(max 怪癖
			//   已在 S2), rowH, W/3=bw, wrap=fstep}(a72ad6@49613-49630)。
			s_grep_bands_a66ae8(m_ctx, p, 8, 8, "grep.mark",
			    dh, denom, rowH, bw, fstep);             // 00a72ec1
			s_grep_bands_a66ae8(m_ctx, p, 6, 0, "grep.mark",
			    dh, denom, rowH, bw, fstep);             // 00a72ed7
			s_grep_bands_a66ae8(m_ctx, p, 5, 0, "grep.match",
			    dh, denom, rowH, bw, fstep);             // 00a72ee9
			s_grep_bands_a66ae8(m_ctx, p, 7, 0, "grep.mark",
			    dh, denom, rowH, bw, fstep);             // 00a72efb
			// ===== S6 逐条目绘(49727-49875)=====
			// E+0x250 无锁遍历(怪癖#2 原样:不加 mutex;语料
			//   QList header +8/+0xc/+0x10 → range-for 等价)
			for (const QByteArray &entry : m_ctx.eSerialEntries) {
				QDataStream ds(entry);                   // 00a731ca
				QByteArray key, modstr, data;
				ds >> key >> modstr >> data;             // 00a731d7 ×3
				Q_UNUSED(key);                           // 仅 S7 释放腿
				// 中段串查样式(00a7323c;FUN_00a65f12 raw-byte
				//   std::string → fromLatin1 字节保真承接)
				const auto it = m_ctx.styleTable.constFind(
				    QString::fromLatin1(modstr));
				if (it == m_ctx.styleTable.cend())
					continue;                            // 00a73199
				// 四路判位(00a73265):0094a86e(b+9 bit4)→
				//   0094a790(v+0x48 表)/ 0094a87c(b+9 bit5)→
				//   0094a806(v+0x58 表)/ 0094a786(b+8 bit0)→
				//   0094a576(v+0x20 表)/ 0094a7f8(b+8 bit1)→
				//   editor_styleAt(v+0x30 表)— 样式记录位面未落地,
				//   统一落 editor_styleAt 同面(= S3 占位),分派腿
				//   cited — wave-2;空表默认色缺省腿已回填(S3 同款:
				//   editor_styleAt 空→DAT_011c25e0=GlobalColor(3))
				const QColor c = it.value();             // 0094a5b2
				if (!c.isValid())                        // local_108==0
					continue;                            // 00a73199
				// CSuperBuffer 态机真身化:ctor FUN_00a92656(36B,
				//   +0x00 ba/+0x08 cache/+0x10 pend/+0x18 pos/+0x1c
				//   end)/ hasNext FUN_00a927c8(23B)/ nextChar
				//   bytestream_nextChar(00a928a6 198B)
				const char *d = data.constData();
				const int n = data.size();
				int bpos = 0;                            // +0x18
				quint64 cache = 0;                       // +0x08
				qint64 pend = 0;                         // +0x10
				auto xprRead = [&]() -> quint64 {        // 00a923cd
					// FUN_00a9230c(26B):len = 首字节最低置位
					//   bit + 1(0 字节 → 隐含 bit8 → len 9)
					const unsigned char c0 =
					    (unsigned char)d[bpos];
					unsigned v =
					    ((unsigned)(c0 >> 7) << 8) | c0 | 0x100u;
					int len = 0;
					while (!((v >> len) & 1))
						++len;
					++len;
					if (len > 8) {                       // 00a92413
						quint64 r;                       // 9 字节
						memcpy(&r, d + bpos + 1, 8);     // 形态
						bpos += 9;                       // 前 1 字节
						return r;                        // 直读
					}
					quint64 r = 0;
					memcpy(&r, d + bpos, len);           // LE n 字节
					bpos += len;
					return r >> len;                     // 00a924a0
				};                                       // (v<<s1)>>s2
				auto nextChar = [&]() -> quint64 {       // 00a928a6
					if (pend == 0) {
						if (n <= bpos) {                 // end≤pos
							pend = -1;                   // 00a928c0
							return cache;                // 哨兵
						}
						cache = xprRead();               // 00a928d1
						// NUL 重复转义(语料原样):\0 后跟
						//   重复计数 varint;peek 的 +0x18 偏移
						//   特判 = QArrayData compact 读(此处
						//   constData() 等价承接)
						if (bpos < n && d[bpos] == '\0') {
							++bpos;                      // 00a9290d
							pend = (qint64)xprRead() - 1; // 2918
						}
						return cache;                    // 00a9291e
					}
					--pend;                              // 00a9286d
					return cache;                        // 00a92875
				};
				auto hasNext = [&]() -> bool {           // 00a927c8
					return bpos < n ? true : pend != 0;
				};
				// 逐码点循环(00a7331a-00a7344c)真身化:pos 累加、
				//   fold 步行去重、行向 y 条带。fstep 可为 0(S2 截断)
				//   → 语料直除(SIGFPE 怪癖,原样保留不修,QUIRKS 登记)
				qint64 pos = 0, lastStep = -1;           // 00a7331a
				bool has = hasNext();                    // 00a73326 首检
				for (;;) {
					if (!has)
						break;                           // → 下条目
					pos += (qint64)nextChar();           // 00a7332e
					if (pos / fstep == lastStep)         // 00a7333a
						continue;        // 同步行:has 不刷新(原样)
					// FUN_009589f0(135B)fold 感知行号 — SCI 承接
					//   (标准行为委托;fold 通道 00958536 cited)
					const qint64 line =
					    send(SCI_LINEFROMPOSITION, pos, 0);
					double y = double(line) * dh / double(denom);
					const double cap = dh - rowH;        // 00a73354
					if (y > cap)
						y = cap;                         // 00a7335c
					// fillRect 定案坐标序(b1b §4,同 S4):
					//   QRectF(0, y, bw, rowH),行向沿 y
					p.fillRect(QRectF(0, y, bw, rowH), c); // 00a73366
					has = hasNext();                     // 00a73444
					lastStep = pos / fstep;              // 00a7344c
				}
			}
		}
		return QVariant::fromValue(pm);
	}
	case 0x7548:     // 槽 29 kind=2 = 垂直滚动条可见性(同 0x7546)
		return QVariant((bool)send(SCI_GETVSCROLLBAR));
	case 0x7549:     // FUN_00930338(654B)— cited — wave-2
		return QVariant(0);
	case 0x754a:     // 槽 +0xd0 = FUN_00948c89(thunk→00948c6e;体未录)
	                 //   — 槽已定位(批 66 vtable 勘破),体 cited
		return QVariant(0);
	case 0x754b:     // 槽 +0xf8 kind=1(FUN_00948ab0 全读):policy!=
	                 //   AlwaysOff 时 setHorizontalScrollBarPolicy(v^1)
	                 //   = v?AsNeeded:AlwaysOff — QAbstractScrollArea 承接
		if (m_edit->horizontalScrollBarPolicy() != Qt::ScrollBarAlwaysOff)
			m_edit->setHorizontalScrollBarPolicy(a.toBool()
			    ? Qt::ScrollBarAsNeeded : Qt::ScrollBarAlwaysOff);
		return QVariant(0);
	case 0x754c:     // 槽 +0xf8 kind=2 = 垂直同构(FUN_00948ab0)
		if (m_edit->verticalScrollBarPolicy() != Qt::ScrollBarAlwaysOff)
			m_edit->setVerticalScrollBarPolicy(a.toBool()
			    ? Qt::ScrollBarAsNeeded : Qt::ScrollBarAlwaysOff);
		return QVariant(0);
	case 0x754d: {   // FUN_0092e44e(195B)后台解析全停(批 69 勘正:
	                 //   stopCount/nodes 实属 E +0x128/+0x2d8;
	                 //   FUN_009264ba 腿 cited — wave-2)
		++m_ctx.eStopCount;
		for (auto it = m_ctx.eNodes.begin(); it != m_ctx.eNodes.end(); ++it) {
			void *e = it.value();
			if (e && quint8(*(quint8 *)(reinterpret_cast<char *>(e) + 8) - 5) < 4) {
				// FUN_009264ba:type∈[5,8] 逐节点停机(动态转换/
				//   广播/取消)— cited — wave-2
			}
		}
		// QThreadPool clear/waitForDone(E+0x118)—— 池未建模 cited
		return QVariant(0);
	}
	case 0x7552: {   // 5 元列表 → FUN_00a2893e(112B)→ FUN_0092c0cc
	                 //   (105B):FUN_0098075a doc+0x38 挂起标注记录
	                 //   (字段承接,批 67a;链内无文本写入,不加 SCI
	                 //   替换 — 铁律 6)+ editor_undoBegin(SCI 承接;
	                 //   end 腿不在本链)+ FUN_00974856 sel 收尾 cited
		const QVariantList list = a.toList();
		if (list.size() == 5) {
			const qint64 pos = list[0].toLongLong();
			const QByteArray baA = list[3].toByteArray();
			// FUN_00a4e152(76B)toChar 宽松转换(两标注字符)
			auto toCharQ = [](const QVariant &v) -> quint8 {
				if (v.userType() == QMetaType::Char)
					return *(const quint8 *)v.constData();
				QVariant cv = v;
				if (!cv.convert(QMetaType::Char))
					return 0;
				return quint8(cv.value<QChar>().toLatin1());
			};
			m_ctx.pendAnnPos0 = pos;                     // 记录 +0x00
			m_ctx.pendAnnPos1 = pos + baA.size();        // +0x08
			m_ctx.pendAnnCh1  = toCharQ(list[1]);        // +0x10
			m_ctx.pendAnnCh2  = toCharQ(list[2]);        // +0x11
			m_ctx.pendAnnBa   = baA;                     // +0x18 槽
			send(SCI_BEGINUNDOACTION, 0, 0);             // undo begin 腿
			// FUN_00980710(74B)槽释放 / FUN_00974856(130B)收尾
			// — cited — wave-2
		}
		return QVariant(0);
	}
	case 0x7573:     // fold 折叠+滚到视野(FUN_00a5e952 90B/
	                 //   FUN_00a5e8bc 141B vt+0xa0;fold ctx 0x217
	                 //   未建模)— cited — wave-2
		return QVariant(0);
	case 0x7576: {   // 30070:runnode 插入样式表(c92c 主循环真身化批 82;
	                 //   76d §5 片段;runvector = QVector<ValueTable*> 承接,
	                 //   壳期空 → 0 = 语料"无 runvector"语义同相)
	                 //   内层 c1c2 三怪癖真身化(批 83,76d §4);
	                 //   深腿:迭代器/R·T 段 — cited
		if (m_ctx.runVector.isEmpty())                   // L29033 *(rv)==0 → 0
			return QVariant(0);
		bool ok = false;
		(void)ok;
		const qint64 nodePos = a.toLongLong();
		for (int i = m_ctx.runVector.size() - 1; i >= 0; --i) {   // L29057 逆序
			if (i >= m_ctx.runVector.size())             // L29068 向量化守卫同相
				continue;                                //   (内层摘除后越界 → 跳)
			wt::ValueTable *r = m_ctx.runVector[i];
			const qint64 at = wt::vcallSlotArg(r->delegate, 0x28, nodePos);  // FUN_009cc396
			const quint64 sv = wt::MarkersStore::runValueWordAt(r, int(at)); // FUN_009cd3da 六路
			if (m_ctx.styleProps190.value(int(sv >> 2)) == 0)   // FUN_00957892 表门
				continue;
			const qint64 s = wt::vcallSlotArg(r->delegate, 0x38, at);   // vt+0x38 run 起
			const qint64 e = wt::vcallSlotArg(r->delegate, 0x40, at);   // vt+0x40 run 止
			// ===== FUN_0095c91e(13B thunk)→ FUN_0095c1c2(1857B @0031:28734)
			//   内层真身化(批 83;76d §4 三怪癖)。c91e = 尾跳直通:
			//   p4 = i(批 76b 尾跳勘定);p5 = sv(run 值字面形态);
			//   p6 = 残寄不可读 → 壳期取 -1(全选)— cited — wave-2。
			//   入口 FUN_0095c086(复位/ensure 腿)— cited — wave-2。
			qint64 sMin = s, sMax = e;                   // L28745-28749 swap 归一
			if (e < s) { sMin = e; sMax = s; }
			const int p4 = i;
			const quint64 p5 = sv;
			const qint64 p6 = -1;                        // cited — wave-2
			for (int j = m_ctx.runVector.size() - 1; j >= 0; --j) {  // L28787 elem 逆序
				if (!(p4 != 0 || p6 == -1 || p6 == j))   // LAB_0095c240 选 elem 门
					continue;
				if (j >= m_ctx.runVector.size())         // 摘除后越界 → 跳(向量化
					continue;                            //   守卫同相:越界读作 0)
				wt::ValueTable *rj = m_ctx.runVector[j];
				// ② runIdx(min)/runIdx(max) 对(L2879x 反编译器丢参;
				//   R 段 LAB_0095c47d 同面字证 iVar7=min/iVar18=max)
				const int atMin = int(wt::vcallSlotArg(rj->delegate, 0x28, sMin));
				const int atMax = int(wt::vcallSlotArg(rj->delegate, 0x28, sMax));
				if (atMax < atMin)                       // L28804 → 下一 elem
					continue;
				for (int rr = atMax; rr >= atMin; --rr) {          // run 序降序
					// ① 子 run 重新六路取值 + props 门(非外层直传;
					//   uVar5 复用为表值,L28813-28821)
					const quint64 svIn = wt::MarkersStore::runValueWordAt(rj, rr);
					const quint64 props = m_ctx.styleProps190.value(int(svIn >> 2)); // FUN_00957892
					if (props == 0)
						continue;
					const qint64 rs = wt::vcallSlotArg(rj->delegate, 0x38, rr);  // vt38 run 起
					const qint64 re = wt::vcallSlotArg(rj->delegate, 0x40, rr);  // vt40 run 止
					if (p4 == 1) {                       // 掩码特判(L28845)
						if (((p5 ^ props) & 0x1f) == 0 &&
						    ((props ^ p5) & 0x3fe0) == 0) {
							// 掩码同 → 直落界交判定(跳 p4==2 去重腿)
						} else {
							continue;                    // 掩码异 → 跳此 run
						}
					} else if (p4 == 2) {
						// p4==2 去重向量腿 FUN_00926ddc(ctx+8,rs,re,
						//   props&0x3fff)+ 5-long 步进线性查,命中即跳
						//   — cited — wave-2(去重 store 未建模,不落)
					}
					// ② 界交判定不夹交(L28869):runStart<s || e<runEnd
					//   即跳;命中标整 run
					if (rs < sMin || sMax < re)
						continue;
					// 命中:get_chars_locked(ctx+0x180,rs,1,re-rs,0)
					//   (L28873)→ charUsedView FillRange(标记腿已接)
					if (m_ctx.charUsedView) {
						const int len = int(re - rs);
						if (len > 0)
							m_ctx.charUsedView->FillRange(int(rs), 1, len);
					}
					// upgrade 腿(L28877):run 值清零 → prune 触发面;
					//   len 参反编译器丢弃(RCX),壳期取整 run — cited — wave-2
					if (j < m_ctx.runVector.size())          // i<count 再验(L28879)
						wt::runstylesUpgrade(rj, rs, 0, re - rs);
					// ③ prune 一次(FUN_0095da64 @0031:30016;正向逐个摘
					//   ≡ 全摘;delete 腿已补:语料 0095da64 命中后
					//   scanner_resetState + operator_delete(0x40) 再
					//   0095da30 摘;resetState 腿仍 cited — wave-2)
					for (int q = m_ctx.runVector.size() - 1; q >= 0; --q) {
						wt::ValueTable *qe = m_ctx.runVector[q];
						if (wt::vcallSlot(qe->delegate, 0x30) == 1 &&
						    wt::MarkersStore::runValueWordAt(qe, 0) == 0) {
							delete qe;                   // 0095da64 operator_delete(_,0x40)
							m_ctx.runVector.remove(q);   // da30 memmove 左移
						}
					}
					if (m_ctx.runVector.size() == j)         // count==i → break 内层
						break;                               //   run 序(L28886 字面)
					// ok = (char)c1c2 返回(R 段结果)— cited — wave-2;
					//   骨架期不置位
				}
			}
		}
		// FUN_00a162b6(iter 收尾)/FUN_00a161d8(221B)— cited — wave-2
		// vt+0xa0 刷新(true → 刷新)— cited(Phase-4b)
		return QVariant(0);
	}
	case 0x757c:     // ctx[0x213]+0x1f8 = a.toBool()(0x757b 读对)
		m_ctx.field213f8 = a.toBool();
		return QVariant(0);
	case 0x757d: {   // {起始行,缩进}:行首 ' ' 扫 ':'/'.' 前缀数字 +
	                 //   上溯全空格行(FUN_00925200/0092520c/009284aa
	                 //   SCI 承接;FUN_00929002 子串提取转写);
	                 //   返回容器 = FUN_008956eb(410B)自定义 metaType
	                 //   — cited — wave-2(形状待转写)
		const long long line = a.toLongLong();
		const long long ls = send(SCI_POSITIONFROMLINE, line, 0);
		const long long le = send(SCI_GETLINEENDPOSITION, line, 0);
		long long indent = -1, start = line;
		if ((char)send(SCI_GETCHARAT, ls, 0) == ' ') {
			indent = 0;
			for (long long p = ls; p < le; ++p) {
				const char ch = (char)send(SCI_GETCHARAT, p, 0);
				if (ch == ':' || ch == '.') {
					QString num;   // FUN_00929002:ls..p 子串
					for (long long q = ls; q < p; ++q)
						num += QChar((char)send(SCI_GETCHARAT, q, 0));
					indent = num.toLongLong();
					break;
				}
			}
			for (long long p = line - 1; p >= 0; --p) {
				if ((char)send(SCI_GETCHARAT,
				    send(SCI_POSITIONFROMLINE, p, 0), 0) != ' ')
					break;
				start = p;
			}
		}
		(void)indent; (void)start;
		return QVariant(0);   // 容器形状 cited(FUN_008956eb)
	}
	case 0x757f:     // FUN_00a38936(783B)Uint8RunStyles 查询面
	                 //   — cited — wave-2
		return QVariant(0);
	case 0x7581:     // +0x1b2 开关:false → FUN_00a28316(106B mode7
	                 //   清高亮);true → editor_getSelRange
	                 //   (FUN_00a2bbbe 897B)— cited — wave-2
		return QVariant(0);
	case 0x7585: {   // FUN_00925310(40B)setter(L24001):n==0 → 默认
	                 //   (+0x270/+0x278=1 — cited);n<1 → false;n==现值
	                 //   → false;写 + soft_reset → true
		const int v = a.toInt();
		if (v == 0) {
			// +0x260 = +0x270(默认)/+0x278 = 1 — cited — wave-2
			return QVariant(true);
		}
		if (v < 1)
			return QVariant(false);
		if (v == m_ctx.field213_260)
			return QVariant(false);
		m_ctx.field213_260 = v;
		// session_view_soft_reset — cited
		return QVariant(true);
	}
	case 0x7584:     // *(int*)(ctx[0x213]+0x260) 读(0x7585 setter =
	                 //   FUN_00925310 40B:n>0 写 n/+0x278=0;n==0 默认)
		return QVariant(m_ctx.field213_260);
	case 0x758c: {   // float +0x1a1 行距倍率:clamp >2→2;<=0 拒(SSE
	                 //   语义:保持原值);变更 → session_view_soft_reset
	                 //   — cited(Phase-4 视图)
		float v = a.toFloat();
		if (v > 2.0f)
			v = 2.0f;
		else if (v <= 0.0f)
			return QVariant(0);
		if (v != m_ctx.field1a1) {
			m_ctx.field1a1 = v;
			// session_view_soft_reset — cited(Phase-4 视图)
		}
		return QVariant(0);
	}
	case 0x758f:     // FUN_00a2a8c4(189B)margin 命中测试:point.x 按
	                 //   width+padding 累计定位 → *(byte*)(e+10)&0xf
	                 //   type — cited — wave-2(builder 字段域测绘
	                 //   见 PHASE5 批 65 附)
		return QVariant(0);
	case 0x75b6:     // selectionAsHtml:FUN_00a36e40(104B)→
	                 //   FUN_00a3663e(2025B 导出主函数)— cited
		return QVariant(0);
	case 0x75b7: {   // FUN_00a36eb0(110B)selectionBytes(同上导出体)
	                 //   — cited
		return QVariant(QByteArray());
	}
	case 0x75b9:     // FUN_009276ee(52B)装饰器工厂(vt+0x60/0xe0)
	                 //   — cited
		return QVariant();
	case 0x75bb:     // 片段 tabstop 行扫描 FUN_00a2eee0(434B)
	                 //   — cited(snippetSession +0xd0 槽待建模)
		return QVariant(0);
	case 0x75bd:     // FUN_00a2f09a(1308B)"Expand Snippet" 选区事务
	                 //   — cited — wave-2
		return QVariant(false);
	case 0x75be:     // FUN_00a28f98(15B)→ FUN_00926ff6(8B)→
	                 //   FUN_009a7140 词条命中查找 — cited
		return QVariant(0);
	case 0x75c0:     // FUN_00a297e8(591B)片段会话开启 — cited
		return QVariant(0);
	case 0x75c3:     // *(bool*)(doc+0x279) 读(0x75c6 写)
		return QVariant(m_ctx.docIndentTabs);
	case 0x75c6:     // doc+0x279 = a.toBool()(0x75c3 读;无刷新)
		m_ctx.docIndentTabs = a.toBool();
		return QVariant(0);
	case 0x75c7:     // s_text_backgroundColor_92fe4a(779B)文本背景色
	                 //   三元组写(列表 ==3 元素门)— cited — wave-2
		return QVariant(0);
	case 0x75c8:     // 部件树查询 FUN_0092759a(20B)→ FUN_009258b2
	                 //   (类型 6 子节点链)— cited
		return QVariant(0);
	case 0x75c9:     // doc+0x108 QList 内部句柄包装(FUN_00926b28 12B)
	                 //   — cited(返空)
		return QVariant();
	case 0x75ca:     // 列表首节点 begin!=end → 非空(FUN_00926afe 21B)
	                 //   — cited(返 false)
		return QVariant(false);
	case 0x75cb:     // marker 插入 FUN_009301a8(109B)→ FUN_0092fb40
	                 //   (634B 标记树)+ FUN_00a20666/00a20680 游标行
	                 //   — cited — wave-2
		return QVariant(0);
	case 0x75cc:     // FUN_0092fb40 直调批量设标记列表 — cited
		return QVariant(0);
	case 0x75cd:     // editor_textLength(46B):hexMode→009586d4/
	                 //   skiprunnodes→00970d8c/普通 = SCI_GETLENGTH
		return QVariant((long long)send(SCI_GETLENGTH));
	case 0x75cf: {   // FUN_009589f0(135B):pos 夹取 [0,textLength]
	                 //   (hexMode→0095886c 腿 cited)
		const long long p = a.toLongLong();
		const long long tl = (long long)send(SCI_GETLENGTH);
		return QVariant(qBound(0LL, p, tl));
	}
	case 0x75d5:      // a.toBool() ? doc+0x288 : doc+0x280 槽读
	                  //   (QString 引用计数取;0x75d6 写对,L24114)
		return QVariant(a.toBool() ? m_separators1 : m_separators0);
	case 0x75da:     // FUN_00a245c6(154B)字号族 set(engine,int,
	                 //   FUN_00a21610 old = +0x10a0 对象+0x20);+0x20
	                 //   域语义未解 — cited
		return QVariant(0);
	case 0x75e4: {   // flag1083 写:变更才动作 + FUN_00a2cea8(1259B)
	                 //   刷新 — cited(L24025)
		const bool v = a.toBool();
		if (m_ctx.flag1083 != v) {
			m_ctx.flag1083 = v;
			// FUN_00a2cea8(1259B)视图刷新 — cited
		}
		return QVariant(0);
	}
	// 其余 ~44 个 fork 特性(scrollbar marks/margin 链表/
	case 0x7582: {   // +0xd91 = a.toBool()(L23538-50 归属核批 66):
	                 //   false → 释放 +0x1d7(0x40)+ FUN_00a22c4e(2);
	                 //   true → FUN_00a2509a(this,-1,0) — cited — wave-2
	                 //   (原 +0xd8f 写属 <0x7582 区间未定条目,fieldD8f
	                 //   保留待归)
		m_ctx.flagD91 = a.toBool();
		// FUN_00a22c4e(28B)/FUN_00a2509a — cited — wave-2
		return QVariant(0);
	}
	case 0x7580: {   // +0xd8f = a.toBool() + vt+0xa0 刷新(L23532-35
	                 //   <0x7580 边界 else 腿;与 0x7581 的 +0x1b2 开关
	                 //   (FUN_00a28316/editor_getSelRange 双腿)异体 —
	                 //   独立转写;同型见 0x758b)
		m_ctx.flagD8f = a.toBool();
		// (**+0xa0)(ctx) 刷新 — cited(Phase-4b 视图腿)
		return QVariant(0);
	}
	// 0x7583 归属核定案(批 66):唯一语义 = pairHighlightUnmatched
	//   (L23339,无双面);+0xd91 写已归位 0x7582
	case 0x756a: {   // +0x1b3 bool = a.toBool();变更 → vtable+0xa0
	                 //   刷新( cited — Phase-4b 视图腿)
		const bool v = a.toBool();
		if (m_ctx.flag1b3 != v) {
			m_ctx.flag1b3 = v;
			// (**+0xa0)(ctx) 刷新 — cited(Phase-4b 视图腿)
		}
		return QVariant(0);
	}
	case 0x756c: {   // +0x227 字节 = a.toBool()(00669xxx 区直写)
		m_ctx.flag227 = a.toBool();
		return QVariant(0);
	}
	case 0x7543: {   // FUN_0092f0f6(1279B)setCurrentBuffer(a):
	                 //   FUN_0092ef06 拆链 → FUN_00925338/00925310
	                 //   状态应用 → +0x274 写;命中变更 →
	                 //   FUN_0095cc7e + session_view_soft_reset +
	                 //   FUN_00a243ae(0x10)( cited — Phase-4b 面)
		const quint64 bufId = a.toULongLong();
		if (m_ctx.currentBufferId == bufId)
			return QVariant(0);              // 语料同 id 短路
		m_ctx.currentBufferId = bufId;
		// editor_initDoc 腿(FUN_0092f0f6@0030.c:29827;批 83 C2 破案:
		//   editor_initDoc 唯一调用点 = 本命令,不在会话创建链)——
		//   lexer 门(buffer+0x108 面)— cited(buffer 未建模,换缓冲即达)
		//   → editor_initDoc(new(0x70),doc,*(doc+0xa0)) → D 挂 doc+0xc0。
		//   E=doc ⇒ &m_ctx(批 69 E 面平铺);param3/lexerSnap 未建模
		//   → nullptr(cited — wave-2)
		wt::MarkersStore::markersCtxInit(&m_ctx.markersStore, &m_ctx, nullptr, nullptr);
		m_ctx.wireSlot10();                          // slot10 = param_1[2](0030.c:29770 形;
		                                             //   批 99 R2:0x48 doc-scan 伴随对象,壳期 null 门关)
		// —— FUN_009a2b90(634B,0032.c:36795)Outlining 驱动 ——
		// 语料触发:DocumentTask 分发线程入口 0030.c:28874 case4
		//   FUN_009a2b90(*(session+0xc0), -1)(异步);壳期无线程基建
		//   → 同步直调【偏差登记:语料异步不阻塞主线程,同步版行为
		//   等价但阻塞】。调用者门(0030.c:28871):task+0x28==0
		//   (task 对象未建模,同相不可达)且 *(session+0xc0) 非空
		//   → 我方代理门 = markersCtxInit 已建 arr。
		if (m_ctx.markersStore.arr != nullptr) {          // *(session+0xc0)==0 → return 1 门(0030.c:28875)
			const qint64 textLen = m_ctx.docBytes.size(); // -1 → FUN_0092801a=*(doc+0xf8)+0x28 长度面
			                                              //   (EditorContext docBytes 等价承载);
			                                              //   FUN_0092814a 同面钳制(0032.c:36813)
			if (textLen == 0) {                           // to==0 && len==0 → FUN_009a29ce(009a2cb5)
				m_ctx.markersStore.publishOutline();      //   发布/分发腿(→009a2766 体转写;壳期惰值)
			}
			if (qint64(m_ctx.markersStore.scanCursor) < textLen) {  // *(D+0x20) < to 主门(009a2cbf)
				// FUN_0099d072 关键词腿(387B,0032.c:32955)— cited —
				//   wave-2:语料其返回真才进 region 循环 + *(D+0x2c)=0
				//   清零(009a2ce 区)+ finally 回调机制(cited);壳期
				//   kwVec30 空 → regionScan 内 FUN_00a10472 门走基值腿
				//   同相。【偏差登记:未设 0099d072 返回门,kw 就位批需补】
				m_ctx.markersStore.stopFlag = 0;          // *(u8*)(D+0x2c)=0(009a2ce 区字面)
				m_ctx.regionScan(0, 0, textLen);                // FUN_0099d4de(0032.c:36875;经 E 面包装,lex=bufferLexer):
				                                          //   mode=0;from=scanCursor 初值 0,
				                                          //   to=param_2 全文档
				m_ctx.markersStore.publishOutline();      // 循环尾非停机腿 FUN_009a29ce(009a2df8)
			} else if (m_ctx.markersStore.stopFlag == 0) {
				// "Outlining End, Nothing to do............" 返 0 — 语料字面(009a2e0a)
			} else {
				m_ctx.markersStore.publishOutline();      // "outliningRegions Again" 腿(009a2e0e)
			}
		}
		// setCurrentBuffer 核心(1279B)与刷新腿 — cited(Phase-4b)
		// (Phase-4b 视图面;字段面已落位)
		return QVariant(0);
	}
	case 0x7553: {   // buf_substr(0092acb8,192B):doc[a,b) →
	                 //   QVariant(bytearray);空 = shared_null 语义
		const long long from = a.toLongLong();
		const long long to = b.toLongLong();
		return QVariant(m_ctx.docSub(from, to));
	}
	case 0x7565:     // 0034:23050:pos → FUN_009284aa(13B)→ int
	                 //   (批 77 清点薄条;体未读 —— cited — wave-2)
		return QVariant(0);
	case 0x754e:     // 0034:23602 <0x7550 默认腿:FUN_0092e368(session)
	                 //   无参调用(1 行;体未读 —— cited — wave-2)
		return QVariant(0);
	case 0x7566: {   // FUN_0093079a(257B):charAt → ucs4 码点
		return QVariant((uint)m_ctx.docCharCodeAt(a.toLongLong()));
	}
	// --- replaceText 族(rt2 批 89;语料 0034.c:12789-13104 全读)---
	case 0x4f00: {   // editor_replaceText @00a3360e(2248B)— A-G 六段真身
	                 //   (A codec 判定/B runlist/D 逐 run/E a2de1c 段级转
	                 //   写/F store/G RAII);codec/undo/选区族深腿 cited
		// ReplaceOp = runnode 态 op 结构(rt2 §1):字段按语料偏移
		//   直读(+0x0c flags/+0x10 type/+0x38 标记/+0x3c 命中计数)
		char *const opb = (char *)a.toULongLong();       // 桥面 = toULongLong(命令表)
		if (opb == nullptr)                   // 我方安全守卫(宿主桥未建对象;
			return QVariant((long long)-1);   //   取语料早退值;非语料行为 — 登记)
		// —— 段 A 入口/编码判定(12791-12874)——
		const quint8 type = *(const quint8 *)(opb + 0x10);       // 12792 bVar1
		const quint32 flags = *(const quint32 *)(opb + 0x0c);    // *(op+0xc)
		bool selMode = ((type & 0xfd) == 1);            // 12793 local_18a
		// 旧/新 codec getter FUN_009276e2/FUN_00927600(doc+0xe0 持有体
		//   +0x28/+0x20 串读取器;p3 §1 语义修正:009276e2 = find,
		//   00927600 = replace 长提示)— cited — wave-2(空串承载)。
		// codec memo 面(批 91):canOld = FUN_0089a756(179B)真身
		//   (CodecMemo::canOld:op+0xc&5 门 + +0x58 Grep 针缓存查/插;
		//   产腿 cited → 针恒 null → 真值,占位同相)。
		// codec_canEncode(0089b85e)/FUN_0089a0a0 产物对(12842/12847:
		//   新长/旧长源;canOld→canEncode 对 12871)产腿 cited → null
		//   承载;null 门真身化(12871-12874)即 B-G 骨架死相(占位链
		//   活性丢失)→ newLen/oldLen 占位非零保持
		const bool canOld = s_codecMemo.canOld(QString());   // 12816 local_189 真身
		if (!canOld)
			selMode = !selMode;                         // 12798-12800
		constexpr long long newLen = 1;                 // 【占位 — cited】local_188
		const long long oldLen = newLen;                // 12817 canOld → 同值 local_178
		if (oldLen == 0)
			return QVariant((long long)-1);             // 12820-12822
		// ctx[4]/ctx[5] 产物对(codec_canEncode ctl/Grep 针对象)载体:
		//   产腿 cited → 零值针(len=0 = conv+0x10;literal=1 = convCtor
		//   面)。scanMask 26272 nlen<=0 门 / searchNeedle 00a83946 门
		//   → 恒 -1(占位同相;ctx[4]/ctx[5] 同载体 — 产物对未建模登记)
		GrepNeedle448 needleCar;                        // ctx[4]/ctx[5] 载体
		// —— 段 B 撤销组+替换 runlist(12875-12926;type==3 门)——
		QVector<EditorContext::Span56> runlist;         // local_1d0(splitvector 承载)
		if (type == 3) {
			// FUN_009cff30(doc,"Replace Text")事务对象(0x10B)—
			//   undo 族 — cited — wave-2(不落 SCI;BEGINUNDOACTION 非
			//   009cff30 转写)。FUN_0092801a(doc)长度面(0x7543 同面:
			//   docBytes 承接)→ runnode_init(textLen,0,0)/runnode_init(0,0,0)
			//   → FUN_0096be24 合并(n0←param_3=textLen 节点,n1←param_2=0
			//   节点,be24 逆序;bd68 flag=0)→ push_back/尾槽直写二腿
			//   (12912-12919 FUN_00a4d18e/直写;QVector::append 承载同效)
			const qint64 textLen = m_ctx.docBytes.size();   // FUN_0092801a — cited 适配
			EditorContext::Span56 sp;
			sp.flagWord = 0;
			sp.n0 = RunNode::make(textLen, 0, false);   // +0x08←param_3
			sp.n1 = RunNode::make(0, 0, false);         // +0x20←param_2
			runlist.append(sp);
		}
		// 12924-12925 尾:editor_clearSelectState(p1,(flags>>4)&1)
		//   — 选区族 — cited — wave-2(874B 体未转写)
		// —— 段 C 选区来源(12926-12939)——
		QVector<EditorContext::Span56> *base = &runlist;         // local_168[0]
		if ((flags & 0x10) != 0 && m_ctx.selStoreOn              // 12927-12934:
		    && !m_ctx.selStore.extras.isEmpty())                 //   FUN_00a283a4
			base = &m_ctx.selStore.extras;                       //   非空 → store extras
		// —— 段 D 逐 run 腿(12939-13011;type==3 门)——
		long long selStart = 0, selEnd = 0, delLen = 0, insLen = 0;
		if (type == 3) {
			// FUN_00a1ff9c+FUN_0096bbc0 → selStart、FUN_00a20050 →
			//   selEnd(12941-12950)— 选区族 cited,真 Scintilla 承接
			//   适配(0x75b8 同面)
			selStart = send(SCI_GETSELECTIONSTART);
			selEnd = send(SCI_GETSELECTIONEND);
			// 语料手写 deque 步进(12951-12975):元素 0x38B、/7 魔数
			//   0x6db6db6db6db6db7×3 段式、块界跳转 — 承载替 = QVector
			//   线性迭代(批 81/85 怪癖登记);0x38 原样保留于 Span56 布局
			for (int i = 0; i < base->size(); ++i) {
				const EditorContext::Span56 &run = base->at(i);
				const qint64 rs = run.n0.pos;    // FUN_0096c18e(元素+0x10)
				const qint64 re_ = run.n1.pos;   // FUN_0096c1a4(元素+0x28)
				if (rs <= selStart && selEnd <= re_) {       // 12978 含选区门
					// delLen:FUN_009253ee(doc,s,e,&ba)旧编码字节长
					//   (009253ee,78B,rt2 §3)— cited — wave-2(编码
					//   引擎 f88 未建模;占位 = 原生区间长 → 1:1 守卫恒真)
					delLen = selEnd - selStart;
					if (selEnd - selStart == delLen) {       // 12987 1:1 守卫;
					                                     //   不满足静默跳过 = 原版怪癖勿修
						// FUN_0089ab22 重编码/FUN_00899316 长度/
						//   FUN_008990b2 空判/editor_undoBegin 应用
						//   (空→直写腿 12992-12997/打包腿 13000-13005
						//   FUN_00925564+008990c0)— codec/undo 族 —
						//   cited — wave-2
						insLen = delLen;                     // 【占位 — cited】lVar14
						// 12991-12995:B 建本地 runlist 时 FUN_0096c334
						//   风格 run 插入腿 — 容器族 — cited — wave-2
						if (selMode)
							selStart += insLen;              // 13001-13003
						// 12998-12999:FUN_00a21110(165B,0034:778,rt2 §4)
						//   选区 finalize + doc 通知 = vt8 事件源 → 写侧
						//   挂点接线(批 85 存照的 notifyTextChanged 调用点)
						m_ctx.notifyTextChanged(selStart, delLen, insLen);
					}
					break;                                   // 13010 仅首命中
				}
			}
		}
		// —— 段 E 游标定位(13012-13056)——
		// FUN_0096bd82(&local_c8)锚初始化{0,{-1},{-1}}(13012)
		EditorContext::Span56 anchor;                   // local_c8..local_98
		anchor.n0 = RunNode::make(-1, 0, false);
		anchor.n1 = RunNode::make(-1, 0, false);
		long long pos;                                  // a2de1c 搜索实参
		if ((flags & 8) == 0) {
			// !(flags&8):selMode==0 → FUN_00a1ff9c/否则 FUN_00a20050
			//   +back → pos(13015-13032;选区族 cited,SCI 承接适配)
			pos = selMode ? send(SCI_GETSELECTIONEND)
			              : send(SCI_GETSELECTIONSTART);
		} else {
			// flags&8 → FUN_00a28516(323B,批 85 真身化存照)懒建置位;
			//   00a28577 现选区载入腿 FUN_00a1fc3a — cited — wave-2
			//   (壳期 anchor 恒 {-1} 同相);13035-13043 7 long 拷贝
			m_ctx.selStoreOn = true;
			anchor = m_ctx.selStore.anchor;
			pos = anchor.n0.pos;                        // 13044 FUN_0096c18e
		}
		// FUN_00a2de1c(1663B)@0034:9644 游标落点搜索 — 段级转写(rt2
		//   §2:段 1-4/5/6/7/8 门/9/10/11;段 9 位对/段 8 步进推进/命中
		//   腿消费 a20eb2/a235ce/925304 — cited — wave-2)。ctx 面
		//   (12938-12944 局部排布直读):ctx[0]=base(段 C 选定
		//   runlist)、ctx[1]=&selMode(方向:非 0 前向)、ctx[2]=&canOld
		//   (模式:非 0 → FUN_0092547e 针搜)、ctx[3]=ed、
		//   ctx[4]=&newLen(针字节 ctl)、ctx[5]=&oldLen(Grep 针对象)、
		//   ctx[6]=op
		auto cursorSearch_a2de1c = [&](long long startPos,
		                                bool force) -> long long {
			const int size = base->size();          // 9671 deque distance
			long long idx;                          // uVar7
			if (selMode) {                          // 9677 ctx[1] 非 0 → 前向
				if (size == 0)                      // 9885 LAB_00a2e218
					return -1;
				idx = 0;                            // 9886
			} else {
				idx = (long long)size - 1;          // 9678-9681 后向 size-1
				if (idx < 0)
					return -1;
			}
			while (true) {                          // 9682-9887 主循环
				// 段 2/3 at(idx)(9680-9740 手写 deque::at,/7 魔数
				//   0x6db6…×3 段式 — QVector 承载等价替,批 81/85 怪癖)
				const EditorContext::Span56 &run = base->at((int)idx);
				const qint64 rs = run.n0.pos;       // 9746 FUN_0096c18e(+0x10)
				const qint64 re_ = run.n1.pos;      // 9769 FUN_0096c1a4(+0x28)
				qint64 lo = rs, hi = rs;            // lVar2/lVar4
				long long cur = startPos;           // local_90(钳制可改写)
				bool enter = false;                 // 包夹门(段 4)
				if (!selMode) {                     // 9770 后向(ctx[1]==0)
					if (rs <= cur) {                // 9773
						hi = rs;                    //   lVar4 = rs
						if (re_ < cur)              // 9774-9776 re<startPos
							cur = re_;              //   钳制 local_90=re
						lo = (rs < cur) ? cur : rs; // 9777 LAB_00a2e02a
						enter = true;
					}
				} else {                            // 9771 前向
					hi = re_;                       //   lVar4 = re
					if (cur <= re_) {               // 9772
						lo = (rs < cur) ? cur : rs; //   同 02a
						enter = (lo <= hi);
					}
				}
				if (enter) {
					// —— 段内体(9765-9858;LAB_00a2e02a 入口)——
					// ctx 载体:ctx[5] 针对象 = 段 A needleCar(段 5/6/9
					//   共用;产腿 cited → literal=1/len=0);ctx[4] 同
					//   载体(产物对未建模登记)。
					long long cand = -1;            // local_e0
					long long candEnd = -1;         // local_c8(段 6/针搜位对写)
					int cc = 2;                     // 9740 local_cc=2(包夹门置)
					if (!canOld) {                  // 9767 ctx[2]==0 → 掩码腿
						// 段 5 LAB_00a2e326(9770-9771):FUN_0092a596()
						//   掩码扫描 = CodecMemo::scanMask 真身(467B
						//   骨架;四引擎/填充方 cited — 占位下恒 -1)
						cand = CodecMemo::scanMask(&needleCar, lo, hi);
						if (cand == -1)             // 9772 → LAB_00a2e1c6
							goto step;              //   步进
						// 段 6(9773):local_c8 = *(int*)(针+0x10)
						//   + local_e0(GrepNeedle448 conv+0x10 针长加算)
						candEnd = cand + needleCar.len;
						// → 直落 LAB_00a2e0c1(语料 fall-through)
					} else {                        // ctx[2] 非 0 → 针搜腿
						// 段 9 LAB_00a2e07d(9852-9853):FUN_0092547e
						//   (doc,lo,hi,ctx[4],runEnd)针搜真身(95B 骨架
						//   = CodecMemo::searchNeedle;00b422d0 引擎
						//   cited — 占位下恒 -1)
						if (CodecMemo::searchNeedle(&needleCar, lo, hi) != -1) {
							// 9855-9856:FUN_00925540/9554c(doc,0)读
							//   命中位对 → local_e0/local_c8(0030:20478/
							//   20488 12B thunk → 00a839cc 75B/00a83bd0
							//   76B @0035:518/620:state==1 结果表槽
							//   [i*2]+0x98 偏移读/state==2 委 00a839ae/
							//   bb2 — 结果槽未建模)— cited — wave-2
							cand = -1;              // 【cited 占位】local_e0
							candEnd = -1;           // 【cited 占位】local_c8
							goto hit;               // 9857 → LAB_00a2e0c1
						}
						goto step;                  // -1 → LAB_00a2e1c6
					}
					// 段 7 force 判定(9774-9800;LAB_00a2e0c1 入口):
					//   force / *(op+0xc)&8 → 命中腿;docLen<1(9795
					//   FUN_0092801a — docBytes 承接)→ 命中腿;否则
					//   入段 8 边界校验腿
hit:
					if (force || (flags & 8) != 0
					    || m_ctx.docBytes.size() < 1) {
						// LAB_00a2e470/00a2e159 命中腿(9778-9793)
						++*(int *)(opb + 0x3c);     // 9779 *(op+0x3c)++
						const RunNode a0 =          // 9781 runnode_init
						    RunNode::make(candEnd, 0, false);  //   (a0,local_c8)
						const RunNode n78 =         // 9782 runnode_init
						    RunNode::make(cand, 0, false);     //   (local_78,local_e0)
						Q_UNUSED(a0); Q_UNUSED(n78); // 消费腿 cited(下行)
						// FUN_00a20eb2(ed,&n78,&a0,1) 移选区 — cited —
						//   wave-2(238B@0034:676:两 runnode → 选区 +
						//   doc 通知 FUN_009783fa;宿主选区写侧未建模)
						// FUN_00a235ce(ed,-1,0) 刷新 — cited — wave-2
						//   (356B@0034:2405)
						if (cand != -1)             // 9792
							return cand;            //   返命中位
						goto step;                  // 9793 e0==-1 → 1c6
					}
					// 段 8 边界校验腿(9801-9846;候选 viable 才达):
					//   FUN_00a1ff9c+FUN_0096bbc0 取内容首(9803/9811)/
					//   FUN_00a20050+FUN_0096bbc0 取尾(9815/9822)→
					//   现选区界 = SCI 选区承接(50a/50b 三真身:posCmp
					//   41B×2@0031:41015/41032 + 0096bbc0 *(+8) 5B)。
					//   后向(9803-9819,selMode==0):首> cand 或 尾>
					//   candEnd → LAB_00a2e137/2ed 命中腿(9826);前向
					//   (9829-9837):首<cand 或 尾<candEnd → 2ed 同;
					//   界外(LAB_00a2e406 9838)→ FUN_00925304(doc,
					//   candEnd,±1)跳选单步(9843;00925304 12B thunk →
					//   009988e2 176B@0032:28889 全读:FUN_0099881e
					//   词跳步基元 196B 全读 = 本文件 static
					//   s_wordStep_0099881e 真身)+ cc=2→1(9850)内环
					//   重入(带推进后 local_c8 重包夹 — 推进结果不回写
					//   语料 9843 调用即弃 → 内环重入腿 = 语料恒 cc=1
					//   后 9851 → LAB_00a2e326/9852 针搜重扫,同 our
					//   step 腿;0x3c 步进计数同 hit 腿 9779 同相)
					{
						// a1ff9c→0096c0c0=posCmp 取小=选区首(SCI selstart);
						//   a20050→0096c0ea=取大=选区尾(SCI selend)
						const qint64 selB = send(SCI_GETSELECTIONSTART);
						const qint64 selE = send(SCI_GETSELECTIONEND);
						bool inSel;                         // 包夹判定(→e137/2ed 命中)
						if (!selMode)                       // 9811-9818 后向
							inSel = selB > cand || selE > candEnd;
						else                                // 9831-9837 前向
							inSel = selB < cand || selE < candEnd;
						if (!inSel) {                       // 9838 e406 界外
							// 9843:FUN_00925304(doc,candEnd,±1)跳选单步
							//   (真身 s_wordStep_0099881e;返回值语料即弃)
							s_wordStep_0099881e(m_ctx, candEnd, selMode ? 1 : -1);
						}
					}
					cc = 1;                         // 9850 local_cc=1(重入门)
					Q_UNUSED(cc);                   //   内环未建模 → 仅登记
				}
step:;
				// 段 11 步进(9859-9887)
				idx += selMode ? 1 : -1;            // LAB_00a2e1cd/1d5
				if (idx < 0 || idx >= size)         // 9879-9887 界外
					return -1;
			}
		};
		long long r = cursorSearch_a2de1c(pos, false);       // 13045
		if (r == -1 && (flags & 0x20) != 0) {           // 13047-13049 重试门
			*(quint8 *)(opb + 0x38) |= 4;               // 13050 *(op+0x38)|=4
			// 13052-13058:selMode==0 → FUN_0092801a 长度面,else 0;
			//   二次 FUN_00a2de1c(&ctx,pos,1)(13059-13061)
			pos = selMode ? 0 : m_ctx.docBytes.size();
			r = cursorSearch_a2de1c(pos, true);
		}
		// —— 段 F store 懒建(13057-13090;flags&8)——
		if ((flags & 8) != 0) {
			// *(p1+0xfb8)==0 → operator_new(0x88)+0096bd82+槽[7..0x10]
			//   清零(13063-13075);旧 store 清理腿 13076-13081 = 语料
			//   判空后死分支,成员化值语义重置同效(批 85 登记);
			//   13082-13089:锚 7 long 写入 store[0..6]
			m_ctx.selStoreOn = true;
			m_ctx.selStore.anchor = anchor;
		}
		// —— 段 G 析构/返回(13091-13104)——
		// FUN_0096bd50/splitvector_blocks_free/事务 FUN_009cff96+delete/
		//   _Sp_counted_base::_M_release ×2 — RAII 承载零操作(容器/undo
		//   族 cited)
		Q_UNUSED(insLen);   // 段 D 占位链(仅 delLen 进 notify;codec 族落地时接)
		return QVariant(r);
	}
	case 0x4eff: {   // editor_replaceAll @00a32cca(2171B,0034:12493-12786
	                 //   体全读;批 90→rt2 升)— 命中循环+命中处理体真身
	                 //   (双计数/选区腿结构/undo 腿推进结构);codec/搜索/
	                 //   undo/选区族深腿 cited — wave-2
		char *const opb = (char *)a.toULongLong();       // 22608 toULongLong 桥面
		if (opb == nullptr)                   // 我方安全守卫(宿主桥未建对象;
			return QVariant(0);               //   取语料空判早退值 0;非语料行为 — 登记)
		int hits = 0;                         // 12565/12785 iVar4 命中计数(return 值)
		// —— 段 A 入口/编码判定(12551-12570)——
		// 旧/新 codec getter FUN_009276e2/00927600 — cited — wave-2
		//   (009276e2 = find 串源,p3 §1 修正;空串承载)。
		// codec memo 面(批 91):canOld = FUN_0089a756(179B)真身
		//   (CodecMemo::canOld;产腿 cited → 针恒 null → 真值,占位同相)。
		// codec_canEncode(0089b85e,12657)/FUN_0089a0a0(12661)产物对 →
		//   canOld 选对(12663:canOld→canEncode 对 else 针对象);产腿
		//   cited → null 承载 → 12665 lVar7==0 门真身接线:针 null →
		//   return 0(空判早退)。FUN_0089ab22(3300B)重编码 +
		//   FUN_00899316(8B 真身 CodecMemo::encodedLen)→ repLen
		//   (local_1d0,undo 腿写入长)— 0089ab22 cited → 占位非零
		const bool canOld = s_codecMemo.canOld(QString());   // 12651 cVar2 真身
		const void *needlePair = nullptr;     // 【占位 — cited】local_168/158
		if (needlePair == nullptr)
			return QVariant(0);               // 12665-12667 针 null → 0(真身)
		constexpr long long repLen = 1;       // 【占位 — cited】local_1d0
		const quint8 type = *(const quint8 *)(opb + 0x10);   // 12571 cVar1
		// —— 段 B 替换 runlist(12572-12614)——
		// 本地 splitvector 清零 → QVector 承载(批 81/85 怪癖);
		//   12583 FUN_0092801a(doc) 长度面(docBytes 承接,0x4f00 同面)
		//   → runnode_init(textLen,0,0)/runnode_init(0,0,0) →
		//   FUN_0096be24 合并 → push_back(FUN_00a4d18e/尾槽直写二腿
		//   12595-12607,QVector::append 承载同效);12613
		//   editor_clearSelectState(p1,(flags>>4)&1)— 选区族 —
		//   cited — wave-2(874B 体未转写;0x4f00 同注)
		const quint32 flags = *(const quint32 *)(opb + 0x0c);    // 12613/12616 *(op+0xc)
		QVector<EditorContext::Span56> runlist;
		{
			const qint64 textLen = m_ctx.docBytes.size();   // FUN_0092801a — cited 适配
			EditorContext::Span56 sp;
			sp.flagWord = 0;
			sp.n0 = RunNode::make(textLen, 0, false);   // local_128 +0x08←param_3
			sp.n1 = RunNode::make(0, 0, false);         // local_148 +0x20←param_2
			runlist.append(sp);
		}
		// —— 段 C 选区来源(12616-12619)——
		QVector<EditorContext::Span56> *base = &runlist;         // plVar11
		if ((flags & 0x10) != 0 && m_ctx.selStoreOn              // FUN_00a283a4(127B,
		    && !m_ctx.selStore.extras.isEmpty())                 //   0034:5635)非空 → extras
			base = &m_ctx.selStore.extras;
		// —— 段 C2 type==4 前置腿(12620-12629)——
		// FUN_00925798(doc+0x100 → 0092042e(…,1))事务挂起 +
		//   FUN_00a28316(editctx 事件 5,106B,0034:5594)批注腿 —
		//   undo/editctx 族 — cited — wave-2
		if (type == 4) {
			// cited — wave-2
		}
		// —— 段 D runlist 空判(12631-12637)——
		if (base->isEmpty())                 // 12636 local_1a0==lVar10(deque 空 ≡ 空容器)
			return QVariant(0);              //   12637 blocks_free + iVar4=0
		// —— 段 E 逐 run 命中循环(12639-12759;手写 deque 步进
		//   local_1a0 += 0x38 + 块界跳转 12752-12757 — QVector 线性
		//   迭代承载等价替,批 81/85 怪癖登记)——
		for (int i = 0; i < base->size(); ++i) {
			const EditorContext::Span56 &run = base->at(i);
			qint64 from = run.n0.pos;        // 12647 FUN_0096c18e(元素+0x10)
			qint64 to = run.n1.pos;         // 12648 FUN_0096c1a4(元素+0x28)
			// —— 搜索腿真身接线(12651-12653;批 91 要点 3/4)——
			//   canOld → FUN_0092547e(95B 真身骨架:searcher 复位+
			//   state=2+thunk 门;00b422d0 引擎 cited);否则
			//   FUN_0092a596(467B 骨架:四引擎分派 + pack64 掩码
			//   过滤式;引擎/填充方 cited)。产腿 cited 下 needlePair
			//   恒 null(12665 门先行 return 0)→ 本腿恒不达。
			while (true) {                    // 12642-12748 同 run 多命中
				qint64 hit = -1;              // lVar8
				if (canOld)
					hit = CodecMemo::searchNeedle(needlePair, from, to);  // 12652
				else
					hit = CodecMemo::scanMask(needlePair, from, to);      // 12653
				if (hit == -1)
					break;                    // 12719 LAB_00a33299 → 下一 run
				// —— 命中处理体(12654-12749)转写(占位链下恒不达)——
				qint64 hitLen = 0;            // 【cited 占位】lVar13:12655-
				                              //   12657 FUN_00925540/92554c
				                              //   (12B×2,0030:20478/20488)
				                              //   位对差;掩码模式 12720 ←
				                              //   产物 +0x10
				++hits;                       // 12658 iVar4++
				++*(int *)(opb + 0x3c);       // 12659 *(op+0x3c)++
				const qint64 hitStart = hit;  // 12660 lVar12 = lVar8
				if (type == 2) {
					// type==2 选区腿(LAB_00a330bf 12723-12746):hitEnd
					//   ← FUN_0092554c(cited);首命中(hits==1,12725)
					//   → runnode_init(end)/runnode_init(start) +
					//   FUN_00a20eb2(238B,0034:676:两 runnode → 选区 +
					//   doc 通知 FUN_009783fa)移选区;非首命中 →
					//   editor_selCtor 懒建多选区上下文(12732-12735
					//   operator_new(0x18))+ FUN_00a211c6(238B,0034:808,
					//   通知面 009786fa)追加 — 选区/通知族 — cited —
					//   wave-2(宿主选区写侧未建模,calls 空缺承原样)
					const RunNode endN = RunNode::make(hit, 0, false);   // 12726(lVar8=lVar9 尾)
					const RunNode startN = RunNode::make(hitStart, 0, false);  // 12728
					Q_UNUSED(endN); Q_UNUSED(startN);   // 消费腿 cited(上行)
					continue;                 // 12742→12708 同 run 重搜
				}
				// type==4 undo 替换腿(12663-12707):editctx iter 懒建
				//   (12665-12669 operator_new(0x18)+editctx_beginIter)/
				//   editor_selMake("Replace All")懒建(12671-12675,
				//   operator_new(0x10))/ FUN_008990b2 替换串空判(12678):
				//   空 → editor_undoBegin 直写(12680-12684,数据 =
				//   *(re+0x10)+*(*(re+0x10)+0x10));非空 →
				//   FUN_00925564+FUN_008990c0 打包 + repLen←ba.size
				//   更新(12690)+ editor_undoBegin(12691-12694)—
				//   codec/undo 族 — cited — wave-2
				// 【notifyTextChanged 接线点】对位 0x4f00 段 D 挂点:
				//   语料同位 = per-hit editor_undoBegin 应用面(12682/
				//   12691)→ doc 观察链 vt8 选区平移;参数 = (命中位
				//   hitStart,delLen=hitLen,insLen=repLen,12704 推进前)
				//   —— 本腿不达,搜索/codec 引擎落地时随 0x4f00 段 D
				//   同批激活
				// 12704-12706:from += repLen、to += repLen−hitLen
				//   (run 尾伸展)、run 尽 break(语料 = type==4 腿内)
				if (type == 4) {
					from += repLen;               // 12704
					to += repLen - hitLen;        // 12705
					if (to <= from)               // 12706
						break;                    //   run 尽 → 下一 run
				}
				// 非 2/4 型直落重搜面(语料 do-while 直入);12708
				//   hitLen!=0 → 同 run 重搜;12709-12714 hitLen==0 防
				//   死循环腿 FUN_00925304(12B,0030:20331)步进 +
				//   12715-12718 重搜 — cited — wave-2(结构 = while(true)
				//   重入;searcher 推进面 cited)
			}
		}
		// —— 段 F 收尾(12760-12776)——
		// 12760-12762:type==2 且有命中 → FUN_00a235ce(356B,0034:2405,
		//   -1,0 全文档刷新)刷新腿 — cited — wave-2(00a23206/
		//   00a20a56/00a209e4 深腿未解);12764 runlist 析构 = RAII
		//   承载零操作;12765-12775 三懒建槽收尾(editor_selCtor →
		//   FUN_00974856/selMake → FUN_00963b22/editctx iter →
		//   FUN_00a161d8 + operator_delete ×3)— 占位下不懒建 →
		//   无槽可收,同相
		// —— 段 G 尾(12778-12785)——
		// _M_release ×2(codec 查找/替换串 QByteArray 引用)— cited —
		//   wave-2(RAII 承载零操作);return iVar4
		return QVariant(hits);
	}
	default:
		// 其余 ~44 个 fork 特性(scrollbar marks/margin 链表/
		// std::string 返回族/hexBase…):真名与语义锚见
		// EDITOR-ENGINE-COMMANDS.md,按需逐个接
		(void)a; (void)b;
		return QVariant(0);
	}
}
