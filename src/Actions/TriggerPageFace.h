#pragma once

#include <QWidget>

class QHBoxLayout;

// TriggerPageFace — 语料触发器设置页族共有面(批 341/342)。
//
// ctor FUN_006f1966(45B,0022.c:19239) 实测:
//   QWidget::QWidget(this,parent,0) → vptr = 0x11a47f0(vt0 ConnectionTriggerPage;
//   asm 0x6f66fe: mov $0x11a47e0 + lea 0x10 = 0x11a47f0) →
//   +0x10 副 vptr = 0x11a49b0 → +0x30 = 0。
//
// 八页同族实证(批 342):8 个 dtor(FUN dtor 29B/dtor_deleting 47B,
//   006f66fe..006f6b9c) **汇编逐字节相同**——均只写回同一 vptr 对
//   (0x11a47f0 / 0x11a49b0)后 jmp ~QWidget;差异仅在 operator_delete 尺寸:
//     ConnectionTriggerPage 0x48 · CustomLinkTriggerPage 0x58 ·
//     CustomMenuTriggerPage 0x60 · HighlightTextTriggerPage 0x40 ·
//     PlaySoundTriggerPage 0x48 · RunCommandTriggerPage 0x50 ·
//     SendTextTriggerPage 0x68 · ShowTooltipTriggerPage 0x60
//   ⇒ 八页不各自新增虚函数(共享同一 vtable),只以数据成员与装配函数区分;
//   页面差异落在各自装配腿,不在类层次。故本面 = 八页共有的 ctor/遮罩腿,
//   不作为"抽象基类"另行派生。
//
// 装配 FUN_006f1994(417B) 全量已转写 → assembleBusyOverlay。
// 遮罩信号槽 FUN_006f2be6(395B) 全量已转写 → onBusyStateChanged。
class TriggerPageFace : public QWidget {
	Q_OBJECT
public:
	explicit TriggerPageFace(QWidget *parent = nullptr); // FUN_006f1966

	// FUN_006f1994(417B):建遮罩(+0x30)+ 两路 connect + QHBoxLayout
	// (margins 全零 / addStretch(0) / addWidget(遮罩,0,0));返回布局,
	// 语料本函数**不**调 setLayout(由调用方接)。
	QHBoxLayout *assembleBusyOverlay();

public slots:
	// FUN_006f2be6(395B) 遮罩信号(0x008faeac,单 bool 参)的槽 →
	// 遍历子件:QTableView 子类且带指定子件(0x1194e40)时
	// v ? selectRow(0) : clearSelection();其余子件(除 +0x30 遮罩)
	// 一律 setEnabled(v)。
	void onBusyStateChanged(bool v);

protected:
	QWidget *m_busy30 = nullptr; // +0x30(overlay_makeBusyWidget 0xa0)
};
