# SuperSession 状态机(动态实测 + 枚举注册表交叉)

> 方法:Frida attach(临时 ptrace_scope=0)挂钩 stateChanged 发射桩 0x91237e,
> 实测一次成功 SSH 连接与断开;枚举名值来自 QMetaObject 枚举注册表(KingEnums.h)。

## 实测迁移序列

```
连接(成功):Unconnected → Connecting → Connected → HostVerified → HostAuthed
                    (+98ms)     (同毫秒)        (+250ms)
断开:            HostAuthed → Unconnected(直落,无 Closing 中间态)
```

## 状态机图(实证 + 合理推断)

```
                 ┌──────────────┐  host key   ┌─────────────┐ auth ok  ┌──────────┐
 Unconnected ──→ │  Connecting  │ ──TCP ok──→ │  Connected  │ ───────→ │HostAuthed│
     ▲    open() └──────┬───────┘             └──────┬──────┘          └────┬─────┘
     │                  │ DNS 解析前                  │ host key denied      │ auth denied
     │                  ▼                           ▼                      ▼
     │            HostLookup                    HostDenied*            HostDenied*
     │                                                                (推断*)
     └──────────────────────────── close()/drop ────────────────────────────┘
```

带 `*` 的边未在本轮观测(目标主机直连 IP,未触发 DNS;认证一次成功)。
Bound/Closing/Listening 属隧道/半开场景(TunnelType 枚举佐证),未触发。

## 关键结论

1. **断开路径无中间态**:HostAuthed 直落 Unconnected(无 Closing)—— Closing 保留给
   优雅关闭等待(waitForSessionClosed 槽佐证)
2. HostVerified 在 Connected 同毫秒发出 —— 主机密钥校验内联在连接回调里
3. 状态全部经同一个 emit 桩(0x91237e)广播,UI(TerminalWidget::sessionStateChanged)
   与 Bridge 处理器统一消费
