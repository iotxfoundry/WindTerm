// ExplorerPaneFace.cpp — 文件浏览器面板。

#include "Widgets/Panes/ExplorerPaneFace.h"

#include <QEvent>

// 出处:QMetaObject 0x011a5180(methods=0 signals=0,superdata=KitPane);
// ctor 内联在调用点。
ExplorerPaneFace::ExplorerPaneFace(QWidget *parent)
    : KitPaneFace(parent)
{
}

// dtor 0x00909b84(29B)真身:零自有字段(vptr 落回 KitPane 的
// PTR_FUN_011ab6b8 后 QWidget 析构);
// deleting 0x00909bc2(47B)真身:+ operator_delete(this, 0x58)。
ExplorerPaneFace::~ExplorerPaneFace() = default;

// vt6 0x008c4446(**1827B**)eventFilter:整块未转写,只锚入口。
// 同一族的 vt5(61B)/ vt13(45B)也一并留到浏览器开批 ——
// 三者合起来才是完整的交互面,单拆任一块都没有可验证的落点。
bool ExplorerPaneFace::eventFilter(QObject *watched, QEvent *event)
{
	return KitPaneFace::eventFilter(watched, event);
}
