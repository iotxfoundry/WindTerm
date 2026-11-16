// ScanTaskFace.cpp — 扫描任务(非 QObject)。

#include "Utility/ScanTaskFace.h"

// 出处:RTTI "ScanTask";无 QMetaObject(非 QObject 派生)。
// 语料名 ScanTask_metaObject(0x0096d684,514B)实为析构体,见头注。
ScanTaskFace::ScanTaskFace() = default;

// 0x0096d684(514B)析构真身(逐段):
//   ① +0xa8 句柄对:**先 `scanner_resetState(句柄+8)` 再
//      `operator_delete(句柄+8, **0x40**)`,最后 `operator_delete(句柄,**0x18**)`
//      —— reset 必须在删除之前,否则扫描器内部状态先被释放会踩空;
//   ② +0x38 两级 QMap:节点 +0x18 QString / +0x20 QVariant,
//      子链 +0x08/+0x10 各再递归一层 → 最后 QMapDataBase::freeData;
//   ③ +0x30 引用计件归零 → operator_delete(_, 8)。
// deleting(语料名 ScanTask_qt_metacast,0x0096d886,23B):
//   + operator_delete(this, **0xb0**)。
ScanTaskFace::~ScanTaskFace() = default;
