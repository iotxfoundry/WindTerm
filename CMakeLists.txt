cmake_minimum_required(VERSION 3.16)

project(WindTermGuiSkeleton LANGUAGES CXX)

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

add_executable(WindTermGuiSkeleton ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(WindTermGuiSkeleton PRIVATE src)
target_link_libraries(WindTermGuiSkeleton PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${CMAKE_DL_LIBS})
if (TARGET Qt${QT_VERSION_MAJOR}::Network)
  target_link_libraries(WindTermGuiSkeleton PRIVATE Qt${QT_VERSION_MAJOR}::Network)
endif()
if (TARGET Qt${QT_VERSION_MAJOR}::SerialPort)
  target_compile_definitions(WindTermGuiSkeleton PRIVATE WINDTERM_HAVE_SERIALPORT)
  target_link_libraries(WindTermGuiSkeleton PRIVATE Qt${QT_VERSION_MAJOR}::SerialPort)
endif()
if (WINDTERM_HAVE_QJSENGINE)
  target_compile_definitions(WindTermGuiSkeleton PRIVATE WINDTERM_HAVE_QJSENGINE)
  target_link_libraries(WindTermGuiSkeleton PRIVATE Qt5::Qml)
endif()

# ═══ Tests（tests/ 回归集；CTest 接线）═══
enable_testing()

# 与主 target 同样的源过滤：pty 仅 Unix、SerialSession 依赖 SerialPort 组件
# HEADERS 必须一并带上：AUTOMOC 按 target 源/头清单决定为哪些 Q_OBJECT 头生成 moc_*；
# 少了 Session.h 等纯接口头 → 子类 moc 引用其 qt_metacall 链接失败
set(TEST_SOURCES ${PROJECT_SOURCES} ${PROJECT_HEADERS})
list(FILTER TEST_SOURCES EXCLUDE REGEX "/src/main\\.cpp$")

# 通用接线：include src、复用主项目条件链接与宏；按需单独覆盖（SSH/serial 不注 HOME）
function(windterm_add_test name)
  add_executable(${name} tests/${name}.cpp ${TEST_SOURCES})
  target_include_directories(${name} PRIVATE src)
  target_link_libraries(${name} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${CMAKE_DL_LIBS})
  if (TARGET Qt${QT_VERSION_MAJOR}::Network)
    target_link_libraries(${name} PRIVATE Qt${QT_VERSION_MAJOR}::Network)
  endif()
  # src/MainWindow.cpp 的 reopen Serial 段无 #ifdef 守卫（仅 connect 段有）——
  # SerialPort 组件在系统上时测试 target 必须同样携带 define+链接才能编过共享源
  if (TARGET Qt${QT_VERSION_MAJOR}::SerialPort)
    target_compile_definitions(${name} PRIVATE WINDTERM_HAVE_SERIALPORT)
    target_link_libraries(${name} PRIVATE Qt${QT_VERSION_MAJOR}::SerialPort)
  endif()
  if (WINDTERM_HAVE_QJSENGINE)
    target_compile_definitions(${name} PRIVATE WINDTERM_HAVE_QJSENGINE)
    target_link_libraries(${name} PRIVATE Qt5::Qml)
  endif()
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

# 渲染像素断言：offscreen 平台必须
windterm_add_test(test_terminal_render)
windterm_test_offscreen(test_terminal_render)

# SSH 认证：自管 HOME（可写临时目录）+ 本机 sshd 127.0.0.1:22，缺则测试内 SKIP
windterm_add_test(test_ssh_auth)

# 分屏/标签端到端：offscreen + 本地 bash
windterm_add_test(test_pane_split)
windterm_test_offscreen(test_pane_split)

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
