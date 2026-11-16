# src/Actions — 目录说明

界面重建主战场:**64 个头 / 126 个文件 / ≈17K 行**,全仓最大目录。
2026-11-16 按角色分为 5 个子目录 + 根目录(装配链与基础件)。

## 1. 结构

| 目录 | 头 | 内容 |
|---|---|---|
| `Dialogs/` | **33** | 全部 `*DialogFace`(32)+ `MsgBoxFace`(消息框自由函数) |
| `Settings/` | **4** | `SettingsFace`(纯静态工具,非原版类)`SettingsPageFace` `PasteSettingsPageFace` `TriggerPageFace` |
| `Kit/` | **12** | `KitWindowFace` `KitWindowAssemblyFace` `KitDockFace` `KitWindowFactory` `MainWindowFace` `SuperApplicationFace` `StatusBarFace` `SlipButtonFace` `LoginWizardFace` `TabGroup` `KitBar` `SplitterGroup` |
| `Menu/` | **4** | `ActionFactory` `ActionRegistryFace` `ToolBarBuilder` `ThemeIcons` |
| `Mux/` | **5** | `MuxWindow` `MuxPane` `MuxPaneGroup` `MuxPaneJs` `MuxPaneView` |
| 根 | **6** | `StartupChain`(启动装配链)`StateStore`(窗口状态)`JsEngine`(JS 桥)`SearchPanelFace` `TransferAskFace` `TunnelFace` |

**归类判据**:同目录 = 同一装配链上一起出现的类。例:`TriggerPageFace` /
`TriggerDialogFace` / `TriggerActionDialogFace` 共用 `FUN_006f2dd4` 一族,
但后者是对话框 → 前两者在 `Settings/`,后者在 `Dialogs/`。

## 2. include 约定

`src/` 是 include 根(见 `CMakeLists.txt` 的 `WT_INCLUDES`),因此**跨目录一律写
根相对路径**:

```cpp
#include "Actions/Dialogs/KitDockFace.h"   // ✅ 任何位置都成立
#include "Actions/StateStore.h"            // ✅ 根目录件同样带 Actions/ 前缀
#include "KitDockFace.h"                   // ⚠ 只在同目录内成立
```

`src/Actions` **不在** `WT_INCLUDES` 里 —— 裸文件名只在同目录内可解析。
新增文件时:`*.cpp` 用全路径 include,避免因再分层而失效。

## 3. 构建侧

`CMakeLists.txt` 用 `GLOB_RECURSE` 收源文件与 **moc 头**,所以子目录零配置。
(2026-11-16 修:原 moc 头用非递归 `GLOB`,一进子目录 `Q_OBJECT` 类会静默不进
moc,且不编译时无从发现。)

## 4. 历史路径

`docs/history/` 下 2026-11-16 之前的批次日志引用的是**平铺路径**
(`src/Actions/XxxFace.h`)。历史不重写,查旧批次时按文件名 `find` 即可。
