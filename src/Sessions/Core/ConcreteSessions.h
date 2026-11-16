#pragma once

#include "Sessions/Core/SuperSession.h"

// ConcreteSessions.h — 三个协议会话(全部 SuperSession 直接派生,**零字段**)。
//
// 三者 QMetaObject 的 metacall 都是 **5 字节纯转发** ⇒ 0 条自有信号槽;
// superdata 均实读为 **0x011a8220 = SuperSession**
// (methods=59 / **signals=11**:asyncMessage / autoLoginFailed /
//  commanderCreated / commandOutput / errorOccurred / loggerCreated /
//  loggerRemoved / stateChanged / syncMessage / …)。
//
// | 类 | dtor | deleting | 其他 |
// |---|---|---|---|
// | SerialSession | 0x009189bc(19B) | 0x009189d0(37B) | — |
// | SshSession    | 0x00918444(19B) | 0x00918458(37B) | vt15 0x0086f1c2(57B) |
// | TcpSession    | 0x00919146(19B) | 0x0091915a(37B) | — |
//
// 三者 dtor 都是 19B(只有 SuperSession 析构)⇒ **零自有字段**。
// SshSession 的 vt15(57B)与 SshCommander 的 vt12 同构:门 `+0x10` 非空后
// `__dynamic_cast(+0x10, …, 0x011a8f30)` —— 会话侧从 +0x10 取句柄。
//
// ⚠ **+0x40/+0x48(commander 侧)与 +0x10(会话侧)是两对不同指针**,
//   两边各自 dynamic_cast 同一目标类型(0x011a8f30)。不要因为"都 cast 到
//   同一个类型"就以为是同一个字段。

class SerialSessionFace : public SuperSession {
	Q_OBJECT
public:
	explicit SerialSessionFace(QObject *parent = nullptr);
	~SerialSessionFace() override; // 0x009189bc
};

class SshSessionFace : public SuperSession {
	Q_OBJECT
public:
	explicit SshSessionFace(QObject *parent = nullptr);
	~SshSessionFace() override; // 0x00918444
};

class TcpSessionFace : public SuperSession {
	Q_OBJECT
public:
	explicit TcpSessionFace(QObject *parent = nullptr);
	~TcpSessionFace() override; // 0x00919146
};
