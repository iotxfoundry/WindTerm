// SessionThreadFace.cpp — 会话线程载体。

#include "Sessions/Core/SessionThreadFace.h"

// 出处:QMetaObject 0x011a8020(methods=1 signals=1);ctor 内联在调用点。
SessionThreadFace::SessionThreadFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x007c7ee2(79B)真身:
//   +0x10 非空 → 置 0;+0x18 非空 → 置 0;**两者都不释放**
//   ⇒ 非拥有指针(所有权在别处)。这条很关键:照习惯去 delete 就会双重释放。
// deleting 0x007c7f32(23B)真身:+ operator_delete(_, size)。
SessionThreadFace::~SessionThreadFace() = default;

// metasurface:metaObject 0x00911d10;qt_metacast 0x00911d6c;
// qt_metacall 0x00911dae(87B):1 条记录;小分发 0x00911d28(16B)。
