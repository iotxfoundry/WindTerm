#pragma once

#include <QMainWindow>

class KitBar;
class QStackedWidget;

// MainWindowFace —— 语料 MainWindow 面装配函数(FUN_007662e6,109B,
// decomp-part-0023.c:33100)宿主语义壳(对位 MuxPane.h 批 71/87 壳惯例;
// 铁律 6:不落 MainWindow 类 —— 宿主类建模属他人写域)。
// 语料全读(109B 体,汇编 007662e6-0076634e 对齐无歧义):
//   operator_new(0x48)+KitBar::KitBar(bar,param_1)(FUN_008b31b6,0027:71172
//     已落库 src/Actions/KitBar.cpp)→ 存 param_1+0x50;
//   operator_new(0x30)+QStackedWidget::QStackedWidget(stack,param_1)
//     @0076631e → 存 param_1+0x58;
//   QMainWindow::addToolBar(param_1,1,bar)@00766333(第二参字面 1 照语料
//     = Qt::LeftToolBarArea;p3_notes_mp2 §7);
//   QMainWindow::setCentralWidget(param_1,stack)@0076633f(汇编 rsi=+0x58
//     实证,Ghidra 折叠 — p3_notes_mp2 §7 "参数 Ghidra 丢" 勘补);
//   QWidget::hide(bar)@00766348(尾 jmp,初始隐藏;语料 hide 的 this =
//     bar,+0x50 侧)。
// 触发点:mainWindow_connectSignals(0076b9ec,0023:36614)第 3 步
// FUN_0076663e 之后(汇编 0076ba0d 直调实证)。
// 下游消费(不在本壳转写域):页挂 s_HistoryHints_7664a2(244B,0023:
// 33200)、关闭扫描 FUN_007660e6(171B,0023:32991)—— MuxWindow 侧承接。
// +0x50/+0x58 宿主槽位经返回结构承载(本壳零自造行为)。
class MainWindowFace {
public:
	// 装配四件套(bar→+0x50 / stack→+0x58 / addToolBar(1) /
	// setCentralWidget / bar->hide()),返回宿主槽位对(FUN_007662e6 锚)。
	struct Slots {
		KitBar *f50;          // 语料 param_1+0x50(KitBar,QToolBar 子类)
		QStackedWidget *f58;  // 语料 param_1+0x58(QStackedWidget,central)
	};

	explicit MainWindowFace(QMainWindow *host);   // FUN_007662e6(109B)

	Slots hostSlots() const { return m_slots; }

private:
	QMainWindow *m_host;   // 语料 param_1(不持所有权 — 宿主侧)
	Slots m_slots;
};
