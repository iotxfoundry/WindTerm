# 新会话起点(交接文档)

> 用途:新会话冷启动。先读 AGENTS.md → 本文件 → docs/PLAN.md,即可无缝续作。

## 一句话状态(2026-10-28 终态)

**Phase 0/1/2 全部收口;Phase 4b 槽覆盖完成;Phase 3 批量模式运行中。**
libWindTermRe.so 9.2MB,dlopen OK;e2eterm 25 断言 + recheck 22 例 +
engtest×2 + sshsmoke 全绿。gen_stubs 70→**5**(全为 Phase-3/4 深项)。

## 里程碑链(全部 ✅)

语法/moc/编译/链接/dlopen → 三层真实现(终端栈 259/259、编辑引擎
混合、SSH 认证)→ CMake 构建(增量 0.08s,静态库入库)→ 目录归位 →
**moc 权威抽取器**(Screen 37 信号/SuperSession 59/SuperCommander 264
三表入库)→ **行为测试矩阵**(e2eterm/recheck)→ **配置层贯通**
(CTerminalConfig+ProfileLoader)→ **端到端写路径**(ASCII/UTF-8/
wrap/SGR)→ **Phase 4b TerminalWidget 58 槽覆盖**。

## 目录结构

```
src/
  Sessions/   ← 会话层(SuperCommander 264 槽/Screen/TerminalCore/
                SuperSession;gen_stubs.cpp 仅剩 5 深项)
  Editor/     ← EditorEngine(混合层)+ ConfigBridge + CTerminalConfig
                + ProfileLoader + EditorContext.h
  Widgets/    ← TerminalWidget(58 槽)+ SessionManager + TextView +
                ScrollBar/Splitter/PopupWidget
  Protocols/  ← Telnet
  Utility/    ← KingEnums + Cryptographic + ThreadLocal
  Scintilla|libssh|Onigmo|jsoncpp|yaml-cpp  ← 五源码树
lib/          ← 原版 .so + 预构建 .a(20MB)
docs/         ← 19 .md(含 PLAN.md/QUIRKS.md)
tools/re/     ← 逆向工具链 + 49M decomp + metatest/(5 测试)+ data/
```

## 构建/验证(每轮提交门)

```bash
mkdir build && cd build && cmake .. && make -j$(nproc)   # 增量 0.08s
LD_LIBRARY_PATH=build:lib QT_QPA_PLATFORM=offscreen \
  python3 -c "import ctypes; ctypes.CDLL('build/libWindTermRe.so')"
# 测试(改头文件后必须重编!踩坑 15):
g++ -std=c++17 -fPIC -o /tmp/e2e tools/re/metatest/e2eterm.cpp …(-L build -lWindTermRe)
```

## 测试策略(PLAN.md 头部成文)

**测试跟随真身化,不领先。** e2eterm(25 断言)/recheck(22 例)冻结
为提交门;不向未完成子系统扩展;失败测试按 docs/QUIRKS.md 裁决
(10 条原版怪癖登记,禁止按"终端应该怎样"修)。

## 关键方法论资产(本轮新增)

1. **moc 权威抽取器**(tools/re/data/*_moc_methods.json ×3):
   stringdata = 每串一 QArrayData(24B 步长),offset 相对条目自身;
   data[4]/[5]=方法数/偏移;每方法 5 uint(name/argc/params/tag/flags)。
   任意类的 moc 方法名/序/签名可权威抽出——**禁止按 pool 位置猜名**。
2. **metacall 全映射**:supercommander_metacall_map.json(264 槽 case→
   target+权威名)。教训:SuperCommander.h 声明序 ≠ 原 moc 序。
3. **数据表 dump 法**:宽度表(1307 区间)/字符集注册表(31)/
   terminfo(92)从 .rodata/.data.rel.ro 直接 dump 入 .inc。
4. **IDA = Ghidra − 0x400000**;kuna disassemble 用于寄存器级确认
   (如 FUN_007a2bd4 第二参=ESI 直透)。

## 下一步(按优先级)

1. **Phase 3 批 3**:editctx 迭代器模型(FUN_00a169cc/00a167ac 对
   跳转)+ pair 批 0x75b4/75b5;之后 0x7558/7567/7568 margin 元数据批
2. **Phase 4 深腿**:渲染层(调色板/字体/视口——TerminalWidget 目前
   无 paint)、会话栈(+0x1e0/+0x1e8)、对话框面
3. **SessionLogger moc 抽取**(loggerOp 的 FUN_007c1b92 sink 面)
4. **Phase 5**:离屏渲染对比(需渲染层先行)

## 已知开放问题

- convertRowToHistory(007a9582,1262B)= RunStyles/PieceTable 文档
  桥,待 Phase-4 文档模型(可直接对接 src/Scintilla 的 RunStyles)
- notifyIterm2 CursorShape 腿(007e3b12/007cc828)、setHyperlinkTarget
  (007f43ce,457B)cited
- vt14 门控 +0xfc 命令器成员、+0x12c 写屏门语义待 Commander 状态面
- wind.config 数组缺逗号 QUIRK 已由 jsoncpp 容错覆盖(QUIRKS 无条目,
  见 ProfileLoader parseTolerant 注释)

## 提交规范(不变)

中文 commit;push 必带 `-c http.proxy=http://192.168.1.106:7890`;
每轮:改动 + 对应 .md 更新,一条 commit 一条 push。
