// CategoryTreeFace.cpp — 分类树。

#include "Widgets/Views/CategoryTreeFace.h"

#include <QEvent>
#include <QKeyEvent>

// 出处:RTTI "CategoryTree";ctor 内联在调用点。
CategoryTreeFace::CategoryTreeFace(QWidget *parent) : QTreeWidget(parent) { }

// dtor 0x006ec2e0(29B)真身:零自有字段;
// deleting 0x006ec31e(47B)真身:+ operator_delete(this, 0x78)。
CategoryTreeFace::~CategoryTreeFace() = default;

// vt6 0x0058cad2(437B)eventFilter 真身:
//   三连门(可见 && watched == **+0x48** && KeyPress)→ 落 vtable+0x298(moveCursor)。
//   键位来源件在 **+0x48**,而 ListWidget/ListView 是 +0x38 —— 偏移不同。
bool CategoryTreeFace::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == m_keySource48 && event->type() == QEvent::KeyPress) {
		// cited:vtable+0x298 = QAbstractItemView::moveCursor 转发
	}
	return QTreeWidget::eventFilter(watched, event);
}
