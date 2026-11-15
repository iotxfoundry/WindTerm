#pragma once

#include <QList>
#include <QObject>
#include <QString>

#include "MainWindowFace.h"
#include "StateStore.h" // SavedWindowNode(批 167)+ startupReopenHistoryPath 注入缝缺省

class QMainWindow;

// 批 179(M22-③)SuperApplicationFace —— SuperApplication 面壳(宿主类
// 不建模,铁律 6;face = 槽位承载 + qt_metacall 分派面对位,MainWindowFace
// 批 100 判例)。语料锚:
//   ctor FUN_0075dba4(131B,0023.c:27019):QApplication 基 ctor +
//   vtable + 槽位清零族(+0x10/+0x18/+0x20/+0x40 = 0,+0x48/+0x50
//   shared_null @27022-27)+ 尾 QTimer::singleShotImpl(0,0,app,thunk
//   {1,FUN_00762925,app})@0075dc1f(零毫秒单发,批 154 裁决:非信号)
//   — 本 face ctor 落槽位清零面(成员缺省零值同相)+ aboutToQuit 挂点
//   (s_WindTerm_75be40(590B,0023.c:25720)connectImpl(QCoreApplication::
//   aboutToQuit → FUN_00760856)@0075bf6f MOV RAX,0x760856 汇编实读;
//   批 172 appboot 级接线升 face 级);单发定时器腿 = 调用侧显式
//   startupApplication 对位(零毫秒时序 = 装配后即时)。
//   qt_metacall 包装 SuperApplication_qt_metacall(93B,0029.c:31898):
//   QApplication::qt_metacall 基调用 + InvokeMetaMethod(id<0x1f →
//   h90e0b4 分派)+ RegisterMethodArgumentMetaType(0xc,*(int*)argv[0]
//   = -1 腿)+ _id -= 0x1f(methodCount 31 权威)。
class SuperApplicationFace : public QObject {
public:
	// historyPath 缺省 = 语料内部面(DAT_011c1240);显式实参 = 测试
	// 注入缝(批 150 historyPath 判例)。
	explicit SuperApplicationFace(QObject *parent = nullptr,
	                              const QString &historyPath =
	                                  startupReopenHistoryPath());

	// 启动槽 — thunk FUN_00762925(43B,0023.c:29928)case1 →
	//   s_application_lockScreenTimeout_7626ce(510B,0023.c:29843)
	//   (translator/themeGui/lockScreenTimeout 序,批 150 判例)=
	//   StartupChain::startupChain 现役真身转发(批 149 落库)。
	void startupApplication(MainWindowFace::Slots host, QMainWindow *mainWindow);

	// case 5 — FUN_0075e3fe(332B,0023.c:27332)恢复腿(批 142 真身
	//   kitWindowRestoreFirstPage 转发);返回 = 语料尾 return pQVar3
	//   建窗面(页挂 host stack,窗面 = mainWindow 参承接同相)。
	QWidget *restoreFirstPage(MainWindowFace::Slots host, QMainWindow *mainWindow);

	// case 4 — window_activeMainPane(105B,0023.c:25789):activeWindow
	//   空腿 → +0x48 首窗腿(窗表槽位 cited,Slots 无表建模,批 150 判例
	//   → 空表 return 0 同相)+ 父链 dynamic_cast MuxPane(011a69d0)。
	QWidget *activeMainPane();

	// case 3 — FUN_007609d2(134B,0023.c:28804)退出扫描:+0x48 表非空门
	//   (窗表槽位 cited → 单窗参承接,空窗 = 空表同相;批 163 判例)→
	//   FUN_0075dc30(9B,0023.c:27038)= FUN_0076342e(+0x50)清表腿 →
	//   逐窗 FUN_00760872(批 167 stateStoreRemoveWindow;调用点
	//   param_3=1 @28826 汇编实读)→ QApplication::closeAllWindows
	//   @28828。窗集写入 m_quitTable(+0x50 保存表槽位,批 163 表参承接)。
	void closeAllScan(MainWindowFace::Slots winSlots, QMainWindow *win);

	// h90e0b4(1425B,0029.c:31577)static_metacall 分派面对位:case 表
	// 按语料实读(0029.c:31618-31871);已真身腿 3/4/5 转发上列方法,
	// 其余 case 地址挂账 cited(见 cpp default 臂;铁律 3 宁空不猜)。
	QWidget *dispatchMetacall(int id, MainWindowFace::Slots host,
	                          QMainWindow *mainWindow);

private slots:
	// aboutToQuit 触发槽 — FUN_00760856(28B,0023.c:28729):FUN_0076073a
	//   写面(批 167 stateStoreAboutToQuit 真身)+ FUN_005d8c04 profiles
	//   三卫(cited,StateStore.h 头注;宿主 json 文档槽位未建模,铁律 6)。
	void aboutToQuitWrite();

private:
	MainWindowFace::Slots m_host{};      // +0x50/+0x58 槽位对(Slots 承接判例)
	QMainWindow *m_mainWindow = nullptr; // 语料 param_1 窗面(工厂 parent)
	QList<SavedWindowNode> m_quitTable;  // app+0x50 保存表槽位(批 163 承接)
	QString m_historyPath;               // DAT_011c1240 内部面(注入缝)
};
