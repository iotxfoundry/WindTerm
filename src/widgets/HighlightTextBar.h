#pragma once

#include <QWidgetAction>

class TerminalView;

// 原版 HighlightTextBar（0x55c246）：QWidgetAction 子类（"Text.HighlightTextBar" 特判
// 0x665dc2）。createWidget 惰建 8 色 [默认(None),Red,Orange,Yellow,Green,Royalblue,Cyan,
// Purple] flat+checkable QPushButton（fixedSize=style PM×2、checked 无边框 QSS 是样式行为
// ——铁律禁内联 QSS 压主题：仅 setFlat+checkable 简化+视觉挂账）。
// toggled→checked 时取当前 view 选区→>511 字符 QMessageBox 确认→setHighlightRange；
// 取消 checked→clearHighlightRange。
class HighlightTextBar : public QWidgetAction
{
    Q_OBJECT

public:
    explicit HighlightTextBar(QObject *parent = nullptr);

    // 0x665dc2 actionFactory：按 actionId 特判建本类；widget 惰建于 createWidget
    static HighlightTextBar *instance();

    // 测试通路：createWidget 为 protected（QWidgetAction 契约），测试直建 8 色钮条
    QWidget *createWidgetForTest(QWidget *parent) { return createWidget(parent); }

protected:
    QWidget *createWidget(QWidget *parent) override;

private:
    static HighlightTextBar *s_instance;
};
