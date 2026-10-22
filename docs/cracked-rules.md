# 破解规则汇总（cracked-rules）

每条规则 = 反汇编证据 → 应用落点。细则见 `docs/phase*.md`，原始反编译在 `reference/asm/`。

## 界面结构
| # | 规则 | 证据函数 | 代码落点 |
|---|---|---|---|
| R1 | 中央区 = 嵌套 QSplitter（非 QDockWidget）：root(V)[col(V 1:4:1 bands), bottom(H)] | `FUN_008cd068` | `MainWindow::createCentral` |
| R2 | 面板插入 = 相对锚点四方向 + 自动嵌套（dir<2→H，≥2→V） | `FUN_005a277a` | `PaneManager::insert` |
| R3 | 栏注册表 7 项 / 面板注册表 9 项 | `FUN_008a1106` | `Bars.h`、9 个 Pane 类 |
| R4 | MenuBar objectName="MenuBar"，注册表驱动 | `FUN_00693036` | `MainWindow` |

## 配置与主题
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R5 | 构造顺序：windowOpacity→WA_DeleteOnClose→延迟恢复(QTimer 单发) | `FUN_00768f44` | `MainWindow` ctor |
| R6 | 配置键 `application.windowOpacity` 经 config 单例读取 | 同上 | `WindConfig` |
| R7 | 菜单图标色 = 主题 icon.theme `.pixmap .pen stroke`（浅壳 black/暗壳 #A1A1A1/激活 #007acc） | icon.theme 数据 + strace | `ActionIcons::themeIconColor` |

## 图标系统
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R8 | king.svg 精灵表 302 元素，id=king:: 名；icon.theme 为其 CSS | king.svg + strace | `KingIcons` |
| R9 | 工厂：QSvgRenderer(elementExists→boundsOnElement→render)，未给尺寸默认 0x20=32 | `FUN_007572ac` | `KingIcons::icon` |
| R10 | 面板图标 `king::%1`，名字 toLower，Pane 后缀特判 | `FUN_0089e584` | phase10 记录 |
| R11 | 无 icon 字段动作 = 纯文字（原版无图标） | orig_menu_0 像素统计 | `makeAction` |

## 快捷键
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R12 | keymaps 按动作 id 查绑定，按【焦点部件 keyMode】过滤 modes 后 setShortcut | `FUN_006a872d`/`FUN_008cb962` | `KeymapConfig`+`makeAction` |
| R13 | 显示规则：空 modes=全局；否则须含 `remote`；滤 Meta；同 id 取最后条 | keymaps 数据 7 样本 | 同上 |
| R14 | 菜单条目助记符显示为 `(X)` 后缀（CJK） | orig_menu_0 | `displayActionText` |

## 文案
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R15 | 动作文本 = locale 查表（键=EN 去尾部 `...`）；CJK 下补 `(X)` 助记符 | zh-CN.locale + orig_menu_0 | `makeAction` |
