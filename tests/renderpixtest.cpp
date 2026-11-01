// 渲染核像素级行为测试(0x7547 S1 构图 → QImage 读像素 / 0x753e 返回态冒烟)
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 语料:s_line_modified_a72ad6(3008B,0034.c:49531):dh=a(00a72ad9)/
//   dw=b(00a72aef)/ QPixmap(qRound(dw),qRound(dh))(00a72b14)/
//   fill QColor(0,0,0,19)(00a72b6e;0x13=alpha19)/ dh>0 才 QPainter
//   (00a72bbd);0x753e = FUN_00a417fe→FUN_00a41552 渲染核
//   (EditorEngine.cpp:1075,返回 EditorEngine.cpp:2011)。
// 注入缝:dispatch() public(EditorEngine.h:31);EditorEngine 无头构建
//   沿用批 80 rendermathtest 惯例(QT_QPA_PLATFORM=offscreen)。
// 停手(见报告):0x7547 S2 度量(denom 00a72cd4/rowH 00a72d0e)皆
//   case 内局部变量,dispatch 返回后无观察缝 → 副作用不可直接断言。
#include "EditorEngine.h"
#include <QApplication>
#include <QImage>
#include <QPixmap>
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

	// ======== a. 0x7547 返回 QPixmap,尺寸 = qRound(dw)xqRound(dh) ========
	// 语料:param_4[1](dh)/[0](dw) 四舍五入构 QPixmap(00a72b14);
	// a=dh/b=dw 映射(EditorEngine.cpp:2137-2139)。
	QVariant pmv = e.dispatch(0x7547, 100.6, 30.4);
	QPixmap pm = pmv.value<QPixmap>();
	expect(pmv.userType() == QMetaType::QPixmap,
	       "a: dispatch 返回 QPixmap(EditorEngine.cpp:2317 fromValue(pm))");
	expect(!pm.isNull(),
	       "a: dh=100.6>0 → 非 null(00a72bbd painter 腿进入)");
	QImage img = pm.toImage();
	expect(img.size() == QSize(30, 101),
	       "a: QImage 尺寸 30x101 = qRound(dw)xqRound(dh)(00a72b14;"
	       "qRound(30.4)=30/qRound(100.6)=101)");

	// ======== b. 全图像素 = QColor(0,0,0,19)(S1 fill 00a72b6e)========
	// S4 markerBand cited 桩无带(EditorEngine.cpp:2177-2182)/S5 grep
	//   注册占位(2205-2211)/S6 eSerialEntries 空 → 零迭代(2215
	//   range-for)→ 空态图像 = 纯 S1 fill;四角+中心五点抽样。
	const QColor fillRef(0, 0, 0, 19);           // QColor(0x13)=alpha19
	expect(img.pixelColor(0, 0) == fillRef,
	       "b: 左上 (0,0) = RGBA(0,0,0,19)(00a72b6e fill)");
	expect(img.pixelColor(29, 0) == fillRef,
	       "b: 右上 (w-1,0) = RGBA(0,0,0,19)(00a72b6e fill)");
	expect(img.pixelColor(0, 100) == fillRef,
	       "b: 左下 (0,h-1) = RGBA(0,0,0,19)(00a72b6e fill)");
	expect(img.pixelColor(29, 100) == fillRef,
	       "b: 右下 (w-1,h-1) = RGBA(0,0,0,19)(00a72b6e fill)");
	expect(img.pixelColor(15, 50) == fillRef,
	       "b: 中心 (w/2,h/2) = RGBA(0,0,0,19)(00a72b6e fill)");

	// ======== c. dh=0 门 → null QPixmap(00a72ad9 dh>0 才 QPainter)========
	// qRound(0)=0 → QPixmap(50,0);Qt 平台语义 0 尺寸 pixmap = null
	// (非语料裁决点,批 80 c 同款);painter 腿跳过(2141 行同语料门),
	// S1 构图仍返回 QPixmap 型 QVariant(2317 fromValue)。
	QVariant v0 = e.dispatch(0x7547, 0, 50);
	QPixmap pm0 = v0.value<QPixmap>();
	expect(v0.userType() == QMetaType::QPixmap && pm0.isNull()
	       && pm0.width() == 0 && pm0.height() == 0,
	       "c: dh=0 → painter 腿跳过(00a72ad9 `if (0.0 < local_160)`;"
	       "EditorEngine.cpp:2141 同门),null 0x0 pixmap 返回");

	// ======== d. S2 度量副作用 — 停手 ========
	// denom(00a72cd4)/rowH(00a72d0e)/bw(00a72d1a)/fstep(00a72d1e)
	// 皆 case 内局部变量,dispatch 返回后无 getter/无绘制外显观察缝
	// → 不可直接断言(登记,详见报告)。
	expect(true, "d: S2 度量断言停手(局部变量无观察缝,见报告)");

	// ======== e. 0x753e 返回态冒烟(FUN_00a417fe→FUN_00a41552)========
	// S2 起骨架深腿 cited(EditorEngine.cpp:2100-2111)→ 只断言非崩 +
	// 返回类型 QPixmap(EditorEngine.cpp:2011 return QVariant(out))。
	QVariant sv = e.dispatch(0x753e);
	expect(sv.userType() == QMetaType::QPixmap,
	       "e: 0x753e 返回 QPixmap(EditorEngine.cpp:2011;深腿 cited 仅类型冒烟)");

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
