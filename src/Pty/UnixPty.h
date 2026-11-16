// [B-OPENSOURCE] 第一方开源件 —— **勿逆向**。
// 这是 WindTerm 作者以 Apache-2.0 开源的一手组件(基于上游 ptyqt / 自研),不是反编译对象;
// 移植或修改须按 docs/calibration.md 逐句同构记录。分类依据见 src/README.md §1b。

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

private:
	void moveToThread(QThread *targetThread);
	void setError(const char *error);
	bool setTerminalAttributes(struct ::termios *ttmode);
	void stop();
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
