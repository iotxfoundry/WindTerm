// SideButtonFace.cpp — 侧栏图标按钮。

#include "Widgets/Controls/SideButtonFace.h"

#include <QEvent>
#include <QIcon>
#include <QVariant>

// theme_icon_load_svg — cited:主题 SVG 图标加载器(地址 DAT_011c1ce0 处为
// ThemeIcons 单例持有者;函数体未转写)。
static QIcon loadThemeIcon(const QString &file);

SideButtonFace::SideButtonFace(QWidget *parent)
    : QPushButton(parent)
{
}

// 0058eb86(270B)event 真身。逐句:
//   仅处理 **自定义事件类型 0x2af9**(字面保留,非 QEvent::Type 标准值):
//     name = property("iconFile").toString();   // 属性名字面实读 0xd0dfb8
//     if (!name.isEmpty()) setIcon(loadThemeIcon(name));
//     event->accept()                           // 语料:+0x12 |= 4
//   其余类型直接落 QPushButton::event。
// 说明:同族 SwitchButtonFace 的 event 与本函数逐句同构,仅 setIcon 的
//   接收者调用点不同(0x005b31f0)。
bool SideButtonFace::event(QEvent *event)
{
	if (event->type() == QEvent::Type(0x2af9)) {
		const QString name = property("iconFile").toString();
		if (!name.isEmpty())
			setIcon(loadThemeIcon(name));
		event->accept();
	}
	return QPushButton::event(event);
}

// 008f7188(29B)dtor 真身:
//   vptr = &SideButton_vtable;*(this+0x10) = &PTR_FUN_01198898;QPushButton::~QPushButton
SideButtonFace::~SideButtonFace() = default;

static QIcon loadThemeIcon(const QString &file)
{
	Q_UNUSED(file);
	return QIcon();
}
