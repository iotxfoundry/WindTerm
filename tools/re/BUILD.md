# 编译验证配方(2026-10-28 达成)

成果:`libWindTermRe.so`(775KB)可加载、元对象活性通过。

## 环境

| 项 | 值 |
|---|---|
| 系统 Qt 头 | /usr/include/x86_64-linux-gnu/qt5(5.15.13) |
| 链接库 | **仓库 lib/**(Qt 5.15.2 与系统 5.15.13 ABI 同)+ libssh.so.4 |
| moc | /usr/lib/qt5/bin/moc(系统 5.15.13,与 5.15.2 元数据兼容) |
| inc/qt5 | 仅转发头(qtbase 源码未入库),**不可用作编译头** |
| inc/scintilla | Scintilla 完整源码树(EditorEngine 原生参考,后续挖) |

## 步骤

```bash
B=/tmp/opencode/build; W=$(pwd); Q=/usr/include/x86_64-linux-gnu/qt5
mkdir -p $B && cd $B

# 1) moc(22 个 Q_OBJECT 头;Screen/TextView 是壳类无 Q_OBJECT)
for h in $(grep -l Q_OBJECT $W/src/Sessions/*.h $W/src/Widgets/*.h $W/src/Protocols/*.h); do
  /usr/lib/qt5/bin/moc $h -o moc_$(basename $h .h).cpp
done

# 2) 开发符号链(发行库无 .so 开发名)
for l in Qt5Core Qt5Gui Qt5Widgets Qt5Network; do ln -sf $W/lib/lib$l.so.5 $B/lib$l.so; ln -sf $W/lib/lib$l.so.5 $B/lib$l.so.5; done
for so in libssh.so.4 libicui18n.so.56 libicuuc.so.56 libicudata.so.56 libcrypto.so.1.1 libssl.so.1.1; do ln -sf $W/lib/$so $B/$so; done

# 3) 编译+链接(stubs_gen.cpp 见下)
g++ -std=c++17 -fPIC -shared -o libWindTermRe.so \
  $W/src/Sessions/*.cpp $W/src/Widgets/*.cpp $W/src/Protocols/*.cpp \
  $W/src/Utility/ThreadLocal.cpp stubs_gen.cpp moc_*.cpp \
  -I $W/src/Sessions -I $W/src -I $Q -I $Q/QtCore -I $Q/QtGui -I $Q/QtWidgets -I $Q/QtNetwork \
  -I $W/src/libssh/include \
  -L$B -lQt5Core -lQt5Gui -lQt5Widgets -lQt5Network -lssh

# 4) 验证
LD_LIBRARY_PATH=$B python3 -c "import ctypes; ctypes.CDLL('$B/libWindTermRe.so'); print('dlopen OK')"
LD_LIBRARY_PATH=$B ./metatest   # SuperSession 元对象活性
```

## stubs_gen.cpp(97 个 cited-stub)

`tools/re/gen_stubs.py`(链接器 mangled 未定义表 × 头文件返回类型)
自动生成 —— 已声明未定义的会话 API(SuperSession 认证族、行操作族
等,地址见 IMPL-ADDRESSES.md)。**转写真身时删对应行**。

## 已知边界

- PopupWidget 的 qFadeEffect:仓库私有头是转发桩,用本地 inline 桩
  (装饰性动画);qtbase 源码联编时换回 `#include <private/qeffects_p.h>`
- QScrollBar 未定义符号:PopupWidget 派生链引用,已由本库各 .cpp 覆盖
- Screen/TextView 壳类无 Q_OBJECT(信号经 SuperCommander 侧),故
  元对象探针用 SuperSession
