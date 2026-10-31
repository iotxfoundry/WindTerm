#include "KitBar.h"

// === KitBar(QWidget*) ===
// 转写 FUN_008b31b6(0027:71172,420B):
//   QToolBar::QToolBar(param_1,param_2)→ vtable=KitBar →
//   +0x30 QList(shared_null)→ +0x38/+0x40 ← 0 →
//   objectName("KitBar")@008b321b-34 → King::registerBarsAndPanes(&out,"KitBar")
//   → setWindowTitle(out)@008b3287 → setAttribute(0x37,1)@008b32cc →
//   setAllowedAreas(3)@008b32d8 → setFloatable(false)@008b32e2 →
//   FUN_008b3178(尾装)。
// 注:setAttribute 第二参 0x37 = Qt::WA_ 常量(0x37 = 55 = WA_StyledBackground
//   邻域;语料字面照抄,语义名不发明);setFloatable(false) = SUB81(...,0)。
KitBar::KitBar(QWidget *parent)
	: QToolBar(parent)
	, m_f30()   // *(this+0x30) = QListData::shared_null @008b31e2
	, m_f38(0)  // *(this+0x38) = 0 @008b31ea
	, m_f40(0)  // *(this+0x40) = 0 @008b31f2
{
	setObjectName(QStringLiteral("KitBar"));       // @008b321b-34
	// King::registerBarsAndPanes(&out,QString("KitBar"))@008b3269-8b →
	//   QWidget::setWindowTitle(out)@008b3287 — cited — wave-2
	//   (King::registerBarsAndPanes 未落库,标题合成面不发明)
	setAttribute(Qt::WidgetAttribute(0x37), true); // @008b32cc(语料字面 0x37)
	setAllowedAreas(Qt::ToolBarAreas(3));          // @008b32d8(语料字面 3)
	setFloatable(false);                           // SUB81(param_1,0)@008b32e2
	tailAssemble();                                // FUN_008b3178 @008b32ec
}

// === tailAssemble() ===
// 转写 FUN_008b3178(0027:71156,62B):layout() 非空 →
//   QLayout::setContentsMargins / QLayout::setSpacing(实参 Ghidra 折叠)。
void KitBar::tailAssemble()
{
	if (layout() != nullptr) { // QWidget::layout @008b3182
		// QLayout::setContentsMargins / QLayout::setSpacing
		//   (实参 Ghidra 折叠)— cited — wave-2
	}
}
