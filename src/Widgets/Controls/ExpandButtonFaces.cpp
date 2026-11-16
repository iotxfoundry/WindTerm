// ExpandButtonFaces.cpp — 展开钮两类(批 491)
#include "ExpandButtonFaces.h"

#include "App/ThemeIcons.h"

#include <QIcon>
#include <QToolButton>

// s_ExpandButton_5984be(1021B)ctor
ExpandButtonFace::ExpandButtonFace(QWidget *parent)
	: QWidget(parent)
{
	// +0x30(三角)/ +0x38(标题)/ +0x40(容器)三件装配 — cited
}

// ExpandToggleFace ctor —— 注意:语料里**没有**对应的 ctor 函数
// (s_ExpandButton_5ab32a 不是 ctor,见下方 setExpandButtonIcon)。
ExpandToggleFace::ExpandToggleFace(QWidget *parent)
    : QWidget(parent)
{
}

// s_ExpandButton_5ab32a(584B)真身(逐句):
//   btn = host->findChild<QToolButton>("ExpandButton"@0x…, Qt::FindChildrenRecursively=1)
//   btn 为空 → 返回
//   名 = expanded ? "king::expand" : "king::shrink"(0xc 字符)
//   icon = theme_icon_load_svg(DAT_011c1ce0, 名, …)(1272B,见 Actions/ActionFactory.cpp)
//   btn->setIcon(icon)(QAbstractButton::setIcon)
void setExpandButtonIcon(QWidget *host, bool expanded)
{
	if (host == nullptr)
		return;
	QToolButton *btn = host->findChild<QToolButton *>(
	    QStringLiteral("ExpandButton"), Qt::FindChildrenRecursively);
	if (btn == nullptr)
		return;
	const QString name = expanded ? QStringLiteral("king::expand")
	                              : QStringLiteral("king::shrink");
	btn->setIcon(ThemeIcons::loadSvg(name, QString())); // theme_icon_load_svg(0x00756cd6)
}
