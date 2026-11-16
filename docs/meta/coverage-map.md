# 全仓逆向覆盖索引（自动生成，勿手改）

> 生成:`python3 tools/re/coverage.py --write`。
> 用途:**转写任何函数前先 `coverage.py --addr <地址>`**,确认是否已有实现,
> 避免在已有代码上重复新增。

## 1. 分组规模

| 目录 | 文件 | 行数 | 类 | 唯一地址 | cited 标记 |
|---|---:|---:|---:|---:|---:|
| `Actions` | 11 | 1757 | 5 | 264 | 27 |
| `Actions/Dialogs` | 66 | 3900 | 35 | 416 | 99 |
| `Actions/Kit` | 23 | 4957 | 18 | 866 | 90 |
| `Actions/Menu` | 8 | 1198 | 5 | 141 | 13 |
| `Actions/Mux` | 10 | 2885 | 8 | 635 | 27 |
| `Actions/Settings` | 8 | 2363 | 21 | 339 | 56 |
| `Editor/Config` | 9 | 2303 | 14 | 269 | 23 |
| `Editor/Engine` | 17 | 11325 | 55 | 1259 | 341 |
| `Ext` | 2 | 494 | 3 | 106 | 1 |
| `Protocols` | 3 | 348 | 3 | 0 | 0 |
| `Pty` | 9 | 1243 | 6 | 0 | 0 |
| `Pty/Public` | 1 | 6 | 0 | 0 | 0 |
| `Sessions/Bridges` | 14 | 1032 | 8 | 157 | 2 |
| `Sessions/Commanders` | 12 | 3147 | 7 | 80 | 44 |
| `Sessions/Core` | 7 | 2437 | 7 | 486 | 19 |
| `Sessions/Protocols` | 10 | 324 | 5 | 28 | 0 |
| `Sessions/Terminal` | 6 | 5783 | 12 | 327 | 50 |
| `Stubs` | 1 | 25 | 0 | 1 | 0 |
| `Utility` | 11 | 1434 | 11 | 30 | 6 |
| `Widgets` | 6 | 722 | 3 | 4 | 0 |
| `Widgets/Faces` | 18 | 1059 | 20 | 110 | 32 |
| `Widgets/Panels` | 13 | 2183 | 13 | 194 | 23 |
| **合计** | **265** | **50925** | **259** | **5222** | **853** |

## 2. 被引用最多的地址（多为共享腿，不要重复实现）

| 地址 | 文件数 | 位置 |
|---|---:|---|
| `FUN_006b2420` | 19 | src/Actions/Dialogs/DefaultEditorDialogFace.h<br>src/Actions/Dialogs/FocusModeDialogFace.cpp<br>src/Actions/Dialogs/FocusModeDialogFace.h<br>src/Actions/Dialogs/HighlightTextDialogFace.cpp |
| `FUN_00692ef0` | 11 | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Kit/KitWindowFace.h<br>src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h |
| `FUN_00809d78` | 9 | src/Actions/Kit/KitWindowFace.h<br>src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h<br>src/Editor/Config/CGlobalConfigFace.cpp |
| `FUN_007664a2` | 9 | src/Actions/Kit/KitBar.cpp<br>src/Actions/Kit/KitBar.h<br>src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h |
| `FUN_00692a70` | 9 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h<br>src/Actions/Menu/ActionRegistryFace.h<br>src/Actions/Menu/ToolBarBuilder.h |
| `FUN_008d2f7e` | 8 | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Kit/KitWindowAssemblyFace.h<br>src/Actions/Kit/KitWindowFace.h<br>src/Actions/StartupChain.cpp |
| `FUN_0076b9ec` | 8 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/MainWindowFace.h<br>src/Actions/Mux/MuxWindow.h<br>src/Actions/StartupChain.cpp |
| `FUN_006926c2` | 8 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h<br>src/Actions/Menu/ToolBarBuilder.cpp<br>src/Actions/Mux/MuxPaneGroup.cpp |
| `FUN_0064b102` | 8 | src/Actions/JsEngine.cpp<br>src/Actions/JsEngine.h<br>src/Actions/Mux/MuxPane.cpp<br>src/Actions/Mux/MuxPane.h |
| `FUN_00b422d0` | 7 | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/CodecMemo.h<br>src/Editor/Engine/EditorEngine.cpp<br>src/Editor/Engine/MatchEngine.cpp |
| `FUN_008c9ee4` | 7 | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Kit/KitWindowAssemblyFace.h<br>src/Actions/Kit/KitWindowFace.h<br>src/Actions/Kit/KitWindowFactory.cpp |
| `FUN_008062b6` | 7 | src/Actions/Dialogs/TriggerDialogFace.cpp<br>src/Actions/Dialogs/TriggerDialogFace.h<br>src/Sessions/Core/WorkspaceLoader.cpp<br>src/Sessions/Core/WorkspaceLoader.h |
| `FUN_0076663e` | 7 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/MainWindowFace.cpp<br>src/Actions/Kit/MainWindowFace.h<br>src/Actions/Mux/MuxWindow.h |
| `FUN_007662e6` | 7 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/MainWindowFace.cpp<br>src/Actions/Kit/MainWindowFace.h<br>src/Actions/Mux/MuxWindow.h |
| `FUN_00766192` | 7 | src/Actions/JsEngine.h<br>src/Actions/Mux/MuxPane.h<br>src/Actions/Mux/MuxPaneView.cpp<br>src/Actions/Mux/MuxPaneView.h |

## 3. 疑似重复实现（同一地址在 2+ 个 .cpp 带实现标记）

只统计带 `真身` / `// ===` 实现标记的行,普通引用不计 —— 共 **19** 处。
逐条核对:共享腿(合理,补交叉引用)还是重复转写(应合并)。

| 地址 | 文件 |
|---|---|
| `FUN_00692ef0` | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Menu/ToolBarBuilder.cpp<br>src/Actions/Mux/MuxPaneGroup.cpp<br>src/Actions/Mux/MuxPaneView.cpp |
| `FUN_008c9e64` | src/Actions/StartupChain.cpp<br>src/Actions/StateStore.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_00766c26` | src/Actions/StartupChain.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_0075e0f8` | src/Actions/StartupChain.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_00760856` | src/Actions/Kit/SuperApplicationFace.cpp<br>src/Actions/StateStore.cpp |
| `FUN_00752640` | src/Actions/Mux/MuxWindow.cpp<br>src/Utility/ApplicationTheme.cpp |
| `FUN_008bca9e` | src/Actions/Mux/MuxPaneGroup.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_005211fe` | src/Actions/Menu/ToolBarBuilder.cpp<br>src/Widgets/Faces/BreadCrumbFace.cpp |
| `FUN_0057eb0c` | src/Actions/Menu/ToolBarBuilder.cpp<br>src/Widgets/Faces/SearchEditFace.cpp |
| `FUN_0072d0f2` | src/Actions/Dialogs/TunnelDialogFace.cpp<br>src/Actions/Settings/SettingsPageFace.cpp |
| `FUN_0072bf8a` | src/Actions/Dialogs/TunnelDialogFace.cpp<br>src/Actions/Settings/SettingsPageFace.cpp |
| `FUN_0072edfe` | src/Actions/Dialogs/TunnelDialogFace.cpp<br>src/Actions/Settings/SettingsPageFace.cpp |
| `FUN_005ab32a` | src/Actions/Kit/KitDockFace.cpp<br>src/Actions/Kit/KitWindowAssemblyFace.cpp |
| `FUN_0075e3fe` | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/SuperApplicationFace.cpp |
| `FUN_008d2f7e` | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_008d304b` | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_0089a756` | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/EditorEngine.cpp |
| `FUN_00899316` | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/EditorEngine.cpp |
| `FUN_0092547e` | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/EditorEngine.cpp |

## 4. 第一方开源件（B 类·勿逆向）

文件带 `[B-OPENSOURCE]` 标记;清单 `tools/re/data/open_source_files.txt`;校验 `coverage.py --audit`。

| 文件 |
|---|
| `src/Protocols/Protocol.h` |
| `src/Protocols/TelnetProtocol.cpp` |
| `src/Protocols/TelnetProtocol.h` |
| `src/Pty/ConPty.cpp` |
| `src/Pty/ConPty.h` |
| `src/Pty/Pty.cpp` |
| `src/Pty/Pty.h` |
| `src/Pty/Public/Spin.h` |
| `src/Pty/ShellProcess.h` |
| `src/Pty/UnixPty.cpp` |
| `src/Pty/UnixPty.h` |
| `src/Pty/WinPty.cpp` |
| `src/Pty/WinPty.h` |
| `src/Utility/CircularBuffer.h` |
| `src/Utility/Cryptographic.cpp` |
| `src/Utility/Cryptographic.h` |
| `src/Utility/MemoryPointer.h` |
| `src/Utility/ScopeGuard.h` |
| `src/Utility/Spin.h` |
| `src/Utility/ThreadLocal.cpp` |
| `src/Utility/ThreadLocal.h` |
| `src/Widgets/PopupWidget.cpp` |
| `src/Widgets/PopupWidget.h` |
| `src/Widgets/ScrollBar.cpp` |
| `src/Widgets/ScrollBar.h` |
| `src/Widgets/Splitter.h` |
