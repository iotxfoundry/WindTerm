#include "MasterPasswordDialog.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

MasterPasswordDialog::MasterPasswordDialog(QWidget *parent)
    : QDialog(parent)
    , m_passwordEdit(new QLineEdit(this))
{
    setWindowTitle(tr("Master Password"));
    m_passwordEdit->setEchoMode(QLineEdit::Password);

    auto *label = new QLabel(tr("Master password:"), this);
    auto *okButton = new QPushButton(tr("OK"), this);
    auto *cancelButton = new QPushButton(tr("Cancel"), this);

    connect(okButton, &QPushButton::clicked, this, &MasterPasswordDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &MasterPasswordDialog::reject);

    auto *buttons = new QHBoxLayout;
    buttons->addStretch();
    buttons->addWidget(okButton);
    buttons->addWidget(cancelButton);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(m_passwordEdit);
    layout->addLayout(buttons);
}

void MasterPasswordDialog::accept()
{
    done(Accepted);
}
