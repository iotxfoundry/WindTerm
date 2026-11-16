// HighlightTextBarActionFace.cpp — 工具栏高亮文本行动作。

#include "Widgets/Bars/HighlightTextBarActionFace.h"

#include <QHBoxLayout>
#include <QLayout>
#include <QWidget>

static QWidget *makeInner(QWidget *parent); // 0x0055c246(0x48B 件)

HighlightTextBarActionFace::HighlightTextBarActionFace(QObject *parent)
    : QWidgetAction(parent)
{
}

// vt12 0x0055cad0(280B)createWidget 真身。逐句:
//   ① 容器 = new QWidget(parent)(0x30)→ vptr 换成 **WidgetContainer_vtable**
//      + *(c+0x10) = &PTR_FUN_01184638 —— 即用一个"容器子类"承载
//   ② layout = new QHBoxLayout —— 注意:**不传 parent**(与 SlipButtonAction 不同)
//   ③ setSpacing / setContentsMargins(语料把边距整体折叠,值未取)
//   ④ `(**(*this + 0x70))(&list, this, parent)` —— 走虚面 vt14 拿部件列表
//   ⑤ 逐个 addWidget 到 layout
QWidget *HighlightTextBarActionFace::createWidget(QWidget *parent)
{
	auto *box = new QWidget(parent);
	auto *layout = new QHBoxLayout; // 无 parent
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);

	QWidget *const inner = requestWidget(parent);
	if (inner != nullptr)
		layout->addWidget(inner); // 语料:遍历 vt14 返回的列表逐个加

	box->setLayout(layout);
	return box;
}

// vt14 0x0055c556(409B)requestWidget 真身 —— 惰性 + 共享：
//   门:已建(+0x10 计数非 0 且 +0x18 非空)则直接复用
//   否则 w = new 0x48B(parent)(0x0055c246)
//        d = ExternalRefCountData::getAndRef(w)
//        旧 (d,w) 换出,旧计数减一归零则 operator_delete
//   然后 connectImpl(w 的某信号, this, functor 0x008f0b38)
QWidget *HighlightTextBarActionFace::requestWidget(QWidget *parent)
{
	if (!m_widget.isNull())
		return m_widget.data();

	QWidget *const w = makeInner(parent);
	if (w == nullptr)
		return nullptr;
	m_widget.reset(w);
	return w;
}

static QWidget *makeInner(QWidget *) { return nullptr; }
