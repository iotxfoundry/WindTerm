#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include <QtGlobal>

class GrepNeedle448;   // CodecMemo.h(0x448 针对象;批 93 convCtor 构造链)

// 批 94 定案 1:1 方案:四匹配引擎 ENG<IsLiteral,UseSkip> 参数化单模板
// (P3 勘察 /tmp/opencode/p3_notes_eng.md:骨架 100% 同构,差异 2 维 —
//   针源单双表 / miss 步进短针 vs 跳表)。
// 语料:tools/re/decomp/decomp-part-0030.c
//   entry=0093632d(34587,任意类/短针)/ 00936cf1(36224,任意类/跳表)/
//   009376d1(37874,literal/短针)/ 0093830d(40274,literal/跳表)/
//   分派器 0092a596(26261)。
// 转写序:3632d(最纯)→ 376d1 → 36cf1 → 3830d → 2a596(批 94 定案)。

namespace MatchEngine {

// 16B 逐字节相等掩码 pack(34639-34672 auVar10 直译:-(eq)/字节 →
//   各字节最高位收 16bit;SUB161(>>7)&1 … [0xf]>>7 展开同构)。
//   eng 笔记 §3:语义等价直译免 SSE intrinsic(源码本为同模板展开)。
inline quint16 engCmp16(const char *blk, const char *tbl)
{
	quint16 m = 0;
	for (int i = 0; i < 0x10; ++i)
		m |= quint16(blk[i] == tbl[i]) << i;      // -(eq) 高位语义
	return m;
}

// 外部可见四符号(eng 笔记 §3:便于 xref 与断点对齐)= ENG<
//   IsLiteral,UseSkip> 模板四实例化(体在 MatchEngine.cpp;engScan
//   模板 + vt 承载占位同文件)。实例化矩阵:
//   ┌─────────────┬ IsLiteral=false(任意类,单表 +0x420)
//   │             ├ IsLiteral=true (literal,双表 OR +0x428|+0x430)
//   ├ UseSkip=false(短针,miss pos+=0x10)→ 0093632d / 009376d1
//   └ UseSkip=true (长针,bad-char 类跳表)   → 00936cf1 / 0093830d
//   签名统一 ulong ENG(long *lineDoc, long needle, ulong from, long to)
//   (eng 笔记 §0;返回 pack64:hi16 = 16-lane 候选掩码,lo48 = 窗口
//   起点(命中位 = 置位 lane i + lo48,分派器 262b0 消费);无命中 =
//   0xffffffffffff — 34634/36272/37953/40354 边界哨兵)。
quint64 engEntry0093632d(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // 任意类/短针
quint64 engEntry00936cf1(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // 任意类/跳表
quint64 engEntry009376d1(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // literal/短针
quint64 engEntry0093830d(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // literal/跳表

// 分派判式(0092a596 内 26276-26288/26314-26326 两处同构):literal 门
//   *(char*)(needle+0x01)==0 → literal 对;非 0 → 任意类对;各按
//   len<0xc 分短/长(体在 .cpp — 读针门字段需完整型)。
//   lineDoc 承载替:语料 param_1+0xf8 解引用(26280/26316)→ 直收
//   lineDoc 承载(EditorContext +0xf8 = 布尔位,布局不同构 — 登记;
//   批 119:vt 槽真身 = docBytes 直读承载(engVt50Block/engVt28Class))。
//   批 127:engDispatch 内 null → s_scanCarrier 承接(活性缝,挂线 =
//   initDoc 驱动批);未挂线保持 null = 壳态守卫(同相)。
quint64 engDispatch(const void *lineDoc, const GrepNeedle448 *needle,
                    quint64 from, qint64 winEnd);

// 批 127:scanMask 活性接线 — +0xf8 buffer 承载缝(见 MatchEngine.cpp
//   缝注记:载体 = docBytes 直读;attach/detach = initDoc/拆链驱动面)。
void attachScanCarrier(const void *lineDoc);   // +0xf8 槽挂线(00929fe1 面)
void detachScanCarrier();                      // 拆线(0092f852 面)
bool carrierLive();                            // 缝非空读面(scanLineDoc 门)

// FUN_00b422d0(2750B)@decomp-part-0037.c:32598 — 缓冲扫描引擎 — **边界
//   委托(批 102 勘定)**:直调 regex_nfa_compile(00b3cc80 20839B)/
//   regexp_match_dispatch(00b3b730)命名符号,本体 = Onigmo-改 搜索
//   驱动(≈onig_search),ext-boundary 第一方组件 → 停止逆向,行为由
//   src/Onigmo 移植校准委托承接(激活批需 calibration)。thunk 链:
//   0092547e → 00a8395c(42B)→ 00a83946(21B 门)→ 00b42e10(28B)→ 本体。
//
//   批 105 取证结论(kuna CLI 全实证;激活未落行为码 — 任务书失败条款):
//   ① 0x448 GrepNeedle448 无编译产物字段:operator_new(0x448)@0089a0a0
//     产腿 → refs{1,1}+vt 0x1192460 → convCtor(&v7[2]) 写域 conv+0x10..
//     +0x437 恰满 0x448-0x10 头 — 零剩余字节,无 regex 编译体指针;
//     SIMD/掩码腿(engDispatch)与 onig 引擎(00b422d0)对象布局零重叠。
//   ② canOld=true 搜索腿正则来源不在针对象:0x4eff @0xa33001 调
//     sub_92547e(doc, v7, v21, &v10, v21)— param_4 = &v10 =
//     canEncodeMemo(0089b85e→00a8450a Uint32Bimap 0x20 ctl)缓存对象
//     (00a32d30 实证),非 onig regex;搜索正则由 doc+0x1098
//     FindContext 深腿持有(cited),编译 = Onigmo-改 惰性编译栈
//     (FUN_00ad7360 304B/FUN_00ad2ae0 17929B,批 101 三源互证),
//     业务区零 onig_new 直调(kuna xrefs --to onig_new 无名命中;
//     语料 49M onig_new/regex_compile/REG_COMPILE 零命中;批 103 L3 同判)。
//   ③ b422d0 param_2 正则对象布局(kuna 反编译 0x00b422d0 实测):
//     +0x48 编码 vtable(*vt+0x90 step_back/+0x28 mbc_enc_len/+0x38
//     is_mbc_newline — Onigmo-改 iterator 面)/+0x50,+0x51 选项位/
//     +0x70,+0x74,+0x78 优化标志/+0x80,+0x88 minLen,maxLen/+0x1c0
//     精确串指针/regex+0x14 捕获对容量(b41ee0 扩容面)— 与
//     GrepNeedle448 布局零重叠;onig_new 语法/编码选项实参在业务区
//     不可达 — 激活缺证:FindContext 深腿正则条目构造链(doc+0x1098
//     → 编译栈入参),不猜选项(铁律 3)。
//   ④ 批 109 编译栈深取证(kuna 全链反编译,2026-11-13;仍未达激活门槛):
//     · 调用链全图:00a81655(210B 编译门)→ 00a9c780(22512B,Onigmo-改
//       parse+compile 本体,签名 (pat*,len,option,err_code*,err_pos*,syntax*)
//       6 参 — 上游 onig_new 7 参无此形,regex** 出参改返回值 = 改版差异
//       之一)→ 唯一编译门调用方 00ad7360(304B 惰性编译门,产物挂对象
//       a0[4]=+0x20 槽;0xa816d1 唯一上游)。构造器族:00a81a88(450B ←
//       00a81c4a 200B ctor ← 0x80a2c5/0x89c0fb/0xa84f32 三调用点)/
//       00a848d6(207B ← 00a140b2(368B QByteArray→std::string 桥)←
//       00a144d2(1112B:序列化 "//…//" 剥壳与 /*…*/ 分支 ← 00a15ef6
//       (90B)← 00a121a0(1600B 文档模型循环))。消费侧:doc+0x88
//       searcher sub_a83c7a(400B)取 *(needle+0x18)=regex 对象 →
//       FUN_00ad74a0(431B,Onigmo-改 onig_search 等价:param_6=region,
//       +0x18/+0x20/+0x40 结果写面)。
//     · 正则条目不在 FindContext 自身:构造产物挂 *调用方对象* +0x0
//       (a81a88/a848d6 均 a0->field_0x0=regex);doc+0x1098 仅经
//       9975c8(槽[5]=+0x28)取 pattern 串源(getter 9276e2/927600
//       ← editor_replaceAll 12551-12557);编译时机 = 各上游调用点,
//       非 doc 持有编译栈(批 105 缺证清单 1 勘正)。
//     · 语法/编码仍缺证:①编码 — a81655→a9c780 直调无 encoding 参
//       (编码进 a9c780 内部);旁支编译栈 00b3b090→00b39830 传全局
//       DAT_011becc8 作 encoding,唯一写点 00b39540(9B setter)
//       kuna xrefs = 0(运行不写 → 取 0;ONIG_ENCODING_* 对应值
//       无实证)。②语法 — a9c780 内默认语法 = &dat_d15860(a5==0
//       时),数据地址无符号对照(上游 OnigDefaultSyntax=
//       ONIG_SYNTAX_RUBY 仅候选);业务三调用点(a81a88/a848d6/
//       a82450)语法参恒 0 → 运行值 = dat_d15860,内容不可达。
//       ③选项位 — a81655 入口重组(0x2000000→|0x80000000; a1→
//       |0x8000008; a2→|0x20)与 Onigmo-改位面吻合,但多调用点
//       option 恒 0 → 非正向证据。
//     · 裁决:证据不齐(编码/语法运行值零实证)→ 本批零行为码;
//       下批入口 = dat_d15860 数据段转储(对照 src/Onigmo
//       OnigSyntaxType 布局逐域比对)+ DAT_011becc8 运行时观察
//       (实验锚)。
//   ⑤ 批 110 face 定案取证(kuna + xrefs + ELF 转储,2026-11-13;未激活):
//     · 00aa1f70=malloc 尾调用/00aa1f80=free 尾调用(kuna 直证,编码
//       钩子候选证伪);dat_d15860 = 编译环境 face 0x48B:
//       [0]alloc [1]free [2]ctx [3,4]0 [5]=0xd35f40 fold 表 [6]=-1
//       (pattern 限长 ∞) [7]=u16{2,5}+u32{0xfa} [8]=flags — 消费点
//       唯一 @a9c780(a9c7ee);aa2060(0) 堆构造为同构镜像(a81655
//       param_5 腿)。
//     · 0xd35f40 勘正 = ASCII case-fold 表 256B(A-Z→a-z,余恒等),
//       非恒等表/非编码 face;dat_d158a8 = 9 项 vtable{free,aa26b0×6,
//       aa2728×2}(aa1f90 继承构造,aa26b0/28 = pattern 扫描虚方法)。
//     · 语法 op/op2/behavior 域零消费(硬编码进 a9c780)→ 上游
//       ONIG_SYNTAX_*/ONIG_ENCODING_* 映射无落点,libonig 委托缺
//       syntax/encoding 实参 — 零行为码(详 docs/calibration.md 批 110)。
//   ⑥ 批 116 激活定案(2026-11-13;calibration 批 116 对账):
//     语法假设 = ONIG_SYNTAX_RUBY(五真实样例对账:possessive ++ 与
//     \g<X> 子例程调用同时要求 → RUBY 唯一上游覆盖,Java/Perl 无
//     ESC_G_SUBEXP_CALL;(*UTF) 前缀 = WindTerm 层剥壳非语法域)。
//     委托形态 = onig_new(RUBY+UTF-8)+ onig_search 字节承载替
//     (OnigIterator{onig_default_charat};OnigSearch.cpp 逐句映射,
//     calibration 批 116 逐句条目)。缓冲字节契约 = 0x4eff case
//     needlePair(conv+0x08 针字节/+0x01 case 位)→ bufferScan。
qint64 bufferScan00b422d0(const void *needlePair, qint64 from, qint64 to);

} // namespace MatchEngine

#endif // MATCHENGINE_H
