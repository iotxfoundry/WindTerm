// BreadCrumbFace.cpp —— 从 Widgets/Faces/BreadCrumbFace 拆出(按 UI 架构归位)
#include "Widgets/Bars/BreadCrumbFace.h"

// FUN_00548630(55B,0017.c:16344)真身:
//   FUN_0054d22a(*(this+0x30), flags)(编辑件启用/只读面,cited);
//   flag != 0 → QWidget::setFocus(edit, 7 = MenuBarFocusReason)。
void BreadCrumbFace::setCrumbsActive(bool active)
{
	if (m_edit30 == nullptr)
		return;
	if (m_crumb30 != nullptr)
		m_crumb30->setActive(active); // FUN_0054d22a @00548630
	if (active)
		m_edit30->setFocus(Qt::MenuBarFocusReason); // 7 @0054864x
}

// FUN_005211fe(162B,0016.c:15189)AddressBar ctor 真身:
//   基 BreadCrumb ctor → vtable 换 AddressBar → objectName "AddressBar"
//   @00521242-57 → FUN_00521178(134B):connect(edit, FUN_008f826e →
//   this, FUN_005247c5)(edit 类未建模 → 接线 cited 不落)。
AddressBarFace::AddressBarFace(QWidget *parent)
	: BreadCrumbFace(parent) // FUN_00548546 @005211fe
{
	setObjectName(QStringLiteral("AddressBar")); // @00521242-57
	// connect(edit30(), 信号 FUN_008f826e, this, FUN_005247c5)@00521178 — cited。
}

// FUN_0054d22a(197B,0017.c:19741)激活切换真身:
//   @0054d22a +0x74 = active;!active → +0xb8 QTimer::start();
//   active → QLineEdit::text() + setSelection(0);
//   cursor = QCursor(active ? 4(IBeam) : 0(Arrow)) → setCursor;
//   setAttribute(2, !active) → update()。