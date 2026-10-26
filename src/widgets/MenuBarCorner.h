#pragma once

#include <QToolBar>

// 原版 MenuBar 右上角 corner widget（0x008c9ee4）：QToolBar objectName "MenuBarCorner"，
// 按钮 PaletteButton/FocusModeButton/ManageLayoutButton，Terminal 版追加 TunnelsButton/XServerButton
// （0x0085d99e）。
class MenuBarCorner : public QToolBar
{
    Q_OBJECT

public:
    explicit MenuBarCorner(QWidget *parent = nullptr, bool terminal = true);
};
