# BUILD-AUDIT — 开源组件嵌入审计(原版 vs 重建)

> 调查日期:2026-10-29。证据 = 原版二进制符号/版本串 + 我方
> libWindTermRe 的 nm + compile_commands.json 包含路径。

## 一、原版静态嵌入的开源组件(实证)

| 组件 | 版本 | 证据 | 我方状态 |
|---|---|---|---|
| **boost** | 1_78_0 | 大量 `boost::xpressive`/`boost::condition_variable` 符号 + `boost_1_78_0` 串 | **未复刻(已知差距)**:正则面原版用 boost::xpressive |
| **yaml-cpp** | 0.7.0 | 构建路径串 `/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/*` | ✅ libyaml-cpp.a 链入(586 符号) |
| **jsoncpp** | — | `Json::Value` 等 | ✅ 链入(428 `_ZN4Json` 符号) |
| **dtl** | — | `N3dtl3LcsIiEE` 等(diff template library) | 未复刻(diff 面未及) |
| **zstd** | — | `ZSTD_trace_*` 符号 | 未复刻 |
| **ICU** | 56 | lib/icudata.so.56 动态捆绑 | 动态捆绑同款 |
| spdlog/fmt | — | **0 符号命中**(仅特征串;踩坑 6"特征串≠同版本源码") | 日志实现存疑,loggerOp 面 Phase-4 cited |
| onig/Onigmo | — | **0 命中(原版不用!)** | 已删除(早期误判引入) |

## 二、我方 libWindTermRe 嵌入实况

| 库 | 符号证据 |
|---|---|
| scintilla_core + scintilla_qt | 9535 |
| yaml-cpp | 586 |
| jsoncpp | 428(_ZN4Json) |
| onig | 0(未链,已删) |

## 三、inc/ 头文件快照(2026-10-29 曾删,同日恢复——保留至复刻完成)

19 目录 / 23MB:alsa, cpp-btree, dbus-1.0, dtl, fmt, glib-2.0,
gstreamer-1.0, gtk-3.0, icu, jsoncpp, openssl, pulse, spdlog, X11,
xcb, xxhash, yaml-cpp, zlib(19 = 含 openssl 子级)。

- **0 构建引用**:compile_commands.json 无 `-I inc/*`;openssl 的
  `#include "openssl/evp.h"` 解析自 ssl11/include 与
  src/libssh/include;yaml-cpp 解析自源码树。
- **性质 = 未复刻子系统的 API 参考文档**,不是构建垃圾:
  - fmt/spdlog → loggerOp/logger 面(Phase-4 cited)复刻时
    需要对齐原版 spdlog API 与版本
  - dtl → diff 功能面未复刻
  - cpp-btree/xxhash → 原版容器/哈希实现线索
  - zlib/zstd → 会话存档/传输压缩未复刻
  - gstreamer/pulse/alsa → bell 音频播放路径未复刻
  - icu → 原版 Unicode 语义参照(我方暂用 QTextCodec)
- **处置原则(2026-10-29 修订)**:参考性材料的删除等该子系统
  复刻完成并过对比后再做;不当"构建未引用=可删"。
- src/Onigmo + lib/libonig.a 同批恢复(证据仅"无符号",非定论;
  保留至正则面对比完成)。

## 四、CMake 链接修正(2026-10-29)

- libWindTermRe RUNPATH 曾指向 repo lib/(bundled libssh.so.4 链入
  所致),令 libQt5Network NEEDED 解析到 bundled 5.15.2 Qt——与
  系统 5.15.13 混载即堆损坏(Phase 5 diff 环境问题根源之一)。
- 修正:POST_BUILD `patchelf --remove-rpath` +
  `BUILD_RPATH_USE_ORIGIN TRUE`;测试经 LD_LIBRARY_PATH 显式控版本。
