# docs 索引

> **冷启动顺序**:`../AGENTS.md` → `../tools/re/handoff.md` → **本文件** →
> `plan.md` → `phase5.md` 顶部「结论快照」。
>
> 判读规则:**以二进制为准**(`../WindTerm` + `../tools/re/decomp` 语料)。
> 文档只记已取证结论;与语料冲突 → 回二进制取证后修文档。
> `history/` 下是审计轨迹,**结论可能已被勘正** —— 引用前先查
> `../tools/re/handoff.md`「勘正谱系」。

## 1. 当前真值(先读这些)

| 文档 | 作用 |
|---|---|
| [`../AGENTS.md`](../AGENTS.md) | **根目录布局(§1)+ src 架构分层与归位判据(§1.1)+ 会话重启加载顺序(§2)**/ 铁律 / 基线 / 工具 / 踩坑 18 条 |
| [`../tools/re/handoff.md`](../tools/re/handoff.md) | 单页当前态:七节覆盖表 + 勘正谱系 + 现役队列 |
| [`plan.md`](plan.md) | 阶段总览(Phase 0-5)+ 追踪表 |
| [`phase5.md`](phase5.md) | 结论快照:里程碑 / 编辑引擎真值 / 5b 终局 / 开放风险 |
| [`quirks.md`](quirks.md) | **原版怪癖台账**(bug 原封不动,只记不改) |
| [`pending-attribution.md`](pending-attribution.md) | **收尾期工作单**:归属迁移 6 项 + 17 例名不副实 + 待定 6 条 |
| [`ext-boundary.md`](ext-boundary.md) | 外部库边界(不逆向清单 + 版本锚) |
| [`cleanup.md`](cleanup.md) | 清理台账(删了什么 / 保留什么 / 判据) |
| [`../src/README.md`](../src/README.md) | **src/ 三类归属**:逆向重建(A)/ 第一方开源(B)/ 第三方库(C)+ 版本表 + 改动规则 |

## 2. 界面重建

| 文档 | 作用 |
|---|---|
| [`../tools/re/gui-map.md`](../tools/re/gui-map.md) | **界面唯一总账**:①-⑦ 七节范围 + 重建优先级 |
| [`pending-attribution.md`](pending-attribution.md) | 收尾期归属工作单(配套) |

## 3. 子系统(`subsystems/`)

| 文档 | 子系统 |
|---|---|
| [`state-machine.md`](subsystems/state-machine.md) | 终端状态机(SGR / DECSM / CSI) |
| [`terminal-core.md`](subsystems/terminal-core.md) | TerminalCore 行/格模型 |
| [`screen-signals.md`](subsystems/screen-signals.md) | Screen → Widget 信号面 |
| [`terminal-widget.md`](subsystems/terminal-widget.md) | TerminalWidget 实现面 |
| [`protocol-architecture.md`](subsystems/protocol-architecture.md) | 协议层(Telnet / SSH / Serial) |
| [`ssh-internals.md`](subsystems/ssh-internals.md) | SSH 认证族(libssh 委托边界) |
| [`session-config-layer.md`](subsystems/session-config-layer.md) | 会话配置装载器 / 管理器 / schema |
| [`config-schemas.md`](subsystems/config-schemas.md) | `wind.config` / `wind.keymaps` 等配置面 |
| [`editor-engine-commands.md`](subsystems/editor-engine-commands.md) | 336 条编辑器命令(**CASE 标签 = 唯一溯源**) |
| [`editor-scintilla-map.md`](subsystems/editor-scintilla-map.md) | Scintilla 上游 ↔ WindTerm 改动映射 |
| [`textedit-commands.md`](subsystems/textedit-commands.md) | TextEdit 命令面 |
| [`textview-commands.md`](subsystems/textview-commands.md) | TextView 命令面 |
| [`textview-impl.md`](subsystems/textview-impl.md) | TextView 实现面 |
| [`supercommander.md`](subsystems/supercommander.md) | SuperCommander(SSH 多路)实现 |

## 4. 元数据与审计(`meta/`)

| 文档 | 作用 |
|---|---|
| [`king-enums.md`](meta/king-enums.md) | King 枚举值域(**QMetaObject 权威**) |
| [`vtable-map.md`](meta/vtable-map.md) | vtable → 类 → 槽位图 |
| [`moc-names.md`](meta/moc-names.md) | moc 名表(签名对齐用) |
| [`classes-sweep.md`](meta/classes-sweep.md) | 全库类清点(名字 / 尺寸 / vtable) |
| [`impl-addresses.md`](meta/impl-addresses.md) | 实现地址总表(函数 → 文件:行) |
| [`coverage-map.md`](meta/coverage-map.md) | **全仓覆盖索引**(自动生成):分组规模 + 地址反查 + 疑似重复实现 |
| [`work-ledger.md`](meta/work-ledger.md) | **逆向工作总账**(自动生成):四状态(真实现/半成品/引用档/未触及)+ 双分母(函数数/字节数)+ 未触及池 |
| [`class-names.md`](meta/class-names.md) | **类名一致性审计**:二进制 RTTI 真名 vs 我方类名;`*Face` 后缀定性 |
| [`calibration.md`](calibration.md) | 开源码移植**逐句同构**记录(移植件合法性凭据) |
| [`build-audit.md`](build-audit.md) | 依赖版本审计(spdlog / fmt / jsoncpp / yaml-cpp / onig) |

## 5. 历史(`history/`,结论以现行文档为准)

| 文档 | 内容 |
|---|---|
| [`phase5-log.md`](history/phase5-log.md) | 批 20-493 阶段段与批次流水(3000+ 行) |
| [`gui-map-log.md`](history/gui-map-log.md) | 界面批 192-493 的 22 段落地/勘正记录 |
| [`plan-detail.md`](history/plan-detail.md) | Phase 0-3 逐项细节 + Phase 2 收尾补记 |
| [`kitwindow-recon.md`](history/kitwindow-recon.md) | KitWindow 侦察方案书(批 131,判据已失效) |
| [`enodes-recon.md`](history/enodes-recon.md) | eNodes 节点层方案书(判据已失效) |

## 6. 工具侧文档(`../tools/re/`)

| 文档 | 作用 |
|---|---|
| [`handoff.md`](../tools/re/handoff.md) | 交接单页(当前态) |
| [`gui-map.md`](../tools/re/gui-map.md) | 界面七节总账 |
| [`build.md`](../tools/re/build.md) | 手工 g++ 配方(不走 CMake 时) |
| `phase5/5b-report.md` / `5c-report.md` | 5b/5c 行为对比战报(取证记录) |

## 7. 文档纪律

- **一处结论只写一处**:当前态 → `handoff.md`;阶段 → `plan.md`;
  界面 → `gui-map.md`;怪癖 → `quirks.md`;归属 → `pending-attribution.md`。
  其余文档**引用而非复制**。
- **按里程碑更新**,不逐批流水(逐批轨迹在 `history/` 与提交信息里)。
- **命名**:文件名小写 kebab-case(`AGENTS.md` / `README.md` 为工具约定例外)。
- **历史不重写**:改写会丢审计证据;确需更正时在正文加 `⚠ 勘正` 块,
  并把结论登记到 `handoff.md` 谱系。
- **删除判据**:参考材料(语料 / `inc/` / 数据面)在对应子系统复刻完成并通过
  行为对比前不动(AGENTS 踩坑 14);清理动作必须登记 `cleanup.md`。
