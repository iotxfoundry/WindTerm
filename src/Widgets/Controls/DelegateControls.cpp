// DelegateControls.cpp — 委托/表格控件族(见头注对照表)。

#include "Widgets/Controls/DelegateControls.h"

// 出处:四者 metacall 均 5 字节纯转发;ctor 均内联在调用点,只转发基构造。

// dtor 0x008effd8(29B)真身:零字段;deleting 0x008f0016(47B)真身。
CheckEditorFace::CheckEditorFace(QWidget *parent) : QWidget(parent) { }
CheckEditorFace::~CheckEditorFace() = default;

// dtor 0x008f1d7a(66B)真身;deleting 0x008f1dbc(5B)真身(纯转发桩)。
EditDelegateFace::EditDelegateFace(QObject *parent) : QStyledItemDelegate(parent) { }
EditDelegateFace::~EditDelegateFace() = default;

// dtor 0x008f9846(36B)真身:唯一字段 **+0x10 QIcon**;
// deleting 0x008f986a(49B)真身。
TransferDelegateFace::TransferDelegateFace(QObject *parent) : QStyledItemDelegate(parent) { }
TransferDelegateFace::~TransferDelegateFace() = default;

// dtor 0x008f1662(86B)真身:唯一字段 **+0x38 QString**;
// deleting 0x008f154e(92B)真身。
TableWidgetFace::TableWidgetFace(QWidget *parent) : QTableWidget(parent) { }
TableWidgetFace::~TableWidgetFace() = default;
