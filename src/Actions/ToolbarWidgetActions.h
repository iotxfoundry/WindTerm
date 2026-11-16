#pragma once

#include <QWidgetAction>

// ToolbarWidgetActions.h — 六个**逐字节同构**的零字段工具栏动作。
//
// 为什么六个类放一个文件:它们的 dtor 与 dtor_deleting 在语料里
// **完全相同**,只是符号名不同,属于同组同层(都是 QWidgetAction 直接派生、
// 都是 sizeof 0x10、都没有自己的 Q_OBJECT)。按 AGENTS §1.1「同组 = 同一
// 装配链上一起出现的类」归一处;若日后其中一个长出字段或虚面,再拆出去。
//
// 共同事实(六份语料完全一致):
//   · vptr 复位写 `&PTR_metaObject_01184688` —— QWidgetAction 族元对象
//     ⇒ **六个类都没有 Q_OBJECT**,靠继承拿元对象;
//   · deleting 里 `operator_delete(_, **0x10**)` = QWidgetAction 本身大小
//     ⇒ **六个类都零字段**;
//   · dtor 19B / deleting 37B,函数体只有 vptr 复位 + 基类析构两行。
//
// 各自出处(entry 地址逐一列,便于 coverage 索引):
//   GroupWidgetAction    dtor 0x006d48bc / deleting 0x006d48d0
//   UnitWidgetAction     dtor 0x007391e6 / deleting 0x007391fa
//   IntervalWidgetAction dtor 0x0073925a / deleting 0x0073926e
//   TargetsWidgetAction  dtor 0x00739294 / deleting 0x007392a8
//   CountWidgetAction    dtor 0x00739220 / deleting 0x00739234
//   EditWidgetAction     dtor 0x007391ac / deleting 0x007391c0
//
// ⚠ 六者语义差异(各自 createWidget 造什么控件)**不在本批**:语料里
//   它们的 ctor / createWidget 没有独立 entry(内联在调用点),要做只能从
//   装配点反推 —— 留到对应工具栏开批时一起取。

class GroupWidgetActionFace : public QWidgetAction {
public:
	explicit GroupWidgetActionFace(QObject *parent);
	~GroupWidgetActionFace() override; // 0x006d48bc
};

class UnitWidgetActionFace : public QWidgetAction {
public:
	explicit UnitWidgetActionFace(QObject *parent);
	~UnitWidgetActionFace() override; // 0x007391e6
};

class IntervalWidgetActionFace : public QWidgetAction {
public:
	explicit IntervalWidgetActionFace(QObject *parent);
	~IntervalWidgetActionFace() override; // 0x0073925a
};

class TargetsWidgetActionFace : public QWidgetAction {
public:
	explicit TargetsWidgetActionFace(QObject *parent);
	~TargetsWidgetActionFace() override; // 0x00739294
};

class CountWidgetActionFace : public QWidgetAction {
public:
	explicit CountWidgetActionFace(QObject *parent);
	~CountWidgetActionFace() override; // 0x00739220
};

class EditWidgetActionFace : public QWidgetAction {
public:
	explicit EditWidgetActionFace(QObject *parent);
	~EditWidgetActionFace() override; // 0x007391ac
};
