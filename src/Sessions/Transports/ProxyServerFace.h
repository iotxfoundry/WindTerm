#pragma once

#include <QMap>
#include <QString>
#include <QTcpServer>

// ProxyServerFace — 代理监听器(QTcpServer 派生)。
//
// 出处:RTTI "ProxyServer";QMetaObject 0x0119f340
// (rev=8,class="ProxyServer",methods=2,**signals=2**,props=0,superdata=0);
// sizeof = **0x30**(deleting 0x008fcd38 的 operator_delete(_,0x30));
// dtor 0x008fcc98(160B)/deleting 0x008fcd38(161B);
// 信号桥 0x008fcb80(120B);metacast 0x008fcbf8 / metacall 0x008fcc3a(93B)。
//
// 两条信号(串表实读;形参个数按桥逐个实读):
//   #0 newTcpSocket(?, ?, ?, quint16)
//      4 个实参:args[1](宽)、args[2] 整槽、args[3] 宽、*(u16*)args[4]
//      → 发射器 0x008fcb32
//   #1 proxyError(?)  1 参 → 发射器 0x008fcb08
//
// 字段(dtor 实读):
//   +0x18 QString
//   +0x28 QMap<?>(引用计数归零后 freeTree + freeData)
class ProxyServerFace : public QTcpServer {
	Q_OBJECT

public:
	explicit ProxyServerFace(QObject *parent = nullptr);
	~ProxyServerFace() override; // 0x008fcc98

signals:
	void newTcpSocket(const QString &host, int port, const QString &peer, quint16 localPort); // #0
	void proxyError(const QString &message);                                                  // #1

private:
	QString m_f18;               // +0x18
	QMap<QString, void *> m_f28; // +0x28
};
