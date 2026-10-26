# Phase 6 发现 — 菜单组合完全破译（menu.config）+ UI 配置全家桶 + 图标机制收口

日期：2026-10-22 · 方法：发行包数据文件全量清点 + REA 导入表/字符串链（已 close）

## 1. 菜单组合 100% 破译：`terminal/configs/menu.config`（28KB）

Phase 5 关闭此案时漏了数据文件清点——菜单布局一直在 `terminal/configs/menu.config`：

- **顶层菜单顺序**（`"Kit"` 键）：Session, Edit, Search, Selection, Goto, View, Mode, **Tool**, Window, Help
  （比 2020 年老截图多 Tool 菜单——以 2.7.0 发行包数据为准）
- 每菜单条目类型：`{"Action":"ID"}`、`{"Separator":true|"Text"|"Toggle"|"Window"}`、`{"Menu":"子标题","Actions":[…]}`（可嵌套）
- 规模：Session 21 项、View 23、Goto 22、Mode 18、Selection 15、Window 14、Search 9、Edit 8、Tool 7、Help 2
- 同文件还含全部**右键弹出菜单**（Explorer/Filer/Outline/Session/TabGroup/Transfer/View×5 Popup）、Dock/Layout、"Kit More"、Open Recent 等布局

## 2. UI 配置全家桶（`terminal/configs/`，均为数据驱动）

| 文件 | 内容 |
|---|---|
| `menu.config` 28KB | 上述菜单/弹出菜单/布局 |
| `toolbar.config` | 每面板工具栏布局（Standard: NewSession/Disconnect/Reconnect/**AddressBar**/KitMore；FilerPane: FilterEdit/Cdup/Refresh/More…） |
| `statusbar.config` | 状态栏条目，**内嵌 JS**（init/update/change 函数，操作 `King.LocalMode` 等对象） |
| `session.config` | 会话默认值（serial.baudRate 9600、ZMODEM 等） |
| `triggers.config` | 触发器配置 |

## 3. 图标机制收口（架构级，像素级封顶）

新证据：
- 特性位标志表：`king::add`→0x2、`king::matchCase`→0x4000、`king::config`→0x40000（7 项，数据段指针表）
- 图标名格式串 `"king::%1"`（0xcb9a8f）→ 唯一消费函数 `FUN_0089e584`：QIcon 工厂，`"Pane"` 后缀特判（pane 类图标）、`QChar::toLower` 归一名、配合 Phase 5 的 `images/%1.svg` 主题路径解析
- 绘制原语函数未逐一逆向：87 个图标每个需独立分析，成本/收益明确不成立。**像素级调查到此封顶**，骨架维持占位方案

## 4. scheme.theme 结构（数据，待接入）

- 61 个样式 × 8 类：terminal 17、line 12、text 11、pair 9、margin 6、fold/grep/hex 各 2 + `scopes` 列表
- 例：`line.caret.normal/local/command/remote`、`terminal.*`、`grep.match`、`text.*`
- Monokai 系配色，JSON + `//` 注释（与 wind.config 同风格）

## 5. 骨架改造（已派发）

1. **真实菜单树**：新增 `MenuConfig` 加载 menu.config → MainWindow 按 Kit 顺序构建 10 个菜单，条目 Action/Separator/子菜单递归；动作文案经 ActionRegistry→LocaleManager
2. **Standard 工具栏**：toolbar.config 的 5 项（AddressBar 占位为 QLineEdit）
3. **SchemeManager**：加载 scheme.theme，终端占位区应用 `line.background`/前景/选区色
4. 资产脚本增拷 `terminal/configs/*.config`
