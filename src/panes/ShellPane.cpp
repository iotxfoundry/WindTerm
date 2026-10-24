#include "ShellPane.h"

#include <QLineEdit>
#include <QPlainTextEdit>
#include <QVBoxLayout>

ShellPane::ShellPane(QWidget *parent)
    : KitPane(parent, QStringLiteral("ShellPane"))
    , m_commandEdit(new QLineEdit(this))
    , m_outputEdit(new QPlainTextEdit(this))
{
    m_outputEdit->setReadOnly(true);
    m_outputEdit->setPlainText(QStringLiteral("[shell output placeholder]"));

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_commandEdit);
    layout->addWidget(m_outputEdit);
}
