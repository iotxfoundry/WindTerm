# 逆向工作总账（自动生成，勿手改）

> 生成:`python3 tools/re/coverage.py --write`(或 `--ledger` 只打印)。
> 分母 = 语料 `.text` 内 38748 条(排除 PLT/数据);
> 同一件事有两个量纲 —— **函数数**与**字节数**,两者差一倍以上,所以下表两列都给。

## 1. 四状态口径

| 状态 | 判据 |
|---|---|
| 真实现 | 函数定义紧邻注释里带出处,且函数体去掉注释/空白后 >40 字符 |
| 半成品 | 带出处,但函数体近乎空壳(只有注释 / `Q_UNUSED`) |
| 引用档 | 地址只在别处被引用(接口声明、调用点、`cited` 注释),没有本函数定义 |
| 未触及 | 地址不出现在 `src/` 任何文件 |

**已知盲区(不修,只声明)**:只枚举 `Class::method` 与 `Class::~Class`;自由函数、文件内 `static` 函数(如 `Utility/Format.cpp` 的 `formatDuration`)未计入 → **真实现/半成品两档略偏低**(数量级为数十,不影响量级判断)。

## 2. 总账

| 状态 | 函数 | 函数占比 | 字节 | 字节占比 |
|---|---:|---:|---:|---:|
| 真实现 | 733 | 1.89% | 274178 | 3.57% |
| 半成品 | 40 | 0.10% | 13943 | 0.18% |
| 引用档 | 2143 | 5.53% | 798126 | 10.40% |
| 未触及(真工作) | 20773 | 53.61% | 5570748 | 72.62% |
| 异常清理块(非函数) | 13952 | 36.01% | 786418 | 10.25% |
| Qt 元数据桩(非逆向对象) | 1107 | 2.86% | 228022 | 2.97% |
| **合计** | **38748** | 100% | **7671435** | 100% |
| **真工作分母** | **23689** | — | — | — |

> 真工作分母 = 合计 − 异常清理块 − Qt 元数据桩。「未触及(真工作)」一栏才是真正的待办量。

## 3. 按文件（有落点的）

`未触及` 无法按文件分(它没有落点),故只列三档。

| 文件 | 真实现 | 半成品 | 引用档 |
|---|---:|---:|---:|
| `src/Terminal/Screen.cpp` | 131 | 3 | 132 |
| `src/Terminal/Screen.h` | 114 | 3 | 95 |
| `src/Terminal/TerminalCore.cpp` | 82 | 0 | 19 |
| `src/Terminal/TerminalCore.h` | 82 | 0 | 13 |
| `src/Widgets/Controls/TabGroup.cpp` | 45 | 1 | 29 |
| `src/Widgets/Controls/TabGroup.h` | 44 | 1 | 32 |
| `src/Windows/Mux/MuxPaneGroup.cpp` | 44 | 0 | 39 |
| `src/Widgets/Settings/TriggerPageFace.cpp` | 38 | 0 | 41 |
| `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 | 40 |
| `src/Widgets/Dialogs/TriggerDialogFace.cpp` | 33 | 0 | 34 |
| `src/Widgets/Dialogs/TriggerDialogFace.h` | 33 | 0 | 26 |
| `src/Windows/Mux/MuxPaneGroup.h` | 31 | 0 | 12 |
| `src/Sessions/Commanders/SuperCommander.cpp` | 27 | 0 | 27 |
| `src/Windows/Mux/MuxWindow.cpp` | 27 | 0 | 55 |
| `src/Windows/Kit/KitWindowFace.h` | 26 | 0 | 30 |
| `src/Windows/Mux/MuxWindow.h` | 24 | 0 | 25 |
| `src/Windows/Kit/KitWindowAssemblyFace.cpp` | 23 | 0 | 67 |
| `src/Widgets/Settings/SettingsPageFace.cpp` | 19 | 0 | 23 |
| `src/Widgets/Settings/SettingsPageFace.h` | 19 | 0 | 23 |
| `src/Sessions/Transfers/Modem.h` | 17 | 1 | 4 |
| `src/Sessions/Transfers/XYModem.h` | 17 | 1 | 3 |
| `src/Sessions/Transfers/XYModem.cpp` | 17 | 0 | 0 |
| `src/Sessions/Transfers/Modem.cpp` | 16 | 0 | 16 |
| `src/Windows/Kit/KitDockFace.cpp` | 16 | 0 | 19 |
| `src/Windows/Mux/MuxPaneView.h` | 16 | 0 | 14 |
| `src/App/StartupChain.cpp` | 13 | 1 | 47 |
| `src/Sessions/Transfers/ZModem.cpp` | 13 | 0 | 4 |
| `src/Widgets/Views/LockScreenFace.cpp` | 10 | 3 | 16 |
| `src/Windows/Kit/KitDockFace.h` | 13 | 0 | 10 |
| `src/Sessions/Bridges/ProxyCommandSocket.h` | 12 | 0 | 12 |
| `src/Widgets/Views/LockScreenFace.h` | 9 | 3 | 5 |
| `src/Windows/Kit/KitBar.cpp` | 12 | 0 | 18 |
| `src/Windows/Kit/KitWindowFactory.cpp` | 12 | 0 | 9 |
| `src/Windows/Mux/MuxPaneView.cpp` | 12 | 0 | 11 |
| `src/App/StateStore.cpp` | 11 | 0 | 38 |
| `src/Editor/Config/CGlobalConfigFace.h` | 11 | 0 | 29 |
| `src/Sessions/Bridges/ProxyCommandSocket.cpp` | 11 | 0 | 14 |
| `src/Sessions/Transfers/ModemProcess.h` | 10 | 1 | 0 |
| `src/Widgets/Controls/SearchEditFace.cpp` | 10 | 1 | 10 |
| `src/Widgets/Controls/SearchEditFace.h` | 10 | 1 | 10 |
| `src/Sessions/Bridges/TcpBridge.cpp` | 10 | 0 | 13 |
| `src/Sessions/Bridges/TelnetBridge.h` | 10 | 0 | 10 |
| `src/Windows/Kit/KitWindowFactory.h` | 10 | 0 | 25 |
| `src/App/StartupChain.h` | 8 | 1 | 22 |
| `src/Editor/Engine/EditorEngine.cpp` | 9 | 0 | 514 |
| `src/Sessions/Bridges/TcpBridge.h` | 9 | 0 | 10 |
| `src/Sessions/Transfers/ModemProcess.cpp` | 8 | 1 | 0 |
| `src/Windows/Kit/KitBar.h` | 9 | 0 | 8 |
| `src/Actions/ActionFactory.cpp` | 8 | 0 | 10 |
| `src/App/JsEngine.h` | 8 | 0 | 4 |
| `src/Editor/Config/CGlobalConfigFace.cpp` | 8 | 0 | 20 |
| `src/Editor/Engine/SuperKeymap.cpp` | 8 | 0 | 60 |
| `src/Sessions/Bridges/TelnetBridge.cpp` | 8 | 0 | 12 |
| `src/Sessions/Core/SuperSessionPrivate.cpp` | 8 | 0 | 45 |
| `src/Sessions/Core/WorkspaceLoader.cpp` | 8 | 0 | 50 |
| `src/Sessions/Transfers/ZModem.h` | 8 | 0 | 0 |
| `src/Sessions/Transports/TelnetSession.h` | 8 | 0 | 9 |
| `src/Widgets/Controls/SplitterGroup.h` | 8 | 0 | 14 |
| `src/Actions/SlipButtonFace.cpp` | 7 | 0 | 7 |
| `src/Actions/SlipButtonFace.h` | 7 | 0 | 2 |
| `src/Actions/ToolBarBuilder.cpp` | 7 | 0 | 10 |
| `src/App/JsEngine.cpp` | 7 | 0 | 3 |
| `src/App/SuperApplicationFace.cpp` | 7 | 0 | 34 |
| `src/App/SuperApplicationFace.h` | 7 | 0 | 14 |
| `src/Editor/Engine/CodecMemo.cpp` | 7 | 0 | 26 |
| `src/Editor/Engine/CodecMemo.h` | 7 | 0 | 12 |
| `src/Editor/Engine/KeymapEngine.cpp` | 7 | 0 | 8 |
| `src/Sessions/Core/SuperSessionPrivate.h` | 7 | 0 | 35 |
| `src/Sessions/Core/WorkspaceLoader.h` | 7 | 0 | 41 |
| `src/Widgets/Controls/CompleterFace.h` | 5 | 2 | 0 |
| `src/App/StateStore.h` | 6 | 0 | 36 |
| `src/Editor/Engine/KeymapEngine.h` | 6 | 0 | 10 |
| `src/Widgets/Controls/CompleterFace.cpp` | 4 | 2 | 3 |
| `src/Actions/ToolBarBuilder.h` | 5 | 0 | 12 |
| `src/App/ApplicationTheme.cpp` | 5 | 0 | 10 |
| `src/App/ApplicationTheme.h` | 5 | 0 | 1 |
| `src/Sessions/Commanders/TelnetCommander.cpp` | 5 | 0 | 19 |
| `src/Sessions/Commanders/TelnetCommander.h` | 5 | 0 | 11 |
| `src/Actions/ActionFactory.h` | 4 | 0 | 5 |
| `src/Actions/ActionRegistryFace.cpp` | 4 | 0 | 13 |
| `src/Actions/ActionRegistryFace.h` | 4 | 0 | 15 |
| `src/Editor/Config/CTerminalConfig.cpp` | 4 | 0 | 8 |
| `src/Editor/Engine/MatchEngine.h` | 4 | 0 | 28 |
| `src/Editor/Engine/SuperKeymap.h` | 4 | 0 | 32 |
| `src/Widgets/Bars/BreadCrumbFace.cpp` | 4 | 0 | 4 |
| `src/Widgets/Bars/BreadCrumbFace.h` | 4 | 0 | 4 |
| `src/Widgets/Bars/StatusBarFace.cpp` | 4 | 0 | 1 |
| `src/Widgets/Bars/StatusBarFace.h` | 4 | 0 | 0 |
| `src/Widgets/Controls/SplitterGroup.cpp` | 4 | 0 | 10 |
| `src/Widgets/Dialogs/InsertFileDialogFace.cpp` | 3 | 1 | 2 |
| `src/Widgets/Dialogs/InsertFileDialogFace.h` | 3 | 1 | 2 |
| `src/Widgets/Dialogs/NameDialogFace.cpp` | 4 | 0 | 4 |
| `src/Widgets/Dialogs/NameDialogFace.h` | 4 | 0 | 4 |
| `src/Widgets/Dialogs/ProfileDialogFace.cpp` | 2 | 2 | 5 |
| `src/Widgets/Dialogs/ProfileDialogFace.h` | 2 | 2 | 5 |
| `src/Widgets/Dialogs/SessionDialogFace.cpp` | 4 | 0 | 6 |
| `src/Widgets/Dialogs/SessionDialogFace.h` | 4 | 0 | 4 |
| `src/Widgets/Dialogs/SyncInputDialogFace.cpp` | 3 | 1 | 2 |
| `src/Widgets/Dialogs/SyncInputDialogFace.h` | 3 | 1 | 2 |
| `src/Widgets/Panes/ViewBase.h` | 4 | 0 | 25 |
| `src/Widgets/Settings/SettingsFace.cpp` | 4 | 0 | 6 |
| `src/Windows/Kit/MainWindowFace.h` | 4 | 0 | 13 |
| `src/Editor/Config/CTerminalConfig.h` | 3 | 0 | 5 |
| `src/Editor/Engine/EditorEngine.h` | 3 | 0 | 1 |
| `src/Sessions/Bridges/SessionProtocol.h` | 3 | 0 | 9 |
| `src/Sessions/Commanders/SuperCommander.h` | 3 | 0 | 0 |
| `src/Sessions/Core/SuperSession.h` | 3 | 0 | 2 |
| `src/Sessions/Transports/TelnetSession.cpp` | 3 | 0 | 3 |
| `src/Widgets/Bars/BarFaces.cpp` | 3 | 0 | 7 |
| `src/Widgets/Bars/BarFaces.h` | 3 | 0 | 7 |
| `src/Widgets/Dialogs/FocusModeDialogFace.cpp` | 2 | 1 | 2 |
| `src/Widgets/Dialogs/FocusModeDialogFace.h` | 2 | 1 | 2 |
| `src/Widgets/Dialogs/HighlightTextDialogFace.cpp` | 2 | 1 | 1 |
| `src/Widgets/Dialogs/HighlightTextDialogFace.h` | 2 | 1 | 1 |
| `src/Widgets/Dialogs/PlaySoundDialogFace.cpp` | 2 | 1 | 0 |
| `src/Widgets/Dialogs/PlaySoundDialogFace.h` | 2 | 1 | 2 |
| `src/Widgets/Dialogs/RemoteFileDialogFace.cpp` | 3 | 0 | 0 |
| `src/Widgets/Dialogs/RemoteFileDialogFace.h` | 3 | 0 | 0 |
| `src/Widgets/Dialogs/SessionGroupDialogFace.cpp` | 2 | 1 | 1 |
| `src/Widgets/Dialogs/SessionGroupDialogFace.h` | 2 | 1 | 1 |
| `src/Widgets/Dialogs/SessionTriggerDialogFace.cpp` | 2 | 1 | 2 |
| `src/Widgets/Dialogs/SessionTriggerDialogFace.h` | 2 | 1 | 2 |
| `src/Widgets/Dialogs/SettingDialogFace.cpp` | 2 | 1 | 0 |
| `src/Widgets/Dialogs/SettingDialogFace.h` | 2 | 1 | 0 |
| `src/Widgets/Dialogs/TextMarkDialogFace.cpp` | 3 | 0 | 6 |
| `src/Widgets/Dialogs/TriggerActionDialogFace.cpp` | 2 | 1 | 1 |
| `src/Widgets/Dialogs/TriggerActionDialogFace.h` | 2 | 1 | 1 |
| `src/Widgets/Settings/SettingsFace.h` | 3 | 0 | 0 |
| `src/Windows/Mux/MuxPane.h` | 3 | 0 | 5 |
| `src/Sessions/Transfers/XModem.cpp` | 2 | 0 | 1 |
| `src/Sessions/Transfers/YModem.cpp` | 2 | 0 | 1 |
| `src/Utility/DirScanerFace.h` | 2 | 0 | 0 |
| `src/Widgets/Bars/AddressBarFace.cpp` | 2 | 0 | 3 |
| `src/Widgets/Bars/AddressBarFace.h` | 2 | 0 | 3 |
| `src/Widgets/Bars/AppletBarFace.h` | 2 | 0 | 0 |
| `src/Widgets/Controls/HoverButtonFace.cpp` | 2 | 0 | 0 |
| `src/Widgets/Controls/HoverButtonFace.h` | 2 | 0 | 0 |
| `src/Widgets/Controls/HtmlListFace.h` | 1 | 1 | 0 |
| `src/Widgets/Controls/ListViewFace.h` | 2 | 0 | 2 |
| `src/Widgets/Controls/SideButtonFace.cpp` | 2 | 0 | 0 |
| `src/Widgets/Controls/SideButtonFace.h` | 2 | 0 | 0 |
| `src/Widgets/Controls/SwitchButtonFace.cpp` | 2 | 0 | 1 |
| `src/Widgets/Controls/SwitchButtonFace.h` | 2 | 0 | 0 |
| `src/Widgets/Dialogs/EnvironmentDialogFace.cpp` | 2 | 0 | 4 |
| `src/Widgets/Dialogs/EnvironmentDialogFace.h` | 2 | 0 | 5 |
| `src/Widgets/Dialogs/LogDialogFace.cpp` | 1 | 1 | 3 |
| `src/Widgets/Dialogs/LogDialogFace.h` | 1 | 1 | 0 |
| `src/Widgets/Dialogs/MasterPasswordDialogFace.cpp` | 1 | 1 | 3 |
| `src/Widgets/Dialogs/MasterPasswordDialogFace.h` | 1 | 1 | 0 |
| `src/Widgets/Dialogs/OneKeyDialogFace.cpp` | 2 | 0 | 0 |
| `src/Widgets/Dialogs/OneKeyDialogFace.h` | 2 | 0 | 0 |
| `src/Widgets/Dialogs/PasswordDialogFace.cpp` | 1 | 1 | 2 |
| `src/Widgets/Dialogs/PasswordDialogFace.h` | 1 | 1 | 0 |
| `src/Widgets/Dialogs/PasteDialogFace.cpp` | 1 | 1 | 4 |
| `src/Widgets/Dialogs/PasteDialogFace.h` | 1 | 1 | 0 |
| `src/Widgets/Dialogs/QuickDialogFace.cpp` | 1 | 1 | 3 |
| `src/Widgets/Dialogs/QuickDialogFace.h` | 1 | 1 | 0 |
| `src/Widgets/Dialogs/RunToolDialogFace.cpp` | 2 | 0 | 5 |
| `src/Widgets/Dialogs/RunToolDialogFace.h` | 2 | 0 | 5 |
| `src/Widgets/Dialogs/TextMarkDialogFace.h` | 2 | 0 | 2 |
| `src/Widgets/Dialogs/TunnelDialogFace.cpp` | 2 | 0 | 0 |
| `src/Widgets/Dialogs/WindowOpacityDialogFace.cpp` | 2 | 0 | 0 |
| `src/Widgets/Dialogs/WindowOpacityDialogFace.h` | 2 | 0 | 0 |
| `src/Widgets/Panes/SessionPane.h` | 2 | 0 | 19 |
| `src/Windows/Kit/KitWindowAssemblyFace.h` | 2 | 0 | 32 |
| `src/Windows/Kit/MainWindowFace.cpp` | 2 | 0 | 7 |
| `src/Windows/Mux/MuxPane.cpp` | 2 | 0 | 0 |
| `src/Windows/Mux/MuxPaneJs.h` | 2 | 0 | 0 |
| `src/Editor/Engine/EditorContext.h` | 1 | 0 | 121 |
| `src/Editor/Engine/MatchEngine.cpp` | 1 | 0 | 16 |
| `src/Sessions/Bridges/SshBridge.cpp` | 1 | 0 | 9 |
| `src/Sessions/Core/FileOps.h` | 1 | 0 | 23 |
| `src/Sessions/Core/SessionLoggerOp.h` | 1 | 0 | 14 |
| `src/Sessions/Core/SuperSession.cpp` | 1 | 0 | 11 |
| `src/Sessions/Transfers/XModem.h` | 0 | 1 | 1 |
| `src/Sessions/Transfers/YModem.h` | 0 | 1 | 1 |
| `src/Sessions/Transports/SshSocketFace.cpp` | 1 | 0 | 1 |
| `src/Sessions/Transports/SshSocketFace.h` | 1 | 0 | 2 |
| `src/Stubs/gen_stubs.cpp` | 1 | 0 | 0 |
| `src/Terminal/TermViewFace.h` | 1 | 0 | 0 |
| `src/Utility/FileWatcherFace.h` | 1 | 0 | 0 |
| `src/Widgets/Bars/AppletBarFace.cpp` | 1 | 0 | 0 |
| `src/Widgets/Bars/MessageBarFace.h` | 1 | 0 | 0 |
| `src/Widgets/Controls/CompleteListFace.h` | 1 | 0 | 0 |
| `src/Widgets/Controls/CompleteModelFace.h` | 1 | 0 | 1 |
| `src/Widgets/Controls/CrumbEditFace.cpp` | 1 | 0 | 0 |
| `src/Widgets/Controls/CrumbEditFace.h` | 1 | 0 | 1 |
| `src/Widgets/Controls/HtmlListFace.cpp` | 1 | 0 | 2 |
| `src/Widgets/Controls/ListViewFace.cpp` | 1 | 0 | 5 |
| `src/Widgets/Controls/ListWidgetFace.h` | 1 | 0 | 0 |
| `src/Widgets/Controls/ToolButtonFace.h` | 1 | 0 | 0 |
| `src/Widgets/Dialogs/DefaultEditorDialogFace.cpp` | 1 | 0 | 0 |
| `src/Widgets/Dialogs/DefaultEditorDialogFace.h` | 1 | 0 | 4 |
| `src/Widgets/Dialogs/HelpDialogFace.cpp` | 1 | 0 | 0 |
| `src/Widgets/Dialogs/HelpDialogFace.h` | 1 | 0 | 0 |
| `src/Widgets/Dialogs/TableItemDialogFace.cpp` | 1 | 0 | 0 |
| `src/Widgets/Dialogs/TableItemDialogFace.h` | 1 | 0 | 0 |
| `src/Widgets/Panes/OutlinePaneFace.h` | 1 | 0 | 8 |
| `src/Widgets/Panes/OutputPane.h` | 1 | 0 | 9 |
| `src/Widgets/Panes/SearchPaneFace.h` | 1 | 0 | 4 |
| `src/Widgets/Settings/PasteSettingsPageFace.cpp` | 1 | 0 | 1 |
| `src/Widgets/Settings/PasteSettingsPageFace.h` | 1 | 0 | 1 |
| `src/Widgets/Splitter.cpp` | 1 | 0 | 0 |
| `src/Widgets/Splitter.h` | 1 | 0 | 0 |
| `src/Widgets/Views/TerminalView.cpp` | 1 | 0 | 1 |
| `src/Widgets/Views/TextView.h` | 1 | 0 | 17 |
| `src/Windows/Mux/MuxPaneJs.cpp` | 1 | 0 | 0 |

## 4. 未触及池（按体积降序前 50，下一批候选）

| 地址 | 语料名 | 字节 |
|---|---|---:|
| `00a418c4` | `s_line_caret_remote_a418c4` | 37951 |
| `00b6f940` | `FUN_00b6f940` | 19043 |
| `00a96e50` | `FUN_00a96e50` | 18517 |
| `00b64410` | `FUN_00b64410` | 16807 |
| `00b75a50` | `FUN_00b75a50` | 15761 |
| `00b6a690` | `FUN_00b6a690` | 13667 |
| `008a1106` | `King::registerBarsAndPanes` | 12455 |
| `0057196a` | `s_transfer_localFileSystem_57196a` | 12007 |
| `00535d00` | `s_terminal_ansiBrightMagenta_535d00` | 11834 |
| `00adaac0` | `FUN_00adaac0` | 11459 |
| `00bd6630` | `FUN_00bd6630` | 10955 |
| `008f3a74` | `FUN_008f3a74` | 10735 |
| `00ac1ef0` | `FUN_00ac1ef0` | 10516 |
| `007907ec` | `FUN_007907ec` | 10061 |
| `00bddb40` | `FUN_00bddb40` | 9775 |
| `00bd9170` | `FUN_00bd9170` | 9760 |
| `0058722a` | `s_transfer_currentItemName_58722a` | 9233 |
| `005ffd00` | `FUN_005ffd00` | 9218 |
| `00bbbbd0` | `FUN_00bbbbd0` | 9093 |
| `00bbe010` | `FUN_00bbe010` | 9053 |
| `008acf1a` | `FUN_008acf1a` | 8808 |
| `00636f96` | `qmap_insert_string_string` | 8808 |
| `00598cc8` | `FUN_00598cc8` | 8808 |
| `00bdb7d0` | `FUN_00bdb7d0` | 8732 |
| `00ac4960` | `FUN_00ac4960` | 8724 |
| `005d28b6` | `FUN_005d28b6` | 8699 |
| `005cc94e` | `FUN_005cc94e` | 8699 |
| `009bb4fa` | `FUN_009bb4fa` | 8683 |
| `00aca5f0` | `FUN_00aca5f0` | 8564 |
| `00963d50` | `FUN_00963d50` | 8532 |
| `00ace3a0` | `FUN_00ace3a0` | 8417 |
| `008a7406` | `cglobalconfig_destructor_full` | 8355 |
| `00bc2bf0` | `FUN_00bc2bf0` | 8342 |
| `006ac4e2` | `FUN_006ac4e2` | 8311 |
| `009312ce` | `FUN_009312ce` | 8224 |
| `006bb240` | `FUN_006bb240` | 7992 |
| `00b31550` | `FUN_00b31550` | 7924 |
| `00a18220` | `ExpectTask_dtor_deleting` | 7831 |
| `00a1a0c0` | `ExpectTask_dtor` | 7815 |
| `008b0530` | `FUN_008b0530` | 7767 |
| `005d0a4e` | `FUN_005d0a4e` | 7738 |
| `005cebe6` | `FUN_005cebe6` | 7738 |
| `00b687b0` | `FUN_00b687b0` | 7731 |
| `00b509a0` | `FUN_00b509a0` | 7703 |
| `00568022` | `pattern_table_fill_rows` | 7640 |
| `00ac6c70` | `kitty_input_state_advance` | 7539 |
| `0091b3d6` | `FUN_0091b3d6` | 7500 |
| `00ac0120` | `kitty_csi_dispatch` | 7395 |
| `00549240` | `s_session_protocol_549240` | 7347 |
| `008b5f04` | `FUN_008b5f04` | 7331 |

## 5. RTTI 类清单（380 个：已建 192 / 未建 188）

> 类名来自 `tools/re/data/rtti_classes.txt`（typeinfo 扫出，**含上游类**）
> 上游类（Scintilla 的 `RunStyles*`/`GapBuffer*`/`UPartitioning`、
> universalchardet 的 `ns*Prober`、标准库类型）**不是逆向目标**，
> 它们出现在此表只表示「二进制里有多态类」，不代表欠债。
> 已建 = 我方有同名（或去 `Face` 后缀同名）的声明文件。
> 后两列是**文件级**计数：一个文件装多个类时(如 `TriggerPageFace.h` 装 13 个)，
> 这几个类会显示同一组数字 —— 二进制里无法把地址反推到具体类，故不伪造类级数字。

| 类 | 文件 | 该文件真实现 | 该文件半成品 |
|---|---|---:|---:|
| `AddressBar` | `src/Widgets/Bars/AddressBarFace.h` | 2 | 0 |
| `AppletBar` | `src/Widgets/Bars/AppletBarFace.h` | 2 | 0 |
| `ApplicationTheme` | `src/App/ApplicationTheme.h` | 5 | 0 |
| `BreadCrumb` | `src/Widgets/Bars/BreadCrumbFace.h` | 4 | 0 |
| `ButtonBar` | `src/Widgets/Bars/ButtonBarFace.h` | 0 | 0 |
| `ButtonBarPanel` | `src/Widgets/Bars/ButtonBarPanelFace.h` | 0 | 0 |
| `CEditorConfig` | `src/Editor/Config/CEditorConfigFace.h` | 0 | 0 |
| `CGlobalConfig` | `src/Editor/Config/CGlobalConfigFace.h` | 11 | 0 |
| `CTerminalConfig` | `src/Editor/Config/CTerminalConfig.h` | 3 | 0 |
| `CaptureGroupsButton` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `CheckList` | `src/Widgets/Controls/CheckListFace.h` | 0 | 0 |
| `CloseButtonAction` | `src/Actions/CloseButtonActionFace.h` | 0 | 0 |
| `ColorButton` | `src/Widgets/Controls/ColorButtonFace.h` | 0 | 0 |
| `ComboBox` | `src/Widgets/Controls/ComboBoxFace.h` | 0 | 0 |
| `CommanderRobot` | `src/Sessions/Commanders/CommanderRobotFace.h` | 0 | 0 |
| `CompleteList` | `src/Widgets/Controls/CompleteListFace.h` | 1 | 0 |
| `CompleteModel` | `src/Widgets/Controls/CompleteModelFace.h` | 1 | 0 |
| `Completer` | `src/Widgets/Controls/CompleterFace.h` | 5 | 2 |
| `CountWidgetAction` | `src/Actions/ToolbarWidgetActions.h` | 0 | 0 |
| `CustomLinkTriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `CustomMenuTriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `DefaultEditorDialog` | `src/Widgets/Dialogs/DefaultEditorDialogFace.h` | 1 | 0 |
| `DirScaner` | `src/Utility/DirScanerFace.h` | 2 | 0 |
| `DoubleSpinBox` | `src/Widgets/Controls/SpinBoxFaces.h` | 0 | 0 |
| `EditWidgetAction` | `src/Actions/ToolbarWidgetActions.h` | 0 | 0 |
| `EditorWindow` | `src/Windows/Kit/KitWindowFactory.h` | 10 | 0 |
| `EnvironmentDialog` | `src/Widgets/Dialogs/EnvironmentDialogFace.h` | 2 | 0 |
| `ExplorerList` | `src/Widgets/Controls/ExplorerListFace.h` | 0 | 0 |
| `FileReader` | `src/Editor/Config/FileReaderFace.h` | 0 | 0 |
| `FileSystemItem` | `src/Widgets/Views/FileSystemItemFace.h` | 0 | 0 |
| `FileView` | `src/Widgets/Views/FileViewFace.h` | 0 | 0 |
| `FileWatcher` | `src/Utility/FileWatcherFace.h` | 1 | 0 |
| `FilerPane` | `src/Widgets/Panes/FilerPane.h` | 0 | 0 |
| `FilterEdit` | `src/Widgets/Controls/SearchEditFace.h` | 10 | 1 |
| `FilterEditAction` | `src/Actions/FilterEditActionFace.h` | 0 | 0 |
| `FocusModeDialog` | `src/Widgets/Dialogs/FocusModeDialogFace.h` | 2 | 1 |
| `FontComboBox` | `src/Widgets/Controls/FontComboBoxFace.h` | 0 | 0 |
| `ForwardingHandler` | `src/Sessions/Tunnels/ForwardingHandlerFace.h` | 0 | 0 |
| `GroupWidgetAction` | `src/Actions/ToolbarWidgetActions.h` | 0 | 0 |
| `HighlightTextBar` | `src/Widgets/Bars/HighlightTextBarFace.h` | 0 | 0 |
| `HighlightTextBarAction` | `src/Widgets/Bars/HighlightTextBarActionFace.h` | 0 | 0 |
| `HighlightTextDialog` | `src/Widgets/Dialogs/HighlightTextDialogFace.h` | 2 | 1 |
| `HighlightTextTriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `HoverButton` | `src/Widgets/Controls/HoverButtonFace.h` | 2 | 0 |
| `HtmlLabel` | `src/Widgets/Controls/HtmlLabelFace.h` | 0 | 0 |
| `HtmlList` | `src/Widgets/Controls/HtmlListFace.h` | 1 | 1 |
| `IconSelector` | `src/Widgets/Controls/IconSelectorFace.h` | 0 | 0 |
| `InsertFileDialog` | `src/Widgets/Dialogs/InsertFileDialogFace.h` | 3 | 1 |
| `InsertFilePage` | `src/Widgets/Dialogs/SimpleDialogs.h` | 0 | 0 |
| `IntValidator` | `src/Widgets/Controls/IntValidatorFace.h` | 0 | 0 |
| `IntervalWidgetAction` | `src/Actions/ToolbarWidgetActions.h` | 0 | 0 |
| `JsEngine` | `src/App/JsEngine.h` | 8 | 0 |
| `KitBar` | `src/Windows/Kit/KitBar.h` | 9 | 0 |
| `KitDock` | `src/Windows/Kit/KitDockFace.h` | 13 | 0 |
| `KitPane` | `src/Widgets/Panes/KitPaneFace.h` | 0 | 0 |
| `KitWindow` | `src/Windows/Kit/KitWindowFace.h` | 26 | 0 |
| `LabelAction` | `src/Actions/LabelActionFace.h` | 0 | 0 |
| `LineEdit` | `src/Widgets/Controls/LineEditFace.h` | 0 | 0 |
| `ListView` | `src/Widgets/Controls/ListViewFace.h` | 2 | 0 |
| `ListWidget` | `src/Widgets/Controls/ListWidgetFace.h` | 1 | 0 |
| `LocalFile` | `src/Sessions/Transfers/LocalFileFace.h` | 0 | 0 |
| `LocalFileSystemItem` | `src/Widgets/Views/LocalFileSystemItemFace.h` | 0 | 0 |
| `LocalTransfer` | `src/Sessions/Transfers/FileAbstractions.h` | 0 | 0 |
| `LockScreen` | `src/Widgets/Views/LockScreenFace.h` | 9 | 3 |
| `LogDialog` | `src/Widgets/Dialogs/LogDialogFace.h` | 1 | 1 |
| `LoginWizard` | `src/Widgets/Dialogs/LoginWizardFace.h` | 0 | 0 |
| `MainWindow` | `src/Windows/Kit/MainWindowFace.h` | 4 | 0 |
| `MarkStyleWidget` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `MaskDialog` | `src/Widgets/Dialogs/SimpleDialogs.h` | 0 | 0 |
| `MasterPasswordDialog` | `src/Widgets/Dialogs/MasterPasswordDialogFace.h` | 1 | 1 |
| `Menu` | `src/Widgets/Controls/MenuFace.h` | 0 | 0 |
| `MessageBar` | `src/Widgets/Bars/MessageBarFace.h` | 1 | 0 |
| `Modem` | `src/Sessions/Transfers/Modem.h` | 17 | 1 |
| `ModemProcess` | `src/Sessions/Transfers/ModemProcess.h` | 10 | 1 |
| `MuxPane` | `src/Windows/Mux/MuxPane.h` | 3 | 0 |
| `MuxPaneGroup` | `src/Windows/Mux/MuxPaneGroup.h` | 31 | 0 |
| `MuxWindow` | `src/Windows/Mux/MuxWindow.h` | 24 | 0 |
| `NameDialog` | `src/Widgets/Dialogs/NameDialogFace.h` | 4 | 0 |
| `OneKeyDialog` | `src/Widgets/Dialogs/OneKeyDialogFace.h` | 2 | 0 |
| `OutlinePane` | `src/Widgets/Panes/OutlinePaneFace.h` | 1 | 0 |
| `OutputPane` | `src/Widgets/Panes/OutputPane.h` | 1 | 0 |
| `PasswordDialog` | `src/Widgets/Dialogs/PasswordDialogFace.h` | 1 | 1 |
| `PasswordMeter` | `src/Widgets/Controls/PasswordMeterFace.h` | 0 | 0 |
| `PasteDialog` | `src/Widgets/Dialogs/PasteDialogFace.h` | 1 | 1 |
| `PathEdit` | `src/Widgets/Controls/PathEditFace.h` | 0 | 0 |
| `PeriodTimer` | `src/Utility/PeriodTimerFace.h` | 0 | 0 |
| `PlainTextEditPanel` | `src/Widgets/Controls/PlainTextEditPanelFace.h` | 0 | 0 |
| `PlaySoundDialog` | `src/Widgets/Dialogs/PlaySoundDialogFace.h` | 2 | 1 |
| `PlaySoundTriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `PopupWidget` | `src/Widgets/PopupWidget.h` | 0 | 0 |
| `Process` | `src/Utility/ProcessFace.h` | 0 | 0 |
| `ProfileDialog` | `src/Widgets/Dialogs/ProfileDialogFace.h` | 2 | 2 |
| `ProxyCommandSocket` | `src/Sessions/Bridges/ProxyCommandSocket.h` | 12 | 0 |
| `ProxyServer` | `src/Sessions/Transports/ProxyServerFace.h` | 0 | 0 |
| `QuickBar` | `src/Widgets/Bars/BarFaces.h` | 3 | 0 |
| `QuickDialog` | `src/Widgets/Dialogs/QuickDialogFace.h` | 1 | 1 |
| `RemoteFileDialog` | `src/Widgets/Dialogs/RemoteFileDialogFace.h` | 3 | 0 |
| `RemoteFileSystemModel` | `src/Widgets/Views/RemoteFileSystemModelFace.h` | 0 | 0 |
| `RunCommandTriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `RunToolDialog` | `src/Widgets/Dialogs/RunToolDialogFace.h` | 2 | 0 |
| `SafeEdit` | `src/Widgets/Controls/SafeEditFace.h` | 0 | 0 |
| `ScrollBar` | `src/Widgets/ScrollBar.h` | 0 | 0 |
| `SearchEdit` | `src/Widgets/Controls/SearchEditFace.h` | 10 | 1 |
| `SearchEngineDialog` | `src/Widgets/Dialogs/SearchEngineDialogFace.h` | 0 | 0 |
| `SearchPane` | `src/Widgets/Panes/SearchPaneFace.h` | 1 | 0 |
| `SendTextTriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `SenderPane` | `src/Widgets/Panes/SenderPaneFace.h` | 0 | 0 |
| `SerialBridge` | `src/Sessions/Bridges/SerialBridge.h` | 0 | 0 |
| `SerialCommander` | `src/Sessions/Commanders/SerialCommander.h` | 0 | 0 |
| `SerialSession` | `src/Sessions/Transports/SerialSession.h` | 0 | 0 |
| `SessionDialog` | `src/Widgets/Dialogs/SessionDialogFace.h` | 4 | 0 |
| `SessionGroupDialog` | `src/Widgets/Dialogs/SessionGroupDialogFace.h` | 2 | 1 |
| `SessionLogger` | `src/Sessions/Core/SuperSessionPrivate.h` | 7 | 0 |
| `SessionPane` | `src/Widgets/Panes/SessionPaneFace.h` | 0 | 0 |
| `SessionThread` | `src/Sessions/Core/SessionThreadFace.h` | 0 | 0 |
| `SessionTriggerDialog` | `src/Widgets/Dialogs/SessionTriggerDialogFace.h` | 2 | 1 |
| `SettingDialog` | `src/Widgets/Dialogs/SettingDialogFace.h` | 2 | 1 |
| `SftpFile` | `src/Sessions/Transfers/FileAbstractions.h` | 0 | 0 |
| `SftpFileSystemItem` | `src/Widgets/Views/SftpFileSystemItemFace.h` | 0 | 0 |
| `SftpFolder` | `src/Sessions/Transfers/SftpFolderFace.h` | 0 | 0 |
| `SharedConfigHandler` | `src/Editor/Config/CGlobalConfigFace.h` | 11 | 0 |
| `ShellBridge` | `src/Sessions/Bridges/ShellBridge.h` | 0 | 0 |
| `ShellCommander` | `src/Sessions/Commanders/ShellCommander.h` | 0 | 0 |
| `ShellPane` | `src/Widgets/Panes/ShellPaneFace.h` | 0 | 0 |
| `ShellProcess` | `src/Pty/ShellProcess.h` | 0 | 0 |
| `ShellSession` | `src/Sessions/Transports/ShellSession.h` | 0 | 0 |
| `ShowTooltipTriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `SideButton` | `src/Widgets/Controls/SideButtonFace.h` | 2 | 0 |
| `SideSeparator` | `src/Widgets/Controls/SideSeparatorFace.h` | 0 | 0 |
| `SlipButton` | `src/Actions/SlipButtonFace.h` | 7 | 0 |
| `SlipButtonAction` | `src/Actions/SlipButtonActionFace.h` | 0 | 0 |
| `SpinBox` | `src/Widgets/Controls/SpinBoxFaces.h` | 0 | 0 |
| `Splitter` | `src/Widgets/Splitter.h` | 1 | 0 |
| `SplitterGroup` | `src/Widgets/Controls/SplitterGroup.h` | 8 | 0 |
| `SshBridge` | `src/Sessions/Bridges/SshBridge.h` | 0 | 0 |
| `SshCommander` | `src/Sessions/Commanders/SshCommander.h` | 0 | 0 |
| `SshExecutor` | `src/Sessions/Transports/SshExecutorFace.h` | 0 | 0 |
| `SshSession` | `src/Sessions/Transports/SshSession.h` | 0 | 0 |
| `SshSocket` | `src/Sessions/Transports/SshSocketFace.h` | 1 | 0 |
| `StatusBar` | `src/Widgets/Bars/StatusBarFace.h` | 4 | 0 |
| `SuperApplication` | `src/App/SuperApplicationFace.h` | 7 | 0 |
| `SuperBridge` | `src/Sessions/Bridges/SuperBridge.h` | 0 | 0 |
| `SuperCommander` | `src/Sessions/Commanders/SuperCommander.h` | 3 | 0 |
| `SuperFile` | `src/Sessions/Transfers/FileAbstractions.h` | 0 | 0 |
| `SuperFolder` | `src/Sessions/Transfers/SuperFolderFace.h` | 0 | 0 |
| `SuperKeymap` | `src/Editor/Engine/SuperKeymap.h` | 4 | 0 |
| `SuperSession` | `src/Sessions/Core/SuperSession.h` | 3 | 0 |
| `SuperTransfer` | `src/Sessions/Transfers/FileAbstractions.h` | 0 | 0 |
| `SwitchButton` | `src/Widgets/Controls/SwitchButtonFace.h` | 2 | 0 |
| `SyncInputCenter` | `src/Widgets/Controls/SyncInputCenterFace.h` | 0 | 0 |
| `SyncInputDialog` | `src/Widgets/Dialogs/SyncInputDialogFace.h` | 3 | 1 |
| `TabBar` | `src/Widgets/Controls/TabGroup.h` | 44 | 1 |
| `TabGroup` | `src/Widgets/Controls/TabGroup.h` | 44 | 1 |
| `TableItemDialog` | `src/Widgets/Dialogs/TableItemDialogFace.h` | 1 | 0 |
| `TargetsWidgetAction` | `src/Actions/ToolbarWidgetActions.h` | 0 | 0 |
| `TcpBridge` | `src/Sessions/Bridges/TcpBridge.h` | 9 | 0 |
| `TcpCommander` | `src/Sessions/Commanders/TcpCommander.h` | 0 | 0 |
| `TcpSession` | `src/Sessions/Transports/TcpSession.h` | 0 | 0 |
| `TelnetCommander` | `src/Sessions/Commanders/TelnetCommander.h` | 5 | 0 |
| `TelnetProtocol` | `src/Protocols/TelnetProtocol.h` | 0 | 0 |
| `TelnetSession` | `src/Sessions/Transports/TelnetSession.h` | 8 | 0 |
| `TerminalView` | `src/Widgets/Views/TerminalView.h` | 0 | 0 |
| `TerminalWidget` | `src/Widgets/Views/TerminalWidget.h` | 0 | 0 |
| `TerminalWindow` | `src/Windows/Kit/KitWindowFactory.h` | 10 | 0 |
| `TextEdit` | `src/Widgets/Views/TextEdit.h` | 0 | 0 |
| `TextMarkDialog` | `src/Widgets/Dialogs/TextMarkDialogFace.h` | 2 | 0 |
| `TextMarkTablePanel` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `TextView` | `src/Widgets/Views/TextView.h` | 1 | 0 |
| `ToolButton` | `src/Widgets/Controls/ToolButtonFace.h` | 1 | 0 |
| `Tools` | `src/Widgets/Controls/ToolsFace.h` | 0 | 0 |
| `TransferBar` | `src/Widgets/Bars/BarFaces.h` | 3 | 0 |
| `TransferLabel` | `src/Widgets/Bars/TransferLabelFace.h` | 0 | 0 |
| `TransferPane` | `src/Widgets/Panes/TransferPane.h` | 0 | 0 |
| `TransferTask` | `src/Sessions/Transfers/TransferTaskFace.h` | 0 | 0 |
| `TreeListModel` | `src/Widgets/Views/TreeListModelFace.h` | 0 | 0 |
| `TriggerActionDialog` | `src/Widgets/Dialogs/TriggerActionDialogFace.h` | 2 | 1 |
| `TriggerActionEditPanel` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `TriggerActionWidget` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `TriggerDialog` | `src/Widgets/Dialogs/TriggerDialogFace.h` | 33 | 0 |
| `TriggerPage` | `src/Widgets/Settings/TriggerPageFace.h` | 38 | 0 |
| `TunnelCenter` | `src/Sessions/Tunnels/TunnelCenterFace.h` | 0 | 0 |
| `TunnelDialog` | `src/Widgets/Dialogs/TunnelDialogFace.h` | 0 | 0 |
| `TunnelSession` | `src/Sessions/Tunnels/TunnelSessionFace.h` | 0 | 0 |
| `UndoListAction` | `src/Actions/UndoListActionFace.h` | 0 | 0 |
| `UnitWidgetAction` | `src/Actions/ToolbarWidgetActions.h` | 0 | 0 |
| `UnixPty` | `src/Pty/UnixPty.h` | 0 | 0 |
| `WidgetList` | `src/Widgets/Controls/WidgetListFace.h` | 0 | 0 |
| `WindowOpacityDialog` | `src/Widgets/Dialogs/WindowOpacityDialogFace.h` | 2 | 0 |
| `XModem` | `src/Sessions/Transfers/XModem.h` | 0 | 1 |
| `XYModem` | `src/Sessions/Transfers/XYModem.h` | 17 | 1 |
| `YModem` | `src/Sessions/Transfers/YModem.h` | 0 | 1 |
| `ZModem` | `src/Sessions/Transfers/ZModem.h` | 8 | 0 |

**未建 188 个**：

`ActionHandler`, `AddressListModel`, `ApplicationPalette`, `Big5DistributionAnalysis`, `BreadButton`, `BreadEdit`, `BreadMenu`, `ByteArrayBimap`, `CKitConfig`, `CSuperBuffer32`, `CSuperBuffer64`, `CSuperBufferBase`, `CategoryPage`, `CategoryTree`, `CharDistributionAnalysis`, `CheckDelegate`, `CheckEditor`, `CheckListPanel`, `CheckListSortFilterProxyModel`, `ComboBoxDelegate`, `CommandListModel`, `CommandPalette`, `ConnectionTriggerPage`, `CyclicMemoryPool`, `DocWatcher`, `DocumentTaskRunner`, `DynamicLibrary`, `DynamicLibraryImpl`, `EUCJPContextAnalysis`, `EUCJPDistributionAnalysis`, `EUCKRDistributionAnalysis`, `EUCTWDistributionAnalysis`, `EditDelegate`, `Editor`, `EditorView`, `EditorViewConfig`, `ExpectTask`, `ExplorerDelegate`, `ExplorerEditor`, `ExplorerPane`, `FileDialog`, `FileGrep`, `FileScaner`, `FileSystemModel`, `FileSystemSortFilterProxyModel`, `FileTree`, `FocusModeController`, `FontPreviewDelegate`, `FontPreviewWidget`, `ForwardingCenter`, `GB2312DistributionAnalysis`, `Grep`, `GrepView`, `GrepViewConfig`, `HtmlAbstractModel`, `HtmlDelegate`, `HtmlListModel`, `JapaneseContextAnalysis`, `JumpServer`, `KitGroup`, `KitView`, `LinePartition`, `ListItemDelegate`, `ListModel`, `ListPanel`, `LocalFolder`, `MediaCenter`, `ModemFileDialog`, `MuxDesktop`, `OneKeyCenter`, `OutlineTree`, `OutlineTreeModel`, `Partitioning`, `PlainTextEdit`, `PlaySoundWidget`, `ProxyStyle`, `QJSValue`, `QSharedData`, `RGBAImage`, `RunStylesInterface`, `SJISContextAnalysis`, `SJISDistributionAnalysis`, `ScanTask`, `SciCalltipClickEvent`, `SciCharAddedEvent`, `SciCompleterEvent`, `SciContainerChangeEvent`, `SciDecorationChangeEvent`, `SciExpectEvent`, `SciFocusEvent`, `SciHighlightEvent`, `SciHoverEvent`, `SciMacroRecordEvent`, `SciMarginChangeEvent`, `SciMarginClickEvent`, `SciMouseEvent`, `SciNavigateEvent`, `SciPaintEvent`, `SciPasteEvent`, `SciPreview`, `SciSaveStateChangeEvent`, `SciSchemeChangeEvent`, `SciScrollBarMarkEvent`, `SciScrollbar`, `SciShownLinesChange`, `SciTextChangeEvent`, `SciTextClientResizeEvent`, `SciTextMultiChangeEvent`, `SciTryModifyReadOnlyEvent`, `SciZoomEvent`, `ScintillaBase`, `ScintillaEditBase`, `ScintillaEditWatcher`, `ScintillaQt`, `SessionConnector`, `SessionWatcher`, `SftpTransfer`, `SharedConfig`, `ShellExecutor`, `SkipPartition`, `Snapshot`, `Snapshot32`, `Snapshot64`, `SortFilterProxyModel`, `SparsePartition`, `SshAuthOperator`, `SshOperator`, `SuperAction`, `SuperProtocol`, `SuperPty`, `SuperTerm`, `SuperTranslator`, `Surface`, `SurfaceImpl`, `SvgIconEngine`, `TablePanel`, `TableWidget`, `TerminalKeyboard`, `TerminalSender`, `TerminalViewConfig`, `TerminalWatcher`, `TextArrayData`, `ThemeChangeEvent`, `Tmux`, `ToolRunner`, `TransferCenter`, `TransferDelegate`, `TreeItemDelegate`, `TreeModel`, `TreeView`, `TriggerCenter`, `TriggerData`, `Uint16RunStyles`, `Uint16SkipRunStyles`, `Uint32Bimap`, `Uint32PieceTable`, `Uint32RunStyles`, `Uint32SkipRunStyles`, `Uint64RunStyles`, `Uint64SkipRunStyles`, `Uint8PieceTable`, `Uint8RunStyles`, `Uint8SkipRunStyles`, `UndoList`, `UndoModel`, `UniversalChardet`, `UuidCenter`, `VBoxLayout`, `WidgetAction`, `WidgetContainer`, `WidgetDelegate`, `Window`, `XServerCenter`, `nsBig5Prober`, `nsCharSetProber`, `nsEUCJPProber`, `nsEUCKRProber`, `nsEUCTWProber`, `nsEscCharSetProber`, `nsGB18030Prober`, `nsHebrewProber`, `nsLatin1Prober`, `nsMBCSGroupProber`, `nsSBCSGroupProber`, `nsSJISProber`, `nsSingleByteCharSetProber`, `nsUTF8Prober`, `nsUniversalDetector`
