#include "SerialSession.h"

#include <QDebug>

SerialSession::SerialSession(const QString &portPath, int baudRate, int dataBits,
                             const QString &parity, int stopBits, const QString &flowControl,
                             QObject *parent)
    : Session(parent)
    , m_port(new QSerialPort(this))
{
    m_port->setPortName(portPath);
    m_port->setBaudRate(baudRate);
    m_port->setDataBits(static_cast<QSerialPort::DataBits>(dataBits)); // 5-8 直接映射 Data5..Data8
    m_port->setParity(parity == QLatin1String("Even") ? QSerialPort::EvenParity
                      : parity == QLatin1String("Odd") ? QSerialPort::OddParity
                                                       : QSerialPort::NoParity);
    m_port->setStopBits(stopBits == 2 ? QSerialPort::TwoStop : QSerialPort::OneStop);
    m_port->setFlowControl(flowControl == QLatin1String("XON/XOFF") ? QSerialPort::SoftwareControl
                          : flowControl == QLatin1String("CTS/RTS") ? QSerialPort::HardwareControl
                                                                    : QSerialPort::NoFlowControl);

    // 打开失败（设备不存在/权限）即 finished + qWarning——offscreen 下预期路径
    if (!m_port->open(QIODevice::ReadWrite)) {
        qWarning() << "SerialSession:" << m_port->portName() << m_port->errorString();
        emit finished();
        return;
    }

    connect(m_port, &QSerialPort::readyRead, this, [this]() {
        const QByteArray data = m_port->readAll();
        if (!data.isEmpty())
            emit output(data);
    });
    // 设备不存在/权限不足等错误即会话终止（offscreen 下无真串口为预期路径）
    connect(m_port, &QSerialPort::errorOccurred, this, [this](QSerialPort::SerialPortError error) {
        if (error != QSerialPort::NoError) {
            qWarning() << "SerialSession:" << m_port->portName() << m_port->errorString();
            emit finished();
        }
    });
}

SerialSession::~SerialSession() = default;

void SerialSession::write(const QByteArray &data)
{
    m_port->write(data);
}

// 串口无终端尺寸协商（原版 serial 会话无 NAWS 概念）
void SerialSession::resize(int rows, int columns)
{
    Q_UNUSED(rows);
    Q_UNUSED(columns);
}

void SerialSession::close()
{
    if (m_port->isOpen())
        m_port->close();
    emit finished();
}
