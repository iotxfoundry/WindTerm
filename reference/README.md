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

## 符号库（累计 5,944 条 / 具名函数头 15,017，33.6%）

| 文件 | 来源 | 证据等级 |
|---|---|---|
| `symbols.tsv` | 人工破解 + **反哺批**（界面还原/排版树/bars/QuickBar/生命周期/PaneHeader 七节）+ **BSim 节**（2,780 条特征匹配名）+ AI 理解批（1,303 条并入） | 实锤（字面量/调用结构/实现确证），弱名升级覆盖 |
| `symbols-inferred.tsv` | `tools/infer-names.py` 机械批：字符串指纹 789 + 调用者归属 4 | `s_<slug>`（引用了某字面量）/`_h`（调用者同类前缀） |
| `symbols-inferred2.tsv` | 同工具 v2：vtable 全槽位 1,653 + 字面量放宽 1,038 + 归属放宽 207 | `_vt<N>`（位置事实，零猜测） |

命名前缀即证据等级：无前缀=实锤 / `BSim_`=开源参考库特征匹配（sim/sig 记于函数注释）/
`s_`、`_h`、`_vt`=推断 / `_helper`、`_callback`=未定位挂账。

**优先级重放**（重建项目后恢复全部命名，symbols 优先、inferred 仅补缺、同地址后行胜=弱名升级）：
```bash
python3 - <<'EOF'
final = {}
for p in ['reference/symbols.tsv', 'reference/symbols-inferred.tsv', 'reference/symbols-inferred2.tsv']:
    for line in open(p, encoding='utf-8'):
        if line.startswith('#') or not line.strip(): continue
        a = line.split('\t')
        if len(a) >= 2: final[a[0].strip().lower().removeprefix('0x').lstrip('0') or '0'] = a[1]
open('/tmp/opencode/symbols-final.tsv','w').write(''.join(f'0x{k}\t{v}\n' for k,v in sorted(final.items())))
EOF
analyzeHeadless /tmp/opencode/ghidra-proj WindTermRef -process WindTerm -noanalysis \
  -scriptPath tools -postScript RenameSymbols.java /tmp/opencode/symbols-final.tsv
```

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

## 工具

| 工具 | 用途 |
|---|---|
| `tools/RenameSymbols.java` / `DecompileAll.java` | 符号应用 / 全量重 dump（AGENTS 反哺管线） |
| `tools/infer-names.py` | 机械批推断（字符串指纹/调用者归属/vtable 槽位） |
| `tools/merge-ai-names.py` | AI 理解批合并校验 |
| `tools/calls-with-receivers.py` | **恢复 Ghidra 丢弃的成员调用 receiver（this）**——objdump 回溯 `mov rdi,<src>`，含黑名单与用法 |
| `tools/BSimApply.java` | **BSim 开源参考库管线**（add 入库 / apply 查询应用，前缀 `BSim_`） |

已知教训：**禁止对已标注项目跑 RecoverClassesFromRTTIScript**（bad_alloc 误绑定扩散 5,086 处且不可精确回滚，2026-10-23 实证）——见 AGENTS.md。

## BSim 参考库（/tmp/opencode/bsim-lab/splitter.hdb，可重建）

```bash
# 1. 编译开源参考（仓库 /home/pana/go/src/github.com/kingtoolbox/WindTerm/src 可编译集）
#    依赖：libboost-dev + qtbase5-private-dev（sudo apt install，版本 5.15.13 精确匹配）
#    full.pro 见 /tmp/opencode/bsim-full/（Telnet/Cryptographic/ThreadLocal/PopupWidget/ScrollBar/Splitter；
#    Pty 层开源 API 断裂 + PopupWidget 需 Qt private 均已解决）
# 2. import 编译产物 → BSimApply.java add → apply（两轮累计 2,780 名）
```

规则汇总见 `docs/cracked-rules.md`（R1-R28）；各阶段证据链见 `docs/phase*.md`。
