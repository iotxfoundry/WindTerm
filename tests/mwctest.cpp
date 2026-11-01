// 冒烟断言(ctest 门;铁律 5:断言语料行为,非教科书行为)——
// onFocusChanged 槽体真身(批 92,FUN_008e0bb2):验证 S4-S6 tab bar
// state 翻转腿(008e0da5:祖先→"Active";S2 锚 = win.focusWidget(),
// 窗口失活保持 — 008e0c9e 反汇编)、S8-S9 焦点链回溯不崩、S0/S10
// 更新禁更撤防(FUN_008dfd89→008dfd7c)。
#include <QApplication>
#include <QTabBar>
#include <QTimer>
#include <cstdio>
#include "Actions/MuxWindow.h"
#include "Actions/MuxPaneGroup.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv); // focusChanged 信号源(qcoreapp)
	int fails = 0;
	QWidget *out = nullptr; // 常驻焦点外顶层

	MuxWindow win(QStringLiteral("smoke"), nullptr);
	win.resize(300, 200);

	MuxPaneGroup *group = new MuxPaneGroup(true, &win); // S3 findChildren 面
	group->show();
	win.show();

	// 与槽体 S4 同面取 bar(TabGroup 装配的;非另造)
	QTabBar *bar = group->findChild<QTabBar *>(QString());
	if (bar == nullptr) {
		printf("mwc_smoke: FAIL (no QTabBar under group)\n");
		return 1;
	}

	// 焦点进 win → S5 真腿:bar 是 win 焦点链祖先 → "Active"
	QApplication::setActiveWindow(&win);
	bar->setFocus(); // 焦点落在 tab bar(S4 同 face 部件)
	QApplication::processEvents();
	if (bar->property("state").toString() != QStringLiteral("Active"))
		++fails; // 语料 008e0da5-dac:祖先 → "Active"

	// 焦点移出(常驻顶层防失焦回收)—— 语料语义:槽内锚 = this->focusWidget()
	//   (008e0c9e-8e0ca6 反汇编:receiver = 0x20(%rsp) = this;窗口失活后
	//   QWidget::focusWidget 仍返回窗口内旧焦点件)→ state 保持 "Active"
	//   = 原版行为(isaprobe34 实证;不按"教科书清空"断言,铁律 5)
	out = new QWidget;
	out->show();
	QApplication::setActiveWindow(out);
	out->setFocus();
	QApplication::processEvents();
	printf("dbg2: app.fw=%p win.fw==bar? %d upd=%d state='%s'\n",
	       (void *)QApplication::focusWidget(),
	       (int)(win.focusWidget() == (QWidget *)bar),
	       (int)win.updatesEnabled(),
	       bar->property("state").toString().toUtf8().constData());
	if (bar->property("state").toString() != QStringLiteral("Active"))
		++fails; // 语料 008e0ca6 锚语义:win.fw 仍 bar → Active 保持

	// 直接喂槽复核(语料槽面 = 只读 win.focusWidget(),幂等):
	QMetaObject::invokeMethod(&win, "onFocusChanged",
	                          Q_ARG(QWidget *, nullptr),
	                          Q_ARG(QWidget *, nullptr));

	// S0/S1+S10 更新禁更腿:槽外沿(enabled 默认 true)
	if (!win.updatesEnabled())
		++fails; // FUN_008dfd7c 撤防后必须回 true

	printf("mwc_smoke: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
