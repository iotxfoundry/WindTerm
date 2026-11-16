// PeriodTimerFace.cpp — 周期计时器。

#include "Utility/PeriodTimerFace.h"

// 出处:QMetaObject 0x0119f4c0(methods=1 signals=1);ctor 内联在调用点。
PeriodTimerFace::PeriodTimerFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x008fd356(19B)真身:只有 QObject::~QObject —— 零字段。
// deleting 0x008fd36a(37B)真身:+ operator_delete(_, size)。
PeriodTimerFace::~PeriodTimerFace() = default;

// metasurface:metaObject 0x008fd260 → &PTR_staticMetaObject_0119f4c0;
// qt_metacast 0x008fd2bc;qt_metacall 0x008fd2fe(87B):1 条记录,超出 index - 1。
