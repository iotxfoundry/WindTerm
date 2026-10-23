# reference/ — 原程序反编译参照库

Ghidra 12.1.4 headless 反编译产物（`analyzeHeadless … -postScript DecompileDump.java`）。
源二进制：`WindTerm 2.7.0` Linux x86-64，sha256 `9491b87eec5c4482f34a01cca78be6ecbf5f7f427278dcec48eb7d20a7469f54`。
**用途**：已破解机制的原始参照，避免重复反汇编。新破解的函数按 AGENTS.md 铁律追加到此目录。

## 索引（地址 → 角色 → 破解结论落点）

| 文件 | 角色 | 结论/规则 → 应用与文档 |
|---|---|---|
| `0x8cd068_central-splitter-assembly.c` | 主窗口中央 Splitter 树装配 | 嵌套 QSplitter 结构/1:4:1 → `PaneManager`/phase7 |
| `0x5a277a_pane-insert-engine.c` | 面板四方向插入引擎 | dir<2=H、≥2=V、自动嵌套 → `PaneManager::insert`/phase8 |
| `0x768f44_mainwindow-ctor-complete.c` | MainWindow C1 构造 | windowOpacity/WA_DeleteOnClose/延迟初始化 → `MainWindow`/phase2 |
| `0x768cb6_mainwindow-delayed-init.c` | 构造后 QTimer 延迟恢复 | 单发延迟恢复模式 → `onRestoreLayout`/phase2 |
| `0x693036_menubar-ctor.c` | MenuBar 构造 | objectName "MenuBar"、注册表驱动 → `Bars.h`/phase2 |
| `0x8a1106_bars-panes-registry.c` | 7 栏 + 9 面板注册表 | MenuBar..TransferBar / ExplorerPane..ShellPane → `Bars.h`/phase2 |
| `0x7ce254_vt-operations-registry.c` | VT 53 操作注册表 | 操作枚举面 → `ScreenModel`/phase9 |
| `0x75541e_icon-name-resolver.c` | 图标名 `::` 分解与路径候选 | images/%1.svg → `ActionIcons`/phase10 |
| `0x755c86_icontheme-svg-loader.c` | icon.theme + QSvgRenderer 加载器 | 主题 CSS 注入 → `KingIcons`/phase12 |
| `0x7572ac_icon-factory-king.c` | 图标工厂（king.svg 精灵渲染） | elementExists→bounds→render，默认 0x20=32 → `KingIcons`/phase12 |
| `0x639e76_qiconengine-virtual-hook.c` / `0x639652_…cache.c` | QIconEngine 钩子/缓存 | 委托绘制的证据链 → phase11 |
| `0x89e584_pane-icon-factory.c` | `king::%1` 面板图标工厂 | Pane 后缀特判/toLower → phase10 |
| `0x6a872d_menu-shortcut-resolver.c` | 菜单快捷键解析 | keymap 按动作 id + keyMode → `KeymapConfig`/phase12 |
| `0x8cb962_keymode-resolver.c` | 焦点部件 keyMode | 多模式键位系统 → phase12 |
| `0x76bf82_keysequence-builder.c` | 绑定→QKeySequence | 同上 |
| `0x635abe_mnemonic-helper.c` | `(&%1)` 助记符 | 2020 EN 编号（CN 无）→ phase13 |
| `0x5a1c00_splitter-subclass-ctor.c` | 开源 Splitter 子类实例化 | 与 src/Widgets/Splitter 对应 → phase7 |

## reference/full/ — 全量反编译（44,664 函数 / 45 分块 / 49MB）

`DecompileAll.java` 一次跑完（Ghidra headless，175 秒，0 失败）。每函数以
`// ==== entry=<地址> name=<名> size=<字节> ====` 分隔，可 rg 直接检索：

```bash
rg -A 20 'entry=008cd068' reference/full/     # 定位已知函数
rg -l 'QSvgRenderer' reference/full/          # 语义搜索
```

## 符号库（累计 3,072 条 / 具名函数头 12,232）

| 文件 | 来源 | 证据等级 |
|---|---|---|
| `symbols.tsv` | 人工破解 + **反哺批**（界面还原/排版树/bars/QuickBar/生命周期五节） | 实锤（字面量/调用结构/实现确证），弱名升级覆盖 |
| `symbols-inferred.tsv` | `tools/infer-names.py` 机械批：字符串指纹 789 + 调用者归属 4 | `s_<slug>`（引用了某字面量）/`_h`（调用者同类前缀） |
| `symbols-inferred2.tsv` | 同工具 v2：vtable 全槽位 1,653 + 字面量放宽 1,038 + 归属放宽 207 | `_vt<N>`（位置事实，零猜测） |

AI 理解批（fixer 阅读函数体命名 1,303 条）已并入 `symbols.tsv` 的 "AI 理解批" 节，
证据列为一句依据。命名前缀即证据等级：无前缀=实锤 / `s_`、`_h`、`_vt`=推断 / `_helper`、`_callback`=未定位挂账。

**反哺管线**（AGENTS.md 第四步，与实现同批提交）：
```bash
# 1. symbols.tsv 追加：0x<地址>\t<名>\t<证据>
# 2. 应用+重 dump（调用点烧真名）+ orig= 标注：
analyzeHeadless /tmp/opencode/ghidra-proj WindTermRef -process WindTerm -noanalysis \
  -scriptPath tools -postScript RenameSymbols.java reference/symbols.tsv
analyzeHeadless … -scriptPath /tmp/opencode/gscripts -postScript DecompileAll.java /tmp/opencode/decomp-full<N>
# 3. cp -r → reference/full → orig= 标注脚本（见 git log "symbols:" 提交）→ commit
```
Ghidra 项目 `/tmp/opencode/ghidra-proj WindTermRef` 可 -process 复用（免重分析）。

规则汇总见 `docs/cracked-rules.md`（R1-R25）；各阶段证据链见 `docs/phase*.md`。
