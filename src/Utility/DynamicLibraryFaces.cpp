// DynamicLibraryFaces.cpp — 动态库抽象与其实现(见头注对照表)。

#include "Utility/DynamicLibraryFaces.h"

#include <QLibrary>

// 出处:两类的 vtable 均 5 槽,无 QObject 基(无 metaObject/metacast),
// 判据只能靠 vtable 形状(见 docs/ext-boundary.md 的 vtable@0x11ad170)。

DynamicLibraryImplFace::DynamicLibraryImplFace(const QString &fileName)
    : m_lib8(new QLibrary(fileName))
{
}

// 0x00944f50(46B)deleting 析构真身:
//   +0x8 非空 → QLibrary::unload() → operator_delete(this, **0x10**)
DynamicLibraryImplFace::~DynamicLibraryImplFace()
{
	unload();
}

// 0x00944f32(29B)真身:isLoaded 为假时**什么都不做**(不重复 unload)。
void DynamicLibraryImplFace::unload()
{
	if (m_lib8 != nullptr)
		m_lib8->unload();
}

// 0x00944f20(17B)真身:+0x8 非空 → QLibrary::resolve(symbol),否则返回 0。
void *DynamicLibraryImplFace::resolve(const char *symbol)
{
	if (m_lib8 == nullptr)
		return nullptr;
	return reinterpret_cast<void *>(m_lib8->resolve(symbol));
}

// 0x00944f16(9B)真身:**只看句柄是否非空**,不调 QLibrary::isLoaded()。
// 这条很重要 —— 语义是"我有没有库对象",不是"库是否已加载成功"。
bool DynamicLibraryImplFace::isLoaded() const
{
	return m_lib8 != nullptr;
}
