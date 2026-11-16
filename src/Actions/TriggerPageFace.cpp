// TriggerPageFace.cpp — 触发器页族共有面(批 341/342)
#include "TriggerPageFace.h"

#include <QComboBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QTabBar>
#include <QTableView>

// FUN_006f1966(45B,0022.c:19239)ctor 真身
TriggerPageFace::TriggerPageFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @006f1966
{
	// +0x10 副 vptr / +0x30 = 0(C++ 自洽承载)
}

// FUN_006f1994(417B,0022.c:19240)装配真身(全量):
//   @006f1994 overlay = operator_new(0xa0) + overlay_makeBusyWidget(overlay,1,0,0)
//     → +0x30;                                    制件 0xa0 未建模(cited 承接为 QWidget)
//   @006f19c6 connect(overlay, 信号 FUN_008fae78, this, 槽 FUN_00909092,
//     闭包 impl FUN_006f6d60(0x20,捕获 page), smeta 0119d620);
//   @006f1a5x connect(overlay, 信号 FUN_008faeac(bool), this,
//     闭包 impl FUN_006f2be6(0x18,捕获 page), smeta 0119d620);
//   @006f1ae8 layout = operator_new(0x20) QHBoxLayout;
//   @006f1b05 QLayout::setContentsMargins(QMargins 全零 —— asm 0x6f1aed 两处 movq $0);
//   @006f1b0f QBoxLayout::addStretch(0);
//   @006f1b1e QBoxLayout::addWidget(overlay, 0, Qt::Alignment(0));
//   @006f1b23 return layout(语料无 setLayout)。
QHBoxLayout *TriggerPageFace::assembleBusyOverlay()
{
	// overlay_makeBusyWidget(0xa0, 1, 0, 0)@006f1994 — 遮罩件未建模,
	// 以裸 QWidget 承接占位(cited:样式/动画腿来自 overlay_makeBusyWidget)
	m_busy30 = new QWidget(this);

	// 两路 connect(信号 FUN_008fae78 / FUN_008faeac,闭包槽)@006f19c6/@006f1a5x
	// — 信号地址无 Qt 元对象名可引,cited(行为面已在 onBusyStateChanged 转写)。

	auto *lay = new QHBoxLayout;                 // @006f1ae8(0x20)
	lay->setContentsMargins(0, 0, 0, 0);         // @006f1b05
	lay->addStretch(0);                          // @006f1b0f
	lay->addWidget(m_busy30, 0, Qt::Alignment()); // @006f1b1e
	return lay;                                  // @006f1b23
}

// FUN_006f2be6(395B,0022.c:19952)遮罩信号槽真身:
//   入口 = QSlotObjectBase::impl(which):which==0 → delete 闭包(0x18);
//   which==1 → Call 体。
//   @006f2c08 v = *(bool*)(args[1])(信号唯一 bool 参,args[0] 为返回值槽);
//   @006f2c17 parent = *(闭包+0x10)(= page,捕获);
//   @006f2c50 qt_qFindChildren_helper(page, "", QWidget::smeta, 递归);
//   @006f2cb2 逐项 __dynamic_cast(w, QWidget::typeinfo, 0x1195cf0)
//     (0x1195cf0 = 本二进制内 QTableView 派生类 typeinfo);
//   @006f2cdd qt_qFindChild_helper(tv, "", 0x1194e40) 非空才动作;
//   @006f2cf9 v ? @006f2d05 selectRow(asm xor esi,esi → 0) : @006f2d46 clearSelection;
//   @006f2d0e w != *(page+0x30)(= 遮罩) → @006f2d1b setEnabled(v)(esi = v)。
void TriggerPageFace::onBusyStateChanged(bool v)
{
	const QList<QWidget *> ws = findChildren<QWidget *>(); // @006f2c50 递归
	for (QWidget *w : ws) {
		if (auto *tv = dynamic_cast<QTableView *>(w)) { // @006f2cb2 类型 0x1195cf0
			if (tv->findChild<QObject *>() != nullptr) { // @006f2cdd smeta 0x1194e40
				if (v)
					tv->selectRow(0); // @006f2d05(esi=0)
				else
					tv->clearSelection(); // @006f2d46
			}
		}
		if (w != m_busy30) // @006f2d0e 遮罩自身不参与启停
			w->setEnabled(v); // @006f2d1b
	}
}

// FUN_006fde04(210B,0022.c:26743)ConnectionTriggerPage 装配真身(结构段):
//   @006fde23 form = operator_new(0x20) + QFormLayout(父 0);
//   @006fde3d w = operator_new(0x78) + FUN_006fdcde(w, *(int*)(page+0x38), 0)
//     → +0x40(TriggerActionWidget,dtor 实测尺寸 0x78 一致);
//   @006fde5x QLayout::setContentsMargins(全零,Margins 由 Ghidra 折叠);
//   @006fde6x FUN_006f1994(page) —— 遮罩装配(本类 assembleBusyOverlay);
//   @006fde7x form->addRow(子件);form->addRow(第二行,Ghidra 折叠);
//   @006fdex  setLayout(form);setFocusProxy(page)。
void TriggerPageFace::assembleConnectionPage(int kind)
{
	auto *form = new QFormLayout;                  // @006fde23(0x20,父 0)
	m_action40 = new TriggerActionWidgetFace(kind, this); // @006fde3d 0x78(FUN_006fdcde)
	form->setContentsMargins(0, 0, 0, 0);          // @006fde5x(全零)
	assembleBusyOverlay();                         // @006fde6x(FUN_006f1994)
	form->addRow(m_action40);                      // @006fde7x
	setLayout(form);                               // @006fdex
	setFocusProxy(this);                           // @006fdex
}

// FUN_006fdf10(281B,0022.c:26774)ConnectionTriggerPage ctor(1-4 共用):
//   FUN_006f1966(base)→ 自写 vtable ConnectionTriggerPage + 副 vptr 0118c100 →
//   +0x38 = kind → 标题按 kind 取 tr(1..4)否则 ascii(0xcb99b6,非串面 cited)→
//   setWindowTitle → 装配 FUN_006fde04。
static QString connTriggerTitle(int kind)
{
	switch (kind) {
	case 1: return QStringLiteral("&After connection");      // 0xc9fe89
	case 2: return QStringLiteral("&After disconnection");   // 0xc9fe9b
	case 3: return QStringLiteral("&Before connection");     // 0xc9feb0
	case 4: return QStringLiteral("&Before disconnection");  // 0xc9fec3
	default: return QString();                               // @0xcb99b6(cited 非串面)
	}
}

// 006f440e 逐 case 的标题(kind 5-12),地址见表:
static QString actionPageTitle(int kind)
{
	switch (kind) {
	case 5:  return QStringLiteral("&Custom Link");     // 0xc9fb21
	case 6:  return QStringLiteral("&Custom Menu");     // 0xc9fb2e
	case 8:  return QStringLiteral("&Highlight Text");  // 0xc9fb3b
	case 9:  return QStringLiteral("&Play Sound");      // 0xc9fb4b
	case 10: return QStringLiteral("Run &Command");     // 0xc9fb57
	case 11: return QStringLiteral("&Send Text");       // 0xc9fb64
	case 12: return QStringLiteral("&Show Tooltip");    // 0xc9fb6f
	default: return QString();
	}
}

// 006f440e 建页(switch 腿):kind 1-4 走 FUN_006fdf10(含装配);
// kind 5/6/8/9/10/11/12 各自 new + base ctor + 自写 vtable + tr 标题 +
// 各自装配腿(表见头注,均 cited —— 各页装配函数未逐句转写)。
QWidget *TriggerPageStackFace::createPage(int kind)
{
	TriggerPageFace *page = nullptr;
	switch (kind) {
	case 1: case 2: case 3: case 4:
		page = new TriggerPageFace;             // operator_new(0x48)
		page->setWindowTitle(connTriggerTitle(kind)); // FUN_006fdf10 tr 四串
		page->assembleConnectionPage(kind);     // FUN_006fde04
		return page;
	case 5: case 6: case 8: case 9: case 10: case 11: case 12:
		page = new TriggerPageFace;             // 0x58/0x60/0x40/0x48/0x50/0x68/0x60
		page->setWindowTitle(actionPageTitle(kind)); // 006f440e 逐 case tr
		// 各页装配腿(FUN_00703d3e / 00703fb0+006f79ec / 006f7c3c /
		//   00704340+006f7ea6 / 006fe290 / dialog_buildSpinForm /
		//   00703ab0)— cited。
		return page;
	default:
		return nullptr;                         // 语料无 case → caseD_0 直返
	}
}

// FUN_006f440e(1804B)页栈建页真身:
//   @006f44xx 命中 +0x88(QMap<int,page*>)→ 复用(pQVar6 = 节点+0x20);
//   未命中 → 建页 → 插表(createNode 0x28,键 @+0x18,值 @+0x20)→
//   QStackedLayout::addWidget(+0x40, page)(@006f4a78,实参 Ghidra 折叠);
//   合流:@006f4548 windowTitle(@006f453e tabBar = +0x30)→
//   @006f4555 setTabText(asm esi=0 → 恒第 0 页)→
//   @006f456a FUN_006f1b5a(page, state):page+0x30 非空 → FUN_0056672a(
//     page+0x30, state, 0, 1)(179B 自定义可切换件置态;param_4!=0 发
//     信号 FUN_008faeac(件, 态))— cited(该类未建模);
//   @006f4579 页虚槽 +0x1a0(基类 = __cxa_pure_virtual@0xbec350,各页覆写)— cited;
//   @006f4586 QStackedLayout::setCurrentWidget(+0x40, page)。
QWidget *TriggerPageStackFace::showPage(int kind, bool state, void *param4)
{
	QWidget *page = m_pages88.value(kind, nullptr); // +0x88 查
	if (page == nullptr) {
		page = createPage(kind);
		if (page == nullptr)
			return nullptr;                 // default → caseD_0 直返
		m_pages88.insert(kind, page);       // createNode(0x28)
		if (m_stack40)
			m_stack40->addWidget(page);     // @006f4a78
	}
	if (m_tabBar30)
		m_tabBar30->setTabText(0, page->windowTitle()); // @006f4555(esi=0)
	// FUN_006f1b5a(page, state)@006f456a — cited(FUN_0056672a 面)
	Q_UNUSED(state);
	// (**(*page+0x1a0))(page, param4)@006f4579 — 基类纯虚槽,各页覆写,cited
	Q_UNUSED(param4);
	if (m_stack40)
		m_stack40->setCurrentWidget(page);  // @006f4586
	return page;
}

// FUN_006fdcde(274B,0022.c:26700)TriggerActionWidget ctor 真身
TriggerActionWidgetFace::TriggerActionWidgetFace(int kind, QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @006fdcde
	, m_kind30(kind)                      // +0x30
{
	// +0x50..+0x70 五槽清零(成员初值)
	build();                              // @006fdd3d FUN_006fd6c0
	// connect(+0x38 currentIndexChanged → +0x40 setCurrentIndex)@006fdd5x
	// — 闭包 impl FUN_006b6730,smeta QComboBox;cited(槽面同签名直连)。
}

// FUN_006fd6c0(1203B,0022.c:26537)TriggerActionWidget 内部装配真身(结构段)
void TriggerActionWidgetFace::build()
{
	auto *form = new QFormLayout;                          // @006fd6ea(0x20,父 0)
	auto *label = new QLabel(QStringLiteral("&Action:"));  // tr(0xc9fe80),new 0x30

	m_combo38 = new QComboBox;                             // @006fd74a 0x48
	//   combo_makeSearchCombo 承接(搜索式下拉;cited 附加件)
	m_stack40 = new QStackedWidget;                        // @006fd765(0x30)
	m_tabs48 = new QTabWidget;                             // @006fd780(0x30)

	m_tabs48->addTab(new QWidget, QStringLiteral("&Linux"));   // @006fd7xx(0xc9d4aa)
	m_tabs48->addTab(new QWidget, QStringLiteral("&macOS"));   // @006fd7xx(0xc9d4cb)
	m_tabs48->addTab(new QWidget, QStringLiteral("&Windows")); // @006fd820(ascii)

	// 建页序 int 表 @0xc9ff80 实读 = {3, 2, 1, 4}
	static const int kBuildOrder[4] = { 3, 2, 1, 4 };
	for (int i = 0; i < 4; ++i) {
		const int sub = kBuildOrder[i];
		if (m_kind30 == 10 && sub != 3)                          // @006fd982
			continue;
		if (m_kind30 >= 2 && m_kind30 <= 4 && sub == 4)          // @006fd874
			continue;
		const bool gt4 = (m_kind30 - 1) > 3;                     // @006fd8xx bVar3
		if (sub == 1) {
			// new 0x70 + FUN_006f83b0(w, 1, gt4, 0) — cited(件未建模)
			m_f58 = new QWidget;
			m_stack40->addWidget(m_f58);                         // @006fdaxx
		} else if (sub == 2) {
			auto *group = new QGroupBox;                         // @006fda80(0x30)
			auto *vbox = new QVBoxLayout(group);                 // @006fda97(0x20)
			m_f50 = new QWidget;                                 // 0x50 + FUN_006cc226(w,0) cited
			vbox->addWidget(m_f50, 0, Qt::Alignment());          // @006fdaxx
			m_stack40->addWidget(group);                         // @006fdaxx
		} else if (sub == 4) {
			// new 0x70 + FUN_006f83b0(w, 4, gt4, 0) — cited
			m_f60 = new QWidget;
			m_stack40->addWidget(m_f60);                         // @006fdbxx
		} else {
			// sub == 3:语料 @006fd987 直接 addWidget(入参 Ghidra 折叠)— cited
		}
		// combo 追加项:文案 = FUN_0069b57e/FUN_006f8cb4 → tr,data = sub
		//   (@006fd8f4 count/insert_item)— cited(文案链未转写,不发明)。
	}

	label->setBuddy(m_combo38);                              // @006fd9xx(setBuddy)
	if (m_kind30 == 10) {
		const int idx = m_combo38->findData(3, Qt::UserRole); // @006fdb0d(0x100,0x10)
		m_combo38->setCurrentIndex(idx);                      // @006fdaxx
		hide();                                               // @006fdaxx
	}
	form->setContentsMargins(0, 0, 0, 0);                     // @006fdaxx(全零)
	form->addRow(label);                                     // addRow ×3(实参折叠,cited)
	form->addRow(m_combo38);
	form->addRow(m_tabs48);
	setLayout(form);                                         // @006fdaxx
	QWidget::setTabOrder(m_combo38, m_stack40);              // @006fdaxx(+0x38 → +0x40)
	setFocusProxy(this);                                     // @006fdaxx
}

// FUN_006f8590(dialog_buildSpinForm,1013B,0022.c:23660)SendText 页装配真身
SendTextTriggerPageFace::SendTextTriggerPageFace(QWidget *parent)
	: TriggerPageFace(parent)
{
	assembleSendTextPage();
}

void SendTextTriggerPageFace::assembleSendTextPage()
{
	auto *form = new QFormLayout;                                  // @006f85b3(0x20)
	auto *label1 = new QLabel(QStringLiteral("&Match:"));          // tr(0xc9fd97),0x30
	auto *label2 = new QLabel(QStringLiteral("&Send:"));           // tr(0xc9dafd),0x30

	m_edit38 = new TriggerActionEditPanelFace(0xe000, this);                                  // @006f8658(0x68,FUN_0056376e)
	m_f48 = new QWidget(this);                                     // @006f8686 0x70 + FUN_006f83b0(4,1,0) cited
	m_combo58 = new QComboBox;                                     // @006f86aa 0x48
	m_spin60 = new QDoubleSpinBox;                                 // @006f86c5 0x30

	m_combo58->addItem(QStringLiteral("Send after text match and next command prompt"), 2); // 0xc9fdd8
	m_combo58->addItem(QStringLiteral("Send after text match and next line break"), 1);     // 0xc9fe08
	m_combo58->addItem(QStringLiteral("Send after text match "), 0);                        // 0xc9fd9f

	m_spin60->setSuffix(QStringLiteral("s"));                      // @006f8804
	m_spin60->setMinimum(0.0);                                     // @006fxxxx
	m_spin60->setMaximum(999999.9);                                // @006fxxxx
	m_spin60->setSingleStep(0.1);                                  // @006fxxxx

	label1->setBuddy(m_edit38);                                    // setBuddy ×2
	label2->setBuddy(m_combo58);
	// if (+0x38) FUN_006f1850(+0x48)@006f88xx — cited
	form->setContentsMargins(0, 0, 0, 0);                          // 全零
	assembleBusyOverlay();                                         // @006f88xx(FUN_006f1994)
	form->addRow(label1, m_edit38);                                // addRow ×4(字段行,实参折叠)
	form->addRow(label2, m_combo58);
	form->addRow(QStringLiteral("Send &Condition:"));              // tr(0xc9fdb6) 表头行
	form->addRow(QStringLiteral("Send &Later:"));                  // tr(0xc9fdc7) 表头行
	setLayout(form);                                               // @006fxxxx
	// 语料 setTabOrder 链走 +0x40/+0x50(两件各自的内部 +0x40 子件);
	//   本面以两件本体顺序承接(cited)。
	QWidget::setTabOrder(m_edit38, m_f48);                         // @(+0x40 → +0x50)
	QWidget::setTabOrder(m_f48, m_combo58);                        // @(+0x50 → +0x58)
	QWidget::setTabOrder(m_combo58, m_spin60);                     // @(+0x58 → +0x60)
	setFocusProxy(this);
}

// FUN_0056376e(90B)TriggerActionEditPanel ctor 真身
TriggerActionEditPanelFace::TriggerActionEditPanelFace(int flags, QWidget *parent)
	: QWidget(parent)                     // FUN_0053397c(基类装配;flags 语料 0xe000)
{
	Q_UNUSED(flags);                      // 0xe000 交由基类面(cited)
	m_f48a = true;                        // +0x48 = 0x0101
	m_f48b = true;                        // +0x49
	// +0x50/+0x58/+0x60 空 QString;metaObject 011955f8 / 副 011957a8(C++ 自洽)
	// s_king__visible_56325c(this) 初始化腿 — cited
}

// FUN_006f7c3c(243B)HighlightText 页装配真身
HighlightTextTriggerPageFace::HighlightTextTriggerPageFace(QWidget *parent)
	: TriggerPageFace(parent)
{
	assembleHighlightPage();
}

void HighlightTextTriggerPageFace::assembleHighlightPage()
{
	auto *form = new QFormLayout;                              // @006f7c5d(0x20)
	auto *label = new QLabel(QStringLiteral("&Rules:"));       // tr(0xc9fd07),0x30
	m_rules38 = new QWidget(this);                             // @006f7cb9(0x48 + FUN_005675e8(0)) cited
	label->setBuddy(m_rules38);
	form->setContentsMargins(0, 0, 0, 0);                      // 全零
	assembleBusyOverlay();                                     // @006f7cxx(FUN_006f1994)
	form->addRow(label);                                       // addRow ×2(实参折叠)
	setLayout(form);                                           // @006f7dxx
	setFocusProxy(this);
}

// FUN_006fe290(327B)RunCommand 页装配真身
RunCommandTriggerPageFace::RunCommandTriggerPageFace(QWidget *parent)
	: TriggerPageFace(parent)
{
	assembleRunCommandPage();
}

void RunCommandTriggerPageFace::assembleRunCommandPage()
{
	auto *form = new QFormLayout;                              // @006fe2b1(0x20)
	auto *label = new QLabel(QStringLiteral("&Match:"));       // tr(0xc9fd97),0x30
	m_edit38 = new TriggerActionEditPanelFace(0xe000, this);                              // @006fe312(0x68,FUN_0056376e)
	m_f40 = m_edit38;                                          // +0x40 = w+0x40
	m_action48 = new TriggerActionWidgetFace(10, this);          // @006fe33a(0x78,kind 10)
	label->setBuddy(m_edit38);
	// FUN_006fb180(+0x48, +0x38)(动作件 ↔ 文本域接线)@006fe3xx — cited
	form->setContentsMargins(0, 0, 0, 0);                      // 全零
	assembleBusyOverlay();                                     // @006fe3xx(FUN_006f1994)
	form->addRow(label);                                       // addRow ×3(实参折叠)
	setLayout(form);                                           // @006fe3xx
	QWidget::setTabOrder(m_f40, m_action48);                   // @(+0x40 → +0x48)
	setFocusProxy(this);
}

// FUN_00703d3e(379B)CustomLink 页装配真身
CustomLinkTriggerPageFace::CustomLinkTriggerPageFace(QWidget *parent)
	: TriggerPageFace(parent)
{
	assembleCustomLinkPage();
}

void CustomLinkTriggerPageFace::assembleCustomLinkPage()
{
	auto *form = new QFormLayout;                              // @00703d5f(0x20)
	auto *label = new QLabel(QStringLiteral("&Match:"));       // tr(0xc9fd97),0x30
	m_edit38 = new TriggerActionEditPanelFace(0xe000, this);                              // @00703dc0(0x68,FUN_0056376e)
	m_f40 = m_edit38;                                          // +0x40 = w+0x40
	m_action48 = new TriggerActionWidgetFace(5, this);          // @00703de8(0x78,kind 5)
	m_f50 = new QWidget(this);                                 // @00703e03(0x40 + FUN_00703a58(0)) cited
	label->setBuddy(m_edit38);
	// FUN_006fb180(+0x48, +0x38)(动作件 ↔ 文本域)@00703exx — cited
	form->setContentsMargins(0, 0, 0, 0);                      // 全零
	assembleBusyOverlay();                                     // @00703exx(FUN_006f1994)
	form->addRow(label);                                       // addRow ×4(实参折叠)
	setLayout(form);                                           // @00703exx
	QWidget::setTabOrder(m_f40, m_action48);                   // @(+0x40 → +0x48)
	QWidget::setTabOrder(m_action48, m_f50);                   // @(+0x48 → +0x50)
	setFocusProxy(this);
}

// FUN_00704340(470B)PlaySound 页装配真身
PlaySoundTriggerPageFace::PlaySoundTriggerPageFace(QWidget *parent)
	: TriggerPageFace(parent)
{
	assemblePlaySoundPage();
}

void PlaySoundTriggerPageFace::assemblePlaySoundPage()
{
	auto *form = new QFormLayout;                              // @00704363(0x20)
	auto *label = new QLabel(QStringLiteral("&Rules:"));       // tr(0xc9fd07)
	m_table38 = new QWidget(this);                             // @007043c9(0x48 + FUN_00584e4a(0x48f)) cited
	m_f40 = m_table38;                                         // +0x40 = w+0x40
	label->setBuddy(m_table38);
	// 三列表头(实读):Pattern / Description / Sound
	//   qlist_appendRange → FUN_00584ee8(+0x38, list)@00704459 — cited
	// FUN_00566d6e(+0x40, tr("No sound available")(0xc9ff23))@007044a4 — cited
	form->setContentsMargins(0, 0, 0, 0);                      // 全零
	assembleBusyOverlay();                                     // @007045xx(FUN_006f1994)
	form->addRow(label);                                       // addRow ×4(实参折叠)
	setLayout(form);
	setFocusProxy(this);
}

// FUN_00703ab0(489B)ShowTooltip 页装配真身
ShowTooltipTriggerPageFace::ShowTooltipTriggerPageFace(QWidget *parent)
	: TriggerPageFace(parent)
{
	assembleShowTooltipPage();
}

void ShowTooltipTriggerPageFace::assembleShowTooltipPage()
{
	auto *form = new QFormLayout;                              // @00703ad3(0x20)
	auto *l1 = new QLabel(QStringLiteral("&Match:"));          // tr(0xc9fd97)
	auto *l2 = new QLabel(QStringLiteral("&Tooltip:"));        // tr(0xc9fefb)
	m_edit38 = new TriggerActionEditPanelFace(0xe000, this);                              // @00703b75(0x68,FUN_0056376e)
	m_f40 = m_edit38;                                          // +0x40
	m_f48 = new QWidget(this);                                 // @00703ba2(0x70 + FUN_006f83b0(5,1,0)) cited
	m_f50 = m_f48;                                             // +0x50
	m_f58 = new QWidget(this);                                 // @00703bc5(0x40 + FUN_00703a58(0)) cited
	l1->setBuddy(m_edit38);
	l2->setBuddy(m_f48);
	// if (+0x38) FUN_006f1850(+0x48)@00703cxx — cited
	form->setContentsMargins(0, 0, 0, 0);                      // 全零
	assembleBusyOverlay();                                     // @00703cxx(FUN_006f1994)
	form->addRow(l1);                                          // addRow ×5(实参折叠)
	form->addRow(l2);
	setLayout(form);
	QWidget::setTabOrder(m_f40, m_f50);                        // @(+0x40 → +0x50)
	QWidget::setTabOrder(m_f50, m_f58);                        // @(+0x50 → +0x58)
	setFocusProxy(this);
}

// FUN_00703fb0(683B)CustomMenu 页装配真身
CustomMenuTriggerPageFace::CustomMenuTriggerPageFace(QWidget *parent)
	: TriggerPageFace(parent)
{
	assembleCustomMenuPage();
}

void CustomMenuTriggerPageFace::assembleCustomMenuPage()
{
	auto *form = new QFormLayout;                              // @00703fd1(0x20)
	auto *l1 = new QLabel(QStringLiteral("&Match:"));          // tr(0xc9fd97)
	auto *l2 = new QLabel(QStringLiteral("&Actions:"));        // tr(0xc9ff05)
	// src = FUN_006f7830(this)@00703fxx(行源/模型)— cited
	m_edit38 = new TriggerActionEditPanelFace(0xe000, this);    // 0x68(FUN_0056376e)
	m_f40 = m_edit38;                                          // +0x40
	m_table48 = new QWidget(this);                             // 0x48 + FUN_00584e4a(0x48f) cited
	m_f50 = new QWidget(this);                                 // 0x40 + FUN_00703a58(0) cited
	l1->setBuddy(m_edit38);
	l2->setBuddy(m_table48);
	// 两列表头(实读):Label / Action → FUN_00584ee8(+0x48)@007040xx — cited
	// FUN_00533a0c(+0x48, 1, src)@007040xx(表 ← 行源)— cited
	// FUN_00566d6e(+0x40, tr("No action available")(0xc9ff0f))@007040xx — cited
	form->setContentsMargins(0, 0, 0, 0);                      // 全零
	assembleBusyOverlay();                                     // @007041xx(FUN_006f1994)
	form->addRow(l1);                                          // addRow ×5(实参折叠)
	form->addRow(l2);
	setLayout(form);
	QWidget::setTabOrder(m_f40, m_f50);                        // @(+0x40 → +0x50)
	QWidget::setTabOrder(m_f50, m_f58);                        // @(+0x50 → +0x58)
	setFocusProxy(this);
}
