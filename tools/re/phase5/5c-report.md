# 5c-report — Phase 5c 会话持久化对表报告

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

## 批 180(2026-11-15)M23-①:5c 收官冲刺 — 全帧字节对表执行 ✅ ctest 23/23

### 一、三段落位(真身/cited 三态)

| 段 | 定性 | 落位 |
|---|---|---|
| **blobB LastSessions 组块外框** | 位级反推 byte-perfect(样本 110..417) | 外框字节序框架记档(`5c/dump_lastsessions.py` + StateStore.cpp 块注);**写面 cited** |
| **浮停腿 dock_toggleFloat(866B)** | 全读定性(asm/decomp 双源) | cited 维持(KitDock 类未建模,现役树零实例 → 8cf1f3 循环不可达同相;零字节产物) |
| **尾钩 vtable+0x248** | 定性 = **QuickBar 窗条面** | cited 维持(QuickBar 宿主槽 +0xd8/+0xe0 未建模) |

**blobB LastSessions 外框**(样本实证,count=1 + 根 ss 27B + 1 条 kind2):

```
[int count][BA 根 splitter saveState][逐 widget: char kind
  kind==1(QSplitter cast,ti 11b8958 import)→ 句柄入表零字节
  kind==2(KitGroup cast,ti 011ab130 "8KitGroup" 实读)→ <<BA title]
title BA 内层 = [int 1][int 2]{BA uuid UTF-16 + BA 会话态}×2
  + 15B 尾标(0000ffff 00000000_00000000 ffffffff 同构 ×2)
```

- kind 写 = `operator<<(char)`(asm 8cf783 ESI=1 / 8cf842 ESI=2 →
  PLT 11b9ef8 `QDataStream::operator<<(char)` 实读;先前"int kind"
  误读勘正 — 1B 字节序在样本上 byte-perfect 收敛,int 序不解析)。
- title 内层样本页:uuid `48149a6b-fe0d-406b-993e-add4713e4d7a`
  (state 34B)/`3a0fce24-4412-4668-bab1-103b61ff2f68`(state 35B)。
- 写面 cited 因:句柄表迭代(push @8cf6cd / erase @8cf740)静态定序
  不唯一 + param_1[9] LastSessions splitter 槽位宿主域未建模
  (铁律 3/6);title 写体 s_RenamedTitle_8bbab6(850B)深域 cited。

**dock_toggleFloat 全读定性**(承接面注记,StateStore.cpp 块注全出处):

- 门 `dock+0x39 != float`(FUN_008b8c62 5B = byte 读);尾写 +0x39
  + KitDock 信号 `floating(bool)` emit(91a80c;KitDock smo 0x11ab100
  QMetaObject 实读:12 方法,floating Q_PROPERTY + floating(bool)
  信号 attrs 0x6)。
- 浮出腿:hostSp cast(QSplitter)→ saved rect(mapToGlobal +0x3c/
  +0x40 + 尺寸 +0x44/+0x48)→ 槽位号 +0x4c(8ca0b8:kit+0x38/+0x40/
  +0x50 三 QSplitter 槽表,8ca096 取面)→ +0x50 = indexOf;单子
  吸收腿(sizes 邻位合并/自位清零 setSizes)→ setParent(kit)+
  setWindowFlags(layout flags|1)+ show + singleShot(0,8b7cdb
  setGeometry 复位)。
- 回位腿:8ca096(kit,+0x4c)取槽 splitter → insertWidget(+0x50)
  + setWindowFlags(0) + show。
- 邻接族:showEvent 0x69 腿(8b9050)/ deleteLater 腿(8b86e4)/
  Splitter 子类 handle 折叠(5a1c70/5a1cfc/5a1ebc/5a2096 + eventFilter
  双击,smdat 0x11981a0 showIndex/hideIndexRequested 信号,"ratio"
  handle 属性缺省 0.18 @c8b190 实读)。

**尾钩定性**(vtable 槽位表 .data.rel.ro 实读):

| 槽 | TerminalWindow(vt 0x11a7c80) | EditorWindow(vt 0x119ee30) |
|---|---|---|
| +0x240 恢复钩 | FUN_008d1014 | FUN_008d1014 |
| +0x248 保存钩 | **FUN_0085ae68(220B 读 face)** | FUN_008d5bee(默认 6B return-1) |
| +0x250 | FUN_008d5bf4(空腿判别锚) | FUN_008d5bf4 |

- 写体 = FUN_008596b8(395B,0026.c:50614):QuickBar 懒建
  (sub_56e26e ctor,objectName "QuickBar" @0xd0e6d4 实读,存宿主
  +0xd8/+0xe0 QPointer 对)→ `<<BA[<<bool 可见位][<<int 表长]
  [<<QString 逐项]`(+0x68 names 表)。
- **样本尾 9B byte-perfect 同相** = `BA(5B: 00 + 00000000)` =
  可见 false + 空表(先前"00000005 00000000 00"误拆勘正 — 首段
  是 BA 长度头 5,非记录字段)。
- 读 face 85ae68:>>BA → 子流 >>bool/>>int/>>QString×(85e0c0
  QVariantList<QString> 承载)→ flags&4 门 → 85ae06 属性回写
  (QuickBar +0x68 表)+ !visible → 8595c8 hide。
- cited 因:QuickBar 宿主槽 +0xd8/+0xe0 未建模 + KitWindowFace
  壳零虚槽声明(22 虚零消费判例,铁律 6)。

### 二、全帧字节对表(核心交付)

对等状态(探针 `frameprobe`,产物 `5c/ours/frame.history` 175B):
单窗 713×451 + 双页 Terminal/Editor(cur=1)带实体树 → 摘除入表 →
写面落盘。原版 789B(`5c/original/reopen.history`)= 1 窗 66B 几何 +
1 Terminal 页(cur=0)。

| 帧级 | 原版 789B | 我方 175B | 结论 |
|---|---|---|---|
| 魔数 @0076076f | b9e7e626 | b9e7e626 | **MATCH** |
| 窗数 | 1 | 1 | **MATCH** |
| 窗段序 geo→payload→bool | ✓ | ✓(t8 读回三字段逐项 ==) | **MATCH** |
| bool(focusMode cited 0) | 0 | 0 | **MATCH** |
| 页帧序 count→cur→(名+BA)× | 1/0 | 2/1(夹具态,环境差) | **框架 MATCH**(字段序同相) |
| 页名 UTF-16 BA 头 | 16("Terminal") | 16/12("Terminal"/"Editor") | **MATCH**(编码同相) |
| payload BA 头 | 706 | 92/20 | 框架 MATCH(体量环境差) |
| 帧 consumed==size | ✓ | ✓ | **MATCH**(零尾渣) |
| kit 魔数 | b9e7e626 | b9e7e626 | **MATCH** |
| kit 段序 A→B→C | ✓ | ✓ | **MATCH** |
| blobB 旗标字节 | 01 | 01 | **MATCH** |
| blobC 三 bool | 00 00 00 | 00 00 00 | **MATCH** |
| blobA 树段 | 229B(3 splitter 实体) | null(探针零树)/t7 夹具 20B 实体段 | 框架 MATCH(批 177 实体面) |
| blobB saveState 段 | 31/35/27/0 | 空/夹具逐段 | 框架 MATCH(批 177 面对账) |
| LastSessions 组块 | 307B(外框上表) | 无(flags&1 测试面零条件) | cited 仅记 |
| 尾钩段 | 9B(BA[00][00000000]) | 无(壳零虚槽) | cited 仅记 |

**三态记账结论:全帧 = 框架 MATCH + 深段 cited** — 魔数/段序/各段
长度构成/记录框架逐项对账通过(上表 14 项);深段差 = LastSessions
组块(写面句柄表定序不唯一)+ 尾钩段(QuickBar 宿主槽未建模)+
blobA 树深(几何环境差),全部 cited 仅记、逐段有落点。测试 t8
(statereopen)固化帧级字段序断言(魔数/单窗/三字段序读回 ==
t3 快照/页帧 count/UTF-16 头),字节级随环境几何漂移仅框架锚。

### 三、新采样与工具

- `5c/original/kitframe-blobA-229B.bin` / `kitframe-blobB-417B.bin`
  (原版 kit 帧两段切出,批 177 反推复核面)
- `5c/ours/frame.history`(175B 对等状态全帧产物)
- `5c/parse_reopen_frame.py`(全帧解析器:窗段/页帧/kit 三段/blobA
  逐 splitter/blobB 旗标+ss 表+LastSessions 组块,框架级零发明)
- `5c/dump_lastsessions.py`(组块外框 byte-perfect 验证器)
- statereopen.cpp t8 块(帧级字段序断言;tmpDir 快照承载)

### 验证

- `cmake -S . -B build` 退出码 0;`cmake --build build -j8` 退出码 0;
  ctest **23/23**;dlopen OK
