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
- TerminalView 自有簇(0x833-0x834)定性:会话 UUID(+0x218)解析、
  A/B/C/D 会话槽字母->id 映射(0x8341c8)、SessionPane 祖先聚焦;
  ViewBase 的属性串实为 "Url"(0xca9158-0xca9164 = 'A'/'B'/'C'/'D')

## 大件定性(2026-10-27 补)

- **0x8c6f48(6.8K)ViewBase::ViewById 收集器**:遍历 CoW 部件列表
  (0x5e9480 分离)→ dynamic_cast QWidget → qt_qFindChildren_helper
  (metaobject 0x119a2e0)→ 每个子件手写 QMap 树查找 "id" 属性
  (operator< 走树)→ 字符串比对命中经 FUN_008c81e8 收集。
- **0x5d0a4e(31K)TextEdit 配置映射构建器**:头部构建 "reverse"
  (fromRawData 0xd0cf0d)/"type" 键的 QVariant 映射;函数体 ~80% 为
  编译器内联的 QMap 递归析构(引用计数逐节点释放),非业务逻辑。
  深挖价值否决:配置构建 + 析构噪音。
