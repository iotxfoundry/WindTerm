#pragma once

#include <QWidget>

class QMenu;
class QWidgetAction;

// SlipButtonFace — 语料 SlipButton / 其菜单动作行(批 338)。
// slipButton_makeMenu(1023B,0021.c:40319)构建结构(逐对象实读):
//   menu = new QMenu(0x30)(parent);
//   action = new QWidgetAction(0x30) + vtable SlipButtonAction(自定义行);
//     +0x18 = QLabel(0x30)(行文本,tr(0xc9d3fb) 取面);
//     +0x20 = overlay_makeBusyWidget(0xa0)(忙碌遮罩);
//     +0x28 = QWidget(0x30)(行容器);
//     QLabel::setBuddy(+0x18)—— 随后 addAction + connect/弹面(cited)。
// 备注:该函数名取自其首个产物,实际 = "SlipButton 菜单行构建"。
class SlipButtonFace : public QObject {
	Q_OBJECT
public:
	// 行的四个部件尺寸/顺序按语料实读落结构;文本腿 cited(tr 串未取)。
	static QMenu *makeMenu(QWidget *parent);
};
