// TriggerPageFace.cpp — 触发器页族共有面(批 341/342)
#include "TriggerPageFace.h"

#include <QHBoxLayout>
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
