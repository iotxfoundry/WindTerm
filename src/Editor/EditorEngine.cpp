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
	case 0x75c5:     // setIndentSize
		send(SCI_SETINDENT, a.toInt());
		return QVariant(0);
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
	case 0x756d:     // 标记注册(FUN_00925c02 sortedvec 插入 + 0092671c
	                 //  回调接线 — 片段标记模型 cited)
		return QVariant(0);
	case 0x756e:     // 同 0x756d(变体,cited)
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
	default:
		// 其余 ~44 个 fork 特性(scrollbar marks/margin 链表/
		// std::string 返回族/hexBase…):真名与语义锚见
		// EDITOR-ENGINE-COMMANDS.md,按需逐个接
		(void)a; (void)b;
		return QVariant(0);
	}
}
