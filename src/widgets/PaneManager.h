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

} // namespace PaneManager
