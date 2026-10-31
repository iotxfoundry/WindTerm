#ifndef TELNETSESSION_H
#define TELNETSESSION_H

#pragma once

#include "SuperSession.h"

class TelnetBridge;

// 装配五元组(批 70 勘察,ts 笔记;本批:桥结构面 + vt15 真身落地,
// 网络腿/Commander 写出腿 cited — wave-2 待 ProxyCommandSocket):
// - vtable 0x11a8e78;sizeof 0x68;ctor 008616d0(25B,零自有成员)
// - 槽表:metaObject 00917f76/metacast 00917f8e/metacall 00917fd0
//   (信号 12 特判 → -1,怪癖候选)/D2·D1/+0x60=007d952e 拨号槽/
//   +0x78=008616ea vt15 唯一自有虚(cast +0x10→TcpBridge,写 2B IAC)
// - 创建链:s_session_proxyHost_7be0a6 → 工厂 007d48ce("Telnet"→
//   new 0x68)→ 装配点 FUN_007bc21e(SessionThread + 6×connectImpl
//   至 SuperSession SMO 0x11a8220)
// - Commander:session_applySetting(007dc146)case 0xc → 工厂
//   007d9776 → TelnetCommander(new 0x140;ctor 0085f520)
// - Bridge:拨号槽 → 007d846e(Telnet/Tcp 共用 TcpBridge 00875ffe),
//   存会话 +0x10;socket = ProxyCommandSocket(0065f0a0,QTcpSocket
//   子类)@TcpBridge+0x30;读 = readyRead→lambda 00869 8c0,写 =
//   008768 5a/64 → 0065d228/0065f572
// - 勘正:negotiationReply 语料无同名信号 —— 协商写出 = vt15 直调
//   socket 写(0x0b 尾字节),无 connectImpl;我方信号 = 架构化替代
// - 未解:session id 注入点/Commander→socket 落地/metacall 信号 12
//   特判语义
// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperSession.
class TelnetSession : public SuperSession
{
	Q_OBJECT

public:
	TelnetSession(QObject *parent = nullptr);
	virtual ~TelnetSession(void) = default;

	// TelnetSession_vt15(008616ea,303B;vtable +0x78 唯一自有虚)
	// 真身:cast 桥 → 2B{IAC,0x0b} 经桥写(negotiationReply 勘正
	// 见 TelnetCommander.h;语料面 = 直调非信号)
	void negotiationWrite();

private:
	// 会话 +0x10 = 桥指针槽(语料:FUN_007d846e 装配 TcpBridge 于
	// session+0x10;树面基类 m_protocol 同位但私有,写域限本批 →
	// TelnetBridge 本地承载,TcpBridge 语料结构面见 TelnetBridge.h)
	TelnetBridge *m_bridge = nullptr;

private:
	Q_DISABLE_COPY(TelnetSession)
};

#endif // TELNETSESSION_H
