# BSim 开源参考库构建（R28 管线第一步）——编译 WindTerm 开源可编译集为带符号 so，
# 供 tools/BSimApply.java 生成签名入库。依赖：qmake(Qt5) + libboost-dev + qtbase5-private-dev
# 开源源码位置（本仓库的同门开源仓 /home/pana/go/src/github.com/kingtoolbox/WindTerm），
# 可用环境变量 WINDTERM_SRC 覆盖
isEmpty(WINDTERM_SRC): WINDTERM_SRC = /home/pana/go/src/github.com/kingtoolbox/WindTerm/src

TEMPLATE = lib
TARGET = windtermopen
QT += widgets network widgets-private
CONFIG += debug
INCLUDEPATH += $$PWD $$WINDTERM_SRC/Pty \
  $$[QT_INSTALL_HEADERS]/QtWidgets/$$[QT_VERSION]/QtWidgets \
  $$[QT_INSTALL_HEADERS]/QtCore/$$[QT_VERSION]/QtCore
SOURCES += $$WINDTERM_SRC/Protocols/TelnetProtocol.cpp \
 $$WINDTERM_SRC/Utility/Cryptographic.cpp $$WINDTERM_SRC/Utility/ThreadLocal.cpp \
 $$WINDTERM_SRC/Widgets/PopupWidget.cpp $$WINDTERM_SRC/Widgets/ScrollBar.cpp $$WINDTERM_SRC/Widgets/Splitter.cpp
HEADERS += $$WINDTERM_SRC/Protocols/Protocol.h $$WINDTERM_SRC/Protocols/TelnetProtocol.h \
 $$WINDTERM_SRC/Utility/CircularBuffer.h $$WINDTERM_SRC/Utility/Cryptographic.h $$WINDTERM_SRC/Utility/MemoryPointer.h $$WINDTERM_SRC/Utility/ScopeGuard.h $$WINDTERM_SRC/Utility/ThreadLocal.h \
 $$WINDTERM_SRC/Widgets/PopupWidget.h $$WINDTERM_SRC/Widgets/ScrollBar.h $$WINDTERM_SRC/Widgets/Splitter.h

# Public/Spin.h 为原版 Public/<路径> 的 shim 拷贝（源: 开源仓库 src/Utility/Spin.h, Apache-2.0）
# 编译产物仅作 BSim 特征参考库，不入发行物
