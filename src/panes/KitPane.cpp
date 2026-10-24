#include "KitPane.h"

#include <QHash>

#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "widgets/ActionIcons.h"

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
    // paneIconFactory（0x0089e584）：objectName endsWith("Pane")（大小写不敏感，原 endsWith
    // 第 3 参=1）不匹配→空 icon；匹配→"king::"+首字母小写（ExplorerPane→king::explorerPane，
    // king.svg 实存 explorerPane/filerPane/outlinePane/outputPane/senderPane/sessionPane/
    // shellPane/transferPane）；icon 缺失无回退（0x5acaba 同款）
    if (name.endsWith(QLatin1String("Pane"), Qt::CaseInsensitive)) {
        QString iconName = name;
        iconName[0] = iconName.at(0).toLower();
        setWindowIcon(ActionIcons::iconFor(name, QStringLiteral("king::") + iconName,
                                           ThemeManager::instance().currentTheme()));
    }
    const QString title = paneTitle(name);
    if (!title.isEmpty())
        setWindowTitle(LocaleManager::instance().tr(title));
}

void KitPane::contextMenuEvent(QContextMenuEvent *e)
{
    emit popupRequested(e->modifiers());
    e->accept();
}
