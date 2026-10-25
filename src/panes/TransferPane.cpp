#include "TransferPane.h"

#include <QHeaderView>
#include <QItemSelectionModel>
#include <QLabel>
#include <QMenu>
#include <QTreeView>
#include <QVBoxLayout>

#include "core/LocaleManager.h"
#include "transfer/TransferCenter.h"

TransferPane::TransferPane(QWidget *parent)
    : KitPane(parent, QStringLiteral("TransferPane"))
    , m_view(new QTreeView(this))
{
    // QTreeView "TreeView"（0x733a18 族 initUi）：Extended 选择/col1 Stretch/headerHidden
    m_view->setObjectName(QStringLiteral("TreeView"));
    m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
    m_view->setHeaderHidden(true);
    m_view->setRootIsDecorated(false);
    // 模型先于 header 配置在位（FilerPane 同序;空模型 setSectionResizeMode 段错——实测）
    m_view->setModel(TransferCenter::instance()->model());
    m_center = TransferCenter::instance();
    m_view->header()->setStretchLastSection(false);
    m_view->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    m_view->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    // // shortcut: col 0 进度 delegate（TransferDelegate 0x8f97e6）未照搬,文本近似挂账

    auto *empty = new QLabel(LocaleManager::instance().tr(QStringLiteral("No transfer available")),
                             this);
    empty->setObjectName(QStringLiteral("EmptyLabel"));
    // 空态命令条：模型空→"No transfer available" 可见（0x733a18 族空态语义）
    connect(m_view->model(), &QAbstractItemModel::rowsInserted, empty, [empty, this] {
        empty->setVisible(m_view->model()->rowCount() == 0);
    });

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_view);
    layout->addWidget(empty);

    // 行右键菜单（menu.config "Transfer Popup"：OpenTargetDirectory/Pause/Remove——
    // 骨架 Popup 管线在 MainWindow showPopupMenu("TransferPopup"…),此处按 0x7346c4 族
    // 直连简化：Pause/Remove 两项循环选中路径）
    m_view->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_view, &QTreeView::customContextMenuRequested, this, [this](const QPoint &pos) {
        const QStringList paths = selectedPaths();
        if (paths.isEmpty() || !m_center)
            return;
        QMenu menu(this);
        // TransferPane.Pause 文案随状态（wind.actions：isPaused?Resume:Pause）
        const QVariantMap first = m_center->taskProperties(paths.first());
        const bool paused =
            first.value(QStringLiteral("transfer.state")).toString() == QLatin1String("Paused");
        QAction *pause = menu.addAction(LocaleManager::instance().tr(
            paused ? QStringLiteral("Resume") : QStringLiteral("Pause")));
        QAction *remove = menu.addAction(LocaleManager::instance().tr(QStringLiteral("Remove")));
        QAction *chosen = menu.exec(m_view->viewport()->mapToGlobal(pos));
        if (chosen == pause) {
            for (const QString &path : paths)
                paused ? m_center->resumeTask(path) : m_center->pauseTask(path);
        } else if (chosen == remove) {
            for (const QString &path : paths) // 0x734804：循环逐个移除
                m_center->removeTask(path);
        }
    });
}

void TransferPane::hookModel(QAbstractItemModel *model)
{
    // 模型在 ctor 已挂（setSectionResizeMode 需模型在位）;此处仅兜底重挂/中心锚
    if (model && model != m_view->model())
        m_view->setModel(model);
    m_center = TransferCenter::instance();
}

// 0x734398：selectionModel→selectedRows(0)→data(DisplayRole) toString 列表
QStringList TransferPane::selectedPaths() const
{
    QStringList paths;
    const QItemSelectionModel *selection = m_view->selectionModel();
    if (!selection)
        return paths;
    const QModelIndexList rows = selection->selectedRows(0);
    for (const QModelIndex &idx : rows)
        paths << idx.data(Qt::DisplayRole).toString();
    return paths;
}
