#include "MatchEngine.h"

#include <QByteArray>     // 批 119:vt 载体 docBytes 直读(charAt/block16 承载)

#include "CodecMemo.h"   // GrepNeedle448 完整型(0x448;批 93 convCtor 构造链)
#include "OnigSearch.h"  // 批 116:0x4eff 引擎腿委托(批 102 ext-boundary 激活)

// 批 94 定案 1:1 方案落地。每行出处:语料 tools/re/decomp/
// decomp-part-0030.c(eng 四函数 + 分派器)/ decomp-part-0037.c
// (00b422d0);铁律 1。

namespace MatchEngine {

// —— vt 承载真身(批 119 buffer vtable 槽转储定案;批 118 形态对账升级)——
// 转储方法(qmo_extract.py 同法):readelf -lW LOAD 段映射 + .data.rel.ro
//   (VA 0x117eba0/file 0xb7eba0)直读 + R_X86_64_RELATIVE 重定位解析。
//   两源定案:①ctor imm(vptr 写入常数)②typeinfo 名串:
//   CSuperBufferBase 体 0x11ad718/vptr 0x11ad728(ctor FUN_00980380
//   `mov $0x11ad718,+0x10` @980387;decomp-part-0032.c:9403;ti 0x11ad708
//   = "16CSuperBufferBase");
//   CSuperBuffer32 体 0x11ad808/vptr 0x11ad818(ctor FUN_009818aa @9818b6,
//   0032.c:10506/10509;ti 0x11ad790 = "14CSuperBuffer32",si-base→基);
//   CSuperBuffer64 体 0x11ad900/vptr 0x11ad910(ctor FUN_00989ef2 @989efe,
//   0032.c:17145;ti 0x11ad8e8 = "14CSuperBuffer64")。
//   槽语义(vptr 相对;行号 @decomp-part-0032.c):
//   · +0x28 = charAt:CSuperBuffer32_vt5 00981b2a(:10577;越界/负位 →
//     DAT_011c26b1(.bss 零)=0;锁路同返 0);64 同面 00989e8c →
//     Snapshot64_h9c784c 009c784c(:63492,"pos<0||pos>=+0x10 长度→0")。
//   · +0x50 = block16:CSuperBuffer32_vt10 00982212(:10948;pos+0xf 段内
//     直返段指针,跨界清零 buffer+0x30 16B 出参 + memcpy + 尾填
//     FUN_00989740);64 = 00989ec0(:17102)→ FUN_009c7cd0(:63742)同构。
//   engScan 消费对账:34638/34674/36132 lane 窗口块取 ↔ vt+0x50;37865/
//   42667 skip cls ↔ vt+0x28 charAt(= FUN_009284aa byteAt vcall 同面,
//   EditorEngine.cpp:48 docBytes 承载先例)。
//   载体:lineDoc = const QByteArray*(docBytes 承载替;nullptr = 壳态 →
//   恒零块/类 0,与批 118 占位同相 — product scanMask 现传 nullptr,
//   活性接线挂 buffer 承载批,engDispatch/scanMask 零改动)。block16 跨界
//   出参 = 文件级 static 16B(语料 per-object buffer+0x30 槽 — 承载替登记)。
//   批 127 补:engDispatch 入口于 lineDoc==null 时以 s_scanCarrier 承接
//   (下方分派器前定义);s_scanCarrier 挂线后 null 分支仅剩未挂壳态。
namespace {
const void *s_scanCarrier = nullptr;   // +0xf8 槽承载缝(壳态 null;
                                       //   批 127 fwd:engDispatchImpl 先用)
// 壳态恒零 16B 块(engVt50Block null 分支;批 118/119 同相语义 —
//   语料 = buffer+0x30 出参清零面,非 "" 字面量:engCmp16 读满 16B,
//   "" 只有 1B → 越界 .rodata 未定义读,批 127 i5 断言暴露)
const char s_zeroBlock[0x10] = {0};
}
static const char *engVt50Block(const void *lineDoc, qint64 pos)
{
	if (lineDoc == nullptr)
		return s_zeroBlock;                           // 壳态恒零 16B(同相;
		                                              //   批 127:静态 16 零块,
		                                              //   免 "" 1B 越界读)
	const QByteArray *doc = static_cast<const QByteArray *>(lineDoc);
	static char scratch[0x10];                        // vt10 buffer+0x30 出参承载替
	if (pos + 0x10 <= doc->size())                    // :10985 段内直返臂
		return doc->constData() + pos;
	int i = 0;
	if (pos < doc->size()) {                          // :10989-10992 清零+memcpy
		for (; i < 0x10 && pos + i < doc->size(); ++i)
			scratch[i] = doc->constData()[pos + i];
	}
	for (; i < 0x10; ++i)                             // :10994 尾填(FUN_00989740/
		scratch[i] = char(0);                         //   009c7a84 面;越界读=0 同相)
	return scratch;
}

// vt+0x28 任意类→类 id byte vcall(37865)真身(批 119 转储升级)。
//   kuna 00936cf1 尾逐字:v1 = *(void**)(vt(v2)+0x28);a2 = *(int*)(needle
//   + cls*4 + 0x14) + a2 + 0xf — skip 算式腿已真身(engScan UseSkip 腿)。
//   槽 = charAt(上注 00981b2a/009c784c):越界→0;载体同 engVt50Block。
static int engVt28Class(const void *lineDoc, qint64 pos)
{
	if (lineDoc == nullptr)
		return 0;                                     // 壳态类 0(同相)
	const QByteArray *doc = static_cast<const QByteArray *>(lineDoc);
	if (pos < 0 || pos >= doc->size())
		return 0;                                     // :10583 越界→DAT_011c26b1=0
	return quint8(doc->constData()[pos]);             // charAt 真身承载
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
		blk = engVt50Block(lineDoc, qint64(from));    // 34638 vt+0x50 真身(批 119)
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
				blk = engVt50Block(lineDoc, qint64(from) + lane);  // 34674 vt+0x50(批 119)
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
				blk = engVt50Block(lineDoc, pos);     // 36132 vt+0x50(批 119)
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
			const int cls = engVt28Class(lineDoc,     // 37865 vt+0x28 charAt 真身
			    qint64(nlen) + qint64(from) + 0xf);   //   (批 119 转储)
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

// 分派判式(26276-26288/26314-26326 两处同构)真身。批 127:lineDoc
//   null 时以载体缝承接(+0xf8 attached → &docBytes;壳态保持 null 同相)。
quint64 engDispatch(const void *lineDoc, const GrepNeedle448 *needle,
                    quint64 from, qint64 winEnd)
{
	if (lineDoc == nullptr)
		lineDoc = s_scanCarrier;      // 0092a596 param_1+0xf8 解引承载缝
	// (判式体下行)
	if (needle->literal == 0)                         // 26276 *(char*)(lVar4+1)=='\0'
		return needle->len < 0xc                      // 26277 iVar1<0xc
		    ? engEntry009376d1(lineDoc, needle, from, winEnd)   // 26278
		    : engEntry0093830d(lineDoc, needle, from, winEnd);  // 26281
	return needle->len < 0xc                          // 26284
	    ? engEntry0093632d(lineDoc, needle, from, winEnd)       // 26285
	    : engEntry00936cf1(lineDoc, needle, from, winEnd);      // 26288
}

// —— 批 127:scanMask 活性接线 —— +0xf8 buffer 承载缝。
//   语料:engDispatch 消费者 FUN_0092a596(26276/26314)解引 *(param_1
//   +0xf8) 传真体;+0xf8 槽由 editor_engineCtor 00929fdd..00929fe1
//   建 32 型(FUN_009818aa)/ 00927f16 置换(0x48B,false→32 型 /
//   true→64 型 FUN_00989ef2)/ 0092f852 拆链置 null。我方承载替:
//   vtable 槽 charAt/block16 语义已由批 119 真身按 docBytes 直读
//   同相承接 → 缝只持载体指针(engVt50Block/engVt28Class 的
//   const QByteArray* 直读面),不建 CSuperBuffer 对象(类型面
//   0x48/0x70 槽 = 引用档,需时单批升真)。
//   守卫:未挂线 → engDispatch 收 null → 壳态(恒零块/类 0,批 118/
//   119 同相);挂线 = initDoc 驱动批(EditorEngine 侧,本批只落缝)。
void attachScanCarrier(const void *lineDoc)   // initDoc 接线(00929fe1 面)
{
	s_scanCarrier = lineDoc;
}
void detachScanCarrier()                      // 拆链(0092f852 面)
{
	s_scanCarrier = nullptr;
}
bool carrierLive()                            // 缝读面(0x7543 短路门同形)
{
	return s_scanCarrier != nullptr;
}

// FUN_00b422d0(2750B)@decomp-part-0037.c:32598 — 批 116 激活:OnigSearch
//   委托薄包装(批 102 ext-boundary 勘定;恒 -1 占位退役)。逐句映射:
//   · 门 32611(param_4<param_6 return -1)/32614(param_6<param_3
//     return -1)→ 本包装 to/from 契约校验同相(bufferScan 内 search
//     门前置);needlePair null → -1(00a83946 *param_2 门)。
//   · 引擎主体(regex_nfa_compile/regexp_match_dispatch NFA 搜索环)
//     = onig_search(regexec.c:3905)委托 — Onigmo-改 与上游同源,
//     行为由 libonig.a 承接(ext-boundary 注册表;calibration 批 116)。
//   · 返回契约:命中绝对字节位 / -1(0x4eff 段 E 12719 LAB_00a33299
//     消费同相)。
//   · 语法/编码假设(RUBY/UTF-8)= calibration 批 116 对账定案,
//     非语料直证 — 假设登记行(铁律 3:不猜已显式声明)。
qint64 bufferScan00b422d0(const void *needlePair, qint64 from, qint64 to)
{
	if (needlePair == nullptr)                      // 00a83946 needle[0]!=0 门:
		return -1;                                  //   真载体首八字 = conv vtable
	                                                    //   恒非零;我方壳无 vtable
	                                                    //   (批 105:0x448 无编译产物),
	                                                    //   literal=0 档首八字可为零 —
	                                                    //   门以 null 门承接(壳态等价)
	const GrepNeedle448 *needle =
	    static_cast<const GrepNeedle448 *>(needlePair); // 语料 param_4 = 针对象
	                                                    //   指针(单层;批 116 双层
	                                                    //   解引 = searcher 槽形态
	                                                    //   误推,批 116b 勘正)
	if (needle->len <= 0)                           // 26272 nlen<=0 门同相
		return -1;
	// 针字节(conv+0x08 QByteArray)+ case 位(conv+0x01)→ 委托。
	// 主题承载 = setSubject 静态缝(登记承载替;调用方 = 0x4eff case
	// 文档字节 — 本函数内 set,search 内消费,无跨调用残留)。
	OnigSearch::setSubject(needle->bytes.constData(), needle->bytes.size());
	const qint64 hit = OnigSearch::bufferScan(needle->bytes.constData(),
	    needle->len, needle->caseFlag != 0, from, to);
	OnigSearch::clearSubject();
	return hit;
}

} // namespace MatchEngine
