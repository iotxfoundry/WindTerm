#pragma once

#include <QObject>

// PeriodTimerFace — 周期计时器(QObject 派生,**零字段 / 零自有析构**)。
//
// 出处:RTTI "PeriodTimer";QMetaObject 0x0119f4c0
// (rev=8,class="PeriodTimer",methods=1,**signals=1**,props=0,superdata=0);
// dtor 0x008fd356(19B)/deleting 0x008fd36a(37B)
//   —— 只有 QObject::~QObject,deleting 尺寸未在语料出现(见注);
// metacast 0x008fd2bc / metacall 0x008fd2fe(87B)。
//
// 唯一条信号:`timeout(...)` —— 与 QTimer 同名,但这是复现"周期误差补偿"
//   的自研计时器(名字如此,行为以语料为准)。
class PeriodTimerFace : public QObject {
	Q_OBJECT

public:
	explicit PeriodTimerFace(QObject *parent = nullptr);
	~PeriodTimerFace() override; // 0x008fd356

signals:
	void timeout(); // #0
};
