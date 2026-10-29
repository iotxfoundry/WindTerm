# 会话/配置层定位(静态库反哺逆向,2026-10-28)
#
# 【实现状态 2026-10-29】CTerminalConfig(JSONC)+ ProfileLoader
# 已实现(src/Editor,Phase 4a 部分 ✅);workspace 布局装载 ⬜
# 见 PLAN 4a。

由引入的 jsoncpp 1.9.4 / yaml-cpp 0.6.3 反哺:先在主二进制证实
静态打包,再经反编译语料中的库函数名(Ghidra 从字符串解名)与
字符串引用,定位 WindTerm 自有的两大序列化层。

## 内嵌库函数区(48 个,选录)

| 地址 | 名 | 库 |
|---|---|---|
| 0x00aefc30 | json_value_as_cstring | jsoncpp |
| 0x00ae7130 | json_read_value | jsoncpp |
| 0x00aeb820 | json_readerParse | jsoncpp |
| 0x00aea0f0 | json_value_copy | jsoncpp |
| 0x00aebf80 | json_readerLogError | jsoncpp |
| 0x00a7ecde | yaml_toQVariant(1302B) | yaml-cpp→Qt 桥 |
| 0x00a7fbc8 | yaml_loadFile | yaml-cpp |
| 0x00a9367e | yaml_readFile(1920B) | yaml-cpp |
| 0x00ae8b10 | yaml_scanNumber | yaml-cpp |
(全表:48 条,`grep -h "name=json_\|name=yaml" tools/re/decomp/*.c`)

## WindTerm 会话序列化层(调 jsoncpp;0x52x 区)

| 地址 | 名 | 体量 | 语义 |
|---|---|---|---|
| 0x00522056 | s_session_uuid | **9063B** | 会话 JSON 主读写(最大单函数之一) |
| 0x00524a20 | s_session_icon | 1401B | 会话图标字段 |
| 0x00549240 | s_session_protocol | 7347B | 会话协议字段族 |

`.wind/` 目录 + 会话文件 = JSON(json_value_as_cstring 调用点密集)。

## 配置读取层(调 yaml-cpp;0xa7x-0xa9x 区)

- yaml_toQVariant = **yaml→QVariant 桥**(WindTerm 自有粘合,1302B)
- wind.config / wind.variables = YAML(键串实证:xserver.windowMode、
  application.windowOpacity 等)
- 与已转写的 `session_optGet`/`configValue`(text.* / terminal.bellStyle
  键)同族:配置读取统一走此层

## 反哺链闭环

静态库源码 → 版本钉死(串命中率)→ 语料库函数名 → 调用点反查 →
WindTerm 层定位。下期转写目标:0x00522056 会话主读写(9KB,会话
持久化核心)与 yaml_toQVariant 桥。

## 进展(同日续)

- **yamlToQVariant 桥已真身化**(ConfigBridge.cpp,跑在 vendored
  yaml-cpp 上,冒烟通过:嵌套/double/列表全类型正确)
- 0x00522056(9KB)结构初判:**按面板类型路由的分发体**——体内
  仅 "Terminal"(×5)/"Editor"(×2)/"Browser" 三词 + "session.uuid"
  键 + URL 正则 `://([^/]++)/`,各面板的序列化在各自的被调函数;
  会话文件按 Terminal/Editor/Browser 分节

### 深挖一层(同日)

- 路由形态:`QString::compare_helper(pane, "Editor"/"Terminal"/
  "Browser")` → 类型收集器(FUN_008c9e64/FUN_008d0cf2/FUN_008d097c,
  **视图类区 0x8c9-0x8d0**——与 EditorWindow/TerminalView 实现
  簇同区!)→ 每项经 **session_defaultDir** 展开 → QHash<项> 构建
  (FUN_0052523e = qHash 查找,0x5247fc/0x524830 = 节点拷贝/释放对)
- **会话树节点 schema 三件套**(json_get_string_default 实证):
  `text`(显示名)/ `data`(负载)/ `session.uuid`(默认空串 ""),
  配 URL 正则 `://([^/]++)/` 解析会话 URI(ssh://user@host/ 形态)
### 深挖二层(结构真相:工作区恢复系统)

- FUN_008c9e64(105B):`QObject::objectName()` 去掉 "Window"
  →面板类型("TerminalWindow"→"Terminal")
- FUN_008d0cf2(339B):dynamic_cast 过滤子 QWidget,逐个取
  **windowFilePath()** 入 QVariantList——目录项=打开文件的路径
- FUN_008d097c(223B):递归子件遍历("Editor" 过滤)
- **定性:0x00522056 = 工作区(打开的窗口/文件)装载器**——
  按面板类型枚举打开的 QWidget,取其文件路径建 QHash 目录,
  配 text/data/session.uuid 三件套与 URI 正则做持久化关联;
  写入侧(保存)在别处,字段级序列化即 QWidget 属性转储

### ① 全局根定案:DAT_011c2200 = CTerminalConfig 单例

- FUN_00809d78(121B)= **Meyers 单例访问器**(__cxa_guard_acquire/
  release + atexit),存储于 &DAT_011c2220
- 构造 FUN_00809b90(432B):`CTerminalConfig_vtable` + 默认 prompt
  正则(`>` 转义 + `^\s++|\s++(?=%1)|(?<=%1)\s++|\s++$` 空白分割)
- 析构 CTerminalConfig_vt7(680B);使用点 **199 处**(全语料)
- 修正:此前"全局会话库"实为 **CTerminalConfig 终端配置单例**——
  会话管理器模型(0x6f571a)从其管理的会话列表构建 UI;懒初始化
  触发点:FUN_00750b36/00858fce

### ② 启动会话恢复(s_kit_startupSessions_8d2f7e,3122B)

- 配置键:`kit.startupSessions` = "LastSessions"(恢复上次)或
  "SpecificSessions"(开指定);后者读 **kit.startupSession1-4**
  四个会话槽;同区恢复 ToolBar/StatusBar/MenuBar UI 状态
- **实机对证**:发行包 global/wind.config 真含
  `"terminal.startupSessions": "LastSessions"` 与
  `"editor.startupSessions"` ——与二进制分支逐一吻合
- 格式修正:wind.config 实为 **JSON**(默认包实证);yaml 层
  (yaml_loadFile 等)服务 wind.variables/其他文件,两桥并存

### 消费层与 UI 链(0x6f571a,会话管理器模型构建)

- s_session_uuid_6f571a(927B):**会话管理器 QStandardItemModel
  构建器**——遍历全局 JSON(DAT_011c2200,即会话库),每项取
  `session.uuid`/`session.icon`/组(s_session_group_805a3e)/
  标签(s_session_label_8062b6),图标经 theme_icon_load_svg
  (SVG 主题),组名以 "%1 / " 前缀插入标签 → QStandardItem 行
- 会话库 schema 扩容:session.uuid + session.icon + 组 + 标签
- 上层 FUN_005420c8(2925B,SuperSession 区)调用装载器并含
  KeyMode/protocol/subtitle/title/tmux/mux 键——会话协议配置
  与工作区的汇合点
