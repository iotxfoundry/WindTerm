// TransferLabelFace.cpp — 传输条进度标签。

#include "Widgets/Bars/TransferLabelFace.h"

// 出处:QMetaObject 0x01196540(methods=0 signals=0 **props=1**);
// ctor 内联在调用点。
TransferLabelFace::TransferLabelFace(QWidget *parent)
    : QFrame(parent)
{
}

// 0x008f193a(104B)dtor 真身:
//   vptr = &TransferLabel_vtable;*(this+0x10) = &PTR_FUN_011964e8;
//   +0x40 QBrush 析构 → +0x38 QBrush 析构(**先高后低**)
//   → +0x30 QString 引用计数递减 → QFrame::~QFrame
// deleting 0x008f1a88(110B):同上 + operator_delete(this, 0x88)。
TransferLabelFace::~TransferLabelFace() = default;

// 0x008f17d8(167B)属性桥真身:
//   op=1 index 0(读 progressColor)→ 从 *(this+0x38) 的私有区 +8 起
//        按 4 + 8 + 2 字节整体拷出(与 SlipButton 读 QBrush 的写法同形)
//   op=2 index 0(写)→ QBrush clone → 与 +0x38 交换 → 析构旧的
// 说明:这里的 "14 字节整体拷出" 与 SlipButton 的 metaDispatch 是同一段
//   模板(编译自同一个 moc 属性桥),可以互相当参照。
