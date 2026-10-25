#pragma once

#include <QAbstractItemModel>
#include "KitPane.h"

class QTreeView;
class TransferCenter;

// 原版 TransferPane（ctor 0x733a18 s_TransferPane）：KitPane 保留（objectName "TransferPane"）
// + QTreeView"TreeView"（Extended 选择/col 0 进度 delegate 简化为文本挂账/col 1 Stretch/
// headerHidden）挂 TransferCenter::model；空态命令条 "No transfer available"（locale 表）；
// 行右键弹菜单（暂停/恢复/移除——0x7346c4/0x734764/0x734804：选中行 path 循环逐个收口）。
class TransferPane : public KitPane
{
    Q_OBJECT

public:
    explicit TransferPane(QWidget *parent = nullptr);

    // MainWindow 接线点：挂 TransferCenter::model（createCentral 装配后调用）
    void hookModel(QAbstractItemModel *model);

private:
    // 0x734398：选中行 col 0 data→path 列表;0x7346c4 循环 0x61b176 族
    QStringList selectedPaths() const;

    QTreeView *m_view;
    TransferCenter *m_center = nullptr;
};
