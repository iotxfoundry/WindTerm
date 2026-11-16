// ConcreteCommanders.cpp — 三个协议命令器(见头注对照表)。

#include "Sessions/Commanders/ConcreteCommanders.h"

// 出处:三者 QMetaObject 的 metacall 均 5 字节纯转发、superdata 均
// SuperCommander(0x011a7440);ctor 均内联在调用点,只转发基构造。

// SerialCommander dtor 0x009188ba(29B)真身:零字段;
// deleting 0x009188f8(47B)真身:+ operator_delete(_, size)。
SerialCommanderFace::SerialCommanderFace(QObject *parent) : SuperCommander(parent) { }
SerialCommanderFace::~SerialCommanderFace() = default;

// SshCommander dtor 0x00869a1c(42B)真身:零字段,但多一跳清理;
// deleting 0x00869a4c(23B)真身;vt12 0x00869a16(5B)是句柄取用腿。
SshCommanderFace::SshCommanderFace(QObject *parent) : SuperCommander(parent) { }
SshCommanderFace::~SshCommanderFace() = default;

// TcpCommander dtor 0x00919044(29B)真身:零字段;
// deleting 0x00919082(47B)真身;
// 协议实现 0x0090ef1c(5928B)本批 cited —— 锚入口,留协议开批。
TcpCommanderFace::TcpCommanderFace(QObject *parent) : SuperCommander(parent) { }
TcpCommanderFace::~TcpCommanderFace() = default;
