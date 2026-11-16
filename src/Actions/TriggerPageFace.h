#pragma once

#include <QMap>
#include <QWidget>

class QHBoxLayout;
class QStackedLayout;
class QTabBar;

// TriggerPageFace — 语料触发器页族共有面(批 341/342/343)。
//
// ctor FUN_006f1966(45B,0022.c:19227) 实测:
//   QWidget::QWidget(this,parent,0) → vptr = 0x11a47f0(vt0 ConnectionTriggerPage;
//   asm 0x6f66fe: mov $0x11a47e0 + lea 0x10 = 0x11a47f0) →
//   +0x10 副 vptr = 0x11a49b0 → +0x30 = 0。
//   各派生页 ctor 在 base 之后自写 vtable/副 vptr(见批 343 表)。
//
// 八页同族实证(批 342):8 个 dtor(FUN dtor 29B/dtor_deleting 47B,
//   006f66fe..006f6b9c) 汇编逐字节相同——均只写回同一 vptr 对
//   (0x11a47f0 / 0x11a49b0)后 jmp ~QWidget;差异仅在 operator_delete 尺寸
//   (见批 343 表,与 006f440e 的 operator_new 尺寸逐项一致)。
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

	// FUN_006fde04(210B,0022.c:26743)ConnectionTriggerPage 装配:
	//   form = new QFormLayout(0x20)(父 0);
	//   +0x40 = new 0x78 + FUN_006fdcde(w, +0x38(kind), 0)(TriggerActionWidget 0x78);
	//   setContentsMargins(margins 全零);assembleBusyOverlay();
	//   form->addRow(子件);form->addRow(...);page->setLayout(form→实际接 form);
	//   page->setFocusProxy(page)。
	void assembleConnectionPage(int kind);

	QWidget *busyOverlay() const { return m_busy30; }  // +0x30
	QWidget *actionWidget40() const { return m_action40; } // +0x40(0x78)

public slots:
	// FUN_006f2be6(395B) 遮罩信号(0x008faeac,单 bool 参)的槽 →
	// 遍历子件:QTableView 子类且带指定子件(0x1194e40)时
	// v ? selectRow(0) : clearSelection();其余子件(除 +0x30 遮罩)
	// 一律 setEnabled(v)。
	void onBusyStateChanged(bool v);

protected:
	QWidget *m_busy30 = nullptr; // +0x30(overlay_makeBusyWidget 0xa0)
	QWidget *m_action40 = nullptr; // +0x40(FUN_006fdcde 0x78)
};

// ---------------------------------------------------------------- 页种类表
// 006f440e(1804B) switch(param_2) 逐 case 实测:尺寸 = operator_new 实参,
// 标题 = tr 串(.rodata 实读),各页 ctor 之后自写 vtable + 副 vptr,
// 末接各自的装配腿。kind 7 **无 case**(落 default → 不建页)。
//
// kind | 类                        | new   | 副 vptr   | 标题(tr)            | 装配腿
// -----+---------------------------+-------+-----------+---------------------+--------
//  1   | ConnectionTriggerPage     | 0x48  | 0118c100  | &After connection   | FUN_006fde04
//  2   |   同上(kind 分支)          | 0x48  | 0118c100  | &After disconnection| FUN_006fde04
//  3   |   同上                     | 0x48  | 0118c100  | &Before connection  | FUN_006fde04
//  4   |   同上                     | 0x48  | 0118c100  | &Before disconnection| FUN_006fde04
//  5   | CustomLinkTriggerPage     | 0x58  | 0118c310  | &Custom Link        | FUN_00703d3e
//  6   | CustomMenuTriggerPage     | 0x60  | 0118c520  | &Custom Menu        | FUN_00703fb0
//  8   | HighlightTextTriggerPage  | 0x40  | 0118c730  | &Highlight Text     | FUN_006f7c3c
//  9   | PlaySoundTriggerPage      | 0x48  | 0118c940  | &Play Sound         | FUN_00704340
// 10   | RunCommandTriggerPage     | 0x50  | 0118cb50  | Run &Command        | FUN_006fe290
// 11   | SendTextTriggerPage       | 0x68  | 0118cd60  | &Send Text          | dialog_buildSpinForm
// 12   | ShowTooltipTriggerPage    | 0x60  | 0118cf70  | &Show Tooltip       | FUN_00703ab0
//
// 标题地址:1-4 = 0xc9fe89/0xc9fe9b/0xc9feb0/0xc9fec3(FUN_006fdf10 四 tr);
// 5-12 = 0xc9fb21/2e/3b/4b/57/64/6f(006f440e 逐 case tr)。kind 5 与 6 另接
// 第二条腿(6 多 FUN_006f79ec;9 多 FUN_006f7ea6)。kind 1-4 共用
// FUN_006fdf10(281B)= ConnectionTriggerPage ctor:+0x38 = kind。
enum class TriggerPageKind : int {
	AfterConnection = 1,
	AfterDisconnection = 2,
	BeforeConnection = 3,
	BeforeDisconnection = 4,
	CustomLink = 5,
	CustomMenu = 6,
	HighlightText = 8,
	PlaySound = 9,
	RunCommand = 10,
	SendText = 11,
	ShowTooltip = 12,
};

// TriggerPageStackFace — FUN_006f440e(1804B,0022.c:20784)页栈建页。
// 宿主类名未定(Ghidra 无符号;cited),字段由 asm 实读:
//   +0x30 QTabBar / +0x40 QStackedLayout / +0x88 QMap<int,QWidget*>
//   (节点 0x28:键 int @+0x18,值 ptr @+0x20)。
// 流程:命中 +0x88 → 复用;未命中 → 按 kind 建页 → 插表 → stack->addWidget;
// 两路合流:tabBar->setTabText(0, page->windowTitle())(asm 0x6f4550 xor esi,esi
// = 恒第 0 页)→ FUN_006f1b5a(page,状态)→ 页虚槽 +0x1a0(基类为
// __cxa_pure_virtual@0xbec350,各页覆写;cited)→ stack->setCurrentWidget(page)。
class TriggerPageStackFace {
public:
	// 返回新页/复用页;kind 无 case(7 等)→ nullptr(语料 default 直返)。
	QWidget *showPage(int kind, bool state, void *param4);

private:
	QWidget *createPage(int kind);

	QTabBar *m_tabBar30 = nullptr;          // +0x30
	QStackedLayout *m_stack40 = nullptr;    // +0x40
	QMap<int, QWidget *> m_pages88;         // +0x88
};
