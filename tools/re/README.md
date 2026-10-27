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
| `data/ida_makeqmo2.py` | IDA 控制台批量建函数(create_insn→add_func,FDE 端点) | IDA Python: `exec(open(...).read())` |

## 数据产物(data/)

| 文件 | 内容 |
|---|---|
| `king_api.json` | 61 个 King 类完整方法表(名/参数/分类) |
| `super_bases.json` | SuperSession/Bridge/Commander 方法+枚举 |
| `super_sigs.json` | 三基类方法签名(带类型) |
| `fdes.json` | 30,566 函数边界(VA+长度) |
| `proto_hierarchy.json` | 协议五元组继承表 |
| `ssh_callsites.json` | libssh 49 API 全部调用点 |
| `proto_callsites.json` / `qt_got_calls.json` | Serial/Tcp 家族调用点(开放问题数据) |

## 已验证方法

1. **QMetaObject 模式匹配**:`.data.rel.ro` 四字段模式(super/stringdata/data/metacall 分区)
   + RELATIVE 重定位回填 + QArrayData(24B)头表解析
2. **metacall case ↔ 方法索引对齐**:Ghidra 反编译 `switch(param_3)` 与 moc 表序号一一对应
3. **PLT/GOT 双路解析**:直接 e8 调用 + BIND_NOW 的 GOT 间接调用都要扫(本二进制仅 350 直调)
4. **动态验证**:Frida 挂 emit 桩实测状态迁移(静态歧义一跑即消)

## 相关文档

实现还原与结论见 `src/Sessions/*.md`(SSH-INTERNALS / PROTOCOL-ARCHITECTURE /
STATE-MACHINE / IMPL-ADDRESSES / enums-recovered)。
