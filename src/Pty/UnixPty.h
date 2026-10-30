 /*
 * Copyright 2020, WindTerm.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef UNIXPTY_H
#define UNIXPTY_H

#pragma once

#include <QtGlobal>

#ifdef Q_OS_UNIX

#include "Pty.h"
#include <QProcess>
#include <QSocketNotifier>

#include <termios.h>

#include "ShellProcess.h"

class UnixPty
	: public Pty
{
public:
	UnixPty(QObject *parent = nullptr);
    virtual ~UnixPty();

	bool createProcess(QString command, const QString &arguments,
					   const QString &workingDirectory, const QProcessEnvironment &environment,
					   int rows, int columns) final;
	static bool isAvailable();
	bool resizeWindow(int rows, int columns) final;
    QByteArray readAll() final;
	qint64 write(const QByteArray &text) final;
	// pty 操作面(访问级属重建自由度:原版 ptyqt 基类 stop() 即 public)
	void stop();
	qint64 pid() const { return m_pid; }

private:
	void moveToThread(QThread *targetThread);
	void setError(const char *error);
	bool setTerminalAttributes(struct ::termios *ttmode);
	bool terminalAttributes(struct ::termios *ttmode);

private:
	qint64 m_pid;
	ShellProcess m_shellProcess;
	QSocketNotifier *m_readMasterNotify;

	char *m_buffer;
	QByteArray m_shellReadBuffer;
};

#endif // Q_OS_UNIX
#endif // UNIXPTY_H
