#pragma once

#include <QFrame>

#include "Widgets/Bars/ButtonBarPanelFace.h"

// TablePanels.h — 表格面板两级(TablePanel → TextMarkTablePanel)。
// 出处:QMetaObject 元数据(superdata 0x01193440 / 0x011d880);
// 两个 dtor 0x008f16d2 / 0x008f171a 真身。
//
// superdata 逐跳实读:
//   TablePanel        → 0x01193440 **ButtonBarPanel**
//   TextMarkTablePanel→ 0x011d880  **TablePanel**
//   ⇒ 三跳链:TextMarkTablePanel → TablePanel → ButtonBarPanel → QFrame
//
// | 类 | dtor | deleting | 自有字段 |
// |---|---|---|---|
// | TablePanel         | 0x008f16d2(66B)真身 | 0x008f1714(5B) | 有(见注) |
// | TextMarkTablePanel | 0x008f171a(29B)真身 | 0x008f1758(47B) | **零** |
//
// TextMarkTablePanel 的 dtor 29B 只复位 vptr 后落基类 ⇒ 它比 TablePanel
// 一个字段都不多,纯粹靠基类 + 装配腿区分。
//
// ⚠ TablePanel 的 dtor 66B 与 ButtonBarPanel 的 29B 差 37B ⇒ 它确实加了字段,
//   但字段类型未复原(66B 里含一次间接释放)。**按铁律 6 不落玄字段**,
//   只登记"有字段",等表格开批时回 asm 补。

// dtor 0x008f16d2 真身 —— superdata 0x01193440 ButtonBarPanel
class TablePanelFace : public ButtonBarPanelFace {
	Q_OBJECT
public:
	explicit TablePanelFace(QWidget *parent = nullptr);
	// 0x008f16d2 真身(66B,比基类多 37B ⇒ 有字段)
	~TablePanelFace() override;
};

// dtor 0x008f171a 真身 —— superdata 0x011d880 TablePanel
class TextMarkTablePanelFace : public TablePanelFace {
	Q_OBJECT
public:
	explicit TextMarkTablePanelFace(QWidget *parent = nullptr);
	// 0x008f171a 真身(29B ⇒ 零字段)
	~TextMarkTablePanelFace() override;
};
