#include "QuickBar.h"

#include <QHBoxLayout>

#include "core/LocaleManager.h"

QuickBar::QuickBar(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("QuickBar"));
    // 注册名 "&Quick Bar"；locale 查表键不含 & 助记符（AGENTS.md #14），缺键回退英文
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Quick Bar")));
    // 0x0056e26e: setAttribute(0x5d,1)=WA_StyledBackground，gui.theme 的 QuickBar 规则背景方可生效
    setAttribute(Qt::WA_StyledBackground, true);

    // 空态占位布局；按钮构建挂账 0x0056e420/0x0056ce72（clicked→close），F4 接入时补
    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
}
