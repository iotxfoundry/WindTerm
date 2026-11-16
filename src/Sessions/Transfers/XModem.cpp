#include "Sessions/Transfers/XModem.h"

// 构造腿出处:0x007e44c0(s_xmodem_packetSize_7e44c0)param_2 == 0 分支:
//   operator_new(200) → FUN_0079c8a0(session, parent)(XYModem ctor)
//   → *this = &XModem_vtable → *(ushort*)(this + 0x50) = 0(dirOnly = false)
//   → 配置键 "xmodem.packetSize" 取值 value → FUN_0079c88c(this, value == 0x400)
XModem::XModem(QObject *session, QObject *writer)
    : XYModem(session, writer) // FUN_0079c8a0
{
	m_dirOnly50 = false; // +0x50 实读 0
	// setSubChar(configValue == 0x400) —— 配置读取腿属宿主(0x007e44c0 调用方),
	// 此处只登记语义。
}

// XModem_dtor(0x007f6a7a,19B):vptr = XModem_vtable → XYModem_dtor。
XModem::~XModem() = default;
