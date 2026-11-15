#ifndef TCPBRIDGE_H
#define TCPBRIDGE_H

#pragma once

#include "SuperBridge.h"
#include "SessionProtocol.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperBridge.
//
// 批 161:协议对象构造窄面 —— TcpBridge_vt13(008762f4,55B)= label 腿:
// socket(QAbstractSocket)peerAddress().toString();vt14(00876334,18B)=
// peerName()。生产链 = 桥工厂 007d846e(qstricmp "Tcp"/"Telnet" →
// operator_new(0x38) → FUN_00875ffe)→ +0x10 槽;SessionProtocolFace
// 经 SessionLogger::virtualLabel(@007d4da2 虚表 +0x68)消费。
// 批 165:ctor 4×connectImpl 升真(FUN_00875ffe 642B,decomp-part-0027.c:
// 18673 asm/体双源实读):
//   readyRead    → lambda 008698c0(型2)→ 00911e60 = emit readyRead()(idx5)
//   errorOccurred→ 00875f1f(206B):socket 非 0 门 → 0065d202 态映射 ==0
//                  → setState(0)→ 00911eb6 = emit errorOccurred(code,errStr)
//   connected    → 00875eb0(103B):setState(3,∅)→ 00911e28 = emit attached()
//   disconnected → lambda 008698c0(型2)→ SerialBridge_h7c83c6(007c83c6,
//                  271B):自旋门收口 → +0x28(bit5)置位时虚+0xc0 关闭腿
//                  (= 0087687c:detaching→socket disconnectProxy→setState(0)
//                  →detached)→ errorOccurred(0,∅)→ +0x28 清 0
//   setState = FUN_007c85dc(87B,0024.c:34783)同值去重门(同 TelnetBridge)。
// socket 挂点:ctor +0x30 = ProxyCommandSocket(0065f0a0 以桥为 parent,
// findChild 对位 —— 语料 socket 恒在;真拨号 connectToHost = 0065f572
// 分流,m_command 非空走 spawn 代理;cited 外库/网络边界)。
class TcpBridge : public SuperBridge, public SessionProtocolFace
{
	Q_OBJECT

public:
	TcpBridge(QObject *parent = nullptr);
	virtual ~TcpBridge(void) = default;

	// TcpBridge_vt13(008762f4,55B,decomp-part-0027.c:18791):
	// QAbstractSocket::peerAddress().toString() —— socket 槽 +0x30
	// 对位非空卫(未连 → 空 QHostAddress → 空串,Qt 语义同语料)。
	QString label() const override;
	// TcpBridge_vt14(00876334,18B):peerName()(QHostInfo 反查名,
	// 未连 → 空)
	QString peerNameLabel() const;

private slots:
	// lambda 008698c0(readyRead 型2 连接)落点:= 00911e60 纯信号转发
	// (批 83 TelnetBridge 判例同构)。
	void onReadyRead();

private:
	// 关闭腿 vt+0xc0(= 0087687c,78B,0027.c:19061)转写 ——
	// SerialBridge_h7c83c6 disconnected 腿消费(emit detaching → socket
	// disconnectProxy → setState(0) → emit detached)。
	void closeLeg();
	// FUN_007c85dc(87B)状态门:`(s==+0x2c)&&(1<s-8U)` 去重(仅 Auth
	// 区同值不重发)→ +0x2c=s → 00911ef2 emit stateChanged(state,extra)。
	bool setState(King::SessionState state, const QVariant &extra);

private:
	int m_state2c = 0;                // +0x2c(007c85dc 状态门槽)
	bool m_connectedBit = false;      // +0x28 bit5(h7c83c6 关闭腿卫)

private:
	Q_DISABLE_COPY(TcpBridge)
};

#endif // TCPBRIDGE_H
