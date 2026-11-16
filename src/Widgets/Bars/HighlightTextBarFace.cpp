// HighlightTextBarFace.cpp — 高亮文本条。

#include "Widgets/Bars/HighlightTextBarFace.h"

#include <QEvent>
#include <QVariant>

// 出处:QMetaObject 0x011950a0(methods=1 signals=1 superdata=0);
// ctor 内联在调用点,仅转发 QWidget 基构造。
HighlightTextBarFace::HighlightTextBarFace(QWidget *parent)
    : QWidget(parent)
{
}

// 0x008f0c56(55B)dtor 真身:
//   vptr = &HighlightTextBar_vtable;*(this+0x10) = &PTR_FUN_01195048;
//   +0x40 QSharedDataPointer 减引用;
//   +0x30 子对象走 FUN_00556570(**不是** operator_delete —— 是值语义析构);
//   QWidget::~QWidget
// deleting 0x008f0d24(68B):同上 + operator_delete(this, 0x48)。
HighlightTextBarFace::~HighlightTextBarFace() = default;

// vt6 0x0055b83a(858B)event:该条的鼠标/绘制腿(858B)。
// 本批只锚入口,不转写 —— 它的体量与 HighlightTextBarAction 的
// createWidget 加起来才是完整交互,留到高亮功能开批时一起取。
bool HighlightTextBarFace::event(QEvent *event)
{
	return QWidget::event(event);
}

// metasurface:metaObject 0x008f0b20 → &PTR_staticMetaObject_011950a0;
// qt_metacast 0x008f0bb4(strcmp "HighlightTextBar" → QWidget::qt_metacast);
// qt_metacall 0x008f0bf6(95B):1 条记录转发到 0x008f0b38(bool + 宽实参);
//   超出则返回 (index - 1)。
