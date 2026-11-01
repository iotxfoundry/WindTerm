#ifndef CODECMEMO_H
#define CODECMEMO_H

#include <QtCore/qbasicatomic.h>
#include <QByteArray>
#include <QHash>
#include <QString>
#include <QtGlobal>

class QTextCodec;

// ReplaceOp codec 缓存面(批 91 p3;批 89 定性:op 体即 codec 缓存体)。
// 语料 op 体段:+0x08 自旋锁 / +0x0c flags / +0x18 codec(+4 int 门)/
// +0x48 FUN_0089ab22 重编码缓存 / +0x58 FUN_0089a0a0 旧编码 Grep 针缓存 /
// +0x60 codec_canEncode 缓存(三面均 QHash<QString→产物>)。
// 宿主桥 op 对象不承载我方缓存 → 本类局部承载(EditorEngine.cpp 文件级
// static,批 81 s_grep_reg_1a60 先例;语料 op 级生命期 → 进程级,单会话
// 单线程同相 — 登记承载替)。

// 0x20 转换控制体(FUN_008997ec,249B @decomp-0027.c:52015 全读):
//   +0x00 flag(四单字节 codec → 1)/ +0x08 键串 d 指针(值语义承载并入
//   QHash 键)/ +0x10 编码产物 QByteArray / +0x18 QListData 槽(消费面
//   未解 — cited — wave-2)。FUN_00899316 消费 +0x10 的 d->size。
struct CodecCtl20
{
	quint8 flag = 0;          // +0x00
	QByteArray encoded;       // +0x10(FUN_00899316 读 *(x+0x10)+4 = size)
};

// 0x448 Grep 针对象(FUN_0089a0a0 operator_new(0x448)@0089a2e9;头 0x10 =
//   {vtable PTR_Grep_dtor_deleting_01192460, refs{1,1}};codec_convCtor
//   (0089c450)载体 @obj+0x10 —— 下列偏移按 conv 基):
struct GrepNeedle448
{
	quint8 literal = 1;        // conv+0x00(convCtor 置 1;canOld 门读位:
	                           //   0089a756 返回 *data^1)
	quint8 caseFlag = 0;       // conv+0x01(=op flags bit1;0092a596 引擎
	                           //   分派门读位)
	QByteArray bytes;          // conv+0x08 针字节 QByteArray(param_3,param_4)
	int len = 0;               // conv+0x10 针长(0092a596 读 +0x10)
	int skip[256] = {};        // conv+0x14..0x413 跳表:默认 len+1 逐项填
	                           //   (convCtor do-while);case 档逐字符覆写
	                           //   len-offset(Boyer-Moore 面)
	quint64 allowedBits = 0;   // conv+0x418 允许命中位图(u64;0092a596 候选
	                           //   & allowed==0 才收)。convCtor 四单字节
	                           //   codec 面(0066bc12/bcd2/bd92/be52)置
	                           //   1/3;其余填充方未解 — cited — wave-2
	void *simdBlocks = nullptr; // conv+0x420 16B/字符 SIMD 块(posix_memalign
	                            //   len<<4,字节×8 广播;case 档)— cited
};

class CodecMemo
{
public:
	CodecMemo() { lock.storeRelease(0); }

	// —— op 体布局对位 ——
	QBasicAtomicInt lock;         // +0x08 自旋锁(byte test-and-set;退避
	                              //   序列见 CodecMemo.cpp LockGuard)
	quint32 flags = 0;            // +0x0c(bit0/1/2:008997d6/008997bc 读面)
	QTextCodec *codec = nullptr;  // +0x18(+4 int 门:concrete codec 布局面
	                              //   — cited;非空承载)
	QHash<QString, CodecCtl20 *> reencCache;      // +0x48(0089ab22 3300B cited)
	QHash<QString, GrepNeedle448 *> needleCache;  // +0x58(0089a0a0)
	QHash<QString, CodecCtl20 *> encCache;        // +0x60(0089b85e cited)

	// FUN_0089a756(179B)@decomp-0027.c:52888 真身:canOld 门。
	//   op+0xc & 5 == 0 → +0x58 针缓存查(grepNeedle);针 null→真,
	//   否则 !针 literal 字节;门不中 → 真。
	bool canOld(const QString &findStr);

	// FUN_0089a0a0(1680B)@decomp-0027.c:52578 骨架:+0x58 缓存查/插
	//   真身(锁+查+插;canEncode 败/门不中也插 null,0089a262 门同插);
	//   产腿 = operator_new(0x448)+codec_convCtor(2543B)— cited —
	//   wave-2(→ null 承载,占位同相)
	GrepNeedle448 *grepNeedle(const QString &findStr);

	// codec_canEncode(0089b85e,2047B)@decomp-0027.c:53596 声明层:
	//   +0x60 缓存查/插 + QTextCodec::canEncode + 编码器 vt+0x20
	//   toLocal8Bit 形态 + ConverterState 栈对象 + FUN_00a8450a→
	//   00a84376(276B pthread 互斥 utx 工厂)Uint32Bimap 0x20 ctl
	//   包装(00a84492)— 体 cited — wave-2
	CodecCtl20 *canEncodeMemo(const QString &s);

	// FUN_00899316(8B)@decomp-0027.c:51741 真身:编码结果字节长
	//   accessor(*(int*)(*(x+0x10)+4);语料无空判 — 调用方保非空)
	static int encodedLen(const CodecCtl20 *ctl);

	// —— 搜索腿(0x4eff 段 E 接线;批 91 要点 3/4)——
	// FUN_0092547e(95B)@0030:20440 真身骨架:复位 searcher(doc+0x88)
	//   → state=2 → FUN_00a8395c thunk 门;00b422d0(2750B 缓冲扫描
	//   引擎)— cited — wave-2(恒未命中 → -1,占位同相)
	static qint64 searchNeedle(const void *needlePair, qint64 from, qint64 to);
	// FUN_0092a596(467B)@0030:26261 骨架:四引擎分派 + pack64 掩码
	//   过滤式真身(引擎四腿 + +0x418 填充方 — cited — wave-2)
	static qint64 scanMask(const void *needlePair, qint64 from, qint64 to);
};

#endif // CODECMEMO_H
