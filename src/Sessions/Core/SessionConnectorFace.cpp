// SessionConnectorFace.cpp — 会话连接器。

#include "Sessions/Core/SessionConnectorFace.h"

// 出处:QMetaObject 0x011a7220(methods=0 signals=0 props=0);ctor 内联在调用点。
SessionConnectorFace::SessionConnectorFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x007be004(138B)真身 —— **两段式顺序,不是按偏移单调**:
//   ① +0x58 子对象(0x007c0730)
//   ② +0x48 QList 清空(0x007c0710)
//   ③ +0x30 QString 减引用
//   ④ +0x18 引用计件归零 → operator_delete
//   ⑤ +0x10 子对象(0x007c06f0)
//   → QObject::~QObject
// deleting 0x007be08e(23B)真身:+ operator_delete(_, 0x60)。
SessionConnectorFace::~SessionConnectorFace() = default;

// metasurface:metaObject 0x0090ed20;qt_metacast 0x0090ed38;
// qt_metacall 0x0090ed7a(5B)= 纯转发 QObject::qt_metacall。
