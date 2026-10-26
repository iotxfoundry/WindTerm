#include "ConnectDialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QIntValidator>
#include <QLineEdit>
#include <QVBoxLayout>

ConnectDialog::ConnectDialog(QWidget *parent)
    : QDialog(parent)
    , m_host(new QLineEdit(this))
    , m_user(new QLineEdit(this))
    , m_port(new QLineEdit(QStringLiteral("22"), this))
    , m_password(new QLineEdit(this))
{
    setWindowTitle(tr("SSH 连接"));
    m_host->setPlaceholderText(QStringLiteral("host"));
    m_user->setPlaceholderText(QStringLiteral("user"));
    m_port->setValidator(new QIntValidator(1, 65535, m_port));
    m_password->setEchoMode(QLineEdit::Password);
    m_password->setPlaceholderText(QStringLiteral("password"));

    auto *form = new QFormLayout;
    form->addRow(QStringLiteral("Host"), m_host);
    form->addRow(QStringLiteral("User"), m_user);
    form->addRow(QStringLiteral("Port"), m_port);
    form->addRow(QStringLiteral("Password"), m_password);

    auto *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(buttons);

    m_host->setFocus();
}

QString ConnectDialog::host() const
{
    return m_host->text().trimmed();
}

QString ConnectDialog::user() const
{
    return m_user->text().trimmed();
}

QString ConnectDialog::password() const
{
    return m_password->text();
}

int ConnectDialog::port() const
{
    bool ok = false;
    const int value = m_port->text().toInt(&ok);
    return ok && value > 0 && value <= 65535 ? value : 22;
}

void ConnectDialog::setSpec(const QString &user, const QString &host, int port)
{
    m_user->setText(user);
    m_host->setText(host);
    m_port->setText(QString::number(port > 0 && port <= 65535 ? port : 22));
}

bool ConnectDialog::parseSpec(const QString &text, QString *user, QString *host, int *port)
{
    QString rest = text.trimmed();
    if (rest.compare(QStringLiteral("ssh"), Qt::CaseInsensitive) == 0)
        rest.clear();
    else if (rest.startsWith(QStringLiteral("ssh "), Qt::CaseInsensitive))
        rest = rest.mid(4).trimmed();

    QString userPart;
    QString hostPart = rest;
    const int at = rest.lastIndexOf(QLatin1Char('@'));
    if (at >= 0) {
        userPart = rest.left(at).trimmed();
        hostPart = rest.mid(at + 1).trimmed();
    }

    int portValue = 22;
    const int colon = hostPart.lastIndexOf(QLatin1Char(':'));
    // 只在形如 host:port（端口为纯数字）时拆分，避免误伤 IPv6 字面量
    if (colon > 0) {
        const QString candidate = hostPart.mid(colon + 1);
        bool ok = false;
        const int parsed = candidate.toInt(&ok);
        if (ok && parsed > 0 && parsed <= 65535) {
            portValue = parsed;
            hostPart = hostPart.left(colon).trimmed();
        }
    }

    if (user)
        *user = userPart;
    if (host)
        *host = hostPart;
    if (port)
        *port = portValue;
    return !hostPart.isEmpty();
}
