#include "ProxyCommandSocket.h"

#include <QAbstractSocket>
#include <QCoreApplication>
#include <QDir>
#include <QNetworkProxy>
#include <QChar>
#include <QProcess>
#include <QProcessEnvironment>

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
	// 0065f22c-0065f28b:connectImpl(connected → thunk_FUN_0065f58a,
	// 直连型 2;px §7.3 复核项:型 2 = Qt::DirectConnection)
	connect(this, &QTcpSocket::connected, this, &ProxyCommandSocket::flushSocketOptions,
		Qt::DirectConnection);
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
// FUN_0065d482(6947B 代理进程分支,spawnProxyProcess);否则
// QAbstractSocket::connectToHost(this,host,port)直连。
void ProxyCommandSocket::connectToHost(const QString &hostName, quint16 port,
	OpenMode mode, NetworkLayerProtocol protocol)
{
	if (!m_command.isEmpty()) {   // *(int *)(*(long *)(this+0x10)+4) != 0
		spawnProxyProcess();   // FUN_0065d482(6947B):host/port 被 65f572 丢弃
		return;
	}
	QTcpSocket::connectToHost(hostName, port, mode, protocol);
}

// FUN_0065d24a(551B,0020.c:43660)拆词 setter:
// 0065d281:旧 +0x10 释放(shared_null 置换);0065d2ad:FUN_0065c11e 拆词
// → +0x18;0065d2f0:空表提前 return;0065d301-0065d374:detach 深拷贝
// (QList 隐共享展开);0065d381:取尾下标元素置 shared_null + 0065d3a7
// QListData::remove(弹出尾);0065d37d:弹出的尾 token 赋 +0x10 = program。
void ProxyCommandSocket::setProxyCommand(const QString &commandLine)
{
	m_command.clear();   // 0065d281:+0x10 → shared_null
	// 0065d2ad:FUN_0065c11e(1091B):trimmed;空白集 {0x20,9–13,0x85,0xa0,
	// isSpace} 分词;`"`/`'` 引号开关(前一字符非空白才视为开引号;引号是
	// 末字符 → 字面 append);引号态 `\` 转义 `\`/`"`/`'`(成对消解,
	// 单独 `\` 字面);引号态遇同引号闭合。
	QString cur;   // 语料 local_48 = 累积词
	m_commandArgs.clear();
	const QString s = commandLine.trimmed();   // 0065c154 trimmed_helper
	const int n = s.size();
	int i = 0;
	ushort inQuote = 0;   // uVar12:0 = 非引号态,否则 = 开引号字符
	while (i < n) {
		const ushort c = s.at(i).unicode();
		if (inQuote == 0) {
			// 0065c28c-0065c2b1:空白(0x20/9-13/0x85/0xa0/isSpace)断词
			if (c == 0x20 || (c >= 9 && c <= 13) || c == 0x85 || c == 0xa0
				|| QChar::isSpace(c)) {
				if (!cur.isEmpty()) {   // 空词不入表(0065c240 跳过)
					m_commandArgs.append(cur);
					cur.clear();
				}
				++i;
				continue;
			}
			// 0065c2b9-0065c301:引号字符且非末字符;开引号须前一字符
			// 非空白(含首字符,i==0 0065c2e0 跳过前查)
			if ((c == 0x22 || c == 0x27) && i != n - 1) {
				if (i != 0) {
					const ushort prev = s.at(i - 1).unicode();
					const bool prevSpace = prev == 0x20 || (prev >= 9 && prev <= 13)
						|| prev == 0x85 || prev == 0xa0 || QChar::isSpace(prev);
					if (!prevSpace) {   // 0065c319-0065c35b:非空白 → 字面
						cur.append(QChar(c));
						++i;
						continue;
					}
				}
				++i;
				inQuote = c;   // 0065c36a:uVar12 = 该引号字符
				continue;
			}
			cur.append(QChar(c));   // 0065c43f
			++i;
			continue;
		}
		// 引号态(0065c3f0 起):
		if (c == inQuote) {   // 0065c3f9:同引号闭合 → 出词
			m_commandArgs.append(cur);
			cur.clear();
			++i;
			inQuote = 0;   // 0065c529:uVar12 = 0
			continue;
		}
		if (c == 0x5c) {   // 0065c40d:`\`:下一字符为 `\`/`"`/`'` → 转义取字面
			if (i + 1 < n) {
				const ushort nx = s.at(i + 1).unicode();
				if (nx == 0x5c || nx == 0x22 || nx == 0x27) {
					cur.append(QChar(nx));
					i += 2;
					continue;
				}
			}
			cur.append(QLatin1Char('\\'));   // 0065c42c:单独 `\` 字面
			++i;
			continue;
		}
		cur.append(QChar(c));   // 0065c2d8(引号态含空白)
		++i;
	}
	// 0065c44b-0065c45a:收尾残词(引号态尾字符也字面 append 后入表)
	if (!cur.isEmpty())
		m_commandArgs.append(cur);
	if (m_commandArgs.isEmpty())   // 0065d2f0:空表 → return,+0x10 保持空
		return;
	// 0065d381-0065d37d:弹出尾 token 回填 +0x10(列表 detach 展开略)
	m_command = m_commandArgs.last();
	m_commandArgs.removeLast();   // 0065d3a7 QListData::remove(尾下标)
}

// FUN_0065d01e(298B,0020.c:43486)workingDir setter:0065d04d FUN_0065c56a
// 宏展开(cited — wave-2:懒建 DAT_011c18a0 {AppDir→applicationDirPath,
// HomeDir→homePath};$(AppDir)/$(HomeDir) → ${k} 由 FUN_00a8b2e6 展开,
// 0035.c:6132)→ 存 +0x28;0065d0a8 QDir::exists() 失败 → 清 +0x28。
void ProxyCommandSocket::setProxyWorkingDirectory(const QString &dir)
{
	// FUN_0065c56a — cited — wave-2(583B;展开算式已测绘 px §4,
	// 真身化随装配批落地)
	m_field28 = dir;   // 0065d066:+0x28 = 展开结果
	if (!QDir(m_field28).exists())   // 0065d0a8-0065d0b2
		m_field28.clear();   // 0065d12a:+0x28 → shared_null
}

// FUN_0065d482(6947B,0020.c:43784)spawn 代理命令进程:
// S1 env 装载 → S2 进程重建 → S3 配置 → S4 4×connect(Direct)→
// S5 start(ReadWrite)。S6 = QMap<QString,QVariant> RAII 清算展开
// (0065e86f-45320,qmap_freetree_free_variants 0065f8cc 家族),零行为
// 不转写。hostName/port 参数被 65f572 分流丢弃(0020.c:45525),目标主机
// 内嵌于命令串(占位展开点疑在 0086c7b2 调用侧,px §7 未解)。
void ProxyCommandSocket::spawnProxyProcess()
{
	// 0065d4b2 FUN_0065ca80(587B,0020.c:43173):+0x20 按 "\r" 拆行
	// (SkipEmptyParts 型 1)→ 每行 split('=',KeepEmptyParts 型 0,
	// 0065cbb2)→ 恰 2 段才入表(0065cbde size==2;多 '=' 值行丢弃 =
	// 原版如此勿修)→ QMap<QString,QVariant>。
	// 0065d4c6 FUN_0065b9da(169B,0020.c:42395):systemEnvironment 起底
	// + 遍历 map QVariant::toString → env.insert(0065ba3e)。
	QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
	const QStringList lines = m_field20.split(QLatin1Char('\r'),
		Qt::SkipEmptyParts);
	for (const QString &line : lines) {
		const QStringList kv = line.split(QLatin1Char('='));   // KeepEmptyParts
		if (kv.size() == 2)
			env.insert(kv[0], kv[1]);   // 0065cb52-0065cc03 qmap_insert
	}
	if (m_process != nullptr)   // 0065d4c0
		m_process->deleteLater();
	m_process = new QProcess(this);   // 0065d4d8-0065d4e4:new + QProcess(this)
	m_process->setProgram(QDir::toNativeSeparators(m_command));   // 0065d4fb
	m_process->setArguments(m_commandArgs);   // 0065d529
	m_process->setProcessEnvironment(env);   // 0065d52e
	// 0065d533-0065d539:+0x28 空 → applicationDirPath 回退
	m_process->setWorkingDirectory(m_field28.isEmpty()
		? QCoreApplication::applicationDirPath() : m_field28);
	// 0065d5c5-0065d7e6 C1:stdout readyReadStandardOutput →
	// QIODevice::readyRead(socket 自身信号,signal-to-signal 转发;经
	// 桥 lambda 008698c0 readAll 分流)→ 本类 read() 分流进程 stdout。
	// 槽胶水 FUN_0065f840(102B)= Qt connectImpl 比较器,非业务码。
	connect(m_process, &QProcess::readyReadStandardOutput,
		this, &QIODevice::readyRead, Qt::DirectConnection);
	// C2(0065d5a5 → FUN_0065ce02 393B,0020.c:43353):readAllStandardError;
	// 非 null 扫至首 '\0'(0065ce3c 循环)→ fromUtf8 → setErrorString;
	// 随后恒 errorOccurred(-1)(0065ce8c,有无文本都发,怪癖原样)。
	connect(m_process, &QProcess::readyReadStandardError, this, [this] {
		const QByteArray err = m_process->readAllStandardError();
		if (!err.isNull())   // 0065ce30 QByteArray::isNull
			setErrorString(QString::fromUtf8(err.constData()));   // 0065ce60
		emit errorOccurred(UnknownSocketError);   // 0065ce8c:-1
	}, Qt::DirectConnection);
	// C3(0065d5b2 → FUN_0065d1ad 61B,0020.c:43592):前置 once-guard
	// registerNormalizedType(DAT_011c18c0/011c18d4,0065e8c1-0065ec6c,
	// 名拼接被 Ghidra 吞)→ cited — wave-2,模板 connect 由 Qt 自理;
	// 槽体 FUN_0065d158(47B,0020.c:43557)映射 QProcessError→SocketError:
	// {0→2,1→1,2→5,3/4→-1}(0x65d17c:-(uint)(e-3<2)&2-1)→ errorOccurred。
	connect(m_process, &QProcess::errorOccurred, this, [this](QProcess::ProcessError e) {
		int mapped;   // 0065d158 分支直写,不设表
		if (e == QProcess::FailedToStart)      // 0 → 2
			mapped = 2;
		else if (e == QProcess::Crashed)       // 1 → 1
			mapped = 1;
		else if (e == QProcess::Timedout)      // 2 → 5
			mapped = 5;
		else                                   // 3/4(FailedToWrite/ReadError)→ -1
			mapped = -1;
		emit errorOccurred(static_cast<SocketError>(mapped));
	}, Qt::DirectConnection);
	// C4(0065d5bd → FUN_0065cd40 69B,0020.c:43289):state==0(NotRunning)
	// → disconnected();state==2(Running)→ connected();Starting(1)→ 忽略。
	connect(m_process, &QProcess::stateChanged, this, [this](QProcess::ProcessState st) {
		if (st == QProcess::NotRunning)
			emit disconnected();
		else if (st == QProcess::Running)
			emit connected();
	}, Qt::DirectConnection);
	m_process->start(QIODevice::ReadWrite);   // 0065d58b:型 3 = ReadWrite
	// S6(0065e86f-45320):env map QMap RAII 清算展开,零行为;env/lines
	// 析构天然承载(qmap_freetree_free_variants 0065f8cc 家族)。
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
