#pragma once

#include <QList>
#include <QString>
#include <QWidget>

#include "Utility/KingEnums.h"

class QAbstractButton;

// MessageBarFace — 提示条(消息文本 + 一排按钮)。
//
// 出处:RTTI "MessageBar";dtor 0x008f7fc8(95B)/deleting 0x008f80fc(101B,
// operator_delete(_,**0x68**));metaObject 0x008f7e20(→ PTR_staticMetaObject_0119a2e0)/
// metacast 0x008f7f28 / metacall 0x008f7f6a(93B);信号发射器 0x008f7e38(56B);
// 信号分发桥 0x008f7e70(175B)。
//
// QMetaObject 实读(rev=8,class="MessageBar",methods=2,signals=2):
//   信号 `clicked(King::StandardButton button, const QString &text = QString())`
//     —— 单信号 + 默认实参克隆(moc 生成两条 method 记录,argc 0 / 2;
//        参数名 "button"/"text"、类型 "King::StandardButton" 均自串表实读)
//   发射器 0x008f7e38 = QMetaObject::activate(this, &staticMetaObject, 0,
//        (int, QString)) —— 即 clicked(button, text)
//
// 字段(dtor 实读):
//   +0x58 QString  消息文本
//   +0x60 QList<?> 按钮表(qlist_unref_dispose3 释放)
class MessageBarFace : public QWidget {
	Q_OBJECT

public:
	explicit MessageBarFace(QWidget *parent = nullptr);
	~MessageBarFace() override; // 008f7fc8

signals:
	// 参数顺序与类型自 QMetaObject 串表实读;枚举走 King 值域。
	void clicked(King::StandardButton button, const QString &text = QString());

private:
	QString m_text58;    // +0x58
	QList<QAbstractButton *> m_buttons60; // +0x60
};
