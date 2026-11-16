// TriggerPageFace.cpp — 触发器页基(批 341)
#include "TriggerPageFace.h"

// FUN_006f1966(45B,0022.c:19239)ctor 真身
TriggerPageFace::TriggerPageFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @006f1966
{
	// +0x10 副 vptr / +0x30 = 0(C++ 自洽承载)
}

// FUN_006f1994(417B)装配真身(遮罩腿):
//   @006f1994 overlay_makeBusyWidget(0xa0, 1, 0, 0) → +0x30;
//   @006f19xx connect(遮罩 信号 FUN_008fae78 → 页槽,0x20 闭包 FUN_006f6d60,
//     smeta 0119d620)→ 余段(遮罩策略/字段装配)cited。
void TriggerPageFace::assembleBusyOverlay()
{
	// overlay_makeBusyWidget(this, 1, 0, 0)@006f1994 — cited(遮罩件未建模)
	// connect(遮罩信号 → 页槽)@006f19xx — cited。
}
