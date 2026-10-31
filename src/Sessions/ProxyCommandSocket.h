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
//   +0x18 QList<QString>     m_commandArgs(FUN_0065d24a 拆词 setter
//                            = setProxyCommand 已真身,0020.c:43660)
//   +0x20 QString            m_field20(环境变量定义文本,"\r" 分行 "="
//                            恰 2 段入 env;0065ca80/spawnProxyProcess)
//   +0x28 QString            m_field28(workingDir,FUN_0065d01e setter)
//   +0x30 QProcess*          m_process(ctor 置 0;分流键)
//   +0x38 QMap<int,QVariant> m_socketOptions(FUN_0065efde 写 /
//                            FUN_0065f58a connected 时 flush)
//
// ctor/C3 的 once-guard QMetaType::registerNormalizedType(className()+…,
// 0065f33d/0065f461/0065e8c1):拼接字符串常量被 Ghidra 寄存器复用吞名,
// 枚举名不可复原 → cited — wave-2,不发明注册(模板 connect 的型参由
// Qt 自理,注册段维持 cited)。
//
// 深腿已真身化(P3 破案 2026-10-31,p3_notes_px.md):FUN_0065d482(6947B,
// spawn 代理进程)= spawnProxyProcess(S1 env 装载/S2 进程重建/S3 配置/S4
// 4×DirectConnection/S5 start;S6 0065e86f-45320 = QMap RAII 清算展开,
// 零行为不转写);FUN_0065d24a(551B,命令拆词 setter)= setProxyCommand
// (+ FUN_0065c11e 1091B 拆词器;尾 token = program,0020.c:43766-4376d)。
// cited 维持:FUN_0065f7d0 桥侧槽闭包(jumptable 未复原,不在本类)/
// FUN_0065d01e workingDir setter(c56a/a8b2e6 宏展开,待装配批)。
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
	// FUN_0065d482(spawnProxyProcess);否则 QAbstractSocket::connectToHost。
	// 桥侧 00876864 直调本方法(3,2 = ReadWrite/AnyIPProtocol = 默认参)。
	void connectToHost(const QString &hostName, quint16 port,
		OpenMode mode = ReadWrite,
		NetworkLayerProtocol protocol = AnyIPProtocol) override;

	// FUN_0065d24a(551B,0020.c:43660;applySetting 键 "ProxyCommand" 三参
	// setter 链首,s_ProxyCommand_876780 @0027.c:19006):清 +0x10 →
	// FUN_0065c11e(1091B,0020.c:42741)拆词整串 → 存 +0x18 → 弹出列表尾
	// token 回填 +0x10(QListData::remove 尾下标,0065d3a7/0065d374)。
	// 约定 = 命令串末 token 为程序名,其余为参数(d482 侧 setProgram/
	// setArguments 严格对称)。空表 → 提前 return(0065d2f0),+0x10 保持空。
	void setProxyCommand(const QString &commandLine);

	// FUN_0065d01e(298B,0020.c:43486;setter 链第二参):workingDir 落
	// +0x28(宏展开 cited — wave-2:FUN_0065c56a 583B 懒建 $(AppDir)/
	// $(HomeDir) 表 + FUN_00a8b2e6 520B ${k} 模板展开);QDir::exists()
	// 失败则清 +0x28(0065d0a8-0065d12a)。
	void setProxyWorkingDirectory(const QString &dir);

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

	// FUN_0065d482(6947B,0020.c:43784)spawn 代理命令进程:唯一参数 =
	// socket 自身(hostName/port 在 65f572 分流时被丢弃,0020.c:45525)。
	// S1 env(0065d4b2 ca80+b9da)/S2 重建(0065d4c0-d4fb)/S3 配置
	// (0065d529-d55f)/S4 connect×4(0065d5c5-e8b0,全 Direct 型 2)/
	// S5 start(0065d58b,ReadWrite=3)。S6 QMap 清算(0065e86f-45320,
	// qmap_freetree_free_variants 家族)= RAII 展开,零行为不转写。
	void spawnProxyProcess();

	void flushSocketOptions();

private:
	QString m_command;                   // +0x10 program(d24a 拆词尾 token 回填)
	QStringList m_commandArgs;           // +0x18(0065c11e 拆词整串)
	QString m_field20;                   // +0x20 环境变量定义文本("\r" 分行,
	                                     //   "k=v" 恰 2 段入 env;0065ca80)
	QString m_field28;                   // +0x28 workingDir(d01e setter)
	QProcess *m_process = nullptr;       // +0x30
	QMap<int, QVariant> m_socketOptions; // +0x38

private:
	Q_DISABLE_COPY(ProxyCommandSocket)
};

#endif // PROXYCOMMANDSOCKET_H
