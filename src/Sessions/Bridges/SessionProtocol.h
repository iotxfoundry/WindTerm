#ifndef SESSIONPROTOCOL_H
#define SESSIONPROTOCOL_H

#include <QString>

// SessionProtocolFace —— 语料协议对象层最小虚面(KitWindowFace 抽象基
// 判例,批 133/142:抽象身份 + 纯虚槽,槽位由 C++ 自洽,不追语料
// vtable 精确 ABI 对位)。q+0x10 协议对象槽(SuperSession.h m_protocol)
// 非空时,FUN_007d4d9c(39B,0025.c:4080)虚表 +0x68 槽调面取 label
// (sret 形态 = QString 返回;同族消费腿 FUN_007d4dc4 +0x78/
// FUN_007d6736/FUN_007d4dda,cited)。
// 语料协议对象 ctor 族(便携 ctor Tcp 00876a16/Telnet 0085f520/
// SSH 008699b0/Serial 0086ff6c/Shell 008750e6,对象 ≥0x128B)+ 主升面
// FUN_007cd120 深依赖未开 → face + cited 分段:本壳零实例字段、零
// 构造点(铁律 6:无转写落点的行为代码不入库,构造腿 cited 挂
// insertTermSession 注记),只有虚槽声明 = 消费面。
// 桥真身链(批 155 注记):协议对象下行桥 vtable 面 —— TcpBridge_vt13
// 008762f4 / SshBridge_vt13 00862692(label 腿经 socket peerAddress
// 装配;cited,桥下行层未开)。
class SessionProtocolFace
{
public:
	virtual ~SessionProtocolFace() = default;
	// vtable +0x68 label 槽(FUN_007d4d9c @007d4da2 虚调;批 155
	// SessionLogger::virtualLabel 升真为真虚调)
	virtual QString label() const = 0;
};

#endif // SESSIONPROTOCOL_H
