#include "ProxyCommandSocket.h"

#include <QAbstractSocket>
#include <QNetworkProxy>
#include <QProcess>

// ctor = FUN_0065f0a0(1170B,decomp-part-0020.c:45351):
// 1) QTcpSocket 基 + 直置 ProxyCommandSocket_vtable(0020.c:45372)
// 2) 成员置 shared_null / 0(+0x10/+0x18/+0x20/+0x28/+0x30/+0x38,
//    0020.c:45373-45378)
// 3) 两段 once-guard QMetaType::registerNormalizedType(0065f33d-45531,
//    className()+… 拼接常量被 Ghidra 吞名;cited — wave-2,不发明注册)
// 4) QNetworkProxy(NoProxy,2 = ProxyType::NoProxy,0020.c:45537)→
//    QAbstractSocket::setProxy(0065f178)
// 5) setOptionMap1(0,QVariant(1))(0065f1e3 → FUN_0065efde)
// 6) connectImpl:connected → thunk_FUN_0065f58a(Qt::直连型 2,
//    0065f22c-45522)
ProxyCommandSocket::ProxyCommandSocket(QObject *parent)
	: QTcpSocket(parent)
{
	// 0065f169-0065f178:NoProxy 直连(代理进程分支不走 socket 层代理)
	setProxy(QNetworkProxy::NoProxy);
	// 0065f1e3:FUN_0065efde(this,0,QVariant(1)) → LowDelayOption=1 预置
	setSocketOptionImpl(QAbstractSocket::LowDelayOption, QVariant(1));
	// 0065f22c-0065f28b:connectImpl(connected → thunk_FUN_0065f58a,型 2)
	connect(this, &QTcpSocket::connected, this, &ProxyCommandSocket::flushSocketOptions);
}

// FUN_0065d228(33B,0020.c:43643):+0x30 m_process 非空 →
// QIODevice::write(m_process)(子进程 stdin);否则 QIODevice::write(this)。
void ProxyCommandSocket::write(const QByteArray &data)
{
	if (m_process != nullptr) {
		m_process->write(data);   // QIODevice::write(→ +0x30)直写分支
		return;
	}
	QTcpSocket::write(data);   // QIODevice::write(this)直写分支
}

// FUN_0065cfe4(22B,0020.c:43458):读腿分流(进程 stdout,否则自身)。
qint64 ProxyCommandSocket::read(char *data, qint64 maxlen)
{
	if (m_process != nullptr) {
		return m_process->read(data, maxlen);
	}
	return QTcpSocket::read(data, maxlen);
}

// FUN_0065cffa(36B,0020.c:43472):readAll 同构分流。(返回值语料显示
// 畸变,实际语义 = 返回读到的字节。)
QByteArray ProxyCommandSocket::readAll()
{
	if (m_process != nullptr) {
		return m_process->readAll();
	}
	return QTcpSocket::readAll();
}

// FUN_0065f572(24B,0020.c:45520):+0x10 m_command d->size≠0 →
// FUN_0065d482(6947B 代理进程分支,cited — wave-2);否则
// QAbstractSocket::connectToHost(this,host,port)直连。
void ProxyCommandSocket::connectToHost(const QString &hostName, quint16 port,
	OpenMode mode, NetworkLayerProtocol protocol)
{
	if (!m_command.isEmpty()) {   // *(int *)(*(long *)(this+0x10)+4) != 0
		// FUN_0065d482 — cited — wave-2(6947B:spawn 代理命令进程,
		// 经进程 stdin/stdout 中转;语料体量超单轮真身化)
		return;
	}
	QTcpSocket::connectToHost(hostName, port, mode, protocol);
}

// FUN_0065cf9c(35B,0020.c:43430):+0x30 在 → deleteLater + 清槽;
// 随后直发 disconnected()(原样:直连态无 close 调用,怪癖候选记录勿修)。
void ProxyCommandSocket::disconnectProxy()
{
	if (m_process != nullptr) {
		m_process->deleteLater();   // QObject::deleteLater(→ +0x30)
		m_process = nullptr;        // +0x30 = 0
	}
	emit disconnected();   // QAbstractSocket::disconnected() 直发
}

// FUN_0065efde(188B,0020.c:45306):options map(QMap<int,QVariant>)写;
// 上界查 ≤option 复写,否则 createNode(节点 0x30,键 int @+0x18,值
// QVariant @+0x20)—— Qt5 QMap 结构,直接用 QMap 容器承载。
void ProxyCommandSocket::setSocketOptionImpl(int option, const QVariant &value)
{
	m_socketOptions.insert(option, value);
}

// thunk_FUN_0065f58a(0065f7a2,体 0065f58a 520B,0020.c:45528):
// 逐项 setSocketOption;键 5/6(Send/ReceiveBufferSize,值≤1)时
// QAbstractSocket::socketOption 回读,于 0x2000..0x400000 夹取下限后
// 复写(options map 随后清空)。
void ProxyCommandSocket::flushSocketOptions()
{
	for (auto it = m_socketOptions.constBegin(); it != m_socketOptions.constEnd(); ++it) {
		const int option = it.key();
		QVariant value = it.value();
		if (option == QAbstractSocket::SendBufferSizeSocketOption
			|| option == QAbstractSocket::ReceiveBufferSizeSocketOption) {
			// 0065f647-0065f683:buffer 键先回读现值(vtable +0x120 =
			// socketOption),值 < 下限则复写下限。
			const uint requested = value.toUInt();
			const uint current = QAbstractSocket::socketOption(
				static_cast<QAbstractSocket::SocketOption>(option)).toUInt();
			uint minimum;
			if (requested == 0) {
				// 0065f66d:0 → 6(RCVBUF)=0x100000,否则(SNDBUF)=0x40000
				minimum = (option == QAbstractSocket::ReceiveBufferSizeSocketOption)
					? 0x100000u : 0x40000u;
			} else if (requested == 1) {
				minimum = 0x2000u;
			} else {
				// 0065f674-0065f681:round up 到 2 的幂(requested-1 最高位
				// 起算 2<<shift),夹至 0x2000..0x400000
				int shift = 31;
				while (((requested - 1) >> shift) == 0)
					--shift;
				minimum = 2u << shift;
				if (minimum < 0x2000u)
					minimum = 0x2000u;
				if (minimum > 0x400000u)
					minimum = 0x400000u;
			}
			if (current < minimum) {
				QAbstractSocket::setSocketOption(
					static_cast<QAbstractSocket::SocketOption>(option), QVariant(minimum));
			}
		} else {
			QAbstractSocket::setSocketOption(
				static_cast<QAbstractSocket::SocketOption>(option), value);
		}
	}
	m_socketOptions.clear();   // 0065f6f5:param_1[7] = shared_null
}
