#include "TelnetBridge.h"

#include <QAbstractSocket>
#include <QTcpSocket>

// ctor 语料 = FUN_00875ffe(642B):SuperBridge 基(007c8290)→
// +0x30 = new ProxyCommandSocket(0065f0a0)→ 4×connectImpl
// (readyRead/errorOccurred/connected/disconnected,见 TelnetBridge.h
// 头注)。socket 槽 = ProxyCommandSocket 真身(0065f0a0 转写,
// 见 ProxyCommandSocket.{h,cpp});读/写/态腿按语料接线。
TelnetBridge::TelnetBridge(QObject *parent)
	: SuperBridge(parent)
{
	// FUN_00875ffe:param_1[6] = new ProxyCommandSocket(this)(0065f0a0)
	m_socket = new ProxyCommandSocket(this);
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

// FUN_0087685a(9B)同构:直调 socket→FUN_0065d228(转写 =
// ProxyCommandSocket::write:m_process 在走进程 stdin,否则直写)。
void TelnetBridge::writeToSocket(const QByteArray &bytes)
{
	if (m_socket != nullptr)
		m_socket->write(bytes);   // FUN_0065d228(0065f0a0 转写,实接)
}

// FUN_00876864(23B)同构:直调 socket→FUN_0065f572(转写 =
// ProxyCommandSocket::connectToHost:m_command 非空走 FUN_0065d482 代理
// 分支 [cited — wave-2],否则 QAbstractSocket::connectToHost 直连)。
// 拨号门 FUN_007c82e6(自旋 +0x18 → 桥虚 +0xb8)为会话侧入口,树面
// 直接落 connectToHost(自旋门单线程装配态无竞争,cited 注记)。
void TelnetBridge::connectToTarget(const QString &host, unsigned short port)
{
	if (m_socket != nullptr)
		m_socket->connectToHost(host, port);   // FUN_0065f572(实接;代理腿 cited)
}

// lambda FUN_008698c0(102B,decomp-part-0027.c:8680)readyRead 落点:
// 体为 Qt 元调用分发器(param_1 型 1/2/0),真调用腿 @0086990b jumptable
// 未复原(Ghidra WARNING)→ 下行承接面未定,cited — wave-2,禁止按
// "终端应该怎样"补读循环。socket 侧读腿分流(进程/自身)已在
// ProxyCommandSocket::read/readAll 实接(0065cfe4/0065cffa)。
void TelnetBridge::onReadyRead()
{
}
