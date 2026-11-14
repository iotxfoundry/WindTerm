#include "StartupChain.h"

#include <QTimer>

#include "KitWindowFactory.h"
#include "Editor/CTerminalConfig.h"

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
	// @00762748-278f:QVariant("dige-black") + global_setting_get
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
	// @0076289a:恢复门 FUN_0075ffcc(504B,0023.c:28400)— cited 占位:
	//   QDataStream 魔数 0xb9e7e600 读 DAT_011c1240,成功腿逐条
	//   operator>> + FUN_0075e0f8 + FUN_00766c26(flags=1)恢复页;
	//   返回"未恢复"同相 → 走失败腿(批 149 深度项,Phase 4a 转写)。
	bool restored = false; // FUN_0075ffcc cited 占位(同相:未恢复)
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
