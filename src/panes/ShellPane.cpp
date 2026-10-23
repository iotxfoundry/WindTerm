#include "ShellPane.h"

#include <QLineEdit>
#include <QPlainTextEdit>
#include <QVBoxLayout>

#include "core/LocaleManager.h"

ShellPane::ShellPane(QWidget *parent)
    : QWidget(parent)
    , m_commandEdit(new QLineEdit(this))
    , m_outputEdit(new QPlainTextEdit(this))
{
    // KitPane 三连 0x008c3bbe：objectName → setWindowIcon（挂账）→ setWindowTitle(King_title 0x008a1106)
    setObjectName(QStringLiteral("ShellPane"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Shell")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    m_outputEdit->setReadOnly(true);
    m_outputEdit->setPlainText(QStringLiteral("[shell output placeholder]"));

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_commandEdit);
    layout->addWidget(m_outputEdit);
}
