# BUILD.md — WindTerm 构建详解

## 快速构建(clone 后直接)

```bash
mkdir build && cd build
cmake .. && make -j$(nproc)
ls libWindTermRe.so    # 8.82MB
```

**增量:0.08s**(无改动时仅 stamp 检查)。
**改 1 个 .cpp:~1.3s**(1 编 + 1 链)。

## CMake 选项

| 选项 | 默认 | 说明 |
|---|---|---|
| BUILD_DEPS | OFF | 重编外部静态库(Scintilla+yaml-cpp+jsoncpp)到 lib/*.a |
| BUILD_ENGTEST | OFF | 编译编辑引擎测试二进制 |

## 构建架构

```
prebuilt_deps   ← Scintilla core(155 obj)+ Qt 绑定(3 cpp+2 moc)
                  + yaml-cpp + jsoncpp → lib/*.a(20MB 静态库)
WindTermRe      ← src/{Sessions,Editor,Widgets,Protocols,Utility}/*.cpp
                  + moc(自动检测 Q_OBJECT 头)→ libWindTermRe.so
engtest         ← 编辑引擎混合层测试(可选)
```

外部静态库**首次构建后入 lib/ 提交**,clone 后 CMake 检查 `.a` 存在
即直接链接,不重编。上游更新时 `cmake .. -DBUILD_DEPS=ON && make rebuild_deps`。

## 手工编译(不走 CMake)

```bash
B=/tmp/build; W=$(pwd); Q=/usr/include/x86_64-linux-gnu/qt5
mkdir $B && cd $B

# moc
for h in $(grep -l Q_OBJECT $W/src/Sessions/*.h $W/src/Widgets/*.h $W/src/Protocols/*.h); do
  /usr/lib/qt5/bin/moc $h -o moc_$(basename $h .h).cpp
done

# 链接符号(发行库无 .so 开发名)
for l in Qt5Core Qt5Gui Qt5Widgets Qt5Network; do ln -sf $W/lib/lib$l.so.5 $B/lib$l.so; ln -sf $W/lib/lib$l.so.5 $B/lib$l.so.5; done
for so in libssh.so.4 libicui18n.so.56 libicuuc.so.56 libicudata.so.56 libcrypto.so.1.1 libssl.so.1.1; do ln -sf $W/lib/$so $B/$so; done

# 编译
g++ -std=c++17 -fPIC -shared -o libWindTermRe.so \
  $W/src/Sessions/*.cpp $W/src/Editor/*.cpp $W/src/Widgets/*.cpp $W/src/Protocols/*.cpp \
  $W/src/Utility/*.cpp moc_*.cpp \
  -I $W/src/Sessions -I $W/src/Editor -I $W/src/Widgets -I $W/src/Protocols -I $W/src/Utility -I $W/src \
  -I $W/src/Scintilla/include -I $W/src/Scintilla/qt/ScintillaEditBase -I $W/src/Scintilla/src -I $W/src/Scintilla/lexlib \
  -I $W/src/yaml-cpp/include -I $W/src/jsoncpp/include -I $W/src/libssh/include \
  -I $Q -I $Q/QtCore -I $Q/QtGui -I $Q/QtWidgets -I $Q/QtNetwork \
  -L$B -lQt5Core -lQt5Gui -lQt5Widgets -lQt5Network -lssh \
  -lscintilla_qt -lscintilla_core -lyaml-cpp -ljsoncpp
```

## 环境

| 项 | 值 |
|---|---|
| 系统 Qt 头 | /usr/include/x86_64-linux-gnu/qt5(5.15.13) |
| 链接库 | 仓库 lib/(Qt 5.15.2 + libssh.so.4 + Scintilla/yaml/json .a) |
| moc | /usr/lib/qt5/bin/moc(系统 5.15.13) |
| inc/qt5 | **已删除**(转发头不可用,用系统头) |
| inc/boost | **已删除**(不完整副本,用系统 boost 1.83) |
| inc/openssl | 保留(1.1.1 头配 lib/libcrypto.so.1.1) |

## 已知边界

- PopupWidget 的 qFadeEffect:本地 inline 桩(装饰性动画);qtbase
  源码联编时换回 `#include <private/qeffects_p.h>`
- Screen/TextView 壳类无 Q_OBJECT(信号经 SuperCommander 侧)

## 第三方静态打包审计(2026-10-28,主二进制字符串证据)

**动态链接**(NEEDED):libssh/crypto/ssl + Qt 全家(Qt5SerialPort 新发现!)
+ X11/Xtst/GL —— 对应 inc/ 的运行时依赖头(版本配套,保留)。

**静态打包确凿**(主二进制内特征串实证):
| 库 | 证据 | 处置 |
|---|---|---|
| spdlog(+fmt 后端) | mangled `N6spdlog9spdlog_exE` + 全 sink 串 ×7 + format_error ×3 | **已含头即源**(header-only),inc/spdlog+fmt 保留 |
| jsoncpp 1.9.4 | 20 串;源码串命中 69/278 | **已引入 src/jsoncpp**,libjsoncpp.a(438KB)冒烟通过 |
| yaml-cpp 0.6.3 | `error at line` ×19;源码串命中 **56/114(49%)** | **已引入 src/yaml-cpp**,libyaml-cpp.a(923KB)冒烟通过 |

**零证据判否**:boost::thread(0 串)/xxhash/btree/dtl —— 原删除决定追加确证。

## Scintilla 静态库(src/Scintilla = 上游 4.4.6)

版本钉死:原 bundled 头与上游 4.4.6 的 API 逐行零 diff。

双静态库:libscintilla_core.a(16.5MB,155 obj)+ libscintilla_qt.a(646KB)。
冒烟实证:离屏 QApplication 下 `ADDTEXT("hello") → GETLENGTH = 5`——
静态库响应的正是从 WindTerm 二进制逆向出的命令号。

战略:标准 SCI_(120 命令)委托真 Scintilla,WindTerm 扩展
(EXT/WT 211 命令)用自研 EditorEngine 层。
