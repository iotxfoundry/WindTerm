#pragma once

#include <QObject>
#include <QString>

// JumpServerFace — 跳板机记录(QObject 派生)。
//
// 出处:RTTI "JumpServer";QMetaObject 0x0119f8a0
// (rev=8,class="JumpServer",methods=1,**signals=1**,props=0,superdata=0);
// sizeof = **0x28**(deleting 0x008fd9d6 的 operator_delete(_,0x28));
// dtor 0x008fda28(76B)/deleting 0x008fd9d6(82B);
// metacast 0x008fd938 / metacall 0x008fd97a(91B)。
//
// 唯一条信号:`serverPortReady(...)` —— 跳板机端口就绪。
// 字段(dtor 实读):+0x20 QString。
class JumpServerFace : public QObject {
	Q_OBJECT

public:
	explicit JumpServerFace(QObject *parent = nullptr);
	~JumpServerFace() override; // 0x008fda28

signals:
	void serverPortReady(quint16 port); // #0

private:
	QString m_f20; // +0x20
};
