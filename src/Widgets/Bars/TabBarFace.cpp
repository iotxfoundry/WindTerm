// TabBarFace.cpp — 终端标签栏。

#include "Widgets/Bars/TabBarFace.h"

#include <QEvent>

static void refreshTabGeometry(TabBarFace *self);      // 0x005a6b1c
static void onIndexChanged(TabBarFace *self);          // 0x005a81c6
static void setCloseOnly(TabBarFace *self, bool on);   // 0x005a84f6

TabBarFace::TabBarFace(QWidget *parent)
    : QTabBar(parent)
{
}

// 0x008f68fc(113B)dtor 真身。逐句:
//   vptr = &TabBar_vtable;*(this+0x10) = &PTR_FUN_01197ef0;
//   freeList(+0x70)(0x008f67fc,含元素内 8 字节引用计数件)
//   qt_shared_data_unref(+0x68)
//   freeList(+0x60)(0x008f67a0,元素 0x10 字节直接删)
//   +0x38 QString 引用计数递减
//   QTabBar::~QTabBar
// deleting 0x008f6a66(119B):同上 + operator_delete(this, 0x80)。
TabBarFace::~TabBarFace() = default;

// vt5 0x005a8aa0(141B)event 真身 —— **按事件类型白名单**触发两种动作:
//
//   类型 ∈ {0x04, 0x0d, 0x3d, 0x7b, 0x7f, 0x80, 0x81}
//        → refreshTabGeometry(this)(0x005a6b1c),然后落 QTabBar::event
//   类型 == 0x64
//        → onIndexChanged(this)(0x005a81c6),然后落 QTabBar::event
//   其余 → 只落 QTabBar::event
//
// 语料这套判定写成嵌套区间比较(<0x70 / <0x6e / !=0xd / <0xe / (u16)(t-0x7f)>2),
// 展开后正是上面两个集合;类型值按字面保留,不硬套 QEvent::Type 名字
// (版本表差,套名字容易套错)。
bool TabBarFace::event(QEvent *event)
{
	switch (int(event->type())) {
	case 0x04: // MouseButtonPress
	case 0x0d: // Move
	case 0x3d:
	case 0x7b:
	case 0x7f:
	case 0x80:
	case 0x81:
		refreshTabGeometry(this);
		break;
	case 0x64:
		onIndexChanged(this);
		break;
	default:
		break;
	}
	return QTabBar::event(event);
}

// 0x008f6618(153B)属性桥真身。逐句:
//   读 index 0 → *(u64*)(this+0x44)                    (highlightTopLeft)
//   读 index 1 → *(u64*)(this+0x4c)                    (highlightBottomRight)
//   读 index 2 → *(u8*)(this+0x30)                     (bool)
//   写 index 0 → 两个 32 位分量落 +0x44/+0x48
//   写 index 1 → **反序**:v[1] → +0x4c,v[0] → +0x50   (语料如此,保留)
//   写 index 2 → setCloseOnly(this, v)(0x005a84f6)
//   op=10 反查发射器 → 写回 0。
void TabBarFace::metaDispatch(int op, int index, void **args)
{
	if (args == nullptr)
		return;

	if (op == 1) {
		if (index == 0)
			*reinterpret_cast<QSize *>(args) = m_topLeft44;
		else if (index == 1)
			*reinterpret_cast<QSize *>(args) = m_bottomRight4c;
		else if (index == 2)
			*reinterpret_cast<bool *>(args) = m_closeOnly30;
		return;
	}
	if (op == 2) {
		auto *v = static_cast<int *>(*reinterpret_cast<void **>(args));
		if (index == 0)
			m_topLeft44 = QSize(v[0], v[1]);
		else if (index == 1)
			m_bottomRight4c = QSize(v[1], v[0]); // 语料:反序
		else if (index == 2)
			setCloseOnly(this, *reinterpret_cast<bool *>(v));
	}
}

static void refreshTabGeometry(TabBarFace *) { }
static void onIndexChanged(TabBarFace *) { }
static void setCloseOnly(TabBarFace *, bool) { }
