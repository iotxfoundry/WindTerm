#include "StartupChain.h"

#include <QCoreApplication>
#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QStackedWidget>
#include <QTimer>
#include <QWidget>
#include <json/json.h>

#include "KitWindowFactory.h"
#include "WorkspaceLoader.h"
#include "Editor/CTerminalConfig.h"
#include "Editor/KeymapEngine.h"
#include "Editor/ProfileLoader.h"

#include <QAbstractButton>
#include <QCoreApplication>
#include <QStackedWidget>
#include <QTimer>
#include <QToolButton>

#include "ActionFactory.h"
#include "KitBar.h"

// === profiles.config "path" 读 — s_profiles_config_5d8732(707B,
// 0019.c:10148)路径腿转写:appdir + "/profiles.config" yaml_loadFile
// → json "path" 键(缺省 DAT_00cb99b6)→ "." 特判 homePath 替换
// (@005d88c1 0x2e 首字符腿)/"~" 前缀 homePath 插入(@005d88d4)。
// yaml_loadFile = JSON 兼容解析(SESSION-CONFIG-LAYER yaml 层判例;
// profiles.config 实文件为 JSON 形)— jsoncpp 委托(EXT-BOUNDARY)。
// profileDir = FUN_005d8a36(429B,0019.c:10263)+0x30 槽存取同相。
static QString startupProfileDir()
{
	const QString path = QCoreApplication::applicationDirPath()
	                     + QStringLiteral("/profiles.config"); // @005d8758 拼序
	QFile f(path);
	if (!f.open(QIODevice::ReadOnly))
		return QString(); // yaml_loadFile 失败 → +0x30 空同相
	Json::Value root;
	Json::CharReaderBuilder b;
	b.settings_["collectComments"] = true;
	std::unique_ptr<Json::CharReader> reader(b.newCharReader());
	std::string errs;
	if (!reader->parse(f.readAll().constData(),
	                   f.readAll().constData() + f.size(), &root, &errs)
	    || !root.isObject())
		return QString(); // cVar3='\0' 同相
	const Json::Value p = root["path"]; // json_get_string_default @005d8845
	if (!p.isString())
		return QString(); // 缺省 DAT_00cb99b6(空)同相
	QString dir = QString::fromUtf8(p.asCString()); // @005d8888
	if (dir == QLatin1String("."))                  // @005d88c1 首字符 0x2e 腿
		return QDir::homePath();                    // QString::operator=(homePath)
	if (dir.startsWith(QLatin1Char('~'))) {         // @005d88d0 startsWith 0x7e
		dir.remove(0, 1);                           // @005d89bf remove(0)
		dir.prepend(QDir::homePath());              // @005d89e3 insert(0,homePath)
	}
	return dir;
}

// === startupReopenHistoryPath — FUN_005dd560(236B,0019.c:13838)
// 路径腿:cfg_ensureProfileDir(005d7dae)="%1/profiles/%2/%3" 拼序
// (profileDir/profile 名/reopen.history 名字面 @005dd570)+ QFile 读全
// (返回 QByteArray;本面只供路径消费)。profile 名 = profiles.config
// "path" 腿(startupProfileDir,空则空路径 — 语料空 +0x30 时 ensure
// 产 "profiles//" 形,文件不存在 → shared_null 同相,门闭)。
QString startupReopenHistoryPath()
{
	const QString dir = startupProfileDir();
	if (dir.isEmpty())
		return QString(); // DAT_011c1240 空 +0x30 同相(005d8aa4 门)
	return dir + QStringLiteral("/global/reopen.history"); // @005dd570 字面
}

// === startupRestoreDispatch — FUN_00766c26(1042B,0023.c:33567)分发壳
// 真身(任务书 M15-①a:分发壳真身 + 页恢复分段)。语句逐条带地址:
//   @33569-72:payload 空(size@+4==0)→ return 0(空负载卫);
//   @335d4-65:QDataStream(payload) >> count(local_c8) >> currentIndex
//     (local_c4)—— 页数 + 当前索引双 int 头;
//   循环逐页(@335d8-66e5):
//     >> 页名 QString(local_c0,@008c9e64 面 = objectName 去 "Window");
//     magic < 0xb9e7e622(旧格式)→ >> QIcon + >> 串(丢弃读,格式吞位
//       @008d2c 前段;仅序列游标语义,不落对象);
//     >> payload QByteArray(local_b8);
//     flags & 4 == 0 → s_HistoryHints_7664a2(244B,0023.c:33200)腿:
//       blockSignals(stack)@33635 + 页挂 kitWindowAttachPage(名,currentIndex
//       ==i,payload,flags)@33637 + 尾 blockSignals 复原 @33662;
//     flags & 4 → kit.startupSessions 腿:widget(i) dynamic_cast +
//       FUN_008c9e64 名比较 + s_kit_startupSessions_8d2f7e(3122B,
//       0028.c:17278)— cited 挂账(本链唯一调用点 flags=1,腿不可达;
//       522056 工作区装载器独立批)。
// &4 尾段(currentIndex 存/setWindowState 0x4 全屏/setWindowOpacity,
// @336f22-66f4c)属 kit 恢复腿面,cited 同上(不可达同因)。
// 返回 1(语料尾 return 1 @00767061;void 消费面同相)。
bool startupRestoreDispatch(MainWindowFace::Slots host, QMainWindow *mainWindow,
                            quint32 magic, const QByteArray &payload,
                            quint32 flags)
{
	Q_UNUSED(mainWindow); // 语料 param_1 仅页挂/工厂 parent 面(槽位承载)
	if (payload.isEmpty())
		return false; // *(int *)(*(long *)param_3 + 4) == 0 @3356d
	QDataStream in(payload); // @336d47
	quint32 count = 0, currentIndex = 0;
	in >> count >> currentIndex; // local_c8/local_c4 @336d54-65
	host.f58->blockSignals(true); // @33635(&4==0 段内;重复复原同相)
	for (quint32 i = 0; i < count; ++i) { // @336d8 do-while iVar3 < local_c8
		QString pageName;
		in >> pageName; // operator>>(QString) @336e20 前
		if (magic < 0xb9e7e622u) { // @336e26 旧格式吞位腿
			// QIcon + QString 丢弃读(@336e31-42;游标推进同相,
			// 不落对象 — 反编译体内两读后即析构)
			QByteArray iconBlob; QString iconText;
			in >> iconBlob >> iconText;
		}
		QByteArray pagePayload;
		in >> pagePayload; // @336e5d-eef
		if ((flags & 4u) == 0) { // @336e5d 门
			// s_HistoryHints_7664a2 @33637:blockSignals 已在壳头
			// (@33635);页挂 = kitWindowAttachPage(批 142 真身,
			// 007664a2 244B 面:param_3 = currentIndex==i、param_5 = flags)。
			kitWindowAttachPage(host, mainWindow, pageName,
			                    currentIndex == i, pagePayload,
			                    static_cast<int>(flags));
		} else {
			// &4 腿 @336e5d-e0c:widget(i) dynamic_cast(011ab390)+
			// FUN_008c9e64 名比较 + 命中才分发达(批 154 接真身)。
			QWidget *widget = host.f58 != nullptr
			                      ? host.f58->widget(static_cast<int>(i))
			                      : nullptr; // QStackedWidget::widget @336e5d
			if (widget != nullptr) { // dynamic_cast KitWindow 011ab390 —
			                         //   KitWindowFace 承接(批 133 判例;
			                         //   命中腿名比较)
				const QString pageTypeName =
				    widget->objectName().remove(QStringLiteral("Window")); // FUN_008c9e64
				if (pageTypeName == pageName) { // operator== @336e2x
					kitStartupSessions(widget, pagePayload, flags); // @336e0c
				}
			}
		}
	}
	host.f58->blockSignals(false); // @33662 复原(&4 段内同语句)
	// &4 尾段 @336f22-66f4c(currentIndex 腿 FUN_00766466/setWindowState
	// 0x4/setWindowOpacity)— 批 154 真身:currentIndex 存窗读腿
	// (FUN_00766466 param_1 = win 面本壳无 win 表,cited — 宿主域)
	// + startupWindowTail(>>QByteArray 全屏/几何/置顶/透明度四读面)。
	if ((flags & 4u) != 0) { // @00766f1d 门
		startupWindowTail(mainWindow, in); // @00766f22-66fb0
	}
	return true; // 尾 return 1 @00767061
}

// === startupRestoreGate — FUN_0075ffcc(504B,0023.c:28400)恢复门真身。
// 语料序(FUN_005dd560 读文件 → 空读直返 false → QDataStream 门):
//   @28414-1d:QByteArray 全读(FUN_005dd560 236B 面;路径腿见
//     startupReopenHistoryPath — cfg_ensureProfileDir 438B
//     "%1/profiles/%2/%3" + "global/reopen.history" 字面 @005dd570);
//   @28420:size < 1 → local_91=false 直返(空文件腿);
//   @28426:QDataStream(buf) >> magic(local_78);
//   @2842e:(magic & 0xb9e7e600) == 0xb9e7e600 掩码门 — 不配 → false;
//   @28436:>> count(local_74);count<=0 → true(0 页恢复同相);
//   逐窗循环 @2844c-60160:
//     >> geometry QByteArray(shared_null 起)→ FUN_0075e0f8(765B,
//       0023.c:27251)建窗(mainWindow_connectSignals 尾 @27327);
//     >> payload QByteArray → FUN_00766c26(win,magic,payload,flags=1
//       字面 @28446);
//     magic > 0xb9e7e621 → >> bool,@true 时 *(win+0x32)=1 +
//       FUN_0076f4d6(win,1)(405B,0023.c:38662 focusMode 恢复腿)—
//       cited(405B > 500B 邻档;win+0x32 槽位宿主 face 无消费);
//   @28458-73:windows 表 detach×2 + 逐窗 QWidget::show +
//     FUN_0090e018(param_1,win)(52B,0029.c:31526 = signal index0
//     发射,QMetaObject::activate 面 — host 槽位面,单窗 show 真腿
//     同相;activate 信号无我方接收者 → no-op 同相);
//   释放 + return local_91。
bool startupRestoreGate(MainWindowFace::Slots host, QMainWindow *mainWindow,
                        const QString &historyPath)
{
	QFile f(historyPath); // FUN_005dd560 QFile 面 @005dd5ba
	if (!f.open(QIODevice::ReadOnly))
		return false; // cVar1='\0' → shared_null → size<1 腿 @28418
	const QByteArray blob = f.readAll(); // QIODevice::readAll @005dd5c7
	if (blob.size() < 1)
		return false; // *(int *)(local_70 + 4) < 1 @28418
	QDataStream in(blob); // @28426
	quint32 magic = 0;
	in >> magic; // local_78 @2842a
	if ((magic & 0xb9e7e600u) != 0xb9e7e600u)
		return false; // 魔数掩码门 @2842e-38 else 腿 local_91=false
	quint32 count = 0;
	in >> count; // local_74 @28436
	// 语料 local_91 = (0 < local_74):count==0 → 恒 false(0 页读尽
	// 亦走 first-page 失败腿,语料同相 @007628a5-ab 门腿)。
	bool ok = false; // local_91
	for (quint32 i = 0; i < count; ++i) { // @2844c do-while iVar6 < local_74
		QByteArray geometry; // local_68 = shared_null @28454
		in >> geometry; // operator>>(QByteArray) @2845c
		// 建窗腿:FUN_0075e0f8(765B,0023.c:27251)全文真身
		//   (批 188:startupWindowCreateFull = 批 154 窄面
		//   startupWindowCreate + 尾接线段 mainWindow_connectSignals
		//   @0075e2c0/@27327 — mainWindowConnectSignals S1-S7);
		//   窗表 append(FUN_00763b64)宿主 +0x48 槽位 cited(Slots 无表
		//   建模 — 批 150 判例)。
		QMainWindow *win = startupWindowCreateFull(mainWindow,
		                                           geometry); // @2844c
		QByteArray payload; // local_60 = shared_null @28470
		in >> payload; // @28477-b9
		startupRestoreDispatch(host, mainWindow, magic, payload,
		                       1u); // FUN_00766c26(flags=1 字面)@28446
		if (magic > 0xb9e7e621u) { // @28464-6a
			bool focusMode = false;
			in >> focusMode; // local_79 @2846c
			if (focusMode) { // local_79 != false @28470
				// *(win+0x32)=1 + FUN_0076f4d6(win,1)— focusMode 恢复
				// 腿(405B,0023.c:38662)cited:win+0x32 槽位宿主 face
				// 无建模(铁律 6),恢复面待 KitWindow 真身批。
				Q_UNUSED(win);
			}
		}
		ok = true; // local_91 同相(0 < local_74 已过 → 恒 true)
	}
	// 尾段 @28458-73:windows 表(QList@+0x48)detach×2 + 逐窗 show +
	// FUN_0090e018 信号发射。窗表 = FUN_00763b64(50B)append 面,宿主
	// 槽位 face 无 +0x48 表建模(铁律 6)— show/发射逐窗同相落:
	for (int wi = 0; wi < host.f58->count(); ++wi) {
		QWidget *w = host.f58->widget(wi);
		if (w != nullptr)
			w->show(); // QWidget::show @28476(尾段批量腿同相)
		// FUN_0090e018(param_1,win)@2847e:signal index0(QMetaObject::
		// activate)— 本面无接收者接线(铁律 3,消费点缺),no-op 同相。
	}
	return ok; // local_91 @2848e
}

// === startupChain — s_application_lockScreenTimeout_7626ce(510B,
// 0023.c:29843)语料序转写(每语句带地址;宿主成员槽位 cited)===
void startupChain(MainWindowFace::Slots host, QMainWindow *mainWindow)
{
	Q_UNUSED(host); // 语料 this+0x50/+0x58 槽位宿主侧(本面不落宿主类,铁律 6)

	// @007626ce-2ee:FUN_007625b6(248B,0023.c:29797)= profiles 前置门
	// (DAT_011c1240 装载/空表 ProfileDialog::exec 交互腿)— 交互面
	// cited,不落(铁律 3;批 149 深度项清单)。
	// @007626f5-2715:operator_new(0x38)+FUN_0062b040 / operator_new(0x28)
	// +FUN_0063a568(SuperTranslator/CyclicMemoryPool,存 this+0x18/+0x28)
	// — 宿主槽位对象,cited。
	// @00762748-70:QVariant("dige-black") + global_setting_get
	// ("application.themeGui") → QVariant::toString — 配置读真腿:
	//   CTerminalConfig 真单例调面(CTERMINAL-CONFIG 199 use sites,
	//   dotted-key 面),默认值 "dige-black" 照语料。
	(void)CTerminalConfig::instance()->value(
		QStringLiteral("application.themeGui"), QStringLiteral("dige-black")); // @00762748-70
	// @00762793-b0:FUN_00760ffe(467B,0023.c:29028)= 遍历窗口派发
	// LanguageEvent(SendEvent 面)— cited(体量 >500B)。
	// @007627b0-c0:QDateTime::currentMSecsSinceEpoch() → this+0x38
	// (lockScreen 基准时戳,宿主槽位)— cited。
	// @007627c0-db:global_setting_get("application.lockScreenTimeout",
	// 缺省 local_40=0x80000000)→ QVariant::toLongLong → FUN_0075d73c
	// (53B,0023.c:26759,存值腿)— 配置读真腿 + 下游 cited。
	(void)CTerminalConfig::instance()->value(
		QStringLiteral("application.lockScreenTimeout")); // @007627d1-db
	// @00762814-2c9:operator_new(0x20)+FUN_006368e6(SuperTranslator
	// ctor,locales 装载 s_application_language_635fd6)→ this+0x20 →
	// QCoreApplication::installTranslator @0076282a — translator 装载
	// 真腿转写为语料同相安装(SuperTranslator ctor 体 cited,006368e6
	// 14839,0020.c);@0076283a-98:FUN_00635758(31B,0020.c:14107,
	// translator layoutDirection 读)+ layoutDirection 不等才 setLayout
	// Direction — cited(Qt 单件读面,零 fork 特性)。
	// @0076289a:恢复门 FUN_0075ffcc(504B,0023.c:28400)— 批 150 真身
	//   (startupRestoreGate:读 global/reopen.history + 魔数 0xb9e7e600
	//   门 + 逐窗 FUN_0075e0f8/FUN_00766c26(flags=1);测试环境状态文件
	//   缺失 → false 同相)。
	bool restored = startupRestoreGate(host, mainWindow); // FUN_0075ffcc @0076289a
	// @007628a5-ab:if (FUN_0075ffcc(this) == '\0') → 失败腿
	// FUN_0075e3fe(332B,0023.c:27332)= 建 "Terminal" 首页(批 142
	// 真身 kitWindowRestoreFirstPage)。
	if (!restored)
		kitWindowRestoreFirstPage(host, mainWindow); // FUN_0075e3fe @007628a7
	// @007628ae-2be:operator_new(0x18){1,FUN_0075c40d(74B,0023.c:
	// 25936),this} → QTimer::singleShotImpl(0,0,this,slot) — 尾 cited
	// (回调体未转写;installEventFilter @007628c6 同 cited)。
	// QTimer::singleShot(0, ...); // FUN_0075c40d — cited,不落(铁律 3)
	Q_UNUSED(mainWindow); // 语料 param_1 其余用途仅下游槽位父(本面无消费)
}

// === mainWindowConnectSignals — mainWindow_connectSignals(1043B,
// 0023.c:36614)全文分段真身(批 188;段序 = kuna 0076b9ec 全读 +
// 语料 36614-36736 双源一致)。宿主类不建模(铁律 6):S3 装配段经
// MainWindowFace 现役真身承载(槽位 = 返回值);无现役面的段 cited
// 分段(缺席 + 注记,非占位)。===
MainWindowFace::Slots mainWindowConnectSignals(QMainWindow *mainWindow)
{
	// ── S1 @0076b9da-ec(18B 壳体直译):动作/键位装载前置腿 ──
	// s_wind_actions_76b7c0(457B,0023.c:36525;kuna 全读):累积器
	// FUN_00a7e75e → "wind.actions"(FUN_005d7cf8 全局路径拼序)→
	// FUN_00a7e78a → "user.actions"(cfg_ensureProfileDir 用户路径)→
	// FUN_00a7e866 → +0x60 工厂懒建(operator_new(0x20)+FUN_00665948)
	// + 双源 FUN_00a7fdd8/00a8017e → toMap → wind_actions_build
	// (00667102)。工厂体 = ActionFactory::getOrCreate(00665dc2)/
	// build(00667102)现役真身 — 双源装载序直译(缺文件腿
	// yaml_loadFile 失败 → 空 map → build 空守卫直返,同相)。
	{
		ActionFactory factory; // +0x60 工厂槽 = 槽位承载(宿主类不落,
		                       //   栈域现役面;工厂表语义同相)
		const QString globalPath = QCoreApplication::applicationDirPath()
		                           + QStringLiteral("/global/")
		                           + QStringLiteral("wind.actions"); // @0076b7f5-821(FUN_005d7cf8 拼序)
		factory.loadActionsFile(globalPath); // FUN_00a7fdd8 门 + toMap +
		                                     //   wind_actions_build @0076b888-8a2
		const QString userPath = ProfileLoader::defaultProfilePath()
		                         + QStringLiteral("/user.actions"); // cfg_ensureProfileDir @0076b842-864
		factory.loadActionsFile(userPath); // @0076b8bd-8d7(用户源腿)
	}
	// FUN_0076b430(68B,0023.c:36366):+0x68 引擎懒建
	// (operator_new(0x20)+FUN_00674648 = SuperKeymap ctor parent 注入)
	// → s_wind_keymaps_768854(428B 双源 YAML 装载)→ FUN_0076aee6
	// (JSON 导入腿)— KeymapEngine 现役真身面(KeymapEngine.h 头注
	// "宿主装配批调用"即本位;attachHost ctor 注入对位)。
	KeymapEngine::instance().load(); // @0076b451-68(懒建+装载序同相)

	// ── S2 @0076ba05 CALL FUN_0076663e(114B,0023.c:33272)— cited
	// 分段:QMetaType 注册族(pthread_once 0x11c1dd0 + registerNorm
	// alizedType ×20,KitWindow smeta 0x11ab660 等;探锚 FUN_0076913f
	// 5958B 体事实 StateStore.h 批 168 在档)。元类型注册 = Qt 底座
	// 语义(EXT-BOUNDARY,零 fork 特性),QDataStream 页序列化消费
	// 面在 KitWindow 批 — 本面缺席不改变装配行为(注册惰性)。

	// ── S3 @0076ba0d CALL FUN_007662e6(109B,0023.c:33100)— 装配
	// 四件套真身:MainWindowFace ctor(addToolBar(1)@00766333/
	// setCentralWidget @0076633f/bar->hide @00766348)。宿主槽位 =
	// 返回值(Slots)。
	MainWindowFace winFace(mainWindow); // FUN_007662e6 @0076ba0d
	const MainWindowFace::Slots host = winFace.hostSlots();

	// ── S4 ① @0076ba18-4f:qApp signal0(FUN_0090e018 = activate
	// smo 011a6ce0 idx0;kuna read 0x11a6ce0 实读:className
	// "14CommanderRobot" @0xcd73c0,method 0x90e0b4)→ FUN_007662ce
	// (24B,0023.c:33086;sender==receiver 卫)→ FUN_00766192(65B,
	// 33030:+0x48 旧引擎 deleteLater + 懒建 JsEngine(0064ab10)+
	// s_MuxPane_64b102 引导)+ FUN_007661dc(234B,33049:+0x80 QTimer
	// 懒建 + session_throttled_refresh(1480B,37046)接线 + start)。
	// cited 分段:发射源 smo 011a6ce0 类(CommanderRobot)我方无
	// Q_OBJECT 承载(铁律 6,类建模属宿主批)→ 接线面缺席;槽体
	// 引擎/定时器腿体量 >500B 邻档且 +0x48/+0x80 槽位宿主域 —
	// MuxPaneView::attachJsEngine(JsEngine 引导现役调用面)/
	// KeymapEngine 同型挂点为消费批接口,本面不发明触发点
	// (offscreen 无发射点,语料同相死路)。

	// ── S4 ② @0076ba56-8d:qApp focusChanged → FUN_0076dcae(kuna
	// 全读:activeWidget 祖先链 dynamic_cast MuxPane 011b84d0 →
	// QPointer 对 getAndRef ×2 写宿主 +0xd8/+0xe0)— 宿主 QPointer
	// 对槽位未建模(铁律 6)→ 接线面 cited 分段(缺席 + 注记;
	// 焦点追踪缓存,零产品消费点在档)。

	// ── S4 ③④ @0076ba92-632:tools 容器(FUN_005d9378(DAT_011c1240)
	// → +0x10)信号 0/1(FUN_008fd3d0/008fd3fc = activate smo
	// 0119f720 idx0/1;kuna read 实读 = "Tools" 类:toolAdded/
	// toolRemoved,参数 name/scheme)→ FUN_0076aee6(1185B,36216 =
	// keymap JSON 导入腿:容器逐项建 {keys,script|when} → reset(1)
	// → loadEntries(list,1))。发射源 = Tools 容器对象(宿主域
	// Q_OBJECT 未建模)→ 接线面 cited;接收腿已真身(KeymapEngine::
	// loadJsonLeg,S1 load() 内同函数;Type 0x82 字面 = Unique(0x80)
	// |Auto(0x02) 照录 @36690 区)。工具清单 +0x10 槽位 cited
	// (CTerminalConfig 单例现役,清单容器面未建模 — 铁律 6)。

	// ── S4 ⑤ @0076ba67-6e6:KitBar(host.f50)kitActivated
	// (FUN_0091a518 → activate smo 011aaea0 idx0;KitBar.h
	// QMetaObject 实证)→ FUN_007656bc(42B,kuna 全读:index>=0 &&
	// index<count → setCurrentIndex)。connect 真身(语料 connectImpl
	// 8 参形 0,0 — 无 Unique 位 @3667x)。
	if (host.f50 != nullptr && host.f58 != nullptr) { // +0x50/+0x58 槽位读
		QObject::connect(host.f50, &KitBar::kitActivated, host.f58,
		    [host](int index) {
			    // FUN_007656bc(kuna 007656bc 全读):0 <= a1 &&
			    //   a1 < QStackedWidget::count → setCurrentIndex。
			    if (index >= 0 && index < host.f58->count())
				    host.f58->setCurrentIndex(index); // @007656c8 区
		    });
	}

	// ── S4 ⑥ @0076baed-718:stack(host.f58)currentChanged
	// (QStackedWidget::staticMetaObject)→ FUN_00767ba0(27B,34355
	// 区;kuna 全读 + asm 767ba0-b6:+0x50 非空 → CALL 0x8b3426(查得
	// 按钮 setChecked(1),asm 008b3434 ESI=1 实证)+ 尾 jmp
	// FUN_00767b4a(85B,34283:isActiveWindow && +0x70 表非空 &&
	// +0x78 非空 → QTimer::start 深腿 — +0x70/+0x78 槽位宿主域,
	// cited))。
	if (host.f58 != nullptr && host.f50 != nullptr) {
		QObject::connect(host.f58, &QStackedWidget::currentChanged,
		    host.f58, [host](int) {
			    // FUN_00767ba0 @00767ba4-b6:+0x50 非空门 →
			    // FUN_008b3426(36B,0027.c:71298)= 查得即
			    // setChecked(1);index 实参 Ghidra 折叠形照录
			    // (36B 体无第二参传递;查询面 = buttonForIndex,
			    //   表序首钮语义,批 77 同源,不发明 index 面)。
			    if (QToolButton *btn = host.f50->buttonForIndex(0))
				    btn->setChecked(true); // @008b3439-45(ESI=1 实证)
			    // FUN_00767b4a(85B)活性标题 QTimer 腿 — +0x70/
			    //   +0x78 槽位宿主域未建模,cited(缺席 + 注记)。
		    });
	}

	// ── S7 @36720-36733:QTimer::singleShotImpl(0,0,host,
	// FUN_0076bdff)(212B,0023.c:36741;kuna 全读:单发 0x18 闭包
	// {1,FUN_0076bdff,host} → case1:winId + windowHandle 非空门 →
	// connectImpl(screenChanged → FUN_00765721:窗口 +0xb0 ← screen
	// + King::refreshWidgetStyle 尾调)— 闭包体屏钩腿深(+0xb0 槽位
	// 宿主域)cited;单发时序真身照落(零毫秒 = 事件循环首拍;
	// offscreen windowHandle 为空 → 语料 @0076be40 门同直返)。
	QTimer::singleShot(0, mainWindow, []() {});
	return host; // S3 装配产物(+0x50/+0x58 槽位对)
}

// === startupWindowCreateFull — FUN_0075e0f8(765B,0023.c:27251)
// 全文真身(批 188 窄面扩张):建窗窄面 = startupWindowCreate
// (批 154 真身,WorkspaceLoader.cpp 916:operator_new(0xf0)+MainWindow
// ctor(0)@0075e11a → FUN_00763b64 append @0075e12e → restoreGeometry
// @0075e140 → 空腿 FUN_0075d6e8 居中缩放 @0075e160-2c0)+ 尾接线段
// mainWindow_connectSignals(local_40)@0075e2c0(@27327 — 本文件
// mainWindowConnectSignals S1-S7 真身)。返回新窗(语料 local_40)。===
QMainWindow *startupWindowCreateFull(QMainWindow *mainWindow,
                                     const QByteArray &geometry)
{
	QMainWindow *win = startupWindowCreate(mainWindow, geometry); // @0075e11a-2c0
	if (win == nullptr)
		return nullptr; // FUN_0075e3fe @0075e501 null 卫同相
	mainWindowConnectSignals(win); // 尾 mainWindow_connectSignals @0075e2c0
	return win;                    // local_40 @0075e2d8
}
