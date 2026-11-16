#ifndef SUPERBRIDGE_H
#define SUPERBRIDGE_H

#pragma once

#include <QObject>
#include <QVariant>
#include "../Utility/KingEnums.h"

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// Base class of Ssh/Shell/Telnet/Tcp/Serial bridges. Declares only the
// lifecycle/IO signal surface; concrete bridges add protocol specifics.
class SuperBridge : public QObject
{
	Q_OBJECT

public:
	SuperBridge(QObject *parent = nullptr);
	virtual ~SuperBridge(void) = default;

signals:
	void attached();
	void detaching();
	void detached();
	void readyRead();
	// moc 权威(SuperBridge SMO 0x11a8140,idx6;moc_names.json:'King::SessionState','state','QVariant&','result')
	// emit 桩 FUN_00911ef2(0030.c:1452):activate(idx6,{int,QVariant-arg});
	// 状态门 FUN_007c85dc(0024.c:34783):`(s==+0x2c)&&(1<s-8U)` 去重
	// → emit stateChanged(state, extra)—— 单 state 参 + QVariant extra,
	// 非 oldState 对(批 83 C4 勘正)。
	void stateChanged(King::SessionState state, const QVariant &extra);
	// moc 参数名 'code','info';emit 桩 FUN_00911eb6(0030.c:1433,idx4)
	// emit 点 FUN_00875f1f(0027.c:18625):code 前 errStr 后。
	void errorOccurred(int code, const QString &errStr);
	void commandOutput(const QString &context, const QString &input, const QString &output);

private:
	Q_DISABLE_COPY(SuperBridge)
};

#endif // SUPERBRIDGE_H
