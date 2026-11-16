#pragma once

#include <QFrame>
#include <QMap>
#include <QString>

// ButtonBarFace — 按钮条(QFrame 派生,17 条信号)。
//
// 出处:RTTI "ButtonBar";QMetaObject 0x011931e0
// (rev=8,class="ButtonBar",methods=17,**signals=17**,props=0,superdata=0);
// sizeof = **0x50**(deleting 0x008ef6ee 的 operator_delete(_,0x50));
// dtor 0x008ef56e(127B)/deleting 0x008ef6ee(128B);
// 信号桥 0x008ef1ea(740B);metacast 0x008ef4ce / metacall 0x008ef510(93B)。
//
// 十七条信号 —— **真名与形参名都来自串表**,与桥的 switch 0..0x10 逐条对上:
//   0 addAllRequested()                         0 参
//   1 addRequested()                            0 参
//   2 captureGroupTriggered(captureGroup)        1 参(串表名 "captureGroup")
//   3 checkAllRequested()                       0 参
//   4 duplicateRequested()                      0 参
//   5 filterToggled(checked)                    bool
//   6 matchCaseToggled(checked)                 bool
//   7 matchRegexToggled(checked)                bool
//   8 matchWholeWordToggled(checked)            bool
//   9 modifyRequested()                         0 参
//  10 moveRequested(down)                       bool(串表名 "down")
//  11 removeAllRequested()                      0 参
//  12 removeRequested()                         0 参
//  13 renameRequested()                         0 参
//  14 scriptToggled(checked)                    bool
//  15 textToggled(checked)                      bool
//  16 uncheckAllRequested()                     0 参
//
// 字段(dtor 实读):
//   +0x30 QMap<?>  (走 QMapDataBase::freeTree + freeData)
//   +0x40 QSharedDataPointer(qt_shared_data_unref)
class ButtonBarFace : public QFrame {
	Q_OBJECT

public:
	explicit ButtonBarFace(QWidget *parent = nullptr);
	~ButtonBarFace() override; // 0x008ef56e

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

private:
	QMap<QString, void *> m_map30; // +0x30
	void *m_shared40 = nullptr;    // +0x40
};
