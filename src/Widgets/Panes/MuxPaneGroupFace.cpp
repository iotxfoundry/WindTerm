// MuxPaneGroupFace.cpp — 分屏组。

#include "Widgets/Panes/MuxPaneGroupFace.h"

// 出处:QMetaObject 0x011ac040(class="MuxPaneGroup",methods=10,signals=0);
// ctor 内联在调用点,仅转发 QWidget 基构造。
MuxPaneGroupFace::MuxPaneGroupFace(QWidget *parent)
    : QWidget(parent)
{
}

// 0x0091e30e(29B)dtor 真身:
//   vptr = &MuxPaneGroup_vtable;*(this+0x10) = &PTR_FUN_011abfe8;
//   QWidget::~QWidget —— **零字段**(0x40 的尺寸全来自基类链)。
// deleting 0x0091e34c(47B):同上 + operator_delete(this, 0x40)。
MuxPaneGroupFace::~MuxPaneGroupFace() = default;

// 槽体(0x008dxxxx / 0x0091xxxx 区,尚未逐条转写):
void MuxPaneGroupFace::breakMuxPane() { }                       // 0x008de576
bool MuxPaneGroupFace::isMuxPaneZooming() { return false; }     // 0x008def36
void MuxPaneGroupFace::renameMuxPane(int id, const QString &name)
{ Q_UNUSED(id); Q_UNUSED(name); }                               // mux_renamePaneDialog
void MuxPaneGroupFace::renameMuxPane(int id) { Q_UNUSED(id); }
void MuxPaneGroupFace::renameMuxPane() { }
void MuxPaneGroupFace::resizeMuxPane(const QVariant &) { }       // cited
void MuxPaneGroupFace::selectMuxPane(const QVariant &) { }       // cited
void MuxPaneGroupFace::splitMuxPane(const QVariant &) { }        // cited
void MuxPaneGroupFace::swapMuxPane(const QVariant &) { }         // cited
void MuxPaneGroupFace::toggleMuxPaneZoom(const QVariant &) { }   // cited

// metasurface:metaObject 0x0091e100 → &PTR_staticMetaObject_011ac040;
// qt_metacast 0x0091e26e(strcmp "MuxPaneGroup" → QWidget::qt_metacast);
// qt_metacall 0x0091e2b0(93B):10 条记录转发到 0x0091e118;超出则 index - 10。
