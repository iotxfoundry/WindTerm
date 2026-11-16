// ThinControls.cpp — 六个薄类(见头注对照表)。

#include "Widgets/Controls/ThinControls.h"

// 出处:六者 QMetaObject 的 metacall 均为 5 字节纯转发(0 条自有记录),
// metaObject 均为 24B;ctor 均内联在调用点,只转发基构造。

// dtor 0x008eff9e(19B)真身:只有 QStyledItemDelegate::~QStyledItemDelegate
// —— 零字段;deleting 0x008effb2(37B):+ operator_delete(_, size)。
// 另有两虚面:vt12 0x005d56b0(62B,绘制)、vt14 0x005d56a4(12B,
// 转调 vtable+0xc0)。
CheckDelegateFace::CheckDelegateFace(QObject *parent) : QStyledItemDelegate(parent) { }
CheckDelegateFace::~CheckDelegateFace() = default;

// dtor 0x008f1182(46B)真身:vptr 复位 → **+0x68 QSharedDataPointer** 减引用
// → QWidget::~QWidget;deleting 0x008f11e0(59B):+ operator_delete(_, size)。
QuickBarFace::QuickBarFace(QWidget *parent) : QWidget(parent) { }
QuickBarFace::~QuickBarFace() = default;

// dtor 0x0090ece4(19B)真身:只有 QObject::~QObject —— 零字段。
// deleting 0x0090ecf8(37B):+ operator_delete(_, size)。
TerminalKeyboardFace::TerminalKeyboardFace(QObject *parent) : QObject(parent) { }
TerminalKeyboardFace::~TerminalKeyboardFace() = default;

// dtor 0x006744f4(67B)真身:
//   +0x18 QRegularExpression 析构 →
//   +0x10 原子计数 qatomic_int_deref,归零走 0x006744ae →
//   QObject::~QObject
// ⇒ **+0x10 是原子引用计件、+0x18 是正则** —— 键位映射表本体。
// deleting 0x00674538(23B):+ operator_delete(_, size)。
SuperKeymapFace::SuperKeymapFace(QObject *parent) : QObject(parent) { }
SuperKeymapFace::~SuperKeymapFace() = default;
