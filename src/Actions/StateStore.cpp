#include "StateStore.h"

#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStackedWidget>

#include "Editor/ProfileLoader.h"      // 806958/806904 对偶(批 169 现役)
#include "WorkspaceLoader.h" // collectorPaneTypeName/sessionByUuid 真身

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

// === stateStoreAboutToQuit — FUN_00760856(28B,0023.c:28729)触发
// 接线真身(头注全出处;s_WindTerm_75be40 connectImpl 汇编实读
// 0x75bf6f)。FUN_005d8c04 profiles 三卫 cited 不落(铁律 6)。===
void stateStoreAboutToQuit(const QList<SavedWindowNode> &table,
                           const QString &historyPath)
{
	stateStoreWriteReopenHistory(table, historyPath); // FUN_0076073a
	                                                  //   @28733 CALL
	// FUN_005d8c04(DAT_011c1240)@28735 — profiles 三卫 cited(见
	//   StateStore.h 头注;宿主 json 文档槽位未建模,不发明)。
}

// === SessionStore — 三件套 text/data/session.uuid 保存侧(批 168,
// 出处清单见 StateStore.h 头注;数组承载替 = QVariantList 注入面)。===

// FUN_00aef040(401B,0035.c:65951)同型比值对偶:异型即不等
//   (@00aef05b 同型门);null==null 相等(语料 case 0 双空同相)。
static bool sessionTrioVariantEqual(const QVariant &a, const QVariant &b)
{
	if (a.userType() != b.userType())
		return false; // 不同型不等(@00aef05b 门)
	switch (a.userType()) {
	case QMetaType::UnknownType: return true; // null==null(case 0)
	case QMetaType::Bool:
		return a.toBool() == b.toBool(); // case 5
	case QMetaType::Int:
	case QMetaType::LongLong:
		return a.toLongLong() == b.toLongLong(); // case 1/2
	case QMetaType::Double:
		return a.toDouble() == b.toDouble(); // case 3
	case QMetaType::QString:
		return a.toString() == b.toString(); // case 4
	default:
		return a == b; // 容器等 — QVariant 对等承载
	}
}

// 8051f2(304B,0025.c:40618)uuid 替换腿:空数组/空 uuid 卫
// (@0080528x 门)→ 顺序扫 json_get_string_default("session.uuid")
// 对等 → json_value_swap 槽位整条换写(lib[i]=session 同相)。
bool SessionStore::replaceByUuid(QVariantList &library,
                                 const QString &uuid,
                                 const QVariantMap &session)
{
	if (uuid.isEmpty()) // *(int *)(*(long *)param_2 + 4) == 0 卫
		return false;
	for (int i = 0; i < library.size(); ++i) { // +0xe0 数组腿
		const QVariantMap m = library.at(i).toMap();
		if (m.value(QStringLiteral("session.uuid")).toString() == uuid) {
			library[i] = session; // json_value_swap @008052f3-2a
			return true;
		}
	}
	return false; // 尾 return 0 同相
}

// 80ee76(316B,0025.c:45867)uuid 摘除腿:首命中
//   json_value_remove_take(+0xe0,i,out)→ return;80eb6c 重命名
//   前置腿 cited(KitView 遍历域,见头注)。
bool SessionStore::takeByUuid(QVariantList &library, const QString &uuid)
{
	if (uuid.isEmpty()) // param_2 空串卫 @0080ef21 前
		return false;
	for (int i = 0; i < library.size(); ++i) { // +0xe0 数组腿
		const QVariantMap m = library.at(i).toMap();
		if (m.value(QStringLiteral("session.uuid")).toString() == uuid) {
			library.removeAt(i); // json_value_remove_take @0080ef6d-f2
			return true;
		}
	}
	return false; // 尾 return 0
}

// 80efd2(365B,0025.c:45917)组摘除腿:倒序逐项
//   s_session_group_805a3e(195B 组腿)compare == 0 → 逐项
//   remove_take,uVar6 OR 累积;removed 注入缝 = 测试对账(语料
//   逐项析构,收集不发明行为面)。
bool SessionStore::takeByGroup(QVariantList &library,
                               const QString &group, QVariantList *removed)
{
	bool any = false; // uVar6 OR 累积同相
	for (int i = library.size() - 1; i >= 0; --i) { // 倒序 @0080f0a0
		const QVariantMap m = library.at(i).toMap();
		if (m.value(QStringLiteral("session.group")).toString() == group) {
			if (removed != nullptr)
				removed->append(library.at(i)); // 对账缝(见头注)
			library.removeAt(i); // json_value_remove_take @0080f0f4
			any = true;          // uVar6 |= uVar3
		}
	}
	return any;
}

// 805398(139B,0025.c:40687)追加腿:+0xe0 空则数组初始化
//   (json_value_init_by_type(,6)array 同相 — QVariantList 默认空
//   同相);FUN_00af5c40(227B)arrayAt 尾交换插入 → append;
//   FUN_00805342 +0xe8 QHash 缓存清 cited(注入库无缓存)。
void SessionStore::append(QVariantList &library,
                          const QVariantMap &session)
{
	library.append(session); // @008053bd-06 arrayAt 尾插同相
}

// 8069b0(211B,0025.c:41501)upsert 腿:json_get_string_default
//   ("session.uuid","")空 → 0(@008069bx 卫);8051f2 命中替换否则
//   805398 追加(@00806a35-bb);param_3!=0 → 806958 保存腿。
bool SessionStore::upsert(QVariantList &library,
                          const QVariantMap &session, bool save,
                          const QString &profilePath)
{
	const QString uuid = session.value(QStringLiteral("session.uuid"))
	                         .toString();
	if (uuid.isEmpty()) // *(int *)(local_a0 + 4) == 0 → 0
		return false;
	if (!replaceByUuid(library, uuid, session)) // 8051f2 @00806a35
		append(library, session);               // 805398 @00806a4x
	if (!save)                                  // param_3==0 → 1
		return true;
	// 806958(80B,0025.c:41482)config_saveFile("/user.sessions")
	//   = ProfileLoader::saveSessions 现役对偶(批 169);路径腿
	//   806904 "/user.sessions" 现役同面;profilePath 空 = 语料
	//   内部面(defaultProfilePath 同相)。
	ProfileLoader pl(profilePath.isEmpty()
	                     ? ProfileLoader::defaultProfilePath()
	                     : profilePath);
	return pl.saveSessions(library); // config_saveFile 对账 bool
}

// 810c4e(258B,0025.c:46974)字段对等 set 腿:810056 定位未中 → 0;
//   json_get_string_default(key,DAT_00d38120 null 缺省)旧值与新值
//   FUN_00aef040 同型比值;值变 → 非 null set(json_value_swap)/
//   null removeMember → 8069b0(param_5)收尾。返回 = 变更与否。
// 注记(null 摘除语义):语料 removeMember 空缺省(DAT_00d38120
//   json null)对位 — 本承载替中 entry 缺键 == QVariant null;当
//   旧值与新值同为 null(json 双 null,FUN_00aef040 case 0 相等)
//   → 无变更返 0;键存在且新值 null → removeMember 腿变更返 1。
bool SessionStore::setField(QVariantList &library, const QString &uuid,
                            const QString &key, const QVariant &value,
                            bool save, const QString &profilePath)
{
	const int idx = [&library, &uuid]() -> int { // 810056 对位
		for (int i = 0; i < library.size(); ++i) {
			const QVariantMap m = library.at(i).toMap();
			if (m.value(QStringLiteral("session.uuid")).toString()
			    == uuid)
				return i;
		}
		return -1;
	}();
	if (idx < 0)
		return false; // 810056 未中 → 0 @00810c9x
	QVariantMap entry = library.at(idx).toMap();
	const QVariant oldVal = entry.value(key); // 缺失 = null 缺省同相
	// 语料对位:json_get_string_default 旧值取自存储条目(键存在才
	//   有值);键不存在 = null 缺省与新 null 对等 — 对等门先行。
	if (sessionTrioVariantEqual(oldVal, value))
		return false; // FUN_00aef040 对等 → 不写(uVar2=0)
	if (!value.isNull())
		entry.insert(key, value); // json_value_swap set @00810ce5-f4
	else
		entry.remove(key); // json_removeMember @00810d0x null 腿
	library[idx] = entry;  // 原位同相(语料指针面直写)
	// 8069b0 收尾(@00810d08-45;uuid 未变 → 8051f2 替换腿同相)。
	const bool saved = upsert(library, entry, save, profilePath);
	return saved;
}
