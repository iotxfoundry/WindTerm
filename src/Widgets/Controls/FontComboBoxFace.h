#pragma once

#include "Widgets/Controls/ComboBoxFace.h"

// FontComboBoxFace — 字体选择下拉框(ComboBox 派生,再补一件)。
//
// 出处:RTTI "FontComboBox";QMetaObject 0x01194ac0
// (rev=8,class="FontComboBox",methods=0,**superdata=0x0119bf60 = ComboBox**);
// sizeof = **0x50**(deleting 0x005568a4 的 operator_delete(_,0x50));
// dtor 0x0055682e(112B);metaObject = FontComboBox_vt0 0x008f091e(24B)。
//
// 字段:+0x48 一个 **8 字节独立块**(dtor 里 operator_delete(_, 8) 后置 0)
class FontComboBoxFace : public ComboBoxFace {
	Q_OBJECT

public:
	explicit FontComboBoxFace(QWidget *parent = nullptr);
	~FontComboBoxFace() override; // 0x0055682e

private:
	void *m_f48 = nullptr; // +0x48(8 字节独立块)
};
