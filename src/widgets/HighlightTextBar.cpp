#include "HighlightTextBar.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QStyle>

#include "widgets/TerminalView.h"

HighlightTextBar *HighlightTextBar::s_instance = nullptr;

HighlightTextBar::HighlightTextBar(QObject *parent)
    : QWidgetAction(parent)
{
    setObjectName(QStringLiteral("Text.HighlightTextBar"));
}

HighlightTextBar *HighlightTextBar::instance()
{
    if (!s_instance)
        s_instance = new HighlightTextBar;
    return s_instance;
}

// 8 色表（0x55c246 createWidget）：默认(None) + 7 命名色
QWidget *HighlightTextBar::createWidget(QWidget *parent)
{
    auto *row = new QWidget(parent);
    auto *layout = new QHBoxLayout(row);
    layout->setContentsMargins(2, 2, 2, 2);
    layout->setSpacing(2);

    const int size = row->style()->pixelMetric(QStyle::PM_SmallIconSize) * 2;

    // 默认(None)：取消所有高亮入口（0x55c246 色表首项；clear 语义挂账——原版语义未逆明，
    // 以"取消选中色钮"等价）
    auto addColor = [this, row, layout, size](const QString &name) {
        auto *b = new QPushButton(name.isEmpty() ? QStringLiteral("None") : name, row);
        b->setFlat(true);
        b->setCheckable(true);
        b->setFixedSize(size, size);
        b->setToolTip(name.isEmpty() ? QStringLiteral("None") : name);
        layout->addWidget(b);
        connect(b, &QPushButton::toggled, this, [this, b, name](bool checked) {
            auto *view = TerminalView::activeView();
            if (!checked)
                return; // 取消 checked：clear 语义挂账（原版 None/clear 链未逆明）
            if (!view || !view->hasSel())
                return;
            const QString sel = view->selectionText();
            // >511 字符 QMessageBox 确认（0x55c246）
            if (sel.size() > 511
                && QMessageBox::question(b->window(), HighlightTextBar::tr("高亮确认"),
                                         HighlightTextBar::tr("选中文本超过 511 字符，仍要高亮？"))
                       != QMessageBox::Yes) {
                b->setChecked(false);
                return;
            }
            view->highlightSelection(name);
        });
        return b;
    };

    addColor(QString()); // None
    for (const char *name : { "Red", "Orange", "Yellow", "Green", "Royalblue", "Cyan", "Purple" })
        addColor(QLatin1String(name));
    return row;
}
