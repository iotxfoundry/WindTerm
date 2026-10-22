# Phase 3 发现 — UI 是数据驱动的（架构级）

日期：2026-10-22 · 方法：REA/Ghidra 字符串/xref 链 + 发行包数据文件分析（本轮结束已 close）

## 1. 核心发现：菜单/动作不在二进制里，在数据文件里

`strings` 全量搜索 `&Session`/`Goto`/`Selection` 等菜单标题**均不存在**于二进制——因为 WindTerm 的界面是**数据驱动**的：

### `global/wind.actions`（129KB，526 个动作，16 组）
- 结构：`"Action.Id": { "text": "E&xit", "icon": "king::xxx", "script": "() => { application.exit() }" }`
- **内嵌 JS 引擎**：每个动作的 `script`/`state` 是 JavaScript（QtScript/QJSEngine 风格，操作 `application`/`window`/`text` 对象）
- 分组：Text 226、Window 94、Terminal 52、FilerPane 35、Mux 29、Editor 20、OutlinePane 11、Dock 9、SessionPane 9、Application 8、OutputPane 8、Tool 8、Tmux 7、SenderPane 5、TransferPane 3、Help 2
- 文件不是严格 JSON（含未转义控制字符）——解析需宽松处理

### `global/wind.config`（5984B，~70 个配置键，JSON + BOM；实测含 2 处 `//` 行尾注释，非严格 JSON，解析需字符串感知剥离）
全部默认值可见，与二进制字符串互证（`application.windowOpacity`、`application.themeGui: dige-black`、`tabbar.*`、`terminal.*`、`quickbar.*`…）。**这就是设置对话框的完整键空间。**

### `global/wind.keymaps`（69KB）
Vim 风格按键绑定（`keys` 正则 + `modes: "command, local"` + JS `script`/`action`）。

## 2. 菜单标题格式（已证实）

- 二进制含格式串 **`"(&%1)"`**（0xc90a47），配套助记符提取辅助函数（0x635abe：定位 `&`、移除、返回助记字符）
- 结论：菜单标题 = `标题 + QString("(&%1)").arg(序号)`，与截图 `Session (1) … Help (0)` 吻合（9 个菜单 1-8 号 + 0 号 Help）
- 菜单内动作的组合顺序仍在函数指针表后（间接调用，0xdab204 区域），本轮未追——**但已不关键**：动作集合可整体来自 wind.actions 数据

## 3. qss 结论：不是 qss 驱动

- 二进制**无** `background-color {`/`border-radius` 类 qss 模板；仅 1 个富文本模板：`<span style="color: %1; background-color: %2">`（终端输出高亮用）
- 样式 = QPalette 程序化设置 + 自绘控件（`paintEvent`）——Phase 3 视觉工作应针对 QPalette 而非 qss 文件

## 4. 对骨架的架构修正（本轮派发）

| 项 | 修正 |
|---|---|
| 动作 | 新增 `ActionRegistry`：宽松解析 `assets/config/wind.actions`，暴露 text/icon/分组 |
| 配置 | 新增 `WindConfig`：解析 `assets/config/wind.config`（去 BOM），窗口透明度等读真实键名 `application.windowOpacity`（点号风格，与二进制一致，替代上一轮的 QSettings 斜杠键） |
| 菜单 | 新增 `makeMenuTitle(title, n)` 复刻 `标题 + " (&N)"` 模式（Help 用 0） |
| 资产 | `fetch-assets.sh` 增拷 `wind.config`/`wind.actions` 到 `assets/config/` |

## 5. 证据与未决

- 证据：`(&%1)`@0xc90a47、辅助函数 0x635abe、wind.actions 526 键、wind.config 全键、keymaps 结构（以上均本轮实测）
- 未决：菜单→动作的精确组合顺序（函数指针表后）、主题 QPalette 具体色值、JS 引擎行为（骨架明确不做逻辑）
