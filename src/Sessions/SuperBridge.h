#ifndef SUPERBRIDGE_H
#define SUPERBRIDGE_H

#pragma once

#include <QObject>
#include "KingEnums.h"

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
	void stateChanged(King::SessionState oldState, King::SessionState state);
	void errorOccurred(const QString &context, int code);
	void commandOutput(const QString &context, const QString &input, const QString &output);

private:
	Q_DISABLE_COPY(SuperBridge)
};

#endif // SUPERBRIDGE_H
