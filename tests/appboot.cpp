// 批 166(M19-①):可运行应用骨架 — 5c 对表"我方侧"载体。
// offscreen 启动 → 真实装配链(mwctest d1-d7 判例形态)→ startupChain
// 真调(FUN_007626ce 语料序;恢复门 FUN_0075ffcc 真身:无状态文件 →
// false 腿 → 失败腿 kitWindowRestoreFirstPage 建 "Terminal" 首页,
// 批 142/150 真身)→ QTimer::singleShot(0,quit) 存活一拍事件循环
// (SuperApplication ctor 0075dc1f 零毫秒单发定时器判例)→ 干净退出。
#include <QApplication>
#include <QFile>
#include <QMainWindow>
#include <QStackedWidget>
#include <QTemporaryDir>
#include <QTimer>
#include <QWidget>
#include <cstdio>
#include "Actions/MainWindowFace.h"
#include "Actions/StartupChain.h"
#include "Actions/StateStore.h" // 批 172:aboutToQuit 挂点真身
#include "Actions/SuperApplicationFace.h" // 批 179:face 级挂点

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
	if (fails)
		return 1;

	// ======== 批 172(M20-③):aboutToQuit 挂点闭环(尾部追加;
	// 既有断言不动)— 5c 我方全生命周期自洽:boot → 写 reopen.history
	// (临时路径注入缝,批 150 historyPath 显式实参判例;不打真用户
	// 目录)→ 退出触发面 stateStoreAboutToQuit(FUN_00760856 真身,
	// s_WindTerm_75be40 connectImpl 汇编 0x75bf6f 挂点)→ 重启 appboot
	// 态(二次构造 = 新 MainWindowFace + startupChain 重跑,语料 main
	// FUN_0051f3ab exec 返回后 dtor/重启同相)→ restoreGate 真读对账
	// (页数/页名,statereopen t4 判例形态)。
	{
		QTemporaryDir tmpDir; // 注入缝:临时 reopen.history 路径
		if (!tmpDir.isValid()) {
			printf("appboot: FAIL (tmpdir)\n");
			return 1;
		}
		const QString hist = tmpDir.path()
		                     + QStringLiteral("/global/reopen.history");
		// 退出触发面(窗集装配 = 现役 stack 页族,closeAll 扫描腿
		//   FUN_007609d2 逐窗摘除对位 — stateStoreRemoveWindow
		//   FUN_00760872 param_3=1 调用点同相):
		QList<SavedWindowNode> table;
		stateStoreRemoveWindow(sl, table, &mwHost, true);
		stateStoreAboutToQuit(table, hist); // FUN_00760856 真身
		QFile hf(hist);
		if (!hf.open(QIODevice::ReadOnly) || hf.size() < 16)
			++fails; // 写面真调落盘(FUN_0076073a + 005dd6fc)

		// 重启 appboot 态:二次构造跑 startupChain(门真读 → 恢复腿)
		QMainWindow mwHost2;
		MainWindowFace mf2(&mwHost2);
		MainWindowFace::Slots sl2 = mf2.hostSlots();
		if (sl2.f50 == nullptr || sl2.f58 == nullptr) {
			printf("appboot: FAIL (restart slots null)\n");
			return 1;
		}
		mwHost2.show();
		startupChain(sl2, &mwHost2); // 恢复门真读 hist(缺省路径腿
		                             //   不可达 → 注入缝直达恢复腿)

		// restoreGate 对账(页数/页名):写侧窗 1 页(TerminalWindow
		//   现役)→ 恢复后恰 1 页且同名(statereopen t4 判例形态)。
		if (sl2.f58->count() != 1)
			++fails; // payload 头 local_c8=1 → 恢复页数对账
		QWidget *rpg = sl2.f58->widget(0);
		if (rpg == nullptr
		    || rpg->objectName() != QStringLiteral("TerminalWindow"))
			++fails; // 页名对账(逐页 QString → 工厂腿)
		if (sl2.f58->currentIndex() != 0)
			++fails; // currentIndex 对账(payload local_c4=0)
	}

	// ======== 批 179(M22-③):SuperApplicationFace 产品挂点(尾部追加;
	// 既有断言不动)— appboot 装配升 face 级:启动链经 face 调度
	// (startupApplication = thunk FUN_00762925 case1 → 7626ce 序)+ 分派
	// 面可达(h90e0b4 case4/case5)+ aboutToQuit→写面挂 face(FUN_00760856
	// 挂点,批 172 appboot 级接线升 face 级;s_WindTerm_75be40 connectImpl
	// 0x75bf6f 汇编实读)。
	{
		QTemporaryDir tmpDir3;
		if (!tmpDir3.isValid()) {
			printf("appboot: FAIL (tmpdir3)\n");
			return 1;
		}
		const QString hist3 = tmpDir3.path()
		                      + QStringLiteral("/global/reopen.history");
		SuperApplicationFace appFace(nullptr, hist3); // ctor = FUN_0075dba4 槽位面

		// face 调度启动链(新装配态,免扰既有断言;门 false 腿同前判例)
		QMainWindow mwHost3;
		MainWindowFace mf3(&mwHost3);
		MainWindowFace::Slots sl3 = mf3.hostSlots();
		if (sl3.f50 == nullptr || sl3.f58 == nullptr) {
			printf("appboot: FAIL (face slots null)\n");
			return 1;
		}
		mwHost3.show();
		appFace.startupApplication(sl3, &mwHost3); // 00762925 case1 → 7626ce
		if (sl3.f58->count() != 1)
			++fails; // 门 false(无状态文件)→ 失败腿恰一页
		if (sl3.f58->widget(0) == nullptr
		    || sl3.f58->widget(0)->objectName() != QStringLiteral("TerminalWindow"))
			++fails; // 7626ce 尾恢复腿产物页名

		// case4 分派(window_activeMainPane 105B:activeWindow 空腿 +
		// 父链 MuxPane cast 未命中 → 0)—— offscreen 无活动 MuxPane。
		QWidget *pane = appFace.dispatchMetacall(4, sl3, &mwHost3);
		if (pane != nullptr)
			++fails; // @25802/25812 未命中腿

		// case5 恢复路径分派(FUN_0075e3fe → 批 142 真身):门 false →
		// 失败腿建 "Terminal" 首页;返回 = 语料尾 return pQVar3 窗面。
		QMainWindow mwHost4;
		MainWindowFace mf4(&mwHost4);
		MainWindowFace::Slots sl4 = mf4.hostSlots();
		QWidget *r4 = appFace.dispatchMetacall(5, sl4, &mwHost4);
		if (r4 == nullptr)
			++fails; // case5 返回窗面非空(31639-41 写回 argv 面)
		if (sl4.f58->count() != 1)
			++fails; // case5 页挂腿对账
		if (sl4.f58->widget(0) == nullptr
		    || sl4.f58->widget(0)->objectName() != QStringLiteral("TerminalWindow"))
			++fails; // case5 页名(007665ae "Terminal")

		// aboutToQuit 挂 face:closeAllScan 装配窗集(FUN_007609d2 case3
		//   逐窗摘除腿对位)→ 事件循环退出触发 face 槽(FUN_00760856 真身
		//   → stateStoreAboutToQuit;hist3 注入缝)→ 落盘对账。
		appFace.closeAllScan(sl4, &mwHost4);
		QTimer::singleShot(0, &app, SLOT(quit()));
		app.exec(); // aboutToQuit → aboutToQuitWrite(FUN_00760856)
		QFile hf3(hist3);
		if (!hf3.open(QIODevice::ReadOnly) || hf3.size() < 16)
			++fails; // face 级写面落盘(FUN_0076073a + 005dd6fc)
	}

	printf("appboot: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
