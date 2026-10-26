#pragma once

#include <QColor>
#include <QLineEdit>
#include <QTabBar>
#include <QTimer>
#include <QVector>
#include <functional>

class QMouseEvent;
class QToolButton;
// TabGroup 标签条（QTabBar 子类，原版 TabBar 0x005a859a 的骨架面；QSS 类型选择器按
// C++ 类名 QTabBar 命中子类，#ViewGroup > QTabBar::tab 规则不受影响）：
// - R45 hoverToSelect（0x005ad4a6 建定时器/0x005aa91e 超时选签/0x005abfd8 eventFilter）
// - R47 滚动钮溢出面（0x005aec28 建面 autoRepeat/0x005aa862 按溢出态刷显隐可用）
// - R46 per-tab 标签色（0x005a7b66 per-tab 列表/0x005a8b2e fillRect 叠加，无效不染）
class TabGroupBar : public QTabBar
{
    Q_OBJECT

public:
    explicit TabGroupBar(QWidget *parent = nullptr);

    // R45：键 tabbar.hoverToSelect（double 秒→int ms，0x005ad4a6 cvttsd2si(v*1000)）；
    // >0 建 QTimer 并 setInterval（下限 100ms，0x005ad4a6 cmovl 0x64）；≤0 删定时器禁用
    void setHoverToSelect(double seconds);
    int hoverInterval() const { return m_hoverTimer ? m_hoverTimer->interval() : 0; }
    QTimer *hoverTimer() const { return m_hoverTimer; } // 测试断言面
    int hoverIndex() const { return m_hoverIndex; }     // 测试断言面（TabGroup+0x40）
    // 测试驱动面：offscreen 合成鼠标事件被 QApplication::notify 前置吞没
    // （notify 返回 true 不达 event()），测试走 notify_helper 同源 event() 虚调用
    void sendSyntheticEvent(QEvent *event) { this->QWidget::event(event); }
    // 测试驱动面：offscreen 无布局拍，显式触发溢出态刷新（0x005aa862 体）
    void refreshScrollButtonsForTest() { refreshScrollButtons(); }

    // R47：挂接左右滚动钮（0x005aec28 +0x70/+0x78 槽）；显隐/可用由溢出态刷新
    void setScrollButtons(QToolButton *left, QToolButton *right);

    // R46：per-tab 色（0x005a7b66），无效=不染色（0x005a8b2e 门卫）
    void setTabColor(int index, const QColor &color);
    QColor tabColor(int index) const;

    // TabListMenu（0x005b1c08）：平铺 QWidgetAction 行（图标 pixmap+文本 QLabel+每行
    // CloseButton）+顶部 FilterEdit+CountLabel 过滤计数；closeHandler=行 CloseButton
    // 落点（原版 0x005aa958 经 action close flag 分流到 tabCloseRequested 链）
    static QMenu *buildTabListMenu(QTabBar *bar, std::function<void(int)> closeHandler);
    // 0x005b2946/0x005ac790：anchor（TabListButton）mapToGlobal exec，前后 setAutoRaise
    // 按压态，结束后补发 Leave（0x005ac863）
    static void execTabListMenu(QTabBar *bar, QWidget *anchor,
                                std::function<void(int)> closeHandler);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    bool event(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void tabInserted(int index) override;
    void tabRemoved(int index) override;

private:
    void refreshScrollButtons();
    void scrollStep(int dir);

    QTimer *m_hoverTimer = nullptr;
    int m_hoverIndex = -1; // 0x005abfd8 TabGroup+0x40（hover 命中签位，-1=无）
    QToolButton *m_scrollLeft = nullptr;  // 0x005aec28 +0x70
    QToolButton *m_scrollRight = nullptr; // 0x005aec28 +0x78
    QVector<QColor> m_tabColors;          // 0x005a7b66 TabBar+0x60 per-tab 色列表
};

// gui.theme "QMenu FilterEdit > #CountLabel"（dige-black:271）类型选择器按 C++ 类名命中
// （R17 机制：真实子类而非 objectName 挂名）
class FilterEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit FilterEdit(QWidget *parent = nullptr)
        : QLineEdit(parent)
    {
    }
};
