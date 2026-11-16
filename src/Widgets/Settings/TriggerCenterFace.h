#pragma once

#include <QObject>

// TriggerCenterFace — 触发器中心(QObject 派生,1 条信号)。
//
// 出处:RTTI "TriggerCenter";QMetaObject 0x011a09a0
// (rev=8,class="TriggerCenter",methods=1,**signals=1**,props=0,superdata=0);
// sizeof = **0x78**(deleting 0x0069a034 的 operator_delete(_,0x78));
// dtor 0x00699f90(163B)/deleting 0x0069a034(23B);
// metacast 0x00903bc2 / metacall 0x00903c04(84B)。
//
// 唯一信号:`triggersUpdated()`。
//
// 字段(dtor 实读):+0x20 一个节点容器 —— dtor 里逐元素
//   `operator_delete(elem, **0x28**)`,即元素是 0x28 字节的记录。
//   (TriggerData 的析构也是 0x18 —— 两者是不同粒度的对象,别混。)
class TriggerCenterFace : public QObject {
	Q_OBJECT

public:
	explicit TriggerCenterFace(QObject *parent = nullptr);
	~TriggerCenterFace() override; // 0x00699f90

signals:
	void triggersUpdated(); // 唯一信号

private:
	void *m_f20 = nullptr; // +0x20(元素 0x28 字节的容器)
};
