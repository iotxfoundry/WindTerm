#include "TransferCenter.h"

#include <QBrush>
#include <QFont>
#include <QPointer>

#include "SftpTransfer.h"

namespace {
// role 0x100（0x617aea：(**vtable)(QVariant,item,0x100) 读属性 map;对应 Qt::UserRole+0）
constexpr int kPropertiesRole = 0x100;
// 0x617aea 固定键序（ppcVar4 步进 2 的 {值键,标题键} 表）
const char *kHtmlKeys[] = {
    "transfer.session",          "Session",
    "transfer.targetDirectory",  "Target directory",
    "transfer.currentItemName",  "Current Item",
    "transfer.processedCount",   "Items",
    "transfer.failedCount",      "Failed items",
    "transfer.processedSize",    "Processed size",
    "transfer.leftTime",         "Time left",
    "transfer.elapsedTime",      "Time elapsed",
    "transfer.averageSpeed",     "Average speed",
};
constexpr int kHtmlKeyCount = sizeof(kHtmlKeys) / sizeof(kHtmlKeys[0]) / 2;

inline QString htmlEscaped(const QString &s)
{
    return s.toHtmlEscaped();
}
} // namespace

TransferCenter::TransferCenter(QObject *parent)
    : QObject(parent)
    // ctor 0x618a0a：operator_new QStandardItemModel + setColumnCount(2) + FUN_006162a6
    // （singleShot(0) 挂信号——骨架构造期直连等效）
    , m_model(new QStandardItemModel(0, 2, this))
{
    m_model->setColumnCount(2); // 0x618a0a setColumnCount 实参 2
}

TransferCenter *TransferCenter::instance()
{
    // FUN_00618a9c：guard 静态单例（DAT_011c16a0）
    static TransferCenter center;
    return &center;
}

QStandardItem *TransferCenter::rowFor(const QString &path) const
{
    return m_rows.value(path);
}

QVariantMap TransferCenter::taskProperties(const QString &path) const
{
    if (const QStandardItem *row = rowFor(path))
        return row->data(kPropertiesRole).toMap();
    return {};
}

void TransferCenter::setTaskProperty(const QString &path, const QString &key,
                                     const QVariant &value)
{
    QStandardItem *row = rowFor(path);
    if (!row)
        return;
    QVariantMap map = row->data(kPropertiesRole).toMap();
    map.insert(key, value);
    row->setData(map, kPropertiesRole); // role 0x100 存属性 map（0x617aea 读侧）
}

void TransferCenter::ensureTaskRow(const QString &path)
{
    if (rowFor(path))
        return;
    auto *name = new QStandardItem(path); // col 0=任务路径（0x617aea DisplayRole 列 0 原样）
    auto *detail = new QStandardItem;
    detail->setEditable(false);
    name->setEditable(false);
    name->setData(QVariantMap {}, kPropertiesRole);
    m_model->appendRow({ name, detail });
    m_rows.insert(path, name);
    emitTaskEvent(path, LabelCreate); // kind 0=建标签（TransferBar 懒建行触发）
}

void TransferCenter::removeTaskRow(const QString &path)
{
    QStandardItem *row = rowFor(path);
    if (!row)
        return;
    const int r = row->row();
    m_model->removeRow(r);
    m_rows.remove(path);
    emitTaskEvent(path, LabelRemove); // kind 2=删标签
}

void TransferCenter::pauseTask(const QString &path)
{
    // 0x61b176：s_transfer_pointer 非空→recent_map_update(mode 2)+forwardSetMode(0xb,path)
    if (QStandardItem *row = rowFor(path)) {
        Q_UNUSED(row);
        emit transferSignal(path, true);
    }
}

void TransferCenter::resumeTask(const QString &path)
{
    // 0x61b2a8：forwardSetMode(0xf,path)
    if (QStandardItem *row = rowFor(path)) {
        Q_UNUSED(row);
        emit transferSignal(path, false);
    }
}

void TransferCenter::removeTask(const QString &path)
{
    // 0x61b206：forwardSetMode(0,path)+recent_map_update(mode 5)——骨架=移除行（kind 2 链）
    removeTaskRow(path);
    // 行移除后回收该行键的任务对象：remove() 置位→run 块边界退出→终态 Removing→finished
    // （QPointer 守护：对象若已被 parent 链析构则跳过——teardown 竞态面闭合）
    const auto transfers = findChildren<SftpTransfer *>();
    for (SftpTransfer *t : transfers)
        if (t->path() == path)
            t->remove();
}

// 竞态测试挂钩：teardown 序（removeTask 先于线程收口）的可观测出口
void TransferCenter::teardownTask(const QString &path)
{
    removeTask(path); // remove 置位 → run 退出
    for (QObject *child : findChildren<SftpTransfer *>()) {
        if (qobject_cast<SftpTransfer *>(child)->path() == path)
            child->deleteLater(); // 析构→~SftpTransfer 确定收口线程
    }
}

QString TransferCenter::activeTaskPaths() const
{
    QStringList paths;
    const auto transfers = findChildren<SftpTransfer *>();
    for (const SftpTransfer *t : transfers)
        if (!t->isFinished())
            paths << t->path();
    return paths.join(QLatin1Char('\n'));
}

void TransferCenter::emitTaskEvent(const QString &path, int kind)
{
    emit taskEvent(path, kind);
    if (kind == Refresh) {
        // 进度同步（`(path,int)` 形态信号；值=transfer.weightPercent）
        const QVariantMap map = taskProperties(path);
        emit progressSignal(path, map.value(QStringLiteral("transfer.weightPercent")).toInt());
    }
}

// 0x617aea s_transfer_targetDirectory 原样复刻：固定键序逐行拼
// `<tr><td align=right>%1: </td><td>%2</td>`；空值行跳过（iVar1!=0 门）；
// transfer.processedCount 行="%1 of %2"（transfer.count 合成,0xc90301 tr）；
// transfer.failedCount 行 toInt>0 才出且值=红字包裹（0xc9030a `<font color="red">`+
// 0xc9d328 `</font>`）；表尾 `</table>`（0xc8a438 段落）
QString TransferCenter::propertiesToHtml(const QVariantMap &properties)
{
    QString html;
    for (int i = 0; i < kHtmlKeyCount; ++i) {
        const QString key = QString::fromLatin1(kHtmlKeys[i * 2]);
        if (!properties.contains(key))
            continue;
        QString title = QString::fromLatin1(kHtmlKeys[i * 2 + 1]);
        QString value = properties.value(key).toString();
        if (key == QLatin1String("transfer.processedCount")) {
            // 双键合成："Items" "%1 of %2"（transfer.count 第二键）
            const QString total = properties.value(QStringLiteral("transfer.count")).toString();
            if (!total.isEmpty())
                value = QStringLiteral("%1 of %2").arg(value, total);
        }
        if (value.isEmpty())
            continue; // 0x617ea：iVar1!=0 才 append 行
        if (key == QLatin1String("transfer.failedCount") && value.toInt() > 0)
            value = QStringLiteral("<font color=\"red\">%1</font>").arg(htmlEscaped(value));
        else
            value = htmlEscaped(value);
        html += QStringLiteral("<tr><td align=right>%1: </td><td>%2</td>").arg(title, value);
    }
    return html;
}
