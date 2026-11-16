#pragma once

#include <QWidget>

// PlaySoundWidgetFace — 播放提示音的设置控件(QWidget 派生,**零字段**)。
//
// 出处:RTTI "PlaySoundWidget";QMetaObject 0x011a1fc0
// (**methods=0 / signals=0 / props=0**);
// dtor 0x00904c4a(29B)/deleting 0x00904c88(47B) —— 只有 vptr 复位 +
// QWidget 析构 ⇒ **零自有字段**;
// metacast 0x00904b1a / metacall 0x00904b5c(5B,纯转发)。
class PlaySoundWidgetFace : public QWidget {
	Q_OBJECT
public:
	explicit PlaySoundWidgetFace(QWidget *parent = nullptr);
	~PlaySoundWidgetFace() override; // 0x00904c4a
};
