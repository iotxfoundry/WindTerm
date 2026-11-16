// KitPaneFace.cpp — 面板基类。

#include "Widgets/Panes/KitPaneFace.h"

KitPaneFace::KitPaneFace(QWidget *parent)
    : QWidget(parent)
{
}

KitPaneFace::~KitPaneFace() = default;

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject → &staticMetaObject(0x011ab900)
// qt_metacast 0x0091d3e2(strcmp "KitPane")
// qt_metacall 0x0091d38c(86B):两条记录
//   记录 0 → emit hideRequest()      (FUN_0091d368)
//   记录 1 → emit focusViewRequest() (FUN_0091d378)
//   记录 10 → 反查:args[1] == {&发射器, 0} 时把 0/1 写回 *args
