# gui-map — 界面重建范围地图(批 187 盘点 / 批 493 收官,2026-11-16)

> 用户纪律:界面按语料重建(控件树构建序列逐段转写),原版截图只作对表证据,
> 禁止按样造形/占位/发明菜单项(铁律 3/6)。本文件 = 全部界面批的总账依据。

## 目录

**范围七节(批 187 盘点基线)**
`① 主窗装配族` · `② 菜单族` · `③ 工具栏/状态栏族` · `④ 对话框/弹窗族` ·
`⑤ 设置页族` · `⑥ dock/浮停/标签` · `⑦ 我方现状对照` · `重建优先级`

**落地与勘正增量(按批号递增)**
| 批段 | 主题 |
|---|---|
| 192-235 | 七节首批落地 + 勘正 |
| 236-273 | 对话框/设置页第二批 |
| 313-331 | P5 对话框族 + Paste/Login/RunTool 数据面 |
| 333-341 | 菜单族右鍵四件 + 设置页两件 + 触发器基类 |
| 342-345 | 触发器页族全谱 |
| 346-348 | 归属勘定 → TriggerDialog 全谱 + 通用 NameDialog |
| 349-358 | TriggerDialog 行为面 + 菜单机械 + expect 数据面 |
| 359-368 | TriggerDialog 收口 + 记录布局定案 |
| 369-380 | 八个触发器页装配全数落地 |
| 381-390 | 页内件真类化 + 传输下拉 + 菜单懒构建 |
| 391-400 | ② 动作 DSL 地基 |
| **401-409** | **修复轮**(撤回批 393 的 `state` 归属误记、`getOrCreate` 判据、addRow 计数等 9 项) |
| 410-419 | ⑤ 页内件收口 + TunnelDialog 归属勘正 |
| 420-428 | 四个对话框 ctor + **0x72xxxx 归属图谱** |
| 429-438 | **对话框全清单**(28 → 后修正为 29) |
| 439-448 | ② 动作执行链闭环 + QuickBar/TransferBar |
| 449-455 | 样式件/线型表 + 两对话框接线 + 5c 尾钩定案 |
| 456-465 | 10 个对话框 build/wire 分工厘清 |
| 466-475 | 余下装配腿 + ⑥ 页签关钮机制闭环 |
| 476-484 | 工厂型 ctor 补入(29 个)+ 配置键面成批落 |
| 485-493 | ② 数据源落定(`wind.actions`+`user.actions`)+ 主窗接线 + 自绘控件族 |

> **读法**:七节 = 范围定义(稳定);下方增量段 = 每批的实读证据与勘正记录。
> 冲突时以 `tools/re/handoff.md` 勘正谱系为准。

## ① 主窗装配族(依赖序)
main(StartupChain)→ FUN_0075e0f8 765B 建 MainWindow(ctor 00768f44 475B →
delayedInit 00768cb6 → connectSignals 0076b9ec 1043B:0076663e pthread_once
类型注册 → 007662e6 109B 挂工具栏(f50=FUN_008b31b6 KitBar)+ 中央
QStackedWidget(f58)→ app/config 信号 → singleShot → 0076bdff screenChanged)。
KitWindow 页面:s_HistoryHints_7664a2 244B → kitWindowFactory 0089d752
(Editor/Terminal/Buy 三分支;ctor:TerminalWindow 00859902 296B/EditorWindow 域)
→ KitBar.addKit FUN_008b346e;KitWindow 真身 ctor FUN_008fc2f8 57B(薄转发);
**KitWindow 延迟装配 FUN_008d3cc2 296B**:008c9ee4(→FUN_006926a0→King::MenuBar
00693036 575B 建菜单栏)→ King::assembleCentralSplitters → 008cd822 → 008c9fc2 →
s_kit_startupSessions_8d2f7e 3122B(恢复 MenuBar/StatusBar/ToolBar 可见性 +
LastSessions splitter)。

## ② 菜单族
King::MenuBar 00693036;King::applyMenuShortcut 006a872d;toolbar 内菜单
s_ToolBarPopup_693470 3293B;右键:tabbar_contextMenu 0058e38a 1942B /
pane_showPopupMenu 008c3c6a 1044B / s_ShowMenu_7502f0 / trigger_buildMenu
0069a84e 1702B / slipButton_makeMenu 006af0da / colorMenu_addEntry 0070a56a +
showPopup 00719dee / toolbutton_menu_connect 00531966 / menu_action_timeout_show
005b1371 / s_MenuItemWidget_5b1c08 3727B;数据源 terminal/configs/menu.config
(784 行,Kit→Session/Edit/… 层级)。

## ③ 工具栏/状态栏族
toolbar_build 00694276 2164B(递归子栏;toolbar.config 45 行);
StatusBar_h8f24a8/h8f24e0(0029)+ statusbar.config 113 行(**JS init 脚本**,
button/widget 内嵌 JS);MessageBar_h8f7e70 175B。

## ④ 对话框/弹窗族
QMessageBox ~45 调用点(0017-0028)+ 自定义 question ctor 0028:24540 +
msgbox_buildRich 00615d00 918B + file_showErrorBox 00579ba0;对话框:TextMarkDialog
006f1036 175B、envDialog 006b3100 1109B、RunToolDialog ctor 00707f8e 1116B +
setupUi 00707ada 1098B、LoginWizard_setupUi 00590efa 1088B、pasteDialog 006dfd9e
1221B/00843050 789B、mux_renamePaneDialog 008df0a4 904B、dirCompareDialog
006ce8c2 1695B、save_file_dialog_exec 0076fb16 1412B、log_showSaveDialog
0070c15e、TunnelDialog_h9097b0 535B、SessionDialog/QuickDialog 小件、
TriggerAction/SessionGroup/WindowOpacity/Mask/TableItem/Profile Dialog(dtor 族
锚定);通用件:dialog_add_yn_combo 006ba04c、dialog_buttonsConnect 006c00ce
2230B、expectDialog_collectRows/saveRows、dialog_buildSpinForm 006f8590、
dialog_connectAcceptReject 0072bbe2/006f2852、dialog_loadWidgetValues 00737334、
window_closeChildDialogs 008c6cc2、PopupWidget_vt6 005a0b1a 1357B、
s_PropertyPopup_8bcba8 1289B。

## ⑤ 设置页族
壳 = 006f1036(search_page_build_layout 006f09ba 1498B + options_connectSignals
006edc90 1063B);导航 = settings_category_tree_create 006e9cd8 1520B +
CategoryTree/CategoryPage;页面引擎 = settings_loadWidgets 0072e4f6 /
connectSignals 00735056 / enableDependentWidgets 00736bfe / sync_action_combo
006fe450 / buildRadioGroup 0070bb32 / table_row_item 0071b02e /
TabSettings_map_freetree 00739f76 4449B;触发器 8 页(ConnectionTrigger/CustomLink/
CustomMenu/HighlightText/PlaySound/RunCommand/SendText/ShowTooltip,dtor
006f66fe-006f6b9c 邻域即 ctor);会话页 sessionpane_connect_rows 0073d836 3735B +
sessionpage_title 00725d66;设置值腿 = 6e7dda 4777B(0022.c:13181)。

## ⑥ dock/浮停/标签
MuxWindow ctor s_MuxWindow_8e0938 289B(0028:27695)+ dtor 0091e4ca;
MuxDesktop_h91d4a8 1389B;KitDock_h91a844 444B/KitBar_h91a622/KitGroup ctor
0091aca2 697B + KitGroup_vt6 008bdd66 3440B + map_freetree 008bf498 4449B;
KitView×3 + vt6 008c69fe;ExplorerPane_vt6 008c4446 1827B;s_RenamedTitle_8bb3e6
1693B/8bbab6 850B;mux_switch_kit_page 007317a6 1250B;TabGroup/TabBar 族
(008f6618/8f67a0/8f67fc);TerminalWindow_h911868 900B;周边:Splitter/BreadEdit/
BreadCrumb/SlipButton/Completer/FilterEdit/FileView/FileTree/ToolButton/
EditorView_h8fbe64 928B/TransferCenter/ForwardingCenter/IconSelector。

## ⑦ 我方现状对照
- 真身:Actions 全域(MuxWindow/TabGroup/MuxPaneGroup/StateStore/StartupChain/
  KitBar/KitWindowFactory/MainWindowFace/SuperApplicationFace);Widgets:
  SessionPane/SessionManager/OutputPane/FilerPane/TransferPane/EditorWindow/
  TerminalWindow/ViewBase/TextView/TerminalWidget+TerminalView/SplitterGroup。
- 引用档(face 壳):KitWindowFace/EditorWindow.h(槽空 cite)/SessionPane(槽框架)。
- 未触(absent):MenuBar/ToolBar 装配腿(00693036/00694276)、StatusBar、设置对话
  框全家(006f1036+⑤)、全部 QDialog 族(④)、LoginWizard/LockScreen、
  tabbar_contextMenu、pane_showPopupMenu、RenamedTitle、KitGroup 真身、
  statusbar.config JS 引擎。Widgets/PopupWidget = 自有文件零语料引用(候选
  对应 005a0b1a,未核不猜)。

## 重建优先级(依赖序)
P1 主窗装配腿(face 已有)→ KitWindow 延迟装配 008d3cc2 链(菜单栏+splitter
恢复,Phase 4c 门)。P2 菜单族 00693036 + menu.config 装载(ActionFactory✓)。
P3 工具栏 00694276 + toolbar.config;状态栏 + statusbar.config(需 JS 引擎✓)。
P4 设置壳 006f1036 + category_tree + 页面引擎五件(~11KB,单点收益最大)。
P5 对话框高频件(RunToolDialog/envDialog/pasteDialog/通用 dialog_* 件族)。
P6 标签/dock 真身(KitGroup/TabBar/RenamedTitle)。
- 证据不足:KitWindow ctor 008fc2f8 57B 疑薄转发(深装配在 008d3cc2);
  EditorWindow ctor 地址未取证(仅 0089d795 new 0xd0 锚);PopupWidget 语料
  对应未核。

---

## 落地增量(已拆出)

> 批 192-493 的 22 段落地/勘正记录已拆出 → **`docs/history/gui-map-log.md`**。
> 七节范围(上文)稳定;每批的实读证据与勘正在该日志里。
