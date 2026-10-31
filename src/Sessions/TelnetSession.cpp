#include "TelnetSession.h"
#include "TelnetBridge.h"

// ctor 语料 = FUN_008616d0(0x8616d0,25B):FUN_007d807e(SuperSession
// 基)+ 置 vtable 0x11a8e78,零自有成员动作(桥由装配点 007d846e 于
// 会话 +0x10 注入,非 ctor)。
TelnetSession::TelnetSession(QObject *parent)
	: SuperSession(parent)
{
}

// TelnetSession_vt15(008616ea,303B)真身转写:
//   if (+0x10 == 0) return;
//   bridge = __dynamic_cast(+0x10, SuperBridge ZTI → TcpBridge ZTI);
//   if (bridge == 0) return;
//   QByteArray(2, -1); [0]=0xff(IAC) [1]=0x0b;   // 尾字节 0x0b
//   FUN_0087685a(bridge, bytes, session, 0)      // 桥写出面 → socket
// (勘正:语料为直调非信号;negotiationReply 信号无语料先例)
void TelnetSession::negotiationWrite()
{
	if (m_bridge == nullptr)
		return;
	// __dynamic_cast 落点:桥工厂 007d846e 只装 TcpBridge(00875ffe),
	// Telnet 与 Tcp 共用,cast 恒成;树面桥即 TcpBridge 结构承载。
	QByteArray bytes(2, '\0');
	bytes[0] = '\xff';   // IAC(语料 QArrayData 写 local_20[lVar2+1] 前
	                     // 置 0x18 首槽;尾字节 0x0b 为 vt15 常量实证)
	bytes[1] = '\x0b';
	// FUN_0087685a(bridge,bytes,session,0) → socket 写;树面桥写出
	// 真身 = TelnetBridge::writeToSocket(0087685a 同构)
	m_bridge->writeToSocket(bytes);
}
