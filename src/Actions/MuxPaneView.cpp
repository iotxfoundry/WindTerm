#include "MuxPaneView.h"
#include <QVBoxLayout>

// === MuxPaneView(QWidget,MuxPane::Type) ===
// 转写 s_MuxPane_8de0c0(decomp-part-0028.c:25440,202B):
//   QWidget::QWidget(parent) → vt 011abbb8 / 011abd90(vt 表示,不落成员)
//   +0x30 ← FUN_008de0b0(DAT_011be6c8 −1 面板计数;返回值语义未解)
//   +0x34 ← param_2(Type);+0x38 ← shared_null(QString);+0x40 ← 0
//   setObjectName("MuxPane") → FUN_008de052(QVBoxLayout 装配)
// ctor 声明为两参:语料第 3 参 parent 经 QWidget 基类链,QWidget(ptr)
//   惯例由 Qt 显式传递,不另设默认值(语料无默认参证据,不发明)。
MuxPaneView::MuxPaneView(QWidget *parent, MuxPaneType type)
	: QWidget(parent)
	, m_f30(0)   // FUN_008de0b0 计数返回值,值语义未解 — cited — wave-2
	, m_type(type)
{
	setObjectName(QStringLiteral("MuxPane")); // s_MuxPane_8de0c0 @008de12c

	// FUN_008de052(0028:25410,86B):new QVBoxLayout → setContentsMargins →
	// setSpacing → setLayout。两调参数值反编译体为裸调用(常量被 Ghidra
	// 折叠为寄存器传递,不可读)→ 按铁律 3 不发明,记 cited。
	{
		QVBoxLayout *layout = new QVBoxLayout(this); // FUN_008de052 @008de06b
		// QLayout::setContentsMargins(...) — cited — wave-2(参数不可读)
		// QBoxLayout::setSpacing(...)      — cited — wave-2(参数不可读)
		setLayout(layout);                           // FUN_008de052 @008de086
	}
}

// === setCentralView(QWidget*) ===
// 转写 FUN_008de1a8(0028:25489,124B):
//   +0x40 == 新件 → 直返;旧件非空 → deleteLater;
//   layout() dynamic_cast<QVBoxLayout*> → addWidget(view,0,0) →
//   setFocusProxy → 存 +0x40 → show();layout 缺失/非 VBox → 直返。
void MuxPaneView::setCentralView(QWidget *view) // FUN_008de1a8
{
	if (m_central == view) // @008de1b8(+0x40 比较)
		return;
	if (m_central != nullptr) // @008de1bf(旧件 deleteLater)
		m_central->deleteLater();

	QLayout *layout = QWidget::layout(); // @008de1d0
	if (layout == nullptr)
		return;
	QVBoxLayout *vbox = dynamic_cast<QVBoxLayout *>(layout); // @008de1d9(__dynamic_cast → QVBoxLayout typeinfo)
	if (vbox == nullptr)
		return;

	vbox->addWidget(view, 0, 0);                 // QBoxLayout::addWidget(lVar1,param_2,0,0)
	setFocusProxy(view);                         // QWidget::setFocusProxy(param_1)
	m_central = view;                            // 存 +0x40
	QWidget::show();                             // @008de1fd
}
