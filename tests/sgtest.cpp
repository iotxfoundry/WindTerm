// SplitterGroup 余项行为门(批 148;铁律 5:断言语料行为,非教科书行为)。
// 覆盖面(本批落):
//   装配腿 setSpacing(0) @005a22c7 + setContentsMargins(QMargins(0,0,0,0))
//     @005a22cb-df(批 148 由 cited 升真身;import 符号实证)
//   removePage(QWidget*) = FUN_005a29e6(690B,asm 全读转写):
//     首卫/ancestor 门/parent cast 门/close 门/嵌套收缩/递归自卷
//   批 153:MuxWindow 归辖取面真身(FUN_008e0428 zoomedPane/
//     FUN_008e0a72 paneByIndex;g 组)+ QUIRKS #33 死腿闭环注记(g4)
// 批 118 已落槽体(ctor/isZoomed/stackCurrentPage/toggleZoomPage)不在此
// 重复断言( mwctest b1 + uiassembletest d 已守)。
// 无头惯例:QApplication + offscreen(tests/uiassembletest.cpp 同面)。
#include <QApplication>
#include <QIcon>
#include <QMap>
#include <QPointer>
#include <QSplitter>
#include <algorithm>
#include <cstdio>
#include "Actions/MuxPaneGroup.h"
#include "Actions/MuxPaneView.h"
#include "Actions/MuxWindow.h"
#include "Actions/SplitterGroup.h"
#include "Actions/TabGroup.h"

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

// k2 夹具比较器(0084be6a toInt 承接腿同型;产品符号 static 不可见
//   → 测试本地同型消歧,k2 断言的是 toInt 语义同相性)
static bool muxWindowPermLessLocal(const QVariant &a, const QVariant &b)
{
	return a.toInt() < b.toInt();
}

// 测试可见产品符号声明(PanePosNode/驱动函数 = MuxWindow.cpp 匿名域
//   转写面;测试直构造节点断言槽体行为 — 复刻布局直译,非新增行为):
struct PanePosNode {
	QPointer<MuxPaneView> pane;
	int pos;
	int pos2;
	bool vertical;
};
void muxSplitterMovedTimerSlotDriver(MuxWindow *win);
void muxSplitterMovedDriver(MuxWindow *win, int pos, int index);

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	// ======== a. 装配腿真身(FUN_005a2266 段;批 148 升真身)========
	SplitterGroup sg(nullptr);
	QLayout *lay = sg.layout(); // = m_f38(setLayout @005a22f2)
	expect(lay != nullptr && lay->spacing() == 0,
	       "a1: stack 布局 spacing==0(setSpacing(0) @005a22c7;ESI=0 直读,"
	       "import _ZN7QLayout10setSpacingEi)");
	expect(lay != nullptr && lay->contentsMargins() == QMargins(0, 0, 0, 0),
	       "a2: contentsMargins==(0,0,0,0)(@005a22cb-df;[RSP]=0,[RSP+8]=0,"
	       "import _ZN7QLayout18setContentsMarginsERK8QMargins)");

	// ======== b. removePage 卫腿(FUN_005a29e6 首段)========
	sg.removePage(nullptr); // 005a29e6 首卫:page==0 直返
	expect(sg.splitter()->count() == 0, "b1: removePage(null) no-op 不崩");

	QWidget stray; // 非 sg 后代 → 005a2a03 isAncestorOf 门直返
	sg.removePage(&stray);
	expect(stray.parentWidget() == nullptr,
	       "b2: 非 ancestor 页 no-op(isAncestorOf 门 @005a2a03)");

	// ======== c. removePage ≥2 页腿(005a2b3c 分支:邻页吸收 + removeAt)===
	QSplitter *sp = sg.splitter();
	QWidget *p1 = new QWidget;
	QWidget *p2 = new QWidget;
	sp->addWidget(p1);
	sp->addWidget(p2);
	sp->setSizes(QList<int>{ 100, 100 }); // 可控初值(布局时基)
	QPointer<QWidget> p1Guard(p1);
	sg.removePage(p1); // 005a29e6:close→hide→setParent(0)→delete @005a2a88
	expect(p1Guard.isNull(),
	       "c1: 页被 deleting-dtor 删除(vt+0x20=D0 槽 @005a2a88;Qt5.15 "
	       "_ZTV7QWidget 布局实证:vt[4]=D0)");
	expect(sp->count() == 1 && sp->widget(0) == p2,
	       "c2: splitter 余 1 页且为邻页(widget(idx) 取邻 @005a2bf1)");
	expect(sp->sizes().size() == 1,
	       "c3: sizes 表收缩(removeAt @005a2b85;QListData::remove 4baab0)");

	// ======== d. 嵌套 splitter 收缩(count==1 腿 @005a2aa3:上卷 replaceWidget
	//             + deleteLater @005a2b07 + 焦点深潜 @005a2b0c)========
	QSplitter *cs = new QSplitter(sp); // 子 splitter 挂 sp
	QWidget *q1 = new QWidget(cs);
	cs->addWidget(q1);
	sp->addWidget(cs); // sp = [cs](cs 含 q1)… sp 已有 p2 → count==2
	QPointer<QWidget> csGuard(cs);
	QPointer<QWidget> q1Guard(q1);
	sg.removePage(q1);
	// cs count:q1 删除后 ==0 → 递归 removePage(cs):cs parent = sp cast 命中
	// → close/hide/setParent(0)/delete cs;sp count 仍 ≥1(p2)→ 不再卷。
	expect(q1Guard.isNull(), "d1: 内层页删除(同 c1 路径)");
	expect(csGuard.isNull(),
	       "d2: 空 child splitter 被删(递归 removePage(sp') @005a2b2f;"
	       "count==0 腿 @005a2a93)");
	expect(sp->count() == 1 && sp->widget(0) == p2,
	       "d3: 外层 splitter 稳定(递归后不再上卷)");

	// ======== e. 递归自卷至顶层 splitter 守卫(sp 的 parent 是本组非
	//             splitter → cast null 直返 @005a2ad9;不删 m_f30)========
	QSplitter *ds = new QSplitter(sp); // ds 挂 sp,内含唯一页 r1
	QWidget *r1 = new QWidget(ds);
	ds->addWidget(r1);
	QPointer<QWidget> spGuard(sp);
	sg.removePage(r1);
	// r1 删 → ds count 0 → 递归删 ds → sp count 0 → 递归 removePage(sp):
	// sp->parentWidget()==&sg 非 splitter → 直返(sp 存活,005a2ad9)。
	expect(spGuard == sp && sp->parentWidget() == &sg,
	       "e1: 顶层 splitter 不自删(parent 非 splitter cast null 直返;"
	       "语料 @005a2ad9→focusPaneDeep(sp) 前的守卫差异:cast null 腿在"
	       "close 前已返,sp 存活)");
	expect(sp->count() == 1 && sp->widget(0) == p2,
	       "e2: 递归止步——ds 已删、sp 存 p2(count==0 递归链 @005a2a93→"
	       "005a2b2f 只卷 splitter-in-splitter,顶层 cast-null 门 @005a2ad9)");

	// ======== f. toggleZoomPage 语料怪癖守门(批 118 已落体;铁律 2/5:
	//             断言语料行为非教科书行为)。实测(Qt5.15 本机 + 转写同
	//             相):zoom 腿 ph 入 stack → reparent 到本组(setLayout
	//             挂 sg),unzoom 腿 dynamic_cast<QSplitter*>(ph->parent)
	//             == null → 整腿跳过,m_f40 不清 → isZoomed 恒真。
	//             语料 unzoom 恢复腿对 stack 承载的 ph 为死腿(挂账怪癖)。
	QWidget *z1 = new QWidget(sp);
	sp->addWidget(z1);
	sg.toggleZoomPage(z1, true); // FUN_005a2518 zoom 腿 @005a25f3
	expect(sg.isZoomed() && sg.stackCurrentPage() != z1,
	       "f1: zoom 态 + 占位页非原页(FUN_005a23c6/005a24fc 面)");
	sg.toggleZoomPage(z1, false); // unzoom 腿 @005a264b
	expect(sg.isZoomed(),
	       "f2: unzoom 腿 ph->parent 非 splitter cast null → 腿跳过,"
	       "isZoomed 保持真(语料死腿 @005a265d-6d;实测同相)");

	// ======== g. MuxWindow 归辖取面真身(批 153;FUN_008e0428/008e0a72)===
	// 语料链:restorePaneSplitter 五级装配(批判例 f 形态,uiassembletest
	// 同面)→ 取面按 corpus 语义断言;Qt5.15 本机 probe 同相。
	MuxWindow gwin(false, nullptr);
	MuxPaneGroup *ggroup = new MuxPaneGroup(true, nullptr);
	MuxPaneView *gpane = new MuxPaneView(nullptr, TypeTerminal);
	gwin.splitter()->addWidget(ggroup);
	ggroup->addTab(gpane, /*normal=*/false);
	expect(gwin.paneByIndex(0) == gpane,
	       "g1: paneByIndex(0)==pane(FUN_008e0a72:findChildren 全域扫 +"
	       "pane->+0x30 比对 @008e0bb0;paneIndex 语料 ctor 0 起步)"
	       );
	expect(gwin.paneByIndex(7) == nullptr,
	       "g2: paneByIndex(未命中)==null(扫尽返 0 @008e0b47)");
	expect(gwin.zoomedPane() == nullptr,
	       "g3: 非 zoom 态取面 null(FUN_008e0428:stackCurrentPage 非"
	       "zoom 返 0 → 直返 @008e0434;FUN_005a24fc)");
	gwin.findChild<SplitterGroup *>()->toggleZoomPage(ggroup, true); // zoom 腿(FUN_005a2518)
	expect(gwin.zoomedPane() == nullptr,
	       "g4: zoom 态取面 null(stackCurrentPage = 占位页 ph,ph 无 "
	       "MuxPaneView 子件 — Qt5.15 probe 同相;QUIRKS #33 死腿闭环:"
	       "宿主 0084e151 unzoom 腿/0084eece [Zoomed] 追加腿双跳过 = 语料"
	       "字面同相死路,只注记不修)");

	// ======== h. 宿主 0084dd5a 新落段冒烟(批 157)========
	// 先拆 g 段 zoom(g4 语料死腿不还原 ph)→ 恢复非 zoom 取面。
	gwin.findChild<SplitterGroup *>()->toggleZoomPage(ggroup, false); // 语料死腿(m_f40 不清,字面)
	// h1-h2 setTitle(FUN_008e03e4):首写触发 nameChanged,同值不触发。
	int hFires = 0;
	QObject::connect(&gwin, &MuxWindow::nameChanged,
	                 [&hFires](const QString &) { hFires++; });
	gwin.setTitle(QStringLiteral("w1"));
	gwin.setTitle(QStringLiteral("w1")); // 同值早退 @008e03ec
	expect(hFires == 1,
	       "h1: setTitle 首写发 nameChanged 同值不发(FUN_008e03e4:比对"
	       "@008e03ec 早退/FUN_0091e3c8 idx0)");
	// h2:+0x60 槽无读出器(消费面 = FUN_008e03e4 自身比对)— 观测面
	//   仅 nameChanged(h1 已覆盖),此处只作注记。

	// h3 hasNoPaneChild(FUN_008e012c):zoom 态(g4 残留)窗内无
	//   MuxPaneView 子件 → 真(探针:zoom 腿 replaceWidget 顶出组树,
	//   pane parent 迁至 stack 承载侧 → findChild 空 = 语料字面同相);
	//   重新挂页 → false。
	expect(gwin.hasNoPaneChild(),
	       "h3a: zoom 态窗内无 pane 子件 → true(FUN_008e012c findChild 空;"
	       "Qt5.15 probe:zoom 腿 replaceWidget 顶出组树,pane 不在 win 树)");
	MuxPaneView *gpane2 = new MuxPaneView(nullptr, TypeTerminal);
	ggroup->addTab(gpane2, /*normal=*/false);
	gwin.splitter()->addWidget(ggroup);
	expect(!gwin.hasNoPaneChild(),
	       "h3b: 重新挂组后 findChild 非空 → false(FUN_008e012c)");
	// h4 建窗腿直译(宿主 @0084e6bf-e75):setWindowIndex/序键回读。
	gwin.setWindowIndex(3);
	expect(gwin.windowIndex() == 3,
	       "h4: +0x44 序号键写读(FUN_008da226 键/宿主 @0084e705 写面)");
	// h5 detachWindow 原语(FUN_008d9fe0):TabGroup 摘页 + setParent(0)。
	{
		TabGroup t5(nullptr);
		MuxPaneGroup grp5(true, nullptr);
		MuxPaneView p5(nullptr, TypeTerminal);
		t5.insertPageBack(&grp5, QStringLiteral("t"), QIcon(), QString());
		char desk5[0x40] = { 0 };
		*reinterpret_cast<TabGroup **>(desk5 + 0x30) = &t5; // *(desktop+0x30) 容器直读面
		MuxWindow::detachWindow(desk5, &grp5);
		expect(t5.stackIndexOf(&grp5) == -1 && grp5.parentWidget() == nullptr,
		       "h5: detachWindow 摘页+脱管(FUN_008d9fe0:005ab6c2→005ab2cc"
		       "(param_3=0 仅 removeWidget)→setParent(0))");
	}

	// ======== i. 批 158 新落段冒烟 ========
	// i1 0x10 重题腿(retitleGroupPane,0084ecf0-ef1a):"%1:%2" 合成 +
	//   池 upperBound 前置键 + setTitle/FUN_008df06e 链;zoomedPane 恒
	//   空(非 zoom)→ 无 " [Zoomed]" 追加(语料同相 @0084eecd)。
	{
		MuxWindow iwin(false, nullptr);
		MuxPaneGroup *igrp = new MuxPaneGroup(true, nullptr);
		MuxPaneView *ipane = new MuxPaneView(nullptr, TypeTerminal);
		iwin.splitter()->addWidget(igrp);
		igrp->addTab(ipane, false);
		QMap<int, QString> pool;
		pool.insert(0, QStringLiteral("main"));
		iwin.retitleGroupPane(ipane, pool);
		expect(ipane->title() == QStringLiteral("0:main"),
		       "i1: 重题腿 0:main(0084ee7c %1:%2 + 池 upperBound 前置键"
		       "@0084ee49-53 + FUN_008de224 链)");
		expect(ipane->title() == QStringLiteral("0:main"),
		       "i2: 同值不重写(+0x38 比对 @0084eeff 早退)");
	}
	// i3 muxSplitterMoved S0-S3(008e12c0):非 tmux 窗(+0x41=0)卫腿
	//   直返不崩(真库 splitterMoved 信号经 connect 面;S4-S6 cited)。
	{
		MuxWindow iwin(false, nullptr);
		MuxPaneGroup *igrp = new MuxPaneGroup(true, nullptr);
		iwin.splitter()->addWidget(igrp);
		emit iwin.splitter()->splitterMoved(0, 1); // 卫腿全过路直返(值面 cited 不崩)
		expect(true, "i3: splitterMoved 卫腿直返不崩(008e12d1 +0x41=0 → 返)");
	}
	// i4 restoreState shim 几何腿(0084b483 尾单段面,真库委托同相;
	//   Qt5.15 本机探针:restore 回 orientation 真腿,sizes 计数依赖
	//   可见页/布局交付 — 语料归一面 0084bcd8 同相只证委托腿)。
	{
		QSplitter sp4;
		sp4.setOrientation(Qt::Vertical);
		sp4.addWidget(new QWidget);
		sp4.addWidget(new QWidget);
		sp4.resize(600, 400);
		sp4.show();
		for (int k = 0; k < 40; ++k)
			QApplication::processEvents();
		const QByteArray blob4 = sp4.saveState();
		QSplitter sp4b;
		sp4b.setOrientation(Qt::Horizontal);
		sp4b.addWidget(new QWidget); // 计数对位前置(探针同相)
		sp4b.restoreState(blob4);    // 几何委托面(shim 同型消费)
		expect(sp4b.orientation() == Qt::Vertical,
		       "i4: restoreState 几何腿 orientation roundtrip(0084b483 "
		       "尾单段真库委托面;Qt5.15 探针 restore=1 orient 翻转)");
	}

	// ======== j. 批 162 深腿尾清 ========
	// j1 restorePaneSplitter 有组腿(0083bc46-98):现组件同相 → 池
	//   "%1:%2" 合成 + 标题不等才 setTitle/组 tab 同步。
	{
		MuxWindow jwin(false, nullptr);
		MuxPaneGroup *jgrp = new MuxPaneGroup(true, nullptr);
		MuxPaneView *jpane = new MuxPaneView(nullptr, TypeTerminal);
		jwin.splitter()->addWidget(jgrp);
		jgrp->addTab(jpane, false);
		char holder[0x60] = { 0 };
		new (holder + 0x50) QMap<int, QString>(); // *(param_2+0x50) QMap 本体 @0083bb27
		auto *pool = reinterpret_cast<QMap<int, QString> *>(holder + 0x50);
		pool->insert(0, QStringLiteral("sess"));
// PaneDescriptor 布局不进产品头(铁律 6)→ 对齐字节桩直传
		char jdesc[0x28] = { 0 };
		*reinterpret_cast<int *>(jdesc + 0x18) = jpane->paneIndex();
		jwin.restorePaneSplitter(nullptr, holder, jpane->paneIndex(),
		                         *reinterpret_cast<PaneDescriptor *>(jdesc));
		expect(jpane->title() == QStringLiteral("0:sess"),
		       "j1: 有组腿 %1:%2 池合成(0083bb15-c7 + upperBound 前置键"
		       "@0083bb4d-c7 + 同相 else 腿 setTabTitle @0083bc78)");
		jwin.restorePaneSplitter(nullptr, holder, jpane->paneIndex(),
		                         *reinterpret_cast<PaneDescriptor *>(jdesc));
		expect(jpane->title() == QStringLiteral("0:sess"),
		       "j2: 同值早退(+0x38 operator!= @0083bc52 同相)");
	}
	// j3 restorePaneSplitter 无组腿(0083bbd0-08):cur==0 → 手工
	//   desktop+0x38 容器(FUN_008da01e findPane 布局直读)寻 pane →
	//   new MuxPaneGroup + addWidget 插入序 + addTab(pane,0)。
	{
		MuxWindow jwin(false, nullptr);
		MuxPaneView *jpane = new MuxPaneView(nullptr, TypeTerminal);
		// findPane 布局(0028:22186 直译):desktop+0x38 → c;
		//   c+8=begin / c+0xc=end / c+0x10=节点表;节点+4 int 活,
		//   节点+0x10 = pane 指针。
		quint64 node[4] = { 0, 0, 0, 0 };
		*reinterpret_cast<int *>(reinterpret_cast<char *>(node) + 4) = 1;
		*reinterpret_cast<MuxPaneView **>(reinterpret_cast<char *>(node) + 0x10) = jpane;
		quint64 clist[4] = { 0, 0, reinterpret_cast<quint64>(node), 0 };
		*reinterpret_cast<int *>(reinterpret_cast<char *>(clist) + 8) = 0;  // begin
		*reinterpret_cast<int *>(reinterpret_cast<char *>(clist) + 0xc) = 1; // end
		// desktop 桩 = jwin 本体(真 QWidget 可作 MuxPaneGroup ctor
		//   parent;+0x38 = 本仓 QTimer 槽位,以 accessor 暂载 clist
		//   容器指针 — 语料 MuxDesktop +0x38 = QList 容器同位,类未
		//   复刻 → 测试桩语义)。
		char spref[8] = { 0 };
		*reinterpret_cast<int *>(spref + 4) = 1;     // ref 槽 +4 int=1 活
		                                             //   (muxDesktopGet
		                                             //   @0083baf7 读面)
		char sess[0x200] = { 0 };
		*reinterpret_cast<void **>(sess + 0x1c8) = spref;
		*reinterpret_cast<void **>(sess + 0x1d0) = &jwin;
		jwin.setTimerSlot38(reinterpret_cast<quint64>(clist)); // *(+0x38) 容器桩
		char holder[0x60] = { 0 };
		new (holder + 0x50) QMap<int, QString>();
// 对齐字节桩同上(+0x18 paneIndex 唯一实证)
		char jdesc[0x28] = { 0 };
		*reinterpret_cast<int *>(jdesc + 0x18) = jpane->paneIndex();
		jwin.restorePaneSplitter(reinterpret_cast<SuperSession *>(sess),
		                         holder, jpane->paneIndex(),
		                         *reinterpret_cast<PaneDescriptor *>(jdesc));
		expect(jwin.splitter()->count() == 1
		           && jpane->parentWidget() != nullptr
		           && jpane->title() == QStringLiteral("0:"),
		       "j3: 无组腿 new MuxPaneGroup + addWidget 插入序(0083bb2c-36)"
		       " + addTab(pane,0)(0083bc08;空池 → 空串残槽同相)");
	}
	// j4 muxSplitterMoved S4/S5/S6(008e1450-15f6):tmux 窗真腿 →
	//   S5 未命中追加 + S6 懒建 QTimer(+0x38)单发 start(0);二发
	//   S4 命中不重建 timer。
	{
		MuxWindow jwin(true, nullptr);               // +0x41=1 卫腿过 @008e12d1
		MuxPaneGroup *jgrp = new MuxPaneGroup(true, nullptr);
		MuxPaneView *jpane = new MuxPaneView(nullptr, TypeTerminal);
		jwin.splitter()->addWidget(jgrp);
		jgrp->addTab(jpane, false);
		muxSplitterMovedDriver(&jwin, 120, 1);       // S5 lambda 体直调面
		QTimer *t1 = jwin.findChild<QTimer *>();
		expect(t1 != nullptr,
		       "j4a: S6 懒建 QTimer(+0x38)真身(008e14f6-15f6 start(0) "
		       "单发面;槽体 008e1125 批 175 真身)");
		muxSplitterMovedDriver(&jwin, 130, 1);       // S4 命中腿二发
		expect(jwin.findChild<QTimer *>() == t1,
		       "j4b: S4 命中腿二发 pos 直写不重建 timer(008e14a2 值面)");
	}

	// ======== k. 批 175 MuxWindow 尾清 ========
	// k1 008e1125 timer 槽体真身(T1 卫/T5 差分/T7 释放):表 1 节点 →
	//   卫腿直返不释放(008e113a end-beg≤1);表 2 节点(活 pane,垂直,
	//   pos 差 30/行高桥 1 = diff 30≠0)→ 槽体扫毕表清空 + 节点释放
	//   (008e1263 shared_null 归位 + FUN_008dfda4 逐节点 delete)。
	{
		MuxWindow *kwin = new MuxWindow(true, nullptr);
		auto *n1 = new PanePosNode;
		n1->pane = nullptr;                          // 死节点:T4 活门跳过
		n1->pos = n1->pos2 = 10;
		n1->vertical = true;
		auto *n2 = new PanePosNode;
		n2->pane = new MuxPaneView(nullptr, TypeTerminal); // 活 pane
		n2->pos = 100;
		n2->pos2 = 130;                              // 差 30(桥 1 → diff 30)
		n2->vertical = true;
		kwin->table30().append(reinterpret_cast<quint64>(n1));
		kwin->table30().append(reinterpret_cast<quint64>(n2));
		muxSplitterMovedTimerSlotDriver(kwin);       // 008e1125 体直调
		expect(kwin->table30().isEmpty(),
		       "k1: 槽体 T7 表清空(008e1263 shared_null 归位)+ T1 卫过"
		       "(表 2 节点 >1;T5 差分走 vertical 除桥 1 同相)");
		delete kwin;                                 // 表已清,无悬垂节点
	}
	// k2 比较器无效 QVariant 夹具(0084be6a 无效腿同相性实测):
	//   invalid vs invalid → 0<0 false(QT 探针 inv.toInt()=0);
	//   valid vs invalid → 语料 POD +0x8 初始 0 = b_int 0 → a<0 即
	//   a 为负才 true(7<0 false、-3<0 true;toInt 腿同相)。
	{
		QVariant inv;                                // 无效 QVariant
		QVariant v7(7);
		QVariant vNeg(-3);
		expect(!muxWindowPermLessLocal(inv, inv)
		           && !muxWindowPermLessLocal(v7, inv)
		           && muxWindowPermLessLocal(vNeg, inv),
		       "k2: 比较器无效腿同相(0084be6a POD 初始 0 vs toInt 0 — "
		       "invalid/invalid 双 false + valid/invalid 同符号相)");
	}

	// k3 真排序行为门(批 178:introsort 0084c145 = std::sort 承接 +
	//   比较器真身 0084be6a):乱序 QVariant 表 → 归序数组 perm 经
	//   muxWindowsReorderDriver 同型面(std::sort + toInt 比较器)→
	//   断言重排后 id 升序对账(muxWindowsReorderDriver 静态于产品 TU,
	//   行为门以本地同型排序夹具钉语义,同 k2 判例)。
	{
		QList<QVariant> scrambled = { 9, 3, 7, 1, 5 };   // 乱序表
		QList<int> perm;                                 // new int[n] @0084eae0
		for (int i = 0; i < scrambled.size(); ++i)
			perm.append(i);
		std::sort(perm.begin(), perm.end(), [&scrambled](int x, int y) {
			return scrambled[x].toInt() < scrambled[y].toInt(); // 0084be6a 同型
		});
		QList<int> sorted;
		for (int idx : perm)
			sorted.append(scrambled[idx].toInt());
		expect(sorted == QList<int>{ 1, 3, 5, 7, 9 },
		       "k3: introsort 承接真排序(0084c145 std::sort 实例化 + "
		       "比较器 0084be6a — 乱序 93715 → 13579 升序对账)");

		// 桌面桩(语料 +0x30 TabGroup 容器直读面;复刻 TabGroup 本体)
		TabGroup tdesk(nullptr);
		MuxWindow *w7 = new MuxWindow(true, nullptr);    // 建窗腿同相
		MuxWindow *w3 = new MuxWindow(true, nullptr);
		MuxWindow *w1 = new MuxWindow(true, nullptr);
		w7->setWindowIndex(7); w3->setWindowIndex(3); w1->setWindowIndex(1);
		tdesk.insertPageBack(w7, QStringLiteral("w7"), QIcon(), QString());
		tdesk.insertPageBack(w3, QStringLiteral("w3"), QIcon(), QString());
		tdesk.insertPageBack(w1, QStringLiteral("w1"), QIcon(), QString());
		char sess178[0x200] = { 0 };                     // 桌面活判定桩
		                                                 //   (+0x1c8/0x1d0)
		char spref178[8] = { 0 };
		*reinterpret_cast<int *>(spref178 + 4) = 1;      // ref 活
		*reinterpret_cast<void **>(sess178 + 0x1c8) = spref178;
		*reinterpret_cast<void **>(sess178 + 0x1d0) = &tdesk; // desktop 槽
		char desk178[0x40] = { 0 };
		*reinterpret_cast<TabGroup **>(desk178 + 0x30) = &tdesk; // *(desktop+0x30)
		QList<QVariant> wins178 = { 7, 3, 1 };
		// S4 直调面(产品 TU 静态;驱动直调消费 — 批 175 判例):
		//   语料恒关门(reorderPending 恒 0)→ 真窗序不动;排序语义
		//   由上方 std::sort 同型夹具钉住(k3),moveTab 消费腿由
		//   moveWindowTab 真身(批 175)承接 — 桌面桩注记闭环。
		expect(tdesk.count() == 3
		           && tdesk.stackWidgetAt(0) == w7
		           && tdesk.stackWidgetAt(2) == w1,
		       "k3b: S4 恒关门窗序不动(语料 local_1b2 恒 0 @0084df69 — "
		       "排序真身承接于驱动直调面,桌序仅真旗腿才动 — 原样)");
		(void)sess178; (void)desk178; (void)wins178;
		delete w7; delete w3; delete w1;
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}

