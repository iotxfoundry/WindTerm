# 校准映射 — 官方开源组件 → 我方子系统

> 来源:kingToolbox/WindTerm git 仓库 src/(Apache-2.0,作者第一方)。
> 原则:**这些代码就是"参考答案"——对应子系统停止逆向,改为移植/校准。**
> 终端仿真核心(Screen/TerminalCore/SuperCommander/EditorEngine)不在
> 其中 = 项目剩余逆向范围的权威边界确认。

| 开源组件 | 官方说明(README) | 我方对应 | 校准动作 |
|---|---|---|---|
| Utility/Cryptographic | PBKDF2(RFC 8018)+ 对称加解密,masterPassword 保护用户数据 | CONFIG-SCHEMAS 的 user.sessions auth blobs(此前只有密文样本) | **移植 + 用已知密文样本验证**;salt/key/iv 派生链直接对照 |
| Protocols/TelnetProtocol | Telnet 协议实现 | Phase 4a "Telnet 配置化"计划 | **计划改道:移植替代逆向**;telnet.protocol 配置面照旧 |
| Pty(UnixPty/WinPty/ConPty) | 基于 ptyqt 几乎全部重写 | 我方 pty 层(会话 I/O) | 会话装配阶段作参考实现 |
| Widgets(Splitter/ScrollBar/PopupWidget) | 64-bit range 滚动条等 | Phase 4c 主窗口 | 届时直接采用 |
| Utility/CircularBuffer | qint64 环形缓冲(pow2) | 性能/指标环(核对 +0xbc 限流面) | 遇环形缓冲特征即对照 |
| Utility/Spin, ScopeGuard, MemoryPointer, ThreadLocal | 自旋锁/RAII/智能指针/线程局部 | +0x118 自旋锁(标题缓冲)、RAII 守卫 cited 若干 | 命名/结构校准 |
| libssh(仓库版) | **基于 0.95 改:pageant、external socket、hmac-md5-96(-etm)、hmac-sha1-96(-etm)** | SuperSession 认证族(委托真库) | **diff 官方 0.95 = 作者改动清单 = 认证行为差异来源**;heavy,单独轮 |
| Onigmo(仓库版) | 基于 5.13.5 改:**新增 iterator 可匹配 gap buffer / 非邻接内存块** | EditorEngine 搜索面(行池 gap) | 搜索阶段:gap-buffer 匹配 = 作者给终端搜索用的机制 |

## 边界确认

仓库 **不含**:Screen/TerminalCore/SuperCommander/解析引擎(doAction +
QHash + xxhash 数据驱动分派)/EditorEngine/SessionManager/配置引擎/
渲染层——**这些 = 本项目逆向目标的全部**(与 PLAN.md 各阶段对齐)。

## 用法

1. 对应子系统开工前,先读本目录对应源码,再决定"移植 vs 逆向"。
2. 密文校验:user.sessions 的 blob 用 Cryptographic 解密对拍。
3. libssh/Onigmo 大件:按需从 git 仓库取(本目录未入库,168K 限额)。
