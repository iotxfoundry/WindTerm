#pragma once

#include <QList>
#include <QSplitter>
#include <QWidget>

#include "Splitter.h"

enum class Dir { Left, Right, Top, Bottom };

namespace PaneManager {

inline Qt::Orientation orientationFor(Dir dir)
{
    return (dir == Dir::Left || dir == Dir::Right) ? Qt::Horizontal : Qt::Vertical;
}

// 稳定名称用于 QSettings 持久化；启动插入序列确定，序号可复现
inline QString nextNestedSplitterName()
{
    static int counter = 0;
    return QStringLiteral("NestedSplitter_%1").arg(++counter);
}

// 移植 FUN_005a277a：相对锚点四方向插入，方向冲突时自动外包一层 splitter
inline QWidget *insert(Splitter *root, QWidget *anchor, QWidget *pane, Dir dir)
{
    if (!anchor || !pane)
        return pane;

    const Qt::Orientation target = orientationFor(dir);
    auto *parent = qobject_cast<QSplitter *>(anchor->parentWidget());

    // 锚点不在任何 splitter 中：退化为追加到根
    if (!parent) {
        if (root)
            root->addWidget(pane);
        return pane;
    }

    // FUN_005a277a：count < 2 直接改父 splitter 方向
    if (parent->count() < 2) {
        parent->setOrientation(target);
    } else if (parent->orientation() != target) {
        // FUN_005a277a：方向不同 → replaceWidget(anchor) 后新建子 splitter 再嵌套
        const int idx = parent->indexOf(anchor);
        auto *nested = new Splitter;
        nested->setOrientation(target);
        nested->setChildrenCollapsible(false);
        nested->setObjectName(nextNestedSplitterName());
        parent->replaceWidget(idx, nested);
        nested->addWidget(anchor);
        nested->show(); // 无父新建的 splitter 被 replaceWidget 收养后不会自动显示
        parent = nested;
    }

    // FUN_005a277a：偶数方向（Left/Top）插到锚点前，奇数（Right/Bottom）插到锚点后
    const int idx = parent->indexOf(anchor);
    const bool before = (dir == Dir::Left || dir == Dir::Top);
    parent->insertWidget(before ? idx : idx + 1, pane);

    // 引擎的均分 + handleWidth 扣除，这里近似为：新槽取锚点尺寸的 1/4
    QList<int> sizes = parent->sizes();
    const int paneIndex = parent->indexOf(pane);
    const int anchorIndex = parent->indexOf(anchor);
    if (sizes.size() == parent->count() && paneIndex >= 0 && anchorIndex >= 0) {
        sizes[paneIndex] = qMax(1, sizes.value(anchorIndex) / 4);
        parent->setSizes(sizes);
    }

    return pane;
}

// E(0x5a236c)：沿首子 QSplitter 下钻到底（null 即止），OtherFocusReason 聚焦
inline void restoreFocus(QWidget *w)
{
    while (auto *sp = qobject_cast<QSplitter *>(w)) {
        w = sp->widget(0);
        if (!w)
            return;
    }
    w->setFocus(Qt::OtherFocusReason);
}

namespace detail {

// D(0x5a29e6) 全文照搬（递归 690B）：closedView 关闭后自底向上清理/合并 splitter 树
inline void cleanupEmptyTree(QWidget *closedView, QWidget *container)
{
    if (!container)
        return;
    auto *sp = qobject_cast<QSplitter *>(container->parentWidget());
    if (!sp)
        return;
    const int idx = sp->indexOf(container);
    QList<int> sizes = sp->sizes();
    if (!container->close())
        return;
    container->hide();
    // 重建注记：原版经关闭链即时移除（count 同步递减）；重建以脱离父 splitter 等价，
    // 脱离件即删（0x8cee89 sweep 的 deleteLater 语义并至此，且脱离子件 findChildren 不达）
    container->setParent(nullptr);
    container->deleteLater();
    if (sp->count() == 0) {
        cleanupEmptyTree(closedView, sp); // 父也空→递归向上
    } else if (sp->count() == 1) {
        QWidget *only = sp->widget(0);
        if (!qobject_cast<QSplitter *>(only)) {
            restoreFocus(sp);
            return;
        }
        QWidget *keep = qobject_cast<QSplitter *>(only)->widget(0);
        const int i2 = sp->indexOf(only);
        sp->replaceWidget(i2, keep);
        only->deleteLater();
        restoreFocus(keep);
    } else {
        QWidget *survivor = nullptr;
        if (idx + 1 < sp->count()) {
            sizes[idx + 1] += sp->handleWidth() + sizes[idx]; // 尺寸移交右邻
            survivor = sp->widget(idx + 1);
        } else if (idx >= 1) {
            sizes[idx - 1] += sp->handleWidth() + sizes[idx]; // 尺寸移交左邻
            survivor = sp->widget(idx);
        }
        sizes.removeAt(idx);
        sp->setSizes(sizes);
        restoreFocus(survivor);
    }
}

} // namespace detail

// D(0x5a29e6) 入口守卫：closedView 须为 container 祖先（0x5a29e6 isAncestorOf）
inline void cleanupEmptyTree(QWidget *closedView, QWidget *container)
{
    if (!container || !closedView->isAncestorOf(container))
        return;
    detail::cleanupEmptyTree(closedView, container);
}

} // namespace PaneManager
