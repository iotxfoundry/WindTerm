#include "TransferPane.h"

#include <QHeaderView>
#include <QItemSelectionModel>
#include <QLabel>
#include <QMenu>
#include <QProgressBar>
#include <QStandardItemModel>
#include <QTreeView>
#include <QVBoxLayout>

#include "core/LocaleManager.h"
#include "transfer/TransferCenter.h"

TransferPane::TransferPane(QWidget *parent)
    : KitPane(parent, QStringLiteral("TransferPane"))
    , m_view(new QTreeView(this))
{
    // QTreeView "TreeView"（0x733ca6 s_TreeView_733ca6）：NoEditTriggers/
    // SelectRows/Extended(3)/UniformRowHeights/headerHidden/列0 pause delegate
    //（0x57181a king::pause;paint/命中细节未逆明挂账）。
    // R48 真相更正：原版**无**进度自绘 delegate——进度=隐藏 QProgressBar 借位记值
    //（0x735a0c/0x73782e）+悬浮 tooltip HTML 表（0x617aea）+行内 weightPercent 文本
    //（旧挂账"col 0 进度 delegate 未照搬"表述有误,删）。
    // 列布局反汇编实证（0x733ca6 尾）：col0 mode 1=Stretch/col1 mode 3=ResizeToContents;
    // sizes[4000,1000] 属 0x735a0c QSplitter（ListWidget+centralStack）非 header——
    // 骨架无历史 ListWidget（splitter 挂账）
    m_view->setObjectName(QStringLiteral("TreeView"));
    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
    m_view->setUniformRowHeights(true);
    m_view->setHeaderHidden(true);
    m_view->setRootIsDecorated(false);
    // 模型先于 header 配置在位（FilerPane 同序;空模型 setSectionResizeMode 段错——实测）
    m_view->setModel(TransferCenter::instance()->model());
    m_center = TransferCenter::instance();
    m_view->header()->setStretchLastSection(false);
    m_view->header()->setSectionResizeMode(0, QHeaderView::Stretch);          // mode 1
    m_view->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents); // mode 3

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
    // R48（0x735a0c 尾段）：隐藏 QProgressBar 成员——progress 信号借位记值
    //（0x73782e："TabProgress" property→setMaximum/setValue,仅记状态不进单元格）;
    // singleShot(0) 初始刷新槽（0x735a0c）无初值可刷,骨架省
    m_progress = new QProgressBar(this);
    m_progress->setRange(0, 100);
    m_progress->hide();
    layout->addWidget(m_progress);
    connect(m_center, &TransferCenter::progressSignal, m_progress,
            [p = m_progress](const QString &, int percent) { p->setValue(percent); });
    // 行悬浮 tooltip=0x617aea HTML 表（R48 ③;建行/刷新两挂点全量刷。原版 data 重写
    // 0x6202ba 属 TransferModel——center 不在白名单,骨架行 tooltip 落 pane 侧,结构
    // 差异注释挂账）
    connect(m_center, &TransferCenter::taskEvent, this, [this] { refreshRowToolips(); });
    connect(m_view->model(), &QAbstractItemModel::rowsInserted, this,
            [this] { refreshRowToolips(); });

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

// R48 ③：全行 tooltip=0x617aea 属性表（键序/Items %1 of %2/Failed 红/Time left/
// elapsed/Avg speed——三时间行数据由 FilerPane progress 链写入）
void TransferPane::refreshRowToolips()
{
    auto *model = qobject_cast<QStandardItemModel *>(m_view->model());
    if (!model || !m_center)
        return;
    for (int r = 0; r < model->rowCount(); ++r)
        if (QStandardItem *item = model->item(r, 0))
            item->setToolTip(
                TransferCenter::propertiesToHtml(m_center->taskProperties(item->text())));
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
