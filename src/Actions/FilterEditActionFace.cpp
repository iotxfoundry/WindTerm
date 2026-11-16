// FilterEditActionFace.cpp — 过滤器输入框动作。

#include "Actions/FilterEditActionFace.h"

#include <QWidget>

FilterEditActionFace::FilterEditActionFace(QObject *parent)
    : QWidgetAction(parent)
{
}

// vt14 0x005b3180(87B)requestWidget 真身:
//   把 **+0x18 单个控件**装进一个新建 QList<QWidget*> 并返回
//   (语料:QListData::realloc / FUN_00534da0 + qlist_appendDetach)。
// 说明:QWidgetAction::requestWidget 的语义是"交出该动作的控件",
//   这里用单元素列表包装,与 CloseButtonAction/LabelAction 直接返回
//   一个容器不同 —— 差异原样保留。
QWidget *FilterEditActionFace::requestWidget(QWidget *parent)
{
	Q_UNUSED(parent);
	// 语料返回 QList<QWidget*>{ m_w18 };此处取首元素语义等价
	return m_w18;
}
