#pragma once

#include <QPushButton>

// SideButtonFace — 侧栏图标按钮(QPushButton 派生,事件驱动换图标)。
// 出处:RTTI "SideButton";dtor 0x008f7188(29B)/deleting 0x008f71c6(47B);
// event 虚面 vt5 = 0x0058eb86(270B);metaObject 0x008f7026 /
// metacast 0x008f7058 / metacall 0x008f709a(5B = 空)。
class SideButtonFace : public QPushButton {
	Q_OBJECT

public:
	explicit SideButtonFace(QWidget *parent = nullptr);
	~SideButtonFace() override; // 008f7188

protected:
	bool event(QEvent *event) override; // vt5 0058eb86
};
