// ListWidgetFace.cpp — 自定义键位列表件。

#include "Widgets/Controls/ListWidgetFace.h"

#include <QAbstractScrollArea>
#include <QKeyEvent>
#include <QScrollBar>
#include <QStringMatcher>

ListWidgetFace::ListWidgetFace(QWidget *parent)
    : QListWidget(parent)
{
}

// 0x0055e8ce(677B)dtor 真身(结构段):
//   vptr = &ListWidget_vtable;*(this+0x10) = &PTR_FUN_01199b80;
//   +0x40 结构逐块释放:
//     [+0x13]/[+0xf]/[+0xc]/[+0x9] 四块 operator_delete;
//     [+0x8] QList 里每个元素(0x418 字节 = QStringMatcher)
//        QStringMatcher::~QStringMatcher + operator_delete(_,0x418),
//        随后 QListData::dispose;
//     [+0x3] 处另一个 QListData::dispose;
//     +0x40 本体 operator_delete。
// 内部字段语义(四个裸块分别是什么)未复原 → 处在该层时回源码取证。
// deleting 0x0055eb7c(23B):同上 + operator_delete(this, 0x58)。
ListWidgetFace::~ListWidgetFace() = default;

// vt6 0x0055f314(347B)eventFilter 真身。逐句:
//   ① 竖直滚动条信号(watched == verticalScrollBar()):
//        RangeChanged(0x11) → thunk_FUN_0055f23a(this, 1)
//        ValueChanged(0x12) → thunk_FUN_0055f23a(this, 0)   ← 滚动条联动
//   ② 键盘腿三连门:本件可见(byte[+9]&0x80)&& watched == +0x38 && KeyPress(6)
//        key == 0x1000013 → moveCursor(MoveUp        = 0)
//        key == 0x1000015 → moveCursor(MoveDown      = 1)
//        key == 0x1000016 → moveCursor(MovePageUp    = 6)
//        key == 0x1000017 → moveCursor(MovePageDown  = 7)
//        随后 setCurrentIndex(moveCursor 的返回)
//        key ∈ {0x1000004, 0x1000005} → emit activated(currentIndex())
//        (语料:`1 < key + 0xfefffffc` 的区间判定 = 0x1000004..0x1000005)
//        命中者一律 event->accept()(+0x12 |= 4)并 return true(吞键)
//   ③ 其余落 QAbstractItemView::eventFilter。
bool ListWidgetFace::eventFilter(QObject *watched, QEvent *event)
{
	// ① 滚动条联动
	if (m_keySource38 != nullptr && watched == verticalScrollBar()) {
		if (event->type() == QEvent::Type(0x11)) { // RangeChanged
			QMetaObject::invokeMethod(this, [this]() { /* 0055f23a(this,1) cited */ });
		} else if (event->type() == QEvent::Type(0x12)) { // ValueChanged
			QMetaObject::invokeMethod(this, [this]() { /* 0055f23a(this,0) cited */ });
		}
	}

	// ② 键盘腿
	if (watched == m_keySource38 && event->type() == QEvent::KeyPress) {
		const int key = static_cast<QKeyEvent *>(event)->key();
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
	}

	return QAbstractItemView::eventFilter(watched, event);
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject → &staticMetaObject(0x01199bc0)
// qt_metacast 0x008f774c(strcmp "ListWidget" → QListWidget::qt_metacast)
// qt_metacall 0x008f778e(87B):单条记录(信号 itemsRemoved)转发到 0x008f7708。
