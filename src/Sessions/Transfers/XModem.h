#ifndef SESSIONS_TRANSFERS_XMODEM_H
#define SESSIONS_TRANSFERS_XMODEM_H

#pragma once

// XModem — XMODEM 变体。RTTI 类名 "XModem"(vtable 0x118f2f8)。
// 构造证据:0x007e44c0 `s_xmodem_packetSize_7e44c0(session, 0)`:
//   operator_new(200) → XYModem ctor 0x0079c8a0 → vptr = XModem_vtable
//   → +0x50 = 0(dirOnly = false)
//   → 配置键 "xmodem.packetSize" → setSubChar(value == 0x400)
//   → 存到宿主 +0x200
// 析构:XModem_dtor 0x007f6a7a / deleting 0x007f6a8e(尺寸 200)。

#include "Sessions/Transfers/XYModem.h"

class XModem : public XYModem {
	Q_OBJECT

public:
	XModem(QObject *session, QObject *writer); // 0x007e44c0 内的构造腿
	~XModem() override;                        // 007f6a7a
};

#endif // SESSIONS_TRANSFERS_XMODEM_H
