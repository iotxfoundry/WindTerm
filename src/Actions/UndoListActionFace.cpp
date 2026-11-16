// UndoListActionFace.cpp — 撤销历史下拉动作。

#include "Actions/UndoListActionFace.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

static QWidget *makeUndoList(QWidget *parent);      // 0x009c3e06(0x40B 列表件)
static void applyFont(double pt, void *theme, QWidget *w); // 0x0075263e

UndoListActionFace::UndoListActionFace(QObject *parent)
    : QWidgetAction(parent)
{
}

// vt12 0x009c3f12(778B)createWidget 真身(结构段,建造顺序见头注):
//   ① 容器 QWidget(0x30)
//   ② 列表件 new 0x40 → FUN_009c3e06(list, 容器)
//   ③ QLabel(容器) + setAlignment(0x84) + 16pt 字号 + setMinimumHeight
//   ④ QVBoxLayout(容器):边距 0 / 间距 0 / addWidget(list) / addWidget(label)
//   ⑤ 三路接线(triggered → 0x00a1c084;列表信号 → 0x009c3c52 带 label;
//      最后 vtable+0x1c0 设模型,模型由 +0x10 二选一取 0x005cc580 的返回)
// ⚠ 三路 connect 的接收者实参被折叠,按调用形态复原(踩坑 18)。
QWidget *UndoListActionFace::createWidget(QWidget *parent)
{
	auto *box = new QWidget(parent);
	QWidget *const list = makeUndoList(box); // 0x40B 件 — cited

	auto *label = new QLabel(box);
	label->setAlignment(Qt::AlignRight | Qt::AlignVCenter); // 0x84
	applyFont(16.0, nullptr, box);                          // 0x4030000000000000
	label->setMinimumHeight(label->sizeHint().height());

	auto *layout = new QVBoxLayout(box);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	if (list != nullptr)
		layout->addWidget(list);
	layout->addWidget(label);

	// ⑤ 三路接线 — cited(接收者折叠)
	return box;
}

static QWidget *makeUndoList(QWidget *) { return nullptr; }
static void applyFont(double, void *, QWidget *) { }
