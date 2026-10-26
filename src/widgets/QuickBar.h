#pragma once

#include <QJsonObject>
#include <QList>
#include <QSet>
#include <QString>
#include <QStringList>
#include <QWidget>

class QHBoxLayout;
class QMenu;
class QAction;
class QToolBar;

// 原版 QuickBar（ctor 0x0056e26e）：普通 QWidget 子类（非 QToolBar），objectName "QuickBar"，
// windowTitle 由 King::registerBarsAndPanes(0x008a1106) 注册名 "&Quick Bar" 提供。
// 内容=[左弹性区, QuickButton(InstantPopup+king::monoLogo), 组工具条…, ConfigButton(king::config), CloseButton(king::close)]
// （0x0056d0ac 布局序：addStretch → addLayout[QuickButton+组条] → ConfigButton → CloseButton）。
// 命令来自 ~/.wind/profiles/<profile>/terminal/quickbar.config（0x008065a2 懒加载），
// 按 quickbar.showCommandsInOrder / showGroupTitle / showMultipleGroups 渲染
// （0x0056e420 sortCommands / 0x0056e540 buildGroupBar / 0x0056f866 refresh）。
class QuickBar : public QWidget
{
    Q_OBJECT

public:
    explicit QuickBar(QWidget *parent = nullptr);

    // 0x0056f866 QuickBar_refresh：菜单重建+工具条重建
    void rebuild();

signals:
    // 0x0056ce72：CloseButton 点击→QWidget::close；宿主未接线前本类先 hide 自身
    void closeRequested();
    // 0x0056d890：命令点击，unescape 后的待写入文本。原版直接写焦点终端
    // （0x8cabee/0x8d9764 链）；骨架终端写入在宿主层，MainWindow 接此信号直连
    // TerminalView::sendText（与原版仅"宿主层差异"，0x833db4 写入路径挂账）。
    void sendTextRequested(const QString &text);

private:
    // 0x0056e420：仅 showCommandsInOrder=true 时按 quick.label 升序（区分大小写）排序，无 usage 计数
    void sortCommands(QList<QJsonObject> &commands) const;
    // 0x0056e540：按 group 全局聚合（配置数组序线性收集 group==组名的全部条目，非相邻归并）建组工具条
    QToolBar *buildGroupBar(const QString &groupName) const;
    // 0x0056be56：单命令 QAction（uuid 存 data，空 uuid 返回 null 跳过）
    QAction *createCommandAction(const QJsonObject &command, int elideMode) const;
    // 0x0056f866 工具条重建半段：旧组条 deleteLater 后按可见组序 insertWidget
    void rebuildToolBars();

    QList<QJsonObject> loadCommands() const;

    QHBoxLayout *m_buttons = nullptr;
    QMenu *m_quickMenu = nullptr;
    QStringList m_visibleGroups; // 0x5a3156 同名 +0x68：可见组列表（单组模式恒 ≤1）
};
