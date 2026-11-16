// ProcessFace.cpp — 子进程封装。

#include "Utility/ProcessFace.h"

// 出处:RTTI "Process";ctor 内联在调用点,仅转发 QProcess 基构造。
ProcessFace::ProcessFace(QObject *parent)
    : QProcess(parent)
{
}

// dtor 0x0065ccfe(19B)真身:只有 QProcess::~QProcess —— 零字段。
// deleting 0x0065cd12(37B)真身:+ operator_delete(_, size)。
ProcessFace::~ProcessFace() = default;
