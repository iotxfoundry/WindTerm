// 批 167(M19-②)roundtrip 断言 — reopen.history 保存侧真身闭环:
// 写面 stateStoreWriteReopenHistory(FUN_0076073a)产出 → 读门
// startupRestoreGate(FUN_0075ffcc,批 150 真身)→ 页名/窗数/几何
// 对账。挂接方式:本文件独立于 tests/CMakeLists.txt(禁碰),待
// 车道合流时 foreach 追加 "statereopen" 即接入;本轮以手工 g++
// 配方(tools/re/BUILD.md)编译验证。
#include <QApplication>
#include <QDataStream>
#include <QFile>
#include <QMainWindow>
#include <QStackedWidget>
#include <QTemporaryDir>
#include <cstdio>

#include "Actions/KitBar.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/MainWindowFace.h"
#include "Actions/MuxPaneGroup.h"
#include "Actions/MuxPaneView.h"
#include "Actions/MuxWindow.h"
#include "Actions/SplitterGroup.h"
#include "Actions/StartupChain.h"
#include "Actions/StateStore.h"
#include "Actions/TabGroup.h"
#include "Editor/ProfileLoader.h"
#include "Sessions/WorkspaceLoader.h"

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

	// ── t6. 三件套保存侧(批 168):8051f2/80ee76/80efd2/805398/
	//     8069b0/810c4e 对偶 + 522056 骨架读回对账 ──
	{
		QVariantList lib;
		const QString u1 = QStringLiteral(
		    "11111111-1111-1111-1111-111111111111");
		const QString u2 = QStringLiteral(
		    "22222222-2222-2222-2222-222222222222");
		QVariantMap s1;
		s1.insert(QStringLiteral("session.uuid"), u1);
		s1.insert(QStringLiteral("text"), QStringLiteral("t1"));
		s1.insert(QStringLiteral("data"), QStringLiteral("d1"));
		if (!SessionStore::upsert(lib, s1, false))
			++fails; // 8069b0 param_3==0 → 1(@00806axx)
		if (lib.size() != 1)
			++fails; // 805398 追加腿
		QVariantMap s0;
		s0.insert(QStringLiteral("session.uuid"), QString());
		if (SessionStore::upsert(lib, s0, false))
			++fails; // 空 uuid 卫 → 0
		if (lib.size() != 1)
			++fails; // 空 uuid 不追加
		const QVariantMap back = Workspace::sessionByUuid(lib, u1);
		if (back.value(QStringLiteral("text")).toString()
		        != QStringLiteral("t1")
		    || back.value(QStringLiteral("data")).toString()
		           != QStringLiteral("d1"))
			++fails; // 810056 读回对账
		if (!SessionStore::setField(lib, u1, QStringLiteral("text"),
		                            QStringLiteral("t2"), false))
			++fails; // 810c4e 值变 → 1
		if (Workspace::sessionByUuid(lib, u1)
		        .value(QStringLiteral("text"))
		        .toString()
		    != QStringLiteral("t2"))
			++fails; // set 读回
		if (SessionStore::setField(lib, u1, QStringLiteral("text"),
		                           QStringLiteral("t2"), false))
			++fails; // 对等门(FUN_00aef040)→ 0
		if (!SessionStore::setField(lib, u1, QStringLiteral("data"),
		                            QVariant(), false))
			++fails; // null → removeMember 腿 → 1
		if (Workspace::sessionByUuid(lib, u1).contains(
		        QStringLiteral("data")))
			++fails; // 摘键读回
		QVariantMap s1b;
		s1b.insert(QStringLiteral("session.uuid"), u1);
		s1b.insert(QStringLiteral("text"), QStringLiteral("t3"));
		s1b.insert(QStringLiteral("data"), QStringLiteral("d3"));
		if (!SessionStore::replaceByUuid(lib, u1, s1b))
			++fails; // 8051f2 命中
		if (lib.size() != 1)
			++fails; // 替换不增
		if (Workspace::sessionByUuid(lib, u1)
		        .value(QStringLiteral("data"))
		        .toString()
		    != QStringLiteral("d3"))
			++fails; // 换写读回
		if (SessionStore::replaceByUuid(lib, u2, s1b))
			++fails; // 未命中 → 0
		if (!SessionStore::takeByUuid(lib, u1))
			++fails; // 80ee76 首命中摘除
		if (!lib.isEmpty())
			++fails; // count-1
		if (SessionStore::takeByUuid(lib, u1))
			++fails; // 二次摘除 → 0
		// 80efd2 倒序组摘除 + removed 注入缝
		QVariantList lib2;
		const QString uA = QStringLiteral(
		    "aaaaaaaa-1111-1111-1111-111111111111");
		const QString uB = QStringLiteral(
		    "bbbbbbbb-2222-2222-2222-222222222222");
		const QString uC = QStringLiteral(
		    "cccccccc-3333-3333-3333-333333333333");
		QVariantMap ga, gb, gc;
		ga.insert(QStringLiteral("session.uuid"), uA);
		ga.insert(QStringLiteral("session.group"),
		          QStringLiteral("临时IP设备"));
		gb.insert(QStringLiteral("session.uuid"), uB);
		gb.insert(QStringLiteral("session.group"),
		          QStringLiteral("临时IP设备"));
		gc.insert(QStringLiteral("session.uuid"), uC);
		gc.insert(QStringLiteral("session.group"),
		          QStringLiteral("本地设备"));
		lib2 << ga << gb << gc;
		QVariantList removed;
		if (!SessionStore::takeByGroup(lib2, QStringLiteral("临时IP设备"),
		                               &removed))
			++fails; // uVar6 OR 累积
		if (removed.size() != 2 || lib2.size() != 1)
			++fails; // 摘除计数对账
		if (Workspace::sessionByUuid(lib2, uC).isEmpty())
			++fails; // 别组保留
		// 磁盘腿:806958 对偶(ProfileLoader::saveSessions 现役)
		QVariantMap sd;
		sd.insert(QStringLiteral("session.uuid"), u2);
		sd.insert(QStringLiteral("text"), QStringLiteral("tS"));
		sd.insert(QStringLiteral("data"), QStringLiteral("dS"));
		QVariantList lib3;
		lib3 << sd;
		ProfileLoader pl(tmpDir.path()
		                 + QStringLiteral("/profiles.save"));
		if (!pl.saveSessions(lib3) || pl.loadSessions().size() != 1)
			++fails; // 落盘/读回对账
		// 522056 骨架读回(text/data/uuid 对账;批 154 读侧)
		QString title = QStringLiteral("  ws  ");
		Workspace::LoaderResult lr =
		    Workspace::workspaceLoader(nullptr, nullptr, title, lib3);
		if (title != QStringLiteral("ws"))
			++fails; // trimmed 门 @005220c0
		if (!lr.keys.contains(QStringLiteral("dS"))
		    || !lr.kinds.contains(3))
			++fails; // data 键 + kind3(非 Terminal/Browser 腿)
	}

	// ── t7. 页 payload 骨架帧对账(批 173,M21-①;8cf0c8 升真)──
	{
		// 写侧产 payload 非空(Terminal 页,KitWindow 命中腿)
		const QByteArray payload0 = table.at(0).payload;
		if (payload0.size() < 8)
			++fails; // 骨架帧 ≥ magic+首段头
		// 页表壳(count/current/页名)剥离 — 语料页 payload = 7669b2
		//   帧内逐页 BA 段(见 5C-REPORT 布局语义 diff)。
		const int pageIdx = payload0.lastIndexOf(
		    QByteArrayLiteral("\xb9\xe7\xe6\x26\xff\xff\xff\xff\x00"
		                      "\x00\x00\x01\x01"));
		if (pageIdx < 0)
			++fails; // Terminal 页骨架帧在位(magic+三段头指纹)
		const int payloadLen = static_cast<int>(
		    static_cast<quint32>(payload0.at(pageIdx - 4) & 0xff) << 24
		    | static_cast<quint32>(payload0.at(pageIdx - 3) & 0xff)
		          << 16
		    | static_cast<quint32>(payload0.at(pageIdx - 2) & 0xff)
		          << 8
		    | static_cast<quint32>(payload0.at(pageIdx - 1) & 0xff));
		const QByteArray frame = payload0.mid(
		    pageIdx, payload0.size() - pageIdx < payloadLen
		                 ? payload0.size() - pageIdx
		                 : payloadLen);
		QDataStream in(frame);
		quint32 magic = 0;
		in >> magic;
		if (magic != 0xb9e7e626u)
			++fails; // @008cf173 家族魔数(样本 b9e7e626 实证)
		QByteArray a, b, c;
		in >> a >> b >> c; // 三段 << BA 序(@008cf37b/490/587)
		if (in.status() != QDataStream::Ok)
			++fails; // 帧自洽(整读尽)
		// ── 批 177(M22-①):blobA 树实体框架对账(带实体树夹具)──
		// 夹具:活体 KitWindowFace 宿主(TerminalWindowFace;pg0 已 delete
		//   于 t5 尾 — UAF 判例防)+ MuxWindow 现役树(只读引用面):
		//   MuxPaneGroup(splitter 直子,KitDock 对位)+ TabGroup
		//   insertPageBack 一页(MuxPaneView,objectName 对位)。
		{
			TerminalWindowFace hostPage; // 活体 KitWindowFace(壳零字段判例)
			MuxWindow mwin(false, nullptr);
			MuxPaneGroup *grp = new MuxPaneGroup(true, nullptr);
			mwin.splitter()->addWidget(grp);
			MuxPaneView *pv = new MuxPaneView(nullptr, TypeTerminal);
			pv->setObjectName(QStringLiteral("PaneX"));
			grp->addTab(pv, /*normal=*/false);
			// 将 mwin 挂到宿主页域(findChildren 承接面):
			mwin.setParent(&hostPage, Qt::Widget); // 显式 Widget 旗(非窗型)
			const QByteArray a2 = stateStoreSerializeSplitterBlob(&hostPage);
			if (a2.isEmpty())
				++fails; // 树实体非空(blobA 段升真门)
			QDataStream in2(a2);
			int childCount = -1;
			in2 >> childCount;
			if (childCount != mwin.splitter()->count())
				++fails; // <<int(QSplitter::count)@8cf2e4 对账
			QByteArray tb, ss;
			in2 >> tb >> ss; // tabbar BA + saveState BA(@8cf32d/8cf353)
			if (tb.isEmpty() || ss.isEmpty())
				++fails; // 双 BA 段在位
			QDataStream tin(tb);
			int cur = -1, tc = -1;
			tin >> cur >> tc; // @8b9250/8b9257(cur/count 头)
			if (tc != grp->tabGroup()->count() || tc != 1)
				++fails; // tabbar count 对账
			QString tabName;
			QByteArray paneState;
			tin >> tabName >> paneState; // @8b92e2/8b929e
			if (tabName != QStringLiteral("PaneX"))
				++fails; // tab objectName 对账
			if (!paneState.isNull())
				++fails; // paneIndex==0 → null BA(8c37a4 默认腿 -1 序)
			if (static_cast<int>(ss.size()) !=
			    mwin.splitter()->saveState().size())
				++fails; // QSplitter::saveState 真库委托同长(几何差仅记)
			mwin.setParent(nullptr, Qt::Widget); // 摘除(同旗对称)
			(void)pv; // grp 树随 mwin 摘除后由 Qt 父链清偿(pv 归 grp)
		}
		// t7 帧对账(t7 夹具 mwin 已摘除 — 恢复基线):
		// 原版 674B 段(blobA 229B)字段序对账 = 上面 tb/ss 拆解已覆盖
		// (count→tab BA→saveState BA 序;内容级几何因环境差仅框架对账,
		// 任务书指定)。
		if (b.size() != 1 || quint8(b.at(0)) != 1)
			++fails; // blobB = pane+0x70 旗标单字节(ctor +0x70=1;
			         //   原版样本 B[0]=01 同相)
		if (c.size() != 3)
			++fails; // blobC 三 bool 段(样本 00 00 00 同相)
		if (!in.atEnd())
			++fails; // 尾钩段我方无(壳零虚槽;原版 9B 钩体产物差仅记)
		// Editor 页 cast 未命中腿?—— EditorWindow 亦 KitWindowFace 子类
		//   (命中);真"未命中"腿由非 KitWindow 页承载,无现役产物面
		//   (011ab390 cast 面 = 页工厂全部产物;空 BA 腿不测)。
	}

	printf("statereopen: %s (%d fails)\n", fails ? "FAIL" : "OK", fails);
	return fails ? 1 : 0;
}
