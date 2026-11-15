#include "StateStore.h"

#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStackedWidget>

#include "WorkspaceLoader.h" // collectorPaneTypeName(FUN_008c9e64 真身)

// === stateStoreSerializePages — FUN_007669b2(571B,0023.c:33468)
// 窄面真身(头注全出处;&4 段 cited 不落;8cf0c8 页 payload cited
// 空实现 — 读侧空 payload 页挂闭环判例,批 150 mwctest e2)。===
QByteArray stateStoreSerializePages(MainWindowFace::Slots host,
                                    quint32 flags)
{
	QByteArray blob; // local_88 = shared_null @007669e6
	// &4 段调用面 FUN_007682d2(focusMode 缓存)cited 域 — 本窄面
	// 只承接 &4==0 腿(唯一 reopen 链调用点 0x76096b param_3=1 /
	// 0x75e43e param_3=2,汇编 EDX 实读)。
	if ((flags & 4u) != 0)
		return blob; // @766b58-bf5 cited 段(见头注)不可达同相
	QDataStream out(&blob, QIODevice::WriteOnly); // @007669ef(mode 2)
	if (host.f58 == nullptr)
		return blob; // QStackedWidget 槽位缺位卫(0x58==0 同相)
	const int count = host.f58->count(); // @007669ef QStackedWidget::count
	out << count; // @007669f5 operator<<(int)
	const int current = host.f58->currentIndex(); // @007669fa currentIndex
	out << current; // @007669ff
	for (int i = 0; i < count; ++i) { // @00766a35-6b do-while iVar3<iVar2
		QString pageName;
		QWidget *page = host.f58->widget(i); // @00766a71 widget(i)
		// dynamic_cast KitWindow(011ab390)@00766a8b — 命中 →
		//   FUN_008c9e64 面板名真身(批 159);未命中/空页 →
		//   QObject::objectName(@00766aed-f1,lVar4=0 同相)。
		pageName = Workspace::collectorPaneTypeName(page); // @00766a9e-aa / 766aed
		out << pageName; // operator<<(QString)@00766aaf
		// 页 payload = s_kit_startupSessions_8cf0c8(w,param_3)
		// @00766a31 — 2233B cited(>500B 邻档;KitWindow 深域),
		// 空实现(铁律 3 宁可留空;读侧空 payload 页挂闭环)。
		QByteArray pagePayload; // local_58 = shared_null @00766a3c
		out << pagePayload; // operator<<(QByteArray)@00766a3c-40
	}
	return blob; // param_1 返回 @00766c1d
}

// === stateStoreRemoveWindow — FUN_00760872(344B,0023.c:28740)
// 真身。FUN_00764d74(170B,0023.c:31906)= QList removeAll 对位面
// (@7608a1-8f2 表头 detach ×2 — QList 值语义承接);命中直返
// @7609b3;未命中保存体 @7608fc-9c3。===
void stateStoreRemoveWindow(MainWindowFace::Slots winSlots,
                            QList<SavedWindowNode> &table,
                            QMainWindow *win, bool clearList)
{
	// FUN_00764d74 扫描/移除腿(0x764d74-96x 直译:begin..end 逐项
	// == 比较 → removeAt;命中 return 1;未命中 return 0 — 返回值
	// 语料仅作腿选择,removeAll 门 @7608c0-8f2 内联消费同相)。
	for (int i = 0; i < table.size(); ++i) {
		if (table.at(i).win == win) {
			table.removeAt(i); // QListData::remove @0076496x 内联面
			return;            // @7609b3 命中直返(汇编 JZ 实读)
		}
	}
	// 未命中保存体(@7608fc-9c3):
	//   FUN_0076f4d6(win,0)@76091f focusMode 退 — 405B cited(批 150
	//   读侧 startupRestoreGate focusMode 腿同判);node.focusMode =
	//   [win+0x31] 读腿 @76090d — MainWindow +0x31 槽位宿主类未建模,
	//   cited 缺省 0(铁律 3;KitWindow 实例字段批升真)。
	SavedWindowNode node; // local_48 0x20 块,@7608fc shared_null 起
	node.focusMode = false; // +0x31 读腿 cited 缺省 0(见头注;显式
	                        //   清零防栈垃圾位 — AGENTS 坑 15 判例)
	node.win = win;       // @760924 MOV [RSP+0x10],RBP 实读
	node.geometry = win->saveGeometry(); // @760937 CALL 0x4c1580
	node.payload = stateStoreSerializePages(winSlots, 1u); // FUN_007669b2
	                     // (param_3=1,汇编 EDX=1 @760960 实读)@76096b
	if (!clearList) {
		// param_3==0 → 清表腿 FUN_0076342e(app+0x50)@7609c3
		// (JZ 7609c0 汇编实证;49B = QList 置 shared_null + 旧表
		// dispose FUN_0075baa0 — QList 值语义 clear 承接同相)。
		table.clear();
	}
	table.append(node); // FUN_007639a0(120B,0023.c:30860)@76099c
}

// === stateStoreWriteReopenHistory — FUN_0076073a(268B,0023.c:28686)
// 真身 + FUN_005dd6fc(250B,0019.c:13916)写盘腿。===
bool stateStoreWriteReopenHistory(const QList<SavedWindowNode> &table,
                                  const QString &historyPath)
{
	QByteArray blob; // local_50 = shared_null @0076076a
	QDataStream out(&blob, QIODevice::WriteOnly); // @0076076f(mode 2)
	out << quint32(0xb9e7e626u); // @0076076f-74(汇编 MOV ESI 实读;
	                             //   反编译 -0x461819da)
	// 窗数 = +0x50 表 end-begin(@00760780-86;QList size 同相)。
	out << int(table.size());
	for (const SavedWindowNode &n : table) { // @0076078c-b10 逐窗
		out << n.geometry;  // operator<<(QByteArray +0x10)@28702
		out << n.payload;   // operator<<(QByteArray +0x18)@28704
		out << n.focusMode; // QDataStream::operator<<(bool +8)@28706
	}
	// FUN_005dd6fc(DAT_011c1240,&blob)@00760800:QFile(path)
	//   open(WriteOnly=2)@005dd770 + QIODevice::write 全量
	//   @005dd781 + bVar3 = (size == written)@005dd786;路径腿 =
	//   cfg_ensureProfileDir "%1/profiles/%2/%3" + "global/reopen.
	//   history"(startupReopenHistoryPath 读侧同面复用,批 150)。
	QFile f(historyPath);
	// 路径目录确保腿(cfg_ensureProfileDir 尾 @005d7e9e-f2:
	//   QFileInfo(path).absolutePath → QDir.mkpath)— 读侧
	//   startupReopenHistoryPath 仅产路径串,ensure 腿属写盘面
	//   FUN_005dd6fc→005d7dae 前置,e2e 批 150 mwctest e1 mkpath
	//   同相(mwctest 手工 mkpath 先行;产品写侧须自 ensure)。
	QDir().mkpath(QFileInfo(historyPath).absolutePath()); // @005d7ec8-f2
	if (!f.open(QIODevice::WriteOnly))
		return false; // cVar1='\0' → bVar3=false @005dd770-76
	return f.write(blob) == qint64(blob.size()); // @005dd781-86
}
