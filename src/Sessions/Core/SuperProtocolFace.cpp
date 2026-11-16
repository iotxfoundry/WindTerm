// SuperProtocolFace.cpp — 协议抽象基座。

#include "Sessions/Core/SuperProtocolFace.h"

// 出处:RTTI "SuperProtocol";ctor 内联在调用点。
SuperProtocolFace::SuperProtocolFace(QObject *parent)
    : QObject(parent)
{
}

// 0x007a2732(156B)swapDelegate 真身:
//   old = +0x10;+0x10 = 新值;然后 0x00a81502(实参, +0x20, *(int*)(+0x1c))
//   —— 先换指针再按 +0x1c 的宽度做一次重注册。
void SuperProtocolFace::swapDelegate(void *)
{
	// cited:0x00a81502(重注册腿)
}

// metasurface:metaObject 0x007a27ce(88B,**带 dynamicMetaObject 分支**);
// qt_metacast 0x007a2826(23B)。
