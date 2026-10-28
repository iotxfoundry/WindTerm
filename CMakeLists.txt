cmake_minimum_required(VERSION 3.16)
project(WindTermRe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# =====================================================================
# 外部静态库:预构建一次,改代码不重编(除非 --fresh)
# =====================================================================
set(LIB_OUT ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(PREBUILT_DIR ${CMAKE_BINARY_DIR}/prebuilt)

# --- 预构建脚本(首次 cmake --build 时跑,之后跳过) ---
file(MAKE_DIRECTORY ${PREBUILT_DIR})
add_custom_command(
  OUTPUT ${PREBUILT_DIR}/.stamp
  COMMAND ${CMAKE_COMMAND} -E echo ">>> Pre-building external static libs..."
  # Scintilla core (154 objects)
  COMMAND bash -c "cd ${PREBUILT_DIR} && ${CMAKE_CXX_COMPILER} -std=c++17 -fPIC -c ${CMAKE_SOURCE_DIR}/src/Scintilla/src/*.cxx ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib/*.cxx ${CMAKE_SOURCE_DIR}/src/Scintilla/lexers/*.cxx -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/src -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib 2>/dev/null && ${CMAKE_CXX_COMPILER} -std=c++17 -fPIC -c ${CMAKE_SOURCE_DIR}/src/Scintilla/src/ExternalLexer.cxx -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/src 2>/dev/null; ar rcs libscintilla_core.a *.o"
  # Scintilla Qt binding
  COMMAND /usr/lib/qt5/bin/moc ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaEditBase.h -o ${PREBUILT_DIR}/moc_ScintillaEditBase.cpp -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib
  COMMAND /usr/lib/qt5/bin/moc ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaQt.h -o ${PREBUILT_DIR}/moc_ScintillaQt.cpp -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -fPIC -c ${PREBUILT_DIR}/moc_ScintillaEditBase.cpp -o ${PREBUILT_DIR}/moc_ScintillaEditBase.o -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/src -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib -I /usr/include/x86_64-linux-gnu/qt5 -I /usr/include/x86_64-linux-gnu/qt5/QtCore -I /usr/include/x86_64-linux-gnu/qt5/QtGui -I /usr/include/x86_64-linux-gnu/qt5/QtWidgets
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -fPIC -c ${PREBUILT_DIR}/moc_ScintillaQt.cpp -o ${PREBUILT_DIR}/moc_ScintillaQt.o -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/src -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib -I /usr/include/x86_64-linux-gnu/qt5 -I /usr/include/x86_64-linux-gnu/qt5/QtCore -I /usr/include/x86_64-linux-gnu/qt5/QtGui -I /usr/include/x86_64-linux-gnu/qt5/QtWidgets
  COMMAND bash -c "cd ${PREBUILT_DIR} && ${CMAKE_CXX_COMPILER} -std=c++17 -fPIC -c ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/PlatQt.cpp ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaEditBase.cpp ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase/ScintillaQt.cpp -I ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase -I ${CMAKE_SOURCE_DIR}/src/Scintilla/src -I ${CMAKE_SOURCE_DIR}/src/Scintilla/include -I ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib -I /usr/include/x86_64-linux-gnu/qt5 -I /usr/include/x86_64-linux-gnu/qt5/QtCore -I /usr/include/x86_64-linux-gnu/qt5/QtGui -I /usr/include/x86_64-linux-gnu/qt5/QtWidgets && ar rcs libscintilla_qt.a ScintillaEditBase.o ScintillaQt.o PlatQt.o moc_ScintillaEditBase.o moc_ScintillaQt.o"
  # yaml-cpp static
  COMMAND bash -c "cd ${PREBUILT_DIR} && mkdir -p ycpp && cd ycpp && ${CMAKE_CXX_COMPILER} -std=c++11 -fPIC -O2 -I ${CMAKE_SOURCE_DIR}/src/yaml-cpp/include -c ${CMAKE_SOURCE_DIR}/src/yaml-cpp/src/*.cpp && ar rcs ../libyaml-cpp.a *.o"
  # jsoncpp static
  COMMAND bash -c "cd ${PREBUILT_DIR} && mkdir -p jcpp && cd jcpp && ${CMAKE_CXX_COMPILER} -std=c++11 -fPIC -O2 -I ${CMAKE_SOURCE_DIR}/src/jsoncpp/include -c ${CMAKE_SOURCE_DIR}/src/jsoncpp/src/lib_json/*.cpp && ar rcs ../libjsoncpp.a *.o"
  COMMAND ${CMAKE_COMMAND} -E touch ${PREBUILT_DIR}/.stamp
  COMMENT "Pre-building Scintilla + yaml-cpp + jsoncpp (first time only)"
  VERBATIM)
add_custom_target(prebuilt_deps DEPENDS ${PREBUILT_DIR}/.stamp)

# --- 预构建静态库路径 ---
set(SCINTILLA_CORE ${PREBUILT_DIR}/libscintilla_core.a)
set(SCINTILLA_QT    ${PREBUILT_DIR}/libscintilla_qt.a)
set(YAML_CPP       ${PREBUILT_DIR}/libyaml-cpp.a)
set(JSONCPP        ${PREBUILT_DIR}/libjsoncpp.a)

# =====================================================================
# libssh:共享库(保留原 CMakeLists 子项目方式)
# =====================================================================
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(BUILD_STATIC_LIBS OFF CACHE BOOL "" FORCE)
set(WITH_EXAMPLES OFF CACHE BOOL "" FORCE)
set(UNIT_TESTING OFF CACHE BOOL "" FORCE)
# add_subdirectory(src/libssh)  # 注释掉:使用 lib/libssh.so.4(仓库预构建)

# =====================================================================
# Qt 查找
# =====================================================================
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network)

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
  ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5Network_INCLUDE_DIRS}
)

# --- 源文件(按目录自动收集,新文件零配置) ---
file(GLOB_RECURSE WT_SOURCES
  ${CMAKE_SOURCE_DIR}/src/Sessions/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Editor/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Widgets/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Protocols/*.cpp
  ${CMAKE_SOURCE_DIR}/src/Utility/*.cpp
)
file(GLOB WT_MOC_HEADERS
  ${CMAKE_SOURCE_DIR}/src/Sessions/*.h
  ${CMAKE_SOURCE_DIR}/src/Widgets/*.h
  ${CMAKE_SOURCE_DIR}/src/Protocols/*.h
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
set_target_properties(WindTermRe PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
  OUTPUT_NAME WindTermRe)

target_include_directories(WindTermRe PRIVATE ${WT_INCLUDES})
target_link_libraries(WindTermRe
  Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network
  ${SCINTILLA_QT} ${SCINTILLA_CORE}
  ${YAML_CPP} ${JSONCPP}
  ${LIB_OUT}/libssh.so.4
)
add_dependencies(WindTermRe prebuilt_deps)

# =====================================================================
# 测试目标(可选)
# =====================================================================
# engtest 可选(主库完整;测试用 cmake --build . --target engtest)
if(BUILD_ENGTEST)
  add_executable(engtest tools/re/metatest/engtest.cpp
    tools/re/metatest/metahook.cpp)
  target_include_directories(engtest PRIVATE ${WT_INCLUDES})
  target_link_libraries(engtest WindTermRe ${SCINTILLA_QT} ${SCINTILLA_CORE} Qt5::Core Qt5::Gui Qt5::Widgets)
  set_target_properties(engtest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
