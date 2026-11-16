# 归属待办(收尾期第一批工作单)

> 生成于批 448,**批 493 复核更新**。本文档是**代码级工作单**,不是设计文档。
> 触发原因:多轮反编译中按"地址邻近"猜归属,后期用"ctor 调用链"复盘时发现错案。
> **收尾期第一步(编译之前)必须先清这张单**,否则编译错误会与模型错混在一起。

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

## 3. 待定(证据不足,勿擅改)

- `TriggerRecord +0x18` = 描述? (34dd 回写 / 263e 建项都用它,但未见语义定义)
- `TriggerRecord +0x30` 8 字节未定(初值 `0x80000000`)
- `applyAttributes` 的 `state` 键落点
- `006ebd28`(794B)/`006ff1a0`(647B):两个 QDialog 构造但**未写自有 vtable**
- `MuxPaneView::actionContext` 的 `vt+0x1f0` 目标(vtable 该槽实测为 0)

## 4. 名不副实清单(17 例;引用时勿信函数名)

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

## 5. 待定(证据不足,勿擅改)

- `TriggerRecord +0x18` = 描述?(回写与建项都用它,未见语义定义)
- `TriggerRecord +0x30` 8 字节未定(初值 `0x80000000`)
- `applyAttributes` 的 `state` 键**落点未知**(批 404 已撤回"双控"结论)
- `MuxPaneView::actionContext` 的 `vt+0x1f0` 目标(vtable 该槽实测为 0)
- `CountSpinbox` / `CursorShape` 的基类未取证(批 492)
- 线型表 14 项的 **id ↔ 名逐项配对**(批 449 只确证名集)
