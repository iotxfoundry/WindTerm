#pragma once

#include <QPushButton>

// SwitchButtonFace — 可切换图标按钮(QPushButton 派生)。
// 出处:RTTI "SwitchButton";dtor 0x008f73c4(29B)/deleting 0x008f7402(47B);
// event 虚面 vt5 = 0x005b33e0(270B);metaObject 0x008f7364 /
// metacast 0x008f737c / metacall 0x008f73be(5B = 空)。
//
// 与 SideButtonFace 的 event **逐句同构**(同 270B),唯一差异是图标落点
// 走 0x005b31f0 而非 QAbstractButton::setIcon。两者是兄弟类,不是派生。
class SwitchButtonFace : public QPushButton {
	Q_OBJECT

public:
	explicit SwitchButtonFace(QWidget *parent = nullptr);
	~SwitchButtonFace() override; // 008f73c4

protected:
	bool event(QEvent *event) override; // vt5 005b33e0
};
