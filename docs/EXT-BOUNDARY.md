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

## 动态库直接调用接口(2026-10-31 勘定,导出表交集法)

主二进制 NEEDED = 10 动态库;PLT 直接调用 ≈3270 符号(交集法精确计数):

| 库 | 符号数 | 结论 |
|---|---|---|
| Qt5Widgets/Core/Gui/Network | 1535/1052/371/91 | 委托真库(既有策略)|
| **libssh.so.4** | **117**(sftp_async_* 47 全套)| SSH-INTERNALS 委托边界精确到符号清单;TLS 走 libssh(libssl 交集=0)|
| **libQt5Qml** | **45 = QJSEngine 全家** | **JsEngine 底座钉死:动态 QJSEngine 真库,零逆向**(CALIBRATION 落定)|
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
