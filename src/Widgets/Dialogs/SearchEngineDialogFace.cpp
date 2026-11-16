// SearchEngineDialogFace.cpp — 搜索引擎配置对话框。

#include "Widgets/Dialogs/SearchEngineDialogFace.h"

// 出处:QMetaObject 0x011a4000(methods=0 signals=0 props=0 superdata=0);
// ctor 内联在调用点,仅转发 QDialog 基构造。
SearchEngineDialogFace::SearchEngineDialogFace(QWidget *parent)
    : QDialog(parent)
{
}

// 0x00905d5c(29B)dtor: vptr 复位 + QDialog::~QDialog(零字段)。
// deleting 0x00905d9a(47B): + operator_delete(_, 0x58)。
SearchEngineDialogFace::~SearchEngineDialogFace() = default;
