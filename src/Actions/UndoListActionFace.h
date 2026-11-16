#pragma once

#include <QWidgetAction>

class QWidget;

// UndoListActionFace — 撤销历史下拉动作(QWidgetAction 派生)。
//
// 出处:RTTI "UndoListAction";QMetaObject 0x011af420
// (**methods=0 / signals=0 / props=0 / superdata=0**);
// dtor 0x00a1c206(19B)/deleting 0x00a1c21a(37B)
//   —— 与 ToolbarWidgetActions 里那六个同构(vptr 写 PTR_metaObject_01184688,
//   deleting 用 operator_delete(_,0x10))⇒ **零字段、无自有 Q_OBJECT**;
// createWidget = vt12 0x009c3f12(778B)。
//
// 字段(createWidget 实读):
//   +0x10 bool  方向/模式位(后半段按它二选一:0 → 0x005cc4de,否则 0x005cbe14)
//   +0x18 void* 撤销模型(传给 connectImpl 作为第二个连接方;实为 UndoModel*)
//
// 版面(createWidget 建造顺序,逐句实读):
//   容器 QWidget(0x30) → 列表件 new 0x40(FUN_009c3e06(list, 容器))
//   → QLabel(容器) + **setAlignment(0x84)**(AlignRight|AlignVCenter)
//   → FUN_0075263e(**0x4030000000000000 = double 16.0**, 主题单例, 容器)
//     并 setMinimumHeight(label)  ⇒ 16pt 字号决定行高下限
//   → QVBoxLayout(容器):边距 0、间距 0 → addWidget(list) → addWidget(label)
//   → 三路接线:QAction::triggered / 列表件信号 → 0x00a1c084 /
//     列表件信号 → 0x009c3c52(带 label)/ 最后走 vtable+0x1c0 设模型
class UndoListActionFace : public QWidgetAction {
public:
	explicit UndoListActionFace(QObject *parent);

	QWidget *createWidget(QWidget *parent) override; // vt12 0x009c3f12

private:
	bool m_mode10 = false;      // +0x10
	void *m_model18 = nullptr;  // +0x18(UndoModel*)
};
