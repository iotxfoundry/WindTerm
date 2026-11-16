#include "StateStore.h"

#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QSplitter>
#include <QStackedWidget>

#include "Editor/ProfileLoader.h"      // 806958/806904 对偶(批 169 现役)
#include "KitWindowFactory.h"          // KitWindowFace(8cf0c8 cast 面)
#include "MuxPaneGroup.h"
#include "WorkspaceLoader.h" // collectorPaneTypeName/sessionByUuid 真身

#include "Editor/ProfileLoader.h"      // 806958/806904 对偶(批 169 现役)
#include "KitWindowFactory.h"          // KitWindowFace(8cf0c8 cast 面)
#include "MuxPaneGroup.h"              // MuxPaneGroup/tabGroup()(KitDock 对位,批 177)
#include "MuxPaneView.h"               // MuxPaneView(KitPane 对位;paneIndex)
#include "MuxWindow.h"                 // MuxWindow::splitter()(现役树只读)
#include "TabGroup.h"                  // TabGroup tabBar()/count()(8b85d8/ce 面)
#include "WorkspaceLoader.h" // collectorPaneTypeName/sessionByUuid 真身

// === stateStoreSerializeSplitterBlob — 批 177(M22-①)blobA 实体真身。
// 语料锚(8cf0c8 内 8cf245-837f 段;asm/反编译双源):
//   表源:pane+0x38..+0x40 迭代对(FUN_008d7840 = QList<[first,last)>
//     构造,8d75b4 逐元 append)— KitWindow+0x38 槽位族(KITWINDOW-
//     RECON 1.4 七 qw)→ 我方现役承载 = pane 域 findChildren<MuxWindow*>
//     → MuxWindow::splitter()(FUN_008e01ac +0x70→+0x30 只读引用面)。
//   逐 splitter(元素 = QSplitter*,循环体 @8cf2c8-357 asm 全读):
//     <<int(QSplitter::count)@8cf2d7-84;
//     逐 i<count:widget(i)@8cf2f5 → __dynamic_cast(QWidget,7KitDock
//       0x11aaed0)@8cf301 命中 → <<BA(FUN_008b921a)@8cf322 —
//       KitDock cast 对位 = MuxPaneGroup(QSplitter 直子现役实体,
//       sgtest f 形态;+0x30 TabGroup 槽语义对位 — 布局注);
//     <<BA(QSplitter::saveState)@8cf348-57。
//   无外层数量头(原版 229B 段反推实证:splitter 数不可预知,读侧
//     FUN_008d2f7e 同构 while 迭代)。
// FUN_008b921a(306B,0027.c:76356)tabbar serialize 直译:
//   <<int(tabbar currentIndex)@8b9250(8b85d8→5ab5ca QTabBar::
//     currentIndex,dock+0x30 TabGroup 槽 0xb tabBar)→ MuxPaneGroup
//     对位 = tabGroup()->tabBar()->currentIndex();
//   <<int(tabbar count)@8b9257(8b85ce→5abbda QTabBar::count);
//   逐 i<count(8b92bb 门 iVar2<=iVar1):pane = stackWidgetAt(i)
//     (8b83ee→5abbd0 QStackedWidget::widget + cast 7KitPane 0x11ab690
//     → MuxPaneView 对位 — paneIndex @+0x30 槽位同形)命中 →
//     <<QString(objectName)@8b92e2 + <<BA(pane 会话态)@8b929e。
// pane 会话态 = FUN_008c37a4(84B,0028.c:6065;asm 008c37a4-e1 全读):
//   pane+0x30 byte==0 → vcall vt+0x1d8(KitPane 默认 = 8c367e return-1,
//     sret RDI 不动 → BA 保持 shared_null → << -1 null 序同相);
//   !=0 → QObject::property(0xc9e544="History")@8c37c9-d6 →
//     QVariant::toByteArray@8c37db(→ null QVariant 空串 BA;kitWindow
//     AttachPage hints 腿设置面,KitWindowFactory.cpp 批 142 判例)。
//   → MuxPaneView 直译:paneIndex()==0 → null BA(<<-1);!=0 →
//     property("History").toByteArray()(现役树无 History 属性面时 =
//     QVariant null → toByteArray 空 BA —— 注:语料 toByteArray(null
//     QVariant) = 空 BA(0 长度)非 null;样本三 tab 全 null(-1)与
//     paneIndex 全 0 或无属性窗同相 — 本面按语料分支直译)。
// 前置浮停副作用腿(8cf1f3-24a):findChildren<KitDock*>(pane)(smo
//   011ab100)逐 dock+0x39 flag(FUN_008b8c62 5B = byte 读)非零 →
//   dock_toggleFloat(dock,0)(8b8ce6 866B)— 无字节产物,cited 不落
//   (铁律 6;样本帧零痕迹)。
// blobB 逐 splitter saveState 段(@8cf412-456)同面承接:
//   param_2[0xb/0xc] 迭代对(QSplitter* 表第二族,8cf40a 同 8d7840)→
//   我方现役树单族(MuxWindow::splitter() 唯一)→ 语料两族对位:
//   [0xb/0xc] 表 = 现役 splitter 逐 saveState(样本实序 31/35/27/0
//   四段位级对账;@8cf412 循环直译)。
static QByteArray stateStoreTabbarBlob(QWidget *dock); // FUN_008b921a
static QByteArray stateStorePaneStateBlob(QWidget *pane); // FUN_008c37a4

QByteArray stateStoreSerializeSplitterBlob(const KitWindowFace *pane)
{
	QByteArray blob; // local_b8 shared_null @008cf1a3
	if (pane == nullptr)
		return blob; // param_2 卫(调用契约外零消费同相)
	// 前置浮停副作用腿(@8cf1f3-24a):dock_toggleFloat(8b8ce6 866B,
	//   批 180 全读定性)——
	//   门:dock+0x39 != float;尾写 +0x39 = float + KitDock 信号
	//     floating(bool)(smo 0x11ab100 methodCount 12,idx1
	//     "floating" attrs 0x6 信号,QMetaObject 实读)emit 91a80c。
	//   float=1 浮出腿:hostSp = parentWidget+0x10 cast QSplitter;
	//     未存 saved rect 腿(dock+0x3c > +0x44 / +0x40 > +0x48)→
	//     mapToGlobal 存 +0x3c/+0x40 + 尺寸(+0x28 geometry w/h)存
	//     +0x44/+0x48;+0x4c = 8ca0b8(kit 上溯 8b8694,hostSp)槽位号
	//     (1/2/8 → kit+0x38/+0x40/+0x50 三 QSplitter 槽表 8ca096);
	//     +0x50 = hostSp->indexOf(dock);hostSp.count()==1 且 outerSp =
	//     hostSp.parent cast QSplitter → sizes 吸收(hostSp 尺寸加邻位,
	//     自位清零,setSizes)+ setParent(kit)+ setWindowFlags(
	//     kit+0x28 layout flags |1)+ show + QTimer::singleShot(0,
	//     8b7cdb 闭包 setGeometry(savedRect))复位几何。
	//   float=0 回位腿:kit = 8b8694 上溯;slotSp = 8ca096(kit,+0x4c);
	//     saved rect 未存腿同上;setWindowFlags(0);slotSp->
	//     insertWidget(+0x50,dock);show。
	//   邻接族(FUN_008b9050 showEvent 0x69 腿 + FUN_008b86e4 deleteLater
	//     + Splitter 子类 handle 折叠 5a1c70/5a1cfc/5a1ebc/5a2096/
	//     eventFilter,smdat 0x11981a0 showIndex/hideIndexRequested)。
	//   我方承接:KitDock 类未建模(现役树零实例)→ 8cf1f3 findChildren
	//     <KitDock*> 循环不可达同相,cited 不落(铁律 6;零字节产物,
	//     样本帧零痕迹同相)。
	// 表源:@8cf245-85 pane+0x38 迭代对 → 我方现役承载 =
	//   findChildren<MuxWindow*>(pane)(只读引用;非 pane 直子域同相 —
	//   qt_qFindChildren_helper recursive=1 @8cf1f3)。
	QDataStream out(&blob, QIODevice::WriteOnly); // local_78 同构面
	const QList<MuxWindow *> wins = pane->findChildren<MuxWindow *>();
	for (MuxWindow *win : wins) { // 逐 mux(= 逐 splitter 表实体)
		QSplitter *sp = win->splitter(); // FUN_008e01ac(+0x70→+0x30 只读)
		if (sp == nullptr)
			continue; // 表元素空位跳过(语料元素直取非空同相)
		const int n = sp->count(); // QSplitter::count @8cf2d7
		out << n; // @8cf2e4
		for (int i = 0; i < n; ++i) { // @8cf2ee-3a 循环体
			QWidget *w = sp->widget(i); // QSplitter::widget @8cf2f5
			// __dynamic_cast(QWidget,KitDock)@8cf301 — MuxPaneGroup 对位
			if (dynamic_cast<MuxPaneGroup *>(w) != nullptr) {
				const QByteArray tb = stateStoreTabbarBlob(w); // 8b921a
				out << tb; // @8cf32d
			}
		}
		const QByteArray ss = sp->saveState(); // QSplitter::saveState @8cf348
		out << ss; // @8cf353
	}
	return blob; // local_b8 → @8cf37b 由调用侧 << 承接
}

// === stateStoreTabbarBlob — FUN_008b921a(306B,0027.c:76356)直译。
// dock 参数 = QSplitter 直子(KitDock 对位 = MuxPaneGroup);体序见
// stateStoreSerializeSplitterBlob 块注。===
static QByteArray stateStoreTabbarBlob(QWidget *dock)
{
	QByteArray blob; // *param_1 = shared_null @8b9248
	auto *group = dynamic_cast<MuxPaneGroup *>(dock);
	if (group == nullptr)
		return blob; // cast 面同相(调用侧已 cast,卫 = 契约外)
	TabGroup *tabs = group->tabGroup(); // dock+0x30 槽(8b81b0 ctor param_1+0x30)
	if (tabs == nullptr)
		return blob; // 槽位缺位 = shared_null 迭代零次同相
	QDataStream out(&blob, QIODevice::WriteOnly); // @8b924c
	out << tabs->tabBar()->currentIndex(); // 8b85d8→5ab5ca @8b9250
	out << tabs->count(); // 8b85ce→5abbda QTabBar::count @8b9257
	for (int i = 0; i < tabs->count(); ++i) { // @8b92bb iVar2<=iVar1 门
		QWidget *pw = tabs->stackWidgetAt(i); // 8b83ee→5abbd0 widget(i)
		if (pw == nullptr)
			break; // i==count 腿(语料 while 反译;break 语义同相)
		// cast 7KitPane 0x11ab690 — MuxPaneView 对位(paneIndex @+0x30 同形)
		if (dynamic_cast<MuxPaneView *>(pw) == nullptr)
			continue; // cast 未命中 → 语料下行同样走 objectName/会话态?
		// 语料:cast 未命中也 <<(8b83ee 返回 0 时 uVar3=0 → objectName(0)
		//   = 空 QString;8c37a4(0)解引用风险 = 语料原样 — 不修,铁律 2;
		//   本面 pw 非 QWidget 域不可达,直译同相)。
		out << pw->objectName(); // QObject::objectName @8b92e2
		out << stateStorePaneStateBlob(pw); // 8c37a4 @8b929e
	}
	return blob;
}

// === stateStorePaneStateBlob — FUN_008c37a4(84B,0028.c:6065)直译。
// pane+0x30 byte==0 → vt+0x1d8 默认腿(8c367e return-1,sret RDI 不动
//   → BA 恒 shared_null → << -1 序);!=0 → property("History")→
//   toByteArray(0x11820e8 串实读;asm 008c37ad-d6 全读)。===
static QByteArray stateStorePaneStateBlob(QWidget *pane)
{
	auto *pv = dynamic_cast<MuxPaneView *>(pane);
	if (pv == nullptr) {
		// 非 MuxPaneView(cast 未命中域):语料 param_2+0x30 byte 直读
		//   对位 = QWidget 无实例语义 → property 腿同面(零自研):
		return pane->property("History").toByteArray(); // @8c37c9-db
	}
	if ((pv->paneIndex() & 0xff) == 0)
		return QByteArray(); // shared_null(<<-1 null 序;vt 默认腿同相)
	return pv->property("History").toByteArray(); // @8c37c9-db
}

// === stateStoreSerializePagePayload — FUN_008cf0c8(2233B,
// 0028.c:15003)页 payload 骨架帧真身(批 173;出处清单见 StateStore.h
// 头注;深腿 cited 分段 — 铁律 3 宁空不猜)。===
// (char)pane+0x30 旗标门(ctor +0x30 WORD=0x0101 恒零低位 → 全帧腿
//   同相;property 直取腿 @008cf110 cited 运行期装配族)。
QByteArray stateStoreSerializePagePayload(const KitWindowFace *pane,
                                          quint32 flags)
{
	QByteArray blob; // local_d8 = shared_null @008cf162
	if (pane == nullptr)
		return blob; // param_2 卫(语料 param_2 由 7669b2 页非空调用点保证;
		             //   空指针 = 调用契约外,零消费同相)
	// QDataStream(&blob,WriteOnly)@008cf162(mode 2)
	QDataStream out(&blob, QIODevice::WriteOnly);
	// << 0xb9e7e626(@008cf173,反编译 -0x461819da;原版样本 4B
	//   b9e7e626 实证,5C-REPORT 页 payload 深 diff 表)
	out << quint32(0xb9e7e626u);
	// blobA:pane+0x38 splitter 容器槽族序列化(@008cf1f3-357)——
	//   批 177 升真 = stateStoreSerializeSplitterBlob(现役树只读面,
	//   树深依赖浮停腿 cited;见 .cpp 块注 + 原版 229B 实物反推印证)。
	const QByteArray blobA = stateStoreSerializeSplitterBlob(pane); // @8cf1a3
	out << blobA; // @008cf37b
	// blobB:(char)pane+0x70 旗标(ctor +0x70 BYTE=1,KitWindowFace.h
	//   头注;样本 B[0]=01 实证)+ 逐 splitter saveState([0xb/0xc] 表,
	//   批 177 同面承接:现役 MuxWindow::splitter() 逐 saveState)+
	//   flags&1 LastSessions 组块(cited,>500B 邻档)。
	QByteArray blobB; // local_d0 @008cf3bb
	{
		QDataStream b(&blobB, QIODevice::WriteOnly); // @008cf3bf
		b << qint8(1); // (int)(char)param_2[0xe] ← ctor +0x70=1
		               //   @008cf3cd(样本 B[0]=01 同相)
		// param_2[0xb/0xc] splitter 表逐 saveState(@8cf412-456 循环直译;
		//   表源同 blobA 现役承载 — 样本 31/35/27/0 四段位级对账)。
		const QList<MuxWindow *> wins =
		    pane->findChildren<MuxWindow *>(); // @8cf3f8-40a 同表源
		for (MuxWindow *win : wins) {
			QSplitter *sp = win != nullptr ? win->splitter() : nullptr;
			if (sp == nullptr)
				continue; // 表元素空位跳过同相
			const QByteArray ss = sp->saveState(); // @8cf447
			b << ss;                               // @8cf452
		}
		if ((flags & 1u) != 0) {
			// LastSessions 组块外框真身(批 223;@008cf62f-8ff):
			//   mode = kitScopedConfigValue(kit,"kit.startupSessions",
			//     "LastSessions")@008cf62f-6c4;isLast = (mode=="LastSessions");
			//   队列首节点 = {0, param_1[9](= +0x48 LastSessions splitter)}
			//     (prepend @008cf977);
			//   逐节点 pop-front:<< int index << int count
			//     << QSplitter::saveState @008cf740-76b;
			//   子件:QSplitter → <<(char)1 + append{1, child}@008cf783-8xx;
			//     KitGroup(011ab130,= MuxPaneGroup 同址 +0x38 TabGroup)→
			//     <<(char)2 + << (isLast ? s_RenamedTitle_8bbab6 : 空 BA)
			//     @008cf842-8ff;BFS 顺序由 append/erase 队列定序。
			const QString groupMode = Workspace::kitScopedConfigValue(
			    QStringLiteral("Terminal"),
			    QByteArrayLiteral("kit.startupSessions"),
			    QStringLiteral("LastSessions")); // @008cf62f-6c4
			const bool isLast = groupMode == QLatin1String("LastSessions");
			QSplitter *root = pane->m_split0x48; // param_1[9]
			if (root != nullptr) {
				QList<QPair<int, QSplitter *>> queue;
				queue.append(qMakePair(0, root)); // prepend 根 @008cf96a
				while (!queue.isEmpty()) {        // @008cf740 队列消费
					const QPair<int, QSplitter *> node = queue.takeFirst();
					b << node.first;                  // << int index
					b << node.second->count();        // << int count
					b << node.second->saveState();    // << BA @008cf772
					QList<QSplitter *> nested;
					for (int i = 0; i < node.second->count(); ++i) {
						QWidget *w = node.second->widget(i); // @008cf7c1
						if (auto *sp = qobject_cast<QSplitter *>(w)) {
							b << qint8(1);               // @008cf783(ESI=1)
							nested.append(sp);           // append {1, child}
						} else if (auto *pg = qobject_cast<MuxPaneGroup *>(w)) {
							b << qint8(2);               // @008cf842(ESI=2)
							b << (isLast ? pg->sessionTitleBlob()
							             : QByteArray()); // @008cf86b-8ff
						}
					}
					for (QSplitter *sp : nested)
						queue.append(qMakePair(1, sp));
				}
			}
		}
	}
	out << blobB; // @008cf490
	// blobC:MenuBar/StatusBar/ToolBar 三「全隐藏」bool —
	//   FUN_008cefe4(212B,0028.c:14969)真身:findChildren<QWidget>(名,递归)
	//   逐项读 QWidget 私有位(d+8 bit 0x10000)全为 1 才 true;
	//   本面以 isHidden() 等价承接(cited 适配,位域不可移植)。
	QByteArray blobC; // local_b8 @008cf4ce
	{
		QDataStream c(&blobC, QIODevice::WriteOnly); // @008cf4d2
		c << allNamedHidden(pane, QStringLiteral("MenuBar"))    // @008cf4e5
		  << allNamedHidden(pane, QStringLiteral("StatusBar"))  // @008cf4xx
		  << allNamedHidden(pane, QStringLiteral("ToolBar"));   // @008cf4xx
	}
	out << blobC; // @008cf587
	// 尾钩 vtable+0x248 != FUN_008d5bf4(@008cf960)→ 虚调(本批定性,
	//   asm/kuna 双源;QuickBar 窗条面):
	//   - TerminalWindow vt 0x11a7c80 +0x248 = FUN_0085ae68(220B)读侧
	//     face(>>BA → 子流 >>bool 可见 >>int count >>QString×count
	//     经 85e0c0 QVariantList;param_3&4 门;!visible → 8595c8
	//     hide)+0x240 默认腿(FUN_008d1014/8d5bee)双窗同值;
	//   - 写侧镜像 = FUN_008596b8(395B,0026.c:50614):QuickBar 懒建
	//     (sub_56e26e ctor,objectName "QuickBar" 0xd0e6d4 实读,存
	//     +0xd8/+0xe0 QPointer 对)→ <<BA[<<bool 可见位(quickBar
	//     QWidgetData 字位 >>0xf&1)][<<int names count(+0x68 表)]-
	//     [<<QString 逐项] — 样本尾 9B = BA(5B:00+00000000)= 可见
	//     false + 空表 byte-perfect 同相;
	//   - EditorWindow vt 0x119ee30 +0x248 = FUN_008d5bee(默认 6B
	//     return-1)→ Editor 页零尾段(样本单 Terminal 页同相)。
	//   KitWindowFace 壳零虚槽声明(22 虚零消费判例,KitWindowFace.h
	//   头注)+ QuickBar 宿主槽 +0xd8/+0xe0 未建模(铁律 6)→ 钩腿
	//   cited 不落(恢复侧 startupChain 对页 payload 掩码门
	//   &0xb9e7e600 + 头三段消费,尾钩段零消费闭环)。
	return blob; // *param_1 = local_d8 @008cf988
}

// === stateStoreSerializePages — FUN_007669b2(571B,0023.c:33468)
// FUN_008cefe4(212B,0028.c:14969)全隐藏判定真身(cited 等价面):
//   findChildren<QWidget>(root, name, 递归=1);空表 → false;
//   逐项 (d+8 & 0x10000) 全为 1 → true。本面以 isHidden() 承接
//   (语料直读 QWidget 私有位,不可移植 — 已注记)。
static bool allNamedHidden(const QWidget *root, const QString &name)
{
	if (root == nullptr)
		return false;
	const QList<QWidget *> ws = root->findChildren<QWidget *>(name);
	if (ws.isEmpty())
		return false;
	for (QWidget *w : ws) {
		if (!w->isHidden()) // 位域 0x10000 等价面(cited)
			return false;
	}
	return true;
}

// 窄面真身(头注全出处;&4 段 cited 不落;页 payload 腿 =
//   stateStoreSerializePagePayload 骨架帧,批 173 升真)。===
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
		// @00766a31 — 批 173 升真骨架帧(dynamic_cast KitWindow
		// 011ab390 → KitWindowFace 壳承接;非 KitWindow 页 → 语料同相
		// 空 BA — @00766a8b cast 未命中腿页名走 objectName,payload
		// local_58 shared_null 同相)。
		QByteArray pagePayload; // local_58 = shared_null @00766a3c
		if (auto *kit = dynamic_cast<KitWindowFace *>(page))
			pagePayload = stateStoreSerializePagePayload(kit, flags); // @00766a31
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

// FUN_008596b8(395B,0026.c:50614)QuickBar 写侧真身
QByteArray stateStoreSerializeQuickBar(const KitWindowFace *pane)
{
	QByteArray buf;                                   // local_68(shared_null)
	QDataStream s(&buf, QIODevice::WriteOnly);         // @008596ef(2 = WriteOnly)

	// 可见位:名称非空且宿主非空才取 QWidget 私有位 bit15
	bool vis = false;                                 // @0085970x
	if (pane != nullptr && !pane->quickBarName().isEmpty() && pane->quickBarHost() != nullptr) {
		// 语料直读私有位 (*(+0xe0 的 +0x28 的 +8) >> 0xf) & 1
		vis = pane->quickBarHost()->isVisible();       // 等价承接(cited)
	}
	s << vis;                                          // @00859737

	// 快捷项名表
	QStringList names;                                 // local_60(QList)
	if (pane != nullptr && !pane->quickBarName().isEmpty() && pane->quickBarHost() != nullptr)
		names = pane->quickBarItemNames();              // detach(+0xe0 + 0x68)
	s << names.size();                                 // @008597a0(<< int count)
	for (const QString &n : names)
		s << n;                                        // 逐项 <<QString
	return buf;                                        // 外层再 out << buf
}
