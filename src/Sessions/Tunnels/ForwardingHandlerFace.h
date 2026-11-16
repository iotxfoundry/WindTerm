#pragma once

#include <QList>
#include <QObject>
#include <QString>
#include <QUuid>

// ForwardingHandlerFace — 端口转发 / X11 转发的处理器。
//
// 出处:RTTI "ForwardingHandler";QMetaObject 0x0119f400
// (rev=8,class="ForwardingHandler",methods=2,**signals=2**,props=0,superdata=0);
// 析构 0x005f1838(367B)/deleting 0x005f19a8(23B);
// 信号桥 0x008fceb0(740B);注销腿 0x005eda26(695B);
// metacast 0x008fd1a4 / metacall 0x008fd1e6(109B)。
//
// 两条信号(串表实读;形参名与类型名都在串表里):
//   #0 startX11Server(ForwardingHandler *forwardingHandler)
//      串表:"ForwardingHandler*" / "forwardingHandler";emit 腿 0x008fcdf8(1 参)
//   #1 startForwardingServer(...)  **argc = 7**,emit 腿 0x008fce2c 传 7 个槽:
//      args[1] 宽值、args[2] 宽值、*(int*)args[3]、*(quint16*)args[4]、
//      args[5] 宽值、*(quint16*)args[6]、*(uchar*)args[7]
//      串表里给出的形参名只有 6 个:serverUuid / proxyType / listenPort /
//      remoteHost / remotePort / localHostOnly。**argc=7 与 6 个名字对不上**
//      —— 有一个形参在串表里没有名字。此处按下发实参序声明 7 个形参,
//      已知的 6 个用真名,多出来的那一个留 arg7 并注明"待开批对号"。
//
// 字段(析构实读):+0x18 QList<?>(析构里 detach + 逐元素释放)
class ForwardingHandlerFace : public QObject {
	Q_OBJECT

public:
	explicit ForwardingHandlerFace(QObject *parent = nullptr);
	~ForwardingHandlerFace() override; // 0x005f1838

signals:
	void startX11Server(ForwardingHandlerFace *forwardingHandler); // #0
	// #1 — 6 个真名按串表序;arg7 无名字(见头注)
	void startForwardingServer(const QUuid &serverUuid,
	                           int proxyType,
	                           quint16 listenPort,
	                           const QString &remoteHost,
	                           quint16 remotePort,
	                           bool localHostOnly,
	                           int arg7);

private:
	QList<void *> m_f18; // +0x18
};
