#include "SessionSettingsDialog.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

SessionSettingsDialog::SessionSettingsDialog(QWidget *parent)
    : QDialog(parent)
    , m_nameEdit(new QLineEdit(this))
{
    setWindowTitle(tr("Session Settings"));

    auto *label = new QLabel(tr("Session name:"), this);
    auto *okButton = new QPushButton(tr("OK"), this);
    auto *cancelButton = new QPushButton(tr("Cancel"), this);

    connect(okButton, &QPushButton::clicked, this, &SessionSettingsDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &SessionSettingsDialog::reject);

    auto *buttons = new QHBoxLayout;
    buttons->addStretch();
    buttons->addWidget(okButton);
    buttons->addWidget(cancelButton);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(m_nameEdit);
    layout->addLayout(buttons);
}

void SessionSettingsDialog::accept()
{
    done(Accepted);
}
