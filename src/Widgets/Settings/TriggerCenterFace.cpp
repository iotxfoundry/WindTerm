// TriggerCenterFace.cpp — 触发器中心。

#include "Widgets/Settings/TriggerCenterFace.h"

// 出处:QMetaObject 0x011a09a0(methods=1 signals=1);ctor 内联在调用点。
TriggerCenterFace::TriggerCenterFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x00699f90(163B)真身:
//   +0x20 容器逐元素 operator_delete(elem, **0x28**)(元素是 0x28 字节记录)
//   → QObject 析构;deleting 0x0069a034(23B)真身:+ operator_delete(_, 0x78)。
TriggerCenterFace::~TriggerCenterFace() = default;

// metasurface:metaObject 0x00903a00;qt_metacast 0x00903bc2;
// qt_metacall 0x00903c04(84B):1 条记录,超出 index - 1。
