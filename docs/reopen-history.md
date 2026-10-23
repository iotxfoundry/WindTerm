# reopen.history 二进制格式（逐字段逆明，622B 真实样例验证）

来源：反汇编 `0x5dd560`（读）/`0x5dd6fc`（写）/`0x76073a`（顶层写）/`0x75ffcc`（顶层读）+ 真实样例 `~/.wind/profiles/default.v10/global/reopen.history` hexdump 逐字段对齐（2026-10-23）。
用途：LastSessions 启动恢复（`kit.startupSessions`）的数据源；QDataStream **默认大端、Qt 5.15 版本（20），无 setVersion**。

## 文件结构

| 偏移 | 类型 | 含义 | 样例 |
|---|---|---|---|
| 0x000 | u32 BE | magic `0xB9E7E626`（低 8 位=格式修订号；读侧校验 `(magic & 0xB9E7E600)==0xB9E7E600`，>0x21 有 bool、>0x24 有 RenamedTitle） | B9E7E626 |
| 0x004 | i32 | 窗口数 | 1 |
| 每窗口 | QBA | `QWidget::saveGeometry()`（内含 0x01D9D0CB/ver3，Qt 私有不透明，透传） | 66 B |
| | QBA | 窗口状态 blob（`0x7669b2`） | 539 B |
| | bool(1B) | maximized | 00 |

## 窗口状态 blob（0x7669b2）

```
i32 pageCount; i32 currentIndex;
每页: QString pageName("Terminal"/"Editor"/"Grep"); QBA pageBlob
```

## 页 blob（0x8cf0c8 写 / 0x8d2f7e 读）

```
i32 innerMagic(0xB9E7E626)
QBA docksBlob   — 每中央 splitter: i32 子数; 每子(tab 组) QBA(0x8b921a: i32 current,i32 count,
                  每 tab: QString objectName + QBA state); 尾 QBA QSplitter::saveState
QBA rightBlob   — quint8 flag; 每 splitter QBA saveState; param&1 时 BFS 树:
                  i32 nodeIdx, i32 childCount, QBA splitterState, 每子 1B marker(1=子splitter 入队, 2=tab 组→QBA tabListBlob)
QBA barsBlob    — 3×bool: MenuBar/StatusBar/ToolBar 可见性
QBA 子类尾块    — vtbl+0x248 钩子直写; 样例 5B 全 0（语义未明）
```

## tab 列表 blob（0x8bbab6 写 / 0x8bb3e6 读；NoSessions 时为 null）

```
i32 current; i32 count;
每 view: QString url("$<uuid>" 会话视图 / 内部视图 ::explorer 等被跳过)
       + QBA viewState(KitView_vt9)
       + (magic>0x15) QColor
       + (magic>0x24 且 page=="Terminal") QString RenamedTitle
```

## 恢复语义

- 顶层 `0x75ffcc` **无条件**恢复窗口几何+布局；仅会话重连受 `kit.startupSessions` 约束。
- LastSessions：tabListBlob → `0x8d2e46` 按 pageName 建视图入 tab → vtbl[0x60](url) → TerminalView 槽 `0x833db4`：`QUuid($uuid)` → 查 `user.sessions`（`0x810056`）→ **真重连**（uuid 查不到→视图标 Error/Discarded）。
- SpecificSessions：`kit.startupSession1..4`（`"uuid[,profile]"`）同路径。
- NoSessions：tabListBlob=null，仅布局。

## 复刻要点

仅用 i32/u32/bool(1B)/QByteArray(4B 长度前缀,null=0xFFFFFFFF)/QString(4B 字节长+UTF-16BE)/quint8/QColor；几何与 QSplitter::saveState 原样透传；写侧 magic 低字节保持 0x26。QDataStream(Qt_5_15) 直接可读写。
旁证：profile 下另有 `terminal/reopen.history`（magic `0xB9E7E601`，url 形如 `$<uuid>`）——终端侧独立历史，结构未逆。

## 挂账

- 重建侧布局持久化现用 QSettings("layout.v5/...")，未切到 reopen.history 体系（实现成本：docksBlob/rightBlob/splitter state 全透传+tabList 恢复+uuid 重连）。
- 子类尾块 5B 语义未明；`kit.startupSessions` 与 `terminal.startupSessions` 双键作用域差异未细究。

## 勘误（2026-10-24 真样例实证）

- **barsBlob「3 bool=MenuBar/StatusBar/ToolBar 可见性」语义存疑**：真样例读出 `00 00 00`，但原版实机明明显示三栏——保存侧对称推定有误，恢复侧 0x8d2f7e 的应用条件（可能仅显式隐藏才动 / 或另有 flag 前缀）未逆明。重建读侧已挂账不应用。
- **rightBlob BFS 结构与本文描述不符**：真样例 `flag=01 idx=31 cc=255 sp=1B`——idx/cc 离谱（非 0/1）。0x8cf0c8 写侧 param&1 分支的真实序列待重逆；tabList 解析在真样例上不成立（骨架自写自读自洽）。
