#ifndef SESSIONS_TRANSFERS_YMODEM_H
#define SESSIONS_TRANSFERS_YMODEM_H

#pragma once

// YModem — YMODEM 变体。RTTI 类名 "YModem"(vtable 0x118f390)。
// 构造证据:0x007e44c0 `s_xmodem_packetSize_7e44c0(session, 1)`:
//   operator_new(200) → XYModem ctor 0x0079c8a0 → vptr = YModem_vtable
//   → +0x50 = 0x101(dirOnly = true,trimSub = true;两旗标同处 16 位写)
//   → 配置键 "ymodem.packetSize" → setSubChar(value != 0x80)
//   → 存到宿主 +0x200
// 析构:YModem_dtor 0x007f6ab4 / deleting 0x007f6ac8(尺寸 200)。

#include "Sessions/Transfers/XYModem.h"

class YModem : public XYModem {
	Q_OBJECT

public:
	YModem(QObject *session, QObject *writer); // 0x007e44c0 内的构造腿
	~YModem() override;                        // 007f6ab4
};

#endif // SESSIONS_TRANSFERS_YMODEM_H
