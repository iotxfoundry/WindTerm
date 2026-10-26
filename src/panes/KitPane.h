#pragma once

#include <QContextMenuEvent>
#include <QWidget>

// 原版 KitPane 基类（0x008c3bbe）：ctor 三连 objectName → setWindowIcon（挂账）→
// setWindowTitle(King_title 0x008a1106)；右键走基类 contextMenuEvent（vtable+0x110）
// → pane_showPopupMenu（0x8c3c6a）。重建以 popupRequested 信号接 MainWindow::showPopupMenu
class KitPane : public QWidget
{
    Q_OBJECT

public:
    explicit KitPane(QWidget *parent, const QString &name);

signals:
    // 原 contextMenuEvent 直调 pane_showPopupMenu；骨架弹菜单逻辑在 MainWindow，经信号转发
    void popupRequested(Qt::KeyboardModifiers mods);

protected:
    void contextMenuEvent(QContextMenuEvent *e) override;
};
