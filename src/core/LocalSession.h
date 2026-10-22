#pragma once

#include <QByteArray>
#include <QObject>
#include <QString>

class UnixPty;

class LocalSession : public QObject
{
    Q_OBJECT

public:
    explicit LocalSession(int rows, int columns, QObject *parent = nullptr);
    ~LocalSession() override;

    bool start(const QString &program = QStringLiteral("/bin/bash"));
    void write(const QByteArray &data);
    void resize(int rows, int columns);

signals:
    void output(const QByteArray &data);
    void finished();

private:
    UnixPty *m_pty;
    int m_rows;
    int m_columns;
};
