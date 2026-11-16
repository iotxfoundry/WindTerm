// SearchPaneFace.cpp — 搜索面板。

#include "Widgets/Panes/SearchPaneFace.h"

#include <QEvent>
#include <QLineEdit>

SearchPaneFace::SearchPaneFace(QWidget *parent)
    : KitPaneFace(parent)
{
}

// 0x0090b61c(258B)dtor 真身。逐句:
//   vptr = &SearchPane_vtable;*(this+0x10) = &PTR_FUN_011a6390;
//   遍历 [+0x130, +0x138) 的元素(**步长 24 字节**),每个元素首字段是引用
//   计数指针:计数减一,归零即销毁元素;
//   随后 operator_delete(容器起始指针);
//   +0x118 QString 引用计数递减;
//   +0x110 非空 → 走 vtable+8 析构;
//   vptr → &PTR_FUN_011ab6b8(KitPane 基 vtable);*(this+0x10) = &DAT_011ab8b0;
//   → QWidget::~QWidget
// deleting 0x0090b92e(271B):同上 + operator_delete(this, 0x148)。
SearchPaneFace::~SearchPaneFace() = default;

// vt5 0x0074cffe(61B)event 真身:
//   事件类型 == 8(KeyPress)时:QLineEdit::selectAll()(接收者为 +0x58 的
//   编辑框,实参折叠)+ setFocus(+0x58, 7 = Qt::OtherFocusReason);
//   之后无条件落父类事件处理(0x0091d424 区 = KitPane::event)。
bool SearchPaneFace::event(QEvent *event)
{
	if (event->type() == QEvent::KeyPress)
		setFocus(Qt::OtherFocusReason); // 语料:setFocus(+0x58, 7)
	return KitPaneFace::event(event);
}

// ───────── 槽体(按 §5 锚入口,0x0074xxxx 区未开批) ─────────
void SearchPaneFace::search1(int arg) { Q_UNUSED(arg); }                          // FUN_0074eecc
void SearchPaneFace::search3(int a, bool b, int c) { Q_UNUSED(a); Q_UNUSED(b); Q_UNUSED(c); } // FUN_0074e9cc
void SearchPaneFace::search2(int a, bool b) { Q_UNUSED(a); Q_UNUSED(b); }         // FUN_0074e9cc(...,0)
void SearchPaneFace::doSearch(bool a, const QString &b) { Q_UNUSED(a); Q_UNUSED(b); }    // FUN_0074e58e
void SearchPaneFace::setupSearch(bool a, const QString &b) { Q_UNUSED(a); Q_UNUSED(b); } // FUN_0074f5ac

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject → &staticMetaObject(0x011a63e0),superdata = 0x011ab900(KitPane)
// qt_metacast 0x0090b428(strcmp "SearchPane")
// qt_metacall 0x0090b5c0(91B):8 条记录(3 信号 + 5 槽)全部转发到
//   0x0090b4c6 的 switch;超出则返回 (index - 8)。
