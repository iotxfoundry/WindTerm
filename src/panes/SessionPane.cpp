#include "SessionPane.h"

#include <QDir>
#include <QPainter>
#include <QPixmap>

#include "core/LocaleManager.h"
#include "core/SessionStore.h"
#include "widgets/ActionIcons.h"
#include "core/ThemeManager.h"

namespace {

// icon 值 "session::xxx" 经 ActionIcons 机制取 KingIcons（剥前缀，无则空图标）
QIcon sessionIcon(const QString &icon)
{
    QString name = icon;
    name.remove(QLatin1String("session::"));
    if (name.isEmpty())
        return QIcon();
    return ActionIcons::iconFor(QStringLiteral("session"), name,
                                ThemeManager::instance().currentTheme());
}

} // namespace

SessionPane::SessionPane(QWidget *parent)
    : QTreeWidget(parent)
{
    // KitPane 三连 0x008c3bbe：objectName → setWindowIcon（挂账）→ setWindowTitle(King_title 0x008a1106)
    setObjectName(QStringLiteral("SessionPane"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Session")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    setHeaderHidden(true);

    reload();

    connect(this, &QTreeWidget::itemDoubleClicked, this,
            [this](QTreeWidgetItem *item, int column) {
        Q_UNUSED(column);
        // 仅子项（协议非空）都发信号——MainWindow 按 SessionStore 条目 protocol 分派
        // （SSH→ConnectDialog，Telnet/Shell/Serial 直接建会话）
        if (item->parent())
            emit sessionActivated(item->data(1, Qt::UserRole).toString(),
                                  item->data(2, Qt::UserRole).toInt(),
                                  item->text(0));
    });
}

// 建树逻辑抽自 ctor（F4：reload 写盘后复用）
void SessionPane::reload()
{
    clear();
    // 按 session.group 分组：顶层=组名，子项=label + target:port
    const QVector<SessionEntry> entries = SessionStore::load();
    QHash<QString, QTreeWidgetItem *> groups;
    for (const SessionEntry &e : entries) {
        QTreeWidgetItem *group = groups.value(e.group);
        if (!group) {
            group = new QTreeWidgetItem(this, QStringList{e.group});
            groups.insert(e.group, group);
        }
        auto *item = new QTreeWidgetItem(
            group, QStringList{e.label, QStringLiteral("%1:%2").arg(e.target).arg(e.port)});
        item->setIcon(0, sessionIcon(e.icon));
        item->setData(0, Qt::UserRole, e.protocol);
        item->setData(1, Qt::UserRole, e.target);
        item->setData(2, Qt::UserRole, e.port);
        item->setData(3, Qt::UserRole, e.uuid); // SessionPane.Property 编辑定位用
    }
    expandAll();
}

QVariantMap SessionPane::selectedEntry() const
{
    QTreeWidgetItem *item = currentItem();
    if (!item || !item->parent())
        return {};
    const QString uuid = item->data(3, Qt::UserRole).toString();
    return uuid.isEmpty() ? QVariantMap() : SessionStore::sessionByUuid(uuid);
}
