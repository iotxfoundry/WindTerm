#include "Sessions/Transfers/YModem.h"

// 构造腿出处:0x007e44c0(s_xmodem_packetSize_7e44c0)param_2 == 1 分支:
//   operator_new(200) → FUN_0079c8a0(session, parent)(XYModem ctor)
//   → *this = &YModem_vtable → *(ushort*)(this + 0x50) = 0x101
//   → 配置键 "ymodem.packetSize" 取值 value → FUN_0079c88c(this, value != 0x80)
YModem::YModem(QObject *session, QObject *writer)
    : XYModem(session, writer) // FUN_0079c8a0
{
	m_dirOnly50 = true; // +0x50 低字节 = 1
	m_trimSub51 = true; // +0x50 高字节 = 1
	// setSubChar(configValue != 0x80) —— 配置读取腿属宿主调用方。
}

// YModem_dtor(0x007f6ab4,19B):vptr = YModem_vtable → XYModem_dtor。
YModem::~YModem() = default;
