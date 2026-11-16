#pragma once

#include <QString>

class QLibrary;

// DynamicLibraryFaces.h — 动态库抽象 + 其唯一实现(纯 C++,非 QObject)。
//
// **这一族没有 QObject 基**:vtable 只有 5 槽
// `{typeinfo, unload, deleting-dtor, resolve, isLoaded}`
// (docs/ext-boundary.md 已记 vtable@0x11ad170),没有 metaObject/metacast,
// 所以 `qmo_class.py` 在这里完全不适用 —— 判据只能靠 vtable 形状。
//
// | 类 | 角色 | 出处(真身) |
// |---|---|---|
// | DynamicLibrary      | 抽象接口 | vt13 0x00943a4e(103B) / vt14 0x00943ab6(191B) / vt15 0x009441cc(245B) |
// |                     |          | dtor 0x009433b6(23B) / deleting 0x00943748(52B) / h9433a2 0x009433a2(19B) |
// | DynamicLibraryImpl  | 唯一实现 | isLoaded 0x00944f16(9B) / unload+dtor 0x00944f32(29B) |
// |                     |          | resolve 0x00944f20(17B) / deleting 0x00944f50(46B) |
// |                     |          | vt12 0x0094f30c(1B) / vt13 0x0094f32a(10B) |
// |                     |          | vt14 0x0094f34c(39B) / vt15 0x0094f334(10B) |
//
// 两个类的 sizeof:**DynamicLibraryImpl = 0x10**(deleting 的
// operator_delete(_, 0x10)),内含 **+0x8 QLibrary*** 一个字段。
//
// 行为逐条(全部实读):
//   · `isLoaded()` = `*(long*)(this + 8) != 0` —— 只看句柄是否非空;
//   · `unload()`   = +0x8 非空则 `QLibrary::unload()`;
//   · `resolve()`  = +0x8 非空则 `QLibrary::resolve()`,否则 0;
//   · 析构         = unload 后 `operator_delete(this, 0x10)`;
//   · vt13/vt15 各 10B,都是 `operator_delete(_, 0x18)` —— **0x18 的件**,
//     不是本类自身(本类 0x10),说明它们释放的是**内嵌的辅助件**;
//   · vt14 39B:+0x10 处另一件,先删其首字段再 `operator_delete(件, 0x18)`。
//
// ⚠ docs/ext-boundary.md 记过"五重扫描零调用者 ⇒ 机制存在未激活"。
//   本批落了接口面,但**没有发现任何创建点**,该结论仍成立 ——
//   不要因为"类已建模"就以为它被用到了。

// 抽象接口:5 槽 vtable,纯虚的语义由 Impl 承接。
class DynamicLibraryFace {
public:
	DynamicLibraryFace() = default;
	virtual ~DynamicLibraryFace() = default;              // 0x009433b6
	virtual void unload() = 0;                            // vt13 0x00943a4e
	virtual void *resolve(const char *symbol) = 0;        // vt14 0x00943ab6
	virtual bool isLoaded() const = 0;                     // vt15 0x009441cc
};

// 唯一实现:持一个 QLibrary*。
class DynamicLibraryImplFace : public DynamicLibraryFace {
public:
	explicit DynamicLibraryImplFace(const QString &fileName);
	~DynamicLibraryImplFace() override; // 0x00944f50(deleting)

	void unload() override;                       // 0x00944f32
	void *resolve(const char *symbol) override;   // 0x00944f20
	bool isLoaded() const override;                // 0x00944f16

private:
	QLibrary *m_lib8 = nullptr; // +0x8
};
