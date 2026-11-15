#include "TcpBridge.h"

#include <QAbstractSocket>
#include <QHostAddress>

// 批 161:协议对象构造窄面(00875ffe/0x38B 最小窗)。
// 语料 TcpBridge ctor FUN_00875ffe(642B,0027.c:18673):SuperBridge 基
// (007c8290)→ +0x30 = operator_new(0x40) → FUN_0065f0a0
// (ProxyCommandSocket,QTcpSocket 子类)→ 4×connectImpl
// (readyRead→008698c0 型2/errorOccurred→00875f1f/connected→00875eb0/
// disconnected→008698c0 型2)。TelnetBridge 为同构真身(同一 ctor
// 复刻,0087685a/64 写面/007c82e6 拨号门落地)——本类 = Tcp 协议对象
// face 生产壳(007d846e 工厂 qstricmp "Tcp" 腿同窗),socket 深依赖
// (连接腿)cited,字段面照 +0x30 布局以桥子对象 socket 槽承接
// (0065f0a0 以桥为 parent,findChild 承接对位)。
TcpBridge::TcpBridge(QObject *parent)
	: SuperBridge(parent)
{
}

// TcpBridge_vt13(008762f4,55B,decomp-part-0027.c:18791)转写:
// QAbstractSocket::peerAddress() → QHostAddress::toString()。
// socket 槽空(未装配)→ 空 label(语料 socket 恒在,本 face 壳卫)。
QString TcpBridge::label() const
{
	// +0x30 socket 槽对位:语料 socket = 桥子对象(0065f0a0 ctor 以
	// param_2=桥为 parent)。子对象族首 QAbstractSocket 承接。
	const QAbstractSocket *sock = findChild<const QAbstractSocket *>();
	return sock ? sock->peerAddress().toString() : QString();
}

// TcpBridge_vt14(00876334,18B,decomp-part-0027.c:18806)转写:
// QAbstractSocket::peerName()。
QString TcpBridge::peerNameLabel() const
{
	const QAbstractSocket *sock = findChild<const QAbstractSocket *>();
	return sock ? sock->peerName() : QString();
}
