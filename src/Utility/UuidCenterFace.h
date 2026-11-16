#pragma once

#include <QMap>
#include <QObject>
#include <QUuid>

// UuidCenterFace — UUID 注册表(QObject 派生)。
//
// 出处:RTTI "UuidCenter";QMetaObject 0x011a0b20
// (**methods=0 / signals=0 / props=0** —— 零元接口);
// sizeof = **0x20**(deleting 0x00903fd0 的 operator_delete(_,0x20));
// dtor 0x00904046(115B)/deleting 0x00903fd0(118B);
// metacast 0x00903f88 / metacall 0x00903fca(5B,纯转发)。
//
// 字段(dtor 实读):**+0x18 QMap<?>** —— 唯一字段,
//   引用计数归零后 QMapDataBase::freeTree + freeData。
//   0x18 + 8 = 0x20 与 sizeof 自洽。
class UuidCenterFace : public QObject {
	Q_OBJECT

public:
	explicit UuidCenterFace(QObject *parent = nullptr);
	~UuidCenterFace() override; // 0x00904046

private:
	QMap<QUuid, void *> m_map18; // +0x18
};
