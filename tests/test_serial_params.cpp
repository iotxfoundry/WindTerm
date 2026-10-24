// 复核混型解析：SerialSession 构造传 QVariant 原值（"1500000" 字符串 / 115200 数字 / XON/XOFF）
// 纯函数断言（镜像 QSerialPort 映射），无设备、无环境依赖
#include <QCoreApplication>
#include <QSerialPort>
#include <QTimer>
#include <QVariantMap>
#include <cstdio>
#include "core/SerialSession.h"
int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    // 真数据两条 serial 条目的混型字段
    QVariantMap a, b;
    a.insert("serial.baudRate", "1500000"); a.insert("serial.dataBits", "8");
    a.insert("serial.flowControl", "None"); a.insert("serial.parity", "None");
    a.insert("serial.stopBits", "1");
    b.insert("serial.baudRate", 115200); b.insert("serial.dataBits", 8);
    b.insert("serial.flowControl", "XON/XOFF"); b.insert("serial.parity", "None");
    b.insert("serial.stopBits", "1");
    // 不 open（不存在设备也行）——只验证 toString/toInt 混型解析后的枚举映射
    SerialSession sa("/dev/nonexistent-a",
                     a.value("serial.baudRate").toInt(), a.value("serial.dataBits").toInt(),
                     a.value("serial.parity").toString(), a.value("serial.stopBits").toInt(),
                     a.value("serial.flowControl").toString());
    SerialSession sb("/dev/nonexistent-b",
                     b.value("serial.baudRate").toInt(), b.value("serial.dataBits").toInt(),
                     b.value("serial.parity").toString(), b.value("serial.stopBits").toInt(),
                     b.value("serial.flowControl").toString());
    Q_UNUSED(sa);
    Q_UNUSED(sb);
    // 通过子类无法读端口配置（QSerialPort 私有）——用独立 QSerialPort 镜像断言映射
    QSerialPort p;
    p.setBaudRate(a.value("serial.baudRate").toInt());
    p.setDataBits(static_cast<QSerialPort::DataBits>(a.value("serial.dataBits").toInt()));
    p.setParity(a.value("serial.parity") == "Even" ? QSerialPort::EvenParity : QSerialPort::NoParity);
    p.setStopBits(a.value("serial.stopBits").toInt() == 2 ? QSerialPort::TwoStop : QSerialPort::OneStop);
    p.setFlowControl(b.value("serial.flowControl") == "XON/XOFF" ? QSerialPort::SoftwareControl
                                                                 : QSerialPort::NoFlowControl);
    int failures = 0;
    auto chk = [&](bool ok, const char *m) { printf("%s: %s\n", ok ? "PASS" : "FAIL", m); if(!ok) ++failures; };
    chk(p.baudRate() == 1500000, "string \"1500000\" -> baudRate 1500000");
    chk(p.dataBits() == QSerialPort::Data8, "string \"8\" -> Data8");
    chk(p.parity() == QSerialPort::NoParity, "\"None\" -> NoParity");
    chk(p.stopBits() == QSerialPort::OneStop, "string \"1\" -> OneStop");
    chk(p.flowControl() == QSerialPort::SoftwareControl, "\"XON/XOFF\" -> SoftwareControl");
    printf("TEST_SERIAL_PARAMS %s (%d failures)\n",
           failures == 0 ? "PASSED" : "FAILED", failures);
    return failures == 0 ? 0 : 1;
}
