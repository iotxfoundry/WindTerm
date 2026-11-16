#pragma once

#include <QToolButton>

// HoverButtonFace — 带悬停图标的工具按钮(QToolButton 派生)。
// 出处:RTTI "HoverButton";dtor 0x0055cfe6(71B)/deleting 0x0055d034(23B);
// 清理腿 0x0055cf8c(90B);metaObject 0x008f0d6a / metacast 0x008f0d82 /
// metacall 0x008f0d32(5B = 空)。
// sizeof = 0x48(deleting 的 operator_delete(_,0x48))。
//
// 字段(dtor/清理腿实读,均为引用计数件):
//   +0x30 void*  引用计数对象(清理腿与 dtor 各减一次引用)
//   +0x38 void*  伴生指针(与 +0x30 同生同灭)
class HoverButtonFace : public QToolButton {
	Q_OBJECT

public:
	explicit HoverButtonFace(QWidget *parent = nullptr);
	~HoverButtonFace() override; // 0055cfe6

	// 0055cf8c(90B)—— 拆掉悬停件:两者皆在时 deleteLater + 置空 + 减引用。
	void clearHover();

private:
	void *m_hover30 = nullptr; // +0x30
	void *m_hover38 = nullptr; // +0x38
};
