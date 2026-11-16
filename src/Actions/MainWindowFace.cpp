#include "MainWindowFace.h"

#include <QStackedWidget>

#include "KitBar.h"

// === MainWindowFace(QMainWindow*) ===
// 转写 FUN_007662e6(109B,decomp-part-0023.c:33100;汇编
// 007662e6-0076634e):
//   operator_new(0x48)+KitBar::KitBar(bar,param_1)@007662f4-302
//     → 存 param_1+0x50 @00766307;
//   operator_new(0x30)+QStackedWidget::QStackedWidget(stack,param_1)
//     @0076630b-1e → 存 param_1+0x58 @00766323;
//   QMainWindow::addToolBar(param_1,1,bar)@00766333(字面 1 照语料);
//   QMainWindow::setCentralWidget(param_1,stack)@0076633f(汇编
//     mov 0x58(%rbx),%rsi 实证第二实参;Ghidra 折叠勘补);
//   QWidget::hide(bar)@00766348(尾 jmp;hide this = bar = +0x50 侧)。
// 宿主类 MainWindow 未建模(不落他人写域)→ +0x50/+0x58 槽位由
// 返回 Slots 结构承载;行为零增删。
MainWindowFace::MainWindowFace(QMainWindow *host)
	: m_host(host)
{
	KitBar *bar = new KitBar(host);                 // operator_new(0x48)+KitBar @007662f4-302
	m_slots.f50 = bar;                              // *(param_1+0x50) = bar @00766307
	QStackedWidget *stack = new QStackedWidget(host); // operator_new(0x30)+QStackedWidget @0076630b-1e
	m_slots.f58 = stack;                            // *(param_1+0x58) = stack @00766323
	host->addToolBar(Qt::LeftToolBarArea, bar);     // QMainWindow::addToolBar(param_1,1,bar)@00766333(字面 1 = LeftToolBarArea)
	host->setCentralWidget(stack);                  // QMainWindow::setCentralWidget(param_1,stack)@0076633f(第二实参汇编实证)
	bar->hide();                                    // QWidget::hide(bar)@00766348(初始隐藏,bar 侧)
}

// mainWindow_connectSignals(1043B)主窗信号接线真身(结构段,7 路)
void MainWindowFace::connectAppSignals()
{
	// ①②③ 三条子接线族(FUN_0076b9da / 0076663e / 007662e6)— cited
	// ④ qApp 信号 FUN_0090e018 → 槽 FUN_007662ce(smeta 011a6ce0)— cited
	// ⑤ QApplication::focusChanged → 槽 FUN_0076dcae — cited
	// ⑥⑦ 配置对象信号 FUN_008fd3d0 / FUN_008fd3fc → 槽 FUN_0076aee6,
	//    flags **0x82**(QueuedConnection|UniqueConnection)— cited
	// 其余 3 路挂在 +0xe0/+0xe8 QPointer 对上(与 QuickBar/TransferBar 同型)— cited
}
