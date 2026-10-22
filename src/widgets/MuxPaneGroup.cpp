#include "MuxPaneGroup.h"

#include <QIcon>
#include <QPainter>
#include <QPixmap>
#include <QPlainTextEdit>

namespace {

QIcon dotIcon(const QColor &color)
{
    QPixmap pixmap(10, 10);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawEllipse(0, 0, 9, 9);
    return QIcon(pixmap);
}

} // namespace

MuxPaneGroup::MuxPaneGroup(QWidget *parent)
    : QTabWidget(parent)
{
    addPane(tr("Local SSH"), Qt::red);
    addPane(tr("Local Telnet"), Qt::green);
    addPane(tr("Ubuntu"), Qt::blue);
}

void MuxPaneGroup::addPane(const QString &title, const QColor &color)
{
    auto *edit = new QPlainTextEdit(this);
    edit->setReadOnly(true);
    edit->setPlainText(title + QStringLiteral(" terminal placeholder"));
    addTab(edit, dotIcon(color), title);
}
