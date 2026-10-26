#pragma once

#include <QDialog>

class QDialogButtonBox;
class QLabel;
class QSlider;

// 0x00704dd2 ctor / 0x00704b32 setup（s_application_windowOpacity_704b32）/
// 0x0070496e connect / 0x007048a0 预览文案 / 0x00704840 valueChanged 落窗 /
// 0x00704e96 opacity() / 0x0075d79c 全局入口（dialog 打开+写回 application.windowOpacity）。
class WindowOpacityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WindowOpacityDialog(QWidget *parent = nullptr);

    double opacity() const; // 0x00704e96：slider value / 100.0

    // 接线面：模态弹出（原版 0x0075d79c：parent=activeMainPane）；接受时写回键
    // application.windowOpacity（写经 FUN_0075c480，骨架无全局 setter——挂账：仅预览，不落盘）
    static void open(QWidget *parent);

private:
    void setOpacity(int value); // 0x007048a0：预览文案 + 即时应用（0x00704840 经 75d79c）

    QDialogButtonBox *m_box;     // +0x30（Close 单键，0x200000）
    QLabel *m_percent;           // +0x38
    QSlider *m_slider;           // +0x40
};
