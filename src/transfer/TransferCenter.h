#pragma once

#include <QAbstractItemModel>
#include <QHash>
#include <QObject>
#include <QStandardItemModel>
#include <QString>
#include <QVariantMap>

// 原版 TransferCenter（ctor 0x618a0a/单例 FUN_00618a9c 静态 DAT_011c16a0）：QObject +
// QStandardItemModel（setColumnCount(2)）+ 按路径任务 map（+0x30 QMap path→行）。
// 3 信号：`(path,bool)`（0x61b176 暂停族实参形态）/`taskEvent(path,int kind)`
// （0=建标签/1,3=状态/2=删/4=刷新——0x61b206 recent_map_update(mode 5/0/4)、
// FUN_008f17c0 族消费）/`(path,int)`。行属性存 role 0x100（QVariantMap）。
// **data() 仅重写**（0x617aea s_transfer_targetDirectory）：role==DisplayRole 且列 1 时
// 由属性 map 生成 HTML 表——行格式 `<tr><td align=right>%1: </td><td>%2</td>`（0xcba2c0），
// 键序固定：Session/Target directory/Current Item/Items "%1 of %2"（transfer.processedCount
// +transfer.count 双键合成）/Failed items（transfer.failedCount>0 才出,值红字
// `<font color="red">`（0xc9030a）包裹）/Processed size/Time left/Time elapsed/Average
// speed；表尾 `</table>`（0xc8a438 段）。0=列 0 原样转发 QStandardItemModel。
class TransferCenter : public QObject
{
    Q_OBJECT

public:
    // taskEvent kind（FUN_0061b176/0061b206/0061b2a8 recent_map_update mode 编码）
    enum TaskEventKind { LabelCreate = 0, StateChangedKind = 1, LabelRemove = 2, Refresh = 4 };
    Q_ENUM(TaskEventKind)

    // 单例（FUN_00618a9c：guard 静态 DAT_011c16a0）
    static TransferCenter *instance();

    // 行访问：模型 2 列（col0=名称/col1=详情 HTML）；行按路径幂等
    QStandardItemModel *model() const { return m_model; }
    QVariantMap taskProperties(const QString &path) const;
    void setTaskProperty(const QString &path, const QString &key, const QVariant &value);

    // 任务生命周期：ensureRow（kind 0 建行+taskEvent(LabelCreate)）/removeRow（kind 2）
    void ensureTaskRow(const QString &path);
    void removeTaskRow(const QString &path);

    // 0x61b176/0x61b206/0x61b2a8 语义收口：暂停（mode 0xb）/移除（mode 0/5 双参）/恢复
    // （mode 0xf）。骨架按 SftpTransfer 槽直调（原版经 forwardSetMode 分派）,事件序列
    // 保持 taskEvent 同步发出
    void pauseTask(const QString &path);
    void resumeTask(const QString &path);
    void removeTask(const QString &path);

    // 0x617aea 原样复刻：属性 map → tooltip HTML 表（键序/键名/条件行全照搬）
    static QString propertiesToHtml(const QVariantMap &properties);

signals:
    void transferSignal(const QString &path, bool flag); // `(path,bool)` 形态
    void taskEvent(const QString &path, int kind);       // 0=建标签/1,3=状态/2=删/4=刷新
    void progressSignal(const QString &path, int percent); // `(path,int)` 形态

private:
    explicit TransferCenter(QObject *parent = nullptr);
    QStandardItem *rowFor(const QString &path) const;
    void emitTaskEvent(const QString &path, int kind);

    QStandardItemModel *m_model;
    // 按路径任务 map（ctor +0x30 QMap path→QStandardItem*；骨架 QHash 等效）
    QHash<QString, QStandardItem *> m_rows;
};
