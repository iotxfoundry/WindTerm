#include "KitPane.h"

#include <QHash>

#include "core/LocaleManager.h"

namespace {

// King_title 0x008a1106 表（16 对）中 pane 的 9 对：objectName → 标题（tr 键无 "Pane" 后缀）
QString paneTitle(const QString &objectName)
{
    static const QHash<QString, QString> titles = {
        {QStringLiteral("ExplorerPane"), QStringLiteral("Explorer")},
        {QStringLiteral("FilerPane"), QStringLiteral("Filer")},
        {QStringLiteral("OutlinePane"), QStringLiteral("Outline")},
        {QStringLiteral("OutputPane"), QStringLiteral("Output")},
        {QStringLiteral("SenderPane"), QStringLiteral("Sender")},
        {QStringLiteral("SessionPane"), QStringLiteral("Session")},
        {QStringLiteral("TransferPane"), QStringLiteral("Transfer")},
        {QStringLiteral("SearchPane"), QStringLiteral("Search")},
        {QStringLiteral("ShellPane"), QStringLiteral("Shell")},
    };
    return titles.value(objectName);
}

} // namespace

KitPane::KitPane(QWidget *parent, const QString &name)
    : QWidget(parent)
{
    setObjectName(name);
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    const QString title = paneTitle(name);
    if (!title.isEmpty())
        setWindowTitle(LocaleManager::instance().tr(title));
}

void KitPane::contextMenuEvent(QContextMenuEvent *e)
{
    emit popupRequested(e->modifiers());
    e->accept();
}
