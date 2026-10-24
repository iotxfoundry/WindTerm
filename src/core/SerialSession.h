#pragma once

#include <QSerialPort>
#include <QString>

#include "Session.h"

// 串口会话：QSerialPort。五参数取自 user.sessions serial.* 键（值字符串/数字混型，
// 统一 QVariant::toString 解析后在此转枚举）。
// resize 空实现——串口无终端尺寸协商（原版 serial 会话无 NAWS 概念）。
class SerialSession : public Session
{
    Q_OBJECT

public:
    SerialSession(const QString &portPath, int baudRate, int dataBits,
                  const QString &parity, int stopBits, const QString &flowControl,
                  QObject *parent = nullptr);
    ~SerialSession() override;

    void write(const QByteArray &data) override;
    void resize(int rows, int columns) override;
    void close() override;

private:
    QSerialPort *m_port;
};
