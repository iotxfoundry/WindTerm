#pragma once

#include "Sessions/Commanders/SuperCommander.h"

// ConcreteCommanders.h — 三个协议命令器(全部 SuperCommander 直接派生,**零字段**)。
//
// 三者 QMetaObject 的 metacall 都是 **5 字节纯转发** ⇒ 0 条自有信号槽;
// superdata 均实读为 **0x011a7440 = SuperCommander**(59 条方法的一张表)。
// dtor 分别 29B / 42B / 29B,内容只有"vptr 复位 + SuperCommander 析构"
// ⇒ **零自有字段**,差异全在协议实现里。
//
// | 类 | superdata | dtor | deleting | 其他 |
// |---|---|---|---|---|
// | SerialCommander | 0x011a7440 SuperCommander | 0x009188ba(29B) | 0x009188f8(47B) | — |
// | SshCommander    | 同上 | 0x00869a1c(42B) | 0x00869a4c(23B) | vt12 0x00869a16(5B) |
// | TcpCommander    | 同上 | 0x00919044(29B) | 0x00919082(47B) | h90ef1c **5928B**(cited) |
//
// SshCommander 的 vt12(5B)是一段 getter:门 `+0x48 && +0x40` 之后
// `__dynamic_cast(+0x40, …, 0x011a8f30)` 再调 `FUN_0086247e(x, +0x48)`
// —— 即"从句柄取到某个具体类型再交给桥"。**+0x40/+0x48 是句柄对**。
//
// TcpCommander 的 0x0090ef1c(5928B)是全仓最大的单函数之一,本批只锚入口;
// 它属于 TCP 协议实现面,与其余两个 commander 的协议实现同批开。

class SerialCommanderFace : public SuperCommander {
	Q_OBJECT
public:
	explicit SerialCommanderFace(QObject *parent = nullptr);
	~SerialCommanderFace() override; // 0x009188ba
};

class SshCommanderFace : public SuperCommander {
	Q_OBJECT
public:
	explicit SshCommanderFace(QObject *parent = nullptr);
	~SshCommanderFace() override; // 0x00869a1c
};

class TcpCommanderFace : public SuperCommander {
	Q_OBJECT
public:
	explicit TcpCommanderFace(QObject *parent = nullptr);
	~TcpCommanderFace() override; // 0x00919044
};
