#pragma once

#include <QComboBox>

// ComboBoxFace — 带侧按钮的下拉框(QComboBox 派生)。
//
// 出处:RTTI "ComboBox";QMetaObject 0x0119bf60
// (rev=8,class="ComboBox",methods=2,**signals=2**,props=0,superdata=0);
// metacast 0x008f961e(strcmp "ComboBox" → QComboBox);
// FontComboBox 的 metacast 0x008f0936 先比 "FontComboBox" 再落这里。
//
// 两条信号(串表实读):
//   #0 returnPressed()      —— 回车
//   #1 sideButtonTriggered() —— 右侧按钮
//
// 字段(dtor 实读):+0x30 引用计数件(计数减一,归零 operator_delete)
class ComboBoxFace : public QComboBox {
	Q_OBJECT

public:
	explicit ComboBoxFace(QWidget *parent = nullptr);
	~ComboBoxFace() override;

signals:
	void returnPressed();      // #0
	void sideButtonTriggered(); // #1

protected:
	void *m_ref30 = nullptr; // +0x30
};
