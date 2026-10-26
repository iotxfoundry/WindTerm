#include "OutputPane.h"

#include "core/LocaleManager.h"

OutputPane::OutputPane(QWidget *parent)
    : QPlainTextEdit(parent)
{
    // KitPane 三连 0x008c3bbe：objectName → setWindowIcon（挂账）→ setWindowTitle(King_title 0x008a1106)
    setObjectName(QStringLiteral("OutputPane"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Output")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    setReadOnly(true);
    setPlainText(QStringLiteral("[output placeholder]\n[output placeholder]\n[output placeholder]"));
}
