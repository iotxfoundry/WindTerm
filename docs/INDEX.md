# docs/ 索引(2026-11-16 重整)

> **冷启动顺序**:`AGENTS.md` → `tools/re/HANDOFF.md` → **本文件** →
> `docs/PLAN.md` → `docs/PHASE5.md` 顶部「结论快照」。
>
> 判读规则:**以二进制为准**(`./WindTerm` + `tools/re/decomp` 语料)。
> 文档只记录**已取证的结论**;文档与语料冲突 → 回二进制取证后修文档。
> 标 **历史** 的文件是审计轨迹,结论可能已被勘正 —— 引用前先查
> `tools/re/HANDOFF.md`「勘正谱系」。

## 1. 当前真值(先读这些)

| 文档 | 作用 | 何时读 |
|---|---|---|
| `../AGENTS.md` | 铁律/基线二进制/构建(收尾期)/踩坑 22 条 | **每次开工** |
| `../tools/re/HANDOFF.md` | 单页当前态:七节覆盖表 + 勘正谱系 + 现役队列 | 每次开工 |
| `PLAN.md` | 阶段总览(Phase 0-5)与口径说明 | 判断"现在在哪一阶段" |
| `PHASE5.md` | 顶部结论快照 + 批次流水(批 20-341 + 阶段段 192-493) | 查某批做了什么 |
| `QUIRKS.md` | **原版怪癖台账**(bug 原封不动的登记处) | 觉得"这里不对"时先查 |
| `PENDING-ATTRIBUTION.md` | **收尾期工作单**:归属迁移 6 项 + 17 例名不副实 + 待定 6 条 | 收尾期第一步 |
| `CLEANUP.md` | 清理台账(删了什么、保留什么、判据) | 想删文件前 |
| `EXT-BOUNDARY.md` | 外部库边界:不逆向清单 + 版本锚 | 碰到库内部时 |

## 2. 界面重建(七节总账)

| 文档 | 作用 |
|---|---|
| `../tools/re/GUI-MAP.md` | **界面唯一总账**:七节范围 + 22 段落地增量(含目录) |
| `PENDING-ATTRIBUTION.md` | 收尾期归属工作单(与 GUI-MAP 配套) |

## 3. 子系统逆向文档

| 文档 | 子系统 | 关键证据来源 |
|---|---|---|
| `STATE-MACHINE.md` | 终端状态机(SGR/DECSM/CSI) | `Screen.cpp` + 语料 |
| `TERMINAL-CORE.md` | TerminalCore 行/格模型 | `TerminalCore.cpp` |
| `SCREEN-SIGNALS.md` | Screen→Widget 信号面 | qmo + 语料 |
| `TERMINALWIDGET-IMPL.md` | TerminalWidget 实现面 | 语料 + 批 4b |
| `PROTOCOL-ARCHITECTURE.md` | 协议层(Telnet/SSH/Serial) | `Protocols/` |
| `SSH-INTERNALS.md` | SSH 认证族(libssh 委托边界) | `SuperSessionPrivate.cpp` |
| `SESSION-CONFIG-LAYER.md` | 会话配置装载器/管理器/schema | `Sessions/` |
| `CONFIG-SCHEMAS.md` | `wind.config` / `wind.keymaps` 等配置面 | 数据面 `global/` |
| `EDITOR-ENGINE-COMMANDS.md` | 336 条编辑器命令(**CASE 标签 = 唯一溯源**) | `EditorEngine.cpp` |
| `EDITOR-SCINTILLA-MAP.md` | Scintilla 上游 ↔ WindTerm 改动映射 | `src/Scintilla` |
| `TEXTEDIT-COMMANDS.md` / `TEXTVIEW-COMMANDS.md` / `TEXTVIEW-IMPL.md` | 文本编辑视图命令与实现 | `src/Scintilla` + 语料 |
| `SUPERCOMMANDER-IMPL.md` | SuperCommander(SSH 多路)实现 | `SuperCommander.cpp` |
| `CLASSES-SWEEP.md` | 全库类清点(名字/尺寸/vtable) | qmo + dtor 扫描 |
| `VTABLE-MAP.md` | vtable → 类 → 槽位图 | `.data.rel.ro` 实读 |
| `MOC-NAMES.md` | moc 名表(签名对齐用) | 二进制符号 |
| `KING-ENUMS-AUTHORITATIVE.md` | King 枚举值域(**QMetaObject 权威**) | qmo_extract |
| `IMPL-ADDRESSES.md` | 实现地址总表(函数 → 文件:行) | 语料 |

## 4. 方法与审计

| 文档 | 作用 |
|---|---|
| `BUILD-AUDIT.md` | 依赖版本审计(spdlog/fmt/jsoncpp/yaml-cpp/onig) |
| `CALIBRATION.md` | 开源码移植**逐句同构**记录(移植件的合法性凭据) |
| `../tools/re/BUILD.md` | 手工 g++ 配方(不走 CMake 时) |
| `../tools/re/HANDOFF.md` §车道方法论 | worktree 隔离/写域互斥/预算护栏 |

## 5. 历史方案书(结论可能已过时,**引用前先查勘正谱系**)

| 文档 | 说明 |
|---|---|
| `../tools/re/KITWINDOW-RECON.md` | KitWindow 侦察方案书(批 131);其"ctest 通过"判据已因测试删除而失效 |
| `../tools/re/ENODES-RECON.md` | eNodes 节点层方案书(批 130 前后);同上 |
| `../tools/re/phase5/5B-REPORT.md` `5C-REPORT.md` | 5b/5c 行为对比战报(取证记录) |
| `PHASE5.md` 正文批次流水 | 批 20-341 审计轨迹(结论以顶部快照 + 谱系为准) |

## 6. 文档纪律

- **一处结论只写一处**:当前态写 HANDOFF,阶段写 PLAN,界面写 GUI-MAP,
  怪癖写 QUIRKS,归属写 PENDING-ATTRIBUTION。其余文档引用而非复制。
- **按里程碑更新**,不逐批流水(逐批轨迹在 PHASE5 与提交信息里)。
- **删除判据**:参考材料(语料/`inc/`/数据面)在对应子系统复刻完成并通过
  行为对比前不动(见 AGENTS 踩坑 17);清理动作必须登记到 `CLEANUP.md`。
- 历史文档**不重写**——改写会丢审计证据;确需更正时在正文加"⚠ 勘正"块。
