#ifndef WT_EXT_ZSTDFACE_H
#define WT_EXT_ZSTDFACE_H

// EXT-BOUNDARY zstd 接口面(docs/EXT-BOUNDARY.md 注册表"压缩面")。
//
// 语料调用点:s_PairColor_a72272@00a7246x → zstd_ctxCreate(dst,dstSize,
// src,srcSize)(00bb88b0@decomp-0038.c:84689,388B 全读:cpuid 派发 +
// 0x176d8 DCtx alloc + FUN_00bb8820/00bb8800,零 WindTerm 业务态)=
// 真库 ZSTD_decompress(dst,dstCap,src,srcSize) 等价签名。
//
// 委托状态:libzstd 未链接(CMakeLists 写域外)→ 调用点
// (src/Editor/EditorEngine.cpp PairColor 膨胀腿,批 84)暂 no-op sink
// + cited — wave-2;链接 -lzstd 后该腿改调 ZSTD_decompress 即点亮
// (仅此一处调用点)。

#include <cstddef>

extern "C" {
unsigned ZSTD_versionNumber(void);   // 备查;当前无调用点
size_t ZSTD_decompress(void *dst, size_t dstCap, const void *src,
                       size_t srcSize);
}

#endif // WT_EXT_ZSTDFACE_H
