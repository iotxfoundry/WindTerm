// TablePanels.cpp — 表格面板两级(见头注)。

#include "Widgets/Bars/TablePanels.h"

// 出处:两者 metacall 均 5 字节纯转发;ctor 均内联在调用点。

// dtor 0x008f16d2(66B)真身 —— 比基类 ButtonBarPanel 的 29B 多 37B,
// 说明 TablePanel 有自有字段(类型未复原,按铁律 6 不落玄字段);
// deleting 0x008f1714(5B)真身(纯转发桩,无 operator_delete —— 语料如此)。
TablePanelFace::TablePanelFace(QWidget *parent) : ButtonBarPanelFace(parent) { }
TablePanelFace::~TablePanelFace() = default;

// dtor 0x008f171a(29B)真身:**零自有字段**(只复位 vptr 后落基类);
// deleting 0x008f1758(47B)真身。
TextMarkTablePanelFace::TextMarkTablePanelFace(QWidget *parent) : TablePanelFace(parent) { }
TextMarkTablePanelFace::~TextMarkTablePanelFace() = default;
