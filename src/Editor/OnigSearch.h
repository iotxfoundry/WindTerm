#ifndef ONIGSEARCH_H
#define ONIGSEARCH_H

#include <QByteArray>
#include <QtGlobal>

#include "Onigmo/oniguruma.h"   // 上游 Onigmo 面(src/Onigmo;lib/libonig.a 预构建)

// 批 116:0x4eff 搜索引擎腿委托(批 102 EXT-BOUNDARY 激活;语法假设 =
// ONIG_SYNTAX_RUBY — CALIBRATION 批 116 对账定案;铁律 1 落点见 .cpp)。
namespace OnigSearch {

// 编译:pattern 字节 → OnigRegex。RUBY 语法 + UTF-8 编码 + 可选忽略
// 大小写(↔ 00a9c780 编译本体上游 7 参形态;errOut 收 onig_new 返回码,
// 0 = 成功)。
OnigRegex compile(const char *pat, int len, bool ignoreCase, int *errOut);

// 搜索:subject = setSubject 承载缝;[str=0, end=len], start=from,
// range=to。返回命中起(绝对位置)或 -1(ONIG_MISMATCH 契约同相)。
qint64 search(OnigRegex re, qint64 from, qint64 to);

// 引擎委托落点(FUN_00b422d0 缓冲扫描驱动承载):pat = 针字节
// (GrepNeedle448 conv+0x08),ignoreCase = conv+0x01 case 位。惰性
// 编译单槽缓存(00ad7360 产物挂 +0x20 槽承载同相;换 pattern 释旧)。
qint64 bufferScan(const char *pat, int len, bool ignoreCase,
                  qint64 from, qint64 to);

// 主题承载缝(语料 searcher +0x74/+0x78 buffer 字段替;批 116 登记 —
// 字节缓冲不被复制,调用方保生存期)。
void setSubject(const char *bytes, qint64 len);
void clearSubject();

// 释放(onig_free ↔ 00aa1f80 free 尾调用 face;批 110)。
void freeRegex(OnigRegex re);

} // namespace OnigSearch

#endif // ONIGSEARCH_H
