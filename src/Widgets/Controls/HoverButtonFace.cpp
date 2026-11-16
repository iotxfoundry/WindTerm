// HoverButtonFace.cpp — 悬停工具按钮。

#include "Widgets/Controls/HoverButtonFace.h"

#include <QObject>

HoverButtonFace::HoverButtonFace(QWidget *parent)
    : QToolButton(parent)
{
}

// 0055cf8c(90B)clearHover 真身。逐句:
//   门:+0x30 非空 **且** 其引用计数(+4)非 0 **且** +0x38 非空
//   → QObject::deleteLater(+0x38)
//   → +0x30 = 0;+0x38 = 0
//   → +0x30 引用计数减一,归零则 operator_delete
//   (三个条件缺一即整腿不动 —— 原样保留)
void HoverButtonFace::clearHover()
{
	if (m_hover30 == nullptr || m_hover38 == nullptr)
		return;
	if (*reinterpret_cast<int *>(reinterpret_cast<char *>(m_hover30) + 4) == 0)
		return;
	reinterpret_cast<QObject *>(m_hover38)->deleteLater();
	m_hover30 = nullptr;
	m_hover38 = nullptr;
	// cited:+0x30 的引用计数递减与归零释放(件类型未复原)
}

// 0055cfe6(71B)dtor 真身:
//   vptr = &HoverButton_vtable;*(this+0x10) = &PTR_FUN_011952c0;
//   clearHover();+0x30 再减一次引用(为 0 则 operator_delete);
//   QToolButton::~QToolButton。
HoverButtonFace::~HoverButtonFace()
{
	clearHover();
}
