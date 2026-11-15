#pragma once

#include <QStatusBar>

class QLabel;
class QTimer;

// StatusBarFace — 语料状态栏子类(FUN_005a2d26 typeof 0x48 字节,
// 0018.c:18966 ctor 252B)承载面(批 196)。
// 字段(ctor 实读):+0x30 QLabel*(惰建,insertPermanentWidget)/
//   +0x38 QTimer*(惰建,消息超时)/ +0x40 int(ctor 清零,消费面 cited 不落)。
// 成员 = 语料槽位一一对位,不增减。
class StatusBarFace : public QStatusBar {
	Q_OBJECT
public:
	explicit StatusBarFace(QWidget *parent = nullptr); // FUN_005a2d26(252B)

	// FUN_005a2e58(654B,0018.c:19022):消息显示 + 超时定时器管理。
	//   timeoutMs < 1 → 停表释放；否则惰建 QTimer 并 start。
	//   空串 → tr("Ready")(0xc8b211 实读)。文本变化才发 messageChanged。
	void showFaceMessage(const QString &text, int timeoutMs);

private slots:
	// FUN_005a6552(325B,0018.c:21306)超时槽:停表释放 → 文本回 "Ready"。
	void onMessageTimeout();

private:
	QLabel *m_label = nullptr; // +0x30
	QTimer *m_timer = nullptr; // +0x38
};
