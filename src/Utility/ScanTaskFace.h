#pragma once

#include <QMap>
#include <QVariant>

// ScanTaskFace — 扫描任务(**非 QObject**,持扫描器状态 + 一张 QMap)。
//
// 出处:RTTI "ScanTask";sizeof = **0xb0**
// (语料名 `ScanTask_qt_metacast` 0x0096d886 的 23B 函数实为 deleting 析构:
//  `operator_delete(param_1, 0xb0)`);
// 语料名 **`ScanTask_metaObject`(0x0096d684,514B)实为析构体** ——
//   首句写 `&ScanTask_vtable`,后面整段是字段释放。
// **本类无 QMetaObject**(非 QObject 派生),两个 moc 名字都是错挂。
//
// 字段(dtor 实读):
//   +0x30(param_1[6])—— 一个 8 字节的引用计件(计数归零 `operator_delete(_, 8)`)
//   +0x38(param_1[7])—— **QMap<QString, QVariant>**
//      (节点结构:节点 +0x18 是 QString、+0x20 是 QVariant;
//       且节点还有 +0x08/+0x10 两条子链 —— 说明是**两级 QMap 嵌套**:
//       一层 key → 一层 (key → QVariant));释放走 QMapDataBase::freeData
//   +0xa8(param_1[0x15])—— 扫描器句柄对:
//      `句柄 +0x8` 是真正的扫描器,**0x40 字节**,
//      释放前必须先 `scanner_resetState(扫描器)`;
//      外壳 `operator_delete(_, 0x18)`。
//      ⇒ **0x18 外壳 + 0x40 内核**,先 reset 再删,顺序不能反。
class ScanTaskFace {
public:
	ScanTaskFace();
	~ScanTaskFace(); // 0x0096d684(514B)

private:
	void *m_ref30 = nullptr;         // +0x30
	QMap<QString, QVariant> m_map38; // +0x38(两级嵌套)
	void *m_scannerA8 = nullptr;     // +0xa8(0x18 外壳,内含 0x40 扫描器)
};
