#pragma once

#include <QList>
#include <QWidget>

class QHBoxLayout;
class QMenu;

// 原版 QuickBar（ctor 0x0056e26e）：普通 QWidget 子类（非 QToolBar），objectName "QuickBar"，
// windowTitle 由 King::registerBarsAndPanes(0x008a1106) 注册名 "&Quick Bar" 提供。
// 内容包括 QuickButton（下拉）、各分组 ActionButton、ConfigButton、CloseButton（0x0056d0ac 右对齐）；
// 命令来自 ~/.wind/profiles/<profile>/terminal/quickbar.config（0x008065a2 懒加载），
// 按 quickbar.showCommandsInOrder / showGroupTitle / showMultipleGroups 渲染（0x0056e420/0x0056e540）。
class QuickBar : public QWidget
{
    Q_OBJECT

public:
    explicit QuickBar(QWidget *parent = nullptr);

    // 0x0056e420 buildCommands + 0x0056e540 groupButtons：按 WindConfig 当前命令表重建命令区
    void rebuild();

signals:
    // 0x0056ce72：CloseButton 点击→close；宿主未接线前本类先 hide 自身
    void closeRequested();
    // 0x0056d890：命令点击。终端接入时 MainWindow 连接此信号按 uuid 分派执行 quick.text。
    void commandTriggered(const QString &uuid);

private:
    QHBoxLayout *m_buttons = nullptr;
    QMenu *m_quickMenu = nullptr;
    QList<QWidget *> m_commandWidgets;
};
