// ShellPaneFace.cpp — Shell/命令器面板。

#include "Widgets/Panes/ShellPaneFace.h"

// 出处:QMetaObject 0x011a6680(class="ShellPane",methods=2,signals=0,
// superdata=0x011ab900 KitPane);ctor 内联在调用点,仅转发基构造。
ShellPaneFace::ShellPaneFace(QWidget *parent)
    : KitPaneFace(parent)
{
}

// 0x0090bcd2(130B)dtor 真身:
//   vptr = &ShellPane_vtable;*(this+0x10) = &PTR_FUN_011a6630;
//   +0x58 QMap:引用计数归零 → QMapDataBase::freeTree(根) + freeData
//   vptr → &PTR_FUN_011ab6b8(KitPane);*(this+0x10) = &DAT_011ab8b0;
//   QWidget::~QWidget
// deleting 0x0090bb30(143B):同上 + operator_delete(this, 0x60)。
ShellPaneFace::~ShellPaneFace() = default;

// 槽体(0x0075xxxx 区,尚未转写):
int ShellPaneFace::addCommander(const QString &name)
{
	Q_UNUSED(name);
	return 0; // 0x007503a0(s_session_color_7503a0)—— 返回该会话的颜色值
}

int ShellPaneFace::commanderCount()
{
	return 0; // 0x0074ffde
}

// metasurface:metaObject 0x0090ba40 → &PTR_staticMetaObject_011a6680;
// qt_metacast 0x0090ba58(strcmp "ShellPane" → KitPane::qt_metacast);
// qt_metacall 0x0090bad2(93B):2 条记录转发到 0x0090ba9a。
