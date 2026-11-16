#pragma once

#include "Widgets/Panes/KitPaneFace.h"

class Grep;
class QEvent;

// SearchPaneFace — 搜索面板(KitPane 直接派生)。
//
// 出处:RTTI "SearchPane";QMetaObject 0x011a63e0
// (rev=8,class="SearchPane",methods=8,superdata=0x011ab900 = KitPane);
// dtor 0x0090b61c(258B)/deleting 0x0090b92e(271B,operator_delete(_,**0x148**));
// metacast 0x0090b428 / metacall 0x0090b5c0(91B);槽分发 0x0090b4c6(147B);
// event = vt5 0x0074cffe(61B,语料名 SearchPane_vt5)。
//
// 三条信号(串表实读 + 发射器逐个取证;dispatch 0..2 走 0x0090b4xx 的
// QMetaObject::activate 包装,与 3..7 的 0x0074xxxx 实现体分属两段 —— 这就是
// 信号/槽的分界证据):
//   #0 searchRequest(Grep *)        发射器 0x0090b492(52B)activate idx 0
//   #1 searchHighlight()            发射器 0x0090b46a(19B)activate idx 1
//   #2 searchIncrementalReset()     发射器 0x0090b47e(19B)activate idx 2
//
// 五条槽(名字串表实读;**形参个数**按 dispatch 逐个实读,不猜):
//   #3 search(...)         → FUN_0074eecc(this, int)                 1 参
//   #4 search(...)         → FUN_0074e9cc(this, int, bool, int)      3 参
//   #5 search(...)         → FUN_0074e9cc(this, int, bool, 0)        2 参(第 3 参默认)
//   #6 doSearch(...)       → FUN_0074e58e(this, bool, QString*)      2 参
//   #7 setupSearch(...)    → FUN_0074f5ac(this, bool, QString*)      2 参
// 串表里另有形参名 actionType / matchIncremental / delay / forward /
// findText / searchMode / searchText —— 归属未逐条钉死,故形参名暂用 arg,
// 名字留在注释里待该区开批时对号。
//
// 字段(dtor 实读):
//   +0x110 接口件(vtable+8 析构)
//   +0x118 QString
//   +0x130/+0x138 std::vector<24 字节元素>(元素首字段为引用计数指针)
class SearchPaneFace : public KitPaneFace {
	Q_OBJECT

public:
	explicit SearchPaneFace(QWidget *parent = nullptr);
	~SearchPaneFace() override; // 0090b61c

	// 属性面(Q_PROPERTY 未出现在本类 metaobject,故不声明)

signals:
	void searchRequest(Grep *pGrep); // #0 0x0090b492
	void searchHighlight();          // #1 0x0090b46a
	void searchIncrementalReset();   // #2 0x0090b47e

public slots:
	void search1(int arg);               // #3 → FUN_0074eecc
	void search3(int arg, bool arg2, int arg3); // #4 → FUN_0074e9cc
	void search2(int arg, bool arg2);    // #5 → FUN_0074e9cc(..., 0)
	void doSearch(bool arg, const QString &arg2);    // #6 → FUN_0074e58e
	void setupSearch(bool arg, const QString &arg2); // #7 → FUN_0074f5ac

protected:
	bool event(QEvent *event) override; // vt5 0x0074cffe

private:
	void *m_iface110 = nullptr;    // +0x110
	QString m_str118;              // +0x118
	void *m_vecBegin130 = nullptr; // +0x130
	void *m_vecEnd138 = nullptr;   // +0x138
};

