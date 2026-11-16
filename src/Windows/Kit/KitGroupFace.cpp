// KitGroupFace.cpp — 分屏组窗口。

#include "Windows/Kit/KitGroupFace.h"

// 出处:QMetaObject 0x011ab360(methods=6 signals=4);ctor 内联在调用点。
KitGroupFace::KitGroupFace(QWidget *parent)
    : QMainWindow(parent)
{
}

// dtor 0x0091b128(86B)真身:唯一字段 +0x30 QString 减引用 →
// QMainWindow 析构;deleting 0x0091b074(92B)真身:+ operator_delete(_, 0x48)。
KitGroupFace::~KitGroupFace() = default;

// 槽体(0x0091abxx 区,尚未开批;按分发 0x0091aca2 的六路 switch 锚入口):
int KitGroupFace::viewCount() { return 0; }        // case 4
QString KitGroupFace::name() const { return m_f30; } // case 5

// metasurface:metaObject 0x0091aba0 → &PTR_staticMetaObject_011ab360;
// qt_metacast 0x0091af64;qt_metacall 0x0091afa6(109B):6 条记录 → 0x0091aca2。
