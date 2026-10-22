#include "SenderPane.h"

#include <QLabel>
#include <QVBoxLayout>

SenderPane::SenderPane(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    auto *label = new QLabel(tr("Sender pane placeholder"), this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
    layout->addStretch();
}
