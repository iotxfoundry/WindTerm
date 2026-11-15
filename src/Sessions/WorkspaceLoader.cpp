#include "WorkspaceLoader.h"

#include <QDataStream>
#include <QHash>
#include <QRegularExpression>
#include <QScreen>
#include <QSet>
#include <QVariantMap>

#include "Actions/KitWindowFace.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/MainWindowFace.h"
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
	// @00522288 param_1!=0 门:面板类型名收集。
	const QString paneType = pane != nullptr
	                             ? pane->objectName().remove(QStringLiteral("Window"))
	                             : QString(); // FUN_008c9e64 @00522288(105B
	                                          //   真身语义 = objectName
	                                          //   去 "Window")
	// @005222df "Editor" 腿:windowFilePath 收集(session_defaultDir
	//   kind=2)。收集器 FUN_008d0cf2(339B)cited — 对位面 =
	//   pane 子 QWidget 树 windowFilePath 逐项(EditorWindowFace 域,
	//   windowFilePath 写侧未建模 — kind=2 腿仅落遍历骨架,不发明
	//   路径源,铁律 3)。
	// @00522df8 "Terminal" 腿:收集器 FUN_008d097c(223B)cited —
	//   mux 子件 QVariant 遍历(vt+0x78 uuid 取);kind=6 同因 cited。
	// @00522495 kind 位:Terminal/Browser → 7,else 3(会话库腿)。
	const int libraryKind =
	    (paneType == QLatin1String("Terminal") || paneType == QLatin1String("Browser"))
	        ? 7
	        : 3; // @005224c5 local_218 双腿
	// @005224c5 FUN_008caf52(48B)= vt+0x1f0 menu 单例 → vt+0x10 收集
	//   — CGlobalConfigFace 域(会话数组);对位 = sessionLibrary
	//   注入(CTERMINAL-CONFIG 判例;DAT_011c2200+0xe0 消费同相)。
	QHash<QString, int> seen; // FUN_0052523e(165B,18431)命中早退腿
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
		if (text.isEmpty() && data.isEmpty())
			key = uuid; // json_isNullType!=0 腿 @00522620(pQVar25 直键)
		else if (!text.isEmpty() && !data.isEmpty())
			key = data; // @005235d1 session_defaultDir(text,data,kind)
			            //   键面 = data 串(FUN_0052523e key = local_190
			            //   = "data" 取值 @0052365a)
		else
			continue; // 双取其一空 → 不落(语料 *(local_198+4)!=0 &&
			          //   *(local_190+4)!=0 门 @0052340a 同相)
		if (seen.contains(key))
			continue; // *puVar12 == local_1b0 未命中才入 @0052254d
		seen.insert(key, libraryKind); // node+3 = local_218 @00522657
		out.keys.append(key);
		out.kinds.append(libraryKind);
	}
	// @0052271e "Editor" 目录扫描腿(cited:FUN_008bca9e(pane,1) 域
	//   未建模 + QDirIterator 深度枚举 — kind=1/0 腿,EditorWindow
	//   windowFilePath 写侧缺,不发明路径源)。
	// @005237e3 "Terminal" session.uuid 匹配腿(cited:URL 正则
	//   "://([^/]++)/" captured 面 + s_session_protocol_810d6e 1760B
	//   protocol 取腿 — pane vt+0x78 串消费在 Pane 域,unreachable 于
	//   本面 pane 抽象 QObject;三件套/键面已落上循环)。
	// @00522a48 尾容量代数(≤9 截断/9999 cap)+ FUN_00632426 转移构造
	//   — QHash 内部面,QHash 承接同相。
	return out;
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
