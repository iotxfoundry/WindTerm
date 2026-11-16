// TriggerActionDialogFace.cpp — 触发器动作对话框(批 476)
#include "Actions/Dialogs/TriggerActionDialogFace.h"

// FUN_006ff1a0(647B)工厂型 ctor 真身
TriggerActionDialogFace::TriggerActionDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006ff1c9(new 0x48)
{
	// vtable TriggerActionDialog_vtable / 副 0118bef0(C++ 自洽)
	setWindowTitle(QStringLiteral("Action"));             // tr(0xc9fcf1)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);     // @006ff22c
	build();                                              // @FUN_006fe066(393B)
	body();                                               // @FUN_006f9f3c(1369B)
	// connect(finished → 闭包 impl FUN_0070331a)@006ff2xx — cited
}

// FUN_006fe066(393B)装配 — 结构段(cited)
void TriggerActionDialogFace::build() {}

// FUN_006f9f3c(1369B)遍历子件接线真身(结构段)
void TriggerActionDialogFace::body()
{
	if (m_body38 == nullptr)
		return;
	const QList<QWidget *> kids = m_body38->findChildren<QWidget *>(); // @006f9f96(递归=1)
	for (QWidget *w : kids) {
		if (w == nullptr)
			continue;
		// dynamic_cast 到 0x1198430(页类型);命中 → 逐项 connect — cited
		Q_UNUSED(w);
	}
}
