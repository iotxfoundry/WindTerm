// MessageBarFace.cpp — 语料 MessageBar ctor 转写(批 244)
#include "MessageBarFace.h"

// FUN_0059af30(262B,0018.c:14395)ctor:
//   @0059af30 QWidget(parent,0);vtable MessageBar;
//   @0059af5x +0x48 = 0;+0x50 &= 0xfc;+0x58 = shared_null;+0x60 = QListData 空;
//   @0059af9c objectName "MessageBar";
//   @0059afd9 setAttribute(0x5d,1);@0059afe? setAttribute(0x37,1)
//     (0x37 = WA_DeleteOnClose,与 TextMarkDialog 同值);
//   @0059affx setSizePolicy(0x5d0000)(与 FUN_005a2d26 状态栏 ctor **同一
//     立即数** — 双源;编码解码仍未取证,直录);
//   @0059b00x s_ExpandButton_5984be(this)+FUN_0059834c(this)
//     — 子件装配两腿未转写,cited 不落(铁律 6)。
MessageBarFace::MessageBarFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @0059af30
{
	setObjectName(QStringLiteral("MessageBar")); // @0059af9c
	setAttribute(static_cast<Qt::WidgetAttribute>(0x5d), true); // @0059afd9
	setAttribute(Qt::WA_DeleteOnClose, true);                   // 0x37 @0059afe?
	// setSizePolicy(QSizePolicy(0x5d0000))@0059affx — 立即数直录,编码面
	//   未解码(与状态栏 ctor 同常量;解码后统一替换)。
	// s_ExpandButton_5984be(this)/FUN_0059834c(this) — cited。
}
