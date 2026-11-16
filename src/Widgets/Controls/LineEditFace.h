#pragma once

#include <QLineEdit>

// LineEditFace — 输入框基座(QLineEdit 派生,**零字段**)。
//
// 出处:RTTI "LineEdit";QMetaObject 0x01198660
// (rev=8,class="LineEdit",methods=2,**signals=2**,props=0,**superdata=0**);
// qt_metacast 0x008f6e2e(s_LineEdit_8f6e2e);qt_metacall 0x008f6e70
//   (语料把它错标成 `BreadEdit_h8f6e70`,但 PathEdit/SafeEdit/SearchEdit 的
//    metacall 全都转发到它 ⇒ 它就是 LineEdit 的 metacall)。
//
// 两条信号(串表实读):
//   #0 layoutRequested()      发射器 0x008fa97a(activate idx 0)
//   #1 completerRequested()
//
// **本类零字段**:它的 dtor 只做 vptr 复位 + QLineEdit 析构。
// PathEdit 的 +0x30/+0x50、SearchEdit 的 +0x30..+0x68 都是各自派生层加的。
//
// 继承面(按 qt_metacast 的 strcmp 链实读):
//   QLineEdit → LineEdit → { PathEdit → SafeEdit,  SearchEdit,  BreadEdit }
class LineEditFace : public QLineEdit {
	Q_OBJECT

public:
	explicit LineEditFace(QWidget *parent = nullptr);
	~LineEditFace() override;

signals:
	void layoutRequested();    // #0 0x008fa97a
	void completerRequested(); // #1
};
