// CyclicMemoryPoolFace.cpp — 循环内存池。

#include "Utility/CyclicMemoryPoolFace.h"

// 出处:QMetaObject 0x011a0160(methods=1 signals=0);ctor 内联在调用点。
CyclicMemoryPoolFace::CyclicMemoryPoolFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x00902de8(67B)真身:
//   +0x20 的池体 `operator_delete(_, **0x20**)` → QObject 析构。
// deleting 0x00902e2c(80B)真身:+ operator_delete(this, 0x28)。
CyclicMemoryPoolFace::~CyclicMemoryPoolFace() = default;

// 槽体未开批(锚入口 0x00902d94 的分发):freeUnusedMemoryBlocks()
void CyclicMemoryPoolFace::freeUnusedMemoryBlocks() { }
