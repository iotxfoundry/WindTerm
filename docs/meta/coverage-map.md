# 全仓逆向覆盖索引（自动生成，勿手改）

> 生成:`python3 tools/re/coverage.py --write`。
> 用途:**转写任何函数前先 `coverage.py --addr <地址>`**,确认是否已有实现,
> 避免在已有代码上重复新增。

## 1. 分组规模

| 目录 | 文件 | 行数 | 类 | 唯一地址 | cited 标记 |
|---|---:|---:|---:|---:|---:|
| `Actions` | 11 | 1757 | 5 | 102 | 27 |
| `Actions/Dialogs` | 66 | 3900 | 35 | 201 | 99 |
| `Actions/Kit` | 23 | 4957 | 18 | 282 | 90 |
| `Actions/Menu` | 8 | 1198 | 5 | 41 | 13 |
| `Actions/Mux` | 10 | 2885 | 8 | 148 | 27 |
| `Actions/Settings` | 8 | 2363 | 21 | 115 | 56 |
| `Editor/Config` | 9 | 2303 | 14 | 71 | 23 |
| `Editor/Engine` | 17 | 11325 | 55 | 675 | 341 |
| `Ext` | 2 | 494 | 3 | 11 | 1 |
| `Protocols` | 3 | 336 | 3 | 0 | 0 |
| `Pty` | 9 | 1207 | 6 | 0 | 0 |
| `Pty/Public` | 1 | 2 | 0 | 0 | 0 |
| `Sessions/Bridges` | 15 | 1027 | 8 | 42 | 2 |
| `Sessions/Commanders` | 12 | 3135 | 7 | 60 | 44 |
| `Sessions/Core` | 7 | 2437 | 7 | 125 | 19 |
| `Sessions/Protocols` | 10 | 315 | 5 | 14 | 0 |
| `Sessions/Terminal` | 6 | 5783 | 12 | 325 | 50 |
| `Stubs` | 1 | 25 | 0 | 1 | 0 |
| `Utility` | 3 | 668 | 1 | 12 | 6 |
| `Utility/Components` | 8 | 734 | 10 | 0 | 0 |
| `Widgets/Faces` | 18 | 1059 | 20 | 46 | 32 |
| `Widgets/OpenSource` | 6 | 702 | 3 | 1 | 0 |
| `Widgets/Panels` | 13 | 2183 | 13 | 150 | 23 |
| **合计** | **266** | **50795** | **259** | **2129** | **853** |

## 2. 被引用最多的地址（多为共享腿，不要重复实现）

| 地址 | 文件数 | 位置 |
|---|---:|---|
| `FUN_006b2420` | 19 | src/Actions/Dialogs/DefaultEditorDialogFace.h<br>src/Actions/Dialogs/FocusModeDialogFace.cpp<br>src/Actions/Dialogs/FocusModeDialogFace.h<br>src/Actions/Dialogs/HighlightTextDialogFace.cpp |
| `FUN_00692ef0` | 10 | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Kit/KitWindowFace.h<br>src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h |
| `FUN_00809d78` | 9 | src/Actions/Kit/KitWindowFace.h<br>src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h<br>src/Editor/Config/CGlobalConfigFace.cpp |
| `FUN_00692a70` | 8 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h<br>src/Actions/Menu/ToolBarBuilder.h<br>src/Actions/Mux/MuxPaneGroup.cpp |
| `FUN_006926c2` | 8 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/KitWindowFactory.h<br>src/Actions/Menu/ToolBarBuilder.cpp<br>src/Actions/Mux/MuxPaneGroup.cpp |
| `FUN_007662e6` | 7 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/MainWindowFace.cpp<br>src/Actions/Kit/MainWindowFace.h<br>src/Actions/Mux/MuxWindow.h |
| `FUN_00766192` | 7 | src/Actions/JsEngine.h<br>src/Actions/Mux/MuxPane.h<br>src/Actions/Mux/MuxPaneView.cpp<br>src/Actions/Mux/MuxPaneView.h |
| `FUN_0066a148` | 7 | src/Actions/Kit/KitBar.cpp<br>src/Actions/Menu/ActionFactory.cpp<br>src/Actions/Menu/ActionFactory.h<br>src/Actions/Menu/ActionRegistryFace.cpp |
| `FUN_0093fc60` | 6 | src/Editor/Config/DeepEngineFace.cpp<br>src/Editor/Config/DeepEngineFace.h<br>src/Editor/Engine/ENodes.h<br>src/Editor/Engine/EditorEngine.cpp |
| `FUN_008ef798` | 6 | src/Actions/Dialogs/TriggerDialogFace.cpp<br>src/Actions/Dialogs/TunnelDialogFace.cpp<br>src/Actions/Settings/SettingsPageFace.cpp<br>src/Actions/Settings/SettingsPageFace.h |
| `FUN_008d7840` | 6 | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Kit/KitWindowAssemblyFace.h<br>src/Actions/Kit/KitWindowFace.h<br>src/Actions/StateStore.cpp |
| `FUN_008d5bee` | 6 | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Kit/KitWindowFace.h<br>src/Actions/StateStore.cpp<br>src/Actions/StateStore.h |
| `FUN_008bca9e` | 6 | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Kit/KitWindowFace.h<br>src/Actions/Mux/MuxPaneGroup.cpp<br>src/Actions/Mux/MuxPaneGroup.h |
| `FUN_0076aee6` | 6 | src/Actions/Kit/MainWindowFace.cpp<br>src/Actions/Kit/MainWindowFace.h<br>src/Actions/StartupChain.cpp<br>src/Actions/StartupChain.h |
| `FUN_0076663e` | 6 | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/MainWindowFace.h<br>src/Actions/Mux/MuxWindow.h<br>src/Actions/StartupChain.cpp |

## 3. 疑似重复实现（同一地址在 2+ 个 .cpp 带实现标记）

只统计带 `真身` / `// ===` 实现标记的行,普通引用不计 —— 共 **15** 处。
逐条核对:共享腿(合理,补交叉引用)还是重复转写(应合并)。

| 地址 | 文件 |
|---|---|
| `FUN_008c9e64` | src/Actions/StartupChain.cpp<br>src/Actions/StateStore.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_00692ef0` | src/Actions/Kit/KitWindowAssemblyFace.cpp<br>src/Actions/Menu/ToolBarBuilder.cpp<br>src/Actions/Mux/MuxPaneGroup.cpp |
| `FUN_00766c26` | src/Actions/StartupChain.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_0075e0f8` | src/Actions/StartupChain.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_00760856` | src/Actions/Kit/SuperApplicationFace.cpp<br>src/Actions/StateStore.cpp |
| `FUN_008bca9e` | src/Actions/Mux/MuxPaneGroup.cpp<br>src/Sessions/Core/WorkspaceLoader.cpp |
| `FUN_005211fe` | src/Actions/Menu/ToolBarBuilder.cpp<br>src/Widgets/Faces/BreadCrumbFace.cpp |
| `FUN_0057eb0c` | src/Actions/Menu/ToolBarBuilder.cpp<br>src/Widgets/Faces/SearchEditFace.cpp |
| `FUN_0072d0f2` | src/Actions/Dialogs/TunnelDialogFace.cpp<br>src/Actions/Settings/SettingsPageFace.cpp |
| `FUN_0072bf8a` | src/Actions/Dialogs/TunnelDialogFace.cpp<br>src/Actions/Settings/SettingsPageFace.cpp |
| `FUN_0072edfe` | src/Actions/Dialogs/TunnelDialogFace.cpp<br>src/Actions/Settings/SettingsPageFace.cpp |
| `FUN_0075e3fe` | src/Actions/Kit/KitWindowFactory.cpp<br>src/Actions/Kit/SuperApplicationFace.cpp |
| `FUN_0089a756` | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/EditorEngine.cpp |
| `FUN_00899316` | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/EditorEngine.cpp |
| `FUN_0092547e` | src/Editor/Engine/CodecMemo.cpp<br>src/Editor/Engine/EditorEngine.cpp |
