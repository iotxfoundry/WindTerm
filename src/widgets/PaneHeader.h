#pragma once

#include <QWidget>

class QLabel;
class QToolButton;

// 标题行组件（createFamily 0x005524a0）：QHBox margins=0 [StateLabel(宽6px), IconLabel,
// TitleLabel(可换行自定义), 右侧QHBox[功能按钮…, CloseButton]]。
// 行高无代码常量（实机≈28px 像素对照挂账，无数据键）——不 setFixedHeight，由 QSS padding 自然撑起。
// 仅非 tab 形态的 pane 挂标题行（tab 合流 pane 无）。
class PaneHeader : public QWidget
{
    Q_OBJECT

public:
    explicit PaneHeader(const QString &title, QWidget *parent = nullptr);

    // 0x00553156：setProperty("state")+样式刷新（Warning/Error 由 gui.theme ExplorerPane 规则变色）
    void state(const QString &state);

signals:
    // 0x008f0512：CloseButton 点击只发信号，hide/close 由宿主接线
    void closeRequested();

protected:
    bool event(QEvent *event) override; // enter/leave 显隐 CloseButton（0x55332c/0x553354）

private:
    QLabel *m_state;
    QToolButton *m_closeButton;
};
