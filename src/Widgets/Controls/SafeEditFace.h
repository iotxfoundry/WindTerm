#pragma once

#include <QString>

#include "Widgets/Controls/PathEditFace.h"

// SafeEditFace — 安全输入框(PathEdit 派生,再补一个字段)。
//
// 出处:RTTI "SafeEdit";sizeof = **0x90**
// (deleting 0x008fac84 的 operator_delete(_,0x90));
// dtor 0x008fadc0(147B)/deleting 0x008fac84(160B)。
//
// **基类判定用 dtor 链,不采信 QMetaObject 的 superdata**:
//   SafeEdit 的 dtor 是标准三级链 ——
//     ① vptr = &SafeEdit_vtable → 释放 +0x88(SafeEdit 自有);
//     ② vptr = &PathEdit_vtable(语料符号 PTR_FUN_01198458)
//        → 释放 +0x50 / +0x30(PathEdit 层);
//     ③ QLineEdit 析构。
//   中间那一跳写的是 **PathEdit 的 vtable**,并且紧接着释放的正是 PathEdit
//   的字段 ⇒ 基类 = PathEdit。尺寸也自洽:0x90 = PathEdit 的 0x80 + 0x88 字段。
//   ⚠ 但 SafeEdit 的 QMetaObject(0x0119d3c0)superdata 读出来是
//   **LineEdit(0x01198660)**,与本判据矛盾 —— 已登记 docs/quirks.md,
//   待编译期用 `static_cast<PathEdit*>` 是否合法来终审。
class SafeEditFace : public PathEditFace {
	Q_OBJECT

public:
	explicit SafeEditFace(QWidget *parent = nullptr);
	~SafeEditFace() override; // 0x008fadc0

private:
	QString m_f88; // +0x88
};
