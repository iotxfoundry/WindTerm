#ifndef TELNETBRIDGE_H
#define TELNETBRIDGE_H

#pragma once

#include "SuperBridge.h"

#include "ProxyCommandSocket.h"

// 桥结构面(ts 笔记 §3;Telnet/Tcp 共用 TcpBridge 00875ffe,树面以
// TelnetBridge 承载同构成员布局 —— 写域限 Telnet 组件批,不触碰
// TcpBridge.*):
// - ctor 00875ffe(642B,new 0x38):SuperBridge 基(007c8290)→
//   +0x30 = new ProxyCommandSocket(0065f0a0,QTcpSocket 子类 0x40B)
// - connectImpl×4(ctor 内):
//     socket readyRead      → lambda 008698c0(context 00911e60,型 2)
//     socket errorOccurred  → 00875f1f
//     socket connected      → 00875eb0(→ FUN_007c85dc(3)+00911e28)
//     socket disconnected   → 008698c0(SerialBridge_h7c83c6 型 2)
// - 拨号门 007c82e6:桥 +0x18 自旋门(0x38ms backoff/sched_yield/
//   nanosleep 100ns→10µs)→ 桥虚 +0xb8(param=host,port)→ +0x28=1
// - 关闭腿 0087687c:FUN_00911e4c → socket→FUN_0065cf9c(deleteLater
//   进程 + 直发 disconnected,见 ProxyCommandSocket::disconnectProxy)
//   → FUN_007c85dc(0,…)
// - 写出面 0087685a/00876864 → socket(0065d228:代理 +0x30 在则走
//   代理,否则直写;0065f572:m_command 非空走 FUN_0065d482 代理分支
//   [cited — wave-2],否则 connectToHost 直连)—— 见 ProxyCommandSocket.h
// - 网络腿(ProxyCommandSocket 代理进程分支 FUN_0065d482 6947B、命令
//   拆词 FUN_0065d24a 551B、槽闭包 jumptable)cited — wave-2,落点见
//   ProxyCommandSocket.{h,cpp}(直连/写/读/options 腿已实接)。
// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
class TelnetBridge : public SuperBridge
{
	Q_OBJECT

public:
	TelnetBridge(QObject *parent = nullptr);
	virtual ~TelnetBridge(void) override;

	// FUN_0087685a(9B)/FUN_00876864(23B)写转发:实接 ProxyCommandSocket
	// (write=0065d228 / connectToHost=0065f572,代理腿 cited)
	void writeToSocket(const QByteArray &bytes);
	void connectToTarget(const QString &host, unsigned short port);

signals:
	// 桥信号面(SuperBridge SMO 0x11a8140;session 侧承接 = 0x911exx 族)
	void commandOutput(const QString &context, const QString &output);

private slots:
	// readyRead lambda 008698c0 落点(真调用腿 jumptable 未复原,
	// cited — wave-2;socket 读腿分流已在 ProxyCommandSocket 实接)
	void onReadyRead();

private:
	ProxyCommandSocket *m_socket = nullptr;   // +0x30 ProxyCommandSocket 槽
	                                          // (FUN_00875ffe:new 0065f0a0)
	bool m_dialing = false;           // +0x18 自旋门(FUN_007c82e6)
	bool m_connected = false;         // +0x28(007c82e6 拨号成置 1)

private:
	Q_DISABLE_COPY(TelnetBridge)
};

#endif // TELNETBRIDGE_H
