#pragma once

#include <QJSValue>
#include <QMap>
#include <QVariant>

// TriggerDataFace — 单条触发器数据(sizeof 0x18)。
//
// 出处:RTTI "TriggerData";语料名 `TriggerData_metaObject`(0x00699b7a,151B)
// **实为析构体** —— 判据:首句写 `&TriggerData_vtable`,后面整段是字段释放。
// metacast 0x00699c12(23B)。
//
// 析构逐段(信息量很大,一条就够还原结构):
//   ① `param_1[2]`(+0x10)是 **QList<QJSValue*>`**:逐元素
//      `atomic_refptr_delete(elem + 8)` → `QJSValue::~QJSValue(elem)`
//      → `operator_delete(elem, **0x18**)`
//      ⇒ **每个元素 0x18 字节**,且内部还带一个原子引用计件;
//   ② `param_1[3]`(+0x18)是一块 **0x34 字节**的独立数据;
//   ③ `FUN_0069ea50(param_1 + 2)` —— 列表本体清理;
//   ④ `qmap_freetree_variant_nodes(param_1 + 1)` —— **+0x8 是
//      QMap<QString, QVariant>**(节点带 variant,释放走专门的名字)。
//
// ⚠ 尺寸对不上:dtor 里用到 +0x18 且是 0x34 的块,但 **TriggerData 本体
//   只有 0x18**(0x8 QMap + 0x10 QList + 0x18 尾)——说明 +0x18 处是
//   **指向 0x34 块的指针**,不是内嵌块。语料里 `param_1[3]` 是第 4 个
//   qword,即 +0x18,正好是尾部。按"指针 + 单独 alloc(0x34)"理解才自洽。
class TriggerDataFace {
public:
	TriggerDataFace();
	~TriggerDataFace(); // 0x00699b7a

private:
	QMap<QString, QVariant> m_vars8; // +0x8
	void *m_list10 = nullptr;        // +0x10 QList<QJSValue*>
	void *m_block18 = nullptr;       // +0x18 指向 0x34 字节块
};
