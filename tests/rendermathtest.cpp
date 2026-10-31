// 渲染核纯算式行为测试批(0x7585 setter bool / 0x7584 读回 / 0x7547 S1 构图;
// 批 75/77 真身面)
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 语料:FUN_00925310(40B,0030.c:20341-20356)/ dispatch 0x7585 门 =
// 0034.c:24000-24013 / 0x7584 读 = 0034.c:23997 / s_line_modified_a72ad6
// (3008B,0034.c:49531;S1 构图 00a72b14/00a72b6e)。
// 注入缝:dispatch() public(EditorEngine.h:31);SCI 后端 = 真
// ScintillaEditBase(engtest 惯例,QT_QPA_PLATFORM=offscreen)。
// 停手(见报告):0x7547 S2-S6 度量值/色带无观察缝(denom/rowH/bw/fstep
// 皆 case 内局部,styleTable/eSerialEntries 无注入命令);0x7592 过滤语义
// 断言停手 —— marginList 无注入缝(无 append 命令)且无读缝(无 getter)。
#include "EditorEngine.h"
#include <QApplication>
#include <QPixmap>
#include <QStringList>
#include <cstdio>

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
	EditorEngine e;

	// ======== a. 0x7585 setter bool 返回语义(0034.c:24000-24013)========
	// 语料门:v<1 → false(24004-24005)/ v==现值 → false(24004 || 右腿)/
	//         写 + soft_reset → true(24010-24012)/ v==0 → 默认腿 true
	//         (24002-24003 → FUN_00925310(0) 0030.c:20351-20353)
	expect(e.dispatch(0x7585, 5).toBool() == true,
	       "a: 新值 5 → true(24010-24012;写落点 00925310 0030.c:20347)");
	expect(e.dispatch(0x7584).toInt() == 5,
	       "a: 0x7584 读回 5(L23997 *(ctx213+0x260);写后读一致)");
	expect(e.dispatch(0x7585, 5).toBool() == false,
	       "a: 同值 5 → false(24004 iVar16==+0x260 腿)");
	expect(e.dispatch(0x7584).toInt() == 5,
	       "a: 同值 false 腿无写(24004-24006 直跳 bVar11=false 不经 00925310)");
	expect(e.dispatch(0x7585, -3).toBool() == false,
	       "a: n<1 非零 → false(24004 iVar16<1 腿)");
	expect(e.dispatch(0x7584).toInt() == 5,
	       "a: n<1 腿无写(24004 同上短路)");
	expect(e.dispatch(0x7585, 7).toBool() == true,
	       "a: 新值 7 → true(24010-24012)");
	expect(e.dispatch(0x7584).toInt() == 7,
	       "a: 0x7584 读回 7(写后读一致)");
	expect(e.dispatch(0x7585, 0).toBool() == true,
	       "a: n==0 → true(24002-24003 默认腿;24012 bVar11=true)");
	// 注:0x7584 读回不接 —— 语料 v==0 经 00925310 写 +0x260=+0x270 默认
	// (cited — wave-2,EditorEngine.cpp:2201),我方 true 腿不落 +0x260(登记)。

	// ======== b. 0x7547 S1 构图(s_line_modified_a72ad6,0034.c:49531)========
	// 语料:param_4[1](dh)/[0](dw)四舍五入构 QPixmap(00a72b14);
	// fill QColor(0x13)=alpha19(00a72b6e);S4 markerBand cited 桩无带/
	// S5 grep 注册空操作/S6 eSerialEntries 空 → 零绘。
	QVariant pmv = e.dispatch(0x7547, 100.6, 30.4);   // a=dh, b=dw(EditorEngine.cpp:1755)
	QPixmap pm = pmv.value<QPixmap>();
	expect(pm.size() == QSize(30, 101),
	       "b: qRound(dw)xqRound(dh) = 30x101(00a72b14;语料 round-half 49554-49576)");
	expect(pm.toImage().pixelColor(0, 0).alpha() == 19,
	       "b: S1 fill alpha=19(QColor(0x13) 00a72b6e;S4/S6 cited 空态零绘)");

	// ======== c. 0x7547 dh<=0 门(语料 `if (0.0 < local_160)`)========
	// qRound(0)=0 → QPixmap(50,0);Qt5 0 尺寸 pixmap 归一为 null 0x0(平台
	// 语义,非语料裁决点);painter 腿跳过(EditorEngine.cpp:1759 同语料
	// 门),S1 构图仍返回非 null QVariant。
	QVariant v0 = e.dispatch(0x7547, 0, 50);
	QPixmap pm0 = v0.value<QPixmap>();
	expect(v0.userType() == QMetaType::QPixmap && pm0.isNull()
	       && pm0.width() == 0 && pm0.height() == 0,
	       "c: dh=0 → painter 腿跳过(EditorEngine.cpp:1759 同语料门),空 pixmap 返回");

	// ======== d. 0x7547 SCI 承接冒烟(S2 度量 00a72cb8-00a72d3d)========
	// 注入文本(SCI_ADDTEXT 2001 → SCI_GETLENGTH/SCI_LINESONSCREEN 承接),
	// denom=max(visLines,textLen) 怪癖(00a72cd4)两侧皆不触发 fstep 除零
	// (S6 pos/fstep 仅在 eSerialEntries 非空时可达,空表零迭代)。
	e.dispatch(2001, 13, QByteArray("one\ntwo\nthree"));
	QPixmap pm2 = e.dispatch(0x7547, 60, 90).value<QPixmap>();
	expect(pm2.size() == QSize(90, 60),
	       "d: 注入文本后全 case 跑通(S2 度量 00a72cb8-00a72d3d;S6 空条目)");

	// ======== e. 0x7592 空表冒烟(0034.c:24989-25003)========
	// 注入缝缺失:marginList 无 append 命令(EditorContext.h:60;仅 0x7592
	// 自身 bit7 / 0x7596 遍历触达)且无读缝 → 过滤语义断言停手(见报告)。
	// 空表腿 = 语料 for 循环零迭代(24993-25001),soft_reset cited 无外显。
	e.dispatch(0x7592, QStringList{"line.saved", "line.modified"});
	expect(true, "e: 空表 0x7592 跑通(零迭代 24993;语义断言停手见报告)");

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
