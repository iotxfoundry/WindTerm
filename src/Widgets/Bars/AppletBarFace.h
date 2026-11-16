#pragma once

#include "Widgets/Bars/StatusBarFace.h"

// AppletBarFace — 底部小程序条(StatusBarFace 派生,**不新增字段**)。
//
// 出处:RTTI "AppletBar";ctor 0x00526a7c(324B);dtor 0x008eeec4(29B)/
// deleting 0x008eef02(47B,operator_delete(_,**0x48**) —— 与 StatusBar 同尺寸,
// 说明本类**不新增字段**);metaObject 0x008eee64 / metacast 0x008eee7c(66B)/
// metacall 0x008eeebe(5B);槽分发 0x008f24a8(56B)。
//
// 继承链(metacast 实读两跳):
//   AppletBar::qt_metacast  strcmp("AppletBar") → StatusBar::qt_metacast
//   StatusBar::qt_metacast  strcmp("StatusBar") → QStatusBar::qt_metacast
//   ⇒ QStatusBar → StatusBar → AppletBar
//
// 槽(0x008f24a8 实读,3 条,全部转发到基类实现):
//   slot 0  showMessage(QWidget*, int)    → StatusBarFace::showFaceMessage
//   slot 1  showMessage(QWidget*)         → 同上,timeout = 0
//   slot 2  clearMessage()                → StatusBarFace::onMessageTimeout
class AppletBarFace : public StatusBarFace {
	Q_OBJECT

public:
	explicit AppletBarFace(QWidget *parent = nullptr); // 00526a7c
	~AppletBarFace() override;                        // 008eeec4

	// 0x00526be0(174B)—— applicationDirPath() + "/terminal/applets/" + name
	static QString appletPath(const QString &name);

public slots:
	void showMessage(const QString &text, int timeoutMs); // 0x008f24a8 slot 0/1
	void clearMessage();                                  // 0x008f24a8 slot 2
};
