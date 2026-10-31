#include <QTextCodec>
#ifndef EDITORCONTEXT_H
#define EDITORCONTEXT_H

#pragma once

// 编辑器上下文状态模型(重建侧命名字段;语料为 0x00a1-00a3 区 handler
// 写入的多 KB 对象,偏移见注释)。Phase 3 按命令逐字段补齐;软复位
// (session_view_soft_reset)与视图刷新(vtable+0xa0)腿在 Phase-4
// 视图装配时接线。

#include <QByteArray>
#include <QString>
#include <QVariant>
#include <QHash>
#include "MarkersStore.h"
#include <QVariantList>
#include "RunNode.h"

class EditorContext
{
public:
	// --- hex 查看器(0x759a/0x759e;FUN_00a28e7c/00a30c2e)---
	int hexBase = 10;            // +0x1120(合法域 2..0x24)
	QString hexBaseStr = "255";  // +0x1124(FUN_007c4392 number(0xff))
	bool hexMode = false;        // +0x1128
	quint64 mask1108 = 0;        // +0x1108(FUN_00a23d26/00a24126 掩码)
	bool flag21d = false;        // +0x21d(0x7533 写)
	signed char field1067 = 0;   // +0x1067(0x7535 写/FUN_00a30d26)
	int hexField210 = 0;         // +0x1098 对象 +0x210(FUN_00a21b1e)
	int field1b1 = 0;            // +0x1b1(0x7586 写)
	bool flagD84 = false;        // +0xd84(0x7588 邻区写)
	bool flagD8d = false;        // +0xd8d(0x758b 写)
	bool flag1ae = false;        // +0x1ae(0x7593 写)
	bool flagD8e = false;        // +0xd8e(0x7599 写)
	int fieldD94 = 0;            // +0xd94(0x759c 写)
	bool flag225 = false;        // +0x225(刷新门;0x7598 查询)
	bool flagEc3 = false;        // +0xec3(0x75a5 写;FUN_00a2d3ec)
	bool flag1128 = false;       // +0x1128(FUN_00a2d3ec 门读)
	double lineHeightD20 = 0.0;  // +0xd20(行高 A;FUN_00a2041e max)
	double lineHeightD38 = 0.0;  // +0xd38(行高 B;FUN_00a2041e max)
	unsigned char field240 = 0;  // +0x240(0x7537 写 0/0x7538 邻位写 1;语义未解)
	int caretShape = 0;          // +0x10ec(0x753c 读/caret_changeShape 00a29a48 写)
	bool field213f8 = false;     // +0x1f8(0x757c 写/0x757b 读)
	int field213_260 = 0;        // +0x260(0x7584 读/FUN_00925310 写)
	float field1a1 = 0.f;        // +0x1a1 行距倍率(0x758c;合法域 (0,2])
	bool docIndentTabs = false;  // +0x279(0x75c3 读/0x75c6 写)
	QVariantMap linkMap;         // 0x753a 到达参数暂存(FUN_0092ed32 真身化时消费)
	// 0x7552 挂起标注记录(FUN_0098075a doc+0x38 槽的字段承接;批 67a)
	qint64 pendAnnPos0 = -1;     // 记录 +0x00
	qint64 pendAnnPos1 = -1;     // 记录 +0x08
	quint8 pendAnnCh1 = 0;       // +0x10
	quint8 pendAnnCh2 = 0;       // +0x11
	QByteArray pendAnnBa;        // +0x18 槽
	// margin 列表(语料 +0x1ab/+0x1ac,0x18 步长条目:名字 + 标志)
	struct MarginEntry {
		QString name;
		bool hidden = false;   // 语料 +0x0b bit7
	};
	QList<MarginEntry> marginList;
	bool flagD8f = false;        // +0xd8f(0x7582 写)
	bool flagD91 = false;        // +0xd91(0x7583 写)
	bool flag1b3 = false;        // +0x1b3(0x756a 写;变更触发刷新)
	bool flag227 = false;        // +0x227(0x756c 写)
	int fieldD9c = 0;            // +0xd9c(0x756a 邻区写)
	quint64 currentBufferId = 0; // +0x600(FUN_0092f0f6 setCurrentBuffer)
	int taskGeneration = 0;      // +0x128(FUN_0092e44e 线程池代计数)
	// --- 文档模型层(批 58 语料:+0xe0 doc 对象族)---
	// 语料:多态文本缓冲包装(vtable:+0x28 长度/FUN_00928a7a +0x30
	//   拷出)+ QTextCodec 解码(FUN_0099785e ConverterState 静态态
	//   DAT_011c26c0);Qt QByteArray 原生承载(等价面)。
	QByteArray docBytes;                 // +0xe0 文档字节缓冲
	QTextCodec *docCodec = nullptr;      // 解码 codec(nullptr = UTF-8)

	// FUN_009252d4(15B→FUN_009987a2 123B):pos 处字符字节长
	//   (编解码多字节行走;flag = CRLF 对分支 FUN_009975de \r\n)
	int docCharLength(long pos) const
	{
		if (pos < 0 || pos >= (long)docBytes.size())
			return 0;
		if ((docBytes[(int)pos] & 0x80) == 0)
			return 1;                    // ASCII 单字节
		const unsigned char c = docBytes[(int)pos];
		if ((c & 0xE0) == 0xC0) return 2;
		if ((c & 0xF0) == 0xE0) return 3;
		if ((c & 0xF8) == 0xF0) return 4;
		return 1;
	}

	// FUN_0093079a(257B)链:定位 → substr → codec 解码 → ucs4
	uint docCharCodeAt(long pos) const
	{
		const int len = docCharLength(pos);
		if (len <= 0)
			return 0xFFFF;               // 语料空 → 0xffff
		QByteArray seq = docBytes.mid((int)pos, len);
		QTextCodec *codec =
		    docCodec ? docCodec : QTextCodec::codecForName("UTF-8");
		if (codec == nullptr)
			return 0xFFFF;
		const QString s = codec->toUnicode(seq);
		if (s.isEmpty())
			return 0xFFFF;
		const QVector<uint> cps = s.left(1).toUcs4();
		return (uint)cps.value(0, s.at(0).unicode());
	}

	// FUN_00928404(80B):自 from 起首一个字符谓词失败位(FUN_00927940
	//   谓词/FUN_00925200 起点 —— cited — wave-2;docLen 已转写)
	int docNextNonMatching(long from) const
	{
		if (from < 0)
			return 0;
		long p = 0;                    // 语料 FUN_00925200 起点
		const long len = docBytes.size();
		while (p < len) {
			// FUN_00927940(doc,p)谓词 — cited — wave-2
			++p;
		}
		return (int)p;
	}

	// buf_substr(0092acb8,192B):夹取 + 空返回 shared_null 语义
	QByteArray docSub(long from, long to) const
	{
		const int len = docBytes.size();
		long f = qBound(0L, from, (long)len);
		long t = (to < 0) ? len : qBound(0L, to, (long)len);
		if (f >= t)
			return QByteArray();         // 语料 shared_null
		return docBytes.mid((int)f, (int)(t - f));
	}

	// --- 边栏(0x7597;FUN_00a1fd8c)---
	bool marginTrackChange = false;  // +0x113a

	// --- margin 链(0x7591/7594/7595;FUN_00a4bc60)---
	QVariantList margins;            // margin 定义对象列(QList 语义)
	bool marginFlag1ab = false;      // +0x1ab
	bool marginFlag1ac = false;      // +0x1ac
	bool marginFlag1ad = false;      // +0x1ad
	bool marginFlag1ae = false;      // +0x1ae
	void removeMargin(const QString &name)
	{
		// FUN_00a4bc60(387B):按名移除,后续元素前移
		// (语料的逐字段搬移即 QList 压缩语义)
		for (int i = 0; i < margins.size(); ++i) {
			const QVariantMap m = margins.at(i).toMap();
			if (m.value("name").toString() == name) {
				margins.removeAt(i);
				return;
			}
		}
	}
	void clearMarginFlags()
	{
		// 0x7595(inline):四标志清零(+0x1ab..+0x1ae)
		marginFlag1ab = marginFlag1ac = marginFlag1ad = marginFlag1ae = false;
	}

	// --- pair 高亮/片段(0x7583/75b4/75b5/75ba)---
	int pairHighlightUnmatched = 0;  // FUN_00a10c68 置 2(枚举)
	bool snippetMode = false;        // FUN_00926ebc(+0x1098)状态位

	// --- 视口/滚动(0x75b2-75b5;FUN_00a169cc/00a167ac 对)---
	int viewportFlag2c = 0;          // 视口对象 +0x2c 字节(0x75b4 写)

	// --- margin 元数据(0x7567/7568)---
	double marginWidth = 0;          // +0x1a2(double)
	QList<int> marginIcons;          // +0x1b4(QList<int>;0x7568 重建)

	// --- 样式剥离(0x7558;FUN_00a26756 尾)---
	bool bufferStyleFlag = false;    // +0x1098 buffer 样式收集标志
	quint64 pairCacheFc0 = 0;        // +0xfc0(剥离时清零)
	quint64 pairCacheFc8 = 0;        // +0xfc8

	// --- buffer/状态簇(0x7556-0x7564;+0x1098 buffer / +0xed8 状态)---
	bool isSuperBuffer = false;      // +0xf8 动态类型 cast(00927ec8)
	QString bufferString;            // 0x755a(vt+0x58 虚调用 — cited)
	bool bufferModeB = false;        // 0x755b(+0xf8 对象置换 0x48B — cited)
	quint32 stateEd8 = 0;            // bit1=0x755c/7561 布尔 bit2=脏 bits3+=ms
	quint32 valDd0 = 0;              // +0xdd0(0x7563 set)
	int val1ba = 0;                  // 0x755f 查询
	double val1bb = 0;               // 0x7560 查询(double)

	// --- 尾块状态(0x75d0-0x75ff;disp 24100-24518)---
	bool flag1bc = false;            // 0x75d7 查询 / 0x75db 写(+soft_reset)
	int fontScale = 0;               // doc+0x14(00a218dc);0x75d9 夹 [0,10000]
	bool flag210 = false;            // 0x75e0(+00a2cea8 刷新 cited)
	bool flag1083 = false;           // 0x75e2 查询
	bool flag1082 = false;           // 0x75f1(+009502de 传播 cited+soft_reset)
	quint32 remoteCaretFlag = 0;     // +0xedc(0x75e6 "line.caret.remote" 特例)
	quint64 bufField158 = 0;         // buffer+0x158(0x75f3 查询)
	quint64 bufField160 = 0;         // buffer+0x160(0x75f2 查询/0x75f4 写,<0→-1)
	quint32 modeEnum2c0 = 0;         // 0x75f5(00925ae4;(v&~4)!=3 时缓存 -1)
	long long bufObjField = -1;      // 0x75f9 查询(00927170:obj+0x20)/0x75ff 写
	QByteArray timestampFormat;      // 0x75fc(00927216:indexOf('z') 探测)
	bool timestampHasZ = false;
	QByteArray timestampLongFormat;  // 0x75fe

	// --- runnode 面(+0x1068 块光标锚;写入=块编辑路径 00a2a2xx)---
	RunNode blockNode;               // 当前块样式节点(0096bbc6/00a2a2xx 写)
	quint32 bufField148 = 0;         // buffer+0x148(0x75ec hex 模式选)

	// --- 标记注册表(+0x1098+0x100 sortedvec;+0xc0 游标族同型)—
	// 键=位置保序去重;原版为自旋锁槽阵(FUN_009a088e),行为模型
	// 用有序表,单线程等价
	// markers 读侧真身(批 67a;与下行行为模型并存,构建者批后接管门)
	wt::MarkersStore markersStore;
	// E 对象面(批 69 勘正:原误挂 MarkersStore;E=doc+0xc0 宿主态)
	quint32 eStopCount = 0;            // E+0x128(0x754d 停机计数)
	QMap<QString, void *> eNodes;      // E+0x2d8(0x754d 遍历;值+8=type)
	QList<QByteArray> eSerialEntries;  // E+0x250(0x7545 序列化导出 append)
	QString eName;                     // E+0x2b8
	void *ePool = nullptr;             // E+0x118(线程池,0x754d)
	QHash<QString, QColor> styleTable; // 样式表占位(0x7547 S3;+0xe00 面未建模)
	// char-used 视图(批 75 勘察:*(ctx+0x180) = 0x20 壳{vtbl, RS8,
	//   密排 GapBuffer} ≡ RunStyles::FillRange;路线 A = RS8 委托坍缩,
	//   与 MarkersStore rsFill8 同面;ret 1=吸收/0=新写 与 changed
	//   不同相 = QUIRKS 候选,76c 笔记)
	Scintilla::RunStyles<int, char> *charUsedView = nullptr;
	QVector<RunNode> markers;
	int markerInsert(const RunNode &n)
	{
		for (int i = 0; i < markers.size(); ++i)
			if (markers.at(i).pos == n.pos)
				return i;                // FUN_00920442 查得即返
		auto it = std::lower_bound(markers.begin(), markers.end(), n.pos,
		                           [](const RunNode &a, long long p) {
			                           return a.pos < p;
		                           });
		markers.insert(it, n);           // sortedvec_insert;00925bd4 通知 cited
		return int(it - markers.begin());
	}
	RunNode markerAt(int idx) const
	{
		// FUN_00926e1c:越界 = 无效节点(空 RunNode)
		return (idx >= 0 && idx < markers.size()) ? markers.at(idx)
		                                          : RunNode{};
	}

	// --- 渲染 doc/ed 字段(批 75 B 级四被叫;r5 §3 M4 表逐字段补)---
	//   写入命令未落地:全部缺省 = 门关/0(安全缺省,不虚构)
	double indentWidthCf8 = 0.0;       // doc+0xcf8 缩进宽(columnMarker2/wrapSymbol/hex_division)
	int foldCountD34 = 0;              // doc+0xd34(columnMarker2 x 修;r3"折叠计数")
	double highlightOffsetD0c = 0.0;   // doc+0xd0c line.highlight x 修(s_line_highlight)
	bool lineHighlightOn = false;      // doc+0xd4f line.highlight 开(s_line_highlight 门)
	int hexGroupWidth = 0;             // doc+0xd54 hex 组宽(s_hex_division)
	bool columnMarkerOn = false;       // doc+0xd58 列标记开(columnMarker2 门)
	int columnMarkerMode = 0;          // doc+0xd5c 模式(==0 时 columnMarker2 承接)
	bool wrapSymbolOn = false;         // doc+0xda0 wrapSymbol 开(s_line_wrapSymbol 门)
	bool flagEc2 = false;              // ed+0xec2(FUN_00a75976 早退门;M4 表"selection flag")
	int hexByteWidth1118 = 0;          // ed+0x1118 hex 字节宽(s_hex_division 取模)
	int hexSub111c = 0;                // ed+0x111c(FUN_00a28aea 余数子模)
	double bufD18 = 0.0;               // buffer+0x18(FUN_00a218e8 左缘 int 截断;wrapSymbol)
	QList<int> columnMarkers;          // doc+0xd78 列 RB-tree(节点 +0x20 int)行为模型:
	                                   //   有序表 in-order 遍历(markersStore 同款先例,
	                                   //   单线程等价;插入语义 00a682e6 cited)
	// --- hotspot 区间(批 79;r6 §1/FUN_00a6aae6)---
	//   写侧命令未落地:缺省 −1/0 = 门关(00a6ab76 ==−1 早退),不虚构
	long long hotspotLo1048 = -1;      // ed+0x1048(FUN_00a6aae6 门 + fill pos)
	long long hotspotHi1050 = 0;       // ed+0x1050(len = +0x1050 − +0x1048,可负原样)
	// --- 语法名(ed+0xfd8;M4 表;parsePairDef styleLookup/markerFill key)---
	//   写侧未落 → nullptr(空名 → 0092671c _Rep len==0 早退,同相)
	const char *syntaxNameFd8 = nullptr;   // *(char**)(*ed+0xfd8)
	// --- pairDef 表(ed+0x10e0;批 79;r6 §2/FUN_00a6b37e)---
	//   FUN_00a24e72(12B)@0034:3596 = *(ed+0x10e0)+8;数组 *(base+8)..*(base+0x10),
	//   24B/项;写侧未落 → 缺省空表(parsePairDef 空表早退同相)
	struct PairDefEntry {
		qint64 open = 0;               // 项 +0x00(首 long)
		qint64 close = 0;              // 项 +0x08(次 long;len = close−open)
		qint64 flag = 0;               // 项 +0x10(第三 long;拷贝腿携带,消费面未解)
	};
	QList<PairDefEntry> pairDefs;      // parsePairDef 整表堆拷(00a6b3ax)→ QList 值语义

	// --- M1 trigger 组注册表(ed[1]+0x100 = E 宿主行为模型;批 79,r5 §0)---
	// 组对象 = sortedvec_insert(009205ae 段)产的 0x20 vtable obj(PTR_FUN_011acb90 +
	// 0x50B initThread + 0x30B Uint32SkipRunStyles);行为模型 = 有序 runs 表,
	// 单线程等价(markersStore 同款先例)。shortcut: run 末界未建模,读侧
	// (a6b872 Trigger 面消费 u32)落地前须升级 run-end 载体。
	quint8 triggerRev8 = 0;                    // E+8 低 2bit 版本号(00920a8a 自增翻转)
	QHash<QByteArray, int> triggerNameIds;     // ByteArrayBimap(E+0x88;00a7cbd0 523B cited)
	struct TriggerGroup {
		bool flag = false;                     // sortedvec_insert flag 参(00925c02 p3)
		QMap<qint64, quint32> runs;            // pos→u32 打包值(00920a8a 打包式)
	};
	QHash<QString, TriggerGroup> triggerGroups;

	// FUN_009257a8(12B)@0030:20735 → FUN_0092043a(8B)→ trigger_findFont
	//   (00923650,1880B@0030:18805:BST 摘除 + 4-deque 摘挂 + 组对象 D1 析构 +
	//   FUN_00923220 回插)—— 深体 cited — wave-2;行为模型 = 该组 runs 清空
	void resetTriggerGroups(const QString &name)
	{
		// 语料:BST 查不到 → no-op(不建组);查到 → 摘除+D1 析构
		auto it = triggerGroups.find(name);
		if (it != triggerGroups.end())
			it->runs.clear();                  // trigger_findFont 尾 D1(00923a8x)
	}
	// FUN_00925c02(92B)@0030:21179:00920442(182B BST 查)查得即返;miss →
	//   sortedvec_insert(1036B)+ FUN_00925bd4 通知(cited)。组柄 = 名
	//   (语料返回组对象指针;模型名柄 1:1)
	TriggerGroup &markerGroup(const QString &name, bool flag)
	{
		auto it = triggerGroups.find(name);
		if (it == triggerGroups.end()) {       // 00920442 miss → insert(flag)
			it = triggerGroups.insert(name, TriggerGroup{});
			it->flag = flag;
			// FUN_00925bd4 监听者通知 — cited — wave-2
		}
		return it.value();                     // 查得即返
	}
	// FUN_0092671c(279B)@0030:21716:名空早退(std::string _Rep len==0 门,
	//   0092673f)→ FUN_00920a8a(221B@0030:16443):ByteArrayBimap(E+0x88)名→id;
	//   rev = E+8 低 2bit 自增翻转,旧值入包;
	//   val = rev<<30 | on&0x1f | (style3b&7)<<5 | (id&0x3fffff)<<8;
	//   fill_range 循环(模型 = 单遍区间吸收)。
	// notify!=0 腿:SciSchemeChangeEvent(0x3f0) 组播 FUN_0092601a/FUN_00924f02
	//   — cited — wave-2(两调用点均 notify=0,腿不可达)
	void markerFill(const QString &grpName, qint64 pos, qint64 len, int on,
	                int style3b, const QByteArray &name, bool notify)
	{
		Q_UNUSED(notify);                      // 0x3f0 组播腿 — cited — wave-2
		if (name.isEmpty())
			return;                            // 0092673f _Rep len==0 门
		if (!triggerNameIds.contains(name))    // ByteArrayBimap miss 建号 — cited
			triggerNameIds.insert(name, triggerNameIds.size() + 1);
		const quint8 rev = triggerRev8;        // 旧值入包(00920b0x)
		triggerRev8 = quint8((triggerRev8 + 1) & 3);
		const quint32 val = (quint32(rev) << 30) | (quint32(on) & 0x1fu)
		    | ((quint32(style3b) & 7u) << 5)
		    | ((quint32(triggerNameIds.value(name)) & 0x3fffffu) << 8);
		TriggerGroup &g = triggerGroups[grpName];
		// 区间吸收:[pos, pos+len) 内旧 run 起点抹除(fill_range run 分裂语义;
		//   run 末界未建模 — 见 shortcut 注)
		auto it = g.runs.lowerBound(pos);
		while (it != g.runs.end() && it.key() < pos + len)
			it = g.runs.erase(it);
		g.runs.insert(pos, val);               // 单遍吸收(fill_range 循环 00920a8a)
	}

	// --- 语义动作 ---
	void setHexBase(int base)
	{
		// FUN_00a28e7c:值域 2..0x24;变更时刷新 baseStr 并在
		// hexMode 开启时触发重算(FUN_00a28c70)+ soft_reset — cited
		if (hexBase == base || (unsigned)(base - 2) >= 0x23)
			return;
		hexBase = base;
		hexBaseStr = "255";   // 语料:number(0xff) 固定值 — QUIRKS
		// if (hexMode) { FUN_00a28c70; session_view_soft_reset; } — cited
	}
	void setHexMode(bool on)
	{
		// FUN_00a30c2e(247B):置位 + 模式相关重配置尾 — cited
		hexMode = on;
	}
	void setMarginTrackChange(bool on)
	{
		// FUN_00a1fd8c:变更时 vtable+0xa0 视图刷新 — cited
		marginTrackChange = on;
	}
};

#endif // EDITORCONTEXT_H
