# 5C-REPORT — 批 170(M20-①)5c 对表驱动:reopen.history 原版采集 + 布局 diff(2026-11-15)

> 产物目录:`tools/re/phase5/5c/original/`(原版字节)/ `5c/ours/`(我方真身面产出)。
> 采集源:遗留实例 pid 1610117(HOME=/home/pana,真实会话窗
> "192.168.1.94(cac测试)"),UI 菜单优雅退出后落盘
> `~/.wind/profiles/default.v10/global/reopen.history`(789B,2026-11-15
> 17:19 mtime)——**实证原版写盘前提 = 优雅退出(UI 退出链);隔离 HOME
> 下 SIGTERM/SIGKILL 两轮均未产出(global/ 空),与批 166 "aboutToQuit
> 产品挂点 cited" 判例同相。**
> 隔离 HOME 侧证:`/tmp/opencode/b170_home/.wind/profiles/default.v10/`
> 仅有 terminal/user.sessions(1225B 两条 bash),global/ 空。

## 采集产物清单(original/)

| 文件 | 字节 | 来源路径 | 说明 |
|---|---|---|---|
| reopen.history | 789 | profiles/default.v10/global/reopen.history | 唯一窗(Terminal 单页),批 150 读门路径权威样本 |
| reopen.history.terminal | 4860 | profiles/default.v10/terminal/reopen.history | 同名异魔数 0xb9e7e601(terminal 域历史,独立面,本轮仅归档) |
| user.sessions | 22863 | profiles/default.v10/terminal/user.sessions | 会话库(含 cac测试 条目) |

原版 global/wind.config 本轮未变动(mtime 未刷新,原版不回写全局配置,
与 5B/批 166 "wind.config 未见写者(只读对表定案)" 一致)→ 不落盘。

## 布局语义 diff(原始字节解析,QDataStream 大端)

框架(双侧同构,逐字段):

| 字段 | 原版 | 我方 | 判定 |
|---|---|---|---|
| 魔数 | `0xb9e7e626`(8B 头 u32) | `0xb9e7e626` | **MATCH**(汇编 0x76076f MOV ESI 实读同相) |
| 窗数 | 1(int) | 1 | **MATCH** |
| win0.geometry | 66B(saveGeometry 产物;01d9d0cb Qt4 头) | 66B(同头) | **框架 MATCH**;数值差异 = 窗位置/尺寸状态(原版 1023x720@0,0 实窗 vs 我方 offscreen 1023x720 默认位)——非格式差,批 167 判例"几何不按教科书断言"同相 |
| win0.payload | 706B | 32B | **框架 MATCH,体量差 = 页 payload 差**(下节) |
| win0.focusMode | 0(bool) | 0 | **MATCH**(原版非 focus 退出;我方 cited 缺省 0 同相) |
| 总长 | 789B(整读尽) | 115B(整读尽) | 双侧 consumed==total,零尾随 |

## 页 payload 深 diff(原版 674B vs 我方 0B)

| 字段 | 原版 Terminal 页 payload(674B) | 我方 | 判定 |
|---|---|---|---|
| 内魔数 | `0xb9e7e626` + 229 + 2(12B 头) | —(cited 空) | 格式锚:页段独立 0xb9e7e626 家族编号,读侧掩码门 `&0xb9e7e600` 不区分 |
| 页树 | orientation=1(int) paneCount=2(int)+ [ExplorerPane handle=-1][SessionPane handle=-1] 二级:FilerPane -1 + 31/255 尾 | — | 原 8cf0c8 页 payload 真身未升(2233B cited,铁律 3 宁空不猜) |
| 分栏尺寸族 | 488/488、4000、0x1e8 族… (int 流) | — | 同上 cited |
| 会话 uuid 串 | `3a0fce24-4412-4668-bab1-103b61ff2f68`(QString,内嵌) | — | 同上 cited |
| 页表壳(count/current/页名/页 payload) | 1 / 0 / 'Termina'(即 "Terminal",QDataStream QString 尾 NUL) | 1 / 0 / "Terminal" | **MATCH**(007669b2 窄面真身同相) |

**读侧掩码门验证(任务书指定)**:原版 789B 喂 `startupRestoreGate`
(FUN_0075ffcc)→ **gate=true,pages=1,page[0]=TerminalWindow**——
674B 页 payload 未被掩码门吞(magic 0xb9e7e626 过 `&0xb9e7e600` 门,
count>0 → local_91=true);页 payload 由 startupRestoreDispatch 消费
(页挂腿 007664a2,页 payload 语义属 8cf0c8 cited 域,不落深消费)。

## 恢复闭环对账

| 项 | 原版字节 → 我方读门 | 结果 |
|---|---|---|
| 魔数门 | 0xb9e7e626 & 0xb9e7e600 == 0xb9e7e600 | 过 |
| 页数 | payload 头 count=1 | stack count=1 ✓ |
| 页名 | "Terminal" | objectName=TerminalWindow ✓(去 "Window" 后同相) |
| currentIndex | 0 | current=0 ✓ |
| 建窗腿 | geometry 66B | startupWindowCreate(FUN_0075e0f8)真调,restore 走语料 default 腿(offscreen 未 show,批 167 判例同相) |

## 我方产出(ours/reopen.history,115B)

经产品真身面产出(非手拼):`kitWindowFactory("Terminal")` 页装配 →
`stateStoreRemoveWindow`(00760872 入表)→ `stateStoreWriteReopenHistory`
(0076073a 真身写)。驱动:`/tmp/opencode/b170_gen.cpp`(手工 g++ 配方
照 BUILD.md,链 libWindTermRe.so;产物已落 5c/ours/)。
写侧字节差(页 payload 0B vs 674B)**仅记录不改码**(任务书:产品代码
冻结;8cf0c8 升真身属 KitWindow 深域独立批)。

## 结论

1. reopen.history 框架(魔数/窗数/逐窗 geo+payload+bool 三写序)双侧
   **同构同相**;唯一实质差 = 页 payload 体量(8cf0c8 cited 空实现)。
2. 原版写盘触发条件实证:优雅退出链必需(SIGTERM/KILL 不写)——
   批 166 aboutToQuit cited 挂点判例的原版侧行为证据。
3. 读门吞掉性:原版字节全链可恢复(页数/页名/currentIndex 对账全过),
   我方读侧对原版产物**向后兼容**。
4. terminal/reopen.history(0xb9e7e601)为独立魔数族,与 global 面
   (0xb9e7e626)分域,已归档待后批。
