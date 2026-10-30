#include <QCollator>
#include <QPainter>
#include <QRegularExpression>
#include <QPixmap>
#include <QLocale>
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
	case 0x75dc: {   // FUN_00928624:行扫描到 \n 的长度 + 存储节点样式
	                 //  (0092522a/00925200 buffer 链 cited;行长=SCI 适配)
		const RunNode &n = m_ctx.blockNode;
		const long long line = m_edit->send(SCI_LINEFROMPOSITION, n.pos, 0);
		const long long len = m_edit->send(SCI_GETLINEENDPOSITION, line, 0)
		    - m_edit->send(SCI_POSITIONFROMLINE, line, 0);
		return QVariant((int)(n.style() + len));
	}
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
	case 0x753e:     // FUN_00a417fe(112B)→ FUN_00a41552(649B 渲染
	                 //   核心);a.toDouble() 语料未消费,原样
	                 //   — cited — wave-2(渲染专用批)
		return QVariant(0);
	case 0x753f:     // 槽 +0xc0 = FUN_00948b9b(thunk→FUN_00948b5a)
	                 //   — 槽已定位(批 66),体 cited
		return QVariant(0);
	case 0x7541:     // FUN_00a204a0(216B)scrollToFraction:
	                 //   target = f*len − lines*f 夹取 → scroll obj
	                 //   +0x10c8{+0x30/+0x38/+0x3c} — cited(滚动
	                 //   几何 Phase-4b)
		return QVariant(0);
	case 0x7544:     // FUN_00a4186e(86B)可视区 pixmap(pos..pos+lines,
	                 //   高参 −1=实际视高);a.toReal() 未消费原样
	                 //   — cited — wave-2
		return QVariant(0);
	case 0x7545:     // FUN_00933366(892B)markers 导入:标记行收集
	                 //   (0093f7aa)→ QDataStream 序列化 → M+0x250
	                 //   append → SciScrollBarMarkEvent(0x414) 广播
	                 //   — cited — wave-2
		return QVariant(0);
	case 0x7546:     // 槽 29(vt+0xe8,self,1)= 水平滚动条可见性
	                 //   (批 66 勘破:实例 vptr 0x11afd30/派生重写
	                 //   FUN_00948a48:policy 判定 + QScrollBar bit15)
	                 //   → SCI 承接(混合边界:标准行为委托真库)
		return QVariant((bool)send(SCI_GETHSCROLLBAR));
	case 0x7547: {   // s_line_modified_a72ad6(3008B)S1 构图真身化
	                 //   (批 66 分级转写):double 高/宽四舍五入 →
	                 //   QPixmap ctor + QColor(0,0,0,19)fill;
	                 //   S2 度量(max 怪癖:denom = max(textLen,
	                 //   可视行数 FUN_00a20438))/S3 样式装载
	                 //   (editor_styleAt 面)/S4 色带(FUN_00927a78)/
	                 //   S5 grep 注册(FUN_00a66ae8 1031B)/S6 逐条目
	                 //   M+0x250 无锁读(怪癖原样) — cited — wave-2
		const double dh = a.toDouble();
		const double dw = b.toDouble();
		QPixmap pm(qRound(dw), qRound(dh));
		pm.fill(QColor(0, 0, 0, 19));   // 00a72b6e QColor(0x13)
		if (dh > 0.0) {
			QPainter p(&pm);   // 00a72bbd(S2 起腿 cited)
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
	case 0x754d:     // FUN_0092e44e(195B)后台解析全停(批 67a 主体
	                 //   真身化;FUN_009264ba 腿 cited — wave-2)
		m_ctx.markersStore.stopAllBackground();
		return QVariant(0);
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
	case 0x7576: {   // runnode 插入样式表:runstyles_runnode_init(66B
	                 //   已真身 RunNode.h)→ FUN_0095c92c(400B
	                 //   editctx_beginIter + runvector 遍历)插入;
	                 //   true → vt+0xa0 刷新 — cited — wave-2(插入体)
		return QVariant(0);
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
