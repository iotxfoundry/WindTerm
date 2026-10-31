#include "TelnetBridge.h"

#include <QTcpSocket>

// ctor 语料 = FUN_00875ffe(642B):SuperBridge 基(007c8290)→
// +0x30 = new ProxyCommandSocket(0065f0a0)→ 4×connectImpl
// (readyRead/errorOccurred/connected/disconnected,见 TelnetBridge.h
// 头注)。树面 socket = QTcpSocket 承位(ProxyCommandSocket 网络底座
// cited — wave-2,待其组件批替换承位);读/写/态腿按语料接线。
TelnetBridge::TelnetBridge(QObject *parent)
	: SuperBridge(parent)
{
	// FUN_00875ffe:param_1[6] = new ProxyCommandSocket(this)
	m_socket = new QTcpSocket(this);
	// connectImpl:QIODevice::readyRead → lambda 008698c0
	connect(m_socket, &QTcpSocket::readyRead, this, &TelnetBridge::onReadyRead);
	// connectImpl:errorOccurred → FUN_00875f1f
	connect(m_socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
		// FUN_00875f1f 真身待转写(语料:cited — wave-2)
	});
	// connectImpl:connected → FUN_00875eb0(→ FUN_007c85dc(3) + 00911e28)
	connect(m_socket, &QTcpSocket::connected, this, [this]() {
		m_connected = true;   // 007c82e6 拨号成置 +0x28=1
		// FUN_00875eb0 下行(007c85dc(3) 状态置 + 00911e28 信号)
		// cited — wave-2:状态机槽面随 SuperSession 批
	});
	// connectImpl:disconnected → lambda 008698c0(SerialBridge_h7c83c6)
	connect(m_socket, &QTcpSocket::disconnected, this, [this]() {
		m_connected = false;   // SerialBridge_h7c83c6 置 +0x28=0
	});
}

// dtor 语料 = TcpBridge_dtor(00876290,75B):SerialBridge_h7c83c6
// (自旋门收口)→ SuperBridge 基 → delete +0x30 → QObject 基。
TelnetBridge::~TelnetBridge()
{
	delete m_socket;   // 语料引用减计数后 operator_delete(+0x18 槽)
}

// FUN_0087685a(9B)同构:FUN_0065d228(+0x30 代理在则走代理写,
// 否则 QIODevice::write 直写)。
void TelnetBridge::writeToSocket(const QByteArray &bytes)
{
	if (m_socket != nullptr)
		m_socket->write(bytes);   // FUN_0065d228:QIODevice::write 直写分支
}

// FUN_00876864(23B)同构:FUN_0065f572 → QAbstractSocket::connectToHost
// (代理分支 FUN_0065d482 = ProxyCommandSocket 内部,cited — wave-2)。
// 拨号门 FUN_007c82e6(自旋 +0x18 → 桥虚 +0xb8)为会话侧入口,树面
// 直接落 connectToHost(自旋门单线程装配态无竞争,cited 注记)。
void TelnetBridge::connectToTarget(const QString &host, unsigned short port)
{
	if (m_socket != nullptr)
		m_socket->connectToHost(host, port);   // FUN_0065f572 直连分支
}

// lambda FUN_008698c0(102B)readyRead 落点:读腿(字节上行入会话)
// 依赖会话承接面(0x911exx 信号族)cited — wave-2;现仅语料入口位。
void TelnetBridge::onReadyRead()
{
	// 008698c0 真身:jumptable 未复原(Ghidra WARNING),下行承接
	// 面未定 —— cited — wave-2,禁止按"终端应该怎样"补读循环。
}
