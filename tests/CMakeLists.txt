# 行为门测试(每轮提交门;ctest 集成,封装 bundled Qt 运行环境)
# 序列/驱动资产:tools/re/phase5/(phase5_dump.py + phase5_seq.json)

set(TEST_ENV
  "LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}:/opt/WindTerm_2.7.0/lib"
  "QT_PLUGIN_PATH=/opt/WindTerm_2.7.0/lib"
  "QT_QPA_PLATFORM=offscreen"
)

foreach(t e2eterm recheck engtest engtest2 engtest3 engtest4 keymap_test telnet_test pty_test shellsession_test)
  add_executable(${t} ${t}.cpp)
  target_include_directories(${t} PRIVATE
    ${CMAKE_SOURCE_DIR}/src/Sessions
    ${CMAKE_SOURCE_DIR}/src/Editor
    ${CMAKE_SOURCE_DIR}/src/Widgets
    ${CMAKE_SOURCE_DIR}/src/Protocols
    ${CMAKE_SOURCE_DIR}/src/Utility
    ${CMAKE_SOURCE_DIR}/src/Pty
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/Scintilla/include
    ${CMAKE_SOURCE_DIR}/src/Scintilla/qt/ScintillaEditBase
    ${CMAKE_SOURCE_DIR}/src/Scintilla/src
    ${CMAKE_SOURCE_DIR}/src/Scintilla/lexlib
    ${CMAKE_SOURCE_DIR}/src/yaml-cpp/include
    ${CMAKE_SOURCE_DIR}/src/jsoncpp/include
    ${CMAKE_SOURCE_DIR}/src/libssh/include
  )
  target_link_libraries(${t} WindTermRe Qt5::Core Qt5::Gui Qt5::Widgets ssh)
  add_test(NAME ${t} COMMAND ${t})
  set_tests_properties(${t} PROPERTIES
    ENVIRONMENT "${TEST_ENV}"
    TIMEOUT 60)
endforeach()
