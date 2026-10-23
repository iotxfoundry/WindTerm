#include "SenderPane.h"

#include <QLabel>
#include <QVBoxLayout>

#include "core/LocaleManager.h"

SenderPane::SenderPane(QWidget *parent)
    : QWidget(parent)
{
    // KitPane 三连 0x008c3bbe：objectName → setWindowIcon（挂账）→ setWindowTitle(King_title 0x008a1106)
    setObjectName(QStringLiteral("SenderPane"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Sender")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    auto *layout = new QVBoxLayout(this);
    auto *label = new QLabel(tr("Sender pane placeholder"), this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
    layout->addStretch();
}
