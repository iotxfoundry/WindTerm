#pragma once

#include <QString>

#include "Widgets/Controls/LineEditFace.h"

// PathEditFace — 带"浏览"按钮的路径输入框(LineEdit 派生)。
//
// 出处:RTTI "PathEdit";QMetaObject 0x0119d160
// (rev=8,class="PathEdit",methods=1,**signals=1**,props=0,
//  superdata=0x01198660 = **LineEdit**);
// sizeof = **0x80**(deleting 0x008faa7c 的 operator_delete(_,0x80));
// dtor 0x008fab2e(75B)/deleting 0x008faa7c(88B);
// metacast 0x008fa938 / metacall 0x008fa9be(87B)。
//
// 信号(串表实读):#0 `browseButtonClicked()`  发射器 0x008fa97a(activate idx 0)
//
// 字段(dtor 实读):
//   +0x30 引用计数件(计数减一,归零 operator_delete)
//   +0x50 原子引用计件(qatomic_unref_call_deleter2)
class PathEditFace : public LineEditFace {
	Q_OBJECT

public:
	explicit PathEditFace(QWidget *parent = nullptr);
	~PathEditFace() override; // 0x008fab2e

signals:
	void browseButtonClicked(); // #0

private:
	void *m_ref30 = nullptr; // +0x30
	void *m_atomic50 = nullptr; // +0x50
};
