# 终端界面（命令行渲染）一致性审计（2026-10-24）

结论先行：**不一致——差距是架构级的**。原版终端不是 cell 网格也不是 QTextDocument，而是**自研文档编辑器引擎**（VT→行快照→run styles→自绘 painter，增量行级更新）。重建现为 QPlainTextEdit+HTML 全量重画。视觉静态接近（黑底/等宽/scheme 配色），行为层（性能/光标/选中/双宽）差异显著。

证据：反编译 14 函数（TSV「终端渲染链深逆批」）+ gui.theme `TextView > QAbstractScrollArea` 规则。

## 原版架构（逆明）

```
VT 层 u64 属性（vt_sgrParse 0x7ef95c）
  bit0 bold … bit10 属性开关；fg24@bit14-37 / bg24@bit39-62 + brighten 位
  38;5;n / 38;2;r;g;b（colon 形式归一）；bold+fg∈palette[0..7] 自动换 bright
  ↓ 行快照
TerminalCell_snapshot（0xa40876）：style run → docEdit 写入
  文档 = 分块 + zstd 压缩 + 线程本地块缓存（滚回即文档历史行，天然混排）
  ↓ 渲染
editor_paint_line_colors（0xa64cea）：自绘 painter 逐可见行 run 取色
  + selection/hex/空白符/列标色层 + caret_rect_render（0xa64838 覆盖式）
脏区：按可见行范围增量重画（非全屏）
```

## 差异清单

| # | 维度 | 原版 | 重建 | 影响 |
|---|---|---|---|---|
| 1 | 架构 | 自研 doc 引擎+自绘 | QPlainTextEdit+HTML 拼接 | 高速输出（cat 大文件）O(整屏) 重画卡顿 |
| 2 | 光标 | 8 形态（block/line/rect/underline ×blink，DECSCUSR 0xa5940a）+QTimer（caretBlink/caretShape/caretPeriod 配置键）+remote 行变色 | QTextEdit 内建光标 | vim 下光标形态不符；配置键无消费者 |
| 3 | SGR | u64 直存；colon 形式；bold→bright 自动 | HTML span | `38:5:n` colon 形式未归一；bold-as-bright 缺 |
| 4 | 选中 | 自绘选区（3px 拖动阈值/word/行模式/200ms 自动滚动节流）+text.selection 色 | QTextEdit 选区 | 双击词选/拖选行为差异 |
| 5 | 滚回 | **window.scrollbackLimit**（0..999999999）；滚回=文档行 | maximumBlockCount 语义不同 | 配置键名不一致 |
| 6 | 宽度 | 逐字符 UCS4 宽度表（双宽/零宽精确，0xa52aa8 horizontalAdvance 缓存） | rich-text 字体 fallback | CJK 双宽/emoji 零宽错位 |
| 7 | 尺寸协商 | cell 度量→rows/cols→pty（resize 环**未逆完**——dump 无 winsize 具名函数，疑在 Pty 侧） | 固定 24x80（TODO 注释） | 拉伸窗口终端行列不变 |
| 8 | 鼠标上报 | mouse_sgr_encode（0x7f298e）+xterm 序列 | 无 | mc/hmouse 类应用不可用 |

## 修复路线（按依赖序）

1. **自绘网格化**（根）：TerminalView 改 QAbstractScrollArea+paintEvent 逐行 run 绘制（对齐 0xa64cea 模型）——解决 1/3/6；ScrollModel 已是 cell 网格（数据层就绪）。
2. 尺寸协商：QFontMetrics cell 度量→rows/cols→Session::resize（pty/ssh 链已有）——解决 7。
3. 光标形态/闪烁（配置键接入）——解决 2。
4. 滚回键名对齐 window.scrollbackLimit——解决 5。
5. 选中/鼠标上报——解决 4/8。

## 未逆明（挂账）

- resize→pty 上报链（原版在哪算 rows/cols 并下发）
- 终端字体 antialias 专键（未见）
