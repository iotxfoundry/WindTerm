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
