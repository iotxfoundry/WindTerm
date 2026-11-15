// KitDockFace.cpp — 语料 KitDock 两段转写(批 207)
#include <QSplitter>

#include "Actions/KitDockFace.h"
#include "Actions/KitWindowAssemblyFace.h"

// FUN_008b81b0(109B,0027.c:75478)ctor:
//   QWidget::QWidget(this,param_3,0)@008b81b8;+0x38 = param_2 @008b81c8;
//   +0x39 = 0 @008b81d0;+0x3c = 0;+0x44 = -1;+0x4c = -1 @008b81d8-1f4;
//   setFocusPolicy(0)@008b8215;s_ExpandButton_8b7dd4(this);FUN_008b7f60(this)。
KitDockFace::KitDockFace(QWidget *slot38, QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @008b81b8(param_3 = parent)
	, m_f38(slot38)                       // @008b81c8(+0x38)
	, m_f39(false)                        // @008b81d0(+0x39)
{
	setFocusPolicy(Qt::NoFocus); // @008b8215(esi=0)
	// s_ExpandButton_8b7dd4(this)@008b821x + FUN_008b7f60(this)@008b821x
	//   — 子件装配面未转写,cited 不落(铁律 6:不造子件)。
}

// FUN_008b86e4(153B,0027.c:75642)收起行为:
//   if (+0x39 == 0) {
//     p = parentWidget(this);                                    // @008b86ea-f4
//     if (!p) goto tail;
//     sp = dynamic_cast<QSplitter *>(p);                          // @008b86fe
//     if (!sp) goto tail;
//     if (sp->count() < 2) {                                      // @008b8712
//       kitA = kitWindowAncestor(this); kitB = kitWindowAncestor(this);
//       id = kitB->kitSlotIdOf(sp);                               // 008ca0b8
//       kitA->kitSlotHide(id);                                    // 008ca168
//       goto tail;
//     }
//   }
//   deleteLater();                                                // @008b8718
// tail: kit = kitWindowAncestor(this); if (kit) FUN_008cb0c0(kit,3);
void KitDockFace::closeWithCollapse()
{
	if (!m_f39) { // @008b86ea(+0x39 == 0)
		QWidget *p = parentWidget(); // @008b86f4
		if (p != nullptr) {
			if (auto *sp = dynamic_cast<QSplitter *>(p)) { // @008b86fe
				if (sp->count() < 2) {                     // @008b8712
					KitWindowFace *kit = kitWindowAncestor(this); // 008b8694
					if (kit != nullptr) {
						const int id = kit->kitSlotIdOf(sp); // 008ca0b8
						kit->kitSlotHide(id);                // 008ca168
					}
					// 尾刷新腿 FUN_008cb0c0(kit,3)@008b8738 — cited
					//   (24B 包装:008cad6a 门 + 008cb0a0 体未转写)
					return;
				}
			}
		}
	}
	deleteLater(); // @008b8718
	// 尾:kit = kitWindowAncestor(this) @008b8730;非空 →
	//   FUN_008cb0c0(kit,3)@008b8738 — cited(同上)。
}
