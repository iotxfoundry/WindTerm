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

规则汇总见 `docs/cracked-rules.md`；各阶段证据链见 `docs/phase*.md`。
