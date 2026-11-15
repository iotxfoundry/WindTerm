# 5C-REPORT — Phase 5c 会话持久化对表报告

## 批 171(2026-11-15)M20-②:wind.config 盘点 + user.sessions 序列化对表 ✅ ctest 23/23

### 一、wind.config 对表矩阵(只读;/opt/WindTerm_2.7.0/global/wind.config 138 行)

顶层键 **122 个**(re 正则 `^  "` 实数);BOM + CRLF 行尾;两处内联
// 注释(L122 useTabPosition / L125 whiteSpacePosition 值域说明);
L37-39 三键 `key" : " value` 空格变体写法(解析容忍,批 150 已过门)。

| 分组 | 键数 | 值型面 |
|---|---|---|
| application.* | 9 | int/str/bool/real(windowOpacity 1.0)+ **searchEngines 数组** |
| editor.* | 5 | bool ×3 / str ×2(**hugeFileThreshold = "50" 字符串数字陷阱**) |
| filer.* | 1 | bool |
| focusMode.* | 2 | bool + **settings = null** |
| grep.* / outline.* / output.* | 4 | int ×2 / bool ×2 |
| quickbar.* | 3 | bool ×3 |
| tabbar.* | 8 | str 枚举 ×5 / real(hoverToSelect 0.2)/ int(thumbnailRatio 40) |
| terminal.* | 38 | bool ×22 / int ×6 / str ×9(含 expect 正则)/ **hiddenMargins 数组** |
| text.* | 48 | bool/int/real(caretPeriod .5/caretWidth 1.5/char·lineSpaceFactor 0.0)/ **hiddenMargins + margins(对象数组)** |
| xserver.* | 8 | bool ×5 / int ×2(displayNumber -1)/ str ×2 |

**我方读面覆盖(CTerminalConfig::parseInto,批 150)**:
- ✅ 已覆盖:117 标量键(bool/int/uint/real/string 直映射 QVariant)
- ⬜ 缺失(扩面另批):5 复合值键被 `default: break` 丢弃 —
  application.searchEngines / text.hiddenMargins /
  terminal.text.hiddenMargins / text.margins / focusMode.settings(null)
- 值型不符:0(JSON 型 → QVariant 型一一对应;无错配)
- 现役点名消费键:terminal.bellStyle / terminal.bellInterval
  (Screen.cpp 2281/2285)、tab.selectionBehaviorOnRemove(枚举键名域,
  WorkspaceLoader 89f516 面)、startupsessions(kit 剥前缀写面,批 169)

### 二、user.sessions 序列化对表(config_saveFile 1571B,0034.c:59978)

**底座链**:config_saveFile(00a801c6)std::ofstream UTF-8 路径 →
FUN_00aef8c0(412B,序列化器 ctor)→ **00d38620 vtable 实读**
([0]=00af6e70/[1]=00af7000 析构对/[2]=**00afc1b0 toString**)→
ofstream 直写产物。序列化器五函数形态:

| 语料函数 | 形态定案 |
|---|---|
| FUN_00af8810(66B,0035.c:73112) | 流态 +0x30/+0x34 = **0x40000004a**(asm 0xaef849 `movabs` 实读)→ 缩进 = +0x34 = **4 空格**;rightMargin = +0x30 = **74** |
| FUN_00af8a00(116B,0035.c:73222) | `std::string(+0x34,' ')` 缩进串(asm 0xaef8a0d `mov 0x34(%rdi),%esi` 二源一致) |
| FUN_00afc1b0(134B,0035.c:75571) | json_toStream 后 **append "\n"**(@00afc1d6)= 尾换行实证 |
| json_toStream(2173B,0035.c:75212) | 对象键值分隔 **" : "**(@0035.c:75489 append);成员指针向量直扫(FUN_00af34a0)= **插入序**;数组腿 FUN_00afc4f0(820B):单行 `[ a, b ]` / 多行逐元素缩进(判定 size*3 ≥ 74,同 jsoncpp isMultilineArray) |
| jsoncpp_writeString(1722B,0035.c:74563) | 扫描带全 >0x1f → **raw 直包(LAB_00afad87)= 中文原样 UTF-8**;具名转义 \t\n\b\f\r\"\\,其余 <0x20 → \uXXXX(@00afa916 ostream hex) |

**差异清单(我方 saveSessions 现役 vs 语料)**:
- D1 中文深转义:jsoncpp 默认 emitUTF8=false → \uXXXX;原版 raw
  → **已落** `emitUTF8 = true`
- D2 尾换行缺失:Json::writeString endingLineFeed 空;原版尾 \n
  → **已落** `doc += '\n'`
- D3 键序:jsoncpp std::map 字典序 vs 原版成员向量插入序 —
  **cited 登记**(QVariantMap 承载无序源;读回等价,无键序语义消费实证;
  user.sessions 无 /opt 样本,terminal/ 自查确认)
- D4 已同相 ✓:缩进 4 空格(现役已设)/ " : " 分隔(jsoncpp 默认)/
  空容器 "{}" "[]" / 多行数组判定 74 / BOM 不写(原版 ofstream 无
  BOM 腿;实文件 BOM 来自上游)/ CRLF 无(\n 直写)

**同构落点**:saveSessions + saveConfigPath(批 169,同 config_saveFile
底座)双双 emitUTF8 + 尾 \n + 显式 4 空格;原版 profiles.config 产物
样本(`{\n    "path" : "~"\n}`)实证同相。

### 三、roundtrip(mwctest f12)

含中文/多字节/空串/int/bool 两会话条目 → saveSessions → 字节断言
(`[\n` 头 / `\n    {` 缩进 / `"session.label" : "中文终端"` raw /
无 `\u` / 空串 `""` / 尾 `}\n`)→ loadSessions 读回对账全同相;
saveConfigPath 产物 `"path" : "~"` + 尾 \n 复核。

### 验证

- `cmake --build build -j8` 退出码 0;ctest **23/23**;dlopen OK

## 批 174(2026-11-15)M21-②:wind.config 复合缺口 + user.sessions 样本对表 ✅ ctest 23/23

### 一、复合缺口扩面(parseInto 五缺口收口)

**读体定性**(yaml_toQVariant FUN_00a7ecde 1302B,0034.c:59107;装载链
FUN_00a7fe9a 344B @59852 源 1 槽参数 → yaml_loadFile → yaml_toQVariant):

| Json 型 | 语料腿 | 承载 | 落位 |
|---|---|---|---|
| null(case0) | FUN_00a7fe9a @00a7ff03/@00a7ff52/@00a7ff95 json_isNullType → 下一源/缺省 | **不落 map**(miss 链同相) | 真身 `if (!val.isValid()) continue` |
| int/uint(case1/2) | QVariant(i64/u64) | qlonglong(批 150 形态保持) | 真身 |
| real/string/bool(case3/4/5) | toDouble/fromUtf8/asBool | 同相 | 真身(既存) |
| **array(case6)** | @00a7ed2d qlist 循环递归 append | **QVariantList** | 真身 `jsonValueToVariant` 递归 |
| **object(case7)** | @00a7edd0 成员向量 FUN_00af34a0 → QMap 插入 | **QVariantMap** | 真身递归 |
| default | @00a7f0f4 json_value_as_string → QByteArray | QByteArray | 真身 |

五缺口落位:application.searchEngines(对象数组)/text.hiddenMargins +
terminal.text.hiddenMargins(字符串数组)/text.margins(对象数组)→
QVariantList(元素 QVariantMap);focusMode.settings(null)→ 不落
(miss 链语义,非空 QVariant 承载)。消费面现无(现役读点零)→
承载档,cited 待消费点开批。

### 二、user.sessions 样本对表(22863B 原版样本 od/python 实证)

- 顶层:`[\n` … `]\n`;条目对象 4 空格缩进、键 8 空格;`" : "` 分隔;
  无注释/BOM;**49 条目 × 24 键全标量**(str 372/bool 53/int 46,
  零复合值)→ loadSessions `default: break` 深条目 cited 注记同相。
- 键集:session.* 13 键域 + ssh.sysmon/ssh.verifyServerFingerprint/
  ssh.sftp + serial.* 5 + process.* 2(变长键集 16 形态,oneKey 40/49)。
- 框架 diff ↔ 我方 saveSessions(批 171 已同构):缩进/分隔/尾 \n/
  UTF-8 raw 逐项同相(f12 字节断言);**唯一差异 = 键序**(jsoncpp
  字典序 vs 原版插入序,cited D3 维持;样本零复合值 → 深条目语义
  无可落点)。saveSessions 无需微调。

### 三、mwctest f13(复合承载 + 对账)

承载断言(searchEngines/text.margins QVariantList-of-QVariantMap)+
真实 JSONC 装载(字符串数组 2 元素/对象数组 url 字段/null 不落/
标量旁路不回归);样本框架对表结论见上(同相,键序 cited)。

### 验证

- `cmake -S . -B build` 退出码 0;`cmake --build build -j8` 退出码 0;
  ctest **23/23**;dlopen OK
