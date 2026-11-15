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
#include <QPointer>
#include <QSplitter>
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

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
