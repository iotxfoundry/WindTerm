#include "FilerPane.h"

#include <QHeaderView>
#include <QTreeWidget>
#include <QVBoxLayout>

#include "core/LocaleManager.h"
#include "widgets/PaneHeader.h"

FilerPane::FilerPane(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("FilerPane"));
    // King_title 0x008a1106 表中 Filer（"FilerPane" 是 objectName，不是 tr 键）
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Filer")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现

    // 标题行：非 tab 形态 pane 才有（createFamily 0x005524a0）；标题走 locale 查表
    // "Filer"→文件管理器（zh-CN.locale 实键；"FilerPane" 无 tr 键）
    m_header = new PaneHeader(LocaleManager::instance().tr(QStringLiteral("Filer")), this);

    m_tree = new QTreeWidget(this);
    m_tree->setColumnCount(2);
    m_tree->setHeaderLabels({tr("Name"), tr("Date mod")});
    m_tree->setRootIsDecorated(false);
    m_tree->header()->setStretchLastSection(false);
    m_tree->header()->setSectionResizeMode(0, QHeaderView::Stretch);

    m_tree->addTopLevelItem(new QTreeWidgetItem(m_tree, QStringList{QStringLiteral(".."), QStringLiteral("2026-10-22 09:12")}));
    m_tree->addTopLevelItem(new QTreeWidgetItem(m_tree, QStringList{QStringLiteral("bin"), QStringLiteral("2026-09-01 11:40")}));
    m_tree->addTopLevelItem(new QTreeWidgetItem(m_tree, QStringList{QStringLiteral("etc"), QStringLiteral("2026-08-15 18:03")}));
    m_tree->addTopLevelItem(new QTreeWidgetItem(m_tree, QStringList{QStringLiteral("home"), QStringLiteral("2026-10-20 07:55")}));
    m_tree->addTopLevelItem(new QTreeWidgetItem(m_tree, QStringList{QStringLiteral("var"), QStringLiteral("2026-10-21 22:31")}));

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_header);
    layout->addWidget(m_tree);

    // 对齐 Dock.TogglePaneFiler 语义：关闭请求由宿主 hide 整个 pane
    connect(m_header, &PaneHeader::closeRequested, this, &FilerPane::closeRequested);
}
