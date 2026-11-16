// JumpServerFace.cpp — 跳板机记录。

#include "Sessions/Core/JumpServerFace.h"

// 出处:QMetaObject 0x0119f8a0(methods=1 signals=1);ctor 内联在调用点。
JumpServerFace::JumpServerFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x008fda28(76B)真身:vptr 复位 → +0x20 QString 减引用 → QObject 析构。
// deleting 0x008fd9d6(82B)真身:+ operator_delete(_, 0x28)。
JumpServerFace::~JumpServerFace() = default;

// metasurface:metaObject 0x008fd8b0;qt_metacast 0x008fd938;
// qt_metacall 0x008fd97a(91B):1 条记录,超出 index - 1。
