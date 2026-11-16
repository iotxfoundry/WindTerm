// SlipButtonFace.cpp — SlipButton 菜单行构建(批 338)
#include "Actions/SlipButtonFace.h"

#include <QLabel>
#include <QMenu>
#include <QWidgetAction>

// slipButton_makeMenu(1023B,0021.c:40319)真身(结构段):
//   @006af0f5 QMenu(0x30);
//   @006af144 tr(0xc9d3fb) → @006af152 QWidgetAction(0x30)+vtable
//     SlipButtonAction → +0x18 QLabel(0x30) → +0x20 overlay_makeBusyWidget
//     (0xa0) → +0x28 QWidget(0x30) → QLabel::setBuddy(+0x18)。
//   addAction/connect/弹出余段 cited。
QMenu *SlipButtonFace::makeMenu(QWidget *parent)
{
	auto *menu = new QMenu(parent); // @006af0f5(0x30)
	auto *row = new QWidgetAction(menu); // @006af152(0x30)
	auto *label = new QLabel(row);       // +0x18(0x30)
	// +0x20 = overlay_makeBusyWidget(0xa0) — cited(遮罩件未建模)
	// +0x28 = QWidget(0x30) — 行容器(cited)
	row->setDefaultWidget(label);        // QLabel::setBuddy(+0x18) 同相面
	menu->addAction(row);                // addAction(cited 序)
	return menu;
}
