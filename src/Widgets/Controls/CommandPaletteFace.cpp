// CommandPaletteFace.cpp — 命令面板。

#include "Widgets/Controls/CommandPaletteFace.h"

#include <QEvent>

// 出处:QMetaObject 0x01197cc0(methods=0 signals=0);ctor 内联在调用点。
CommandPaletteFace::CommandPaletteFace(QWidget *parent)
    : QFrame(parent)
{
}

// dtor 0x0053fbfc(51B)真身:
//   vptr = &CommandPalette_vtable;*(this+0x10) = &PTR_FUN_01197c78;
//   +0x78 子对象走 FUN_005446d0 释放 → QFrame::~QFrame
// deleting 0x0053fc36(23B)真身:+ operator_delete(_, size)。
CommandPaletteFace::~CommandPaletteFace() = default;

// vt6 0x00540500(51B)真身:
//   仅当事件类型 == 0xe(Resize)时:
//     if (watched == FUN_0053ecae()) FUN_005401d6(this);
//   **两条路径都 return 0** ⇒ 永不吞事件,只做副作用(重排候选列表)。
bool CommandPaletteFace::eventFilter(QObject *watched, QEvent *event)
{
	Q_UNUSED(watched);
	if (event->type() != QEvent::Type(0xe))
		return false;
	// cited:FUN_0053ecae(取目标件)/ FUN_005401d6(重排)
	return false;
}
