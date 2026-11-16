#pragma once

#include <QFrame>
#include <QString>

// ButtonBarPanelFace — 按钮条的"面板"面(QFrame 派生,**不新增字段**)。
//
// 出处:RTTI "ButtonBarPanel";QMetaObject 0x01193440
// (rev=8,class="ButtonBarPanel",methods=17,**signals=17**,props=0,superdata=0);
// dtor 0x008efd6e(29B)/deleting 0x008efdac(47B);
// 信号桥 0x008ef9ea(740B,**与 ButtonBar 的桥逐字节同构**);
// metacast 0x008efcce / metacall 0x008efd10(93B)/ 0x008fb1fe(5B)。
//
// **两条判据说明它与 ButtonBarFace 是"同一组件的两个面",不是派生关系**:
//   ① 两者 superdata 都是 0(各自直接挂 QFrame),不是父子;
//   ② 两者的 17 条信号**名字、顺序、形参名完全一致**(串表逐条比对)。
// 区别只在 dtor:ButtonBar 有 +0x30 QMap / +0x40 共享件,本类**一个字段都没有**
// (dtor 只有 vptr 复位 + QFrame 析构两行)。
class ButtonBarPanelFace : public QFrame {
	Q_OBJECT

public:
	explicit ButtonBarPanelFace(QWidget *parent = nullptr);
	~ButtonBarPanelFace() override; // 0x008efd6e

signals:
	void addAllRequested();
	void addRequested();
	void captureGroupTriggered(const QString &captureGroup);
	void checkAllRequested();
	void duplicateRequested();
	void filterToggled(bool checked);
	void matchCaseToggled(bool checked);
	void matchRegexToggled(bool checked);
	void matchWholeWordToggled(bool checked);
	void modifyRequested();
	void moveRequested(bool down);
	void removeAllRequested();
	void removeRequested();
	void renameRequested();
	void scriptToggled(bool checked);
	void textToggled(bool checked);
	void uncheckAllRequested();
};
