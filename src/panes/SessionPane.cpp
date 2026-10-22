#include "SessionPane.h"

#include <QIcon>
#include <QPainter>
#include <QPixmap>

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

QTreeWidgetItem *addSession(QTreeWidgetItem *parent, const QString &name, const QColor &color)
{
    auto *item = new QTreeWidgetItem(parent, QStringList{name});
    item->setIcon(0, dotIcon(color));
    return item;
}

} // namespace

SessionPane::SessionPane(QWidget *parent)
    : QTreeWidget(parent)
{
    setHeaderHidden(true);

    auto *putty = new QTreeWidgetItem(this, QStringList{tr("Putty sessions")});
    addSession(putty, tr("Local SSH"), Qt::green);
    addSession(putty, tr("Local Telnet"), Qt::yellow);

    auto *shell = new QTreeWidgetItem(this, QStringList{tr("Shell sessions")});
    addSession(shell, tr("Ubuntu"), Qt::blue);
    addSession(shell, tr("bash"), Qt::cyan);
    addSession(shell, tr("zsh"), Qt::magenta);

    expandAll();
}
