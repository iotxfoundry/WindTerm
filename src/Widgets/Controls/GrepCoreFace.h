#pragma once

#include <QHash>
#include <QString>

#include <string>

// GrepCoreFace — 查找核心(**非 QObject**,纯 C++ 类)。
//
// 出处:RTTI "Grep";sizeof = **0x68**
// (语料名 `Grep_qt_metacast` 0x00899d14 的 23B 函数实为 deleting 析构:
//  `operator_delete(param_1, 0x68)`);
// 语料名 **`Grep_metaObject`(0x00899ab4,608B)实为析构体** ——
//   首句写 `&Grep_vtable`,后面整段是字段释放。
// 成员清理腿 0x008998f6(445B)。
//
// **本类没有 QMetaObject**(它不派生 QObject),所以:
//   · `qt_metacast` / `qt_metacall` 这两个名字是错挂;
//   · 判据只能靠 dtor 的字段释放 + vtable 形状。
//
// 字段(dtor 实读,按出现频次排序):
//   +0x08 / +0x10 / +0x18 / +0x20 / +0x28 —— 五个**引用计数/数组件**
//      (dtor 里各出现 3 次:判空 → 减引用 → 归零释放)
//   +0x48 / +0x50 —— 两个 **QHash**(各走一次 QHashData::free_helper,
//      且 dtor 里 +0x58/+0x60 各出现两次 —— 两个哈希各带一层次级)
//   +0x50 起还夹着一个 **std::string**:
//      dtor 里与 `std::string::_Rep::_S_empty_rep_storage` 比较,
//      这是 libstdc++ COW 字符串的标准判空法。
//
// ⚠ **vt8 0x0089c1d0(53B)不是业务函数**:它拿 typeid 名与
//   `"St19_Sp_make_shared_tag"` 比对后返回 `this + 0x10` ——
//   这是 libstdc++ `std::__shared_ptr` 的 aliasing 构造函数,
//   本会话第二次遇到(CGlobalConfig 也有一个同样的)。
//   **看到 `St19_Sp_make_shared_tag` 就停手,那是库模板。**
//
// 成员清理腿 0x008998f6(445B):遍历一个 QHash 的节点,
//   每节点释放 +0x18 处的件与其 +0x10 的字符串 —— 即"正则→计数"表。
class GrepCoreFace {
public:
	GrepCoreFace();
	~GrepCoreFace(); // 0x00899ab4(608B)

private:
	void clearNodes(); // 0x008998f6(445B)

	void *m_ref08 = nullptr; // +0x08
	void *m_ref10 = nullptr; // +0x10
	void *m_ref18 = nullptr; // +0x18
	void *m_ref20 = nullptr; // +0x20
	void *m_ref28 = nullptr; // +0x28
	QHash<QString, void *> m_hash48; // +0x48
	std::string m_text50;            // +0x50
	QHash<QString, void *> m_hash58; // +0x58
	void *m_f60 = nullptr;           // +0x60
};
