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
// 经 SessionLogger::virtualLabel(@007d4da2 虚表 +0x68)消费。socket
// 深依赖(连接建立/网络腿)cited —— 本 face 壳承接 label 生产面,
// socket 挂点由派生桥(TelnetBridge ProxyCommandSocket 对位)装配。
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

private:
	Q_DISABLE_COPY(TcpBridge)
};

#endif // TCPBRIDGE_H
