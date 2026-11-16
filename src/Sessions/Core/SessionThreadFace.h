#pragma once

#include <QObject>

// SessionThreadFace — 会话线程载体(QObject 派生,两个裸指针)。
//
// 出处:RTTI "SessionThread";QMetaObject 0x011a8020
// (rev=8,class="SessionThread",methods=1,**signals=1**,props=0,superdata=0);
// dtor 0x007c7ee2(79B)/deleting 0x007c7f32(23B);
// 小分发 0x00911d28(16B);metacast 0x00911d6c / metacall 0x00911dae(87B)。
//
// 唯一条信号:`started(...)`。
//
// 字段(dtor 实读):+0x10 / +0x18 两个裸指针 ——
//   dtor 里各自判非空后**只置 0**,没有释放(语料如此)⇒ 非拥有指针。
class SessionThreadFace : public QObject {
	Q_OBJECT

public:
	explicit SessionThreadFace(QObject *parent = nullptr);
	~SessionThreadFace() override; // 0x007c7ee2

signals:
	void started(); // #0

private:
	void *m_f10 = nullptr; // +0x10(非拥有)
	void *m_f18 = nullptr; // +0x18(非拥有)
};
