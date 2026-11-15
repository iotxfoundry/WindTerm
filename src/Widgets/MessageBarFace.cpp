// MessageBarFace.cpp — 语料 MessageBar ctor 转写(批 244)
#include "MessageBarFace.h"

#include <QAbstractButton>

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
	// s_ExpandButton_5984be(this)+FUN_0059834c(this):
	//   前者 1021B 子件装配(两按钮 +0x38/+0x40)cited;
	//   后者(接线)本批真身。
	wireButtons();
}

// FUN_0059834c(369B,0018.c:12556)三路接线真身:
//   @0059834c connect(+0x40, clicked, this, FUN_005981c1);
//   @0059838x connect(+0x38, clicked, this, FUN_0059ced9);
//   @005983fx connect(this, destroyed, this, FUN_0059814a)。
//   槽体两市句实证:0x005981c1 emit(0x80,"") + close();
//   0x0059ced9 = s_king__expand_59c9e2(this, !(+0x50 bit1))(cited);
//   0x0059814a = 父链 MuxPane → FUN_00767b4a(cited)。
void MessageBarFace::wireButtons()
{
	if (m_f40 != nullptr) {
		connect(m_f40, &QAbstractButton::clicked, this, [this]() {
			emit messageSignal(0x80, QString()); // @005981fc(FUN_008f7e38)
			close();                            // @00598249
		});
	}
	if (m_f38 != nullptr) {
		connect(m_f38, &QAbstractButton::clicked, this, [this]() {
			/* FUN_0059ced9 → s_king__expand_59c9e2(this, !(+0x50>>1&1))
			   @0059ced9 — 体未转写,cited 不落 */
		});
	}
	connect(this, &QObject::destroyed, this, [this]() {
		/* FUN_0059814a:父链 cast MuxPane(011a69d0) → FUN_00767b4a(pane)
		   @0059814a — cited 不落 */
	});
}
