// CommanderRobotFace.cpp — 命令器自动化机器人。

#include "Sessions/Commanders/CommanderRobotFace.h"

// 出处:QMetaObject 0x011a6da0(methods=1 signals=1);ctor 内联在调用点。
CommanderRobotFace::CommanderRobotFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x0090e834(19B)真身:只有 QObject::~QObject —— 零字段。
// deleting 0x0090e848(37B)真身:+ operator_delete(_, size)。
CommanderRobotFace::~CommanderRobotFace() = default;

// metasurface:metaObject 0x0090e6f0;qt_metacast 0x0090e78c;
// qt_metacall 0x0090e7ce(101B):1 条记录,超出 index - 1。
