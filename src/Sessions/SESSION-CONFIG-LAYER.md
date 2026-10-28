# 会话/配置层定位(静态库反哺逆向,2026-10-28)

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
