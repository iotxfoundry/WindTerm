# src/Actions — 目录说明与**建议分组**

本目录是界面重建主战场:**64 个头 / 126 个文件 / ≈16.9K 行**,占全仓最大头。
文件暂时平铺(与语料一致 —— 二进制没有目录概念,我们的分层是自选的)。

## 1. 现有分组(按角色,共 5 类)

### 对话框(32)

`DefaultEditorDialogFace` `EnvironmentDialogFace` `ExpectDialogFace`
`FileDialogFace` `FocusModeDialogFace` `HelpDialogFace` `HighlightTextDialogFace`
`InsertFileDialogFace` `LogDialogFace` `MasterPasswordDialogFace` `NameDialogFace`
`OneKeyDialogFace` `PasswordDialogFace` `PasteDialogFace` `PlaySoundDialogFace`
`ProfileDialogFace` `ProfileDirDialogFace` `QuickDialogFace` `RemoteFileDialogFace`
`RunToolDialogFace` `SearchEngineDialogFace` `SessionDialogFace`
`SessionGroupDialogFace` `SessionTriggerDialogFace` `SettingDialogFace`
`SyncInputDialogFace` `TableItemDialogFace` `TextMarkDialogFace`
`TriggerActionDialogFace` `TriggerDialogFace` `TunnelDialogFace`
`WindowOpacityDialogFace`

### 设置页 / 页(4)

`SettingsFace`(纯静态工具,非原版类)`SettingsPageFace` `PasteSettingsPageFace`
`TriggerPageFace`

### 主窗 / Kit(10)

`KitWindowFace` `KitWindowAssemblyFace` `KitDockFace` `KitWindowFactory`
`MainWindowFace` `SuperApplicationFace` `StatusBarFace` `SlipButtonFace`
`LoginWizardFace` `TabGroup`

### 菜单 / 工具栏 / 动作(4)

`ActionFactory` `ActionRegistryFace` `ToolBarBuilder` `ThemeIcons`

### Mux / 装配链 / 其余(14)

`KitBar` `MuxWindow` `MuxPane` `MuxPaneGroup` `MuxPaneJs` `MuxPaneView`
`SplitterGroup` `StartupChain` `StateStore` `JsEngine` `SearchPanelFace`
`MsgBoxFace` `TransferAskFace` `TunnelFace`

## 2. 是否要拆成子目录?——**等到首次编译通过后再拆**

现在搬会踩两个坑,且都**不可验证**(铁律 7:不编译):

| 坑 | 说明 |
|---|---|
| **moc 静默漏扫** | `CMakeLists.txt` 里 moc 头曾是**非递归** `GLOB`(已于 2026-11-16 改为 `GLOB_RECURSE`),否则一进子目录 `Q_OBJECT` 类就不生成 metaobject,报错要到链接/运行期才现形 |
| **裸文件名 include** | 61 处 `#include "XxxFace.h"` 是裸文件名,搬运需同步改路径(或给每个子目录加 include 目录) |

**时机**:收尾期首次编译通过后。那时有两条硬信息可用 ——
① 编译/链接会立刻暴露漏改的 include;② 依赖图能说明哪些类真的一起实例化,
分组不是凭语义猜。

**判据**(拆的时候按这个,不要按字母表):同组 = 同一装配链上一起出现的类。
例如 `TriggerPageFace` / `TriggerDialogFace` / `TriggerActionDialogFace` 三者共用
`FUN_006f2dd4` 一族,天然一组。

## 3. 不动代码就能拿到的收益

上面 §1 就是**索引**。要查某个对话框直接看这里,不用 `ls | grep`。
新增文件时补进对应小节(一行),并在头注释写清语料入口地址。
