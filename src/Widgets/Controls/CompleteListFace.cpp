#include "Widgets/Controls/CompleteListFace.h"

// ctor — 语料未单独导出(由 HtmlList ctor 完成后仅换 vptr);
// 按基类构造承载,待取到完整 ctor 再补自有段。
CompleteListFace::CompleteListFace(QWidget *parent)
    : HtmlListFace(parent)
{
}

// CompleteList_dtor(0x00955042,29B)真身:
//   *(void**)this          = &HtmlList_vtable;     ← 基类 = HtmlList
//   *(void**)(this + 0x10)  = &PTR_FUN_01199510;   ← 第二 vptr
//   QListView::~QListView(this);
CompleteListFace::~CompleteListFace() = default;
