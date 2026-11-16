// MessageBarFace.cpp — 提示条。

#include "Widgets/Bars/MessageBarFace.h"

#include <QAbstractButton>

MessageBarFace::MessageBarFace(QWidget *parent)
    : QWidget(parent)
{
}

// 0x008f7fc8(95B)dtor 真身:
//   vptr = &MessageBar_vtable;*(this+0x10) = &PTR_FUN_0119a288;
//   qlist_unref_dispose3(this + 0x60)   ← 释放按钮表
//   +0x58 QString 引用计数递减
//   QWidget::~QWidget
// deleting 0x008f80fc(101B):同上 + operator_delete(this, 0x68)。
MessageBarFace::~MessageBarFace() = default;

// 0x008f7e38(56B)信号发射器真身:
//   QMetaObject::activate(this, &staticMetaObject(0x0119a2e0), 0,
//                         (int button, QString text))
// 即 `emit clicked(button, text)`。
//
// 0x008f7e70(175B)信号分发桥真身(两条 moc 记录共用):
//   记录 0 → emit clicked(button, text)        (args[1]=int, args[2]=QString)
//   记录 1 → emit clicked(button, QString())   (默认实参克隆:text 取空串
//             —— 语料 QString::fromAscii_helper("", 0))
//   记录 10 → 反查:args[1] == {&emitter, 0} 时把 0 写回 *args
// 说明:这两条是 moc 对「带默认实参信号」生成的标准双记录,不是两个信号。
