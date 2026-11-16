#pragma once

#include <QObject>
#include <QString>

// CommanderRobotFace — 命令器自动化机器人(QObject 派生,零字段)。
//
// 出处:RTTI "CommanderRobot";QMetaObject 0x011a6da0
// (rev=8,class="CommanderRobot",methods=1,**signals=1**,props=0,superdata=0);
// dtor 0x0090e834(19B)/deleting 0x0090e848(37B)
//   —— 只有 QObject::~QObject ⇒ 零字段;
// metacast 0x0090e78c / metacall 0x0090e7ce(101B)。
//
// 唯一条信号:`asyncMessage(...)` —— 与 SuperCommander 的 #0 同名同义,
// 说明"机器人的异步消息"走的也是命令器那条通道。
class CommanderRobotFace : public QObject {
	Q_OBJECT

public:
	explicit CommanderRobotFace(QObject *parent = nullptr);
	~CommanderRobotFace() override; // 0x0090e834

signals:
	void asyncMessage(const QString &message); // #0
};
