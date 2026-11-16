// BarFaces.cpp — QuickBar / TransferBar(批 446/447)
#include "BarFaces.h"

#include <QCoreApplication>
#include <QVariant>

#include "App/ThemeIcons.h"

// FUN_0056e26e(402B)QuickBar ctor 真身
QuickBarFace::QuickBarFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @0056e26e
	, m_host30(parent)                    // +0x30 = 父
{
	setObjectName(QStringLiteral("QuickBar"));  // @0056e2d0(strlen 8)
	// King__registerBarsAndPanes("QuickBar")(注册 + setWindowTitle) — cited
}

// FUN_005858fe(449B)TransferBar ctor 真身
TransferBarFace::TransferBarFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @005858fe
{
	setObjectName(QStringLiteral("TransferBar")); // @00585969(strlen 0xb)
	// King__registerBarsAndPanes("TransferBar")(注册 + setWindowTitle) — cited
}

// FUN_0075c480(80B)带门全局写真身
bool QuickBarSettings::setGlobalSetting(const QByteArray &key, const QVariant &value, bool force)
{
	// if (FUN_005d972a(DAT_011c1240) || force) FUN_0090e084(app, key, value);
	//   两腿均 cited(设置启用面/真实写入面未建模)
	Q_UNUSED(key); Q_UNUSED(value); Q_UNUSED(force);
	return false;
}

// s_quickbar_showMultipleGroups_6cf858(190B)真身
void QuickBarSettings::setShowMultipleGroups(bool on)
{
	setGlobalSetting(QByteArray("quickbar.showMultipleGroups"), QVariant(on), false);
}

// s_quickbar_showGroupTitle_6cf926(190B)真身
void QuickBarSettings::setShowGroupTitle(bool on)
{
	setGlobalSetting(QByteArray("quickbar.showGroupTitle"), QVariant(on), false);
}

// s_quickbar_showCommandsInOrder_6cf9f5(190B)真身
void QuickBarSettings::setShowCommandsInOrder(bool on)
{
	setGlobalSetting(QByteArray("quickbar.showCommandsInOrder"), QVariant(on), false);
}

// s_king__start_6cb4e5(392B)启动/停止图标真身
void StartStopButton::setRunning(bool running, QWidget *button)
{
	if (button == nullptr)
		return;
	const QString name = running ? QStringLiteral("king::stop")   // 实读
	                             : QStringLiteral("king::start");  // 实读
	// 语料按 +0x30 图标槽 setIcon(theme_icon_load_svg(名)) — 以属性承接:
	button->setProperty("icon", name);
}

// s_quick_uuid_6cfc46(214B)快捷命令 uuid 查在否真身(结构段)
bool hasQuickUuid(const QString &uuid)
{
	// 配置表 = DAT_011c2200 系(+0x38 数组);逐项 json_get_string_default(obj,
	//   **"quick.uuid"**, "")→ 与 uuid compare → 命中 true — cited
	Q_UNUSED(uuid);
	return false;
}
