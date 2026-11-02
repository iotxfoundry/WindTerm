#include "CodecMemo.h"

#include <QTextCodec>
#include <QTextEncoder>

#include <errno.h>
#include <sched.h>
#include <time.h>

// 批 91 p3:codec memo 面 + 搜索腿。逐函数出处见注释(铁律 1)。

// doc+0x88 searcher 状态面行为模型(FUN_0092547e 复位/置位消费;
//   全槽默认 00a833e8(64B)/00a835c4(31B)两复位体的 +0x10..+0xb8
//   段由引擎消费 — 引擎腿 cited,仅承载 +0xb8 状态机字节)。
namespace {
struct SearcherModel
{
	int state = 0;                 // +0xb8 ∈ {0 未启,1 行内,2 结果表}
	void reset()
	{                              // FUN_00a83622(35B)@0035:186:
		state = 0;                 //   +0xb8=0(直读)
		// FUN_00a835c4(+0x80 区):+0x98/+0xa0=0、+0xa8=0x2000000000;
		//   FUN_00a834a8→00a833e8(+0x28 区):+0x30/+0x40/+0x48=-1、
		//   +0x38 u16=0x101、+0x18=0x7fffffffffffffff — 引擎消费面
		//   — cited — wave-2(值语义重置零操作同相)
	}
};
SearcherModel s_searcher;          // doc+0x88 承载替(文件级 static;登记)

// 自旋锁获取(FUN_0089a0a0 LAB_0089a0e4 / 0089b85e LAB_0089b8a7 /
//   0089ab22 LAB_0089ab4d 同款):byte test-and-set;前 2 次纯自旋,
//   3-15 次 sched_yield;>15 次 nanosleep({0,100}×16 后 {0,10000},
//   EINTR 重试)— 语料 code_r0x0089a102。
class LockGuard
{
public:
	explicit LockGuard(QBasicAtomicInt &lk) : m_lk(lk)
	{
		for (int tries = 0; !m_lk.testAndSetOrdered(0, 1); ++tries) {
			if (tries < 2)
				continue;                        // 0089a118 纯自旋档
			if (tries > 15) {
				timespec ts = {0, 10000};        // 0089a103 末档 10µs
				while (nanosleep(&ts, &ts) == -1
				       && errno == EINTR)        // 0089a11x EINTR 环
					;
				continue;
			}
			sched_yield();                       // 0089a12x 中档
		}
	}
	~LockGuard() { m_lk.storeRelease(0); }       // 0089a1f1 *(op+8)=0
private:
	QBasicAtomicInt &m_lk;
};
} // namespace

// FUN_0089a756(179B)@decomp-0027.c:52888 — canOld 门真身。
//   语料:op+0xc&5==0 → FUN_0089a0a0(&pair,op,findStr);pair 空 → 1;
//   否则 *(byte*)pair ^ 1(pair[0] = 针 conv+0x00 literal 字节)。
//   释引用尾段(local_20 _M_release 双环)= 0x448 包裹 refcount 面,
//   我方缓存持有 → RAII 零操作(承载替,登记)。
bool CodecMemo::canOld(const QString &findStr)
{
	if ((flags & 5) == 0) {                       // 0089a766 门
		GrepNeedle448 *n = grepNeedle(findStr);   // 0089a778
		if (n == nullptr)
			return true;                          // 0089a78c bVar5=1
		return !(n->literal);                     // 0089a782 *local_28 ^ 1
	}
	return true;                                  // 0089a7a6 门不中
}

// FUN_0089a0a0(1680B)@decomp-0027.c:52578 — +0x58 Grep 针缓存骨架。
//   查/插真身(FUN_0089d29e 127B ≡ QHash::find,hash = 串 d 指针
//   u32 三段异或 — QString 键承载同构;canEncode 败/门不中也插 null,
//   0089a46x allocateNode 腿);产腿(0089a262 codec+4 门 →
//   QTextCodec::canEncode → 编码 vt 调 → operator_new(0x448) +
//   codec_convCtor @0089a2e9/0089a32b)— cited — wave-2。
GrepNeedle448 *CodecMemo::grepNeedle(const QString &findStr)
{
	LockGuard g(lock);                            // LAB_0089a0e4
	auto it = needleCache.find(findStr);          // 0089a232/0089a1e3 查
	if (it != needleCache.end())
		return it.value();                        // 0089a1f1 命中携出
	GrepNeedle448 *n = nullptr;
	if (codec != nullptr) {                       // 0089a262 *(op+0x18) 门
		                                          //   (+4 int 布局面 cited)
		if (codec->canEncode(findStr)) {          // 0089a268 QTextCodec 真委托
			const uint opFlags = flags;           // 52653 *(param_2+0xc)
			// 52650–52652 编码器 vt+0x20 vcall(ConverterState 栈对象同款
			//   面)→ 52654/52655 长度与字节 — cited — wave-2(vtable 面;
			//   fromUnicode(QString,0) 为标准 Qt 承载)
			const QByteArray enc = codec->fromUnicode(findStr);
			GrepNeedle448 *conv = new GrepNeedle448;  // 52657 new(0x448)
			convCtor(conv, codec, enc.constData(), enc.size(),
			    (opFlags >> 1) & 1);              // 52661 convCtor 产腿
			n = conv;
		}
	}
	needleCache.insert(findStr, n);               // 0089a49e 插腿(null 同插)
	return n;                                     // 0089a1f1 *(op+8)=0 出锁
}

// FUN_0066bc12/0066bcd2/0066bd92/0066be52(176B×4)@decomp-0020.c:54050/
//   54085/54120/54155 — 四单字节 codec 单例:cxa_guard 惰性静态,
//   codecForName("UTF-16BE"/"UTF-16LE"/"UTF-32BE"/"UTF-32LE")。convCtor
//   四面比较消费(54393–54417);QTextCodec 指针面直接比较同构。
static QTextCodec *utf16beCodec()
{                                                                  // 0066bc12
	static QTextCodec *c = QTextCodec::codecForName("UTF-16BE");   // 54067–54069
	return c;                                                      // 54079
}
static QTextCodec *utf16leCodec()
{                                                                  // 0066bcd2
	static QTextCodec *c = QTextCodec::codecForName("UTF-16LE");   // 54102–54104
	return c;                                                      // 54114
}
static QTextCodec *utf32beCodec()
{                                                                  // 0066bd92
	static QTextCodec *c = QTextCodec::codecForName("UTF-32BE");   // 54137–54139
	return c;                                                      // 54149
}
static QTextCodec *utf32leCodec()
{                                                                  // 0066be52
	static QTextCodec *c = QTextCodec::codecForName("UTF-32LE");   // 54172–54174
	return c;                                                      // 54184
}

// codec_convCtor(0089c450,2543B)@decomp-0027.c:54319 真身。
//   语料:conv+0x00=1、QByteArray(param_3,param_4)@conv+0x08(54351–
//   54352)、+0x418..+0x437 清零(54353–54384)、skip do-while 逐项
//   param_4+1(54385–54389)、+0x10=len、+0x01=param_5(54390–54391);
//   四单字节面 → allowedBits=1(54395)/3(54410),其余 0(ctor 清零);
//   case(param_5)档:+0x420 posix_memalign(0x10,len<<4)+ 逐字节
//   16B 广播 + skip 逐字符覆写(54420–54448);非 case 档 QTextEncoder
//   折叠编码面(54450–54600)→ 触发时 literal 翻转 + +0x428/+0x430
//   SIMD 块 + skip 对覆写(54603–54720)。析构尾段 = Qt RC 面。
//   cited 腿:QTextEncoder 折叠面(54450–54657,深>300B)与 SIMD
//   三块/skip 对覆写(54603–54720)。
void CodecMemo::convCtor(GrepNeedle448 *conv, QTextCodec *codec,
                         const char *bytes, int len, bool caseFlag)
{
	conv->literal = 1;                                        // 54351 *p1=1
	conv->bytes = QByteArray(bytes, len);                     // 54352 +0x08
	conv->allowedBits = 0;                                    // 54353–54360
	conv->simdBlocks = nullptr;                               // 54361–54368
	conv->lowerSimd = nullptr;                                // 54369–54376
	conv->upperSimd = nullptr;                                // 54377–54384
	for (int i = 0; i < 256; ++i)                             // 54385 do-while
		conv->skip[i] = len + 1;                              //   0x14..0x413
	conv->len = len;                                          // 54390 +0x10
	conv->caseFlag = caseFlag ? 1 : 0;                        // 54391 +0x01
	                                                          // 54393–54417:
	if (codec == utf16beCodec() || codec == utf16leCodec())   //   bc12 门
		conv->allowedBits = 1;                                // 54395 =1
	else if (codec == utf32beCodec() || codec == utf32leCodec())
		conv->allowedBits = 3;                                // 54410 =3
	if (conv->caseFlag != 0) {                                // 54420 cVar2 门
		void *blk = nullptr;                                  // 54421 posix_
		posix_memalign(&blk, 0x10, qint64(len) << 4);         //   memalign
		conv->simdBlocks = blk;                               // 54425 +0x420
		if (len >= 1) {                                       // 54426 门
			for (int i = 0; i < len; ++i) {                   // 54430 广播环
				const quint32 b32 = quint32(quint8(bytes[i])) * 0x01010101u;
				quint32 *dst = reinterpret_cast<quint32 *>(
				    static_cast<char *>(blk) + i * 0x10);     // 54433
				dst[0] = b32; dst[1] = b32;               // 54434–54437
				dst[2] = b32; dst[3] = b32;
			}
			for (int i = 0; i < len; ++i)                 // 54442–54447 skip
				conv->skip[quint8(bytes[i])] =            //   逐字符覆写
				    (len + 0) - i;                        //   54445 算式
		}
		return;                                               // 54448 提前出
	}
	// 54450–54600 QTextEncoder 折叠编码面 + 54603–54720 触发面
	// — cited — wave-2(深>300B 内层;carrier 零值同相:literal 保持 1、
	//   SIMD 块空、skip 表保持默认 — 占位同相)
	/* cited — wave-2 */
}

// codec_canEncode(0089b85e,2047B)@decomp-0027.c:53596 真身。
//   语料:返回 {ptr,rc 包装}(param_1 两槽);锁(LAB_0089b8a7);
//   +0x60 缓存查 FUN_0089d31e(53661);miss → codec+4 门(53664)
//   → QTextCodec::canEncode(53666)→ ConverterState 栈 {1,0}
//   (53672–53675)→ 编码器 vtable vt+0x20 vcall(53678)→ std::string
//   _S_construct(53682)→ 空 QByteArray 释放臂(53686–53695)→
//   FUN_00899740(param_4==0 键兜底,53668–53671)/ FUN_008997bc/
//   008997d6 flags 面(53697–53698)→ FUN_00a8450a(&local_78,…,
//   param_2+0x50 std::string 端)(53699)→ 旧产物 RC 释放 + 新产物
//   双槽携出(53700–53742)→ std::string 释放(53743–53752)→
//   ConverterState dtor(53753)→ +0x60 detach/insert(53757–53817)
//   → LAB_0089b9e4 解锁(53945)。命中臂:RC 增持携出(53852–53921)
//   + param_2+0x50 std::string 释放(53923–53943)。
//   cited 腿:编码器 vcall 内层(53678 vtable 面)与 FUN_00a8450a→
//   00a84376 utx 工厂内层(276B pthread 互斥 + FUN_00b3b090 换算)。
CodecCtl20 *CodecMemo::canEncodeMemo(const QString &s)
{
	CodecCtl20 *out = nullptr;                                // 53644 *p1=0
	LockGuard g(lock);                                        // LAB_0089b8a7
	auto it = encCache.find(s);                               // 53661 查
	if (it != encCache.end()) {                               // 53663 命中臂
		out = it.value();                                     // 53885–53896 RC
		return out;                                           //   增持携出(共
		                                                      //   享指针承载替)
	}
	if (codec != nullptr) {                                   // 53664 codec+4 门
		                                                      //   (+4 int 布局面
		                                                      //   cited)
		if (codec->canEncode(s)) {                            // 53666 真委托
			// param_4(53668–53671)= 调用方键 codec 兜底(FUN_00899740
			//   codecForName 面)— 本桥无独立键参数 → param_4==0 恒相,
			//   兜底腿 — cited — wave-2
			// 53672 ConverterState 栈对象 {1,0}(53672–53675)+ 53678
			//   编码器 vt+0x20 vcall → 53682 std::string 承载 — cited —
			//   wave-2(vtable 面;标准 Qt 承载面已备:codec->fromUnicode)
			// 53699 FUN_00a8450a(&local_78,&local_80,uVar6,local_98,
			//   uVar9,param_2+0x50):std::string 端 utx 工厂 →
			//   FUN_00a84492 operator_new(0x20) Uint32Bimap 包装 —
			//   cited — wave-2(pthread 互斥 utx 换算内层;CodecCtl20
			//   flag/QByteArray 载体同相)
			out = nullptr;  /* cited — wave-2 */
		}
		encCache.insert(s, out);                              // 53778–53817 插
	}
	return out;                                               // LAB_0089b9e4
}

// FUN_00899316(8B)@decomp-0027.c:51741 — 编码结果字节长 accessor 真身。
//   语料:*(int*)(*(param_1+0x10)+4)= ctl +0x10 QByteArray 的 d->size。
int CodecMemo::encodedLen(const CodecCtl20 *ctl)
{
	return ctl->encoded.size();
}

// 四引擎分派(FUN_0092a596 内 2627x/262ex 两处同构):caseFlag==0 →
//   literal 引擎(针长 <0xc:009376d1 3132B / ≥0xc:0093830d 3159B);
//   caseFlag!=0 → SIMD 引擎(<0xc:0093632d 2500B,vt+0x50 逐 16B 取块
//   首字比较,针存 conv+0x420 / ≥0xc:00936cf1 2528B,带 doc+0xf8 行
//   感知)— 四腿 2500-3160B 均未解 — cited — wave-2。
//   占位 = pack64 哨兵(hi16=0xffff/lo48 全 1;调用方哨兵门同相)。
static quint64 scanEngine(const GrepNeedle448 *needle, qint64 from, qint64 to)
{
	Q_UNUSED(needle);
	Q_UNUSED(from);
	Q_UNUSED(to);
	return quint64(-1);  /* cited — wave-2 */
}

// FUN_0092547e(95B)@0030:20440 — 搜索腿 wrapper 真身(骨架+置位)。
//   语料:FUN_00a83622(*(doc+0x88));*(searcher+0xb8)=2;
//   FUN_00a8395c(searcher,param_4,0,param_5,param_2,param_3,0)。
//   thunk 链:00a8395c(42B)→00a83946(21B:needle[0]!=0 门,门不中
//   返 -1)→00b42e10(28B)→00b422d0(2750B 缓冲扫描引擎,flags 0x800
//   门/+0x74+0x78 buffer 字段)— 引擎腿 cited — wave-2。
qint64 CodecMemo::searchNeedle(const void *needlePair, qint64 from, qint64 to)
{
	s_searcher.reset();                           // 20440 FUN_00a83622
	s_searcher.state = 2;                         // 2045c *(+0xb8)=2
	if (needlePair == nullptr
	    || *(void *const *)needlePair == nullptr) // 00a83946 *param_2 门
		return -1;
	// 00b422d0(2750B)缓冲扫描引擎 — cited — wave-2(恒未命中 → -1)
	Q_UNUSED(from);
	Q_UNUSED(to);
	return -1;  /* cited — wave-2 */
}

// FUN_0092a596(467B)@0030:26261 — 掩码位置扫描器骨架。
//   param_4 → 针对象(长 +0x10,literal/case 门 +0x00/+0x01,允许命中
//   位图 +0x418 u64);pack64 返回:hi16 = 候选掩码,lo48 = 位置;
//   逐位过滤(候选 & allowed==0 才收,弃位换下一候选);param_2 += 0x10
//   步进;lo48==0xffff... 哨兵 → 出环(语料尾值残留同相 → -1)。
qint64 CodecMemo::scanMask(const void *needlePair, qint64 from, qint64 to)
{
	const GrepNeedle448 *needle = *(const GrepNeedle448 *const *)needlePair;
	const int nlen = needle->len;                 // 2626d *(needle+0x10)
	if (nlen <= 0)
		return -1;                                // 26272 门
	const qint64 scanEnd = to - (nlen - 1);       // 26274 param_3 -= nlen-1
	qint64 pos = from;                            // param_2
	quint64 pack = scanEngine(needle, pos, scanEnd);   // 首扫(cited)
	quint16 mask = quint16(pack >> 0x30);         // 26296 uVar5 hi16
	quint64 low48 = (pack << 0x10) >> 0x10;       // 26298 uVar3 lo48
	while (low48 != Q_UINT64_C(0xffffffffffff)) { // 2629a 哨兵门(循环顶)
		if (mask != 0) {                          // 2629f 掩码非空
			int bit = 0;                          // 262a4 最低置位扫描
			while (((mask >> bit) & 1) == 0)
				++bit;
			quint16 m = mask;
			for (;;) {
				const quint64 cand = quint64(bit) + low48;   // 262b0 uVar2
				if ((cand & needle->allowedBits) == 0)       // 262b4 +0x418 门
					return qint64(cand);          // 262ba 命中即返
				m = quint16(m & ~quint16(1u << bit));        // 262c0 弃位
				if (m == 0)
					break;                        // 262c6 掩码耗尽
				bit = 0;
				while (((m >> bit) & 1) == 0)     // 262cb 次低置位
					++bit;
			}
		}
		pos += 0x10;                              // 262e2 16B 步进
		pack = scanEngine(needle, pos, scanEnd);  // 再扫(cited)
		mask = quint16(pack >> 0x30);             // 262ee
		low48 = (pack << 0x10) >> 0x10;
	}
	return -1;                                    // 哨兵出环(语料尾值同相)
}
