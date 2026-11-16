// SuperPtyFace.cpp — 伪终端抽象。

#include "Sessions/Core/SuperPtyFace.h"

// 出处:QMetaObject 0x011a9a20(methods=2 signals=2);
// ctor 内联在调用点,仅转发 QObject 基构造。
SuperPtyFace::SuperPtyFace(QObject *parent)
    : QObject(parent)
{
}

// 无 dtor entry(内联在 Pty 实现里);metacast 0x00918b92 / metacall 0x00918bd4
// 均真身,分发 0x00918b3c(86B)。
