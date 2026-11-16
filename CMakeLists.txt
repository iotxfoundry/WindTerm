cmake_minimum_required(VERSION 3.16)
project(WindTermRe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# =====================================================================
# 外部静态库:默认使用 lib/ 下已提交的 .a;仅 -DBUILD_DEPS=ON 时重编
# =====================================================================
set(LIB_OUT ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(SCINTILLA_CORE ${LIB_OUT}/libscintilla_core.a)
set(SCINTILLA_QT    ${LIB_OUT}/libscintilla_qt.a)
set(YAML_CPP       ${LIB_OUT}/libyaml-cpp.a)
set(JSONCPP        ${LIB_OUT}/libjsoncpp.a)
# 批 116:Onigmo 上游静态库(EXT-BOUNDARY 委托;src/Onigmo 同源树)。
# 预构建 lib/libonig.a 为非 PIC(带 debug 绝对重定位 + 数据符号 PC32 直
# 寻)— 直链 .so 报 "recompile with -fPIC"。构建时产出 PIC 化替身:
# 提取 → objcopy --strip-debug(去 debug 绝对域)→ 重归档;链接侧
# -Wl,-Bsymbolic 绑定数据符号 PC32(OnigDefaultCaseFoldFlag 等;
# 内部绑定语义对正则引擎无互插需求,同相)。替身落 build/(lib/ 只读)。
execute_process(
  COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/onigpic)
set(ONIG_PIC ${CMAKE_BINARY_DIR}/onigpic/libonigpic.a)
find_program(AR_EXEC ar REQUIRED)
find_program(OBJCOPY_EXEC objcopy REQUIRED)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/onigpic/obj)
add_custom_command(
  OUTPUT ${ONIG_PIC}
  COMMAND bash ${CMAKE_SOURCE_DIR}/tools/re/onigpic.sh
          ${CMAKE_BINARY_DIR}/onigpic ${AR_EXEC} ${OBJCOPY_EXEC} ${LIB_OUT}/libonig.a
  DEPENDS ${LIB_OUT}/libonig.a
  COMMENT "onig: PIC 化替身(strip-debug;批 116)"
  VERBATIM)
add_custom_target(onigpic ALL DEPENDS ${ONIG_PIC})
set(ONIG ${ONIG_PIC})

option(BUILD_DEPS "Rebuild external static libs from source" OFF)

if(BUILD_DEPS)
  # --- 从源码重编(仅首次/上游更新时) ---
  set(DEPS_BUILD ${CMAKE_BINARY_DIR}/deps)
  file(MAKE_DIRECTORY ${DEPS_BUILD})

  add_custom_command(
    OUTPUT ${DEPS_BUILD}/.stamp
    COMMAND ${CMAKE_COMMAND} -E echo ">>> Rebuilding external static libs from source..."

    # Scintilla core
    COMMAND bash -c "cd ${DEPS_BUILD} && mkdir -p sci && cd sci && ${CMAKE_CXX_COMPILER} -std=c++17 -fPIC -c ${CMAKE_SOURCE_DIR}/src/Scintilla/src/*.cxx ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib/*.cxx ${CMAKE_SOURCE_DIR}/src/Scintilla/lexers/*.cxx -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/src -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib 2>&1 | grep -v 'error' | head -5; ar rcs ${LIB_OUT}/libscintilla_core.a *.o"

    # Scintilla Qt binding
    COMMAND /usr/lib/qt5/bin/moc ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaEditBase.h -o ${DEPS_BUILD}/moc_ScintillaEditBase.cpp -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib
    COMMAND /usr/lib/qt5/bin/moc ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaQt.h -o ${DEPS_BUILD}/moc_ScintillaQt.cpp -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib
    COMMAND bash -c "cd ${DEPS_BUILD} && ${CMAKE_CXX_COMPILER} -std=c++17 -fPIC -c moc_ScintillaEditBase.cpp moc_ScintillaQt.cpp ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/PlatQt.cpp ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaEditBase.cpp ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaQt.cpp -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/src -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib -I /usr/include/x86_64-linux-gnu/qt5 -I /usr/include/x86_64-linux-gnu/qt5/QtCore -I /usr/include/x86_64-linux-gnu/qt5/QtGui -I /usr/include/x86_64-linux-gnu/qt5/QtWidgets && ar rcs ${LIB_OUT}/libscintilla_qt.a moc_ScintillaEditBase.o moc_ScintillaQt.o PlatQt.o ScintillaEditBase.o ScintillaQt.o"

    # yaml-cpp
    COMMAND bash -c "cd ${DEPS_BUILD} && mkdir -p ycpp && cd ycpp && ${CMAKE_CXX_COMPILER} -std=c++11 -fPIC -O2 -I ${CMAKE_SOURCE_DIR}/src/yaml-cpp/include -c ${CMAKE_SOURCE_DIR}/src/yaml-cpp/src/*.cpp && ar rcs ${LIB_OUT}/libyaml-cpp.a *.o"

    # jsoncpp
    COMMAND bash -c "cd ${DEPS_BUILD} && mkdir -p jcpp && cd jcpp && ${CMAKE_CXX_COMPILER} -std=c++11 -fPIC -O2 -I ${CMAKE_SOURCE_DIR}/src/jsoncpp/include -c ${CMAKE_SOURCE_DIR}/src/jsoncpp/src/lib_json/*.cpp && ar rcs ${LIB_OUT}/libjsoncpp.a *.o"

    COMMAND ${CMAKE_COMMAND} -E touch ${DEPS_BUILD}/.stamp
    COMMENT "Rebuilding Scintilla + yaml-cpp + jsoncpp from source into lib/"
    VERBATIM)
  add_custom_target(rebuild_deps DEPENDS ${DEPS_BUILD}/.stamp)

else()
  # --- 默认:检查 lib/ 下的 .a 是否存在 ---
  foreach(lib ${SCINTILLA_CORE} ${SCINTILLA_QT} ${YAML_CPP} ${JSONCPP})
    if(NOT EXISTS ${lib})
      message(FATAL_ERROR
        "Missing pre-built library: ${lib}\n"
        "Run: cmake .. -DBUILD_DEPS=ON && make rebuild_deps\n"
        "Or build manually per tools/re/BUILD.md")
    endif()
  endforeach()
  if(NOT EXISTS ${LIB_OUT}/libonig.a)
    message(FATAL_ERROR "Missing pre-built library: ${LIB_OUT}/libonig.a")
  endif()
  add_custom_target(rebuild_deps SOURCES "")
endif()

# =====================================================================
# Qt 查找
# =====================================================================
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network Qml Svg)

# =====================================================================
# WindTerm 重建库(libWindTermRe.so)
# =====================================================================
set(WT_INCLUDES
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/src/Sessions
  ${CMAKE_SOURCE_DIR}/src/Editor
  ${CMAKE_SOURCE_DIR}/src/Widgets
  ${CMAKE_SOURCE_DIR}/src/Protocols
  ${CMAKE_SOURCE_DIR}/src/Utility
  ${CMAKE_SOURCE_DIR}/src/Scintilla/include
  ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase
  ${CMAKE_SOURCE_DIR}/src/Scintilla/src
  ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib
  ${CMAKE_SOURCE_DIR}/src/yaml-cpp/include
  ${CMAKE_SOURCE_DIR}/src/jsoncpp/include
  ${CMAKE_SOURCE_DIR}/src/libssh/include
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Gui_INCLUDE_DIRS}
  ${Qt5Network_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5Qml_INCLUDE_DIRS}
  ${Qt5Svg_INCLUDE_DIRS}
)

# --- 源文件(按目录自动收集,新文件零配置) ---
file(GLOB_RECURSE WT_SOURCES
  ${CMAKE_SOURCE_DIR}/src/Actions/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Sessions/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Editor/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Widgets/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Protocols/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Utility/*.cpp
)
if(UNIX)
  list(APPEND WT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/Pty/Pty.cpp
    ${CMAKE_SOURCE_DIR}/src/Pty/UnixPty.cpp
  )
endif()

file(GLOB WT_MOC_HEADERS
  ${CMAKE_SOURCE_DIR}/src/Actions/*.h
  ${CMAKE_SOURCE_DIR}/src/Editor/*.h
  ${CMAKE_SOURCE_DIR}/src/Sessions/*.h
  ${CMAKE_SOURCE_DIR}/src/Widgets/*.h
  ${CMAKE_SOURCE_DIR}/src/Protocols/*.h
  ${CMAKE_SOURCE_DIR}/src/Pty/Pty.h
  ${CMAKE_SOURCE_DIR}/src/Pty/ShellProcess.h
  ${CMAKE_SOURCE_DIR}/src/Pty/UnixPty.h
)
# 只有含 Q_OBJECT 的头需要 moc
set(WT_MOC_LIST "")
foreach(hdr ${WT_MOC_HEADERS})
  file(READ ${hdr} hdr_content)
  if(hdr_content MATCHES "Q_OBJECT")
    list(APPEND WT_MOC_LIST ${hdr})
  endif()
endforeach()
qt5_wrap_cpp(WT_MOC_SOURCES ${WT_MOC_LIST})

add_library(WindTermRe SHARED ${WT_SOURCES} ${WT_MOC_SOURCES})
# 批 151:spdlog 真库委托面(src/Ext/SpdlogFace.h)→ TU 局部 -I
# (全局路径与 Scintilla/Qt 头冲突,CMakeLists 前注判例)
set_source_files_properties(${CMAKE_SOURCE_DIR}/src/Sessions/SuperSessionPrivate.cpp
    PROPERTIES COMPILE_OPTIONS "-I${CMAKE_SOURCE_DIR}/src/spdlog/include;-I${CMAKE_SOURCE_DIR}/src/fmt/include")
set_target_properties(WindTermRe PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
  OUTPUT_NAME WindTermRe
  BUILD_RPATH_USE_ORIGIN TRUE)   # 防 repo lib/ 污染 RUNPATH(Phase 5)

target_include_directories(WindTermRe PRIVATE ${WT_INCLUDES} ${CMAKE_SOURCE_DIR}/src/Onigmo ${CMAKE_SOURCE_DIR}/src/spdlog/include ${CMAKE_SOURCE_DIR}/src/fmt/include)
# 静态嵌入库源码树(src/spdlog|fmt|dtl)已在 src/ 归位(header-only);
# 不加全局 include——调用点转写时按 TU 局部 -I 接线(全局路径会
# 与 Scintilla/Qt 头冲突,实测 6k 错)
target_link_libraries(WindTermRe
  Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network Qt5::Qml Qt5::Svg
  ${SCINTILLA_QT} ${SCINTILLA_CORE}
  ${YAML_CPP} ${JSONCPP}
  ${ONIG} -Wl,-Bsymbolic
  ${LIB_OUT}/libssh.so.4
)
add_dependencies(WindTermRe rebuild_deps onigpic)

# tests/ 已于批 493 后按用户令删除(工作重心转向逆向代码落地,不编译不测试)
# 去 RUNPATH(repo lib/ 的 Qt5Network 版本符号与系统 Qt 冲突,
# 会污染测试/宿主链接——Phase 5)
add_custom_command(TARGET WindTermRe POST_BUILD
    COMMAND patchelf --remove-rpath $<TARGET_FILE:WindTermRe> || true)
