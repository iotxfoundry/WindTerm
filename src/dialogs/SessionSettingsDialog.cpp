#include "SessionSettingsDialog.h"

#include <QComboBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QUuid>
#include <QVBoxLayout>

namespace {

// 页字段 → 写盘全键名映射（m_edits/m_combos 的键）
// SSH/Telnet 页 target/port → session.target/session.port；
// Shell 页 → session.target/process.*；Serial 页 → session.target/serial.*

QString valueOf(const QVariantMap &m, const QString &fullKey)
{
    return m.value(fullKey).toString();
}

} // namespace

SessionSettingsDialog::SessionSettingsDialog(QWidget *parent, const QVariantMap &entry)
    : QDialog(parent)
    , m_base(entry)
{
    const bool editing = !m_base.isEmpty();
    setWindowTitle(editing ? tr("Session Settings") : tr("New Session"));

    m_label = new QLineEdit(this);
    m_label->setObjectName(QStringLiteral("dlg.label"));
    m_group = new QLineEdit(this);
    m_group->setObjectName(QStringLiteral("dlg.group"));
    m_protocol = new QComboBox(this);
    m_protocol->setObjectName(QStringLiteral("dlg.protocol"));
    m_protocol->addItems({QStringLiteral("SSH"), QStringLiteral("Shell"),
                          QStringLiteral("Serial"), QStringLiteral("Telnet")});

    m_pages = new QStackedWidget(this);
    m_pages->addWidget(createSshPage());
    m_pages->addWidget(createShellPage());
    m_pages->addWidget(createSerialPage());
    m_pages->addWidget(createTelnetPage());
    connect(m_protocol, QOverload<int>::of(&QComboBox::currentIndexChanged),
            m_pages, &QStackedWidget::setCurrentIndex);

    // 编辑态页字段预填（编辑态 protocol 归一时 m_pages 已切对页）
    if (editing) {
        m_label->setText(valueOf(m_base, QStringLiteral("session.label")));
        m_group->setText(valueOf(m_base, QStringLiteral("session.group")));
        const QString proto = valueOf(m_base, QStringLiteral("session.protocol"));
        const int idx = m_protocol->findText(proto, Qt::MatchFixedString);
        if (idx >= 0) {
            m_protocol->setCurrentIndex(idx);
            m_pages->setCurrentIndex(idx);
        }
        const bool shell = proto.compare(QLatin1String("Shell"), Qt::CaseInsensitive) == 0;
        const bool serial = proto.compare(QLatin1String("Serial"), Qt::CaseInsensitive) == 0;
        const bool telnet = proto.compare(QLatin1String("Telnet"), Qt::CaseInsensitive) == 0;
        QLineEdit *edit = shell   ? m_edits.value(QStringLiteral("shell.target"))
                          : serial ? m_edits.value(QStringLiteral("serial.target"))
                          : telnet  ? m_edits.value(QStringLiteral("telnet.target"))
                                    : m_edits.value(QStringLiteral("target"));
        edit->setText(valueOf(m_base, QStringLiteral("session.target")));
        if (shell) {
            m_edits.value(QStringLiteral("shell.arguments"))
                ->setText(valueOf(m_base, QStringLiteral("process.arguments")));
            m_edits.value(QStringLiteral("shell.workingDirectory"))
                ->setText(valueOf(m_base, QStringLiteral("process.workingDirectory")));
        } else if (serial) {
            m_edits.value(QStringLiteral("serial.baudRate"))
                ->setText(valueOf(m_base, QStringLiteral("serial.baudRate")));
            for (auto it = m_combos.constBegin(); it != m_combos.constEnd(); ++it)
                it.value()->setCurrentText(valueOf(m_base, it.key()));
        } else if (telnet) {
            m_edits.value(QStringLiteral("telnet.port"))
                ->setText(QString::number(
                    m_base.value(QStringLiteral("session.port")).toInt()));
        } else { // SSH
            m_edits.value(QStringLiteral("port"))
                ->setText(QString::number(
                    m_base.value(QStringLiteral("session.port")).toInt()));
        }
    }

    auto *buttons = new QHBoxLayout;
    auto *okButton = new QPushButton(tr("OK"), this);
    auto *cancelButton = new QPushButton(tr("Cancel"), this);
    connect(okButton, &QPushButton::clicked, this, &SessionSettingsDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &SessionSettingsDialog::reject);
    buttons->addStretch();
    buttons->addWidget(okButton);
    buttons->addWidget(cancelButton);

    auto *form = new QFormLayout;
    form->addRow(tr("Label:"), m_label);
    form->addRow(tr("Group:"), m_group);
    form->addRow(tr("Protocol:"), m_protocol);

    auto *layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(m_pages);
    layout->addLayout(buttons);
}

QWidget *SessionSettingsDialog::createSshPage()
{
    auto *page = new QWidget(this);
    auto *form = new QFormLayout(page);
    // user 键真数据无（扁平键无 session.user）——编辑面不提供（挂账：user 来源未逆）
    QLineEdit *target = new QLineEdit(page);
    target->setObjectName(QStringLiteral("ssh.target"));
    m_edits.insert(QStringLiteral("target"), target);
    QLineEdit *port = new QLineEdit(page);
    port->setObjectName(QStringLiteral("ssh.port"));
    m_edits.insert(QStringLiteral("port"), port);
    form->addRow(tr("Target:"), m_edits.value(QStringLiteral("target")));
    form->addRow(tr("Port:"), m_edits.value(QStringLiteral("port")));
    return page;
}

QWidget *SessionSettingsDialog::createShellPage()
{
    auto *page = new QWidget(this);
    auto *form = new QFormLayout(page);
    QLineEdit *program = new QLineEdit(page);
    program->setObjectName(QStringLiteral("shell.target"));
    m_edits.insert(QStringLiteral("shell.target"), program);
    QLineEdit *arguments = new QLineEdit(page);
    arguments->setObjectName(QStringLiteral("shell.arguments"));
    m_edits.insert(QStringLiteral("shell.arguments"), arguments);
    QLineEdit *workDir = new QLineEdit(page);
    workDir->setObjectName(QStringLiteral("shell.workingDirectory"));
    m_edits.insert(QStringLiteral("shell.workingDirectory"), workDir);
    form->addRow(tr("Program:"), m_edits.value(QStringLiteral("shell.target")));
    form->addRow(tr("Arguments:"), m_edits.value(QStringLiteral("shell.arguments")));
    form->addRow(tr("Working dir:"), m_edits.value(QStringLiteral("shell.workingDirectory")));
    return page;
}

QWidget *SessionSettingsDialog::createSerialPage()
{
    auto *page = new QWidget(this);
    auto *form = new QFormLayout(page);
    QLineEdit *target = new QLineEdit(page);
    target->setObjectName(QStringLiteral("serial.target"));
    m_edits.insert(QStringLiteral("serial.target"), target);
    QLineEdit *baud = new QLineEdit(page);
    baud->setObjectName(QStringLiteral("serial.baudRate"));
    m_edits.insert(QStringLiteral("serial.baudRate"), baud);
    auto *dataBits = new QComboBox(page);
    dataBits->setObjectName(QStringLiteral("serial.dataBits"));
    dataBits->addItems({QStringLiteral("8"), QStringLiteral("7"), QStringLiteral("6"),
                        QStringLiteral("5")});
    m_combos.insert(QStringLiteral("serial.dataBits"), dataBits);
    auto *parity = new QComboBox(page);
    parity->setObjectName(QStringLiteral("serial.parity"));
    parity->addItems({QStringLiteral("None"), QStringLiteral("Even"), QStringLiteral("Odd")});
    m_combos.insert(QStringLiteral("serial.parity"), parity);
    auto *stopBits = new QComboBox(page);
    stopBits->setObjectName(QStringLiteral("serial.stopBits"));
    stopBits->addItems({QStringLiteral("1"), QStringLiteral("2")});
    m_combos.insert(QStringLiteral("serial.stopBits"), stopBits);
    auto *flow = new QComboBox(page);
    flow->setObjectName(QStringLiteral("serial.flowControl"));
    flow->addItems({QStringLiteral("None"), QStringLiteral("XON/XOFF"),
                    QStringLiteral("CTS/RTS")});
    m_combos.insert(QStringLiteral("serial.flowControl"), flow);
    form->addRow(tr("Port:"), m_edits.value(QStringLiteral("serial.target")));
    form->addRow(tr("Baud rate:"), m_edits.value(QStringLiteral("serial.baudRate")));
    form->addRow(tr("Data bits:"), dataBits);
    form->addRow(tr("Parity:"), parity);
    form->addRow(tr("Stop bits:"), stopBits);
    form->addRow(tr("Flow control:"), flow);
    return page;
}

QWidget *SessionSettingsDialog::createTelnetPage()
{
    auto *page = new QWidget(this);
    auto *form = new QFormLayout(page);
    QLineEdit *target = new QLineEdit(page);
    target->setObjectName(QStringLiteral("telnet.target"));
    m_edits.insert(QStringLiteral("telnet.target"), target);
    QLineEdit *port = new QLineEdit(page);
    port->setObjectName(QStringLiteral("telnet.port"));
    m_edits.insert(QStringLiteral("telnet.port"), port);
    form->addRow(tr("Target:"), m_edits.value(QStringLiteral("telnet.target")));
    form->addRow(tr("Port:"), m_edits.value(QStringLiteral("telnet.port")));
    return page;
}

QVariantMap SessionSettingsDialog::entryValue() const
{
    // 编辑态：原条目未知名键（session.oneKey/ssh.*/serial.* 未编辑项…）全保留
    QVariantMap m = m_base;
    const bool shell = m_protocol->currentText() == QLatin1String("Shell");
    const bool serial = m_protocol->currentText() == QLatin1String("Serial");
    const bool telnet = m_protocol->currentText() == QLatin1String("Telnet");

    m.insert(QStringLiteral("session.label"), m_label->text().trimmed());
    m.insert(QStringLiteral("session.group"), m_group->text().trimmed());
    m.insert(QStringLiteral("session.protocol"), m_protocol->currentText());
    // 真数据 protocol 有 "serial" 小写变体；Serial 落 "Serial" 归一

    const QString targetKey = shell   ? QStringLiteral("shell.target")
                              : serial ? QStringLiteral("serial.target")
                              : telnet  ? QStringLiteral("telnet.target")
                                        : QStringLiteral("target");
    const QString target = m_edits.value(targetKey)->text().trimmed();
    m.insert(QStringLiteral("session.target"), target);

    if (shell) {
        m.insert(QStringLiteral("process.arguments"),
                 m_edits.value(QStringLiteral("shell.arguments"))->text());
        m.insert(QStringLiteral("process.workingDirectory"),
                 m_edits.value(QStringLiteral("shell.workingDirectory"))->text());
    } else if (serial) {
        // 真数据 serial.* 值为字符串（"8"/"1"/"None"）——照抄字符串
        m.insert(QStringLiteral("serial.baudRate"),
                 m_edits.value(QStringLiteral("serial.baudRate"))->text().trimmed());
        for (auto it = m_combos.constBegin(); it != m_combos.constEnd(); ++it)
            m.insert(it.key(), it.value()->currentText());
    } else {
        const QString portKey = telnet ? QStringLiteral("telnet.port")
                                       : QStringLiteral("port");
        bool ok = false;
        const int port = m_edits.value(portKey)->text().trimmed().toInt(&ok);
        m.insert(QStringLiteral("session.port"), ok ? port : 0);
    }

    // 新建：uuid 带花括号（QUuid::createUuid，对齐原版 0x6d37b0）
    if (!m.contains(QStringLiteral("session.uuid")) || m_base.isEmpty())
        m.insert(QStringLiteral("session.uuid"),
                 QUuid::createUuid().toString());
    // 新建图标缺省：SessionPane 空图标可渲染（挂账：图标字段不做）
    return m;
}

void SessionSettingsDialog::accept()
{
    if (m_label->text().trimmed().isEmpty()) {
        m_label->setFocus();
        return;
    }
    const bool shell = m_protocol->currentText() == QLatin1String("Shell");
    const bool serial = m_protocol->currentText() == QLatin1String("Serial");
    const bool telnet = m_protocol->currentText() == QLatin1String("Telnet");
    const QString targetKey = shell   ? QStringLiteral("shell.target")
                              : serial ? QStringLiteral("serial.target")
                              : telnet  ? QStringLiteral("telnet.target")
                                        : QStringLiteral("target");
    if (m_edits.value(targetKey)->text().trimmed().isEmpty()) {
        m_edits.value(targetKey)->setFocus();
        return;
    }
    done(Accepted);
}
