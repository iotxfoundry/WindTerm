#include "WorkspaceLoader.h"

#include <QDataStream>
#include <QDir>
#include <QDirIterator>
#include <QHash>
#include <QRegularExpression>
#include <QScreen>
#include <QSet>
#include <QStackedWidget>
#include <QVariantMap>

#include "Actions/KitWindowFace.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/MainWindowFace.h"
#include "Actions/MuxPaneGroup.h"
#include "Actions/TabGroup.h"
#include "Actions/StartupChain.h"
#include "Editor/CTerminalConfig.h"
#include "Editor/ProfileLoader.h"

// 会话库源:DAT_011c2200+0xe0(user.sessions 数组)对位 — ProfileLoader
// (批 149 判例)profilePath 面;语料 QHash 缓存层 cited(单源线性扫
// 同相 — 810056 +0xe8 缓存腿不在注入面)。
static QVariantList WorkspaceLoader_sessionsLibrary()
{
	// 语料消费形态 = 全局会话数组;ProfileLoader::defaultProfilePath
	// = ~/.wind/profiles/default.v10(实机对证 — CONFIG-SCHEMAS);
	// 空文件/缺文件 → 空表同相(装载腿 cited)。
	static QVariantList s_library = ProfileLoader().loadSessions();
	return s_library;
}

// === 批 154(M16-①)实现面 — 段地址锚见 WorkspaceLoader.h 头注 ===

namespace Workspace {

// sessionByUuid — s_session_uuid_810056(1408B,0025.c:46473)单源腿:
//   @0081016d 串空(size==0)→ 0;@0081018f +0xe0 数组空 → +0xf0 腿;
//   逐项 json_valueAt(i) → json_get_string_default("session.uuid",
//   DAT_00cb99b6 空)→ == param_2 → 返回元素(QHash 缓存 +0xe8 腿
//   cited — 语料内缓存面,注入库无缓存需求同相)。
QVariantMap sessionByUuid(const QVariantList &library, const QString &uuid)
{
	if (uuid.isEmpty()) // *(int *)(*(long *)param_2 + 4) == 0 @0081016d
		return QVariantMap(); // cVar → 0 同相
	for (const QVariant &elem : library) { // +0xe0 数组腿 @0081018f
		const QVariantMap m = elem.toMap();
		if (m.value(QStringLiteral("session.uuid")).toString() == uuid)
			return m; // operator== @00810230 命中返回元素
	}
	return QVariantMap(); // LAB_0081015f 尾 return 0 同相
}

// FUN_008bca9e(193B,0028.c:810)active view 面真身:
//   param_1+0x38(currentWidget 槽)→ FUN_005ab316 → dynamic_cast
//   KitView(011ab390 typeinfo "8KitGroup" 上溯基面)命中即返(+1 腿
//   KitView_vt6);未中 → MuxDesktop(011ab930)→ FUN_008da7a8
//   (307B,0028.c:22620:qFindChildren_helper MuxPane 011abde0 + 逐件
//   +0x160 byte!=1 取末件)→ dynamic_cast KitView 返回。
QWidget *collectorActiveView(const QObject *panel)
{
	const auto *host = qobject_cast<const QWidget *>(panel);
	if (host == nullptr)
		return nullptr;
	if (auto *stack = host->findChild<QStackedWidget *>())
		return stack->currentWidget(); // FUN_005ab316 对位面(+0x38 槽)
	                                   //   经 QStackedWidget findChild
	                                   //   同相(语料槽位未建模,批
	                                   //   150 判例:容器面承接)
	return nullptr;
}

// @005227ea-862/@005231f0-263 目录扫描真腿(QDirIterator 判例面):
//   QDirIterator(base,2=AllDirs,0=Files-only 默认)逐 hasNext/next
//   → QDir::toNativeSeparators → 未重(session_defaultDir)→ flag 写。
void editorDirScan(LoaderResult &out, QHash<QString, int> &seen,
                   const QString &base, int kind)
{
	if (base.isEmpty())
		return; // sep==-1 双腿同相(@00523195/@005231cd 门)
	QDirIterator it(base, QDir::NoDotAndDotDot | QDir::AllDirs,
	                QDirIterator::NoIteratorFlags); // @005227c8(2,0)
	while (it.hasNext()) {                          // @005227ed
		const QString path = QDir::toNativeSeparators(it.next()); // @00522810
		if (seen.contains(path))
			continue;                       // @0052283e 命中早退
		seen.insert(path, kind);            // flag @00523783(kind=1 腿)
		out.keys.append(path);
		out.kinds.append(kind);
		// session_defaultDir(kind)@0052282c — 参数卫面真身(见上),
		//   键值面 = path 同相
		QString k = path;
		Workspace::sessionDefaultDir(nullptr, k, QVariant(path), kind);
	}
}

// s_session_protocol_810d6e(1760B,0025.c:47022)protocol URL 面:
//   @00810da2  810056 uuid 命中卫(空 → shared_null 返回)
//   @00810dce  label(8062b6,target 掩盖腿)/target(8061a0,addr→
//              * 腿)/group(805a3e,组名腿)三取(@00810dce/e0e/e29)
//   @00810e75  json_get_string_default("session.protocol")
//              (0xd0dc94 实读)+ "session.port"(0xd0dca5)@00810ed2
//   @00810f2c  label==target(串相等 memcmp @00811227)→ flag=0
//              (@00811238 CMOVZ 腿 — param_4 清零)
//   @00810f55  空组腿:URL = target;非空组 @00811168:
//              group + '/' + target 拼(@00811168-215 空节 memcpy 面)
//   @00810f85  URL = protocol + "://"(@00810fcb-ff2 "://" 0xcb773e
//              3B 尾逐字节写腿)+ 组/target 拼段
//   @0081105a  port toInt(@00811096,失败 0 腿 @0081109e)
//   @00811395  qstricmp("SSH") 且 port!=22 → append ":" + port
//              (@00811395-a8;0x11818f8 "SSH" @00c9dc44 实读);
//              qstricmp("Telnet") 且 port!=23 同相(@0081139e-b3,
//              0x11818e8 "Telnet" @00ca02d0);port==-1 跳过
//              (@008113b4-bd)
//   @008113c3  append ":"(0xca0e1c 单 ':' 实读)+ number(port,10)
//              (@008113fa EDX=0xa)
//   @008110ae  param_4!=0 → append " / "(0xc89068)+ label 消隐面
//              (@008110cd-0e0)
//   尾 @008112ac toLower(param_1)返。
// 深腿(session.target addr→* 掩盖/label 掩盖腿 s_session_target_
// 8061a0/8062b6)cited — 会话库项面消费,本面以 QVariantMap 字段面
// 直取(protocol/port/target/label 同相;组腿 empty 判定同相)。
QString sessionProtocolUrl(const QVariantMap &session)
{
	const QString label = session.value(QStringLiteral("session.label"))
	                          .toString(); // 8062b6 面
	const QString target = session.value(QStringLiteral("session.target"))
	                           .toString();     // 8061a0 面
	const QString group = session.value(QStringLiteral("session.group"))
	                          .toString();     // 805a3e 面
	QString proto = session.value(QStringLiteral("session.protocol"))
	                    .toString();            // @00810e75
	QString portStr = session.value(QStringLiteral("session.port"))
	                      .toString();          // @00810ed2
	const bool eq = (label == target); // @00811227 memcmp 腿
	QString url;
	if (group.isEmpty())                     // @00810f4d 组空卫
		url = target;                        // @00810f55 空组腿
	else
		url = group + QLatin1Char('/') + target; // @00811168 拼腿
	QString out = proto + QStringLiteral("://") + url; // @00810f85-ff2
	bool ok = false;
	const int port = portStr.toInt(&ok); // @0081105a toInt 腿
	if (ok && port != -1) {              // @008113b4 -1 跳腿
		if ((proto.compare(QStringLiteral("SSH"), Qt::CaseInsensitive) == 0
		     && port == 22)
		    || (proto.compare(QStringLiteral("Telnet"), Qt::CaseInsensitive)
		            == 0
		        && port == 23)) {
			// 默认端口省略腿(@0081137f-ae)— 双 AND 门同相
		} else {
			out += QLatin1Char(':') + QString::number(port); // @008113c3-fa
		}
	}
	if (!eq && !label.isEmpty()) // param_4 腿 flag(@00811238 CMOVZ;
	                             //   8062b6 label 空 → target 覆盖腿,
	                             //   空不拼 — 8110cd 串卫同相)
		out += QStringLiteral(" / ") + label; // @008110ae-e0
	return out.toLower(); // @008112ac toLower 尾
}

QString collectorPaneTypeName(const QObject *pane);
QList<QWidget *> collectorMuxChildren(const QObject *pane,
                                      const QString &nameFilter, bool show);
QList<QString> collectorEditorFilePaths(const QObject *pane);
QWidget *collectorActiveView(const QObject *panel);
void editorDirScan(LoaderResult &out, QHash<QString, int> &seen,
                   const QString &base, int kind);
bool sessionDefaultDir(QObject *config, QString &dir, const QVariant &value,
                       int kind);
QString sessionProtocolUrl(const QVariantMap &session);

// === workspaceLoader — s_session_uuid_522056(9063B,0016.c:16441)
// 骨架真身(分节面;深度腿 cited — 清单见头注)===
// 语料返回 0x50 QHash 堆块:键 = 面板项标识(目录路径/会话 uuid/文件
// 路径),node+3 byte = kind 位。本面以 keys/kinds 平铺承载(插入序 =
// 语料遍历序;hash 去重同相 — QHash 重复键不二插 @FUN_0052523e 命中
// 早退腿)。
LoaderResult workspaceLoader(QObject *pane, QObject *panel, QString &title,
                             const QVariantList &sessionLibrary)
{
	LoaderResult out;
	title = title.trimmed(); // QString::trimmed_helper @005220c0(param_3
	                         //   换写;空串同相)
	// @0052210e operator_new(0x50) QHash 头 + bucket 分配(0x40/0x200)
	//   — 容器内部面,QHash 承接。
	// @00522172 toUtf8 → std::string → FUN_00a8ebd8(json 值构造腿,
	//   flag=4)— 标题 json 化收集腿,产物仅入 QHash 头簇(cited:
	//   00a8ebd8 产物消费点在写侧对偶 — 本读体仅头分配,零键值落)。
	// @00522288 param_1!=0 门:FUN_008c9e64 面板类型名(批 159 真身
	//   collectorPaneTypeName;objectName 去 "Window")。
	const QString paneType = Workspace::collectorPaneTypeName(pane);
	// @005222df "Editor" 腿:FUN_008d0cf2(批 159 真身
	//   collectorEditorFilePaths)逐 windowFilePath → session_defaultDir
	//   kind=2(@005223a2 R8D=2)入 QHash(flag=2 @00522437)。
	QHash<QString, int> seen; // FUN_0052523e(165B,18431)命中早退腿
	if (paneType == QLatin1String("Editor")) { // compare_helper @005222df
		const QList<QString> files = Workspace::collectorEditorFilePaths(pane);
		for (const QString &f : files) { // @00522378 循环
			if (seen.contains(f))
				continue;      // FUN_0052523e 命中早退 @0052238d
			seen.insert(f, 2); // *(byte*)(node+0x18)=2 @00522437
			out.keys.append(f);
			out.kinds.append(2);
		}
	} else if (paneType == QLatin1String("Terminal")) { // @00522df8 腿
		// FUN_008d097c(批 159 真身 collectorMuxChildren,"Terminal"
		//   字面过滤 @00522e05-13,show=0):逐件 vcall+0x78 uuid 取
		//   (@00522fb8)→ 组/题/名腿(@00522fbe-012;cited 面注记)
		//   → session_defaultDir kind=6(@005230ad R8D=6;flag=6
		//   @00522f66)。
		const QList<QWidget *> panes =
		    Workspace::collectorMuxChildren(pane, QStringLiteral("Terminal"),
		                                    false); // @00522e48(show=0)
		for (QWidget *w : panes) {
			// vcall+0x78 uuid 串对位面:qobject_cast property 读
			//   (Pane 域虚槽未建模 — property 面承接,写侧 cited)。
			QString key = w != nullptr ? w->property("session.uuid").toString()
			                           : QString(); // @00522fb8 对位
			if (seen.contains(key))
				continue;      // @00522f1e 命中早退
			seen.insert(key, 6); // flag=6 @00522f66
			out.keys.append(key);
			out.kinds.append(6);
		}
	}
	// @00522495 kind 位:Terminal/Browser → 7,else 3(会话库腿)。
	const int libraryKind =
	    (paneType == QLatin1String("Terminal") || paneType == QLatin1String("Browser"))
	        ? 7
	        : 3; // @005224c5 local_218 双腿(0x1182950 "Terminal"/
	             //   0x1182970 "Browser" .rodata 实读)
	// @005224c5 FUN_008caf52(48B)= vt+0x1f0 menu 单例 → vt+0x10 收集
	//   — CGlobalConfigFace 域(会话数组);对位 = sessionLibrary
	//   注入(CTERMINAL-CONFIG 判例;DAT_011c2200+0xe0 消费同相)。
	for (const QVariant &elem : sessionLibrary) {
		const QVariantMap m = elem.toMap();
		// @00522581 QString::toUtf8 → FUN_00a7e872(json 解析腿)—
		//   data 负载 json 化分叉;@005225bf json_isNullType 门:
		//   null → 键 = pQVar25(session.uuid 串,vcall+0x78 对位 =
		//   "session.uuid" 值);非 null → "text"/"data" 三件套双取
		//   (json_get_string_default 缺省 DAT_00cb99b6 空 @0052330d/
		//   0052337d),双非空才落键。
		const QString uuid = m.value(QStringLiteral("session.uuid")).toString();
		QString text = m.value(QStringLiteral("text")).toString();
		QString data = m.value(QStringLiteral("data")).toString();
		QString key;
		if (text.isEmpty() && data.isEmpty()) {
			key = uuid; // json_isNullType!=0 腿 @00522620(pQVar25 直键;
			            //   session_defaultDir(pQVar25,uuid,kind)
			            //   @005225f8 — 参数卫面已真身,见上)
			Workspace::sessionDefaultDir(nullptr, key, QVariant(uuid),
			                             libraryKind); // @005225f8-605
		} else if (!text.isEmpty() && !data.isEmpty()) {
			key = data; // @005235d1 session_defaultDir(text,data,kind)
			            //   键面 = data 串(FUN_0052523e key = local_190
			            //   = "data" 取值 @0052365a)
			Workspace::sessionDefaultDir(nullptr, text, QVariant(data),
			                             libraryKind); // @005235d1-5f6
		} else {
			continue; // 双取其一空 → 不落(语料 *(local_198+4)!=0 &&
			          //   *(local_190+4)!=0 门 @0052340a 同相)
		}
		if (seen.contains(key))
			continue; // *puVar12 == local_1b0 未命中才入 @0052254d
		seen.insert(key, libraryKind); // node+3 = local_218 @00522657
		out.keys.append(key);
		out.kinds.append(libraryKind);
	}
	// @0052271e "Editor" 目录扫描腿(批 159 真身 — QDir 判例面):
	//   param_2!=0 → FUN_008bca9e(panel,1)(193B,0028.c:810 —
	//   +0x38 currentWidget → dynamic_cast KitView(011ab390 腿)/
	//   MuxDesktop(011ab930)→ FUN_008da7a8(qFindChildren MuxPane
	//   非 +0x160 位)→ KitView)+1 腿 KitView_vt6;命中 →
	//   KitView_vt15(@00522762 = FUN_008c5578 → FUN_008c54a4:
	//   +0x20 handler map "Url" 键 @00cb6fcc → QVariant toString)
	//   → lastIndexOf(QDir::separator)@00522780 → mid → QDirIterator
	//   (dir,2=AllDirs,0)@005227c8 → 逐 hasNext/next(@005227ed)
	//   → QDir::toNativeSeparators(@00522810)非重 →
	//   session_defaultDir(kind=1 @0052282c R8D=1;flag=1 @00523783);
	//   未命中(sep==-1)→ @0052315c second 腿:QDir::
	//   fromNativeSeparators(@00523176)→ lastIndexOf('/')@0052318d
	//   → mid → QDirIterator 同构 → toNativeSeparators →
	//   session_defaultDir(kind=0 @005232cd R8D=0;无 flag 写腿 —
	//   @005232cd-2d1 零 insert 腔,键只入参数面)。
	//   KitView_vt15 面 = handler map "Url" 属性(QVariant map 面,
	//   MuxPaneView property 对位 — 写侧 Editor 域 cited);目录枚举
	//   真腿已落(输入源 property("Url") 注入面)。
	if (paneType == QLatin1String("Editor") && panel != nullptr) { // @0052271e
		QWidget *view = Workspace::collectorActiveView(panel); // 8bca9e
		if (view != nullptr) {
			const QString url =
			    view->property("Url").toString(); // KitView_vt15 面
			                                      //   (@00522762)
			int sep = url.lastIndexOf(QDir::separator()); // @00522780
			QString base = sep != -1 ? url.mid(sep + 1) : QString();
			if (sep == -1) { // @0052315c second 腿(fromNativeSeparators)
				const QString norm = QDir::fromNativeSeparators(url);
				sep = norm.lastIndexOf(QLatin1Char('/')); // @0052318d 0x2f
				if (sep != -1)
					base = norm.mid(sep + 1); // @005231cd
				Workspace::editorDirScan(out, seen, base, 0); // kind=0
			} else {
				Workspace::editorDirScan(out, seen, base, 1); // kind=1
			}
		}
	}
	// @005237e3 "Terminal" 腿(非 Editor 时;session.uuid 匹配):URL
	//   正则 "://([^/]++)/"(0xc8906c 13B 实读;QRegularExpression
	//   @00523832)→ pane view(8bca9e)vcall+0x78 串 @0052388d →
	//   match.hasMatch @005238c0 → captured(0)@005238d1 → 库逐项
	//   json_get_string_default("session.uuid")(0xd0da7b 实读)非空
	//   → QHash 节点链比对(FUN_00525500 收集 kind=7 节点)全无
	//   kind==7 → 810d6e protocol 面(@00524025,见
	//   Workspace_sessionProtocolUrl)match captured(0) 比对 →
	//   session_defaultDir(protocol,…,kind=4|5 @005240c4 R8D=
	//   hasMatch?5:4 双腿 @00524073-7a)。
	else if (paneType == QLatin1String("Terminal")) { // @005237e3
		static const QRegularExpression urlRe(
		    QStringLiteral("://([^/]++)/")); // 0xc8906c 实读 @00523832
		QString paneUrl;
		if (panel != nullptr) {
			if (QWidget *v = Workspace::collectorActiveView(panel))
				paneUrl = v->property("Url").toString(); // vcall+0x78 对位
			                                         //   (8c5578 "Url")
		}
		QString captured0;
		if (!paneUrl.isEmpty()) { // @00523885 门
			const auto m = urlRe.match(paneUrl); // @005238b3
			if (m.hasMatch())                    // @005238c0
				captured0 = m.captured(0);       // @005238d1(idx 0)
		}
		for (const QVariant &elem : sessionLibrary) { // +0xe0 数组腿
			                                          //   @00523957
			const QVariantMap m = elem.toMap();
			const QString uuid =
			    m.value(QStringLiteral("session.uuid")).toString();
			if (uuid.isEmpty())
				continue; // *(int*)(local_198+4)!=0 门 @00523a27
			const bool matchedPane =
			    !captured0.isEmpty() && captured0 == uuid; // captured 比对
			if (seen.contains(uuid)) {
				// 节点链 kind==7 扫描腿(@00523fdd-ff4:node+0x18 链
				//   逐 node[0]==7 停)— QHash 内部面,seen flag 读同相:
				if (seen.value(uuid) != 7)
					continue; // 非 7 → 下一库项(@00523fea 腿)
				// kind==7 命中 → 直落 defaultDir(kind=4/5 双腿)
				QString key = captured0;
				Workspace::sessionDefaultDir(nullptr, key, QVariant(uuid),
				                             matchedPane ? 5 : 4);
				continue;
			}
			// 全无命中 → 810d6e protocol 腿(@00524008 腔):
			const QString protoUrl =
			    Workspace::sessionProtocolUrl(m); // @00524025
			const auto pm = urlRe.match(protoUrl); // @0052403d
			QString key = pm.hasMatch() ? pm.captured(0) : QString();
			Workspace::sessionDefaultDir(nullptr, key, QVariant(uuid),
			                             pm.hasMatch() ? 5 : 4); // @005240c4
		}
	}
	// @00522a48 尾容量代数(≤9 截断/9999 cap)+ FUN_00632426 转移构造
	//   — QHash 内部面,QHash 承接同相。
	return out;
}

// === 收集器面(批 159 M17-②)===

// FUN_008c9e64(105B,0028.c:11345)真身:objectName 去 "Window"
// (fromAscii_helper("Window",6) @008c9e8f + QString::remove cs=1
// @008c9e9c;返回 param_1 sret)。测试注入面同相。
QString collectorPaneTypeName(const QObject *pane)
{
	if (pane == nullptr)
		return QString(); // 语料 param_1!=0 门 @00522288(workspaceLoader 侧)
	return pane->objectName().remove(QStringLiteral("Window")); // @008c9e86-a4
}

// KitView_vt6(610B,0028.c:8617)show 腿对位面:语料 = +1 byte 卫 +
//   FUN_008c54e6(可见卫)+ vt+0xa0 vcall + 活动件查(FUN_008c5438
//   上溯 KitWindow)+ FUN_008d0a76(同面页表)+ QTimer::singleShot(0)
//   尾 — Pane/定时域 cited;本面落可见性真腿(show)承接消费面。
static void KitViewShow(QWidget *w)
{
	if (w != nullptr && !w->isVisible())
		w->show(); // vt+0xa0 显形腿对位(定时/上溯腿 cited)
}

// FUN_008d097c(223B,0028.c:15898)Terminal 收集器真身:
//   @008d099f   *param_1 = shared_null(QList 空起步)
//   @008d09a7   mux_removeSplitWidget 面 = FUN_008b9b2a(pane)+0x38
//               子件计数 → 逐 FUN_008b9890(+0x38 stack→widget i)子件
//               ( detach 面 @008d0a3a — 单件免拷同相)
//   @008d09e3   逐子件 w:FUN_0089ff5a(QVariant→QObject* cast 面)
//               → FUN_008bc328(result,w,filter,show)—— filter 非
//               空(label @008d0a76 判例:== "Editor" 过滤;空 =
//               全收)且 nameFilter 非空时 vcall+0x18 名比对 toLower
//               (@008bc3c0);show 腿 KitView_vt6(@008bc378)
//               → FUN_008bf254 append(QList<QWidget*> detach append)
//   返回 = 收集的子件 QWidget* 列表。
// Pane 域消费面(名过滤腿 caller 侧 @00522e48 "Terminal" 字面 +
//   show=0;KitView_vt6 域 cited — vt+0xa0/定时关窗腿未建模)。
QList<QWidget *> collectorMuxChildren(const QObject *pane,
                                      const QString &nameFilter, bool show)
{
	QList<QWidget *> out; // *param_1 = shared_null @008d099f
	// mux_removeSplitWidget 面 = FUN_008b9b2a(pane+0x38 → TabGroup)。
	//   面板树遍历真腿:pane findChildren<QWidget*> 直集(语料 = pane
	//   +0x38 TabGroup +0x60 stack 的页族;pane 域 widget 树同相 —
	//   页族即 stack 页,树遍历含 stack 页与页内件)。
	QList<QWidget *> kids;
	const auto *pw = qobject_cast<const QWidget *>(pane);
	if (pw != nullptr) {
		const auto *group = qobject_cast<const MuxPaneGroup *>(pane);
		if (group != nullptr && group->tabGroup() != nullptr
		    && group->tabGroup()->stack() != nullptr) {
			// FUN_008b9b2a 计数 + FUN_008b9890 逐件(stack widget i)
			QStackedWidget *stack = group->tabGroup()->stack();
			const int n = stack->count();
			for (int i = 0; i < n; ++i)
				if (QWidget *w = stack->widget(i))
					kids.append(w); // @008bc35c null 门
		} else {
			kids = pw->findChildren<QWidget *>(); // 面板树对位(收集器
			                                      //   消费 = Editor
			                                      //   windowFilePath 族
			                                      //   — 树遍历同相;
			                                      //   8d0cf2 dynamic_cast
			                                      //   QWidget 腿同构)
		}
	}
	for (QWidget *w : kids) { // @008bc32e 循环
		if (!nameFilter.isEmpty()) { // *(int *)(*param_3 + 4) != 0 @008bc380
			// vcall+0x18(名取槽)→ toLower 双侧比对 @008bc3c9-d1
			if (w->objectName().toLower() != nameFilter.toLower())
				continue; // 不等 → 跳过(@008bc38c LAB 腿)
		}
		if (show)
			KitViewShow(w); // param_4 腿 → KitView_vt6 @008bc378(见上)
		out.append(w); // FUN_008bf254(50B)QList append 同相
	}
	return out;
}

// FUN_008d0cf2(339B,0028.c:16042)Editor 收集器真身:
//   @008d0d1d   *param_1 = shared_null;空 QVariant payload(@008d0d24
//               shared_null)→ FUN_008d097c(self,pane,空过滤,show=0)
//   @008d0dbe   逐件 dynamic_cast QWidget(011925c8)→ QWidget::
//               windowFilePath()(QVariant 面 @008d0dc9)非空才
//               qlist_qvariant_append(@008d0dd3;空路径不落)
//   返回 = windowFilePath 串列表。
QList<QString> collectorEditorFilePaths(const QObject *pane)
{
	QList<QString> out; // *param_1 = shared_null @008d0d1d
	const QList<QWidget *> kids =
	    collectorMuxChildren(pane, QString(), false); // payload 空 @008d0d24
	for (QWidget *w : kids) { // @008d0dbe 循环
		const QString path = w->windowFilePath(); // @008d0dc9
		if (!path.isEmpty())                      // *(int*)local_40[0]!=0 门
			out.append(path);                     // qlist_qvariant_append
	}
	return out;
}

// === session_defaultDir — FUN_00521702(2297B,0016.c:15428)===
// 0x21ab3 腔体(q0x00 串前缀钉)标量/门/除语料残缺段外逐地址转写:
//   @00521733 FUN_00a8e17a(trie 卫)空 → return @0052173b
//   @00521749   operator_new(8) 空节点;kind byte 存 @00521772
//   @00521776   kind<=3 → separator 腿 @00521e44:
//                 QDir::separator @00521e49 → param_3.lastIndexOf
//                 (@00521e58,-1 → @00521780)→ mid(@00521e7c)→
//                 toLower 尾段比较腿(@00521e87-8e /applet 尾);
//                 命中 → @00521f6c scale=2.0(0xc890f0 dbl 实读)
//                 否则 scale=1.0(0xc890e8)
//   @00521780   scale=1.0(缺省腿)
//   @0052178e   kind>7 → @00521866;else 跳转表 @00521798
//     case 0   @00521d71-91:tr("Disk")(0xc8902f 实读)→ dir
//     default  @00521bdb-c2f:面板名 compare "Terminal"(@00521c02)
//              → tr("Session")(0xcba2c0)/tr("Dir")(0xc9163e)→
//              scale *= 1.3(0xc89100)
//     case 2/6 @005217ad-82d:tr("Opened")(0xc89034)→ scale *= 1.5
//              (0xc890f8)→ tr("switch to tab")(0xc8903b)→ filter
//     case 3/7 @00521c75-cc8:tr("Recent")(0xc89049)→ scale *= 1.3
//     case 4   @00521cdb-d5e:compare "Terminal" → tr("Session")/
//              tr("History")(0xc9e544)→ scale *= 1.1(0xc890f8+8)
//     case 8   语料 bad-instruction(0xc89127 区段)— 不转写
//   @00521866   trie find 面:strtrie_find_qv(FUN_0052674a)×5:
//               0x101(filter)@00521b39 / 0x103(dir)@00521886 /
//               0x104(scale dbl)@00521908 / 0x107(空键写)@005219fd /
//               0x107(重写)@00521a10 / 0x108(kind)@00521a92(重写)
//   @00521ac4   push 空节点(QList 0x200 页面 — QHash 承接同相)
//   尾 @00521b02-34 deallocate 收尾。
// 串面判例键(候选 2 源:过滤腿 default/scale 腿重复读)→ 不发明串
// 值;本面以 参数面 转写(键值消费在 trie 域 cited)。
bool sessionDefaultDir(QObject *config, QString &dir, const QVariant &value,
                       int kind)
{
	Q_UNUSED(config); // trie 根槽(+0x10 域)cited — 容器面不在本域
	// FUN_00a8e17a 卫(@00521733;trie 空早退 — 注入面无 trie → 同相
	// return 0 腿。落点面 = 参数卫 + 尾,行为对 522056 调用侧同相:
	// 调用侧仅消费"入 QHash 节点"事实,键值面由调用侧持有)。
	if (dir.isEmpty() && value.isNull() && kind < 0)
		return false; // 空入参早退对位(@0052173b 卫腿同相面)
	// @00521776-8e kind<=3 分隔符尾段腿(纯 QString 面):
	if (kind <= 3) {
		const int sep = dir.lastIndexOf(QDir::separator()); // @00521e58
		if (sep != -1) {
			const QString tail = dir.mid(sep + 1); // @00521e7c
			if (tail.compare(QStringLiteral("applet"), Qt::CaseInsensitive)
			    == 0)
				return true; // scale=2.0 腿(@00521f6c;scale 消费 cited)
		}
	}
	// kind 分派标量面(tr 标签/scale 乘数 — .rodata 实读见上;消费在
	//   trie 域 cited,本面落判定骨架不落数值行为,铁律 3)。
	switch (kind) {
	case 0: return true;  // tr("Disk") @00521d91
	case 2:
	case 6: return true;  // tr("Opened")×1.5 + "switch to tab" @005217cb
	case 3:
	case 7: return true;  // tr("Recent")×1.3 @00521c95
	case 4: return true;  // Terminal? "Session":"History" ×1.1 @00521cdb
	case 8: return false; // 语料 bad-instruction 段 — 恒不可达同相
	default: break;       // 1/5 → Terminal? "Session":"Dir" ×1.3 @00521bdb
	}
	return true;
}

} // namespace Workspace

// === kitScopedConfigValue — FUN_008cba1c(253B,0028.c:12847)+
// s_text_preferThemeFonts_760b2c(1141B,0023.c:28014 区段)前缀化键面
// 真身。语料序(8cba1c):
//   键 BA → QString(fromAscii_helper strlen 面 @008cba55-84);
//   FUN_008c9e64(panel)面板名(objectName 去 "Window")@008cbabb;
//   s_text_preferThemeFonts_760b2c(app,面板名,键)@008cbbcc:
//     @00760b86 键 toLower → utf8(@00760b8a-bdc strlen 面);
//     @00760bf1 QRegularExpression("^kit(?=\.)")(0x760bf6 串
//       "^kit(?=\.)" 实读)replace → 剥 kit. 前缀;
//     @00760c68 startsWith("text.")(DAT_00c8b3cb .rodata 实读
//       "text.")且命中 12 font 键哈希(DAT_011c1da0 @00760d77-77:
//       text.caretPeriod/caretWidth/charSpaceFactor/fontFamily1-3/
//       fontSize/fontWeight/lineSpaceFactor/preferThemeFonts/
//       zoomFactor)→ 前插面板名.toLower()+"."(@00760d39 insert 0,
//       尾 0x2e '.' 写位);
//   @008cbbf5→0075c480 global_setting_get(app,键,缺省):DAT_011c1240
//     guard(005d972a 351B — config 值卫面)+ 0090e084 发射面(cited
//     — 发射无接收者 no-op 同相,批 150 判例);通路 = CTerminalConfig
//     值面(value,批 150 wind.config 默认层判例;键未命中 → 缺省)。
QString kitScopedConfigValue(const QString &panelObjectName,
                             const QByteArray &key,
                             const QVariant &defaultValue)
{
	QString k = QString::fromUtf8(key); // @008cba55
	k = k.toLower();                    // @00760b86 toLower
	k.replace(QRegularExpression(QStringLiteral("^kit(?=\\.)")),
	          QString()); // @00760bf1-216("^kit(?=\.)" 串实读)
	// @00760c68 "text." 前缀 + 12 font 键表命中才前插面板段。
	static const QSet<QString> fontKeys = {
	    QStringLiteral("text.caretPeriod"), QStringLiteral("text.caretWidth"),
	    QStringLiteral("text.charSpaceFactor"), QStringLiteral("text.fontFamily1"),
	    QStringLiteral("text.fontFamily2"), QStringLiteral("text.fontFamily3"),
	    QStringLiteral("text.fontFamily4"), QStringLiteral("text.fontSize"),
	    QStringLiteral("text.fontWeight"), QStringLiteral("text.lineSpaceFactor"),
	    QStringLiteral("text.preferThemeFonts"), QStringLiteral("text.zoomFactor")
	}; // @00760d77-77 十二 qstring_assign_from_ascii 实读
	if (k.startsWith(QStringLiteral("text.")) && fontKeys.contains(k)) { // @00760c68-7x
		k.prepend(panelObjectName.toLower() + QLatin1Char('.')); // @00760d39
	}
	// global_setting_get(0075c480)通路 → CTerminalConfig 值面。
	return CTerminalConfig::instance()->value(k, defaultValue).toString(); // @008cbbf5-05
}

// === kitStartupSessions — s_kit_startupSessions_8d2f7e(3122B,
// 0028.c:17278)分发腿(flags&1 会话分发面真身;splitter/tabbar/窗条
// 深腿 cited — 清单见头注)===
bool kitStartupSessions(QObject *panel, const QByteArray &payload,
                        quint32 flags)
{
	Q_UNUSED(panel); // param_1+6 旗标/pane+9 复挂/0xe 写 — 宿主槽位
	                 //   cited(KitWindow 域,批 150 同因)
	if (payload.isEmpty())
		return false; // *(int *)(*(long *)param_2 + 4) != 0 门 @17283
	QDataStream in(payload); // QDataStream::QDataStream @008d2fe5
	// 语料 startTransaction @008d2fef(回滚面 — 失败腿经 catch 到
	//   008d3c2d 汇编桩 → 同相:读失败 payload 不动,return 0)。
	quint32 version = 0;
	in >> version; // local_10c @008d2ff9
	if (version < 0xb9e7e615u)
		return false; // FUN_008ce8f6(1347B)旧格式腿 cited(>500B;
		              //   现行写侧恒 ≥ 0xb9e7e615 — 调用面不可达同相)
	QByteArray splitterBlob;
	in >> splitterBlob; // local_c0 @008d302f
	// splitter 布局段子流(@008d304b-3317):逐 splitter hide/清子/
	// addPage/restoreState + 尾表 restoreState — QSplitter/SplitterGroup
	// 深腿(00770640/008d78bc/008d75b4)cited(D 域;行为位 = 页挂
	// 几何,本读体消费在 SplitterGroup 域)。
	QDataStream sub(splitterBlob); // QDataStream(local_58,local_c0)@008d304b
	quint32 splitterCount = 0;
	sub >> splitterCount; // local_c8[0](int 页数头 — 首组页数读位
	                      //   @008d3092 面)
	(void)splitterCount;  // 页挂腿 cited(见上)
	QByteArray statesBlob;
	in >> statesBlob; // local_100 @008d3303
	{
		QDataStream states(statesBlob); // @008d3323 子流
		bool gateFlag = false;
		states >> gateFlag; // local_10e → pane+0xe 写 @008d3323-40
		                    //   (宿主槽位 cited — 写位不落,读游同相)
		// @008d3380-340x:splitter states 表逐 restoreState — cited 同上。
	}
	// @008d3601 flags&1 腿(startupChain 唯一调用点 flags=1 可达):
	if ((flags & 1u) != 0) {
		// FUN_008d7604(+9 表前置 47B cited — 表操作位)
		const QString mode = kitScopedConfigValue(
		    QStringLiteral("Terminal"), QByteArrayLiteral("kit.startupSessions"),
		    QStringLiteral("LastSessions")); // @008d366a-69c(FUN_008cba1c
		                                     //   + "LastSessions" 缺省
		                                     //   0xd0ce97 串面)
		QDataStream s2(payload); // 局部 stream 游标语义 — 语料 local_78
		                         //   续读面(@008d36c5 起子流;本面以
		                         //   独立会话组流承载,组游标 cited)
		bool firstGroupSeen = false; // bVar5 @008d370c
		while (!s2.atEnd()) { // @008d387b QDataStream::atEnd 门
			quint32 group = 0, count = 0;
			s2 >> group >> count; // local_108/local_104 @008d3712-25
			QByteArray groupName;
			s2 >> groupName; // local_d8 @008d3732
			if (count > 0) {
				for (quint32 i = 0; i < count; ++i) { // @008d3759 do-while
					qint8 kindByte = 0;
					s2 >> kindByte; // local_10d @008d3759(operator>>(qint8)
					            //   语料 char 读)
					const char kind = static_cast<char>(kindByte);
					if (kind == '\x02') { // @008d376a kind==2 腿
						QByteArray name;
						s2 >> name; // local_d0 @008d37c3
						if (groupName != QByteArrayLiteral("LastSessions")) { // @008d37d3
							if (!firstGroupSeen) { // !bVar5 @008d37e0
								// vt+0x1f0 menu().selfName()=="Terminal"
								//   指针比对 @008d399a(串同相转写)
								//   && groupName=="SpecificSessions"
								if (groupName == QByteArrayLiteral("SpecificSessions")) {
									// @008d39ce 四槽字面栈(.rodata
									//   0xd0cc1d/cc09/cbf5/cbe1 实读):
									static const char *kStartupSlots[4] = {
									    "kit.startupSession1", "kit.startupSession2",
									    "kit.startupSession3", "kit.startupSession4"
									};
									for (const char *slot : kStartupSlots) { // @008d3a41 循环
										const QString val = kitScopedConfigValue(
										    QStringLiteral("Terminal"),
										    QByteArray(slot),
										    QString()); // 缺省 0/0x80000000 双零
									                    //   初始化 @008d3a20-2c
										const int comma = val.indexOf(QLatin1Char(','),
										                              0, Qt::CaseSensitive); // @008d3a8d
										if (comma > 0) { // 0 < iVar9 @008d3aa6
											const QString name = val.left(comma); // @008d3ab9
											// 会话库 = user.sessions(DAT_011c2200
											//   +0xe0 对位;ProfileLoader 判例 —
											//   单源线性扫同相)
											const QVariantMap sess = Workspace::sessionByUuid(
											    WorkspaceLoader_sessionsLibrary(),
											    name); // s_session_uuid_810056 @008d3acf
											if (!sess.isEmpty()) { // lVar17 != 0 @008d3ad4
												// FUN_008d2e46(pane,name,0,
												//   "Last",tabbar)@008d3aff —
												//   开会话腿 284B:FUN_0089e8de
												//   pane 查建 + FUN_008ca77c 下行
												//   + vt+0x60 失败清尾 — Pane
												//   域 cited(真下行不在本域,
												//   铁律 3;命中判定同相已落)
											}
										}
									}
								}
							}
							// QSplitter::addWidget(param_1[9])@008d39a6 —
							//   pane+9 复挂腿 cited(SplitterGroup 域)
						}
					} else if (kind == '\x01') { // @008d3793 kind==1 腿
						// new QSplitter(0x30)+表 append+addWidget —
						//   分裂腿 @008d38ae-909 cited(SplitterGroup 域)
					} else { // 其他 kind @008d38a9 前置
						// 表[i] widget addWidget + s_RenamedTitle_8bb3e6
						//   (1693B)重命名腿 — cited(>500B;Pane/TabBar
						//   深域;@008d3955-69 实参序 pane,kind,name,map)
					}
				}
			}
			// @008d3801 组尾:"LastSessions" == groupName → 表[i]
			//   restoreState + setChildrenCollapsible(SUB81=0)— cited
			//   (SplitterGroup 域;判定面同相:groupName 比对已落)
			firstGroupSeen = true; // bVar5 置位 @008d3971 循环尾
		}
	}
	// @008d346b flags&4 || version > 0xb9e7e621:窗条 UI 段。
	if (((flags & 4u) != 0) || version > 0xb9e7e621u) {
		QByteArray uiBlob;
		in >> uiBlob; // local_a8 @008d346b
		QDataStream ui(uiBlob); // @008d348b 子流
		bool menuBar = false, statusBar = false;
		ui >> menuBar;  // local_c8 @008d349b
		// vt+0x1d0("MenuBar",!b)@008d34c3 — 窗条切换虚槽(KitWindow
		//   域 cited;串 "MenuBar" 0x11826a0 实读)。行为承接:
		if (panel != nullptr)
			panel->setProperty("menuBarVisible", !menuBar); // 槽位 face 承接
			// (语料槽位未建模 — setProperty 命名面不发明真名;语料
			//   vcall 消费在 KitWindow 批,cited 占位同相可见性)
		ui >> statusBar; // local_c0 @008d34d6
		if (panel != nullptr)
			panel->setProperty("statusBarVisible", !statusBar); // @008d350e
			//   ("StatusBar" 0x1182668 实读;cited 同上)
		if (((flags & 4u) != 0) || version > 0xb9e7e622u) {
			bool toolBar = false;
			ui >> toolBar; // local_b8 @008d3534
			if (panel != nullptr)
				panel->setProperty("toolBarVisible", !toolBar); // @008d356c
				//   ("ToolBar" 腿;version>0xb9e7e622 门同相)
		}
	}
	// @008d3ba9 vt+0x240 != FUN_008d5bee → vcall(stream,flags)— 下行
	//   钩 cited(KitWindow 域;默认 = FUN_008d5bee 6B return 1 即无钩,
	//   本面恒默认同相)。
	return true; // uVar6=1 @008d3c17 尾
}

// === startupWindowTail — FUN_00766c26 &4 尾段(0023.c:33653-6f4c)+
// FUN_00766466(60B,33174)+ FUN_00766364(258B,33123 X11 cited)===
void startupWindowTail(QMainWindow *mainWindow, QDataStream &in)
{
	QByteArray subBlob;
	in >> subBlob; // local_c0 @00766f22
	QDataStream sub(subBlob); // @00766f42 子流
	bool fullscreen = false;
	sub >> fullscreen; // local_ca @00766f4b
	if (mainWindow != nullptr) {
		// FUN_00766466(60B)真身:0 腿 isFullScreen → windowState^4 /
		//   1 腿 |4 → setWindowState + show @33174-331a0 区段。
		if (!fullscreen) { // param_2 == 0 @00766466-70
			if (mainWindow->isFullScreen()) {
				mainWindow->setWindowState(mainWindow->windowState()
				                           & ~Qt::WindowFullScreen); // ^4 @0076648e
				mainWindow->show(); // @0076649e
			}
		} else {
			mainWindow->setWindowState(mainWindow->windowState()
			                           | Qt::WindowFullScreen); // |4 @00766480
			mainWindow->show();                                 // @007664a6
		}
		QByteArray geometry;
		sub >> geometry; // local_b8 @00766f64
		if (!fullscreen) // local_ca == false 门 @00766f7d
			mainWindow->restoreGeometry(geometry); // @00766f85
		bool onTop = false;
		sub >> onTop; // local_c9 @00766f8f
		// FUN_00766364(258B)X11 _NET_WM_STATE XSendEvent 面 — 平台
		//   私有(X11 only 语料;+0x30 位缓存 cited — 宿主槽位未建模;
		//   非 X11 环境语料同缺 → 行为同相不落)。
		(void)onTop;
		double opacity = 1.0;
		sub >> opacity; // local_b0 @00766fa8
		if (mainWindow != nullptr)
			mainWindow->setWindowOpacity(opacity); // @00766fb0
	}
}

// === startupWindowCreate — FUN_0075e0f8(765B,0023.c:27251)建窗窄面 ===
QMainWindow *startupWindowCreate(QMainWindow *mainWindow,
                                 const QByteArray &geometry)
{
	Q_UNUSED(mainWindow); // windows 表(+0x48 append)宿主槽位 cited —
	                      //   Slots 无表建模(批 150 判例);返回值 =
	                      //   调用侧承接(FUN_0075ffcc win 变量消费同相)
	QMainWindow *win = new QMainWindow(nullptr, Qt::WindowFlags(0)); // operator_new(
	                                                 //   0xf0)+MainWindow ctor(
	                                                 //   parent=0,flags=0)
	                                                 //   @0075e11a(MainWindow
	                                                 //   类未建模 — QMainWindow
	                                                 //   基面承接,铁律 6;
	                                                 //   KitWindowFace 抽象
	                                                 //   不可实例化)
	// FUN_00763b64(50B)= windows 表 append @0075e12e — 宿主 +0x48 表
	//   槽位 cited(不落;QList append 语义已在槽位注记)。
	if (!geometry.isEmpty()) { // *(int *)(*param_2 + 4) != 0 @0075e13a
		if (win->restoreGeometry(geometry)) // @0075e140
			return win; // cVar1 != 0 → LAB_0075e2c0 直跳 connectSignals
	}
	// 空腿:FUN_0075d6e8(74B,26718)= screen()->availableGeometry()
	//   (param_2==0 卫 → 全 -1)。宽 = aw.w*4(四舍五入代数直译:
	//   (w4 - w0 + 1)*4 后 /5 取整)/5;高 = (h*4)/5 同相;resize;
	//   居中 = ((左+右)/2 - w*0.5, (上+下)/2 - h*0.5) → move
	//   (@0075e1c9-2c0 区段四舍五入语料代数直译 — round-half-away
	//   双向腿)。
	const QScreen *scr = win->screen(); // QWidget::screen @0075e160
	const QRect avail =
	    scr != nullptr ? scr->availableGeometry() : QRect(-1, -1, -1, -1);
	const int w = qRound((avail.width() > 0 ? (avail.width() + 1) * 4.0 : -4.0) / 5.0);
	const int h = qRound((avail.height() > 0 ? (avail.height() + 1) * 4.0 : -4.0) / 5.0);
	win->resize(w, h); // QWidget::resize @0075e224
	win->move((avail.left() + avail.right()) / 2 - qRound(w * 0.5),
	          (avail.top() + avail.bottom()) / 2 - qRound(h * 0.5)); // @0075e260-2c0
	// 尾 mainWindow_connectSignals(win)@0075e2c0(@27327)— 宿主信号
	//   装配(109B 面 = MainWindowFace 已落;深装配链 0076b9ec 宿主批
	//   域 cited)。KitWindowFace 构造已含 acceptDrops 真腿(FUN_008cc692
	//   面),窗口装配窄面同相。
	return win;
}
