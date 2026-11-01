#include "TelnetBridge.h"

#include <QAbstractSocket>
#include <QVariant>
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
	// (connectImpl:QIODevice::readyRead → lambda 008698c0;真身见文件尾
	// onReadyRead)
	connect(m_socket, &QTcpSocket::readyRead, this, &TelnetBridge::onReadyRead);
	// connectImpl:errorOccurred → FUN_00875f1f(206B,0027.c:18625):
	// socket(+0x30)非空门 → ① 0065d202 态映射(socket 直返 state())==0
	// → FUN_007c85dc(this,0,∅) 状态门 → 00911ef2 emit stateChanged(Unconnected,∅);
	// ② 0065cfc0 = QIODevice::errorString();③ 00911eb6 = emit
	// errorOccurred(code, errStr)(code 前errStr 后,签名勘正批 83 C4)。
	connect(m_socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError code) {
		if (m_socket != nullptr) {   // 00875f2e:+0x30 非空门
			if (m_socket->state() == QAbstractSocket::UnconnectedState)   // 0065d202:socket 直返 state();875f4c 映射态==0 门
				setState(King::SessionState::Unconnected, QVariant());   // 007c85dc(this,0,∅)→ 00911ef2
			emit errorOccurred(static_cast<int>(code), m_socket->errorString());   // 00911eb6(00875f6c errString + 00875f76 emit)
		}
	});
	// connectImpl:connected → FUN_00875eb0(103B,0027.c:18599):
	// FUN_007c85dc(this,3,∅) 状态门 → 00911ef2 emit stateChanged(Connected,∅)
	// → 00911e28 emit attached()(SMO idx0)。
	connect(m_socket, &QTcpSocket::connected, this, [this]() {
		m_connected = true;   // 007c82e6 拨号成置 +0x28=1
		setState(King::SessionState::Connected, QVariant());   // 007c85dc(this,3,∅)→ 00911ef2(00875ee1)
		emit attached();   // 00911e28(00875ef8,SMO idx0)
	});
	// connectImpl:disconnected → lambda 008698c0(SerialBridge_h7c83c6
	// 自旋门 → vtable+0xc0 虚调用 → 状态收口):置 +0x28=0;
	// 状态门腿 FUN_007c85dc(0,∅) 随桥状态机装配批接线(cited — wave-2)。
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

// FUN_007c85dc(87B,decomp-part-0024.c:34783)同构:同值去重门
// `(s == +0x2c) && (1 < s-8U)`(无符号减法 ⇒ 仅 s==8/9 大于 1…即 Auth
// 态同值不重发;其余同值也 emit——语料原样,见 QUIRKS 候选)→
// 写 +0x2c → 00911ef2 emit stateChanged(state, extra)。
void TelnetBridge::setState(King::SessionState state, const QVariant &extra)
{
	const int s = static_cast<int>(state);
	if (s == m_state && (1 < static_cast<unsigned>(s) - 8U))
		return;   // 007c85dc:同值且 s-8U>1(Auth 区)才去重
	m_state = s;   // +0x2c
	emit stateChanged(state, extra);   // 00911ef2(0030.c:1452)
}

// lambda FUN_008698c0(102B,decomp-part-0027.c:8680)= Qt5 QSlotObjectBase
// 分发器(case 0=destroy/1=call/2=compare);invoke 腿 @0086990b
// `jmp *%rcx` = 闭包+0x10 槽指针间接调用(Ghidra jumptable WARNING 误报,
// 无跳表)。readyRead 连接闭包 = {00911e60, this}(00875ffe ctor 18696 行)
// → activate(SMO 0x11a8140, idx5) = emit readyRead() 纯信号转发;
// connectImpl type=2(QueuedConnection)。协议解析在下游会话/协议层。
void TelnetBridge::onReadyRead()
{
	emit readyRead();   // 00911e60(0030.c:1402,activate idx5;批 74 空壳 → 真身)
}
