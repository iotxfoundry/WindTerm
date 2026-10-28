# 冒烟测试源

| 文件 | 验证 |
|---|---|
| engtest.cpp | 编辑引擎混合层(ADDTEXT→GETLENGTH、SELECTALL) |
| engtest2.cpp | tabSize/indexOf 抽查 |
| engtest3.cpp | TerminalView 离屏渲染(格子→像素、viewWrite 通道、resize) |
| sshsmoke.cpp | libssh 认证族探针 |
| scismoke.cpp | Scintilla 静态库命令号 |
| recheck.cpp | 数据表+键哈希抽查(宽度表 7 例 / 字符集 6 例 / 属性键 2 例) |

构建(recheck 例):
```bash
g++ -std=c++17 -fPIC -o recheck recheck.cpp \
  -I src/Sessions -I src/Editor -I src/Widgets -I src/Protocols -I src/Utility -I src \
  -I src/Scintilla/include -I src/Scintilla/qt/ScintillaEditBase \
  -I src/Scintilla/src -I src/Scintilla/lexlib \
  -I src/yaml-cpp/include -I src/jsoncpp/include -I src/libssh/include \
  -I /usr/include/x86_64-linux-gnu/qt5/{,QtCore,QtGui,QtWidgets} \
  -L<build> -lWindTermRe -lQt5Core -lQt5Gui -lQt5Widgets -lssh
LD_LIBRARY_PATH=<build> QT_QPA_PLATFORM=offscreen ./recheck
```
| engtest4.cpp | Phase 5 对称 dump(writeText→格子 JSON,对比原版) |
