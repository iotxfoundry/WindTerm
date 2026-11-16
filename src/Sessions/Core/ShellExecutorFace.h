#pragma once

#include <QObject>
#include <QString>

// ShellExecutorFace — 本地 shell 命令执行器(QObject 派生)。
//
// 出处:RTTI "ShellExecutor";QMetaObject 0x011a9d40
// (rev=8,class="ShellExecutor",methods=1,**signals=1**,props=0,superdata=0);
// sizeof = **0x28**(deleting 0x00875478 的 operator_delete(_,0x28));
// dtor 0x00875400(120B)/deleting 0x00875478(23B);
// 分发 0x008751dc(141B);计时器腿 0x00875c00(29B);
// metacast 0x00918e3a / metacall 0x00918e7c(104B)。
//
// 唯一条信号:`commandOutput(...)` —— 与 SshExecutor 的 #0 同名,
// 两者是"本地 shell / SSH"两个实现共用同一信号契约。
// 字段(dtor 实读):+0x18 一个子对象(走 0x00875c00 释放)。
class ShellExecutorFace : public QObject {
	Q_OBJECT

public:
	explicit ShellExecutorFace(QObject *parent = nullptr);
	~ShellExecutorFace() override; // 0x00875400

signals:
	void commandOutput(const QString &output); // #0

private:
	char m_f18[0x10] = {}; // +0x18 子对象(类型未复原)
};
