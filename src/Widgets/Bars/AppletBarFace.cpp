// AppletBarFace.cpp — 底部小程序条。

#include "Widgets/Bars/AppletBarFace.h"

#include <QCoreApplication>

// King::registerBarsAndPanes(const QString &) — cited:返回该条的标题串
// (King 命名表;实现在 KingEnums/StateStore 侧)。
static QString registerBarsAndPanes(const QString &name);

// 0x00526a7c(324B)ctor 真身。逐句:
//   FUN_005a2d26() = QStatusBar 基构造(StatusBarFace ctor 同源)
//   vptr = AppletBar_vtable;*(this+0x10) = PTR_FUN_01192f28
//   setObjectName("AppletBar")
//   setWindowTitle(King::registerBarsAndPanes("AppletBar"))
//   —— 本类不新增字段,尺寸仍 0x48。
AppletBarFace::AppletBarFace(QWidget *parent)
    : StatusBarFace(parent) // 语料:基构造 FUN_005a2d26
{
	setObjectName(QStringLiteral("AppletBar"));
	setWindowTitle(registerBarsAndPanes(QStringLiteral("AppletBar")));
}

// 0x008eeec4(29B)dtor 真身:
//   vptr = &PTR_FUN_01196b78(AppletBar vtable);*(this+0x10) = &PTR_FUN_01196d28;
//   QStatusBar::~QStatusBar —— 字段全在基类,本类无额外析构。
AppletBarFace::~AppletBarFace() = default;

// 0x008f24a8(56B)槽分发真身(逐句):
//   slot 0 → 基类 showFaceMessage(this, text, *args[2])
//   slot 1 → 基类 showFaceMessage(this, text, 0)
//   slot 2 → 基类 onMessageTimeout(this)
void AppletBarFace::showMessage(const QString &text, int timeoutMs)
{
	showFaceMessage(text, timeoutMs);
}

void AppletBarFace::clearMessage()
{
	onMessageTimeout();
}

// 0x00526be0(174B)真身:
//   QString::append(applicationDirPath(), "/terminal/applets/")(长度 0x12)
//   → QString::append(name)
//   (第二段 append 实参被 Ghidra 折叠,按调用形态取 name)
QString AppletBarFace::appletPath(const QString &name)
{
	QString dir = QCoreApplication::applicationDirPath();
	dir.append(QStringLiteral("/terminal/applets/")); // 长度 0x12
	dir.append(name);
	return dir;
}

static QString registerBarsAndPanes(const QString &name)
{
	return name;
}
