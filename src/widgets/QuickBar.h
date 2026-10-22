#pragma once

#include <QWidget>

// 原版 QuickBar（ctor 0x0056e26e）：普通 QWidget 子类（非 QToolBar），objectName "QuickBar"，
// windowTitle 由 King::registerBarsAndPanes(0x008a1106) 注册名 "&Quick Bar" 提供。
// 内容=空态骨架：命令按钮构建来自 0x0056e420（会话命令历史，F4 会话功能后接入），
// 届时按 quickbar.showCommandsInOrder / showGroupTitle / showMultipleGroups 经 WindConfig 现有访问器过滤。
class QuickBar : public QWidget
{
    Q_OBJECT

public:
    explicit QuickBar(QWidget *parent = nullptr);
};
