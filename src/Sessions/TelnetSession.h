#ifndef TELNETSESSION_H
#define TELNETSESSION_H

#pragma once

#include "SuperSession.h"

// 装配五元组(批 70 勘察,ts 笔记;铁律 6:实现面待 TcpBridge/
// ProxyCommandSocket 组件批,现壳不动行为):
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

private:
	Q_DISABLE_COPY(TelnetSession)
};

#endif // TELNETSESSION_H
