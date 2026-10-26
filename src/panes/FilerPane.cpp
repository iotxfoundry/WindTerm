#include "FilerPane.h"

#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QLineEdit>
#include <QSignalBlocker>
#include <QStackedWidget>
#include <QTimer>
#include <QTreeView>
#include <QVBoxLayout>

#include "core/Assets.h"
#include "core/JsonText.h"
#include "core/LocaleManager.h"
#include "core/SshSession.h"
#include "filer/FileSystemItem.h"
#include "filer/FileSystemModel.h"
#include "transfer/TransferCenter.h"
#include "transfer/SftpTransfer.h"
#include "widgets/PaneHeader.h"

namespace {

// filer.hiddenItemsVisible 初始值（wind.config:23,默认 false）。
// shortcut: WindConfig 无 bool getter（文件不在本批范围）,user.config 覆盖链挂账——
// 逆明后移入 WindConfig
bool hiddenItemsVisibleDefault()
{
    QFile file(Assets::dir() + QStringLiteral("/config/wind.config"));
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);
    return QJsonDocument::fromJson(JsonText::stripLineComments(data))
        .object()
        .value(QStringLiteral("filer.hiddenItemsVisible"))
        .toBool(false);
}

} // namespace

FilerPane::FilerPane(QWidget *parent)
    : KitPane(parent, QStringLiteral("FilerPane"))
    , m_showHidden(hiddenItemsVisibleDefault())
{
    // 标题行：非 tab 形态 pane 才有（createFamily 0x005524a0）；标题走 locale 查表
    m_header = new PaneHeader(LocaleManager::instance().tr(QStringLiteral("Filer")), this);

    m_localModel = new FileSystemModel(this);
    m_remoteModel = new FileSystemModel(this);

    m_localView = new QTreeView(this);
    m_localView->setModel(m_localModel);
    m_remoteView = new QTreeView(this);
    m_remoteView->setModel(m_remoteModel);
    for (QTreeView *view : {m_localView, m_remoteView}) {
        view->header()->setStretchLastSection(false);
        view->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    }

        // 0x731066：两页栈（页 0=本地视图/页 1=远程视图）
    m_stack = new QStackedWidget(this);
    m_stack->addWidget(m_localView);
    m_stack->addWidget(m_remoteView);

    // 状态 QLabel（0x731066 +0x58 语义：framed/AlignVCenter|AlignLeft）
    m_status = new QLabel(this);
    m_status->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    m_status->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    m_cdDebounce = new QTimer(this);
    m_cdDebounce->setSingleShot(true);
    m_cdDebounce->setInterval(250); // mode 0x10：地址条文本变化=cd 防抖 250ms
    connect(m_cdDebounce, &QTimer::timeout, this, [this] {
        if (m_address)
            cd(m_address->text().trimmed());
    });

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_header);
    layout->addWidget(m_stack);
    layout->addWidget(m_status);

    // 对齐 Dock.TogglePaneFiler 语义：关闭请求由宿主 hide 整个 pane
    connect(m_header, &PaneHeader::closeRequested, this, &FilerPane::closeRequested);

    for (QTreeView *view : {m_localView, m_remoteView}) {
        // 双击进目录：P5 浏览链导航位。shortcut: 双击/单击语义未逐字逆明,
        // Open 动作逆明（P6）时校准
        connect(view, &QTreeView::doubleClicked, this, [this, view](const QModelIndex &idx) {
            FileSystemModel *model = view == m_localView ? m_localModel : m_remoteModel;
            FileSystemItem *item = model->itemFor(idx);
            if (item && item->type == FileSystemItem::Folder)
                cd(model->pathFor(idx));
        });
    }
    for (FileSystemModel *model : {m_localModel, m_remoteModel}) {
        // 状态 QLabel：当前路径/加载态
        connect(model, &FileSystemModel::loadStarted, this, [this](const QString &path) {
            m_status->setText(QStringLiteral("Loading... ") + path);
        });
        connect(model, &FileSystemModel::loadFinished, this, [this, model](const QString &) {
            if ((model == m_localModel) == (m_stack->currentIndex() == 0))
                m_status->setText(model->rootPath());
        });
    }

    // 初始根=HOME。shortcut: 原版 Filer 初始路径未逆明,挂账
    cd(QDir::homePath());
}

void FilerPane::hookAddressEdit()
{
    if (!m_address)
        m_address = findChild<QLineEdit *>(QStringLiteral("FilterEdit"));
    if (m_address)
        connect(m_address, &QLineEdit::textChanged, m_cdDebounce,
                qOverload<>(&QTimer::start), Qt::UniqueConnection);
}

void FilerPane::focusAddressEdit()
{
    hookAddressEdit();
    if (m_address) {
        m_address->setFocus();
        m_address->selectAll();
    }
}

FileSystemModel *FilerPane::activeModel() const
{
    return m_stack->currentIndex() == 1 ? m_remoteModel : m_localModel;
}

QString FilerPane::currentPath() const
{
    return activeModel()->rootPath();
}

void FilerPane::cd(const QString &path, bool pushHistory)
{
    if (path.isEmpty())
        return;
    FileSystemModel *model = activeModel();
    model->setRootPath(path);
    if (m_address) {
        const QSignalBlocker blocker(m_address); // 防回环触发防抖 cd
        m_address->setText(path);
    }
    if (pushHistory) {
        while (m_history.size() > m_historyIdx + 1)
            m_history.removeLast();
        m_history.append(path);
        m_historyIdx = m_history.size() - 1;
    }
    m_status->setText(path);
}

void FilerPane::reload()
{
    activeModel()->setRootPath(currentPath()); // 同路径 setRootPath=整表 reload
}

void FilerPane::cdUp()
{
    // 0x578d88 族导航：父目录（字符串截断,本地/远程通用;remote "." 起点归一化挂账）
    const QString path = currentPath();
    const int slash = path.lastIndexOf(QLatin1Char('/'));
    cd(slash <= 0 ? QStringLiteral("/") : path.left(slash));
}

// 0x578d88：idx>0 后退可用 / idx<count-1 前进可用
void FilerPane::goBackward()
{
    if (m_historyIdx > 0) {
        --m_historyIdx;
        cd(m_history.at(m_historyIdx), false);
    }
}

void FilerPane::goForward()
{
    if (m_historyIdx < m_history.size() - 1) {
        ++m_historyIdx;
        cd(m_history.at(m_historyIdx), false);
    }
}

bool FilerPane::canGoBackward() const
{
    return m_historyIdx > 0;
}

bool FilerPane::canGoForward() const
{
    return m_historyIdx < m_history.size() - 1;
}

// 全局选项键 filer.hiddenItemsVisible（wind.actions script=window.toggleOption）。
// shortcut: toggleOption 持久化未接,仅会话内生效
void FilerPane::toggleHiddenItems()
{
    m_showHidden = !m_showHidden;
    m_localModel->setShowHidden(m_showHidden);
    m_remoteModel->setShowHidden(m_showHidden);
}

bool FilerPane::showHidden() const
{
    return m_showHidden;
}

void FilerPane::setRemoteSession(SshSession *session)
{
    if (m_remoteSession == session)
        return;
    if (m_remoteSession)
        disconnect(m_remoteSession, nullptr, this, nullptr);
    m_remoteSession = session;
    if (!session) {
        m_stack->setCurrentIndex(0); // 非 SSH 会话→本地页（0x5773d6）
        return;
    }
    // sftpReady（worker established 链末尾建好后）→切远程页
    connect(session, &SshSession::sftpReady, this, [this] { applyRemotePage(); },
            Qt::UniqueConnection);
    applyRemotePage();
}

void FilerPane::applyRemotePage()
{
    if (!m_remoteSession || !m_remoteSession->sftpSession())
        return; // sftp 未就绪：留本地页,ready 后经上方连接切入
    m_remoteModel->setSftp(m_remoteSession->sftpSession());
    if (m_stack->currentIndex() != 1) {
        m_stack->setCurrentIndex(1);
        // 远程初始=服务端 home：sftp_canonicalize_path(".")（0x8e8d36 同点——原版
        // listDir 错误链 0x008e8fb1 对 "." canonicalize 拼错误文案,证明 "." 起点合法）。
        // 失败退 "."（服务端 home 相对路径仍可列）
        const QString home = SshSession::sftpCanonicalizePath(m_remoteSession->sftpSession(),
                                                              QStringLiteral("."));
        cd(home.isEmpty() ? QStringLiteral(".") : home);
    }
}

void FilerPane::dropRemoteSession(SshSession *session)
{
    if (m_remoteSession != session)
        return;
    m_remoteSession = nullptr;
    m_remoteModel->setSftp(nullptr);
    m_stack->setCurrentIndex(0);
}

// ═══ P6 传输收口（0x579f0e/0x57acf2/0x8ec9b8）═══
// 0x8ec9b8 createTransfers：QVariantList{方向,files,srcRoot,dstDir}→forwardSetMode(0x12)——
// 骨架直接建 SftpTransfer 入 TransferCenter（分派层简化,事件序列保持 taskEvent 一致）
namespace {
// createTransfers 等效：逐文件建任务行+属性+后台传输;行键=本地路径
void startTransfers(void *sftp, bool upload, const QStringList &files,
                    const QString &srcRoot, const QString &dstDir)
{
    TransferCenter *center = TransferCenter::instance();
    for (const QString &file : files) {
        const QString name = QFileInfo(file).fileName();
        const QString remote = upload ? (dstDir + QLatin1Char('/') + name)
                                      : file;
        const QString local = upload ? file
                                     : (dstDir + QLatin1Char('/') + name);
        auto *transfer = new SftpTransfer(sftp, upload, remote, local, center);
        center->ensureTaskRow(local); // kind 0 建行（TransferBar/Pane 懒建触发）
        // 属性（0x8ec9b8 参 2=方向——transfer.download/transfer.upload 二值键）
        center->setTaskProperty(local, QStringLiteral("transfer.session"),
                                upload ? QStringLiteral("SFTP") : QStringLiteral("SFTP"));
        center->setTaskProperty(local, upload ? QStringLiteral("transfer.upload")
                                              : QStringLiteral("transfer.download"),
                                true);
        center->setTaskProperty(local, QStringLiteral("transfer.targetDirectory"),
                                upload ? dstDir : dstDir);
        center->setTaskProperty(local, QStringLiteral("transfer.currentItemName"), name);
        center->setTaskProperty(local, QStringLiteral("transfer.count"), 1);
        center->setTaskProperty(local, QStringLiteral("transfer.localFileSystem"), !upload);
        // 进度/状态/终局→行属性+taskEvent(4) 刷新（0x58722a 消费链）
        QObject::connect(transfer, &SftpTransfer::progress, center,
                [center, local](qint64 processed, qint64 total) {
            center->setTaskProperty(local, QStringLiteral("transfer.processedSize"),
                                    QString::number(processed));
            center->setTaskProperty(local, QStringLiteral("transfer.size"),
                                    QString::number(total));
            center->setTaskProperty(local, QStringLiteral("transfer.weightPercent"),
                                    total > 0 ? static_cast<int>(processed * 100 / total) : 0);
            emit center->taskEvent(local, TransferCenter::Refresh);
        });
        QObject::connect(transfer, &SftpTransfer::finished, center, [center, local]() {
            center->setTaskProperty(local, QStringLiteral("transfer.weightPercent"), 100);
            emit center->taskEvent(local, TransferCenter::Refresh);
        });
        transfer->start();
    }
}
} // namespace

// 0x57acf2 Download 语义：selectedRows→路径集（srcRoot=远端当前目录）→QFileDialog 选本地
// 目录（0x57a928 原版 RemoteFileDialog 0x6d8cfe 简化挂账）→createTransfers(download)
void FilerPane::download()
{
    if (!m_remoteSession || !m_remoteSession->sftpSession())
        return;
    if (m_stack->currentIndex() != 1)
        return; // wind.actions state=visible=!localSystemMode 等效门
    // 选中项收集（0x734398 同构：selectionModel→selectedRows→路径;目录递归挂账）
    const QItemSelectionModel *selection = m_remoteView->selectionModel();
    if (!selection)
        return;
    QStringList files;
    const QModelIndexList rows = selection->selectedRows(0);
    for (const QModelIndex &idx : rows) {
        if (FileSystemItem *item = m_remoteModel->itemFor(idx);
            item && item->type == FileSystemItem::File)
            files << m_remoteModel->pathFor(idx);
    }
    if (files.isEmpty())
        return;
    const QString dst = QFileDialog::getExistingDirectory(
        this, LocaleManager::instance().tr(QStringLiteral("Select Download Folder")));
    if (dst.isEmpty())
        return;
    startTransfers(m_remoteSession->sftpSession(), false, files, currentPath(), dst);
}

// 0x579f0e Upload 语义：QFileDialog 选本地文件（原版 RemoteFileDialog 多选简化为
// getOpenFileNames）→当前远端目录=createTransfers(upload)
void FilerPane::upload()
{
    if (!m_remoteSession || !m_remoteSession->sftpSession())
        return;
    if (m_stack->currentIndex() != 1)
        return;
    const QStringList files = QFileDialog::getOpenFileNames(
        this, LocaleManager::instance().tr(QStringLiteral("Select Upload Items")));
    if (files.isEmpty())
        return;
    startTransfers(m_remoteSession->sftpSession(), true, files, QString(), currentPath());
}
