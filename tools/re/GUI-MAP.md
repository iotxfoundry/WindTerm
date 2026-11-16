# GUI-MAP — 界面重建范围地图(批 187 盘点,2026-11-15)

> 用户纪律:界面按语料重建(控件树构建序列逐段转写),原版截图只作对表证据,
> 禁止按样造形/占位/发明菜单项(铁律 3/6)。本文件 = 全部界面批的总账依据。

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

## 追加:批 192-235 落地与勘正(2026-11-16)

> 本节 = 已真身化的语料面索引(后续批直接引用,勿重复推导)。
> 铁律 7:全部未过编译门。

### 主窗/装配(P1)
- `008d3cc2`(296B)延迟装配门:gate +0x30 → 菜单栏 → 状态栏 → 中央树 →
  钩 +0x210 → 三连线(008cd822,cited 槽)→ 清 gate → property
  "History"/"HistoryHints"(0x11820e8/0x11820e0 实读)→ startupSessions →
  失败 +0x208 / 尾 +0x250。落 `KitWindowFace::kitWindowAssembleDeferred`。
- `008c9ee4`(159B)菜单栏腿 / `008c9f8c`(54B)状态栏腿 /
  `King::assembleCentralSplitters`(1010B)**中央七槽树**:
  `+0x68[+0x58[+0x38,+0x60[+0x48],+0x40],+0x50]`(asm 还原接收者),
  朝向 0x38/0x40/0x60/0x68=Vertical,sizes [1000,4000,1000]/[4000,2000]。
- 槽位访问族:id 1/2/8 ↔ `+0x38/+0x40/+0x50`;id 1·2 经 +0x58 idx0/2,
  id 8 经 (+0x70==1 ? +0x68 : +0x60) idx1(`008ca096/b8/de/120/168/170`)。
- `008ce100`(244B)展开/收起(+0x50 findChildren<KitDock> 同步展开钮);
  `008ca17a`(110B)子件槽恢复。
- 字段族(ctor 0x8cc6ba-c6f7 实读):+0x30 WORD=0x0101(门/旗标)/
  +0x38..+0x68 七槽 / **+0x70 BYTE 语义勘正** = states 段写入的判选位
  (pane+0xe = 0xe*8 = 0x70,双源)。

### 面板/页体系(P2)
- 面板名归一 `0089ede8`+`0089ebe2`:不以 "Pane" 结尾(忽略大小写)则追加,
  首字母大写。
- 面板工厂 `s_ExplorerPane_89eed8`(1185B):归一名 → findChild 命中即返;
  **9 条分派表**(Explorer 0x58/Filer 0x78/Outline 0x90/Output 0x48/
  Search 0x148/Sender 0xa8/Session 0x68/Shell 0x60/Transfer 0x60)。
- 页挂 `008b8226`(399B)/页恢复 `008b881c`(485B)/页显 `008b8a26`+`008b8abe`/
  批量 `008b8acc`/查名 `008b84b6`/摘页 `008b83dc`+`005ab2cc`/开关 `008b8b7c`/
  按说明插 `008b8bb8`+`005abce4`(First/Last/Before/After/数字)/按名摘 `008b85ba`。
- 恢复链单页腿(asm 0x8d3234-3260):withExpand = (+0x50)->isAncestorOf(sp)
  → kitCreateDock → kitPanelsRestore → addWidget。
- splitter 布局段 `kitSplittersRestore`(8d302f-3317):三槽 [+0x38,+0x40,+0x50];
  states 段 `kitSplittersStatesRestore`(8d3323-340x):>>bool→+0x70 +
  三槽 [+0x68,+0x58,+0x60]。

### KitDock 域(P6)
- ctor `008b81b0`(109B):+0x30 TabGroup/+0x38 **bool** withExpand(勘正)/
  +0x39 浮停位/+0x3c..+0x48 全局矩形四边/+0x4c 槽 id/+0x50 splitter index。
- 子件装配 `s_ExpandButton_8b7dd4`(371B,名误导):TabGroup"PaneGroup"+
  Expand/Config/Close 三钮+QVBoxLayout(addWidget tabs + tabs->stack())。
- 四路接线 `008b7f60`(591B)+槽真身 `008b7d08`(切页同步图标标题)/
  `008b7ca0`(展开转发,非浮停)。
- 创建腿 `s_89d860`(1346B):配置 tabbar.selectionBehaviorOnRemove +
  `QTabBar::setSelectionBehaviorOnRemove`(公开 API)+destroyed→deleteLater。
- 浮停 `dock_toggleFloat`(866B):几何面 **d+0x14..0x20 = QRect 四边** →
  `QRect(mapToGlobal(0,0),size())`;单子 splitter 尺寸并入邻格;
  尾信号 idx1(floatingChanged);尾闭包 8b7cdb = setGeometry(矩形)。
- 收起 `008b86e4`(153B)/切分 `008b9092`(375B)/展开钮 `s_ExpandButton_5ab32a`(584B)。

### TabBar/TabGroup 勘正(P6)
- **`005a80f8`/`005a6c0e` 是 QTabBar 公开 API(setTabButton/tabButton)**,
  非 Qt 私有结构 → `assignTabProperty`(631B)/`setCloseButtonsVisible`(163B)/
  CloseButton 建钮三件真身化(tooltip "Close Tab" 0xc8b231 实读)。
- `005ac8d0`(191B)=replacePage;`005abce4`(301B)=页位说明解析。

### 状态栏(P3)
- 子类 `FUN_005a2d26`(252B)→`StatusBarFace`;`showMessage`(654B):
  空串→tr("Ready")(0xc8b211)+label 永久件+超时表;超时槽(325B)回 "Ready"。
- 染色腿 `005a620e`(787B):属性 "messageLevel"(0xd0dfa6 实读)+
  `s_king_refreshWidgetStyle`(67B,unpolish/polish)。
- `setSizePolicy(0x5d0000)` 按系统 Qt5 Bits 解得 horPolicy=13(非法)→
  **未解码,保持 cited**(防发明)。

### 组会话帧(5c blobB)
- `s_RenamedTitle_8bbab6`(850B)主体 → `MuxPaneGroup::sessionTitleBlob`:
  收集(空页/空 Url 递减 cur、"::" 前缀过滤 0xd99dd1)→ <<cur<<count →
  逐项 <<Url <<会话态 <<颜色 <<(Terminal 腿 RenamedTitle)。
- `KitView_vt9`(008c4ec8,119B)= `property("History").toByteArray()`
  (名 0x11820e8 实读;未初始化腿虚槽 +0xb0 cited)。
- 页元数据表 = 语料 `+0x20 QMap<QString,QVariant>`(008c54a4→00a85f62),
  键 "Url"/"State"/"RenamedTitle" → `MuxPaneView::m_meta20`。
- blobB 组块(8cf62f-8ff):BFS 帧 `<<index <<count <<saveState`,
  子件 QSplitter→kind1 入队 / MuxPaneGroup(**= 语料 KitGroup 011ab130**)
  →kind2 + (isLast ? sessionTitleBlob : 空 BA)。

## 追加:批 236-273 落地(2026-11-16 第二段)

### 工具栏补全(P3/P6)— 七 kind 全真身
- kind5 `AddressBar`:`FUN_005211fe`(162B)= BreadCrumb 基座 + objectName
  "AddressBar";基座 `FUN_00548546`(110B:setAttribute(0xe)/StrongFocus/
  +0x38,0x40)+ 子件装配 `0054842a`(258B)+ 激活 `00548630`(55B,
  setFocus(7))。
- kind6 `FilterEdit`:`searchEdit_init`(131B)= **SearchEdit : QLineEdit**
  (+0x30/38/40,+0x48=0x7fffffff,+0x50 QList,+0x58 byte,+0x68);
  `FUN_0057eb0c`(200B)= +0x78 QTimer(interval 300)+占位 tr("Filter")
  (0xc893d4)+清除钮 `s_king__clear_57e86e`(442B,icon "king::clear",
  tooltip "&Clear" 0xc9e7b8,+0x70)。
- SearchEdit 其余:`0058e028`(158B 布局,HBox 边距 style pixelMetric(5))/
  `0058d818`(296B 接线)/`0058d940`(47B)/`0058d970`(82B)/`0058dff2`(54B)/
  `0058dac2`(18B 占位文案)/`0057eb02`(9B QTimer::setInterval)。

### 设置页族(P4/P5)
- **`SettingsRow`(0x48)** 全字段 asm 实测(名/组合框键/edit50 文本/kind/
  子件值/check38,40/flags/spin70,68/edit60 文本)。
- `settings_loadWidgets`(932B) 全流程;`rowIndexByName`(0072d1e4)、
  `currentListRowIndex`(0072d254)、`resetRow`(0072d0f2)、
  `rowListItem`(0072bf8a 219B)、`onKindComboChanged`(0072eb15 720B 核心)。
- **`dialog_connectAcceptReject`(0072bbe2 935B) 八路接线**;基类勘正为
  **QDialog**;`refreshRows` = `0072dd12`(1872B,cited)。
- **smeta 011a2240 = SessionDialog**(信号 idx0/1/2 = 00904d62/00904d08/
  00904d32;idx1 为会话颜色)。

### 状态栏/消息条(P3)
- `MessageBar`:`FUN_0059af30`(262B ctor)+`s_ExpandButton_5984be`
  (1021B 装配:HBox[VBox,ExpandButton,CloseButton],tooltip "Expand"/
  "Close",icon "king::shrink",边距 style pixelMetric 0x4e/0x50)
  +`FUN_0059834c`(369B 三路接线,信号 idx0=(int,QString),
  emit(0x80,"")→close)+`0059b046`(393B 按文本查 QPushButton)。

### KitDock/TabBar 收尾
- `dock_toggleFloat`(866B) 全真身(几何 = QRect(mapToGlobal,size));
  切分 `008b9092`(375B)+尺寸平分腿;收起尾 → `refreshAfterDockChange`
  (008cb0c0/008cb0a0)→ `focusActiveView`(008cad6a)→ `innerPage`
  (008d9764/008d972e);地址栏激活 `008b9838`(0119aec0 = BreadCrumb)。
- `TabBar::relayoutSideButtons`(005a81c6 134B)、`tabStateAt`(005a6d00 65B)、
  页色读写(005a6ca6/005a7b66)、`sideButtonAt/setSideButton/makeCloseButton`。
- 当前组/视图链:`currentPaneGroup`(008ca6ca)、`currentView`(008bca9e)、
  `activeView`(008cabee)、`ownerConfigName`(008ba210)。

### 会话/5c
- `MuxPaneView::m_meta20`(语料 +0x20 QMap)真身化;
  `historyBlob`(KitView_vt9 = property("History"));
  `parseSessionRestoreBlob`(`s_RenamedTitle_8bb3e6` 1693B 帧面)。

## 追加:批 313-331(P5 对话框族 + Paste/Login/RunTool 数据面)

### P5 对话框(全部按"装配序 + 文案实读"落库)
- **EnvDialogFace**(`envDialog_setupUi` 1109B):+0x48 QPlainTextEdit /
  +0x40 搜索组合框 / +0x30 QDialogButtonBox / QFormLayout /
  `setWordWrapMode(3)` / `systemEnvironment().keys()`。
- **RunToolDialogFace**(`RunToolDialog_setupUi` 1098B + ctor 1116B):
  七控件序(+0x30 check/+0x38 buttons/+0x40 combo/+0x48 label/+0x50 tool/
  +0x58,+0x60 组)+ 两轮 VBox 单选(`setProperty("data")`)+ Ok/Apply +
  占位 `tr("Program [Arguments]...")`(0xca0359);
  **两数据表实读**:参数占位符 6 项(`""/${CurrentChar}/${CurrentWordText}/
  ${CurrentLineText}/${Selection}/${BufferText}`)、输出动作 8 项
  (`ignore/insertText/newBuffer/replaceBuffer/replaceSelection/showOutput/
  showTooltip/showHtml`);
  `applyRadioLabels`(FUN_00707320 1849B:data BA ↔ 表 memcmp → setText(tr));
  `buildCommandObject`(FUN_00708402 1825B:三键 command/stdin/stdout)。
- **MsgBoxFace**(`msgbox_buildRich` 918B + `FUN_00615ad0` 281B):
  三行(File name/Remote path)+ watcher 双分支(icon 3+Ok+"Stop watching
  this file" / icon 1+0x1c000)+ `<pre>%1<br><table>` 拼装 + 行模板
  `<tr><td>%1:</td><td><b>%2</b></td></tr>` + `WA_DeleteOnClose` +
  标题 "Upload File";
  `fileShowErrorBox`(820B):尾 `/` 剥除 + 子目录剔除 + 标题 "Copy" +
  正文 "The destination folder is a subfolder of the source folder:\n%1" +
  Warning(2) + detailedText。
- **FileDialogFace**(`save_file_dialog_exec` 1412B 结构):静态目录缓存 +
  QFileInfo(fileName/exists/absolutePath) + getSaveFileName。
- **ProfileDirDialogFace**(`dirCompareDialog` 1695B,**名不副实** =
  配置目录选择):HBox/VBox + QButtonGroup(+0x38) + 三 QLabel +
  "Please select your profile directory that will be used to store user
  preferences."(0xc9e098) + 候选 `&Application Directory`/`&Home Directory`
  /` - %1`。
- **LoginWizardFace**(`LoginWizard_setupUi` 1088B 全):+0x50 QDialogButtonBox
  (Ok="Continue"/Cancel="&Cancel")+ +0x60/+0x68 QCheckBox
  ("&Auto login next time"/"&Remember this step")+ +0x70/+0x78 QLabel
  (空/"Login" 居中 0x84)+ HBox + QFrame(HLine)+ QFormLayout(-1,0,-1)+
  宿主 QWidget + QStackedWidget(setSizePolicy 0x770000)+ VBox +
  QFrame(StyledPanel)。
- **PasteSettingsPageFace**(`pasteDialog_6dfd9e` 1221B,**实为 CategoryPage**):
  三 QGroupBox(Features/Mouse Actions/Paste Dialog)+ 标签
  "When pasting multiple lines..." + 右键动作三枚举
  (ShowMenu/PasteText/CopyOrPasteText)+ 三配置键
  (terminal.localModeEnabled / terminal.screen.pasteDialog /
  terminal.altScreen.pasteDialog)+ form4 WrapLongRows + form5 三行。
- **TunnelFace**(`TunnelDialog_h9097b0` 535B,**实为行表析构**):
  0x48 步长行,五个 QByteArray(+0x00/+0x08/+0x10/+0x20/+0x38)。

### 5c 会话恢复(读侧补齐)
- `parseSessionRestoreBlob`(帧:>>count>>current + 逐项 name/payload
  (magic 门 → color / renamed))批 269;
- `restoreSessions`(副作用:空表默认会话 / blockSignals / 去重
  QSet ↔ FUN_008bf030 QMap 表查 / 开户腿 cited)批 328。

### 名不副实清单(累计 6 例)
`s_ExpandButton_8b7dd4`=KitDock 装配;`s_tabbar_..._89d860`=dock 工厂;
`pasteDialog`=设置分类页;`dirCompareDialog`=配置目录框;
`TunnelDialog`=行表 dtor;`msgbox_buildRich`=上传确认框。

### 批 333-341 增量(菜单族右鍵四件 + 设置页两件 + 触发器基类)
- **② 菜单族**:`tabbar_contextMenu`(1942B,AddressListModel 模型弹窗:
  `FUN_0062cd9a` 55B QAbstractListModel 子类 +0x1c=1)/`pane_showPopupMenu`
  (1044B,vt+0x1c0 双门 + 修饰键前缀四串 "Shift "/"Ctrl "/"Alt "/"Meta "
  0xcb76d1/d8/de/e3)/`trigger_buildMenu`(1702B,"actions" 键 + 递归条目)/
  `slipButton_makeMenu`(1023B,QWidgetAction 行 +0x18 label/+0x20 overlay
  busy 0xa0/+0x28 容器)。
- **⑤ 设置页**:`settings_sync_action_combo`(1400B,"action" 键 +
  FUN_0069b57e 注册表查)/`settings_table_row_item`(1507B,0x48 项 +
  两列 tr("Variable")/tr("Value") 0xc9d517/0xc91689)/
  `TriggerPageFace`(基类 ctor 006f1966 45B + 装配 006f1994 417B 忙碌遮罩
  overlay 0xa0)。
- **5c**:blobC 三栏可见性真身(`008cefe4`:findChildren 全 isHidden)。
- **TabBar**:`insertTabWithMeta` 增节点标题落位;showTabListMenu 误用
  int 成员已修正。

### 批 342-345 增量(触发器页族全谱)
- **页族共有面**(`FUN_006f1966` 45B):base ctor(vptr 0x11a47f0 / 副 0x11a49b0);
  八页 dtor **汇编逐字节相同**,差异仅 operator_delete 尺寸
  (0x40/0x48×2/0x50/0x58/0x60×2/0x68)。
- **`FUN_006f1994` 417B 全量**:overlay 0xa0 → +0x30;两路 connect
  (信号 0x008fae78 / 0x008faeac);QHBoxLayout margins 全零 + addStretch(0)
  + addWidget(overlay,0,0);**不** setLayout(返回给调用方)。
- **`FUN_006f2be6` 395B 全量**(遮挡槽):遍历子件 → QTableView 子类
  (typeinfo 0x1195cf0)且带子件(0x1194e40)→ v ? selectRow(0) : clearSelection;
  其余(除 +0x30)setEnabled(v)。附:`FUN_0056672a` 179B = 自定义可切换件
  置态(+0x30 bit0;param_4≠0 → 发 0x008faeac)。
- **`FUN_006f440e` 1804B 页栈**:11 kind 表(尺寸/副 vptr/tr 标题全部实读,
  kind 7 无 case);QMap<kind,page> 复用 + addWidget + 合流
  (setTabText **恒 0** / windowTitle / state / vt+0x1a0 = __cxa_pure_virtual)。
- **`FUN_006fdcde` 274B + `FUN_006fd6c0` 1203B**:TriggerActionWidget
  (0x78):+0x30 kind/+0x38 combo 0x48/+0x40 stack 0x30/+0x48 tabs 0x30,
  三平台页签 &Linux/&macOS/&Windows,建页序 {3,2,1,4}(0xc9ff80),
  label tr("&Action:")(0xc9fe80),kind==10 只建 3 号页 + findData(3)/hide。
- **`FUN_006f8590` 1013B 全量**:SendText 页(0x68)——&Match:/&Send: 双标签,
  +0x38 文本域 0x68(FUN_0056376e 0xe000),+0x48 件 0x70(FUN_006f83b0 4,1),
  +0x58 combo 三选项(data 2/1/0),+0x60 QDoubleSpinBox(suffix s/0..999999.9/
  step 0.1),两表头 Send &Condition:/Send &Later:,setTabOrder 链。

### 批 346-348 增量(归属勘定 → ④ TriggerDialog 全谱 + 通用 NameDialog)
- **归属勘定方法**(可复用):ctor 的 `operator_new` 尺寸 + 字段偏移反查——
  `FUN_006f2dd4` = TriggerDialog ctor(尺寸 **0xe0**),其 +0x30 QTabBar /
  +0x40 QStackedLayout / +0x88 QMap 与页栈 `006f440e`、接线 `006f2852`
  三处逐项吻合 ⇒ 三者同宿主。
- **TriggerDialogFace**:ctor 236B(vptr 0x11a4a00/副 0x11a4bd8/+0x78 bool/
  +0x88 QMap/+0x90 QList/+0x98/title **"Triggers"**/setAttribute 0x37)/
  装配 580B(form+grid+tabBar+stacked+buttonBox **0x400400**+PM_SmallIconSize
  左边距+Ok·Cancel 文案+网格 1×2/6格+0.6·0.74)/三子装配(触发器列表 0x68
  「No trigger available」/&Settings 页/S&essions 页 Target &Sessions:·
  Target &Systems:·No session·No system)/八路接线/编辑当前触发器 451B。
- **NameDialogFace**:通用「Create <名>」框(FUN_006bd7f6 319B,vptr 0x11a13b8/
  副 0x11a1590/+0x30 bool/+0x38 名);通用 `nameDialogAddFormRow`
  (FUN_006bd250 242B:addRow(label,field)+FieldRole 逐行 setTabOrder 链)。
- **方法学**:.rodata 取串改用 `file_offset = addr - 0x400000`(readelf 实测
  .rodata addr 0xc89000 ↔ off 0x889000),替代手工读 objdump 行,消除错位。

### 批 349-358 增量(TriggerDialog 行为面补齐 + 菜单机械 + expect 数据面)
- **记录面**:`TriggerRecord` 0x48(+0x08 名/+0x10 UserRole 键/+0x18 描述/
  +0x20 启用/+0x21 入列/+0x24 页 kind/+0x28 子结构)——四条独立证据互证
  (263e setData 0x100 用 +0x10;34dd 回写 +0x08/+0x18;6134 +0x21 门;
  60a8 +0x24 页 kind)。
- **换行驱动 139B**(`006f60a8`):索引有效→提交腿;`+0x24 != 0`→
  页栈 kind + 装载 + 按钮回 "&Ok"。
- **提示框 821B**(`006f2ed8`):HTML 模板实读
  `<tr style="white-space: nowrap;"><td style="text-align:right;">%1: </td><td><b>%2</b></td></tr>`
  + 行标签 `Name`/`Description` + `<table>` 包裹;`data(3)` 比较后才写。
- **初始装载 415B**(`006f6134`):clear → 全局表换手 → 逐记录 `+0x21` 门
  → 空表走 **kind 8(HighlightText)** 页 → 否则 setFocus(3)+setCurrentItem(0x13)。
- **两个范围模型**:动作表 1264B(`006f5b42`,`"*"`→`"all systems"`);
  会话表 927B(`s_session_uuid_6f571a`,键 `session.uuid`/`session.icon`,
  `"%1 / "` 组名头插)。
- **编辑完成 259B**(`006f34dd`):仅 Accepted 落 `+0x08`/`+0x18` 并刷新项文本。
- **禁用外观 425B**(`006f2460`):`FontRole` strikeout + `ForegroundRole`
  `Gray`(`0xd0d152` 实读)。
- **菜单机械**:`paneMenuBaseName`(objectName 去 "Pane")/
  `actionContext`(vt+0x1f0)/`findOrCreateMenu`(QMap 命中 → 复用,否则
  `new QMenu(0x30, tr(name), parent)`)。
- **pane 右键菜单全量 + 勘正**:菜单名 = `"%1 %2Popup"`,前缀
  **0x04000000→Ctrl** / **0x02000000→Shift**(批 336 写反,已纠)。
- **expect 数据面**:`collectRows`(键模板 `%1.path` / `%1.pass` 实读)。

### 批 359-368 增量(TriggerDialog 行为面收口 + 记录布局定案)
- **记录布局定案**(448B ctor + 73B 缺省 ctor 双源):+0x00 样式已设 flag /
  +0x08 名 / **+0x10 uuid**(`QUuid::toString(WithoutBraces)`,故 UserRole 存
  的是记录 id)/ +0x18 描述 / +0x20 启用(图标 active)/ +0x21 入列 /
  +0x24 kind / +0x28 样式 QVariant / +0x30 未定 / +0x38 QMap / +0x40 QHash。
- **kind → 图标表 365B**(`s_king__beforeDisconnection_69934c`,**名不副实**):
  `king::afterConnection/…/showTooltip`,active 追加 `"Active"` —— 与
  `006f440e` 的 kind 表**两独立源互证**(7 无 case)。
- **新增腿 790B + 完成闭包 324B + 追加 192B**:`NameDialog("trigger")` +
  种类 combo(**text = tr(数字源串)**,实参动态)+两行 `&Description:`/`&Type:`
  → `makeRecord` → 在 `currentRow+1` 插入 → 按钮转 `&Next`。
- **删除腿 483B**:`QMessageBox::warning` 文案实读
  「Remove triggers」/「Do you want to remove the selected triggers?」
  (`0x14000` = Yes|No,`Yes` = `0x4000`)。
- **复制腿 655B**:名后缀 `" (%1)".arg(n,10)` 从 2 起避重 + 重生成 uuid。
- **按键选中 193B**、**提交当前页 1608B 结构段**(页值读取纯虚 `vt+0x1a8`,
  与 `+0x1a0` 同族)、**记录族四件**(`defaultRecord`/`regenerateKey`/
  `setStyle`/`isConnectionKind`)、**expect saveRows 997B**(**名不副实**
  = 映射→表回填)。

### 批 369-380 增量(⑤ 八个触发器页装配全数落地 + 表格/面板助手)
- **八页装配全谱**(每页 = QFormLayout + 标签 + 字段 + 遮罩 + addRow + Tab 链):
  | 页(kind) | 装配 | 关键实读 |
  |---|---|---|
  | CustomLink(5) 379B | `00703d3e` | `&Match:` + 文本面板 0x68 + **TriggerActionWidget kind 5** + 0x50 附件 |
  | CustomMenu(6) 683B | `00703fb0` | `&Match:`/`&Actions:` + 表 0x48(0x48f) + 列头 `Label`/`Action` + `No action available` |
  | HighlightText(8) 243B | `006f7c3c` | `&Rules:` + 0x38 规则件 0x48 |
  | PlaySound(9) 470B | `00704340` | `&Rules:` + 表 0x48(0x48f) + 列头 `Pattern`/`Description`/`Sound` + `No sound available` |
  | RunCommand(10) 327B | `006fe290` | `&Match:` + 文本面板 + **TriggerActionWidget kind 10** |
  | SendText(11) 1013B | `006f8590` | 已落(批 345) |
  | ShowTooltip(12) 489B | `00703ab0` | `&Match:`/`&Tooltip:` + 0x70 件(FUN_006f83b0 5,1) + 0x58 附件 |
  | Connection(1-4) | `006fde04` | 已落(批 343) |
  每页 **Tab 链**均为 `setTabOrder(+0x40 → +0x48 → +0x50 …)` 逐页实测。
- **TriggerActionEditPanelFace**(`0056376e` 90B,**名不副实**=动作文本面板 0x68):
  +0x48 = 0x0101,+0x50/58/60 空串;五页的 +0x38 文本域全部由裸 QWidget 换真类。
- **TriggerWidgetKit**:`setupTable`(`00584ee8` 159B:列数/表头/SingleSelection/
  高亮+拉伸+Interactive/横头 show 纵头 hide)、`setPlaceholder`
  (`00566d6e` 22B + 绘制 `00566d84` 97B:空表时主题绘制占位文案)。
- **两条绑定腿**:`bindEditorToActionWidget`(`006fb180` 438B:字段名含
  `arguments` → 插 0x38 盒子 + 属性值 `"${match}"`)、`wireEditorDependents`
  (`006f1850` 278B:两路 connect + 绑定 +0x50)。
- **CustomMenu 新增菜单**(`006f7830` 394B):`Add &Action` / `Add &Separator`。
- **NameDialog 装配收口**(`006bd50c` 670B + `006bd34a` 449B):
  `Enter a name for the new %1.` 提示行 + `&Name:` 行 + Ok 文案 `Create` + 0.35 尺寸比。

### 批 381-390 增量(⑤ 页内件真类化 + ④ 传输下拉 + ② 懒构建菜单)
- **页内件四个方面真类化**(此前全是裸 QWidget / cited):
  | 类 | ctor | 尺寸 | 用途 |
  |---|---|---|---|
  | `MarkStyleWidgetFace` | `00703a58` 55B | 0x40 | CustomLink/ShowTooltip 的 +0x50/+0x58 附件 |
  | `TriggerTableWidgetFace` | `00584e4a` 74B | 0x48 | PlaySound/CustomMenu 表件,基类为 **QTableWidget**(语料直接 rowCount/setColumnCount) |
  | `TextMarkTablePanelFace` | `005675e8` 69B | 0x48 | HighlightText 的 +0x38 规则表(继承上者) |
  | `TriggerActionEditPanelFace` **带 kind 构造** | `006f83b0` 412B | 0x68 | +0x68 = kind;示例样板实读(kind 1 `http://www.sample.com` / kind 4 `echo command\n`) |
- **占位机制闭环**:`setPlaceholder`(`00566d6e` 22B 写 +0x38)→
  `paintEvent` 覆写(`00566d84` 97B:空表 → viewport 主题绘制并 return,否则走
  `QTableView::paintEvent`)。
- **字段表取放**:`findActionFields`(`006f8c6c` 53B:`findChildren` 空名递归,
  smeta 01198660)+ `releaseActionFields`(`006f8c50` 27B)。
- **④ 传输覆盖策略下拉**(`dialog_add_yn_combo` 1482B):`TransferAskFace`,
  7 个 data/文案对全部实读: `-y` Overwrite / `-n` newer / `-N` newer or longer /
  `-+` Append(仅 withAppend)/ `-E` Rename / `-r` Resume / `""` Skip。
- **NameDialog 校验面**:`+0x30` = **允许空名旗标**(非默认);置位时写
  tr("Optional");清位时按当前文本重算 Ok 启停;`setAcceptEnabled` =
  `button(0x400)->setEnabled`。
- **② 菜单懒构建**(`00692a70` 1119B):向上找宿主窗(typeinfo 011a69d0)→
  `tr(动作项名)` 建 QMenu → **`aboutToShow` 时才从动作项子树填充**
  (`FUN_0076cb16`)。再次印证:菜单条目来自动作/配置树,不在 C++ 硬写。

### 批 391-400 增量(② 动作 DSL 地基落地 + 若干勘正)
- **② 三件套**(`ActionRegistryFace`):
  | 函数 | 字节 | 结论 |
  |---|---|---|
  | `actionFactory_getOrCreate` | 856 | 名 trimmed → **QHash<QByteArray,QAction*> @ +0x10** → 命中复用;**未命中:仅 `qstrcmp(name,"Text.HighlightTextBar")==0` 走 HighlightTextBarAction(QWidgetAction 子类,0x20),其余 `new QAction(0x10)` + 默认文案 = 原始名**;两路 connect triggered |
  | `FUN_0066613a` 属性应用 | 2882 | **六属性实读**:**`script` 空→setEnabled(false) / 非空→setData+正则命中→`setProperty("dynamic")`+setVisible**;`text`/`tooltip`→`tr(串)`→setText/setToolTip;`icon`→setIcon;`kits`→`toStringList()`;`state` 落点未定(cited) |
  | `wind_actions_build` | 7702 | **语义只有两行**(遍历 map → 属性应用);余 ~1.4K 行是 QMap/QVariant/QString 逐节点 unref 的内联展开 |
- **勘正**:表件 `+0x10` 不是 QMap 而是 **QHash**;`006926c2` 不是 QMap 查而是**按名线性扫表 memcmp**(`findMenuItemIndex`)。
- **④/⑤ 两小件**:`mapGetOr`(`007349f0` 79B:整数键 QMap 取值带缺省;`dialog_loadWidgetValues` 的覆盖值**按控件地址**存)、`onCursorModeToggled`(`00734f1f` 291B:`setProperty("text", v)` + 标签在 `&Block`/`&Line` 间切换)、`mapGetIntOr`(`006f8cb4` 137B)。
- **表格件首显示自适配**(`00566de6` 163B):`+0x30` 门 → 逐列测宽 `setColumnWidth` → 清标志。
- **搜索面板**(`SearchPanelFace`,`searchpanel_apply` 1716B):**`+0x80` = 待应用标志** → `globalMatch` 逐命中 `capturedStart/End` → 装饰层 → 编辑器虚槽 `vt6`。

### 批 410-419 增量(⑤ 页内件收口 + ④ **TunnelDialog 归属勘正**)
- **⑤ 页内件**:`MarkStyleWidget` 装配 268B(+0x30 线型件 `00703704` 427B /
  +0x38 颜色钮 `s_ColorButton_53904e` 582B / 两行 `Mark &Style:`·`Mark &Color:`);
  **`CaptureGroupsButton`**(`006fad0a` 374B):QToolButton 子类,DownArrow +
  InstantPopup + menu 弹性填充(捕获组插入 `${…}`),即动作字段旁的 0x38 盒子。
- **④ TunnelDialog**(`TunnelDialogFace`,全谱):
  ctor `0072cf44` 257B(title **"Tunnels"**/vtable TunnelDialog_vtable/副 011a4e90);
  建造 `s_king__tunnelDynamic_72c08e` 3404B;接线 `0072bbe2` 935B;
  行→项 `0072bf8a` 219B(setData **1 icon / 3 tooltip / 0x101 行指针**);
  行图标 `6a2c16` 431B(**9 个图标名**:Dynamic/Local/Remote × Active/普通 + Error 三支);
  协议填充 `0072d056` 147B(键 `"SSH"`);初始装载 `0072f007` → `0072d056`+`0072edfe`;
  行表 `0072edfe` 521B(0x48 步长)+ 析构 `0072b9ca` 535B;整行复位 `0072d0f2` 242B。
- **⚠ 两处归属勘正**:
  ① 3404B 建造 + 935B 接线 **同属 TunnelDialog**,此前记在 SettingsPageFace 名下;
  ② `+0x30` 是 **QLabel**(`QLabel::clear` 实证),不是 414 误记的 QGridLayout。
- **`sessionpage_title`(1777B)名不副实**:不是会话页标题,而是**设置分类页标题生成/查重**
  ——模板 `"%1%2"` + **27 条分类键全实读**(Connection/Proxy/Terminal/Bell/…/Tcp)+
  `+0x108` 有序表查重。
- **`expectDialog_collectRows`(984B)名不副实**:固定**一行**遍历各列(非多行)。

### 批 420-428 增量(④ 四个对话框 ctor 全落 + **0x72xxxx 归属图谱**)
- **归属图谱(本轮建立,解 414/415 的串味问题)**:0x72xxxx 区间只有 **4 个 ctor**,
  按"ctor 调用谁"即可判定归属:
  | ctor | 地址/字节 | 归属 |
  |---|---|---|
  | `SessionDialog` | `0072223c` 364B | 00722xxx–0072bxxx 的函数 |
  | `SyncInputDialog` | `0072abce` 239B | 00729xx–0072bxxx |
  | `TunnelDialog` | `0072cf44` 257B | **0072bbe2 接线 / 0072c08e 建造 3404B / 0072d0f2 复位 / 0072d304 说明 / 0072edfe 装载** |
  | `InsertFileDialog` | `0072facc` 74B | 0072f49e 接线 / 0072f584 标签 |
- **SessionDialogFace**:ctor 逐字段(+0x30 名/+0x40 会话 JSON/**+0x70 端口
  QIntValidator 0..99999999** 子类/+0x78..+0xe8 控件槽/**+0xf0·f8 两 QHash**);
  接线 343B(+0x90 页签/+0x68 按钮盒/信号 FUN_00904d62,smeta **011a2240 = 自身**);
  主装配 1166B(**+0x80/+0x88 双 QStackedWidget + +0x90 QTabBar**,按钮
  `Connect`/`Cancel`/`&Edit Default Settings...`);协议切页 3333B(`tabData` 比对 +
  特例串 `Custom`)。
- **SyncInputDialogFace**:ctor 239B(title `Sync Input`);主装配 3005B
  (combo/+0x40 tabBar/+0x48 stacked/+0x58 列表 0x201/+0x38 按钮盒 0x400400);
  **combo 三项实读** `Sessions In Current Window`/`All Windows`/`Group %1`(data 2/1/3);
  收集所选会话 774B(逐页列表 → data(0x100) → 去重)。
- **InsertFileDialogFace**:ctor 74B(**不设窗口标题**);接线 229B;标签 517B
  (title `Insert File` / label `&File:`)。

### 批 429-438 增量(④ **对话框全清单落档** —— 28 个 QDialog ctor 全部定位)
方法:扫全语料找"调 `QDialog::QDialog` 且写 vtable"的函数 ⇒ 得到**权威清单**;
每个 ctor 再取 `副 vptr / 字段写 / tr 标题 / setAttribute(0x37) / singleShot / 装配腿`。

| 对话框 | ctor | 字节 | 标题(tr 实读) | 状态 |
|---|---|---|---|---|
| DefaultEditorDialog | `006b22e6` | 165 | Default Editor | ✅ 429 |
| EnvironmentDialog | `006b35a6` | 175 | Environment Variable | ✅ 429 |
| FocusModeDialog | `006b6676` | 157 | Focus Mode | ✅ 430 |
| HighlightTextDialog | `006b6bfe` | 175 | Highlight Text | ✅ 430 |
| LogDialog | `006b874c` | 206 | Log Dialog | ✅ 431 |
| MasterPasswordDialog | `006b9e92` | 157 | Password(同串) | ✅ 431 |
| NameDialog | `006bd7f6` | 319 | Create <名> | ✅ 347 |
| OneKeyDialog | `006c55c0` | 206 | OneKey Manager | ✅ 432 |
| TableItemDialog | `006c7080` | 254 | **(无标题)** | ✅ 432 |
| PasswordDialog | `006c9e70` | 227 | Password | ✅ 433 |
| PasteDialog | `006caf18` | 221 | Paste | ✅ 433 |
| PlaySoundDialog | `006cc63e` | 175 | Play Sound | ✅ 434 |
| ProfileDialog | `006cf13c` | 240 | Choose Profiles Directory | ✅ 434 |
| QuickDialog | `006d3630` | 125 | **(无标题)** | ✅ 435 |
| RemoteFileDialog | `006d8cfe` | 247 | **(无标题)** | ✅ 435 |
| SearchEngineDialog | `006d9574` | 175 | Search Engine | ✅ 436 |
| SessionGroupDialog | `006d9a66` | 175 | Session Group | ✅ 436 |
| SessionTriggerDialog | `006da816` | 270 | Session Triggers | ✅ 437 |
| SettingDialog | `006ea66e` | 318 | Settings(+Terminal/Editor Settings) | ✅ 437 |
| TextMarkDialog | `006f1036` | 175 | Text Mark | ✅ 438 |
| TriggerDialog | `006f2dd4` | 236 | Triggers | ✅ 346 |
| WindowOpacityDialog | `00704dd2` | 175 | Window Opacity | ✅ 438 |
| RunToolDialog | `00707f8e` | 1116 | — | ✅ 早批 |
| SessionDialog | `0072223c` | 364 | — | ✅ 420 |
| SyncInputDialog | `0072abce` | 239 | Sync Input | ✅ 424 |
| TunnelDialog | `0072cf44` | 257 | Tunnels | ✅ 415 |
| InsertFileDialog | `0072facc` | 74 | **(不设标题)** | ✅ 425 |

另有 `006ebd28`(794B)/`006ff1a0`(647B) 两个 QDialog 构造但**未写自有 vtable**
(疑为子类或复用基类),留待收尾期核。
