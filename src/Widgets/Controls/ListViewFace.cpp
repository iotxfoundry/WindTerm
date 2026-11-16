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

// ───────── 补充(2026-11-16):元接口与两个虚面 ─────────
// 出处:QMetaObject 0x0119b720(rev=8,methods=3 signals=2 props=1)。

// vt6 0x005843b0(461B)eventFilter —— 与 ListWidgetFace 的 eventFilter 同构,
// 但多一支 Ctrl+数字 的处理:
//   ① 三连门:本件可见(byte[+9]&0x80)&& watched == +0x38 && KeyPress(6);
//   ② 0x1000013/0x1000015/0x1000016/0x1000017
//      → moveCursor(0/1/6/7)→ setCurrentIndex;
//      0x1000004/0x1000005 → emit activated(currentIndex());
//   ③ **ListWidget 没有的一支**:modifiers == ControlModifier(0x8000000)
//      且 (key - 0x31) >= 0 且 +0x30 非空 → 走 model 的快捷选择(数字键选行)。
bool ListViewFace::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == m_f38 && event->type() == QEvent::KeyPress) {
		auto *ke = static_cast<QKeyEvent *>(event);
		const int key = ke->key();
		int action = -1;
		switch (key) {
		case 0x1000013: action = 0; break; // MoveUp
		case 0x1000015: action = 1; break; // MoveDown
		case 0x1000016: action = 6; break; // MovePageUp
		case 0x1000017: action = 7; break; // MovePageDown
		default: break;
		}
		if (action >= 0) {
			setCurrentIndex(moveCursor(QAbstractItemView::CursorAction(action), Qt::NoModifier));
			event->accept();
			return true;
		}
		if (key == 0x1000004 || key == 0x1000005) {
			emit activated(currentIndex());
			event->accept();
			return true;
		}
		if (m_f30 != nullptr && ke->modifiers() == Qt::ControlModifier && (key - 0x31) >= 0) {
			// cited:走 model 的数字键快捷选择(+0x30 为选择器件)
		}
	}
	return QListView::eventFilter(watched, event);
}

// vt14 0x00583ace(157B)sizeHint:
//   model 为空 → 返回 **-1**(语料 0xffffffffffffffff,即无效 QSize)
//   否则:单行高 h = moveCursor(0) 的返回(vtable+0x1f0);
//        rows = model 的 rowCount(vtable+0x78,以全无效 index 为父);
//        rows = min(rows, *(int*)(this+0x60));
//        fw = QFrame::frameWidth();
//        宽 = rows * h + fw * 2;高 = (viewport bottom - top) + 1
QSize ListViewFace::sizeHint() const
{
	if (model() == nullptr)
		return QSize(-1, -1);

	const int rowH = moveCursor(QAbstractItemView::MoveUp, Qt::NoModifier).row(); // 语料 vtable+0x1f0
	int rows = model()->rowCount();
	if (m_f60 <= rows)
		rows = m_f60;
	const int fw = frameWidth();
	return QSize(rows * rowH + fw * 2, viewport()->height() + 1);
}

void ListViewFace::updateFilterString(const QString &text)
{
	Q_UNUSED(text); // 0x008f8d2e(150B)分发;本体待该区开批
}

// metasurface:metaObject 0x008f8cd0(24B)→ &PTR_staticMetaObject_0119b720;
// qt_metacast 0x008f8dc4(strcmp "ListView" → QListView::qt_metacast);
// qt_metacall 0x008f8e06(177B):3 条记录转发到 0x008f8d2e,
//   4..8 与 1..3 / 0xb 也走同一条桥(属性面)。
