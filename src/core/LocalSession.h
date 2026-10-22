#pragma once

#include <QByteArray>
#include <QString>

#include "Session.h"

class UnixPty;

class LocalSession : public Session
{
    Q_OBJECT

public:
    explicit LocalSession(int rows, int columns, QObject *parent = nullptr);
    ~LocalSession() override;

    bool start(const QString &program = QStringLiteral("/bin/bash"));
    void write(const QByteArray &data) override;
    void resize(int rows, int columns) override;

private:
    UnixPty *m_pty;
    int m_rows;
    int m_columns;
};
