#pragma once

#include <QVariant>

#include "Widgets/Panes/KitPaneFace.h"

// OutputPaneFace — 输出面板(KitPane 直接派生,9 条槽 / 0 信号)。
//
// 出处:RTTI "OutputPane";QMetaObject 0x011a56c0
// (rev=8,class="OutputPane",methods=9,**signals=0**,props=0,
//  superdata=0x011ab900 = **KitPane**);
// sizeof = **0x48**(deleting 0x00748a8a 的 operator_delete(_,0x48));
// dtor 0x00748a66(29B)/deleting 0x00748a8a(23B);
// 槽分发 0x00909e08(414B);metacast 0x00909fae / metacall 0x00909ff0(93B)。
//
// 九条槽(串表真名按索引;同名两条 = 带默认实参的重载):
//   #0 clearText(...)        → 0x00749422(this, 实参)
//   #1 clearText()           → 0x00749422(this, QVariant())   默认实参腿
//   #2 currentTool()         → 0x00749878(&out, this)         出参 QString
//   #3 locateMessage(...)
//   #4 locateMessage()                                       默认实参腿
//   #5 nextMessage()
//   #6 showTool(...)
//   #7 tools()
//   #8 toolText(...)
//
// 注意 dtor 只做 vptr 复位到 **KitPane 的 vtable**(PTR_FUN_011ab6b8 /
// DAT_011ab8b0)再 QWidget 析构 ⇒ 本类**零字段**,全在基类。
class OutputPaneFace : public KitPaneFace {
	Q_OBJECT

public:
	explicit OutputPaneFace(QWidget *parent = nullptr);
	~OutputPaneFace() override; // 0x00748a66

public slots:
	void clearText(const QVariant &v); // #0
	void clearText();                  // #1
	QString currentTool();             // #2
	void locateMessage(const QVariant &v); // #3
	void locateMessage();              // #4
	void nextMessage();                // #5
	void showTool(const QVariant &v);  // #6
	QVariant tools();                  // #7
	QString toolText(const QVariant &v); // #8
};
