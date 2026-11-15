#include "TcpBridge.h"
#include "ProxyCommandSocket.h"

#include <QAbstractSocket>
#include <QHostAddress>
#include <QTcpSocket>

// 批 161:协议对象构造窄面(00875ffe/0x38B 最小窗);批 165:connectImpl×4
// 升真(0027.c:18673 asm/体双源;槽体 008698c0/00875eb0/00875f1f +
// SerialBridge_h7c83c6 007c83c6 全读,语义见 TcpBridge.h 头注)。
// 语料 TcpBridge ctor FUN_00875ffe(642B):SuperBridge 基(007c8290)→
// +0x30 = operator_new(0x40) → FUN_0065f0a0(ProxyCommandSocket,QTcpSocket
// 子类)→ 4×connectImpl。socket 深依赖(真拨号腿 = 0065f572 分流,代理
// spawn = 0065d482 已真身于 ProxyCommandSocket)—— 本类 socket 槽以
// ProxyCommandSocket 装配(0065f0a0 ctor 以桥为 parent,同 TelnetBridge
// 判例),connectImpl 接线照语料信号/连接型/状态面。
TcpBridge::TcpBridge(QObject *parent)
	: SuperBridge(parent)
{
	// FUN_00875ffe @007c6028:param_1[6] = new ProxyCommandSocket(this)
	ProxyCommandSocket *sock = new ProxyCommandSocket(this);
	// connectImpl#1 @007c603f-60d5:QIODevice::readyRead → lambda 008698c0
	// {00911e60},型 2(Direct);invoke = emit readyRead()(idx5)
	connect(sock, &QTcpSocket::readyRead, this, &TcpBridge::onReadyRead,
	        Qt::DirectConnection);
	// connectImpl#2 @007c60da-614f:errorOccurred → 00875f1f(型 0 Auto):
	// socket 非 0 门 → 0065d202 态 ==0(Unconnected 直连臂)→ setState(0)
	// → errorOccurred(code, socket->errorString())(00911eb6 idx4)
	connect(sock, &QTcpSocket::errorOccurred, this, [this, sock](QAbstractSocket::SocketError code) {
		if (sock == nullptr)            // @00875f2e +0x30 非 0 门
			return;
		if (sock->state() == QAbstractSocket::UnconnectedState)   // 0065d202==0
			setState(King::SessionState::Unconnected, QVariant()); // @007c85dc(0,∅)
		emit errorOccurred(static_cast<int>(code), sock->errorString());
	});
	// connectImpl#3 @007c6154-61ba:connected → 00875eb0(型 0 Auto):
	// setState(3,∅) → attached()(00911e28 idx0);+0x28 bit5 = 关闭腿卫
	// (SerialBridge_h7c83c6 读面 —— 语料 007c82e6 拨号成置 1 同槽)
	connect(sock, &QTcpSocket::connected, this, [this]() {
		m_connectedBit = true;         // @007c82e6 +0x28=1(关闭腿卫置位)
		setState(King::SessionState::Connected, QVariant());   // @00875ee1
		emit attached();               // @00875ef2 00911e28(SMO idx0)
	});
	// connectImpl#4 @007c61c6-626b:disconnected → lambda 008698c0
	// {SerialBridge_h7c83c6},型 2(Direct):关闭腿(007c83c6):
	// +0x28 置位时虚+0xc0(0087687c)→ errorOccurred(0,∅)→ +0x28 清 0
	connect(sock, &QTcpSocket::disconnected, this, [this]() {
		closeLeg();                    // 007c83c6 +0x28 腿(vt+0xc0 同相)
	}, Qt::DirectConnection);
}

// TcpBridge_vt13(008762f4,55B,decomp-part-0027.c:18791)转写:
// QAbstractSocket::peerAddress() → QHostAddress::toString()。
// 语料 +0x30 socket 槽恒一(ctor 建);本树多子近面(测试 LblSock 注入
// 判例):首个 peerAddress 非空的 QAbstractSocket 承接 —— 全空 → 空
// label(未连态,Qt 语义同语料)。
QString TcpBridge::label() const
{
	const auto socks = findChildren<const QAbstractSocket *>();
	for (const QAbstractSocket *sock : socks) {
		if (!sock->peerAddress().isNull())
			return sock->peerAddress().toString();   // @00876314 toString
	}
	return QString();              // 空臂(全 socket 空 = 语料未连)
}

// TcpBridge_vt14(00876334,18B,decomp-part-0027.c:18806)转写:
// QAbstractSocket::peerName()。
QString TcpBridge::peerNameLabel() const
{
	const auto socks = findChildren<const QAbstractSocket *>();
	for (const QAbstractSocket *sock : socks) {
		if (!sock->peerAddress().isNull())   // 同 non-empty 卫(vt13 对位)
			return sock->peerName();
	}
	return QString();
}

// lambda 008698c0(102B,decomp-part-0027.c:8680)invoke 腿 @0086990b
// `jmp *%rcx` = 闭包槽指针间接调用(readyRead 闭包 = {00911e60, this})→
// activate(SMO 0x11a8140, idx5)= emit readyRead() 纯信号转发。
void TcpBridge::onReadyRead()
{
	emit readyRead();   // 00911e60(0030.c:1402,activate idx5)
}

// FUN_007c85dc(87B,decomp-part-0024.c:34783)同构(TelnetBridge 判例):
// 同值去重门 `(s == m_state) && (1 < s-8U)`(无符号减 ⇒ 仅 s==8/9(Auth
// 区)同值不重发;其余同值也 emit —— 语料原样,QUIRKS 候选)→
// 写 +0x2c → 00911ef2 emit stateChanged(state, extra)。
bool TcpBridge::setState(King::SessionState state, const QVariant &extra)
{
	const int s = static_cast<int>(state);
	if (s == m_state2c && (1 < static_cast<unsigned>(s) - 8U))
		return false;              // @007c85dc 同值 Auth 区去重
	m_state2c = s;                 // +0x2c
	emit stateChanged(state, extra);   // 00911ef2(0030.c:1452,idx6)
	return true;
}

// 关闭腿 vt+0xc0 = FUN_0087687c(78B,0027.c:19061)+ SerialBridge_h7c83c6
// disconnected 腿(007c83c6,271B,0024.c:34624)转写:
//   h7c83c6:自旋门收口(+0x18)→ +0x28(bit5)置位? → vt+0xc0(this)
//   → errorOccurred(0,∅)(00911eb6 idx4)→ +0x28 清 0 → +0x18 清 0
//   0087687c:emit detaching(00911e4c idx3)→ socket→0065cf9c
//   (disconnectProxy:m_process deleteLater + 直发 disconnected)
//   → setState(0,∅) → emit detached(00911e38 idx2)
// +0x28 bit5 对位 = m_connectedBit(TcpBridge 实例槽,非 static —— static
// 曾致 disconnectProxy 直发 disconnected → closeLeg 重入 → 无界递归)。
void TcpBridge::closeLeg()
{
	if (!m_connectedBit)                       // @007c8455 bit==0 → 跳关闭腿
		return;
	m_connectedBit = false;                    // 先清,防 reentry(recursive)
	emit detaching();              // 00911e4c(@0087687c 首腿)
	if (QAbstractSocket *sock = findChild<QAbstractSocket *>()) {
		if (auto *pcs = dynamic_cast<ProxyCommandSocket *>(sock))
			pcs->disconnectProxy();   // 0065cf9c(实接 ProxyCommandSocket)
	}
	emit errorOccurred(0, QString());  // 00911eb6(idx4;007c8457 shared_null)
	setState(King::SessionState::Unconnected, QVariant());   // @008768ae
	emit detached();               // 00911e38(@008768b7 idx2)
}
