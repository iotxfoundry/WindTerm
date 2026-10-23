#pragma once

#include <QWidget>

// 原版 QuickBar（ctor 0x0056e26e）：普通 QWidget 子类（非 QToolBar），objectName "QuickBar"，
// windowTitle 由 King::registerBarsAndPanes(0x008a1106) 注册名 "&Quick Bar" 提供。
// 内容包括 QuickButton（下拉）、各分组 ActionButton、ConfigButton、CloseButton（0x0056d0ac 右对齐）；
// 命令来自会话命令历史（0x0056e420），届时按 quickbar.showCommandsInOrder / showGroupTitle /
// showMultipleGroups 经 WindConfig 现有访问器过滤。
class QuickBar : public QWidget
{
    Q_OBJECT

public:
    explicit QuickBar(QWidget *parent = nullptr);

signals:
    // 0x0056ce72：CloseButton 点击→close；宿主未接线前本类先 hide 自身
    void closeRequested();
};
