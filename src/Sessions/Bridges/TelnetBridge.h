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
//   = spawnProxyProcess 已真身,否则 connectToHost 直连)—— 见
//   ProxyCommandSocket.h
// 网络腿真身化(2026-10-31 px 笔记,W4 破案;仅注释,d482/d24a 落点
//   ProxyCommandSocket.{h,cpp}):
// - FUN_0065d482 = spawnProxyProcess(S1 env/S2 new+setProgram/S3 args+
//   env+workdir/S4 4×Direct connect/S5 start 全落地;S6 RAII 展开)
// - FUN_0065d24a = setProxyCommand(c11e 拆词+尾 token 回填落地)
// - cited 维持:d01e 宏展开腿(c56a/a8b2e6)/C3 once-guard 注册段/
//   f7d0 槽闭包(jumptable,不在本类)
// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
class TelnetBridge : public SuperBridge
{
	Q_OBJECT

public:
	TelnetBridge(QObject *parent = nullptr);
	virtual ~TelnetBridge(void) override;

	// FUN_0087685a(9B)/FUN_00876864(23B)写转发:实接 ProxyCommandSocket
	// (write=0065d228 / connectToHost=0065f572,代理腿 spawnProxyProcess
	// 已真身)
	void writeToSocket(const QByteArray &bytes);
	void connectToTarget(const QString &host, unsigned short port);

signals:
	// 桥信号面(SuperBridge SMO 0x11a8140;session 侧承接 = 0x911exx 族)
	void commandOutput(const QString &context, const QString &output);

private slots:
	// readyRead lambda 008698c0 落点(批 83 真身:= 00911e60 纯信号转发)
	void onReadyRead();

private:
	// FUN_007c85dc(87B,0024.c:34783)状态门:`(s==+0x2c)&&(1<s-8U)` 去
	// 重(仅 Auth 区同值不重发)→ +0x2c=s → 00911ef2
	// emit stateChanged(state, extra)。(桥内 +0x2c 状态槽随本 helper
	// 落地;SuperSession 侧消费点后续批接线)
	void setState(King::SessionState state, const QVariant &extra);

private:
	ProxyCommandSocket *m_socket = nullptr;   // +0x30 ProxyCommandSocket 槽
	                                          // (FUN_00875ffe:new 0065f0a0)
	bool m_dialing = false;           // +0x18 自旋门(FUN_007c82e6)
	bool m_connected = false;         // +0x28(007c82e6 拨号成置 1)
	int m_state = 0;                  // +0x2c(FUN_007c85dc 状态门槽)

private:
	Q_DISABLE_COPY(TelnetBridge)
};

#endif // TELNETBRIDGE_H
