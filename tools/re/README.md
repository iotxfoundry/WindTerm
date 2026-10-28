# tools/re — WindTerm 逆向工具箱

从本仓库逆向会话沉淀的可复用工具与数据产物。目标二进制:根目录
`WindTerm`(12MB stripped x86-64 非 PIE)。所有脚本独立可跑,只依赖
python3 + numpy + binutils(readelf)。

## 脚本

| 脚本 | 用途 | 用法 |
|---|---|---|
| `qmo_extract.py` | 无符号提取全部 QMetaObject:类/方法(SIG/SLOT)/属性/Q_ENUM 枚举表(值权威) | `qmo_extract.py WindTerm --json out.json` |
| `xref_scan.py` | numpy 单遍全量交叉引用:任意地址的调用者/引用者/PLT 导入解析 | `xref_scan.py WindTerm --callers 0x629fd0 --imports ssh_` |
| `ehframe_fdes.py` | .eh_frame FDE → 30,566 条权威函数边界(零重叠,.text 99.7% 覆盖) | `ehframe_fdes.py WindTerm --json out.json` |
| `frida_statechanged.js` | 动态挂钩 stateChanged 发射桩,实测状态机迁移序列 | 见文件头注释(需临时 ptrace_scope=0) |
| `gen_editor_cmds.py` | 编辑引擎 38K 分派器提取:cmd→action/成员表 + `--cpp` 生成 switch | `gen_editor_cmds.py decomp-part-0034.c --cpp` |
| `gen_scintilla_returns.py` | Scintilla.iface → 返回类型表(scintilla_returns.inc) | `gen_scintilla_returns.py src/Scintilla/include/Scintilla.iface out.inc` |
| `gen_stubs.py` | 链接器 mangled 未定义 × 头文件返回类型 → cited-stub 定义 | `gen_stubs.py lib.so out.cpp headers...` |
| `decomp/` | **49M 反编译语料**(Ghidra 12.1.4 导出,每函数有 entry/name/size) | `grep -n "entry=007xxxxx" decomp/*.c` 直达 |
| `data/ida_makeqmo2.py` | IDA 控制台批量建函数 | IDA Python: `exec(open(...).read())` |

## 数据产物(data/)

| 文件 | 内容 |
|---|---|
| `king_api.json` | 61 个 King 类完整方法表 |
| `super_bases.json` / `super_sigs.json` | Super 三基类方法+签名 |
| `fdes.json` | 30,566 函数边界(VA+长度) |
| `ssh_callsites.json` | libssh 49 API 全部调用点 |
| `textview_names.json` / `textview_methods.txt` | TextView moc 名池 |
| `moc_names.json` | 21 类全池真名提取 |

## 已验证方法

1. **QMetaObject 模式匹配**:`.data.rel.ro` 四字段模式 + RELATIVE
   重定位回填 + QArrayData(24B)头表解析
2. **metacall case ↔ 方法索引对齐**:Ghidra `switch(param_3)` 与 moc
   表序号一一对应
3. **静态打包审计**:主二进制特征串指纹(spdlog 96 处/jsoncpp 69/278/
   yaml-cpp 56/114)→ 版本钉死 → 源码引入(Scintilla 同法)
4. **混合架构**:标准接口委托真库(Scintilla/libssh/yaml-cpp),
   fork 特性走自研(逆向);反哺链:源码→版本钉死→语料函数名→
   调用点反查→WindTerm 层定位
5. **动态验证**:Frida 挂 emit 桩实测状态迁移

## 相关文档

- **AGENTS.md**(根目录):完整方法论 + 13 项踩坑 + 构建配方
- **docs/PLAN.md**:202 项待收口计划(Phase 1-5)
- **docs/*.md**(18 个):SSH-INTERNALS / PROTOCOL-ARCHITECTURE /
  STATE-MACHINE / TERMINAL-CORE / EDITOR-ENGINE-COMMANDS(336 命令)/
  EDITOR-SCINTILLA-MAP(120 真名)/ SESSION-CONFIG-LAYER / 等
- **tools/re/BUILD.md**:CMake 构建详解 + 静态库配方
