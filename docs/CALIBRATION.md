# 校准映射 — src/ 内官方开源组件 → 我方子系统

> 我方 src/ 本就包含官方开源的全部组件(== kingToolbox/WindTerm 仓库
> src/,Apache-2.0 第一方)。原则:对应子系统**停止逆向,改为移植/校准**。
> 终端核心(Sessions/ 的 Screen/TerminalCore/SuperCommander、Editor/、
> 解析引擎)不在开源集 = 项目逆向范围的权威边界确认。

| 组件(src/ 下) | 官方说明(src/README.md) | 校准动作 |
|---|---|---|
| Utility/Cryptographic | PBKDF2(RFC 8018)+ 对称加解密,masterPassword 保护用户数据 | 用 user.sessions 已知密文**对拍验证**;salt/key/iv 链直接对照 |
| Protocols/TelnetProtocol | Telnet 协议实现 | Phase 4a Telnet 计划改道:**移植替代逆向** |
| Pty(UnixPty/WinPty/ConPty) | 基于 ptyqt 几乎全部重写 | 会话装配阶段的参考实现 |
| Widgets(Splitter/ScrollBar/PopupWidget) | 64-bit range 滚动条等 | Phase 4c 直接采用 |
| Utility/CircularBuffer, Spin, ScopeGuard, MemoryPointer, ThreadLocal | 环形缓冲/自旋锁/RAII/智能指针/线程局部 | +0x118 自旋锁等命名结构校准 |
| libssh(改版) | 基于 0.95:pageant、external socket、hmac-md5-96(-etm)、hmac-sha1-96(-etm) | **diff 官方 0.95 = 认证行为差异清单**(单独轮) |
| Onigmo(改版 5.13.5) | 新增 iterator 可匹配 gap buffer/非邻接内存块 | EditorEngine 搜索面机制对照 |
| Scintilla/jsoncpp/yaml-cpp/dtl/fmt/spdlog | 第三方原版 | 已按 EXT-BOUNDARY 委托真库 |
