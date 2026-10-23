#include "ExplorerPane.h"

#include <functional>

#include <QLineEdit>
#include <QTreeWidget>
#include <QVBoxLayout>

#include "core/LocaleManager.h"

ExplorerPane::ExplorerPane(QWidget *parent)
    : QWidget(parent)
{
    // 原版 KitPane 派生类以类名挂 objectName（0x008c3bbe+0x0072fbee）；gui.theme:544
    setObjectName(QStringLiteral("ExplorerPane"));
    // King_title 0x008a1106 表中 Explorer（"ExplorerPane" 是 objectName，不是 tr 键）
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Explorer")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现

    // toolbar.config ExplorerPane=[{FilterEdit:true}]（ctor 0x0057eb0c）；
    // objectName 命中 gui.theme KitPane FilterEdit 规则（骨架侧 ExplorerPane 是容器自身，
    // KitPane 前缀选择器在骨架无后代链——沿用类名挂名近似，规则未命中挂账）
    m_filter = new QLineEdit(this);
    m_filter->setObjectName(QStringLiteral("FilterEdit"));
    // zh-CN.locale "Filter"→"筛选"（实机占位同款）
    m_filter->setPlaceholderText(LocaleManager::instance().tr(QStringLiteral("Filter")));
    m_filter->setClearButtonEnabled(true);

    // 树本体：原树即 QTreeWidget，保留原 objectName 语义挂子件
    m_tree = new QTreeWidget(this);
    m_tree->setHeaderHidden(true);

    auto *workspace = new QTreeWidgetItem(m_tree, QStringList{QStringLiteral("workspace")});
    auto *project = new QTreeWidgetItem(workspace, QStringList{QStringLiteral("WindTerm")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("src")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("docs")});
    new QTreeWidgetItem(project, QStringList{QStringLiteral("tools")});
    m_tree->expandAll();

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_filter);
    layout->addWidget(m_tree);

    // 简单文本过滤：match 全隐藏/显示——后序遍历，可见 = 自身命中 or 有可见后代
    connect(m_filter, &QLineEdit::textChanged, this, [this](const QString &text) {
        const QString needle = text.trimmed();
        const std::function<bool(QTreeWidgetItem *)> apply = [&](QTreeWidgetItem *item) -> bool {
            bool childMatch = false;
            for (int i = 0; i < item->childCount(); ++i)
                childMatch |= apply(item->child(i));
            const bool hit = needle.isEmpty() || item->text(0).contains(needle, Qt::CaseInsensitive);
            item->setHidden(!(hit || childMatch));
            return hit || childMatch;
        };
        for (int i = 0; i < m_tree->topLevelItemCount(); ++i)
            apply(m_tree->topLevelItem(i));
        emit filterChanged(text);
    });
}
