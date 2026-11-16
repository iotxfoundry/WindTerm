#pragma once

#include <QObject>

// SyncInputCenterFace — 多视图同步输入中心(QObject 派生)。
//
// 出处:RTTI "SyncInputCenter";QMetaObject 0x011a08e0
// (rev=8,class="SyncInputCenter",methods=3,**signals=3**,props=0,superdata=0);
// sizeof = **0x30**(deleting 0x009038e6 的 operator_delete(_,0x30));
// dtor 0x00903972(127B)/deleting 0x009038e6(140B);
// 信号桥 0x009037a8(158B);metacast 0x00903846 / metacall 0x00903888(93B)。
//
// 三条信号(串表实读;形参个数按桥逐个实读):
//   #0 viewJoined(?)           → 0x00903720(this, 宽, int)      2 参
//   #1 viewLeaved(?)           → 0x009036e8(this, 宽)           1 参
//   #2 viewPaused(?, bool)     → 0x00903762(this, 宽, bool)     2 参
//
// 字段(dtor 实读):+0x18 **一段连续数组**,元素**步长 0x20**,
//   每元素 +0x8 处一个引用计数件(减一归零即 operator_delete);
//   +0x20 是数组尾指针。整段最后 operator_delete(数组起始)。
//   ⇒ 这不是 QList,是手写的定长/变长数组,+0x18/+0x20 是 begin/end。
class SyncInputCenterFace : public QObject {
	Q_OBJECT

public:
	explicit SyncInputCenterFace(QObject *parent = nullptr);
	~SyncInputCenterFace() override; // 0x00903972

signals:
	void viewJoined(const QString &view, int mode);      // #0
	void viewLeaved(const QString &view);                 // #1
	void viewPaused(const QString &view, bool paused);    // #2

private:
	char *m_begin18 = nullptr; // +0x18(元素步长 0x20)
	char *m_end20 = nullptr;   // +0x20
};
