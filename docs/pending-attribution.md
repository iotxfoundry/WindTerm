# 归属待办(收尾期第一批工作单)

> 生成于批 448,**批 493 复核更新**。本文档是**代码级工作单**,不是设计文档。
> 触发原因:多轮反编译中按"地址邻近"猜归属,后期用"ctor 调用链"复盘时发现错案。
> **收尾期第一步(编译之前)必须先清这张单**,否则编译错误会与模型错混在一起。

## 0. 编译前必读(规模与已知雷区)

- **待编译规模**:自基线 `3b7a774f` 起 330 提交 / 139 文件 / +11816 行 /
  **59 个 `*Face` 头** —— **一次编译器都没见过**。
- **已知"必然要改"的四类**:
  1. 本文件 §1 的 6 项归属迁移(SettingsPageFace → TunnelDialog);
  2. 头文件里被多处 `static_cast` 的成员类型偏窄(如 `TunnelDialogFace`
     的 `m_combo48` 等以 `QWidget*` 承接,收尾期可收窄为具体类型);
  3. 各 `*Face` 的 `Q_OBJECT` 与派生类链(新增头文件需重跑 `cmake ..`,
     GLOB 无 CONFIGURE_DEPENDS);
  4. 抄写自 Ghidra 的折叠实参处,凡未回 asm 取寄存器的,编译后需逐个运行期验证。
- **建议顺序**:清 §1 → 全量编译修错 → 25 个测试二进制回归 → 装配 `main`
  → Xvfb 截图 vs `/opt` 对表。

> **类名级重复(2026-11-16 新查)**:6 处重复/双建已在
> [`meta/class-names.md`](meta/class-names.md) §3.1/§3.1b 列表
> (EnvDialog / Settings↔TextMarkDialog / SettingsPage↔TunnelDialog /
> CTerminalConfig / EditorWindow / TerminalWindow),与本文件合并清理。

## 1. SettingsPageFace ↔ TunnelDialog(最高优先)

**事实**:`FUN_0072cf44` = TunnelDialog ctor(标题 `"Tunnels"`),它调用:
- `s_king__tunnelDynamic_72c08e`(3404B)建造
- `dialog_connectAcceptReject`(`0072bbe2`,935B)接线
- `0072edfe`(521B)行表装载、`0072b9ca`(535B)行表析构、`0072d0f2`(242B)整行复位

**结论**:下列函数**属 TunnelDialog**,现被 `SettingsPageFace` 持有:

| 函数 | 地址 | 字节 | 现落点 |
|---|---|---|---|
| 接线 | `0072bbe2` | 935 | `SettingsPageFace::connectSignals` |
| 建造 | `0072c08e` | 3404 | (仅字段表,见头注) |
| 说明标签 | `0072d304` | 1257 | `SettingsPageFace::updateInfoLabel` |
| 行 flags | `0072d84e` | 741 | `SettingsPageFace::updateRowFlags` |
| 行装载 | `0072e4f6` | 932 | `SettingsPageFace::loadWidgets` |
| 整行复位 | `0072d0f2` | 242 | `SettingsPageFace::resetRow`(TunnelDialogFace 也有一份) |
| 行→项 | `0072bf8a` | 219 | `TunnelDialogFace::makeRowItem`(已正) |

**2026-11-16 新证据（行结构冲突，必须先裁决）**:

`FUN_0072bf8a`(219B,makeRowItem) 逐句实读:
`QListWidgetItem(this, param_2+0x10, ...)` → 显示文本取 **行+0x10**;
`setData(1/3, QVariant(param_2+0x10))` → 图标名也取 +0x10;
`setData(0x101, QVariant(param_2))` → **行+0x00 是 QString**（QVariant 以 QString* 构造）。

⇒ 「+0x00 是 QString 键」成立 → `SettingsRow::name@0x00` 方向正确,
`TunnelRow::f00[0x10] 不透明` 属未细化的占位;但两者对 +0x10 的语义命名
（`edit50Text` vs `name10`）**不一致**。**合并前必须把 0x48 行结构完整重推**,
否则搬过去就是把错布局固化。重推范围:`0072d0f2`(行复位) / `0072e4f6`(行装载) /
`0072edfe`(行表装载) / `0072d304` / `0072d84e` / `0072bf8a`(已读)。

**2026-11-16 去重批结论**:
`SettingsPageFace` **无人 include**(死代码),其 0x48 行模型与本类冲突;
`coverage.py --dups` 现在恰好只报这两处(`FUN_0072d0f2` / `FUN_0072bf8a`)。
已删其中确属重复且类内零调用的 `rebuildRowsFromGlobal`(=`0072edfe`,本类
`reloadRows` 已实现);其余两处因被本类内部调用,须待行结构裁决后再合并。
两文件头已加 ⚠ 警示,禁止继续扩写。

**动作**:
1. 把上表前 6 项从 `SettingsPageFace` 移到 `TunnelDialogFace`;
2. `SettingsPageFace` 保留**真正的设置页行模型**(`SettingsRow` 0x48 + 装载/回写),
   —— 但那部分也需复核:其字段表(批 414)已被证明是 TunnelDialog 的;
3. 复核后再决定 `SettingsPageFace` 是否改名(建议 `SessionRowPageFace`)。

## 2. 已知错案(已勘正,勿回退)

| 项 | 正确 | 曾错 | 依据 |
|---|---|---|---|
| 设置行 `+0x30` | QLabel(`QLabel::clear`) | QGridLayout | 批 417 `0072d0f2` |
| 表件基类 | QTableWidget | QWidget | 批 387 |
| 动作表 `+0x10` | QHash | QMap | 批 391 |
| `006926c2` | 按名线性扫表 | QMap 查 | 批 397 |
| `getOrCreate` 特例 | `qstrcmp(name,"Text.HighlightTextBar")` | `"::"` | 批 392 |
| pane 菜单前缀 | `0x04000000`=Ctrl / `0x02000000`=Shift | 二者写反 | 批 355 |
| `+0x10`(TriggerRecord) | uuid(`QUuid::toString`) | UserRole 键 | 批 368 |
| `state` 属性 | 落点未知 | setEnabled+setVisible | 批 404 |
| 3404B / 935B 归属 | TunnelDialog | SettingsPageFace | 批 415 |
| `0085af56` | TransferBar 懒建 | QuickBar 懒建 | 批 443 |

## 3. 名不副实清单(17 例;引用时勿信函数名)

> 成因:Ghidra 以"函数里第一个字符串"命名,而 WindTerm 的 ctor 常先设
> objectName / tooltip / config key,于是名字与真实类型无关。

| 语料名 | 实际是什么 | 依据 |
|---|---|---|
| `s_ExpandButton_8b7dd4` | KitDock 装配 | 批 212 |
| `s_tabbar_selectionBehaviorOnRemove_89d860` | KitDock 创建腿 | 批 213 |
| `pasteDialog_6dfd9e` | 设置分类页 | 批 318 |
| `dirCompareDialog` | 配置目录选择框 | 批 321 |
| `TunnelDialog_h9097b0` | 隧道行表析构 | 批 325 |
| `msgbox_buildRich` | 上传确认富文本框 | 批 317 |
| `s_terminal_ansiBrightBlack_699c2a` | **TriggerRecord 构造函数** | 批 361 |
| `s_king__beforeDisconnection_69934c` | **kind → 主题图标** | 批 359 |
| `expectDialog_saveRows` | **映射 → 表回填** | 批 365 |
| `expectDialog_collectRows` | **固定一行遍历各列**(非多行) | 批 412 |
| `sessionpage_title` | **设置分类页标题生成/查重** | 批 413 |
| `TriggerActionEditPanel`(`0056376e`) | **动作文本面板 0x68** | 批 377 |
| `s_king__tunnelDynamicActive_6a2c16` | **隧道行图标**(9 个名) | 批 416 |
| `s_ColorButton_71850e` | SessionDialog 的信号槽 | 批 421 |
| `TriggerDialog`(`006f2dd4`,标题 "Triggers") | 与题意相符(非反例,列此备查) | 批 346 |
| `s_ActionButton_56e540` | **基类是 QToolBar**(动作工具条) | 批 488 |
| `s_BackwardButton_53e936` | **基类是 QShortcut**(快捷键) | 批 493 |

## 4. 待定(证据不足,勿擅改)

- `TriggerRecord +0x18` = 描述?(回写与建项都用它,未见语义定义)
- `TriggerRecord +0x30` 8 字节未定(初值 `0x80000000`)
- `applyAttributes` 的 `state` 键**落点未知**(批 404 已撤回"双控"结论)
- `MuxPaneView::actionContext` 的 `vt+0x1f0` 目标(vtable 该槽实测为 0)
- `CountSpinbox` / `CursorShape` 的基类未取证(批 492)
- 线型表 14 项的 **id ↔ 名逐项配对**(批 449 只确证名集)


## 4b. 模型缺口:TriggerPage 族是**多重继承**(2026-11-16 取证)

七个触发器页(`CustomMenu/HighlightText/PlaySound/RunCommand/SendText/ShowTooltip`
+ 基类 `TriggerPage`)的析构在语料里成对出现,每对形态固定:

```
CustomMenuTriggerPage_dtor(this):            // 0x006f683e
    *(void**)this        = &TriggerPage_vt0(0x011a47f0);
    *(void**)(this+0x10) = &DAT_011a49b0;    // ← 第二个 vptr
    QWidget::~QWidget(this);

FUN_006f680b(this):                          // 0x006f680b(adjustor thunk)
    *(void**)(this-0x10) = &TriggerPage_vt0;
    *(void**)this        = &DAT_011a49b0;
    QWidget::~QWidget(this-0x10);            // 基址回退 0x10
```

两个信号同时成立即为**第二多态基**:
1. 对象 `+0x10` 另存一个 vptr;
2. 另一支析构以 `this-0x10` 为基址(标准 adjustor thunk)。

**我方现状**:`TriggerPageFace : public QWidget` 只有单继承,对象布局比原版少
0x10 字节的第二基子对象。影响:`qobject_cast`/`dynamic_cast` 到第二基的路径、
`sizeof`、以及 `this-0x10` 那支析构无法生成。

**未定**:第二基的类名。`vtable_scan` 对该 vptr 解出的 typeinfo 仍是
`11TriggerPage`(同一类的第二 vtable),说明 moc 侧不暴露第二个基;其槽位在
静态读取下全为 0,未进一步定性。

**处置**:编译期若出现「页对象指针偏移不符 / 第二基 cast 失败」,先回到本条。
在此之前**不要**给 TriggerPageFace 加第二个基(会连带改动 7 个派生类的尺寸)。

## 5. 转写了但未接线(2026-11-16 全树清点)

以下头文件**没有任何 .h/.cpp include 它们** —— 代码在,但不在任何装配链上。
收尾期要么接线,要么确认是备用接口并写明。

| 文件 | 说明 |
|---|---|
| `Widgets/Dialogs/TunnelFace.h` | 隧道行模型(TunnelDialog 相关,尚未被 dialog 引用) |
| `Sessions/Core/FileOps.h` | 文件操作(SuperTransfer 侧未接) |
| `Terminal/ScreenData.h` | 终端数据面 |
| `Widgets/Panes/FilerPane.h` | 文件浏览面板 |
| `Widgets/Panes/OutputPane.h` | 输出面板 |
| `Widgets/Panes/SessionPane.h` | 会话面板 |
| `Widgets/Panes/TransferPane.h` | 传输面板 |
| `Widgets/Views/TextEdit.h` | 文本编辑控件 |
| `Widgets/Panes/ViewBase.h` | 视图基类 |
| `Utility/CircularBuffer.h` | **B 类**:模板,未被实例化属正常 |
| `Utility/MemoryPointer.h` | **B 类**:同上 |
| `Utility/ScopeGuard.h` | **B 类**:同上 |

> 复查命令:`python3 tools/re/coverage.py --audit`(分类)/ 本清单由
> "头文件无人 include" 扫描得出。B 类三件是模板,不需接线;前 9 项是 A 类,
> 属于"转写了还没挂上",收尾期必须处理。


## §6 TextView 的真实基类是 MuxPane(2026-11-16 取证,待装配期改)

用 QMetaObject 的 superdata 逐跳读出来的一条链:

```
GrepView (0x011aab80)
  └─ superdata 0x01197a60  TextView
       └─ superdata 0x011abde0  MuxPane
```

也就是说真实继承是 **`MuxPane → TextView → GrepView`**,
而 `src/Widgets/Views/TextView.h` 现在是一个**裸类**(不带 QWidget/QObject 基,
也不带 MuxPane 基),只建模了字段与命令转发面。

- **现在不改**:TextView 的 400+ 行命令面已经按"裸类 + 委托"跑通,
  改基会连带影响所有 include 与构造点,属装配期工作。
- **装配期必须改**:`class TextViewFace : public MuxPaneFace`,并把
  `GrepViewFace : TextViewFace` 一起接上。判据就在上面这条 superdata 链,
  不需要重新取证。
- **GrepView 本身的元接口已取全**(17 条:1 信号 `ready` + 16 槽:
  activate / close×2 / closeMessageBar / groupName / isLoaded / path /
  setTabIcon / setTabText / showMessageBar / tabIcon / tabText / url /
  caretVirtualSpace / scrollbackLimit / scrollbackLines),
  等基类接好即可一次回填。

> 记号:`MuxPane`(0x011abde0)与 `TextView`(0x01197a60)各自的 metaobject
> 都还没进本仓;装配期先用 `mo_find.py` 取地址再补。
