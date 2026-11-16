#pragma once

#include <QFrame>

#include "Widgets/Bars/ButtonBarPanelFace.h"

// TablePanels.h — 表格面板两级(TablePanel → TextMarkTablePanel)。
//
// superdata 逐跳实读:
//   TablePanel        → 0x01193440 **ButtonBarPanel**
//   TextMarkTablePanel→ 0x011d880  **TablePanel**
//   ⇒ 三跳链:TextMarkTablePanel → TablePanel → ButtonBarPanel → QFrame
//
// | 类 | dtor | deleting | 自有字段 |
// |---|---|---|---|
// | TablePanel         | 0x008f16d2(66B) | 0x008f1714(5B) | 有(见注) |
// | TextMarkTablePanel | 0x008f171a(29B) | 0x008f1758(47B) | **零** |
//
// TextMarkTablePanel 的 dtor 29B 只复位 vptr 后落基类 ⇒ 它比 TablePanel
// 一个字段都不多,纯粹靠基类 + 装配腿区分。
//
// ⚠ TablePanel 的 dtor 66B 与 ButtonBarPanel 的 29B 差 37B ⇒ 它确实加了字段,
//   但字段类型未复原(66B 里含一次间接释放)。**按铁律 6 不落玄字段**,
//   只登记"有字段",等表格开批时回 asm 补。

class TablePanelFace : public ButtonBarPanelFace {
	Q_OBJECT
public:
	explicit TablePanelFace(QWidget *parent = nullptr);
	~TablePanelFace() override; // 0x008f16d2
};

class TextMarkTablePanelFace : public TablePanelFace {
	Q_OBJECT
public:
	explicit TextMarkTablePanelFace(QWidget *parent = nullptr);
	~TextMarkTablePanelFace() override; // 0x008f171a
};
