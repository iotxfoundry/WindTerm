# EXT-BOUNDARY — 外部库接口边界(不逆向实现)

> 原则:原版静态嵌入的开源库,其**实现不逆向**。转写中命中下列
> 命名空间/行为特征 → 标记为外库边界,只转写 WindTerm 侧的调用
> 接口面;行为由接口层(委托真库或 no-op sink)承接。
> 依据:docs/BUILD-AUDIT.md(嵌入审计)。

## 边界注册表

| 库 | 证据(原版) | 符号/行为特征 | 边界面 |
|---|---|---|---|
| boost 1.78.0 | 大量 xpressive/线程符号 + 版本串 | `boost::xpressive`、`boost::condition_variable`… | 正则面转写时补(未及) |
| yaml-cpp 0.7.0 | 构建路径串 | `YAML::` | 委托真库(ConfigBridge 已接) |
| jsoncpp | `Json::Value` | `Json::` | 委托真库(已接) |
| dtl | `N3dtl…` 符号 | `dtl::Sequence/Lcs/Diff3` | diff 面转写时补 |
| zstd | `ZSTD_trace_*` | `ZSTD_*` | 压缩面转写时补 |
| spdlog/fmt | 特征串(0 符号,可见性隐藏) | 日志 sink 行为、`fmt::format` | **src/Ext/**(已建接口层) |
| ICU 56 | lib/icudata.so.56 动态捆绑 | 运行时动态库 | 不需接口(动态加载) |
| glib/gtk/X11/alsa/pulse/gstreamer/dbus | 动态系统栈 | 运行时动态库 | 不需接口 |

## 第一方开源组件(2026-10-29 新增,见 docs/CALIBRATION.md)

src/ 本就包含官方开源的 6 个第一方组件(TelnetProtocol/Pty/Utility/
Widgets/libssh-改/Onigmo-改,Apache-2.0;勿重复 clone)——**对应子系统停止逆向,
改为移植/校准**。终端核心不在其中 = 逆向边界的权威确认。

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
