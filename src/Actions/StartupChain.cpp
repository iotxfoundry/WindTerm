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
		// 建窗腿:FUN_0075e0f8(765B,0023.c:27251)— 批 154 真身
		//   (startupWindowCreate:restoreGeometry/screen 居中缩放腿
		//   FUN_0075d6e8 74B + mainWindow_connectSignals 尾 cited 宿主域);
		//   窗表 append(FUN_00763b64)宿主 +0x48 槽位 cited(Slots 无表
		//   建模 — 批 150 判例)。
		QMainWindow *win = startupWindowCreate(mainWindow, geometry); // @2844c
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
