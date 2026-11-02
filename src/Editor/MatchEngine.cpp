#include "MatchEngine.h"

#include "CodecMemo.h"   // GrepNeedle448 完整型(0x448;批 93 convCtor 构造链)

// 批 94 定案 1:1 方案落地。每行出处:语料 tools/re/decomp/
// decomp-part-0030.c(eng 四函数 + 分派器)/ decomp-part-0037.c
// (00b422d0);铁律 1。

namespace MatchEngine {

// —— vt 承载占位(eng 笔记 §4 深腿 2)——
// vt+0x50 块取 vcall(lineDoc,pos)→16B 块;lineDoc vtable 面落点未解
//   — cited — wave-2。占位 = 恒零 16B 块(静态);活性消费面 0x4f00
//   nlen<=0 门(26272)/0x4eff needlePair null 门(12665)不可达 —
//   占位同相(与批 93 scanEngine 恒哨兵同效)。
static const char *engVt50Block(const void *lineDoc, qint64 pos)
{
	Q_UNUSED(lineDoc);
	Q_UNUSED(pos);
	return "";                                        // 16B 恒零块承载
}

// vt+0x28 任意类→类 id byte vcall(37865)— 同上 cited — wave-2。
//   占位恒 0(skip[0] convCtor 默认 len+1 → 有界推进)。
static int engVt28Class(const void *lineDoc, qint64 pos)
{
	Q_UNUSED(lineDoc);
	Q_UNUSED(pos);
	return 0;                                         // 类 0 承载
}

// —— ENG<IsLiteral,UseSkip> 模板体 ——
// 语料签名 ulong ENG(long *lineDoc, long needle, ulong from, long to)
//   (eng 笔记 §0)。差异 2 维:针源维(IsLiteral=false 单表 +0x420
//   34640;true 双表 OR +0x428|+0x430,37943-38005 C 形/D 版 40299-
//   40360 变量序相反 — 机器码同构,eng 笔记 §1 注);miss 步进维
//   (UseSkip=false pos+=0x10 36216/40266;true bad-char 类跳表
//   37865-37866/42667-42668,消费 convCtor 建的 skip 表 conv+0x14)。
template <bool IsLiteral, bool UseSkip>
static quint64 engScan(const void *lineDoc, const GrepNeedle448 *needle,
                       quint64 from, qint64 to)
{
	const int nlen = needle->len;                     // +0x10(2626d 同源)
	const char *const tbl0 =
	    (const char *)needle->simdBlocks;             // +0x420(34640)
	const char *const tbl1 =
	    (const char *)needle->lowerSimd;              // +0x428(37957 C 形)
	const char *const tbl2 =
	    (const char *)needle->upperSimd;              // +0x430(37954 C 形)
	if (to <= qint64(from))                           // 34634/36272/37953/40354
		return Q_UINT64_C(0xffffffffffff);
	quint16 acc = 0;
	const char *blk;
	for (;;) {
		blk = engVt50Block(lineDoc, qint64(from));    // 34638 — cited — wave-2
		if constexpr (IsLiteral) {                    // 37957/37975 lane0 双表 OR
			acc = engCmp16(blk, tbl2);                //   +0x430 对(37958)
			acc = quint16(acc | engCmp16(blk, tbl1)); //   +0x428 对(37975)
		} else {
			acc = engCmp16(blk, tbl0);                // 34639-34672 lane0 单表
		}
		if (acc == 0)
			goto miss;                                // 34673 uVar1==0 嵌套逃逸
		if (nlen < 2)
			goto tail;                                // 34673 门 → LAB_00936cc3
		{   // 34674-36124 展开 lane1..31(34710..36124 门链 <2..<0x21)
			int lane = 1;
			for (;;) {
				blk = engVt50Block(lineDoc, qint64(from) + lane);  // 34674 — cited
				quint16 m;                            // 39127/39150 双表读序
				if constexpr (IsLiteral) {
					m = engCmp16(blk, tbl1 + lane * 0x10);       // +0x428(39127)
					m = quint16(m | engCmp16(blk, tbl2 + lane * 0x10));  // +0x430(39150)
				} else {
					m = engCmp16(blk, tbl0 + lane * 0x10);       // 34675 表+lane*16
				}
				acc = quint16(acc & m);               // 39111 auVar8 & (a|b)
				if (acc == 0)
					goto miss;                        // 39112 uVar1==0 → 嵌套逃逸
				if (nlen < lane + 2)
					goto tail;                        // 34710..<0x21 门链
				if (++lane == 0x20)
					break;                            // 36124 lane32 止(0x21 门)
			}
		}
		{   // 36129-36182 尾字循环(C 版 40163-40233 同构)
			qint64 pos = qint64(from) + 0x20;         // 36129 lVar6
			qint64 off = 0x200;                       // 36130 lVar7(表偏移)
			int i = 0x20;                             // 36131 iVar8
			while (i < nlen) {                        // 36183 do-while(iVar8<len)
				blk = engVt50Block(lineDoc, pos);     // 36132 — cited — wave-2
				quint16 m;                            // 40166/40204 双表读序
				if constexpr (IsLiteral) {
					m = engCmp16(blk, tbl1 + off);    // auVar73(+0x428,40166)
					m = quint16(m | engCmp16(blk, tbl2 + off));  // auVar41(+0x430,40204)
				} else {
					m = engCmp16(blk, tbl0 + off);    // 36135-36171
				}
				acc = quint16(acc & m);               // 40227 auVar8 & (auVar41|auVar73)
				if (acc == 0)
					break;                            // 36177/40228 break(嵌套逃逸)
				++i;                                  // 36178
				++pos;                                // 36180
				off += 0x10;                          // 36181
			}
			if (i == nlen)
				goto tail;                            // 36182/40233 全验证 → LAB
		}
	miss:                                             // 36216(A/C)/37865(B/D)
		if constexpr (UseSkip) {                      // bad-char 类跳表腿
			const int cls = engVt28Class(lineDoc,     // 37865 vt+0x28(len+pos+0xf)
			    qint64(nlen) + qint64(from) + 0xf);   //   — cited — wave-2
			from = quint64(qint64(needle->skip[cls])  // 37866 *(int*)(needle+
			    + qint64(from) + 0xf);                //   0x14+cls*4)+pos+0xf
		} else {
			from += 0x10;                             // 36216/40266 pos += 0x10
		}
		if (to <= qint64(from))                       // 36217/37867/40267/42669
			return Q_UINT64_C(0xffffffffffff);
	}
tail:                                             // 36125/40157 LAB
	return (quint64(acc) << 0x30)
	    | (from & Q_UINT64_C(0xffffffffffff));    // lo48 = 窗口起点(命中位
	                                              //   = 置位 lane+lo48,262b0)
}

// 四实例化(转写序 3632d→376d1→36cf1→3830d;批 94 定案)
quint64 engEntry0093632d(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to)   // 34639 lane0 单表 / 36216 步进
{
	return engScan<false, false>(lineDoc, needle, from, to);
}
quint64 engEntry00936cf1(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to)   // 37865 跳表腿
{
	return engScan<false, true>(lineDoc, needle, from, to);
}
quint64 engEntry009376d1(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to)   // 37954 双表 OR / 40266 步进
{
	return engScan<true, false>(lineDoc, needle, from, to);
}
quint64 engEntry0093830d(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to)   // 40299 双表 + 42667 跳表
{
	return engScan<true, true>(lineDoc, needle, from, to);
}

// 分派判式(26276-26288/26314-26326 两处同构)真身。
quint64 engDispatch(const void *lineDoc, const GrepNeedle448 *needle,
                    quint64 from, qint64 winEnd)
{
	if (needle->literal == 0)                         // 26276 *(char*)(lVar4+1)=='\0'
		return needle->len < 0xc                      // 26277 iVar1<0xc
		    ? engEntry009376d1(lineDoc, needle, from, winEnd)   // 26278
		    : engEntry0093830d(lineDoc, needle, from, winEnd);  // 26281
	return needle->len < 0xc                          // 26284
	    ? engEntry0093632d(lineDoc, needle, from, winEnd)       // 26285
	    : engEntry00936cf1(lineDoc, needle, from, winEnd);      // 26288
}

// FUN_00b422d0(2750B)@decomp-part-0037.c:32598 — cited — wave-2。
//   (>500B 体量,regex NFA 编译/匹配双路 + flags 0x800 门 + 0x70/0x74/
//   0x1c0 步进门 + 回收 free 腿 — 结构全读,语义未解不转写;恒未命中
//   → -1 承载,searchNeedle 占位同相)
qint64 bufferScan00b422d0(const void *needlePair, qint64 from, qint64 to)
{
	Q_UNUSED(needlePair);
	Q_UNUSED(from);
	Q_UNUSED(to);
	return -1;  /* cited — wave-2 */
}

} // namespace MatchEngine
