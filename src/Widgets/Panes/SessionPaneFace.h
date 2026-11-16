#pragma once

#include <QVariant>

#include "Widgets/Panes/KitPaneFace.h"

// SessionPaneFace — 会话列表面板(KitPane 直接派生,10 条槽 / 0 信号)。
//
// 出处:RTTI "SessionPane";QMetaObject 0x011a5960
// (rev=8,class="SessionPane",methods=10,**signals=0**,props=0,
//  superdata=0x011ab900 = **KitPane**);
// sizeof = **0x68**(deleting 0x0090a2fc 的 operator_delete(_,0x68));
// dtor 0x0090a2be(29B)/deleting 0x0090a2fc(47B);
// 槽分发 0x0090a0aa(413B);metacast 0x0090a068 / metacall 0x0090a260(93B)。
//
// 十条槽(串表真名按索引)与分发落点:
//   #0 duplicate()                → 0x00740472
//   #1 open()                     → view_deleteSelectedRows()
//   #2 hasSelection()             → 0x0073cdaa(出参 bool)
//   #3 importExternalSessions(?)  → 0x007400aa(this, 实参)
//   #4 moveTo()                   → 0x0073eb92
//   #5 newSession()               → 0x0073cdc4
//   #6 remove()                   → sessions_deleteSel()
//   #7 property(?, ?)             → sessionpane_connect_rows(this, str, 实参)
//   #8 property(...)              #9 property(...)  ← 三条同名重载
//
// dtor 只把 vptr 复位到 KitPane 的 vtable 再 QWidget 析构 ⇒ **零字段**,
// 0x68 的尺寸全部来自基类链。
class SessionPaneFace : public KitPaneFace {
	Q_OBJECT

public:
	explicit SessionPaneFace(QWidget *parent = nullptr);
	~SessionPaneFace() override; // 0x0090a2be

public slots:
	void duplicate();                        // #0
	void open();                             // #1
	bool hasSelection();                     // #2
	void importExternalSessions(const QVariant &v); // #3
	void moveTo();                           // #4
	void newSession();                       // #5
	void remove();                           // #6
	QVariant property(const QVariant &a, const QVariant &b); // #7
	QVariant property(const QVariant &a);                    // #8
	QVariant property();                                     // #9
};
