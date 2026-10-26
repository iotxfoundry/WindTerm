# Phase 12 — 图标系统完全恢复（king.svg 精灵表，100% 可提取）

日期：2026-10-22 · 方法：反汇编工厂链（FUN_00755c86→FUN_007572ac）+ 数据验证 + dlopen 复刻

## 1. 最终结论：图标 100% 可提取（推翻 phase5/10 的"不可恢复"定性）

**`global/themes/default/images/king.svg` 是 302 元素的图标精灵表**：
- 每个图标 = `<g id="add" class="pixmap">` 命名元素（id 与 wind.actions 的 `king::*` 名单一一对应）
- 元素内子形状带 `pen/brush/frame-outer/frame-inner/upper/lower/number/symbol` 等类
- 文件头 `<?xml-stylesheet href="icon.theme" type="text/css"?>` 声明主题样式表
- 各主题的 icon.theme CSS 提供颜色（.pixmap .pen stroke=black/#A1A1A1、.frame-* 等）

原版工厂（FUN_007572ac）语义全对齐：名字 → QSvgRenderer(king.svg) → `elementExists` → `boundsOnElement` → `render(painter, element, rect)`。此前"程序化绘制生成器"的推断至此修正为：**矢量精灵表 + CSS 主题**。

## 2. 骨架实现（src/widgets/KingIcons.h）

- dlopen 调 libQt5Svg.so.5（QtSvg 开发头未装的折衷；符号经 nm 验证）
- **ABI 关键坑**：QSvgRenderer 构造函数是隐含 this（RDI）——必须预分配对象内存显式传 this，按普通函数指针调用会把对象写进参数内存直接段错误（已踩并修复，AGENTS.md 可补）
- icon.theme CSS 以 `<style>` 注入 svg 源（QtSvg 不支持外链 stylesheet）
- 任意分辨率渲染（矢量），当前 32px

## 3. 接线优先级（ActionIcons::iconFor）

① **king.svg 矢量**（wind.actions 有 icon 字段的 24 个菜单动作）
② docs/icons 菜单截图裁剪（96 个，覆盖无 icon 字段动作）
③ 主题 images/*.svg → 空

## 4. 验收（menutest 实测）

- 会话菜单：**14/14 图标**（此前 11）、14/14 中文、矢量图标 iconSizes=32
- 与 docs/imgs/original/orig_menu_0.png 逐项对照一致（圆形边框/形状/颜色）
- kingtest 单测：new/open/copy/disconnect/reconnect/add/save/autoSyncTerminalFolder 全 OK

## 5. 边界

- QtSvg 对注入 CSS 的类选择器支持有限（frame 颜色渲染为默认灰，非 icon.theme 指定色——观感已接近原版，精确着色可后续按类解析后改属性注入）
- 302 元素中仅覆盖菜单/动作子集；其余（tabbar/symbol/number 等）待用时提取
- AppletBar/工具栏未接 king 矢量（仍语义绘制/文字）——需要时同一 API 直接取

## 补充：菜单快捷键右列（"图标显大"的真因）

- 图标实测尺寸两侧本已相等（±1px）；视觉"大"源于菜单缺**快捷键右列**（164 vs 260 宽）
- 权威数据：`wind.keymaps`（JSON，宽松正则漏解析需整组解析）：Terminal.Save→Ctrl+Shift+S、Window.Close→Ctrl+Shift+Q、CloseActiveView→Ctrl+Shift+W、NewWindow→Ctrl+Shift+N、Exit→Alt+F4
- 无 keymap 项：二进制内建助记表（strings: Alt+N/C/I/O/W/X + "Alt+%1" 格式）→ & 助记符生成 Alt+X
- 骨架实现：src/core/KeymapConfig.h（修饰键过滤、同 action 取首条）+ makeAction setShortcut；fetch-assets.sh 增拷 wind.keymaps

## 补充：快捷键显示规则（反汇编 FUN_006a872d→FUN_008cb962 + 7 样本验证）

- 原版按【焦点部件 keyMode】过滤 keymaps 绑定后 setShortcut（多模式键位系统）
- 显示规则（无会话态实证）：**空 modes=全局绑定**（Alt+F4/Ctrl+Shift+N/Alt+O）；否则 modes 须含 `remote`；滤 Meta*；同 action 取最后一条
- 实现于 KeymapConfig；Edit 菜单 Copy=Shift+Del/Paste=Shift+Ins（非直觉但与原版一致）
- 无 icon 字段动作的图标恢复 assets/icons 原生裁剪兜底（45 个）
