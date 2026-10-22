# 视觉验收 Round 1（docs/imgs/gui.png vs docs/imgs/WindTerm2.7.0.png）

日期：2026-10-22 · 素材：用户提供的骨架运行截图 + 原版 2.7.0 实机截图

## 1. 骨架截图分析（gui.png）

- 运行的是**旧构建**：9 菜单（无 工具/Tool）、无 Standard 工具栏——早于 Phase 6
- **主题未生效**（浅色背景）：暴露所有加载器用 CWD 相对路径的脆弱性——从非仓库根目录启动时 assets 静默缺失
- ✓ 验证通过的部分：停靠结构、彩色会话标签、AppletBar（标准图标占位生效）、底部五标签、状态栏五段

## 2. 原版 2.7.0 实测布局（WindTerm2.7.0.png，dige-black + 中文）

- 菜单 **10 项**：会话/编辑/搜索/选择/转到/查看/模式/工具/窗口/帮助 —— 与 menu.config Kit 顺序一致 ✓
- **左侧**：`资源管理器 | 会话` **标签组**（上）+ `文件管理器`（下）——修正骨架此前"Explorer 藏、Session 在右"的推测
- 终端标签下有路径面包屑工具栏（ssh ▸ aibox ▸ …）
- 状态栏：就绪 · 远程模式 · **窗口 53×193**（行×列）· **行 769 字符 24** · linux · 日期时间 · WindTerm Issues · 锁屏

## 3. 本轮修正清单（已派发）

1. 左侧停靠重构：`ExplorerPane | SessionPane` 标签组（上）+ FilerPane（下）；右侧保留 Outline
2. 资产路径健壮化：全部加载器改为 `applicationDirPath()/../assets` 优先、CWD 回退——双击 bin/ 内可执行文件也能加载
3. 状态栏补 `窗口 53×193` 与 `行 1 字符 1` 占位段

## 4. 验收对照结论

- 结构层：骨架与原版**区域划分一致**（菜单/工具栏/左中右底四组停靠/标签/按钮栏/状态栏）
- 观感层：待 Round 2（暗色主题 + 真实菜单树生效后对比）

## Round 2（PaneManager + 真实主题，自截图 docs/imgs/skeleton-{light,dark}.png）

- 主题管线闭环：profile(dige-black-and-white=浅色) 与 wind.config(dige-black=暗色) 双向验证，QSS 全局生效（#1c1c1c 底/灰前景）
- 中文 10 菜单（含 工具(8)）、地址栏工具栏、左列 Explorer|Session 标签+Filer、彩签、AppletBar、状态栏 主题名/窗口尺寸/行字符——与原版实机截图逐区域对齐
- 已知残差：标签页标题未本地化（Explorer/Session 应为 资源管理器/会话）；终端占位无时间戳槽与语法色；会话标签样式与原版自绘有差

## Round 3（本地化 + TerminalView，skeleton-r3-*.png）

- 标签本地化：资源管理器|会话、历史命令、发送/传输/输出/搜索——与原版中文界面一致
- TerminalView：110px 时间戳槽 + scheme.theme ANSI 配色 demo（绿主机/蓝路径/红错误），MuxPaneGroup 三会话页各一
- 双主题截图自验（--screenshot），与原版实机截图逐区域对照通过

## Round 6（图标忠实化，skeleton-r6.png）

- 依反编译证据（FUN_007572ac：文件缺失→空图标）删除自绘 QPainter 图标，回退为原版行为：**缺失图标的动作显示本地化文字**（新建会话/断开会话/重新连接会话/显示更多工具）
- 标签栏角钮：+ 与 ≡ 文字化（原版 king::add 无图标文件，同理回退）
- AppletBar 同步：仅主题同名 SVG 命中时显示图标，否则纯文字
- 色板 SwatchIcons（已复现的原版模板）保留待 F4 会话颜色标记使用

## Round F1（功能化后首次全量验收，skeleton-f1-*.png）

- 会话标签可关闭/移动、+钮创建真实 bash（PTY）、AppletBar 语义图标、锁屏钮、layout.v2 持久化
- 菜单图标：原版菜单截图逐项裁剪（96/102），透明化+双主题变体（浅 #333333/深 #e3e3dd），按主题明暗自动选择
- Edit 菜单 6 项因截图带粘连未提取（动作回退文字）

## 修复（用户反馈：浅底图标看不清）

- 根因：变体选择错用 scheme.line.background（dige-black-and-white 的 scheme 是深底）→ 选了浅线条
- 反汇编+数据面确证原版契约：图标色 = 活动主题 icon.theme 的 `.pixmap .pen stroke`（浅壳 black / 暗壳 #A1A1A1 / 激活 #007acc）
- 修正：图标资产改存"纯黑剪影+alpha 掩码"，运行时按主题 icon.theme 着色（themeIconColor 带缓存）
- 双主题截图复验：浅壳黑图标/暗壳灰图标均清晰（skeleton-r8-*.png）

## 图标清晰度迭代（QT_SCALE_FACTOR=2 采集尝试失败：offscreen 下窗口未显示；维持 1x 源 + alpha 拉伸 ≥140 全不透明）

## 图标最终契约（phase12/13，docs/imgs/skeleton-menu.png）

- 像素级证据：原版仅 wind.actions 带 icon 字段的动作渲染图标（像素 69–130），其余（21–42=空白/箭头）纯文字
- 骨架对齐：会话菜单 5/14 项 king.svg 32px 矢量图标（new/disconnect/reconnect/open/save），其余纯文字——与原版逐项一致
- 已清理：docs/icons 裁剪、docs/imgs/original/menu-icons、extract-menu-icons.py（被 king.svg 矢量管线取代）
