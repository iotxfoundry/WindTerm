// TriggerDataFace.cpp — 单条触发器数据。

#include "Widgets/Settings/TriggerDataFace.h"

// 出处:RTTI "TriggerData";语料名 TriggerData_metaObject(0x00699b7a,151B)
// 实为析构体(首句写 &TriggerData_vtable);metacast 0x00699c12(23B)。
TriggerDataFace::TriggerDataFace() = default;

// 0x00699b7a(151B)析构真身(逐段见头注):
//   +0x10 QList<QJSValue*> 逐元素 atomic_refptr_delete(+8) +
//        QJSValue::~QJSValue + operator_delete(elem, 0x18)
//   +0x18 块 operator_delete(_, 0x34)
//   FUN_0069ea50(+0x10) 列表本体清理
//   qmap_freetree_variant_nodes(+0x8) —— QMap<QString,QVariant>
TriggerDataFace::~TriggerDataFace() = default;
