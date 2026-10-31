#ifndef PROXYCOMMANDSOCKET_H
#define PROXYCOMMANDSOCKET_H

#pragma once

#include <QTcpSocket>
#include <QMap>
#include <QVariant>
#include <QStringList>

class QProcess;

// 语料 = FUN_0065f0a0(1170B,decomp-part-0020.c:45351)QTcpSocket 子类:
// ctor 直置 ProxyCommandSocket_vtable(0020.c:45372);metaObject 008fda76 /
// qt_metacast 008fda8e(strcmp "ProxyCommandSocket"→QTcpSocket)/
// qt_metacall 008fdad0(纯转发 QTcpSocket)→ 无自有槽/信号,Q_OBJECT
// 零 signals/slots。唯一 connect = connected → thunk_FUN_0065f58a。
//
// 成员布局(ctor 写点):
//   +0x10 QString            m_command(FUN_0065f572 判空分流代理/直连)
//   +0x18 QList<QString>     m_commandArgs(FUN_0065d24a 拆词 setter,
//                            551B 拆词+去尾语义缠绕 → cited 不建模,成员保留)
//   +0x20 QString            m_field20(仅 FUN_0065d482 深腿使用,语义未解)
//   +0x28 QString            m_field28(同上)
//   +0x30 QProcess*          m_process(ctor 置 0;分流键)
//   +0x38 QMap<int,QVariant> m_socketOptions(FUN_0065efde 写 /
//                            FUN_0065f58a connected 时 flush)
//
// ctor 两段 once-guard QMetaType::registerNormalizedType(className()+…,
// 0065f378/0065f461):拼接字符串常量被 Ghidra 寄存器复用吞名,枚举名
// 不可复原 → cited — wave-2,不发明注册。
//
// 深腿 cited:FUN_0065d482(6947B,spawn 代理进程)/FUN_0065d24a(551B,
// 命令拆词)/FUN_0065f7d0 槽闭包(jumptable 未复原)。
// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
class ProxyCommandSocket : public QTcpSocket
{
	Q_OBJECT

public:
	explicit ProxyCommandSocket(QObject *parent = nullptr);   // FUN_0065f0a0

	// FUN_0065d228(33B):m_process 在 → 进程 stdin 写,否则自身直写。
	// (遮蔽非虚 QIODevice::write(const QByteArray&);树面桥 0087685a
	// 恒持具体指针调用,无经基类指针路径)
	void write(const QByteArray &data);

	// FUN_0065cfe4(22B)/FUN_0065cffa(36B):读腿同构分流(进程 stdout,
	// 否则自身)。0065cffa 返回值系 Ghidra sret 显示畸变,实际返回
	// QByteArray。
	qint64 read(char *data, qint64 maxlen);
	QByteArray readAll();

	// FUN_0065f572(24B):m_command 非空(+0x10 d->size≠0)→ 代理分支
	// FUN_0065d482(cited — wave-2);否则 QAbstractSocket::connectToHost。
	// 桥侧 00876864 直调本方法(3,2 = ReadWrite/AnyIPProtocol = 默认参)。
	void connectToHost(const QString &hostName, quint16 port,
		OpenMode mode = ReadWrite,
		NetworkLayerProtocol protocol = AnyIPProtocol) override;

	// FUN_0065cf9c(35B):m_process 在 → deleteLater + 清槽;随后直发
	// disconnected()。直连态无 close() 调用,原样照写(怪癖候选,记录勿修)。
	// (避用基类虚名 disconnectFromHost 以免遮蔽;调用点 = 桥 0087687c)
	void disconnectProxy();

	// FUN_0065efde(188B):options map 写(键 = QAbstractSocket::SocketOption;
	// 延迟到 connected flush;桥侧配置入口 s_session_tcpReceiveBufferSize_
	// 8768d2:tcpLowDelay→0/tcpKeepAlive→1/tcpReceiveBufferSize→6/
	// tcpSendBufferSize→5)。
	void setSocketOptionImpl(int option, const QVariant &value);

private:
	// thunk_FUN_0065f58a(0065f7a2,520B 体):connected 时刷 options。
	void flushSocketOptions();

private:
	QString m_command;                   // +0x10
	QStringList m_commandArgs;           // +0x18
	QString m_field20;                   // +0x20(语义未解,深腿消费)
	QString m_field28;                   // +0x28(同上)
	QProcess *m_process = nullptr;       // +0x30
	QMap<int, QVariant> m_socketOptions; // +0x38

private:
	Q_DISABLE_COPY(ProxyCommandSocket)
};

#endif // PROXYCOMMANDSOCKET_H
