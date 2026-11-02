// KitBar 行为门(FUN_008b31b6 ctor / FUN_008b346e addKit / 转发
// FUN_0091a518 / 查询 FUN_008b337e·008b33c2)。
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 无头惯例:QApplication offscreen(tests/rendermathtest.cpp 同面);
// addKit S0 卫语料要求 parentWidget 非空(71335)→ 挂 QWidget host。
#include <QApplication>
#include <QSignalSpy>
#include <QToolBar>
#include <QToolButton>
#include <QWidget>
#include <cstdio>
#include "Actions/KitBar.h"

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
	QWidget host; // addKit S0 卫:parentWidget 链非空 @71335

	// ======== a. ctor(FUN_008b31b6,0027:71172,420B)========
	KitBar bar(&host);
	expect(bar.objectName() == QStringLiteral("KitBar"),
	       "a: objectName==\"KitBar\"(@008b321b-34)");
	expect(bar.allowedAreas() == Qt::ToolBarAreas(3),
	       "a: allowedAreas==3(setAllowedAreas(3) @008b32d8 语料字面)");
	expect(!bar.isFloatable(),
	       "a: 不可浮动(SUB81(param_1,0) @008b32e2)");

	// ======== b. addKit(FUN_008b346e,0027:71330)========
	// S7:makeToolButton(p5=1 → checkable)@008b3ec8 + setProperty("kit")
	//   @008b3ef0(DAT_00c8b3d1 二进制实证);S8 登记 +0x30;S9 QButtonGroup
	//   + addKitButtonToBar(FUN_008b305c;spacer 为 QWidget 非 QToolButton)。
	bar.addKit(3, QStringLiteral("Terminal"), QString());
	bar.addKit(7, QStringLiteral("Editor"), QString());
	// QToolBar 自带 extension 隐藏钮(QToolButton 子类)会被 findChildren
	//   误计 —— 按 "kit" property 过滤计数(批 93 断言修正)
	const QList<QToolButton *> btns = bar.findChildren<QToolButton *>();
	int kitBtns = 0;
	for (QToolButton *b : btns)
		if (b->property("kit").isValid())
			++kitBtns;
	expect(kitBtns == 2, "b: 带 kit property 的钮计 2(每 kit 一钮 S7)");
	bool kitProps = kitBtns == 2;
	for (QToolButton *b : btns) {
		const QVariant kp = b->property("kit");
		if (kp.isValid() && kp.toInt() != 3 && kp.toInt() != 7)
			kitProps = false;                            // extension 钮无 kit property,跳过
	}
	expect(kitProps,
	       "b: property(\"kit\")==index(@008b3ef0;QVariant(index) 挂钮)");
	expect(!btns.isEmpty() && btns[0]->isCheckable(),
	       "b: checkable(makeToolButton p5=1 @008b3ec8 → setCheckable(true))");

	// ======== c. toggled → kitActivated 转发 ========
	// 语料 S10 connect(btn::toggled → lambda FUN_008b2f80(59B):checked
	//   门 @008b2f9c → FUN_0091a518(this,index)= emit kitActivated
	//   (QMetaObject::activate 信号 0);kitActivated 串 @0xce43e0)。
	QSignalSpy spy(&bar, &KitBar::kitActivated);
	QToolButton *b3 = bar.buttonForIndex(3);
	QToolButton *b7 = bar.buttonForIndex(7);
	b3->setChecked(true);
	b7->setChecked(true); // S9 互斥组摘 b3:toggled(false) → 零发
	b7->setChecked(false); // checked=false 腿零发(FUN_008b2f80 门)
	expect(spy.count() == 2,
	       "c: 转发仅 checked=true 腿(2 发;false 腿零发 @008b2f9c)");
	expect(spy.count() == 2 && spy.at(0).at(0).toInt() == 3 &&
	           spy.at(1).at(0).toInt() == 7,
	       "c: index 实参透传(FUN_0091a518 activate 信号 0)");

	// ======== d. 查询面(FUN_008b337e 67B / FUN_008b33c2 100B)========
	// 语料:同 +0x30 节点{index,title,btn} — index 命中返节点钮
	//   (*(piVar4+4)),title 命中返节点钮(*(lVar3+0x10))→ 同节点同址;
	//   未命中两函数尾均返 0。
	expect(b3 == bar.buttonForTitle(QStringLiteral("Terminal")),
	       "d: index/title 命中同节点同钮(节点 +0x20/+0x10 同址)");
	expect(bar.buttonForIndex(99) == nullptr,
	       "d: 未命中 index → 0(FUN_008b337e 尾)");
	expect(bar.buttonForTitle(QStringLiteral("Nope")) == nullptr,
	       "d: 未命中 title → 0(FUN_008b33c2 尾)");

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
