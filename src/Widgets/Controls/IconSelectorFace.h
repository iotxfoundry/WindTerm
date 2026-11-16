#pragma once

#include <QString>

#include "Widgets/Controls/SideButtonFace.h"

// IconSelectorFace — 图标选择按钮(SideButton 派生)。
//
// 出处:RTTI "IconSelector";QMetaObject 0x0119cf00
// (rev=8,class="IconSelector",methods=1,**signals=1**,
//  superdata=0x01198b20 = **SideButton**);
// sizeof = **0x48**(deleting 0x008fa75a 的 operator_delete(_,0x48));
// dtor 0x008fa8b8(103B)/deleting 0x008fa75a(116B)。
//
// 唯一条信号:`iconSelected(?)` 1 参。
//
// 字段(dtor 实读):+0x38 QString(图标名);dtor 里递减后把 vptr 落回
//   SideButton(PTR_FUN_01198898)再走 QPushButton 析构。
class IconSelectorFace : public SideButtonFace {
	Q_OBJECT

public:
	explicit IconSelectorFace(QWidget *parent = nullptr);
	~IconSelectorFace() override; // 0x008fa8b8

signals:
	void iconSelected(const QString &icon); // #0

private:
	QString m_f38; // +0x38
};
