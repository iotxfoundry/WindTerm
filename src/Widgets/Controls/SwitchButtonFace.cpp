// SwitchButtonFace.cpp — 可切换图标按钮。

#include "Widgets/Controls/SwitchButtonFace.h"

#include <QEvent>
#include <QIcon>
#include <QVariant>

static QIcon loadThemeIcon(const QString &file); // cited,见 SideButtonFace.cpp
static void applyIcon(QAbstractButton *btn, const QIcon &icon); // 0x005b31f0 — cited

SwitchButtonFace::SwitchButtonFace(QWidget *parent)
    : QPushButton(parent)
{
}

// 005b33e0(270B)event 真身。逐句:
//   仅处理自定义事件类型 0x2af9:
//     name = property("iconFile").toString();
//     if (!name.isEmpty()) applyIcon(this, loadThemeIcon(name));  // 005b31f0
//     event->accept()(+0x12 |= 4)
//   其余落 QPushButton::event。
bool SwitchButtonFace::event(QEvent *event)
{
	if (event->type() == QEvent::Type(0x2af9)) {
		const QString name = property("iconFile").toString();
		if (!name.isEmpty())
			applyIcon(this, loadThemeIcon(name));
		event->accept();
	}
	return QPushButton::event(event);
}

// 008f73c4(29B)dtor 真身:
//   vptr = &SwitchButton_vtable;*(this+0x10) = &PTR_FUN_01198fa0;QPushButton::~QPushButton
SwitchButtonFace::~SwitchButtonFace() = default;

static QIcon loadThemeIcon(const QString &file)
{
	Q_UNUSED(file);
	return QIcon();
}

static void applyIcon(QAbstractButton *btn, const QIcon &icon)
{
	Q_UNUSED(btn);
	Q_UNUSED(icon);
}
