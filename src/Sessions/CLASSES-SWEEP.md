# 剩余类横扫:metacall case 表与实现簇(2026-10-27)

管线:metacall → case 表 → 实现簇聚类。大方法类全部定性。

| 类 | metacall | 方法数 | case 数 | 实现簇 | 备注 |
|---|---|---|---|---|---|
| TerminalView | 0x91478e | 24 | 23 | 0x8c5-0x8c6(共享)+ 0x833 | 信号 2 个 |
| EditorView | 0x8fbe64 | 21 | 21 | 0x8c5-0x8c6(与 TV **共享**) + 0x5e4-0x5e7 | 信号 3 个 |
| GrepView | 0x91a2dc | 17 | 17 | 0x8c5 簇 + 0x891-0x892 自有 | metacall 外壳属性+深分派 |
| TerminalWindow | 0x911868 | 18 | 18 | 0x858b-0x859a 自有 | 重载对共享体 |
| SenderPane | 0x90a378 | 16 | 15 | 0x735-0x738 自有 | 重载对共享体 |
| FilerPane | 0x90aba2 | 35 | 35 | 0x730-0x732 自有 | metacall 外壳(属性 3)+深分派 0x90a86a |

## 已完结类(此前会话)

| 类 | 形态 |
|---|---|
| TextView(227) | 命令转发壳 + 9 真逻辑体(TEXTVIEW-COMMANDS.md) |
| TextEdit(66) | 命令转发壳 + 10 真逻辑体(TEXTEDIT-COMMANDS.md) |
| TerminalWidget(58) | 五形态混合(TERMINALWIDGET-IMPL.md) |
| SuperCommander(259) | 全量真实现(SUPERCOMMANDER-IMPL.md) |

## 架构结论

- 0x8c5-0x8c6 簇是 TerminalView/EditorView/GrepView 共享的视图基类实现
- FilerPane/TextView/GrepView 的 metacall 采用「属性读写外壳 + 深分派器」
  两级结构(0x90aba2→0x90a86a、0x91a2dc→0x91a058)
- SenderPane/TerminalWindow/FilerPane 的实现自成一簇,横扫时按簇取
