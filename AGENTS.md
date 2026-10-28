# AGENTS.md — WindTerm 逆向工程指南

> 目标:完全逆向 WindTerm 2.7.0(含 bug 原封不动)。所有代码必须有出处
> (逆向地址),禁止捏造。本文件是 agent 会话必读,总结了多轮反复
> 踩坑后的方法论与约束。

## 铁律

1. **每行代码有出处**:真实现引用 `FUN_XXXXXXXX` 或 `name@地址`;
   thunk 引用反向表项;文档引用 IMPL-*.md。没地址不写。
2. **bug 原封不动**:不修、不美化、不"顺手改进"。原版有 bug 就是
   我们的 bug。发现疑似 bug 时**记录**到对应的 .md,**不修**。
3. **禁止捏造**:反编译语料里没有的行不写。不确定时用
   `/* cited — wave-2 */` 标记空实现,宁可留空也不猜。
4. **禁用脚本批量替换 case 体**。每条 case 手工读语料、手工写。
   脚本只做机械收尾(如 sed 行号定位、重复检查)。

## 分层体系(三档)

| 档 | 标记 | 何时升级 |
|---|---|---|
| 真实现 | 无标注(默认) | 反编译已解、语义可写 |
| 转发 | `→ FUN_XXXX(…)` | 目标已被真身化,此函数仅重定向 |
| 引用(cited) | `// FUN_XXXX — cited` | 体量 >500B 或下行层未开,标注入口地址即可 |

引用档到真实现的升级 = 读语料 entry → 转写为代码 → 删除 cited 标记。

## 工具优先

| 工具 | 用途 |
|---|---|
| `tools/re/decomp/*.c`(49M) | **主语料**:每函数有 `entry=ADDR name=NAME size=N` 头,`grep -n "entry=..."` 直达 |
| `tools/re/xref_scan.py` | 交叉引用:调用者/导入 |
| `tools/re/ehframe_fdes.py` | 30566 函数边界(零重叠) |
| `tools/re/qmo_extract.py` | QMetaObject:类/方法/Q_ENUM(值权威) |
| `tools/re/gen_scintilla_returns.py` | Scintilla.iface → 返回类型表 |
| `tools/re/gen_stubs.py` | 链接器 mangled → stub 定义 |
| kuna CLI(`~/.local/share/rea/bin/kuna`) | 反编译(优于 grep 语料,支持 `--addr`);Ghidra 12.1.4 包装 |
| IDA(若开着) | **基址差:IDA = Ghidra − 0x400000**;仅 spot check |

反编译语料优先于 kuna(免重复反编译),kuna 优先于 IDA(免基址差)。

## 构建体系

见 `tools/re/BUILD.md`。要点:
- 系统 Qt 头 5.15.13 × 仓库 lib Qt 5.15.2 = **ABI 同代,直接链**
- `inc/qt5` 是转发头(qtbase 源码未入库)→ **不可用**,用系统头
- `inc/boost` 是不完整副本 → **不可用**,用系统头
- Scintilla 混合:src/Scintilla(4.4.6 静态库)承接标准 SCI_*;
  WindTerm EXT/WT(30001-30166)在 EditorEngine::customDispatch
- jsoncpp/yaml-cpp 已入库:src/jsoncpp/src/yaml-cpp(4.4.6 配套)

## 已踩坑(每次重复同样的错就在此追加)

### 1. 变量偏移猜错 → 回归二进制
- **+0xb8**:曾以为是 "style 字符串指针",实际是 `m_sgrBits`
  (SGR 64 位属性状态)。三源互证(0x7e2e2 调用/0x8a5 写/0x7f8
  读)后才定案。**教训**:偏移语义必须 ≥2 源一致才可写。

### 2. 同一偏移挂两个成员
- **+0xb8** 曾同时挂 `m_stateB8(void*)` 和 `m_sgrBits(u64)`。
  后者才是正确的。**教训**:新成员先 `grep "0xXXX"` 查是否已有。

### 3. 函数声明顺序:静态函数必须先声明后使用
- `eA235ce` 在 editorSelDtor 之后定义,调用编译错。
- **对策**:文件头部集中前向声明区(已制度化,见 EditorEngine.cpp
  `// fwd:` 段)。新增静态函数写在这里。

### 4. 重复定义:stub 与真实现共文件
- `eA169cc` 在 SuperSessionPrivate.cpp 与 mine_stubs.cpp 各一份。
- **对策**:mine_stubs.cpp 中加新真身时,**先 grep 旧 stub 同名**,
  有则删旧 stub 行。

### 5. 头文件函数签名不一致
- `option()` 三个重载与 `remove*` 族在 SuperSession.h 有两份
  (一在 auth 之前、一在管家注释内)。**教训**:修改头文件先
  `grep -n "函数名"` 确认唯一声明点。

### 6. 嵌入字符串≠库版本
- 主二进制含 spdlog/jsoncpp/yaml-cpp 特征串 ≠ 用了同版本源码。
- **对策**:拉上游源码后 `diff` 其 Scintilla.h / 特征串
  与仓库 inc/ 头;或用源码唯一串命中二进制(69/278,56/114
  命中率定版本)。零 diff 才入库。

### 7. 反编译 warning 不是 error
- `warning: cast to pointer from integer` 等存在(如 Screen.cpp
  paletteColor)。**不修**——原封不动原则;确认不阻塞编译即可。

### 8. bash 引号嵌套
- `'` 内嵌 `'` 会 break。**对策**:长命令用 heredoc 或
  分号拆短命令;`awk` 变量用 `-v`;`sed` 大段用 `python3 - <<EOF`。

### 9. undefined symbol 迭代
- 链接报 undefined → `gen_stubs.py` 生成 stub → 重链 → 可能
  又报新 symbol。**这是正常流程**。收敛条件:dlopen OK。

### 10. 全局作用域污染
- 生成器曾把 stub 写到全局作用域,与真实现撞名。
- **对策**:新 stub 写进 mine_stubs.cpp 之前,先查 `grep -n
  "函数名" src/Sessions/*.cpp` 看是否已有真实现。

### 11. EditorEngine 混合架构边界
- 标准 SCI_* (≤4033) 走 scintillaDelegate(真 Scintilla);
  WindTerm EXT/WT (≥20163) 走 customDispatch(逆向实现)。
  **不要把 SCI_* 移入 customDispatch**——那是重复 Scintilla。
  fork 独有特性才写 custom。

### 12. QMetaObject 枚举值权威
- Q_ENUM 注册表(qmo_extract.py)> 声明池字符串。
- 曾把声明序当值(全错),后从 QMetaObject 精确读回。

### 13. CASE 注释勿丢:标签行是唯一溯源
- EDITOR-ENGINE-COMMANDS.md 的 case 标签注释是**唯一
  反向溯源**(没有函数名只有 cmd)。改代码时 case 标签
  行绝对不能删。

## 反编译语料结构

```
tools/re/decomp/decomp-part-NNNN.c
// ==== entry=00XXXXXX name=FUN_00XXXXXX size=N ====
<类型> FUN_00XXXXXX(...)
```

- 每个 `.c` 文件按地址升序排 entry
- `grep -n "entry=ADDR"` 拿行号,`sed -n` 截函数体
- 反编译器:Ghidra 12.1.4(-revoke 不可重入,生成一次性导出)

## 逆向领域知识锚点

| 子系统 | 关键文件/文档 |
|---|---|
| 终端状态机 | STATE-MACHINE.md;Screen.cpp(SGR/DECSM 等) |
| SSH 认证 | SSH-INTERNALS.md;SuperSessionPrivate.cpp |
| Scintilla 内核 | src/Scintilla/src/(上游源码)+ EDITOR-ENGINE-COMMANDS.md(336 命令) |
| 会话/工作区 | SESSION-CONFIG-LAYER.md(装载器/管理器/schema) |
| 终端配置 | CTerminalConfig 单例(0x00809d78,199 处);wind.config=JSON |
| Scintilla 委托 | scintilla_returns.inc(743 条返回类型)+ Scintilla.iface |
| King 枚举 | KingEnums.h(45 枚举全值域,QMetaObject 权威) |
| 三大静态库 | spdlog(+fmt)/jsoncpp 1.9.4/yaml-cpp 0.6.3(BUILD.md 审计表) |

## 混合架构边界(不要越线)

```
QVariant dispatch(cmd, a, b)
 ├─ cmd ≥ 20163 (EXT/WT)  → customDispatch     ← WindTerm 自有(逆向)
 └─ cmd ≤ 4033 (标准 SCI) → scintillaDelegate  ← 真 Scintilla 4.4.6
                             ↑
               不要把 SCI_* 移入 customDispatch
               不要把 EXT/WT 移入 scintillaDelegate
```

## 验证管线(每轮必须跑)

```bash
# 编译零错
g++ -std=c++17 -fPIC -fsyntax-only …(各改动文件)

# 链接零 undefined
g++ -std=c++17 -fPIC -shared -o libWindTermRe.so <全量 .cpp> moc_*.cpp …

# 加载零 undefined
LD_LIBRARY_PATH=<build> python3 -c "import ctypes; ctypes.CDLL('…'); print('dlopen OK')"

# 冒烟(全绿才提交)
./engtest2   # 编辑引擎混合层(tabSize=4,indexOf=1)
./engtest    # ADDTEXT→GETLENGTH=5, SELECTALL→SELECTIONS=1
./sshsmoke   # libssh 认证族探针
```

## 提交规范

- 中文 commit,force push 需覆盖远端 dev
- push 必带 `-c http.proxy=http://192.168.1.106:7890`
- 每轮:改动 + 对应 .md 更新,**一条 commit 一条 push**
