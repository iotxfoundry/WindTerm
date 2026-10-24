// F4 SessionSettingsDialog::entryValue 字段拼装单测（QApplication offscreen）
#include <QApplication>
#include <QComboBox>
#include <QLineEdit>
#include <QStackedWidget>
#include <QVariantMap>
#include <cstdio>

#include "dialogs/SessionSettingsDialog.h"

static int failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok) ++failed;
}

static QLineEdit *editOf(const QWidget *page, const char *objectName)
{
    return page->findChild<QLineEdit *>(QString::fromLatin1(objectName));
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // 1. 新建：空 entry → uuid 带花括号
    {
        SessionSettingsDialog d;
        // 页 0=SSH：target/port
        auto *target = d.findChild<QLineEdit *>(QStringLiteral("ssh.target"));
        auto *port = d.findChild<QLineEdit *>(QStringLiteral("ssh.port"));
        auto *label = d.findChild<QLineEdit *>(QStringLiteral("dlg.label"));
        auto *group = d.findChild<QLineEdit *>(QStringLiteral("dlg.group"));
        check(target && port && label && group, "core edits exist");
        label->setText("new-host");
        group->setText("测试组");
        target->setText("10.0.0.1");
        port->setText("2222");
        const QVariantMap m = d.entryValue();
        check(m.value("session.label").toString() == "new-host", "new: label");
        check(m.value("session.protocol").toString() == "SSH", "new: protocol");
        check(m.value("session.target").toString() == "10.0.0.1", "new: target");
        check(m.value("session.port").toInt() == 2222, "new: port int");
        const QString uuid = m.value("session.uuid").toString();
        check(uuid.startsWith('{') && uuid.endsWith('}'), "new: uuid braced");
        check(!m.contains("session.user"), "new: no session.user key (真数据无此键)");
    }

    // 2. 新建 Shell 页字段
    {
        SessionSettingsDialog d;
        d.findChild<QComboBox *>(QStringLiteral("dlg.protocol"))->setCurrentIndex(1); // Shell
        d.findChild<QLineEdit *>(QStringLiteral("dlg.label"))->setText("sh");
        d.findChild<QLineEdit *>(QStringLiteral("shell.target"))->setText("/bin/bash");
        d.findChild<QLineEdit *>(QStringLiteral("shell.arguments"))->setText("-l -i");
        d.findChild<QLineEdit *>(QStringLiteral("shell.workingDirectory"))->setText("${HomeDir}");
        const QVariantMap m = d.entryValue();
        check(m.value("session.protocol").toString() == "Shell", "shell: protocol");
        check(m.value("session.target").toString() == "/bin/bash", "shell: target");
        check(m.value("process.arguments").toString() == "-l -i", "shell: arguments");
        check(m.value("process.workingDirectory").toString() == "${HomeDir}",
              "shell: workingDirectory");
    }

    // 3. 编辑：原条目未知名键保留 + 覆盖字段
    QVariantMap base;
    base.insert("session.uuid", "{11111111-2222-3333-4444-555555555555}");
    base.insert("session.protocol", "SSH");
    base.insert("session.label", "old");
    base.insert("session.target", "192.168.1.11");
    base.insert("session.port", 10022);
    base.insert("session.oneKey", "keep-me");
    base.insert("ssh.sysmon", true);
    {
        SessionSettingsDialog d(Q_NULLPTR, base);
        auto *target = d.findChild<QLineEdit *>(QStringLiteral("ssh.target"));
        check(target->text() == "192.168.1.11", "edit: target prefilled");
        target->setText("192.168.1.99");
        d.findChild<QLineEdit *>(QStringLiteral("dlg.label"))->setText("renamed");
        const QVariantMap m = d.entryValue();
        check(m.value("session.label").toString() == "renamed", "edit: label updated");
        check(m.value("session.target").toString() == "192.168.1.99", "edit: target updated");
        check(m.value("session.port").toInt() == 10022, "edit: port kept");
        check(m.value("session.oneKey").toString() == "keep-me", "edit: unknown key kept");
        check(m.value("ssh.sysmon").toBool() == true, "edit: ssh.sysmon kept");
        check(m.value("session.uuid").toString()
                  == "{11111111-2222-3333-4444-555555555555}",
              "edit: uuid unchanged");
    }

    // 4. 编辑 Serial：serial.* 字符串值 + 小写 "serial" protocol 归一
    {
        QVariantMap ser;
        ser.insert("session.uuid", "{aaaaaaaa-bbbb-cccc-dddd-eeeeeeeeeeee}");
        ser.insert("session.protocol", "serial");
        ser.insert("session.target", "/dev/ttyXRUSB0");
        ser.insert("serial.baudRate", "115200");
        ser.insert("serial.dataBits", 8);
        ser.insert("serial.parity", "Even");
        ser.insert("serial.stopBits", "1");
        ser.insert("serial.flowControl", "None");
        SessionSettingsDialog d(Q_NULLPTR, ser);
        d.findChild<QComboBox *>(QStringLiteral("serial.parity"))->setCurrentText("Odd");
        const QVariantMap m = d.entryValue();
        check(m.value("session.protocol").toString() == "Serial", "serial: protocol normalized");
        check(m.value("serial.baudRate").toString() == "115200", "serial: baudRate string");
        check(m.value("serial.dataBits").toString() == "8", "serial: dataBits string");
        check(m.value("serial.parity").toString() == "Odd", "serial: parity updated");
        check(m.value("serial.stopBits").toString() == "1", "serial: stopBits string");
    }

    std::printf("ENTRYVALUE-TEST %s (%d failures)\n", failed == 0 ? "PASSED" : "FAILED", failed);
    return failed == 0 ? 0 : 1;
}
