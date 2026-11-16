#pragma once

#include <QMap>
#include <QWidget>

class QComboBox;
class QDoubleSpinBox;
class QHBoxLayout;
class QStackedLayout;
class QStackedWidget;
class QTabBar;
class QTabWidget;

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
// **宿主已勘定为 TriggerDialogFace**(批 346:FUN_006f2dd4 ctor 实测
//   +0x30 QTabBar / +0x40 QStackedLayout / +0x88 QMap,与本文用例逐项吻合;
//   两者可视为同一类的行为面拆分)。字段由 asm 实读:
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

// TriggerActionWidgetFace — FUN_006fdcde(274B,0022.c:26700) ctor 全量实读:
//   QWidget(parent, 0) → vtable TriggerActionWidget_vtable + 副 vptr 0118bcc8 →
//   +0x30 = kind(int) → +0x50/+0x58/+0x60/+0x68/+0x70 = 0 →
//   build()(FUN_006fd6c0)→ connect(+0x38 QComboBox::currentIndexChanged →
//   +0x40 QStackedWidget::setCurrentIndex,闭包 impl FUN_006b6730,
//   smeta QComboBox)。dtor 族实测对象尺寸 0x78(与 new 0x78 一致)。
//
// 内部装配 FUN_006fd6c0(1203B,0022.c:26537) 实测:
//   form = new QFormLayout(0x20)(父 0);
//   label = new QLabel(0x30, tr("&Action:")(0xc9fe80), 0, 0);
//   +0x38 = new 0x48 + combo_makeSearchCombo(搜索下拉);
//   +0x40 = new QStackedWidget(0x30);  +0x48 = new QTabWidget(0x30);
//   三平台页签:addTab(FUN_006f8e30(this,"linux"),"&Linux"(0xc9d4aa))/
//     ("macos","&macOS"(0xc9d4cb))/("windows","&Windows"(ascii));
//   建页序 = int 表 @0xc9ff80 实读 {3, 2, 1, 4}:
//     sub=1 → new 0x70 + FUN_006f83b0(w,sub,(kind-1>3),0) → +0x58;+0x68 = w+0x40;
//     sub=2 → new QGroupBox + QVBoxLayout + new 0x50 + FUN_006cc226(w,0) → +0x50;
//             group->setLayout(vbox);(group 进 stack)
//     sub=4 → new 0x70 + FUN_006f83b0 → +0x60;+0x70 = w+0x40;
//     sub=3 → 无建件(直接入 stack);
//     每页入 stack 后 combo 追加一项(文案 = FUN_0069b57e/FUN_006f8cb4 链 tr,
//       data = sub);
//   门:kind == 10 只建 sub==3;kind ∈ 2..4 时不建 sub==4;
//   尾:@label->setBuddy(...);kind==10 → combo->findData(QVariant(3), 0x100,
//     0x10)(Qt::UserRole / Qt::MatchCaseSensitive)→ setCurrentIndex → hide();
//     form->setContentsMargins(全零);addRow ×3;setLayout(form);
//     setTabOrder(+0x38, +0x40);setFocusProxy(this)。
class TriggerActionWidgetFace : public QWidget {
	Q_OBJECT
public:
	explicit TriggerActionWidgetFace(int kind, QWidget *parent = nullptr); // FUN_006fdcde
	void build();                                                          // FUN_006fd6c0

protected:
	int m_kind30 = 0;                    // +0x30
	QComboBox *m_combo38 = nullptr;      // +0x38(0x48 search combo)
	QStackedWidget *m_stack40 = nullptr; // +0x40
	QTabWidget *m_tabs48 = nullptr;      // +0x48
	QWidget *m_f50 = nullptr;            // +0x50(new 0x50 sub=2 件)
	QWidget *m_f58 = nullptr;            // +0x58(new 0x70 sub=1 件)
	QWidget *m_f60 = nullptr;            // +0x60(new 0x70 sub=4 件)
	QWidget *m_f68 = nullptr;            // +0x68(sub=1 件 +0x40)
	QWidget *m_f70 = nullptr;            // +0x70(sub=4 件 +0x40)
};

// SendTextTriggerPageFace — kind 11(new 0x68)装配 FUN_006f8590
//   (dialog_buildSpinForm,1013B,0022.c:23660) 全量实读:
//   form = QFormLayout(0x20);label1  tr("&Match:")(0xc9fd97,0x30);
//                               label2  tr("&Send:")(0xc9dafd,0x30);
//   +0x38 = new 0x68 + FUN_0056376e(w, 0xe000, 0)(文本域);+0x40 = w+0x40;
//   +0x48 = new 0x70 + FUN_006f83b0(w, 4, 1, 0);+0x50 = w+0x40;
//   +0x58 = new 0x48 combo_makeSearchCombo;+0x60 = new QDoubleSpinBox(0x30);
//   combo 三项(data 2/1/0)文案 = tr(0xc9fdd8 "Send after text match and next
//     command prompt" / 0xc9fe08 "Send after text match and next line break" /
//     0xc9fd9f "Send after text match ");
//   spin:setSuffix("s") / setDecimals / setMinimum(0.0) /
//     setMaximum(999999.9) / setSingleStep(0.1);
//   label->setBuddy ×2;+0x38 非空 → FUN_006f1850(+0x48);
//   form margins 全零;assembleBusyOverlay(FUN_006f1994);addRow ×4;
//   另两行表头 tr("Send &Condition:")(0xc9fdb6)/tr("Send &Later:")(0xc9fdc7);
//   setLayout(form);setTabOrder(+0x40,+0x50)→(+0x50,+0x58)→(+0x58,+0x60);
//   setFocusProxy(this)。
class SendTextTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit SendTextTriggerPageFace(QWidget *parent = nullptr);
	void assembleSendTextPage(); // FUN_006f8590

protected:
	QWidget *m_edit38 = nullptr;      // +0x38(0x68 文本域;语料 +0x40 = 其内部件)
	QWidget *m_f48 = nullptr;         // +0x48(new 0x70,FUN_006f83b0(4,1);+0x50 = 其 +0x40)
	QComboBox *m_combo58 = nullptr;   // +0x58(0x48 search combo)
	QDoubleSpinBox *m_spin60 = nullptr; // +0x60(QDoubleSpinBox 0x30)
};
