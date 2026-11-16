#pragma once

#include "Widgets/Panes/KitPaneFace.h"

// OutlinePaneFace — 大纲/符号面板(KitPane 直接派生)。
//
// 出处:RTTI "OutlinePane";QMetaObject 0x011a6140
// (rev=8,class="OutlinePane",**methods=10,signals=0**,props=0,
//  superdata=0x011ab900 = KitPane ⇒ 直接派生自 KitPane);
// dtor 0x0090b020(244B)/deleting 0x0090b30c(253B);
// metacast 0x0090ae58 / metacall 0x0090afc4(91B);
// 槽分发 0x0090ae9a(279B);event 0x0091d424(93B —— 语料名 OutlinePane_h91d424,
// 实为 KitPane::qt_metacall,已按 metacall 语义归位)。
//
// 十条槽(串表实读的**真名**,按索引):
//   0 UpdateKitView         → outline_pane_connect()
//   1 TryShowOutlineTree    → FUN_0074644a()
//   2 copy                  → FUN_00746b00(&s, this)          输出 QString
//   3 copyOutput            → outline_collectVisibleText(&s, this)
//   4 copyToTerminal        → FUN_00746b46(&s, this)          输出 QString
//   5 execute               → FUN_00746bfe()
//   6 executeRepeatedly     → FUN_00746ce4()(语料符号名 s_SenderPane_746ce4)
//   7 gotoSymbol            → FUN_00748510()
//   8 hasSelection          → FUN_00745ee2()                  输出 bool
//   9 preview               → FUN_007478c6()
//
// 字段(dtor 实读):基类 +0x50 / +0x70 之外无自有字段。
class OutlinePaneFace : public KitPaneFace {
	Q_OBJECT

public:
	explicit OutlinePaneFace(QWidget *parent = nullptr);
	~OutlinePaneFace() override; // 0090b020

public slots:
	void updateKitView();         // 0 UpdateKitView
	void tryShowOutlineTree();    // 1 TryShowOutlineTree
	void copy();                  // 2
	void copyOutput();            // 3
	void copyToTerminal();        // 4
	void execute();               // 5
	void executeRepeatedly();     // 6
	void gotoSymbol();            // 7
	bool hasSelection() const;    // 8
	void preview();               // 9
};
