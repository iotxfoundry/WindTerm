#include "Widgets/Controls/ListViewFace.h"

#include <QStyle>

// 四个被调按 §5 引用档锚入口(件类未建模 / 语义未复原):
static void *createDecoration(ListViewFace *) { return nullptr; }        // FUN_00a8ec9c
static void *createDelegate(ListViewFace *) { return nullptr; }          // FUN_00581260
static void attachDecoration(void *, void *) {}                          // FUN_00580f5e
static void setViewSpacing(ListViewFace *, int) {}                       // FUN_00583b8a

// FUN_00583bac(703B)ctor 真身。逐句:
//   QListView::QListView(this, parent) → vptr = ListView_vtable
//   → +0x10 = PTR_FUN_0119b6d8(第二 vptr)
//   → 字段初始化:+0x30 = 0 / +0x31 = owner / +0x32 u16 = 0x101 / +0x34 = 1 /
//     +0x38..+0x50 = 0 / +0x40 = QByteArray 空 / +0x60 = 0 / +0x68 = 0
//   → +0x70 = new 0xb0B(FUN_00a8ec9c(_, 4))
//   → +0x58 = new 0x98B(FUN_00581260(this));FUN_00580f5e(+0x58, +0x70)
//   → setItemDelegate(this 上的件)
//   → setIconSize(QSize(style()->pixelMetric(0x41), 同值))
//   → setResizeMode(1)/setUniformItemSizes(true)/setSelectionBehavior(1)
//   → FUN_00583b8a(this, 9)
//   → connect(clicked, activated → functor 00584670)(双信号同槽)
//   → owner != 0 时再建一个 0x50B 件(尾段,cited)
ListViewFace::ListViewFace(QWidget *parent, QListView *owner)
    : QListView(parent)
    , m_owner31(owner)
{
	m_f30 = nullptr;
	m_flags32 = 0x101;
	m_f34 = 1;
	m_f38 = nullptr;
	m_f40.clear();
	m_f48 = nullptr;
	m_f50 = nullptr;
	m_f60 = 0;
	m_f68 = nullptr;

	m_f70 = createDecoration(this); // FUN_00a8ec9c(_, 4),0xb0B — cited
	m_delegate58 = createDelegate(this); // FUN_00581260(this),0x98B — cited
	if (m_delegate58 != nullptr && m_f70 != nullptr)
		attachDecoration(m_delegate58, m_f70); // FUN_00580f5e — cited
	setItemDelegate(static_cast<QAbstractItemDelegate *>(m_delegate58));

	const int m = style()->pixelMetric(QStyle::PixelMetric(0x41)); // 字面 0x41
	setIconSize(QSize(m, m));
	setResizeMode(QListView::Adjust); // 1
	setUniformItemSizes(true);
	setSelectionBehavior(QAbstractItemView::SelectRows); // 1
	setViewSpacing(this, 9); // FUN_00583b8a(this, 9) — cited(语义未复原)
}

// ListView_dtor(0x00582c72,718B)— cited:释放 +0x58/+0x70 两件并拆接线。
ListViewFace::~ListViewFace() = default;
