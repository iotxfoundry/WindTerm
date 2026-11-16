#pragma once

#include <QObject>
#include <QString>

// SuperPtyFace — 伪终端抽象(QObject 派生,2 条信号)。
//
// 出处:RTTI "SuperPty";QMetaObject 0x011a9a20
// (rev=8,class="SuperPty",methods=2,**signals=2**,props=0,superdata=0);
// **语料无 dtor entry** —— 只有 metacast 0x00918b92(66B)、
// metacall 0x00918bd4(93B)、分发 0x00918b3c(86B)。
// 说明:dtor 全部内联在派生类(Pty 的具体实现)里 ⇒ 字段布局不可得,
// **按铁律 6 不落玄字段**。
//
// 两条信号(串表实读):
//   #0 errorOccurred(...)
//   #1 readyRead()
// ⇒ 与 QProcess / QTcpSocket 的接口同形,上层可把 pty 当流处理。
class SuperPtyFace : public QObject {
	Q_OBJECT

public:
	explicit SuperPtyFace(QObject *parent = nullptr);

signals:
	void errorOccurred(const QString &message); // #0
	void readyRead();                           // #1
};
