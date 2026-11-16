#include "Actions/Kit/SuperApplicationFace.h"

#include <QApplication>
#include <QStackedWidget>
#include <QWidget>

#include "Actions/Kit/KitWindowFactory.h"
#include "Actions/Mux/MuxPane.h"
#include "Actions/StartupChain.h"

#include "Editor/Config/CTerminalConfig.h"

#include <QJsonDocument>
#include <QJsonObject>

// === SuperApplicationFace ctor — FUN_0075dba4(131B,0023.c:27019)
// 槽位清零面 @27022-27(成员缺省零/空同相)+ aboutToQuit 挂点
// s_WindTerm_75be40(590B,0023.c:25720)connectImpl(aboutToQuit →
// FUN_00760856)@0075bf6f(汇编 MOV RAX,0x760856 实读;批 172 appboot
// 级接线升 face 级 — 槽 aboutToQuitWrite 承接 FUN_00760856)。===
SuperApplicationFace::SuperApplicationFace(QObject *parent,
                                           const QString &historyPath)
	: QObject(parent), m_host(), m_mainWindow(nullptr),
	  m_quitTable(), m_historyPath(historyPath)
{
	// 语料 ctor 尾 QTimer::singleShotImpl(0,0,app,thunk{1,FUN_00762925,
	// app})@0075dc1f — 单发定时器非信号(批 154 裁决);启动槽触发 =
	// 调用侧 startupApplication 对位(face 级调度点,时序同相:装配后
	// 零拍)。产品 QEventLoop 零拍语义不发明(铁律 6 — 调用侧承接)。
	// connectImpl 面(QCoreApplication::staticMetaObject @25770)→
	//   本 face 真槽(收发同体 = 语料 sender=receiver=app 同相面)。
	connect(qApp, &QCoreApplication::aboutToQuit, this,
	        &SuperApplicationFace::aboutToQuitWrite); // @0075bf6f 挂点
}

// === startupApplication — thunk FUN_00762925(43B,0023.c:29928)case1
// → s_application_lockScreenTimeout_7626ce(510B,0023.c:29843)=
// StartupChain::startupChain 现役真身(批 149 转写;translator/themeGui/
// lockScreenTimeout 序;恢复门 FUN_0075ffcc + 失败腿 FUN_0075e3fe)。===
void SuperApplicationFace::startupApplication(MainWindowFace::Slots host,
                                              QMainWindow *mainWindow)
{
	m_host = host;             // +0x50/+0x58 槽位面(语料 thunk param_2+0x10 = app)
	m_mainWindow = mainWindow; // 工厂 parent 面
	startupChain(host, mainWindow); // 7626ce 真身 @29941 JMP 腿(批 150)
}

// === restoreFirstPage — case5 腿 FUN_0075e3fe(332B,0023.c:27332)
// 真身转发(批 142 kitWindowRestoreFirstPage;语料尾 return pQVar3 =
// 活动窗面,本 face 页挂 host stack → mainWindow 参承接同相)。===
QWidget *SuperApplicationFace::restoreFirstPage(MainWindowFace::Slots host,
                                                QMainWindow *mainWindow)
{
	m_host = host;
	m_mainWindow = mainWindow;
	kitWindowRestoreFirstPage(host, mainWindow); // FUN_0075e3fe @31636
	// 语料返回 = FUN_0075e0f8 建窗面(批 142 对位腿不落建窗;活动窗 =
	// mainWindow 同相面)。
	return mainWindow;
}

// === activeMainPane — case4 腿 window_activeMainPane(105B,0023.c:
// 25789)真身:activeWindow() 空 → +0x48 首窗腿(窗表槽位 cited,
// Slots 无表建模 — 空表 return 0 同相 @25800-03 门)+ 父链 dynamic_cast
// MuxPane(PTR_PTR_011a69d0 面)@25806。===
QWidget *SuperApplicationFace::activeMainPane()
{
	QWidget *w = QApplication::activeWindow(); // @25797
	for (; w != nullptr; w = w->parentWidget()) // @25810 父链腿
		if (dynamic_cast<MuxPane *>(w) != nullptr) // __dynamic_cast 011a69d0
			return w;                              // @25808 命中面
	return nullptr; // 首窗空表/未命中 → 0 @25802/25812
}

// === closeAllScan — case3 腿 FUN_007609d2(134B,0023.c:28804):表非空
// 门 @28813(窗表 +0x48 槽位 cited → 单窗参承接,win==nullptr = 空表
// 同相)→ FUN_0075dc30(9B,0023.c:27038)= FUN_0076342e(app+0x50)
// 清表腿 → 逐窗 FUN_00760872(param_3=1 @28826;批 167
// stateStoreRemoveWindow 真身)→ QApplication::closeAllWindows
// @28828。窗集落 m_quitTable(app+0x50 保存表槽位,写面消费同相)。===
void SuperApplicationFace::closeAllScan(MainWindowFace::Slots winSlots,
                                        QMainWindow *win)
{
	if (win == nullptr)
		return; // *(int *)(+0x48+8)==*(+0x48+0xc) 空表门 @28813 同相
	// FUN_0075dc30(app+0x50)@28814 = FUN_0076342e(49B,0023.c:30575)
	// 清表腿(QList 置 shared_null;批 167 stateStoreRemoveWindow
	// clearList 腿同函数)。
	m_quitTable.clear(); // @28814(批 172 判例:调用侧装配现役窗集)
	stateStoreRemoveWindow(winSlots, m_quitTable, win, true); // @28826 param_3=1
	QApplication::closeAllWindows(); // @28828
}

// === dispatchMetacall — SuperApplication_h90e0b4(1425B,0029.c:31577)
// static_metacall 分派面对位(id = 语料 param_3;case 表实读 31618-31871):
//   0/1/2/10/0xb/0x1b/0x1c/0x1d = 信号发射面(0090e018/04c/084 activate
//     /windowOpacity 族)— connect 消费域,本 face 零接收者(铁律 3,
//     发射面不落);
//   case 3   FUN_007609d2  退出扫描 — closeAllScan 真身转发(本文件);
//   case 4   window_activeMainPane(105B,0023.c:25789)— activeMainPane;
//   case 5   FUN_0075e3fe  恢复腿 — restoreFirstPage 真身转发(批 142);
//   其余 case(6-9,0xc-0x1a,0x1e)体未解/cited(0029.c 地址挂账):
//     6:FUN_0075dc3a(18B,27048 = +0x48 表拷出腿,窗表槽位域)
//     7:FUN_00760ffe(467B,29028 LanguageEvent 派发)
//     8:FUN_0075c6a0(0023.c)— QByteArray 返回腿
//     9:FUN_0075db80 — QList 返回腿
//     0xc:FUN_0075cfcc / 0xd:+0x10 字节读 / 0xe:FUN_0075d0a4
//     0xf:FUN_0075d108 / 0x10:FUN_0075d3f8 / 0x11:s_ShowFolders_75d22e
//     0x12:FUN_0075d506 / 0x13:FUN_0075d6c0 / 0x14:FUN_0075d6d0(QMap)
//     0x15:s_application_searchEngines_75dc4c(557B,27058 QList)
//        — 批 184 升真:searchEngines getter 真身(本文件);
//     0x16:s_application_searchEngines_75e56a(4882B,27388)⚠ 批 184
//        定性更名:TextView::searchOnline 辅助(TextView qt_metacall
//        8f3a74 case 0x95/0x96 方法表实读;非 setter 非 app 域)—
//        TextView 车道 cited 不落(头注挂账)
//     0x17:FUN_0075debe / 0x18:FUN_0075d732 / 0x19:FUN_0075d73c(53B,
//         26759 lockScreenTimeout 存值腿)
//     0x1a:FUN_0075d78c / 0x1b-0x1d:windowOpacity_75d79c 族 /
//     0x1e:FUN_0075d956 — 全 cited 不落(铁律 3;宿主槽位批升真)。
// 返回:case4/5 活动窗面;其余 nullptr(default 直返 0 同相)。===
QWidget *SuperApplicationFace::dispatchMetacall(int id,
                                                MainWindowFace::Slots host,
                                                QMainWindow *mainWindow)
{
	switch (id) {
	case 3: // FUN_007609d2()@31629
		closeAllScan(host, mainWindow);
		break;
	case 4: // window_activeMainPane()@31632
		return activeMainPane();
	case 5: // FUN_0075e3fe()@31636
		return restoreFirstPage(host, mainWindow);
	default:
		break; // cited case 表(default 直返 0 同相 @31871-72)
	}
	return nullptr;
}

// === searchEngines(getter)— s_application_searchEngines_75dc4c(557B,
// 0023.c:27058)真身(批 184;metacall case 0x15 @31830 返回表写入):
// 键面 QByteArray("application.searchEngines")@27072 → global_setting_get
// (0075c458→0075c480 值卫面;键 as-given,0x1181568 键表指针 MOV 实读)
// → QVariant::toList → 逐元素 QVariant::toJsonObject(@0075dd29 4bb210)
// → QJsonDocument(json)→ toJson(Compact,EDX=1? @0075dd39 EDX=1 =
//   QJsonDocument::Compact 枚举值 0? Compact=0/Indented=1 — 语料 EDX=1
//   = Indented? Qt5 QJsonDocument::Indented=0x1... 实读 EDX=1 → Indented?
//   无空白差异对待:fromJson 往返等价,格式位 face 不判(铁律 3 不猜)
//   → 用 Compact=Qt 默认风格承载,键序 QJsonObject 字典序同相)→
// QString::fromAscii(@0075dd96 4c3220)非空腿 append(@0075ddd9)。
// 读通路 = CTerminalConfig 值面缺省 null(批 150;键未命中 → 空表)。
// 返回 = QStringList(逐引擎 JSON 串;语料 QList<QVariant> 承 QString)。
// ===
QStringList SuperApplicationFace::searchEngines() const
{
	QStringList out;
	const QVariantList list =
	    CTerminalConfig::instance()
	        ->value(QStringLiteral("application.searchEngines"))
	        .toList(); // @27072-db + toList 腿
	for (const QVariant &e : list) { // @0075dd1a-ff 循环腿
		const QString s = QJsonDocument(e.toJsonObject())
		                      .toJson(QJsonDocument::Compact); // @0075dd29-96
		if (!s.isEmpty())                    // *(int *)(local_68+4)!=0 门 @0075ddd9
			out.append(s);                   // qlist_qvariant_append @0075ddd9
	}
	return out; // param_1 表尾 @27170
}

// === setSearchEngines(setter)— s_application_searchEngines_6e761e
// (857B,0022.c:12876)写腿对位(批 184):页行集(QTableWidget 行 →
// QJsonObject{text/icon/url}@12884-13010,行集以 QVariantList 参承接,
// 页车道 cited)→ 尾 FUN_006e6c46(host,"application.searchEngines",
// QVariant(array),0)@13034 即时写腿 → FUN_008cbb2e(242B,0028.c:12894)
// → 00a8009c jsoncpp 成员按名写入(键面 as-given 不归一)。face 落
// CTerminalConfig::setValue 值面(批 169 setValueKitScoped 判例对偶;
// 归一面 760b2c 属页车道 — 头注怪癖)。===
void SuperApplicationFace::setSearchEngines(const QVariantList &engines)
{
	// QJsonArray 组装腿(@12884-13010):行集逐行 map 直承(页行 →
	//   map 的 text/icon/url 三键提写在页车道;face 参已收成品行集,
	//   值域同相)。空列表腿:QJsonArray()空组 @12879 无行循环直过。
	CTerminalConfig::instance()->setValue(
	    QStringLiteral("application.searchEngines"), QVariant(engines)); // @13034
}

// === aboutToQuitWrite — FUN_00760856(28B,0023.c:28729)真身:
// FUN_0076073a()写面(批 167/172 stateStoreAboutToQuit;历史路径 =
// ctor 注入缝)+ FUN_005d8c04 profiles 三卫 cited(StateStore.h 头注;
// 宿主 json 文档槽位未建模 — 铁律 6)。===
void SuperApplicationFace::aboutToQuitWrite()
{
	stateStoreAboutToQuit(m_quitTable, m_historyPath); // FUN_0076073a @28733
	// FUN_005d8c04(DAT_011c1240)@28735 — cited(见上)。
}

// s_application_windowOpacity_75c4d0(408B)读键真身
double readWindowOpacity()
{
	// global_setting_get(qApp, "application.windowOpacity", QVariant(1.0))
	//   → QVariant::toDouble — cited(全局读面未建模)
	return 1.0;
}

// s_application_windowOpacity_75c4d0(408B)应用真身
void applyWindowOpacity(double v)
{
	if (!(v > 0.0 && v <= 1.0))          // 语料门 0 < v <= 1
		return;
	for (QWidget *w : QApplication::topLevelWidgets()) // (+0x20→+0x48 窗口表)
		w->setWindowOpacity(v);          // QWidget::setWindowOpacity
}
