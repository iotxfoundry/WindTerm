// 批 166(M19-①):可运行应用骨架 — 5c 对表"我方侧"载体。
// offscreen 启动 → 真实装配链(mwctest d1-d7 判例形态)→ startupChain
// 真调(FUN_007626ce 语料序;恢复门 FUN_0075ffcc 真身:无状态文件 →
// false 腿 → 失败腿 kitWindowRestoreFirstPage 建 "Terminal" 首页,
// 批 142/150 真身)→ QTimer::singleShot(0,quit) 存活一拍事件循环
// (SuperApplication ctor 0075dc1f 零毫秒单发定时器判例)→ 干净退出。
#include <QApplication>
#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include <QWidget>
#include <cstdio>
#include "Actions/MainWindowFace.h"
#include "Actions/StartupChain.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv); // QT_QPA_PLATFORM=offscreen(ctest 环)
	QMainWindow mwHost;           // 语料 MainWindow 面(mwctest d1:182)
	MainWindowFace mf(&mwHost);   // FUN_007662e6:KitBar→f50/stack→f58
	MainWindowFace::Slots sl = mf.hostSlots();
	if (sl.f50 == nullptr || sl.f58 == nullptr) {
		printf("appboot: FAIL (assembly slots null)\n");
		return 1;
	}
	mwHost.show();

	// 恢复门面(FUN_0075ffcc 真身,缺省路径 startupReopenHistoryPath
	//   FUN_005dd560;测试树无 profiles.config/reopen.history → 门 false)
	const bool restored = startupRestoreGate(sl, &mwHost);

	// startupChain 真调(FUN_007626ce;门 false → @007628a7 失败腿
	//   FUN_0075e3fe → FUN_007665ae "Terminal" 首页挂入,批 142 真身)
	startupChain(sl, &mwHost);

	// 存活一拍事件循环 → quit(0075dc1f singleShotImpl(0,...) 判例)
	QTimer::singleShot(0, &app, SLOT(quit()));
	app.exec();

	// 冒烟断言(d5-d8 判例形态)
	int fails = 0;
	if (restored)
		++fails; // 无状态文件 → 门 false 腿(@2842e else)
	if (sl.f58->count() != 1)
		++fails; // 失败腿恰一页(FUN_007665ae)
	QWidget *page = sl.f58->widget(0);
	if (page == nullptr
	    || page->objectName() != QStringLiteral("TerminalWindow"))
		++fails; // 首页 = TerminalWindow face(s_TerminalWindow_859902)
	if (sl.f58->currentIndex() != 0)
		++fails; // select=0 腿(@0x766548 门,链不改选页)

	printf("appboot: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
