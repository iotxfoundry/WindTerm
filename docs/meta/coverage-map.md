# 全仓逆向覆盖索引（自动生成，勿手改）

> 生成:`python3 tools/re/coverage.py --write`。
> 用途:**转写任何函数前先 `coverage.py --addr <地址>`**,确认是否已有实现,
> 避免在已有代码上重复新增。

## 1. 分组规模

| 目录 | 文件 | 行数 | 类 | 唯一地址 | cited 标记 |
|---|---:|---:|---:|---:|---:|
| `Actions` | 12 | 1423 | 6 | 153 | 16 |
| `App` | 12 | 2326 | 6 | 325 | 33 |
| `Editor/Config` | 9 | 2303 | 14 | 269 | 23 |
| `Editor/Engine` | 17 | 11325 | 55 | 1259 | 341 |
| `Ext` | 1 | 25 | 0 | 4 | 0 |
| `Protocols` | 3 | 348 | 3 | 0 | 0 |
| `Pty` | 9 | 1243 | 6 | 0 | 0 |
| `Pty/Public` | 1 | 6 | 0 | 0 | 0 |
| `Sessions/Bridges` | 14 | 1032 | 8 | 157 | 2 |
| `Sessions/Commanders` | 12 | 3147 | 7 | 80 | 44 |
| `Sessions/Core` | 10 | 3016 | 11 | 572 | 21 |
| `Sessions/Transfers` | 12 | 1762 | 7 | 78 | 9 |
| `Sessions/Transports` | 10 | 324 | 5 | 28 | 0 |
| `Stubs` | 1 | 25 | 0 | 1 | 0 |
| `Terminal` | 6 | 5783 | 12 | 327 | 50 |
| `Utility` | 13 | 1547 | 12 | 3 | 1 |
| `Widgets` | 6 | 722 | 3 | 4 | 0 |
| `Widgets/Bars` | 14 | 606 | 8 | 57 | 7 |
| `Widgets/Controls` | 46 | 3320 | 27 | 435 | 77 |
| `Widgets/Dialogs` | 71 | 4098 | 38 | 434 | 107 |
| `Widgets/Panes` | 13 | 834 | 12 | 126 | 12 |
| `Widgets/Settings` | 8 | 2342 | 21 | 339 | 55 |
| `Widgets/Views` | 8 | 2030 | 5 | 117 | 20 |
| `Windows/Kit` | 11 | 2597 | 10 | 431 | 43 |
| `Windows/Mux` | 10 | 2885 | 8 | 635 | 27 |
| **合计** | **329** | **55069** | **284** | **5356** | **888** |

## 2. 被引用最多的地址（多为共享腿，不要重复实现）

| 地址 | 文件数 | 位置 |
|---|---:|---|
| `FUN_006b2420` | 19 | src/Widgets/Dialogs/DefaultEditorDialogFace.h<br>src/Widgets/Dialogs/FocusModeDialogFace.cpp<br>src/Widgets/Dialogs/FocusModeDialogFace.h<br>src/Widgets/Dialogs/HighlightTextDialogFace.cpp |
| `FUN_00692ef0` | 11 | src/Actions/ToolBarBuilder.cpp<br>src/Actions/ToolBarBuilder.h<br>src/Editor/Config/CGlobalConfigFace.h<br>src/Windows/Kit/KitWindowAssemblyFace.cpp |
| `FUN_00809d78` | 9 | src/Editor/Config/CGlobalConfigFace.cpp<br>src/Editor/Config/CGlobalConfigFace.h<br>src/Editor/Config/CTerminalConfig.cpp<br>src/Editor/Config/CTerminalConfig.h |
| `FUN_007664a2` | 9 | src/App/StartupChain.cpp<br>src/App/StartupChain.h<br>src/Sessions/Core/WorkspaceLoader.cpp<br>src/Windows/Kit/KitBar.cpp |
| `FUN_00692a70` | 9 | src/Actions/ActionRegistryFace.h<br>src/Actions/ToolBarBuilder.h<br>src/Editor/Config/CGlobalConfigFace.cpp<br>src/Editor/Config/CGlobalConfigFace.h |
| `FUN_008d2f7e` | 8 | src/App/StartupChain.cpp<br>src/App/StartupChain.h<br>src/App/StateStore.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_0076b9ec` | 8 | src/App/StartupChain.cpp<br>src/App/StartupChain.h<br>src/App/StateStore.h<br>src/Editor/Engine/KeymapEngine.cpp |
| `FUN_006926c2` | 8 | src/Actions/ToolBarBuilder.cpp<br>src/Editor/Config/CGlobalConfigFace.cpp<br>src/Editor/Config/CGlobalConfigFace.h<br>src/Windows/Kit/KitWindowFactory.cpp |
| `FUN_0064b102` | 8 | src/App/JsEngine.cpp<br>src/App/JsEngine.h<br>src/App/StartupChain.cpp<br>src/Windows/Mux/MuxPane.cpp |
| `FUN_00b422d0` | 7 | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/CodecMemo.h<br>src/Editor/Engine/EditorEngine.cpp<br>src/Editor/Engine/MatchEngine.cpp |
| `FUN_008c9ee4` | 7 | src/Editor/Config/CGlobalConfigFace.cpp<br>src/Editor/Config/CGlobalConfigFace.h<br>src/Windows/Kit/KitWindowAssemblyFace.cpp<br>src/Windows/Kit/KitWindowAssemblyFace.h |
| `FUN_008062b6` | 7 | src/Sessions/Core/SessionManager.cpp<br>src/Sessions/Core/SessionManager.h<br>src/Sessions/Core/WorkspaceLoader.cpp<br>src/Sessions/Core/WorkspaceLoader.h |
| `FUN_0076663e` | 7 | src/App/StartupChain.cpp<br>src/App/StartupChain.h<br>src/App/StateStore.h<br>src/Windows/Kit/KitWindowFactory.cpp |
| `FUN_007662e6` | 7 | src/App/StartupChain.cpp<br>src/App/StartupChain.h<br>src/Sessions/Core/WorkspaceLoader.h<br>src/Windows/Kit/KitWindowFactory.cpp |
| `FUN_00766192` | 7 | src/App/JsEngine.h<br>src/App/StartupChain.cpp<br>src/App/StartupChain.h<br>src/Editor/Engine/SuperKeymap.cpp |

## 3. 疑似重复实现（同一地址在 2+ 个 .cpp 带实现标记）

判定:函数定义紧邻注释块中带 `真身`/字节数/`===` 的那一行,取首个地址作为该函数出处;含 `同构` 的行不计。共 **2** 处。
逐条核对:共享腿(合理,补交叉引用)还是重复转写(应合并)。

| 地址 | 文件 |
|---|---|
| `FUN_0072d0f2` | src/Widgets/Dialogs/TunnelDialogFace.cpp<br>src/Widgets/Settings/SettingsPageFace.cpp |
| `FUN_0072bf8a` | src/Widgets/Dialogs/TunnelDialogFace.cpp<br>src/Widgets/Settings/SettingsPageFace.cpp |

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
