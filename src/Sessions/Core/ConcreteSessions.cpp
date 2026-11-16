// ConcreteSessions.cpp — 三个协议会话(见头注对照表)。

#include "Sessions/Core/ConcreteSessions.h"

// 出处:三者 QMetaObject 的 metacall 均 5 字节纯转发、superdata 均
// SuperSession(0x011a8220);ctor 均内联在调用点,只转发基构造。

// dtor 0x009189bc(19B)真身:零字段;deleting 0x009189d0(37B)真身。
SerialSessionFace::SerialSessionFace(QObject *parent) : SuperSession(parent) { }
SerialSessionFace::~SerialSessionFace() = default;

// dtor 0x00918444(19B)真身:零字段;deleting 0x00918458(37B)真身;
// vt15 0x0086f1c2(57B)真身:门 +0x10 非空 → dynamic_cast(…, 0x011a8f30)。
SshSessionFace::SshSessionFace(QObject *parent) : SuperSession(parent) { }
SshSessionFace::~SshSessionFace() = default;

// dtor 0x00919146(19B)真身:零字段;deleting 0x0091915a(37B)真身。
TcpSessionFace::TcpSessionFace(QObject *parent) : SuperSession(parent) { }
TcpSessionFace::~TcpSessionFace() = default;
