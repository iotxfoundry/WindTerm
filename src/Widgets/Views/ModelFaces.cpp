// ModelFaces.cpp — 三个模型基座 + 自绘委托基座(见头注对照表)。

#include "Widgets/Views/ModelFaces.h"

// 出处:四者 QMetaObject 的 metacall 均 5 字节纯转发(methods 0 或 1);
// ctor 均内联在调用点,只转发基构造。
// 基类判定见头注(语料的 *_dtor 名字是 qt_metacast,末句调谁就是谁的基类)。

WidgetDelegateFace::WidgetDelegateFace(QObject *parent) : QStyledItemDelegate(parent) { }
WidgetDelegateFace::~WidgetDelegateFace() = default;

ListModelFace::ListModelFace(QObject *parent) : QAbstractListModel(parent) { }
ListModelFace::~ListModelFace() = default;

SortFilterProxyModelFace::SortFilterProxyModelFace(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}
SortFilterProxyModelFace::~SortFilterProxyModelFace() = default;

// 0x00663faa(39B)resetCursor 真身:
//   游标对 (+0x30, +0x38) 不等时把 +0x38 收回 +0x30;
//   +0x10 = **-1**(无效哨兵,不是 0)、+0x18 = 0、+0x20 = 0。
void SortFilterProxyModelFace::resetCursor()
{
	if (m_cursorBegin30 != m_cursorEnd38)
		m_cursorEnd38 = m_cursorBegin30;
	m_sentinel10 = -1;
	m_f18 = nullptr;
	m_f20 = nullptr;
}

HtmlListModelFace::HtmlListModelFace(QObject *parent) : QAbstractListModel(parent) { }
HtmlListModelFace::~HtmlListModelFace() = default;
