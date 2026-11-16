#pragma once

#include <QWidget>

// TriggerPageFace — 语料触发器设置页基面(批 341)。
// ctor FUN_006f1966(45B,0022.c:19239):
//   QWidget(parent,0)→ vtable ConnectionTriggerPage(vt0 011a47f0)→
//   +0x10 副 vptr(011a49b0)→ +0x30 = 0。
// 装配 FUN_006f1994(417B):
//   @006f1994 +0x30 = overlay_makeBusyWidget(0xa0, 1, 0, 0)(忙碌遮罩)→
//   connect(遮罩信号 FUN_008fae78 → 页槽 FUN_00909092 + FUN_006f6d60 面)。
//   其余(行表/字段/触发动作行)按各页 ctor 各自装配 — 逐页批(cited)。
class TriggerPageFace : public QWidget {
	Q_OBJECT
public:
	explicit TriggerPageFace(QWidget *parent = nullptr); // FUN_006f1966
	void assembleBusyOverlay();                          // FUN_006f1994

protected:
	QWidget *m_busy30 = nullptr; // +0x30(overlay_makeBusyWidget 0xa0)
};
