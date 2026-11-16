#include "Widgets/Controls/HtmlListFace.h"

#include <QAbstractItemDelegate>

// FUN_0057ec60(this)— cited:0x28B 自绘 delegate 构造(件类未建模)
static QAbstractItemDelegate *createDelegate(QWidget *parent)
{
	Q_UNUSED(parent);
	return nullptr;
}

// FUN_0058222a(131B)ctor 真身。逐句:
//   QListView::QListView(this, parent) → vptr = HtmlList_vtable
//   → +0x10 = PTR_FUN_01199510(第二 vptr)
//   → +0x30 = 0;+0x38 = -1
//   → setSelectionMode(1 = SingleSelection)
//   → FUN_00582220(this)(= setSelectionBehavior(1 = SelectRows),10B,同批实读)
//   → setUniformItemSizes(true)
//   → delegate = new 0x28B(FUN_0057ec60(this))→ setItemDelegate(delegate)
HtmlListFace::HtmlListFace(QWidget *parent)
    : QListView(parent) // QListView::QListView(this, parent)
{
	m_f30 = nullptr; // +0x30
	m_f38 = -1; // +0x38
	setSelectionMode(QAbstractItemView::SingleSelection); // 1
	setSelectionBehavior(QAbstractItemView::SelectRows); // FUN_00582220(1)
	setUniformItemSizes(true);
	setItemDelegate(createDelegate(this)); // FUN_0057ec60(0x28B 件)— cited
}

// HtmlList_dtor(0x008f754e,29B)— cited:
//   vptr = &HtmlList_vtable;*(this+0x10) = &PTR_FUN_01199510;QListView::~QListView
HtmlListFace::~HtmlListFace() = default;
