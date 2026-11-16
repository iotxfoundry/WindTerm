// PlainTextEditPanelFace.cpp — 纯文本编辑面板。

#include "Widgets/Controls/PlainTextEditPanelFace.h"

#include <QEvent>
#include <QKeyEvent>

// 出处:QMetaObject 0x01195800(superdata=ButtonBarPanel);
// ctor 内联在调用点,仅转发基构造。
PlainTextEditPanelFace::PlainTextEditPanelFace(QWidget *parent)
    : ButtonBarPanelFace(parent)
{
}

// 0x006f82c6(88B)dtor 真身(语料名错标为 TriggerActionEditPanel):
//   vptr = &PlainTextEditPanel_vtable;*(this+0x10) = &PTR_FUN_011957a8;
//   +0x60 QString → +0x58 QString → +0x50 QSharedDataPointer 依次减引用;
//   vptr 落回 ButtonBarPanel_vtable;QFrame::~QFrame
// deleting 0x006f8b16(23B):+ operator_delete(this, 0x70)。
PlainTextEditPanelFace::~PlainTextEditPanelFace() = default;

// vt6 0x00533c18(130B)eventFilter 真身:
//   watched == +0x38 且 KeyPress 且 key == 0x1000007
//   → 0x005339d6(this, 2) 为真 → 0x005339ea(this, 2, event) 非 0
//   → 0x008ef7fc(this) + event->accept() 并返回真
//   否则落 QObject::eventFilter。
bool PlainTextEditPanelFace::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == parent() && event->type() == QEvent::KeyPress) {
		if (static_cast<QKeyEvent *>(event)->key() == 0x1000007) {
			// cited:0x005339d6 / 0x005339ea / 0x008ef7fc(第 2 号处理器转发)
			event->accept();
			return true;
		}
	}
	return QObject::eventFilter(watched, event);
}

// metasurface:metaObject 0x008f0fa0 → &PTR_PTR_01195800;
// qt_metacast(strcmp "PlainTextEditPanel" → ButtonBarPanel::qt_metacast);
// qt_metacall 0x008f10c2(93B):2 条记录转发到 0x008f105a;超出 index - 2。
