#include "Widgets/Controls/CompleteListFace.h"

// ctor — 语料未单独导出(构造由父链 ListView→HtmlList 逐级完成);
// 暂以 QListView(parent) 承载,待 ListView 建模后改为委托其 ctor。
CompleteListFace::CompleteListFace(QWidget *parent)
    : QListView(parent)
{
}

// CompleteList_dtor(0x00955042,29B)真身:
//   *(void**)this        = &HtmlList_vtable;      ← 基类 = HtmlList
//   *(void**)(this + 0x10) = &PTR_FUN_01199510;   ← 第二 vptr
//   QListView::~QListView(this);
CompleteListFace::~CompleteListFace() = default;
