// 批 167(M19-②)roundtrip 断言 — reopen.history 保存侧真身闭环:
// 写面 stateStoreWriteReopenHistory(FUN_0076073a)产出 → 读门
// startupRestoreGate(FUN_0075ffcc,批 150 真身)→ 页名/窗数/几何
// 对账。挂接方式:本文件独立于 tests/CMakeLists.txt(禁碰),待
// 车道合流时 foreach 追加 "statereopen" 即接入;本轮以手工 g++
// 配方(tools/re/BUILD.md)编译验证。
#include <QApplication>
#include <QFile>
#include <QMainWindow>
#include <QStackedWidget>
#include <QTemporaryDir>
#include <cstdio>

#include "Actions/KitBar.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/MainWindowFace.h"
#include "Actions/StartupChain.h"
#include "Actions/StateStore.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	int fails = 0;

	// 主窗 + 装配(bar/stack 真腿,批 133 FUN_007662e6 面)
	QMainWindow mw;
	mw.resize(713, 451); // 非常规尺寸防默认撞车(几何对账锚)
	MainWindowFace face(&mw);
	MainWindowFace::Slots sl = face.hostSlots();

	// 预挂两页(工厂真腿:Terminal + Editor;currentIndex=1)
	QWidget *pg0 = kitWindowFactory(QStringLiteral("Terminal"), &mw);
	QWidget *pg1 = kitWindowFactory(QStringLiteral("Editor"), &mw);
	if (pg0 == nullptr || pg1 == nullptr) {
		printf("statereopen: FAIL (factory)\n");
		return 1;
	}
	sl.f58->addWidget(pg0); // select=false
	sl.f58->addWidget(pg1);
	sl.f58->setCurrentIndex(1);

	QList<SavedWindowNode> table;

	// t1. 摘除+入表真身(FUN_00760872):node 四字段 face 对账
	stateStoreRemoveWindow(sl, table, &mw, true); // param_3=1 调用点同相
	if (table.size() != 1)
		++fails; // 未命中 → 保存体 append(FUN_007639a0)
	if (table.at(0).win != &mw)
		++fails; // node.win = param_2(@760924)
	if (table.at(0).geometry.isEmpty())
		++fails; // QWidget::saveGeometry 产物(@760937)
	if (table.at(0).focusMode)
		++fails; // +0x31 读腿 cited 缺省 0(铁律 3 注记)
	if (table.at(0).payload.isEmpty())
		++fails; // FUN_007669b2 窄面产出(count/currentIndex/页名)

	// t2. 命中直返腿(@7609b3):同 win 再摘除 → 表不增
	stateStoreRemoveWindow(sl, table, &mw, true);
	if (table.size() != 0)
		++fails; // 命中 → removeAt 直返,不走保存体

	// t3. 写面真身(FUN_0076073a + FUN_005dd6fc):blob 落盘
	QTemporaryDir tmpDir;
	if (!tmpDir.isValid()) {
		printf("statereopen: FAIL (tmpdir)\n");
		return 1;
	}
	const QString hist = tmpDir.path()
	                     + QStringLiteral("/global/reopen.history");
	// 再摘除一次(重新入表供写面消费)
	stateStoreRemoveWindow(sl, table, &mw, true);
	if (!stateStoreWriteReopenHistory(table, hist))
		++fails; // FUN_005dd6fc 全量写对账 bool(bVar3)
	QFile rf(hist);
	if (!rf.open(QIODevice::ReadOnly) || rf.size() < 16)
		++fails; // 文件落盘非空(魔数+count+窗段)

	// t4. roundtrip 闭环:读门 startupRestoreGate 真读写侧产出
	//     (批 150 真身;新宿主 face 承接恢复)
	QMainWindow mw2;
	MainWindowFace face2(&mw2);
	MainWindowFace::Slots sl2 = face2.hostSlots();
	if (!startupRestoreGate(sl2, &mw2, hist))
		++fails; // 魔数 0xb9e7e626 掩码门过 + count=1 → true
	if (sl2.f58->count() != 2)
		++fails; // 页数对账(payload 头 local_c8=2)
	if (sl2.f58->widget(0) == nullptr
	    || sl2.f58->widget(0)->objectName() != QStringLiteral("TerminalWindow"))
		++fails; // 页名对账 i=0(payload 逐页 QString → 工厂腿)
	if (sl2.f58->widget(1) == nullptr
	    || sl2.f58->widget(1)->objectName() != QStringLiteral("EditorWindow"))
		++fails; // 页名对账 i=1
	if (sl2.f58->currentIndex() != 1)
		++fails; // currentIndex 对账(payload local_c4=1 → select i=1)
	QWidget *restoredPage = sl2.f58->widget(0);
	QWidget *restoredWin = restoredPage != nullptr ? restoredPage->window()
	                                               : nullptr;
	if (restoredWin == nullptr)
		++fails; // 建窗腿 startupWindowCreate(FUN_0075e0f8,批 154)
	// 几何腿注记:restoreGeometry 失败/空 geometry → 语料 default 腿
	//   FUN_0075d6e8(74B,26718 居中缩放)— offscreen 未 show 窗
	//   restore 失败落 default = 语料行为(铁律 5,不按教科书断言
	//   尺寸复原;窗数/页名/currentIndex 对账为 roundtrip 权威面)。

	// t5. 空表写 → 门 false(0 页 local_91=false,批 150 判例同相)
	const QString hist0 = tmpDir.path()
	                      + QStringLiteral("/global/empty.history");
	QList<SavedWindowNode> emptyTable;
	if (!stateStoreWriteReopenHistory(emptyTable, hist0))
		++fails; // 空表亦全量写成功(bVar3 对账)
	{
		QMainWindow mw3;
		MainWindowFace face3(&mw3);
		if (startupRestoreGate(face3.hostSlots(), &mw3, hist0))
			++fails; // count==0 → local_91=false(@28436 语料门)
	}

	delete pg0;
	delete pg1;
	printf("statereopen: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
