cmake_minimum_required(VERSION 3.16)

project(WindTermGuiSkeleton LANGUAGES CXX)
# C 语言：opensource/src/Onigmo 是 C 源码，windterm_onigmo 静态库需要 C 编译器
enable_language(C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# 确定性双 Qt 探测：NAMES 习惯写法在双 Qt 共存系统上会被 Qt6 抢先，改为显式次序
find_package(Qt5 QUIET COMPONENTS Widgets)
if(Qt5_FOUND)
  set(QT_VERSION_MAJOR 5)
else()
  find_package(Qt6 QUIET COMPONENTS Widgets)
  set(QT_VERSION_MAJOR 6)
endif()
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
# F5 Telnet：QTcpSocket（TelnetSession）需 Network
find_package(Qt${QT_VERSION_MAJOR} QUIET COMPONENTS Network)
# F5 Serial：QSerialPort（SerialSession）需 SerialPort。不走 COMPONENTS——Qt5Config 的
# 组件子探测 PATHS NO_DEFAULT_PATH 只认系统前缀；独立 find_package 才吃 CMAKE_PREFIX_PATH。
# QUIET 可选：系统装了 qtserialport 才编 SerialSession（MainWindow 接线无条件编译）
find_package(Qt${QT_VERSION_MAJOR}SerialPort QUIET)

# P5 Filer 懒加载：QtConcurrent 后台列目录（Qt5/Qt6 均有 Concurrent 组件；缺则模型退同步路径）
find_package(Qt${QT_VERSION_MAJOR} QUIET COMPONENTS Concurrent)

# 任务二：statusbar.config 的 JS init 由 QJSEngine 真跑（0x005a3156 statusbar_runInit）。
# Qt5Qml（QJSEngine 跑 statusbar.config 的 JS；qtdeclarative5-dev 系统安装）
find_package(Qt5 QUIET COMPONENTS Qml)
if (TARGET Qt5::Qml)
  set(WINDTERM_HAVE_QJSENGINE ON)
  message(STATUS "Qt5Qml found: script statusbar enabled")
else()
  message(STATUS "Qt5Qml NOT found: script statusbar disabled (hardcoded fallback)")
endif()

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS src/*.h)

# Pty 层仅 Unix（macOS 的 Q_OS_UNIX 路径不参与，按 roadmap F1 限定 Linux/BSD）
if(NOT (UNIX AND NOT APPLE))
  list(FILTER PROJECT_SOURCES EXCLUDE REGEX "/src/pty/")
  list(FILTER PROJECT_HEADERS EXCLUDE REGEX "/src/pty/")
endif()
# SerialPort 组件缺失时 SerialSession 不参与编译（接线头文件探测保护）
if(NOT TARGET Qt${QT_VERSION_MAJOR}::SerialPort)
  list(FILTER PROJECT_SOURCES EXCLUDE REGEX "SerialSession")
  list(FILTER PROJECT_HEADERS EXCLUDE REGEX "SerialSession")
endif()

# ccache 可选：命中时清构建/换分支零重编（缺失自动跳过）
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
  set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()

# ═══ 核心静态库：项目源只编译一次 ═══
# 旧结构 TEST_SOURCES=PROJECT_SOURCES 让 32 个测试 target 各自重编全部源+moc
# （touch 一个 cpp 触发 33 目标×同文件重编）。改静态库后主程序/测试只链接。
set(LIB_SOURCES ${PROJECT_SOURCES} ${PROJECT_HEADERS})
list(FILTER LIB_SOURCES EXCLUDE REGEX "/src/main\\.cpp$")

add_library(windterm_core STATIC ${LIB_SOURCES})
# PUBLIC：include/Qt 链接/条件宏全部传递给主程序与各测试 target
target_include_directories(windterm_core PUBLIC src)
target_link_libraries(windterm_core PUBLIC Qt${QT_VERSION_MAJOR}::Widgets ${CMAKE_DL_LIBS})
if (TARGET Qt${QT_VERSION_MAJOR}::Network)
  target_link_libraries(windterm_core PUBLIC Qt${QT_VERSION_MAJOR}::Network)
endif()
if (TARGET Qt${QT_VERSION_MAJOR}::SerialPort)
  # src/MainWindow.cpp 的 reopen Serial 段无 #ifdef 守卫（仅 connect 段有）——
  # SerialPort 组件在系统上时必须携带 define+链接才能编过共享源
  target_compile_definitions(windterm_core PUBLIC WINDTERM_HAVE_SERIALPORT)
  target_link_libraries(windterm_core PUBLIC Qt${QT_VERSION_MAJOR}::SerialPort)
endif()
if (TARGET Qt${QT_VERSION_MAJOR}::Concurrent)
  target_compile_definitions(windterm_core PUBLIC WINDTERM_HAVE_CONCURRENT)
  target_link_libraries(windterm_core PUBLIC Qt${QT_VERSION_MAJOR}::Concurrent)
endif()
if (WINDTERM_HAVE_QJSENGINE)
  target_compile_definitions(windterm_core PUBLIC WINDTERM_HAVE_QJSENGINE)
  target_link_libraries(windterm_core PUBLIC Qt5::Qml)
endif()

add_executable(WindTermGuiSkeleton src/main.cpp)
target_link_libraries(WindTermGuiSkeleton PRIVATE windterm_core)

# ═══ opensource/src 真实代码合入（用户指令：开源件为真实实现，骨架只补闭源缺口）═══
# ODR 防线——opensource 库排除清单（与骨架 src/ 已 vendor 同物，双编必撞符号）：
#   - Protocols/TelnetProtocol.{h,cpp}+Protocol.h：与 src/protocols/ diff=0
#   - Widgets/Splitter.{h,cpp}：                    与 src/widgets/ diff=0
#   - Pty/UnixPty.{h,cpp}/Pty/{h,cpp}/Spin.h：      src/pty/ 为骨架增强版（QProcess::
#     splitCommand 参数修复等），以骨架为准
#   - libssh 整树：禁止编译链接——SshSession dlopen 原版修补版 libssh.so.4，
#     双实例符号冲突（参考用，不进任何 target）
#   - Pty/WinPty/ConPty：windows.h 平台排除（本工程仅 Linux/BSD）
# Utility/{Cryptographic,ThreadLocal}：依赖 QtNetwork qpassworddigestor / boost.thread，
#   Phase3 接线时按需再入库；本轮只带纯头+无 Qt 私有依赖件。

# ── windterm_opensource：Widgets + Utility 纯头（Phase1）──
set(OPENSOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/opensource/src)

add_library(windterm_opensource STATIC
  ${OPENSOURCE_DIR}/Widgets/ScrollBar.cpp
  ${OPENSOURCE_DIR}/Widgets/ScrollBar.h
  ${OPENSOURCE_DIR}/Widgets/PopupWidget.cpp
  ${OPENSOURCE_DIR}/Widgets/PopupWidget.h
  # Utility 纯头（无 Q_OBJECT，AUTOMOC 扫描过=零 moc 输出；挂 target 保 include 面可追溯）
  ${OPENSOURCE_DIR}/Utility/CircularBuffer.h
  ${OPENSOURCE_DIR}/Utility/MemoryPointer.h
  ${OPENSOURCE_DIR}/Utility/ScopeGuard.h
)
target_include_directories(windterm_opensource
  PUBLIC ${OPENSOURCE_DIR}/Utility ${OPENSOURCE_DIR}/Widgets
)
target_link_libraries(windterm_opensource PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

# PopupWidget.cpp include <private/qeffects_p.h>（qFadeEffect 淡入，上游一行未改）——
# 需 QtWidgets 私有头。正确取法是 Widgets config 传播的 Qt${V}Widgets_PRIVATE_INCLUDE_DIRS
# （含 Gui/Core 递归私有路径），不是 target 属性。变量空=qtbase private dev 未装→硬失败挂账。
if(NOT Qt${QT_VERSION_MAJOR}Widgets_PRIVATE_INCLUDE_DIRS)
  message(FATAL_ERROR
    "Qt${QT_VERSION_MAJOR}Widgets_PRIVATE_INCLUDE_DIRS is empty — "
    "qtbase${QT_VERSION_MAJOR}-private-dev (naming per distro) required for PopupWidget (qeffects_p.h)")
endif()
target_include_directories(windterm_opensource SYSTEM PRIVATE
  ${Qt${QT_VERSION_MAJOR}Widgets_PRIVATE_INCLUDE_DIRS}
)

# ── windterm_onigmo：终端高亮真引擎（Phase2）──
# config.h 生成：宏集逐项有编译报错依据（ablation 实测 2026-10-26，gcc 13.3 x86_64）：
#   HAVE_STDINT_H          缺→uintptr_t 未定义（st.h:9/regint.h:843，16 文件失败）
#   HAVE_STDARG_PROTOTYPES 缺→regerror.c 落 varargs.h 路径，GCC 已移除（fatal）
#   SIZEOF_INT 4           缺→INT_MAX_LIMIT 展开错误（regparse 等 2 文件失败）
#   SIZEOF_LONG 8          regint.h WORD_ALIGNMENT_SIZE 取值（x86_64；非对齐平台用
#                          PadBuf 对齐时必需，勿删）
#   STDC_HEADERS/HAVE_SYS_TYPES_H/HAVE_STDLIB_H/HAVE_STRING_H/HAVE_ALLOCA_H/
#   HAVE_STDARG_H/HAVE_PROTOTYPES          单删可编但落入 fallback 分支（strings.h/
#   alloca 探测/旧式声明），按 config.h.in 语义在 Linux 全开
set(ONIGMO_DIR ${OPENSOURCE_DIR}/Onigmo)
set(ONIGMO_CONFIG_H ${CMAKE_CURRENT_BINARY_DIR}/onigmo/config.h)
configure_file(tools/onigmo-config.h.in ${ONIGMO_CONFIG_H} @ONLY)

add_library(windterm_onigmo STATIC
  ${ONIGMO_DIR}/regerror.c   ${ONIGMO_DIR}/regparse.c  ${ONIGMO_DIR}/regext.c
  ${ONIGMO_DIR}/regcomp.c    ${ONIGMO_DIR}/regexec.c   ${ONIGMO_DIR}/regenc.c
  ${ONIGMO_DIR}/regsyntax.c  ${ONIGMO_DIR}/regtrav.c   ${ONIGMO_DIR}/regversion.c
  ${ONIGMO_DIR}/st.c
  ${ONIGMO_DIR}/reggnu.c     ${ONIGMO_DIR}/regposix.c  ${ONIGMO_DIR}/regposerr.c
  # enc 子集：unicode/ascii/utf8/utf16/utf32 + CJK/单字节（终端 TERM 面覆盖；
  # cp932.c #include "sjis.c" 复用 SJIS 表；koi8/koi8_r、euc_kr 同文件出 EUC_CN）
  ${ONIGMO_DIR}/enc/unicode.c ${ONIGMO_DIR}/enc/ascii.c  ${ONIGMO_DIR}/enc/utf8.c
  ${ONIGMO_DIR}/enc/utf16_le.c ${ONIGMO_DIR}/enc/utf16_be.c
  ${ONIGMO_DIR}/enc/utf32_le.c ${ONIGMO_DIR}/enc/utf32_be.c
  ${ONIGMO_DIR}/enc/euc_jp.c  ${ONIGMO_DIR}/enc/sjis.c   ${ONIGMO_DIR}/enc/cp932.c
  ${ONIGMO_DIR}/enc/gb18030.c ${ONIGMO_DIR}/enc/big5.c   ${ONIGMO_DIR}/enc/euc_kr.c
  ${ONIGMO_DIR}/enc/euc_tw.c  ${ONIGMO_DIR}/enc/koi8.c   ${ONIGMO_DIR}/enc/koi8_r.c
  ${ONIGMO_DIR}/enc/cp1251.c  ${ONIGMO_DIR}/enc/iso8859_1.c
)
target_include_directories(windterm_onigmo PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/onigmo ${ONIGMO_DIR} ${ONIGMO_DIR}/enc
)
target_include_directories(windterm_onigmo INTERFACE ${OPENSOURCE_DIR}/Onigmo)
# Onigmo 上游 C89 风格代码，本仓 gcc13 -Wall 面下仅 regparse.c 两条 unused 警告
# （pfetch_prev / i_free_shared_unicode_table，均为上游死代码路径）——压到零警告基线
target_compile_options(windterm_onigmo PRIVATE
  $<$<COMPILE_LANGUAGE:C>:-w>
)

# ── Onigmo 自检（Phase2）：真引擎 + triggers.config 真数据正则 + 与 QRegularExpression 语义差异留证 ──
add_executable(test_onigmo tests/test_onigmo.cpp)
target_link_libraries(test_onigmo PRIVATE windterm_onigmo windterm_opensource Qt${QT_VERSION_MAJOR}::Widgets)
add_test(NAME test_onigmo COMMAND test_onigmo)

# ═══ Tests（tests/ 回归集；CTest 接线）═══
enable_testing()

# 通用接线：只链 windterm_core（Qt 链接/宏/include 经 PUBLIC 传递）；
# 按需单独覆盖（SSH/serial 不注 HOME）
function(windterm_add_test name)
  add_executable(${name} tests/${name}.cpp)
  target_link_libraries(${name} PRIVATE windterm_core)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

function(windterm_test_offscreen name)
  set_tests_properties(${name} PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")
endfunction()

# 本地 bash 终端行为（无显示需要；工作目录=build，Assets 走 CWD/assets）
windterm_add_test(test_terminal_tui)
windterm_add_test(test_terminal_decckm)
windterm_add_test(test_terminal_mouse)

# 纯函数：colon SGR + 滚回上限
windterm_add_test(test_terminal_sgr)
windterm_test_offscreen(test_terminal_sgr)

# 0x005f5450 宽度区间表：边界向量 + 渲染级（宽字符 2 cell/换行/continuation）
windterm_add_test(test_charwidth)
windterm_test_offscreen(test_charwidth)

# 渲染像素断言：offscreen 平台必须
windterm_add_test(test_terminal_render)
windterm_test_offscreen(test_terminal_render)

# 增量行级重画：脏行跟踪+渲染等价（增量 grab==强制全量 grab），offscreen 必须
windterm_add_test(test_incremental_paint)
windterm_test_offscreen(test_incremental_paint)

# SSH 认证：自管 HOME（可写临时目录）+ 本机 sshd 127.0.0.1:22，缺则测试内 SKIP
windterm_add_test(test_ssh_auth)

# SSH keyboard-interactive：LoginAuthForm 结构/焦点/收集 + kbdint 两阶段状态机
# （fake libssh 表，无网络）；需 offscreen（QWidget/QLineEdit 焦点链）
windterm_add_test(test_ssh_kbdint)
windterm_test_offscreen(test_ssh_kbdint)

# SSH kbdint 真服务器端到端：tools/kbdint_server.py（asyncssh 两轮挑战）+ 完整
# connectFlow（探测信号→程序化 kbdintAnswer 回执→setanswer→终认→shell 回显）；
# python3/asyncssh 缺失则测试内 SKIP
windterm_add_test(test_ssh_kbdint_e2e)
windterm_test_offscreen(test_ssh_kbdint_e2e)

# 分屏/标签端到端：offscreen + 本地 bash
windterm_add_test(test_pane_split)
windterm_test_offscreen(test_pane_split)

# TabGroup 族五件（R45/R46/R47/TabListMenu/R50）：offscreen
windterm_add_test(test_tabgroup_family)
windterm_test_offscreen(test_tabgroup_family)

# SessionStore 写盘 round-trip：测试内自建 QTemporaryDir HOME
windterm_add_test(test_sessionstore)
windterm_test_offscreen(test_sessionstore)

# 对话框字段：offscreen
windterm_add_test(test_entryvalue)
windterm_test_offscreen(test_entryvalue)

# reopen.history round-trip：测试内 QTemporaryDir
windterm_add_test(test_reopen_roundtrip)
windterm_test_offscreen(test_reopen_roundtrip)

# 串口混型参数：需 SerialPort 组件（SerialSession 参编）；无组件则不编译
if (TARGET Qt${QT_VERSION_MAJOR}::SerialPort)
  windterm_add_test(test_serial_params)
  windterm_test_offscreen(test_serial_params)
endif()

# Shell args/workdir：本地 bash
windterm_add_test(test_shell_args)

# P3 命令面板：offscreen + MainWindow（无会话，宿主回退组容器）
windterm_add_test(test_command_palette)
windterm_test_offscreen(test_command_palette)

# P3 mode7 palette 文件模式：offscreen + MainWindow + bash（*.palette 一手证据链）
windterm_add_test(test_palette_mode)
windterm_test_offscreen(test_palette_mode)

# P4 终端搜索/高亮：offscreen + 本地 bash 已知文本（find/高亮/HighlightTextBar 链）
windterm_add_test(test_search_highlight)
windterm_test_offscreen(test_search_highlight)

# P5 Filer/SFTP：LocalFolder 过滤/字段+FileSystemModel 懒加载+FilerPane 本地页；
# sftp 端到端需本机 sshd 127.0.0.1:22 + key，缺则测试内嵌 SKIP
windterm_add_test(test_filer_sftp)
windterm_test_offscreen(test_filer_sftp)

# P6 传输引擎：SftpTransfer 上传/下载 round-trip+暂停/恢复、TransferCenter 行/事件/
# 0x617aea HTML、TransferBar 标签行、TransferPane 模型挂接；
# sftp 端到端需本机 sshd + key，缺则测试内嵌 SKIP
windterm_add_test(test_transfer)
windterm_test_offscreen(test_transfer)

# R55 statusbar applet 体系：7 项 JS init 真跑+AppletBar pane 装载链（offscreen）
windterm_add_test(test_statusbar_applets)
windterm_test_offscreen(test_statusbar_applets)

# 主题 R17 类名→骨架树改写文本断言（offscreen 必须）
windterm_add_test(test_theme_rewrites)
windterm_test_offscreen(test_theme_rewrites)

# 鼠标上报方言编码（0x7ebdfc 四形态分支照搬；纯函数无 IO）
windterm_add_test(test_mouse_dialects)

# P7a tmux 集成：解析单测必跑；真实 -CC 端到端系统缺 tmux 则测试内 SKIP
windterm_add_test(test_tmux_control)
windterm_test_offscreen(test_tmux_control)

# P7b MuxDesktop GUI 映射：真 tmux -CC 端到端（页/分屏树/激活/补屏/%exit 恢复），
# 系统缺 tmux 则测试内 SKIP
windterm_add_test(test_tmux_desktop)
windterm_test_offscreen(test_tmux_desktop)

# 五小对话框（NameDialog/PasteDialog/LogDialog/FocusModeDialog/WindowOpacityDialog）
# 结构+行为断言：offscreen + QTemporaryDir HOME
windterm_add_test(test_small_dialogs)
windterm_test_offscreen(test_small_dialogs)

# R51 设置中心：页树 8 顶层+子页枚举/选中切页/实页控件 WindConfig round-trip/Close 单钮（offscreen）
windterm_add_test(test_settings_dialog)
windterm_test_offscreen(test_settings_dialog)

# R52/R53/R54 菜单动作面：View Popup 节名/门卫/动态展开/Layout 开关/MergeToGroup 勾选/rename（offscreen）
windterm_add_test(test_menu_actions)
windterm_test_offscreen(test_menu_actions)
