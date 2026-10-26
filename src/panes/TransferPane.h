#pragma once

#include <QAbstractItemModel>
#include "KitPane.h"

class QProgressBar;
class QTreeView;
class TransferCenter;

// 原版 TransferPane（ctor 0x733a18/TreeView 0x733ca6/setupUi 0x735a0c）：KitPane 保留
//（objectName "TransferPane"）+ QTreeView"TreeView"（NoEdit/SelectRows/Extended/
// UniformRowHeights/headerHidden/列 0 pause delegate 0x57181a 挂账）挂 TransferCenter::
// model；隐藏 QProgressBar（R48：progress 借位记值,非单元格/非 delegate 自绘）；行
// tooltip=0x617aea HTML 表；空态命令条 "No transfer available"（locale 表）；行右键弹
// 菜单（暂停/恢复/移除——0x7346c4/0x734764/0x734804：选中行 path 循环逐个收口）。
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
    void refreshRowToolips();

    QTreeView *m_view;
    QProgressBar *m_progress = nullptr; // R48：隐藏进度条（0x735a0c +0xa0 借位记值）
    TransferCenter *m_center = nullptr;
};
