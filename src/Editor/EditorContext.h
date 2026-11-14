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
#include <QThreadPool>       // 批 136:ePoolA/E+0x110 · ePoolB/E+0x118
#include <QThread>           // 批 136:idealThreadCount 池宽
#include "ENodes.h"          // 批 136:eNodes 值对象(DocumentTask/ScanTask/Runner)
#include "MarkersStore.h"
#include "ModTrack.h"
#include "MatchEngine.h" // 批 127:+0xf8 载体缝(ctor 挂线/dtor 拆链)
#include <QVariantList>
#include <QColor>        // 批 127:隐式 dtor 实例化 QHash<QString,QColor> 需全型
#include <limits>
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
	bool field1b2 = false;       // +0x1b2(0x7581 写;高亮跟随开关)
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
	// margin 列表(语料 +0x1ab/+0x1ac,0x18 步长条目;批 79 位级布局:
	// 默认构造 FUN_0094fc8c(ba,4) = +0x0a=0x84/+0x0b=0x8b/symbol=0xFFFFFFFF;
	// 0x7596 命中回写段 00a43134-00a437e4)
	struct MarginEntry {              // 0x18B/条(语料步长 0x18:00a43160 *0x18 步进)
		QString name;                 // +0x00 匹配键(00a43134 memcmp 到 d->size)
		quint16 spare08 = 0;          // +0x08 全 0(FUN_0094fc8c qword 常量低 16 位)
		quint8 flagsA = 0x84;         // +0x0a bit0-3 type(默认4 symbol;1 blank/2 fold/3 number/5 text/6 timestamp,00a43340 qstrcmp 链)·bit4-5 border(1 dots/2 line,00a433e3 mask 0x8f 连带清 bit6)·bit6 spare·bit7 cursor 低位
		quint8 flagsB = 0x8b;         // +0x0b bit0-2 cursor 高位(u16(+0x0a)>>7&0xf:2=arrow/7=默认)·bit3-4 alignment(00a43523 mask 0xe7)·bit5 trackChange(00a435c0 mask 0xdf)·bit6 trackSelection(00a4361c mask 0xbf)·bit7 visible(00a432e4 &0x7f|b<<7)
		quint32 symbol = 0xffffffffu; // +0x0c type==4 符号码,默认 -1(FUN_0094fc8c 0xFFFFFFFF;00a437ac DAT_00cf882c 键 toUInt)
		quint16 flagsC = 0;           // +0x10 u32 视角:bit0-11 width(00a4367a)·bit12-15 rightPadding 低 4 位(00a4375f u32&0x3ff000)
		quint16 flagsD = 0;           // +0x12 bit6-15 leftPadding(00a436ee <<6)·bit0-5 spare
		quint32 pad14 = 0;            // +0x14 尾 4B(FUN_0094fc8c *(u64*)(+0x10)=0 覆盖;步长凑满 0x18)
		// 0x7592 `e.hidden = v` 左值写零改动承接(00a432e4 写面):
		//   读 = !(bit7),写 = (b&0x7f)|(!v)<<7;存储唯一位面 = flagsB
		struct HiddenBit {
			quint8 &b;
			explicit HiddenBit(quint8 &ref) : b(ref) {}
			operator bool() const { return !(b & 0x80); }
			HiddenBit &operator=(bool v)
			{
				b = quint8((b & 0x7f) | (quint8(!v) << 7));
				return *this;
			}
		} hidden;                     // +0x0b bit7 视图(引用绑定 flagsB)
		MarginEntry() : hidden(flagsB) {}
		MarginEntry(const MarginEntry &o)
		    : name(o.name), spare08(o.spare08), flagsA(o.flagsA),
		      flagsB(o.flagsB), symbol(o.symbol), flagsC(o.flagsC),
		      flagsD(o.flagsD), pad14(o.pad14), hidden(flagsB)
		{
		}
		MarginEntry &operator=(const MarginEntry &o)
		{
			name = o.name;            // 引用成员不可重绑:hidden 恒指本对象 flagsB
			spare08 = o.spare08;
			flagsA = o.flagsA;
			flagsB = o.flagsB;
			symbol = o.symbol;
			flagsC = o.flagsC;
			flagsD = o.flagsD;
			pad14 = o.pad14;
			return *this;
		}
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
	// 0x7594/0x7595 的 marginList 侧移除/清空(批 126 落到命令体内;
	// 本成员保留给 margin 定义列的旧承载,margins() 0x7591 已改
	// marginList 名单读 —— 语料 +0x1ab 向量与 marginList 同物)
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
	double hexViewHeight = 0.0;      // +0x10a0 obj+0x18 视口高(0x75a8 读;
	                                 //   写侧 00a21576 装配面 cited — 批 126)

	// --- margin 元数据(0x7567/7568)---
	double marginWidth = 0;          // +0x1a2(double)
	QList<int> marginIcons;          // +0x1b4(QList<int>;0x7568 重建)

	// --- 样式剥离(0x7558;FUN_00a26756 尾)---
	bool bufferStyleFlag = false;    // +0x1098 buffer 样式收集标志
	quint64 pairCacheFc0 = 0;        // +0xfc0(剥离时清零)
	quint64 pairCacheFc8 = 0;        // +0xfc8

	// --- buffer/状态簇(0x7556-0x7564;+0x1098 buffer / +0xed8 状态)---
	// doc+0xf8 buffer 载体(批 127 活性接线):ctor = editor_engineCtor
	//   00929fdd..00929fe1(operator_new(0x48) → FUN_009818aa = buffer32
	//   vptr 0x11ad818;置换 00927f16 false→009818aa / true→00989ef2 =
	//   buffer64 vptr 0x11ad910;析构 vt+8,拆链 0092f852 同面)。
	//   32 型 = CSuperBuffer32(0x48B;基 +0x40 = 0x48 体段:0x00 vptr /
	//   +0x08 blockRef(0x30B,00a5f4ca)/ +0x10 styleArr(0x20B,0096820e)
	//   / +0x18 caseFlag/长度 +0x20 数据指针 / +0x40 派生段);64 型 =
	//   CSuperBuffer64(FUN_00989ef2 → FUN_009c7114 0x70B 快照,同 +0x40)。
	//   vtable 槽消费面(批 119 转储):+0x28 charAt / +0x50 block16 /
	//   +0x58 string(0x755a)。engDispatch 载体 = docBytes 直读(charAt/
	//   block16 语义 = 批 119 真身已同相);isSuperBuffer = 00927ec8
	//   dynamic_cast(buffer64 命中)/ bufferModeB = 00927f16 选型位。
	//   engScan 载体接缝(批 127):FUN_0092a596 26276/26314 解引
	//   *(doc+0xf8) 传真体 → 承载替 = docBytes 平铺(&docBytes);attached
	//   false = 槽 null(壳态恒零块/类 0,批 118/119 同相)。
	bool isSuperBuffer = false;      // +0xf8 动态类型 cast(00927ec8)
	QString bufferString;            // 0x755a(vt+0x58 虚调用 — cited)
	bool bufferModeB = false;        // 0x755b(+0xf8 对象置换 0x48B 选型位,
	                                 //   FUN_00927f16 param_2 直证)
	bool superBufferAttached = false; // +0xf8 槽非空门(editor_engineCtor
	                                  //   00929fe1 即建 32 型 → 真载体;壳态
	                                  //   false → engDispatch 传 nullptr 同相)
	                                  //   置换接缝:0x755b(FUN_00927f16)真身
	                                  //   时同步置位;析构链 0092f852 → false。
	// +0xf8 载体取面(批 127):engDispatch param_1 承接 — attached →
	//   &docBytes(charAt/block16 语义 = buffer vtable 槽批 119 真身,
	//   docBytes 直读承载同相);壳态 → nullptr(恒零块/类 0 同相)。
	//   ctor 挂线(00929fe1 引擎 ctor 即建 32 型)/dtor 拆链(0092f852)
	//   经 MatchEngine::attach/detachScanCarrier RAII 承接(对象生命期
	//   = 槽生命期平铺;this 悬垂守卫 — detach 于析构先行)。
	const void *scanLineDoc() const
	{ return (superBufferAttached && MatchEngine::carrierLive())
	    ? static_cast<const void *>(&docBytes) : nullptr; }
	quint32 stateEd8 = 0;            // bit1=0x755c/7561 布尔 bit2=脏 bits3+=ms
	quint32 valDd0 = 0;              // +0xdd0(0x7563 set)
	int val1ba = 0;                  // 0x755f 查询
	double val1bb = 0;               // 0x7560 查询(double)

	// 0x75f6 快照名(M+0x2b8;FUN_00933830 0x75f6 读对,批 132)
	QString snapshotName8;

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

	// --- selection chunked-deque store(ed+0xfb8 0x88B;批 85/D2 定案:
	//   事件驱动 doc 观察者链 + 事务内懒建,绘制帧零写入)---
	// Span56(0x38B/项;0096bd82 init@0031:40640 / 0096be24 组装@40610 =
	//   {+8←param_3, +0x20←param_2} 逆序 + 0096bd68 flag):
	//   +0x00 u32 flagWord(0096bd68@0031:40640:byte3|flag<<6 后
	//   &0xc0000000);+0x08/+0x20 = 两 SelPos 24B(RunNode 形:
	//   u32 styleWord/s64 pos/f64 width,runstyles_runnode_init
	//   0096bac0@0031:40324 同构)
	struct Span56 {
		quint32 flagWord = 0;
		RunNode n0;               // +0x08(be24 ←param_3)
		RunNode n1;               // +0x20(be24 ←param_2)
	};
	// store(00a28516 建;0x88B):anchor@+0 + extras@+0x38。
	// 我方 QVector<Span56> 等价承载(r7 §1c:块/gap 控制字不承载
	// 可观察行为,size 内联公式 ≡ QVector::size(),怪癖登记)
	struct SelStoreX {
		Span56 anchor;            // +0x00(0096bd82:a=b={-1})
		QVector<Span56> extras;   // +0x38 deque 基(0x50B→等价替)
	};
	// ===== span 平移原语(批 81 于 EditorEngine.cpp 0x753e drawLineBody
	//   内 lambda 真身化;批 85 随 SelStoreX 成员化上提 — vt8 写侧
	//   notifyTextChanged 与绘制核共用,单一定义;地址注释原样迁移)=====
	// FUN_0096bb52(35B)@0031:40394 = (x >_lex y):pos2<pos1 返 1;
	//   同 pos → style(x>>1 < y>>1) — 真身化
	static bool pos_gt_bb52(const RunNode &x, const RunNode &y)
	{
		if (y.pos < x.pos)
			return true;
		if (x.pos != y.pos)
			return false;
		return (x.styleWord >> 1) < (y.styleWord >> 1);
	}
	// FUN_0096bb04(24B)@0031:40352 同位判:pos 相等 && 低 30 位
	//   styleWord 全同(flag 位不计)— 真身化
	static bool pos_eq_bb04(const RunNode &x, const RunNode &y)
	{
		if (x.pos != y.pos)
			return false;
		return ((x.styleWord ^ y.styleWord) & 0xfffffffeu) == 0;
	}
	// FUN_0096bca4(162B)@0031:40583 节点位置调整 — 真身化:
	//   cur < pos+len 时(pos < cur 或 (cur==pos && posNode.style
	//   ≤ node.style;语料 qstrdata_length_get 助记名 = runnode
	//   style 面字>>1,与 bb52 平局支同构)):len>0 → pos=pos+
	//   styleWord&1;delta>0 → pos+=delta;width=-1.0 恒置;
	//   cur ≥ pos+len → pos += delta−len(width 同置)
	static void pos_adjust_bca4(RunNode &n, const RunNode &p,
	                            qint64 delta, qint64 len)
	{
		const qint64 pos = p.pos;              // 0096bbc0(p)
		const qint64 cur = n.pos;
		if (cur < pos + len) {                 // 0096bcbx
			if (pos < cur
			    || (cur == pos && (p.styleWord >> 1)
			                             <= (n.styleWord >> 1))) {
				if (0 < len) {                 // 0096bcf8
					n.pos = pos;               // 0096bd02
					n.styleWord &= 1u;         // 留 flag 位
				}
				if (0 < delta)                 // 0096bd0c
					n.pos += delta;            // 0096bd12
				n.width = -1.0;                // 0096bd1c(位型)
				return;
			}
			return;                            // 内层未中 → 隐式尾
		}
		n.pos = cur + (delta - len);           // 0096bcc6 else 支
		n.width = -1.0;                        // 0096bccc
	}
	// FUN_0096c334(150B)@0031:41249 单 Span 平移 — 真身化:
	//   (span,posNode,delta,len);两节点按 bb52 定序为大小两侧
	//   (a=大侧,b=小侧);pos < 大侧(或 len==0 且 bb04 全等)→
	//   bca4(大侧);pos < 小侧 → bca4(小侧)
	static void span_shift_c334(Span56 &sp, const RunNode &posN,
	                            qint64 delta, qint64 len)
	{
		RunNode *a = &sp.n0;                   // lVar2 缺省
		RunNode *b = &sp.n1;                   // lVar3 缺省
		if (pos_gt_bb52(sp.n1, sp.n0)) {       // hi>lo → 换边
			a = &sp.n1;
			b = &sp.n0;
		}
		if (!pos_gt_bb52(*a, posN)) {          // pos ≥ 大侧:
			if (len != 0)                      //   len!=0 → 弃
				return;                        //   (0096c37c)
			if (!pos_eq_bb04(*a, posN))        //   全等才调整
				return;                        //   (0096c384)
		}
		pos_adjust_bca4(*a, posN, delta, len); // 0096c38c
		if (!pos_gt_bb52(*b, posN))            // 小侧 ≤pos → 弃
			return;                            //   (0096c3a0)
		pos_adjust_bca4(*b, posN, delta, len); // 0096c3a8
	}
	SelStoreX selStore;           // ed+0xfb8 store 行为模型(文档级生命
	                              //   周期,帧间持续;a28516 懒建置位)
	bool selStoreOn = false;      // ed+0xfb8 非 0 门(00a28516 懒建;
	                              //   replaceText 族未落地 → 恒 false)
	// Editor_vt8(00a1e8da,439B)@0033:56212 — selection 平移腿转写
	//   (D2:槽 +0x30=vt8,doc 层 FUN_00925c5e 观察者遍历发 vt+0x30;
	//   观察者挂接 — cited — wave-2)。调用点 = 文本修改入口:
	//   我方 dispatch 无写命令面(0x7553 buf_substr 只读)→
	//   **调用点待接线**(replaceText 族落地时挂)。
	void notifyTextChanged(qint64 pos, qint64 delLen, qint64 insLen)
	{
		// 三缓存平移腿 + 模式2节点腿(56229-56239)— cited — wave-2:
		//   FUN_00a16602(ed+0x10c8 游标缓存)/FUN_0095bb76(ed+0x10a0)/
		//   FUN_00a10ba2(*(ed+0x10e0)+8);*(char*)(ed+0x1067)=='\x02'
		//   → FUN_0096bca4(ed+0x1068)(宿主对象未建模)
		if (!selStoreOn)                 // *(ed+0xfb8)==0 → 整段跳过,
			return;                      //   不懒建(56240;空转零成本同相)
		// 语料 00a1ea7f runstyles_runnode_init(pos,0,0);c334 参序
		//   (span,node,[2],[3])= (delta,len):[2]=insLen 平移量/
		//   [3]=delLen 吞区间长(a16602 cur+=a2−a3 同参互证)
		const RunNode posN = RunNode::make(pos, 0, false);
		// anchor 腿(56241-56253):FUN_0096beb4 有效 → c334
		if (selStore.anchor.n0.isValid()   // FUN_0096beb4@0031:40707
		    && selStore.anchor.n1.isValid())   //   两节点均有效门
			span_shift_c334(selStore.anchor, posN, insLen, delLen);
		// extras 五控制字步进(56254-56277 deque 遍历)≡ QVector
		//   线性迭代(承载等价替,怪癖登记)
		for (Span56 &sp : selStore.extras)
			span_shift_c334(sp, posN, insLen, delLen);  // 00a1e9xx
	}

	// --- 标记注册表(+0x1098+0x100 sortedvec;+0xc0 游标族同型)—
	// 键=位置保序去重;原版为自旋锁槽阵(FUN_009a088e),行为模型
	// 用有序表,单线程等价
	// markers 读侧真身(批 67a;与下行行为模型并存,构建者批后接管门)
	wt::MarkersStore markersStore;
	// E 对象面(批 69 勘正:原误挂 MarkersStore;E=doc+0xc0 宿主态)
	quint32 eStopCount = 0;            // E+0x128(0x754d 停机计数;92596c
	                                   //   kind∈[5,8] 兼作 task serial — 同槽
	                                   //   两用怪癖,批 136 原样登记)
	int eSerialA = 0;                  // E+0x124(92596c kind∈[1,4] 取号)
	QMap<int, void *> eNodes;          // E+0x2d8(0x754d 遍历;键型勘正批 136:
	                                   //   语料 key = char kind — 92b56e
	                                   //   `*(char*)(node+0x18)=a1` / 92586c
	                                   //   `a1<=*(char*)(node+0x18)` 实读;
	                                   //   QMap<int> 保序同构;值 = wt::ENodeTask*)
	QList<QByteArray> eSerialEntries;  // E+0x250(0x7545 序列化导出 append)
	QString eName;                     // E+0x2b8
	// 双线程池(批 136 拆单槽 ePool;engine ctor 0092a08e..0092a0ee
	//   @0030.c:26039-26071:operator_new(0x10)+QThreadPool(0)+
	//   setMaxThreadCount(idealThreadCount) ×2)—— QThreadPool 真库
	//   委托(外库边界惯例,批 111 同面)。
	QThreadPool *ePoolA = nullptr;     // E+0x110 池 A(kind∈[1,4] 任务)
	QThreadPool *ePoolB = nullptr;     // E+0x118 池 B(kind∈[5,8] 任务)
	EditorContext()
	{
		superBufferAttached = true;              // 00929fe1 置真载体
		MatchEngine::attachScanCarrier(&docBytes);
		// 池 A/B 构造(0092a08e/0092a0ea 双腿字面)
		ePoolA = new QThreadPool;                // 0092a08e
		ePoolA->setMaxThreadCount(QThread::idealThreadCount()); // 0092a0d3
		ePoolB = new QThreadPool;                // 0092a0ea
		ePoolB->setMaxThreadCount(QThread::idealThreadCount()); // 0092a122
	}
	~EditorContext()
	{
		// eNodes 销毁链(批 136;engine dtor FUN_0092f62e @0030.c:
		//   29809 全读:92e512 全停 → 树遍历逐值 `**(vptr+8)()` 虚 D1
		//   → freeTree/freeData —— 无独立 delete 权,节点生存期 ⊂ E;
		//   C++ QMap 值析构 + delete 同构)
		for (auto it = eNodes.begin(); it != eNodes.end(); ++it) {
			// 语料 `(**(vptr+8))()` = 单独析构(Itanium D1 非 deleting)
			delete reinterpret_cast<wt::ENodeTask *>(it.value());
		}
		eNodes.clear();
		// 池析构(0092f62e 尾:vt+0x20 虚调 = QThreadPool dtor)
		if (ePoolA) ePoolA->waitForDone();       // 92e44e waitForDone 同面收尾
		if (ePoolB) ePoolB->waitForDone();
		delete ePoolA;
		delete ePoolB;
		MatchEngine::detachScanCarrier();        // 0092f852 拆链置 null
		superBufferAttached = false;
	}
	// —— eNodes 树面(批 136 W1;载体 = eNodes QMap 保序坍缩,939f06
	//   detach ≈ QMap 写时分离 → 我方直写同相)——
	// FUN_0092586c(69B)@0030.c:20824:树找首 key≥kind → 值(kind!=8 门;
	//   QMap lowerBound 保序同构)
	void *eNodeFind(int kind)
	{
		auto it = eNodes.lowerBound(kind);
		return (it != eNodes.end() && it.key() == kind) ? it.value() : nullptr;
	}
	// FUN_009258b2(185B)@0030.c:20859:kind 查找 + ScanTask 下行。
	//   kind==8:mode∈[9,11] 线性遍历 9635d0(+0xc==mode)匹配现存
	//   kind-8 节点(QMapNodeBase::nextNode ≡ QMap 迭代);否则走 92586c。
	//   命中 → dynamic_cast(4b0→588)≡ static_cast<ENodeScan*>。
	wt::ENodeScan *eNodeFindScan(int kind, int mode)
	{
		if (kind == 8 && quint32(mode - 9) > 2) {  // (2 < mode-9) 语料门
			wt::ENodeScan *hit = nullptr;
			for (auto it = eNodes.find(8); it != eNodes.end() && it.key() == 8; ++it) {
				auto *t = static_cast<wt::ENodeTask *>(it.value());
				if (t->gate009635d0(mode)) {
					hit = static_cast<wt::ENodeScan *>(t);  // __dynamic_cast 4b0→588
					break;
				}
			}
			return hit;
		}
		void *v = eNodeFind(kind);
		return v ? static_cast<wt::ENodeScan *>(static_cast<wt::ENodeTask *>(v)) : nullptr;
	}
	// FUN_0092b56e(306B)@0030.c:27031:懒工厂(唯一构造点)。
	//   kind≠8:92586c 命中复用;kind∈[1,4] → new 0x30 DocumentTask;
	//   否则 0xb0 ScanTask(96f606)。kind==8:mode∈[9,11] 先 9258b2
	//   现存复用,否则 ScanTask(8)+9637b8(mode)。命中插树。
	void *eNodeGet(int kind, int mode)
	{
		if (kind != 8) {
			if (void *v = eNodeFind(kind))
				return v;
			if (quint8(kind - 1) < 4) {          // (byte)(k-1)<4 → 0x30 族
				wt::ENodeTask *t = new wt::ENodeTask();
				t->ctor00963590(quint8(kind), quint64(reinterpret_cast<uintptr_t>(this)));
				eNodes.insert(kind, t);
				return t;
			}
		} else if (quint32(mode - 9) <= 2) {     // mode∈[9,11] 复用腿
			if (void *v = eNodeFindScan(8, mode))
				return v;
		}
		wt::ENodeScan *t = new wt::ENodeScan();
		t->ctor0096f606(quint8(kind));
		t->p18 = quint64(reinterpret_cast<uintptr_t>(this)); // 92b56e ctor 参 = E
		if (kind == 8)
			t->mode009637b8(mode);               // ⚠ 语料仅 kind==8 尾调
		eNodes.insert(kind, t);
		return t;
	}
	// FUN_0092e524(196B)@0030.c:29190:同 kind 全清(9635d0 匹配 →
	//   虚槽 +8 D1 ≡ delete + 939f20 摘树 ≡ erase)
	void eNodeClearKind(int kind, int mode)
	{
		auto it = eNodes.begin();
		while (it != eNodes.end()) {
			auto *t = static_cast<wt::ENodeTask *>(it.value());
			if (t->kind == kind && t->gate009635d0(mode)) {
				delete t;                        // vt+8 D1(非 deleting)
				it = eNodes.erase(it);
			} else {
				++it;
			}
		}
	}
	// FUN_0092e5e8(280B)@0030.c:29237:kind 应用(0x7581 false 腿/
	//   00a28316 承接)。rec=null 腿:现存 → 9264ba+926356(0x3f0
	//   组播,批 138 真身)+9263fa(经 9264ba)+92e524;rec≠null:
	//   查/建 → 96d022(rec 属性比对 — a837f6 cited,ENODES-RECON
	//   未解 #1 → rec!=null 恒 false 续行同相壳)→ 现存停广播+
	//   96fb1e 清偿 → 96f80a 插 → 96d620 → 92596c。
	void eNodeApplyScan(int kind, const void *rec, qint64 rs, qint64 re)
	{
		wt::ENodeScan *t = eNodeFindScan(kind, 0);
		if (rec == nullptr) {
			if (t != nullptr) {
				eNodeStopOne(t);                 // 9264ba
				eNodeEmit0x3f0(                  // 926356(cmd 0x3f0,批 138 真身;
				    quint64(rs), quint64(re));   //   载荷 p3=rs/p4=re 调面字面)
				eNodeClearKind(kind, 0);         // 92e524
			}
			return;
		}
		if (t == nullptr) {
			t = static_cast<wt::ENodeScan *>(eNodeGet(kind, 0));  // 92b56e
			if (t == nullptr)
				return;
		} else {
			eNodeStopOne(t);                     // 9264ba
			t->runClear0096fb1e();               // 96fb1e 旧 run 清偿
		}
		// 96d022(rec 属性比对;rec!=null → 恒不早返同相壳)→ 96f80a
		t->runInsert0096f80a(rec, -1);
		t->dirtyClamp0096d620(rs, re);           // 96d620
		eNodeDispatch(t);                        // 92596c
	}
	// FUN_0092601a(46B)@0030.c:21386:emit 底座 — E+0x70..+0x78
	//   监听者 QList 遍历,逐项 `(**(obj vptr+0x38))(obj, evs)`。
	//   监听者挂接面(ENODES-RECON 未解 #2)未建模 → 空表零迭代
	//   同相;事件载荷销毁面 924f02(35B@19894:槽 ref 双降)—
	//   本批登记,eNodeEmitKind/0x3f0 直调此空底座。
	void eNodeEmitDispatch()
	{
		// E+0x70 监听者表未建模(未解 #2)→ 零迭代同相
	}	// FUN_00926356(140B)@0030.c:21542:cmd 0x3f0 组播(SciSchemeChange
	//   事件 0x38:new(1,1,vt=935bf3)+FUN_00a1c7cc(ev,0x3f0,p3,p4)+
	//   vt→935d9d + 92601a + 尾 924f02)— 批 138 真身(cmd 字面 +
	//   底座接线;监听者空表 → 零投递同相)。
	void eNodeEmit0x3f0(quint64 a3, quint64 a4)
	{
		Q_UNUSED(a3); Q_UNUSED(a4);   // 事件载荷(+0x18=p4/+0x20=p3)
		eNodeEmitDispatch();          // 92601a 底座
	}
	// FUN_009263fa(168B)@0030.c:21570:kind∈[5,7] 组播 — cmd 门字面:
	//   6 → 0x3f9;否则 0x3f8 + (kind==7)*2(语料 `(c=='\a')+0x3f8+
	//   (uint)(c=='\a')`);SciHighlight 事件 0x28(00a1c584)+ 92601a
	//   + 924f02 — 批 138 真身。
	void eNodeEmitKind(qint8 kind)
	{
		if (quint8(kind - 5) >= 3)    // (byte)(param_2-5)<3 门
			return;
		const int cmd = (kind == 6)
		    ? 0x3f9
		    : 0x3f8 + 2 * int(kind == 7);   // 0x3f8+(c==7)+(c==7) 字面
		Q_UNUSED(cmd);                // SciHighlight ev — 底座同上
		eNodeEmitDispatch();
	}
	// FUN_009264ba(81B)@0030.c:21608:停广播(非零 stopped 跳 →
	//   ScanTask → 9263fa kind∈[5,7] emit → 9637ea 停机)。
	//   组播腿 9263fa 批 138 真身化(底座 92601a 零监听同相)。
	void eNodeStopOne(void *v)
	{
		if (v == nullptr || static_cast<wt::ENodeTask *>(v)->stopped != 0)
			return;
		auto *t = static_cast<wt::ENodeTask *>(v);
		auto *scan = dynamic_cast<wt::ENodeScan *>(t);   // __dynamic_cast 4b0→588
		if (scan != nullptr)
			eNodeEmitKind(scan->kind);       // 9263fa(kind 字面门内组播)
		t->stop009637ea();
	}
	// FUN_0092e44e(195B)@0030.c:29141:0x754d 全停(++E+0x128;
	//   池 B clear + waitForDone;kind∈[5,8] 逐节点 9264ba)
	void eNodeStopAll()
	{
		++eStopCount;                            // LOCK 面 ≡ 单线程 ++
		ePoolB->clear();                         // QThreadPool::clear
		for (auto it = eNodes.begin(); it != eNodes.end(); ++it) {
			auto *t = static_cast<wt::ENodeTask *>(it.value());
			if (t && quint8(t->kind - 5) < 4)
				eNodeStopOne(t);
		}
		ePoolB->waitForDone();
	}
	// FUN_0092e368(211B)@0030.c:29089:0x754e 遍历复位(dynamic_cast →
	//   9635d8 → 96cef2 → 92596c)
	void eNodeResetDirty()
	{
		for (auto it = eNodes.begin(); it != eNodes.end(); ++it) {
			auto *t = dynamic_cast<wt::ENodeScan *>(
			    static_cast<wt::ENodeTask *>(it.value()));
			if (t == nullptr || !t->gate009635d8())
				continue;
			t->dirtyReset0096cef2();
			eNodeDispatch(t);                    // 92596c
		}
	}
	// FUN_0092596c(215B)@0030.c:20898:重排分发。9637da 门 →
	//   kind∈[1,4]:Runner(serial=E+0x124++)→ 池 A;kind∈[5,8]:
	//   ScanTask 96d094 非空门 + serial=E+0x128 → 池 B。
	void eNodeDispatch(wt::ENodeTask *t)
	{
		if (t == nullptr)
			return;
		if (!t->dispGate009637da())
			return;
		if (quint8(t->kind - 1) < 4) {
			const int serial = eSerialA++;       // *(E+0x124)++(uVar1 旧值入 Runner;
			                                     //   语料 uVar1 = ++ 前读 — 原样)
			ePoolA->start(new wt::ENodeRunner(this, t, serial));
		} else if (quint8(t->kind - 5) < 4) {
			auto *scan = dynamic_cast<wt::ENodeScan *>(t);
			if (scan != nullptr && scan->runsNonEmpty0096d094())
				ePoolB->start(new wt::ENodeRunner(this, t, int(eStopCount)));
		}
	}
	// --- lexer/scanner 面(批 markers 翻真①②③;buffer+0x108)---
	void *bufferLexer = nullptr;       // buffer+0x108 原始槽(lexer/scanner obj;工厂
	                                   //   FUN_00930f9e 短路链 *(*(E+0x258)+0x108) 平铺;
	                                   //   生产者 FUN_009de20a→00a1092a — cited 装载链)
	wt::ScannerX *scanner = nullptr;   // scanner ctor 产出(0x70,②);与 bufferLexer 同指
	                                   //   一物 — 装载接线批两槽同写(批 85 同值双槽先例)
	// slot10 承载镜像(批 90 接线批;E=doc ⇒ session+0xa0 平铺):0x48 doc-scan
	//   伴随对象(FUN_009f98a2 103B 0033.c:27347 产出 — ctor cited;建/拆 =
	//   FUN_0092f0f6 0030.c:29676-29686 + 0092ef06 0030.c:29572-29578)。
	//   与 scanner(buffer+0x108,E4' 定性)两轨独立:此对象供 editor_initDoc
	//   param_3(D+0x10 slot10;唯一写入点 0032.c:36931;驱动 0030.c:29770)。
	//   壳期 nullptr → markersStore.slot10 恒 0,行面 ×3 门关(同相)。
	void *docScan48 = nullptr;         // *(session+0xa0) — 接线批经 markersStore.setSlot10 注入
	// FUN_00930f9e(26B)@0030:30982 真身化(①):editor_line_at(E,0) param_2==0
	//   短路门 → *(E+0x258)=curBuffer → 非空取 *(buf+0x108)。我方 bufferLexer 即
	//   平铺值,短路门同相(buffer 未挂 → 0)。
	void *lexerSnap() const { return bufferLexer; }
	// FUN_0099d4de(1407B)region 扫描驱动入口(E 面承接:lex = bufferLexer,③)
	quint8 regionScan(quint32 lexerMode, qint64 from, qint64 to)
	{ return markersStore.regionScan(lexerMode, from, to, bufferLexer); }
	// slot10 接线面(批 90):editor_initDoc 驱动批把 *(session+0xa0)(docScan48)
	//   写入 D+0x10 — 我方 E 平铺经此镜像;0x7543 markersCtxInit 后同位点调用
	//   (对位 0030.c:29770 param_3 传递)。壳期 docScan48==nullptr → slot10=0 门关。
	void wireSlot10()
	{ markersStore.setSlot10(docScan48); }
	QHash<QString, QColor> styleTable; // 样式表占位(0x7547 S3;+0xe00 面未建模)
	// M 修改行跟踪器(doc+0xf0;批 104 建模;ModTrack.h 生命周期头注)
	//   ctor = editor_engineCtor 00929fab..00929fe1;析构 = a362(0030.c:29905);
	//   flat 模式(游程腿 = 写侧 run 迁移,单列批)→ markerBand 走线性支同相。
	wt::ModTrack modTrack;
	// ctx+0x28 行槽(editor_engineCtor 25911 param_1[0x28]=0x7fff…f =
	//   INT64_MAX;消费点 958108 @0031.c:25693/25699 min 收敛负向)
	qint64 modLineSlot28 = std::numeric_limits<qint64>::max();
	// char-used 视图(*(ctx+0x180);批 75 勘察 + 批 115 定型:FUN_0095c086
	//   292B @0031:28685 全读 — 0x20{vtbl→Uint8RunStyles_vtable,+0x08
	//   pieceTable 0x60(piecetable_init,+0x18 threadCtx = 0092801a(doc)
	//   种子),+0x10 GapBuffer 0x30(GapBuffer_dtor 后 gapbuffer_reallocate
	//   (0,0,2) 重开)};pieceTable/GapBuffer/threadCtx 外库边界面 → 我方
	//   RS8 委托坍缩(路线 A 惯例,rsFill8 同面);ensure 重建腿 0x95c19d
	//   vt+0x08(D1 链)旧象释放 ≡ delete;ret 1=吸收/0=新写 与 changed
	//   不同相 = QUIRKS 候选,76c 笔记)
	Scintilla::RunStyles<int, char> *charUsedView = nullptr;
	// runvector(批 82 勘察:ctx+0x178 = 0x28{count,docState,begin,end,cap}
	//   ≡ std::vector<ValueTable*>;run 元素 = wt::ValueTable 0x40 复用)
	QVector<wt::ValueTable *> runVector;
	void *runSeed = nullptr;                        // rv[1] = FUN_0092801a(doc) 种子
	QVector<quint32> styleProps190;                 // ctx+0x190 Uint32Bimap→QList(第六视图,76b 漏列补)
	// p4==2 去重腿(批 115 收口;0031.c:28844-28864 全读):语料 = FUN_00926ddc
	//   (*(ctx+8),rs,re,props&0x3fff,&pts) + pts 5-long 步进线性查。
	//   *(ctx+8) = 标记引擎对象(doc+0xb8;0092bb20 槽面 0x90..0x200 同构;+0xb8 busy
	//   位)→ busy 腿(真身 FUN_009e975a 539B @0033.c:15148:
	//   009e83ea 分页标记扫描,素 {nextStart,nextEnd,start,end,props} 经
	//   009ef31a 追加)整体 cited — wave-2(铁律 3 缺证不转写);pts = 调用局
	//   临时两点向量(0095c4fd 三连 0 初始化)非 ctx 持久。壳态 busy 恒 0 →
	//   非 busy 腿 = pts 对回卷(FUN_00926ddc L22329-22331:pts[1] = pts[0];
	//   空对恒等 no-op)→ 查腿扫 0 素恒无命中(同相直落界交判定)
	//   批 117 裁决(照批 111 判例,边界登记收口):busy 腿不可脱离外库转写。
	//   ①构造链:0092bb20(599B @0030.c:27236)= doc 批处理通知器,唯一调用点
	//     0092bd78(32B @27330,待发缓冲 +0x1b8 合并机,12 处 doc 写路径调用)→
	//     与 doc 生命周期锁死,非独立可构造;00926ddc 调点 (ctx+8) = doc+0xb8
	//     标记引擎槽(kuna xrefs:0092bb20 仅 0x92bd93 一跳)。
	//   ②承载链:busy 位面读 FUN_009e7bce→FUN_00a0ce84(232B @0033.c:40874)=
	//     LOCK 自旋 + nanosleep 指数退避线程锁(批 111 piecetable/线程缓存同族
	//     — QThreadPool 形态,改版底座头不在库,缺证不转写)。
	//   ③扫描索引面:009e83ea=**(*(mark)+0x20) 分页表 / 009e844a→vt+0x30
	//     skipruns 分页数 / 009e8942 边界游程走查(u16 bit14-15 方向)— 皆分页
	//     级 vt 调用,承载= 009e9ad8 写侧同源;坍缩建模破坏读路 invariants。
	//   壳态维持:busy 恒 0 → 非 busy 回卷腿,dedupProbePts 空对同相。
	struct DedupRec { qint64 nextStart; qint64 nextEnd; qint64 start; qint64 end; qint64 props; };
	// 查腿真身(L28849-28864;busy 腿激活后同函数承载):自 pts+0x10(素 0
	//   槽 2)起 ÷5 步进,素槽 2/3 ==(rs,re) 命中 → 跳此 run(L28864 goto)
	static bool dedupProbePts(const QVector<DedupRec> &pts, qint64 rs, qint64 re)
	{
		for (int k = 0; k < pts.size(); ++k)
			if (pts.at(k).start == rs && pts.at(k).end == re)
				return true;
		return false;
	}
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
	bool indentGuidesD44 = false;      // doc+0xd44 缩进参考线开(批 80;
	                                   //   FUN_00a68b18 门,写侧未落 → 缺省关,同相)
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
	QVariantList docObjList;           // doc+0x108 QList 面(0x75c9 读/
	                                   //   0x75ca 空检/0x75cb·0x75cc 置;
	                                   //   0092fb40 全等 no-op 同构 — 批 126)
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
	// —— 批 127:+0xf8 buffer 载体 RAII ——
	// ctor(= editor_engineCtor 尾段:00929fdd..00929fe1 建 buffer32,
	//   槽即非空)→ 挂线;dtor(= FUN_0092f852 doc 拆链)→ 拆线。
	//   scanLineDoc() = engDispatch param_1 承接(attached → &docBytes)。
	//   (批 136:池构造/eNodes 销毁链已并入上方 ctor/dtor)
};

#endif // EDITORCONTEXT_H
