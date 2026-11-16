# ext-boundary — 外部库接口边界(不逆向实现)

> 原则:原版静态嵌入的开源库,其**实现不逆向**。转写中命中下列
> 命名空间/行为特征 → 标记为外库边界,只转写 WindTerm 侧的调用
> 接口面;行为由接口层(委托真库或 no-op sink)承接。
> 依据:docs/build-audit.md(嵌入审计)。

## 外部资产三类归属(判据)

| 去处 | 含义 | 例 | 判据 |
|---|---|---|---|
| `src/<lib>/` | **参与编译**的第三方源码 | Scintilla · jsoncpp · yaml-cpp · Onigmo · libssh-改 | 有 `.c/.cpp`,进 CMake 目标或预构建 `.a` |
| `inc/<lib>/` | **不参与编译**的系统头 / 版本锚 | zstd · X11 · gtk · icu · openssl | 只有 `.h`;用于 API/版本对齐 |
| `vendors/<name>/` | 原版捆绑的**运行时资产** | `lrzsz/{rz,sz}` | 可执行文件/数据,运行时被 spawn 或读取 |

> 判据一句话:**会被编译的进 `src/`,只对齐 API 的进 `inc/`,运行时才用的资产留 `vendors/`。**

## 边界注册表

| 库 | 证据(原版) | 符号/行为特征 | 边界面 |
|---|---|---|---|
| boost 1.78.0 | 大量 xpressive/线程符号 + 版本串 | `boost::xpressive`、`boost::condition_variable`… | 正则面转写时补(未及) |
| yaml-cpp 0.7.0 | 构建路径串 | `YAML::` | 委托真库(ConfigBridge 已接) |
| jsoncpp | `Json::Value` | `Json::` | 委托真库(已接) |
| dtl | `N3dtl…` 符号 | `dtl::Sequence/Lcs/Diff3` | diff 面转写时补 |
| zstd **1.5.2** | **静态嵌入**:`zstd_ctxCreate`(`0x00bb88b0`,388B)在 `.text`,alloc `0x176d8`(96K DCtx);二进制里仅 4 个 `ZSTD_trace_*` 弱符号为动态引用(`ldd` 因此显示 libzstd.so.1) | `ZSTD_*` | 已落声明面 `src/Ext/ZstdFace.h`;调用点(`EditorEngine.cpp` PairColor 膨胀腿)暂 no-op。**版本锚**:`inc/zstd`(1.5.2 头快照,43 个 .h / 0 个 .c) |
| spdlog/fmt | 特征串(0 符号,可见性隐藏) | 日志 sink 行为、`fmt::format` | **src/Ext/**(已建接口层) |
| ICU 56 | lib/icudata.so.56 动态捆绑 | 运行时动态库 | 不需接口(动态加载) |
| glib/gtk/X11/alsa/pulse/gstreamer/dbus | 动态系统栈 | 运行时动态库 | 不需接口 |

## 第一方开源组件(2026-10-29 新增,见 docs/calibration.md)

src/ 本就包含官方开源的 6 个第一方组件(TelnetProtocol/Pty/Utility/
Widgets/libssh-改/Onigmo-改,Apache-2.0;勿重复 clone)——**对应子系统停止逆向,
改为移植/校准**。终端核心不在其中 = 逆向边界的权威确认。

### Onigmo-改 边界精确化(2026-11-13 批 102)

- **00b4xxxx 正则引擎区停逆向**:FUN_00b422d0(2750B 缓冲扫描驱动,
  ≈onig_search)直调 regex_nfa_compile(00b3cc80 20839B)/
  regexp_match_dispatch(00b3b730)/regex_match_execute 等命名符号,
  邻域 onig_*/regex_*/xpr_* 命名密集 — 全区属 Onigmo-改 实现。
- 执行腿先例:批 101 markers 执行腿 00ad74a0 已 cited 同判。
- 委托路径:src/Onigmo 源树 + lib/libonig.a(2.1M 预构建已链);
  业务侧(EditorEngine 0x4eff 搜索腿/MatchEngine::bufferScan00b422d0)
  保持 cited 占位,激活批移植 onig 调用面并按 calibration 记录。

## 使用规则

1. 转写中遇到疑似外库实现(算法密度高、无 WindTerm 业务状态、
   符号/字符串命中上表)→ **停止转写**,查 inc/ 对应头文件的
   API,登记到本表"边界面"列。
2. WindTerm 侧调用点转写为接口层调用(src/Ext/ 声明)。
3. 接口层的实现:优先委托真库(yaml-cpp/jsoncpp 模式);
   无真库可委托时先 no-op sink + cited,行为对比阶段再补。
4. 例外:外库**数据结构在内存中的布局/序列**若被 WindTerm 业务
   逻辑消费(如 SGR 位、行格),该部分仍属逆向范围——边界只在
   库的实现内部。

## 接口层(src/Ext 已删,2026-10-29)

初版 Face 声明层(src/Ext/spdlog|fmt)在源码树归位(src/spdlog、
src/fmt)后由**真库 API 直接承接**(委托真库策略)——logger 面
转写时直接使用 src/spdlog 的 logger.h/格式化 API,不再需要自造
Face 声明。

## 动态库直接调用接口(2026-10-31 勘定,导出表交集法)

主二进制 NEEDED = 10 动态库;PLT 直接调用 ≈3270 符号(交集法精确计数):

| 库 | 符号数 | 结论 |
|---|---|---|
| Qt5Widgets/Core/Gui/Network | 1535/1052/371/91 | 委托真库(既有策略)|
| **libssh.so.4** | **117**(sftp_async_* 47 全套)| ssh-internals 委托边界精确到符号清单;TLS 走 libssh(libssl 交集=0)|
| **libQt5Qml** | **45 = QJSEngine 全家** | **JsEngine 底座钉死:动态 QJSEngine 真库,零逆向**(calibration 落定)|
| Qt5SerialPort | 18 | 串口会话 = 纯委托 QSerialPort |
| Qt5Multimedia / Qt5Svg | 13 / 8 | 提示音 / SVG(QSvgRenderer 委托吻合)|
| X11/Xtst | 10 | XSendEvent/XTestFakeKeyEvent/XKeysymToKeycode(按键模拟/热键)|
| libcrypto 1.1 | 6 | **已勘定(批 68)**:FUN_00a7dfb0(316B)= AES-256-CBC;blob [32B 盐\|48B key\|48B iv\|密文] base64;主密码 PBKDF2-HMAC-SHA256(100000);对象 = 配置敏感字段(autoLogin/proxyPassword);包装链 00a7e12e/e258/e3f0/e5f6/e61c;padding 默认 PKCS7 待证 |

静态(逆向对象,不在 NEEDED):Scintilla/boost/yaml-cpp/jsoncpp/onig。
未定:Multimedia 13 具体符号(勘定见下 EVP 行)。

## lib/ 子目录(2026-10-31 补勘):26 个 Qt 插件,零直调

子目录(platforms/imageformats/iconengines/audio/mediaservice/
platforminputcontexts/platformthemes/xcbglintegrations)26 so 全为
标准 Qt 插件分类:
- **零直调实证**:NEEDED 不含;导出表 ∩ 主二进制未定义 = 16 符号且
  全为 libstdc++ std::string 模板实例(同版工具链共性,非接口)
- 加载机制 = QPluginLoader 运行时自动匹配(QPA/图像格式插件),
  非主二进制代码显式调用;测试环境 QT_PLUGIN_PATH 已覆盖
- 唯一主动加载抽象 = **DynamicLibraryImpl**(FUN_00944a0e 178B 工厂;
  vtable@0x11ad170 = {ZTI,unload,删析构,resolve,isLoaded},ZTI 链
  "18DynamicLibraryImpl"→"14DynamicLibrary"→"7Surface")—— **五重
  扫描零调用者**(E8/E9/LEA rip/绝对引用/xref_scan):机制存在未激活,
  无创建者无加载路径,定案(批 69 tr lane)

## 附:vendors/lrzsz 定性(2026-11-16 取证)

| 项 | 事实 |
|---|---|
| 内容 | 两个 **stripped ELF 可执行文件**:`rz`(76K)/ `sz`(80K)。**无源码** |
| 基线引用 | 二进制内串 `/vendors/lrzsz/sz`、`/vendors/lrzsz/rz`、`The lrzsz is not detected. Please install lrzsz first.` |
| 用法 | WindTerm **spawn 外部进程**跑 ZMODEM 传输;优先 `applicationDirPath()/vendors/lrzsz`,缺失则回退系统 lrzsz |
| 我方状态 | **未转写** —— `src/` 内无该路径引用;`ZModem` 类仅出现在 moc 名表,实现为零 |
| 结论 | **不进 `src/`**:它不是源码,是原版随包分发的运行时程序。保留 `vendors/` 与原版布局一致 |

> 待办:转写 spawn 腿时按上述优先级落地;`ZModem` 类(8 个 moc 名)需单独建模。

## 附:RunStyles / Bimap / SuperBuffer 族 —— 归 B 类,不逆向(2026-11-16 取证)

语料里有一整族 WindTerm 自有命名的类,函数体全部落到 Scintilla 的
RunStyles 语义上。判据不是"名字像",而是**调用点实读**:

| 语料函数 | 体量 | 实读到的调用 |
|---|---:|---|
| `CSuperBufferBase_ha62b28` | 49B | `runstyles_fill_range` / `runstyles_fill_value_range` |
| `CSuperBufferBase_h980580` | 76B | `FUN_00a63336` + `FUN_00926aa6`(样式区间写) |
| `CSuperBufferBase_h980616` | 80B | `FUN_00927a24` → `FUN_00927c04(...,6,1,1)` / `(...,4,0,1)` |

族成员(`coverage.py --ledger` 未触及池中的大户):
`CSuperBufferBase`(12条/2021B)、`CSuperBuffer32`(20/17925B)、
`CSuperBuffer64`(18/3503B)、`Uint8/16/32/64RunStyles`、
`Uint8/16/32/64SkipRunStyles`、`Uint32Bimap`、`ByteArrayBimap`、
`Uint64SkipRunStyles`(合计约 25 条以上的数百 KB)。

**处置:不逆向,按 `docs/calibration.md` 移植;实现委托仓库内已有的
`src/Scintilla/src/RunStyles.{h,cxx}`。** 依据是 AGENTS §10 —
"标准行为委托真库,fork 特性才逆向自研"。这一族没有 fork 独有的数据布局
(SGR 位/行格那种才是逆向范围),所以整族划到委托侧。

> 注意:`RunStyles` 在仓库快照里是**非模板类**,而二进制里是
> `Uint8/16/32/64` 四份实例化 —— 说明上游是模板化版本。移植时按
> Scintilla 上游模板版对齐,不要拿快照里的单版本硬套。

## 附:TextArrayData —— 同属 RunStyles 族,不逆向(2026-11-16 补登记)

`TextArrayData`(7 条 / 495B)初看是自研的文本存储类,但析构
(语料名 `TextArrayData_metaObject`,0x009c5d06,414B)首段就是:

```c
for (i = 0; i < runstyles_runs_count(param_1[6]); ++i) FUN_009c5cba(param_1, i);
...
param_1[5] = &Uint64RunStyles_vtable;
Uint32RunStyles_vt13(param_1 + 5);
```

判据与 `CSuperBufferBase` 完全一致(**调用点实读**,不是名字像):
`runstyles_runs_count` + `Uint64RunStyles_vtable` + `Uint32RunStyles_vt13`
⇒ 它就是 RunStyles 族的一员。

**处置:不逆向,按 `docs/calibration.md` 移植,实现委托
`src/Scintilla/src/RunStyles.{h,cxx}`。**

它的字段里还夹着一个 **0x28 的子件 + 0x30 的外壳**、以及 `+0x68` 的锁字节
(`*(char*)(param_1 + 0xd)` 配合自旋语义),这些都属于 RunStyles 内部实现,
不单独立项。
