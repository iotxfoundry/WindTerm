// ShellExecutorFace.cpp — 本地 shell 命令执行器。

#include "Sessions/Core/ShellExecutorFace.h"

// 出处:QMetaObject 0x011a9d40(methods=1 signals=1);ctor 内联在调用点。
ShellExecutorFace::ShellExecutorFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x00875400(120B)真身:
//   +0x18 子对象走 0x00875c00(29B)清理 → QObject 析构。
// deleting 0x00875478(23B)真身:+ operator_delete(_, 0x28)。
ShellExecutorFace::~ShellExecutorFace() = default;

// metasurface:metaObject 0x00918da0;qt_metacast 0x00918e3a;
// qt_metacall 0x00918e7c(104B):1 条记录;分发 0x008751dc(141B)。
