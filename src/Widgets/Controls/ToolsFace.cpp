// ToolsFace.cpp — 工具注册表。

#include "Widgets/Controls/ToolsFace.h"

// 出处:QMetaObject 0x0119f720(methods=2 signals=2 superdata=0);
// ctor 内联在调用点。
ToolsFace::ToolsFace(QObject *parent)
    : QObject(parent)
{
}

// 0x008fd7f8(36B)dtor 真身:
//   vptr = &Tools_vtable;清单清理腿(+0x10)(0x008fd6e0)→ QObject::~QObject
// deleting 0x008fd81c(49B):同上 + operator_delete(this, 0x18)。
//
// 0x008fd6e0(279B)清理腿:
//   对 +0x10 的 QList 逐元素(从尾向头):
//     元素的 +8 是侵入式计数块:强计数 --,归零时
//       ① vtable+0x10 若不是 FUN_00575d12 则调用它(析构体)
//       ② +0xc 弱计数 --,归零走 vtable+0x18 的释放器
//       ③ 最后 operator_delete(元素)
ToolsFace::~ToolsFace() = default;
