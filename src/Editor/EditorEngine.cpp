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

#include "ScintillaEditBase.h"
#include "Scintilla.h"

// HYBRID EditorEngine: standard SCI_* delegates to real Scintilla
// (src/Scintilla static libs); WindTerm EXT/WT stays in customDispatch.

struct RetEntry { unsigned cmd; char kind; };

static const RetEntry scintilla_returns[] =
{
#include "scintilla_returns.inc"

};

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
			// FUN_00a76608(4628B)initDrawCtx — cited — wave-2
			// s_text_controlChar_a77836(&ctx)(4123B)— cited — wave-2
			// s_grep_mark_a6afa2(ed, doc, &ctx)(440B)— cited — wave-2
			if (!m_ctx.hexMode) {        // *(char*)(*ed+0x1128)==0
				// s_PairColor_a72272(ed, doc, &ctx)(1001B)— cited
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
			// s_text_selection_a67e62(603B)— cited
			// s_text_selection_a680c6(532B)— cited
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
			QColor cSaved, cUnsaved, cModified;          // 缺省 Invalid 同效
			auto styleColor = [&](const char *key) -> QColor {
				// 0095021a(+0xe00)→ 0094a7f8(bit1 门)→ 0094a5b2
				//   环形 16B 槽 —— QHash 占位(丢 bit1 门,登记回填)
				const auto it = m_ctx.styleTable.constFind(
				    QLatin1String(key));
				return it == m_ctx.styleTable.cend()
				    ? QColor() : it.value();
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
			// ===== S5 grep 4 注册(49720-49725)=====
			// FUN_00a66ae8(1031B)分级:① margin 行对象表
			//   FUN_009258b2(185B)→0092586c(this[1]+0x2d8 族,
			//   非 markersStore 面)— 未建模,查不到 → 段尾 return;
			//   ② grep 结果浮点表(E+0x108,FUN_00926b1c→009c8bf2,
			//   行 6‖列 8 特判覆色)— 未建模;③ 行 run 范围
			//   FUN_00927472(29B)→0096d0e2 — 未建模;④ 色腿
			//   FUN_0095021a+editor_styleAt — S3 styleTable 同占位;
			//   ⑤ fillRect 条带循环(fold 跳步 FUN_00958498)依赖③。
			//   ①②③⑤ cited — wave-2;行对象表空 = 原版查不到 →
			//   return 同相,④⑤ 不可达不落(不虚构)。
			auto grepEntry = [&](int row, int col, const char *key) {
				Q_UNUSED(row); Q_UNUSED(col); Q_UNUSED(key);
			};
			grepEntry(8, 8, "grep.mark");                // 00a72ec1
			grepEntry(6, 0, "grep.mark");                // 00a72ed7
			grepEntry(5, 0, "grep.match");               // 00a72ee9
			grepEntry(7, 0, "grep.mark");                // 00a72efb
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
				//   cited — wave-2;空表默认色 DAT_011c25d0/e0 随占
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
	case 0x7576: {   // 30070:runnode 插入样式表 — FUN_0095c92c(400B @0031.c:29031)
	                 //   主循环骨架真身;执行体 c1c2(1857B @0031.c:28734)
	                 //   P0/A/B/R/T 分级(批 70 分段地图 + 76/76b/76c 笔记)
		const qint64 pos = a.toLongLong();              // dispatch 表 30070:
		                                                //   toLongLong → runnode_init
		const RunNode node = RunNode::make(pos, 0, 0);  // runstyles_runnode_init
		                                                //   (0096bac0 66B;RunNode.h 真身)
		const qint64 nodePos = node.pos;                // FUN_0096bbc0(5B):节点 +8 读
		(void)node; (void)nodePos;                      // 消费腿 FUN_009587cc(159B)/
		                     // FUN_00a208a4(75B,kind=1 → +0x10c8 视图通道)— cited — wave-2
		// *(ctx+0x178) run 状态向量未建模 → runcount==0 门(L29035 ==0 → 0)壳态
		//   按语料字面走此路(向量缺省 ≡ 0);editctx_beginIter(kind=1,00a16150
		//   135B)/FUN_00a161d8(221B)迭代器收尾 — cited — wave-2
		// A/B 路 char-used 标记腿实接(c1c2 L28867/L29010 → gapbuffer_get_chars_locked
		//   00890880 2599B 全读,76b/76c):≡ RunStyles::FillRange(char-kind 域,
		//   RunStyles.cxx:132)→ RS8 一体委托(路线 A 定案;与 MarkersStore.h:187
		//   runstylesUpgrade case0 同一委托面);val=1 已用(A)/0 未用(B);
		//   charUsedView null → 壳期跳过
		auto charUsedMark = [this](qint64 s, bool used, qint64 len) {
			if (!m_ctx.charUsedView || len < 1)   // len<1 → *changed=0,ret 0(00890880 首门)
				return false;
			// QUIRKS 23:语料 ret 1=吸收/0=新写,与 FillRange changed 不同相;
			//   changed==false → 原版恒 ret 1(吸收);true 时两相不可辨 — 行为门裁决点
			return m_ctx.charUsedView->FillRange(int(s), char(used ? 1 : 0),
			                                     int(len)).changed;
		};
		(void)charUsedMark;   // 驱动点 = 逆序 runvector 循环(L29057 count-1→0;
		                      //   命中 run vt38/vt40 取界 → c91e→c1c2)— cited —
		                      //   wave-2(容器未建模;A 路 p4=i≠0:标记已用 +
		                      //   runstyles_upgrade(920B,MarkersStore
		                      //   runstylesUpgrade 同面)+FUN_0095da64 prune;
		                      //   i==0 → B 路 标记未用;p4 尾跳勘定,76 笔记 §2)
		// R 段 style==1 重扫+runnode 构建(L28920-29008)/R2 行旗传播(+0x168
		//   flagmask,L28954-28990)/T 拆除(FUN_00957e2c)— cited — wave-2
		//   (底座 +0x170 styleBank/FUN_00962310 restyle/flagmask/skipruns/
		//   +0x178 runvector/+0x180 视图宿主均未建模;批 70 分段地图)
		return QVariant(0);   // true → vt+0xa0 刷新 — cited(Phase-4b)
	}
	case 0x757a:     // FUN_00a21b6a(412B)buffer 模式切换:mode1/2 →
	                 //   FUN_0092c482 持久化 +0x210;mode3 全行 runnode
	                 //   回填(+0x1067 门)— cited — wave-2
		return QVariant(0);
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
	default:
		// 其余 ~44 个 fork 特性(scrollbar marks/margin 链表/
		// std::string 返回族/hexBase…):真名与语义锚见
		// EDITOR-ENGINE-COMMANDS.md,按需逐个接
		(void)a; (void)b;
		return QVariant(0);
	}
}
